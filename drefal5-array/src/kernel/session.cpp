// Copyright (C) 2008-2009 Islamov Marat Shamilevich
// islamov.marat@gmail.com
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

#include "symbols.h"
#include "session.h"
#include "rfunction.h"

RefChain *Session::executeExpression(RefChain *chain) {

    std::stack<RefData**> openExecs; // ссылки на ячейки для открывающихся скобок
    RefData **l_exec;
    RefData **r_exec;
    RefData **chain_last;  // на эл-т после последнего
    RefExecBracket *tmpBr = 0;
    r_exec = chain->get_first();

    do {
        chain_last = &(chain->get_first()[chain->leng]); // на эл-т после последнего
        /// поиск скобки и выделение аргумента
        while (r_exec < chain_last) {
            if (tmpBr = ref_dynamic_cast<RefExecBracket>(*r_exec)) { // > или <
                if (! tmpBr->isOpen(r_exec)) { // > - нашли то, что искали
                    l_exec = openExecs.top();
                    openExecs.pop();
                    break;
                }
                // <
                openExecs.push(r_exec);
            }
            ++r_exec;
        }
        // теперь l_exec и r_exec - это ссылки на ячейки для < и > соотв.
        if (r_exec == chain_last) { // нечего вычислять
            // openExecs - статический и сам очистится. Если динамический, то тут удалить.
            return chain;
        }

        // дано: l_exec и r_exec
        /// получение тела функции из репозитория
        #ifdef TESTCODE
        if (! dynamic_cast<RefWord*>(l_exec[1])) SYSTEMERROR("NOt func NAME: " << l_exec[1]->toString() );
        #endif
        RefFunctionBase* function = dynamic_cast<RefFunctionBase *>( this->findFunctionById(  (ref_dynamic_cast<RefWord>(l_exec[1]))->getValue()  ) );
        if (!function) RUNTIMEERROR(l_exec[1]->toString(), "FUNCTION by ID [" << l_exec[1]->toString() << "] NOT DEFINED!");

        RefChain *newchain = 0;
        RefBuildInFunction *b_funct = dynamic_cast<RefBuildInFunction *>(function);
        // если не пользовательская функция, то выполнение
        if (b_funct) {
            newchain = b_funct->execute(l_exec[2], r_exec[-1], this);
        } else {
            RefUserFunction* u_funct = (RefUserFunction *)(function);
            LOG("Exec " << u_funct->getName());
            // BEGIN of USER FUNCTION EVALUTION
            /// user function->execute : перебор предложений
            /// запуск matching (точку восстановления наверное не тут создавать!)
            /// если успех - substituteExpression по правой части
            /// иначе следующее предлоджение
            /// если неуспех для всех предложений - аварийный останов
            // END of USER FUNCTION EVALUTION


            std::list<RefSentence *>::iterator sent = u_funct->body.begin(); // перебор предложений функции
            bool reslt = false;

            do {
                if (matching(*sent, (*sent)->leftPart, &(l_exec[2]), &(r_exec[-1]), false, false)) {
                    //LOG(step++ <<  "\tsucessfull!");
                    newchain = substituteExpression( (*sent)->rightPart ); // создаем копию rightPart'а с заменой переменных на значения
                    reslt = true;
                } else {
                    ++sent;
                }
            } while (!reslt && sent != u_funct->body.end());  // std: body.end() - элемент после последнего
        }

        if (! newchain) {
            RUNTIMEERROR(function->getName(), "ABORT!");
        }

        /// изменение карты поля зрения
        // сохраняем в карту ссылки на кусок chain до l_exec
        // if (в newchain есть функц вызов) {
        //      прыгаем для поиска <.> в newchain (сохраняем точку выпрыгивания)
        //      итд итп
        // } else {
        //      сохраняем в карту ссылки на newchain
        //      увеличиваем счетчик длины нового поля на длину newchain
        //      итд итп
        // }
        // итд итп


        #ifdef DEBUG
        if (chain->leng == 0) SYSTEMERROR("alarm");
        #endif

        RefData  **a11 = chain->get_first();
        RefData  **a12 = l_exec;
        --a12;
        RefData  **a21 = r_exec;
        ++a21;
        RefData  **a22 = &( chain->get_first()[chain->leng-1] );

//  новая chain = ff (chain_first..l_exec[-1] + newchain + r_exec[+1]..chain_last)  нужна ссылка на начало копии newchain
        RefChain *tmpchain = new RefChain(a11, a12, newchain->get_first(), &( newchain->get_first()[newchain->leng-1] ), a21, a22);
//  удалить старую chain
        delete newchain;
        chain = tmpchain;
        // теперь chain содержит результат подстановки

        r_exec = &( chain->get_first()[a12-a11] );
    } while (true);

};

// готовит подстановку: заменяет переменные значениями. Получаем ОВ с угловыми скобками
// прямое копирование
/// TODO: хорошо оптимизируется!
RefChain *Session::substituteExpression(ChainSubstitution *substitution) {
    // итерация по элементам аргумента (RefChain блоковый)
    // если закрытая переменная, то добавляем копию ее значения
	// если открытая - то ошибка

	//PooledTuple3<RefLinkToVariable**, RefData**, RefData**> varValues;
	PooledTuple2<RefData**, RefData**> partValues;

	DataLinkPooledStack<size_t> &linksAndBrs = substitution->varsAndBrackets;
	DataLinkPooledStack<RefStructBracket* > old_brackets;
	DataLinkPooledStack<RefStructBracket* > new_brackets;
	RefData **l, **r;
	MatchState *matchState;
	RefLinkToVariable* link = 0;
//*
	// 1) получить список закрытых переменных в chain, их значений и длин
	// 2) вычислить длину нового вектора (сумма длин значений переменных - их количество + длина chain) и создать его
	size_t newChainLength = substitution->leng;

	size_t varsAndBracketsCount = substitution->varsAndBrackets.getLength(); // количество закрытых переменных и стр-скобок
	if (varsAndBracketsCount){
		// заполняем значения переменных в partValues - чтоб потом сгенерировать результат
		size_t idx = 0;
		size_t currPosition = 0; // индекс по новому вектору - для скобок
		RefData **part_l = substitution->get_first(), **part_r = 0;


		while(idx < varsAndBracketsCount){
			part_r = substitution->get_first() - 1 + linksAndBrs.getByIndex(idx);  // first + i_diff
			if (part_l != part_r){ // если перед скобкой/переменной - есть что обрабатывать
				partValues.put(part_l, part_r-1);
				currPosition += (part_r - 1 - part_l);
			}
			link = ref_dynamic_cast<RefLinkToVariable>(*part_r);
			if (link){ // если переменная
				getBodyByLink( link->lnk, l, r, matchState);
				if (l) partValues.put(/*link,*/ l, r);  // если переменная с непустым значением
				#ifdef TESTCODE
				if (r-l < 0) SYSTEMERROR("unbalanced links!");
				#endif
				--newChainLength; // ссылки не будет
				newChainLength += (l?r-l+1:0); // но будут значения. поскольку l и r - это части поля зрения, то там только значения - никаких переменных
				currPosition += (l?r-l+1:0);
			} else {
				// стуктурная скобка
				#ifdef TESTCODE
				if (!ref_dynamic_cast<RefStructBracket>(*part_r)) SYSTEMERROR("alarm");
				#endif
				if (*part_r == old_brackets.top()){ // параскобка уже копировалась => позиция для ЗАКР скобки
					old_brackets.top_pop();
					RefStructBracket *nb = new_brackets.top_pop();
					nb->closed_ind = currPosition;
					partValues.put((RefData**)&nb, (RefData**)&nb);
					++currPosition;
				} else { // новая параскобка (закр)
					old_brackets.put((RefStructBracket*)*part_r);
					RefStructBracket *nb = new RefStructBracket();
					nb->opened_ind = currPosition;
					new_brackets.put(nb);
					partValues.put((RefData**)&nb, (RefData**)&nb);
					++currPosition;
				}
			}
			part_l = part_r+1;
			++idx;
		}

		if (part_l != substitution->get_last()+1){
			partValues.put(part_l, substitution->get_last());
		}


	} else {
		RefData** tmp_ptr = (RefData**)malloc((newChainLength+2)*sizeof(RefData*));
		tmp_ptr[0] = nullDataPoint;
		tmp_ptr[newChainLength+1] = nullDataPoint;
		memcpy(tmp_ptr+1, substitution->get_first(), newChainLength*sizeof(RefData*));
		return new RefChain(tmp_ptr, newChainLength);
	}
//*/
	// 2a) создать новый вектор нужной длины из подстановки. 
	//	   Вместо закрытых переменных - значения, стр-скобки заменяем на копии
	RefData** newdatachain = (RefData**)malloc(sizeof(RefData*)*(newChainLength+2));
	if (! newdatachain) SYSTEMERROR("memory limit");
	newdatachain[0] = newdatachain[newChainLength+1] = nullDataPoint;
	RefData** dest = newdatachain+newChainLength;
	RefData** src = substitution->get_first();
	size_t tlen = 0;
#ifdef TESTCODE
	if (!src) SYSTEMERROR("alarm");
#endif




	// 3) заполнять блоками memcpy


	while(partValues.top_pop(/*link,*/ l, r)){
		tlen = r-l+1;
		#ifdef TESTCODE
		if (tlen<1) SYSTEMERROR("alarm");
		#endif
		//std::cout << "\n+\t" << getTextOfChain(l, r);
		memcpy(dest-tlen+1, l, tlen*sizeof(RefData**));
		dest -= tlen;
	}

	RefChain *resultChain = new RefChain(newdatachain, newChainLength);
	// 4) обнулить в области видимости ячейки, попавшие в значения переменных

	// 5) удалить объекты по необнуленным ссылкам и весь ветор старого поля зрения

	PooledTuple3<int, int, int> pol;
	int a1,a2,b1,b2,c1,c2;

	pol.put(-2, 0, SIZE_MAX);
	pol.put(0x012345678, 0x012345678, 0x012345678);

	pol.top_pop(a1,b1,c1);
	pol.top_pop(a2,b2,c2);
//*/

	//PooledClass
	

	return resultChain;
};


RefObject* Session::findFunctionById(unistring id) {
	return 0;
};

unistring getTextOfChain(RefData** from, RefData** to){
	if (!from || !*from) return "[null]";
	if (!to || (to-from)<0 || (to-from)>1024) return "[error string]";
	unistring res = "";
	int i = 0;
	while(&from[i] <= to){
		if(from[i]) res += from[i]->toString();
		++i;
	}
	return res;
};

#define LOGSTEP(s) \
	std::cout << s << "\t" << (*activeTemplate?(*activeTemplate)->toString():"null") << " ~ " << (s=="BACK"?"":getTextOfChain(r+1, rr+1)) << "\n" << std::flush;


// сопоставляет образец tmplate с объектным выражением с l по r.
// isdemaching - признак того, что надо продолжить матчинг от предыдущего удачного состояния (напр в цепочке условий)
// ТОЛЬКО ДЛЯ ЦЕЛОГО ОБРАЗЦА В ПРЕДЛ. ИЛИ УСЛОВИИ
bool  Session::matching(RefObject *initer, RefChain *tmplate, RefData **ll, RefData **rr, bool isdemaching, bool isRevers) {
    LOG("New MATCHING : tmplateChain=" << tmplate->toString() << "  isDematching="<<isdemaching);
    RefData **activeTemplate = 0, **l=0, **r=0;

    if (isdemaching) {
        // продолжаем ранее успешное сопоставление
        result_sost = BACK;
        activeTemplate = tmplate->get_last();
    } else {
        // начинаем новое сопоставление с ll..rr
        result_sost = GO;
        l = 0;
        r = ll-1;
        activeTemplate = tmplate->get_first();

        if (ref_dynamic_cast<RefConditionBase >(initer)) {
			saveCurrentStateSmall(ll, rr, tmplate); // сохр. состояние перед вычислением условия предложения
        } else {
            saveCurrentStateLarge(ll, rr, tmplate); // сохр. состояние перед вычислением всего предложения
        }
    }

	while (true) {
        // сопоставляем текущий шаблон

        switch (result_sost) {

        case GO: {
            // выполняем инит
			/*if (activeTemplate==datadotTemplate_end ){
				if (r==current_view_r){
					result_sost = SUCCESS;
					break;
				} else {
					result_sost = BACK;
					MOVE_TO_pred_template(activeTemplate);
					break;
				}
			};*/

            LOGSTEP("GO  ");
            #ifdef TESTCODE
            if (!r) {
                SYSTEMERROR("RefData::init() tring to matching with NULL address!");
            };
            #endif
            l=0;
            result_sost = (*activeTemplate)->init(activeTemplate, this, l, r); /// ШАГ ВПЕРЕД
            break;
        }
        case BACK: {
			/*if (activeTemplate==datadotTemplate_beg){
				result_sost = FAIL;
				break;
			}*/

            LOGSTEP("BACK");
            result_sost = (*activeTemplate)->back(activeTemplate, this, l, r); /// ШАГ НАЗАД
            break;
        }

        case SUCCESS :
            return true;

        case ERROR :
            //return -1;
            #ifdef DEBUG
            LOG( "ERROR signal when maching!" );
            #endif
            return false;
        case FAIL   :
            #ifdef DEBUG
            LOG( "FAIL signal when maching!" );
            #endif
            return false;



        default:
            break;
        }
    };







};








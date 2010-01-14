// D-Refal - sentential program language
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

#include <sstream>

#include "program.h"
#include "system.h"


RefProgram::RefProgram(){
	step = 0;
	this->regModule(new ModSystem());
}


RefProgram::~RefProgram(){
	std::map<unistring, RefModuleBase*>::iterator
		iter = modules.begin(),
		iend = modules.end();
	while(iter != iend){
		//std::cout << "\n~~~ " << iter->first;

		delete iter->second;
		iter->second = 0;
		++iter;
	}

}


void RefProgram::regModule(RefModuleBase *module){ // регистрация модуля в программе (перед загрузкой)
		if (module->getName() == EmptyUniString)
			SYSTEMERRORn("Empty module name");
		if (modules.find(module->getName()) != modules.end())
			SYSTEMERRORn("Several loads of module [" << module->getName() << "] ");
		modules[module->getName()] = module;
};


//TODO: оптимизировать - без рекурсии
RefChain*  RefProgram::executeExpression (RefChain *chain, Session *sess){ // вычисляет цепочку
	if (!chain || chain->isEmpty()) {
		return chain; // new RefChain();
	}

#ifdef DEBUG
	std::cout << "executeExpression: " << chain->debug() << "\n";
#endif

	RefData* gc_save_point = sess->gc_last;

	RefChain* result = new RefChain(sess, chain->getLength());

	RefData
        **iter=chain->at_first(),       // поле зрения
        **iend = chain->at_afterlast(); // конец активной части поля зрения

	for (; iter < iend; ++iter){

		RefDataBracket *databr = (*iter)->isDataBracket();

		if (databr){
			if (ref_dynamic_cast<RefStructBrackets>(databr)){
				*result += new RefStructBrackets( sess, executeExpression(databr->chain, sess) );
			} else {
				#ifdef TESTCODE
				if (! ref_dynamic_cast<RefExecBrackets>(databr)) AchtungERRORs(sess);
				#endif

				//RefExecBrackets
				RefChain *arg = executeExpression(databr->chain, sess); // вычисляем внутренние exec-скобки
				if (arg->isEmpty()) SYSTEMERRORs(sess, "Unexpected empty argument for function call-brackets! " << databr->chain->debug());
				RefData **functionid = (*arg)[0];
				//TODO: сделать привязку функциональных вызовов по именнованым областям
				RefWordBase *fname = ref_dynamic_cast<RefWordBase>(*functionid);
				RefFunctionBase *func = 0;
				if (!fname || !(func = this->findFunction(fname->getValue()))){
					RUNTIMEERRORs(sess, "Function not found in program");
				}
				RefChain *fresult;
				if (arg->getLength() > 1){
					fresult = func->exec((*arg)[1], (*arg)[-1], sess);
				} else {
					#ifdef TESTCODE
					if (arg->getLength() != 1) AchtungERRORs(sess);
					#endif
					fresult = func->exec(0, 0, sess);
				}

				//arg = executeExpression(fresult, sess); // опасная рекурсия! Заменить
				//*result += arg;  // arg уничтожен оператором +=
				//continue;



                if (! fresult->isEmpty()){
      
                    if (++iter < iend){ // если еще есть необработанный хвост
                        *fresult += new RefChain(sess, chain, iter, iend);  // сохраняем хвост
	                }
					iter = fresult->at_first();
					--iter;
                    iend = fresult->at_afterlast();
				} else {
				    // если результат был пуст, то двигаемся дальше
				}
			}
		} else {
			*result += *iter;
		}
	}

	sess->gc_prepare(gc_save_point);
	sess->gc_exclude(result);
	sess->gc_clean(gc_save_point);

	//std::cout << "executeExpression: " << result->debug() << "\n";
	return result;
};

//---------
RefChain*  RefProgram::executeExpression2 (RefChain *chain, Session *sess){ // вычисляет цепочку
	PooledTuple2<RefData**, RefData**> pastWay; // <с, по>   - обработанное поле зрения
	PooledTuple2<RefData**, RefData**> futurWay;// <с, до> - запланированые для обработки поля
	PooledTuple2<size_t, size_t> brackets; // индекс скобки в way, размер ее цепочки
	PooledStack<RefSegment**> segments;
	
	RefData
		**ifrom = chain->at_beforefirst(),
		**iend  = chain->at_afterlast(),
        **iter  = chain->at_first();
	RefDataBracket *tmpbr;
	RefStructBrackets *tmpSbr;
	RefExecBrackets   *tmpEbr;
	size_t tmpsizet;

	RefSegment *segment = 0;
	RefChain *currentChain = chain;

	while(true){
		if (iter == iend){
			//// закончили гулять внутри подцепочки
			if (brackets.getLength()==0){
				// вычисление цепочки для postWay закончено
				if (futurWay.getLength()==0){  // закончили вычисление всего аргумента. компилируем результат
					notrealisedERRORn;
					//return result;
				} else {
					// активируем верхнюю отложенную подцепочку
					futurWay.top_pop(iter, iend);
					continue;
				}
			} else
			if (/*мы в отрезке?*/ brackets.equalTop(0, 0)) { 
				//// выпрыгиваем из отрезка;
				brackets.pop();
				futurWay.top_pop(iter, iend);
				continue; 
			} else {
				//// значит мы внутри скобки и обработали все ее содержимое
				size_t br_index;
				brackets.top_pop(br_index, tmpsizet);
				PooledTuple2<RefData**,RefData**>::TUPLE2 *lnk = pastWay.getPoolLinkByIndex(br_index);
				

				notrealisedERRORn;


			}
		} // end: if iter==end

		//// если перед нами непустая подстрока символов
		if ((*iter)->isRefSymbol()){			
			do {
				//sess->MOVE_TO_next_term(iter);  - сегментация учитывается тут принудительно, поэтому ++ :
				++iter;
			} while(iter != iend && (*iter)->isRefSymbol());
			pastWay.put(ifrom+1, iter-1);
			continue;
		}

		// перед нами отрезок
		if (segment = ref_dynamic_cast<RefSegment>(*iter)){
			if (++iter != iend){
				// откладываем обработку всего, что после сегмента
				futurWay.put(iter, iend);
				brackets.put(0, 0); // кидаем в стек скобок признак того, что мы прыгнули в отрезок, а не в скобку
			}

			// прыгаем в сегмент
			iend = segment->own->first + segment->to + 1;
			iter = segment->own->first + segment->from;
			continue;
		}

		// скобки: () или <>
		if (tmpbr = (*iter)->isDataBracket()){
			if (++iter != iend){
				// откладываем обработку всего, что после скобки
				futurWay.put(iter, iend);
			}

			brackets.put(pastWay.getLength(), 1);      // 1 - чтобы не конфликтовать с отрезками, если эта скобка с индексом 0
			pastWay.put(0, tmpbr->getNewInstance(sess));  // первый 0 - означает что второй - RefDataBracket

			// прыгаем в скобку
			iend = segment->own->first + segment->to + 1;
			iter = segment->own->first + segment->from;
			continue;
		}

		SYSTEMERRORs(sess, "UNREALISED executing for point: " << (*iter)->debug());
		//++iter; // именно ++, а не next_term, так как отрезки отлавливаются здесь
	}

};


RefFunctionBase* RefProgram::findFunction(unistring id){
	std::map<unistring, RefModuleBase*>::iterator modit = modules.begin(), end = modules.end();
	RefModuleBase* mod = 0;

	RefFunctionBase* obj;
	while (modit != end){
		mod = &(*modit->second);

		if (obj = mod->getFunctionByName(id)){
			return obj;
		}
		++modit;
	};
	RUNTIMEERRORn("function " << id << " not found in program");
	return 0;
};


RefTemplateBase* RefProgram::findTemplate(unistring id){
	std::map<unistring, RefModuleBase*>::iterator modit = modules.begin(), end = modules.end();
	RefModuleBase* mod = 0;

	RefTemplateBase* obj;
	while (modit != end){
		mod = &(*modit->second);

		if (obj = mod->getTemplateByName(id)){
			return obj;
		}
		++modit;
	};
	RUNTIMEERRORn("template [" << id << "] not found in program");
	return 0;
};



RefData* RefProgram::createSymbolByCode(unistring code, unistring value){
	std::map<unistring, RefModuleBase*>::iterator modit = modules.begin(), end = modules.end();
	RefDllModule* dllmod = 0;
	RefData* result = 0;

	while (modit != end){
		//TODO: поиск согласно порядку подключения модулей
		dllmod = dynamic_cast<RefDllModule*>(&(*modit->second));
		if (dllmod && (result=dllmod->constructSymbol(code, value))){
			return result;
		} // на данный момент в НЕ dll-модулях не может определяться генератор символов по коду
		++modit;
	}

	COMPILETIMEERRORn("Definition for " << code << " not found in loaded modules");
};



// создает переменную с именем по коду. Ищет в подключенных модулях (среди встроенных переменных и пользовательских шаблонов)
RefData* RefProgram::createVariableByTypename(unistring code, unistring value){
	std::map<unistring, RefModuleBase*>::iterator modit = modules.begin(), end = modules.end();
	RefModuleBase* mod = 0;
	RefDllModule  *dllmod = 0;
	RefUserModule *usermod= 0;
	RefData* result = 0;

	while (modit != end){
		//TODO: сделать поиск согласно порядку подключения модулей
		mod = &(*modit->second);
		dllmod = dynamic_cast<RefDllModule*>(mod);
		if (dllmod){
			result=dllmod->constructVariable(code, value);
			if (result && ref_dynamic_cast<RefVariable>(result)) {
				return result;
			}
			if (result) {
				SYSTEMERRORn("not variable loading like variable: " << result->debug());
			}
		} else {
			usermod = dynamic_cast<RefUserModule*>(mod);
			if (!usermod) SYSTEMERRORn("unknown children of RefModuleBase");
			RefTemplateBase *tp = usermod->getTemplateByName(code);
			if (tp){
				RefTemplateBase *templ = ref_dynamic_cast<RefTemplateBase>(tp);
				if (templ){
					return new RefVarChains(code, value);
				}
			}
		}
		++modit;
	}

	return 0;
};

void RefUserModule::initilizeAll(RefProgram* program){
	std::map<unistring, RefFunctionBase*>::iterator funit = functions.begin(), fend = functions.end();
	std::map<unistring, RefTemplateBase*>::iterator tplit = templates.begin(), tend = templates.end();

	while (tplit != tend){
		tplit->second->initilizeAll(program);
		++tplit;
	}

	while (funit != fend){
		funit->second->initilizeAll(program);
		++funit;
	}

};

unistring RefUserModule::debug(){
	unistring result = "\n@UserModule " + getName() + "\n";

	std::map<unistring, RefFunctionBase*>::iterator funit = functions.begin(), fend = functions.end();
	std::map<unistring, RefTemplateBase*>::iterator tplit = templates.begin(), tend = templates.end();

	while (tplit != tend){
		result += tplit->second->debug() + "\n";
		++tplit;
	}

	while (funit != fend){
		result += funit->second->debug() + "\n";
		++funit;
	}
	return result;
};



void RefModuleBase::setFunctionByName(unistring name, RefFunctionBase* o){
	std::map<unistring, RefFunctionBase*>::iterator iter = functions.find(name);
	if (iter != functions.end()) { COMPILETIMEERRORn("function multi-definition"); }
		functions[name] = o;
};

void RefModuleBase::setTemplateByName(unistring name, RefTemplateBase* o){
	std::map<unistring, RefTemplateBase*>::iterator iter = templates.find(name);
		if (iter != templates.end()) {	COMPILETIMEERRORn("template multi-definition"); }
		templates[name] = o;
};


RefData* RefDllModule::constructSymbol(unistring typecode, unistring value){
		std::map<unistring, RefData*(*)(unistring)>::iterator iter = dataConstructors.find(typecode);
		if (iter==dataConstructors.end()) return 0;
		return (*iter->second)(value);
};


RefData* RefDllModule::constructVariable(unistring typecode, unistring value){
		std::map<unistring, RefData*(*)(unistring)>::iterator iter = varConstructors.find(typecode);
		if (iter==varConstructors.end()) return 0;
		return (*iter->second)(value);
};




RefModuleBase::~RefModuleBase(){
		std::set<void*> deleted;

		std::map<unistring, RefFunctionBase*>::iterator it = functions.begin();
		while(it != functions.end()){
			//std::cout << "\n~ " << it->first;
			if (deleted.find(it->second)==deleted.end()) {
				deleted.insert(it->second);
				delete it->second;
			}
			it->second = 0;
			++it;
		}

		deleted.clear();

		std::map<unistring, RefTemplateBase*>::iterator itt = templates.begin();
		while(itt != templates.end()){
			//std::cout << "\n~ " << itt->first;
			if (deleted.find(itt->second)==deleted.end()) {
				deleted.insert(itt->second);
				delete itt->second;
			}
			itt->second = 0;
			++itt;
		}
	};
RefFunctionBase* RefModuleBase::getFunctionByName(unistring nm, Session *s){
		std::map<unistring, RefFunctionBase*>::iterator iter = functions.find(nm);
		if (iter != functions.end()) return iter->second;
		return 0;
	};
RefTemplateBase* RefModuleBase::getTemplateByName(unistring nm, Session *s){
		std::map<unistring, RefTemplateBase*>::iterator iter = templates.find(nm);
		if (iter != templates.end()) return iter->second;
		return 0;

	};

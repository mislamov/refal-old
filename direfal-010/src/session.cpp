#include "session.h"

#include "function.h"
#include "program.h"

#ifdef DEBUG
#define LOGSTEP(s) \
	std::cout << s << " | " << ((activeTemplate && *activeTemplate) ? (*activeTemplate)->debug():"null") << "\t\t~\t\t" << std::flush << (s=="BACK"?"":chain_to_text(r?r+1:0, arg_l?arg_r:0, 50)) << "\n" << std::flush;
#define LOGMATCH() \
	std::cout << "\n\nSTEP: "<< ++(program->step) <<"\n###### maps:" << varMapStack.getCount() << "\n" << (isdemaching?"DMTCH|":"START| ") << (thetmplate && !thetmplate->isEmpty() ? thetmplate->debug() : "$empty") << "\t\t~\t\t" << std::flush << (!arg_l?" $empty":chain_to_text(arg_l, arg_r, 50)) << "\n" << std::flush;
#else
#define LOGSTEP(s)
#define LOGMATCH()
#endif




// сопоставляет образец tmplate с объектным выражением arg.
// isdemaching - признак того, что надо продолжить матчинг от предыдущего удачного состояния (напр в цепочке условий)
// ТОЛЬКО ДЛЯ ЦЕЛОГО ОБРАЗЦА В ПРЕДЛ. ИЛИ УСЛОВИИ
// Политика управления varMapб current_LR задается из вне.
// TODO: подумать над возможностью пердавать 2 chain в аргументах, а не 1 chain и 2 dot.
bool  Session::matching(RefObject *initer, RefChain *thetmplate, RefData **arg_l, RefData **arg_r, bool isdemaching) {
#ifdef TESTCODE
	if (! varMapStack.getCount()) SYSTEMERRORs(this, "createVarMap() wanted! No varmaps in stack for matching");
#endif

	//LOG("New MATCHING : tmplateChain=" << thetmplate->debug() << "  isDematching="<<isdemaching);
    RefData **activeTemplate = 0, **l=0, **r=0;

    if (isdemaching) {
        // продолжаем ранее успешное сопоставление
		if (thetmplate->isEmpty()) return false; // дематчинг пустых векторов - неудача
        result_sost = BACK;
		activeTemplate = (*thetmplate)[-1];
		current_view_borders.put(arg_l, (!arg_l ? 0 : arg_r) );
    } else {
        // начинаем новое сопоставление с argl..argr
		if (thetmplate->isEmpty()) return !arg_l; // дематчинг пустых векторов - неудача
        result_sost = GO;
		l = 0;
		r = arg_l ? arg_l-1 : 0;
        activeTemplate = (*thetmplate)[0];
		current_view_borders.put(arg_l, (!arg_l ? 0 : arg_r) );
    }

	this->setTmplate(thetmplate);
	LOGMATCH();

	while (true) {
        // сопоставляем текущий шаблон

        switch (result_sost) {

        case GO: {
			if (!activeTemplate || activeTemplate == tmplate()->at(-1)+1){ // достигнут правый край сопоставления! DataDOT
				//TODO: привести все методы к одному условию
				if (this->tmplate()!=thetmplate){ // завершилось сопоставление user-шаблона
					#ifdef TESTCODE
						if (! termChainsJumpPoints.getLength()) AchtungERRORs(this);
					#endif
					RefVarChains* var1 = ref_dynamic_cast<RefVarChains>(* termChainsJumpPoints.top());
					if (var1) {
						result_sost = var1->success(activeTemplate, this, l, r);
					}else{
						RefVariantsChains* var2 = ref_dynamic_cast<RefVariantsChains>(* termChainsJumpPoints.top());
						result_sost = var2->success(activeTemplate, this, l, r);
					}
					break;
				}
				activeTemplate = activeTemplate ? GET_pred_template(activeTemplate) : tmplate()->at(-1);  // когда шаблон исчерпан, а аргумент еще нет - ошибка
				result_sost = (r==arg_r) ? SUCCESS : BACK;  // не двигали r вперед => сравниваем с (*arg)[-1]
				break;
			}
            LOGSTEP("GO  ");
            #ifdef TESTCODE
            if (l && !r) {   
				SYSTEMERRORs(this, "RefData::init() tring to matching with NULL address!");            
			};
            #endif
            l=0;
            result_sost = (*activeTemplate)->init(activeTemplate, this, l, r); /// ШАГ ВПЕРЕД
            break;
        }
        case BACK: {
			//if (activeTemplate== this->tmplate()->at(0)-1){ // достигнут левый край сопоставления! DataDOT
			if (!activeTemplate || activeTemplate== this->tmplate()->at(0)-1){ // достигнут левый край сопоставления! DataDOT
				//TODO: привести все методы к одному условию
				if (this->tmplate()!=thetmplate){ // завершилось сопоставление user-шаблона
					#ifdef TESTCODE
						if (! termChainsJumpPoints.getLength()) AchtungERRORs(this);
					#endif
					RefVarChains* var1 = ref_dynamic_cast<RefVarChains>(* termChainsJumpPoints.top());
					if (var1){
						result_sost = var1->failed(activeTemplate, this, l, r);
					}else{
						RefVariantsChains* var2 = ref_dynamic_cast<RefVariantsChains>(* termChainsJumpPoints.top());
						result_sost = var2->failed(activeTemplate, this, l, r);
					}
					break;
				}
				//activeTemplate = activeTemplate ? GET_next_template(activeTemplate) : tmplate()->at(0);  // когда шаблон исчерпан, а аргумент еще нет - ошибка
				result_sost = FAIL;
				break;
			}
            LOGSTEP("BACK");
            result_sost = (*activeTemplate)->back(activeTemplate, this, l, r); /// ШАГ НАЗАД
            break;
        }

        case SUCCESS :
            #ifdef DEBUG
			std::cout << "SUCCESS\n######\n";
            #endif
			current_view_borders.pop();
			popTmplate();
            return true;

        case ERROR :
            #ifdef DEBUG
			std::cout << "ERROR\n######\n";
            #endif
			current_view_borders.pop();
			popTmplate();
            return false;
        case FAIL   :
            #ifdef DEBUG
			std::cout << "FAIL\n######\n";
            #endif
			current_view_borders.pop();
			popTmplate();
            return false;



        default:
            break;
        }
    };
};


unistring Session::debug(){
		std::ostringstream s;

		for (int i=varMapStack.getCount()-1; i>=0; --i){
			s << "--------------------------------------- " << i+1 << "\n";
			s << varMapStack.pool[i]->debug();
		}
		return s.str();
};

/*
unistring MatchState::debug(){
		std::ostringstream s;

		s << "****\tMatchState:\t" << std::flush << chain_to_text(view_l, view_r) << "\t~\t" << tpl->debug() << "\n";
		s << varmap.debug();
		return s.str();
};
*/




// ищет по имени переменной ее облать видимости
bool VarMap::findByName(unistring name, RefData** &l, RefData** &r, VarMap *&vm) {
        for (size_t ind = last_ind; ind>=0; --ind) {
            if (pool[ind].i1->getName()==name) {
                l  = pool[ind].i2;
                r  = pool[ind].i3;
				vm = pool[ind].i4;
                return true;
            }
        }
            return false;
};

// ищет по ссылке на переменную ее облать видимости
bool VarMap::findByLink(RefVariable* var, RefData** &l, RefData** &r, VarMap *&vm) {
        for (size_t ind = last_ind; ind>=0; --ind) {
            if (pool[ind].i1==var) {
                l = pool[ind].i2;
                r = pool[ind].i3;
				vm = pool[ind].i4;
                return true;
            }
        }
            return false;
};

bool VarMap::folowByWay(unistring path, RefData** &l, RefData** &r){
    #ifdef TESTCODE
	if (path == EmptyUniString) {
		AchtungERRORn;
	}
    #endif
	long t_from  = 0;
    long t_to    = -1;
    unistring vname;
	VarMap *vm = this;

	do {
        t_from = t_to+1;
        t_to   = path.find(varPathSeparator, t_from);
        vname = path.substr(t_from, t_to-t_from);

		if (!vm) return false;
		vm->findByName(vname, l, r, vm);
    } while (t_to != std::string::npos);
	return true;
}

	
unistring VarMap::debug(){
		std::ostringstream s;

		s << "****\t\tVarMap pool:   (by"<< (creator?creator->debug().substr(0, 15):" 0 ") <<")" << std::flush << "\n";
		size_t ind = last_ind;
		while(ind){
			s << "****\t\t\t" << ind << ") " << std::flush << pool[ind].i1->debug() << " : " << chain_to_text( pool[ind].i2,  pool[ind].i3 ) << "\n";
			--ind;
		};
		return s.str();
};

/*
// TODO:а нужна ли промежуточная ф-я? проверить когда все отлажено
void Session::saveVar   (RefData** activeTemplate, RefData** &l, RefData** &r) { // сохраняет состояние переменной
        RefVariable* var = ref_dynamic_cast<RefVariable>(*activeTemplate);
        if (var){
            saveVar(this, (RefVariable*)var, l, r);
        }
//		LOG("save: " << var->getName() << " : " << ((l && *l) ? (*l)->debug() : "null") << " .. " <<  (r&& *r &&(current_view_l()-1-r)?(*r)->debug():"null"));
};
    
// TODO:а нужна ли промежуточная ф-я? проверить когда все отлажено
void Session::restoreVar(RefData** activeTemplate, RefData** &l, RefData** &r){ // восстанавливает состояние переменной
        RefVariable* var = ref_dynamic_cast<RefVariable>(*activeTemplate);
        if (!var) SYSTEMERROR("not var restoring!");

        restoreVar(this, var, l, r); // для польз-переменной varMatchState хранит ее подсессию
};
*/

// TODO: оптимизировать!
RefChain*  Session::substituteExpression(RefChainConstructor *chain){
	if (! chain->leng) return new RefChain();

	RefChain *result = new RefChain(chain->leng);
	RefLinkToVariable *link = 0;
	RefDataBracket   *brack = 0;
	RefData **enditem = (*chain)[-1]+1;
	for(RefData **item = (*chain)[0]; item < enditem; ++item){
		link = ref_dynamic_cast<RefLinkToVariable>(*item);
		if (link){
			RefData **endi, **i;
			VarMap* vm = 0;
			findVar(link->lnk, i, endi, vm);
			if (link->path != EmptyUniString){
				// заглядывание в пользовательскую переменную
				if (! vm->folowByWay(link->path, i, endi)) RUNTIMEERRORs(this, "Wrong way for variable " << link->lnk->toString() << " : " << link->path);
			}
			if (i){
				++endi;
				for( ; i < endi; ++i){
					*result += *i;
				}
			}

			continue;
		}
		brack = ref_dynamic_cast<RefDataBracket>(*item);
		if (brack){
			if (ref_dynamic_cast<RefStructBrackets>(brack)){
				*result +=  new RefStructBrackets( substituteExpression((RefChainConstructor*) brack->chain) ); //TODO: опасно! когда RefChainConstructor != RefChain
			} else {
				// RefExecBracket
				*result +=  new RefExecBrackets( substituteExpression((RefChainConstructor*) brack->chain) ); //TODO: опасно! когда RefChainConstructor != RefChain
			}

			continue;
		}
		*result += *item;
	}
	return result;
};


void Session::printExecTrace(){
	unistring tab = "";
	while (execTrace.getLength()){
		std::cout << tab  << "<" << execTrace.top1()->getName() << " " << chain_to_text(execTrace.top2(), execTrace.top3()) << " >\n";
		execTrace.pop();
		tab += "   ";
	}
}
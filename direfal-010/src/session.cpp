#include "session.h"

#include "function.h"

#ifdef DEBUG
#define LOGSTEP(s) \
	std::cout << s << "\t" << (*activeTemplate?(*activeTemplate)->debug():"null") << " ~ " << std::flush << (s=="BACK"?"":chain_to_text(r?r+1:0, arg_l?arg_r:0)) << "\n" << std::flush;
#else
#define LOGSTEP(s)
#endif




// сопоставляет образец tmplate с объектным выражением arg.
// isdemaching - признак того, что надо продолжить матчинг от предыдущего удачного состояния (напр в цепочке условий)
// ТОЛЬКО ДЛЯ ЦЕЛОГО ОБРАЗЦА В ПРЕДЛ. ИЛИ УСЛОВИИ
// Политика управления varMapб current_LR задается из вне.
bool  Session::matching(RefObject *initer, RefChain *tmplate, RefData **arg_l, RefData **arg_r, bool isdemaching) {
#ifdef TESTCODE
	if (! varMapStack.getCount()) SYSTEMERROR("createVarMap() wanted! No varmaps in stack for matching");
#endif

	LOG("New MATCHING : tmplateChain=" << tmplate->debug() << "  isDematching="<<isdemaching);
    RefData **activeTemplate = 0, **l=0, **r=0;

    if (isdemaching) {
        // продолжаем ранее успешное сопоставление
		if (tmplate->isEmpty()) return false; // дематчинг пустых векторов - неудача
        result_sost = BACK;
		activeTemplate = (*tmplate)[-1];
		current_view_borders.put(arg_l, (!arg_l ? 0 : arg_r) );
    } else {
        // начинаем новое сопоставление с argl..argr
		if (tmplate->isEmpty()) return !arg_l; // дематчинг пустых векторов - неудача
        result_sost = GO;
		l = 0;
		r = arg_l ? arg_l-1 : 0;
        activeTemplate = (*tmplate)[0];
		current_view_borders.put(arg_l, (!arg_l ? 0 : arg_r) );
    }

	this->setTmplate(tmplate);
	while (true) {
        // сопоставляем текущий шаблон

        switch (result_sost) {

        case GO: {
			if (activeTemplate == this->tmplate()->at(-1)+1){ // достигнут правый край сопоставления! DataDOT
				if (userVarJumpPoints.getLength()){ // это был user-шаблон
					RefUserVar** var = userVarJumpPoints.top();
					(*var)->success(activeTemplate, this, l, r);
					result_sost = GO;
					break;
				}
				MOVE_TO_pred_template( activeTemplate ); // ?
				result_sost = (r==arg_r) ? SUCCESS : BACK;  // не двигали r вперед => сравниваем с (*arg)[-1]
				break;
			}
            LOGSTEP("GO  ");
            #ifdef TESTCODE
            if (l && !r) {   
				SYSTEMERROR("RefData::init() tring to matching with NULL address!");            
			};
            #endif
            l=0;
            result_sost = (*activeTemplate)->init(activeTemplate, this, l, r); /// ШАГ ВПЕРЕД
            break;
        }
        case BACK: {
			if (activeTemplate== this->tmplate()->at(0)-1){ // достигнут левый край сопоставления! DataDOT
				if (userVarJumpPoints.getLength()){ // это был user-шаблон
					RefUserVar** var = userVarJumpPoints.top();
					(*var)->failed(activeTemplate, this, l, r);
					result_sost = BACK;
					break;
				}
				MOVE_TO_next_template( activeTemplate ); // ?
				result_sost = FAIL;
				break;
			}
            LOGSTEP("BACK");
            result_sost = (*activeTemplate)->back(activeTemplate, this, l, r); /// ШАГ НАЗАД
            break;
        }

        case SUCCESS :
			current_view_borders.pop();
            return true;

        case ERROR :
            //return -1;
            #ifdef DEBUG
            LOG( "ERROR signal when maching!" );
            #endif
			current_view_borders.pop();
            return false;
        case FAIL   :
            #ifdef DEBUG
            LOG( "FAIL signal when maching!" );
            #endif
			current_view_borders.pop();
            return false;



        default:
            break;
        }
    };
};


unistring Session::debug(){
		std::ostringstream s;
		s << varMapStack.top()->debug();
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
bool VarMap::findByName(unistring name, RefData** &l, RefData** &r) {
        for (size_t ind = last_ind; ind>=0; --ind) {
            if (pool[ind].i1->getName()==name) {
                l = pool[ind].i2;
                r = pool[ind].i3;
                return true;
            }
        }
            return false;
};

// ищет по ссылке на переменную ее облать видимости
bool VarMap::findByLink(RefVariable* var, RefData** &l, RefData** &r) {
        for (size_t ind = last_ind; ind>=0; --ind) {
            if (pool[ind].i1==var) {
                l = pool[ind].i2;
                r = pool[ind].i3;
                return true;
            }
        }
            return false;
};

	
unistring VarMap::debug(){
		std::ostringstream s;

		s << "****\t\tVarMap pool:" << std::flush << "\n";
		size_t ind = last_ind;
		while(ind){
			s << "****\t\t\t" << ind << ") " << std::flush << pool[ind].i1->debug() << " : " << chain_to_text( pool[ind].i2,  pool[ind].i3 ) << "\n";
			--ind;
		};
		return s.str();
};


// TODO:а нужна ли промежуточная ф-я? проверить когда все отлажено
void Session::SAVE_VAR_STATE   (RefData** activeTemplate, RefData** &l, RefData** &r) { // сохраняет состояние переменной
        RefVariable* var = ref_dynamic_cast<RefVariable>(*activeTemplate);
        if (var){
            saveVar(this, (RefVariable*)var, l, r);
        }
		LOG("save: " << var->getName() << " : " << ((l && *l) ? (*l)->debug() : "null") << " .. " <<  (r&& *r &&(current_view_l()-1-r)?(*r)->debug():"null"));
};
    
// TODO:а нужна ли промежуточная ф-я? проверить когда все отлажено
void Session::RESTORE_VAR_STATE(RefData** activeTemplate, RefData** &l, RefData** &r){ // восстанавливает состояние переменной
        RefVariable* var = ref_dynamic_cast<RefVariable>(*activeTemplate);
        if (!var) SYSTEMERROR("not var restoring!");

        restoreVar(this, var, l, r); // для польз-переменной varMatchState хранит ее подсессию
};


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
			getVariableValue(link->lnk, i, endi);
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

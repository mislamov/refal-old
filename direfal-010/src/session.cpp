#include "session.h"

#include "function.h"


unistring getTextOfChain(RefData** from, RefData** to){
	if (!from || !*from) return "[null]";
	if (!to || (to-from)<0 || (to-from)>1024) return "[error string]";
	unistring res = "";
	int i = 0;
	while(from+i <= to){
		if(from[i]) res += from[i]->debug();
		++i;
	}
	return res;
};

#define LOGSTEP(s) \
	std::cout << s << "\t" << (*activeTemplate?(*activeTemplate)->debug():"null") << " ~ " << std::flush << (s=="BACK"?"":getTextOfChain(r?r+1:0, argr)) << "\n" << std::flush;


MatchState* Session::saveCurrentState(RefData** ll, RefData** rr, RefChain *tpl) { // сохраняет и возвращает ссылку на состояние сопоставления для предложения
		MatchState* res = new MatchState(current_view_l=ll, current_view_r=rr, tpl);
        matchStates.push( res );
		return res;
};




// сопоставляет образец tmplate с объектным выражением с l по r.
// isdemaching - признак того, что надо продолжить матчинг от предыдущего удачного состояния (напр в цепочке условий)
// ТОЛЬКО ДЛЯ ЦЕЛОГО ОБРАЗЦА В ПРЕДЛ. ИЛИ УСЛОВИИ
bool  Session::matching(RefObject *initer, RefChain *tmplate, RefChain *arg, bool isdemaching, bool isRevers) {
	RefData **argl = (*arg)[0], **argr=0;
	if (! arg->isEmpty()){
		argr = (*arg)[-1];
	} 

	#ifdef TESTCODE
	if (argl-argr>0) 
		AchtungERROR;
	#endif


    LOG("New MATCHING : tmplateChain=" << tmplate->debug() << "  isDematching="<<isdemaching);
    RefData **activeTemplate = 0, **l=0, **r=0;

    if (isdemaching) {
        // продолжаем ранее успешное сопоставление
		AchtungERROR;
        //result_sost = BACK;
        //activeTemplate = tmplate->get_last();
    } else {
        // начинаем новое сопоставление с argl..argr
        result_sost = GO;
		l = 0;
		r = argl?argl-1:0;
        activeTemplate = (*tmplate)[0];

		saveCurrentState(argl, argr, tmplate); // сохр. состояние перед вычислением условия предложения
    }

	while (true) {
        // сопоставляем текущий шаблон

        switch (result_sost) {

        case GO: {
			if (activeTemplate==(*tmplate)[-1]+1){ // достигнут правый край сопоставления! DataDOT
				--activeTemplate;
				result_sost = (r==argr) ? SUCCESS : BACK;
				break;
			}
            LOGSTEP("GO  ");
            #ifdef TESTCODE
            if (l && !r) {   SYSTEMERROR("RefData::init() tring to matching with NULL address!");            };
            #endif
            l=0;
            result_sost = (*activeTemplate)->init(activeTemplate, this, l, r); /// ШАГ ВПЕРЕД
            break;
        }
        case BACK: {
			if (activeTemplate==(*tmplate)[0]-1){ // достигнут левый край сопоставления! DataDOT
				++activeTemplate;
				result_sost = FAIL;
				break;
			}
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

unistring MatchState::debug(){
		std::ostringstream s;

		s << "****\tMatchState:\t" << std::flush << getTextOfChain(view_l, view_r) << "\t~\t" << tpl->debug() << "\n";
		s << varmap.debug();
		return s.str();
};





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
bool VarMap::findByLink(RefVariable* var, RefData** &l, RefData** &r, MatchState *&matchState) {
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
			s << "****\t\t\t" << ind << ") " << std::flush << pool[ind].i1->debug() << " : " << getTextOfChain( pool[ind].i2,  pool[ind].i3 ) << "\n";
			--ind;
		};
		return s.str();
};


void Session::MOVE_TO_next_term(RefData** &p){
	if (p == current_view_r || !p) {
		p=0;
	} else {
		++p;
	}
}

void Session::MOVE_TO_pred_term(RefData** &p){
	if (p == current_view_l || !p) {
		p=0;
	} else {
		--p;
	}
}


void Session::SAVE_VAR_STATE   (RefData** activeTemplate, RefData** &l, RefData** &r) { // сохраняет состояние переменной
        RefVariable* var = ref_dynamic_cast<RefVariable>(*activeTemplate);
        if (var){
            matchStates.top()->saveVar(this, (RefVariable*)var, l, r);
        }
		LOG("save: " << var->getName() << " : " << ((l && *l) ? (*l)->debug() : "null") << " .. " <<  (r&& *r &&(current_view_l-1-r)?(*r)->debug():"null"));
};
    
//void SAVE_VAR_STATE_AND_VALUE(RefData** activeTemplate); // сохраняет состояние и значение переменной
void Session::RESTORE_VAR_STATE(RefData** activeTemplate, RefData** &l, RefData** &r){ // восстанавливает состояние переменной
        RefVariable* var = ref_dynamic_cast<RefVariable>(*activeTemplate);
        if (!var) SYSTEMERROR("not var restoring!");

        MatchState *varMatchState;
        matchStates.top()->restoreVar(this, var, varMatchState, l, r); // для польз-переменной varMatchState хранит ее подсессию
};
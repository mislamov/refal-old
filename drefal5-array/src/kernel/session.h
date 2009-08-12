#ifndef SESSION_H_INCLUDED
#define SESSION_H_INCLUDED

#include <stack>
#include <stdlib.h>

#include "data.h"
#include "rfunction.h"
#include "poolTuples.h"

class VarMap;
class MatchState;
class RefVariableBase;
class RefStructBracket;


class VarMapItem {
public:
    RefVariableBase* var;   // сама переменна€
    RefData** l;            // значение..
    RefData** r;            // ..значение
    MatchState* matchState; // состо€ние сопоставлени€ (дл€ польз-их шаблонов)

    VarMapItem() {
        var=0;
        l=r=0;
        matchState=0;
    };

	VarMapItem(RefVariableBase* vv,RefData** ll,RefData** rr,MatchState* mm=0) {
        var=vv;
        l=ll;
		r=rr;
        matchState=mm;
    };
};



class VarMap : public PooledTuple4<RefVariableBase*, RefData** , RefData** , MatchState*>{
public:
	VarMap(void *own = 0) {
        pool[0].i1 = (RefVariableBase*)own;
    };


    // ищет по имени переменной ее облать видимости
    bool findByName(unistring name, RefData** &l, RefData** &r) {
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
	bool findByLink(RefVariableBase* var, RefData** &l, RefData** &r, MatchState *&matchState) {
        for (size_t ind = last_ind; ind>=0; --ind) {
            if (pool[ind].i1==var) {
                l = pool[ind].i2;
                r = pool[ind].i3;
                return true;
            }
        }
            return false;
    };


	void showDebugInfo(){
		std::cout << "****\t\tVarMap pool:" << std::flush << "\n";
		size_t ind = last_ind;
		while(ind){
			std::cout << "****\t\t\t" << ind << ") " << std::flush << pool[ind].i1->toString() << " : " << getTextOfChain(beginOfTerm(pool[ind].i2), endOfTerm(pool[ind].i3)) << "\n";
			--ind;
		};
	};
};

// блок сопоставлений (откатываемый)
class MatchState {
    VarMap varmap; // карта сопоставлени€
    RefData** view_l;   // аргумент сопоставлени€ всего образца
    RefData** view_r;

public:
	RefChain *tpl;
	
	MatchState(RefData** ll, RefData** rr, RefChain *tl) {
        view_l=ll;
        view_r=rr;
		tpl = tl;
    };

    // сохран€ет состо€ние переменной
    void saveVar(Session *s, RefVariableBase *varOrData, RefData **&l, RefData **&r);
    void restoreVar(Session *s, RefVariableBase *varOrData, MatchState* &matchState, RefData **&l, RefData **&r);
	bool findVar(RefVariableBase *var, RefData **&l, RefData **&r, MatchState* &matchState);

	void showDebugInfo(){
		std::cout << "****\tMatchState:\t" << std::flush << getTextOfChain(view_l, view_r) << "\t~\t" << tpl->toString() << "\n";
		varmap.showDebugInfo();
	};
};


class Session {
    friend class MatchState;
	friend class RefData_DOT;
	friend class RefStructBracket;

    std::stack<MatchState*>  matchStates;
	DataLinkPooledStack<RefData**> stackOfDataSkob;		// стек сопоставлени€ скобок
	DataLinkPooledStack<RefData**> stackOfDataSkob_done;	// стек удачного сопоставлени€ скобок
    RefData** current_view_l;
    RefData** current_view_r;
public:
	Session(){
		current_view_l = current_view_r = 0;
	};

    TResult  result_sost;

	inline bool getBodyByLink(RefVariableBase *var, RefData **&l, RefData**&r, MatchState *&matchState ) {
		return matchStates.top()->findVar(var, l, r, matchState);
    };

    RefData** getTopDataSkob() { // RefData так как не только скобки но и границы аргументов
        return stackOfDataSkob.top();
    };
	void setTopDataSkob(RefData** b) {
		stackOfDataSkob.put(b);
    };


    // сопоставл€ет образец tmplate с объектным выражением с l по r.
    // isdemaching - признак того, что надо продолжить матчинг от предыдущего удачного состо€ни€ (напр в цепочке условий)
    bool  matching(RefObject *initer, RefChain *tmplate, RefData **l, RefData **r, bool isdemaching, bool isRevers);
    // оптимально вычисл€ет объектное выражение с функциональными вызовами в ќ¬ без угловых скобок
    // ¬ызываетс€ подстановкой в предложении пользовательской функциии и перед вычислением условий
    // если выр-е без <.>, то возвращаетс€ аргумент (Ќ≈  ќѕ»я!)
    RefChain*  executeExpression (RefChain *);
    // готовит подстановку: замен€ет переменные значени€ми. ѕолучаем ќ¬ с угловыми скобками
    RefChain*  substituteExpression(RefChain *);

    RefObject* findFunctionById(unistring id);

    MatchState* saveCurrentStateLarge(RefData** ll, RefData** rr, RefChain *tpl) { // сохран€ет и возвращает ссылку на состо€ние сопоставлени€ дл€ предложени€
		MatchState* res = new MatchState(current_view_l=ll, current_view_r=rr, tpl);
		stackOfDataSkob.put(current_view_r+1);
        matchStates.push( res );
		return res;
    };
    MatchState* saveCurrentStateSmall(RefData** ll, RefData** rr, RefChain *tpl) { // сохран€ет и возвращает ссылку на состо€ние сопоставлени€ образца
		MatchState* res = new MatchState(current_view_l=ll, current_view_r=rr, tpl);
        matchStates.push( res );
		return res;
    };
    void restoreToLastSavedStateLarge(); // возвращаетс€ к состо€нию на начало выполнени€ предложени€
    void restoreToLastSavedState(); // возвращаетс€ к предыдущему состо€нию
    void clearAllStatesAfter(MatchState*); // очищает от всего, что было создано после сохранени€ состо€ни€ ј–√

    void SAVE_VAR_STATE   (RefData** activeTemplate, RefData** &l, RefData** &r) { // сохран€ет состо€ние переменной
        RefVariableBase* var = ref_dynamic_cast<RefVariableBase>(*activeTemplate);
        if (var){
            matchStates.top()->saveVar(this, (RefVariableBase*)var, l, r);
        }
		LOG("save: " << var->getName() << " : " << ((l && *l) ? (*l)->toString() : "null") << " .. " <<  (*r&&(current_view_l-1-r)?(*r)->toString():"null"));
    };
    //void SAVE_VAR_STATE_AND_VALUE(RefData** activeTemplate); // сохран€ет состо€ние и значение переменной
    void RESTORE_VAR_STATE(RefData** activeTemplate, RefData** &l, RefData** &r){ // восстанавливает состо€ние переменной
        RefVariableBase* var = ref_dynamic_cast<RefVariableBase>(*activeTemplate);
        if (!var) SYSTEMERROR("not var restoring!");

        MatchState *varMatchState;
        matchStates.top()->restoreVar(this, var, varMatchState, l, r); // дл€ польз-переменной varMatchState хранит ее подсессию
    };

	void showDebugInfo(){
		std::cerr << "\n***** SESS **********************\n";
		this->matchStates.top()->showDebugInfo();
	}
};

inline void MatchState::saveVar(Session *s, RefVariableBase *varOrData, RefData **&l, RefData **&r) {
    varmap.put(varOrData, l, r, 0);
};

inline void MatchState::restoreVar(Session *s, RefVariableBase *varOrData, MatchState* &matchState, RefData **&l, RefData **&r) {
    varmap.top_pop(varOrData, l, r, matchState);
};

inline bool MatchState::findVar(RefVariableBase *var, RefData **&l, RefData **&r, MatchState* &matchState) {
	return varmap.findByLink(var, l, r, matchState);
};


/*
#define SAVE_STATE(activeTemplate) { \
    s->getCurrentSopostStack()->push( new TVarBody(l, r, activeTemplate) ); \
    std::cout << "\nsave : "; print_vector(l, r); std::cout << "\n" << std::flush; \
}; \

#define RESTORE_STATE(tpl) { \
    TVarBody *tvb = s->getCurrentSopostStack()->top(); \
    l=tvb->first;r=tvb->second; \
    if (tvb->owner!=tpl) SYSTEMERROR("mmmm: tvb->owner(" << tvb->owner->toString() << ") !=  tpl("<<tpl->toString()<<")"); \
    s->getCurrentSopostStack()->pop(); \
}; \

#define SAVE_STATE_AND_VAR(activeTemplate) { \
    s->getCurrentSopostStack()->push( s->setVarBody(name, new TVarBody(l, r, this)) ); \
    LOG( "\nsave(" << name << ") : "; print_vector(l, r); std::cout << "\n" ) \
};
*/


#endif

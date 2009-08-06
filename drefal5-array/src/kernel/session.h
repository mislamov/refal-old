#ifndef SESSION_H_INCLUDED
#define SESSION_H_INCLUDED

#include <stack>

#include <stdlib.h>

#include "data.h"
#include "rfunction.h"

class VarMap;
class RefVariableBase;

class VarMapItem {
    public:
    RefVariableBase* var; // сама переменная
    RefData** l;          // значение..
    RefData** r;          // ..значение
    VarMap*   matchState; // состояние сопоставления (для польз-их шаблонов)

    VarMapItem() {
        var=0;
        l=r=0;
        matchState=0;
    };
};

size_t POOLSIZE_DEFAULT = 128;

class VarMap {
    VarMapItem *pool;
    size_t last_ind;   // индекс последнего в стеке элемента
    size_t poolsize;   // индекс последнего в стеке элемента

public:
    VarMap(void *own = 0){
        last_ind = 0;
        poolsize = POOLSIZE_DEFAULT;
        pool = (VarMapItem*)malloc( sizeof(VarMapItem)*POOLSIZE_DEFAULT );
        pool[0].var = (RefVariableBase*)own;
    };

    ~VarMap(){
        free(pool);
    };

    // сохраняет состояние переменной
    void put(RefVariableBase *var, RefData** l, RefData** r, VarMap* matchState) {
        ++last_ind ;
        if (last_ind >= poolsize) {
            // пул исчерпан
            LOG("VarMapItem-pool is full. realloc!");
            poolsize += POOLSIZE_DEFAULT;
            pool = (VarMapItem*) realloc(pool, poolsize*sizeof(VarMapItem) );
            if (!pool) {
                RUNTIMEERROR("VarMapItem-pool", "not anouth memory");
                return;
            }
        }

        VarMapItem pool_last_ind = pool[last_ind];
        pool_last_ind.var = var;
        pool_last_ind.l = l;
        pool_last_ind.r = r;
        pool_last_ind.matchState = matchState;
        return;
    };

    void top_pop(RefVariableBase *var, RefData** &l, RefData** &r, VarMap* &matchState) {
        #ifdef TESTCODE
        if (var != pool[last_ind].var) {
            SYSTEMERROR("var != pool.var");
        }
        #endif

        VarMapItem pool_last_ind = pool[last_ind];
        l = pool_last_ind.l;
        r = pool_last_ind.r;
        matchState = pool_last_ind.matchState;
        --last_ind;

        // TODO (Islamov#1#): может убрать:
        #ifdef DEBUG
        pool_last_ind = pool[last_ind+1];
        pool_last_ind.var = 0;
        pool_last_ind.l = 0;
        pool_last_ind.r = 0;
        pool_last_ind.matchState = 0;
        #endif
    };

    // ищет по имени переменной ее облать видимости
    bool findByName(unistring name, RefData** &l, RefData** &r) {
        for (size_t ind = last_ind; ind>=0; --ind) {
            if (pool[ind].var->getName()==name) {
                l = pool[ind].l;
                r = pool[ind].r;
                return true;
            }
            return false;
        }
    };

    void clear(){
        last_ind = 0;
        pool[0].var = 0;
    };

};

class MatchState {
    VarMap varmap; // карта сопоставления
    RefData** l;   // аргумент
    RefData** r;

    MatchState(RefData** ll, RefData** rr){ l=ll; r=rr; };
};

class Session {
    std::stack<MatchState*>  matchStates;
    std::stack<RefBracketBase**> stackOfDataSkob; // стек сопоставления скобок
    RefData** current_l;
    RefData** current_r;
public:
    TResult  result_sost;

    TVarBody* getBodyByLink(RefVariable*) {
        SYSTEMERROR("not realized");
    };
    RefBracketBase** getTopDataSkob() {
        return stackOfDataSkob.top();
    }

    // сопоставляет образец tmplate с объектным выражением с l по r.
    // isdemaching - признак того, что надо продолжить матчинг от предыдущего удачного состояния (напр в цепочке условий)
    bool  matching(RefObject *initer, RefChain *tmplate, RefData **l, RefData **r, bool isdemaching, bool isRevers);
    // оптимально вычисляет объектное выражение с функциональными вызовами в ОВ без угловых скобок
    // Вызывается подстановкой в предложении пользовательской функциии и перед вычислением условий
    // если выр-е без <.>, то возвращается аргумент (НЕ КОПИЯ!)
    RefChain*  executeExpression (RefChain *);
    // готовит подстановку: заменяет переменные значениями. Получаем ОВ с угловыми скобками
    RefChain*  substituteExpression(RefChain *);

    RefObject* findFunctionById(unistring id);

    MatchState* saveCurrentStateLarge(){ // сохраняет и возвращает ссылку на состояние сопоставления для предложения
        matchStates.push( new MatchState(current_l, current_r) );
    };
    MatchState* saveCurrentStateSmall(){ // сохраняет и возвращает ссылку на состояние сопоставления образца
        matchStates.push( new MatchState(current_l, current_r) );
    };
    void restoreToLastSavedStateLarge(); // возвращается к состоянию на начало выполнения предложения
    void restoreToLastSavedState(); // возвращается к предыдущему состоянию
    void clearAllStatesAfter(MatchState*); // очищает от всего, что было создано после сохранения состояния АРГ
};


void SAVE_VAR_STATE   (RefData** activeTemplate); // сохраняет состояние переменной
void SAVE_VAR_STATE_AND_VALUE(RefData** activeTemplate); // сохраняет состояние и значение переменной
void RESTORE_VAR_STATE(RefData** activeTemplate); // восстанавливает состояние переменной

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

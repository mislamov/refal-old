#ifndef SESSION_H_INCLUDED
#define SESSION_H_INCLUDED

#include <stack>

#include "data.h"
#include "rfunction.h"


class Session {
    std::stack<RefBracketBase**> stackOfDataSkob; // стек сопоставления скобок
public:
    TVarBody* getBodyByLink(RefVariable*) {        SYSTEMERROR("not realized");    };
    RefBracketBase** getTopDataSkob(){ return stackOfDataSkob.top(); }

    // сопоставляет шаблон tmplate с объектным выражением с l по r.
    // isdemaching - признак того, что надо продолжить матчинг от предыдущего удачного состояния (напр в цепочке условий)
    bool  matching(RefObject *initer, RefChain *tmplate, RefData **l, RefData **r, bool isdemaching, bool isRevers);
    // оптимально вычисляет объектное выражение с функциональными вызовами в ОВ без угловых скобок
    // Вызывается подстановкой в предложении пользовательской функциии и перед вычислением условий
    void  executeExpression(RefChain *&);
    // готовит подстановку: заменяет переменные значениями. Получаем ОВ с угловыми скобками
    void  substituteExpression(RefChain *&);


    RefObject* findFunctionById(unistring id);
};


void SAVE_STATE   (RefData** activeTemplate);    // сохраняет состояние переменной
void SAVE_VARSTATE(RefData** activeTemplate); // сохраняет состояние и значение переменной
void RESTORE_STATE(RefData** activeTemplate); // восстанавливает состояние переменной

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

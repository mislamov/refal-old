#ifndef SESSION_H
#define SESSION_H

#include <map>
#include <stack>
#include <pair.h>

//#include "kernel.h"
//#include "datastructs.h"
#include "core.h"
#include "data.h"
#include "rfunction.h"

class DataForRepeater;
class TVarBody;
class Session;
class DataForRepeater;
class RefModuleBase;
class RefFunctionBase;


class TVarBodyTable : public std::map<unistring, TVarBody*>{};

// тело сопоставленной переменной
class TVarBody : public pair<RefData *, RefData *>{
public:
    RefObject *owner; // ссылка на описание типа переменной
    TVarBodyTable *subv;  // подпеременные - для пользовательских шаблонов
    TVarBody(RefData* l, RefData* r, RefObject* o, TVarBodyTable *themap=0);
    unistring toString();
};


//////////////////////////////////////////////////////////////////
// Данные для процесса вычисления функции (сессия сопоставления)
class Session : public RefObject {

    class SessionMaching {
        public:
            int i;
    };

  public:
    std::stack<RefChain *> pole_zrenija;		// begin- и end-шаблон (поле зрения)
    std::map <unistring, RefModuleBase*> modules;  // подгруженные модули

    RefData*		StopBrackForceVar;	// Конечная точка (шаблон) принудительного отката

    std::stack<  std::stack<TVarBody*> *> StacksOfSopost;		// Стеки хранителей состояний шаблонов

    std::stack<TVarBodyTable *> varTables;		// Таблица переменных  имя -> ссылк на элемент стека
    TVarBody*   getVarBody( unistring vname );
    TVarBody*   setVarBody( unistring vname, TVarBody* );

    unistring varTableToText();

    std::stack<RefBracketBase  *>	StackOfDataSkob;	    // Стек ЗАКР. скобок в векторе данных
    std::stack<DataForRepeater *>	StackOfRepeatSkob;	    // Стек итераций повторителей
    std::stack<DataForRepeater *>	StackOfRepeatSkobDoned;	// Стек итераций повторителей для успешно сопоставленных

    std::stack<RefData *>	StackOfGroupSkob;	    // Стек указателей на ПЕРЕДначало группы шаблонов
    //std::stack<ref_variant_vert*> StackOfVariants;	//

    Session();
    ~Session();

    void SaveTempl   (RefData* var, RefData* l, RefData* r); // если аргумент - переменная, то добавляем ее состояние
    void RestoreTempl(RefData *owner, RefData* &l, RefData* &r ); // извлекаем последнее сохраненное сост-е

    void  initializationArg(RefData*&, RefData*&);        // регистрация ОО для сапостовления. приставка дот
    void  initializationTemplate(RefChain *tmpl);   // оснащение дотами
    RefChain*  deinitializationArg();                        // откат регистрации ОО в initialization
    void  deinitializationTemplate(RefChain *&tmpl); // удаление дот
    bool  matching(RefChain *tmplate, bool isdemaching=false); // сопоставляет шаблон tmplate с объектным выражением в initialization. Если isdemaching, то делать откат от последнего дота
    RefChain *execChain();  // вычисляет поле зрения

    std::stack<TVarBody*> *getCurrentSopostStack(){
        #ifdef DEBUG
        if (StacksOfSopost.empty()) SYSTEMERROR("Tring to get from empty sopost-stack!");
        #endif
        return StacksOfSopost.top();
    }


    RefChain *RightPartToObjectExpression(RefChain *);  // готовит правую часть для сопоставления - подстановка переменных

    void regModule(RefModuleBase *);
    RefFunctionBase* findMethodFromModule(unistring);

    virtual unistring toString(){ return "Session"; };
    void flush(){ varTables.top()->clear(); }; // сброс лишних данных после вычислений.
    void showStatus();
};





class DataForRepeater {
public:
    RefData *owner; //?
    unsigned long from, to;	// границы количества допутимых проходов
    long step;
    long mustbe;	//?
    long maxstep;	//?
    unsigned long current_step;	// число активных проходов
    RefData *leftPoint;	// левый край захватывемой подцепочки

    DataForRepeater(RefData *o);
    std::string toString(){ return ("@DataForRepeater:owner=" + owner->toString()); }
};

#endif

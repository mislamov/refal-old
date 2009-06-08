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

#ifndef SESSION_H
#define SESSION_H

#include <map>
#include <stack>
#include <list>

#ifndef WIN32
#include <pair.h>   // for MSVC 6.0 that doens't have a proper <utility>
#endif /* WIN32 */

//#include "kernel.h"
//#include "datastructs.h"
#include "core.h"
#include "data.h"
#include "rfunction.h"

class DataForRepeater;
class TVarBody;
class Session;
class SessionOfMaching;
class DataForRepeater;
class RefModuleBase;
class RefFunctionBase;
class RefTemplateBridgeVar;

class TVarBodyTable : public std::map<unistring, TVarBody*> {};

template <class T1, class T3>
struct quadL {
    T1 first;
    T3 second;
};

// тело сопоставленной переменной
class TVarBody : public quadL<RefData*, RefData*> {
public:
    RefObject *owner;        // ссылка на переменную-владельца данного тела

    // сделал стек, так как у внешнего шаблона могут быть условия, а значит несколько субсессий при сопоставлении
    std::list<SessionOfMaching*> sessStack;  // состояние внешней переменной во время сопоставления

    TVarBody(RefData* l, RefData* r, RefObject* o);
    unistring toString();
    TVarBody * folowByWay(unistring path);
};


/*
    Класс SessionOfMaching - подсессия сопоставлений (состояние сессии).

    После выполнения функции (успешного или нет), сессия должна быть в исходном состоянии, а все новое кроме результата и
        глобальных данных - мусор
    После провального матчинга условия - сессия д.б. исходной. Все новое - мусор
    После успешного матчинга условия - все новое нужно сохранить для возможного отката

    Пользовательский шаблон: это будет TemplateItem c сылками на концы тела. В сессии сделать специальный стек/мап указателей на точки возврата пользовательскоо шаблона при сопоставлении.
*/
class SessionOfMaching  : public RefObject {
public:
    bool isfar; // признак того, что субсессия создается для внешнего сопоставления (чужое поле зрения)
public:
    RefObject *owner;  // причина подсессии : предложение(образец), условие или внешний шаблон(образец);
    RefChain  *pole_zrenija;		   // begin- и end-шаблон (поле зрения)

    RefData* matching_savedL ;
    RefData* matching_l ;
    RefData* matching_r ;


    std::stack<RefBracketBase  *>	StackOfDataSkob;	    // Стек ЗАКР. скобок в векторе данных
    std::stack<RefBracketBase  *>	StackOfDataSkob_done;	    // Стек ЗАКР. скобок в векторе данных
    std::stack<ref_variant_vert*>   StackOfVariants;	    // Стек удачно сопоставленных вариантов (ссылки на границы последнего варианта)

    std::stack<infint> StackOfRepeater;	        // Стек активных повторителей
    std::stack<infint> StackOfRepeaterDoned;	// Стек удачно сопоставленных повторителей

    RefData *activeTemplate; // последнее активное выражение шаблона в сопоставлении (использовать вне matching ОПАСНО!)
    RefTemplateBridgeVar *templReturnBackPoint;// точка возврата при сопоставлении внешних шаблонов


    TVarBodyTable varTable;		          // Таблица переменных  имя -> ссылка на элемент стека
    std::stack<TVarBody*> StackOfSopost; // Стек хранителей состояний шаблонов
    //RefData*    StopBrackForceVar;	// Конечная точка (шаблон) принудительного отката. ?: нужно ли в подсессию?

    // создает и возвращает субсессию (точку восстановления) для сопоставления с новым полем зрения
    SessionOfMaching(RefObject *own, RefData *argLeft, RefData *argRight);

    // создает точку внутри субсессии. Нужно для сопоставления внешних шаблонов (поле зения уже подготовлено)
    SessionOfMaching(RefObject *own, Session *s);

    // очищает точку восстановления с удалением мусора
    virtual ~SessionOfMaching();
    unistring toString() {
        return "SessionOfMaching";
    };
};


//////////////////////////////////////////////////////////////////
// Данные для процесса вычисления функции (сессия сопоставления)
class Session : public RefObject {

private:
    RefChain* globalData;   // глобальные данные для цепочек

    RefChain*  deinitializationArg();               //  откат регистрации ОО в initialization
    void  initializationArg(RefData*, RefData*);    //  регистрация ОО для сапостовления. приставка дот

public:

    /* путешествие по цепочкам данных сканирующей головки */
    RefDataChainPart *currentChainPart;

    int fcalls;
    unsigned long step;

    TResult result_sost;     // последний статус в сопоставлении. Внешнее изменение: ref_variant_dot::pred_

    TMessage message4nextpred; // через эту переменную методы init и back могут передавать указание методам next_ и pred_

    // данные
    std::map <unistring, RefModuleBase*>  modules;  //  подгруженные модули
    std::list <SessionOfMaching *> matchSessions;  //  стек состояний сопоставлений

    // методы
    TVarBody*   getVarBody( unistring vname );
    TVarBody*   setVarBody( unistring vname, TVarBody* );
    RefObject*  getObjectByName(unistring name, Session *s=0); // ищет объект (функция/шаблон) во всех модулях
    RefTemplateBridgeVar * getTemplReturnBackPoint();  // ищет и возвращает последнюю точку возврата внешней переменной

    unistring varTableToText();

    Session();
    virtual ~Session();

    //void  SaveTemplItem   (RefData* var,   RefData*  l, RefDataChainPart*  lWay, RefData*  r, RefDataChainPart*  rWay); // если аргумент - переменная, то добавляем ее состояние
    //void  RestoreTemplItem(RefData *owner, RefData* &l, RefDataChainPart* &lWay, RefData* &r, RefDataChainPart* &rWay); // извлекаем последнее сохраненное сост-е
    void  SaveTemplItem   (RefData* var,   RefData*  l, RefData*  r ); // если аргумент - переменная, то добавляем ее состояние
    void  RestoreTemplItem(RefData *owner, RefData* &l, RefData* &r ); // извлекаем последнее сохраненное сост-е

    bool  matching(RefObject *initer, RefChain *tmplate, RefData*l, RefData*r, bool isdemaching, bool isRevers); // сопоставляет шаблон tmplate с объектным выражением. isdemaching - признак того, что надо продолжить матчинг от предыдущего удачного состояния (напр в цепочке условий)

    std::stack<TVarBody*> *getCurrentSopostStack() {
        #ifdef TESTCODE
        if (matchSessions.empty()) {
            showStatus();
            SYSTEMERROR("matchSessions is EMPTY !");
        }
//        if (matchSessions.back()->StackOfSopost.empty()){
//            LOG("Current Stak of sopost is empty!");
//        }
        #endif
        return &(matchSessions.back()->StackOfSopost);



    }

    inline std::stack<RefBracketBase  *>  *getStackOfDataSkob() {
        return &(matchSessions.back()->StackOfDataSkob);
    }
    inline RefChain *getPole_zrenija() {
        return matchSessions.back()->pole_zrenija;
    }

    // готовит правую часть для сопоставления - подстановка переменных. В сессии, потому что нужна таблица переменных
    RefChain *RightPartToObjectExpression(RefChain *);

    void regModule(RefModuleBase *);
    RefFunctionBase* findMethodFromModule(unistring);

    virtual unistring toString() {
        return "Session";
    };
    void showStatus();



};



#endif

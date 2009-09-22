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

#include "RefSymbolBase.hxx"
#include "rfunction.h"
#include "kernel.h"
#include "datastructs.h"
#include "evalutor.h"

RefFunctionBase::RefFunctionBase() {};
RefFunctionBase::~RefFunctionBase() {};



RefSentence::RefSentence() : RefObject() {
    leftPart = rightPart = 0;
};
RefSentence::RefSentence(RefChain *l, RefChain *r) : RefObject() {
    leftPart = l;
    rightPart = r;
};
unistring RefSentence::toString() {
    //return "$RefSentence: Lp="+(leftPart?leftPart->toString():"$notset")+"   Rp="+(rightPart?rightPart->toString():"$noset");
    return "\t\t\t"+(leftPart?leftPart->toString():"$notset")+"   ::==   "+(rightPart?rightPart->toString():"$noset");
};


RefObject* RefUserModule::getObjectByName(unistring name, Session *s) {
    return objects[name];
};


unistring RefUserModule::toString() {
    unistring result = "";
    std::map<unistring, RefObject*>::iterator it;
    RefUserFunction *f = 0;
    for (it = objects.begin(); it!=objects.end(); it++) {
        result += it->first;
        if (f = ref_dynamic_cast<RefUserFunction >(it->second)) {
            result += " {\n";
            std::list<RefSentence *>::iterator sit;
            for (sit = f->body.begin(); sit!=f->body.end(); sit++) {
                result += (*sit)->toString();
                result += ";\n";
            };
            result += "}\n\n";
        } else {
            result += ": ";
            result += it->second->toString();
            result += "\n";
        }

    };
    return result;
};



void RefUserModule::initilizeAll(Session *s) {
    while (! initItems.empty()) {
        initItems.top()->initize(s);
        initItems.pop();
    };
};





unistring RefUserFunction::toString() {
    std::string result = "";
    result += " {\n";
    std::list<RefSentence *>::iterator sit;
    for (sit = body.begin(); sit!=body.end(); sit++) {
        result += (*sit)->toString();
        result += ";\n";
    };
    result += "}\n\n";

    return "RefUserFunction::" + name + result;

};


/// аргументы - концы чистого ОВ
bool RefUserFunction::execute(RefData *argfirst, RefData *argsecond, Session *s) {

    //long &dc = co::datacount;


    s->fcalls++;
    RefData *ldot;
    RefData *rdot;

    if (!argfirst) {
        // пустой аргумент
        ldot = argsecond;
    } else {
        ldot = argfirst ->getPred();
    }
    rdot = argsecond->getNext();
    #ifdef TESTCODE
    // должно вызываться только для части цепочки => окружено чем-то. Нужно чтоб не потерять место изменения
    if (! ldot )
        SYSTEMERROR("RefUserFunction::execute( argfirst->pred != RefDATA not null, ...) !\RefUserFunction::execute( " << RefChain(argfirst, argsecond).toString() << " )");
    if (! rdot )
        SYSTEMERROR("RefUserFunction::execute(..., argsecond->next != RefDATA not null) !\RefUserFunction::execute( " << RefChain(argfirst, argsecond).toString() << " )");
    #endif

    LOG(s->step++ <<  "::  <" << getName() << " " << std::flush << RefChain(argfirst,argsecond).toString() << " >  ###############################################################" );


    std::list<RefSentence *>::iterator sent = body.begin(); // перебор предложений функции
    bool reslt = false;

    do {
        LOG(s->step++ <<  "::  \ttring this: " << (*sent)->toString() );
        // s->showStatus();

        /// todo: создать тут точку отката сессии для очистки последствий функции
        //SessionOfMaching* stateBeforeMatch = s->matchSessions.back();
        SessionOfMaching* stateBeforeMatch = s->matchSessions.empty() ? 0 : s->matchSessions.back();

        if (s->matching(*sent, (*sent)->leftPart, argfirst, argsecond, false, false)) {
            LOG(s->step++ <<  "\tsucessfull!");
            #ifdef DEBUG
            s->showStatus();
            #endif

            RefChain *newoe = s->RightPartToObjectExpression( (*sent)->rightPart ); // создаем копию rightPart'а с заменой переменных на значения

            /// todo: откатиться до созданной точки, оставив только newoe и глобальные данные. Созданные переменные удалить.
            // сейчас дилетантский откат:
            //while (s->matchSessions.back() != stateBeforeMatch){
            while ((s->matchSessions.empty() ? 0 : s->matchSessions.back()) != stateBeforeMatch) {
                delete s->matchSessions.back();
                s->matchSessions.pop_back();
            } // конец дилетантского отката

            // удаляем старый вектор аргументов
            if (ldot->getNext() != rdot) {
                delChain(ldot->getNext(), rdot->getPred());
            }
            // вставляем новый вектор
            if (newoe->first) {
                ldot->setNext( newoe->first);
                newoe->first->setPred(ldot);
                #ifdef TESTCODE
                if (!newoe->second) SYSTEMERROR("newoe->first && ! newoe->second ");
                #endif
                rdot->setPred( newoe->second);
                newoe->second->setNext( rdot);
            } else {
                ldot->setNext( rdot);
                rdot->setPred( ldot);
            }

            // тут не надо удалять содержимое newoe! Его содержимое встроено в поле зрения
            delete newoe; // удаляем старую _оболочку_ вектора - новый вектор встроен в поле зрения

            reslt = true;
        } else {
            // по идее если матчинг закончился не удачно, то в нем происходит откат к исходному состоянию и удаление мусора
            #ifdef TESTCODE
            if (stateBeforeMatch  && stateBeforeMatch != s->matchSessions.back()) SYSTEMERROR("unbalansed sub-sessions and recover-dots"); // хм...
            #endif
            sent++;
        }
    } while (!reslt && sent != body.end());  // std: body.end() - элемент после последнего

    s->fcalls--;
    return reslt;
};





RefDllModule::RefDllModule() : RefModuleBase() {
//        std::cout << "\nRefDllModule::RefDllModule() : " << (long)this << "\n";
};

RefDllModule::~RefDllModule() {
//        std::cout << "\nRefDllModule::~RefDllModule() : " << (long)this << "\n";
};


RefObject* RefDllModule::getObjectByName(unistring nm, Session *s) {
    return objects[nm];
};


void RefDllModule::setObjectByName(unistring name, RefObject* o) {
    objects[name] = o;
};


unistring RefDllModule::toString() {
    std::ostringstream s;
    s << "RefDllModule[ objects: " << (objects.size()) << " ]" ;
    return s.str();
};


RefBuildInFunction::RefBuildInFunction(unistring name, RefDllModule *m) : RefFunctionBase() {
    m->setObjectByName(name, this);
};


bool RefBuildInFunction::execute(RefData* lp, RefData* rp, Session* s) {
    LOG( "\n====================================\n< " << this->getName() << std::flush << " " << vectorToString(lp, rp) << " >" );
    // сохраним границы
    RefData *lold, *rold=0;
    if (! lp) { // пустой вектор
        #ifdef TESTCODE
        if (!rp) SYSTEMERROR("!lp && !rp");
        #endif
        lold = rp;
        if (lold) {
            rold = rp->getNext();
        };
    } else {
        lold = lp->getPred();
        rold = rp->getNext();
    };
    // вычислим функции
    RefChain *result = new RefChain();
    if (! this->eval(lp, rp, result, s)) {
        // не вычислена функция
        delete result;
        return false;
    };

    // удалим старый вектор
    if (lp) {
        delChain(lp, rp);
    }

    // функция вычислена. результат в result
    if (! result->first) {
        // на всякий случай
        lold->setNext( rold);
        rold->setPred( lold);
        delete result; // ?
        return true;
    };

    lold->setNext (result->first);
    rold->setPred (result->second);
    result->first->setPred( lold);
    result->second->setNext( rold);

    delete result;
    return true;
};


// matching  в случае неуспеха сам восстанавливает состояние. В случае успеха - оставляет изменения
// по идее рефал-условие не должно контроллировать точки состояний. Главное правильно вызывать дизмачинг (домачинг)
TResult  RefCondition::init(RefData*&tpl, Session* s, RefData *&l, RefData *&r) {
    /// todo: ниже не верно. условие может быть внутри внешнего шаблона и сопоставляться с пустым выражением не в конце
    /// однако для условия в предложении очень важно проверять, что оно сопост-ся с концом аргумента
    /// как вариант - ставить датадоты перед первым условием; можно помечать условия как внешние

    if (ref_dynamic_cast<RefFunctionBase >(own)) {
        // условие для предложения функции может быть только в конце шаблона и сопоставляться с пустым выражением в конце,
        // в отличие от условия в конце пользовательского шаблона
        RefData_DOT *d = ref_dynamic_cast<RefData_DOT >(next_term(r));
        if (!d) {
            tpl=tpl->getPred();
            return BACK;
        }
    }

    //s->showStatus();
    RefChain *newpz = s->RightPartToObjectExpression(this->rightPart);  /// todo: тут создается - где-то тут же и кильнуть

    //std::cout << "\nCOND-EVALUTE:::\t" << newpz->toString() << " : " << this->leftPart->toString();

    newpz = evalutor(newpz, s);

    //std::cout << "\nCOND-EVALUTE-OO:\t" << newpz->toString() << " : " << this->leftPart->toString();

    if (s->matching(this, this->leftPart, newpz->first, newpz->second, false, isReverse )) {
        /// Go->Go
        //std::cout << "\n\nCOND-RETURN:::\tinit-> GO" << std::flush << "\n\n\n";
        //std::cout << "s.sopost.top: " << s->getCurrentSopostStack()->top()->toString() << std::flush;
        tpl=tpl->getNext();
        return (GO);
    } else {
        /// Go->Back
        //std::cout << "\nCLEAR: " << newpz->toString() << "\n\n" << std::flush;
        //уже. в деструкторе субсессии: newpz->clear(); // сопоставление неуспешно - удаляем
        delete newpz;
        //std::cout << "\n\nCOND-RETURN:::\tinit-> BACK" << std::flush << "\n\n\n";
        //s->showStatus();
        tpl=tpl->getPred();
        return (BACK);
    }
};


TResult  RefCondition::back(RefData*&tpl, Session* s, RefData *&l, RefData *&r) {
    if (!isReverse && s->matching( this, this->leftPart, 0, 0, true, false)) { // продолжаем поиск вариантов
        /// Back->Go
        //std::cout << "\n\nCOND-RETURN:::\tback-> GO" << std::flush << "\n\n\n";
        tpl=tpl->getNext();
        return GO;
    } else {
        /// Back->Back
        //std::cout << "\n\nCOND-RETURN:::\tback-> BACK" << std::flush << "\n\n\n";
        tpl=tpl->getPred();
        return BACK;
    }

};





RefTemplateBase::RefTemplateBase(unistring name) : RefModuleBase(name) {
};

RefUserTemplate::RefUserTemplate(unistring name, RefChain *lp) : RefTemplateBase(name) {
    if (lp) {
        setLeftPart(lp);
    } else {
        leftPart = 0;
    }
};

void RefUserTemplate::setLeftPart(RefChain *lp) {
    // добавляем мосты к концам тела шаблона
    RefTemplateBridgeTmpl *lbr = new RefTemplateBridgeTmpl(), *rbr = new RefTemplateBridgeTmpl(lbr, 0);
    lp->first = lp->first->predInsert(lbr);
    lp->second = lp->second->afterInsert(rbr);

    //std::cout << "newlp: " << lp->toString() << "\n" << std::flush;
    leftPart = lp;
};





/****************  вызывающие ( переменная )  *****************
**************************************************************/
TResult  RefTemplateBridgeVar::init(RefData*&tpl, Session* s, RefData *&l, RefData *&r) {

    #ifdef TESTCODE
    if (! ref_dynamic_cast<RefTemplateBridgeVar>(this->other) ) SYSTEMERROR("not RefTemplateBridgeVar pair!");
    #endif

    if (is_opened) { /// [{]

        TVarBody *varBody = new TVarBody(l, r, this);

        //  сохраняем сопоставление в вызывающей субсессии
        s->getCurrentSopostStack()->push( s->setVarBody(name, varBody) );
        LOG( "\nsave(" << name << ") : "; print_vector(l, r); std::cout << "\n" );

        //  создаем подсессию для шаблона - стелим подкладку для сопоставления шаблона
        SessionOfMaching *sess = new SessionOfMaching(this, s);
        //  текущую закрывающую скобку копируем в новое сопоставление - граница действий нового сопоставления
        sess->StackOfDataSkob.push( s->matchSessions.back()->StackOfDataSkob.top()  );
        s->matchSessions.push_back(sess);
        //  сохраняем конец ссылки на шаблон для возврата : [}]
        sess->templReturnBackPoint =  (RefTemplateBridgeVar *)other ;  //  [}]

        tpl=bridge->getNext();
        return GO;
    }
    /// [}]

    TVarBody *varBody = s->getVarBody(getName(), other); // оптимизировать
    // сохраняем состояние сопоставления в тело переменной (основную подсессию шаблона и подсессии условий шаблона)
    SessionOfMaching *sess;
    do {
        sess = s->matchSessions.back();
        #ifdef TESTCODE
        if (! sess) {
            SYSTEMERROR("alarm!");
        }
        #endif
        varBody->sessStack.push_back(sess);
        s->matchSessions.pop_back();
    } while (! sess->templReturnBackPoint); /// оптимизировать?

    #ifdef TESTCODE
    if (varBody->first) SYSTEMERROR("varBody->first != 0");
    #endif
    // сохраняем значение самой переменной
    if (varBody->second != r) {
        // не пустое
        varBody->first  = varBody->second->getNext();
        varBody->second = r;
    }

    LOG( "\nsave(" << name << ") : "; print_vector(varBody->first, varBody->second); std::cout << "\n" )
    tpl=getNext();
    return GO;

};




TResult  RefTemplateBridgeVar::back(RefData*&tpl, Session* s, RefData *&l, RefData *&r) {
    if (is_opened) {  /// [{]
        // удаление субсессии для внешней переменной
        delete s->matchSessions.back();   // TODO: очистка мусора
        s->matchSessions.pop_back();

        #ifdef TESTCODE
        if (s->getCurrentSopostStack()->empty()) SYSTEMERROR("empty sopost stack!");
        if (s->getCurrentSopostStack()->top()->owner != this) SYSTEMERROR("wrong owner for " << toString() << " : " << s->getCurrentSopostStack()->top()->owner->toString() );
        #endif

        RESTORE_STATE(tpl); // оптимизировать(значения не нужны)

        tpl=tpl->getPred();
        return BACK;
    }
    /// [}]

    // приводим в порядок тело переменной
    TVarBody *varBody = s->getVarBody(getName());
    if (varBody->first) {
        // не пустое значение
        varBody->second = varBody->first->getPred();
        varBody->first = 0;
    }

    //  извлекаем из тела переменной все подсессии (базовую и условий) сопоставления и делаем их акивными
    SessionOfMaching *sess;
    while (! varBody->sessStack.empty()) {
        sess = varBody->sessStack.back();
        s->matchSessions.push_back(sess);
        varBody->sessStack.pop_back();
    }

    tpl = bridge->getPred();
    return BACK;
};





/**************  вызываемые ( $Template ) ********************
**************************************************************/
TResult  RefTemplateBridgeTmpl::init(RefData*&tpl, Session* s, RefData *&l, RefData *&r) {
    if (this->is_opened) { ///  {[}
        SYSTEMERROR("unexpected"); // Var перепрыгивает на getNext() минуя Tmpl
    } else {              ///  {]}
        tpl = s->getTemplReturnBackPoint();
        return GO;
    }
};



TResult  RefTemplateBridgeTmpl::back(RefData*&tpl, Session* s, RefData *&l, RefData *&r) {
    if (this->is_opened) { ///    {[}
        tpl = s->matchSessions.back()->templReturnBackPoint->other;  // [{]
        return BACK;
    } else {              ///    {]}
        SYSTEMERROR("unexpected"); // Var перепрыгивает Tmpl на getPred()
    }
};







// класс - непроинициализированная переменная внешнего типа.
// После инициализации заменяется на пару   {RefTemplateBridgeVar   RefTemplateBridgeVar}
bool RefUserVarNotInit::initize(Session *s) { // замещается на пару
    RefObject* oo = s->getObjectByName(this->getType());
    RefUserTemplate *utempl =  oo ? ref_dynamic_cast<RefUserTemplate >( oo ) : 0 ;
    if (! utempl) SYSTEMERROR("User $Template '" << getType() << "' not defined!"); //     return false;
    // шаблон найден
    RefTemplateBridgeVar
    *leftBridge  = new RefTemplateBridgeVar(),
    *rightBridge = new RefTemplateBridgeVar(leftBridge, leftBridge);
    #ifdef TESTCODE
    if (! (this->pred && this->next) ) {
        SYSTEMERROR("@RefUserVarNotInit around by $null !");
    }
    #endif
    // встраиваем переменную
    this->pred->next = leftBridge;
    leftBridge->pred = this->pred;
    this->next->pred = rightBridge;
    rightBridge->next = this->next;
    this->pred = this->next = 0;
    // назначаем имя
    /// todo: сделать именование только в одном месте - для одной скобки
    leftBridge->setName(this->getName());
    rightBridge->setName(this->getName());
    // нацеливаем на тело шаблона
    #ifdef TESTCODE
    if (! ref_dynamic_cast<RefTemplateBridgeTmpl >(utempl->getLeftPart()->first) ) SYSTEMERROR("Template body error: no RefTemplateBridgeTmpl in the first");
    if (! ref_dynamic_cast<RefTemplateBridgeTmpl >(utempl->getLeftPart()->second) ) SYSTEMERROR("Template body error: no RefTemplateBridgeTmpl in the second");
    #endif
    //leftBridge ->bridge = ref_dynamic_cast<RefTemplateBridgeTmpl *>( utempl->getLeftPart()->first );  // должно быть уже RefTemplateBridgeTmpl
    //rightBridge->bridge = ref_dynamic_cast<RefTemplateBridgeTmpl *>( utempl->getLeftPart()->second ); // должно быть уже RefTemplateBridgeTmpl
    leftBridge ->bridge = (RefTemplateBridgeTmpl *)( utempl->getLeftPart()->first );  // должно быть уже RefTemplateBridgeTmpl
    rightBridge->bridge = (RefTemplateBridgeTmpl *)( utempl->getLeftPart()->second ); // должно быть уже RefTemplateBridgeTmpl

    delete this;
    return true;
}
TResult RefUserVarNotInit::init(RefData*&tpl, Session*, RefData *&, RefData *&) {
    SYSTEMERROR("ALARM!");
};
TResult RefUserVarNotInit::back(RefData*&tpl, Session*, RefData *&, RefData *&) {
    SYSTEMERROR("ALARM!");
};

//----------------------- $CUTTER$ ---------------------
TResult  RefMatchingCutter::init(RefData *&tpl, Session* , RefData *&, RefData *&) {
        tpl=tpl->getNext();
        return GO;
};

TResult  RefMatchingCutter::back(RefData *&tpl, Session* s, RefData *&, RefData *&) {
        /// TODO: Обязательно оптимизировать! очень неэффективно. нет сборки мусора
        #ifdef DEBUG
        s->showStatus();
        #endif

        SessionOfMaching *sess = s->matchSessions.back();

        // выгребаем стек сопоставлений
        if (! sess->StackOfSopost.empty()){
        for(long i=sess->StackOfSopost.size(); --i; i){
            LOG( ">> CUTTER BACKFORSE DROP: " << sess->StackOfSopost.top()->owner->toString() );
            sess->StackOfSopost.pop();
        }}

        // выгребаем стек скобок doned
        if (! sess->StackOfDataSkob_done.empty()){
        for(long i=sess->StackOfDataSkob_done.size(); --i; i){
            LOG( ">> CUTTER BACKFORSE DROP bracket_done: " << sess->StackOfDataSkob_done.top()->toString() );
            sess->StackOfDataSkob_done.pop();
        }}

        // выгребаем стек скобок
        if (! sess->StackOfDataSkob.empty()){
        for(long i=sess->StackOfDataSkob.size(); --i; i){
            LOG( ">> CUTTER BACKFORSE DROP bracket : " << sess->StackOfDataSkob.top()->toString() );
            sess->StackOfDataSkob.pop();
        }}



        // обработка каттера для образца
        RefData *finish;
        if (sess->templReturnBackPoint){
            // если пользовательский шаблон
            finish = sess->templReturnBackPoint->other; // [}]
        } else {
            finish = sess->pole_zrenija->first; // datadot
        }

        tpl=finish;
        return BACK;
};

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

RefFunctionBase::RefFunctionBase(){};
RefFunctionBase::~RefFunctionBase(){};



RefSentence::RefSentence() : RefObject() {
    leftPart = rightPart = 0;
};
RefSentence::RefSentence(RefChain *l, RefChain *r) : RefObject() {
    leftPart = l;
    rightPart = r;
};
unistring RefSentence::toString(){
    //return "$RefSentence: Lp="+(leftPart?leftPart->toString():"$notset")+"   Rp="+(rightPart?rightPart->toString():"$noset");
    return sss = "\t\t\t"+(leftPart?leftPart->toString():"$notset")+"   ::==   "+(rightPart?rightPart->toString():"$noset");
};




RefObject* RefUserModule::getObjectByName(unistring name, Session *s){
    return objects[name];
};


unistring RefUserModule::toString(){
            unistring result = "";
            std::map<unistring, RefObject*>::iterator it;
            RefUserFunction *f = 0;
            for (it = objects.begin(); it!=objects.end(); it++){
                result += it->first;
                if (f = dynamic_cast<RefUserFunction *>(it->second)){
                    result += " {\n";
                    std::list<RefSentence *>::iterator sit;
                    for (sit = f->body.begin(); sit!=f->body.end(); sit++){
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
            return sss = result;
};



void RefUserModule::initilizeAll(Session *s){
    while (! initItems.empty()){
        initItems.top()->initize(s);
        initItems.pop();
    };
};





unistring RefUserFunction::toString() {
        std::string result = "";
        result += " {\n";
        std::list<RefSentence *>::iterator sit;
        for (sit = body.begin(); sit!=body.end(); sit++){
            result += (*sit)->toString();
            result += ";\n";
        };
        result += "}\n\n";

        return sss = "RefUserFunction::" + name + result;

};


/// аргументы - концы чистого ОВ
bool RefUserFunction::execute(RefData *argfirst, RefData *argsecond, Session *s){

    //long &dc = co::datacount;


s->fcalls++;
        RefData *ldot;
        RefData *rdot;

        if (!argfirst){
            // пустой аргумент
            ldot = argsecond;
        } else {
            ldot = argfirst ->pred;
        }
        rdot = argsecond->next;
        #ifdef DEBUG
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
        SessionOfMaching* stateBeforeMatch = s->matchSessions.back();

        if (s->matching(*sent, (*sent)->leftPart, argfirst, argsecond, false, false)){
            LOG(s->step++ <<  "\tsucessfull!");
            //s->showStatus();

            RefChain *newoe = s->RightPartToObjectExpression( (*sent)->rightPart ); // создаем копию rightPart'а с заменой переменных на значения

            /// todo: откатиться до созданной точки, оставив только newoe и глобальные данные. Созданные переменные удалить.
            // сейчас дилетантский откат:
            while (s->matchSessions.back() != stateBeforeMatch){
                delete s->matchSessions.back();
                s->matchSessions.pop_back();
            } // конец дилетантского отката

            // удаляем старый вектор аргументов
            if (ldot->next != rdot){
                delChain(ldot->next, rdot->pred);
            }
            // вставляем новый вектор
            if (newoe->first){
                ldot->next = newoe->first;
                newoe->first->pred = ldot;
                #ifdef DEBUG
                if (!newoe->second) SYSTEMERROR("newoe->first && ! newoe->second ");
                #endif
                rdot->pred = newoe->second;
                newoe->second->next = rdot;
            } else {
                ldot->next = rdot;
                rdot->pred = ldot;
            }

            // тут не надо удалять содержимое newoe! Его содержимое встроено в поле зрения
            delete newoe; // удаляем старую _оболочку_ вектора - новый вектор встроен в поле зрения

            reslt = true;
        } else {
            // по идее если матчинг закончился не удачно, то в нем происходит откат к исходному состоянию и удаление мусора
            #ifdef DEBUG
            if (stateBeforeMatch != s->matchSessions.back()) SYSTEMERROR("unbalansed sub-sessions and recover-dots"); // хм...
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

RefObject* RefDllModule::getObjectByName(unistring nm, Session *s){ return objects[nm]; };

void RefDllModule::setObjectByName(unistring name, RefObject* o){
    objects[name] = o;
};


unistring RefDllModule::toString(){
        std::ostringstream s;
        s << "RefDllModule[ objects: " << (objects.size()) << " ]" ;
        return sss = s.str();
};

RefBuildInFunction::RefBuildInFunction(unistring name, RefDllModule *m) : RefFunctionBase() {
    m->setObjectByName(name, this);
};


bool RefBuildInFunction::execute(RefData* lp, RefData* rp, Session* s){
    LOG( "\n====================================\n< " << this->getName() << std::flush << " " << vectorToString(lp, rp) << " >" );
    // сохраним границы
    RefData *lold, *rold=0;
    if (! lp){ // пустой вектор
        #ifdef DEBUG
        if (!rp) SYSTEMERROR("!lp && !rp");
        #endif
        lold = rp;
        if (lold) {
            rold = rp->next;
        };
    } else {
        lold = lp->pred;
        rold = rp->next;
    };
    // вычислим функции
    RefChain *result = new RefChain();
    if (! this->eval(lp, rp, result, s)){
            // не вычислена функция
            delete result;
            return false;
    };

    // удалим старый вектор
    if (lp) {
        delChain(lp, rp);
    }

    // функция вычислена. результат в result
    if (! result->first){
        // на всякий случай
        lold->next = rold;
        rold->pred = lold;
        delete result; // ?
        return true;
    };

    lold->next = result->first;
    rold->pred = result->second;
    result->first->pred = lold;
    result->second->next = rold;

    delete result;
    return true;
};


// matching  в случае неуспеха сам восстанавливает состояние. В случае успеха - оставляет изменения
// по идее рефал-условие не должно контроллировать точки состояний. Главное правильно вызывать дизмачинг (домачинг)
TResult  RefCondition::init(Session* s, RefData *&l){
    /// todo: ниже не верно. условие может быть внутри внешнего шаблона и сопоставляться с пустым выражением не в конце
    /// однако для условия в предложении очень важно проверять, что оно сопост-ся с концом аргумента
    /// как вариант - ставить датадоты перед первым условием; можно помечать условия как внешние

    if (dynamic_cast<RefFunctionBase *>(own)){
        // условие для предложения функции может быть только в конце шаблона и сопоставляться с пустым выражением в конце,
        // в отличие от условия в конце пользовательского шаблона
        RefData_DOT *d = dynamic_cast<RefData_DOT *>(l->next);
        if (!d){
            return BACK;
        }
    }

    //s->showStatus();
    RefChain *newpz = s->RightPartToObjectExpression(this->rightPart);  /// todo: тут создается - где-то тут же и кильнуть

    //std::cout << "\nCOND-EVALUTE:::\t" << newpz->toString() << " : " << this->leftPart->toString();

    newpz = evalutor(newpz, s);

    //std::cout << "\nCOND-EVALUTE-OO:\t" << newpz->toString() << " : " << this->leftPart->toString();

    if (s->matching(this, this->leftPart, newpz->first, newpz->second, false, isReverse )){
        /// Go->Go
        //std::cout << "\n\nCOND-RETURN:::\tinit-> GO" << std::flush << "\n\n\n";
        //std::cout << "s.sopost.top: " << s->getCurrentSopostStack()->top()->toString() << flush;
        return (GO);
    } else {
        /// Go->Back
        //std::cout << "\nCLEAR: " << newpz->toString() << "\n\n" << flush;
        //уже. в деструкторе субсессии: newpz->clear(); // сопоставление неуспешно - удаляем
        delete newpz;
        //std::cout << "\n\nCOND-RETURN:::\tinit-> BACK" << std::flush << "\n\n\n";
        //s->showStatus();
        return (BACK);
    }

};

TResult  RefCondition::back(Session* s, RefData *&l, RefData *&r){
    if (!isReverse && s->matching( this, this->leftPart, 0, 0, true, false)){ // продолжаем поиск вариантов
        /// Back->Go
        //std::cout << "\n\nCOND-RETURN:::\tback-> GO" << std::flush << "\n\n\n";
        return GO;
    } else {
        /// Back->Back
        //std::cout << "\n\nCOND-RETURN:::\tback-> BACK" << std::flush << "\n\n\n";
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

void RefUserTemplate::setLeftPart(RefChain *lp){
    // добавляем мосты к концам тела шаблона
    RefTemplateBridgeTmpl *lbr = new RefTemplateBridgeTmpl(), *rbr = new RefTemplateBridgeTmpl(lbr, 0);
    lp->first = lp->first->predInsert(lbr);
    lp->second = lp->second->afterInsert(rbr);

    //std::cout << "newlp: " << lp->toString() << "\n" << std::flush;
    leftPart = lp;
};





/****************  вызывающие ( переменная )  *****************
**************************************************************/
TResult  RefTemplateBridgeVar::init(Session* s, RefData *&l){
    if (this->isOpen()){  //  {
        #ifdef DEBUG
        if (! dynamic_cast<RefTemplateBridgeVar*>(this->other) ) SYSTEMERROR("not RefTemplateBridgeVar pair!");
        #endif
        /// начало сопоставления переменной
        /* --== перенесено в Session::SaveTemplItem, т.к. там изменяется varMap, которую надо делать еще для преждней субсесии а не для новой
        //  переменная: создаем подсессию для шаблона - стелим подкладку для сопоставления шаблона
        SessionOfMaching *sess = new SessionOfMaching(s->getPole_zrenija());
        //  текущую закрывающую скобку копируем в новое сопоставление - граница действий нового сопоставления
        sess->StackOfDataSkob.push( s->matchSessions.back()->StackOfDataSkob.top()  );
        s->matchSessions.push_back(sess);
        //  переменная: сохраняем конец ссылки на шаблон для возврата  }
        sess->templReturnBackPoint =  (RefTemplateBridgeVar *)this->other ;  //  }
        */

        return GO;
    } else {             //  }
        /// успешное сопоставление переменной
        /*  --== действия перенесены в Session::SaveTemplItem для сохранения подсессии в теле переменной */
        return GO;
    }
};

RefData*  RefTemplateBridgeVar::next_point( ThisId var_id, Session *s){
    if (this->isOpen()){
        // указывает на открывающую скобку-мост своего шаблона
        // по идее ссылка уже должна быть присвоена (при инициализации модуля после загрузки)
        #ifdef DEBUG
        if (! this->bridge) SYSTEMERROR("bridge back-dot not found!");
        #endif
        return this->bridge;
    } else {
        #ifdef DEBUG
        s->showStatus();
        #endif
        return next; //?
    }
};


TResult  RefTemplateBridgeVar::back(Session* s, RefData *&l, RefData *&r){
    if (this->isOpen()){  //  [{]
        /// неудачное сопоставление переменной внешнего типа
        //  переменная: удаляем подсессию для переменной с очисткой мусора
//s->showStatus();
        //delete s->matchSessions.back();
        //s->matchSessions.pop_back();
//s->showStatus();
        //  переменная: забываем точку возврата
        //sess->templReturnBackPoint.pop();
        //s->matchSessions.back()->templReturnBackPoint = 0;

        return BACK;
    } else {              //  [}]
        /// откат к ранее успешной сопоставленной переменной пользовательского типа
        /* --== перенесено в Session::RestoreTemplItem */
        //s->showStatus();
        return BACK;
    }
};

RefData*  RefTemplateBridgeVar::pred_point( ThisId var_id, Session *s){
    if (this->isOpen()){
        return pred; //?
    } else {
        // указывает на закр скобку-мост своего шаблона
        // по идее ссылка уже должна быть присвоена (при инициализации модуля после загрузки)
        #ifdef DEBUG
        if (! this->bridge) SYSTEMERROR("bridge back-dot not found!");
        #endif
        if (s->message4nextpred == mFORCEBACK) return pred;
        return this->bridge;
    }
};


/**************  вызываемые ( $Template ) ********************
**************************************************************/
TResult  RefTemplateBridgeTmpl::init(Session* s, RefData *&l){
    if (this->isOpen()){  //  {
        /// начало сопоставления внешнего шаблона
        //  шаблон:  в переменной была создана подсессия и точка возврата
        return GO;
    } else {              //  }
        /// успешное сопоставление внешнего шаблона
        //  шаблон:  в переменной будет забыта точка возврата, подсессия будет перемещена в тело переменной
        return GO;
    }
};

RefData*  RefTemplateBridgeTmpl::next_point( ThisId var_id, Session *s){
    if (this->isOpen()){  //  {
        return next;
    } else {              //  }
        #ifdef DEBUG
        if (s->matchSessions.empty()) SYSTEMERROR("no sessions!");
        if (! s->getTemplReturnBackPoint()) {
            s->showStatus(); SYSTEMERROR("bridge back-dot not found!");
        }
        #endif

        return s->getTemplReturnBackPoint();
    }
};


TResult  RefTemplateBridgeTmpl::back(Session* s, RefData *&l, RefData *&r){
    if (this->isOpen()){  //    {
        /// неудачное сопоставление внешнего шаблона
        //  в переменной будет удалена подсессия и точка возврата
        return BACK;
    } else {              //    }
        /// откат к ранее успешному сопоставленному пользовательскому шаблону
        //  шаблон: в переменной была возвращена и активирована подсессия, восстановлена точка возврата
        return BACK;
    }
};

RefData*  RefTemplateBridgeTmpl::pred_point( ThisId var_id, Session *s){
    if (this->isOpen()){
        #ifdef DEBUG
        if (! s->matchSessions.back()->templReturnBackPoint)
            SYSTEMERROR("bridge back-dot not found!");
        #endif
        return s->matchSessions.back()->templReturnBackPoint->other;
    } else {
        return pred;
    }
};






// класс - непроинициализированная переменная внешнего типа.
// После инициализации заменяется на пару   {RefTemplateBridgeVar   RefTemplateBridgeVar}
bool RefUserVarNotInit::initize(Session *s){ // замещается на пару
    RefUserTemplate *utempl =  dynamic_cast<RefUserTemplate *>( s->getObjectByName(this->getType()) );
    if (! utempl) SYSTEMERROR("User $Template '" << getType() << "' not defined!"); //     return false;
    // шаблон найден
    RefTemplateBridgeVar
        *leftBridge  = new RefTemplateBridgeVar(),
        *rightBridge = new RefTemplateBridgeVar(leftBridge, leftBridge);
    #ifdef DEBUG
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
    #ifdef DEBUG
    if (! dynamic_cast<RefTemplateBridgeTmpl *>(utempl->getLeftPart()->first) ) SYSTEMERROR("Template body error: no RefTemplateBridgeTmpl in the first");
    if (! dynamic_cast<RefTemplateBridgeTmpl *>(utempl->getLeftPart()->second) ) SYSTEMERROR("Template body error: no RefTemplateBridgeTmpl in the second");
    #endif
    leftBridge ->bridge = dynamic_cast<RefTemplateBridgeTmpl *>( utempl->getLeftPart()->first );  // должно быть уже RefTemplateBridgeTmpl
    rightBridge->bridge = dynamic_cast<RefTemplateBridgeTmpl *>( utempl->getLeftPart()->second ); // должно быть уже RefTemplateBridgeTmpl

    delete this;
    return true;
}
TResult RefUserVarNotInit::init(Session*, RefData *&){ SYSTEMERROR("ALARM!"); };
TResult RefUserVarNotInit::back(Session*, RefData *&, RefData *&){ SYSTEMERROR("ALARM!"); };


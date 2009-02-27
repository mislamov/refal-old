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


    LOG("<" << getName() << " " << std::flush << RefChain(argfirst,argsecond).toString() << " >" );


    std::list<RefSentence *>::iterator sent = body.begin(); // перебор предложений функции
    bool reslt = false;

    do {
        LOG("\ttring this: " << (*sent)->toString() );

        /// todo: создать тут точку отката сессии для очистки последствий функции
        SessionOfMaching* stateBeforeMatch = s->matchSessions.back();

        if (s->matching( (*sent)->leftPart, argfirst, argsecond, false)){
            LOG("\tsucessfull!");
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
            delete newoe; // больше незачем хранить старую оболочку - новый вектор встроен в поле зрения

            reslt = true;
        } else {
            // по идее если матчинг закончился не удачно, то в нем происходит откат к исходному состоянию и удаление мусора
            #ifdef DEBUG
            if (stateBeforeMatch != s->matchSessions.back()) SYSTEMERROR("unbalansed sub-sessions and recover-dots"); // хм...
            #endif
            sent++;
        }
    } while (!reslt && sent != body.end());  // std: body.end() - элемент после последнего

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
    std::cout << "\n====================================\n< " << this->getName() << std::flush << " " << vectorToString(lp, rp) << " >";
    // сохраним границы
    RefData *lold, *rold;
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
        return true;
    };

    lold->next = result->first;
    rold->pred = result->second;
    result->first->pred = lold;
    result->second->next = rold;

    delete result;
};


// matching  в случае неуспеха сам восстанавливает состояние. В случае успеха - оставляет изменения
// по идее рефал-условие не должно контроллировать точки состояний. Главное правильно вызывать дизмачинг (домачинг)
TResult  RefCondition::init(Session* s, RefData *&l){
    // условие может быть только в конце шаблона и сопоставляться с пустым выражением в конце
    RefData_DOT *d = dynamic_cast<RefData_DOT *>(l->next);
    if (!d){
        return BACK;
    }

    s->showStatus();

    RefChain *newpz = s->RightPartToObjectExpression(this->rightPart);  /// todo: тут создается - где-то тут же и кильнуть
    std::cout << "\nCOND-EVALUTE:::\t" << newpz->toString() << " : " << this->leftPart->toString();

    newpz = evalutor(newpz, s);

    std::cout << "\nCOND-EVALUTE-OO:\t" << newpz->toString() << " : " << this->leftPart->toString();

    if (s->matching( this->leftPart, newpz->first, newpz->second, false )){
        std::cout << "\n\nCOND-RETURN:::\tinit-> GO" << std::flush << "\n\n\n";
        return GO;
    } else {
        newpz->clear(); // сопоставление неуспешно - удаляем
        delete newpz;

        std::cout << "\n\nCOND-RETURN:::\tinit-> BACK" << std::flush << "\n\n\n";

        s->showStatus();

        return BACK;
    }

};

TResult  RefCondition::back(Session* s, RefData *&l, RefData *&r){

    if (s->matching( this->leftPart, 0, 0, true )){ // продолжаем поиск вариантов
        std::cout << "\n\nCOND-RETURN:::\tback-> GO" << std::flush << "\n\n\n";
        return GO;
    } else {
        std::cout << "\n\nCOND-RETURN:::\tback-> BACK" << std::flush << "\n\n\n";
        return BACK;
    }

};





RefTemplateBase::RefTemplateBase(unistring name) : RefModuleBase(name) {
};

RefUserTemplate::RefUserTemplate(unistring name, RefChain *lp) : RefTemplateBase(name) {
    if (lp) {
        setLeftPart(lp);
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
        //  переменная: создаем подсессию для шаблона - стелим подкладку для сопоставления шаблона
        SessionOfMaching *sess = new SessionOfMaching(s->getPole_zrenija());
        s->matchSessions.push_back(sess);
        //  переменная: сохраняем конец ссылки на шаблон для возврата  }
        //sess->templReturnBackPoint.push( (RefTemplateBridgeVar *)this->other );  //  }
        sess->templReturnBackPoint =  (RefTemplateBridgeVar *)this->other ;  //  }

        return GO;
    } else {             //  }
        /// успешное сопоставление переменной
        SessionOfMaching *sess = s->matchSessions.back();
        //  переменная: забываем точку возврата шаблона в левую часть   } (this)
        //sess->templReturnBackPoint.pop();
        sess->templReturnBackPoint = 0;
        //  переменная: перемещаем подсессию в тело пользовательской переменной
        s->matchSessions.pop_back();
        //??? = sess;
        RUNTIMEERROR("RefTemplateBridgeVar::init", "not realized line upper");
        return GO;
    }
};

RefData*  RefTemplateBridgeVar::next_point( ThisId var_id, Session *s){
    if (this->isOpen()){
        // указывает на открывающую скобку-мост своего шаблона
        // по идее ссылка уже должна быть присвоена (при инициализации модуля после загрузки)
        return this->getBridge();
    } else {
        return next; //?
    }
};


TResult  RefTemplateBridgeVar::back(Session* s, RefData *&l, RefData *&r){
    if (this->isOpen()){  //  {
        /// неудачное сопоставление переменной внешнего типа
        //  переменная: удаляем подсессию для переменной с очисткой мусора
        delete s->matchSessions.back();
        s->matchSessions.pop_back();
        //  переменная: забываем точку возврата
        //sess->templReturnBackPoint.pop();
        s->matchSessions.back()->templReturnBackPoint = 0;

        return BACK;
    } else {              //  }
        /// откат к ранее успешной сопоставленной переменной пользовательского типа
        //  переменная: извлекаем из тела переменной подсессию сопоставления и делаем ее акивной
        SessionOfMaching *sess /*= ???*/;
        RUNTIMEERROR("RefTemplateBridgeVar::back", "not realized line upper");
        s->matchSessions.push_back(sess);
        //  переменная: вспоминаем точку возврата   } (this)
        //sess->templReturnBackPoint.push( this );
        sess->templReturnBackPoint = this ;

        return BACK;
    }
};

RefData*  RefTemplateBridgeVar::pred_point( ThisId var_id, Session *s){
    if (this->isOpen()){
        return pred; //?
    } else {
        // указывает на закр скобку-мост своего шаблона
        // по идее ссылка уже должна быть присвоена (при инициализации модуля после загрузки)
        return this->getBridge();
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
        //return sess->templReturnBackPoint.top();
        return s->matchSessions.back()->templReturnBackPoint;
    }
};


TResult  RefTemplateBridgeTmpl::back(Session* s, RefData *&l, RefData *&r){
    if (this->isOpen()){  //  {
        /// неудачное сопоставление внешнего шаблона
        //  в переменной будет удалена подсессия и точка возврата
        return BACK;
    } else {              //  }
        /// откат к ранее успешному сопоставленному пользовательскому шаблону
        //  шаблон: в переменной была возвращена и активирована подсессия, восстановлена точка возврата
        return BACK;
    }
};

RefData*  RefTemplateBridgeTmpl::pred_point( ThisId var_id, Session *s){
    if (this->isOpen()){
        //return sess->templReturnBackPoint.top()->other;
        return s->matchSessions.back()->templReturnBackPoint->other;
    } else {
        return pred;
    }
};


#include <pair.h>
#include <list>
#include <sstream>


#include "kernel.h"
#include "session.h"
#include "datastructs.h"

TVarBody::TVarBody(RefData* l, RefData* r, RefObject* o)  {
    first=l;
    second=r;
    owner = o;
    //sess = 0;
};

TVarBody * TVarBody::folowByWay(unistring path){
    #ifdef DEBUG
    if (path == EmptyUniString) SYSTEMERROR("mpty subVar path : " + toString());
    #endif

    size_t t_from  = 0;
    size_t t_to    = -1;
    unistring vname;
    TVarBody * varItem = this;
    do {
        t_from = t_to+1;
        t_to   = path.find(varPathSeparator, t_from);
        #ifdef DEBUG
        std::cout << "\n\n" << path.substr(t_from, t_to-t_from) << "\n\n" << flush;
        #endif

        vname = path.substr(t_from, t_to-t_from);

        // пробегаемся по подсессиям сопоставлений
        std::list<SessionOfMaching *>::reverse_iterator som = varItem->sessStack.rbegin();
        TVarBodyTable::iterator fnded;

        while( som != varItem->sessStack.rend()){

            TVarBodyTable varTable = ((*som)->varTable);
            fnded = varTable.find(vname);
            if (fnded != varTable.end()){
                varItem  = (*fnded).second;
                break;
            }

            ++som;
        }

        if (som == varItem->sessStack.rend()) {
            SYSTEMERROR("subVariable not found : " << path << "  for  " << toString());
        }

    } while (t_to != std::string::npos);

    return varItem;

};


Session::Session() {
};

Session::~Session(){
};

TVarBody* Session::setVarBody( unistring vname, TVarBody* vb){
    #ifdef DEBUG
    if (! matchSessions.size()) {
        showStatus(); SYSTEMERROR("matchSessions is EMPTY!");
    }
    #endif
    ( matchSessions.back()->varTable )[ vname ] = vb;
    return vb;
};

TVarBody* Session::getVarBody( unistring vname ){
    #ifdef DEBUG
    if (this->matchSessions.empty()) SYSTEMERROR("matchSessions is EMPTY!");
    #endif

    std::list<SessionOfMaching *>::reverse_iterator som = this->matchSessions.rbegin();
    TVarBodyTable::iterator fnded;
    //TVarBody* result = 0;

    while( som != this->matchSessions.rend()){

        TVarBodyTable varTable = ((*som)->varTable);
        fnded = varTable.find(vname);
        if (fnded != varTable.end()){
            return  (*fnded).second;
        }

        ++som;
    }
    #ifdef DEBUG
    SYSTEMERROR("varieble not found in maps: " << vname);
    #endif
    return 0;
};

// ищет по всем модулям
RefObject*  Session::getObjectByName(unistring name, Session *s){
    ///todo: проверить указан ли модуль явно и если указан, то искать только в нем
    std::map<unistring, RefModuleBase*>::reverse_iterator mod;
    RefObject* result = 0;
    //std::cout << "\n\n" << modules.size() << flush << "\n\n";


    for ( mod=this->modules.rbegin() ; mod != this->modules.rend(); ++mod ){
        std::cout << "\n\n" << mod->second->getName() << flush << "\n\n";

        if (result = mod->second->getObjectByName(name, s)){
            return result;
        }
    }
    return 0;
};

// ищет последнюю точку возврата
RefTemplateBridgeVar * Session::getTemplReturnBackPoint(){
     std::list<SessionOfMaching *>::reverse_iterator som;
     for (som = matchSessions.rbegin(); som != matchSessions.rend(); ++som ){
            if ((*som)->templReturnBackPoint){
                return (*som)->templReturnBackPoint;
            }
     }
     SYSTEMERROR("templReturnBackPoint NOT EXISTS");
};

unistring Session::varTableToText(){
        //std::string result = "";
        std::ostringstream s;
        s << "\n\nVARTABLES\t:[subsessions: " << this->matchSessions.size() << "]"<< "\n";
        //std::cout << "\n\nVARTABLES\t:[subsessions: " << this->matchSessions.size() << "]"<< "\n";

        std::list<SessionOfMaching *>::reverse_iterator som;
        for (som = matchSessions.rbegin(); som != matchSessions.rend(); ++som ){
            s << "--=== Subsession: " << (*som) << "\n";
            TVarBodyTable tbl = (*som)->varTable;

            TVarBodyTable::iterator it;
            for (it = tbl.begin(); it != tbl.end(); ++it){
                s << (*it).first << '\t' ;
                if ((*it).second) { s << vectorToString(((*it).second)->first, ((*it).second)->second) << '\n'; }
                else { s << "$NULL" << '\n'; }
            }
            s << "----------------------\n";
        }
        s << "======================\n";

        return s.str();
};




bool matchingBySession(Session *s, RefChain *tmplate, bool isdemaching);

/*  Сопоставляет шаблон с аргументом. Аргумент должен быть подцепочкой (т.е. окружон слева и справа элементами)
    Шаблон должен быть с дотами (на данный момент все левые части оснащ. дотами при загрузке)
    Если внутри шаблона есть другие датадоты, то для их сопоставления НУЖНО запускать отдельный матчинг
    Управляет полями зрения во время сопоставления

    После провального матчинга условия - сессия д.б. исходной. Все новое - мусор
    После успешного матчинга условия - все новое нужно сохранить для возможного отката

    Если isdemaching==true, то argleft и argrigh игнорируются.
*/
bool  Session::matching(RefChain *tmplate, RefData *argleft, RefData *argrigh, bool isdemaching){
    bool succmatch = false;

    if (! isdemaching){
        /// новое сопоставление в цепочке
        //  поместить новое поле зрения в стек
        //  создать точку восстановления
        this->matchSessions.push_back( new SessionOfMaching(argleft, argrigh) );
        //  showStatus();
        //  запустиь матчинг
        succmatch = matchingBySession(this, tmplate, isdemaching);
    } else {
        /// продолжение старого сопоставления, начиная с предыдущего состояния (цепочке условий неудача)
        //  задействовать нужное поле зрения (уже: должно быть на вершине стека подсессий, так как предшествующая неудача должна была удалить свою точку - останется эта)
        //  начать с конца матчинг
        succmatch = matchingBySession(this, tmplate, isdemaching);
    }

    if (succmatch){
        // если успех, то сохранить состояние, и вернуть успех
        return succmatch;
    }//else {
        // если провал, то очистить все последствия (откатиться до точки, очистить созданное после точки и саму точку)
        #ifdef DEBUG
        if (! this->matchSessions.size()) SYSTEMERROR("alarm");
        #endif
        delete this->matchSessions.back();
        this->matchSessions.pop_back();
        return succmatch;
    //}
}




bool matchingBySession(Session *s, RefChain *tmplate, bool isdemaching){

    /**/
    std::cout << "\n\n###################################################\n";
    std::cout << "####\t" << s->getPole_zrenija()->toString() << "\n";
    std::cout << "####\t~\n";
    std::cout << "####\t" << tmplate->toString() << "\n";
    std::cout << "#######################################################\n";
    //std::cout << s->varTableToText();
    //s->showStatus();
    /**/

//    std::cout << "\n\nMATCHING:\ntmpl: " << tmplate->toString();
//    std::cout << "\nargs: " << s->pole_zrenija.top()->toString();

    TResult  pre_sost = isdemaching?BACK:GO, result_sost = isdemaching?BACK:GO;

    RefChain *args = s->getPole_zrenija();
    #ifdef DEBUG
    if (!args || !args->first || !args->second) { SYSTEMERROR("unexpected NULLs in session::matching arguments!"); }
    #endif

    // запускается вне матчинга: initialization(args->first, args->second);
    RefData *l=0, *r=0,
        *activeTemplate = isdemaching?tmplate->second:tmplate->first, // было: tmplate->second->pred - это потому что последний датадот. сделал tmplate->second чтоб откат обработал скобки
        *preCurrentPoint=0;

    RefVariable * ifvar=0;
    l=r=s->getPole_zrenija()->first; // для isdemaching не важно - все равно сначала будет restore

    while (activeTemplate) {
        /* */
        std::cout << "\n>>   ";
        switch(result_sost){
            case GO :       std::cout << "GO   "; break;
            case BACK :     std::cout << "BACK "; break;
            case ERROR :    std::cout << "ERROR"; break;
            default:        std::cout << "???? ";
        }
        std::cout << " [s:"<< s->matchSessions.size() << "//" << s->matchSessions.back() <<"] ";
        //std::cout << "\n>>   " << (result_sost==GO?"GO":"BACK");
        std::cout << "\t" << activeTemplate->toString() << "\t\t~\t" /*<< getCurrentSopostStack().size()*/ << std::flush;
        std::cout << "\t";  print_vector(r);
        //*/
        pre_sost = result_sost;
        // даны l и r  (l=r=pred)
        if (pre_sost==GO){
            l = r; // началом становится конец предыдущего - r - конец сопоставленного значения переменной которая левее

            #ifdef DEBUG
            RefObject *lastowner = 0;
            if (s->getCurrentSopostStack()->empty()){

                lastowner = 0;
            } else {
                lastowner = s->getCurrentSopostStack()->top()->owner;
            };
            #endif

                    result_sost = activeTemplate->init(s, r);
                    if (result_sost == GO || result_sost == SUCCESS){  // сохранять сотояние для элемента с SUCCESS нужно для дематчинга
                        if (l==r){ // r не изменилось => пустое
                            s->SaveTemplItem(activeTemplate, 0, l);
                        } else {
                            move_to_next_point(l, 0, s);  ///
                            s->SaveTemplItem(activeTemplate, l, r);
                        }
                        //std::cout << "A: " << activeTemplate->toString() << "\n" << flush;
                        //std::cout << "B: " << activeTemplate->next << "\n" << flush;
                        move_to_next_point(activeTemplate, 0, s);
                    } else
                    if (result_sost == BACK){
                        // не сохраняем ничего

                        #ifdef DEBUG
                        RefObject *newowner = 0;
                        if (s->getCurrentSopostStack()->empty()){
                            newowner = 0;
                        } else {
                            newowner = s->getCurrentSopostStack()->top()->owner;
                        }
                        if (!lastowner  ||  lastowner != newowner){
                            SYSTEMERROR("!lastowner  ||  lastowner != newowner,   lastowner=" << (lastowner?lastowner->toString():"null"));
                        }
                        //std::cout << "\n" << "{{{{{{ " << lastowner << std::flush << ": " ;
                        //std::cout << ((RefData *)(lastowner))->toString() << std::flush;
                        //std::cout << "\n" << "{{{{{{ " << newowner  << std::flush << ": " ;
                        //RefData * tmpd = dynamic_cast<RefData *>(newowner);
                        //std::cout << tmpd->toString() << std::flush << "\n\n";
                        #endif

                        r = 0;
                        move_to_pred_point(activeTemplate, 0, s);
                    }

        } else
        if (pre_sost==BACK){
//s->showStatus();
            s->RestoreTemplItem(activeTemplate, l, r);
//s->showStatus();
            result_sost = activeTemplate->back(s, l, r);
            if (result_sost == GO){
                #ifdef DEBUG
                //if (!l) SYSTEMERROR("Unexpected situation: after back(l,r) method, l==null ! For simple variable it is mistake! Marat, prover - eli peremennaja ne prostaja, to vozmozhno nado ubrat etu proverku. Peremennaja: "+activeTemplate->toString() << "[" << activeTemplate << "]  BACK -> back() -> GO");
                #endif
                s->SaveTemplItem(activeTemplate, l, r);
                //s->showStatus();
                move_to_next_point(activeTemplate, 0, s);
            } else
            if (result_sost == BACK){
                // не сохраняем ничего
                r = 0;
                        // обнуляем вармапинг для переменной - чтоб не было ошибок при showStatus.
                        // Может создать ошибки для varBridge
                        IRefVar* vart = dynamic_cast <IRefVar *>(activeTemplate);
                        if (vart && vart->getName() != EmptyUniString){
                            //std::cout << "\n::::: del map for : " << vart->getName() << flush << "\n";
                            s->setVarBody(vart->getName(), 0);
                        }
                move_to_pred_point(activeTemplate, 0, s);
            }
        }

        switch (result_sost) {
        case ERROR :
            //return -1;
            #ifdef DEBUG
            LOG( "ERROR signal when maching!" );
            #endif
            return false;
        case FAIL   :
            #ifdef DEBUG
            //LOG( "FAIL signal when maching!" );
            #endif
            return false;

        case SUCCESS :
            #ifdef DEBUG
            //LOG( "SUCCESS signal when maching!" );
            #endif
            return true;

        case FORCEBACK:
            RefBracketBase* br = dynamic_cast<RefBracketBase *>(activeTemplate);
            if (!br){
                SYSTEMERROR("FORCEBACK not for barcket! But for : " << activeTemplate->toString());
            }

            while(s->getCurrentSopostStack()->top()->owner != br->getOther()){
                #ifdef DEBUG
                if (! s->getCurrentSopostStack()->size()) SYSTEMERROR("Empty getCurrentSopostStack() while FORCEBACKing");
                #endif
                LOG( ">> BACKFORSE DROP: " << s->getCurrentSopostStack()->top()->owner->toString() );
                s->getCurrentSopostStack()->pop(); /// clean pered pop ?
            }

            // сейчас активна закрытая скобка
            while (activeTemplate != br->getOther()){
                activeTemplate->forceback(s);  // принудительный откат переменной
                LOG( ">> BACKFORSE forceback: " << activeTemplate->toString() );
                move_to_pred_point(activeTemplate, 0, s);
            }; // (

            //this->getCurrentSopostStack().pop(); /// clean pered pop ? // - for (
            //move_to_pred_point(activeTemplate, 0, this);
            result_sost = BACK;
        };
    };

/*
    std::cout << "\nActiveTemplate is NULL while matching: [" <<pre_sost<<']';
    std::cout << "\n>   tmpl:" << activeTemplate; if(activeTemplate) activeTemplate->print_inf();
    std::cout << "\n>>  vars:" << r; if(r) r->print_inf();
    std::cout << "\n>>> pre_sost:" << pre_sost << std::flush;
*/
    ///todo: ниже экспериментальное: тоключил наобум, когда тестировал сопоставление внешнего шаблона с условиями -
    //SYSTEMERROR("ActiveTemplate is NULL while matching: [" << pre_sost << "]  ");
    //if (pre_sost == GO) return true; /// ?? может result_sost == GO ?
    if (result_sost == GO) return true; /// ?? может pre_sost == GO ?
    return false;

};

RefChain* Session::RightPartToObjectExpression(RefChain *src){  // готовит правую часть для сопоставления - подстановка переменных
    std::cout << "\n\nRightPartToObjectExpression( " << src->toString() << " )\n\n";
    //showStatus();
    RefChain* tmp = src->Copy( this );
    //std::cout << "RESULT RightPartToObjectExpression: " << tmp->toString()  << "\n" << std::flush;
    return tmp; ///todo: сократить

};

/*
//  завершение работы с текущим полем зрения. удаление датадот и возврат устаревшего поля зрения как вектора
RefChain* Session::deinitializationArg() {
    RefChain *pz = pole_zrenija.top();
    //std::cout << "\ndeinitializationArg::\t" << pz->toString();
    RefData* pleft  = pz->first;
    RefData* pright = pz->second;
    /*
    #ifdef DEBUG
    if (! dynamic_cast<RefData_DOT *>(StackOfDataSkob.top()) )
        SYSTEMERROR("StackOfDataSkob.top() != DataDOT");
    #endif
    StackOfDataSkob.pop(); //???  а если удачное сопост-е
    std::cout << "\n\n% % % after.pop: " << StackOfDataSkob.size() << "\n\n" << std::flush;
    * /
    pole_zrenija.pop();

    #ifdef DEBUG
    if (! pleft || ! pright || !dynamic_cast<RefData_DOT *>(pleft) || !dynamic_cast<RefData_DOT *>(pright) || !(pleft->next) || !(pright->pred)) {
        SYSTEMERROR("polezrenija ne emeet vida  DOT[ - ... - ]DOT libo narusheni ssilki next-pred!!!");
    }
    #endif

    if (pleft->next == pright){ // если пустое поле зрения  dot[ <-> dot]
        if (pleft  ->pred) pleft  ->pred->next = pright ->next;
        if (pright ->next) pright ->next->pred = pleft  ->pred;
        pright = pleft->pred;
        pleft = 0;
    } else {    // не пустое поле зрения  dot[ - ... - ]dot
        /*if (pleft  ->next) * / pleft  ->next->pred = pleft  ->pred;
        /*if (pright ->pred) * / pright ->pred->next = pright ->next;
        if (pleft  ->pred) pleft  ->pred->next = pleft  ->next;
        if (pright ->next) pright ->next->pred = pright ->pred;
        pleft  = pleft->next;
        pright = pright->pred;
    }

    pz->first  ->next = pz->first  ->pred = pz->second ->next = pz->second ->pred = 0;
    delete pz->first;
    delete pz->second;
    pz->first  = pleft;
    pz->second = pright;
    //std::cout << "\t->\t" << pz->toString();
    return pz;
};
*/



/*void Session::initializationTemplate(RefChain *tpl) { //  оснащение дотами шаблона
    RefData * l =  tpl->first;
    RefData * r =  tpl->second;
    //std::cout << "\ninitializationTemplate::\t" << tpl->toString();

    #ifdef DEBUG
    //if (!r || !l) SYSTEMERROR("r or l is NULL !!! l="<<l<< " r="<<r);
    #endif
    // снабжаем область зрения датадотами
    RefData_DOT *leftd = new RefData_DOT();
    RefData_DOT *rightd = new RefData_DOT(leftd, 0);
    if (l) {
        #ifdef DEBUG
        if (!r) SYSTEMERROR("!r && l  !!! l="<<l<< " r="<<r);
        #endif
        l->predInsert(leftd);
        r->afterInsert(rightd);
    } else {
        if (r){
            r->afterInsert(leftd);
            leftd->afterInsert(rightd);
        } else {
            leftd->afterInsert( rightd );
        }
    }
    tpl->first = leftd;
    tpl->second = rightd;
    //std::cout << "\t->\t" << tpl->toString();
};


void Session::deinitializationTemplate(RefChain *&tpl) { //  удаление дот шаблона
    //std::cout << "\ndeinitializationTemplate::\t" << tpl->toString();

    RefData * l =  tpl->first;
    RefData * r =  tpl->second;
    #ifdef DEBUG
    if (!r || !l) SYSTEMERROR("r or l is NULL !!!");
    RefData_DOT *tmp;
    /*tmp = dynamic_cast<RefData_DOT *>(tpl->second->next);
    if (!tmp) SYSTEMERROR("tpl->second->next not a DOT : " << ((tpl->second->next)?tpl->second->next->toString():"0"));
    tmp = dynamic_cast<RefData_DOT *>(tpl->first->pred);
    if (!tmp) SYSTEMERROR("tpl->first->pred not a DOT : " << ((tpl->first->pred)?tpl->first->pred->toString():"0"));* /

    tmp = dynamic_cast<RefData_DOT *>(tpl->second);
    if (!tmp) SYSTEMERROR("tpl->second not a DOT : " << ((tpl->second)?tpl->second->toString():"0"));
    tmp = dynamic_cast<RefData_DOT *>(tpl->first);
    if (!tmp) SYSTEMERROR("tpl->first not a DOT : " << ((tpl->first)?tpl->first->toString():"0"));
    #endif

    if (tpl->first->next == tpl->second){ // пустой
        tpl->first = tpl->second = 0;
    } else {
        tpl->first  = tpl->first->next;
        tpl->second = tpl->second->pred;
    }

    delete l;
    delete r;

    //std::cout << "\t->\t" << tpl->toString();

};*/




// сохраняет состояние переменной во время сопоставления
void Session::SaveTemplItem(RefData* v, RefData* l, RefData* r) {
    //std::cout << "\nSaveTempl::\t" << v->toString() << "\t->\t" << vectorToString(l, r);


    RefBracketBase *rb;
    if ((rb = dynamic_cast<RefBracketBase *>(r)) && (rb->isOpen()) && (!dynamic_cast<RefData_DOT *>(r))) {
        r = rb->getOther();
    }

    TVarBody *varBody = new TVarBody(l, r, v);      /// todo ... сохранять состояние только переменных

    // переменные внешнего типа обрабатываются персонально
    RefTemplateBridgeVar *bridge = dynamic_cast<RefTemplateBridgeVar *>(v);
    if (bridge){
        /// случай когда удачно сопоставлена переменная внешнего типа

        if (! bridge->isOpen()){       ///  [}]
            // сохраняем состояние сопоставления в тело переменной (основную подсессию шаблона и подсессии условий шаблона)
            SessionOfMaching *sess;
            do {
                sess = this->matchSessions.back();
                #ifdef DEBUG
                if (! sess){ SYSTEMERROR("alarm!"); }
                #endif
                varBody->sessStack.push_back(sess);
                this->matchSessions.pop_back();
            } while(! sess->templReturnBackPoint);
            //sess->templReturnBackPoint = 0; //??? зачем?

            // сохраняем полную область сопоставления (основываясь на том, что обе скобки ~ внешн перем. ~ имеют одно имя переменной)
            // поскольку на данный момент обе скобки-моста сопоставляются с пустым выражением, то ссылки на нужные элементы хранятся в second
            RefData *leftSecond = getVarBody(bridge->getName())->second; /// todo сделать эффективнее. Без использования промежуточного сохранения в map
            #ifdef DEBUG
            if (getVarBody(bridge->getName())->first || l) SYSTEMERROR("Skobki !~ 0"); // сохранение переменных внешнего типа завязано на том, что скобки внешней переменной сопоставляются с пустым выражением. А взор всей переменной - по границам пустых выражений
            #endif
            if (leftSecond != r){ // взор на НЕ пустое выражение
                varBody->first  = leftSecond->next;
                //varBody->second = уже какое надо
            } /*else {
                varBody уже какое надо
            }*/
            getCurrentSopostStack()->push( setVarBody(bridge->getName(), varBody) );

        } else {        ///  [{]
            //  сохраняем сопоставление в вызывающей субсессии
            getCurrentSopostStack()->push( setVarBody(bridge->getName(), varBody) );
            //  создаем подсессию для шаблона - стелим подкладку для сопоставления шаблона
            SessionOfMaching *sess = new SessionOfMaching(getPole_zrenija());
            //  текущую закрывающую скобку копируем в новое сопоставление - граница действий нового сопоставления
            sess->StackOfDataSkob.push( matchSessions.back()->StackOfDataSkob.top()  );
            matchSessions.push_back(sess);
            //  сохраняем конец ссылки на шаблон для возврата  }
            sess->templReturnBackPoint =  (RefTemplateBridgeVar *)bridge->other ;  //  }

        }

        //showStatus();
    } else {
        /// не внешняя переменная
        // если элемент является переменной (наследуется от соотв интерфейса - это признак), то ...
        IRefVar* vart = dynamic_cast <IRefVar *>(v);

        if (vart && vart->getName() != EmptyUniString){
            // если переменная с именем, то сохр. в карте переменных и в стеке
            getCurrentSopostStack()->push( setVarBody(vart->getName(), varBody) );
        } else {
            // все остальное - только в стеке
            getCurrentSopostStack()->push( varBody );
        }

    }

};


void Session::RestoreTemplItem(RefData *owner, RefData* &l, RefData* &r) {
    RefTemplateBridgeVar *bridge = dynamic_cast<RefTemplateBridgeVar *>(owner);

    if (bridge){
        if (bridge->isOpen()){   ///  [{]
            delete matchSessions.back();   // удаление субсессии для внешней переменной
            matchSessions.pop_back();

            #ifdef DEBUG
            if (getCurrentSopostStack()->empty()) SYSTEMERROR("empty sopost stack!");
            if (getCurrentSopostStack()->top()->owner != owner) SYSTEMERROR("wrong owner for " << owner->toString() << " : " << getCurrentSopostStack()->top()->owner->toString() );
            #endif
            getCurrentSopostStack()->pop();

            return;
        } else {            ///   [}]
            int i=0;
        }
    }

    #ifdef DEBUG
    if ( getCurrentSopostStack()->empty() ) {
        showStatus();  SYSTEMERROR("empty stak!!!  " );
    }
    #endif

    TVarBody *varBody = getCurrentSopostStack()->top();
    getCurrentSopostStack()->pop();

    if (bridge && !bridge->isOpen()){  ///  [}]
        /// случай когда откат вернулся к переменной внешнего типа
        // восстанавливаем значение левой var-скобки моста
        if (varBody->first){
            // непустое значение
            setVarBody(bridge->getName(), new TVarBody(0, varBody->first->pred, bridge->getOther()));
        } else {
            // пустое значение
            setVarBody(bridge->getName(), new TVarBody(0, varBody->second, bridge->getOther()));
        }

        //  переменная: извлекаем из тела переменной все подсессии (базовую и условий) сопоставления и делаем их акивными
        SessionOfMaching *sess;
        while(! varBody->sessStack.empty()){
            sess = varBody->sessStack.back();
            this->matchSessions.push_back(sess);
            varBody->sessStack.pop_back();
        };

        //sess->templReturnBackPoint = bridge ;
        /// todo: откат до последнего условия может привести к ненужным сопоставлениям и продолжениям, так как если условие при откате снова выполнится,
        /// то ничего по сути не изменится на данном этапе, но произойдет повторная попытка продолжить сопоставление.
        /// откатываться до последнего условия разумно, если в нем инициализируется переменная, используемая далее за пределами
        /// сопоставления шаблона (в объекте) - например в следующем условии внешнего уровня
        /// пока оставил неэффективно - откат к последнему условию шаблона

        //showStatus();
    }

    #ifdef DEBUG
    if (varBody->owner != owner) {
        std::cout << "\n\n\size=" << getCurrentSopostStack()->size() << flush ;
        std::cout << "\ncall owner=" << owner << flush << owner->toString() << std::flush;
        std::cout << "\ntop  owner=" << varBody->owner << flush << varBody->owner->toString() << "\n\n" << std::flush;
        printf("\n");


        std::cout << "\n=======\nGetCurrentSopostStack::\n";
        while (! getCurrentSopostStack()->empty()){
            std::cout << getCurrentSopostStack()->top()->toString() << "\n";
            getCurrentSopostStack()->pop();
        }
        std::cout << flush;

        showStatus(); SYSTEMERROR("RestoreTemplItem for INCORRECT OWNER: " << std::flush << owner->toString() << "[" << owner << "] but " << varBody->owner->toString() << "[" << varBody->owner << "] expected!");
    }
    #endif
    l = varBody->first;
    r = varBody->second;

//showStatus();
    delete varBody;
//showStatus();
    //std::cout << "\nRestoreTemplItem::\t" << owner->toString() << "\t->\t" << vectorToString(l, r);
    return;
};






void Session::regModule(RefModuleBase *m){
    //std::cout << "\n\n\n\nSession::regModule [" << m->getName() << "]  :: " << m->toString() << "\n\n\n\n";
    if (!m) SYSTEMERROR("Tring to load $null module!");
    modules[m->getName()] = m; // сначала модуль присвоим - потом инициализация. Чтоб модулю бы доступен сам модуль через сессию
    m->initilizeAll(this);
    /// todo: связывание у пользовательских переменных ссылок на шаблоны с шаблонми по описаням/именам, указаным в конструкторе
};



// извлечение функции по имени из модулей
RefFunctionBase * Session::findMethodFromModule(unistring fname){
    #ifdef DEBUG
    if (modules.empty()) {
        SYSTEMERROR("No modules loaded!");
    }
    //else std::cout << "\n\n\n\n" << modules.size() << "\n\n\n\n";
    #endif

    /// todo: поддержку разименования namespace:   < mymodule:myfunction   E.args >

    std::map<unistring, RefModuleBase*>::iterator it;
    RefFunctionBase *f = 0;

    // поиск по модулям
    for (it = modules.end(); it!=modules.begin(); it){  // исходя из того что последние модули самые актуальные (см порядок загрузки модулей)
        it--;
        //std::cout << "\n\n:::: " << it->first << " ::::\n\n" << std::flush;
        if (f = dynamic_cast<RefFunctionBase *>( it->second->getObjectByName(fname) )){
            //LOG("implementation of " << fname << " finded (" << f << ") in " << it->first);
            return f;
        }
        //LOG("implementation of " << fname << " NOT FOUND in user-modules");
    }
    // функция не найдена
    return 0;
};


unistring TVarBody::toString(){
        unistring s="VarBody for ";
        s+=owner->toString();
        s+=" with ";
        s+=vectorToString(first,second);
        return sss = s;
};



DataForRepeater::DataForRepeater(RefData *o) {
        owner = o;
        from = to = step = mustbe = current_step = 0;
        leftPoint = 0;
};

void Session::showStatus(){
    std::cout << "\n\n";
    std::cout << "************************************************************************\n";
    std::cout  << "[subsessions: " << this->matchSessions.size() << "]"<< "\n";

    std::list<SessionOfMaching *>::reverse_iterator som;
    for (som = matchSessions.rbegin(); som != matchSessions.rend(); ++som ){
        std::cout << "\n--=== Subsession: " << (*som) << "\n";
        TVarBodyTable tbl = (*som)->varTable;

        std::cout << " varTable:\n";
        TVarBodyTable::iterator it;
        for (it = tbl.begin(); it != tbl.end(); ++it){
                    std::cout << '\t' << (*it).first << '\t' ;
                    if ((*it).second) { std::cout << vectorToString(((*it).second)->first, ((*it).second)->second) << '\n'; }
                    //std::cout << "####:\t" << (*it).first << '\t' ;
                    //if ((*it).second) { std::cout << ((*it).second)->toString() << '\n'; }
                    else { std::cout << "$NULL" << '\n'; }
        }

        std::cout << " : isfar=" << (*som)->isfar << "\n";
        std::cout << " : pole_zrenija=" << (*som)->pole_zrenija->toString()    << "\n";
        //std::cout << " : StackOfDataSkob=" << (*som)->StackOfDataSkob.size()    << "\n";
        std::cout << " : templReturnBackPoint=" << ((*som)&&(*som)->templReturnBackPoint ? (*som)->templReturnBackPoint->toString() : "$NULL")   << "\n";
        std::cout << " : StackOfSopost=" << (*som)->StackOfSopost.size()  << "  " << ((*som)->StackOfSopost.size() ? (*som)->StackOfSopost.top()->toString() : "") << "\n";
        //std::cout << " : StopBrackForceVar=" << ((*som)->StopBrackForceVar ? (*som)->StopBrackForceVar->toString() : "$NULL")   << "\n";


    }


    /*
    std::cout << "\n    pole_zrenija: size=" << pole_zrenija.size() << "  " << (pole_zrenija.empty() ? "" : pole_zrenija.top()->toString());
    std::cout << "\n    StopBrackForceVar: " << (StopBrackForceVar?StopBrackForceVar->toString():"null");
    std::cout << "\n    StacksOfSopost : size=" << StacksOfSopost.size();
    if (StacksOfSopost.size()) {    std::cout << "\n\t    StacksOfSopost.top() : size=" << StacksOfSopost.top()->size();   };
    std::cout << "\n    varTables : size=" << varTables.size() <<  varTableToText();
    std::cout << "\n    StackOfDataSkob : size=" << StackOfDataSkob.size() << std::flush;  std::cout << "  " << (StackOfDataSkob.empty() ? "" : StackOfDataSkob.top()->toString());
    std::cout << "\n    StackOfRepeatSkob : size=" << StackOfRepeatSkob.size() << "  " << (StackOfRepeatSkob.empty() ? "" : StackOfRepeatSkob.top()->toString());
    std::cout << "\n    StackOfRepeatSkobDoned : size=" << StackOfRepeatSkobDoned.size() << "  " << (StackOfRepeatSkobDoned.empty() ? "" : StackOfRepeatSkobDoned.top()->toString());
    std::cout << "\n    StackOfGroupSkob : size=" << StackOfGroupSkob.size() << "  " << (StackOfGroupSkob.empty() ? "" : StackOfGroupSkob.top()->toString());
    RefTemplateBridgeVar
    */
    std::cout << "************************************************************************\n";
    std::cout << "\n\n";

}

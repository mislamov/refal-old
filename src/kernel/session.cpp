#include <pair.h>
#include <sstream>


#include "kernel.h"
#include "session.h"
#include "datastructs.h"

TVarBody::TVarBody(RefData* l, RefData* r, RefObject* o, TVarBodyTable *themap)  {
    first=l;
    second=r;
    owner = o;
    subv = themap;
};



Session::Session() {
    //varTables.push( new TVarBodyTable() );
    StacksOfSopost.push( new std::stack<TVarBody *> );
/*
    RefData_DOT *l_dot = new RefData_DOT();
    RefData_DOT *r_dot = new RefData_DOT(l_dot);
    TVarBody *p = new TVarBody(l_dot, r_dot, this);

    pole_zrenija.push( p );
    StackOfDataSkob.push(r_dot);
    StopBrackForceVar = 0;
    varTable.push(new TTableVarSaver(l_dot, r_dot));
*/
};

Session::~Session(){
};

TVarBody* Session::getVarBody( unistring vname ){
    return (*(varTables.top()))[ vname ];
};

TVarBody* Session::setVarBody( unistring vname, TVarBody* vb){
    (* varTables.top())[ vname ] = vb;
};

unistring Session::varTableToText(){
        //std::string result = "";
        if (! varTables.size()){
            return "\n\nVARTABLES  varTables\t:\tempty\n";
        }

        std::ostringstream s;
        s << "\n\nVARTABLES\t:" << varTables.size() << "\n";

        if (! (* varTables.top()).size() ){
            s << "VARTABLES  varTables.top()\t:\tempty\n";
            return s.str();
        }

        s << "VARTABLES.TOP\t:" << (* varTables.top()).size() << "\n";
        TVarBodyTable::iterator it;
        for (it = (* varTables.top()).begin(); it!=(* varTables.top()).end(); it++){
           if ((*it).second) {
               s << (*it).first << '\t' << vectorToString(((*it).second)->first, ((*it).second)->second) << '\n';
           }
        }
        return s.str();
};


// подготовка к матчингу. подстановка мусорного ведра
void matchingGarbagePrepare(Session *s){
    // создаем свежий стек сопоставлений
    //s->StacksOfSopost.push( new std::stack<TVarBody*> );
    s->StackOfDataSkob.push((RefData_DOT *) s->pole_zrenija.top()->second );
/** /
    std::cout << "\n#######################################################\n";
    std::cout << "BEFORE matching:\n";
    std::cout << "\ts->StackOfDataSkob.top :\t" <<  (s->StackOfDataSkob.empty()?"$empty":s->StackOfDataSkob.top()->toString()) << "\n";
    //std::cout << "\ts->StackOfGroupSkob.top :\t" << (s->StackOfGroupSkob.empty()?"$empty":s->StackOfGroupSkob.top()->toString()) << "\n";
    //std::cout << "\ts->StackOfRepeatSkob :\t" << s->StackOfRepeatSkob.top()->toString() << "\n";
    //std::cout << "\ts->StackOfRepeatSkobDoned.top :\t" << s->StackOfRepeatSkobDoned.top()->toString() << "\n";
    std::cout << "\ts->StacksOfSopost.top.top :\t" << ( (s->StacksOfSopost.empty()||s->StacksOfSopost.top()->empty())?"$empty":s->StacksOfSopost.top()->top()->toString()) << "\n";
    std::cout << "#######################################################\n";
//*/
}

// очищение мусора сессии. Если tosavevarmap, то среди мусора может оказаться нужное - то что в карте переменных
void matchingGarbageCleaner(Session *s, bool tosavevarmap=false){
    // удаляет последний стек сопоставлений, очищая его содержимое. Если tosavevarmap, то очищает не полностью - оставляет то, что в карте переменных
    //std::stack<TVarBody *> *upstack = s->getCurrentSopostStack();
    //s->StacksOfSopost.pop(); - не надо чистить, тк это может быть для условия, кот-е придется откатывать

        //std::cout << "\n$poping by matchingGarbageCleaner" << "  :  " << s->StackOfDataSkob.top()->toString();
        s->StackOfDataSkob.pop(); // del DOT

    /// todo аккуратное удаление данных сопоставления

    //delete upstack; // стек очищен где надо
/** /
    std::cout << "\n######################  matchingGarbageCleaner  #################################\n";
    std::cout << "After matching:\n";
    std::cout << "\ts->StackOfDataSkob.top :\t" <<  (s->StackOfDataSkob.empty()?"$empty":s->StackOfDataSkob.top()->toString()) << "\n";
    //std::cout << "\ts->StackOfGroupSkob.top :\t" << (s->StackOfGroupSkob.empty()?"$empty":s->StackOfGroupSkob.top()->toString()) << "\n";
    //std::cout << "\ts->StackOfRepeatSkob :\t" << s->StackOfRepeatSkob.top()->toString() << "\n";
    //std::cout << "\ts->StackOfRepeatSkobDoned.top :\t" << s->StackOfRepeatSkobDoned.top()->toString() << "\n";
    std::cout << "\ts->StacksOfSopost.top.top :\t" << ( (s->StacksOfSopost.empty()||s->StacksOfSopost.top()->empty()) ?"$empty":s->StacksOfSopost.top()->top()->toString()) << "\n";
    std::cout << "#######################################################\n";
//*/
    return;
}


bool matchingBySession(Session *s, RefChain *tmplate, bool isdemaching);


bool  Session::matching(RefChain *tmplate, bool isdemaching){
    if (! isdemaching){
        // не нужно ничего создавать если откат!
        matchingGarbagePrepare(this);
    }

    #ifdef DEBUG
    if (! dynamic_cast<RefData_DOT *>( pole_zrenija.top()->second )) SYSTEMERROR("unexpected situation!");
    #endif

    bool succmatch = matchingBySession(this, tmplate, isdemaching);

    #ifdef DEBUG
    if (! pole_zrenija.size()) SYSTEMERROR("empty pole");
    if (! this->StackOfDataSkob.size()) SYSTEMERROR("empty skobs " << StackOfDataSkob.size());
    if (pole_zrenija.top()->second != this->StackOfDataSkob.top()) {
        SYSTEMERROR("matching with not balanced skobs : pole_zrenija.top()->second=" << pole_zrenija.top()->second->toString() << "   !=  this->StackOfDataSkob.top()=" << this->StackOfDataSkob.top()->toString() << "("<< this->StackOfDataSkob.size() <<")" );
    }
    #endif

    //std::cout << "\n$poping by " << this->toString() << "  :  " << StackOfDataSkob.top()->toString() <<  "    left: " << StackOfDataSkob.size()-1;
    if (succmatch){
        //matchingGarbageCleaner(this, true);
    } else {
        matchingGarbageCleaner(this, false);
    }
    return succmatch;
}




bool matchingBySession(Session *s, RefChain *tmplate, bool isdemaching){

    /*std::cout << "\n\n#######################################################\n";
    std::cout << s->pole_zrenija.top()->toString() << "\n";
    std::cout << "~\n";
    std::cout << tmplate->toString() << "\n";
    std::cout << "\n#######################################################\n";
    std::cout << "\n" << s->varTableToText();
    */
//    std::cout << "\n\nMATCHING:\ntmpl: " << tmplate->toString();
//    std::cout << "\nargs: " << s->pole_zrenija.top()->toString();

    TResult  pre_sost = isdemaching?BACK:GO, result_sost = isdemaching?BACK:GO;

    RefChain *args = s->pole_zrenija.top();
    #ifdef DEBUG
    if (!args || !args->first || !args->second) { SYSTEMERROR("unexpected NULLs in session::matching arguments!"); }
    #endif

    // запускается вне матчинга: initialization(args->first, args->second);
    RefData *l=0, *r=0,
        *activeTemplate = isdemaching?tmplate->second->pred:tmplate->first, // tmplate->second->pred - это потому что последний датадот
        //*currentLeft  = this->pole_zrenija.top()->first,
        //*currentRight = this->pole_zrenija.top()->first,
        //*preCurrentLeft, *preCurrentRight;
        //*currentPoint = this->pole_zrenija.top()->first,
        *preCurrentPoint=0;

    RefVariable * ifvar=0;
    l=r=s->pole_zrenija.top()->first; // для isdemaching не важно - все равно сначала будет restore

    while (activeTemplate) {
        /* */
        //std::cout << "\n>>   " << (result_sost==GO?"GO":"BACK");
        //std::cout << "\t" << activeTemplate->toString() << " ~ " /*<< getCurrentSopostStack().size()*/ << std::flush;

        //std::cout << "\t";  print_vector(r);
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
                    if (result_sost == GO){
                        if (l==r){ // r не изменилось => пустое
                            s->SaveTempl(activeTemplate, 0, l);
                        } else {
                            move_to_next_point(l, 0, s);  ///
                            s->SaveTempl(activeTemplate, l, r);
                        }
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
                            SYSTEMERROR("!lastowner  &&  lastowner != newowner,   lastowner=" << lastowner->toString());
                        }
                        //std::cout << "\n" << "{{{{{{ " << lastowner << std::flush << ": " ;
                        //std::cout << ((RefData *)(lastowner))->toString() << std::flush;
                        //std::cout << "\n" << "{{{{{{ " << newowner  << std::flush << ": " ;
                        RefData * tmpd = dynamic_cast<RefData *>(newowner);
                        //std::cout << tmpd->toString() << std::flush << "\n\n";
                        #endif
                        r = 0;
                        move_to_pred_point(activeTemplate, 0, s);
                    }

        } else
        if (pre_sost==BACK){
            s->RestoreTempl(activeTemplate, l, r);
            result_sost = activeTemplate->back(s, l, r);
            if (result_sost == GO){
                #ifdef DEBUG
                if (!l) SYSTEMERROR("Unexpected situation: after back(l,r) method, l==null ! For simple variable it is mistake! Marat, prover - eli peremennaja ne prostaja, to vozmozhno nado ubrat etu proverku. Peremennaja: "+activeTemplate->toString() << "[" << activeTemplate << "]  BACK -> back() -> GO");
                #endif
                s->SaveTempl(activeTemplate, l, r);
                move_to_next_point(activeTemplate, 0, s);
            } else
            if (result_sost == BACK){
                // не сохраняем ничего
                r = 0;
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
    SYSTEMERROR("ActiveTemplate is NULL while matching: [" << pre_sost << "]  ");
    return false;

};

RefChain* Session::RightPartToObjectExpression(RefChain *src){  // готовит правую часть для сопоставления - подстановка переменных
    //std::cout << "\n\nRightPartToObjectExpression( " << src->toString() << " )\n\n";
    RefChain* tmp = src->Copy( this );
    //std::cout << "RESULT RightPartToObjectExpression: " << tmp->toString()  << "\n" << std::flush;
    return tmp; ///todo: сократить

};

void Session::initializationArg(RefData* &l, RefData* &r) { //  взгляд на новое поле зрения, подготовка к матчингу
    //std::cout << "\ninitializationArg::\t\t" << vectorToString(l, r);
    #ifdef DEBUG
    if (!r) SYSTEMERROR("!r nelza tak! esli pustaja, to nado pokazat posle kakoj refdata ona stiot => r!=0 !!!");
    #endif
    // снабжаем область зрения датадотами
    RefData_DOT *leftd = new RefData_DOT();
    RefData_DOT *rightd = new RefData_DOT(leftd, 0);

//    std::cout << "\n\nleftd=" << leftd->toString() << "    rightd=" << rightd->toString() << "\n\n";

    //leftd->pred = (l?l->pred:0);

    if (!l){ // пустая
        r->afterInsert(leftd);
        leftd->afterInsert(rightd);
    } else {
        l->predInsert(leftd);
        r->afterInsert(rightd);
    }
    // запоминаем  поле езрения в стеке - теперь оно активно
    RefChain *newPole = new RefChain(leftd, rightd);
    pole_zrenija.push(newPole);
    //StackOfDataSkob.push(rightd);
    StopBrackForceVar = 0;

    //std::cout << "\t->\t" << newPole->toString();
    //std::cout << "\t->\t" << newPole->toString();
    l = leftd;
    r = rightd;
    //current_point = newPole->first;
    //extention_number = 0;
};




RefChain* Session::deinitializationArg() { //  завершение работы с текущим полем зрения. удаление датадот и возврат устаревшего поля зрения
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
    */
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
        /*if (pleft  ->next) */ pleft  ->next->pred = pleft  ->pred;
        /*if (pright ->pred) */ pright ->pred->next = pright ->next;
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




void Session::initializationTemplate(RefChain *tpl) { //  оснащение дотами шаблона
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
    if (!tmp) SYSTEMERROR("tpl->first->pred not a DOT : " << ((tpl->first->pred)?tpl->first->pred->toString():"0"));*/

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

};





void Session::SaveTempl(RefData* v, RefData* l, RefData* r) {
    //std::cout << "\nSaveTempl::\t" << v->toString() << "\t->\t" << vectorToString(l, r);
    RefBracketBase *rb;
    //RefVariable* vart = dynamic_cast <RefVariable *>(v);
    //if (!vart) return;
    if ((rb = dynamic_cast<RefBracketBase *>(r)) && (rb->isOpen()) && (!dynamic_cast<RefData_DOT *>(r))) {
        r = rb->getOther();
    }
    //unistring vname = vart->getName();
    //getCurrentSopostStack().push( varTable.top()->vars[vname] = new TVarSaver(l, r) );

    RefVariable* vart = dynamic_cast <RefVariable *>(v);
    #ifdef DEBUG
    if (StacksOfSopost.empty()) SYSTEMERROR("emplty stacks!");
    #endif
    if (vart && vart->getName() != EmptyUniString){
        getCurrentSopostStack()->push( setVarBody(vart->getName(), new TVarBody(l, r, v)) );
    } else {
        getCurrentSopostStack()->push( new TVarBody(l, r, v) );
    }

};

void Session::RestoreTempl(RefData *owner, RefData* &l, RefData* &r) {
    #ifdef DEBUG
    if (! getCurrentSopostStack()->size() ) SYSTEMERROR("empty stak!!!  staks=" << StacksOfSopost.size());
    #endif
    TVarBody  *pd = getCurrentSopostStack()->top();
    #ifdef DEBUG
    if (pd->owner != owner) {
        std::cout << "\nowner=" << owner->toString() << std::flush;
        std::cout << "\npd->owner=" << pd->owner << "\n\n\n\n\n\n\n\n" << std::flush;
        std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;std::cout << "\npd->owner=" << pd->owner << "  " << std::flush;
        printf("\n");
        SYSTEMERROR("RestoreTempl for INCORRECT OWNER: " << std::flush << owner->toString() << "[" << owner << "] but " << pd->owner->toString() << "[" << pd->owner << "] expected!");
    }
    #endif
    l = pd->first;
    r = pd->second;
    //getCurrentSopostStack().show()->eexport(l, r);
    //delete getCurrentSopostStack().extract();
    TVarBody *tmp = getCurrentSopostStack()->top();
    getCurrentSopostStack()->pop();
    #ifdef DEBUG
    RefVariable* vart = dynamic_cast <RefVariable *>(tmp->owner);
    if (vart) setVarBody( vart->getName(), 0 );
    #endif
    //( varTable[vart->getName()] = new TVarBody(l, r, v) );
    delete tmp;
    //std::cout << "\nRestoreTempl::\t" << owner->toString() << "\t->\t" << vectorToString(l, r);
    return;
};






void Session::regModule(RefModuleBase *m){
    //std::cout << "\n\n\n\nSession::regModule [" << m->getName() << "]  :: " << m->toString() << "\n\n\n\n";
    if (!m) SYSTEMERROR("Tring to load $null module!");
    modules[m->getName()] = m;
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
        return s;
};



DataForRepeater::DataForRepeater(RefData *o) {
        owner = o;
        from = to = step = mustbe = current_step = 0;
        leftPoint = 0;
};

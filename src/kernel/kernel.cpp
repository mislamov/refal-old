#include "kernel.h"
#include "session.h"
//#include "dataterms.h"



RefStructBracket::RefStructBracket(RefData* rp) : RefBracketBase(rp) { is_system = false; };

RefStructBracket::RefStructBracket(RefStructBracket *br, RefData* rp) : RefBracketBase(br, rp) {
    is_system = false;
};
RefData*  RefStructBracket::next_term( ThisId var_id ) {
    if (is_opened) {
        return other->next;//
    }
    return next;
};
RefData*  RefStructBracket::pred_term( ThisId var_id ) {
    if (!is_opened) {
        return getOther()->pred;
    }
    return pred;
};
bool RefStructBracket::operator ==(RefData &rd) {
    RefStructBracket *aux = dynamic_cast<RefStructBracket *>(&rd);
    return  aux && (aux->is_opened == is_opened);
};

TResult RefStructBracket::init(Session* s, RefData *&l) {
    move_to_next_term(l,myid(),s);
    RefStructBracket* aux = dynamic_cast<RefStructBracket *>(l);
    if (!aux || (isOpen()!=aux->isOpen()))  return BACK; //   )  (
    if (isOpen()) {  //    (  (
        //std::cout << "\n% % % : " << std::flush;
        //std::cout << s->getStackOfDataSkob()->size() << std::flush;
        s->getStackOfDataSkob()->push( aux->getOther() );
        l = l->next; // jump into brackets (to NULL-dot)
        return GO;
    };
    //    )  )
    if (aux != s->getStackOfDataSkob()->top()){
        return BACK;
    }
    //std::cout << "\n$poping by " << this->toString() << "  :  " << s->getStackOfDataSkob()->top()->toString();
    s->getStackOfDataSkob()->pop();
    return GO;

};

TResult RefStructBracket::back(Session* s, RefData *&l, RefData *&r) {
    if (is_opened) { //  (
        //std::cout << "\n$poping by " << this->toString() << "  :  " << s->getStackOfDataSkob()->top()->toString();
        s->getStackOfDataSkob()->pop(); /// clean?
        return BACK;
    }

    // )
    #ifdef DEBUG
    if (! dynamic_cast<RefBracketBase *>(r) ){
        SYSTEMERROR("may be unnormal situation");
    }
    #endif
    s->getStackOfDataSkob()->push( dynamic_cast<RefBracketBase*>( r ) );
    //return FORCEBACK; - не надо, т к ситуация мб такая: (e.1 e.all)
    return BACK;
};


void RefStructBracket::forceback(Session *s){
    if (this->isOpen()){
        //std::cout << "\n$poping by " << this->toString() << "  :  " << s->getStackOfDataSkob()->top()->toString();
        //s->getStackOfDataSkob()->pop(); /// - в стеке скобок нет инфы для этой скобки! Она и ее пара была сопоставлена
    }
    return;
}





RefExecBracket::RefExecBracket(RefData* rp) : RefBracketBase(rp) {
    is_system = false;
};

RefExecBracket::RefExecBracket(RefExecBracket *br, RefData* rp) : RefBracketBase(br, rp) {
    is_system = false;
};
RefData*  RefExecBracket::next_term( ThisId var_id ) {
    if (is_opened) {
        return other->next;//
    }
    return next;
};
RefData*  RefExecBracket::pred_term( ThisId var_id ) {
    if (!is_opened) {
        return other->pred;
    }
    return pred;
};
bool RefExecBracket::operator ==(RefData &rd) {
    RefExecBracket *aux = dynamic_cast<RefExecBracket *>(&rd);
    return  aux && (aux->is_opened == is_opened);
};

TResult RefExecBracket::init(Session* s, RefData *&l) {
    SYSTEMERROR("RefExecBracket::init! Exec bracket can't to match!");
    move_to_next_term(l,myid(),s);
    RefData*  a   = l;
    RefExecBracket* aux = dynamic_cast<RefExecBracket *>(a);
//    if (a)  a->drop(myid()); //   удаляет старую ссылку если создатель
    if (!aux || (is_opened!=aux->is_opened))  return BACK; //   )  (
    if (is_opened) {  //    (  (
        s->getStackOfDataSkob()->push( aux->other );
        l = l -> next; // jump into brackets (to NULL-dot)
        return GO;
    };
    //    )  )
    if (aux != s->getStackOfDataSkob()->top()){
        return BACK;
    }

    //std::cout << "\n$poping by " << this->toString() << "  :  " << s->getStackOfDataSkob()->top()->toString();
    s->getStackOfDataSkob()->pop();
    return GO;

};

TResult RefExecBracket::back(Session* s, RefData *&l, RefData *&r) {
    SYSTEMERROR("RefExecBracket::back! Exec bracket can't to match!");
    if (is_opened) { //  (

        //std::cout << "\n$poping by " << this->toString() << "  :  " << s->getStackOfDataSkob()->top()->toString();
        s->getStackOfDataSkob()->pop();
        return BACK;
    } else {          //  )
        return FORCEBACK;
    };
};



TResult  RefVariable_s::init(Session *s, RefData *&a) {
    move_to_next_term(a, myid(), s);
    if (! dynamic_cast<RefBracketBase *>(a) ){
        return GO;
    } else {
        return BACK;
    }
};

TResult  RefVariable_s::back(Session *s, RefData *&l, RefData *&r) {
    return BACK;
};




TResult  RefVariable_t::init(Session *s, RefData *&a) {
    move_to_next_term(a, myid(), s);
    if (dynamic_cast<RefData_DOT *>(a) ){
        return BACK;
    } else {
        // *a оставляем на открытой скобке в надежде на то, что move_to_next_term будет перекидывать за закрытую скобку
        return GO;
    }
};

TResult  RefVariable_t::back(Session *s, RefData *&l, RefData *&r) {
    return BACK;
};




TResult  RefVariable_e::init(Session *s, RefData *&a) {
    return GO;
};

TResult  RefVariable_E::init(Session *s, RefData *&a) {
    //SYSTEMERROR("");
    a = s->getStackOfDataSkob()->top()->pred;
    return GO;
};

TResult  RefVariable_e::back(Session *s, RefData *&l, RefData *&r) {
    //std::cout << "\n## restore for e.e: " << std::flush; if (l) l->print_inf(); std::cout << " , "; if (r) r->print_inf(); std::cout << " next: " << r->next->toString() << "\n" << flush;
    if (l) {
        if (r==s->getStackOfDataSkob()->top()) {
            //std::cout << "\n\n[r] back: " << r->toString() << ' ' << s->getStackOfDataSkob()->size() << std::flush;
            return BACK;
        };
        //std::cout << "\n\n[r]: r==" << r->toString() << "  top=" << s->getStackOfDataSkob()->top()->toString() << "   " << s->getStackOfDataSkob()->size() << std::flush;



        move_to_next_term(r, myid(), s);
        r = r->endOfTerm();
    } else {
        move_to_next_term(r, myid(), s);
        l = r->beginOfTerm();
        r = r->endOfTerm();
    }

    //std::cout << "\ns->getStackOfDataSkob()->top() = " << s->getStackOfDataSkob()->top()->toString();
    //std::cout << "\n\n" << s->getStackOfDataSkob()->size() << "\n\n" << flush;
    #ifdef DEBUG
    if (! s->getStackOfDataSkob()->size()) SYSTEMERROR("empty stack!");
    #endif
    if (r==s->getStackOfDataSkob()->top()) {
        return BACK;
    };
    return GO;

};

TResult  RefVariable_E::back(Session *s, RefData *&l, RefData *&r) {
    if (!l) return BACK;
    if (l==r){
        l = 0;
        r = move_to_pred_point(r, myid(), s);
        return GO;
    }
    r = move_to_pred_point(r, myid(), s);
    //SYSTEMERROR("not yet");
    return GO;
};



//--------------------------------------------------
/*void	RefVariable_e::print_inf() {
    std::cout << " [e." << this->getName().c_str() << "] " << std::flush;
};
void	RefVariable_E::print_inf() {
    std::cout << " [E." << this->getName().c_str() << "] " << std::flush;
};*/

bool	RefVariable_e::operator==(RefData &rd) {
    return dynamic_cast<RefVariable_e *>(&rd);
};
bool	RefVariable_E::operator==(RefData &rd) {
    return dynamic_cast<RefVariable_E *>(&rd);
};

unistring vectorToString(RefData *f, RefData *g){
    unistring a = "";
    //return "----";
    #ifdef DEBUG
     if (!g && f){
        //return "";
        //SYSTEMERROR("f && !g in vectorToString! f=" << f->toString() << " and g=" << g);
    }
    #endif
    if (!f) {
        a+= "$null, ";
        if (g){
            a+=" after "+g->toString();
            //a+="(-> "+(g->next?g->next->toString():"null")+" )";
        } else {
            a+=" $null";
        }
    } else {

        while (f && (!g || f!=g->next)) {
        //while (f && f!=g->next) {
                RefData *ff = f;
                a += f->toString();
                //a += ' ';
                f = f->next;
                if (f && f->pred != ff){
                    #ifdef DEBUG
                    std::cout << a << std::flush;
                    std::cout << "\n~f=" << (f?f->toString():"@null")  << std::flush;
                    std::cout << "\n~f->pred=" << ((f&&f->pred)?f->pred->toString():"@null") << std::flush;
//return a;
                    #endif
                    SYSTEMERROR(" next<>pred : f->pred!=ff : f=" << (f?f->toString():"@null") << std::flush << "\tf->pred=" << ((f&&f->pred)?f->pred->toString():"@null") << std::flush  << " , ff=" << (ff?ff->toString():"@null"));
                    //LOG("WANING!!!  next<>pred : f->pred!=ff : f=" << (f?f->toString():"@null") << std::flush << "\tf->pred=" << ((f&&f->pred)?f->pred->toString():"@null") << std::flush  << " , ff=" << (ff?ff->toString():"@null"));
                };
        };

        #ifdef DEBUG
        if (g && f!=g->next){
                SYSTEMERROR("f!=g after vectorToString! f=" << f << " and g=" << g->toString());
        };
        #endif
    }
    if(g){
//            a += " -> ";
//            a += (g->next?g->next->toString():"$null");
    }
    return a;
}

void print_vector(RefData *f, RefData *g){
    std::cout << vectorToString(f ,g);
};



/*
template <class T>
TResult RefSymbol<T>::init(Session* s) {
    RefData* aux = s->get_moved_to_next_current_term(this->myid);

#ifdef DEBUG
    if (!aux) { SYSTEMERROR("RefData::init() tring to matching with NULL address!"); };
#endif

    std::cout << "\nthis==aux??? this:"; print_inf(); std::cout << "  aux:"; aux->print_inf(); std::cout << "  aux->pred:" << aux->pred << std::flush; std::cout << "  this->pred:" << this->pred << std::flush;


    bool r = (*this == *aux);
    aux->drop(this->myid);
    if (r) return GO;
    s->get_moved_to_pred_current_term(this->myid);
    return BACK;
};

template <class T>
TResult RefSymbol<T>::back(Session* s) {
    s->get_moved_to_pred_current_term(this->myid);
    return BACK;
};
*/

RefData*  RefNULL::Copy(RefData *d) {
    return new RefNULL(d);
}

TResult RefNULL::init(Session* s, RefData *&){
#ifdef DEBUG
    SYSTEMERROR("RefNULL::init() tring!");
#endif
};
TResult RefNULL::back(Session* s, RefData *&, RefData *&){
#ifdef DEBUG
    SYSTEMERROR("RefNULL::RefNULL() tring!");
#endif
};

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

#include "kernel.h"
#include "session.h"
//#include "dataterms.h"

#ifdef TESTCODE
long co::ocount    = 0;
long co::datacount = 0;
long co::symcount  = 0;
long co::varcount  = 0;
long co::chaincount  = 0;

#endif



RefStructBracket::RefStructBracket(RefData* rp) : RefBracketBase(rp) {
    is_system (false);
};

RefStructBracket::RefStructBracket(RefStructBracket *br, RefData* rp) : RefBracketBase(br, rp) {
    is_system (false);
};
RefData*  RefStructBracket::next_term( ThisId var_id ) {
    if (is_opened) {
        return other->getNext();//
    }
    return next;
};
RefData*  RefStructBracket::pred_term( ThisId var_id ) {
    if (!is_opened) {
        return getOther()->getPred();
    }
    return pred;
};
bool RefStructBracket::operator ==(RefData &rd) {
    RefStructBracket *aux = ref_dynamic_cast<RefStructBracket >(&rd);
    return  aux && (aux->is_opened == is_opened);
};

TResult RefStructBracket::init(RefData*&tpl, Session* s, RefData *&l, RefData *&r) {
    MOVE_TO_NEXT_TERM(r,0,s);

    RefStructBracket* aux = ref_dynamic_cast<RefStructBracket >(r);
    if (!aux || (isOpen()!=aux->isOpen()))  {
        tpl=tpl->getPred();
        return BACK; //   )  (
    }
    if (isOpen()) {  //    (  (
        s->getStackOfDataSkob()->push( aux->getOther() );
        r = r->getNext(); // jump into brackets (to NULL-dot)
        tpl=tpl->getNext()->getNext(); // jump into brackets after NULL-dot
        return GO;
    };
    //    )  )
    if (aux != s->getStackOfDataSkob()->top()) {
        tpl=tpl->getPred();
        return BACK;
    }
    s->matchSessions.back()->StackOfDataSkob_done.push( s->getStackOfDataSkob()->top() );
    s->getStackOfDataSkob()->pop();
    tpl=tpl->getNext();
    return GO;

};

TResult RefStructBracket::back(RefData*&tpl, Session* s, RefData *&l, RefData *&r) { /// TODO: оптимизировать
    if (is_opened) { ///  (
        s->getStackOfDataSkob()->pop(); /// clean?
    } else {
        /// )
        s->getStackOfDataSkob()->push( s->matchSessions.back()->StackOfDataSkob_done.top() );
        s->matchSessions.back()->StackOfDataSkob_done.pop();
    }

    tpl=tpl->getPred();
    //return FORCEBACK; - не надо, т к ситуация мб такая: (e.1 e.all)
    return BACK;
};


void RefStructBracket::forceback(RefData*&tpl, Session *s) {
    if (! this->isOpen()) { // )
        s->matchSessions.back()->StackOfDataSkob_done.pop();
    }
    return;
}





RefExecBracket::RefExecBracket(RefData* rp) : RefBracketBase(rp) {
    is_system (false);
};

RefExecBracket::RefExecBracket(RefExecBracket *br, RefData* rp) : RefBracketBase(br, rp) {
    is_system (false);
};

RefData*  RefExecBracket::next_term( ThisId var_id ) {
    if (is_opened) {
        return other->getNext();//
    }
    return next;
};
RefData*  RefExecBracket::pred_term( ThisId var_id ) {
    if (!is_opened) {
        return other->getPred();
    }
    return pred;
};
bool RefExecBracket::operator ==(RefData &rd) {
    RefExecBracket *aux = ref_dynamic_cast<RefExecBracket >(&rd);
    return  aux && (aux->is_opened == is_opened);
};

TResult RefExecBracket::init(RefData*&tpl, Session* s, RefData *&l, RefData *&r) {
    SYSTEMERROR("RefExecBracket::init! Exec bracket can't to match!");
};

TResult RefExecBracket::back(RefData*&tpl, Session* s, RefData *&l, RefData *&r) {
    SYSTEMERROR("RefExecBracket::back! Exec bracket can't to match!");
};



TResult  RefVariable_s::init(RefData*&tpl, Session *s, RefData *&l, RefData *&r) {
    MOVE_TO_NEXT_TERM(r,0,s);
    if (! ref_dynamic_cast<RefBracketBase >(r) ) {
        l=r;
        SAVE_STATE_AND_VAR( tpl);
        tpl = tpl->getNext();
        return GO;
    }

    tpl = tpl->getPred();
    return BACK;
};

TResult  RefVariable_s::back(RefData*&tpl, Session *s, RefData *&l, RefData *&r) {
    RESTORE_STATE(tpl); /// todo: оптимизация. заменить на DROP_STATE
    tpl = tpl->getPred();
    return BACK;
};




TResult  RefVariable_t::init(RefData*&tpl, Session *s, RefData *&l, RefData *&r) {

    MOVE_TO_NEXT_TERM(r,0,s);
    if (! (ref_dynamic_cast<RefData_DOT >(r) ) ) {
        l=r;
        SAVE_STATE_AND_VAR( tpl);
        tpl = tpl->getNext();
        return GO;
    }

    tpl = tpl->getPred();
    return BACK;
};

TResult  RefVariable_t::back(RefData*&tpl, Session *s, RefData *&l, RefData *&r) {
    RESTORE_STATE(tpl); /// todo: оптимизация. заменить на DROP_STATE
    tpl = tpl->getPred();
    return BACK;
};




TResult  RefVariable_e::init(RefData*&tpl, Session *s, RefData *&l, RefData *&r) {
    SAVE_STATE_AND_VAR(tpl);
    tpl = tpl->getNext();
    return GO;
};

TResult  RefVariable_E::init(RefData*&tpl, Session *s, RefData *&l, RefData *&r) {
    //SYSTEMERROR("");
    RefData *rr = s->getStackOfDataSkob()->top()->getPred();
    if (r->getNext()!=rr) { // getNextSymbol! not nextTerm
        // НЕ пустое значение
        l = r->getNext(); // getNextSymbol! not nextTerm
        r = rr;
    }
    SAVE_STATE_AND_VAR(tpl);
    tpl = tpl->getNext();
    return GO;
};




TResult  RefVariable_END::init(RefData*&tpl, Session *s, RefData *&l, RefData *&r) {
    r = s->getStackOfDataSkob()->top()->getPred();
    tpl=tpl->getNext();
    SAVE_STATE_AND_VAR( tpl);
    return GO;
};

TResult  RefVariable_e::back(RefData*&tpl, Session *s, RefData *&l, RefData *&r) {
    RESTORE_STATE(tpl);

    if (l) {
        if (r==s->getStackOfDataSkob()->top()) {
            tpl=tpl->getPred();
            return BACK;
        };
        MOVE_TO_NEXT_TERM(r, 0/*myid()*/, s);
        r = r->endOfTerm();
    } else {
        MOVE_TO_NEXT_TERM(r, 0/*myid()*/, s);
        l = r->beginOfTerm();
        r = r->endOfTerm();
    }

    #ifdef TESTCODE
    if (! s->getStackOfDataSkob()->size()) SYSTEMERROR("empty stack!");
    #endif
    if (r==s->getStackOfDataSkob()->top()) {
        tpl=tpl->getPred();
        return BACK;
    };
    SAVE_STATE_AND_VAR( tpl); // оптимизировать
    tpl=tpl->getNext();
    return GO;

};

TResult  RefVariable_E::back(RefData*&tpl, Session *s, RefData *&l, RefData *&r) {
    RESTORE_STATE(tpl);
    if (!l) {
        tpl=tpl->getPred();
        return BACK;
    }
    #ifdef TESTCODE
    if (! r)SYSTEMERROR("alarm!");
    #endif
    r = r->beginOfTerm();

    if (l==r) {
        l = 0;
    }
    MOVE_TO_PRED_TERM(r, 0/*myid()*/, s);
    SAVE_STATE_AND_VAR( tpl);          /// todo оптимизировать: не удалять тело переменной в начале при ресторе, а изменять его параметры
    tpl=tpl->getNext();
    return GO;
};

TResult  RefVariable_END::back(RefData*&tpl, Session *s, RefData *&l, RefData *&r) {
    RESTORE_STATE(tpl);
    tpl=tpl->getPred();
    return BACK;
};



bool	RefVariable_e::operator==(RefData &rd) {
    return ref_dynamic_cast<RefVariable_e >(&rd);
};
bool	RefVariable_E::operator==(RefData &rd) {
    return ref_dynamic_cast<RefVariable_E >(&rd);
};
bool	RefVariable_END::operator==(RefData &rd) {
    return ref_dynamic_cast<RefVariable_END >(&rd);
};

unistring vectorToString(RefData *f, RefData *g) {
    unistring a = EmptyUniString;
    #ifdef TESTCODE
    if (g && f==g->getNext()) SYSTEMERROR("bad ends of RefVector (perekrest)");
    #endif

    if (!f) {
        #ifdef TESTCODE
        a+= "$null, ";
        if (g) {
            a+=" after "+g->toString();
        } else {
            a+=" $null";
        }
        #endif
    } else {

        while (f && (!g || f!=g->getNext())) {
            RefData *ff = f;
            a += f->toString();
            f = f->getNext();
            #ifdef TESTCODE
            if (f && f->getPred() != ff) {
                #ifdef DEBUG
                std::cout << a << std::flush;
                std::cout << "\n~f=" << (f?f->toString():"@null")  << std::flush;
                std::cout << "\n~f->pred=" << ((f&&f->getPred())?f->getPred()->toString():"@null") << std::flush;
                #endif
                SYSTEMERROR(" next<>pred : f->pred!=ff : f=" << (f?f->toString():"@null") << std::flush << "\tf->pred=" << ((f&&f->getPred())?f->getPred()->toString():"@null") << std::flush  << " , ff=" << (ff?ff->toString():"@null"));
            };
            #endif
        };

        #ifdef TESTCODE
        if (g && f!=g->getNext()) {
            SYSTEMERROR("f!=g after vectorToString! f=" << f << " and g=" << g->toString());
        };
        #endif
    }
    return a;
}

unistring vectorExplode(RefData *f, RefData *g) {
    #ifdef TESTCODE
    vectorToString(f, g); // проверка ошибок
    #endif

    unistring a = EmptyUniString;
    if (f) {
        while (f && (!g || f!=g->getNext())) {
            a += f->explode();
            f = f->getNext();
        }
    }
    return a;
}

void print_vector(RefData *f, RefData *g) {
    std::cout << vectorToString(f ,g);
};




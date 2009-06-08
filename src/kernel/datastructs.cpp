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

#include "datastructs.h"
#include "kernel.h"
#include "session.h"

#include <sstream>

/**-----------------  границы  --------------------------**/

bool RefData_DOT::operator ==(RefData &rd) {
    RefData_DOT *aux = ref_dynamic_cast<RefData_DOT >(&rd);
    return  aux && (aux->is_opened == is_opened);
};

TResult RefData_DOT::init(RefData*&tpl, Session* s, RefData *&l, RefData *&r) {
    RefData_DOT* aux;
    if (is_opened) { // (
        aux = ref_dynamic_cast<RefData_DOT >(r);

        if (aux && aux->is_opened) {
            tpl=tpl->getNext();
            return GO;
        }
        ; // DOT не двигает указатель на след. аргумент
        tpl=tpl->getPred();
        return ERROR;
    };

    // )
    MOVE_TO_NEXT_TERM(r, 0/*this->myid()*/, s);
    aux = ref_dynamic_cast<RefData_DOT >(r);
    if ( !aux || aux->is_opened) {
        tpl=tpl->getPred();
        return BACK;
    }
    /// ?? tpl=tpl->getNext();
    return SUCCESS;
};


TResult RefData_DOT::back(RefData*&tpl, Session* sess, RefData *&l, RefData *&r) {
    if (is_opened) { /*sess->extention_number = 0;*/
        /// ?? tpl=tpl->getPred();
        return FAIL;
    };
    tpl=tpl->getPred();
    return BACK;
};


unistring  RefData_DOT::toString() {
    #ifndef DEBUG
    return "";
    #endif
    std::ostringstream s;
    s << (is_opened?" [":" ]")
    /*  << "." << std::hex << (unsigned short)this << ' '; //<< ":other=" << (long)this->other << " ";// */
//        s << "." << (long)this << ' ';
    ;
    return s.str();
};
RefData* RefData_DOT::next_term( ThisId var_id, Session *s ) {
    return next;
};
RefData* RefData_DOT::pred_term( ThisId var_id, Session *s ) {
    return pred;
};



/**------------------- группа -----------------**/


TResult  RefGroupBracket::init(RefData*&tpl, Session *s, RefData *&l, RefData *&r) {
    if (isOpen()) { ///      {
        // сохранить левую границу для }
        SAVE_STATE_AND_VAR(this);
    } else {        ///      }.name
        TVarBody *vb = s->getVarBody(name); /// сделать эффективнее чем поиск по имени

int x=0;
        if (vb->first) { // повторное сопоставление закрытой групповой скобки
            vb->second = r;
            x=1;
        } else {
            x=2;
            // первое сопоставление закрытой групповой скобки
            if (vb->second != r) { // взор на НЕ пустое выражение
                x = 3;
                vb->first  = vb->second->getNext();
                vb->second = r;
            }
        }
        LOG( "\nsave(" << name << ") : " << x << " "; print_vector(vb->first, vb->second); std::cout << "\n" );
    }

    tpl=tpl->getNext();
    return GO;
};

TResult  RefGroupBracket::back(RefData*&tpl, Session *s, RefData *&l, RefData *&r) {
    if (isOpen()) {
        RESTORE_STATE(this);  // ?
    }
    tpl=tpl->getPred();
    return BACK;
};


/**-------------------  варианты  ---------------------**/

//-----------  o  -----------
ref_variant_dot::ref_variant_dot( RefData* rp) : RefData(rp) {
    is_system (false);
};

TResult	   ref_variant_dot::init(RefData*&tpl, Session *s, RefData *&l, RefData *&r) {
    #ifdef TESTCODE
    TVarBody* vb = dynamic_cast<TVarBody *>( s->matchSessions.back()->StackOfSopost.top() );
    if ( (!vb) || (! dynamic_cast<RefGroupBracket *>(vb->owner)) )
        SYSTEMERROR("net ozhifaemoj skobki na vershine steka sopostavlenij");
    #endif
    // восстанавливаем начало зрения
    r = ((TVarBody *)( s->matchSessions.back()->StackOfSopost.top()) )->second;
    // идем дальше
    tpl=tpl->getNext();
    return GO;
};

TResult	   ref_variant_dot::back(RefData*&tpl, Session *s, RefData *&l, RefData *&r) {
    tpl=nextvert->getNext();
    return GO;
};

bool	   ref_variant_dot::operator==(RefData&rd) {
    return false;
};

//----------  |  ------------
ref_variant_vert::ref_variant_vert( RefData* rp) : RefData(rp) {
    is_system (false);
};
TResult	  ref_variant_vert::init(RefData*&tpl, Session *s, RefData *&l, RefData *&r)	{
    // сохраняем удачный вариант для отката
    s->matchSessions.back()->StackOfVariants.push(this);
    // прыгаем на конец варианта
    tpl = vopr->getNext();
    return GO;
};
TResult	  ref_variant_vert::back(RefData*&tpl, Session *s, RefData *&l, RefData *&r)	{
    SYSTEMERROR("unecpected");
};



void      ref_variant_vert::forceback (RefData*&tpl, Session *s)	{
    SYSTEMERROR("not released");
    s->matchSessions.back()->StackOfVariants.pop();
};
bool	  ref_variant_vert::operator==(RefData&rd) {
    return false;
};



//----------  ?  ------------
ref_variant_vopr::ref_variant_vopr( RefData* rp) : RefData(rp) {
    is_system (false);
};
TResult		ref_variant_vopr::init(RefData*&tpl, Session *, RefData *&, RefData *&) {
    // вариант не сопоставим с аргументом
    tpl=begbr;
    return BACK;
};
TResult     ref_variant_vopr::back(RefData*&tpl, Session* s, RefData *&l, RefData *&r) {
    ref_variant_vert *rvv = s->matchSessions.back()->StackOfVariants.top();
    s->matchSessions.back()->StackOfVariants.pop();
    tpl=rvv->getPred();
    return BACK;
}
; //

bool ref_variant_vopr::operator==(RefData&rd) {
    return false;
};
void ref_variant_vopr::forceback(RefData*&tpl, Session* s) {
    //s->matchSessions.back()->StackOfVariants.pop();
};






//----------  [...]  ------------
TResult  ref_repeater::init(RefData*&tpl, Session *s, RefData *&l, RefData *&r) {
    if (isOpen()) { ///  [
        if (! getMin()) { // [0..x]
            tpl=other->getNext();
            s->matchSessions.back()->StackOfRepeaterDoned.push(0);
        } else {
            s->matchSessions.back()->StackOfRepeater.push(0);
            tpl=tpl->getNext();
        }
        return GO;
    }
    ///  ]
    infint currentStep = s->matchSessions.back()->StackOfRepeater.top();
    s->matchSessions.back()->StackOfRepeater.pop();
    ++currentStep;

    if (currentStep < getMin()) {
        s->matchSessions.back()->StackOfRepeater.push(currentStep);  ///todo: рптимизировать ++(...top()) ?
        tpl=other->getNext(); // остаемся внутри варианта
        return GO;
    }
    tpl=tpl->getNext(); // уходим из варианта
    s->matchSessions.back()->StackOfRepeaterDoned.push(currentStep);
    return GO;

};

TResult  ref_repeater::back(RefData*&tpl, Session *s, RefData *&l, RefData *&r) {
    if (isOpen()) {  ///   [
        infint currentStep = s->matchSessions.back()->StackOfRepeater.top();
        if (currentStep) {
            s->matchSessions.back()->StackOfRepeater.push(--currentStep);
            tpl=other->getPred(); // внутри
            return BACK;
        }
        s->matchSessions.back()->StackOfRepeater.pop();
        tpl=tpl->getPred(); // выходим из варианта
        return BACK;
    }
    ///   ]
    infint currentStep = s->matchSessions.back()->StackOfRepeaterDoned.top();
    s->matchSessions.back()->StackOfRepeaterDoned.pop();

    if (currentStep < getMax()) {
        s->matchSessions.back()->StackOfRepeater.push( currentStep );
        tpl=other->getNext();
        return GO;
    }
    --currentStep;
    s->matchSessions.back()->StackOfRepeater.push( currentStep );
    tpl=tpl->getPred();
    return BACK;
};

/*RefData*  ref_repeater::next_template (ThisId id, Session*s) {
    switch (s->message4nextpred) {
    case mNEXT:
        return next;
    case mPRED:
        return pred;
    case mOTHER_next:
        return other->getNext();
    case mOTHER_pred:
        return other->getPred();
    default:
        ;
    }
    SYSTEMERROR("unexpected message");
};


RefData*  ref_repeater::pred_template (ThisId id, Session*s) {
    switch (s->message4nextpred) {
    case mNEXT:
        return next;
    case mPRED:
        return pred;
    case mOTHER_next:
        return other->getNext();
    case mOTHER_pred:
        return other->getPred();
    default:
        ;
    }
    SYSTEMERROR("unexpected message");
};
*/

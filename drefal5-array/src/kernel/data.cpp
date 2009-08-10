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

#include "data.h"
//#include "datastructs.h"
//#include "kernel.h"
#include "session.h"

#include <stdlib.h>
#include <iostream>
#include <sstream>


//TResult RefData::init(RefData*&tpl, Session* s, RefData *&, RefData *&) {
//    SYSTEMERROR("unexpected called for " << toString());
//    return ERROR;
//}
//
//TResult RefData::back(RefData*&tpl,Session* s, RefData *&, RefData *&) {
//    SYSTEMERROR("unexpected called for " << toString());
//    return ERROR;
//}





//RefBracketBase::RefBracketBase( RefData *rp) : RefData(rp){ // открывающая
//    other = 0;
//    is_opened = true;
//};
//
//
//
//
//RefBracketBase::RefBracketBase( RefBracketBase *dr, RefData *rp) : RefData(rp){ // закрывающая
//        other = dr;
//        is_opened = false;
//        dr->other = this;
////        if (name == EmptyUniString) {  }
//};




//bool   RefBracketBase::operator==(RefData &rd){ return false; };

//TResult RefBracketBase::init(RefData*&tpl,Session* s, RefData *&){ SYSTEMERROR(" RefBracketBase::init zagluska!"); };
//TResult RefBracketBase::back(RefData*&tpl,Session* s, RefData *&, RefData *&){ SYSTEMERROR(" RefBracketBase::back zagluska!"); };




RefChain::RefChain() {
	first = (RefData**)malloc(sizeof(RefData*));
	memcpy(first, &nullDataPoint, sizeof(RefData*));
    after = 0;
    leng = 0;
};

RefChain::RefChain(RefData** a11, RefData** a12, RefData** a21, RefData** a22, RefData** a31, RefData** a32) {
    leng = 0;
    if (a11) leng += a12-a11;
    if (a21) leng += a22-a21;
    if (a31) leng += a32-a31;

    if (!leng) {
		first = (RefData**)malloc(sizeof(RefData*));
		first[0] = nullDataPoint;
		after = 0;
		leng = 0;
        return;
    }

    first = (RefData**)malloc( sizeof(RefData*) * leng + sizeof(RefData*));
    memcpy(first, a11, sizeof(RefData*) * (a12-a11));
    memcpy(first[(a12-a11)], a21, sizeof(RefData*) * (a22-a21));
    memcpy(first[(a12-a11)+(a22-a21)], a31, sizeof(RefData*) * (a32-a31));
	//memset(first+leng, 0, sizeof(RefData*));
	memcpy(first+leng, &nullDataPoint, sizeof(RefData*));

    return;

};



RefChain& RefChain::operator+=(RefBracketBase *br) {
	*this += (RefData*)br;
	br->chain = this;
	if (br->opened_ind == SIZE_MAX){ // [
		#ifdef TESTCODE
		if (br->closed_ind != SIZE_MAX) SYSTEMERROR("chain + bracket alarm");
		if (!ref_dynamic_cast<RefBracketBase>(* this->get_last())) SYSTEMERROR("alarm");
		#endif
		br->opened_ind = (get_last()-first);
	} else { // ]
		#ifdef TESTCODE
		if (!ref_dynamic_cast<RefBracketBase>(* this->get_last())) SYSTEMERROR("alarm");
		#endif
		br->closed_ind = (this->get_last()-first);
	}
	return *this;
};

RefChain& RefChain::operator+=(RefData *ch) {
    if (! this->first && !this->after) {
        first = (RefData**)malloc( sizeof(RefData*) +  sizeof(RefData*)); // + для  0x0
        if (!first) std::cerr << "NO MEMORY";
        memcpy(first, &ch, sizeof(RefData*));
        //memset(first+1, 0, sizeof(RefData*));  // 0x0
		memcpy(first+1, &nullDataPoint, sizeof(RefData*));
        leng = 1;
        return *this;
    }

    first   =  (RefData**) realloc(first, (++leng)*sizeof(RefData*) +  sizeof(RefData*));
    if (! this->first) {
        std::cerr << "\nNO MEMORY !";
    }
    memcpy(first+leng-1, &ch, sizeof(RefData*));
    //memset(first+leng, 0, sizeof(RefData*));  // 0x0
	memcpy(first+leng, &nullDataPoint, sizeof(RefData*));

    return *this;
};


RefChain& RefChain::operator+=(RefChain &ch) {
    return (*this += &ch);
};


RefChain& RefChain::operator+=(RefChain *ch) {


    if (!this->first) {
        #ifdef DEBUG
        if (this->after) {
            LOG("Poterja posledovatelnosti chain (after != NULL) but (first = malloc)");
        }
        #endif
        first = (RefData**)malloc( sizeof(RefData*) * ch->leng  + sizeof(RefData*));
        if (!first) std::cerr << "NO MEMORY";
        memcpy(first, &ch->first, sizeof(RefData*) * ch->leng);
        leng = ch->leng;
        //memset(first+leng+1, 0, sizeof(RefData*));
		memcpy(first+leng+1, &nullDataPoint, sizeof(RefData*));
        return *this;
    }

    first   =  (RefData**) realloc(first, (this->leng + ch->leng)*sizeof(RefData*) + sizeof(RefData*));
    if (! this->first) {
        RUNTIMEERROR("ABORT", "\nNO MEMORY!");
        return *this;
    }
    memcpy(&( this->first[leng]), ch->first, (ch->leng)*sizeof(RefData*));
    this->leng += ch->leng;
    //memset(first+leng+1, 0, sizeof(RefData*) );
	memcpy(first+leng+1, &nullDataPoint, sizeof(RefData*));

    return *this;
};


unistring RefChain::toString() {
    unistring result = "";
    for (size_t i=0; i<leng; i++) {
        result += first[i]->toString();
    }
    return result;
};

unistring RefChain::explode()     {
    unistring result = "";
    for (size_t i=0; i<leng; i++) {
        result += first[i]->explode();
    }
    return result;
};




RefChain* RefChain::Copy(Session *s) {
    if (!first) return new RefChain();

    SYSTEMERROR("zaglushka");




};



////////////////////////////////////////////
//


bool RefNULL::operator==(RefData&) {
    return false;
};

TResult RefNULL::init(RefData**&tpl, Session* s, RefData **&l, RefData **&r) {
    SYSTEMERROR("RefNULL::init() tring!");
};
TResult RefNULL::back(RefData**&tpl, Session* s, RefData **&, RefData **&) {
    LOG("vremenno RefNULL::back - potom produmat kak ubrat Ref_NULL iz skobok voobshe!");
    --tpl;
    return BACK;
    SYSTEMERROR("RefNULL::RefNULL() tring!");
};






unistring RefLinkToVariable::toString() {
    std::ostringstream s;
    s << "[LNK::"<< lnkData->toString() <<"]" << (long)this ;
    return s.str();
};

bool RefLinkToVariable::operator==(RefData&) {
    return false;
};


TResult RefLinkToVariable::init(RefData**&tpl, Session* s, RefData **&l, RefData **&r) {

    TVarBody *pd  =  s->getBodyByLink(this->lnkData);

    if ( !pd ) {
        SYSTEMERROR("INTERNAL ERROR: link to not exists variable! link = " << this->toString());
        return ERROR;
    };

    RefData
    **ldata = pd->first,
              **rdata = pd->second;

    if (!ldata ) {
        MOVE_TO_next_template(tpl);
        return GO; // ссылка на пустой отрезок - верна
    }

    MOVE_TO_next_term(r);
    if (*r==*ldata) { // сопоставление с собой
        r = rdata;
        MOVE_TO_next_template(tpl);
        return GO;
    }

//    RefData *lend = rdata;
//    MOVE_TO_next_term(lend); // граница сравнения
//
//    MOVE_TO_pred_term(r); /// todo: оптимизировать
//    while ((ldata!=lend) ) { // проверка на конец сравниваемого
//        MOVE_TO_next_term(r);
//        if ( !(*r == *ldata)) {
//            tpl=tpl->getPred();
//            return BACK;
//        }
//
//        MOVE_TO_next_term(ldata);
//    };
//    tpl = tpl->getNext();
//    return GO;

    while ((**r == **ldata) && (ldata != rdata)  ) {
        MOVE_TO_next_term(r);
        MOVE_TO_next_term(ldata);
    }

    if (**r == **ldata) { // TODO: оптимизировать. убрать вызов ==
        MOVE_TO_next_template(tpl);
        return GO;
    }
    MOVE_TO_pred_template(tpl);
    return BACK;
};


TResult RefLinkToVariable::back(RefData**&tpl, Session* s, RefData **&l, RefData **&r) {
    MOVE_TO_pred_template(tpl);
    return BACK;
};

RefVariable::RefVariable(unistring name) : RefVariableBase() {
    setName(name);
};




TResult RefData_DOT::init(RefData **&tpl, Session *s, RefData **&l, RefData **&r){
    RefData_DOT* aux;
    if (isOpen(tpl)) { // (
		if (r == s->current_view_l-1){
			MOVE_TO_next_template(tpl);
            return GO;
        }
        ; // DOT не двигает указатель на след. аргумент
        MOVE_TO_pred_template(tpl);
        return ERROR;
    };

    // )
    MOVE_TO_next_term(r);
    
	if ( r != s->current_view_r+1) {
        MOVE_TO_pred_template(tpl);
        return BACK;
    };
    return SUCCESS;
};

TResult RefData_DOT::back(RefData **&tpl, Session *s, RefData **&l, RefData **&r){
	if (isOpen(tpl)) {
        return FAIL;
    };
    MOVE_TO_pred_template(tpl);
    return BACK;
};




RefData** beginOfTerm(RefData** r) {
	if (! *r) return r;
    RefBracketBase *br;
	if ( !(br = ref_dynamic_cast<RefBracketBase>(*r)) || (br->isOpen(r))) {
        return r;
    }
    br=*(br->getOther(r));
    while (*r != br) {
        --r;
        #ifdef TESTCODE
        if (!r) SYSTEMERROR("alarm");
        #endif
    }
    return r;
};

RefData** endOfTerm(RefData** r) {
	if (! *r) return r;
    RefBracketBase *br;
	if ( !(br = ref_dynamic_cast<RefBracketBase>(*r)) || !(br->isOpen(r))) {
        return r;
    }
    br=*(br->getOther(r));
    while (*r != br) {
        ++r;
        #ifdef TESTCODE
        if (!r) SYSTEMERROR("alarm");
        #endif
    }
    return r;
};


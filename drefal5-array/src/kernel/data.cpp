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
#include "symbols.h"
#include "session.h"

#include <stdlib.h>
#include <iostream>
#include <sstream>



RefChain::RefChain() {
	first = (RefData**)malloc(sizeof(RefData*) * 2);
	first[0] = nullDataPoint;
	first[1] = nullDataPoint;
    leng = 0;
};

RefChain::RefChain(unistring text){
	leng = text.length();
	first = (RefData**)malloc(sizeof(RefData*) * (leng+2));
	first[0] = nullDataPoint;
	RefData **iter = first+1;

	for(size_t i=0; i<leng; i++){
		*iter = new RefAlpha(text[i]);
		++iter;
	};

	first[leng+1] = nullDataPoint;
};

RefChain::RefChain(RefData* d) {
	first = (RefData**)malloc(sizeof(RefData*) * 3);
	first[0] = nullDataPoint;
	first[1] = d;
	first[2] = nullDataPoint;
    leng = 1;
};

RefChain::RefChain(size_t system_size) {
	LOG("chain() systemsize not realised!");
	RefChain();
};


RefChain::RefChain(RefData** a11, RefData** a12, RefData** a21, RefData** a22, RefData** a31, RefData** a32) {
	SYSTEMERROR("ne sdelano kopirovanie skobok");
    leng = 0;
    if (a11) leng += a12-a11;
    if (a21) leng += a22-a21;
    if (a31) leng += a32-a31;

    if (!leng) {
		first = (RefData**)malloc(sizeof(RefData*) * 2);
		first[0] = nullDataPoint;
		first[1] = nullDataPoint;
		leng = 0;
        return;
    }

    first = (RefData**)malloc( sizeof(RefData*)*(leng+2) );

	memset(first, 0xff, leng+2);

	first[0] = nullDataPoint;
    memcpy(first+1, a11, sizeof(RefData*) * (a12-a11));
    memcpy(first[1+(a12-a11)], a21, sizeof(RefData*) * (a22-a21));
    memcpy(first[1+(a12-a11)+(a22-a21)], a31, sizeof(RefData*) * (a32-a31));
	//memset(first+leng, 0, sizeof(RefData*));
	//memcpy(first+leng+1, &nullDataPoint, sizeof(RefData*));
	first[leng+1] = nullDataPoint;

    return;

};


ChainSubstitution& ChainSubstitution::operator+=(RefLinkToVariable *vr) {
	*this += (RefData*)vr;
	#ifdef TESTCODE
	if (! ref_dynamic_cast<RefLinkToVariable>(*get_last())) SYSTEMERROR("alarm");
	#endif
	this->varsAndBrackets.put(leng);
	return *this;
};


RefChain& RefChain::operator+=(RefBracketBase *br) {
	*this += (RefData*)br;
	br->chain = this;
	if (br->opened_ind == SIZE_MAX){		// [
		#ifdef TESTCODE
		if (!ref_dynamic_cast<RefBracketBase>(* this->get_last())) SYSTEMERROR("alarm");
		#endif
		br->opened_ind = (get_last()-get_first());
		#ifdef TESTCODE
		if (! ref_dynamic_cast<RefBracketBase>(*get_last())) SYSTEMERROR("alarm");
		#endif

		*this += refNullGlobal; // add null dot after open bracket
	} else {								// ]
		#ifdef TESTCODE
		if (br->closed_ind != SIZE_MAX) SYSTEMERROR("chain + bracket alarm");
		if (!ref_dynamic_cast<RefBracketBase>(* get_last() )) SYSTEMERROR("alarm");
		#endif
		br->closed_ind = (get_last()-get_first());
	}
	return *this;
};

ChainSubstitution& ChainSubstitution::operator+=(RefBracketBase *br) {
	RefChain::operator +=(br);
	//if (br->closed_ind == SIZE_MAX) => ( , else )
	if (ref_dynamic_cast<RefStructBracket>(br)) {
		varsAndBrackets.put((br->closed_ind==SIZE_MAX) ? leng-1 : leng ); // если ( то был создан nullDot
	}

	return *this;
};


ChainSubstitution& ChainSubstitution::operator+=(RefData  *br){
	return (ChainSubstitution&)RefChain::operator+=(br);
};


RefChain& RefChain::operator+=(RefData *ch) {
	#ifdef TESTCODE
	if (!first || !get_first()) SYSTEMERROR("null first of chain");
	#endif

	first   =  (RefData**) realloc(first, (++leng + 2)*sizeof(RefData*) );
    if (! first) RUNTIMEERROR("membuffer", "memory limit");
    memcpy(first+leng, &ch, sizeof(RefData*));
	memcpy(first+leng+1, &nullDataPoint, sizeof(RefData*));

    return *this;
};


RefChain& RefChain::operator+=(RefChain &ch) {
    return (*this += &ch);
};


RefChain& RefChain::operator+=(RefChain *ch) {
	SYSTEMERROR("kopirovanie sjobok ne realisovano!");
	#ifdef TESTCODE
	if (!first || !get_first()) SYSTEMERROR("null first of chain");
	if (!ch->first || !ch->get_first()) SYSTEMERROR("null first of chain");
	#endif

    first   =  (RefData**) realloc(first, (this->leng + ch->leng + 2)*sizeof(RefData*) );
    if (! first) RUNTIMEERROR("membuffer", "memory limit");
    memcpy(&(first[leng+1]), ch->first+1, (ch->leng+1)*sizeof(RefData*)); // вместе с 0x00
    leng += ch->leng;
	//memcpy(first+leng+1, &nullDataPoint, sizeof(RefData*));
    return *this;
};


unistring RefChain::toString() {
    unistring result = "";
    for (size_t i=0; i<=leng+1; i++) {
		result += (first[i] ? first[i]->toString() : "[null]");
    }
    return result;
};

unistring RefChain::explode()     {
    unistring result = "";
    for (size_t i=1; i<=leng; i++) {
        result += first[i]->explode();
    }
    return result;
};




RefChain* RefChain::Copy(Session *s) {
    if (!first) return new RefChain();

    SYSTEMERROR("zaglushka");




};








unistring RefLinkToVariable::explode() {
    std::ostringstream s;
	s << "@."<< this->lnk->getName() <<" ";
    return s.str();
};


TResult RefLinkToVariable::init(RefData**&tpl, Session* s, RefData **&l, RefData **&r) {
	RefData **ldata, **rdata;
	MatchState* matchState;
	if ( ! s->getBodyByLink(this->lnk, ldata, rdata, matchState) ) {
        SYSTEMERROR("INTERNAL ERROR: link to not exists variable! link = " << this->toString());
        return ERROR;
    };

    if (!ldata ) {
        MOVE_TO_next_template(tpl);
        return GO; // ссылка на пустой отрезок - верна
    }

    MOVE_TO_next_term(r);

	while(ldata<=rdata){
		if (*ldata != *r && !(**ldata == **r)) {
		    MOVE_TO_pred_template(tpl);
			return BACK;
		};
		RefBracketBase* br1 = ref_dynamic_cast<RefBracketBase>(*ldata);
		if (br1){
			if (br1->isOpen(ldata) != ((RefBracketBase*) *r)->isOpen(r)) {
				MOVE_TO_pred_template(tpl);
				return BACK;
			};
		}
		MOVE_TO_next_symbol(ldata);
		MOVE_TO_next_symbol(r);
	}

    MOVE_TO_next_template(tpl);
	//r = rdata;
	return GO;
};



TResult RefLinkToVariable::back(RefData**&tpl, Session* s, RefData **&l, RefData **&r) {
    MOVE_TO_pred_template(tpl);
    return BACK;
};

RefVariable::RefVariable(unistring name) : RefVariableBase() {
    setName(name);
};



TResult RefData_DOT::init(RefData **&tpl, Session *s, RefData **&l, RefData **&r){
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




TResult RefStructBracket::init(RefData **&tpl, Session *s, RefData **&l, RefData **&r){
    MOVE_TO_next_term(r);

    RefStructBracket* aux = ref_dynamic_cast<RefStructBracket >(*r);
    if (!aux || (isOpen(tpl)!=aux->isOpen(r)))  {
		MOVE_TO_pred_template(tpl);
        return BACK; //   )  (
    };
    if (isOpen(tpl)) {  //    (  (
		s->setTopDataSkob( (RefData**) aux->getOther(r));
        ++r; // jump into brackets (to NULL-dot)
		MOVE_TO_next_template(++tpl); // jump into brackets after NULL-dot
        return GO;
    };
    //    )  )
	if (aux != *(s->getTopDataSkob())) {
		MOVE_TO_pred_template(tpl);
        return BACK;
    };

	s->stackOfDataSkob_done.put( s->stackOfDataSkob.top_pop() );
	MOVE_TO_next_template(tpl);
    return GO;
};

TResult RefStructBracket::back(RefData **&tpl, Session *s, RefData **&l, RefData **&r){
	if (isOpen(tpl)) { ///  (
		s->stackOfDataSkob.top_pop(); /// clean?
    } else {
        /// )
		s->setTopDataSkob( s->stackOfDataSkob_done.top_pop() );
    }

	MOVE_TO_pred_template(tpl);
    //return FORCEBACK; - не надо, т к ситуация мб такая: (e.1 e.all)
    return BACK;
};




RefData** beginOfTerm(RefData** r) {
	if (!r || !*r) return r;
    RefBracketBase *br;
	if ( !(br = ref_dynamic_cast<RefBracketBase>(*r)) || (br->isOpen(r))) {
        return r;
    }
    return (RefData**)br->getOther(r);
};

RefData** endOfTerm(RefData** r) {
	if (!r || !*r) return r;
    RefBracketBase *br;
	if ( !(br = ref_dynamic_cast<RefBracketBase>(*r)) || !(br->isOpen(r))) {
        return r;
    }
    return (RefData**)br->getOther(r);
};


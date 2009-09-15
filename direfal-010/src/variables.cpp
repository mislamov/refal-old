// DiRefal - sentential program language
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

#include "symbols.h"
#include "variables.h"
#include "session.h"

TResult  RefVariable_e::init(RefData**&tpl, Session *s, RefData **&l, RefData **&r) {
	RefData **tmp = tpl;
	IRefSymbol *symb = 0;
	s->MOVE_TO_next_template(tmp);

	
	if (tmp && (symb=ref_dynamic_cast<IRefSymbol>(*tmp))){ // если следующий элемент шаблона - символ
#ifdef DEBUG
		std::cout << "e-symbol optimization\n";
#endif
		l = r;
		do {
			s->MOVE_TO_next_term(r);
		} while( r && !(*symb == **r) );
		if (!r){
			s->MOVE_TO_pred_template(tpl);
			return BACK;
		}
		// соотв-ий символ найден
		l = (l==r-1)?0:l+1;
		--r;
		s->SAVE_VAR_STATE(tpl, l, r);
		++r;
		s->MOVE_TO_next_template(tpl);
		s->MOVE_TO_next_template(tpl);
		return GO;
	}

    s->SAVE_VAR_STATE(tpl, l, r);
    s->MOVE_TO_next_template(tpl);
    return GO;
};

  


TResult  RefVariable_e::back(RefData**&tpl, Session *s, RefData **&l, RefData **&r) {
	s->RESTORE_VAR_STATE(tpl, l, r);

    s->MOVE_TO_next_term(r);
	if (!r){ // достигнули конца цепочки
        s->MOVE_TO_pred_template(tpl);
        return BACK;
	}
        
	l = (l?l:r); 

	s->SAVE_VAR_STATE(tpl, l, r);
    s->MOVE_TO_next_template(tpl);
    return GO;
};

bool    RefVariable_e::operator==(RefData &rd) {    return ref_dynamic_cast<RefVariable_e >(&rd)?true:false; };




TResult  RefVariable_E::init( RefData**&tpl, Session *s, RefData **&l, RefData **&r ) {
	RefData **rr = s->current_view_r();
	s->MOVE_TO_pred_term(rr);

	RefData **rnext = r;
	s->MOVE_TO_next_term(rnext);

    if (rnext!=rr) { // getNextSymbol! not nextTerm
        // НЕ пустое значение
        l = rnext; // getNextSymbol! not nextTerm
        r = rr;
    }
    s->SAVE_VAR_STATE(tpl, l, r);
	s->MOVE_TO_next_template(tpl);
    return GO;
};

TResult  RefVariable_E::back(RefData**&tpl, Session *s, RefData **&l, RefData **&r) {
    s->RESTORE_VAR_STATE(tpl, l, r);
    if (!l) {
		s->MOVE_TO_pred_template(tpl);
        return BACK;
    }
    #ifdef TESTCODE
    if (! r)SYSTEMERROR("alarm!");
    #endif

    if (l==r) {
        l = 0;
    }
    s->MOVE_TO_pred_term(r);
    s->SAVE_VAR_STATE( tpl, l, r);          /// todo оптимизировать: не удалять тело переменной в начале при ресторе, а изменять его параметры
	s->MOVE_TO_next_template(tpl);
    return GO;
};

bool    RefVariable_E::operator==(RefData &rd) {    return ref_dynamic_cast<RefVariable_E >(&rd)?true:false; };



TResult  RefVariable_s::init(RefData**&tpl, Session *s, RefData **&l, RefData **&r) {
    s->MOVE_TO_next_term(r);
	if (r && *r && !ref_dynamic_cast<RefDataBracket>(*r) ) {
        l=r;
        s->SAVE_VAR_STATE( tpl, l, r);
        s->MOVE_TO_next_template(tpl);
        return GO;
    }

    s->MOVE_TO_pred_template(tpl);
    return BACK;
};

TResult  RefVariable_s::back(RefData**&tpl, Session *s, RefData **&l, RefData **&r) {
	s->RESTORE_VAR_STATE(tpl, l, r); /// todo: оптимизация. заменить на DROP_STATE
    s->MOVE_TO_pred_template(tpl);
    return BACK;
};
bool    RefVariable_s::operator==(RefData &rd) {    return ref_dynamic_cast<RefVariable_s >(&rd)?true:false; };



TResult  RefVariable_t::init(RefData**&tpl, Session *s, RefData **&l, RefData **&r) {
    s->MOVE_TO_next_term(r);
    if  (r && *r && (void*)r!=(void*)s->current_view_r()) {
        l=r;
        s->SAVE_VAR_STATE( tpl, l, r);
        s->MOVE_TO_next_template(tpl);
        return GO;
    }

    s->MOVE_TO_pred_template(tpl);
    return BACK;
};

TResult  RefVariable_t::back(RefData**&tpl, Session *s, RefData **&l, RefData **&r) {
    s->RESTORE_VAR_STATE(tpl, l, r);
    s->MOVE_TO_pred_template(tpl);
    return BACK;
};
bool    RefVariable_t::operator==(RefData &rd) {    return ref_dynamic_cast<RefVariable_t >(&rd)?true:false; };

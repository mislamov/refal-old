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

#include "symbols.h"
#include "variables.h"
#include "session.h"

TResult  RefVariable_e::init(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own) {
	RefData **tmp = tpl;
	sess->MOVE_TO_next_template(tmp);


	if (tmp && (*tmp)->isRefSymbol()){ // если следующий элемент шаблона - символ
#ifdef DEBUG
		std::cout << "e-symbol optimization\n";
#endif
		l = r;
		do {
			sess->MOVE_TO_next_term(r);
		} while( r && !(**tmp == **r) );
		if (!r){
			sess->MOVE_TO_pred_template(tpl);
			return BACK;
		}
		// соотв-ий символ найден
		l = (l==r-1)?0:l+1;
		--r;
		sess->saveVar((RefVariable*)*tpl, l, r, lr_own);
		++r;
		sess->MOVE_TO_next_template(tpl);
		sess->MOVE_TO_next_template(tpl);
		return GO;
	}

    sess->saveVar((RefVariable*)*tpl, l, r, lr_own);
    sess->MOVE_TO_next_template(tpl);
    return GO;
}




TResult  RefVariable_e::back(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own) {
	sess->restoreVar((RefVariable*)*tpl, l, r, lr_own);

	sess->MOVE_TO_next_term(r);
	if (!r){ // достигнули конца цепочки
		sess->MOVE_TO_pred_template(tpl);
        return BACK;
	}
	l = (l?l:r);


	RefData **tmp = tpl;
	sess->MOVE_TO_next_template(tmp);
	if (tmp && (*tmp)->isRefSymbol()){ // если следующий элемент шаблона - символ
#ifdef DEBUG
		std::cout << "e-symbol optimization\n";
#endif

		do {
			sess->MOVE_TO_next_term(r);
		} while( r && !(**tmp == **r) );
		if (!r){
			sess->MOVE_TO_pred_template(tpl);
			return BACK;
		}

		--r;
		sess->saveVar((RefVariable*)*tpl, l, r, lr_own);
		++r;
		sess->MOVE_TO_next_template(tpl);
		sess->MOVE_TO_next_template(tpl);
		return GO;
	}



	sess->saveVar((RefVariable*)*tpl, l, r, lr_own);
    sess->MOVE_TO_next_template(tpl);
    return GO;
}

bool    RefVariable_e::operator==(RefData &rd) {    return ref_dynamic_cast<RefVariable_e >(&rd)?true:false; }



//todo: оптимизацию как в е!
TResult  RefVariable_E::init(RefData**&tpl, Session *sess, RefData **&l, RefData **&r, RefChain *&lr_own) {
	/*	RefData **rr = sess->current_view_r();
	//s->MOVE_TO_pred_term(rr);

	RefData **rnext = r;
	sess->MOVE_TO_next_term(rnext);

    if (rnext!=rr) { // getNextSymbol! not nextTerm
        // НЕ пустое значение
        l = rnext; // getNextSymbol! not nextTerm
        r = rr;
    }
	*/
	RefData **rnext = r;
	sess->MOVE_TO_next_term(rnext);

	if (rnext){
		l = rnext;
		r = sess->current_view_r();
	}
    sess->saveVar((RefVariable*)*tpl, l, r, lr_own); // todo: может можно везде current_view_lr_own?
	sess->MOVE_TO_next_template(tpl);
    return GO;

}

//todo: оптимизацию как в е!
TResult  RefVariable_E::back(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own) {
	sess->restoreVar((RefVariable*)*tpl, l, r, lr_own);
    if (!l) {
		sess->MOVE_TO_pred_template(tpl);
        return BACK;
    }
    #ifdef TESTCODE
    if (! r)
		SYSTEMERRORs(sess, "alarm!");
    #endif

    if (l==r) {
        l = 0;
    }
	//std::cout << "\n\ns->saveVar((RefVariable*)*tpl, l, r) = " << "s->saveVar(" << tpl << ", " << (*l)->debug() << ", " << (*r)->debug() << ")\n\n";

    sess->MOVE_TO_pred_term(r);
    sess->saveVar((RefVariable*)*tpl, l, r, lr_own);          /// todo оптимизировать: не удалять тело переменной в начале при ресторе, а изменять его параметры
	sess->MOVE_TO_next_template(tpl);

	#ifdef TESTCODE
	RefData **i = 0, **endi = 0;
	VarMap* vm = 0;
	ref_assert( sess->findVar(this, i, endi, lr_own, vm) || i!=l || endi!=r );
	#endif


	return GO;
}

bool    RefVariable_E::operator==(RefData &rd) {    return ref_dynamic_cast<RefVariable_E >(&rd)?true:false; }

TResult  RefVariable_END::back(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own) {
	sess->restoreVar(this, l, r, lr_own);
    sess->MOVE_TO_pred_template(tpl);
    return BACK;
}

TResult  RefVariable_s::init(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own) {
    sess->MOVE_TO_next_term(r);
	if (r && *r && !(*r)->isDataBracket() ) {
        l=r;
        sess->saveVar((RefVariable*)*tpl, l, r, lr_own);
        sess->MOVE_TO_next_template(tpl);
        return GO;
    }

    sess->MOVE_TO_pred_template(tpl);
    return BACK;
}

TResult  RefVariable_s::back(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own) {
	sess->restoreVar((RefVariable*)*tpl, l, r, lr_own); /// todo: оптимизация. заменить на DROP_STATE
    sess->MOVE_TO_pred_template(tpl);
    return BACK;
}
bool    RefVariable_s::operator==(RefData &rd) {    return ref_dynamic_cast<RefVariable_s >(&rd)?true:false; }



TResult  RefVariable_t::init(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own) {
    sess->MOVE_TO_next_term(r);
    if  (r) {
        l=r;
        sess->saveVar( (RefVariable*)*tpl, l, r, lr_own);
        sess->MOVE_TO_next_template(tpl);
        return GO;
    }

    sess->MOVE_TO_pred_template(tpl);
    return BACK;
}

TResult  RefVariable_t::back(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own) {
    sess->restoreVar((RefVariable*)*tpl, l, r, lr_own);
    sess->MOVE_TO_pred_template(tpl);
    return BACK;
}
bool    RefVariable_t::operator==(RefData &rd) {    return ref_dynamic_cast<RefVariable_t >(&rd)?true:false; }

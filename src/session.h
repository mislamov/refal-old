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

#ifndef SESSION_H_INCLUDED
#define SESSION_H_INCLUDED

#include <sstream>
#include <stack>

#include "data.h"
#include "poolTuples.h"

class MatchState;

class VarMap : public PooledTuple4<RefVariable*, RefData** , RefData** , MatchState*>{
public:
	VarMap(void *own = 0) {        pool[0].i1 = (RefVariable*)own;    };

    // ищет по имени переменной ее облать видимости
    bool findByName(unistring name, RefData** &l, RefData** &r);

	// ищет по ссылке на переменную ее облать видимости
	bool findByLink(RefVariable* var, RefData** &l, RefData** &r, MatchState *&matchState);

	unistring debug();
};


// блок сопоставлений (откатываемый)
class MatchState {
    VarMap varmap; // карта сопоставления
    RefData** view_l;   // аргумент сопоставления всего образца
    RefData** view_r;
public:
	RefChain *tpl;

	MatchState(RefData** ll, RefData** rr, RefChain *tl) {    view_l=ll;      view_r=rr;	tpl = tl;    };
    // сохраняет состояние переменной
    void saveVar(Session *s, RefVariable *varOrData, RefData **&l, RefData **&r);
    void restoreVar(Session *s, RefVariable *varOrData, MatchState* &matchState, RefData **&l, RefData **&r);
	bool findVar(RefVariable *var, RefData **&l, RefData **&r, MatchState* &matchState);
	unistring debug();
};


// среда для вычисления пользовательской функции функции
class Session {
    TResult  result_sost;

    RefData** current_view_l;
    RefData** current_view_r;

    std::stack<MatchState*>  matchStates; // цепочка подсопоставлений

public:
	// сопоставление образца tmplate с аргументом l..r
    bool  matching(RefObject *initer, RefChain *tmplate, RefChain *arg, bool isdemaching, bool isRevers);

	// готовит подстановку: заменяет переменные значениями. Получаем ОВ с угловыми скобками
    RefChain*  substituteExpression(RefChainSubstitution *);

	void SAVE_VAR_STATE   (RefData** activeTemplate, RefData** &l, RefData** &r); // сохраняет состояние переменной
	void RESTORE_VAR_STATE(RefData** activeTemplate, RefData** &l, RefData** &r); // восстанавливает состояние переменной
	RefData** getTopBoard(){ return current_view_r+1; };

	MatchState* saveCurrentState(RefData** ll, RefData** rr, RefChain *tpl); // сохраняет и возвращает ссылку на состояние сопоставления
	unistring debug();

	void MOVE_TO_next_term(RefData** &p);
	void MOVE_TO_pred_term(RefData** &p);

};


inline void MatchState::saveVar(Session *s, RefVariable *varOrData, RefData **&l, RefData **&r) {
    varmap.put(varOrData, l, r, 0);
};

inline void MatchState::restoreVar(Session *s, RefVariable *varOrData, MatchState* &matchState, RefData **&l, RefData **&r) {
    varmap.top_pop(varOrData, l, r, matchState);
};

inline bool MatchState::findVar(RefVariable *var, RefData **&l, RefData **&r, MatchState* &matchState) {
	return varmap.findByLink(var, l, r, matchState);
};







#endif

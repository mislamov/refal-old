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

#include "variables.h"
#include "session.h"

TResult  RefVariable_e::init(RefData**&tpl, Session *s, RefData **&l, RefData **&r) {
    s->SAVE_VAR_STATE(tpl, l, r);
    MOVE_TO_next_template(tpl);
    return GO;
};

TResult  RefVariable_e::back(RefData**&tpl, Session *s, RefData **&l, RefData **&r) {
    s->RESTORE_VAR_STATE(tpl, l, r);

    if (l) {
        // предыдущее значение не пустое
        if ((void*)r == (void*)s->getTopDataSkob()) {
            MOVE_TO_pred_template(tpl);
            return BACK;
        };
        MOVE_TO_next_term(r);
        r = endOfTerm(r);
    } else {
        MOVE_TO_next_term(r);
        l = beginOfTerm(r);
        r = endOfTerm(r);
    }

    if ((void*)r == (void*)s->getTopDataSkob()) {
        MOVE_TO_pred_template(tpl);
        return BACK;
    };
    s->SAVE_VAR_STATE(tpl, l, r); // TODO: Р_РїС'РёР_РёР·РёС_Р_Р_Р°С'С_
    MOVE_TO_next_template(tpl);
    return GO;

};

bool    RefVariable_e::operator==(RefData &rd) {
    return ref_dynamic_cast<RefVariable_e >(&rd);
};

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

#ifndef REF_VARIABLES_H_INCLUDED
#define REF_VARIABLES_H_INCLUDED

#include "data.h"



class RefVariable_e : public RefVariable {
public:
    ////CLASS_OBJECT_CAST(RefVariable_e);

    RefVariable_e(unistring name = EmptyUniString) : RefVariable(name) {};

    TResult  init(RefData **&tpl, Session *, RefData **&, RefData **&);
    TResult  back(RefData **&tpl, Session *, RefData **&, RefData **&);
    bool operator==(RefData &rd);
    virtual unistring explode() {        return " e."+getName()+" ";    };
};



class RefVariable_E : public RefVariable {
public:
    ////CLASS_OBJECT_CAST(RefVariable_E);

    RefVariable_E(unistring name = EmptyUniString) : RefVariable(name) {};

    TResult  init(RefData **&tpl, Session *, RefData **&, RefData **&);
    TResult  back(RefData **&tpl, Session *, RefData **&, RefData **&);
    bool operator==(RefData &rd);
    virtual unistring explode() {        return " E."+getName()+" ";    };
};

class RefVariable_END : public RefVariable_E {
public:
    ////CLASS_OBJECT_CAST(RefVariable_END);
    RefVariable_END(unistring name = EmptyUniString) : RefVariable_E(name) {};

    TResult  back(RefData **&tpl, Session *, RefData **&, RefData **&);
    virtual unistring explode() {        return " END."+getName()+" ";    };
};


class RefVariable_s : public RefVariable {
public:
    ////CLASS_OBJECT_CAST(RefVariable_s);

    RefVariable_s(unistring name = EmptyUniString) : RefVariable(name) {};

    TResult  init(RefData **&tpl, Session *, RefData **&, RefData **&);
    TResult  back(RefData **&tpl, Session *, RefData **&, RefData **&);
    bool operator==(RefData &rd);
    virtual unistring explode() {        return " s."+getName()+" ";    };
};


class RefVariable_t : public RefVariable {
public:
    ////CLASS_OBJECT_CAST(RefVariable_t);

    RefVariable_t(unistring name = EmptyUniString) : RefVariable(name) {};

    TResult  init(RefData **&tpl, Session *, RefData **&, RefData **&);
    TResult  back(RefData **&tpl, Session *, RefData **&, RefData **&);
    bool operator==(RefData &rd);
    virtual unistring explode() {        return " t."+getName()+" ";    };
};



#endif

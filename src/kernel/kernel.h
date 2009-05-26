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

#ifndef KERNEL_H_INCLUDED
#define KERNEL_H_INCLUDED

#include <iostream>
#include <sstream>

#include "data.h"


namespace co {
    extern long ocount;
    extern long datacount;
    extern long symcount;
    extern long varcount;
    extern long chaincount;
};



class RefVariable_e : public RefVariable {
public:
    CLASS_OBJECT_CAST(RefVariable_e);

RefVariable_e(unistring name = EmptyUniString, RefData *rp=0) : RefVariable(name, rp) {};

    TResult  init(RefData *&tpl, Session *, RefData *&);
    TResult  back(RefData *&tpl, Session *, RefData *&, RefData *&);
    void     dropall(Session *);
    bool operator==(RefData &rd);

    virtual RefData*  Copy(RefData *d = 0) {
        return new RefVariable_e(getName());
    };
    virtual unistring toString() {
        return " e."+getName()+" ";
    };
};

class RefVariable_E : public RefVariable {
public:
CLASS_OBJECT_CAST(RefVariable_E);

RefVariable_E(unistring name = EmptyUniString, RefData *rp=0) : RefVariable(name, rp) {};

    void     dropall(Session *);
    bool operator==(RefData &rd);

    TResult  init(RefData *&tpl, Session *, RefData *&);
    TResult  back(RefData *&tpl, Session *, RefData *&, RefData *&);
    virtual RefData*  Copy(RefData *d = 0) {
        return new RefVariable_E(getName());
    };
    virtual unistring toString() {
        return "E."+getName();
    };
};

class RefVariable_END : public RefVariable {
public:
    CLASS_OBJECT_CAST(RefVariable_END);

RefVariable_END(unistring name = EmptyUniString, RefData *rp=0) : RefVariable(name, rp) {};

    void     dropall(Session *);
    bool operator==(RefData &rd);

    TResult  init(RefData *&tpl, Session *, RefData *&);
    TResult  back(RefData *&tpl, Session *, RefData *&, RefData *&);
    virtual RefData*  Copy(RefData *d = 0) {
        return new RefVariable_END(getName());
    };
    virtual unistring toString() {
        return "END."+getName();
    };
};

class RefVariable_s : public RefVariable {
public:
CLASS_OBJECT_CAST(RefVariable_s);

RefVariable_s(unistring name = EmptyUniString, RefData *rp=0) : RefVariable(name, rp) {};
    //void     dropall(Session *);
    bool operator==(RefData &rd) {
        return false;
    };

    TResult  init(RefData *&tpl, Session *, RefData *&);
    TResult  back(RefData *&tpl, Session *, RefData *&, RefData *&);
    virtual RefData*  Copy(RefData *d = 0) {
        return new RefVariable_s(getName());
    };
    virtual unistring toString() {
        return " s."+getName()+" ";
    };
};

class RefVariable_t : public RefVariable {
public:
CLASS_OBJECT_CAST(RefVariable_t);

RefVariable_t(unistring name = EmptyUniString, RefData *rp=0) : RefVariable(name, rp) {
        return;
    };

    bool operator==(RefData &rd) {
        return false;
    };

    TResult  init(RefData *&tpl, Session *, RefData *&);//{ SYSTEMERROR(""); };
    TResult  back(RefData *&tpl, Session *, RefData *&, RefData *&);//{ SYSTEMERROR(""); };
    virtual RefData*  Copy(RefData *d = 0) {
        return new RefVariable_t(getName());
    };
    virtual unistring toString() {
        return "t."+getName();
    };
};


/*************************
*   Скобки
**************************/
class RefStructBracket : public RefBracketBase{  // IRefVarStacked нужно для back(l, r) - работает с getStackOfDataSkob
public:
CLASS_OBJECT_CAST(RefStructBracket);
    virtual bool IRefVarStacked(){ return true; };

    RefStructBracket(RefData* rp=0);
    RefStructBracket(RefStructBracket *br, RefData* rp=0);

    bool       operator ==(RefData &);
    RefData*  next_term( ThisId );
    RefData*  pred_term( ThisId );
    TResult    init(RefData *&tpl,  Session* , RefData *& );
    TResult    back(RefData *&tpl,  Session* , RefData *&, RefData *& );
    void    forceback(Session *);
    unistring toString() {
        std::ostringstream s;
        s << (isOpen()?"(":") ") ;//<< "." << (long)this << ":other=" << (long)other;
        return s.str();
    };

    RefData* Copy(RefData *rp) {
        RefStructBracket* br = new RefStructBracket(rp);
        return new RefNULL(br);
    };
    RefData* Copy(RefBracketBase *b, RefData *rp) {
        #ifdef TESTCODE
        if (!dynamic_cast<RefStructBracket *>(b)) SYSTEMERROR("Closed brackets error: " << b->toString() << " with " << this->toString());
        #endif
        return new RefStructBracket((RefStructBracket *)b, rp);
    };

    unistring getName() {
        SYSTEMERROR("unexpected call");
    };

};


class RefExecBracket : public RefBracketBase {
public:
CLASS_OBJECT_CAST(RefExecBracket);

    RefExecBracket(RefData* rp=0);
    RefExecBracket(RefExecBracket *br, RefData* rp=0);

    bool       operator ==(RefData &rd);
    RefData*  next_term( ThisId var_id );
    RefData*  pred_term( ThisId var_id );
    TResult    init(RefData *&tpl,  Session* s, RefData *&l );
    TResult    back(RefData *&tpl,  Session* s, RefData *&l, RefData *&r );
    unistring toString() {
        std::ostringstream s;
        s << (isOpen()?"<":"> ") ;//<< "." << (long)this << "other:" << (long)other;
        return s.str();
    };

    RefData* Copy(RefData *rp) {
        RefExecBracket* br = new RefExecBracket(rp);
        return new RefNULL(br);
    };
    RefData* Copy(RefBracketBase *b, RefData *rp) {
        #ifdef TESTCODE
        if (!dynamic_cast<RefExecBracket *>(b)) SYSTEMERROR("Closed brackets error: " << b->toString() << " with " << this->toString());
        #endif
        return new RefExecBracket((RefExecBracket *)b, rp);
    };
};



unistring vectorToString(RefData *f, RefData *g);
unistring vectorExplode(RefData *f, RefData *g);
void print_vector(RefData *f, RefData *t=0);

#endif // DATATERMS_H_INCLUDED


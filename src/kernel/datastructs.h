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

#ifndef DATASTRUCTS_H_INCLUDED
#define DATASTRUCTS_H_INCLUDED

#include "data.h"

#include <sstream>


class RefData_DOT;
class ref_variant_dot;
class ref_variant_ffwd;
class ref_variant_krest;
class ref_variant_vert;
class ref_variant_vopr;

//---------- $[  $] ----------
class RefData_DOT : public RefBracketBase { // begin- Рё end-
public:
    CLASS_OBJECT_CAST(RefData_DOT);
    virtual bool IRefVarStacked() {
        return true;
    };

    //~RefData_DOT(){ if(pred)next->pred=pred; if(pred)pred->next=next; };
RefData_DOT(RefData* rp = 0) : RefBracketBase(rp) {};

RefData_DOT(RefData_DOT *nd, RefData* rp = 0) : RefBracketBase(nd, rp) {};
    bool operator ==(RefData &rd);
    TResult  init(RefData *&tpl, Session* s, RefData *&l, RefData *&r); //
    TResult  back(RefData *&tpl, Session* s, RefData *&l, RefData *&r); //

    virtual RefData*  next_term( ThisId var_id, Session *s );
    virtual RefData*  pred_term( ThisId var_id, Session *s );

    unistring getName() {
        SYSTEMERROR("unexpected call");
    }

    virtual RefData* Copy(RefData *where=0) {
        return new RefData_DOT(where);
    };
    virtual RefData* Copy(RefBracketBase *b, RefData *where=0) {
        #ifdef TESTCODE
        if (! dynamic_cast<RefData_DOT *>(b)) SYSTEMERROR(" unexpected bracket type: " << b->toString() << " ~ " << this->toString());
        #endif
        return new RefData_DOT((RefData_DOT *)b, where);
    };
    virtual unistring toString();

};



//-----------  o  -----------
class ref_variant_dot : public RefData/*, public IRefVarStacked*/ { // IRefVarStacked чтоб срабаытвал restoreTempl и saveTempl
public:


    ref_variant_vert  *nextvert;

    ref_variant_dot( RefData* rp=0);
    TResult	   init	      (RefData *&tpl, Session *s, RefData *&l, RefData *&);
    TResult	   back	      (RefData *&tpl, Session *s, RefData *&l, RefData *&r);
    bool operator==(RefData&rd);
    void forceback(RefData *&, Session* s) {};

    virtual RefData* Copy(RefData *where=0) {
        SYSTEMERROR("zagl");
    };
    virtual unistring toString() {
        return "-o- ";
        std::ostringstream ss;
        ss << " $o." << ((long)this);
        return ss.str();
    };
    /*
    unistring getName(){ return EmptyUniString; };
    void setName(unistring ){ SYSTEMERROR("alarm"); };
    */

};
//----------  |  ------------
class ref_variant_vert : public RefData {
public:


    RefData *vopr;

    ref_variant_vert( RefData* rp=0);
    bool operator==(RefData&rd);
    void forceback (RefData *&, Session *s);

    TResult  init(RefData *&tpl, Session* s, RefData *&l, RefData *&); //
    TResult  back(RefData *&tpl, Session* s, RefData *&l, RefData *&r); //
    virtual RefData* Copy(RefData *where=0) {
        SYSTEMERROR("zagl");
    };
    virtual unistring toString() {
        return " |";
    };

};
//----------  =>  ------------
class ref_variant_ffwd : public RefData {


public:
    ref_variant_ffwd(RefData *rp=0);
    TResult	 init(RefData *&tpl, Session *s, RefData *&l, RefData *&);
    TResult	 back(RefData *&tpl, Session *s, RefData *&l, RefData *&r);
    bool operator==(RefData&rd);

    virtual RefData* Copy(RefData *where=0) {
        SYSTEMERROR("zagl");
    };
    void forceback(RefData *&, Session* s) {};
    virtual unistring toString() {
        return "=>";
        std::ostringstream ss;
        ss << " =>." << (long)this;
        return ss.str();
    };

};
//----------  ?  ------------
class ref_variant_vopr : public RefData {
public:
    RefData *begbr;


    ref_variant_vopr( RefData* rp=0);
    bool operator==(RefData&rd);

    TResult  init(RefData *&tpl, Session* s, RefData *&l, RefData *&); //
    TResult  back(RefData *&tpl, Session* s, RefData *&l, RefData *&r); //
    virtual RefData* Copy(RefData *where=0) {
        SYSTEMERROR("zagl");
    };
    virtual unistring toString() {
        return "-?-";
    };
    void forceback(RefData *&, Session* s);

};


////////////////  {o      | o      | o      | ?} ///////////////////
//---------- {  } ----------
class RefGroupBracket : public RefBracketBase {
protected:
    unistring name;

public:
    virtual unistring getName() {
        return name;
    }
    virtual void setName(unistring s) {
        name = s;
    }
public:
    CLASS_OBJECT_CAST(RefGroupBracket);
    virtual bool IRefVarStacked() { return true; };

    virtual ~RefGroupBracket() {};
    RefGroupBracket(unistring name, RefData *rp) : RefBracketBase(rp) {
        setName(name);
    }; // оптимизировать
    RefGroupBracket(RefGroupBracket *oth, RefData *rp) : RefBracketBase(oth, rp) {
        setName(oth->name);
    };
    //RefGroupBracket(RefBracketBase *oth, RefData *rp) : RefBracketBase(oth) {};
    TResult  init(RefData *&tpl, Session *, RefData *&l, RefData *&);
    TResult  back(RefData *&tpl, Session *, RefData *&l, RefData *&r);
    bool operator==(RefData&rd) {
        return false;
    };

    virtual RefData* Copy(RefData *where=0) {
        SYSTEMERROR("unexpected call");
    };
    virtual RefData* Copy(RefBracketBase *b, RefData *where=0) {
        SYSTEMERROR("unexpected call");
    };

    virtual unistring toString() {
        return (isOpen() ? "{" : ("}."+name) );
    };
    virtual void forceback(RefData *&, Session *) { /** todo: очищать подсессию до открывающей скобки */};
};






//-------- [...] -----------//  варианты. В ОВ выглядит так:    { [ ... ] }.vname
class ref_repeater : public RefBracketBase {
    infint min; /// todo: экономить. вообще используются толька в ]
    infint max;
public:
    CLASS_OBJECT_CAST(ref_repeater);

    virtual ~ref_repeater() {};

ref_repeater(infint tfrom, infint tto, RefData *rp=0) : RefBracketBase(rp) {
        min=tfrom;
        max=tto;
    };
ref_repeater(ref_repeater *oth, RefData *rp=0) : RefBracketBase(oth, rp) { };
    //RefGroupBracket(RefBracketBase *oth, RefData *rp) : RefBracketBase(oth) {};
    TResult  init(RefData *&tpl, Session *, RefData *&l, RefData *&);
    TResult  back(RefData *&tpl, Session *, RefData *&l, RefData *&r);

    bool operator==(RefData&rd) {
        SYSTEMERROR("unexpected call");
    };

    virtual RefData* Copy(RefData *where=0) {
        SYSTEMERROR("unexpected call");
    };
    virtual RefData* Copy(RefBracketBase *b, RefData *where=0) {
        SYSTEMERROR("unexpected call");
    };

    infint getMin() {
        return isOpen()?min: ((ref_repeater*)other)->getMin();
    };
    infint getMax()  {
        return isOpen()?max  : ((ref_repeater*)other)->getMax();
    };

    virtual unistring toString() {
        if (isOpen()) {
            return "[.." ;
        }
        std::ostringstream ss;
        ss << "[.." << getMin() << ".." << getMax() << "]";
        return ss.str();
    };
    virtual void forceback(RefData *&, Session *) { /** todo: */};


};




#endif // DATASTRUCTS_H_INCLUDED

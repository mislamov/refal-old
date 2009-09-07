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

#ifndef REF_SYMBOLS_H_INCLUDED
#define REF_SYMBOLS_H_INCLUDED

#include "data.h"
#include "session.h"

#include <sstream>

class RefAlphaBase;


inline unistring the_text(RefData **a, RefData **b){
	if (!a) {
		return " $empty ";
	}
	size_t leng = b-a;
	if (!a || !b || leng<0) RUNTIMEERROR("the_text(**, **)", "error arguments");
	unistring result = "";
    for (size_t i=0; i<=leng; i++) {
		result += (a[i]?a[i]->explode():" 0x0000 ");
    }
	return result;
}


template <class T, class t>
class RefSymbolBase : public RefData {
public:
    RefSymbolBase(){};
    virtual ~RefSymbolBase(){};
    virtual t getValue() = 0;
    bool operator ==(RefData &rd) {
        RefData *tmp = &rd;
        void* rr = dynamic_cast<RefAlphaBase*>(tmp);
        return ref_dynamic_cast<T>(&rd) && ((T*)&rd)->getValue()==this->getValue();
    };
    TResult init(RefData**&, Session* , RefData**&, RefData**&);
    TResult back(RefData**&, Session* , RefData**&, RefData**&);
    unistring explode(){
        std::ostringstream os;
        os << getValue();
        return os.str();
        };
};


class RefAlphaBase : public RefSymbolBase<RefAlphaBase, unichar> {
public:
    CLASS_OBJECT_CAST(RefAlphaBase);
    virtual ~RefAlphaBase(){};
};

class RefIntegerBase : public RefSymbolBase<RefIntegerBase, infint> {
public:
    CLASS_OBJECT_CAST(RefIntegerBase);
    virtual ~RefIntegerBase(){};
};


class RefRealBase : public RefSymbolBase<RefRealBase, infreal> {
public:
    CLASS_OBJECT_CAST(RefRealBase);
    virtual ~RefRealBase(){};
};



class RefWordBase : public RefSymbolBase<RefWordBase, unistring> {
public:
    CLASS_OBJECT_CAST(RefWordBase);
    virtual ~RefWordBase(){};
};


class RefByteBase : public RefSymbolBase<RefByteBase, char> {
public:
    CLASS_OBJECT_CAST(RefByteBase);
    virtual ~RefByteBase(){};
};




class RefAlpha : public RefAlphaBase {
    unichar value;
public:
    RefAlpha(unichar val){ value = val; };
    virtual ~RefAlpha(){};
    virtual unichar getValue()   { return value; };
};


class RefInteger : public RefIntegerBase {
    infint value;
public:
    RefInteger(infint val){ value = val; };
    virtual ~RefInteger(){};
    virtual infint getValue() {return value;};
};


class RefReal : public RefRealBase {
	infreal value;
public:
    RefReal(infreal val){ value = val; };
    virtual ~RefReal(){};
    virtual infreal getValue() {return value;};
};


class RefWord : public RefWordBase {
    unistring value;
public:
	RefWord(unistring val){ value = val; };
    virtual ~RefWord(){};
    virtual unistring getValue() {return value;};
    unistring debug() {
		std::ostringstream ss;
        ss << '"' << replace(value, "\n", "\\n") << "\" ";
        return ss.str();
	}
};


class RefByte : public RefByteBase {
    char value;
public:
	RefByte(char val){ value = val; };
    virtual ~RefByte(){};
    virtual char getValue() {return value;};
};


template <class TT, class tt>
TResult  RefSymbolBase<TT, tt>::init(RefData**& tpl, Session* s, RefData**& l, RefData**& r) {
    s->MOVE_TO_next_term(r);
	LOG(" " << this->debug() << " == " << ((r && *r) ? (*r)->debug() : "0"));
    if ( r && *r && (this==*r || *this == **r)) {
        s->MOVE_TO_next_template(tpl);
        return GO;
    }

	s->MOVE_TO_pred_template(tpl);
    return BACK;
};


template<class T, class t>
TResult  RefSymbolBase<T, t>::back(RefData**&tpl, Session* s, RefData**&l, RefData**&r) {
    s->MOVE_TO_pred_template(tpl);
    return BACK;
};



#endif

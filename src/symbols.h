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

#ifndef REF_SYMBOLS_H_INCLUDED
#define REF_SYMBOLS_H_INCLUDED

#include "data.h"
#include "session.h"

#include <sstream>
#include <map>

class RefAlphaBase;
RefAlphaBase* newRefAlpha(Session *, unichar);


unistring the_explode(RefData **a, RefData **b);
unistring the_text(RefData **a, RefData **b);
unistring the_debug_text(RefData **a, RefData **b);



template <class T, class t>
class RefSymbolBase : public RefData {
public:
	RefSymbolBase(Session *s) : RefData(s){};
    virtual ~RefSymbolBase(){};
    virtual t getValue() = 0;
	virtual RefSymbolBitType isRefSymbol() = 0;

    bool operator ==(RefData &rd) {
        return ref_dynamic_cast<T>(&rd) && ((T*)&rd)->getValue()==this->getValue();
    };
	bool operator >(RefData &rd){ notrealisedERRORn; };

    TResult init(RefData**&, Session* , RefData**&, RefData**&);
    TResult back(RefData**&, Session* , RefData**&, RefData**&);
    unistring explode(){
        std::ostringstream os;
        os << getValue();
        return os.str();
        };
    unistring debug(){
		unistring tmp = explode() + " ";
		return explode() + " ";
	};
};


class RefAlphaBase : public RefSymbolBase<RefAlphaBase, unichar> {
public:
	RefAlphaBase(Session *s) : RefSymbolBase<RefAlphaBase, unichar>(s) {};

    ////CLASS_OBJECT_CAST(RefAlphaBase);
    virtual ~RefAlphaBase(){};
    #ifdef TESTCODE
	virtual unistring explode(){
		if (getValue() == '\n') return "\\n";
		if (getValue() == '\t') return "\\t";
		return RefSymbolBase<RefAlphaBase, unichar>::explode();
	};
	#endif
	virtual unistring toString(){ return explode(); };
	virtual unistring debug(){ return explode(); };

	CLASS_SYMBOL_CAST(RefAlphaBase);
	virtual bool operator ==(RefData &rd) { return this==&rd; };
};

class RefIntegerBase : public RefSymbolBase<RefIntegerBase, infint> {
public:
    ////CLASS_OBJECT_CAST(RefIntegerBase);
	RefIntegerBase(Session *s) : RefSymbolBase<RefIntegerBase, infint>(s) {};
    virtual ~RefIntegerBase(){};

	CLASS_SYMBOL_CAST(RefIntegerBase);
};


class RefRealBase : public RefSymbolBase<RefRealBase, infreal> {
public:
    ////CLASS_OBJECT_CAST(RefRealBase);
	RefRealBase(Session *s) : RefSymbolBase<RefRealBase, infreal>(s) {};
    virtual ~RefRealBase(){};

	CLASS_SYMBOL_CAST(RefRealBase);
};



class RefWordBase : public RefSymbolBase<RefWordBase, unistring> {
public:
    ////CLASS_OBJECT_CAST(RefWordBase);
	RefWordBase(Session *s) : RefSymbolBase<RefWordBase, unistring>(s) {};
    virtual ~RefWordBase(){};

	CLASS_SYMBOL_CAST(RefWordBase);
};


class RefByteBase : public RefSymbolBase<RefByteBase, char> {
public:
    ////CLASS_OBJECT_CAST(RefByteBase);
	RefByteBase(Session *s) : RefSymbolBase<RefByteBase, char>(s) {};
    virtual ~RefByteBase(){};

	CLASS_SYMBOL_CAST(RefByteBase);
};



class RefAlpha : public RefAlphaBase {
    unichar value;
public:
	static std::map<unichar, RefAlphaBase*> alphamap;
	static void RefAlpha::alphaMapDestroy();

	RefAlpha(Session *s, unichar val) : RefAlphaBase(s) { set_not_deleteble_by_gc_delete();	value = val; };
    virtual ~RefAlpha(){};
    virtual unichar getValue()   { return value; };

};

class RefAlpha128 : public RefAlphaBase {
public:
	RefAlpha128() : RefAlphaBase(0) { set_not_deleteble_by_gc_delete();	 };
	static RefAlpha128* alphatable;
	virtual unichar getValue()   { return (this-alphatable); };
};



class RefInteger : public RefIntegerBase {
    infint value;
public:
	RefInteger(Session *s, infint val) : RefIntegerBase(s) { value = val; };
    virtual ~RefInteger(){};
    virtual infint getValue() {return value;};
};


class RefReal : public RefRealBase {
	infreal value;
public:
	RefReal(Session *s, infreal val) : RefRealBase(s){ value = val; };
    virtual ~RefReal(){};
    virtual infreal getValue() {return value;};
};


class RefWord : public RefWordBase {
    unistring value;
public:
	inline RefWord(Session *s, unistring val) : RefWordBase(s){ value = val; };
	inline RefWord(Session *s, unichar val) : RefWordBase(s){ value = ""; value += val; };
    virtual ~RefWord(){};
    virtual unistring getValue() {return value;};
    unistring debug() ;
};


class RefByte : public RefByteBase {
    char value;
public:
	RefByte(Session *s, char val) : RefByteBase(s) { value = val; };
    virtual ~RefByte(){};
    virtual char getValue() {return value;};
};




template <class TT, class tt>
TResult  RefSymbolBase<TT, tt>::init(RefData**& tpl, Session* s, RefData**& l, RefData**& r) {
    s->MOVE_TO_next_term(r);
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





/***********************
*   ����������
************************/
template <class T> class RefVarForSymbol : public RefVariable
{
public:
    TResult init(RefData**&, Session* , RefData**&, RefData**&);
    TResult back(RefData**&, Session* , RefData**&, RefData**&);
	RefVarForSymbol (unistring name) : RefVariable(name) {};

    virtual unistring explode(){        return "RefVarForSymbol<T>."+getName();    }
};


template <class T>
TResult RefVarForSymbol<T>::init(RefData**&tpl, Session* sess, RefData**&l, RefData**&r){
	sess->MOVE_TO_next_term(r);
    if (r && ref_dynamic_cast<T >(*r)){
        l=r;
		sess->saveVar(this, l, r);
		sess->MOVE_TO_next_template(tpl);
        return GO;
    }

	sess->MOVE_TO_pred_template(tpl);
    return BACK;
};


template <class T>
TResult RefVarForSymbol<T>::back(RefData**&tpl, Session* sess, RefData**&l, RefData**&r){
	sess->restoreVar(this, l, r);
	sess->MOVE_TO_pred_template(tpl);
    return BACK;
};



typedef RefVarForSymbol<RefIntegerBase>  RefVarInteger;
typedef RefVarForSymbol<RefRealBase>     RefVarReal;
typedef RefVarForSymbol<RefWordBase>     RefVarWord;
typedef RefVarForSymbol<RefAlphaBase>    RefVarAlpha;
typedef RefVarForSymbol<RefByteBase>     RefVarByte;








#endif

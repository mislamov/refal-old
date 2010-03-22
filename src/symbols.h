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
	RefSymbolBase(Session *sess) : RefData(sess){};
    virtual ~RefSymbolBase(){};
    virtual t getValue() = 0;
	virtual RefSymbolBitType isRefSymbol() = 0;

    bool operator ==(RefData &rd) {
        return ref_dynamic_cast<T>(&rd) && ((T*)&rd)->getValue()==this->getValue();
    };
	bool operator >(RefData &rd){ notrealisedERRORn; };

    TResult init(RefData**&, Session*, RefData**&, RefData**&, RefChain *&);
    TResult back(RefData**&, Session*, RefData**&, RefData**&, RefChain *&);
    unistring explode(){
        std::ostringstream os;
        os << getValue();
        return os.str();
        };
    unistring debug(){
		unistring tmp = explode() + " ";
		return explode() + " ";
	};
    unistring toString(){
		unistring tmp = explode() + " ";
		return explode() + " ";
	};
};


class RefAlphaBase : public RefSymbolBase<RefAlphaBase, unichar> {
public:
	RefAlphaBase(Session *sess) : RefSymbolBase<RefAlphaBase, unichar>(sess) {};

    ////CLASS_OBJECT_CAST(RefAlphaBase);
    virtual ~RefAlphaBase(){};
    #ifdef TESTCODE
	virtual unistring explode(){
		//if (getValue() == '\n') return "\\n";
		//if (getValue() == '\t') return "\\t";
		return RefSymbolBase<RefAlphaBase, unichar>::explode();
	};
	#endif
	virtual unistring toString(){ return explode(); };
	virtual unistring debug(){ 
		if (getValue() == ' ') return " _ ";
		if (getValue() == '\n') return "\\n";
		if (getValue() == '\t') return "\\t";
		return explode(); 
	};

	CLASS_SYMBOL_CAST(RefAlphaBase);
	virtual bool operator ==(RefData &rd) { return this==&rd; };
};

class RefIntegerBase : public RefSymbolBase<RefIntegerBase, infint> {
public:
    ////CLASS_OBJECT_CAST(RefIntegerBase);
	RefIntegerBase(Session *sess) : RefSymbolBase<RefIntegerBase, infint>(sess) {};
    virtual ~RefIntegerBase(){};

	CLASS_SYMBOL_CAST(RefIntegerBase);
};


class RefRealBase : public RefSymbolBase<RefRealBase, infreal> {
public:
    ////CLASS_OBJECT_CAST(RefRealBase);
	RefRealBase(Session *sess) : RefSymbolBase<RefRealBase, infreal>(sess) {};
    virtual ~RefRealBase(){};

	CLASS_SYMBOL_CAST(RefRealBase);
};



class RefWordBase : public RefSymbolBase<RefWordBase, unistring> {
public:
    ////CLASS_OBJECT_CAST(RefWordBase);
	RefWordBase(Session *sess) : RefSymbolBase<RefWordBase, unistring>(sess) {};
    virtual ~RefWordBase(){};

	CLASS_SYMBOL_CAST(RefWordBase);
};


class RefByteBase : public RefSymbolBase<RefByteBase, char> {
public:
    ////CLASS_OBJECT_CAST(RefByteBase);
	RefByteBase(Session *sess) : RefSymbolBase<RefByteBase, char>(sess) {};
    virtual ~RefByteBase(){};

	CLASS_SYMBOL_CAST(RefByteBase);
};



class RefAlpha : public RefAlphaBase {
    unichar value;
public:
	static std::map<unichar, RefAlphaBase*> alphamap;
	static void RefAlpha::alphaMapDestroy();

	RefAlpha(Session *sess, unichar val) : RefAlphaBase(sess) { set_not_deleteble_by_gc_delete();	value = val; };
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
	RefInteger(Session *sess, infint val) : RefIntegerBase(sess) { value = val; };
    virtual ~RefInteger(){};
    virtual infint getValue() {return value;};
};


class RefReal : public RefRealBase {
	infreal value;
public:
	RefReal(Session *sess, infreal val) : RefRealBase(sess){ value = val; };
    virtual ~RefReal(){};
    virtual infreal getValue() {return value;};
};


class RefWord : public RefWordBase {
    unistring value;
public:
	inline RefWord(Session *sess, unistring val) : RefWordBase(sess){ value = val; };
	inline RefWord(Session *sess, unichar val) : RefWordBase(sess){ value = ""; value += val; };
    virtual ~RefWord(){};
    virtual unistring getValue() {return value;};
    unistring debug() ;
};


class RefByte : public RefByteBase {
    char value;
public:
	RefByte(Session *sess, char val) : RefByteBase(sess) { value = val; };
    virtual ~RefByte(){};
    virtual char getValue() {return value;};
};




template <class TT, class tt>
TResult  RefSymbolBase<TT, tt>::init(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own) {
	//todo убрать этот хак. сохранять границы а не 0 при перемещении
	if (!r && sess->alt_r+1==sess->current_view_l()){
		r = sess->alt_r;
	}
	
	sess->MOVE_TO_next_term(r);
    if ( r && *r && (this==*r || *this == **r)) {
        sess->MOVE_TO_next_template(tpl);
        return GO;
    }

	sess->MOVE_TO_pred_template(tpl);
    return BACK;
};


template<class T, class t>
TResult  RefSymbolBase<T, t>::back(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own) {
    sess->MOVE_TO_pred_template(tpl);
    return BACK;
};





/***********************
*   Переменные
************************/
template <class T> class RefVarForSymbol : public RefVariable
{
public:
    TResult init(RefData**&, Session*, RefData**&, RefData**&, RefChain *&);
    TResult back(RefData**&, Session*, RefData**&, RefData**&, RefChain *&);
	RefVarForSymbol (unistring name) : RefVariable(name) {};
    virtual unistring explode(){        return "RefVarForSymbol<T>."+getName();    }
};


template <class T>
TResult RefVarForSymbol<T>::init(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own){
	sess->MOVE_TO_next_term(r);
    if (r && ref_dynamic_cast<T >(*r)){
        l=r;
		sess->saveVar(this, l, r, lr_own);
		sess->MOVE_TO_next_template(tpl);
        return GO;
    }

	sess->MOVE_TO_pred_template(tpl);
    return BACK;
};


template <class T>
TResult RefVarForSymbol<T>::back(RefData**&tpl, Session* sess, RefData**&l, RefData**&r, RefChain *&lr_own){
	sess->restoreVar(this, l, r, lr_own);
	sess->MOVE_TO_pred_template(tpl);
    return BACK;
};



typedef RefVarForSymbol<RefIntegerBase>  RefVarInteger;
typedef RefVarForSymbol<RefRealBase>     RefVarReal;
typedef RefVarForSymbol<RefWordBase>     RefVarWord;
typedef RefVarForSymbol<RefAlphaBase>    RefVarAlpha;
typedef RefVarForSymbol<RefByteBase>     RefVarByte;








#endif

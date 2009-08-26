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

#ifndef REF_DATA_H_INCLUDED
#define REF_DATA_H_INCLUDED

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <map>


#include "config.h"
#include "poolTuples.h"
//#include "sentence.h"


class RefExecBracket;
class RefStructBracket;
class RefChain;
class ref_variant_dot;
class ref_variant_ffwd;
class ref_variant_vert;
class ref_variant_vopr;


// Абстрактный класс - предок всех термов языка
class RefData : public RefObject {
public:
    virtual bool operator >(RefData &rd)  { RUNTIMEERROR("operator >", "Not comparable"); };
    //virtual bool operator ==(RefData &rd) = 0;//{ return false; };
	virtual bool operator ==(RefData &rd){ SYSTEMERROR("alarm!"); return false; };
    virtual TResult init(RefData **&activeTemplate, Session* s, RefData **&currentRight, RefData **&currentLeft)=0; //  --> operator==() => [return GO] else [return BACK]
    virtual TResult back(RefData **&activeTemplate, Session* s, RefData **&currentRight, RefData **&currentLeft)=0;
    virtual void    forceback(RefData *&activeTemplate, Session* s) {     SYSTEMERROR("RefData.forceback NOT DEFINE for "                 << toString());    }; // принудительный откат. Точка убирает из сессии свое состояние
};
inline RefData** MOVE_TO_next_template(RefData** &p) {    return ++p;}
inline RefData** MOVE_TO_pred_template(RefData** &p) {    return --p;}
inline RefData** MOVE_TO_next_symbol(RefData** &p) {    return ++p;}
inline RefData** MOVE_TO_pred_symbol(RefData** &p) {    return --p;}


static RefData* nullDataPoint = 0;




class RefNULL : public RefData {
public:
	RefNULL(){};
	virtual unistring explode(){
        #ifdef DEBUG
        return " . ";
        #endif
        return "";
    };

	virtual bool operator==(RefData&){SYSTEMERROR("unexpected");};
	virtual TResult init(RefData **&tpl, Session* , RefData **&, RefData **&){MOVE_TO_next_template(tpl); return GO;};
	virtual TResult back(RefData **&tpl, Session* , RefData **&, RefData **&){MOVE_TO_pred_template(tpl); return BACK;};

    void forceback(RefData *&, Session *) {};
};

static RefNULL* refNullGlobal = new RefNULL();


// Абстрактный класс - предок всех открытых переменных языка (простых и скобочных)
class RefVariableBase :  public RefData {
public:
    BASE_CLASS_CAST(RefVariableBase);
    virtual unistring getName() = 0;
    virtual bool IRefVarStacked() {        return true;    };
};


class RefVariable : public RefVariableBase { // Простая переменная
protected:
    unistring name;
public:
    BASE_CLASS_CAST(RefVariable);
    RefVariable(unistring name = EmptyUniString);
    unistring getName() {        return name;    }
    void setName(unistring s) {        name = s;    }
    virtual void    forceback(RefData *&, Session* s) { }; // принудительный откат. Точка убирает из сессии свое состоян
};




// скобки - это пара ссылок в цепочке на общее тело

class RefBracketBase;
class RefVariableBase;
class RefLinkToVariable;
class RefConditionBase;


class RefChain : public RefObject  {
	friend class Session;
protected:
    RefData** first;
	DataLinkPooledStack<size_t> varsAndBrackets ;	//	индексы закрытых переменных и скобок в подстановке. 
													//	first+1 + .. - закрытая переменная или скобка
													//	chain[..]  - она же
public:

	size_t leng; // длина цепочки

	inline RefData** get_first(){ return first+1; };
    inline RefData** get_last (){ return first+leng; };

    RefChain();
	RefChain::RefChain(RefData* );
	RefChain::RefChain(unistring);
	RefChain(RefData **&datachain, size_t theleng){ first=datachain; this->leng = theleng; };
    RefChain(RefData** a11, RefData** a12, RefChain *f_result_chain, RefData** a31, RefData** a32);
	RefChain(size_t size);
    virtual ~RefChain() {        free(first);    };

    // TODO: сделать блоковое расширение
    RefChain& operator+=(RefChain &ch);   // к левому аргумент пристыковывается копия правого!
    RefChain& operator+=(RefChain *ch);  // к левому аргумент пристыковывается копия правого!
    RefChain& operator+=(RefData  *ch);  // рефдата ПОГЛАЩАЕТСЯ цепочкой!!!
	RefChain& operator+=(RefBracketBase   *br); // скобки указывают друг на друга
	RefChain& operator+=(RefStructBracket *br); // ( null    )
	RefChain& operator+=(RefLinkToVariable  *vr);
	RefChain& operator+=(RefConditionBase *cn){ SYSTEMERROR("must be ChainPattern, not RefChain"); };
	inline RefData** operator[](size_t idx){ return first+idx+1; }

    unistring toString();
    unistring explode(); // голый текст без форматирования

	RefVariableBase** getVarByName(unistring name);
};

typedef RefChain ChainSubstitution;


// цепочка - образец (левая часть без условий. нет функц скобок.)
class ChainPattern : public RefChain {
public:
	ChainPattern();
	void closeDot();
	void closeDotIfNotYet();
	ChainPattern& operator+=(RefConditionBase *cn);
};

extern unistring getTextOfChain(RefData** from, RefData** to);


RefData** beginOfTerm(RefData** r);
RefData** endOfTerm  (RefData** r);

class RefBracketBase : public RefData {
public:
    BASE_CLASS_CAST(RefBracketBase);
	size_t opened_ind; // порядковый номер от get_first()
	size_t closed_ind; // порядковый номер от get_first()
	RefChain *chain;

	bool isSetClosed(){ return closed_ind!=SIZE_MAX; }
	bool isSetOpened(){ return opened_ind!=SIZE_MAX; }

	RefBracketBase (){opened_ind = closed_ind = SIZE_MAX; chain=0; }
	bool isOpen(RefData** p){
		#ifdef TESTCODE
		if (closed_ind-opened_ind <=0 || !chain || ((chain->get_first()+opened_ind)!= p && (chain->get_first()+closed_ind)!=p))
			SYSTEMERROR("brack-error");
		#endif
		return ((chain->get_first()+opened_ind)==p);
	};
	RefBracketBase **getOther(RefData** p){
		#ifdef TESTCODE
		if (closed_ind-opened_ind <=0 || !chain || (chain->get_first()+opened_ind!=p && chain->get_first()+closed_ind!=p))SYSTEMERROR("brack-error");
		if (! ref_dynamic_cast<RefBracketBase>(chain->get_first()[opened_ind])) SYSTEMERROR("brack-error");
		if (! ref_dynamic_cast<RefBracketBase>(chain->get_first()[closed_ind])) SYSTEMERROR("brack-error");
		#endif
		return (RefBracketBase**)(chain->get_first()+opened_ind==p ? chain->get_first()+closed_ind : chain->get_first()+opened_ind);
	};

	virtual RefBracketBase* newInstance() = 0;
	virtual RefBracketBase* newInstanceCopy(RefChain *ch) { 
		RefBracketBase* copy = newInstance();
		copy->chain = ch;
		copy->closed_ind = closed_ind;
		copy->opened_ind = opened_ind;
		return  copy;
	};

};

class RefExecBracket : public RefBracketBase {
public:
    CLASS_OBJECT_CAST(RefExecBracket);
	bool       operator ==(RefData &rd){ SYSTEMERROR("unexpected"); };
    TResult init(RefData **&tpl, Session* s, RefData **&l, RefData **&r){ SYSTEMERROR("unexpected"); };
    TResult back(RefData **&tpl, Session* s, RefData **&l, RefData **&r){ SYSTEMERROR("unexpected"); };
	unistring explode() { SYSTEMERROR("unexpected"); };
	unistring toString(){  
		return "<br>"; 
	};
	RefBracketBase* newInstance() { return new RefExecBracket(); };
};

class RefStructBracket : public RefBracketBase {
public:
    CLASS_OBJECT_CAST(RefStructBracket);
	bool       operator ==(RefData &rd){ // проверка только по типу. не по открытости
		return (ref_dynamic_cast<RefStructBracket>(&rd))?true:false;
	};
    TResult init(RefData **&tpl, Session* s, RefData **&l, RefData **&r);
    TResult back(RefData **&tpl, Session* s, RefData **&l, RefData **&r);
	unistring explode(){ return "(br)"; };
	RefBracketBase* newInstance() { return new RefStructBracket(); };
};

class RefData_DOT : public RefBracketBase {
public:
	CLASS_OBJECT_CAST(RefData_DOT);
    bool operator ==(RefData &rd) { SYSTEMERROR("unexpected"); };
    TResult init(RefData **&tpl, Session* s, RefData **&l, RefData **&r);
    TResult back(RefData **&tpl, Session* s, RefData **&l, RefData **&r);
	unistring toString(){ return "[br]"; };
	unistring explode() { SYSTEMERROR("unexpected"); };
	RefBracketBase* newInstance() { SYSTEMERROR("unexpected"); };
};




////////////////  {o      | o      | o      | ?} ///////////////////
//---------- {  } ----------
class RefGroupBracket : public RefBracketBase {
protected:
    unistring name;

public:
    unistring getName() {    return name;    }
    void setName(unistring s) {        name = s;    }

    CLASS_OBJECT_CAST(RefGroupBracket);
	bool       operator ==(RefData &rd){ // проверка только по типу. не по открытости
		return (ref_dynamic_cast<RefGroupBracket>(&rd))?true:false;
	};
	RefGroupBracket(unistring name) : RefBracketBase() { setName(name); };
    TResult init(RefData **&tpl, Session* s, RefData **&l, RefData **&r){ SYSTEMERROR("unrelised"); };
    TResult back(RefData **&tpl, Session* s, RefData **&l, RefData **&r){ SYSTEMERROR("unrelised"); };
	unistring explode() { SYSTEMERROR("unexpected"); };
	unistring toString(){ return  "{$"+name+"}"; };
	RefBracketBase* newInstance(){ SYSTEMERROR("unexpected"); };
};



//-----------  o  -----------
class ref_variant_dot : public RefData {
public:
    ref_variant_vert  **nextvert;

    ref_variant_dot(){SYSTEMERROR("unrelised");};
    TResult init(RefData **&tpl, Session* s, RefData **&l, RefData **&r);
    TResult back(RefData **&tpl, Session* s, RefData **&l, RefData **&r);
    //void forceback(RefData *&, Session* s) {};

	unistring explode() {		SYSTEMERROR("unexpected");	}
	unistring toString() {
        return "-o- ";
        std::ostringstream ss;
        ss << " $o." << ((long)this);
        return ss.str();
    };
};


//----------  |  ------------
class ref_variant_vert : public RefData {
public:
    RefData **vopr;

    ref_variant_vert(){SYSTEMERROR("unrelised");};
    //bool operator==(RefData&rd);
    //void forceback (RefData *&, Session *s);

    TResult init(RefData **&tpl, Session* s, RefData **&l, RefData **&r);
    TResult back(RefData **&tpl, Session* s, RefData **&l, RefData **&r);

	unistring toString() {	return " |";	};
	unistring explode() {SYSTEMERROR("unexpected"); };

};
//----------  =>  ------------
class ref_variant_ffwd : public RefData {
public:
    ref_variant_ffwd(){SYSTEMERROR("unrelised");};
    TResult init(RefData **&tpl, Session* s, RefData **&l, RefData **&r);
    TResult back(RefData **&tpl, Session* s, RefData **&l, RefData **&r);
    //bool operator==(RefData&rd);
    //void forceback(RefData *&, Session* s) {};
    virtual unistring toString() {
        return "=>";
        std::ostringstream ss;
        ss << " =>." << (long)this;
        return ss.str();
    };
	unistring explode() {SYSTEMERROR("unexpected"); };
};
//----------  ?  ------------
class ref_variant_vopr : public RefData {
public:
    RefData **begbr;

    ref_variant_vopr(){SYSTEMERROR("unrelised");};
    //bool operator==(RefData&rd);
    //void forceback(RefData *&, Session* s);

    TResult init(RefData **&tpl, Session* s, RefData **&l, RefData **&r);
    TResult back(RefData **&tpl, Session* s, RefData **&l, RefData **&r);
    unistring toString() {        return "-?-";    };
	unistring explode() {SYSTEMERROR("unexpected"); };
};




class TVarBody : public RefObject {
public:
    RefData** first;
    RefData** second;
};



inline RefData** MOVE_TO_next_term(RefData** &p) {
	if ((void*)p==(void*)&refNullGlobal) return ++p;

	RefStructBracket *br;
	if ((br=ref_dynamic_cast<RefStructBracket>(*p)) && br->isOpen(p)){  // (
		return (p = (RefData**) br->getOther(p)+1);
	}
	return ++p;
}
inline RefData** MOVE_TO_pred_term(RefData** &p) {
	if ((void*)p==(void*)&refNullGlobal) return --p;

	RefStructBracket *br;
	if ((br=ref_dynamic_cast<RefStructBracket>(*p)) && !br->isOpen(p)){  // )
		return (p = (RefData**) br->getOther(p)-1);
	}
	return --p;
};




// Ссылка на переменную
class RefLinkToVariable : public RefData {
	friend class Session;
protected:
	RefVariableBase *lnk;
public:
    CLASS_OBJECT_CAST(RefLinkToVariable);

	unistring explode();
	bool operator==(RefData&){SYSTEMERROR("unexpected");};
    TResult init(RefData **&tpl, Session* s, RefData **&l, RefData **&r);
    TResult back(RefData **&tpl, Session* s, RefData **&l, RefData **&r);
    //virtual RefData*  Copy(RefData* where=0);
    RefLinkToVariable(RefVariableBase *ln){lnk=ln;};
	RefLinkToVariable(unistring varName, RefChain *chain){
		RefVariableBase** cv = chain->getVarByName(varName);
		if (!cv) 
			SYSTEMERROR("can't find variable '" << varName << "' ");
		lnk=*cv; 
	};
    //void forceback(RefData *&, Session *) {};
    virtual unistring getPath() { return EmptyUniString;  }; // для наследников класса - путь к подпеременной относитльно основной переменной
};


class RefLinkToPartOfVariable : public RefLinkToVariable {
    unistring path; // путь к подпеременной относитльно основной переменной
public:
    unistring getPath() {        return path;    };
	RefLinkToPartOfVariable(unistring name, unistring tpath, RefChain *chain) : RefLinkToVariable(name, chain) {
        this->path = tpath;
    };
};


#endif // REF_KERNEL_H_INCLUDED


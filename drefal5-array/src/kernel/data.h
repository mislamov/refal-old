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
#include <limits>


#include "config.h"

#ifndef SIZE_MAX 
	#define SIZE_MAX std::numeric_limits<std::size_t>::max()
#endif

#ifndef POOLSIZE_DEFAULT
    #define POOLSIZE_DEFAULT 128
#endif


class RefExecBracket;
class RefStructBracket;
class RefChain;

// Абстрактный класс - предок всех термов языка
class RefData : public RefObject {
public:
    virtual bool operator >(RefData &rd)  { RUNTIMEERROR("operator >", "Not comparable"); };
    virtual bool operator ==(RefData &rd) = 0;//{ return false; };
    virtual TResult init(RefData **&activeTemplate, Session* s, RefData **&currentRight, RefData **&currentLeft)=0; //  --> operator==() => [return GO] else [return BACK]
    virtual TResult back(RefData **&activeTemplate, Session* s, RefData **&currentRight, RefData **&currentLeft)=0;
    virtual void    forceback(RefData *&activeTemplate, Session* s) {     SYSTEMERROR("RefData.forceback NOT DEFINE for "                 << toString());    }; // принудительный откат. Точка убирает из сессии свое состояние
};
inline RefData** MOVE_TO_next_template(RefData** &p) {    return ++p;}
inline RefData** MOVE_TO_pred_template(RefData** &p) {    return --p;}


static RefData* nullDataPoint = 0;

template <class T>
class DataLinkPool {
	size_t idx;
	size_t size;
	T* pool;
public:
	DataLinkPool(){
		idx = 0;
		size = POOLSIZE_DEFAULT;
		pool = (T*)malloc(sizeof(T)*size);
		if (!pool) RUNTIMEERROR("Mem-buffer", "memory limit");
		memset(pool, 0xff, sizeof(T)*size);
	};

	void put(T l){
		if (idx >= size-1){
			size+=POOLSIZE_DEFAULT;
			pool = (T*)realloc(pool, sizeof(T)*size);
		};
		pool[idx] = l;
		++idx;
	};

	T top_pop(){ 
		#ifdef TESTCODE
		if (!idx) SYSTEMERROR("link-stack is empty!");
		#endif
		return pool[--idx]; 
	};

	T top(){ 
		return pool[idx-1]; 
	};
};






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



class RefChain : public RefObject  {
    RefData** first;
	DataLinkPool<RefBracketBase*> brackets; // скобки для цепочки
	DataLinkPool<RefLinkToVariable*> vars ; // закрытые переменные
public:
    size_t leng;

    //RefData** after;

	inline RefData** get_first(){ return first+1; };
    inline RefData** get_last (){ return first+leng;	};

    RefChain();
    RefChain(RefData **a11, RefData **a12, RefData **a21, RefData **a22, RefData **a31, RefData **a32);
    virtual ~RefChain() {        free(first);    };

    // TODO: сделать блоковое расширение
    RefChain& operator+=(RefChain &ch);   // к левому аргумент пристыковывается копия правого!
    RefChain& operator+=(RefChain *ch);  // к левому аргумент пристыковывается копия правого!
	RefChain& operator+=(RefBracketBase  *br);
	RefChain& operator+=(RefVariableBase  *vr);
    RefChain& operator+=(RefData  *ch);  // рефдата ПОГЛАЩАЕТСЯ цепочкой!!!
    RefChain* Copy(Session *s =0);

    unistring toString();
    unistring explode(); // голый текст без форматирования

	RefVariableBase** getVarByName(unistring name){
		size_t ind = 1;
		RefVariableBase *var;
		while(ind <= leng){
			if ((var = ref_dynamic_cast<RefVariableBase>(first[ind])) && (var->getName()==name)) return (RefVariableBase**)(first+ind);
			++ind;
		}
		return 0;
	}
};

extern unistring getTextOfChain(RefData** from, RefData** to);


RefData** beginOfTerm(RefData** r);
RefData** endOfTerm  (RefData** r);

class RefBracketBase : public RefData {
public:
    BASE_CLASS_CAST(RefBracketBase);
	size_t opened_ind;
	size_t closed_ind;
	RefChain *chain;

	RefBracketBase (){opened_ind = closed_ind = SIZE_MAX; chain=0; }
	bool isOpen(RefData** p){
		#ifdef TESTCODE
		if (closed_ind-opened_ind <=0 || !chain || ((chain->get_first()+opened_ind)!= p && (chain->get_first()+closed_ind)!=p))SYSTEMERROR("brack-error");
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

};

class RefExecBracket : public RefBracketBase {
public:
    CLASS_OBJECT_CAST(RefExecBracket);
	bool       operator ==(RefData &rd){ SYSTEMERROR("unexpected"); };
    TResult init(RefData **&tpl, Session* s, RefData **&l, RefData **&r);
    TResult back(RefData **&tpl, Session* s, RefData **&l, RefData **&r);
	unistring explode(){ return "<br>"; };
};

class RefStructBracket : public RefBracketBase {
public:
    CLASS_OBJECT_CAST(RefStructBracket);
	bool       operator ==(RefData &rd){ SYSTEMERROR("unexpected"); };
    TResult init(RefData **&tpl, Session* s, RefData **&l, RefData **&r);
    TResult back(RefData **&tpl, Session* s, RefData **&l, RefData **&r);
	unistring explode(){ return "(br)"; };
};

class RefData_DOT : public RefBracketBase {
public:
	CLASS_OBJECT_CAST(RefData_DOT);
    bool operator ==(RefData &rd) { SYSTEMERROR("unexpected"); };
    TResult init(RefData **&tpl, Session* s, RefData **&l, RefData **&r);
    TResult back(RefData **&tpl, Session* s, RefData **&l, RefData **&r);
	unistring explode(){ return "[br]"; };
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
	RefLinkToVariable(unistring varName, RefChain *chain){lnk=*(chain->getVarByName(varName)); };
    //void forceback(RefData *&, Session *) {};
    virtual unistring getPath() { return EmptyUniString;  }; // для наследников класса - путь к подпеременной относитльно основной переменной
};
/*
// Ссылка на переменную (закрытая переменная)
class RefLinkToVariable : public RefData {
public:
    RefVariable *lnkData; // массив ссылок на переменную. (массив для цепочки вложений в шаблоны переменных. последний элемент \x0. При поиске значений итерация по подсессиям)
public:
    CLASS_OBJECT_CAST(RefLinkToVariable);
    RefLinkToVariable(unistring name);
    unistring toString();

    bool operator==(RefData&);
    virtual TResult init(RefData **&, Session* , RefData **&, RefData **&);
    virtual TResult back(RefData **&, Session* , RefData **&, RefData **&);
    virtual void forceback(RefData *&, Session *) {};
};
*/
#endif // REF_KERNEL_H_INCLUDED


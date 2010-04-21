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

#include <string>
#include <set>

#include "config.h"
#include "poolTuples.h"

class RefChain;
class RefDataBracket;
class RefProgram;
class VarMap;
class RefTemplateBase;
class RefVariable;
class RefLinkToVariable;



class RefObject {
public:
	inline RefObject(){
		co::objs++;
	};
	virtual unistring debug(){ return " $RefObject "; };
	virtual ~RefObject(){
		co::objs--;
	};
};


/*
	Элементы объектного выражения.

	Если конструктору не передается сессия, то сборщик мусора будет игнорировать
	  данный экземпляр. Такие элементы будем называть НЕколлекционируемыми.
	Деструктор элемента должен удалять все свои элементы, кроме коллекционируемых RefData.
	ЗАПРЕЩЕНО удалять коллекционируемые элементы не сборщиком мусора!
	*/
class RefData : public RefObject {
	friend class Session;

protected:
	inline void set_not_deleteble_by_gc_delete(){ gc_label |= 2; };

	char gc_label;//todo:bitmap
	RefData *gc_next;
	RefData() : RefObject(){ gc_next = 0; gc_label=0; co::datas++; }
	virtual ~RefData(){
		//std::cout << "\n~~~~DEL: " << co::datas << " " << this;
		co::datas--;
	}

public:
	RefData(Session *);
	virtual unistring explode() = 0;
	virtual TResult init(RefData **&activeTemplate, Session* sess, RefData **&currentRight, RefData **&currentLeft, RefChain *&ownerOfCurrentDot)=0; //  --> operator==() => [return GO] else [return BACK]
    virtual TResult back(RefData **&activeTemplate, Session* sess, RefData **&currentRight, RefData **&currentLeft, RefChain *&ownerOfCurrentDot)=0;

	virtual bool operator >(RefData &rd)  { RUNTIMEERRORn("Not comparable for" << explode() << " and " << rd.explode()); };
	virtual bool operator ==(RefData &rd) { notrealisedERRORn; };

	virtual unistring debug(){ return explode()+" "; };
	virtual unistring toString(){ return explode()+" "; };

	inline bool is_collected() { return (gc_label&4) != 0; } //   xxxxx0xx  -  НЕ коллекционируемый
	inline void set_collected(){ gc_label &= 4; } //   xxxxx1xx  -  коллекционируемый

	// xxxx0xxx  -  бит для использования наследниками RefData. Напр. RefChain

	inline void gc_delete()  { if (!is_collected() && !(gc_label&2)){ delete this; return; } }; // удалить если коллекционируемо и не не удаляемо
	//gc_label |= 2; // xxxxxx1x   -  для принудительного сохранения (ручная отметка)
	/*virtual*/inline void set_gc_mark(){ gc_label |= 1; };   // xxxxxxx1  -  для сохранения (gc отметка)
	inline bool is_gc_mark(){ return  (gc_label&3)!=0; };// xxxxxx10 xxxxxx01 xxxxxx11 - отмечено ли для сохранения
	inline void flush_gc_mark(){ gc_label &= 254; }; // xxxxxxx0 - удалить по gc

	const static  RefSymbolBitType bitRefSymbolBitType = bitNotSymbol;
	virtual RefDataBracket*  isDataBracket(){ return 0; };
	virtual RefSymbolBitType isRefSymbol(){ return bitNotSymbol; };

	virtual RefData* getNewInstance(Session* sess){ notrealisedERRORn; };

};

// отрезок
class RefSegment : public RefData {
public:
	RefChain *own;
	size_t from; // поскольку цепочки увеличиваются в конце, а не в начале, то можетм хранить отступы от начала
	size_t to;

	RefSegment(Session *s, RefChain *o, RefData **f, RefData **t);
	virtual ~RefSegment();
	virtual unistring explode(){ return "[segment]";};
	virtual TResult init(RefData **&activeTemplate, Session* sess, RefData **&currentRight, RefData **&currentLeft, RefChain *&ownerOfCurrentDot){unexpectedERRORn;};
	virtual TResult back(RefData **&activeTemplate, Session* sess, RefData **&currentRight, RefData **&currentLeft, RefChain *&ownerOfCurrentDot){unexpectedERRORn;};
};


class RefDataNull : public RefData {
	virtual unistring explode() { return "[RefDataNull]"; };
	virtual TResult init(RefData **&activeTemplate, Session* sess, RefData **&currentRight, RefData **&currentLeft, RefChain *&currentBorderOwn);
    virtual TResult back(RefData **&activeTemplate, Session* sess, RefData **&currentRight, RefData **&currentLeft, RefChain *&currentBorderOwn);
public:
	//RefDataNull();

};



// Предок всех открытых переменных языка (простых и скобочных)
class RefVariable : public RefData {
protected:
    unistring name;
public:
	inline RefVariable(unistring tname = EmptyUniString) : RefData(){ name=tname; co::vars++; };
	virtual ~RefVariable(){ co::vars--; }
    inline unistring getName() {        return name;    };
    inline void setName(unistring s) {        name = s;    };
};


class RefUserTemplate;

// usertype-переменная, группа
class RefVarChains : public RefVariable {
	friend class RefChain;

	unistring typeString;
	//RefTemplateBase *templInstant;
	RefUserTemplate *templInstant;
	RefChain *templ;
public:


	RefVarChains() : RefVariable() { templ=0; templInstant=0; };
	RefVarChains(unistring ntype, unistring nname) : RefVariable(nname) { typeString=ntype; templ=0; templInstant=0; };
	virtual ~RefVarChains();

	//////CLASS_OBJECT_CAST(RefVarChainsNotInit);

	inline void setTempl(RefChain *ntm){ templ = ntm; templInstant = 0; };
	inline void setUserType(RefUserTemplate *ntempli);
	inline RefUserTemplate *getUserType(){ return templInstant; };
	unistring getTypeString() {        return typeString;    };
	void setTypeString(unistring ntype) {      typeString = ntype;    };
	unistring explode();

	TResult init   (RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own);
    TResult back   (RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own);
	TResult success(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own);
	TResult failed (RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own);

};




// вариант
// TODO: совместить с RefVarChains
class RefVariantsChains : public RefVariable {
	friend class RefChain;

	PooledStack<RefChain *> templs;
public:
	RefVariantsChains(unistring tname = EmptyUniString) : RefVariable(tname) {};
	virtual ~RefVariantsChains();
	void addTempl(RefChain *ntm){ templs.put(ntm); };

	unistring explode();

	TResult init   (RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own);
    TResult back   (RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own);
	TResult success(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own);
	TResult failed (RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own);

};


// [ .. ]
class RefRepeaterChain : public RefData {
	friend class RefChain;

	RefChain *templ;

	infint min;
    infint max;
public:
	RefRepeaterChain(infint a, infint b) : RefData() { min=a; max=b; };
	virtual ~RefRepeaterChain();

	inline infint getMin(){ return min; };
	inline infint getMax(){ return max; };

	void setTempl(RefChain *ntm){ templ = ntm; };

	unistring explode();

	TResult init   (RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own);
    TResult back   (RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own);
	TResult success(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own);
	TResult failed (RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own);
};






class RefDataBracket : public RefData {
public:
	RefChain *chain;

	RefDataBracket(Session *sess, RefChain *thechain) : RefData(sess){
		++co::stbracks;
		chain = thechain;
	};
	virtual ~RefDataBracket();
	virtual unistring debug() = 0;

	virtual RefDataBracket* isDataBracket(){ return this; };
};


class RefStructBrackets : public RefDataBracket {
public:
	inline RefStructBrackets(Session* sess, RefChain* thechain) : RefDataBracket(sess, thechain){};
	virtual ~RefStructBrackets(){};
	unistring explode();
	unistring debug();
	unistring toString();

    TResult init(RefData **&, Session*, RefData **&, RefData **&, RefChain *&);
    TResult back(RefData **&, Session*, RefData **&, RefData **&, RefChain *&);

	virtual RefData* getNewInstance(Session* sess){ return new RefStructBrackets(sess, 0); };
};

class RefExecBrackets : public RefDataBracket {
public:
	inline RefExecBrackets(Session *sess, RefChain* thechain) : RefDataBracket(sess, thechain){};
	virtual ~RefExecBrackets(){};
	unistring explode();
	unistring debug();
	unistring toString();

    TResult init(RefData **&, Session*, RefData **&, RefData **&, RefChain *&);
    TResult back(RefData **&, Session*, RefData **&, RefData **&, RefChain *&);

	virtual RefData* getNewInstance(Session* sess){ return new RefExecBrackets(sess, 0); };

};



char* c_str(std::string str);

//class RefChain;
//static std::set<RefChain *> allchains;

/*
  Рефал-цепочка. Может только наращиваться справа. Не уменьшается.
  Для хранения ссылок на точки в цепочки использовать только индексы (size_t),
  так как из-за realloc ссылки могут изменяться.
*/
class RefChain : public RefData {
	friend bool eq(RefChain *, RefChain *);
	friend class Session;
	friend class RefProgram;

#ifdef TESTCODE
public:
#else
protected:
#endif

	RefData** first;
	size_t leng;
	size_t sysize;

	static size_t alloc_portion;
public:

	RefChain(Session *sess) : RefData(sess) { sysize=leng=0; first=0; co::chains++; };
	RefChain(Session *, RefData *);			// цпочка из одного терма
	RefChain(Session *, size_t systemsize);	// пустая цепочка для systemsize элементов
    RefChain(Session *, RefChain *ownchain, RefData **from, RefData **to); // цепочка из подцепочки
	RefChain(Session *sess, RefData** d, size_t sz) : RefData(sess){ 
		co::chains++; 
		sysize=leng=sz; 
		/* todo: оптимизировать. без копирования сделать		
		first=d; 
		gc_label|=0x08; 
		*/
		first = (RefData**)malloc(sizeof(RefData*) * sysize);
		if (!first) RUNTIMEERRORn("memory limit");
		memcpy(first, d, sizeof(RefData*)*sz);
	}
	virtual ~RefChain();
	inline bool isMemoryProtected(){ return (gc_label&0x08)!=0; };

	RefChain*  operator+=(RefData  *ch);
	RefChain*  operator+=(RefChain *ch); // удаляет *ch
	RefChain*  operator+=(RefChain  ch); // только копирует *ch
	inline RefData**  operator[](signed long idx){
		return leng? ((idx<0) ? first+leng+idx : first+idx) : 0;
	}
	inline RefData**  at(signed long idx){ return (*this)[idx]; };
	inline RefData**  at_first(){ return (*this)[0]; };
	inline RefData**  at_last(){ return (*this)[-1]; };
	inline RefData**  at_afterlast(){ return (*this)[-1]+1; };
	inline RefData**  at_beforefirst(){ return (*this)[0]-1; };

	inline bool isEmpty(){ return (leng==0); }
	inline size_t getLength(){ return leng; }

	unistring debug();
	unistring explode();
	unistring toString();

	void compile(RefChain *, RefProgram *);
	//void killall();     // удаление всех RefChain
	void killalldata(); // удаление всех RefChain и RefData

	TResult init   (RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own){ return ERROR; };
	TResult back   (RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own){ return ERROR; };

	//void *operator new(size_t size);
	//void operator delete(void *p);
};







class RefLinkToVariable : public RefData {
	friend class RefChain;
	friend class RefPointLink;
	friend class Session;
	RefVariable *lnk;
	unistring path;
public:
	RefLinkToVariable() : RefData(){};
	TResult init(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own);
    TResult back(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own);
	inline unistring explode(){ 
		/*if(
			lnk && lnk->getName()==""
			){
				std::cout << "";
		};*/
		return " @."+(lnk?lnk->getName():"$notinit$")+(path==EmptyUniString?"":"/"+path)+" "; 
	};

	inline RefLinkToVariable(RefVariable *ln){ lnk=ln; path=EmptyUniString; };
	inline RefLinkToVariable(unistring varName){
		path = varName;
		lnk=0;
	};
};


inline unistring chain_to_text(RefData** from, RefData** to, int showleng = 356){
	if (!from || !*from) return "#empty";
	if (!to || (to-from)<0) return "[error string]";
	unistring res = "";
	int i = 0;
	while(from+i <= to && (showleng<=0 || i<showleng)){
		if(from[i]) res += from[i]->debug();
		++i;
	}
	if (i==showleng) res += "... ";
	return res;
};



class RefMatchingCutter : public RefData {
public:
	RefMatchingCutter() : RefData(){};
	TResult init(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own);
    TResult back(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own);
	inline unistring explode(){ return " $cutter$ "; };
};



// указатель на ОВ пользовательского типа
class RefPoint : public RefData {
	RefPoint(){};

public:
	RefData **l, **r;      // тело ОВ
	RefChain *lr_own;
	RefTemplateBase* type; // тип тела ОВ
	VarMap *the_namespace; // результат сопоставления ОВ

	inline RefPoint(RefTemplateBase* thetype, RefData **ll, RefData **rr, RefChain *llrr_own, VarMap *tn, Session *sess) : RefData(sess){
		l=ll;r=rr;lr_own=llrr_own; type=thetype;the_namespace=tn; 
	};

	virtual unistring explode();
	virtual TResult init(RefData **&activeTemplate, Session* sess, RefData **&currentRight, RefData **&currentLeft, RefChain *&currentBorderOwn);
	virtual TResult back(RefData **&activeTemplate, Session* sess, RefData **&currentRight, RefData **&currentLeft, RefChain *&currentBorderOwn);

	void set_gc_mark(Session *sess); // если в RefData не virtual, то вызвать явно в Session::gc_exclude
	
};

// открытая переменная-указатель
class RefPointVariable : public RefData {
public:
	RefVariable* theVar;
	RefPointVariable(RefVariable* tV, Session *sess) : RefData(sess){ ref_assert(ref_dynamic_cast<RefVarChains>(tV) != 0); theVar = tV; };

	virtual unistring explode() { return "&[" + theVar->explode() + "]"; };
	virtual TResult init(RefData **&activeTemplate, Session* sess, RefData **&currentRight, RefData **&currentLeft, RefChain *&currentBorderOwn);
    virtual TResult back(RefData **&activeTemplate, Session* sess, RefData **&currentRight, RefData **&currentLeft, RefChain *&currentBorderOwn);
	virtual ~RefPointVariable(){ delete theVar; };};

// закрытая переменная-указатель
class RefPointLink : public RefData {
public:
	RefLinkToVariable* theLink;
	RefPointLink(RefLinkToVariable* tL, Session *sess) : RefData(sess){ theLink = tL; };

	virtual unistring explode();
	virtual TResult init(RefData **&activeTemplate, Session* sess, RefData **&currentRight, RefData **&currentLeft, RefChain *&currentBorderOwn);
    virtual TResult back(RefData **&activeTemplate, Session* sess, RefData **&currentRight, RefData **&currentLeft, RefChain *&currentBorderOwn);
	virtual ~RefPointLink(){ delete theLink; };
};




#endif

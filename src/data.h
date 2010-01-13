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
class RefProgram;
class VarMap;



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
private:
	char gc_label;//todo:bitmap
protected:
	RefData *gc_next;
	RefData() : RefObject(){ gc_next = 0; gc_label=0; co::datas++; }
	virtual ~RefData(){
		//std::cout << "\n~~~~DEL: " << co::datas << " " << this;
		co::datas--;
	}

public:
	RefData(Session *);
	virtual unistring explode() = 0;
    virtual TResult init(RefData **&activeTemplate, Session* s, RefData **&currentRight, RefData **&currentLeft)=0; //  --> operator==() => [return GO] else [return BACK]
    virtual TResult back(RefData **&activeTemplate, Session* s, RefData **&currentRight, RefData **&currentLeft)=0;

	virtual bool operator >(RefData &rd)  { RUNTIMEERRORn("Not comparable for" << explode() << " and " << rd.explode()); };
	virtual bool operator ==(RefData &rd) { notrealisedERRORn; };

	virtual unistring debug(){ return explode()+" "; };
	virtual unistring toString(){ return explode()+" "; };

	inline bool is_collected() { return (gc_label&4) != 0; } //   xxxxx0xx  -  НЕ коллекционируемый
	inline void set_collected(){ gc_label &= 4; } //   xxxxx1xx  -  коллекционируемый

	/*inline*/ void gc_delete()  {
		if (!is_collected()){
			delete this;
			return;
		}
		gc_label |= 2; // xxxxxx1x   -  для удаления (ручная отметка)
	};
	inline void set_gc_mark(){ gc_label |= 1; };   // xxxxxxx1  -  для удаления (gc отметка)
	inline bool is_gc_mark(){ return  (gc_label&3)!=0; };// xxxxxx10 xxxxxx01 xxxxxx11
	inline void flush_gc_mark(){ gc_label &= 254; }; // xxxxxxx0
};

class RefDataNull : public RefData {
	virtual unistring explode() { return "[RefDataNull]"; };
	virtual TResult init(RefData **&activeTemplate, Session* s, RefData **&currentRight, RefData **&currentLeft);
    virtual TResult back(RefData **&activeTemplate, Session* s, RefData **&currentRight, RefData **&currentLeft);
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

	unistring type;
	//RefTemplateBase *templInstant;
	RefUserTemplate *templInstant;
	RefChain *templ;
public:


	RefVarChains() : RefVariable() { templ=0; templInstant=0; };
	RefVarChains(unistring ntype, unistring nname) : RefVariable(nname) { type=ntype; templ=0; templInstant=0; };
	virtual ~RefVarChains();

	CLASS_OBJECT_CAST(RefVarChainsNotInit);

	void setTempl(RefChain *ntm){ templ = ntm; templInstant = 0; };
	void setTemplInstant(RefUserTemplate *ntempli);
    unistring getType() {        return type;    };
	void setType(unistring ntype) {      type = ntype;    };
	unistring explode();

	TResult init   (RefData **&tpl, Session* sess, RefData **&l, RefData **&r);
    TResult back   (RefData **&tpl, Session* sess, RefData **&l, RefData **&r);
	TResult success(RefData **&tpl, Session* sess, RefData **&l, RefData **&r);
	TResult failed (RefData **&tpl, Session* sess, RefData **&l, RefData **&r);

};




// выриант
// TODO: совместить с RefVarChains
class RefVariantsChains : public RefVariable {
	friend class RefChain;

	PooledStack<RefChain *> templs;
public:
	RefVariantsChains(unistring tname = EmptyUniString) : RefVariable(tname) {};
	virtual ~RefVariantsChains();
	void addTempl(RefChain *ntm){ templs.put(ntm); };

	unistring explode();

	TResult init   (RefData **&tpl, Session* sess, RefData **&l, RefData **&r);
    TResult back   (RefData **&tpl, Session* sess, RefData **&l, RefData **&r);
	TResult success(RefData **&tpl, Session* sess, RefData **&l, RefData **&r);
	TResult failed (RefData **&tpl, Session* sess, RefData **&l, RefData **&r);

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

	TResult init   (RefData **&tpl, Session* sess, RefData **&l, RefData **&r);
    TResult back   (RefData **&tpl, Session* sess, RefData **&l, RefData **&r);
	TResult success(RefData **&tpl, Session* sess, RefData **&l, RefData **&r);
	TResult failed (RefData **&tpl, Session* sess, RefData **&l, RefData **&r);
};






class RefDataBracket : public RefData {
public:
	RefChain *chain;

	RefDataBracket(Session *s, RefChain *thechain) : RefData(s){
		++co::stbracks;
		chain = thechain;
	};
	virtual ~RefDataBracket();
	virtual unistring debug() = 0;
};


class RefStructBrackets : public RefDataBracket {
public:
	inline RefStructBrackets(Session* s, RefChain* thechain) : RefDataBracket(s, thechain){};
	virtual ~RefStructBrackets(){};
	unistring explode();
	unistring debug();

    TResult init(RefData **&, Session*, RefData **&, RefData **&);
    TResult back(RefData **&, Session*, RefData **&, RefData **&);
};

class RefExecBrackets : public RefDataBracket {
public:
	inline RefExecBrackets(Session *s, RefChain* thechain) : RefDataBracket(s, thechain){};
	virtual ~RefExecBrackets(){};
	unistring explode();
	unistring debug();

    TResult init(RefData **&, Session*, RefData **&, RefData **&);
    TResult back(RefData **&, Session*, RefData **&, RefData **&);
};



char* c_str(std::string str);

//class RefChain;
//static std::set<RefChain *> allchains;

class RefChain : public RefData {
	friend bool eq(RefChain *, RefChain *);
	friend class Session;


	RefData** first;
	size_t leng;
	size_t sysize;

	static size_t alloc_portion;
public:

	RefChain(Session *s) : RefData(s) { sysize=leng=0; first=0; co::chains++; };
	RefChain(Session *s, RefData *);			// цпочка из одного терма
	RefChain(Session *s, size_t systemsize);	// пустая цепочка для systemsize элементов
	virtual ~RefChain();

	RefChain*  operator+=(RefData  *ch);
	RefChain*  operator+=(RefChain *ch); // удаляет *ch
	RefChain*  operator+=(RefChain  ch); // только копирует *ch
	RefData**  operator[](signed long idx);
	inline RefData**  at(signed long idx){ return (*this)[idx]; };
	inline RefData**  at_first(){ return (*this)[0]; };
	inline RefData**  at_last(){ return (*this)[-1]; };
	inline RefData**  at_afterlast(){ return (*this)[-1]+1; };

	inline bool isEmpty(){ return (leng==0); }
	inline size_t getLength(){ return leng; }

	unistring debug();
	unistring explode();

	void compile(RefChain *, RefProgram *);
	//void killall();     // удаление всех RefChain
	void killalldata(); // удаление всех RefChain и RefData

	TResult init   (RefData **&tpl, Session* sess, RefData **&l, RefData **&r){ return ERROR; };
	TResult back   (RefData **&tpl, Session* sess, RefData **&l, RefData **&r){ return ERROR; };
};







class RefLinkToVariable : public RefData {
	friend class RefChain;
	friend class Session;
	RefVariable *lnk;
	unistring path;
public:
	RefLinkToVariable() : RefData(){};
	TResult init(RefData **&tpl, Session* s, RefData **&l, RefData **&r);
    TResult back(RefData **&tpl, Session* s, RefData **&l, RefData **&r);
	inline unistring explode(){ return " @."+(lnk?lnk->getName():"$notinit$"+path)+" "; };

	inline RefLinkToVariable(RefVariable *ln){lnk=ln; path=EmptyUniString; };
	inline RefLinkToVariable(unistring varName){
		path = varName;
		lnk=0;
	};
};


inline unistring chain_to_text(RefData** from, RefData** to, int showleng = 356){
	if (!from || !*from) return "[null]";
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
	TResult init(RefData **&tpl, Session* s, RefData **&l, RefData **&r);
    TResult back(RefData **&tpl, Session* s, RefData **&l, RefData **&r);
	inline unistring explode(){ return " $cutter$ "; };
};






#endif

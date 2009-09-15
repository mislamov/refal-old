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

#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

#include <list>

#include "data.h"

class RefSentence;

// рефал-функция
class RefFunctionBase : public RefObject {
protected:
	virtual unistring getName() = 0;
public:
	virtual void initilizeAll(RefProgram* program){};
	virtual RefChain* eval(RefData**, RefData**, Session*) = 0;
	virtual unistring debug() = 0;

};

class RefBuildInFunction : public RefFunctionBase {
public:
	unistring debug(){ return "Function " + getName(); };
};

class RefUserFunction : public RefFunctionBase {
	unistring name;
public:
    std::list<RefSentence *> body; // предложения

	inline RefUserFunction(unistring tname){		name = tname;	}
	unistring getName() { return name; };
	unistring debug();

	void initilizeAll(RefProgram *);
	RefChain* eval(RefData**, RefData**, Session*);
};



// локальное условие (ограничение на переменную)
class RefTemplateBase : public RefObject {
public:
	virtual void initilizeAll(RefProgram *) = 0;
	virtual unistring debug() =0;
	virtual unistring getName() =0;
	
};

// пользовательский шаблон
class RefUserTemplate : public RefTemplateBase {
	unistring name;
	RefChain *leftPart;
public:
	inline RefUserTemplate(unistring tname){ name = tname; }
	unistring getName() { return name; };
	inline void setLeftPart (RefChain *lp){ leftPart  = lp; };
	inline RefChain* getLeftPart(){ return leftPart; };
	
	void initilizeAll(RefProgram *);
	unistring debug(){
		return "Template " + getName() + "  ::=  " + leftPart->debug();
	}
};

// предложение
class RefSentence : public RefObject {
public:
	RefChain *leftPart;
	RefChainConstructor *rightPart;
};

// глобальное условие для сопоставления
class RefConditionBase : public RefData {
};

class RefUserCondition : public RefConditionBase {
	bool withnot;
	RefChain *leftPart;
	RefChainConstructor *rightPart;
public:
	RefObject *own;

	inline RefUserCondition(bool withNOT){ withnot = withNOT; };
	inline void setLeftPart(RefChain *ch){ leftPart = ch; };
	inline void setRightPart(RefChain *ch){ 
		#ifdef TESTCODE
		if (! dynamic_cast<RefChainConstructor*>(ch)) SYSTEMERROR("RefChainConstructor expected!");
		#endif
		rightPart = (RefChainConstructor*)ch; 
	};
	inline RefChain *getLeftPart(){ return leftPart; };
	inline RefChainConstructor *getRightPart(){ return rightPart; };

	unistring explode(){ return " , $UserCondition[ " + rightPart->explode() + " ::: " + leftPart->explode() + " ]"; };
	TResult init(RefData **&, Session*, RefData **&, RefData **&);
	TResult back(RefData **&, Session*, RefData **&, RefData **&);

};



















#endif

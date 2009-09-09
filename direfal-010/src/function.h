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
	virtual unistring getName() = 0;
};

class RefBuildInFunction : public RefFunctionBase {
};

class RefUserFunction : public RefFunctionBase {
	unistring name;
public:
    std::list<RefSentence *> body; // предложения

	inline RefUserFunction(unistring tname){		name = tname;	}
	unistring getName() { return name; };


};

// локальное условие (для переменной)
class RefTemplateBase : public RefObject {
};

class RefUserTemplate : public RefTemplateBase {
	unistring name;
	RefChain *leftPart;
	RefChain *rightPart;
public:
	inline RefUserTemplate(unistring tname){ name = tname; }
	unistring getName() { return name; };
	inline void setLeftPart (RefChain *lp){ leftPart  = lp; };
	inline void setRightPart(RefChain *rp){ rightPart = rp; };
	
};

// предложение
class RefSentence : public RefObject {
public:
	RefChain *leftPart;
	RefChain *rightPart;
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

	unistring explode(){ return "@RefUserCondition( " + rightPart->explode() + " ~ " + leftPart->explode() + " )"; };
	TResult init(RefData **&, Session*, RefData **&, RefData **&){ AchtungERROR; };
	TResult back(RefData **&, Session*, RefData **&, RefData **&){ AchtungERROR; };

};



// класс - непроинициализированная переменная внешнего типа. После инициализации заменяется на пару {RefTemplateBridgeVar RefTemplateBridgeVar}
class RefUserVarNotInit : public RefVariable, public NeedInitilize {
    unistring type;
	RefTemplateBase *templ;
public:
	RefUserVarNotInit(){};
	RefUserVarNotInit(RefTemplateBase *ntempl, unistring ntype, unistring nname){ type=ntype; name=nname; ntempl=templ; };
    CLASS_OBJECT_CAST(RefUserVarNotInit);
    bool initize(Session *){SYSTEMERROR("unexpected");}; // замещается на пару
    void setType(unistring ttype) {        type = ttype;    };
    unistring getType() {        return type;    };
    unistring explode() {        return "@RefUserVarNotInit.toString()";    }
    bool operator ==(RefData &rd) {        return false;    };
	TResult init(RefData **&tpl, Session* s, RefData **&l, RefData **&r){SYSTEMERROR("unexpected");};
    TResult back(RefData **&tpl, Session* s, RefData **&l, RefData **&r){SYSTEMERROR("unexpected");};
    ~RefUserVarNotInit() {    };
};

















#endif

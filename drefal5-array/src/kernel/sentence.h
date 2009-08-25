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

#ifndef REFFUNCTION_H_INCLUDED
#define REFFUNCTION_H_INCLUDED

#include <iostream>
#include <sstream>
#include <list>
#include <stack>

#include "data.h"

class RefUserFunction;


class RefSentence;
class NeedInitilize;
class RefUserVarNotInit;
class RefConditionBase;
class RefCondition;
class RefMatchingCutter;
class RefTemplateBase;
class RefUserTemplate;
class RefTemplateBridgeTmpl;


class RefSentence : public RefObject {
public:
    RefChain *leftPart;
    ChainSubstitution *rightPart;

    unistring explode(){SYSTEMERROR("unrelised");};

	RefSentence(){ leftPart = rightPart = 0; };
	RefSentence(RefChain* l, ChainSubstitution *r){SYSTEMERROR("unrelised");};
    virtual ~RefSentence() {};
};




// интерфейс для элементов, которые необходимо проинициализировать после загрузки модуля
class NeedInitilize {
public:
    virtual bool initize(Session *) = 0;
};

// класс - непроинициализированная переменная внешнего типа. После инициализации заменяется на пару {RefTemplateBridgeVar RefTemplateBridgeVar}
class RefUserVarNotInit : public RefVariable, public NeedInitilize {
    unistring type;
	RefTemplateBase *templ;
public:
	RefUserVarNotInit();
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






////  рефал-условие. базовый класс
class RefConditionBase : public RefData {
public:
    BASE_CLASS_CAST(RefConditionBase);

    RefConditionBase() : RefData() {};
    ~RefConditionBase() {};
    //void forceback(Session *) {
    //    SYSTEMERROR("RefConditionBase.forceback NOT DEFINE");
    //};

};

////  Рефал-условие пользовтаельское
class RefCondition : public RefConditionBase {
    RefChain *rightPart;
    RefChain *leftPart;
    bool isReverse; // признак условия $NOT
public:
    CLASS_OBJECT_CAST(RefCondition);
    RefObject *own;  // RefCondition or RefFunctionBase

    void setRightPart(RefChain *rp) {        rightPart = rp;    }
    void setLeftPart(RefChain *lp)  {        leftPart  = lp;    }

	virtual bool operator ==(RefData &rd) {    SYSTEMERROR("unexpected");    };
    TResult init(RefData **&tpl, Session* s, RefData **&l, RefData **&r){SYSTEMERROR("unrelised");};
    TResult back(RefData **&tpl, Session* s, RefData **&l, RefData **&r){SYSTEMERROR("unrelised");};

	RefCondition(bool withnot) : RefConditionBase() {
        isReverse = withnot;
        rightPart = leftPart = 0;
    }

    virtual ~RefCondition() {};
	unistring explode(){ SYSTEMERROR("alarm"); };
    unistring toString() ;
    RefData* Copy(RefData *where=0) {
        SYSTEMERROR("unexpected try to Copy REF-condition");
        return 0;
    };
};



/* отсечение шаблона. его откат приводит к откату всего субмачинга */
class RefMatchingCutter : public RefData {
public:
    CLASS_OBJECT_CAST(RefMatchingCutter);

    RefMatchingCutter() : RefData() {
    }
    TResult init(RefData **&tpl, Session* s, RefData **&l, RefData **&r){SYSTEMERROR("unrelised");};
    TResult back(RefData **&tpl, Session* s, RefData **&l, RefData **&r){SYSTEMERROR("unrelised");};

    unistring toString() {        return " $CUTTER$ ";    }
	unistring explode()  {        SYSTEMERROR("unexpected");    }
    virtual bool operator ==(RefData &rd) {        SYSTEMERROR("alarm");    };
    //virtual void    forceback(RefData *&a, Session* s) {};
};



// абстрактный класс для всех сложных шаблонов

class RefTemplateBridgeTmpl;

/**
// мосты между лев.частью и внешним шаблоном. Со стороны левой части
class RefTemplateBridgeVar : public RefBracketBase  {
    unistring name;
public:
    CLASS_OBJECT_CAST(RefTemplateBridgeVar);

    virtual bool IRefVarStacked() {
        return true;
    };

    RefTemplateBridgeTmpl* bridge; // указатель на соединяющий мост тела шаблона. Присвоить до сопоставления - при инициализации загруженного модуля

RefTemplateBridgeVar () {
        bridge=0;
        name="NOT SET";
    };
    unistring toString() {
        if (is_opened) return ("[{]." + getName());
        else return  name+".[}]";
    };

    TResult init(RefData **&tpl, Session* s, RefData **&l, RefData **&r);
    TResult back(RefData **&tpl, Session* s, RefData **&l, RefData **&r);

    unistring getName() {
        if (is_opened)
            return ((RefTemplateBridgeVar*) other)->name;
        return name;
    }
    void setName(unistring nname) {
        name = nname;
    }
//
//    RefData* Copy(RefBracketBase *bb, RefData *rp=0) {
//        RefTemplateBridgeVar *b = (RefTemplateBridgeVar *)(bb);
//        #ifdef TESTCODE
//        b = ref_dynamic_cast<RefTemplateBridgeVar >(bb);
//        if (!b) SYSTEMERROR("not RefTemplateBridgeVar !");
//        #endif
//        RefTemplateBridgeVar *cp = new RefTemplateBridgeVar(b, rp);
//        cp->setName(this->getName());
//        RUNTIMEERROR("RefTemplateBridgeVar::Copy", "zaglushka!");
//        /// ??? нужно ли копировать тело сопоставления с таблицей переменных
//        return cp;
//    };
//
//    RefData* Copy(RefData *rp=0) {
//        RefTemplateBridgeVar *cp = new RefTemplateBridgeVar(rp);
//        cp->setName(this->getName());
//        RUNTIMEERROR("RefTemplateBridgeVar::Copy", "zaglushka!");
//        /// ??? нужно ли копировать тело сопоставления с таблицей переменных
//        return cp;
//    };

    virtual void    forceback(RefData *&a, Session* s);

};

// мосты между лев.частью и внешним шаблоном. Со стороны внешнего шаблона
class RefTemplateBridgeTmpl : public RefBracketBase {
public:
    CLASS_OBJECT_CAST(RefTemplateBridgeTmpl);

    virtual bool IRefVarStacked() {
        return true;
    };

RefTemplateBridgeTmpl () : RefBracketBase() { };
RefTemplateBridgeTmpl (RefTemplateBridgeTmpl *nd) : RefBracketBase(nd) { };
    unistring toString() {
        if (is_opened) return "{[}";
        else return "{]}";
    };

    TResult init(RefData **&tpl, Session* s, RefData **&l, RefData **&r);
    TResult back(RefData **&tpl, Session* s, RefData **&l, RefData **&r);

    RefData* Copy(RefBracketBase *b, RefData *rp=0) {
        SYSTEMERROR("взятие копии внешнего шаблона не предусмотрено! наверное ошибка");
    };
    RefData* Copy(RefData *rp=0) {
        SYSTEMERROR("взятие копии внешнего шаблона не предусмотрено! наверное ошибка");
    };

    unistring getName() {
        SYSTEMERROR("unexpected call");
    };
    virtual void    forceback(Session* s) {};

};
*/




#endif // FUNCTION_H_INCLUDED

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
//#include "program.h"
//#include "../refal.h"
//#include "../modules/system.h"

class RefSentence : public RefObject {
public:

    RefChain *leftPart;
    ChainSubstitution *rightPart;
    unistring explode(){SYSTEMERROR("unrelised");};

    RefSentence(){SYSTEMERROR("unrelised");};
    RefSentence(RefChain* l, RefChain *r){SYSTEMERROR("unrelised");};
    virtual ~RefSentence() {};
};


/* функции - не слабое место в производительности. Поэтому разумно использовать виртуальную таблицу */
class RefFunctionBase : public RefObject {
    unistring name;
public:
    CLASS_CAST(UseRTTI);

	RefFunctionBase(){};
	virtual ~RefFunctionBase(){};
    virtual unistring getName() = 0;
    virtual RefChain *eval(RefData**, RefData**, Session*)=0;
};

class RefUserFunction : public RefFunctionBase {
    unistring name;
public:
    std::list<RefSentence *> body; // предложения

    /// аргументы - концы чистого ОВ   // заменяет в объектном выражении участок(перед. в аргум)
	RefChain *eval(RefData **, RefData **, Session *s){SYSTEMERROR("urealised");}; // - перенесено в session
    unistring getName()  { return name; };
	unistring explode(){SYSTEMERROR("unrelised");};
    RefUserFunction(unistring nname) {
        name = nname;
    }
    virtual ~RefUserFunction() {};
};


class RefModuleBase : public RefObject {
protected:
    unistring name;
public:
    virtual unistring getName() {        return name;    }
    virtual void setName(unistring s) {        name = s;    }

    RefModuleBase(unistring nname = EmptyUniString) {        setName(nname);    };
    virtual ~RefModuleBase() {};
    virtual RefObject* getObjectByName(unistring name, Session *s=0)=0;
    virtual void initilizeAll(Session *) {        LOG("not realized!");    };
	// создает RefData-символ по rsl-коду code и со значением value (текстовое представление)
/*
	virtual RefData* createSymbolByCode(unistring code, unistring value){
		// TODO: поиск по себе и включенным модулям (а если "свое" описание загружается ПОСЛЕ использования внутри себя? а во включенных определено?)
		extern mSYSTEM msystem;
		return msystem.dataConstructors[code](value);
	};
*/
};



// интерфейс для элементов, которые необходимо проинициализировать после загрузки модуля
class NeedInitilize {
public:
    virtual bool initize(Session *) = 0;
};

// класс - непроинициализированная переменная внешнего типа. После инициализации заменяется на пару {RefTemplateBridgeVar RefTemplateBridgeVar}
class RefUserVarNotInit : public RefVariable, public NeedInitilize {
    unistring type;
public:
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


class RefProgram;

// пользовательские модули могут быть только частью программы (совокупность модулей и зависимостей между ними)
class RefUserModule : public RefModuleBase {
public:
    std::map<unistring, RefObject*> objects;
    unistring getName() {
        return name;
    };

    RefUserModule(RefProgram* p);
    virtual ~RefUserModule() {};

    unistring explode(){SYSTEMERROR("unrelised");};
    RefObject* getObjectByName(unistring name, Session *s=0){SYSTEMERROR("unrelised");};

    std::stack<NeedInitilize *> initItems; // стек ссылок на неинициализированные данные (внешние переменные)
    void initilizeAll(Session *){SYSTEMERROR("unrelised");};
    /*  void print_inf(){
            std::cout << this->toString();
        }
    */
};


class RefDllModule : public RefModuleBase {
    std::map<unistring, RefObject*> objects;
public:
	RefDllModule(){};
	virtual ~RefDllModule(){};
	RefObject* getObjectByName(unistring nm, Session *s=0){SYSTEMERROR("unrelised");};
    void setObjectByName(unistring name, RefObject* o){SYSTEMERROR("unrelised");};
    unistring toString(){SYSTEMERROR("unrelised");};
};



class RefBuildInFunction : public RefFunctionBase {
public:
    RefBuildInFunction(unistring name, RefDllModule *m){SYSTEMERROR("unrelised");};
    virtual ~RefBuildInFunction() {};
    RefChain *eval(RefData**, RefData**, Session*){ SYSTEMERROR("not realised!"); };

};




class RefConditionBase : public RefData {
public:
    BASE_CLASS_CAST(RefConditionBase);

    RefConditionBase() : RefData() {};
    ~RefConditionBase() {};
    void forceback(Session *) {
        SYSTEMERROR("RefConditionBase.forceback NOT DEFINE");
    };

};

class RefCondition : public RefConditionBase {
    RefChain *rightPart;
    RefChain *leftPart;
    bool isReverse; // признак условия $NOT
public:
    CLASS_OBJECT_CAST(RefCondition);
    RefObject *own;  // RefCondition or RefFunctionBase

    void setRightPart(RefChain *rp) {
        rightPart = rp;
    }
    void setLeftPart(RefChain *lp) {
        leftPart  = lp;
    }

    virtual bool operator ==(RefData &rd) {
        return false;
    };
    TResult init(RefData **&tpl, Session* s, RefData **&l, RefData **&r){SYSTEMERROR("unrelised");};
    TResult back(RefData **&tpl, Session* s, RefData **&l, RefData **&r){SYSTEMERROR("unrelised");};

    RefCondition(bool withnot) : RefConditionBase() {
        isReverse = withnot;
        rightPart = leftPart = 0;
    }

    virtual ~RefCondition() {};
	unistring explode(){ SYSTEMERROR("alarm"); };
    unistring toString() {
        std::ostringstream s;
        s << " @Condition/" << (isReverse?"$not$":"") <<  (ref_dynamic_cast<RefUserFunction>(own)?"F":"T") << "$" << rightPart->toString() << "::" << leftPart->toString() << ' ';
        return s.str();
    }
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
class RefTemplateBase : public RefModuleBase {
public:
    BASE_CLASS_CAST(RefTemplateBase);

    RefTemplateBase (unistring name){SYSTEMERROR("unrelised");};
    virtual ~RefTemplateBase () {};
	RefTemplateBase () {SYSTEMERROR("unrelised");};
};

// пользовательский шаблон
class RefUserTemplate : public RefTemplateBase {
    RefChain *leftPart;
public:
    CLASS_OBJECT_CAST(RefUserTemplate);

    RefUserTemplate(unistring name){SYSTEMERROR("unrelised");};
    inline RefChain* getLeftPart() {        return leftPart;    };
    void setLeftPart(RefChain *){SYSTEMERROR("unrelised");};
    RefObject* getObjectByName(unistring name, Session *s) {        SYSTEMERROR("--== ZAGLUSHKA ==--");    };
    unistring explode() {        return (getName()+"$RefUserTemplate_::=_"+(leftPart?leftPart->toString():"$void"));    }
    virtual ~RefUserTemplate() {};
    RefUserTemplate(){SYSTEMERROR("unrelised");};
};

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



// программа. содержит подключенные модули и поддерживает различные операции по ним
class RefProgram {
public:
	// TODO: сделать список пар для приоритетности.
	std::map<unistring, RefModuleBase*> modules;
	RefProgram(){};

	void regModule(RefModuleBase *module){ // регистрация модуля в программе (перед загрузкой)
		if (module->getName() == EmptyUniString) SYSTEMERROR("Empty module name");
		if (modules.find(module->getName()) == modules.end()) SYSTEMERROR("Several loads of module [" << module->getName() << "] ");
		modules[module->getName()] = module;
	};

	RefData* createSymbolByCode(unistring code, unistring value){
		SYSTEMERROR("zaglushka");
	};
	RefVariable* createVariableByTypename(unistring code, unistring value){
		SYSTEMERROR("zaglushka");
	};
};

#endif // FUNCTION_H_INCLUDED

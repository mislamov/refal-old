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

#include <iostream.h>
#include <sstream>
#include <list>

#include "core.h"
#include "data.h"
#include "datastructs.h"
#include "session.h"


class RefSentence : public RefObject {
public:
    unistring sss;

    RefChain *leftPart;
    RefChain *rightPart;
    virtual unistring toString();

    RefSentence();
    RefSentence(RefChain* l, RefChain *r);
    virtual ~RefSentence(){};
};


class RefFunctionBase : public RefObject {
    unistring name;
public:
    RefFunctionBase();
    virtual ~RefFunctionBase();
    virtual unistring getName() = 0;
    virtual bool execute(RefData*, RefData*, Session*)=0;
};

class RefUserFunction : public RefFunctionBase {
    unistring name;
public:
    std::list<RefSentence *> body; // предложения

    /// аргументы - концы чистого ОВ   // заменяет в объектном выражении участок(перед. в аргум)
    virtual bool execute(RefData *argfirst, RefData *argsecond, Session *s);
    virtual unistring getName()  { return name; };
    virtual unistring toString();
    RefUserFunction(unistring nname){ name = nname; }
    virtual ~RefUserFunction(){};
};


class RefModuleBase : public RefalNameSpace, public RefObject {
  public:
    virtual unistring getName()=0;
    //{ return name; };
    //virtual void setName(unistring s){ name = s; };

    RefModuleBase(unistring nname = EmptyUniString) : RefalNameSpace(nname) {};
    virtual ~RefModuleBase(){};
    virtual RefObject* getObjectByName(unistring name, Session *s=0)=0;
    virtual void initilizeAll(Session *){ LOG("not realized!"); };
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
        bool initize(Session *); // замещается на пару
        void setType(unistring ttype){ type = ttype; };
        unistring getType(){ return type; };

        unistring toString() { return "@RefUserVarNotInit.toString()"; }
        bool operator ==(RefData &rd) { return false; };
        TResult init(Session*, RefData *&);
        TResult back(Session*, RefData *&, RefData *&);
        RefData*  Copy(RefData* where=0){ return 0; };

        ~RefUserVarNotInit(){
        };
};


class RefUserModule : public RefModuleBase {
public:
    std::map<unistring, RefObject*> objects;
    unistring getName(){ return name; };

    RefUserModule() : RefModuleBase(){}
    virtual ~RefUserModule(){};

    unistring toString();
    RefObject* getObjectByName(unistring name, Session *s=0);

    std::stack<NeedInitilize *> initItems; // стек ссылок на неинициализированные данные (внешние переменные)
    void initilizeAll(Session *);
/*  void print_inf(){
        std::cout << this->toString();
    }
*/
};


class RefDllModule : public RefModuleBase {
    std::map<unistring, RefObject*> objects;
public:
    RefDllModule();
    virtual ~RefDllModule();
    RefObject* getObjectByName(unistring nm, Session *s=0);
    void setObjectByName(unistring name, RefObject* o);
    unistring toString();
};



class RefBuildInFunction : public RefFunctionBase {
    bool execute(RefData*, RefData*, Session*);
public:
    RefBuildInFunction(unistring name, RefDllModule *m);
    virtual ~RefBuildInFunction(){};
    virtual bool eval(RefData* lft, RefData* rht, RefChain* &result, Session* s=0) = 0;

};


class RefConditionBase : public RefData {
public:
    RefConditionBase(RefData *r=0) : RefData(r){};
    ~RefConditionBase(){};
    void forceback(Session *){ SYSTEMERROR("RefConditionBase.forceback NOT DEFINE"); };

};

class RefCondition : public RefConditionBase {
        RefChain *rightPart;
        RefChain *leftPart;
        bool isReverse; // признак условия $NOT
    public:
        RefObject *own;  // RefCondition or RefFunctionBase

        void setRightPart(RefChain *rp){ rightPart = rp; }
        void setLeftPart(RefChain *lp) { leftPart  = lp; }

        virtual bool operator ==(RefData &rd){return false; };
        virtual TResult  init(Session* , RefData *&); //
        virtual TResult  back(Session* , RefData *&, RefData *&); //

        RefCondition(bool withnot, RefData *r=0) : RefConditionBase(r){ isReverse = withnot; rightPart = leftPart = 0; is_system = false; }
        //RefCondition(RefObject *owner, RefData *r=0) : RefConditionBase(r){ rightPart = leftPart = 0; is_system = false; own = owner; }
        virtual ~RefCondition(){};
        unistring toString(){
            std::ostringstream s;
            s << " @Condition/" << (isReverse?"$not$":"") <<  (dynamic_cast<RefUserFunction *>(own)?"F":"T") << "$" << rightPart->toString() << "::" << leftPart->toString() << ' ';
            return s.str();
        }
        RefData* Copy(RefData *where=0){ SYSTEMERROR("unexpected try to Copy REF-condition"); return 0; };



};

/* отсечение шаблона. его откат приводит к откату всего субмачинга */
class RefMatchingCutter : public RefData {
    public:
        RefMatchingCutter(RefData *d=0) : RefData(d){ is_system = false; }
        virtual TResult  init(Session* , RefData *&){ return GO; }
        virtual TResult  back(Session* , RefData *&, RefData *&){ return FORCEBACK; }

        virtual unistring toString() { return " $CUTTER$ "; }
        RefData* Copy(RefData *rp=0){
            return new RefMatchingCutter(rp);
        }
        virtual bool operator ==(RefData &rd){ SYSTEMERROR("alarm"); };
        virtual void    forceback(Session* s){};


};

// абстрактный класс для всех сложных шаблонов
class RefTemplateBase : public RefModuleBase {
public:
    RefTemplateBase (unistring name);
    virtual ~RefTemplateBase (){};
};

// пользовательский шаблон
class RefUserTemplate : public RefTemplateBase {
        RefChain *leftPart;
    public:
        inline unistring getName(){ return name; };
        RefUserTemplate(unistring name, RefChain *lp=0);
        inline RefChain* getLeftPart(){ return leftPart;};
        void setLeftPart(RefChain *);
        RefObject* getObjectByName(unistring name, Session *s){ SYSTEMERROR("--== ZAGLUSHKA ==--"); };
        unistring toString(){
            return (getName()+"$RefUserTemplate_::=_"+(leftPart?leftPart->toString():"$void"));
        }
        virtual ~RefUserTemplate(){};
};

class RefTemplateBridgeTmpl;


// мосты между лев.частью и внешним шаблоном. Со стороны левой части
class RefTemplateBridgeVar : public IRefVarStacked, public RefBracketBase  {
        unistring name;
    public:
        RefTemplateBridgeTmpl* bridge; // указатель на соединяющий мост тела шаблона. Присвоить до сопоставления - при инициализации загруженного модуля

        RefTemplateBridgeVar (RefData *d=0) : RefBracketBase(d){ bridge=0; name="NOT SET";};
        RefTemplateBridgeVar(RefTemplateBridgeVar *nd, RefData* rp = 0) : RefBracketBase(nd, rp){ bridge=0;  name="NOT SET";};
        unistring toString() { if (isOpen()) return sss = ("[{]." + getName()); else return sss =  name+".[}]"; };

        TResult init(Session* s, RefData *&currentPoint);
        TResult back(Session* s, RefData *&currentRight, RefData *&currentLeft);
        RefData*  next_point( ThisId var_id, Session *s);
        RefData*  pred_point( ThisId var_id, Session *s);

        unistring getName(){
            if (isOpen())
                return ((RefTemplateBridgeVar*) other)->name;
            return name;
        }
        void setName(unistring nname){ name = nname; }

        RefData* Copy(RefBracketBase *bb, RefData *rp=0){
            RefTemplateBridgeVar *b = (RefTemplateBridgeVar *)(bb);
            #ifdef DEBUG
            b = dynamic_cast<RefTemplateBridgeVar *>(bb);
            if (!b) SYSTEMERROR("not RefTemplateBridgeVar !");
            #endif
            RefTemplateBridgeVar *cp = new RefTemplateBridgeVar(b, rp);
            cp->setName(this->getName());
            RUNTIMEERROR("RefTemplateBridgeVar::Copy", "zaglushka!");
            /// ??? нужно ли копировать тело сопоставления с таблицей переменных
            return cp;
        };

        RefData* Copy(RefData *rp=0){
            RefTemplateBridgeVar *cp = new RefTemplateBridgeVar(rp);
            cp->setName(this->getName());
            RUNTIMEERROR("RefTemplateBridgeVar::Copy", "zaglushka!");
            /// ??? нужно ли копировать тело сопоставления с таблицей переменных
            return cp;
        };

        virtual void    forceback(Session* s){};

};

// мосты между лев.частью и внешним шаблоном. Со стороны внешнего шаблона
class RefTemplateBridgeTmpl : public RefBracketBase, public IRefVarStacked {
    public:
        RefTemplateBridgeTmpl (RefData *d=0) : RefBracketBase(d){ };
        RefTemplateBridgeTmpl (RefTemplateBridgeTmpl *nd, RefData* rp = 0) : RefBracketBase(nd, rp){ };
        unistring toString() { if (isOpen()) return sss = "{[}"; else return sss = "{]}"; };

        TResult init(Session* s, RefData *&currentPoint);
        TResult back(Session* s, RefData *&currentRight, RefData *&currentLeft);
        RefData*  next_point( ThisId var_id, Session *s);
        RefData*  pred_point( ThisId var_id, Session *s);

        RefData* Copy(RefBracketBase *b, RefData *rp=0){
            SYSTEMERROR("взятие копии внешнего шаблона не предусмотрено! наверное ошибка");
        };
        RefData* Copy(RefData *rp=0){
            SYSTEMERROR("взятие копии внешнего шаблона не предусмотрено! наверное ошибка");
        };

        unistring getName(){ SYSTEMERROR("unexpected call"); };
        virtual void    forceback(Session* s){};

};

#endif // FUNCTION_H_INCLUDED

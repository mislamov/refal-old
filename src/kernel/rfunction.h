#ifndef REFFUNCTION_H_INCLUDED
#define REFFUNCTION_H_INCLUDED

#include <iostream.h>
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
};


class RefFunctionBase : public RefObject {
    unistring name;
public:
    RefFunctionBase();
    ~RefFunctionBase();
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
};


class RefModuleBase : public RefalNameSpace {
  public:
    virtual unistring getName()=0;
    //{ return name; };
    //virtual void setName(unistring s){ name = s; };

    RefModuleBase(unistring nname = EmptyUniString) : RefalNameSpace(nname){};
    virtual RefObject* getObjectByName(unistring name, Session *s=0)=0;
};

/*

        virtual RefObject* getObjectByName(unistring name){ return 0; };
        RefalNameSpace(unistring name = EmptyUniString) : RefObject(){ setName(name); };

*/

class RefUserModule : public RefModuleBase {
public:
    std::map<unistring, RefObject*> objects;
    unistring getName(){ return name; };
    RefUserModule() : RefModuleBase(){}
    unistring toString();
    RefObject* getObjectByName(unistring name, Session *s=0);
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
    public:
        void setRightPart(RefChain *rp){ rightPart = rp; }
        void setLeftPart(RefChain *lp) { leftPart  = lp; }

        virtual bool operator ==(RefData &rd){return false; };
        virtual TResult  init(Session* , RefData *&); //
        virtual TResult  back(Session* , RefData *&, RefData *&); //

        RefCondition(RefData *r=0) : RefConditionBase(r){ rightPart = leftPart = 0; is_system = false; }
        virtual ~RefCondition(){};
        unistring toString(){ return sss=" @Condition$" + rightPart->toString() + "::" + leftPart->toString() + ' '; }
        RefData* Copy(RefData *where=0){ SYSTEMERROR("unexpected try to Copy REF-condition"); return 0; };



};


// абстрактный класс для всех сложных шаблонов
class RefTemplateBase : public RefModuleBase {
public:
    RefTemplateBase (unistring name);
    ~RefTemplateBase (){};
};

// пользовательский шаблон
class RefUserTemplate : public RefTemplateBase {
        RefChain *leftPart;
    public:
        unistring getName(){ return name; };
        RefUserTemplate(unistring name, RefChain *lp=0);
        void setLeftPart(RefChain *);
        RefObject* getObjectByName(unistring name, Session *s){ SYSTEMERROR("--== ZAGLUSHKA ==--"); };
        unistring toString(){
            return (getName()+"$RefUserTemplate_::=_"+leftPart->toString());
        }
};


// мосты через session между экземплярами пользовательских переменных и телами шаблонов
class RefTemplateBridge : public RefData_DOT {
    public:
        RefTemplateBridge (RefData *d=0) : RefData_DOT(d){};
        RefTemplateBridge(RefTemplateBridge *nd, RefData* rp = 0) : RefData_DOT(nd, rp){};

};

#endif // FUNCTION_H_INCLUDED

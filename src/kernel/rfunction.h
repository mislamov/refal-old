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
    std::list<RefSentence *> body; // �����������

    /// ��������� - ����� ������� ��   // �������� � ��������� ��������� �������(�����. � �����)
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
    virtual void initilizeAll(Session *){ LOG("not realized!"); };
};



// ��������� ��� ���������, ������� ���������� ������������������� ����� �������� ������
class NeedInitilize {
    public:
        virtual bool initize(Session *) = 0;
};

// ����� - ����������������������� ���������� �������� ����. ����� ������������� ���������� �� ���� {RefTemplateBridgeVar RefTemplateBridgeVar}
class RefUserVarNotInit : public RefVariable, public NeedInitilize {
        unistring type;
    public:
        bool initize(Session *); // ���������� �� ����
        void setType(unistring ttype){ type = ttype; };
        unistring getType(){ return type; };

        unistring toString() { return "@RefUserVarNotInit.toString()"; }
        bool operator ==(RefData &rd) { return false; };
        TResult init(Session*, RefData *&);
        TResult back(Session*, RefData *&, RefData *&);
        RefData*  Copy(RefData* where=0){ return 0; };

        ~RefUserVarNotInit(){
            int i=0;
        };
};


class RefUserModule : public RefModuleBase {
public:
    std::map<unistring, RefObject*> objects;
    unistring getName(){ return name; };
    RefUserModule() : RefModuleBase(){}
    unistring toString();
    RefObject* getObjectByName(unistring name, Session *s=0);

    std::stack<NeedInitilize *> initItems; // ���� ������ �� �������������������� ������ (������� ����������)
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


// ����������� ����� ��� ���� ������� ��������
class RefTemplateBase : public RefModuleBase {
public:
    RefTemplateBase (unistring name);
    ~RefTemplateBase (){};
};

// ���������������� ������
class RefUserTemplate : public RefTemplateBase {
        RefChain *leftPart;
    public:
        inline unistring getName(){ return name; };
        RefUserTemplate(unistring name, RefChain *lp=0);
        inline RefChain* getLeftPart(){return leftPart;};
        void setLeftPart(RefChain *);
        RefObject* getObjectByName(unistring name, Session *s){ SYSTEMERROR("--== ZAGLUSHKA ==--"); };
        unistring toString(){
            return (getName()+"$RefUserTemplate_::=_"+leftPart->toString());
        }
};

class RefTemplateBridgeTmpl;


// ����� ����� ���.������ � ������� ��������. �� ������� ����� �����
class RefTemplateBridgeVar : public RefBracketBase, public IRefVar {
        unistring name;
    public:
        RefTemplateBridgeTmpl* bridge; // ��������� �� ����������� ���� ���� �������. ��������� �� ������������� - ��� ������������� ������������ ������

        RefTemplateBridgeVar (RefData *d=0) : RefBracketBase(d){ bridge=0; name="NOT SET";};
        RefTemplateBridgeVar(RefTemplateBridgeVar *nd, RefData* rp = 0) : RefBracketBase(nd, rp){ bridge=0;  name="NOT SET";};
        unistring toString() { if (isOpen()) return sss = "[{]"; else return sss = "[}]"; };

        TResult init(Session* s, RefData *&currentPoint);
        TResult back(Session* s, RefData *&currentRight, RefData *&currentLeft);
        RefData*  next_point( ThisId var_id, Session *s);
        RefData*  pred_point( ThisId var_id, Session *s);

        unistring getName(){ return name; }
        void setName(unistring nname){ name = nname; }

        RefData* Copy(RefBracketBase *bb, RefData *rp=0){
            RefTemplateBridgeVar *b = dynamic_cast<RefTemplateBridgeVar *>(bb);
            #ifdef DEBUG
            if (!b) SYSTEMERROR("not RefTemplateBridgeVar !");
            #endif
            RefTemplateBridgeVar *cp = new RefTemplateBridgeVar(b, rp);
            cp->setName(this->getName());
            RUNTIMEERROR("RefTemplateBridgeVar::Copy", "zaglushka!");
            /// ??? ����� �� ���������� ���� ������������� � �������� ����������
            return cp;
        };

        RefData* Copy(RefData *rp=0){
            RefTemplateBridgeVar *cp = new RefTemplateBridgeVar(rp);
            cp->setName(this->getName());
            RUNTIMEERROR("RefTemplateBridgeVar::Copy", "zaglushka!");
            /// ??? ����� �� ���������� ���� ������������� � �������� ����������
            return cp;
        };

};

// ����� ����� ���.������ � ������� ��������. �� ������� �������� �������
class RefTemplateBridgeTmpl : public RefBracketBase {
    public:
        RefTemplateBridgeTmpl (RefData *d=0) : RefBracketBase(d){};
        RefTemplateBridgeTmpl(RefTemplateBridgeTmpl *nd, RefData* rp = 0) : RefBracketBase(nd, rp){};
        unistring toString() { if (isOpen()) return sss = "{[}"; else return sss = "{]}"; };

        TResult init(Session* s, RefData *&currentPoint);
        TResult back(Session* s, RefData *&currentRight, RefData *&currentLeft);
        RefData*  next_point( ThisId var_id, Session *s);
        RefData*  pred_point( ThisId var_id, Session *s);

        RefData* Copy(RefBracketBase *b, RefData *rp=0){
            SYSTEMERROR("������ ����� �������� ������� �� �������������! �������� ������");
        };
        RefData* Copy(RefData *rp=0){
            SYSTEMERROR("������ ����� �������� ������� �� �������������! �������� ������");
        };

};

#endif // FUNCTION_H_INCLUDED

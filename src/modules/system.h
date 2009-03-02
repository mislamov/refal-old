#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <sstream>

#include "../kernel/rfunction.h"
#include "../kernel/data.h"

class system_DEC : public RefBuildInFunction {
public:
    system_DEC(RefDllModule *m) : RefBuildInFunction("Dec", m) {}
    unistring toString(){ return "DEC"; };
    unistring getName(){ return "Dec"; };
    bool eval(RefData* lft, RefData* rht, RefChain* &result, Session* s=0);
};

class system_DIV : public RefBuildInFunction {
public:
    system_DIV(RefDllModule *m) : RefBuildInFunction("Div", m) {}
    unistring toString(){ return "DIV"; };
    unistring getName(){ return "Div"; };
    bool eval(RefData* lft, RefData* rht, RefChain* &result, Session* s=0);
};

class system_MUL : public RefBuildInFunction {
public:
    system_MUL(RefDllModule *m) : RefBuildInFunction("Mul", m) {}
    unistring toString(){ return "MUL"; };
    unistring getName(){ return "Mul"; };
    bool eval(RefData* lft, RefData* rht, RefChain* &result, Session* s=0);
};

class system_SUM : public RefBuildInFunction {
public:
    system_SUM(RefDllModule *m) : RefBuildInFunction("Sum", m) {}
    unistring toString(){ return "SUM"; };
    unistring getName(){ return "Sum"; };
    bool eval(RefData* lft, RefData* rht, RefChain* &result, Session* s=0);
};

class system_LENW : public RefBuildInFunction {
public:
    system_LENW(RefDllModule *m) : RefBuildInFunction("Lenw", m) {}
    unistring toString(){ return "LENW"; };
    unistring getName(){ return "Lenw"; };
    bool eval(RefData* lft, RefData* rht, RefChain* &result, Session* s=0);
};

class system_COMPARE : public RefBuildInFunction {
public:
    system_COMPARE(RefDllModule *m) : RefBuildInFunction("Compare", m) {}
    unistring toString(){ return "COMPARE"; };
    unistring getName(){ return "Compare"; };
    bool eval(RefData* lft, RefData* rht, RefChain* &result, Session* s=0);
};

class system_CARD : public RefBuildInFunction {
public:
    system_CARD(RefDllModule *m) : RefBuildInFunction("Card", m) {}
    unistring toString(){ return "CARD"; };
    unistring getName() { return "Card"; };
    bool eval(RefData* lft, RefData* rht, RefChain* &result, Session* s=0);
};

class system_PROUT : public RefBuildInFunction {
public:
    system_PROUT(RefDllModule *m) : RefBuildInFunction("Prout", m) {}
    unistring toString(){ return "PROUT"; };
    unistring getName() { return "Prout"; };
    bool eval(RefData* lft, RefData* rht, RefChain* &result, Session* s=0);
};

class system_PRINT : public RefBuildInFunction {
public:
    system_PRINT(RefDllModule *m) : RefBuildInFunction("Print", m) {}
    unistring toString(){ return "PRINT"; };
    unistring getName() { return "Print"; };
    bool eval(RefData* lft, RefData* rht, RefChain* &result, Session* s=0);
};




class mSYSTEM : public RefDllModule {
public:
    unistring getName(){ return "System"; };
    mSYSTEM() : RefDllModule() {
        setObjectByName("Dec",  new system_DEC(this));
        setObjectByName("Div",  new system_DIV(this));
        setObjectByName("Mul",  new system_MUL(this));
        setObjectByName("Sum",  new system_SUM(this));

        setObjectByName("Lenw",  new system_LENW(this));
        setObjectByName("Compare",  new system_COMPARE(this));

        setObjectByName("Add",  getObjectByName("Sum"));
        setObjectByName("Sub",  getObjectByName("Dec"));

        setObjectByName("Card", new system_CARD(this));
        setObjectByName("Prout", new system_PROUT(this));
        setObjectByName("Print", new system_PRINT(this));
    };
};



#endif

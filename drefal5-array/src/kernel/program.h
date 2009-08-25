#ifndef PROGRAM_H
#define PROGRAM_H

#include <map>
#include <stack>

#include "config.h"
//#include "data.h"
#include "sentence.h"


class RefProgram;
class RefModuleBase;
class RefDllModule;
class RefUserModule;
class RefFunctionBase;
class RefBuildInFunction;
class RefUserFunction;
class RefTemplateBase;
class RefUserTemplate;



// программа. содержит подключенные модули и поддерживает различные операции по ним
class RefProgram {
public:
	// TODO: сделать список пар для приоритетности.
	std::map<unistring, RefModuleBase*> modules;
	RefProgram(){};

	void regModule(RefModuleBase *module); // регистрация модуля в программе (перед загрузкой)
	RefData* createSymbolByCode(unistring code, unistring value);
	RefData* createVariableByTypename(unistring code, unistring value);

	RefObject* findFunctionById(unistring id);

};


class RefModuleBase : public RefObject {
public:
    virtual unistring getName() =0;
	//virtual void setName(unistring s) {        name = s;    }

    RefModuleBase() {};
    virtual ~RefModuleBase() {};
    virtual RefObject* getObjectByName(unistring name, Session *s=0)=0;
    virtual void initilizeAll(Session *);
};


class RefDllModule : public RefModuleBase {
    std::map<unistring, RefObject*> objects;
protected:
	std::map<unistring, RefData*(*)(unistring)> dataConstructors;
	std::map<unistring, RefData*(*)(unistring)> varConstructors;
public:
	RefDllModule(){};
	virtual ~RefDllModule(){};
	RefObject* getObjectByName(unistring nm, Session *s=0){return objects[nm];};
    void setObjectByName(unistring name, RefObject* o){objects[name] = o; };
    unistring toString(){SYSTEMERROR("unrelised");};
	RefData* constructSymbol(unistring typecode, unistring value){
		std::map<unistring, RefData*(*)(unistring)>::iterator iter = dataConstructors.find(typecode);
		if (iter==dataConstructors.end()) return 0;
		return (*iter->second)(value);
	};
	RefData* constructVariable(unistring typecode, unistring value){
		std::map<unistring, RefData*(*)(unistring)>::iterator iter = varConstructors.find(typecode);
		if (iter==varConstructors.end()) return 0;
		return (*iter->second)(value);
	};
};



// пользовательские модули могут быть только частью программы (совокупность модулей и зависимостей между ними)
class RefUserModule : public RefModuleBase {
protected:
	unistring name;
public:
    std::map<unistring, RefObject*> objects;
    unistring getName() {        return name;    };

    RefUserModule(unistring name, RefProgram* p);
    virtual ~RefUserModule() {};

    unistring explode(){SYSTEMERROR("unrelised");};
    unistring toString();
    RefObject* getObjectByName(unistring name, Session *s=0){
		std::map<unistring, RefObject*>::iterator it = objects.find(name);
		if (it!=objects.end()) return it->second;
		return 0;
	};

    std::stack<NeedInitilize *> initItems; // стек ссылок на неинициализированные данные (внешние переменные)
    void initilizeAll(Session *){SYSTEMERROR("unrelised");};
};





//  функции - не слабое место в производительности. Поэтому разумно использовать виртуальную таблицу 
class RefFunctionBase : public RefObject {
public:
    CLASS_CAST(UseRTTI);

	RefFunctionBase(){};
	virtual ~RefFunctionBase(){};
    virtual unistring getName() = 0;
    virtual RefChain *eval(RefData**, RefData**, Session*)=0;
};



class RefBuildInFunction : public RefFunctionBase {
public:
	RefBuildInFunction() : RefFunctionBase() {};
    virtual ~RefBuildInFunction() {};
    RefChain *eval(RefData**, RefData**, Session*){ SYSTEMERROR("not realised!"); };
};



class RefUserFunction : public RefFunctionBase {
    unistring name;
public:
    std::list<RefSentence *> body; // предложения

    /// аргументы - концы чистого ОВ   // заменяет в объектном выражении участок(перед. в аргум)
	RefChain *eval(RefData **, RefData **, Session *s){SYSTEMERROR("urealised");}; // - перенесено в session
    unistring getName()  { return name; };
	unistring toString();
	unistring explode(){
		SYSTEMERROR("unrelised");
	};
    RefUserFunction(unistring nname) {        name = nname;    }
    virtual ~RefUserFunction() {};
};



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
	unistring name;
public:
    CLASS_OBJECT_CAST(RefUserTemplate);

	unistring getName(){return name;};
	RefUserTemplate(unistring nam) : RefTemplateBase() {this->name = nam;};
    inline RefChain* getLeftPart() {        return leftPart;    };
    void setLeftPart(RefChain *){SYSTEMERROR("unrelised");};
    RefObject* getObjectByName(unistring name, Session *s) {        SYSTEMERROR("--== ZAGLUSHKA ==--");    };
    unistring explode() {        return (getName()+"$RefUserTemplate_::=_"+(leftPart?leftPart->toString():"$void"));    }
    virtual ~RefUserTemplate() {};
    RefUserTemplate(){SYSTEMERROR("unrelised");};
};



#endif

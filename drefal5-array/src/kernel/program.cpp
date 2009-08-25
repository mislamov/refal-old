#include "program.h"
#include "../modules/system.h"

//////   программа. содержит подключенные модули и поддерживает различные операции по ним
//////   class RefProgram

void RefProgram::regModule(RefModuleBase *module){ // регистрация модуля в программе (перед загрузкой)
		if (module->getName() == EmptyUniString) 
			SYSTEMERROR("Empty module name");
		if (modules.find(module->getName()) != modules.end()) 
			SYSTEMERROR("Several loads of module [" << module->getName() << "] ");
		modules[module->getName()] = module;
};

RefData* RefProgram::createSymbolByCode(unistring code, unistring value){
	std::map<unistring, RefModuleBase*>::iterator modit = modules.begin(), end = modules.end();
	RefModuleBase* mod = 0;
	RefDllModule* dllmod = 0;
	RefData* result = 0;

	while (modit != end){
		//TODO: поиск согласно порядку подключения модулей
		dllmod = dynamic_cast<RefDllModule*>(&(*modit->second));
		if (dllmod && (result=dllmod->constructSymbol(code, value))){
			return result;
		} // на данный момент в НЕ dll-модулях не может определяться генератор символов по коду
		++modit;
	}

	COMPILETIMEERROR("Loader", "Definition for " << code << " not found in loaded modules");
};


// создает переменную с именем по коду. Ищет в подключенных модулях (среди встроенных переменных и пользовательских шаблонов)
RefData* RefProgram::createVariableByTypename(unistring code, unistring value){
	std::map<unistring, RefModuleBase*>::iterator modit = modules.begin(), end = modules.end();
	RefModuleBase* mod = 0;
	RefDllModule  *dllmod = 0;
	RefUserModule *usermod= 0;
	RefData* result = 0;

	while (modit != end){
		//TODO: сделать поиск согласно порядку подключения модулей
		mod = &(*modit->second);
		dllmod = dynamic_cast<RefDllModule*>(mod);
		if (dllmod){
			result=dllmod->constructVariable(code, value);
			if (result && ref_dynamic_cast<RefVariableBase>(result)) {
				return result;
			}
			if (result) {
				SYSTEMERROR("not variable loading like variable: " << result->toString());
			}
		} else {
			usermod = dynamic_cast<RefUserModule*>(mod);
			if (!usermod) SYSTEMERROR("unknown children of RefModuleBase");
			RefObject *obj = usermod->getObjectByName(code);
			if (obj){
				RefTemplateBase *templ = ref_dynamic_cast<RefTemplateBase>(obj);
				if (templ){
					return new RefUserVarNotInit(templ, code, value);
				}
			} 
		}
		++modit;
	}

	return 0;
};




////   class RefModuleBase

void RefModuleBase::initilizeAll(Session *) {        LOG("not realized!");    };
	


////  class RefUserModule

RefUserModule::RefUserModule(unistring name, RefProgram* p) : RefModuleBase() {
		this->name = name;
        p->regModule(this);
};

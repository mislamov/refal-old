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
		SYSTEMERROR("zaglushka");
};

RefVariable* RefProgram::createVariableByTypename(unistring code, unistring value){
		SYSTEMERROR("zaglushka");
};




////   class RefModuleBase

void RefModuleBase::initilizeAll(Session *) {        LOG("not realized!");    };
	
// создает RefData-символ по rsl-коду code и со значением value (текстовое представление)
RefData* RefModuleBase::createSymbolByCode(unistring code, unistring value){
		// TODO: поиск по себе и включенным модулям (а если "свое" описание загружается ПОСЛЕ использования внутри себя? а во включенных определено?)
		extern mSYSTEM msystem;
		return msystem.dataConstructors[code](value);
};


////  class RefUserModule

RefUserModule::RefUserModule(unistring name, RefProgram* p) : RefModuleBase() {
		this->name = name;
        p->regModule(this);
};

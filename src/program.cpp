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

#include <sstream>

#include "program.h"
#include "system.h"


RefProgram::RefProgram(){
	this->regModule(new ModSystem());
}


void RefProgram::regModule(RefModuleBase *module){ // регистрация модуля в программе (перед загрузкой)
		if (module->getName() == EmptyUniString) 
			SYSTEMERROR("Empty module name");
		if (modules.find(module->getName()) != modules.end()) 
			SYSTEMERROR("Several loads of module [" << module->getName() << "] ");
		modules[module->getName()] = module;
};


//TODO: оптимизировать - без рекурсии
RefChain*  RefProgram::executeExpression (RefChain *chain){ // вычисляет цепочку
	RefChain* result = new RefChain(chain->getLength());
	for (RefData **iter=(*chain)[0], **iend = (*chain)[-1]+1; iter < iend; ++iter){
		RefDataBracket *databr = ref_dynamic_cast<RefDataBracket>(*iter);
		if (databr){
			if (ref_dynamic_cast<RefStructBrackets>(databr)){
				*result += new RefStructBrackets( executeExpression(databr->chain) );
			} else {
				#ifdef TESTCODE
				if (! ref_dynamic_cast<RefExecBrackets>(databr)) AchtungERROR;
				#endif
				//RefExecBrackets
				RefChain *arg = executeExpression(databr->chain); // вычисляем внутренние exec-скобки
				if (arg->isEmpty()) SYSTEMERROR("Unexpected empty argument for function call-brackets! " << databr->chain->debug());
				RefData **functionid = (*arg)[0];
				//TODO: сделать привязку функциональных вызовов по именнованым областям
				RefFunctionBase *func = this->findFunction(*functionid);
				if (!func) RUNTIMEERROR((*functionid)->explode(), "Function not found in program");
				//RefChain *fresult = func->
			}
		} else {

		}
	}
};

RefFunctionBase* RefProgram::findFunction(RefData *func_id){
	unistring id;
	if (! ref_dynamic_cast<RefWord>(func_id)){
		RUNTIMEERROR(func_id->explode(), "only Compound-symbol supported!");
	}
	id = ((RefWord*)func_id)->getValue();

	std::map<unistring, RefModuleBase*>::iterator modit = modules.begin(), end = modules.end();
	RefModuleBase* mod = 0;

	while (modit != end){
		mod = &(*modit->second);
		RefObject* obj = mod->getObjectByName(id);
		if (ref_dynamic_cast<RefFunctionBase>(obj)){
			return (RefFunctionBase*)obj;
		}
		++modit;
	};
	RUNTIMEERROR("FindFunction", "function " << id << " not found in program");
	return 0;
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
			if (result && ref_dynamic_cast<RefVariable>(result)) {
				return result;
			}
			if (result) {
				SYSTEMERROR("not variable loading like variable: " << result->debug());
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

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

#ifndef PROGRAM_H_INCLUDED
#define PROGRAM_H_INCLUDED

#include <map>
#include <stack>

#include "config.h"
#include "data.h"
#include "function.h"


class RefModuleBase;

// программа
class RefProgram {
	std::map<unistring, RefModuleBase*> modules;
public:
	long long step;

	RefProgram();
	void regModule(RefModuleBase *); // регистрация модуля в программе (перед загрузкой)
    RefChain*  executeExpression (RefChain*, Session*); // вычисляет цепочку
	RefFunctionBase *findFunction(unistring  ); // ищет функцию в модулях по id
	RefTemplateBase *findTemplate(unistring  ); // ищет шаблон в модулях по id

	RefData* createSymbolByCode(unistring code, unistring value);
	RefData* createVariableByTypename(unistring code, unistring value);

};

// модуль
class RefModuleBase {
protected:
    //std::map<unistring, RefObject*> objects;
	std::map<unistring, RefFunctionBase*> functions;
	std::map<unistring, RefTemplateBase*> templates;
public:
	//RefObject* getObjectByName(unistring nm, Session *s=0){return objects[nm];};
	RefFunctionBase* getFunctionByName(unistring nm, Session *s=0){ 
		std::map<unistring, RefFunctionBase*>::iterator iter = functions.find(nm);
		if (iter != functions.end()) return iter->second;
		return 0;
	};
	RefTemplateBase* getTemplateByName(unistring nm, Session *s=0){
		std::map<unistring, RefTemplateBase*>::iterator iter = templates.find(nm);
		if (iter != templates.end()) return iter->second;
		return 0;

	};

    //void setObjectByName(unistring name, RefObject* o){objects[name] = o; };
    void setFunctionByName(unistring name, RefFunctionBase* o);
    void setTemplateByName(unistring name, RefTemplateBase* o);
    virtual unistring getName() =0;
};

class RefDllModule : public RefModuleBase {
protected:
	std::map<unistring, RefData*(*)(unistring)> dataConstructors;
	std::map<unistring, RefData*(*)(unistring)> varConstructors;
public:
	RefData* constructSymbol(unistring typecode, unistring value);
	RefData* constructVariable(unistring typecode, unistring value);

};

class RefUserModule : public RefModuleBase {
	unistring name;
public:
	RefUserModule(unistring thename){ name=thename; };
	inline unistring getName(){ return name; };
	unistring debug();
	virtual void initilizeAll(RefProgram* program);
};

#endif

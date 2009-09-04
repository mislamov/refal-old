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

#include "config.h"
#include "data.h"


class RefModuleBase;

// программа
class RefProgram {
	std::map<unistring, RefModuleBase*> modules;
public:
	RefProgram();
	void regModule(RefModuleBase *); // регистрация модуля в программе (перед загрузкой)
    RefChain*  executeExpression (RefChain *); // вычисляет цепочку
};

// модуль
class RefModuleBase {
public:
    virtual unistring getName() =0;
};

class RefDllModule : public RefModuleBase {
    std::map<unistring, RefObject*> objects;
protected:
	std::map<unistring, RefData*(*)(unistring)> dataConstructors;
	std::map<unistring, RefData*(*)(unistring)> varConstructors;
public:
	RefObject* getObjectByName(unistring nm, Session *s=0){return objects[nm];};
    void setObjectByName(unistring name, RefObject* o){objects[name] = o; };
};

class RefUserModule : public RefModuleBase {
};

#endif

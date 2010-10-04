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

#include "SAXLoaderHeap.h"


// возвращает переменную
RefVariable* LoaderHeap::getVariableByTypename(unistring nametype, unistring vn){
	RefData* res = currentProgram->createVariableByTypename(nametype, vn);

    if (res) {
		#ifdef TESTCODE
		if (! dynamic_cast<RefVariable*>(res)) AchtungERRORn;
		#endif
		return (RefVariable*)res;
    }

    // создаем пользовательскую переменную
    RefVarChains *v = new RefVarChains();
    v->setName(vn);
    v->setTypeString(nametype);
    return v;
}

/*
// возвращает рефал-символ
RefData* LoaderHeap::getNewEmptyRefSymbolByTypeName(unistring nametype){
    // поиск среди встроенных типов символов
    RefData* result = createNewEmptyRefSymbolByTypeName(nametype);
    if (result) {
        return result;
    }

    SYSTEMERRORn("Unknown Refal-symbol: " << nametype );
    //return new RefVarChains(nametype);
}
*/

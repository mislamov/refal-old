// D-Refal - sentential program language
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
#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <sstream>

#include "../kernel/program.h"
#include "../kernel/symbols.h"
#include "module_sdk.h"


RefChain* Dec  (RefData** beg, RefData** end, Session* s);
RefChain* Div  (RefData** beg, RefData** end, Session* s);
RefChain* Mul  (RefData** beg, RefData** end, Session* s);
RefChain* Sum  (RefData** beg, RefData** end, Session* s);
RefChain* Numb (RefData** beg, RefData** end, Session* s);
RefChain* Lenw (RefData** beg, RefData** end, Session* s);
RefChain* Compare (RefData** beg, RefData** end, Session* s);
RefChain* Implode (RefData** beg, RefData** end, Session* s);
RefChain* Explode (RefData** beg, RefData** end, Session* s);
RefChain* ExplodeAll (RefData** beg, RefData** end, Session* s);
RefChain* Add   (RefData** beg, RefData** end, Session* s);
RefChain* Sub   (RefData** beg, RefData** end, Session* s);
RefChain* Mount (RefData** beg, RefData** end, Session* s);
RefChain* Card  (RefData** beg, RefData** end, Session* s);
RefChain* Prout (RefData** beg, RefData** end, Session* s);
RefChain* Print (RefData** beg, RefData** end, Session* s);
RefChain* Exit  (RefData** beg, RefData** end, Session* s);




BEGIN_DLL_MODULE("System", mSYSTEM)
		DEFINE_MODULE_FUNCTION(Sum);
		DEFINE_MODULE_FUNCTION(Dec);
		DEFINE_MODULE_FUNCTION(Div);
		DEFINE_MODULE_FUNCTION(Mul);
		DEFINE_MODULE_FUNCTION(Numb);
		DEFINE_MODULE_FUNCTION(Lenw);
		DEFINE_MODULE_FUNCTION(Compare);
		DEFINE_MODULE_FUNCTION(Implode);
		DEFINE_MODULE_FUNCTION(Explode);
		DEFINE_MODULE_FUNCTION(ExplodeAll);
		DEFINE_MODULE_FUNCTION(Mount);
		DEFINE_MODULE_FUNCTION(Card);
		DEFINE_MODULE_FUNCTION(Prout);
		DEFINE_MODULE_FUNCTION(Print);
		DEFINE_MODULE_FUNCTION(Exit);

		DEFINE_MODULE_FUNCTION_ALIAS(Add, Sum);
		DEFINE_MODULE_FUNCTION_ALIAS(Sub, Dec);
END_DLL_MODULE


#endif

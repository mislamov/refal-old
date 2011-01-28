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

//#include "symbols.h"
#include "DataChain.h"

//#include "module_sdk.h"


DataChain* Dec  (DataCursor beg, DataCursor end);
DataChain* Div  (DataCursor beg, DataCursor end);
DataChain* Mul  (DataCursor beg, DataCursor end);
DataChain* Sum  (DataCursor beg, DataCursor end);

DataChain* Mod  (DataCursor beg, DataCursor end);
DataChain* Trunc(DataCursor beg, DataCursor end);
DataChain* Round(DataCursor beg, DataCursor end);
DataChain* Symb (DataCursor beg, DataCursor end);
DataChain* Chr (DataCursor beg, DataCursor end);
DataChain* Ord (DataCursor beg, DataCursor end);
DataChain* First (DataCursor beg, DataCursor end);
DataChain* Last (DataCursor beg, DataCursor end);
DataChain* Lower (DataCursor beg, DataCursor end);
DataChain* Upper (DataCursor beg, DataCursor end);
DataChain* StdLog (DataCursor beg, DataCursor end);
DataChain* Time (DataCursor beg, DataCursor end);
DataChain* Mu (DataCursor beg, DataCursor end);


DataChain* Numb (DataCursor beg, DataCursor end); // строку в число
DataChain* Lenw (DataCursor beg, DataCursor end);
DataChain* Compare (DataCursor beg, DataCursor end); // Сравнивает два терма (по перегруженному оператору > или ==)
DataChain* Implode (DataCursor beg, DataCursor end);
DataChain* Explode (DataCursor beg, DataCursor end);
DataChain* ExplodeAll (DataCursor beg, DataCursor end);
DataChain* Add   (DataCursor beg, DataCursor end);
DataChain* Sub   (DataCursor beg, DataCursor end);
DataChain* Mount (DataCursor beg, DataCursor end);
DataChain* File  (DataCursor beg, DataCursor end);
DataChain* Args  (DataCursor beg, DataCursor end);
DataChain* Card  (DataCursor beg, DataCursor end);
DataChain* Prout (DataCursor beg, DataCursor end);
DataChain* ProutDebug (DataCursor beg, DataCursor end);
DataChain* StdErr(DataCursor beg, DataCursor end);
DataChain* StdLog(DataCursor beg, DataCursor end);
DataChain* Print (DataCursor beg, DataCursor end);
DataChain* Exit  (DataCursor beg, DataCursor end);

DataChain* RandomIdName(DataCursor beg, DataCursor end);

DataChain* RefalTokens  (DataCursor beg, DataCursor end);
DataChain* PrintStackTrace   (DataCursor beg, DataCursor end);
DataChain* Eval  (DataCursor beg, DataCursor end);

DataChain* DebugStart  (DataCursor beg, DataCursor end);
DataChain* DebugStop  (DataCursor beg, DataCursor end);



inline infint str2infint(unistring si) { // строку в число
    return atol(si.c_str());
};

inline infreal str2infreal(unistring si) { // строку в вещественное число
	return atof(si.c_str());
};


#endif

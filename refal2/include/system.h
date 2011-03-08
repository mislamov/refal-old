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
#include "ExecContext.h"

//#include "module_sdk.h"


DataChain* Dec  (DataCursor beg, DataCursor end, ExecContext *context);
DataChain* Div  (DataCursor beg, DataCursor end, ExecContext *context);
DataChain* Mul  (DataCursor beg, DataCursor end, ExecContext *context);
DataChain* Sum  (DataCursor beg, DataCursor end, ExecContext *context);

DataChain* Mod  (DataCursor beg, DataCursor end, ExecContext *context);
DataChain* Trunc(DataCursor beg, DataCursor end, ExecContext *context);
DataChain* Round(DataCursor beg, DataCursor end, ExecContext *context);
DataChain* Symb (DataCursor beg, DataCursor end, ExecContext *context);
DataChain* Chr (DataCursor beg, DataCursor end, ExecContext *context);
DataChain* Ord (DataCursor beg, DataCursor end, ExecContext *context);
DataChain* First (DataCursor beg, DataCursor end, ExecContext *context);
DataChain* Last (DataCursor beg, DataCursor end, ExecContext *context);
DataChain* Lower (DataCursor beg, DataCursor end, ExecContext *context);
DataChain* Upper (DataCursor beg, DataCursor end, ExecContext *context);
DataChain* StdLog (DataCursor beg, DataCursor end, ExecContext *context);
DataChain* Time (DataCursor beg, DataCursor end, ExecContext *context);
DataChain* Mu (DataCursor beg, DataCursor end, ExecContext *context);


DataChain* Numb (DataCursor beg, DataCursor end, ExecContext *context); // строку в число
DataChain* Lenw (DataCursor beg, DataCursor end, ExecContext *context);
DataChain* Compare (DataCursor beg, DataCursor end, ExecContext *context); // Сравнивает два терма (по перегруженному оператору > или ==)
DataChain* Implode (DataCursor beg, DataCursor end, ExecContext *context);
DataChain* Explode (DataCursor beg, DataCursor end, ExecContext *context);
DataChain* ExplodeAll (DataCursor beg, DataCursor end, ExecContext *context);
DataChain* Add   (DataCursor beg, DataCursor end, ExecContext *context);
DataChain* Sub   (DataCursor beg, DataCursor end, ExecContext *context);
DataChain* Mount (DataCursor beg, DataCursor end, ExecContext *context);
DataChain* File  (DataCursor beg, DataCursor end, ExecContext *context);
DataChain* Args  (DataCursor beg, DataCursor end, ExecContext *context);
DataChain* Card  (DataCursor beg, DataCursor end, ExecContext *context);
DataChain* Prout (DataCursor beg, DataCursor end, ExecContext *context);
DataChain* ProutDebug (DataCursor beg, DataCursor end, ExecContext *context);
DataChain* StdErr(DataCursor beg, DataCursor end, ExecContext *context);
DataChain* StdLog(DataCursor beg, DataCursor end, ExecContext *context);
DataChain* Print (DataCursor beg, DataCursor end, ExecContext *context);
DataChain* Exit  (DataCursor beg, DataCursor end, ExecContext *context);

DataChain* RandomIdName(DataCursor beg, DataCursor end, ExecContext *context);

DataChain* RefalTokens  (DataCursor beg, DataCursor end, ExecContext *context);
DataChain* PrintStackTrace   (DataCursor beg, DataCursor end, ExecContext *context);
DataChain* Eval  (DataCursor beg, DataCursor end, ExecContext *context);

DataChain* DebugStart  (DataCursor beg, DataCursor end, ExecContext *context);
DataChain* DebugStop  (DataCursor beg, DataCursor end, ExecContext *context);



inline infint str2infint(unistring si) { // строку в число
    return atol(si.c_str());
};

inline infreal str2infreal(unistring si) { // строку в вещественное число
	return atof(si.c_str());
};


#endif

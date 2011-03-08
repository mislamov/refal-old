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

#ifndef DiRefal_H_INCLUDED
#define DiRefal_H_INCLUDED

class DataChain;
class DataCursor;
class ExecContext;

typedef DataChain* (*rf_function)(DataCursor arg_from, DataCursor arg_to, ExecContext *context);

//DataChain* dummy(DataCursor arg_from, DataCursor arg_to, ExecContext *context){return 0; };
//rf_function dummy2(){ return 0; }



#include "DataContainerType.h"
#include "DataContainer.h"
#include "DataCursor.h"
#include "DataChain.h"

//#include "ExecContext.h"



#endif

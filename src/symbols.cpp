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

#include "symbols.h"


RefAlpha128* RefAlpha128::alphatable = new RefAlpha128[128];


unistring the_explode(RefData **a, RefData **b){
	if (!a) {
		return "";
	}
	size_t leng = b-a;
	if (!a || !b || leng<0) RUNTIMEERRORn("the_explode(**, **) : error arguments");
	unistring result = "";
    for (size_t i=0; i<=leng; i++) {
		#ifdef TESTCODE
		if (! a[i]) AchtungERRORn;
		#endif
		result += a[i]->explode();
    }
	return result;
};


unistring the_text(RefData **a, RefData **b){
	if (!a) {
		return "";
	}
	size_t leng = b-a;
	if (!a || !b || leng<0) RUNTIMEERRORn("the_text(**, **) : error arguments");
	unistring result = "";
    for (size_t i=0; i<=leng; i++) {
		#ifdef TESTCODE
		if (! a[i]) AchtungERRORn;
		#endif
		result += a[i]->toString();
    }
	return result;
};


unistring RefWord::debug() {
		std::ostringstream ss;
        ss << '"' << replace(value, "\n", "\\n") << "\" ";
        return ss.str();	
};













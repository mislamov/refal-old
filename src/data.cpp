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

#include "data.h"
//#include "symbols.h"
//#include "sentence.h"
//#include "session.h"

#include <stdlib.h>
#include <iostream>
#include <sstream>

size_t RefChain::alloc_portion = CHAIN_SYSTEM_PORTION_SIZE_INIT;


RefChain::RefChain(RefData* d) {
    sysize = leng = 1;
	first = (RefData**)malloc(sizeof(RefData*) * sysize);
	first[0] = d;
};

RefChain::RefChain(size_t size) { // size is not lenght
	sysize = size;
	first = (RefData**)malloc(sizeof(RefData*) * sysize);
	leng = 0;
};

RefChain& RefChain::operator+=(RefData *ch) {

	#ifdef TESTCODE
	if (leng>sysize) SYSTEMERROR("Achtung!")
	#endif

	if (leng == sysize){
		sysize += RefChain::alloc_portion;
		first   =   (RefData**) realloc(first, sizeof(RefData*)*sysize );
		//LOG("realloc");
		if (! first) RUNTIMEERROR("membuffer", "memory limit");
	}
	first[leng] = ch;
	++leng;

    return *this;
};

RefData** RefChain::operator[](signed long idx) {
#ifdef TESTCODE
	if ((idx<0 && (long)leng+idx<0) || (idx>0 && idx>=leng)) 
		AchtungERROR;
#endif
	return	(idx<0) ? first+leng+idx : first+idx;
};

unistring RefChain::debug(){
		    unistring result = "";
			result += "[";
			result += " leng=";
			char tmp[256];
			result += ltoa( leng, tmp, 10);
			result += " size=";
			result += ltoa( sysize, tmp, 10);
			result += " ";
			//result += ltoa( RefChain::alloc_portion, tmp, 10);
			result += "] ";

			for (size_t i=0; i<leng; i++) {
				result += (first[i] ? first[i]->debug() : " \x0000 ");
			}
			return result;
};

unistring RefStructBrackets::explode(){		return "(" + chain->explode() + ") ";	};
unistring RefExecBrackets::explode(){	return "<" + chain->explode() + "> ";	};


TResult RefStructBrackets::init(RefData **&tpl, Session* s, RefData **&l, RefData **&r){
    s->MOVE_TO_next_term(r);
	RefStructBrackets *br;
	
	if (r && (br=ref_dynamic_cast<RefStructBrackets>(*r)))
};
TResult RefStructBrackets::back(RefData **&tpl, Session* s, RefData **&l, RefData **&r){
};


TResult RefExecBrackets::init(RefData **&tpl, Session* s, RefData **&l, RefData **&r){
	AchtungERROR;
};
TResult RefExecBrackets::back(RefData **&tpl, Session* s, RefData **&l, RefData **&r){
	AchtungERROR;
};

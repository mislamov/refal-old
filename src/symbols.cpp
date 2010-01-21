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
#include <map>


RefAlpha128* RefAlpha128::alphatable = new RefAlpha128[128];

std::map<unichar, RefAlphaBase*> RefAlpha::alphamap;

RefAlphaBase* newRefAlpha(Session *s, unichar val){
		if (val < 128){
			return RefAlpha128::alphatable + val;
		} else {
			std::map<unichar, RefAlphaBase*>::iterator it = RefAlpha::alphamap.find(val);
			if (it == RefAlpha::alphamap.end()){
				return (RefAlpha::alphamap[val] = new RefAlpha(0, val));
			}
			return it->second;
		}
};


unistring the_explode(RefData **a, RefData **b){
#ifdef DEBUG
	if (!a) {
		return "$null, " + (*b)->debug();
	}
#endif
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

void RefAlpha::alphaMapDestroy(){
	std::map<unichar, RefAlphaBase*>::iterator it;
	while(alphamap.size()){
		it = alphamap.begin();
		delete it->second;
		alphamap.erase(it);
	}
};



/*RefAlphaBase* newRefAlpha(Session *s, unichar val){
	if (val < 128){
		return RefAlpha128::alphatable + val;
	}

	std::map<unichar, RefAlphaBase*>::iterator it = alphamap.find(val);
	if (it != alphamap.end()){
		return it->second;
	}

	RefAlphaBase *ab = new RefAlpha(s, val);
	alphamap[val] = ab;
	return ab;
};*/


unistring RefWord::debug() {
		std::ostringstream ss;
        ss << '"' << replace(value, "\n", "\\n") << "\" ";
        return ss.str();	
};













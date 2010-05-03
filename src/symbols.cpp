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

RefAlphaBase* newRefAlpha(Session *sess, unichar value) {
    unsigned char val = value;
    if (val < 128) {
        return RefAlpha128::alphatable + val;
    } else {
        std::map<unichar, RefAlphaBase*>::iterator it = RefAlpha::alphamap.find(val);
        if (it == RefAlpha::alphamap.end()) {
            return (RefAlpha::alphamap[val] = new RefAlpha(0, val));
        }
        return it->second;
    }
};


unistring the_explode(RefData **a, RefData **b) {
    ref_assert(b || !a);
    #ifdef DEBUG
    if (!a && b) {
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


unistring chain_to_text(RefData **a, RefData **b) {
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


unistring the_debug_text(RefData **a, RefData **b, size_t maxlen) {
    if (!a) {
        return " ";
    }
    size_t leng = b-a;
    if (maxlen && leng > maxlen){
        leng = maxlen;
    }
    if (!a || !b || leng<0) RUNTIMEERRORn("the_debug_text(**, **) : error arguments");
    std::stringstream result;

    for (size_t i=0; i<=leng; i++) {
        ref_assert(a[i]);

        RefAlphaBase *alp = ref_dynamic_cast<RefAlphaBase>(a[i]);
        if (alp) {
            result << " '";
            while (i<=leng && (alp = ref_dynamic_cast<RefAlphaBase>(a[i]))) {
                if ((unsigned long)alp->getValue() < 20) {
                    result << "#" << (int) alp->getValue();
                } else {
                    result << alp->getValue();
                }
                ++i;
            }
            result << "' ";
            if (i>leng) break;
        }

        result << a[i]->debug();
    }
    return result.str();
};

/*
unistring chain_to_text(RefData** from, RefData** to, int showleng){
	if (!from || !*from) return "#empty";
	if (!to || (to-from)<0) return "[error string]";
	std::stringstream result;
	int i = 0;
	while(from+i <= to && (showleng<=0 || i<showleng)){

		RefAlphaBase *alp = ref_dynamic_cast<RefAlphaBase>(from[i]);
		if (alp){
			result << " '";
			while(from+i <= to && (showleng<=0 || i<showleng) && (alp = ref_dynamic_cast<RefAlphaBase>(from[i]))){
				if (alp->getValue() < 20){
                    result << "#" << (int) alp->getValue();
                } else {
				    result << alp->getValue();
				}
				++i;
			}
			result << "' ";
			if (!(from+i <= to && (showleng<=0 || i<showleng))) break;
		}


		if(from[i]) result << from[i]->debug();
		++i;
	}
	if (i==showleng) result << "... ";
	return result.str();
};
*/

RefChain *text_to_chain(Session *sess, const char *buffer) {
    RefChain *result = new RefChain(sess, 1024);
    while (*buffer) {
        (*result) += newRefAlpha(sess, *buffer);
        buffer++;
    }
    return result;
}
RefChain *text_to_chain(Session *sess, const char *buffer, size_t length) {
    RefChain *result = new RefChain(sess, length);
    for (size_t i=0; i<length; i++) {
        if (buffer[i] != '\r') {  /// todo: правильно обрабатывать
            (*result) += newRefAlpha(sess, buffer[i]);
        }
    }
    return result;
}


void RefAlpha::alphaMapDestroy() {
    std::map<unichar, RefAlphaBase*>::iterator it;
    while (alphamap.size()) {
        it = alphamap.begin();
        delete it->second;
        alphamap.erase(it);
    }
};



/*RefAlphaBase* newRefAlpha(Session *sess, unichar val){
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


/*
unistring RefWord::debug() {
		std::ostringstream ss;
        ss << '"' << replace(value, "\n", "\\n") << "\" ";
        return ss.str();
};
*/

bool RefIntegerBase::operator >(RefData &rd){
        return
            (ref_dynamic_cast<RefIntegerBase>(&rd) && this->getValue() > ((RefIntegerBase*)&rd)->getValue()) ||
            (ref_dynamic_cast<RefRealBase>(&rd) && this->getValue() > ((RefRealBase*)&rd)->getValue())
            ;
};


bool RefRealBase::operator >(RefData &rd){
        return
            (ref_dynamic_cast<RefIntegerBase>(&rd) && this->getValue() > ((RefIntegerBase*)&rd)->getValue()) ||
            (ref_dynamic_cast<RefRealBase>(&rd) && this->getValue() > ((RefRealBase*)&rd)->getValue())
            ;
};











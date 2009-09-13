#include "symbols.h"

RefChainConstructor *textToChain(unistring str){
	RefChainConstructor *ch = new RefChainConstructor();
	size_t len = str.length();
	for (size_t i=0; i<len; ++i){
		*ch += new RefAlpha(str[i]);
	}
	return ch;
};


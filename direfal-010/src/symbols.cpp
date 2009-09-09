#include "symbols.h"

RefChainConstructor* textToChain(unistring str){
	RefChainConstructor *res = new RefChainConstructor();
	for (size_t i=0; i<str.length(); i++){
		*res += new RefAlpha(str[i]);
	}
	return res;
};

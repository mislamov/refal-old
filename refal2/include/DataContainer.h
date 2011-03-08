#ifndef TERM_H
#define TERM_H


#include <stddef.h>

#include "config.h"
#include "direfal.h"

class DataChain;
class DataCursor;


inline bool isSymbolType(DataContainerType type){
	return (type <= word);
};

struct BracketData {
	rf_function fn;
	DataChain *chain;
	char fname[256]; //todo: убрать
};


struct WordData {
	void* value;
	size_t leng;
};

typedef union {
	BracketData  bracket_data; // struct_bracket or exec_bracket
	char byte; // byte
	unichar *text; // bytes, text
	infint num;  // integer
	double real; // real
	WordData word; // word
} DataContainerValue;


class DataContainer
{
public:
	DataContainer(const DataContainerType, const DataContainerValue, const size_t len=1);
	DataContainer(const DataContainerType tp){ ref_assert(tp==dummy); type=dummy; leng=1; };
	~DataContainer();

	DataContainer *prev;
	DataContainer *next;

	DataContainerType  type;
	DataContainerValue  value;

	size_t leng;
	DataContainer* copy();
protected:



private:
};

DataContainer* newRefWord(unistring wr);

DataContainer* newRefExecBrackets(rf_function fn, DataChain *chain, unistring fname);

DataContainer* newRefInteger(infint);

DataContainer* newRefStructBrackets(DataChain *chain);

DataContainer* newRefText(unistring str);


bool equal(DataChain *ch1, DataChain *ch2);
bool equal(DataCursor cur1, DataCursor cur2);
/*
inline bool equal(
	const DataContainerType &cont1_type,
	const DataContainerValue &cont1_value,
	const size_t &cur1_index,

	const DataContainerType &cont2_type,
	const DataContainerValue &cont2_value,
	const size_t &cur2_index){

	if (cont1_type != cont2_type) return false;

	switch (cont1_type){
	case struct_bracket:
				  return equal(cont1_value.bracket_data.chain, cont2_value.bracket_data.chain);
	case byte:    return cont1_value.byte==cont2_value.byte;
	case integer: return cont1_value.num==cont2_value.num;
	case real:	  return cont1_value.real==cont2_value.real;
	case word:	  return (cont1_value.word.leng==cont2_value.word.leng) && memcmp(cont1_value.word.value, cont2_value.word.value, cont1_value.word.leng*sizeof(unichar));
	case text:	  return (cont1_value.text)[cur1_index] == (cont2_value.text)[cur2_index];
	case bytes:	  return ((char*) cont1_value.text)[cur1_index] == ((char*) cont2_value.text)[cur2_index];
	default:	  SYSTEMERRORn("UNEXPECTED");
	}
};
*/
#endif // TERM_H

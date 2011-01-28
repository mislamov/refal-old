#ifndef TERM_H
#define TERM_H

#include <stddef.h>
#include "config.h"

class DataChain;
struct DataCursor;

typedef DataChain* (*rf_function)(DataCursor arg_from, DataCursor arg_to);

enum DataContainerType {
	byte,
	bytes,
	text,
	integer,
	real,

	word,
	struct_bracket,
	exec_bracket,
	dummy
};

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
	DataContainerValue value;

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

#endif // TERM_H

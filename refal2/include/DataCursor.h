#ifndef datacursor_h
#define datacursor_h

#include "DataContainerType.h"

#include <stddef.h>

class DataContainer;
class DataChain;

// указатель на элемент цепочки
class DataCursor {
public:
    DataContainer *container; // элемент содержится в этом контейнере
    size_t index; // index=, когда container простой; index = порядковому номеру элемента, когда container составной
    DataCursor& operator++ ();
    DataCursor& operator-- ();
    DataCursor operator-(const int&);
    DataCursor operator+(const int&);
    bool operator!=(const DataCursor);
    bool operator==(const DataCursor);
    bool operator! ();
	void next_container();

    DataCursor (DataContainer* c, size_t idx = 0);
    DataCursor (int i=0);

	void replaceBy(DataChain *chain);

	DataContainerType getType();
};

inline bool DataCursor::operator==(const DataCursor cur){
	return container==cur.container && index==cur.index;
}

inline bool DataCursor::operator!=(const DataCursor cur){
	return container!=cur.container || index!=cur.index;
}


#endif

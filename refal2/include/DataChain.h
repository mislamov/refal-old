#ifndef DATACHAIN_H
#define DATACHAIN_H

#include "DataContainer.h"
#include "config.h"

class DataChain;


struct DataCursor {
    DataContainer *container;
    size_t index;

    DataCursor& operator++ ();
    DataCursor& operator-- ();
    DataCursor operator-(const int&);
    DataCursor operator+(const int&);
    bool operator!=(const DataCursor);
    bool operator==(const DataCursor);
    bool operator! ();
	void next_container(){
		ref_assert(container && container->type!=dummy);
		container=container->next; index=0;
		ref_assert(container->leng!=0 || container->type==dummy);
	};

    DataCursor (DataContainer* c){
        container = c;
        index = 0;
    };

    DataCursor (int i=0){
        ref_assert(i==0);
        container=0;
        index=0;
    };

	void replaceBy(DataChain *chain);
};




class DataChain
{
    public:
        DataChain();
        ~DataChain();

       	DataChain*  append(DataContainer *con);
       	DataChain*  append_copy(DataCursor cur_from, DataCursor cur_to);

       	DataCursor at_before_first(){ return before_first_cursor; };
       	DataCursor at_last(){ return after_last_cursor-1; };
       	DataCursor at_first(){ return before_first_cursor+1; };
       	DataCursor at_after_last(){ return after_last_cursor; };

        bool isEmpty(){ return before_first_cursor.container->next == after_last_cursor.container; };

        unistring debug();
    protected:
    private:
        DataCursor before_first_cursor;
        DataCursor after_last_cursor;
};

DataChain* text_to_chain(unistring);
unistring chain_to_text(DataCursor prebeg, DataCursor end);

inline bool DataCursor::operator==(const DataCursor cur){
	return container==cur.container && index==cur.index;
}

inline bool DataCursor::operator!=(const DataCursor cur){
	return container!=cur.container || index!=cur.index;
}

inline DataCursor& DataCursor::operator++ (){
	ref_assert( container!=0 && container->leng>0);

	if (container->leng==1 || index+1==container->leng){
		// перемещение между контейнерами
		container = container->next;
		ref_assert(container->leng!=0 || container->type==dummy);
		index = 0;
		return *this;
	}
	// перемещение внутри контейнера
	++index;
	return *this;
}



#endif // DATACHAIN_H

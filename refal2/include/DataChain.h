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

#endif // DATACHAIN_H

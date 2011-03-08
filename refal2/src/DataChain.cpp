#include "DataChain.h"

#include "direfal.h"

#include <sstream>
#include <cstring>



DataChain::DataChain()
{
	//ctor
	//before_first_cursor = new DataCursor();
	//after_last_cursor   = new DataCursor();

	DataContainer *contA = new DataContainer(dummy);
	DataContainer *contZ = new DataContainer(dummy);
	before_first_cursor.container = contA;
	after_last_cursor.container = contZ;
	contA->prev = contZ->next = 0;
	contA->next = contZ;
	contZ->prev = contA;

	before_first_cursor.index = 0;
	after_last_cursor.index = 0;
}


DataChain::~DataChain()
{
	//dtor
}

bool DataChain::isEmpty(){ 
	return before_first_cursor.container->next == after_last_cursor.container; 
};


DataChain*  DataChain::append(DataContainer *con){
	if (!con) return this;
	ref_assert(con->prev == con->next && con->prev==0);

	DataContainer *A = after_last_cursor.container->prev;
	DataContainer *B = after_last_cursor.container;

	con->prev = A;
	con->next = B;
	A->next = con;
	B->prev = con;

	return this;
}

DataChain*  DataChain::append_copy(DataCursor cur_prefrom, DataCursor cur_to){
	if (cur_prefrom==cur_to) return this;

//	static long ii = 0;
//	ii++;

	//todo: реализовано очень неэффективно (копирование)! обяательно переделать!
	DataCursor i=cur_prefrom+1;

	// если все внутри одного контейнера (array)
	if (i.container == cur_to.container){
		if (i.container->leng==1 /*&& cur_to.container->leng==1*/){
			this->append(i.container->copy());
			return this;
		}

		DataContainer *cc = i.container->copy();
		cc->leng = cur_to.index-i.index+1;
		if (i.container->type==bytes){
			cc->value.text = i.container->value.text + i.index;
		} else if (i.container->type==text) {
			cc->value.text = i.container->value.text + i.index;
		} else {
			notrealisedERRORn;
		}
		this->append( cc );
		return this;
	}

	// если начало цепочки - часть контейнера
	if (i.container->leng > 1 && i.index > 0){
		// нужна лишь часть контейнера (array)
		DataContainerType type = i.container->type;
		DataContainerValue value = i.container->value;
		DataContainer *container = new DataContainer(type, value, i.container->leng - i.index);
		if (type==text){
			container->value.text = i.container->value.text + i.index;
		} else if (type==bytes) {
			value.text = i.container->value.text + i.index;
			container->value = value; //todo: дебагом проверить нужно ли
		} else {
			SYSTEMERRORn("UNREALISED");
		}
		this->append(container);
		i.next_container();
	}



	// начинка цепочки
	while(i.container!=cur_to.container) {
		this->append(i.container->copy());
		i.next_container();
	};


	// конец цепочки
	ref_assert(cur_to.container==i.container);
	if (cur_to.container->leng > 1 && cur_to.index < cur_to.container->leng-1){
		// нужна лишь часть контейнера (array)
		DataContainerType type = cur_to.container->type;
		DataContainerValue value = cur_to.container->value;
		DataContainer *container = new DataContainer(type, value, cur_to.index+1);
		this->append(container);
	} else {
		this->append(cur_to.container->copy());
	}
	return this;
}

DataChain* text_to_chain(unistring str)
{
	DataChain* ch = new DataChain();
	if (str!=""){
		DataContainerValue vv;

		unichar* buff = new unichar[str.length()];
		memcpy(buff, str.c_str(), str.length()*sizeof(unichar));
		vv.text = buff;

		ch->append( new DataContainer(text, vv, str.length()));
	}
	return ch;
}

unistring chain_to_text(DataCursor prebeg, DataCursor end){
	if (prebeg==end) return "";

	std::stringstream str;
	DataCursor i = prebeg+1;
	DataCursor iend = end+1;

	do {
		switch (i.container->type){
		case integer:
			str << i.container->value.num;
			str << " ";
			break;
		case word:
			str << "\"";
			str << (char*)i.container->value.word.value;
			str << "\" ";
			break;
		case text:
			//str << "\'";
			str.write(i.container->value.text + i.index, i.container->leng-i.index);
			//str << "\' ";
			break;
		case struct_bracket:
			str << " (";
			str << i.container->value.bracket_data.chain->debug();
			str << ") ";
			break;
		case exec_bracket:
			str << " <" << i.container->value.bracket_data.fname << " ";
			str << i.container->value.bracket_data.chain->debug();
			str << "> ";
			break;
		default:
			str << " UNKNOWN ";
		}

		i.next_container();
	} while (i!=iend);

	str << "\0";
	return str.str();
};

unistring DataChain::debug(){
	std::stringstream str;
	if (this==0){
		str << " /*empty*/ ";
		return str.str();
	}

	DataCursor i = this->at_first();
	DataCursor iend = this->at_after_last();

	while (i!=iend){
		switch (i.container->type){
		case integer:
			str << i.container->value.num;
			str << " ";
			break;
		case word:
			str << "\"";
			str.write((char*)i.container->value.word.value, i.container->value.word.leng);
			//str << (char*)i.container->value.word.value;
			str << "\" ";
			break;
		case text:
			str << "\'";
			str.write(i.container->value.text, i.container->leng);
			//str << (char*)i.container->value.array;
			str << "\' ";
			break;
		case struct_bracket:
			str << " ( ";
			str << i.container->value.bracket_data.chain->debug();
			str << " ) ";
			break;
		case exec_bracket:
			str << " < " << i.container->value.bracket_data.fname << " ";
			str << i.container->value.bracket_data.chain->debug();
			str << " > ";
			break;
		default:
			str << " DEFAULT ";
		}

		i.next_container();
	}
	return str.str();
}


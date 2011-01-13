#include "DataChain.h"

#include <sstream>

DataCursor& DataCursor::operator++ (){
	ref_assert( container!=0 && container->leng>0);
	if (container->leng==1 || index+1==container->leng){
		// перемещение между контейнерами
		container = container->next;
		index = 0;
		return *this;
	}
	// перемещение внутри контейнера
	++index;
	return *this;
}

DataCursor& DataCursor::operator-- (){
	ref_assert( container!=0 && container->leng>0);
	if (container->leng==1 || index==0){
		// перемещение между контейнерами
		container = container->prev;
		index = container->leng-1;
		return *this;
	}
	// перемещение внутри контейнера
	--index;
	return *this;
}

DataCursor DataCursor::operator-(const int& i){
	ref_assert(i==1);
	ref_assert(container!=0);

	DataCursor result = *this;
	--result;
	return result;
}

DataCursor DataCursor::operator+(const int& i){
	ref_assert(i==1);
	ref_assert(container!=0);

	DataCursor result = *this;
	++result;
	return result;
}

bool DataCursor::operator!=(const DataCursor cur){
	return container!=cur.container || index!=cur.index;
}

bool DataCursor::operator==(const DataCursor cur){
	return container==cur.container && index==cur.index;
}

bool DataCursor::operator! (){
	return container==0;
}



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

	//todo: реализовано очень неэффективно (копирование)! обяательно переделать!
	DataCursor i=cur_prefrom+1;

	// если все внутри одного контейнера (array)
	if (i.container == cur_to.container){
		DataContainer *cc = i.container->copy();
		cc->leng = cur_to.index-i.index+1;
		if (i.container->type==bytes){
			cc->value.array = ((char*)i.container->value.array) + i.index;
		} else if (i.container->type==text) {
			cc->value.array = ((unichar*)i.container->value.array) + i.index;
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
		DataContainer container(type, value, i.container->leng - i.index);
		if (type==text){
			container.value.array = ((unichar*) i.container->value.array) + i.index;
		} else if (type==bytes) {
			value.array = ((char*) i.container->value.array) + i.index;
			container.value = value; //todo: дебагом проверить нужно ли
		} else {
			SYSTEMERRORn("UNREALISED");
		}
		i.next_container();
	}

	// начинка цепочки
	do {
		this->append(i.container->copy());
		i.next_container();
	} while(i!=cur_to);


	// конец цепочки
	if (i.container->leng > 1 && i.index < i.container->leng-1){
		// нужна лишь часть контейнера (array)
		DataContainerType type = i.container->type;
		DataContainerValue value = i.container->value;
		DataContainer container(type, value, i.index+1);
	} else {
		this->append(i.container->copy());
	}
	return this;
}

DataChain* text_to_chain(unistring str)
{
	DataChain* ch = new DataChain();
	if (str!=""){
		DataContainerValue vv;
		
		unichar* buff = new unichar[str.length()];
		strncpy(buff, str.c_str(), str.length());
		vv.array = buff;

		ch->append( new DataContainer(text, vv, str.length()));
	}
	return ch;
}

unistring chain_to_text(DataCursor prebeg, DataCursor end){
	std::stringstream str;
	DataCursor i = prebeg+1;
	DataCursor iend = end;

	while (i!=iend){
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
			str << "\'";
			str << (char*)i.container->value.array;
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
			str << " UNKNOWN ";
		}

		++i;
	}
	str << "\0";
	return str.str();
};

unistring DataChain::debug(){
	std::stringstream str;
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
			str.write((unichar*)i.container->value.array, i.container->leng);
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


void DataCursor::replaceBy(DataChain *chain){
	ref_assert(container!=0);
	ref_assert(container->type==exec_bracket); // пока используется только для замены <> на результат

	DataContainer *aa = container->prev;
	DataContainer *ab = container->next;

	if (!chain || chain->isEmpty()){
		aa->next = ab;
		ab->prev = aa;
		return;
	}

	DataContainer *ba = chain->at_first().container;
	DataContainer *bb = chain->at_last().container;

	aa->next = ba;
	ab->prev = bb;
	ba->prev = aa;
	bb->next = ab;

	chain->at_before_first().container->next = chain->at_after_last().container; 
	chain->at_after_last().container->prev = chain->at_before_first().container;
}
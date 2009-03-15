#include "datastructs.h"
#include "session.h"

#include <sstream>

//--------------------------------------------------------------------------
bool RefData_DOT::operator ==(RefData &rd) {
                RefData_DOT *aux = dynamic_cast<RefData_DOT *>(&rd);
                return  aux && (aux->is_opened == is_opened);
};

TResult RefData_DOT::init(Session* s, RefData *&l){
        RefData_DOT* aux;
		if (is_opened){ // (
			aux = dynamic_cast<RefData_DOT *>(l);

			if (aux && aux->is_opened){ return GO;}; // DOT не двигает указатель на след. аргумент
			return ERROR;
		};

		// )
		move_to_next_term(l, this->myid(), s);
		aux = dynamic_cast<RefData_DOT *>(l);
		if ( !aux || aux->is_opened) { return BACK; }
		return SUCCESS;
};

TResult RefData_DOT::back(Session* sess, RefData *&l, RefData *&r){
		if (is_opened) { /*sess->extention_number = 0;*/
		    return FAIL;
        };
		return BACK;
};


unistring  RefData_DOT::toString() {        std::ostringstream s;
        s << (is_opened?" [":" ]")
        /**/<< "." << std::hex << (unsigned short)this << ' '; /*<< ":other=" << (long)this->other << " ";/**/
//        s << "." << (long)this << ' ';
        ;
        return sss = s.str();
};
RefData* RefData_DOT::next_term( ThisId var_id, Session *s ) { return next; };
RefData* RefData_DOT::pred_term( ThisId var_id, Session *s ) { return pred; };







TResult  RefGroupBracket::init(Session *s, RefData *&l){
    /*
    if (isOpen()){	//      {
            //s->matchSessions.back()->StackOfGroupSkob.push(l); // кладем ссылку на ПЕРЕДначало аргумента группы - не надо
    } else {		//      }
		//s->matchSessions.back()->StackOfGroupSkob.pop();
		//RefData* z2 = l;
    };*/
    return GO;

};

TResult  RefGroupBracket::back(Session *s, RefData *&l, RefData *&r){
	/*if (is_opened) {	//	{
		s->StackOfGroupSkob.top()->drop(myid);
		s->StackOfGroupSkob.pop();
		//s->current_point = s->StackOfGroupSkob.extract();
	} else {		//	}
		ref_DATA *l, *r;
		s->RestoreTempl(l, r);
		s->StackOfGroupSkob.push( l ? l->pred_point(other->myid, s) : r );
//		lbl(); lbl();
		r->drop(myid);
	};*/
	return BACK;

};


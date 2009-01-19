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




////////////////////////////////////////////////
//

    unistring  RefData_DOT::toString() {
        std::ostringstream s;
//        s << "@DOT(" << (is_opened?"opened":"closed") << ")." << (long)this << ":other=" << (long)this->other << " ";  return s.str(); };
        s << (is_opened?" [":" ]"); /*<< ")." << (long)this << ":other=" << (long)this->other << " ";*/
        s << "." << (long)this << ' ';
        return s.str();
    };
	RefData* RefData_DOT::next_term( ThisId var_id, Session *s ) { return next; };
	RefData* RefData_DOT::pred_term( ThisId var_id, Session *s ) { return pred; };



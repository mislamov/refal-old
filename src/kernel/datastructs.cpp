#include "datastructs.h"
#include "session.h"

#include <sstream>

/**-----------------  границы  --------------------------**/

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



/**------------------- группа -----------------**/

TResult  RefGroupBracket::init(Session *s, RefData *&l){
    return GO;
};
TResult  RefGroupBracket::back(Session *s, RefData *&l, RefData *&r){
	return BACK;
};


/**-------------------  варианты  ---------------------**/

//-----------  o  -----------
ref_variant_dot::ref_variant_dot( RefData* rp) : RefData(rp) { is_system=false; };
RefData*   ref_variant_dot::pred_point (ThisId id, Session *s) {
    //if (s->StopBrackForceVar) return krest;
    /// todo: обработать принудительный откат (когда forceback)
    return nextffwd;
};

TResult	   ref_variant_dot::init(Session *s, RefData *&l) {
    #ifdef DEBUG
    TVarBody* vb = dynamic_cast<TVarBody *>( s->matchSessions.back()->StackOfSopost.top());
    if ((!vb) || (! dynamic_cast<RefBracketBase *>(vb->owner)))
        SYSTEMERROR("net ozhifaemoj skobki na vershine steka sopostavlenij");
    #endif
    l = ((TVarBody *)( s->matchSessions.back()->StackOfSopost.top()))->second;
    return GO;
};
TResult	   ref_variant_dot::back(Session *s, RefData *&l, RefData *&r) { /*l = r = s->StackOfGroupSkob.top();*/ return BACK; };
bool	   ref_variant_dot::operator==(RefData&rd){ return false; };

//----------  |  ------------
ref_variant_vert::ref_variant_vert( RefData* rp) : RefData(rp) { is_system=false; };
TResult	   ref_variant_vert::init(Session *s, RefData *&l)	{ s->matchSessions.back()->StackOfVariants.push(this); return GO;};
RefData*   ref_variant_vert::next_point (ThisId id, Session*) { return vopr->next; }; //  return "}.vname"
void       ref_variant_vert::forceback (Session *s)	{ s->matchSessions.back()->StackOfVariants.pop(); };
bool	   ref_variant_vert::operator==(RefData&rd){ return false; };

//----------  =>  ------------
ref_variant_ffwd::ref_variant_ffwd(RefData *rp) : RefData (rp) { is_system=false; };
TResult	 ref_variant_ffwd::init(Session *, RefData *&l) { return GO; };
TResult	 ref_variant_ffwd::back(Session *, RefData *&l, RefData *&r) { return GO; };
bool	 ref_variant_ffwd::operator==(RefData&rd){ return false; };

//----------  ?  ------------
ref_variant_vopr::ref_variant_vopr( RefData* rp) : RefData(rp) { is_system=false; };
TResult		ref_variant_vopr::init(Session *, RefData *&l) { return BACK; };
RefData*	ref_variant_vopr::pred_point (ThisId id, Session *s) {
		ref_variant_vert *rvv = s->matchSessions.back()->StackOfVariants.top();
		s->matchSessions.back()->StackOfVariants.pop();
		return rvv;
};
bool ref_variant_vopr::operator==(RefData&rd){ return false; };

//----------  x  ------------
ref_variant_krest::ref_variant_krest( RefData* rp) : RefData(rp) { is_system=false; };
TResult		ref_variant_krest::init(Session *, RefData *&l) { return BACK; };
RefData*	ref_variant_krest::pred_point (ThisId id, Session *s) { return begbr; };
bool ref_variant_krest::operator==(RefData&rd){ return false; };




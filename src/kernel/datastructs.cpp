// D-Refal - sentential program language
// Copyright (C) 2008-2009 Islamov Marat Shamilevich
// islamov.marat@gmail.com
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

#include "datastructs.h"
#include "session.h"

#include <sstream>

/**-----------------  границы  --------------------------**/

bool RefData_DOT::operator ==(RefData &rd) {
        RefData_DOT *aux = ref_dynamic_cast<RefData_DOT >(&rd);
        return  aux && (aux->is_opened == is_opened);
};

TResult RefData_DOT::init(RefData*&tpl, Session* s, RefData *&l){
        RefData_DOT* aux;
		if (is_opened){ // (
			aux = ref_dynamic_cast<RefData_DOT >(l);

			if (aux && aux->is_opened){ return GO;}; // DOT не двигает указатель на след. аргумент
			return ERROR;
		};

		// )
		//move_to_next_term(l, 0/*this->myid()*/, s);
		MOVE_TO_NEXT_TERM(l, 0/*this->myid()*/, s);
		aux = ref_dynamic_cast<RefData_DOT >(l);
		if ( !aux || aux->is_opened) { return BACK; }
		return SUCCESS;
};

TResult RefData_DOT::back(RefData*&tpl, Session* sess, RefData *&l, RefData *&r){
		if (is_opened) { /*sess->extention_number = 0;*/
		    return FAIL;
        };
		return BACK;
};


unistring  RefData_DOT::toString() {
        #ifndef DEBUG
        return "";
        #endif
        std::ostringstream s;
        s << (is_opened?" [":" ]")
        /*  << "." << std::hex << (unsigned short)this << ' '; //<< ":other=" << (long)this->other << " ";// */
//        s << "." << (long)this << ' ';
        ;
        return s.str();
};
RefData* RefData_DOT::next_term( ThisId var_id, Session *s ) { return next; };
RefData* RefData_DOT::pred_term( ThisId var_id, Session *s ) { return pred; };



/**------------------- группа -----------------**/

TResult  RefGroupBracket::init(RefData*&tpl, Session *s, RefData *&l){
    return GO;
};
TResult  RefGroupBracket::back(RefData*&tpl, Session *s, RefData *&l, RefData *&r){
	return BACK;
};


/**-------------------  варианты  ---------------------**/

//-----------  o  -----------
ref_variant_dot::ref_variant_dot( RefData* rp) : RefData(rp) { is_system (false); };

RefData*   ref_variant_dot::pred_template (ThisId id, Session *s) {
    if (s->result_sost == FORCEBACK){ return krest; };
    return nextffwd;
};

TResult	   ref_variant_dot::init(RefData*&tpl, Session *s, RefData *&l) {
    #ifdef TESTCODE
    TVarBody* vb = dynamic_cast<TVarBody *>( s->matchSessions.back()->StackOfSopost.top());
    if ((!vb) || (! dynamic_cast<RefGroupBracket *>(vb->owner)))
        SYSTEMERROR("net ozhifaemoj skobki na vershine steka sopostavlenij");
    #endif
    l = ((TVarBody *)( s->matchSessions.back()->StackOfSopost.top()))->second;
    return GO;
};

TResult	   ref_variant_dot::back(RefData*&tpl, Session *s, RefData *&l, RefData *&r) {
    //return BACK; //- po logike pravilno
	// optimizacija:

	SessionOfMaching* &subsess = s->matchSessions.back();
	RefData* &savedL = subsess->matching_savedL ;

	savedL = l = r = ((TVarBody *)( subsess->StackOfSopost.top()))->second;
	//TResult res = doGOandINIT(tpl = nextffwd->getNext()->getNext(), s, s->matchSessions.back());
	
	//if (ref_dynamic_cast<ref_variant_dot>(nextffwd->getNext())){
	//	doGOandINIT(tpl = nextffwd->getNext(), s, s->matchSessions.back());
	//}

	TResult res = doGOandINIT(tpl = nextffwd->getNext(), s, s->matchSessions.back());
	return res;

    //l = ((TVarBody *)( s->matchSessions.back()->StackOfSopost.top()))->second;
	//return doGOandINIT(tpl = nextffwd->getNext()->getNext(), s, s->matchSessions.back());

    //tpl = nextffwd;//->next_template(0, s);
    //return GO;
};

bool	   ref_variant_dot::operator==(RefData&rd){ return false; };

//----------  |  ------------
ref_variant_vert::ref_variant_vert( RefData* rp) : RefData(rp) { is_system (false); };
TResult	   ref_variant_vert::init(RefData*&tpl, Session *s, RefData *&l)	{ 
	s->matchSessions.back()->StackOfVariants.push(this); 
	return GO;
};
TResult	   ref_variant_vert::back(RefData*&tpl, Session *s, RefData *&l, RefData *&r)	{ s->matchSessions.back()->StackOfVariants.pop(); return BACK;};
RefData*   ref_variant_vert::next_template (ThisId id, Session*) { return vopr->getNext(); }; //  return "}.vname"
void       ref_variant_vert::forceback (Session *s)	{ s->matchSessions.back()->StackOfVariants.pop(); };
bool	   ref_variant_vert::operator==(RefData&rd){ return false; };

//----------  =>  ------------
ref_variant_ffwd::ref_variant_ffwd(RefData *rp) : RefData (rp) { is_system (false);};
TResult	 ref_variant_ffwd::init(RefData*&tpl, Session *, RefData *&l) { return GO; };
TResult	 ref_variant_ffwd::back(RefData*&tpl, Session *, RefData *&l, RefData *&r) { return GO; };
bool	 ref_variant_ffwd::operator==(RefData&rd){ return false; };

//----------  ?  ------------
ref_variant_vopr::ref_variant_vopr( RefData* rp) : RefData(rp) { is_system (false);};
TResult		ref_variant_vopr::init(RefData*&tpl, Session *, RefData *&l) { return BACK; };
TResult     ref_variant_vopr::back(RefData*&tpl, Session* s, RefData *&l, RefData *&r){ return BACK; }; //
RefData*	ref_variant_vopr::pred_template (ThisId id, Session *s) {
        //if (s->message4nextpred == mFORCEBACK){ return pred; } - закрыл, так как откатывать надо не последний вариант а сопоставленный
		ref_variant_vert *rvv = s->matchSessions.back()->StackOfVariants.top();
		return rvv;
};
bool ref_variant_vopr::operator==(RefData&rd){ return false; };
void ref_variant_vopr::forceback(Session* s){
    //s->matchSessions.back()->StackOfVariants.pop();
};

//----------  x  ------------
ref_variant_krest::ref_variant_krest( RefData* rp) : RefData(rp) { is_system (false);};
TResult		ref_variant_krest::init(RefData*&tpl, Session *, RefData *&l) { return BACK; };
RefData*	ref_variant_krest::pred_template (ThisId id, Session *s) { return begbr; };
bool ref_variant_krest::operator==(RefData&rd){ return false; };





//----------  [...]  ------------
TResult  ref_repeater::init(RefData*&tpl, Session *s, RefData *&l){
    if (isOpen()){ ///  [
        if (! getMin()){ // [0..x]
            s->message4nextpred = mOTHER_next; // выходим из варианта
            s->matchSessions.back()->StackOfRepeaterDoned.push(0);
        } else {
            s->matchSessions.back()->StackOfRepeater.push(0);
            s->message4nextpred = mNEXT; // остаемся внутри варианта
        }
        return GO;
    }
    ///  ]
    infint currentStep = s->matchSessions.back()->StackOfRepeater.top();
    s->matchSessions.back()->StackOfRepeater.pop();
    ++currentStep;

    if (currentStep < getMin()){
        s->matchSessions.back()->StackOfRepeater.push(currentStep);  ///todo: рптимизировать ++(...top()) ?
        s->message4nextpred = mOTHER_next; // остаемся внутри варианта
        return GO;
    }
    s->message4nextpred = mNEXT; // уходим из варианта
    s->matchSessions.back()->StackOfRepeaterDoned.push(currentStep);
    return GO;

};

TResult  ref_repeater::back(RefData*&tpl, Session *s, RefData *&l, RefData *&r){
    if (isOpen()){   ///   [
        infint currentStep = s->matchSessions.back()->StackOfRepeater.top();
        if (currentStep){
            s->matchSessions.back()->StackOfRepeater.push(--currentStep);
            s->message4nextpred = mOTHER_pred; // внутри
            return BACK;
        }
        s->matchSessions.back()->StackOfRepeater.pop();
        s->message4nextpred = mPRED; // выходим из варианта
        return BACK;
    }
    ///   ]
    infint currentStep = s->matchSessions.back()->StackOfRepeaterDoned.top();
    s->matchSessions.back()->StackOfRepeaterDoned.pop();

    if (currentStep < getMax()){
        s->matchSessions.back()->StackOfRepeater.push( currentStep );
        s->message4nextpred = mOTHER_next;
        return GO;
    }
    --currentStep;
    s->matchSessions.back()->StackOfRepeater.push( currentStep );
    s->message4nextpred = mPRED;
    return BACK;
};

RefData*  ref_repeater::next_template (ThisId id, Session*s){
    switch (s->message4nextpred){
        case mNEXT: return next;
        case mPRED: return pred;
        case mOTHER_next: return other->getNext();
        case mOTHER_pred: return other->getPred();
        default:;
    }
    SYSTEMERROR("unexpected message");
};

RefData*  ref_repeater::pred_template (ThisId id, Session*s){
    switch (s->message4nextpred){
        case mNEXT: return next;
        case mPRED: return pred;
        case mOTHER_next: return other->getNext();
        case mOTHER_pred: return other->getPred();
        default:;
    }
    SYSTEMERROR("unexpected message");
};


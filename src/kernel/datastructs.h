#ifndef DATASTRUCTS_H_INCLUDED
#define DATASTRUCTS_H_INCLUDED

#include "data.h"

#include <sstream>


class RefData_DOT;
class ref_variant_dot;
class ref_variant_ffwd;
class ref_variant_krest;
class ref_variant_vert;
class ref_variant_vopr;

//---------- [  ] ----------
class RefData_DOT : public RefBracketBase { // begin- Рё end-
public:
	//~RefData_DOT(){ if(pred)next->pred=pred; if(pred)pred->next=next; };
	RefData_DOT(RefData* rp = 0) : RefBracketBase(rp){};
	RefData_DOT(RefData_DOT *nd, RefData* rp = 0) : RefBracketBase(nd, rp){};
    bool operator ==(RefData &rd);
	TResult  init(Session* s, RefData *&l); //
	TResult  back(Session* s, RefData *&l, RefData *&r); //

	virtual RefData*  next_term( ThisId var_id, Session *s );
	virtual RefData*  pred_term( ThisId var_id, Session *s );

    virtual RefData* Copy(RefData *where=0){ return new RefData_DOT(where); };
    virtual RefData* Copy(RefBracketBase *b, RefData *where=0){
            #ifdef DEBUG
            if (! dynamic_cast<RefData_DOT *>(b)) SYSTEMERROR(" unexpected bracket type: " << b->toString() << " ~ " << this->toString());
            #endif
            return new RefData_DOT((RefData_DOT *)b, where);
    };
    virtual unistring toString();

};



//-----------  o  -----------
class ref_variant_dot : public RefData/*, public IRefVar*/ { // IRefVar чтоб срабаытвал restoreTempl и saveTempl
    public:
        ref_variant_ffwd  *nextffwd;
        ref_variant_krest *krest;

        ref_variant_dot( RefData* rp=0);
        RefData*  pred_point (ThisId id, Session *s);
        TResult	   init	      (Session *s, RefData *&l);
        TResult	   back	      (Session *s, RefData *&l, RefData *&r);
        bool operator==(RefData&rd);

        virtual RefData* Copy(RefData *where=0){ SYSTEMERROR("zagl"); };
        virtual unistring toString(){
            return "-o- ";
            std::ostringstream ss;
            ss << " $o." << ((long)this);
            return ss.str();
        };
        /*
        unistring getName(){ return EmptyUniString; };
        void setName(unistring ){ SYSTEMERROR("alarm"); };
        */

};
//----------  |  ------------
class ref_variant_vert : public RefData {
    public:
        RefData *vopr;

        ref_variant_vert( RefData* rp=0);
        RefData*  next_point (ThisId id, Session*);
        bool operator==(RefData&rd);
        void forceback (Session *s);

	TResult  init(Session* s, RefData *&l); //
	TResult  back(Session* s, RefData *&l, RefData *&r){ SYSTEMERROR("zagl"); }; //
    virtual RefData* Copy(RefData *where=0){ SYSTEMERROR("zagl"); };
    virtual unistring toString(){ return " |";};

};
//----------  =>  ------------
class ref_variant_ffwd : public RefData {
    public:
        ref_variant_ffwd(RefData *rp=0);
        TResult	 init(Session *s, RefData *&l);
        TResult	 back(Session *s, RefData *&l, RefData *&r);
        bool operator==(RefData&rd);

    virtual RefData* Copy(RefData *where=0){ SYSTEMERROR("zagl"); };
    virtual unistring toString(){
        return "=>";
        std::ostringstream ss;
        ss << " =>." << (long)this;
        return ss.str();
    };

};
//----------  ?  ------------
class ref_variant_vopr : public RefData {
    public:
        ref_variant_vopr( RefData* rp=0);
        RefData*	pred_point (ThisId id, Session *s);
        bool operator==(RefData&rd);

	TResult  init(Session* s, RefData *&l); //
	TResult  back(Session* s, RefData *&l, RefData *&r){ SYSTEMERROR("zagl"); }; //
    virtual RefData* Copy(RefData *where=0){ SYSTEMERROR("zagl"); };
    virtual unistring toString(){ return "-?-";};

};
//----------  x  ------------
class ref_variant_krest : public RefData {
    public:
        RefData *begbr;

        ref_variant_krest(RefData* rp=0);
        virtual ~ref_variant_krest(){};
        RefData*	pred_point (ThisId id, Session *s);
        bool operator==(RefData&rd);

	TResult  init(Session* s, RefData *&l); //
	TResult  back(Session* s, RefData *&l, RefData *&r){ SYSTEMERROR("zagl"); }; //
    virtual RefData* Copy(RefData *where=0){ SYSTEMERROR("zagl"); };
    virtual unistring toString(){ return "-x-";};

};


////////////////  {o      | => o      | => o      | => x ?} ///////////////////
//---------- {  } ----------
class RefGroupBracket : public RefBracketBase, public RefalNameSpace {
    public:
        virtual ~RefGroupBracket(){};
        RefGroupBracket(unistring name, RefData *rp) : RefBracketBase(rp) { RefalNameSpace::setName(name); }; // оптимизировать
        RefGroupBracket(RefGroupBracket *oth, RefData *rp) : RefBracketBase(oth, rp) { RefalNameSpace::setName(oth->name); };
        //RefGroupBracket(RefBracketBase *oth, RefData *rp) : RefBracketBase(oth) {};
        TResult  init(Session *, RefData *&l);
        TResult  back(Session *, RefData *&l, RefData *&r);
        bool operator==(RefData&rd){ return false; };

        virtual unistring getName(){ return RefalNameSpace::getName(); }; /// todo: оптиизировать
        /*
        virtual RefData* Copy(RefData *where=0){ return new RefGroupBracket("", where); };
        virtual RefData* Copy(RefBracketBase *b, RefData *where=0){ return new RefGroupBracket(b, where); };
        */
        virtual RefData* Copy(RefData *where=0){ SYSTEMERROR("unexpected call"); };
        virtual RefData* Copy(RefBracketBase *b, RefData *where=0){ SYSTEMERROR("unexpected call"); };

        virtual unistring toString(){ return (isOpen() ? "{" : ("}."+name) ); };
        virtual void forceback(Session *){ /** todo: очищать подсессию до открывающей скобки */};
};



//-------- $NOT -----------//
class RefNot : public RefBracketBase {
    public:
        virtual ~RefNot(){};
        RefNot(RefData *rp=0) : RefBracketBase(rp){ };
        RefNot(RefNot *other, RefData *rp=0) : RefBracketBase(other, rp){ };

        virtual RefData* Copy(RefData *where=0){ SYSTEMERROR("unexpected call"); };
        virtual RefData* Copy(RefBracketBase*, RefData *rp=0)   { SYSTEMERROR("unexpected call"); };

        virtual unistring toString(){ return "$not "; };
        TResult  init(Session *, RefData *&l){ return (isOpen() ? GO : FAIL); };
        TResult  back(Session *, RefData *&l, RefData *&r){ return (isOpen() ? SUCCESS : BACK); };
        bool operator==(RefData&rd){ SYSTEMERROR("unexpected call"); return false; };

};

#endif // DATASTRUCTS_H_INCLUDED

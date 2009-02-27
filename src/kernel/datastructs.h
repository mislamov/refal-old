#ifndef DATASTRUCTS_H_INCLUDED
#define DATASTRUCTS_H_INCLUDED

#include "data.h"


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
class ref_variant_dot : public RefData {
    public:
	RefData *nextffwd, *krest;
	ref_variant_dot( RefData* rp);
	RefData*  pred_point (ThisId id, Session *s);
	TResult	   init	      (Session *s, RefData *&l);
	TResult	   back	      (Session *s, RefData *&l, RefData *&r);
//	void	   print_inf  ();
	bool operator==(RefData&rd);
};
//----------  |  ------------
class ref_variant_vert : public RefData {
    public:
	RefData *vopr;
	ref_variant_vert( RefData* rp);
	void	   print_inf ();
	TResult	   init (Session *s, RefData *&l);
	RefData*  next_point (ThisId id, Session*);
	void       dropall (Session *s);
	bool operator==(RefData&rd);
};
//----------  =>  ------------
class ref_variant_ffwd : public RefData {
    public:
	ref_variant_ffwd(RefData *rp);
	void	 print_inf( );
	TResult	 init(Session *s, RefData *&l);
	TResult	 back(Session *s, RefData *&l, RefData *&r);
	bool operator==(RefData&rd);
};
//----------  ?  ------------
class ref_variant_vopr : public RefData {
    public:
	ref_variant_vopr( RefData* rp);
	void 		print_inf ();
	TResult		init (Session *, RefData *&l);
	RefData*	pred_point (ThisId id, Session *s);
	bool operator==(RefData&rd);
};
//----------  x  ------------
class ref_variant_krest : public RefData {
    public:
	RefData *begbr;
	ref_variant_krest( RefData* rp, RefData *brop);
	virtual ~ref_variant_krest();
	void 		print_inf ();
	TResult		init (Session *, RefData *&l);
	RefData*	pred_point (ThisId id, Session *s);
	bool operator==(RefData&rd);
};

// --------- [ .. ] ------------
class ref_REPEATER : public RefBracketBase {
	RefData * from;
	RefData * to;

    public:
	virtual ~ref_REPEATER();
	ref_REPEATER( RefData *rp);
	ref_REPEATER( ref_REPEATER *br, RefData *rp, std::string varname, RefData* int1, RefData* int2);
	bool operator==(RefData&rd);

	//void print_inf();

	TResult  init(Session *, RefData *&l);
	TResult  back(Session *, RefData *&l, RefData *&r);
	void     dropall(Session *);

	virtual RefData*  next_point( ThisId var_id, Session *);
	virtual RefData*  pred_point( ThisId var_id, Session *);
};

////////////////  {o   | => o   | => o   | => x   ?} ///////////////////
//---------- {  } ----------
class ref_GROUP_BR : public RefBracketBase, public IRefVar {
    public:
        virtual ~ref_GROUP_BR(){};
        ref_GROUP_BR( RefData *rp);
        ref_GROUP_BR( ref_GROUP_BR *br, RefData *rp, std::string nn);
        bool operator==(RefData&rd);

        TResult  init(Session *, RefData *&l);
        TResult  back(Session *, RefData *&l, RefData *&r);
        void     dropall(Session *);
};




#endif // DATASTRUCTS_H_INCLUDED

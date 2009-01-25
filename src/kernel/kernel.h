#ifndef KERNEL_H_INCLUDED
#define KERNEL_H_INCLUDED

#include <iostream>
#include <sstream>

#include "data.h"




class RefVariable_e : public RefVariable {
    public:
        RefVariable_e(unistring name = EmptyUniString, RefData *rp=0) : RefVariable(name, rp){};

        TResult  init(Session *, RefData *&);
        TResult  back(Session *, RefData *&, RefData *&);
        void     dropall(Session *);
        bool operator==(RefData &rd);

    	virtual RefData*  Copy(RefData *d = 0){ return new RefVariable_e(getName()); };
    	virtual unistring toString(){ return " e."+getName()+" "; };
};

class RefVariable_E : public RefVariable {
    public:
        RefVariable_E(unistring name = EmptyUniString, RefData *rp=0) : RefVariable(name, rp){};

        void     dropall(Session *);
        bool operator==(RefData &rd);

        TResult  init(Session *, RefData *&);
        TResult  back(Session *, RefData *&, RefData *&);
    	virtual RefData*  Copy(RefData *d = 0){ return new RefVariable_E(getName()); };
    	virtual unistring toString(){ return "E."+getName(); };
};

class RefVariable_s : public RefVariable {
    public:
        RefVariable_s(unistring name = EmptyUniString, RefData *rp=0) : RefVariable(name, rp){};
        //void     dropall(Session *);
        bool operator==(RefData &rd){};

        TResult  init(Session *, RefData *&);
        TResult  back(Session *, RefData *&, RefData *&);
    	virtual RefData*  Copy(RefData *d = 0){ return new RefVariable_s(getName()); };
    	virtual unistring toString(){ return " s."+getName()+" "; };
};

class RefVariable_t : public RefVariable {
    public:
        RefVariable_t(unistring name = EmptyUniString, RefData *rp=0) : RefVariable(name, rp){ return; };

        bool operator==(RefData &rd){};

        TResult  init(Session *, RefData *&);//{ SYSTEMERROR(""); };
        TResult  back(Session *, RefData *&, RefData *&);//{ SYSTEMERROR(""); };
    	virtual RefData*  Copy(RefData *d = 0){ return new RefVariable_t(getName()); };
    	virtual unistring toString(){ return "t."+getName(); };
};


/*************************
*   Скобки
**************************/
class RefStructBracket : public RefBracketBase {
    public:
        RefStructBracket(RefData* rp=0);
        RefStructBracket(RefStructBracket *br, RefData* rp=0);

        bool       operator ==(RefData &);
        RefData*  next_term( ThisId );
        RefData*  pred_term( ThisId );
        TResult    init( Session* , RefData *& );
        TResult    back( Session* , RefData *&, RefData *& );
        void    forceback(Session *);
        unistring toString(){
            std::ostringstream s;
            s << (isOpen()?"(":") ") ;//<< "." << (long)this << ":other=" << (long)other;
            return s.str();
        };

        RefData* Copy(RefData *rp){
            RefStructBracket* br = new RefStructBracket(rp);
            return new RefNULL(br);
        };
        RefData* Copy(RefBracketBase *b, RefData *rp){
            #ifdef DEBUG
            if (!dynamic_cast<RefStructBracket *>(b)) SYSTEMERROR("Closed brackets error: " << b->toString() << " with " << this->toString());
            #endif
            return new RefStructBracket((RefStructBracket *)b, rp);
        };

};


class RefExecBracket : public RefBracketBase {
    public:
        RefExecBracket(RefData* rp=0);
        RefExecBracket(RefExecBracket *br, RefData* rp=0);

        bool       operator ==(RefData &rd);
        RefData*  next_term( ThisId var_id );
        RefData*  pred_term( ThisId var_id );
        TResult    init( Session* s, RefData *&l );
        TResult    back( Session* s, RefData *&l, RefData *&r );
        unistring toString(){
            std::ostringstream s;
            s << (isOpen()?"<":"> ") ;//<< "." << (long)this << "other:" << (long)other;
            return s.str();
        };

        RefData* Copy(RefData *rp){
            RefExecBracket* br = new RefExecBracket(rp);
            return new RefNULL(br);
        };
        RefData* Copy(RefBracketBase *b, RefData *rp){
            #ifdef DEBUG
            if (!dynamic_cast<RefExecBracket *>(b)) SYSTEMERROR("Closed brackets error: " << b->toString() << " with " << this->toString());
            #endif
            return new RefExecBracket((RefExecBracket *)b, rp);
        };
};



unistring vectorToString(RefData *f, RefData *g);
void print_vector(RefData *f, RefData *t=0);

#endif // DATATERMS_H_INCLUDED


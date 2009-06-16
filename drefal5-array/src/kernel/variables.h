#ifndef REF_VARIABLES_H_INCLUDED
#define REF_VARIABLES_H_INCLUDED

#include "data.h"



class RefVariable_e : public RefVariable {
public:
    CLASS_OBJECT_CAST(RefVariable_e);

    RefVariable_e(unistring name = EmptyUniString) : RefVariable(name) {};

    TResult  init(RefData **&tpl, Session *, RefData **&, RefData **&);
    TResult  back(RefData **&tpl, Session *, RefData **&, RefData **&);
    bool operator==(RefData &rd);

    virtual unistring explode() {
        return " e."+getName()+" ";
    };
};



#endif

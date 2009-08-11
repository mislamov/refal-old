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
    virtual unistring explode() {        return " e."+getName()+" ";    };
};



class RefVariable_E : public RefVariable {
public:
    CLASS_OBJECT_CAST(RefVariable_E);

    RefVariable_E(unistring name = EmptyUniString) : RefVariable(name) {};

    TResult  init(RefData **&tpl, Session *, RefData **&, RefData **&);
    TResult  back(RefData **&tpl, Session *, RefData **&, RefData **&);
    bool operator==(RefData &rd);
    virtual unistring explode() {        return " E."+getName()+" ";    };
};


class RefVariable_s : public RefVariable {
public:
    CLASS_OBJECT_CAST(RefVariable_s);

    RefVariable_s(unistring name = EmptyUniString) : RefVariable(name) {};

    TResult  init(RefData **&tpl, Session *, RefData **&, RefData **&);
    TResult  back(RefData **&tpl, Session *, RefData **&, RefData **&);
    bool operator==(RefData &rd);
    virtual unistring explode() {        return " s."+getName()+" ";    };
};


class RefVariable_t : public RefVariable {
public:
    CLASS_OBJECT_CAST(RefVariable_t);

    RefVariable_t(unistring name = EmptyUniString) : RefVariable(name) {};

    TResult  init(RefData **&tpl, Session *, RefData **&, RefData **&);
    TResult  back(RefData **&tpl, Session *, RefData **&, RefData **&);
    bool operator==(RefData &rd);
    virtual unistring explode() {        return " t."+getName()+" ";    };
};



#endif

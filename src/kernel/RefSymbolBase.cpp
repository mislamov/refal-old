#ifndef REFSYMBOLBASE_CPP_INCLUDED
#define REFSYMBOLBASE_CPP_INCLUDED

#include <iostream>
//#include <sstream>

#include "RefSymbolBase.hxx"
#include "kernel.h"
#include "data.h"

// счетчик для контроля утечек памяти
long symcount = 0;
long RefValuedData::getCount(){ return symcount; };



template <class T>
TResult RefSymbolBase <T>::init(Session* s, RefData *&l) {
    move_to_next_term(l,myid(),s);
    RefData* aux = l;
    #ifdef DEBUG
        if (!aux) { SYSTEMERROR("RefData::init() tring to matching with NULL address!"); };
    #endif
    //std::cout << "\n?::: "; print_inf(); std::cout << "=="; aux->print_inf(); std::cout << std::flush;
    bool tmpr = (*this == *aux);
    //aux->drop(myid());
    if (tmpr) return GO;
    //s->get_moved_to_pred_current_term(myid);
    move_to_next_term(l,myid(),s);
    return BACK;
};

template <class T>
    TResult RefSymbolBase <T>::back(Session* s, RefData *&l, RefData *&r) {
        //s->get_moved_to_pred_current_term(myid);
        return BACK;
};

template <class T>
    RefSymbolBase<T>::~RefSymbolBase(){
                symcount--;
};

template <class T>
    RefSymbolBase<T>::RefSymbolBase(RefData *rp) : RefValuedData(rp){
        this->is_system = false;
        symcount++;
};
/*template <class T>
    void RefSymbolBase<T>::setValue(T i){};
*/
template <class T>
    bool RefSymbolBase<T>::operator ==(RefData &rd){
        RefSymbolBase<T> *t = dynamic_cast<RefSymbolBase<T>*>(&rd);
        return t && (t->getValue()==this->getValue());
    };



template <class T>
    RefSymbol<T>::RefSymbol(T i, RefData *rp) : RefSymbolBase<T>(rp){ this->setValue(i); /*this->is_system = false;*/ };

template <class T>
    RefSymbol<T>::RefSymbol(RefData *rp) : RefSymbolBase<T>(rp){ return;/*this->is_system = false;*/ };

template <class T>
    T RefSymbol<T>::getValue() { return value; };

template <class T>
    void RefSymbol<T>::setValue(T i) { value = i; };

template <class T>
    RefData* RefSymbol<T>::Copy(RefData *where){
        return new RefSymbol<T>(getValue(), where);
};

template <class T>
    unistring RefSymbol<T>::toString(){
        std::ostringstream s;
        s
        //   << "RefSymbol("
        << this->getValue()
        //   << ") "
        ;
        //return s.string();
        return s.str();
};



template <class T>
    TResult RefVarForSymbol<T>::init(Session* s, RefData *&l){
        move_to_next_point(l, myid(), s);
        if (dynamic_cast<T *>(l))
            return GO;
        else
            return BACK;
    };

template <class T>
    TResult RefVarForSymbol<T>::back(Session* s, RefData *&l, RefData *&r){
        return BACK;
    };

template <class T>
    RefVarForSymbol<T>::RefVarForSymbol (unistring name, RefData *rp) : RefVariable(name, rp){};

template <class T>
    bool RefVarForSymbol<T>::operator ==(RefData &rd){ return false; };






RefVariable *getVariableByTypename(unistring nametype, unistring vn){
    if (nametype == "word") return new RefVarWord(vn);
    if (nametype == "int") return new RefVarInteger(vn);
    if (nametype == "real") return new RefVarReal(vn);
    if (nametype == "char") return new RefVarAlpha(vn);
    if (nametype == "byte") return new RefVarByte(vn);
    if (nametype == "e") return new RefVariable_e(vn);
    if (nametype == "E") return new RefVariable_E(vn);
    if (nametype == "s") return new RefVariable_s(vn);
    if (nametype == "t") return new RefVariable_t(vn);
    return new RefUserVar(nametype, vn);
};


RefData *getNewEmptyRefSymbolByTypeName(unistring nametype){
    if (nametype == "WORD") return new RefWord();
    if (nametype == "INT") return new RefInteger();
    if (nametype == "REAL") return new RefReal();
    if (nametype == "ALPHA") return new RefAlpha();
    if (nametype == "BYTE") return new RefByte();
    return 0;
}




///     ПЕРЕГРУЖЕННЫЕ МЕТОДЫ
void RefSymbol<unichar>::setValueFromString(unistring s){
    setValue( s[0] );
}


void RefSymbol<char>::setValueFromString(unistring s){
    setValue((char)s[0] );
}

void RefSymbol<infint>::setValueFromString(unistring s){
    setValue( strtoul(s.c_str(), 0, 10) );
}

void RefSymbol<infreal>::setValueFromString(unistring s){
    setValue( strtof(s.c_str(), 0) );
}

void RefSymbol<unistring>::setValueFromString(unistring s){
    setValue( s );
}





unistring RefSymbol<unistring>::toString(){
    return "\"" + getValue() + "\" ";
}

unistring RefSymbol<infint>::toString(){
//    return getValue() + " ";
    std::ostringstream s;
    s << getValue() << " ";
    return s.str();

}

unistring RefSymbol<infreal>::toString(){
    std::ostringstream s;
    s << getValue() << " ";
    return s.str();
}

unistring RefSymbol<char>::toString(){
    std::ostringstream s;
    s << "\\x" << std::hex << (int)getValue();
    return s.str();
}

#endif // REFSYMBOLBASE_HPP_INCLUDED

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

#ifndef REFSYMBOLBASE_CPP_INCLUDED
#define REFSYMBOLBASE_CPP_INCLUDED

#include <iostream>
//#include <sstream>

#include "RefSymbolBase.hxx"
#include "kernel.h"
#include "data.h"

#ifdef WIN32
#define strtof(f1,f2) ((float)strtod(f1,f2))
#endif



// счетчик для контроля утечек памяти
//long RefValuedData::getCount(){ return symcount; };



template <class T>
TResult RefSymbolBase <T>::init(Session* s, RefData *&l) {
    move_to_next_term(l,0/*myid()*/,s);
    RefData* aux = l;
    #ifdef DEBUG
        if (!aux) { SYSTEMERROR("RefData::init() tring to matching with NULL address!"); };
    #endif
    //std::cout << "\n?::: "; print_inf(); std::cout << "=="; aux->print_inf(); std::cout << std::flush;
    bool tmpr = (*this == *aux);
    //aux->drop(0/*myid()*/);
    if (tmpr) return GO;
    //s->get_moved_to_pred_current_term(myid);
    return BACK;
};

template <class T>
    TResult RefSymbolBase <T>::back(Session* s, RefData *&l, RefData *&r) {
        //s->get_moved_to_pred_current_term(myid);
        return BACK;
};

template <class T>
    RefSymbolBase<T>::~RefSymbolBase(){
                co::symcount--;
};

template <class T>
    RefSymbolBase<T>::RefSymbolBase(RefData *rp) : RefValuedData(rp){
        this->is_system = false;
        co::symcount++;
};
/*template <class T>
    void RefSymbolBase<T>::setValue(T i){};
*/
template <class T>
    bool RefSymbolBase<T>::operator ==(RefData &rd){
        RefSymbolBase<T> *t = ref_dynamic_cast<RefSymbolBase<T>*>(&rd); //// static_cast
        return t && (t->getValue()==this->getValue());
    };


/* общие  */
template <class T>
    RefSymbol<T>::RefSymbol(T i, RefData *rp) : RefSymbolBase<T>(rp){
        this->setValue(i);
        /*this->is_system = false;*/
        };

template <class T>
    RefSymbol<T>::RefSymbol(RefData *rp) : RefSymbolBase<T>(rp){
        return;
        /*this->is_system = false;*/
        };

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
        s << this->getValue();
        return s.str();
};



template <class T>
    TResult RefVarForSymbol<T>::init(Session* s, RefData *&l){
        move_to_next_term(l, 0/*myid()*/, s);

        if (ref_dynamic_cast<T *>(l))
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
        #ifdef DEBUG
            return "\"" + getValue() + "\" ";
        #else
            //return getValue() + " ";
            return "\"" + getValue() + "\" ";
        #endif
}


unistring RefSymbol<unichar>::toString(){
        std::ostringstream s;
        if ((getValue() == 10) || (getValue() == 13)){
            #ifdef DEBUG
            s << "#" << (int)getValue();
            #else
            s << "\n";
            #endif
        } else {
            s << '\'' << this->getValue();// << '_' <<(long)this << ' ';
            //s << this->getValue();
        }
        return s.str();
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







// возвращает переменную
RefVariable* createVariableByTypename(unistring nametype, unistring vn){
    if (nametype == "word") return new RefVarWord(vn);
    if (nametype == "int") return new RefVarInteger(vn);
    if (nametype == "real") return new RefVarReal(vn);
    if (nametype == "char") return new RefVarAlpha(vn);
    if (nametype == "byte") return new RefVarByte(vn);
    if (nametype == "e") return new RefVariable_e(vn);
    if (nametype == "E") return new RefVariable_E(vn);
    if (nametype == "END") return new RefVariable_END(vn);
    if (nametype == "s") return new RefVariable_s(vn);
    if (nametype == "t") return new RefVariable_t(vn);
    //return new RefUserVar(nametype, vn);
    // переменная пользовательского типа
    return 0;
};


// возвращает рефал-символ
RefData* createNewEmptyRefSymbolByTypeName(unistring nametype){
    if (nametype == "WORD") return new RefWord();
    if (nametype == "INT") return new RefInteger();
    if (nametype == "REAL") return new RefReal();
    if (nametype == "ALPHA") return new RefAlpha();
    if (nametype == "BYTE") return new RefByte();

    return 0;
}

#endif // REFSYMBOLBASE_HPP_INCLUDED

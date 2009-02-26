#ifndef REFSYMBOLBASE_H_INCLUDED
#define REFSYMBOLBASE_H_INCLUDED

#include "data.h"

#include <sstream>


class RefValuedData : public RefData {
    public:
        virtual void setValueFromString(unistring) = 0;
        RefValuedData(RefData *rd) : RefData(rd){};
        static long getCount();
        virtual unistring toString(){ return "~RefValuedData~"; };
};





template <class T>
class RefSymbolBase : public RefValuedData {
        public:
            ~RefSymbolBase();
            RefSymbolBase(RefData *rp = 0);
            RefSymbolBase(T i, RefData *rp = 0);
            virtual T getValue() = 0;
            virtual void setValue(T) = 0;
            virtual bool operator ==(RefData &rd);
            virtual bool operator >(RefData &rd){
                RefSymbolBase<T> *t = dynamic_cast<RefSymbolBase*>(&rd);
                if (!t) RUNTIMEERROR("operator >", "different types for compare");
                return (getValue() > t->getValue());
                };

            virtual TResult init(Session* s, RefData *&currentPoint); //  --> operator==() => [return GO] else [return BACK]
            virtual TResult back(Session* s, RefData *&currentRight, RefData *&currentLeft);

            virtual void setValueFromString(unistring) = 0;
            virtual unistring toString(){
                std::ostringstream s;
                s << getValue() ;
                return s.str();
            };
};


/**********************
// основные данные
***********************/
template <class T>
class RefSymbol : public RefSymbolBase<T>{
            T value;
        public:
            unistring sss;
            RefSymbol(T i, RefData *rp = 0);
            RefSymbol(RefData *rp = 0);
            virtual T getValue();
            virtual void setValue(T i);
            virtual RefData* Copy(RefData *where=0);
            virtual unistring toString();
            //virtual void setValueFromString(unistring) = 0;
            virtual void setValueFromString(unistring);

            void forceback(Session *){};

};




/***********************
*   Переменные
************************/
template <class T> class RefVarForSymbol : public RefVariable {
    public:
        TResult init(Session* s, RefData *&l);
        TResult back(Session* s, RefData *&l, RefData *&r);
        RefVarForSymbol (unistring name, RefData *rp=0);

        //virtual void setValueFromString(unistring) = 0;
        bool operator ==(RefData &rd);
        virtual void setValueFromString(unistring){};
        virtual RefData* Copy(RefData *where=0){
            RefVarForSymbol<T> *t = new RefVarForSymbol<T>(getName(), where);
            t->setName(this->getName());
            return t;
        };
        virtual unistring toString(){ return "RefVarForSymbol<T>."+getName();}
};


typedef  RefSymbolBase<infint>    RefIntegerBase;
typedef  RefSymbolBase<infreal>   RefRealBase;
typedef  RefSymbolBase<unichar>   RefAlphaBase;
typedef  RefSymbolBase<unichar>   RefByteBase;
typedef  RefSymbolBase<unistring> RefWordBase;
typedef  RefSymbol<infint>    RefInteger;
typedef  RefSymbol<infreal>   RefReal;
typedef  RefSymbol<unichar>   RefAlpha;
typedef  RefSymbol<char>      RefByte;
typedef  RefSymbol<unistring> RefWord;


typedef RefVarForSymbol<RefIntegerBase>  RefVarInteger;
typedef RefVarForSymbol<RefRealBase>     RefVarReal;
typedef RefVarForSymbol<RefWordBase>     RefVarWord;
typedef RefVarForSymbol<RefAlphaBase>    RefVarAlpha;
typedef RefVarForSymbol<RefByteBase>     RefVarByte;


RefData *getNewEmptyRefSymbolByTypeName(unistring);
RefVariable *getVariableByTypename(unistring vtype, unistring vname);

/*
void RefVarForSymbol<unichar>::setValueFromString(unistring s);
void RefVarForSymbol<char>::setValueFromString(unistring s);
void RefVarForSymbol<infint>::setValueFromString(unistring s);
void RefVarForSymbol<infreal>::setValueFromString(unistring s);
*/

#endif // REFSYMBOLBASE_H_INCLUDED

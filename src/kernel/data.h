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

#ifndef REF_DATA_H_INCLUDED
#define REF_DATA_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>

#include "core.h"

/************************************************
* KERNEL - ядро рефал-машины
* ядро определяет
*        типы данных на уровне рефал-термов,
*        переменные,
*        цепочки,
*        поля данных
*************************************************/
class RefObject;
class RefData;
class RefData_DOT;

class RefVariable;
class RefLinkToVariable;

class RefNameSpace; // именованное поле переменных и функций
class RefChain;     // цепочка
class RefVarTable;  // таблица сопоставленных переменных
class TVarBodyTable;  // таблица сопоставленных переменных   RefExecBracket

class Session;


const char varPathSeparator = '/';  // разделитель в пути к подпеременной. Внутреннее представление от парсера

/* системный маппинг иерархии классов-данных для минимального использования RTTI. Если не определен, то castNeedSystemCast */
enum RefDataTypesForCast {
    /*   доп.      ветка     лист      -||-   */
    castUseRTTI       = B32(01000000, 00000000, 00000000, 00000000), // для объектов требуется сисемный dynamic_cast
//    castIsSystemData  = B32(10000000, 00000000, 00000000, 00000000),

    /*рефал-символы*/
    castRefSymbolBase = B32(00000000, 00000001, 00000000, 00000000), // рефал-символ
    castRefInteger    = B32(00000000, 00000000, 00000000, 00000001) | castRefSymbolBase,
    castRefReal       = B32(00000000, 00000000, 00000000, 00000010) | castRefSymbolBase,
    castRefAlpha      = B32(00000000, 00000000, 00000000, 00000100) | castRefSymbolBase,
    castRefByte       = B32(00000000, 00000000, 00000000, 00001000) | castRefSymbolBase,
    castRefWord       = B32(00000000, 00000000, 00000000, 00010000) | castRefSymbolBase,

    castRefBracketBase   =    B32(00000000, 00000010, 00000000, 00000000), // базовая скобка
    castRefStructBracket =    B32(00000000, 00000000, 00000000, 00000001) | castRefBracketBase,
    castRefExecBracket   =    B32(00000000, 00000000, 00000000, 00000010) | castRefBracketBase,
    castRefData_DOT      =    B32(00000000, 00000000, 00000000, 00000100) | castRefBracketBase,
    castRefTemplateBridgeVar= B32(00000000, 00000000, 00000000, 00001000) | castRefBracketBase,
    castRefTemplateBridgeTmpl=B32(00000000, 00000000, 00000000, 00010000) | castRefBracketBase,
    castRefGroupBracket  =    B32(00000000, 00000000, 00000000, 00100000) | castRefBracketBase,
    castref_repeater     =    B32(00000000, 00000000, 00000000, 01000000) | castRefBracketBase,


    castRefVariableBase  =  B32(00000000, 00000100, 00000000, 00000000), // базовая открытая переменная
    castRefVariable      = castRefVariableBase, // переменная
    castRefVariable_E    =  B32(00000000, 00000000, 00000000, 00000001) | castRefVariable,
    castRefVariable_e    =  B32(00000000, 00000000, 00000000, 00000010) | castRefVariable,
    castRefVariable_s    =  B32(00000000, 00000000, 00000000, 00000100) | castRefVariable,
    castRefVariable_t    =  B32(00000000, 00000000, 00000000, 00001000) | castRefVariable,
    castRefVariable_END  =  B32(00000000, 00000000, 00000000, 00010000) | castRefVariable,
    castRefUserVarNotInit=  B32(00000000, 00000000, 00000000, 00100000) | castRefVariable,
    castRefVarAlpha      =  B32(00000000, 00000000, 00000000, 01000000) | castRefVariable,
    castRefVarByte       =  B32(00000000, 00000000, 00000000, 10000000) | castRefVariable,
    castRefVarInteger    =  B32(00000000, 00000000, 00000001, 00000000) | castRefVariable,
    castRefVarReal       =  B32(00000000, 00000000, 00000010, 00000000) | castRefVariable,
    castRefVarWord       =  B32(00000000, 00000000, 00000100, 00000000) | castRefVariable,


    castRefLinkToVariable       =   B32(00000000, 00001000, 00000000, 00000000), // закрытая переменная
    castRefLinkToPartOfVariable =   B32(00000000, 00000000, 00000000, 00000001) | castRefLinkToVariable,

    castRefTemplateBase  =  B32(00000000, 00010000, 00000000, 00000000),
    castRefUserTemplate  =  B32(00000000, 00000000, 00000000, 00000001) | castRefTemplateBase,

    castRefMatchingCutter=  B32(00000000, 00100000, 00000000, 00000000),

    castRefConditionBase =  B32(00000000, 01000000, 00000000, 00000000),
    castRefCondition     =  B32(00000000, 00000000, 00000000, 00000001) | castRefConditionBase
    //сastRef            = B32(00000000, 00000000, 00000000, 00000000)


//  castRef            = B32(00000000, 00000000, 00000000, 00000000)
//  castRef            = B8 (00000000)
};


#define BASE_CLASS_CAST(ClassName) \
const static  RefDataTypesForCast getClassTypeCast = cast##ClassName; \
virtual RefDataTypesForCast object_cast()=0;

#define CLASS_CAST(ClassName) \
const static  RefDataTypesForCast getClassTypeCast = cast##ClassName; \

#define OBJECT_CAST(ClassName) \
virtual RefDataTypesForCast object_cast(){ return cast##ClassName; }

#define CLASS_OBJECT_CAST(ClassName) \
const static  RefDataTypesForCast getClassTypeCast = cast##ClassName; \
virtual RefDataTypesForCast object_cast(){ return cast##ClassName; }


// Родитель всего в Рефале
class RefObject {
public:
    OBJECT_CAST(UseRTTI);

    RefObject();
    virtual ~RefObject();
    virtual unistring toString() = 0;//{ return "@RefObject.toString()"; }
    virtual unistring explode() {
        return toString();
    }
};




// Абстрактный класс - предок всех термов языка
class RefData : public RefObject {
    friend class RefChain;
    friend class RefUserVarNotInit;
    friend void delChain(RefData*, RefData*);

protected:
    RefData*  next;
    RefData*  pred;
    bool isSystem;



public:
    inline RefData* getNext(){ return next; };
    inline RefData* getPred(){ return pred; };
    inline void setNext(RefData *p){ next=p; };
    inline void setPred(RefData *p){ pred=p; };

    virtual bool IRefVarStacked(){ return false; };
    inline bool  is_system() {        return isSystem;    };
    inline void  is_system(bool ss) {        isSystem = ss;    };

    RefData(RefData *rp=0); // pr вставляем после себя
    virtual ~RefData();

	virtual RefData*  next_term( ThisId var_id, Session *s); // на виртуально-соседний элемент (для перем.) или через скобку
    virtual RefData*  pred_term( ThisId var_id, Session *s);
    virtual RefData*  next_template( ThisId var_id, Session *s) {
        //return next_term(var_id, s);
        return next;
    }; // следующий шаблон при сопоставлении
    virtual RefData*  pred_template( ThisId var_id, Session *s) {
        //return pred_term(var_id, s);
        return pred;
    };

    virtual RefData*  beginOfTerm() {
        return this;
    };
    virtual RefData*  endOfTerm () {
        return this;
    };

    virtual RefData* predInsert(RefData *);
    virtual RefData* afterInsert(RefData *);

    virtual bool operator ==(RefData &rd) =0;//{ return false; };
    virtual bool operator >(RefData &rd)  {
        RUNTIMEERROR("operator >", "Not comparable");
    };

	virtual TResult init(RefData *&activeTemplate, Session* s, RefData *&currentPoint)=0; //  --> operator==() => [return GO] else [return BACK]
    virtual TResult back(RefData *&activeTemplate, Session* s, RefData *&currentRight, RefData *&currentLeft)=0;
    virtual void    forceback(Session* s) {
        SYSTEMERROR("RefData.forceback NOT DEFINE for "
                    << toString());
    };; // принудительный откат. Точка убирает из сессии свое состояние


    virtual RefData*  Copy(RefData* where=0) = 0;

};

RefData*  move_to_next_term(RefData* &point, ThisId id, Session *s);
RefData*  move_to_pred_term(RefData* &point, ThisId id, Session *s);

#define MOVE_TO_NEXT_TERM(p, id, s) {while ((p = p->next_term(id, s)) && p->is_system());}
#define MOVE_TO_PRED_TERM(p, id, s) {while ((p = p->pred_term(id, s)) && p->is_system());}





class RefNULL : public RefData {
public:
    RefNULL(RefData *pr=0);
    virtual bool operator==(RefData&);
    virtual RefData*  Copy(RefData *d);
    virtual TResult init(RefData *&tpl, Session*, RefData *&);
    virtual TResult back(RefData *&tpl, Session*, RefData *&, RefData *&);

    virtual unistring toString() {
        #ifdef DEBUG
        return " . ";
        #endif
        return "";
    };
    void forceback(Session *) {};
};


// Абстрактный класс - предок всех открытых переменных языка (простых и скобочных)
class RefVariableBase :  public RefData {
public:
    BASE_CLASS_CAST(RefVariableBase);

    virtual bool IRefVarStacked(){ return true; };
    virtual unistring getName() = 0;
    RefVariableBase(RefData *rp) : RefData(rp) { };
};

class RefVariable : public RefVariableBase { // Простая переменная
protected:
    unistring name;

public:
    BASE_CLASS_CAST(RefVariable);

    ~RefVariable();

    virtual void    forceback(Session* s) { }; // принудительный откат. Точка убирает из сессии свое состоян
    RefVariable(unistring name = EmptyUniString, RefData *rp = 0);

	virtual unistring getName() {
        return name;
    }
    virtual void setName(unistring s) {
        name = s;
    }
};


// Ссылка на переменную
class RefLinkToVariable : public RefData {
protected:
    unistring name;
public:
    virtual unistring getName() {
        return name;
    }
    virtual void setName(unistring s) {
        name = s;
    }
    //RefVariable *lnkData;
    // в name хранится адрес ссылочной переменной в виде varname:varname:varname
    /// todo: сделать ссылаемость на конкретную переменную + карту сопоставлений сделать по адресу ссылки а не по имени
public:
    CLASS_OBJECT_CAST(RefLinkToVariable);

    unistring toString();
    bool operator==(RefData&);
    virtual TResult init(RefData *&tpl, Session* s, RefData *&currentPoint);
    virtual TResult back(RefData *&tpl, Session* s, RefData *&currentRight, RefData *&currentLeft);
    virtual RefData*  Copy(RefData* where=0);

    RefLinkToVariable(unistring name, RefData *rp = 0);
    void forceback(Session *) {};

    virtual unistring getPath() {
        return EmptyUniString;
    }; // для наследников класса - путь к подпеременной относитльно основной переменной
};

class RefLinkToPartOfVariable : public RefLinkToVariable {
    unistring path; // путь к подпеременной относитльно основной переменной
public:
    unistring getPath() {
        return path;
    };
RefLinkToPartOfVariable(unistring name, unistring tpath, RefData *rp = 0) : RefLinkToVariable(name, rp) {
        this->path = tpath;
    };
};

class RefUserTemplate;


class RefSmplVarType : public RefVariable {
public:
RefSmplVarType(unistring name = EmptyUniString, RefData *rp = 0) : RefVariable(name, rp) {};
};

class RefVarTable : public std::map<unistring, RefVariable*> {};


class RefBracketBase : public RefData {
protected:
    bool        is_opened; // true = begin- ; false = end-
    RefBracketBase*  other;

public:
    BASE_CLASS_CAST(RefBracketBase);


    RefBracketBase( RefData *rp = 0); // открывающая
    RefBracketBase( RefBracketBase *dr, RefData *rp=0); // закрывающая
    virtual bool isOpen();
    virtual RefBracketBase * getOther();

    virtual RefData*  beginOfTerm();
    virtual RefData*  endOfTerm ();

    virtual bool       operator ==(RefData &rd);
    virtual RefData* Copy(RefBracketBase *b, RefData *rp=0)=0;
    virtual RefData* Copy(RefData *rp=0)=0;

};


class RefChain : public std::pair<RefData*, RefData*> {
public:

    void clear(); // уничтожение всего что ммежду first и second включительно
    ~RefChain();

public:
    RefChain(RefData *l=0, RefData *r=0);

    RefChain& operator+=(RefChain &ch); // к левому аргумент пристыковывается копия правого!
    RefChain& operator+=(RefData *ch);  // рефдата ПОГЛАЩАЕТСЯ цепочкой!!!
    RefChain* Copy(Session *);         // Если ссылка на сессию != 0, то вместо ссылок будут значения переменных
    RefChain* Copy( ) {
        return this->Copy(0);
    }; // Только для объектных выражений!!!

    RefChain* aroundByDots();            //  окружает цепочку датадотами
    RefChain* dearoundByDots();          //  удаляет в цепочке крайние датадоты
    inline void set(RefData *&l, RefData *&r) {
        l=first;
        r=second;
    };  //  присваивает концы цепочки аргументам

    unistring toString();
    unistring explode(); // голый текст без форматирования
};

void delChain(RefData*, RefData*);



struct RefDataChainPart {
    RefData *from;
    RefData *to;

    // TODO (Islamov#1#): Может стоит подумать о массиве ссылок, а не об очереди?
    RefDataChainPart *pred;
    RefDataChainPart *next;
};

struct RefDataLnkPoint {
    RefDataChainPart*   chainLnk;
    RefData*            dataLnk;
};


template <class T>
 T* ref_dynamic_cast(RefObject *d) {
    #ifdef TESTCODE
    if (!d){
        SYSTEMERROR("ref_dynamic_cast for 0!");
    }

    T   *testres = dynamic_cast<T*>(d),
        *testres2=0;

    if ((T::getClassTypeCast & castUseRTTI)) {
        testres2 = dynamic_cast<T*>(d);
    } else {
        if ((d->object_cast() | T::getClassTypeCast) == d->object_cast()) {
            testres2 = (T*)(d);
        }
    }

    if ((testres?1:0) != (testres2?1:0)) {
        SYSTEMERROR(
            "\nCast fail for ref_dynamic_cast<"<<std::binary(T::getClassTypeCast)<<">( " << d->toString() << " )["<<std::binary(d->object_cast())<<"]"
            << "\n  dynamic   : " << (dynamic_cast<T*>(d)?"ok":"fail")
            << "\n  refal_cast: " << (testres2?"ok":"fail") << "\n"
        );
    }
    return testres2;
    #endif

    #define POINTER_INT_TYPE unsigned long

    RefDataTypesForCast objectCast = d->object_cast();

    if ((T::getClassTypeCast & castUseRTTI)) {
        return dynamic_cast<T*>(d);
    }
     else {
        if ((objectCast | T::getClassTypeCast) == objectCast) {
            return (T*)(d);
        }
    }
    return 0;
};


#endif // REF_KERNEL_H_INCLUDED


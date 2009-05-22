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
    castIsSystemData  = B32(10000000, 00000000, 00000000, 00000000),

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


    castRefVariableBase  =  B32(00000000, 00000000, 00000100, 00000000), // базовая открытая переменная
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


    castRefLinkToVariable       =   B32(00000000, 00000000, 00001000, 00000000), // закрытая переменная
    castRefLinkToPartOfVariable =   B32(00000000, 00000000, 00000000, 00000001) | castRefLinkToVariable
    //сastRef            = B32(00000000, 00000000, 00000000, 00000000)  ////



//  castRef            = B32(00000000, 00000000, 00000000, 00000000)  ////
//  castRef            = B8 (00000000)
};

#define BASE_CLASS_CAST(ClassName) \
inline static  RefDataTypesForCast getClassTypeCast(){ return cast##ClassName; }; \
virtual RefDataTypesForCast object_cast()=0

        #define CLASS_CAST(ClassName) \
inline  static  RefDataTypesForCast getClassTypeCast(){ return cast##ClassName; };

#define OBJECT_CAST(ClassName) \
virtual RefDataTypesForCast object_cast(){ return cast##ClassName; }

// Родитель всего в Рефале
class RefObject {
public:
    inline static  RefDataTypesForCast getClassTypeCast() {
        return castUseRTTI;
    };
    virtual RefDataTypesForCast object_cast() {
        return castUseRTTI;
    }
    //static long ocount;
    RefObject();
    virtual ~RefObject();
    virtual unistring toString() = 0;//{ return "@RefObject.toString()"; }
    virtual unistring explode() {
        return toString();
    }
};


#define regCast(CastType) this->typeCast = static_cast<RefDataTypesForCast>(this->typeCast | cast##CastType);


// Абстрактный класс - предок всех термов языка
class RefData : public RefObject {
public:
    RefData*  next;
    RefData*  pred;

    unsigned long castInfo; // для is_system

public:
    virtual bool IsRefVarStacked() {
        return false;
    }; // для всего, что в матчинге считается переменной со значением
    inline bool  is_system() {
        return castInfo&castIsSystemData;
    };
    inline void  is_system(bool ss) {
        castInfo = (ss ? (castInfo|castIsSystemData) : (castInfo&~castIsSystemData) );
    };

    RefData(RefData *rp=0); // pr вставляем после себя
    virtual ~RefData();
    //ThisId  0/*myid()*/{  return (ThisId)(this); };

    //static  RefDataTypesForCast getClassTypeCast(){ return castUseRTTI; };      // инфотип для класса
    //bool  is_symbol; // сопостовимость с s-перемеенной

    virtual RefData*  next_term( ThisId var_id, Session *s); // на виртуально-соседний элемент (для перем.) или через скобку
    virtual RefData*  pred_term( ThisId var_id, Session *s);
    virtual RefData*  next_template( ThisId var_id, Session *s) {
        return next_term(var_id, s);
    }; // следующий шаблон при сопоставлении
    virtual RefData*  pred_template( ThisId var_id, Session *s) {
        return pred_term(var_id, s);
    };

    virtual RefData*  beginOfTerm() {
        return this;
    };
    virtual RefData*  endOfTerm () {
        return this;
    };
//        virtual RefData*  take_copy ( ThisId var_id); // возвращает копию если новый создатель
//        virtual RefData*  take_copy_force ( ThisId var_id); // возвращает копию - независимо от создателя
//        virtual void       drop   ( ThisId var_id);

    virtual RefData* predInsert(RefData *);
    virtual RefData* afterInsert(RefData *);
    ///todo:  virtual void 	   dropall( Session*);

    virtual bool operator ==(RefData &rd) =0;//{ return false; };
    virtual bool operator >(RefData &rd)  {
        RUNTIMEERROR("operator >", "Not comparable");
    };
    /*
            virtual bool operator <(RefData &rd)  { return ! (*this>rd || *this==rd); };
            virtual bool operator <=(RefData &rd) { return ! (*this>rd); };
            virtual bool operator >=(RefData &rd) { return ! (*this<rd); };
    */
    virtual TResult init(Session* s, RefData *&currentPoint)=0; //  --> operator==() => [return GO] else [return BACK]
    virtual TResult back(Session* s, RefData *&currentRight, RefData *&currentLeft)=0;
    virtual void    forceback(Session* s) {
        SYSTEMERROR("RefData.forceback NOT DEFINE for "
                    << toString());
    };; // принудительный откат. Точка убирает из сессии свое состояние


    virtual RefData*  Copy(RefData* where=0) = 0;

};

RefData*  move_to_next_term(RefData* &point, ThisId id, Session *s);
RefData*  move_to_pred_term(RefData* &point, ThisId id, Session *s);





class RefNULL : public RefData {
public:
    RefNULL(RefData *pr=0);
    virtual bool operator==(RefData&);
    virtual RefData*  Copy(RefData *d);
    virtual TResult init(Session*, RefData *&);
    virtual TResult back(Session*, RefData *&, RefData *&);

    virtual unistring toString() {
        #ifdef DEBUG
        return " . ";
        #endif
        return "";
    };
    void forceback(Session *) {};
};


// Именнованое поле методов и переменных
class RefalNameSpace {
protected:
    unistring name;
public:
    virtual unistring getName() {
        return name;
    }
    virtual void setName(unistring s) {
        name = s;
    }

    RefalNameSpace(unistring name = EmptyUniString) {
        setName(name);
    };
    virtual ~RefalNameSpace() {};

};


// Абстрактный класс - предок всех открытых переменных языка (простых и скобочных)
class RefVariableBase {
public:
    virtual bool IsRefVarStacked() {
        return true;
    };
    virtual unistring getName() = 0;
};



class RefVariable : public RefVariableBase, public RefData , public RefalNameSpace { // Простая переменная
public:
    BASE_CLASS_CAST(RefVariable);

    ~RefVariable();

    virtual void    forceback(Session* s) { }; // принудительный откат. Точка убирает из сессии свое состоян
    RefVariable(unistring name = EmptyUniString, RefData *rp = 0);
    virtual unistring getName() {
        return RefalNameSpace::getName();
    }; /// todo очень грязное решение. исправить
    virtual void setName(unistring name) {
        RefalNameSpace::setName(name);
    }; /// todo очень грязное решение. исправить
};

// Ссылка на переменную
class RefLinkToVariable : public RefData, public RefalNameSpace {
    //RefVariable *lnkData;
    // в name хранится адрес ссылочной переменной в виде varname:varname:varname
    /// todo: сделать ссылаемость на конкретную переменную + карту сопоставлений сделать по адресу ссылки а не по имени
public:
    CLASS_CAST(RefLinkToVariable);
    OBJECT_CAST(RefLinkToVariable);

    unistring toString();
    bool operator==(RefData&);
    virtual TResult init(Session* s, RefData *&currentPoint);
    virtual TResult back(Session* s, RefData *&currentRight, RefData *&currentLeft);
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
    OBJECT_CAST(RefLinkToPartOfVariable);
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

public:
    BASE_CLASS_CAST(RefBracketBase);
    RefBracketBase*  other;

    virtual RefData *Clone() {
        SYSTEMERROR("unexpected call");
    };
    RefBracketBase( RefData *rp = 0); // открывающая
    RefBracketBase( RefBracketBase *dr, RefData *rp=0); // закрывающая
    virtual bool isOpen();
    virtual RefBracketBase * getOther();

    virtual RefData*  beginOfTerm();
    virtual RefData*  endOfTerm ();

    virtual bool       operator ==(RefData &rd);
    virtual RefData* Copy(RefBracketBase *b, RefData *rp=0)=0;
    virtual RefData* Copy(RefData *rp=0)=0;

    /*virtual unistring getName(){ SYSTEMERROR("alarm!"); };
    virtual void setName(unistring ){ SYSTEMERROR("alarm!"); };*/

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


class RefLChain : public RefData {
public:
    RefData *from;
    RefData *to  ;

    virtual RefData*  next_term( ThisId var_id, Session *s);
    virtual RefData*  pred_term( ThisId var_id, Session *s);
    virtual RefData*  Copy(RefData* where=0) {
        SYSTEMERROR("undefined");
    };

    virtual TResult init(Session* s, RefData *&currentPoint) {
        SYSTEMERROR("undefined");
    };
    virtual TResult back(Session* s, RefData *&currentRight, RefData *&currentLeft) {
        SYSTEMERROR("undefined");
    };

    virtual bool operator ==(RefData &rd) {
        SYSTEMERROR("undefined");
    };
RefLChain(RefData *rp = 0):RefData(rp) {
        is_system(true);
    };
};





/*
template <class T>
inline T* ref_dynamic_cast(RefObject *d) {
    if (!d)
        return 0;

    //return dynamic_cast<T*>(d);

    #ifdef TESTCODE
    if (!  ((d->OBJECT_CAST() & castUseRTTI) | (T::getClassTypeCast() & castUseRTTI))  ) {
        T* t = dynamic_cast<T*>(d);
        if (t) {
            // динамик_каст пройден!
            if (! (d->OBJECT_CAST() & T::getClassTypeCast())) {
				// а каст битами не пройден
                std::cout << "\n" << std::binary(d->OBJECT_CAST()) <<" try cast with " << std::binary(T::getClassTypeCast()) << "\n";
				std::cout << "\ndynamic_cast: OK";
                std::cout << "\n____bit_cast: fail";
                SYSTEMERROR("\nbit cast fail for ref_dynamic_cast<"<<std::binary(T::getClassTypeCast())<<">( " << d->toString() << " )");
            } else {
				//std::cout << "\ndynamic_cast: OK";
                //std::cout << "\n____bit_cast: OK";
            }
		} else {
			// динамик_каст НЕ пройден!
            if ( (d->OBJECT_CAST() & T::getClassTypeCast())) {
				// а каст битами пройден
                std::cout << "\n" << std::binary(d->OBJECT_CAST()) <<" try cast with " << std::binary(T::getClassTypeCast()) << "\n";
				std::cout << "\ndynamic_cast:fail";
                std::cout << "\n____bit_cast: OK";
                SYSTEMERROR("\nbit cast ERROR SUCCESS for ref_dynamic_cast<"<<std::binary(T::getClassTypeCast())<<">(" << d->toString() << ")");
            } else {
				//std::cout << "\ndynamic_cast:fail";
				//std::cout << "\n____bit_cast: fail";
			}
		}
        return t;
    }
    #endif

    #ifdef TESTCODE
    //if (! dynamic_cast<RefData *>(d)) SYSTEMERROR("call ref_dynamic_cast not for RefData !!!: " << d->toString());
    #endif

    if ((d->OBJECT_CAST() & castUseRTTI) | (T::getClassTypeCast() & castUseRTTI)) {
        return dynamic_cast<T*>(d);
    }
    if (d->OBJECT_CAST() & T::getClassTypeCast()) {
        return reinterpret_cast<T*>(d);
    }

    return 0;
    //return dataref_dynamic_cast(T, d);
};
*/
template <class T>
inline T* ref_dynamic_cast(RefObject *d) {
    if (!d)
        return 0;

    #ifdef TESTCODE
    T* testres = dynamic_cast<T*>(d), testres2=0;

    if ((T::getClassTypeCast() & castUseRTTI)) {
        testres2 = dynamic_cast<T*>(d);
    }
    if (d->OBJECT_CAST() & T::getClassTypeCast()) {
        testres2 = reinterpret_cast<T*>(d);
    }

    if ((testres?1:0) != (testres2?1:0)) {
        SYSTEMERROR("\nCast fail for ref_dynamic_cast<"<<std::binary(T::getClassTypeCast())<<">( " << d->toString() << " )");
    }
    return testres2;
    #endif

    if ((T::getClassTypeCast() & castUseRTTI)) {
        return dynamic_cast<T*>(d);
    }
    if (d->object_cast() & T::getClassTypeCast()) {
        return reinterpret_cast<T*>(d);
    }

    return 0;
};


#endif // REF_KERNEL_H_INCLUDED

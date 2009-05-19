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

enum RefDataTypesForCast {
    castDefault = B8(00000000),
    castRefBracketBase = B8(00000001),
    castRefExecBracket = B8(00000010)
//  castRef = B8(00000000),
};


template <class T>
    T _dynamic_cast(RefObject *d){
        #ifdef DEBUG
        if (! dynamic_cast<RefData *>(d)) SYSTEMERROR("call _dynamic_cast not for RefData !!!");
        #endif
        return dynamic_cast<T>(d);
}


// Родитель всего в Рефале
class RefObject {
    public:
        unistring sss;

        //static long ocount;
        RefObject();
        virtual ~RefObject();
        virtual unistring toString() = 0;//{ return "@RefObject.toString()"; }
        virtual unistring explode() { return toString(); }
};

#define data_dynamic_cast(CastType, obj) ( (cast##CastType & obj->typeCast) ? static_cast<CastType *>(obj) : 0 )

#define regCast(CastType) this->typeCast = static_cast<RefDataTypesForCast>(this->typeCast | cast##CastType);


// Абстрактный класс - предок всех термов языка
class RefData : public RefObject {
    public:
    	RefData*  next;
        RefData*  pred;
    public:
        RefData(RefData *rp=0); // pr вставляем после себя
        virtual ~RefData();
        //ThisId  0/*myid()*/{  return (ThisId)(this); };
        bool  is_system;
        RefDataTypesForCast typeCast;
        //bool  is_symbol; // сопостовимость с s-перемеенной

        virtual RefData*  next_term( ThisId var_id, Session *s); // на виртуально-соседний элемент (для перем.) или через скобку
        virtual RefData*  pred_term( ThisId var_id, Session *s);
        virtual RefData*  next_template( ThisId var_id, Session *s){ return next_term(var_id, s); }; // следующий шаблон при сопоставлении
        virtual RefData*  pred_template( ThisId var_id, Session *s){ return pred_term(var_id, s); };

        virtual RefData*  beginOfTerm(){ return this; };
        virtual RefData*  endOfTerm () { return this; };
//        virtual RefData*  take_copy ( ThisId var_id); // возвращает копию если новый создатель
//        virtual RefData*  take_copy_force ( ThisId var_id); // возвращает копию - независимо от создателя
//        virtual void       drop   ( ThisId var_id);

        virtual RefData* predInsert(RefData *);
        virtual RefData* afterInsert(RefData *);
        ///todo:  virtual void 	   dropall( Session*);

        virtual bool operator ==(RefData &rd) =0;//{ return false; };
        virtual bool operator >(RefData &rd)  { RUNTIMEERROR("operator >", "Not comparable"); };
/*
        virtual bool operator <(RefData &rd)  { return ! (*this>rd || *this==rd); };
        virtual bool operator <=(RefData &rd) { return ! (*this>rd); };
        virtual bool operator >=(RefData &rd) { return ! (*this<rd); };
*/
//        virtual bool dynamic_same(RefData *); // для динамических точек - признак эквивалентности
        virtual TResult init(Session* s, RefData *&currentPoint)=0; //  --> operator==() => [return GO] else [return BACK]
        virtual TResult back(Session* s, RefData *&currentRight, RefData *&currentLeft)=0;
        virtual void    forceback(Session* s){
            SYSTEMERROR("RefData.forceback NOT DEFINE for "
            << toString()); };; // принудительный откат. Точка убирает из сессии свое состояние

        //virtual void print_inf(){ std::cout << "[" << (sss=toString()) << "]" << this << " "; };

        virtual RefData*  Copy(RefData* where=0) = 0;
//      virtual RefData*  getCopyAsData(RefData*);//= 0;  // клон без ссылок. Важно перегружать везде где нужно и правильно!

};

RefData*  move_to_next_term(RefData* &point, ThisId id, Session *s);
RefData*  move_to_pred_term(RefData* &point, ThisId id, Session *s);



class RefChainPointFrom : public RefData {
    public:
        RefData *point;
};

class RefChainPointTo : public RefData {
    public:
        RefData *point;
};



class RefNULL : public RefData {
    public:
        RefNULL(RefData *pr=0);
        virtual bool operator==(RefData&);
        virtual RefData*  Copy(RefData *d);
        virtual TResult init(Session*, RefData *&);
        virtual TResult back(Session*, RefData *&, RefData *&);

        virtual unistring toString(){
            #ifdef DEBUG
            return " . ";
            #endif
            return "";
        };
        void forceback(Session *){};
};


// Именнованое поле методов и переменных
class RefalNameSpace {
    protected:
        unistring name;
    public:
        virtual unistring getName(){ return name; }
        virtual void setName(unistring s){ name = s; }

        RefalNameSpace(unistring name = EmptyUniString) { setName(name); };
        virtual ~RefalNameSpace(){};

};

// Абстрактный интерфейс-класс - для всего, что в матчинге считается переменной
class IRefVarStacked {
    public:
        virtual unistring getName() = 0;
        //virtual void setName(unistring name) = 0;
};


// Абстрактный класс - предок всех открытых переменных языка (простых и скобочных)
class RefVariableBase : public IRefVarStacked {
    public:
        RefVariableBase() : IRefVarStacked() { };
};

class RefVariable : public RefVariableBase, public RefData , public RefalNameSpace { // Простая переменная
    public:
        ~RefVariable();

        virtual void    forceback(Session* s){ }; // принудительный откат. Точка убирает из сессии свое состоян
        RefVariable(unistring name = EmptyUniString, RefData *rp = 0);
        virtual unistring getName(){ return RefalNameSpace::getName(); }; /// todo очень грязное решение. исправить
        virtual void setName(unistring name){ RefalNameSpace::setName(name); }; /// todo очень грязное решение. исправить
};

// Ссылка на переменную
class RefLinkToVariable : public RefData, public RefalNameSpace {
        //RefVariable *lnkData;
        // в name хранится адрес ссылочной переменной в виде varname:varname:varname
        /// todo: сделать ссылаемость на конкретную переменную + карту сопоставлений сделать по адресу ссылки а не по имени
    public:
        unistring toString();
        bool operator==(RefData&);
        virtual TResult init(Session* s, RefData *&currentPoint);
        virtual TResult back(Session* s, RefData *&currentRight, RefData *&currentLeft);
        virtual RefData*  Copy(RefData* where=0);

        RefLinkToVariable(unistring name, RefData *rp = 0);
        void forceback(Session *){};

        virtual unistring getPath(){ return EmptyUniString; }; // для наследников класса - путь к подпеременной относитльно основной переменной
};

class RefLinkToPartOfVariable : public RefLinkToVariable {
        unistring path; // путь к подпеременной относитльно основной переменной
    public:
        unistring getPath(){ return path; };
        RefLinkToPartOfVariable(unistring name, unistring tpath, RefData *rp = 0) : RefLinkToVariable(name, rp){
            this->path = tpath;
        };
};

class RefUserTemplate;


class RefSmplVarType : public RefVariable {
    public:
        RefSmplVarType(unistring name = EmptyUniString, RefData *rp = 0) : RefVariable(name, rp){};
};

class RefVarTable : public std::map<unistring, RefVariable*>{};


class RefBracketBase : /*public IRefVarStacked, */ public RefData {
    protected:
        bool        is_opened; // true = begin- ; false = end-

    public:
        RefBracketBase*  other;

        virtual RefData *Clone(){ SYSTEMERROR("unexpected call"); };
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
    unistring sss;
  public:

	void clear(); // уничтожение всего что ммежду first и second включительно
	~RefChain();

    public:
        RefChain(RefData *l=0, RefData *r=0);

        RefChain& operator+=(RefChain &ch); // к левому аргумент пристыковывается копия правого!
        RefChain& operator+=(RefData *ch);  // рефдата ПОГЛАЩАЕТСЯ цепочкой!!!
        RefChain* Copy(Session *);         // Если ссылка на сессию != 0, то вместо ссылок будут значения переменных
        RefChain* Copy( ){ return this->Copy(0); }; // Только для объектных выражений!!!

        RefChain* aroundByDots();            //  окружает цепочку датадотами
        RefChain* dearoundByDots();          //  удаляет в цепочке крайние датадоты
        inline void set(RefData *&l, RefData *&r){l=first; r=second;};  //  присваивает концы цепочки аргументам

        unistring toString();
        unistring explode(); // голый текст без форматирования
};


void delChain(RefData*, RefData*);


#endif // REF_KERNEL_H_INCLUDED

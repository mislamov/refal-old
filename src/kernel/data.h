#ifndef REF_DATA_H_INCLUDED
#define REF_DATA_H_INCLUDED

#include <iostream.h>
#include <stdlib.h>
#include <strings.h>
#include <map>

//#include "kernel.h"
//#include "session.h"
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
class TVarBodyTable;  // таблица сопоставленных переменных

class Session;

// Родитель всего в Рефале
class RefObject {
    public:
        //static long ocount;
        RefObject();
        static long getCout();
        ~RefObject();
        virtual unistring toString() = 0;//{ return "@RefObject.toString()"; }
};


// Абстрактный класс - предок всех термов языка
class RefData : public RefObject {
    public:
    std::string sss;
    	RefData*  next;
        RefData*  pred;
    public:
        RefData(RefData *rp = 0); // pr вставляем после себя
        virtual ~RefData();
        ThisId  myid(){  sss=toString(); return (ThisId)(this); };
        bool  is_system;
        //bool  is_symbol; // сопостовимость с s-перемеенной

        virtual RefData*  next_point( ThisId var_id, Session *s); // на соседнйи элемени
        virtual RefData*  pred_point( ThisId var_id, Session *s);
        virtual RefData*  next_term( ThisId var_id, Session *s); // на виртуально-соседний элемент (для перем.) или через скобку
        virtual RefData*  pred_term( ThisId var_id, Session *s);
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
        virtual void    forceback(Session* s){ SYSTEMERROR("RefData.forceback NOT DEFINE for " << toString()); };; // принудительный откат. Точка убирает из сессии свое состояние

        virtual void print_inf(){ std::cout << "[" << (sss=toString()) << "]" << this << " "; };

        virtual RefData*  Copy(RefData* where=0) = 0;
//      virtual RefData*  getCopyAsData(RefData*);//= 0;  // клон без ссылок. Важно перегружать везде где нужно и правильно!

};


RefData*  move_to_next_point(RefData*&, ThisId , Session* );
RefData*  move_to_pred_point(RefData*&, ThisId , Session* );
void  move_to_next_term(RefData* &, ThisId , Session *);
void  move_to_pred_term(RefData* &, ThisId , Session *);



class RefNULL : public RefData {
    public:
        RefNULL(RefData *pr=0);
        virtual bool operator==(RefData&);
        virtual RefData*  Copy(RefData *d);
        virtual TResult init(Session*, RefData *&);
        virtual TResult back(Session*, RefData *&, RefData *&);

        virtual unistring toString(){ /*unistring s ="."; return s;*/ return ""; };
        void forceback(Session *){};
};


// Именнованое поле методов и переменных8
class RefalNameSpace : public RefObject {
    protected:
        unistring name;
    public:
        virtual unistring getName(){ return name; }
        virtual void setName(unistring s){ name = s; }

        virtual RefObject* getObjectByName(unistring name){ return 0; };
        RefalNameSpace(unistring name = EmptyUniString) : RefObject(){ setName(name); };

};

// Абстрактный класс - предок всех переменных языка
class RefVariable : public RefData, public RefalNameSpace {
    public:
        RefVariable(unistring name = EmptyUniString, RefData *rp = 0);
        void forceback(Session *){};
};

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

        RefLinkToVariable(unistring pathname, RefData *rp = 0);
        void forceback(Session *){};


};

class RefUserVar: public RefVariable {
    private:
        RefChain *body;
        unistring typeDescription;
    public:
        unistring toString();
        bool operator==(RefData&);
        virtual TResult init(Session* s, RefData *&currentPoint);
        virtual TResult back(Session* s, RefData *&currentRight, RefData *&currentLeft);
        virtual RefData*  Copy(RefData* where=0);

        RefUserVar(unistring typeName, unistring name = EmptyUniString, RefData *rp = 0);
};

class RefSmplVarType : public RefVariable {
    public:
        RefSmplVarType(unistring name = EmptyUniString, RefData *rp = 0) : RefVariable(name, rp){};
};

class RefVarTable : public std::map<unistring, RefVariable*>{};


//class RefBracketBase : public RefVariable {
class RefBracketBase : public RefData {
    protected:
        bool        is_opened; // true = begin- ; false = end-

    public:
        RefBracketBase*  other;

        virtual RefData *Clone(){};
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
        RefChain* Copy( ){ return this->Copy(0); }; // Только для объектных выражений!!!

        RefChain* aroundByDots();            //  окружает цепочку датадотами
        inline void set(RefData *&l, RefData *&r){l=first; r=second;};  //  присваивает концы цепочки аргументам

        unistring toString();
};


void delChain(RefData*, RefData*);


#endif // REF_KERNEL_H_INCLUDED

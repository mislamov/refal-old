#ifndef REF_DATA_H_INCLUDED
#define REF_DATA_H_INCLUDED

#include <iostream.h>
#include <stdlib.h>
#include <strings.h>
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
class TVarBodyTable;  // таблица сопоставленных переменных

class Session;


const char varPathSeparator = '/';  // разделитель в пути к подпеременной. Внутреннее представление от парсера


// Родитель всего в Рефале
class RefObject {
    public:
        unistring sss;

        //static long ocount;
        RefObject();
        static long getCout();
        ~RefObject();
        virtual unistring toString() = 0;//{ return "@RefObject.toString()"; }
};


// Абстрактный класс - предок всех термов языка
class RefData : public RefObject {
    public:
    	RefData*  next;
        RefData*  pred;
    public:
        RefData(RefData *rp=0); // pr вставляем после себя
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

        virtual unistring toString(){ /*unistring s ="."; return s;*/ return " . "; };
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

};

// Абстрактный интерфейс-класс - для всего, что в матчинге считается переменной
class IRefVar {
    public:
        virtual unistring getName() = 0;
        virtual void setName(unistring name) = 0;
};


// Абстрактный класс - предок всех открытых переменных языка (простых и скобочных)
class RefVariableBase : public IRefVar {
    public:
        RefVariableBase() : IRefVar() { };
};

class RefVariable : public RefVariableBase, public RefData , public RefalNameSpace { // Простая переменная
    public:
        virtual void    forceback(Session* s){ }; // принудительный откат. Точка убирает из сессии свое состоян
        RefVariable(unistring name = EmptyUniString, RefData *rp = 0) : RefVariableBase(), RefData(rp), RefalNameSpace(name){ is_system = false;  };
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

/*
class RefUserVar: public RefVariable {
    private:
        RefUserTemplate *body;      // ссылка на описание шаблона
        unistring typeDescription;  // изначально имя на описание шаблона. Используется для поддержки позднего связывания с телом
    public:
        unistring toString();
        bool operator==(RefData&);
        virtual TResult init(Session* s, RefData *&currentPoint);
        virtual TResult back(Session* s, RefData *&currentRight, RefData *&currentLeft);
        virtual RefData*  Copy(RefData* where=0);

        RefUserTemplate *getBody(); // возвращает тело. Если нужно - ищет его (todo: стоит сделать поиск сразу после загрузки модуля)

        RefUserVar(unistring typeDescription, unistring name = EmptyUniString, RefData *rp = 0);
};
*/
class RefSmplVarType : public RefVariable {
    public:
        RefSmplVarType(unistring name = EmptyUniString, RefData *rp = 0) : RefVariable(name, rp){};
};

class RefVarTable : public std::map<unistring, RefVariable*>{};


class RefBracketBase : public IRefVar, public RefData {
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

        virtual unistring getName(){ SYSTEMERROR("alarm!"); };
        virtual void setName(unistring ){ SYSTEMERROR("alarm!"); };

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
};


void delChain(RefData*, RefData*);


#endif // REF_KERNEL_H_INCLUDED

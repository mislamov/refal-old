// DiRefal - sentential program language
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

#ifndef REF_CORE_H_INCLUDED
#define REF_CORE_H_INCLUDED

#define REFVERSION "DiRefal 0.1.0 pre-alpha  Copyright (c) 2008-2009 Marat Islamov"
#define TESTCODE
#define DEBUG
//#define UNICODE
/****************************************************************************************
* CORE - сердцевина рефал-машины
* core хранит описания внутренних типов данных, используемых на уровне работы с байтами
*     юникод-символы
*     бесконечные целые и вещественные
*     и др.
*****************************************************************************************/

#include <iostream>


#include <stdlib.h>
#include <string>

#include <limits>
#ifndef SIZE_MAX
	#define SIZE_MAX std::numeric_limits<std::size_t>::max()
#endif

#ifndef POOLSIZE_DEFAULT
    #define POOLSIZE_DEFAULT 1
#endif

#ifndef CHAIN_SYSTEM_PORTION_SIZE_INIT
    #define CHAIN_SYSTEM_PORTION_SIZE_INIT 8
#endif


typedef unsigned char  unichar;
typedef std::string    unistring;

//#define _L(quote) L##quote
#define _L(quote) quote

typedef long long       infint;
typedef double          infreal;
typedef int             ThisId;     // тип для хранения  идентификатора каждого дататайпа

const unistring EmptyUniString = _L("");
const unistring DefaultVarName = _L("");

typedef enum { GO, BACK, FAIL, SUCCESS, ERROR } TResult; // результат подпроцесса сопоставления


#define HEX__(n) 0x##n##LU

#define B8__(x) ((x&0x0000000FLU)?1:0)      \
               +((x&0x000000F0LU)?2:0)      \
               +((x&0x00000F00LU)?4:0)      \
               +((x&0x0000F000LU)?8:0)      \
               +((x&0x000F0000LU)?16:0)     \
               +((x&0x00F00000LU)?32:0)     \
               +((x&0x0F000000LU)?64:0)     \
               +((x&0xF0000000LU)?128:0)

#define B8(d) ((unsigned char)B8__(HEX__(d)))

#define B16(dmsb,dlsb) (((unsigned short)B8(dmsb)<<8)     \
                        + B8(dlsb))

#define B32(dmsb,db2,db3,dlsb) (((unsigned long)B8(dmsb)<<24)      \
                                  + ((unsigned long)B8(db2)<<16) \
                                  + ((unsigned long)B8(db3)<<8)    \
                                  + B8(dlsb))



namespace std {
    template <typename _T>
    struct _binary {
        std::string _digits;
    };

    template <typename T>
    inline _binary<T> binary(T n) {
        _binary<T> __binary;
        int bits = sizeof(n);

        switch (bits) {
        case 1 :
            bits = 7;
            break;
        case 2 :
            bits = 15;
            break;
        case 4 :
            bits = 31;
            break;
        }

        for (int i = bits; i >= 0; i--) {
            if ((n >> i) & 1)
                __binary._digits.append("1");
            else
                __binary._digits.append("0");
            if (! (i % 8)) {
                __binary._digits.append(" ");
            }
        }

        return __binary;
    }

    template <typename T>
    ostream& operator<<(ostream& stream, _binary<T> __binary) {
        stream << __binary._digits;
        return stream;
    }
}



class Session;


/* системный маппинг иерархии классов-данных для минимального использования RTTI. Если не определен, то castNeedSystemCast */
enum RefDataTypesForCast {
    /*доп. ветка лист -||-*/
    castUseRTTI       = B32(01000000, 00000000, 00000000, 00000000), // для объектов требуется сисемный dynamic_cast

    /*рефал-символы*/
    castRefSymbolBase	  = B32(00000000, 00000001, 00000000, 00000000), // рефал-символ
    castRefIntegerBase    = B32(00000000, 00000000, 00000000, 00000001) | castRefSymbolBase,
    castRefRealBase       = B32(00000000, 00000000, 00000000, 00000010) | castRefSymbolBase,
    castRefAlphaBase      = B32(00000000, 00000000, 00000000, 00000100) | castRefSymbolBase,
    castRefByteBase       = B32(00000000, 00000000, 00000000, 00001000) | castRefSymbolBase,
    castRefWordBase       = B32(00000000, 00000000, 00000000, 00010000) | castRefSymbolBase,

    castRefBracketBase   =    B32(00000000, 00000010, 00000000, 00000000), // базовая скобка
    castRefStructBracket =    B32(00000000, 00000000, 00000000, 00000001) | castRefBracketBase,
    castRefExecBracket   =    B32(00000000, 00000000, 00000000, 00000010) | castRefBracketBase,
    castRefData_DOT      =    B32(00000000, 00000000, 00000000, 00000100) | castRefBracketBase,
    castRefTemplateBridgeVar= B32(00000000, 00000000, 00000000, 00001000) | castRefBracketBase,
    castRefTemplateBridgeTmpl=B32(00000000, 00000000, 00000000, 00010000) | castRefBracketBase,
    castRefGroupBracket  =    B32(00000000, 00000000, 00000000, 00100000) | castRefBracketBase,
    castref_repeater     =    B32(00000000, 00000000, 00000000, 01000000) | castRefBracketBase,

    castRefVariableBase  =  B32(00000000, 00000100, 00000000, 00000000), // базовая открытая переменная
    castRefVariable      =  castRefVariableBase, // переменная
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


class RefObject;

template <class T>
T* ref_dynamic_cast(RefObject* d) {
	return dynamic_cast<T*>(d);
}

const char varPathSeparator = '/';  // разделитель в пути к подпеременной. Внутреннее представление от парсера

/*
template <class T>
T* ref_dynamic_cast(RefObject* d) {
    #ifdef TESTCODE
    if (!d){
		return 0;
        //SYSTEMERROR("ref_dynamic_cast for 0!");
    }

    T   *testres  = dynamic_cast<T*>(d),
        *testres2 = 0;

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
*/


inline std::string replace(std::string text, std::string s, std::string d)
{
  for(unsigned index=0; index=text.find(s, index), index!=std::string::npos;)
  {
    text.replace(index, s.length(), d);
    index+=d.length();
  }
  return text;
}


#ifdef DEBUG
    #define AchtungERROR SYSTEMERROR("Achtung!")
    #define notrealisedERROR SYSTEMERROR("Not realised!")

    #define SYSTEMERROR(msg) { \
        std::cout << "\n\n######## " << __FILE__ << '[' << __LINE__ << "] : "; \
		std::cout << "\n######## " << __FUNCTION__ << "():: " << msg << "\n\n" << std::flush; \
        exit(-1); \
        };

    #define LOG(msg) { \
        std::cout << "\n####### LOG::" << __FILE__ << '[' << __LINE__ << "] : " << __FUNCTION__ << "():: " << msg << "\n" << std::flush; \
        };
#else
    #define SYSTEMERROR(msg) { \
        std::cout << "\n\n######## " << __FILE__ << '[' << __LINE__ << "] : "; \
        std::cout << "\n######## " << __FUNCTION__ << "():: " << msg << "\n\n" << std::flush; \
        exit(-1); \
        };
    /*#define SYSTEMERROR(msg) { \
        std::cout << "\n\n######## SYSTEM ERROR ########:: " << msg << "\n\n" << std::flush; \
        exit(-1); \
        };*/

    #define LOG(msg) {}
#endif

#define RUNTIMEERROR(fname, msg) { \
    std::cout << "\n####:#### RUNTIMEERROR "<< __FILE__ << '[' << __LINE__ << "] : Error in function " << fname << " :: " << msg << "\n" << std::flush; \
    exit(-1); \
    };

#define COMPILETIMEERROR(fname, msg) { \
    std::cout << "\n####:#### COMPILETIMEERROR "<< __FILE__ << '[' << __LINE__ << "] : Error in function " << fname << " :: " << msg << "\n" << std::flush; \
    exit(-1); \
    };




#endif // REF_CORE_H_INCLUDED


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

#ifndef REF_CORE_H_INCLUDED
#define REF_CORE_H_INCLUDED

#define REFVERSION "D-Refal 0.0.9 pre-alpha  Copyright (c) 2008-2009 Marat Islamov"
//#define TESTCODE
//#define DEBUG
//#define UNICODE
/****************************************************************************************
* CORE - сердцевина рефал-машины
* core хранит описания внутренних типов данных, используемых на уровне работы с байтами
*     юникод-символы
*     бесконечные целые и вещественные
*     и др.
*****************************************************************************************/


namespace co {
    extern long ocount;
    extern long datacount;
    extern long symcount;
    extern long varcount;
    extern long chaincount;

};


#ifdef DEBUG
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

#include <stdlib.h>
#include <string>

//typedef wchar_t         unichar;
//typedef std::wstring    unistring;
typedef unsigned char         unichar;
typedef std::string  unistring;

//#define _L(quote) L##quote
#define _L(quote) quote

typedef long long           infint;
typedef double          infreal;
typedef int             ThisId;     // тип для хранения  идентификатора каждого дататайпа

infint str2infint(unistring si);  // строку в число

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



#endif // REF_CORE_H_INCLUDED

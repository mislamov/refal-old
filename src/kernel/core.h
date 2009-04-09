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

#define REFVERSION "D-Refal 0.0.6 pre-alpha  Copyright (c) 2008-2009 Marat Islamov"
//#define DEBUG

#define _UNICODE
/****************************************************************************************
* CORE - сердцевина рефал-машины
* core хранит описания внутренних типов данных, используемых на уровне работы с байтами
*     юникод-символы
*     бесконечные целые и вещественные
*     и др.
*****************************************************************************************/

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

typedef long            infint;
typedef float           infreal;
typedef int             ThisId;     // тип для хранения  идентификатора каждого дататайпа

infint str2infint(unistring si);  // строку в число

const unistring EmptyUniString = _L("");
const unistring DefaultVarName = _L("");

typedef enum { GO, BACK, FAIL, SUCCESS, ERROR, FORCEBACK } TResult; // результат подпроцесса сопоставления
typedef enum {
    mERROR,
    mNEXT,
    mPRED,
    mOTHER_next,
    mOTHER_pred,
    mFORCEBACK   //
} TMessage; // сообщения для nwxt-pred-point

#endif // REF_CORE_H_INCLUDED

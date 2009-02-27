#ifndef REF_CORE_H_INCLUDED
#define REF_CORE_H_INCLUDED

#define DEBUG

#define _UNICODE
/****************************************************************************************
* CORE - сердцевина рефал-машины
* core хранит описания внутренних типов данных, используемых на уровне работы с байтами
*     юникод-символы
*     бесконечные целые и вещественные
*     и др.
*****************************************************************************************/
#define SYSTEMERROR(msg) { \
    std::cout << "\n\n######## " << __FILE__ << '[' << __LINE__ << "] : "; \
    std::cout << "\n######## " << __FUNCTION__ << "():: " << msg << "\n\n" << std::flush; \
    abort(); \
    };

#define LOG(msg) { \
    std::cout << "\n####### LOG::" << __FILE__ << '[' << __LINE__ << "] : " << __FUNCTION__ << "():: " << msg << "\n" << std::flush; \
    };

#define RUNTIMEERROR(fname, msg) { \
    std::cout << "\n######## RUNTIMEERROR : Error in function " << fname << " :: " << msg << "\n" << std::flush; \
    abort(); \
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


const unistring EmptyUniString = _L("");
const unistring DefaultVarName = _L("");

typedef enum { GO, BACK, FAIL, SUCCESS, ERROR, FORCEBACK } TResult; // результат подпроцесса сопоставления


#endif // REF_CORE_H_INCLUDED

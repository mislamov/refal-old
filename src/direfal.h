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

#ifndef DiRefal_H_INCLUDED
#define DiRefal_H_INCLUDED

#include "data.h"		// данные (data, терм, data-скобки, шаблонные скобки, цепочка)
#include "program.h"	// программа, модуль, функция, шаблон, условие, предложение
#include "session.h"	// сопоставление
#include "system.h"		// основной модуль

#include "SAXLoader_expat.h"

typedef enum {
    XML, XMLCODE, REF
} PROGRAMTYPE;



extern std::streambuf *stdbbuf;
extern std::streambuf *nullbuf;
extern std::ostream   *debugstream;
extern bool verbose;




inline void __verbose_off()  {  if (!verbose){ std::cout.rdbuf(nullbuf); };  }
inline void __verbose_on()   {  if (!verbose){ std::cout.rdbuf(stdbbuf); };  }


class RefFunction {
    RefProgram *program;
    unistring   function;
    bool success;
public:
    RefFunction(RefProgram *p, unistring fname){ success = false; program = p; function = fname; };
    bool isSuccess(){ return success; };
    void execute(RefChain *, unistring&, Session *sess=0);  // for compiled refal-chains
    void execute(unistring,  unistring&);  // for chars
};



class RefalProgram {
    RefProgram *program;
    bool success;
public:
    RefalProgram (PROGRAMTYPE type, unistring fname,  int argc, char **argv);
    RefFunction *getFunction(unistring fname);
    bool isSuccess(){ return success; };
    unistring getProgramName();
};

#endif

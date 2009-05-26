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
// MERCHANTABILITY or FITNEFOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.


#include "kernel\rfunction.h"

#include "SAXLoader.hpp"
#include "kernel\RefSymbolBase.hxx"
#include "kernel\session.h"
#include "kernel\kernel.h"
#include "kernel\datastructs.h"
#include "kernel\evalutor.h"
#include "modules\system.h"

#ifdef WIN32
#include <time.h>
#endif




RefUserModule *mod; // модуль
mSYSTEM msystem;

char *xmlFile;

std::string stringtime(struct tm * tt) {
    std::ostringstream ss;
    ss << ""  << tt->tm_hour << ":" << tt->tm_min << ":" << tt->tm_sec;
    return ss.str();
}

int main ( int argv, char **argc ) {

    std::cout << REFVERSION << "\n" << std::flush;
    if (argv == 1) {
        std::cout << "Usage: "<<argc[0]<<" <file_name.ref>\n\n" << std::flush;
        //return 0;
        argc[1] = //"minitest.ref";
            "fn.ref";
    }

    char
    *pname   = argc[1],
               *binpath = getenv("REFAL_HOME");

    if (binpath == NULL) {
        SYSTEMERROR("Define REFAL_HOME variable into your environment");
    }
    std::string refal_dir = binpath;

    if (refal_dir.at(refal_dir.length()-1) != '\\') {
        refal_dir += '\\';
    }

    std::ostringstream ss0, ss1, ss2;
    //std::cout << ss.str() << std::flush;

    int err = 0;
    if (! strstr(pname, ".xml")) {
        ss0 << ".\\refgo.exe -e " /*<< refal_dir*/ << "refal_scaner " << pname << "\n";
        ss1 << refal_dir << "refgo -e " /*<< refal_dir*/ << "refal_scaner " << pname << "\n";
        ss2 << pname << ".xml";
    } else {
        ss2 << pname;
    }

    err =  system(ss1.str().c_str());
    if (err) {
        err = system(ss0.str().c_str());
        if (err) {
            std::cout << ss0.str().c_str() << std::flush;
            std::cout << ss1.str().c_str() << "\n" << std::flush;
            return err;
        }
    }

    xmlFile = new char[256];
    strncpy(xmlFile, ss2.str().c_str(), 255);


// создали сессию
    Session *s = new Session();

// загрузили модули
//std::cout << msystem.toString() << "\n";
    s->regModule ( &msystem );
    mod = new RefUserModule();
    err = loadModuleFromXmlFile ( mod, xmlFile );
    if (err) return err;
    s->regModule ( mod );
    #ifdef DEBUG
    std::cout << mod->toString() << "\n";
    #endif
    /*        RefData_DOT
                *l = new RefData_DOT(),
                *r = new RefData_DOT(l,0);
    */

    time_t starttime, stoptime;
    time ( &starttime );

#ifdef TESTCODE
//    std::cout << "\n" << stringtime(localtime (&starttime)) << "============================================\n" << std::flush;
    std::cout << "program-data-size: " << co::datacount << "\n" << std::flush;
    std::cout << "program-obj-size : " << co::ocount << "\n============================================\n" << std::flush;
#endif
    RefExecBracket
    *lb = new RefExecBracket(),
    *rb = new RefExecBracket ( lb );

    RefChain *polez = new RefChain();

//*polez += l;
    *polez += lb;
    *polez += new RefNULL();
    *polez += new RefWord ( "Go" );
    *polez += rb;
//*polez += r;

//s->pole_zrenija.push( polez );
    RefChain *result = evalutor ( polez, s );
//s->flush();

    time ( &stoptime );
    std::cout << "============================================\nTime: " /*<< stringtime(localtime (&stoptime)) << "\n"*/ << difftime(stoptime, starttime) << " sec.\n" << std::flush;
    std::cout << "Result: " << result->toString() << "\n";

    result->clear();
#ifdef TESTCODE
    std::cout << "datas in mem: " << co::datacount << "\n";
    std::cout << "objts in mem: " << co::ocount << "\n";
#endif
    return 0;
}

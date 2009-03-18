#include "kernel\rfunction.h"

#include "SAXLoader.hpp"
#include "kernel\RefSymbolBase.hxx"
#include "kernel\session.h"
#include "kernel\kernel.h"
#include "kernel\datastructs.h"
#include "kernel\evalutor.h"
#include "modules\system.h"


RefUserModule *mod; // модуль
mSYSTEM msystem;

char *xmlFile;

std::string stringtime(struct tm * tt) {
    std::ostringstream ss;
    ss << ""  << tt->tm_hour << ":" << tt->tm_min << ":" << tt->tm_sec;
    return ss.str();
}

int main ( int argv, char **argc ) {
    std::cout << "D-Refal 0.0.4 pre-alpha  Copyright (c) 2008-2009 Marat Islamov\n" << flush;
    if (argv == 1) {
        std::cout << "Usage: "<<argc[0]<<" <file_name.ref>\n\n" << flush;
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
    std::string homedir = binpath;

    if (homedir.at(homedir.length()-1) != '\\') {
        homedir += '\\';
    }

    std::ostringstream ss;
    ss << homedir << "refgo -e " << homedir << "refal_scaner " << pname << "\n";
    //std::cout << ss.str() << flush;
    int err = system(ss.str().c_str());
    if (err) {
        return err;
    }

    std::ostringstream ss2;
    ss2 << pname << ".xml";
    xmlFile = new char[256];
    strncpy(xmlFile, ss2.str().c_str(), 255);


// создали сессию
    Session *s = new Session();

// загрузили модули
//std::cout << msystem.toString() << "\n";
    s->regModule ( &msystem );
    mod = new RefUserModule();
    loadModuleFromXmlFile ( mod, xmlFile );
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

//    std::cout << "\n" << stringtime(localtime (&starttime)) << "============================================\n" << std::flush;

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
    return 0;
}

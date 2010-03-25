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

#include "DiRefal.h"
#include "SAXLoader_expat.h"

#include "stringutils.h"

#include <ctime>

std::string stringtime(struct tm *timeptr) {
    char result[256];
    strftime(result, 255, "%H:%M", timeptr);
    return result;
}

int main0 ( int argv, char **argc ) {
    RefProgram *program = new RefProgram();
	Session *sess = new Session(program);
	RefChain *res = program->executeExpression(new RefChain(sess), sess);
	std::cout << res->debug();
	return 0;
}

int main ( int argv, char **argc ) {
    char *xmlFile;
    RefUserModule *mod;

    RefProgram *program = new RefProgram();

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
        SYSTEMERRORn("Define REFAL_HOME variable into your environment");
    }
    std::string refal_dir = binpath;

    if (refal_dir.at(refal_dir.length()-1) != '\\') {
        refal_dir += '\\';
    }

    std::ostringstream ss0, ss1, ss2;
    //std::cout << ss.str() << std::flush;

    int err = 0;
    if (! strstr(pname, ".xml")) {
        ss0 << ".\\refgo.exe -e "  << "DiRefal_scaner " << pname << "\n";
        ss1 << refal_dir << "refgo -e " /*<< refal_dir*/ << "DiRefal_scaner " << pname << "\n";
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
        #ifdef DEBUG
        LOG("program: " << ss0.str());
        #endif

    } else {
        #ifdef DEBUG
        LOG("program: " << ss1.str());
        #endif
    }

    xmlFile = new char[256];
    strncpy(xmlFile, ss2.str().c_str(), 255);

    Session *sess = new Session(program);

    mod = new RefUserModule(getModuleNameFromFileName(xmlFile));
    program->regModule(mod);
    err = loadModuleFromXmlFile ( mod, program, xmlFile );
    if (err) return err;
    #ifdef DEBUG
    std::cout << mod->debug() << "\n";
    #endif

    //std::cout << sess->debug();


    time_t starttime, stoptime;
    time ( &starttime );
    #ifdef TESTCODE

    std::cout << "\n";
    //<< stringtime(localtime (&starttime))
    std::cout << "============================================\n" << std::flush;
    std::cout << "program-obj-size : " << co::objs  << "\n" << std::flush;
    //std::cout << "program-var-size : " << co::vars  << "\n" << std::flush;
    std::cout << "program-data-size: " << co::datas << "\n" << std::flush;
    std::cout << "program-chain-size: " << co::chains << "\n" << std::flush;
    std::cout << "program-brack-size: " << co::stbracks << "\n" << std::flush;
    std::cout << "============================================\n" << std::flush;
    #endif

    RefChain *polez = new RefChain(sess);

    *polez += new RefExecBrackets(sess, new RefChain(sess, new RefWord (sess, "Go" )));

    RefChain *result = program->executeExpression( polez, sess );

    std::cout << "============================================\nTime: " ;
    //#ifdef TESTCODE
    time ( &stoptime );
    std::cout
    << difftime(stoptime, starttime) << " sec.\n"
    << std::flush;
    //#endif
    std::cout << "Result: " << result->debug() << "\n";

    sess->gc_prepare();
    sess->gc_clean();

    //delete polez;
    //delete result;

    delete program;
	RefAlpha::alphaMapDestroy();
    delete[] RefAlpha128::alphatable;

    #ifdef TESTCODE
    std::cout << "program-obj-size : " << co::objs  << "\n" << std::flush;
    //std::cout << "program-var-size : " << co::vars  << "\n" << std::flush;
    std::cout << "program-data-size: " << co::datas << "\n" << std::flush;
    std::cout << "program-chain-size: " << co::chains << "\n" << std::flush;
    std::cout << "program-brack-size: " << co::stbracks << "\n" << std::flush;

    #endif

    //std::cout << s->debug();

    return 0;

}

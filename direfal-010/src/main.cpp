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
#include "SAXLoader.hpp"

#include "stringutils.h"

#ifdef WIN32
#include <time.h>
#endif

/*
int main ( int argv, char **argc ) {
	RefChain *chain1 = new RefChain();
	RefChain *chain2 = new RefChain();

	chain1 = textToChain("abcDEFghiDEFJKLmno");
	chain2 = 
			textToChain("abc")+
			*(new RefVariable_s("D"))+
			*(new RefVariable_s("E"))+
			*(new RefVariable_s("F"))+
			*textToChain("ghi");
	*chain2 +=
		*(new RefLinkToVariable("D", chain2))+
			*(new RefLinkToVariable("E", chain2))+
			*(new RefLinkToVariable("F", chain2))+
				*textToChain("JKLmno");

	std::cout << chain1->debug()<< "\n" ;
	std::cout << chain2->debug()<< "\n" ;

	Session *sess = new Session();
	sess->createVarMap();
	if (sess->matching(0, chain2, chain1, false)){
		std::cout << "true\n";
	} else {
		std::cout << "false\n";
	}
	std::cout << sess->debug() << "\n\n";

	RefChainConstructor *chain3 = 
		textToChain("begnin ")+
		*(new RefLinkToVariable("E", chain2))+
		*textToChain(" end");

	std::cout << chain3->debug() << "\n" << 
	sess->substituteExpression(chain3)->debug() << "\n";
}
*/


int main ( int argv, char **argc ) {
char *xmlFile;
RefUserModule *mod; 

	RefProgram program;

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

	Session *s = new Session(&program);

    mod = new RefUserModule(getModuleNameFromFileName(xmlFile));
	program.regModule(mod);
    err = loadModuleFromXmlFile ( mod, &program, xmlFile );
    if (err) return err;
    #ifdef DEBUG
    std::cout << mod->debug() << "\n";
    #endif


//    time_t starttime, stoptime;
//    time ( &starttime );

#ifdef TESTCODE
//    std::cout << "\n" << stringtime(localtime (&starttime)) << "============================================\n" << std::flush;
//    std::cout << "program-data-size: " << co::datacount << "\n" << std::flush;
//    std::cout << "program-obj-size : " << co::ocount << "\n============================================\n" << std::flush;
#endif

    RefChain *polez = new RefChain();

	*polez += new RefExecBrackets(new RefChain(new RefWord ( "Go" )));

	RefChain *result = program.executeExpression( polez, s );

//    time ( &stoptime );
    std::cout << "============================================\nTime: " 
	//<< stringtime(localtime (&stoptime)) << "\n"
//	<< difftime(stoptime, starttime) << " sec.\n" 
	<< std::flush;
    std::cout << "Result: " << result->debug() << "\n";

    delete result;
#ifdef TESTCODE
//    std::cout << "datas in mem: " << co::datacount << "\n";
//    std::cout << "objts in mem: " << co::ocount << "\n";
#endif


    return 0;

}

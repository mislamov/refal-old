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
#include <iostream>
#include <fstream>

std::string stringtime(struct tm *timeptr) {
	char result[256];
	strftime(result, 255, "%H:%M", timeptr);
	return result;
}

void help(char *pname){
	std::cout << REFVERSION << "\n" << std::flush;
	std::cout << "Usage: "<< pname <<" [-h|--help] [-v|--verbose] [-d|--debug] filename [arg1 arg2 ... argN]\n" << std::flush;
	std::cout << "\t-h (or --help) to see this message\n" << std::flush;
	std::cout << "\t-v (or --verbose) to see more information when program execution\n" << std::flush;
	std::cout << "\t-d (or --debug) to see debug information when program execution\n" << std::flush;
}

int main ( int argc, char **argv ) {
	bool verbose = false;
	bool debug = false;

	if (argc <= 1) {
		help(argv[0]);		
		return 0;
	}

	char *prog = 0;
	for (int i=1; i<argc; ++i){
		if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help")){
			help(argv[0]);
			return 0;
		}
		if (!strcmp(argv[i], "-v") || !strcmp(argv[i], "--verbose")){
			verbose = true;
			continue;
		}
		if (!strcmp(argv[i], "-d") || !strcmp(argv[i], "--debug")){
			debug = true;
			continue;
		}
		if (argv[i] && argv[i][0]=='-'){
			RUNTIMEERRORn("Invalid option: " << argv[i]);
			return -2;
		}

		// имя файла программы и аргументы
		prog = argv[i];
		argc = argc - i;
		argv = (argc-1)? &(argv[i]) : 0;
		break;
	}


	if (!prog) {
		RUNTIMEERRORn("File expected.");
		return -1;
	}


	// перенаправляем поток в файл
	std::streambuf *stdbuf = 0;
	std::ostream nullstream(0, false);
	if (!verbose){
		stdbuf = std::cout.rdbuf(nullstream.rdbuf());
	}

	char *scanerxmlFile = "direfal_scaner.xml";
	RefUserModule *parser = new RefUserModule(getModuleNameFromFileName(scanerxmlFile));	
	RefProgram *program = new RefProgram( argc, argv );
	Session *sess = new Session( program );

	// сначала сгенерируем xml запускаемой рефал-программы
	program->regModule( parser );
	int err = loadModuleFromXmlFile ( parser, program, scanerxmlFile);
	if (err) return err;

	//std::cout << parser->debug() << "\n";


	std::string go_function_name = "REFAL";
	RefChain *executeline = new RefChain(sess, new RefWord (sess, go_function_name));
	(*executeline) += text_to_chain(sess, prog);
	RefChain *result = program->executeExpression( 
		new RefChain(sess, new RefExecBrackets(sess, executeline)), 
		sess 
		);
	// теперь в result результат синт- и семант-ического анализа и оптимизации. При успехе - это термальное слово = имя созданного файла
	if (!verbose){
		std::cout.rdbuf(stdbuf);
	}



	unistring rslname = "";
	if (result->getLength()==1 && ref_dynamic_cast<RefWordBase>(*(result->at_first()))){
		rslname = ((RefWordBase*)*(result->at_first()))->explode();
	} else {
		// найдены ошибки
		return -1;
	}

	sess->gc_clean(); // полная очистка мусора

	// запуск выполняемой программы
	RefUserModule *mod = new RefUserModule(getModuleNameFromFileName(rslname));
	program->regModule(mod);
	err = loadModuleFromXmlFile ( mod, program, rslname.c_str());
	if (err) return err;
	#ifdef DEBUG
	std::cout << mod->debug() << "\n";
	#endif

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

	RefChain *polez = new RefChain(sess, new RefExecBrackets(sess, new RefChain(sess, new RefWord (sess, "Go" ))));
	result = program->executeExpression( polez, sess );

	std::cout << "============================================\nTime: " ;
	//#ifdef TESTCODE
	time ( &stoptime );
	std::cout
		<< difftime(stoptime, starttime) << " sec.\n"
		<< std::flush;
	//#endif
	std::cout << "Result: " << result->debug() << "\n";

	//sess->gc_prepare(); - не нужно, так как отметка уже снята у всех (снимается при создании и при сборке)
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

int main0 ( int argc, char **argv ) {
	char *xmlFile;
	RefUserModule *mod;

	RefProgram *program = new RefProgram(argc, argv);

	std::cout << REFVERSION << "\n" << std::flush;
	if (argc == 1) {
		std::cout << "Usage: "<<argv[0]<<" <file_name.ref>\n\n" << std::flush;
		//return 0;
		argv[1] = //"minitest.ref";
			"fn.ref";
	}

	char
		*pname   = argv[1],
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

	//sess->gc_prepare(); - не нужно, так как отметка уже снята у всех (снимается при создании и при сборке)
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

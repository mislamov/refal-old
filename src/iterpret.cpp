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

char *xmlFile = "minitest.ref.xml";

std::string stringtime(struct tm * tt){
    std::ostringstream ss;
    ss << ""  << tt->tm_hour << ":" << tt->tm_min << ":" << tt->tm_sec;
    return ss.str();
}

int main ( int argv, char **argc ) {
	if ( argv < 2 ) {
			xmlFile = "minitest.ref.xml";
			//SYSTEMERROR("Use " << argc[0] << " FILE.XML\n" );
		} else {
			xmlFile = argc[1];
		}

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

    std::cout << "\n" << stringtime(localtime (&starttime)) << "============================================\n" << std::flush;

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

	std::cout << "\n\nRETURN: " << result->toString() << "\n";
    time ( &stoptime );
    std::cout << "============================================\n" << stringtime(localtime (&stoptime)) << "\n" << difftime(stoptime, starttime) << " sec.\n" << std::flush;
	return 0;
}

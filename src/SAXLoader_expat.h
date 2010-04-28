#ifndef SAXLOADER_EXPAT_H
#define SAXLOADER_EXPAT_H

#include "direfal.h"

#include <stdio.h>
#include <expat/expat.h>

	#if defined(__amigaos__) && defined(__USE_INLINE__)
	#include <expat/proto/expat.h>
	#endif

	#ifdef XML_LARGE_SIZE
	#if defined(XML_USE_MSC_EXTENSIONS) && _MSC_VER < 1400
	#define XML_FMT_INT_MOD "I64"
	#else
	#define XML_FMT_INT_MOD "ll"
	#endif
	#else
	#define XML_FMT_INT_MOD "l"
	#endif

	#define BUFFSIZE        8192

int loadModuleFromXmlFile(RefUserModule*, RefProgram*, const char* );
int loadModuleFromXmlCode(RefUserModule*, RefProgram*, const char*, size_t len);


#endif

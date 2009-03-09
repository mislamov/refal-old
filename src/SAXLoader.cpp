/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * $Id: SAXPrint.cpp 471735 2006-11-06 13:53:58Z amassari $
 */


// ---------------------------------------------------------------------------
//  Includes
// ---------------------------------------------------------------------------
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/TransService.hpp>
#include <xercesc/parsers/SAXParser.hpp>
#include <xercesc/util/OutOfMemoryException.hpp>

#include "SAXLoader.hpp"

#include "function.h"
#include "kernel/kernel.h"
#include "kernel/session.h"
#include "kernel/RefSymbolBase.hxx"

#include <strings.h>
// ---------------------------------------------------------------------------
//  Local data
//
//  doNamespaces
//      Indicates whether namespace processing should be enabled or not.
//      Defaults to disabled.
//
//  doSchema
//      Indicates whether schema processing should be enabled or not.
//      Defaults to disabled.
//
//  schemaFullChecking
//      Indicates whether full schema constraint checking should be enabled or not.
//      Defaults to disabled.
//
//  encodingName
//      The encoding we are to output in. If not set on the command line,
//      then it is defaulted to LATIN1.
//
//  xmlFile
//      The path to the file to parser. Set via command line.
//
//  valScheme
//      Indicates what validation scheme to use. It defaults to 'auto', but
//      can be set via the -v= command.
// ---------------------------------------------------------------------------
static bool                     doNamespaces        = false;
static bool                     doSchema            = false;
static bool                     schemaFullChecking  = false;
static const char*              encodingName    = "UTF-8";
//
//static const char*              encodingName    = "USASCII";
static XMLFormatter::UnRepFlags unRepFlags      = XMLFormatter::UnRep_CharRef;
//static char*                    xmlFile         = 0;
static SAXParser::ValSchemes    valScheme       = SAXParser::Val_Never;



// ---------------------------------------------------------------------------
//  Local helper methods
// ---------------------------------------------------------------------------
static void usage()
{
    XERCES_STD_QUALIFIER cout << "\nUsage:\n"
            "    SAXPrint [options] <XML file>\n\n"
            "This program invokes the SAX Parser, and then prints the\n"
            "data returned by the various SAX handlers for the specified\n"
            "XML file.\n\n"
            "Options:\n"
             "    -u=xxx      Handle unrepresentable chars [fail | rep | ref*].\n"
             "    -v=xxx      Validation scheme [always | never | auto*].\n"
             "    -n          Enable namespace processing.\n"
             "    -s          Enable schema processing.\n"
             "    -f          Enable full schema constraint checking.\n"
             "    -x=XXX      Use a particular encoding for output (LATIN1*).\n"
             "    -?          Show this help.\n\n"
             "  * = Default if not provided explicitly.\n\n"
             "The parser has intrinsic support for the following encodings:\n"
             "    UTF-8, USASCII, ISO8859-1, UTF-16[BL]E, UCS-4[BL]E,\n"
             "    WINDOWS-1252, IBM1140, IBM037, IBM1047.\n"
         <<  XERCES_STD_QUALIFIER endl;
};





RefChain *str2chain(std::wstring s){

        RefAlpha *beg = new RefAlpha(s[0]),  *end = beg;
        for(int i=1; i<s.size(); i++){
                end = new RefAlpha(s[i], end);
        };

        return new RefChain(beg, end);
};


unistring getModuleNameFromFileName(unistring fname){
    unistring::size_type i = fname.length()-1;
    while (i && fname[i--] != ':');
    if (!i) {
        fname = fname;
    } else {
        SYSTEMERROR("--== zaglushka module using ==--");
        fname = "errornaME.TXT";
    }

    // óäàëÿåì ðàñøèðåíèÿ
    unistring newname = "";
    i=0;
    while (i<fname.length()){
        if (fname[i] == '.'){
            return newname;
        }
        newname += fname[i++];
    }

    return newname;
};

// ---------------------------------------------------------------------------
//  Program entry point
// ---------------------------------------------------------------------------
int loadModuleFromXmlFile(RefUserModule *mod, char* xmlFile)
{
    // xmlFile - äîëæíà áûòü îòíîñèòåëüíûì èìåíåì îò ïàïêè ïðîåêòà

    mod->setName( getModuleNameFromFileName(xmlFile) );

    // Initialize the XML4C2 system
    try
    {   XMLPlatformUtils::Initialize();    }
    catch (const XMLException& toCatch){
         XERCES_STD_QUALIFIER cerr << L"Error during initialization! :\n"
              << StrX(toCatch.getMessage()) << XERCES_STD_QUALIFIER endl;
         return 1;
    }

    //
    //  Create a SAX parser object. Then, according to what we were told on
    //  the command line, set it to validate or not.
    //
    SAXParser* parser = new SAXParser();
    parser->setValidationScheme(valScheme);
    parser->setDoNamespaces(doNamespaces); // false
    parser->setDoSchema(doSchema); // false
    parser->setValidationSchemaFullChecking(schemaFullChecking);

    //
    //  Create the handler object and install it as the document and error
    //  handler for the parser-> Then parse the file and catch any exceptions
    //  that propogate out
    //
    int errorCount = 0;
    int errorCode = 0;
    try
    {
        SAXPrintHandlers handler(encodingName, unRepFlags, mod);
        parser->setDocumentHandler(&handler);
        parser->setErrorHandler(&handler);
        parser->parse(xmlFile);
        errorCount = parser->getErrorCount();
    }
    catch (const OutOfMemoryException&)
    {
        XERCES_STD_QUALIFIER cerr << "OutOfMemoryException" << XERCES_STD_QUALIFIER endl;
        errorCode = 5;
    }
    catch (const XMLException& toCatch)
    {
        XERCES_STD_QUALIFIER cerr << "\nAn error occurred\n  Error: "
             << StrX(toCatch.getMessage())
             << "\n" << XERCES_STD_QUALIFIER endl;
        errorCode = 4;
    }
    if(errorCode) {
        XMLPlatformUtils::Terminate();
        return errorCode;
    }

    //
    //  Delete the parser itself.  Must be done prior to calling Terminate, below.
    //
    delete parser;

    // And call the termination method
    XMLPlatformUtils::Terminate();

    if (errorCount > 0)
        return 4;
    else
        return 0;
}


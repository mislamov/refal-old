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
 * $Id: SAXPrintHandlers.hpp 557282 2007-07-18 14:54:15Z amassari $
 */


#include    <xercesc/sax/HandlerBase.hpp>
#include    <xercesc/framework/MemBufFormatTarget.hpp>

#include "refal.h"

#include "stack"
#include "map"

XERCES_CPP_NAMESPACE_USE

class LoaderHeap;

class SAXPrintHandlers : public HandlerBase, private MemBufFormatTarget
{
    LoaderHeap *loader;

public:
    // -----------------------------------------------------------------------
    //  Constructors
    // -----------------------------------------------------------------------
    SAXPrintHandlers
    (
        const   char* const                 encodingName
        , const XMLFormatter::UnRepFlags    unRepFlags
        , RefUserModule *mod
		, RefProgram   *progr
		 
    );
    ~SAXPrintHandlers();


    // -----------------------------------------------------------------------
    //  Implementations of the format target interface
    // -----------------------------------------------------------------------
    void writeChars
    (
        const   XMLByte* const  toWrite
    );

    virtual void writeChars
    (
        const   XMLByte* const  toWrite
        , const XMLSize_t       count
        , XMLFormatter* const   formatter
    );


    // -----------------------------------------------------------------------
    //  Implementations of the SAX DocumentHandler interface
    // -----------------------------------------------------------------------
    void endDocument();

    void endElement(const XMLCh* const name);

    void characters(const XMLCh* const chars, const unsigned int length);
	void characters(const XMLCh* const chars, const XMLSize_t length){ return characters(chars, (unsigned int)length); };

    void ignorableWhitespace
    (
        const   XMLCh* const    chars
        , const XMLSize_t       length
    );

    void processingInstruction
    (
        const   XMLCh* const    target
        , const XMLCh* const    data
    );

    void startDocument();

    void startElement(const XMLCh* const name, AttributeList& attributes);



    // -----------------------------------------------------------------------
    //  Implementations of the SAX ErrorHandler interface
    // -----------------------------------------------------------------------
    void warning(const SAXParseException& exc);
    void error(const SAXParseException& exc);
    void fatalError(const SAXParseException& exc);



    // -----------------------------------------------------------------------
    //  Implementation of the SAX DTDHandler interface
    // -----------------------------------------------------------------------
    void notationDecl
    (
        const   XMLCh* const    name
        , const XMLCh* const    publicId
        , const XMLCh* const    systemId
    );

    void unparsedEntityDecl
    (
        const   XMLCh* const    name
        , const XMLCh* const    publicId
        , const XMLCh* const    systemId
        , const XMLCh* const    notationName
    );


private :
    // -----------------------------------------------------------------------
    //  Private data members
    //
    //  fFormatter
    //      This is the formatter object that is used to output the data
    //      to the target. It is set up to format to the standard output
    //      stream.
    // -----------------------------------------------------------------------
    XMLFormatter    fFormatter;
};



class LoaderHeap {
        std::map<unistring, std::stack<RefObject*> > stackstags;
        std::stack<RefChain *>  stckChains;

    public:
        RefUserModule *currentModule;
		RefProgram    *currentProgram;
        RefCondition*  currentCondition;
        std::stack<unistring >  activeTag;
        unistring currentchars;
        unistring templateOrSent;


        RefObject *extractValueFromStack(unistring name){
            std::stack<RefObject*>  &svalue   = stackstags[name];
            //std::cout << "\n--stackstags["<<name<<"]("<< stackstags[name].size() <<")" << std::flush;
            #ifdef TESTCODE
            if (svalue.empty()) SYSTEMERROR("unexpected extracter query: " << name);
            #endif
            RefObject* value = svalue.top();
            //std::cout << "\n--extractValueFromStack["<<name<<"]::" << value->toString();
            svalue.pop();
            //std::cout << "\n"<< "--stackstags["<<name<<"].count="<< (stackstags[name].size()) <<"\n";
            return value;
        }
        RefObject *getValueFromStack(unistring name){
            std::stack<RefObject*>  &svalue   = stackstags[name];
            //std::cout << "\n~~getValueFromStack[" << name << "] " << stackstags[name].size() << std::flush;
            //std::cout << "\n~~getValueFromStack[" << name << "] " << svalue.size() << std::flush;
            #ifdef TESTCODE
            //std::cout << "\nsvalue.size()==" << svalue.size() << "   svalue.size()==0:" << bool(svalue.size()==0);
            if ( svalue.size()==0 )
                SYSTEMERROR("unexpected extracter query: " << name << std::flush);
            #endif
            RefObject* value = svalue.top();
            //svalue.pop();
            //std::cout << "\n~~getValueFromStack::" << value->toString();
            //std::cout << "\n"<< "~~stackstags["<<name<<"].count="<< (stackstags[name].size()) <<"\n";
            return value;
        }
        void createChainToStack(){
            stckChains.push(new RefChain());
        }
		void createSubstitutionToStack(){
			stckChains.push(new ChainSubstitution());
        }
        RefChain* extractCurrChainFromStack(){
            #ifdef TESTCODE
            if (stckChains.empty()) SYSTEMERROR("tring extract from empty stckChains");
            #endif
            RefChain *r = stckChains.top();
            stckChains.pop();
            return r;
        }
        RefChain* getCurrChain(){
            return stckChains.top();
        }
        RefObject* putValueToStack(unistring name, RefObject* o){
            /** /
            std::cout<<"\n++putValueToStack(";
            std::cout<<name;
            std::cout<<", ";
            std::cout<<(long)o;
            std::cout << o->toString();
            std::cout << ")";// */
            stackstags[name].push(o);
            //std::cout << "\n"<< "++stackstags["<<name<<"].count="<< (stackstags[name].size()) <<"\n";
            return o;
        }
        void setChars(unistring ch){
            currentchars = ch;
        }
        unistring getChars(){
            return currentchars + (currentchars="");
        }


        //RefData *getNewEmptyRefSymbolByTypeName(unistring);
        RefVariableBase *getVariableByTypename(unistring vtype, unistring vname);


        LoaderHeap(RefUserModule *m, RefProgram *p){
            currentModule  = m;
			currentProgram = p;
        };
};


#include <xercesc/util/XMLUniDefs.hpp>
#include <xercesc/sax/AttributeList.hpp>
#include "SAXLoader.hpp"

#include <string>
#include <stack>
#include <locale>

//#define unistring std::wstring
//#define unichar   wchar_t

#include "kernel/rfunction.h"
#include "kernel/core.h"
#include "kernel/data.h"
#include "kernel/kernel.h"
#include "kernel/refsymbolbase.hxx"

//using namespace core;

typedef std::basic_string<XMLCh> XercesString;

unistring toWstring(const XercesString& str, unsigned int len){
    #ifdef DEBUG
    unistring result(str.begin( ), str.end( ));
    //std::cout << "\t#### WARNING: toWstring(" << result << ", " << len << ")\t";
    return result;
    #else
    return unistring(str.begin( ), str.end( ));
    #endif
}
unistring toWstring(const XercesString& str){
    return unistring(str.begin( ), str.end( ));
}
XercesString wstringToXerces(const unistring& str){
    return XercesString(str.begin( ), str.end( ));
}

/*

<Function name="Mu">
<Exec name="Mu">
<Var  name="else">Refal::Heap

*/


// ---------------------------------------------------------------------------
//  SAXPrintHandlers: Overrides of the SAX DocumentHandler interface
// ---------------------------------------------------------------------------
void SAXPrintHandlers::startDocument(){
    //std::cout << _L("SAXPrintHandlers::startDocument::. \n");
}


void SAXPrintHandlers::startElement(const   XMLCh* const  name,  AttributeList&  attributes){
    RefObject *tmp = 0;

    unistring command = toWstring(name);
    std::cout << _L("SAXPrintHandlers::startElement::[") << command << "] (attr: "<< attributes.getLength() << " )\n";
    loader->activeTag.push(command);

#ifdef DEBUG
try {
#endif
    if ( command.compare(_L("BEGIN")) == 0 ) {
    } else
    if ( command.compare(_L("FUNCTION")) == 0) {
            if (! attributes.getLength() || !attributes.getValue("name")) SYSTEMERROR("FUNCTION WITHOUT name");
            loader->putValueToStack(command, new RefUserFunction(toWstring(attributes.getValue("name"))));
    } else
    if ( command.compare(_L("TEMPLATE")) == 0) {
            SYSTEMERROR("Templates are switched off! (testing)");
            if (! attributes.getLength() || !attributes.getValue("name")) SYSTEMERROR("TEMPLATE WITHOUT name");
            loader->putValueToStack(command, new RefUserTemplate(toWstring(attributes.getValue("name"))));
    } else
    if ( command.compare(_L("SENTENCE")) == 0) {
            loader->putValueToStack(command, new RefSentence());
    } else
    if ( command.compare(_L("LEFT-PART")) == 0) {
            loader->createChainToStack();
    } else
    if ( command.compare(_L("RIGHT-PART")) == 0) {
            loader->createChainToStack();
    } else
    if ( command.compare(_L("EXEC")) == 0) {  //     <
            RefExecBracket *t = new RefExecBracket();
            loader->putValueToStack("BRACKET", t);
            *(loader->getCurrChain()) += t;
            *(loader->getCurrChain()) += new RefNULL();

            //std::cout << "\n\n" << loader->getCurrChain()->toString() << "\n\n";
    } else
    if ( command.compare(_L("VAR")) == 0) {  //
        // ничего не делаем, так как при закрытии тега воспользуемся менеджером переменных и текущим тексом=описателем переменной
    } else
    if ( command.compare(_L("LNK")) == 0) {  // ссылка на переменную
        // ничего не делаем, так как при закрытии тега воспользуемся менеджером переменных и текущим тексом=описателем переменной
    } else
    if ( command.compare(_L("TEXT")) == 0) {  //
        // ничего не делаем, так как при закрытии тега все сделаем
    } else
    if ( command.compare(_L("BRACKET")) == 0 ) {
            RefStructBracket *t = new RefStructBracket();
            loader->putValueToStack("BRACKET", t);
            *(loader->getCurrChain()) += t;
            *(loader->getCurrChain()) += new RefNULL();
    } else
    if ( command.compare(_L("IF")) == 0 ) {
            loader->currentCondition = new RefCondition();
    } else
    if ( command.compare(_L("ERROR")) == 0 ) {
    } else
    /*****************   выделить в менеджер для простого добавления пользовательских типов  *****************/
    if (tmp = getNewEmptyRefSymbolByTypeName(command)){ // рефал-символ
        loader->putValueToStack(command, tmp);
    } else

    SYSTEMERROR("unknown tag name: " << command);
#ifdef DEBUG
} catch(int i) {
    SYSTEMERROR("excepion!");
}
#endif
}

void SAXPrintHandlers::characters(const     XMLCh* const    chars
                                  , const   unsigned int       length)
{
    //std::setlocale(LC_ALL, "ru_RU.UTF-8");
    loader->currentchars = toWstring(chars, length);
    #ifdef DEBUG
    unistring ss = toWstring(chars);
    std::cout << "SAXPrintHandlers::characters:: " << ss.c_str() << "\n";
    #endif
    //fFormatter.formatBuf(chars, length, XMLFormatter::CharEscapes);
}


void SAXPrintHandlers::endDocument()
{
    //std::cout << _L("SAXPrintHandlers::endDocument::. \n");
}

// от str остается только описание типа переменной
unistring getVarName(unistring &str){
        unistring tip = _L("");
        unistring name = _L("");
        int i=str.length()-1;
        for (; (i>0)&&str[i]!='.'; i--){
            name = str[i] + name;
        }
        if (!i) SYSTEMERROR("No dot in VARiable discription!");
        for (i-=1; (i>=0); i--){
            tip = str[i]+tip;
        }
        str = tip;
        #ifdef DEBUG
        //std::cout << "[VAR::name:"<<name<<":type:"<<tip<<"]";
        #endif
        return name;
}

void SAXPrintHandlers::endElement(const XMLCh* const name)
{
    std::cout << _L("SAXPrintHandlers::endElement:: [") << toWstring(name) << "]\n";
    RefObject *tmpobj = 0;
    RefValuedData *tmpvdata = 0;
    unistring command = toWstring(name);

    #ifdef DEBUG
    try {
    #endif
    if (! command.compare(_L("BEGIN"))) {
        // модуль прочитан полностью
    } else
    if ( command.compare(_L("FUNCTION")) == 0) {
            #ifdef DEBUG
            if (! dynamic_cast<RefUserFunction *>(loader->getValueFromStack("FUNCTION"))) SYSTEMERROR("not RefUserFunction in FUNCTION-stack !!!");
            #endif
            RefUserFunction *f =  (RefUserFunction*)loader->extractValueFromStack("FUNCTION");
            loader->currentModule->objects[f->getName()] = f;
    } else
    if ( command.compare(_L("TEMPLATE")) == 0) {
            #ifdef DEBUG
            if (! dynamic_cast<RefUserTemplate *>(loader->getValueFromStack("TEMPLATE"))) SYSTEMERROR("not TEMPLATE in TEMPLATE-stack !!!");
            #endif
            RefUserTemplate *t =  (RefUserTemplate*)loader->extractValueFromStack("TEMPLATE");
            //std::cout << "\n\nlp: " << loader->getCurrChain()->toString() << "\n\n" << std::flush;
            t->setLeftPart( loader->extractCurrChainFromStack() );
            loader->currentModule->objects[t->getName()] = t;
    } else
    if ( command.compare(_L("SENTENCE")) == 0) {
            #ifdef DEBUG
            if (! dynamic_cast<RefSentence *>(loader->getValueFromStack("SENTENCE"))) SYSTEMERROR("not SENTENCE in SENTENCE-stack !!!");
            if (! dynamic_cast<RefUserFunction *>(loader->getValueFromStack("FUNCTION"))) SYSTEMERROR("not FUNCTION in FUNCTION-stack !!!");
            #endif
            RefSentence     *s =  (RefSentence*)loader->extractValueFromStack("SENTENCE");
            s->rightPart = loader->extractCurrChainFromStack();
            s->leftPart  = loader->extractCurrChainFromStack();
            RefUserFunction *f =  (RefUserFunction*)loader->getValueFromStack("FUNCTION");
            (f->body).push_back(s);
    } else
    if ( command.compare(_L("LEFT-PART")) == 0) {
        /*
            #ifdef DEBUG
            if (! dynamic_cast<RefSentence *>(loader->getValueFromStack("SENTENCE"))) SYSTEMERROR("not SENTENCE in SENTENCE-stack !!!");
            #endif
            RefSentence  *s =  (RefSentence*)loader->getValueFromStack("SENTENCE");
            s->leftPart = loader->extractCurrChainFromStack();
        */
    } else
    if ( command.compare(_L("RIGHT-PART")) == 0) {
        /*
            #ifdef DEBUG
            if (! dynamic_cast<RefSentence *>(loader->getValueFromStack("SENTENCE"))) SYSTEMERROR("not SENTENCE in SENTENCE-stack !!!");
            #endif
            RefSentence  *s =  (RefSentence*)loader->getValueFromStack("SENTENCE");
            s->rightPart = loader->extractCurrChainFromStack();
        */
    } else
    if ( command.compare(_L("EXEC")) == 0) {  //     <
            //std::cout << "EndElement:" << command;
            //std::cout << " stack["<<"BRACKET"<<"]:" << loader->getValueFromStack("BRACKET")->toString();

            RefExecBracket *br = dynamic_cast<RefExecBracket *>(loader->extractValueFromStack("BRACKET"));
            #ifdef DEBUG
            if (! br) SYSTEMERROR("not EXEC BRACKET in BRACKET-stack !!!");
            #endif
            RefExecBracket *brclose = new RefExecBracket(br, 0);
            *(loader->getCurrChain()) += brclose;
    } else
    if ( command.compare(_L("VAR")) == 0) {  //
        // берем по текущему тексту и получаем ссылку на переменную
        unistring vardescr = loader->currentchars;
        unistring vname = getVarName(vardescr); // теперь vname - имя vardescr - тип
        *(loader->getCurrChain()) += getVariableByTypename(vardescr, vname);
        //std::cout << loader->getCurrChain()->second->toString();
    } else
    if ( command.compare(_L("LNK")) == 0) {  //
        // берем по текущему тексту и получаем ссылку на переменную
        *(loader->getCurrChain()) += new RefLinkToVariable(loader->currentchars);
        //std::cout << loader->getCurrChain()->second->toString();
    } else
    if ( command.compare(_L("TEXT")) == 0) {  //
        unistring text = loader->currentchars;
        for (int i=0; i<text.length(); i++){
            *(loader->getCurrChain()) += new RefAlpha(text[i]);
        }
    } else
    if ( command.compare(_L("BRACKET")) == 0 ) {
            RefStructBracket *br = dynamic_cast<RefStructBracket *>(loader->extractValueFromStack("BRACKET"));
            #ifdef DEBUG
            if (! br) SYSTEMERROR("not STRUCT BRACKET in BRACKET-stack !!!");
            #endif
            RefStructBracket *brclose = new RefStructBracket(br, 0);
            *(loader->getCurrChain()) += brclose;
    } else
    if ( command.compare(_L("IF")) == 0 ) {
            RefCondition* cond = loader->currentCondition;
            cond->setLeftPart (loader->extractCurrChainFromStack());
            cond->setRightPart(loader->extractCurrChainFromStack());
            *(loader->getCurrChain()) += cond;
    } else
    if ( command.compare(_L("ERROR")) == 0 ) {
        std::cout << "\n##########################################################################################";
        std::cout << "\n\t" << loader->currentchars;
        std::cout << "\n##########################################################################################\n";
    } else
    /*****************   выделить в менеджер для простого добавления пользовательских типов  *****************/
    //if (tmp = getNewEmptyRefSymbolByTypeName(command)){ // рефал-символ
    //    loader->putValueToStack(command, tmp);
    //} else
    if (tmpvdata = dynamic_cast<RefValuedData *> (loader->extractValueFromStack(command))){
        tmpvdata->setValueFromString(loader->currentchars);
        *(loader->getCurrChain()) += tmpvdata;
    } else

    SYSTEMERROR("unknown tag name: " << command);
    #ifdef DEBUG
    } catch(int i) {
        SYSTEMERROR("excepion!");
    }
    #endif


    loader->activeTag.pop();
    // No escapes are legal here
    //fFormatter << XMLFormatter::NoEscapes << gEndElement << name << chCloseAngle;
}






// ---------------------------------------------------------------------------
//  Local const data
//
//  Note: This is the 'safe' way to do these strings. If you compiler supports
//        L"" style strings, and portability is not a concern, you can use
//        those types constants directly.
// ---------------------------------------------------------------------------
static const XMLCh  gEndElement[] = { chOpenAngle, chForwardSlash, chNull };
static const XMLCh  gEndPI[] = { chQuestion, chCloseAngle, chNull };
static const XMLCh  gStartPI[] = { chOpenAngle, chQuestion, chNull };
static const XMLCh  gXMLDecl1[] =
{
        chOpenAngle, chQuestion, chLatin_x, chLatin_m, chLatin_l
    ,   chSpace, chLatin_v, chLatin_e, chLatin_r, chLatin_s, chLatin_i
    ,   chLatin_o, chLatin_n, chEqual, chDoubleQuote, chDigit_1, chPeriod
    ,   chDigit_0, chDoubleQuote, chSpace, chLatin_e, chLatin_n, chLatin_c
    ,   chLatin_o, chLatin_d, chLatin_i, chLatin_n, chLatin_g, chEqual
    ,   chDoubleQuote, chNull
};

static const XMLCh  gXMLDecl2[] =
{
        chDoubleQuote, chQuestion, chCloseAngle
    ,   chLF, chNull
};




// ---------------------------------------------------------------------------
//  SAXPrintHandlers: Constructors and Destructor
// ---------------------------------------------------------------------------
SAXPrintHandlers::SAXPrintHandlers( const   char* const              encodingName
                                    , const XMLFormatter::UnRepFlags unRepFlags, RefUserModule *mod) :

    fFormatter
    (
        encodingName
        , 0
        , this
        , XMLFormatter::NoEscapes
        , unRepFlags
    )
{
    //
    //  Go ahead and output an XML Decl with our known encoding. This
    //  is not the best answer, but its the best we can do until we
    //  have SAX2 support.
    //
    fFormatter << gXMLDecl1 << fFormatter.getEncodingName() << gXMLDecl2;
    this->loader = new LoaderHeap(mod);
}

SAXPrintHandlers::~SAXPrintHandlers()
{
    //std::cout << _L("destructor");
}


// ---------------------------------------------------------------------------
//  SAXPrintHandlers: Overrides of the output formatter target interface
// ---------------------------------------------------------------------------
void SAXPrintHandlers::writeChars(const XMLByte* const /* toWrite */)
{
    std::cout << _L("SAXPrintHandlers::writeChars::. \n");
    return;
}

void SAXPrintHandlers::writeChars(const XMLByte* const toWrite,
                                  const XMLSize_t      count,
                                  XMLFormatter* const /* formatter */)
{
    // For this one, just dump them to the standard output
    // Surprisingly, Solaris was the only platform on which
    // required the char* cast to print out the string correctly.
    // Without the cast, it was printing the pointer value in hex.
    // Quite annoying, considering every other platform printed
    // the string with the explicit cast to char* below.
    XERCES_STD_QUALIFIER cout.write((char *) toWrite, (int) count);
	XERCES_STD_QUALIFIER cout.flush();
}


// ---------------------------------------------------------------------------
//  SAXPrintHandlers: Overrides of the SAX ErrorHandler interface
// ---------------------------------------------------------------------------
void SAXPrintHandlers::error(const SAXParseException& e)
{
    XERCES_STD_QUALIFIER cerr << "\nError at file " << StrX(e.getSystemId())
		 << ", line " << e.getLineNumber()
		 << ", char " << e.getColumnNumber()
         << "\n  Message: " << StrX(e.getMessage()) << XERCES_STD_QUALIFIER endl;
}

void SAXPrintHandlers::fatalError(const SAXParseException& e)
{
    XERCES_STD_QUALIFIER cerr << "\nFatal Error at file " << StrX(e.getSystemId())
		 << ", line " << e.getLineNumber()
		 << ", char " << e.getColumnNumber()
         << "\n  Message: " << StrX(e.getMessage()) << XERCES_STD_QUALIFIER endl;
}

void SAXPrintHandlers::warning(const SAXParseException& e)
{
    XERCES_STD_QUALIFIER cerr << "\nWarning at file " << StrX(e.getSystemId())
		 << ", line " << e.getLineNumber()
		 << ", char " << e.getColumnNumber()
         << "\n  Message: " << StrX(e.getMessage()) << XERCES_STD_QUALIFIER endl;
}


// ---------------------------------------------------------------------------
//  SAXPrintHandlers: Overrides of the SAX DTDHandler interface
// ---------------------------------------------------------------------------
void SAXPrintHandlers::unparsedEntityDecl(const     XMLCh* const /* name */
                                          , const   XMLCh* const /* publicId */
                                          , const   XMLCh* const /* systemId */
                                          , const   XMLCh* const /* notationName */)
{
    // Not used at this time
    std::cout << _L("SAXPrintHandlers::unparsedEntityDecl::. \n");
    return;
}


void SAXPrintHandlers::notationDecl(const   XMLCh* const /* name */
                                    , const XMLCh* const /* publicId */
                                    , const XMLCh* const /* systemId */)
{
    // Not used at this time
    std::cout << _L("SAXPrintHandlers::notationDecl::. \n");
    return;
}



void SAXPrintHandlers::ignorableWhitespace( const   XMLCh* const chars
                                            ,const  XMLSize_t    length)
{
    std::cout << _L("SAXPrintHandlers::ignorableWhitespace::. \n");
    fFormatter.formatBuf(chars, length, XMLFormatter::NoEscapes);
}


void SAXPrintHandlers::processingInstruction(const  XMLCh* const target
                                            , const XMLCh* const data)
{
    std::cout << _L("SAXPrintHandlers::processingInstruction::. \n");
    fFormatter << XMLFormatter::NoEscapes << gStartPI  << target;
    if (data)
        fFormatter << chSpace << data;
    fFormatter << XMLFormatter::NoEscapes << gEndPI;
}






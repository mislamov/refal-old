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
#include "kernel/datastructs.h"
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

    unistring theCommand = toWstring(name);
    //LOG( _L("SAXPrintHandlers::startElement::[") << theCommand << "] (attr: "<< attributes.getLength() << " )" );
    loader->activeTag.push(theCommand);

#ifdef DEBUG
try {
#endif
    loader->currentchars = _L("");  // ��������� ������ �����, ���������� ������� - ��������� � ���� SAX, �� ������ ���������� ����������� (��������������) � ���������� ��� ����� �����

    if ( theCommand.compare(_L("BEGIN")) == 0 ) {
    } else
    if ( theCommand.compare(_L("FUNCTION")) == 0) {
            if (! attributes.getLength() || !attributes.getValue("name")) SYSTEMERROR("FUNCTION WITHOUT name");
            loader->putValueToStack(theCommand, new RefUserFunction(toWstring(attributes.getValue("name"))));
    } else
    if ( theCommand.compare(_L("TEMPLATE")) == 0) {
            loader->templateOrSent = "T";
            //SYSTEMERROR("Templates are switched off! (testing)");
            if (! attributes.getLength() || !attributes.getValue("name")) SYSTEMERROR("TEMPLATE WITHOUT name");
            loader->putValueToStack(theCommand, new RefUserTemplate(toWstring(attributes.getValue("name"))));
    } else
    if ( theCommand.compare(_L("SENTENCE")) == 0) {
            loader->templateOrSent = "S";
            loader->putValueToStack(theCommand, new RefSentence());
    } else
    if ( theCommand.compare(_L("LEFT-PART")) == 0) {
            loader->createChainToStack();
            //���������� � endElement: loader->getCurrChain()->aroundByDots(); // ����� ����� - ������� - ������ ���� � ������, ���� ������������ � ����������� ������� �� ���� ������
    } else
    if ( theCommand.compare(_L("RIGHT-PART")) == 0) {
            loader->createChainToStack();
    } else
    if ( theCommand.compare(_L("EXEC")) == 0) {  //     <
            RefExecBracket *t = new RefExecBracket();
            loader->putValueToStack("BRACKET", t);
            *(loader->getCurrChain()) += t;
            *(loader->getCurrChain()) += new RefNULL();

            //std::cout << "\n\n" << loader->getCurrChain()->toString() << "\n\n";
    } else
    if ( theCommand.compare(_L("VAR")) == 0) {  //
        // ������ �� ������, ��� ��� ��� �������� ���� ������������� ���������� ���������� � ������� �������=���������� ����������
    } else
    if ( theCommand.compare(_L("LNK")) == 0) {  // ������ �� ����������
        // ������ �� ������, ��� ��� ��� �������� ���� ������������� ���������� ���������� � ������� ������=���������� ����������
    } else
    if ( theCommand.compare(_L("TEXT")) == 0) {  //
        // ������ �� ������, ��� ��� ��� �������� ���� ��� �������
    } else
    if ( theCommand.compare(_L("BRACKET")) == 0 ) {
            RefStructBracket *t = new RefStructBracket();
            loader->putValueToStack("BRACKET", t);
            *(loader->getCurrChain()) += t;
            *(loader->getCurrChain()) += new RefNULL();
    } else
    if ( theCommand.compare(_L("GROUP")) == 0) {
            if (! attributes.getLength() || !attributes.getValue("name")) SYSTEMERROR("GROUP WITHOUT name-attribute");
            RefGroupBracket *gbropen = new RefGroupBracket(toWstring(attributes.getValue("name")), 0);
            loader->putValueToStack( theCommand, dynamic_cast<RefObject *>(gbropen) );
            *(loader->getCurrChain()) += gbropen;
    } else
    if ( theCommand.compare(_L("VARIANTS")) == 0) {
            ref_variant_krest *krest = new ref_variant_krest();
            ref_variant_ffwd  *ffwd  = new ref_variant_ffwd();
            #ifdef DEBUG
            if (! dynamic_cast<RefGroupBracket *>(loader->getCurrChain()->second)) SYSTEMERROR("bad variant build");
            #endif
            krest->begbr = loader->getCurrChain()->second;
            loader->putValueToStack( "VARIANTS-krest", krest); //  ������� ����� � ����� �������
            loader->putValueToStack( "VARIANTS-vopr" , new ref_variant_vopr()); //  ������� ����� � ����� �������
            loader->putValueToStack( "VARIANTS-ffwd" , ffwd);  //  ������� ���� ffwd � ��������� �����������.
            ref_variant_dot *dot = new ref_variant_dot();
            dot->krest    = krest;
            dot->nextffwd = ffwd;
            *(loader->getCurrChain()) += dot;
    } else
    if ( theCommand.compare(_L("THE-VARIANT")) == 0) { //       | => x
            ref_variant_vert  *vert  = new ref_variant_vert();
            ref_variant_ffwd  *ffwd  = (ref_variant_ffwd *) loader->getValueFromStack( "VARIANTS-ffwd" );
            ref_variant_ffwd  *ffwdnext = new ref_variant_ffwd();
            loader->putValueToStack( "VARIANTS-ffwd" , ffwdnext); // ��� ���������� �����������
            ref_variant_dot   *dot   = new ref_variant_dot ();

            vert->vopr = (ref_variant_vopr *) loader->getValueFromStack("VARIANTS-vopr");
            dot->krest = (ref_variant_krest *)loader->getValueFromStack("VARIANTS-krest");
            dot->nextffwd = ffwdnext;

            *(loader->getCurrChain()) += vert;
            *(loader->getCurrChain()) += ffwd;
            *(loader->getCurrChain()) += dot ;
    } else
    if ( theCommand.compare(_L("CUTTER")) == 0 ) {
    } else
    if ( theCommand.compare(_L("NOT")) == 0) {
            *(loader->getCurrChain()) += (RefNot*) (loader->putValueToStack("NOT",
                                                                                    new RefNot()));
    } else
    if ( theCommand.compare(_L("IF")) == 0 ) {
            loader->currentCondition = new RefCondition();
    } else
    if ( theCommand.compare(_L("ERROR")) == 0 ) {
    } else
    /*****************   �������� � �������� ��� �������� ���������� ���������������� �����  *****************/
    if (tmp = loader->getNewEmptyRefSymbolByTypeName(theCommand)){ // �����-������
        loader->putValueToStack(theCommand, tmp);
    } else

    SYSTEMERROR("unknown tag name: " << theCommand);
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
    loader->currentchars += toWstring(chars, length);
    #ifdef DEBUG
    unistring ss = loader->currentchars;
    //LOG( "SAXPrintHandlers::characters:: " << ss.c_str() << "\n");
    #endif
    //fFormatter.formatBuf(chars, length, XMLFormatter::CharEscapes);
}


void SAXPrintHandlers::endDocument()
{
    //std::cout << _L("SAXPrintHandlers::endDocument::. \n");
}

// �� str �������� ������ �������� ���� ����������
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
    //LOG( _L("SAXPrintHandlers::endElement:: [") << toWstring(name) << "]" );
    RefObject *tmpobj = 0;
    RefValuedData *tmpvdata = 0;
    unistring theCommand = toWstring(name);

    #ifdef DEBUG
    try {
    #endif
    if (! theCommand.compare(_L("ERROR"))) {
        SYSTEMERROR(loader->currentchars);
    } else
    if (! theCommand.compare(_L("BEGIN"))) {
        // ������ �������� ���������
    } else
    if ( theCommand.compare(_L("FUNCTION")) == 0) {
            #ifdef DEBUG
            if (! dynamic_cast<RefUserFunction *>(loader->getValueFromStack("FUNCTION"))) SYSTEMERROR("not RefUserFunction in FUNCTION-stack !!!");
            #endif
            RefUserFunction *f =  (RefUserFunction*)loader->extractValueFromStack("FUNCTION");
            loader->currentModule->objects[f->getName()] = f;
    } else
    if ( theCommand.compare(_L("TEMPLATE")) == 0) {
            #ifdef DEBUG
            if (! dynamic_cast<RefUserTemplate *>(loader->getValueFromStack("TEMPLATE"))) SYSTEMERROR("not TEMPLATE in TEMPLATE-stack !!!");
            #endif
            RefUserTemplate *t =  dynamic_cast<RefUserTemplate*>( loader->extractValueFromStack("TEMPLATE") );
            //std::cout << "\n\nlp: " << loader->getCurrChain()->toString() << "\n\n" << std::flush;
            loader->getCurrChain()->dearoundByDots(); // ������� ���� �� �����
            t->setLeftPart( loader->extractCurrChainFromStack() );
            loader->currentModule->objects[ t->getName() ] = t;
    } else
    if ( theCommand.compare(_L("SENTENCE")) == 0) {
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
    if ( theCommand.compare(_L("LEFT-PART")) == 0) {
            loader->getCurrChain()->aroundByDots(); // ����� ����� - ������� - ������ ���� � ������, ���� ������������ � ����������� ������� �� ���� ������

        /*
            #ifdef DEBUG
            if (! dynamic_cast<RefSentence *>(loader->getValueFromStack("SENTENCE"))) SYSTEMERROR("not SENTENCE in SENTENCE-stack !!!");
            #endif
            RefSentence  *s =  (RefSentence*)loader->getValueFromStack("SENTENCE");
            s->leftPart = loader->extractCurrChainFromStack();
        */
    } else
    if ( theCommand.compare(_L("RIGHT-PART")) == 0) {
        /*
            #ifdef DEBUG
            if (! dynamic_cast<RefSentence *>(loader->getValueFromStack("SENTENCE"))) SYSTEMERROR("not SENTENCE in SENTENCE-stack !!!");
            #endif
            RefSentence  *s =  (RefSentence*)loader->getValueFromStack("SENTENCE");
            s->rightPart = loader->extractCurrChainFromStack();
        */
    } else
    if ( theCommand.compare(_L("EXEC")) == 0) {  //     <
            //std::cout << "EndElement:" << theCommand;
            //std::cout << " stack["<<"BRACKET"<<"]:" << loader->getValueFromStack("BRACKET")->toString();

            RefExecBracket *br = dynamic_cast<RefExecBracket *>(loader->extractValueFromStack("BRACKET"));
            #ifdef DEBUG
            if (! br) SYSTEMERROR("not EXEC BRACKET in BRACKET-stack !!!");
            #endif
            RefExecBracket *brclose = new RefExecBracket(br, 0);
            *(loader->getCurrChain()) += brclose;
    } else
    if ( theCommand.compare(_L("VAR")) == 0) {  //
        // ����� �� �������� ������ � �������� ������ �� ����������
        unistring vardescr = loader->currentchars;
        unistring vname = getVarName(vardescr); // ������ vname - ��� vardescr - ���
        *(loader->getCurrChain()) += loader->getVariableByTypename(vardescr, vname);
        //std::cout << loader->getCurrChain()->second->toString();
    } else
    if ( theCommand.compare(_L("LNK")) == 0) {  //
        // ����� �� �������� ������ � �������� ������ �� ����������
        // ������ �� ����� ������� �� ����������?
        int i;
        if ((i = loader->currentchars.find( varPathSeparator ))!=unistring::npos){
            // ������ �� ����� ������� ����������
            unistring name = loader->currentchars.substr(0, i);
            unistring path = loader->currentchars.substr(i+1);
            *(loader->getCurrChain()) += new RefLinkToPartOfVariable(name, path);
        } else {
            // ������ �� ����� ����������
            *(loader->getCurrChain()) += new RefLinkToVariable(loader->currentchars);
            //std::cout << loader->getCurrChain()->second->toString();
        }
    } else
    if ( theCommand.compare(_L("TEXT")) == 0) {  //
        unistring text = loader->currentchars;
        for (int i=0; i<text.length(); i++){
            *(loader->getCurrChain()) += new RefAlpha(text[i], 0);
        }
    } else
    if ( theCommand.compare(_L("BRACKET")) == 0 ) {
            RefStructBracket *br = dynamic_cast<RefStructBracket *>(loader->extractValueFromStack("BRACKET"));
            #ifdef DEBUG
            if (! br) SYSTEMERROR("not STRUCT BRACKET in BRACKET-stack !!!");
            #endif
            RefStructBracket *brclose = new RefStructBracket(br, 0);
            *(loader->getCurrChain()) += brclose;
    } else
    if ( theCommand.compare(_L("GROUP")) == 0) {
            #ifdef DEBUG
            if (! dynamic_cast<RefGroupBracket *>(loader->getValueFromStack(theCommand))) SYSTEMERROR("not RefGroupBracket in GROUP-stack !!!");
            #endif
            RefGroupBracket *gbrclose =  dynamic_cast<RefGroupBracket*>( loader->extractValueFromStack(theCommand) );
            *(loader->getCurrChain()) += new RefGroupBracket(gbrclose, 0);
    } else
    if ( theCommand.compare(_L("VARIANTS")) == 0) {  //   | => x ?
            ref_variant_krest *krest = (ref_variant_krest *)loader->extractValueFromStack("VARIANTS-krest");
            ref_variant_vopr  *vopr  = (ref_variant_vopr *) loader->extractValueFromStack("VARIANTS-vopr" );
            ref_variant_ffwd  *ffwd  = (ref_variant_ffwd *) loader->extractValueFromStack("VARIANTS-ffwd" );
            ref_variant_vert  *vert  = (ref_variant_vert *) new ref_variant_vert();
            vert->vopr = vopr;

            *(loader->getCurrChain()) += vert;
            *(loader->getCurrChain()) += ffwd;
            *(loader->getCurrChain()) += krest;
            *(loader->getCurrChain()) += vopr;
    } else
    if ( theCommand.compare(_L("THE-VARIANT")) == 0 ) {
    } else
    if ( theCommand.compare(_L("CUTTER")) == 0 ) {
            *(loader->getCurrChain()) += new RefMatchingCutter();
    } else
    if ( theCommand.compare(_L("NOT")) == 0) {
        #ifdef DEBUG
        if (! dynamic_cast<RefNot *>(loader->getValueFromStack("NOT")) ) SYSTEMERROR("alarm!");
        #endif
        *(loader->getCurrChain()) += new RefNot((RefNot *)(loader->extractValueFromStack("NOT")));
    } else
    if ( theCommand.compare(_L("IF")) == 0 ) {
            RefCondition* cond = loader->currentCondition;
            cond->setLeftPart (loader->extractCurrChainFromStack());
            cond->setRightPart(loader->extractCurrChainFromStack());
            if (loader->templateOrSent == "S"){ // if for sentense
                cond->own = (RefUserFunction *) loader->getValueFromStack("FUNCTION");
            } else {   // if for template
                cond->own = dynamic_cast<RefUserTemplate *>(loader->getValueFromStack("TEMPLATE"));
            }
            *(loader->getCurrChain()) += cond;
    } else
    if ( theCommand.compare(_L("ERROR")) == 0 ) {
        std::cout << "\n##########################################################################################";
        std::cout << "\n####:ERROR: \t" << loader->currentchars;
        std::cout << "\n##########################################################################################\n";
    } else
    /*****************   �������� � �������� ��� �������� ���������� ���������������� �����  *****************/
    //if (tmp = getNewEmptyRefSymbolByTypeName(theCommand)){ // �����-������
    //    loader->putValueToStack(theCommand, tmp);
    //} else
    if (tmpvdata = dynamic_cast<RefValuedData *> (loader->extractValueFromStack(theCommand))){
        tmpvdata->setValueFromString(loader->currentchars);
        *(loader->getCurrChain()) += tmpvdata;
    } else

    SYSTEMERROR("unknown tag name: " << theCommand);
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
    LOG( _L("SAXPrintHandlers::writeChars::. \n") );
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
    LOG( _L("SAXPrintHandlers::unparsedEntityDecl::. \n") );
    return;
}


void SAXPrintHandlers::notationDecl(const   XMLCh* const /* name */
                                    , const XMLCh* const /* publicId */
                                    , const XMLCh* const /* systemId */)
{
    // Not used at this time
    LOG( _L("SAXPrintHandlers::notationDecl::. \n") );
    return;
}



void SAXPrintHandlers::ignorableWhitespace( const   XMLCh* const chars
                                            ,const  XMLSize_t    length)
{
    LOG( _L("SAXPrintHandlers::ignorableWhitespace::. \n") );
    fFormatter.formatBuf(chars, length, XMLFormatter::NoEscapes);
}


void SAXPrintHandlers::processingInstruction(const  XMLCh* const target
                                            , const XMLCh* const data)
{
    LOG( _L("SAXPrintHandlers::processingInstruction::. \n") );
    fFormatter << XMLFormatter::NoEscapes << gStartPI  << target;
    if (data)
        fFormatter << chSpace << data;
    fFormatter << XMLFormatter::NoEscapes << gEndPI;
}







// ���������� ����������
RefVariable* LoaderHeap::getVariableByTypename(unistring nametype, unistring vn){
    // ����� ����� ���������� ����� ����������
    RefVariable* result = createVariableByTypename(nametype, vn);
    if (result) {
        return result;
    }

    // ������� ���������������� ����������
    RefUserVarNotInit *v = new RefUserVarNotInit();
    v->setName(vn);
    v->setType(nametype);
    currentModule->initItems.push(v);
    return v;
};


// ���������� �����-������
RefData* LoaderHeap::getNewEmptyRefSymbolByTypeName(unistring nametype){
    // ����� ����� ���������� ����� ��������
    RefData* result = createNewEmptyRefSymbolByTypeName(nametype);
    if (result) {
        return result;
    }

    SYSTEMERROR("Unknown Refal-symbol: " << nametype );
    //return new RefUserVar(nametype);
}


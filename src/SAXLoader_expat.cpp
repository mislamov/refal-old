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

#include "SAXLoader_expat.h"
#include "SAXLoaderHeap.h"

unistring toWstring(const char *str, unsigned int len) {
    unistring result(str, len);
    return result;
}
unistring toWstring(const char *str) {
    return str ? unistring(str) : 0;
}
infint str2infint(unistring si) { // строку в число
    return atol(si.c_str());
};

/*
void XMLCALL  start(void *data, const char *el, const char **attr) {
    LoaderHeap *loader = (LoaderHeap *)data;
    int i;
    printf("%s", el);
    for (i = 0; attr[i]; i += 2) {
        printf(" %s='%s'", attr[i], attr[i + 1]);
    }
    printf("\n");
}*/

const char* attributes_value(const char **attr, char* name) {
    for (int i = 0; attr[i]; i += 2) {
        if (strcmp(name, attr[i])==0) {
            return attr[i + 1];
        }
    }
    return 0;
}

// от str остается только описание типа переменной
unistring getVarName(unistring &str) {
    unistring tip = _L("");
    unistring name = _L("");
    int i=str.length()-1;
    for (; (i>0)&&str[i]!='.'; i--) {
        name = str[i] + name;
    }
    if (!i) SYSTEMERRORn("No dot in VARiable discription!");
    for (i-=1; (i>=0); i--) {
        tip = str[i]+tip;
    }
    str = tip;
    #ifdef DEBUG
    //std::cout << "[VAR::name:"<<name<<":type:"<<tip<<"]";
    #endif
    return name;
}

void charData (void *data, const XML_Char *chars, int length) {
    LoaderHeap *loader = (LoaderHeap *)data;
    ref_assert(loader!=0);
    loader->currentchars += toWstring(chars, length);
}

void XMLCALL startElement(void *data, const char *name, const char **attributes) {
    LoaderHeap *loader = (LoaderHeap *)data;
    ref_assert(loader!=0);

    unistring theCommand = toWstring(name);
    loader->activeTag.push(theCommand);

    loader->currentchars = _L("");  // поскольку чтение строк, содержащих перенос - разделено в этом SAX, то строки набираются накоплением (конкатенациями) и обнуляются для новых тегов

    if ( theCommand.compare(_L("BEGIN")) == 0 ) {
    } else
        if ( theCommand.compare(_L("FUNCTION")) == 0) {
            if (! attributes_value(attributes, "name")) SYSTEMERRORn("FUNCTION WITHOUT name");
            loader->putValueToStack(theCommand, new RefUserFunction(toWstring(attributes_value(attributes, "name"))));
        } else
            if ( theCommand.compare(_L("TEMPLATE")) == 0) {
                loader->templateOrSent = "T";
                //SYSTEMERRORn("Templates are switched off! (testing)");
                if (! attributes_value(attributes, "name")) SYSTEMERRORn("TEMPLATE WITHOUT name");
                loader->putValueToStack(theCommand, new RefUserTemplate(toWstring(attributes_value(attributes, "name"))));
            } else
                if ( theCommand.compare(_L("SENTENCE")) == 0) {
                    loader->templateOrSent = "S";
                    loader->putValueToStack(theCommand, new RefSentence());
                } else
                    if ( theCommand.compare(_L("LEFT-PART")) == 0) {
                        loader->createPatternToStack();
                    } else
                        if ( theCommand.compare(_L("RIGHT-PART")) == 0) {
                            loader->createSubstitutionToStack();
                        } else
                            if ( theCommand.compare(_L("EXEC")) == 0) {  //     <
                                loader->createChainToStack();
                            } else
                                if ( theCommand.compare(_L("VAR")) == 0) {  //
                                    // ничего не делаем, так как при закрытии тега воспользуемся менеджером переменных и текущим текстом=описателем переменной
                                } else
                                    if ( theCommand.compare(_L("LNK")) == 0) {  // ссылка на переменную
                                        // ничего не делаем, так как при закрытии тега воспользуемся менеджером переменных и текущим тексом=описателем переменной
                                    } else
                                        if ( theCommand.compare(_L("TEXT")) == 0) {  //
                                            // ничего не делаем, так как при закрытии тега все сделаем
                                        } else
                                            if ( theCommand.compare(_L("BRACKET")) == 0 ) {
                                                loader->createChainToStack();
                                            } else
                                                if ( theCommand.compare(_L("GROUP")) == 0) {
                                                    if (! attributes_value(attributes, "name")) SYSTEMERRORn("GROUP WITHOUT name-attribute");
                                                    *(loader->getCurrChain()) += (new RefVarChains("", toWstring(attributes_value(attributes, "name"))));
                                                    loader->createChainToStack();
                                                } else
                                                    if ( theCommand.compare(_L("VARIANTS")) == 0) {
                                                        if (! attributes_value(attributes, "name")) {
                                                            theCommand = EmptyUniString;
                                                        } else {
                                                            theCommand = toWstring(attributes_value(attributes, "name"));
                                                        }
                                                        *(loader->getCurrChain()) += (new RefVariantsChains(theCommand));
                                                        loader->createChainToStack();
                                                    } else
                                                        if ( theCommand.compare(_L("THE-VARIANT")) == 0) { //       | => x
                                                            RefChain* varch = loader->extractCurrChainFromStack();
                                                            RefVariantsChains *uv = reinterpret_cast<RefVariantsChains*>(* loader->getCurrChain()->at_last());
                                                            #ifdef TESTCODE
                                                            if (! varch) AchtungERRORn;
                                                            if (! dynamic_cast<RefVariantsChains *>(uv)) AchtungERRORn;
                                                            #endif
                                                            uv->addTempl(varch);
                                                            loader->createChainToStack();
                                                        } else
                                                            if ( theCommand.compare(_L("REPEAT")) == 0 ) {
                                                                infint min = str2infint(toWstring(attributes_value(attributes, "from")));
                                                                infint max = str2infint(toWstring(attributes_value(attributes, "to")));

                                                                RefRepeaterChain *repeater = new RefRepeaterChain(min, max);
                                                                loader->putValueToStack( "REPEAT" , repeater);
                                                                loader->createPatternToStack();
                                                            } else
                                                                if ( theCommand.compare(_L("CUTTER")) == 0 ) {
                                                                } else
                                                                    if ( theCommand.compare(_L("IF")) == 0 ) {
                                                                        bool isnot = (attributes[0] && toWstring(attributes_value(attributes, "not"))=="true");
                                                                        loader->currentCondition = new RefUserCondition(isnot);
                                                                    } else
                                                                        if ( theCommand.compare(_L("ERROR")) == 0 ) {
                                                                        }
}


void XMLCALL  endElement(void *data, const char *name) {
    LoaderHeap *loader = (LoaderHeap *)data;
    ref_assert(loader!=0);

    //RefObject *tmpobj = 0;
    unistring theCommand = toWstring(name);
    RefData* tmpvdata = 0;

    #ifdef TESTCODE
    try {
        #endif
        if (! theCommand.compare(_L("ERROR"))) {
            SYSTEMERRORn(loader->currentchars);
        } else
            if (! theCommand.compare(_L("BEGIN"))) {
                // модуль прочитан полностью
                loader->currentModule->initilizeAll(loader->currentProgram);
            } else
                if ( theCommand.compare(_L("FUNCTION")) == 0) {
                    #ifdef TESTCODE
                    if (! dynamic_cast<RefUserFunction *>(loader->getValueFromStack("FUNCTION"))) SYSTEMERRORn("not RefUserFunction in FUNCTION-stack !!!");
                    #endif
                    RefUserFunction *f =  (RefUserFunction*)loader->extractValueFromStack("FUNCTION");
                    loader->currentModule->setFunctionByName(f->getName(), f);
                } else
                    if ( theCommand.compare(_L("TEMPLATE")) == 0) {
                        #ifdef TESTCODE
                        if (! dynamic_cast<RefUserTemplate *>(loader->getValueFromStack("TEMPLATE"))) SYSTEMERRORn("not TEMPLATE in TEMPLATE-stack !!!");
                        #endif
                        //RefUserTemplate *t =  dynamic_cast<RefUserTemplate*>( loader->extractValueFromStack("TEMPLATE") );
                        RefUserTemplate *t =  (RefUserTemplate*)( loader->extractValueFromStack("TEMPLATE") );
                        //std::cout << "\n\nlp: " << loader->getCurrChain()->toString() << "\n\n" << std::flush;
                        //loader->getCurrChain()->dearoundByDots(); // шаблону доты не нужны
                        t->setLeftPart( loader->extractCurrChainFromStack() );
                        loader->currentModule->setTemplateByName( t->getName(), t);
                    } else
                        if ( theCommand.compare(_L("SENTENCE")) == 0) {
                            #ifdef TESTCODE
                            if (! dynamic_cast<RefSentence *>(loader->getValueFromStack("SENTENCE"))) SYSTEMERRORn("not SENTENCE in SENTENCE-stack !!!");
                            if (! dynamic_cast<RefUserFunction *>(loader->getValueFromStack("FUNCTION"))) SYSTEMERRORn("not FUNCTION in FUNCTION-stack !!!");
                            #endif
                            RefSentence     *s =  (RefSentence*)loader->extractValueFromStack("SENTENCE");
                            RefChain *rch = loader->extractCurrChainFromStack();
                            #ifdef TESTCODE
                            //if (! dynamic_cast<RefChainConstructor*>(rch)) SYSTEMERRORn("alarm xml construct");
                            if (! dynamic_cast<RefChain*>(rch)) SYSTEMERRORn("alarm xml construct");
                            #endif
                            //s->rightPart = (RefChainConstructor*)rch;
                            s->rightPart = (RefChain*)rch;
                            s->leftPart  = loader->extractCurrChainFromStack();
                            RefUserFunction *f =  (RefUserFunction*)loader->getValueFromStack("FUNCTION");
                            (f->body).push_back(s);
                        } else
                            if ( theCommand.compare(_L("LEFT-PART")) == 0) {
                                //loader->getCurrChain()->aroundByDots(); // левые части - шаблоны - должны быть с дотами, чтоб сопоставлять в паралельных потоках не меня шаблон

                                /*
                                    #ifdef TESTCODE
                                    if (! dynamic_cast<RefSentence *>(loader->getValueFromStack("SENTENCE"))) SYSTEMERRORn("not SENTENCE in SENTENCE-stack !!!");
                                    #endif
                                    RefSentence  *s =  (RefSentence*)loader->getValueFromStack("SENTENCE");
                                    s->leftPart = loader->extractCurrChainFromStack();
                                */
                                #ifdef TESTCODE
                                if (! dynamic_cast<RefChain*>(loader->getCurrChain()))  SYSTEMERRORn("alarm");
                                #endif
                                //std::cout << "\n\n\n" << loader->getCurrChain()->toString() << "\n\n\n";
                            } else
                                if ( theCommand.compare(_L("RIGHT-PART")) == 0) {
                                    /*
                                        #ifdef TESTCODE
                                        if (! dynamic_cast<RefSentence *>(loader->getValueFromStack("SENTENCE"))) SYSTEMERRORn("not SENTENCE in SENTENCE-stack !!!");
                                        #endif
                                        RefSentence  *s =  (RefSentence*)loader->getValueFromStack("SENTENCE");
                                        s->rightPart = loader->extractCurrChainFromStack();
                                    */
                                } else
                                    if ( theCommand.compare(_L("EXEC")) == 0) {  //     <

                                        RefChain* tmp = loader->extractCurrChainFromStack();
                                        *(loader->getCurrChain()) += new RefExecBrackets(0, tmp);
                                    } else
                                        if ( theCommand.compare(_L("VAR")) == 0) {  //
                                            // берем по текущему тексту и получаем ссылку на переменную
                                            unistring vardescr = loader->currentchars;
                                            unistring vname = getVarName(vardescr); // теперь vname - имя vardescr - тип
                                            *(loader->getCurrChain()) += loader->getVariableByTypename(vardescr, vname);
                                            //std::cout << loader->getCurrChain()->second->toString();
                                        } else
                                            if ( theCommand.compare(_L("LNK")) == 0) {  //
                                                // берем по текущему тексту и получаем ссылку на переменную
                                                *(loader->getCurrChain()) += new RefLinkToVariable(loader->currentchars);
                                                //std::cout << loader->getCurrChain()->second->toString();
                                            } else
                                                if ( theCommand.compare(_L("TEXT")) == 0) {  //
                                                    unistring text = loader->currentchars;
                                                    for (size_t i=0; i<text.length(); i++) {
                                                        *(loader->getCurrChain()) += new RefAlpha(0, text[i]);
                                                    }
                                                } else
                                                    if ( theCommand.compare(_L("BRACKET")) == 0 ) {
                                                        RefChain* tmp = loader->extractCurrChainFromStack();
                                                        *(loader->getCurrChain()) += new RefStructBrackets(0, tmp);
                                                    } else
                                                        if ( theCommand.compare(_L("GROUP")) == 0) {
                                                            RefChain* tmp = loader->extractCurrChainFromStack();
                                                            RefVarChains **uv = reinterpret_cast<RefVarChains**>(loader->getCurrChain()->at_last());
                                                            #ifdef TESTCODE
                                                            if (! tmp) AchtungERRORn;
                                                            if (! dynamic_cast<RefVarChains *>(*uv)) AchtungERRORn;
                                                            #endif
                                                            (*uv)->setTempl(tmp);
                                                        } else
                                                            if ( theCommand.compare(_L("VARIANTS")) == 0) {  //   | => x ?
                                                                RefChain* varch = loader->extractCurrChainFromStack();
                                                                RefVariantsChains *uv = reinterpret_cast<RefVariantsChains*>(* loader->getCurrChain()->at_last());
                                                                #ifdef TESTCODE
                                                                if (! varch) AchtungERRORn;
                                                                if (! dynamic_cast<RefVariantsChains *>(uv)) AchtungERRORn;
                                                                #endif
                                                                uv->addTempl(varch);
                                                            } else
                                                                if ( theCommand.compare(_L("THE-VARIANT")) == 0 ) {
                                                                } else
                                                                    if ( theCommand.compare(_L("REPEAT")) == 0 ) {
                                                                        RefRepeaterChain *repeater = (RefRepeaterChain *)loader->extractValueFromStack( "REPEAT" );
                                                                        repeater->setTempl(loader->extractCurrChainFromStack());
                                                                        *(loader->getCurrChain()) += repeater;
                                                                    } else
                                                                        if ( theCommand.compare(_L("CUTTER")) == 0 ) {
                                                                            //SYSTEMERRORn("cutter not realised!");
                                                                            *(loader->getCurrChain()) += new RefMatchingCutter();
                                                                        } else
                                                                            if ( theCommand.compare(_L("IF")) == 0 ) {
                                                                                RefUserCondition* cond = loader->currentCondition;
                                                                                cond->setLeftPart (loader->extractCurrChainFromStack());
                                                                                cond->setRightPart(loader->extractCurrChainFromStack());
                                                                                if (loader->templateOrSent == "S") { // if for sentense
                                                                                    cond->own = (RefUserFunction *) loader->getValueFromStack("FUNCTION");
                                                                                } else {   // if for template
                                                                                    //cond->own = dynamic_cast<RefUserTemplate *>(loader->getValueFromStack("TEMPLATE"));
                                                                                    cond->own = (RefUserTemplate *)(loader->getValueFromStack("TEMPLATE"));
                                                                                }
                                                                                *(loader->getCurrChain()) += cond;
                                                                            } else
                                                                                if ( theCommand.compare(_L("ERROR")) == 0 ) {
                                                                                    std::cout << "\n##########################################################################################";
                                                                                    std::cout << "\n####:ERROR: \t" << loader->currentchars;
                                                                                    std::cout << "\n##########################################################################################\n";
                                                                                    SYSTEMERRORn("ABORT");
                                                                                } else
                                                                                    if (tmpvdata = loader->currentProgram->createSymbolByCode(theCommand, loader->currentchars)) {
                                                                                        *(loader->getCurrChain()) += tmpvdata;
                                                                                    } else
                                                                                        SYSTEMERRORn("unknown tag name: " << theCommand);
        #ifdef TESTCODE
    } catch (int i) {
        SYSTEMERRORn("excepion!");
    }
    #endif


    loader->activeTag.pop();
    // No escapes are legal here
    //fFormatter << XMLFormatter::NoEscapes << gEndElement << name << chCloseAngle;
}





int loadModuleFromXmlFile(RefUserModule *mod, RefProgram *prog, char* xmlFile) {
    XML_Parser p = XML_ParserCreate(NULL);
    if (! p) {
        fprintf(stderr, "Couldn't allocate memory for parser\n");
        return 1;
    }

    LoaderHeap *loaderHeap = new LoaderHeap(mod, prog);;
    XML_SetUserData(p, loaderHeap);
    XML_SetElementHandler(p, startElement, endElement);
    XML_SetCharacterDataHandler(p, charData );

    FILE *ifile = fopen(xmlFile, "r");
    if (ifile == NULL) {
        fprintf(stderr, "Can't open input file %s\n", xmlFile);
        return -1;
    }


    for (;;) {
        int done;
        int len;

        len = (int)fread(Buff, 1, BUFFSIZE, ifile);
        if (ferror(ifile)) {
            fprintf(stderr, "Read error\n");
            return 2;
        }
        done = feof(ifile);

        if (XML_Parse(p, Buff, len, done) == XML_STATUS_ERROR) {
            fprintf(stderr, "Parse error at line %" XML_FMT_INT_MOD "u:\n%s\n",
                    XML_GetCurrentLineNumber(p),
                    XML_ErrorString(XML_GetErrorCode(p)));
            return 3;
        }

        if (done)
            break;
    }
    XML_ParserFree(p);
    return 0;


};

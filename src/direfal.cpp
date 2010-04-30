#include "direfal.h"
#include "SAXLoader_expat.h"



std::streambuf *stdbbuf = std::cout.rdbuf();
std::streambuf *nullbuf = 0;
std::ostream   *debugstream = 0;
bool verbose = false;


RefalProgram::RefalProgram(PROGRAMTYPE type, int argc, char **argv) {
    success = false;
    program = new RefProgram(argc, argv);
    if (!this->loadModule(XML, "direfal_scaner.xml", "meta")){
        RUNTIMEERRORn("Can't load program direfal_scaner.xml" );
        return;
    }
}


bool RefalProgram::loadModule(PROGRAMTYPE type, unistring file, unistring name){
    unistring result = file;
    if (type==REF) {
        RefFunction *REFALCOMPILE = this->getFunction("REFALCOMPILE"); // получаем функцию  рефал-кода
        REFALCOMPILE->execute(file, result); // применяем функцию к  пользователя. Итог - xml код  программы
        //std::cout << result.c_str() << " " << result.length();
        // теперь в result результат синт- и семант-ического анализа и оптимизации prog.
        type = XMLCODE;
    }

    if (type==XML) {
        RefUserModule *ref = new RefUserModule(name);
        program->regModule(ref);
        int err = loadModuleFromXmlFile (ref, program, result.c_str(), false);
        if (err) return false;
        success = true;
    }

    if (type==XMLCODE) {
        RefUserModule *ref = new RefUserModule(name);
        program->regModule(ref);
        //std::cout << result.c_str() << " " << result.length();
        int err = loadModuleFromXmlCode (ref, program, result.c_str(), result.length(), false);
        if (err) return false;
        success = true;
    }
    return true;
};



RefFunction *RefalProgram::getFunction(unistring fname) {
    if (this->program->findFunction(fname) == 0) return 0;
    return new RefFunction(this->program, fname);
};


void RefFunction::execute(RefChain *arg, unistring &result, Session *sess) {
    if (!sess) sess = new Session(program);
    RefChain *tmp = new RefChain(sess, arg?1+arg->getLength():1);
    (*tmp) += new RefWord(sess, function);
    if (arg) {
        (*tmp) += arg;
    };

    RefChain *chain = new RefChain(sess, new RefExecBrackets(sess, tmp));
    chain = program->executeExpression(chain, sess);

    if (chain) {
        result = chain->explode();
        success = true;
    }
    sess->gc_clean();
    delete sess;
};

void RefFunction::execute(unistring arg,  unistring& result) {
    Session *sess = new Session(program);
    execute(text_to_chain(sess, arg.c_str()), result);
};



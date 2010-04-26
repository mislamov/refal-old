#include "direfal.h"
#include "SAXLoader_expat.h"



RefalProgram::RefalProgram(PROGRAMTYPE type, unistring str_arg,  int argc, char **argv) {
    success = false;
    program = new RefProgram(argc, argv);

    if (type==REF){
        //__verbose_off();
        RefalProgram refalcompiller(XML, "direfal_scaner.xml",  argc, argv); // загружаем программу загрузчика
        if (! refalcompiller.isSuccess()) {
            RUNTIMEERRORn("Can't load program direfal_scaner.xml" );
        }
        RefFunction *REFALCOMPILE = refalcompiller.getFunction("REFALCOMPILE"); // получаем функцию  рефал-кода
        unistring result;
        REFALCOMPILE->execute(str_arg, result); // применяем функцию к  пользователя. Итог - xml код  программы
        // теперь в str_arg результат синт- и семант-ического анализа и оптимизации prog.
        type = XMLCODE;
        str_arg = result;

        //__verbose_on();
        //std::cout << str_arg.c_str() << " " << str_arg.length();
    }

    if (type==XML){
        RefUserModule *ref = new RefUserModule(str_arg);
        program->regModule(ref);
        int err = loadModuleFromXmlFile (ref, program, str_arg.c_str());
        if (err) return;
        success = true;
    }

    if (type==XMLCODE){
        RefUserModule *ref = new RefUserModule(str_arg);
        program->regModule(ref);
        //std::cout << str_arg.c_str() << " " << str_arg.length();
        int err = loadModuleFromXmlCode (ref, program, str_arg.c_str(), str_arg.length());
        if (err) return;
        success = true;
    }

}


RefFunction *RefalProgram::getFunction(unistring fname){
    if (this->program->findFunction(fname) == 0) return 0;
    return new RefFunction(this->program, fname);
};


void RefFunction::execute(RefChain *arg, unistring &result, Session *sess){
    if (!sess) sess = new Session(program);
    RefChain *tmp = new RefChain(sess, arg?1+arg->getLength():1);
    (*tmp) += new RefWord(sess, function);
    if (arg) { (*tmp) += arg; };

    RefChain *chain = new RefChain(sess, new RefExecBrackets(sess, tmp));
    chain = program->executeExpression(chain, sess);

    if (chain) {
        result = chain->explode();
        success = true;
    }
    sess->gc_clean();
    delete sess;
};

void RefFunction::execute(unistring arg,  unistring& result){
    Session *sess = new Session(program);
    execute(text_to_chain(sess, arg.c_str()), result);
};



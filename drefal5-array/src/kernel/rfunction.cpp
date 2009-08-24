#include "rfunction.h"

	RefUserModule::RefUserModule(RefProgram* p) : RefModuleBase() {
        p->regModule(this);
    };


#ifndef EVALUTOR_H_INCLUDED
#define EVALUTOR_H_INCLUDED

#include "data.h"

RefChain* evalutor(RefChain *, Session *);
        // сессия нужна для получения функций из модулей
        // argline должна быть с дотами


#endif // EVALUTOR_H_INCLUDED

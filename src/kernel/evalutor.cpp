// D-Refal - sentential program language
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

#include "evalutor.h"

#include "datastructs.h"
#include "refsymbolbase.hxx"
#include "rfunction.h"
#include "kernel.h"

// вычисляет цепочку до тех пор, пока в ней есть функциональные вызовы <>
// концами цепочки не могут быть датадоты
RefChain* evalutor(RefChain *argline, Session *s){
    long &dc = co::datacount;
        /*
        #ifdef DEBUG
        if (! dynamic_cast<RefData_DOT *>(argline->first) )
            SYSTEMERROR("evalutor( argline->first != RefDATA_DOT, ...) !\nevalutor( " << argline->toString() << " )");
        if (! dynamic_cast<RefData_DOT *>(argline->second) )
            SYSTEMERROR("evalutor(..., argline->second != RefDATA_DOT) !\nevalutor( " << argline->toString() << " )");
        #endif
        */
        /*
        if ( dynamic_cast<RefExecBracket *>(argline->first) )
            SYSTEMERROR("evalutor( argline->first is RefExecBracket ) !\nevalutor( " << argline->toString() << " )");
        if ( dynamic_cast<RefExecBracket *>(argline->second) )
            SYSTEMERROR("evalutor( argline->second is RefExecBracket ) !\nevalutor( " << argline->toString() << " )");
        */

///todo: следующая строка экспериментальная - когда игрался с уловиями (отключил откат если сопоствление не с концом аргумента)
if (! argline->first) return argline;

//std::cout << "\n#### EVALUTOR  " << ((argline->first->pred)?(argline->first->pred->toString()):"$null") << " <--\t\t" << argline->toString() << "\t\t--> " << ((argline->second->next)?(argline->second->next->toString()):"$null") << "\n";

        argline->aroundByDots(); // окружаем дотами чтоб не потерять концы при удалении угловых скобок

        // вычисление поля зрения
        RefExecBracket *exec    = 0;
        RefWordBase *fn         = 0;
        RefFunctionBase *funk   = 0;
        TVarBodyTable *vars     = 0;
        for (RefData *it=argline->first; it&&it!=argline->second->next; move_to_next_point(it, 0, s)){
            exec = dynamic_cast<RefExecBracket *>(it);
            if (exec && !exec->isOpen()){    // поиск >
                it = exec->getOther()->pred; // получение точки перед <  (может быть 0)

                // получение ссылки на функцию
                fn = dynamic_cast<RefWord *>(exec->getOther()->next->next);
                if (fn){
                    unistring fname = fn->getValue();
                    funk = s->findMethodFromModule( fname );
                    vars = 0;
                } else {
                    /// todo: вызов метода из пользовательской переменной
                    // вынос карты подпеременных переменной на передовую
                    SYSTEMERROR("Function name is not RefWord! : " << exec->getOther()->next->next->toString());
                }

                bool succes = funk; // результат поиска функции по имени

                if (fn->next == exec){ // выполнить с пустым аргументом  (  <fn >  )
                    succes = succes && funk->execute(0, fn, s);
                } else {
                    // выполнить с аргументом
                    succes = succes && funk->execute(fn->next, exec->pred, s);  //   <fn  fn_next..exec_pred>
                }
                if (!succes){
                        SYSTEMERROR("FUNCTION FAILD! : <" << (funk?funk->getName() : fn->getValue() ) << " " << RefChain(fn->next, exec->pred).toString() << ">\nView: " << argline->toString());
                }

//std::cout << "\n\n" << fn->getValue() << "  :  " << dc << "\n";

                delete exec->getOther()->next->next; // удаляем вызов - остается только результат вызова
                delete exec->getOther()->next;
                delete exec->getOther();
                delete exec;

//                std::cout << "\n#### VIEWPOLE :: " << argline->toString()  << '\n' << std::flush;
            }
        }


        argline->dearoundByDots(); // удаляем доты, поставленные изначально
        //std::cout << "\n\n\n\n#### RETURN EVAL  " << ((argline->first && argline->first->pred)?(argline->first->pred->toString()):"$null") << " <--\t\t" << argline->toString() << "\t\t--> " << ((argline->second && argline->second->next)?(argline->second->next->toString()):"$null") << "\n\n\n\n";

        return argline;

};

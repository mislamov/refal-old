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

#include "session.h"

void SAVE_STATE   (RefData** activeTemplate) {};   // сохраняет состояние переменной
void SAVE_VARSTATE(RefData** activeTemplate) {}; // сохраняет состояние и значение переменной
void RESTORE_STATE(RefData** activeTemplate) {}; // восстанавливает состояние переменной

void Session::executeExpression(RefChain *&chain) {
    /// поиск скобки и выделение аргумента
    std::stack<RefData**> openExecs;
    RefData **l_exec, **r_exec = chain->first, **&chain_last = chain->first[chain->leng]; // эл-т после последнего
    RefExecBracket *tmpBr = 0;
    while (r_exec < chain_last) {
        if (tmpBr = ref_dynamic_cast<RefExecBracket>(*r_exec)) { // > или <
            if (! tmpBr->is_opened) { // > - нашли то, что искали
                l_exec = openExecs.top();
                openExecs.pop();
                break;
            }
            // <
            openExecs.push(r_exec);
        }
        ++r_exec;
    }
    if (r_exec == chain_last) { // нечего вычислять
        return;
    }


    // дано: l_exec и r_exec
    /// получение тела функции из репозитория
    #ifdef TESTCODE
    if (! dynamic_cast<RefWord*>(l_exec[1])) SYSTEMERROR("NOt func NAME: " << l_exec[1]->toString() );
    #endif
    RefFunctionBase* function = this->findFunctionById(  (ref_dynamic_cast<RefWord>(l_exec[1]))->getValue()  );
    if (!function) RUNTIMEERROR("FUNCTION by ID [" << l_exec[1]->toString() << "] NOT DEFINED!");
    RefChain *newchain = function->execute(l_exec[2], r_exec[-1]);





        /// user function->execute : перебор предложений
        /// запуск matching (точку восстановления наверное не тут создавать!)
        /// если успех - substituteExpression по правой части
        /// иначе следующее предлоджение
        /// если неуспех для всех предложений - аварийный останов


    /// поиск скобки <, вычисление длины и создание аргумента (видимо прямым копированием)
    /// если найдено, то goto ЫЫЫ:

    // удалить стартовый аргумент (если он бы создан полным копированием - то с содержимым)
    // вернуть результат + присвоить его аргументу
};

// готовит подстановку: заменяет переменные значениями. Получаем ОВ с угловыми скобками
// прямое копирование
void Session::substituteExpression(RefChain *&chain) {
    // итерация по элементам аргумента (RefChain блоковый)
    // если переменная, то добавляем копию ее значения
};

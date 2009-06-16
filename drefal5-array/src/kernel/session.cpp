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

void SAVE_STATE   (RefData** activeTemplate){};    // сохран€ет состо€ние переменной
void SAVE_VARSTATE(RefData** activeTemplate){}; // сохран€ет состо€ние и значение переменной
void RESTORE_STATE(RefData** activeTemplate){}; // восстанавливает состо€ние переменной


RefChain* Session::executeExpression(RefChain *&chain){
    // поиск скобки и выделение аргумента

    // џџџ:
    // получение тела функции из репозитори€
    // перебор предложений:
        // запуск matching (точку восстановлени€ наверное не тут создавать!)
        // если успех - substituteExpression по правой части
        // иначе следующее предлоджение
        // если неуспех дл€ всех предложений - аварийный останов
    // поиск скобки, вычисление длины и создание аргумента (видимо пр€мым копированием)
    // если найдено, то goto џџџ:

    // удалить стартовый аргумент (если он бы создан полным копированием - то с содержимым)
    // вернуть результат + присвоить его аргументу
};

// готовит подстановку: замен€ет переменные значени€ми. ѕолучаем ќ¬ с угловыми скобками
// пр€мое копирование
RefChain* Session::substituteExpression(RefChain *&chain){
    // итераци€ по элементам аргумента (RefChain блоковый)
    // если переменна€, то добавл€ем копию ее значени€
};

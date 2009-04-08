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
#include <fstream.h>

#include "system.h"
#include "../kernel/rfunction.h"
#include "../kernel/data.h"
#include "../kernel/kernel.h"
#include "../kernel/refsymbolbase.hxx"


RefChain* Dec (RefData* beg, RefData* end, Session* s){
    RefInteger *a = dynamic_cast<RefInteger *>(beg);
    RefInteger *b = dynamic_cast<RefInteger *>(end);
    if (beg->next != end){
        RUNTIMEERROR("Dec", "error arguments");
        return 0;
    };
    //std::cout << "\n\nDec: " << a->getValue() << "-" << b->getValue() ;
    a = new RefInteger(a->getValue() - b->getValue());
    //std::cout << " = " << a->getValue();
    return new RefChain(a, a);
};

RefChain* Div (RefData* beg, RefData* end, Session* s){
    RefInteger *a = dynamic_cast<RefInteger *>(beg);
    RefInteger *b = dynamic_cast<RefInteger *>(end);
    if (beg->next != end){
        RUNTIMEERROR("Div", "error arguments");
        return 0;
    };
    //std::cout << "\n\nDiv: " << a->getValue() << " / " << b->getValue() ;
    RefReal* c = new RefReal((float)a->getValue() / b->getValue());
    //std::cout << " = " << c->getValue();
    return new RefChain(c, c);
};


RefChain* Sum (RefData* beg, RefData* end, Session* s){
    infint thesum = 0;
    RefInteger *a;
    //std::cout << "\n\nSum: ";
    while(beg != end->next){
        a = dynamic_cast<RefInteger *>(beg);
        if (! a){
            RUNTIMEERROR("Sum", "error arguments");
            return 0;
        }
        thesum += a->getValue();
        //std::cout << a->getValue() << ", ";
        move_to_next_point(beg, 0, s);
    }

    //std::cout << a->getValue() << " = " << thesum ;
    a = new RefInteger(thesum);
    return new RefChain(a, a);
};


RefChain* Mul (RefData* beg, RefData* end, Session* s){
    infint thesum = 1;
    RefInteger *a;
    //std::cout << "\n\nMul: ";
    while(beg != end->next){
        a = dynamic_cast<RefInteger *>(beg);
        if (! a){
            RUNTIMEERROR("Mul", "error arguments");
            return 0;
        }
        thesum *= a->getValue();
        //std::cout << a->getValue() << " * ";
        move_to_next_point(beg, 0, s);
    }
    a = new RefInteger(thesum);
    //std::cout << " = " << thesum;
    return new RefChain(a, a);
};




RefChain* Lenw (RefData* beg, RefData* end, Session* s){
    infint thecount = 0;
    RefInteger *a;
    if (beg) while(beg != end->next){
        thecount++;
        move_to_next_point(beg, 0, s);
    }

    a = new RefInteger(thecount);
    return new RefChain(a, a);
};

RefChain* Numb (RefData* beg, RefData* end, Session* s){
    /// todo: сделать не только integer
    RefChain *result = new RefChain(beg, end);
    long l = strtol(result->toString().c_str(), NULL, 10);

    RefInteger *rint = new RefInteger(l);
    result->first = result->second = rint;
    return result;
};


RefChain*  DataCompare(RefData* beg, RefData* end, Session* s){
    RefData *a = 0;
    if (beg->next != end){
        RUNTIMEERROR("Compare", "Must be 2 arguments");
        return 0;
    }


    if (*beg > *end){
        a = new RefAlpha('+');
    } else if (*beg == *end){
        a = new RefAlpha('0');
    } else {
        a = new RefAlpha('-');
    }
    return new RefChain(a, a);
};


RefChain* Mount (RefData* beg, RefData* end, Session* s){

      int length;
      char * buffer;
      RefChain *result = new RefChain();

      std::ifstream is;
      is.open ( RefChain(beg, end).toString().c_str(), std::ios::binary );

      // get length of file:
      is.seekg (0, std::ios::end);
      length = is.tellg();
      is.seekg (0, std::ios::beg);

      // allocate memory:
      buffer = new char [length];

      // read data as a block:
      is.read (buffer,length);
      is.close();

        for (int i=0; i<length; i++){
            if (buffer[i] != '\r'){   /// todo: правильно обрабатывать
                (*result) += new RefAlpha(buffer[i]);
            }
        }

      delete[] buffer;

        return result;


}


RefChain* Card (RefData* beg, RefData* end, Session* s){
    if (beg) {
        RUNTIMEERROR("Card", "Not empty args in Card : " << vectorToString(beg, end));
        return 0;
    }
    unistring sline; /// todo LOCALE
    std::string text = "";
    //std::cin >>  text;
    std::getline(std::cin, text);

    RefChain *rch = new RefChain();

    //for (size_t i=0; i<text.length(); i++){
    for (size_t i=0; i<text.length(); i++){
        *rch += new RefAlpha(text[i]);
    }

    // конец файла
    if (std::cin.eof()){
        *rch += new RefInteger((infint)0);
        std::cin.clear();
    }

    return rch;
}


bool  system_DEC::eval(RefData* lft, RefData* rht, RefChain* &result, Session* s){
    result = Dec(lft, rht, s);
    if (result) return true;
    return false;
};

bool  system_DIV::eval(RefData* lft, RefData* rht, RefChain* &result, Session* s){
    result = Div(lft, rht, s);
    if (result) return true;
    return false;
};

bool system_MUL::eval(RefData* lft, RefData* rht, RefChain* &result, Session* s){
    result = Mul(lft, rht, s);
    if (result) return true;
    return false;
};

bool system_SUM::eval(RefData* lft, RefData* rht, RefChain* &result, Session* s){
    result = Sum(lft, rht, s);
    if (result) return true;
    return false;
};

bool system_LENW::eval(RefData* lft, RefData* rht, RefChain* &result, Session* s){
    result = Lenw(lft, rht, s);
    if (result) return true;
    return false;
};

bool system_NUMB::eval(RefData* lft, RefData* rht, RefChain* &result, Session* s){
    result = Numb(lft, rht, s);
    if (result) return true;
    return false;
};

bool system_COMPARE::eval(RefData* lft, RefData* rht, RefChain* &result, Session* s){
    result = DataCompare(lft, rht, s);
    if (result) return true;
    return false;
};

bool system_IMPLODE::eval(RefData* lft, RefData* rht, RefChain* &result, Session* s){
    result = new RefChain(lft, rht);
    RefWord  *ww = new RefWord(result->explode());
    result->first = result->second = ww;
    return true;
};

bool system_EXPLODE::eval(RefData* lft, RefData* rht, RefChain* &result, Session* s){
    if (lft != rht) return false;
    RefWord* ww = dynamic_cast<RefWord*>(lft);
    if (! ww) return false;

    long i = 0;
    unistring str = ww->getValue();
    result = new RefChain();
    while(str[i]){
        *result += new RefAlpha(str[i++]);
    }
    return true;
};



bool system_MOUNT::eval(RefData* lft, RefData* rht, RefChain* &result, Session* s){
    result = Mount(lft, rht, s);
    if (result) return true;
    return false;
};

bool system_CARD::eval(RefData* lft, RefData* rht, RefChain* &result, Session* s){
    result = Card(lft, rht, s);
    if (result) return true;
    return false;
};

bool system_PROUT::eval(RefData* lft, RefData* rht, RefChain* &result, Session* s){
    std::cout
    #ifdef DEBUG
            << "\n############################### STDOUT ###############################\n"
            << ":####:\t"
    #endif
            << vectorToString(lft, rht) << "\n"
    #ifdef DEBUG
            << "\n######################################################################\n"
    #endif
            ;
    return true;
};


bool system_PRINT::eval(RefData* lft, RefData* rht, RefChain* &result, Session* s){
    std::cout
    #ifdef DEBUG
            << "\n############################### STDOUT ###############################\n"
            << ":####:\t"
    #endif
            << vectorToString(lft, rht) << "\n"
    #ifdef DEBUG
            << "\n######################################################################\n"
    #endif
            ;

    result = RefChain(lft, rht).Copy(s); //todo: подобрать сборкой мусора или продумать эффективнее
    return true;
};


bool system_EXIT::eval(RefData* lft, RefData* rht, RefChain* &result, Session* s){
    return false;
}

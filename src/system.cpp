// DiRefal - sentential program language
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
#include <fstream>
//#include <stdlib>

#include "system.h"

#include "function.h"
#include "symbols.h"


RefChain *StrToChain(unistring text){
	size_t leng = text.length();
	RefChain *res = new RefChain(leng);

	for(size_t i=0; i<leng; i++){
		*res += new RefAlpha(text[i]);
	};
	return res;
};

RefData*   word_creator(unistring value){
	return new RefWord(value);
};

RefData*  alpha_creator(unistring value){
	if (value.length() != 1) SYSTEMERRORn("Data for alpha incorrect: '" << value << "'");
	return new RefAlpha(value[0]);
};

RefData*    int_creator(unistring value){
	return new RefInteger( atol(value.c_str()) );
};

RefData*   real_creator(unistring value){
	return new RefReal( atof(value.c_str()) );
};

RefData*   byte_creator(unistring value){
	if (sizeof(value.c_str()) != sizeof(char)) SYSTEMERRORn("Data for byte incorrect: '" << value << "'");
	return new RefByte( *(value.c_str()) );
};



RefChain* Dec (RefData** beg, RefData** end, Session* s){
    RefInteger *a = ref_dynamic_cast<RefInteger >(*beg);
    RefInteger *b = ref_dynamic_cast<RefInteger >(*end);

	if (!a || !b || (beg+1 != end)){
        RUNTIMEERRORs(s, "error arguments");
        return 0;
    };
    a = new RefInteger(a->getValue() - b->getValue());
	return new RefChain(a);
};




RefChain* Div (RefData** beg, RefData** end, Session* s){
    RefInteger *a = ref_dynamic_cast<RefInteger >(*beg);
    RefInteger *b = ref_dynamic_cast<RefInteger >(*end);
    if (!a || !b || (beg+1 != end)){
        RUNTIMEERRORs(s, "error arguments");
        return 0;
    };
    //std::cout << "\n\nDiv: " << a->getValue() << " / " << b->getValue() ;
    RefReal* c = new RefReal((float)a->getValue() / b->getValue());
    //std::cout << " = " << c->getValue();
    return new RefChain(c);
};


RefChain* Sum (RefData** beg, RefData** end, Session* s){
    infint thesum = 0;
    RefInteger *a;
    //std::cout << "\n\nSum: ";
    while(beg != end+1){
        a = ref_dynamic_cast<RefInteger >(*beg);

        if (! a){
            RUNTIMEERRORs(s, "error arguments");
            return 0;
        }
        thesum += a->getValue();
        s->MOVE_TO_next_term(beg);
    }

    //std::cout << a->getValue() << " = " << thesum ;
    a = new RefInteger(thesum);
    return new RefChain(a);
};


RefChain* Mul (RefData** beg, RefData** end, Session* s){
    infint thesum = 1;
    RefInteger *a;
    //std::cout << "\n\nMul: ";
    while(beg != end+1){
        a = ref_dynamic_cast<RefInteger >(*beg);

        if (! a){
            RUNTIMEERRORs(s, "error arguments");
            return 0;
        }
        thesum *= a->getValue();
        s->MOVE_TO_next_term(beg);
    }
    a = new RefInteger(thesum);
    return new RefChain(a);
};




RefChain* Lenw (RefData** beg, RefData** end, Session* s){
	//TODO:оптимизировать
    infint thecount = 0;
    RefInteger *a;
    if (beg) while(beg != end+1){
        thecount++;
        s->MOVE_TO_next_term(beg);
    }

    a = new RefInteger(thecount);
    return new RefChain(a);
};



RefChain* Numb (RefData** beg, RefData** end, Session* s){
    /// todo: сделать не только integer и поверять ошибки
    long l = strtol(the_explode(beg, end).c_str(), NULL, 10);
    RefInteger *a = new RefInteger(l);
    return new RefChain(a);
};


RefChain*  Compare(RefData** beg, RefData** end, Session* s){
    RefData *a = 0;
    if (beg+1 != end){
        RUNTIMEERRORs(s, "Must be 2 arguments");
        return 0;
    }

    if (**beg > **end){
        a = new RefAlpha('+');
    } else if (*beg == *end || **beg == **end){
        a = new RefAlpha('0');
    } else {
        a = new RefAlpha('-');
    }
    return new RefChain(a);
};


RefChain* Mount (RefData** beg, RefData** end, Session* s){

      size_t length;
      char * buffer;

      std::ifstream is;
      is.open ( the_explode(beg, end).c_str(), std::ios::binary );

      // get length of file:
      is.seekg (0, std::ios::end);
      length = is.tellg();
      is.seekg (0, std::ios::beg);
	  if (length < 0) {
		  std::cerr << "Can`r open file: " << the_explode(beg, end) << std::flush;
		  return 0;
	  }

      // allocate memory:
      buffer = new char [length];

      // read data as a block:
      is.read (buffer,length);
      is.close();

      RefChain *result = new RefChain(length);
      for (size_t i=0; i<length; i++){
            if (buffer[i] != '\r'){   /// todo: правильно обрабатывать
                (*result) += new RefAlpha(buffer[i]);
            }
      }

      delete[] buffer;

      return result;


}


RefChain* Card (RefData** beg, RefData** end, Session* s){
    if (beg) {
		RUNTIMEERRORs(s, "Not empty args in Card : " << the_explode(beg, end));
        return 0;
    }
    unistring sline; /// todo LOCALE
    std::string text = "";
    //std::cin >>  text;
    std::getline(std::cin, text);

	size_t tlen = text.length();
    RefChain *rch = new RefChain(tlen);

    //for (size_t i=0; i<text.length(); i++){
    for (size_t i=0; i<tlen; i++){
        *rch += new RefAlpha(text[i]);
    }

    // конец файла
    if (std::cin.eof()){
        *rch += new RefInteger((infint)0);
        std::cin.clear();
    }

    return rch;
};


RefChain* Implode (RefData** beg, RefData** end, Session* s){
	return new RefChain(new RefWord(the_explode(beg, end)));
};

RefChain* Explode (RefData** lft, RefData** rht, Session* s){
    if (lft != rht) RUNTIMEERRORs(s, "must be one argument");
    RefWord* ww = ref_dynamic_cast<RefWord>(*lft);
    if (! ww) RUNTIMEERRORs(s, "must be compund-symbol argument");

    long i = 0;
    unistring str = ww->getValue();
    RefChain *result = new RefChain(str.length());
    while(str[i]){
        *result += new RefAlpha(str[i++]);
    }
    return result;
};


RefChain* ExplodeAll (RefData** lft, RefData** rht, Session* s){
    unistring str = the_explode(lft, rht);
    RefChain *result = StrToChain(str);
    return result;
};


RefChain* Prout (RefData** lft, RefData** rht, Session* s){
    std::cout
    #ifdef DEBUG
            << "\n############################### STDOUT ###############################\n"
            << ":####:\t"
    #endif
			<< the_text(lft, rht) << "\n"
    #ifdef DEBUG
            << "\n######################################################################\n"
    #endif
            ;
    return new RefChain();
};


RefChain* Print (RefData** lft, RefData** rht, Session* s){
	unistring thetext = the_text(lft, rht);
    std::cout
    #ifdef DEBUG
            << "\n############################### STDOUT ###############################\n"
            << ":####:\t"
    #endif
			<< thetext << "\n"
    #ifdef DEBUG
            << "\n######################################################################\n"
    #endif
            ;
    return StrToChain(thetext);;
};

RefChain* Exit (RefData** lft, RefData** rht, Session* s){
	exit(0);
	return 0;
};

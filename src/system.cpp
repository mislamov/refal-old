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
#include <fstream>
//#include <stdlib>

#include "system.h"

#include "function.h"
#include "symbols.h"


RefChain *StrToChain(Session *s, unistring text){
	size_t leng = text.length();
	RefChain *res = new RefChain(s, leng);

	for(size_t i=0; i<leng; i++){
		*res += newRefAlpha(s, text[i]);
	};
	return res;
};


RefData*   word_creator(unistring value){
	return new RefWord(0, value);
};

RefData*  alpha_creator(unistring value){
	if (value.length() != 1) SYSTEMERRORn("Data for alpha incorrect: '" << value << "'");
	return newRefAlpha(0, value[0]);
};

RefData*    int_creator(unistring value){
	return new RefInteger(0, atol(value.c_str()) );
};

RefData*   real_creator(unistring value){
	return new RefReal(0, atof(value.c_str()) );
};

RefData*   byte_creator(unistring value){
	if (sizeof(value.c_str()) != sizeof(char)) SYSTEMERRORn("Data for byte incorrect: '" << value << "'");
	return new RefByte(0, *(value.c_str()) );
};



RefChain* Dec (RefData** beg, RefData** end, Session* s){
	RefIntegerBase *a = ref_dynamic_cast<RefIntegerBase >(*beg);
	RefIntegerBase *b = ref_dynamic_cast<RefIntegerBase >(*end);

	if (!a || !b || (beg+1 != end)){
        RUNTIMEERRORs(s, "error arguments");
        return 0;
    };
    a = new RefInteger(s, a->getValue() - b->getValue());
	return new RefChain(s, a);
};




RefChain* Div (RefData** beg, RefData** end, Session* s){
	RefIntegerBase *a = ref_dynamic_cast<RefIntegerBase >(*beg);
	RefIntegerBase *b = ref_dynamic_cast<RefIntegerBase >(*end);
    if (!a || !b || (beg+1 != end)){
        RUNTIMEERRORs(s, "error arguments");
        return 0;
    };
    //std::cout << "\n\nDiv: " << a->getValue() << " / " << b->getValue() ;
    RefReal* c = new RefReal(s, (float)a->getValue() / b->getValue());
    //std::cout << " = " << c->getValue();
    return new RefChain(s, c);
};


RefChain* Sum (RefData** beg, RefData** end, Session* s){
    infint thesum = 0;
    RefIntegerBase *a;
    //std::cout << "\n\nSum: ";
    while(beg != end+1){
		a = ref_dynamic_cast<RefIntegerBase >(*beg);

        if (! a){
            RUNTIMEERRORs(s, "error arguments");
            return 0;
        }
        thesum += a->getValue();
        s->MOVE_TO_next_term(beg);
    }

    //std::cout << a->getValue() << " = " << thesum ;
    a = new RefInteger(s, thesum);
    return new RefChain(s, a);
};


RefChain* Mul (RefData** beg, RefData** end, Session* s){
    infint thesum = 1;
    RefIntegerBase *a;
    //std::cout << "\n\nMul: ";
    while(beg != end+1){
		a = ref_dynamic_cast<RefIntegerBase >(*beg);

        if (! a){
            RUNTIMEERRORs(s, "error arguments");
            return 0;
        }
        thesum *= a->getValue();
        s->MOVE_TO_next_term(beg);
    }
    a = new RefInteger(s, thesum);
    return new RefChain(s, a);
};




RefChain* Lenw (RefData** beg, RefData** end, Session* s){
	//TODO:оптимизировать
    infint thecount = 0;
    RefInteger *a;
    if (beg) while(beg != end+1){
        thecount++;
        s->MOVE_TO_next_term(beg);
    }

    a = new RefInteger(s, thecount);
    return new RefChain(s, a);
};



RefChain* Numb (RefData** beg, RefData** end, Session* s){
    /// todo: сделать не только integer и поверять ошибки
    long l = strtol(the_explode(beg, end).c_str(), NULL, 10);
    RefInteger *a = new RefInteger(s, l);
    return new RefChain(s, a);
};


RefChain*  Compare(RefData** beg, RefData** end, Session* s){
    RefData *a = 0;
    if (beg+1 != end){
        RUNTIMEERRORs(s, "Must be 2 arguments");
        return 0;
    }

    if (**beg > **end){
        a = newRefAlpha(s, '+');
    } else if (*beg == *end || **beg == **end){
        a = newRefAlpha(s, '0');
    } else {
        a = newRefAlpha(s, '-');
    }
    return new RefChain(s, a);
};


RefChain* Mount (RefData** beg, RefData** end, Session* s){

      size_t length;
      char *buffer;

      std::ifstream is;
	  unistring filename = the_explode(beg, end);		  
	  is.open ( filename.c_str(), std::ios::binary );

	  if(! is.is_open()){
		  RUNTIMEERRORs(s, "Can`t open file: " << filename);
	  }

      // get length of file:
      is.seekg (0, std::ios::end);
      length = is.tellg();
      is.seekg (0, std::ios::beg);
	  if (length < 0) {
		  std::cerr << "Can`t open file: " << filename << std::flush;
		  return 0;
	  }

      // allocate memory:
      buffer = new char[length+1];

      // read data as a block:
      is.read (buffer,length);
      is.close();

      RefChain *result = new RefChain(s, length);
      for (size_t i=0; i<length; i++){
            if (buffer[i] != '\r'){   /// todo: правильно обрабатывать
				(*result) += newRefAlpha(s, buffer[i]);
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
    RefChain *rch = new RefChain(s, tlen);

    //for (size_t i=0; i<text.length(); i++){
    for (size_t i=0; i<tlen; i++){
		if (text[i] < 128){
			*rch += RefAlpha128::alphatable+text[i];
		}else{
			*rch += newRefAlpha(s, text[i]);
		}
    }

    // конец файла
    if (std::cin.eof()){
        *rch += new RefInteger(s, (infint)0);
        std::cin.clear();
    }

    return rch;
};


RefChain* Implode (RefData** beg, RefData** end, Session* s){
	return new RefChain(s, new RefWord(s, the_explode(beg, end)));
};

RefChain* Explode (RefData** lft, RefData** rht, Session* s){
    if (lft != rht) RUNTIMEERRORs(s, "must be one argument");
	RefWordBase* ww = ref_dynamic_cast<RefWordBase >(*lft);
    if (! ww) RUNTIMEERRORs(s, "must be compund-symbol argument");

    long i = 0;
    unistring str = ww->getValue();
    RefChain *result = new RefChain(s, str.length());
    while(str[i]){
        *result += newRefAlpha(s, str[i++]);
    }
    return result;
};


RefChain* ExplodeAll (RefData** lft, RefData** rht, Session* s){
    unistring str = the_explode(lft, rht);
    RefChain *result = StrToChain(s, str);
    return result;
};


RefChain* Prout (RefData** lft, RefData** rht, Session* s){
    std::cout
    #ifdef DEBUG
            << "\n############################### STDOUT ###############################\n"
            << ":####:\t"
			<< the_debug_text(lft, rht) << "\n"
            << "\n######################################################################\n"
#else
			<< the_text(lft, rht) << "\n"
#endif
            ;
	//std::cout << s->debug() << "\n" << std::flush;
	//std::cout << "o: " << co::objs << "\n" << std::flush;
	//std::cout << "c: " << co::chains << "\n" << std::flush;
    return new RefChain(s);
};

RefChain* ProutDebug (RefData** lft, RefData** rht, Session* s){
    std::cout
			<< the_debug_text(lft, rht) << "\n";
    return new RefChain(s);
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
    return StrToChain(s, thetext);;
};

RefChain* Exit (RefData** lft, RefData** rht, Session* s){
	exit(0);
	return 0;
};

#define IS_EN_LETTER(ch)	((ch >=65 && ch <= 90)||(ch >= 97 && ch <= 122) || (ch == '_'))
#define IS_DIGIT(ch)		(ch >= 48 && ch <= 57)
#define IS_WHITE(ch)		(ch > 00  && ch <= 32)

inline unichar NEXT_CHAR(Session *s, RefData **&symch){ 
	s->MOVE_TO_next_term(symch); 
	if (!symch) return 0;
	RefAlphaBase *sym = ref_dynamic_cast<RefAlphaBase>(*symch);
	if (!sym) {
			RUNTIMEERRORs(s, "unexpected term: " << sym->debug());
	}
	return sym->getValue();
}

inline unichar AFTER_CHAR(Session *s, RefData **symch){ 
	symch = s->GET_next_term(symch); 
	if (!symch) return 0;
	RefAlphaBase *sym = ref_dynamic_cast<RefAlphaBase>(*symch);
	if (!sym) {
			RUNTIMEERRORs(s, "unexpected term: " << sym->debug());
	}
	return sym->getValue();
}

inline unichar BEFORE_CHAR(Session *s, RefData **symch){ 
	symch = s->GET_pred_term(symch); 
	if (!symch) return 0;
	RefAlphaBase *sym = ref_dynamic_cast<RefAlphaBase>(*symch);
	if (!sym) {
			RUNTIMEERRORs(s, "unexpected term: " << sym->debug());
	}
	return sym->getValue();
}

RefChain* closeAllBrackets(Session *s, RefChain *currChain, PooledTuple2<unichar, RefChain*> *result_stack){
	ref_assert(result_stack->getLength());
	unichar ch;
	RefChain *chain = 0;
	result_stack->top_pop(ch, chain);
	if (ch == '$') return chain;
	RefStructBrackets *br = 0;

	unistring bracket_code;
	do {
		switch (ch){
			case ')' : bracket_code = "("; break;
			case '}' : bracket_code = "{"; break;
			case '>' : bracket_code = "<"; break;
			case ']' : bracket_code = "["; break;
			default: SYSTEMERRORs(s, "unexpected bracket-type: " << ch);
		}
		br = new RefStructBrackets(s, currChain);
		(*chain) += br;
		currChain = chain;
		result_stack->top_pop(ch, chain);
	} while (result_stack->getLength());

	ref_assert(ch=='$');
	//std::cout << chain->debug() << "\n";
	return chain;
};

inline unichar ecran_char(unichar ch){
	switch(ch){
		case 't': return '\t'; 
		case 'n': return '\n'; 
	}
	return ch;
}

RefChain* RefalTokens  (RefData** beg, RefData** end, Session* s){
	RefChain *result = new RefChain(s);
	if (!beg) {
		return result;
	}
	
	s->save_current_view_borders(beg, end);  // устанавливаем границы для GET_next_term
	RefData** symchar = beg; 
	RefAlphaBase* sym = ref_dynamic_cast<RefAlphaBase>(*symchar);
	if (!sym) {
		RUNTIMEERRORs(s, "unexpected term: " << sym->debug());
	}
	unichar ch = sym->getValue();


	PooledTuple2<unichar, RefChain*> result_stack;
	result_stack.put('$', result);


	do {
		// пробелы
		if (IS_WHITE(ch)){
			do {
				ch = NEXT_CHAR(s, symchar);
			}while (IS_WHITE(ch));
			(*result) += newRefAlpha(s, ' ');
			continue;
		}

		// идентификатор
		if (IS_EN_LETTER(ch)){
			unistring word = "";
			do{
				word += ch;
				ch = NEXT_CHAR(s, symchar);
			}while(IS_EN_LETTER(ch) || IS_DIGIT(ch));
			RefChain *tmp = new RefChain(s);
			(*tmp) += new RefWord(s, "word");
			(*tmp) += new RefWord(s, word);
			(*result) += new RefStructBrackets(s, tmp);
			continue;
		}

		// целое число
		if (IS_DIGIT(ch)){
			unistring word = "";
			do{
				word += ch;
				ch = NEXT_CHAR(s, symchar);
			}while(IS_DIGIT(ch));
			/*if (ch!=0x46){ // НЕ точка
				result += new RefInteger(s, word);
				continue;
			}*/
			RefChain *tmp = new RefChain(s);
			(*tmp) += new RefWord(s, "int");
			(*tmp) += new RefInteger(s, str2infint(word));
			(*result) += new RefStructBrackets(s, tmp);
			
			continue;
		}

		if (ch == '\''){  // кавычка текстового символа
			ch = NEXT_CHAR(s, symchar);
			RefChain *tmp = new RefChain(s, new RefWord(s, "text"));
			while(ch && (ch != '\'')){
				if (ch=='\\'){
					ch = NEXT_CHAR(s, symchar);
					(*tmp) += newRefAlpha(s, ecran_char(ch));
				} else {
					(*tmp) += (*symchar);
				}
				ch = NEXT_CHAR(s, symchar);
			};
			(*result) += new RefStructBrackets(s, tmp);
			ch = NEXT_CHAR(s, symchar); // уходим от закр. кавычки
			continue;
		}


		if (ch == '"'){  // кавычка термального слова
			unichar ch_pre = '"';
			ch = NEXT_CHAR(s, symchar);
			unistring word;
			RefChain *tmp = new RefChain(s, new RefWord(s, "word"));
			while(ch && (ch != '"' || ch_pre=='\\')){
				word += ch;
				ch_pre = ch;
				ch = NEXT_CHAR(s, symchar);
			};
			(*tmp) += new RefWord(s, word);
			(*result) += new RefStructBrackets(s, tmp);
			ch = NEXT_CHAR(s, symchar); // уходим от закр. кавычки
			continue;
		}

		// скобки
		if (ch == '('){ 
			result_stack.put(')', result);
			result = new RefChain(s, new RefWord(s, ch));
			ch = NEXT_CHAR(s, symchar); // уходим от закр. кавычки
			continue;
		}
		if (ch == '<'){ 
			result_stack.put('>', result);
			result = new RefChain(s, new RefWord(s, ch));
			ch = NEXT_CHAR(s, symchar); // уходим от закр. кавычки
			continue;
		}
		if (ch == '{'){ 
			result_stack.put('}', result);
			result = new RefChain(s, new RefWord(s, ch));
			ch = NEXT_CHAR(s, symchar); // уходим от закр. кавычки
			continue;
		}
		if (ch == '['){ 
			result_stack.put(']', result);
			result = new RefChain(s, new RefWord(s, ch));
			ch = NEXT_CHAR(s, symchar); // уходим от закр. кавычки
			continue;
		}

		switch (ch){
			case ')':
			case '>':
			case '}':
			case ']':
				unichar old_chr;
				RefChain* old_chain;
				result_stack.top(old_chr, old_chain);
				if (old_chr == ch){
					result_stack.pop();
					(*old_chain) += new RefStructBrackets(s, result);
					result = old_chain;
					//std::cout << "\n::: " << result->debug() << "\n\n";
					ch = NEXT_CHAR(s, symchar); // уходим от ')'
					continue;
				} else {
					/*RefChain* t_result = new RefChain(s, new RefWord(s, "F"));
					(*t_result) += new RefStructBrackets(s, closeAllBrackets(s, result, &result_stack));
					(*t_result) += new RefStructBrackets(s, new RefChain(s, symchar, end-symchar+1));
					return t_result;*/
					RefChain* t_result = new RefChain(s, new RefWord(s, "error"));
					(*t_result) += (symchar ? new RefChain(s, symchar, end-symchar+1) : new RefChain(s));
					(*result)   += new RefStructBrackets(s, t_result);
					return closeAllBrackets(s, result, &result_stack);
				}
		}

		if (
			(ch=='/' && AFTER_CHAR(s, symchar)=='*')
		){ // коментарии   /* */   
			ch = NEXT_CHAR(s, symchar); // *
			ch = NEXT_CHAR(s, symchar);
			RefChain* t_result = new RefChain(s, new RefWord(s, "comment"));
			while(symchar && (ch != '*' || AFTER_CHAR(s, symchar)!='/')){
				(*t_result) += newRefAlpha(s, ch);
				ch = NEXT_CHAR(s, symchar);
			}
			(*result) += new RefStructBrackets(s, t_result);
			if (symchar){
				ch = NEXT_CHAR(s, symchar);  //   /
				ch = NEXT_CHAR(s, symchar);  //   
				continue;
			}
		}



		if (ch=='/' && AFTER_CHAR(s, symchar)=='/'){ // коментарии   //
			ch = NEXT_CHAR(s, symchar); // /
			ch = NEXT_CHAR(s, symchar);
			RefChain* t_result = new RefChain(s, new RefWord(s, "comment"));
			while(symchar && (ch != '\n')){
				(*t_result) += newRefAlpha(s, ch);
				ch = NEXT_CHAR(s, symchar);
			}
			(*result) += new RefStructBrackets(s, t_result);
			if (symchar){
				ch = NEXT_CHAR(s, symchar);  //   /n..
				continue;
			}
		}


		if (ch=='*' && BEFORE_CHAR(s, symchar)=='\n'){ // коментарии   * \n
			ch = NEXT_CHAR(s, symchar);
			RefChain* t_result = new RefChain(s, new RefWord(s, "comment"));
			while(symchar && (ch != '\n')){
				(*t_result) += newRefAlpha(s, ch);
				ch = NEXT_CHAR(s, symchar);
			}
			(*result) += new RefStructBrackets(s, t_result);
			if (symchar){
				ch = NEXT_CHAR(s, symchar);  //   /n..
				continue;
			}
		}

		(*result) += new RefWord(s, ch);
		ch = NEXT_CHAR(s, symchar);
	} while(symchar);

	ref_assert(result_stack.getLength()>=1);

	if (result_stack.getLength()!=1){
		/*RefChain *t_result = new RefChain(s, new RefWord(s, "F"));
		(*t_result) += new RefStructBrackets(s, closeAllBrackets(s, result, &result_stack));
		(*t_result) += new RefStructBrackets(s, symchar ? new RefChain(s, symchar, end-symchar+1) : new RefChain(s));
		//std::cout << "\n\n" << t_result->debug() << "\n\n";
		return t_result;*/

		RefChain* t_result = new RefChain(s, new RefWord(s, "error"));
		(*t_result) += (symchar ? new RefChain(s, symchar, end-symchar+1) : new RefChain(s));
		(*result)   += new RefStructBrackets(s, t_result);
		return closeAllBrackets(s, result, &result_stack);
	}

	s->delete_current_view_borders(); // возвращаем сессию в исходное состояние
	//RefChain *tmp = new RefChain(s, new RefWord(s, "T"));
	//(*tmp) += result;
	//return tmp;
	return result;
};

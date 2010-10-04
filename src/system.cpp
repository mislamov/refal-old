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
//#include <stdlib.h>
#include <time.h>

#include "system.h"

#include "function.h"
#include "symbols.h"

#include "SAXLoader_expat.h"

RefChain *StrToChain(Session *sess, unistring text){
	size_t leng = text.length();
	RefChain *res = new RefChain(sess, leng);

	for(size_t i=0; i<leng; i++){
		*res += newRefAlpha(sess, text[i]);
	}
	return res;
}


RefData*   word_creator(unistring value){
	return new RefWord(0, value);
}

RefData*  alpha_creator(unistring value){
	if (value.length() != 1) SYSTEMERRORn("Data for alpha incorrect: '" << value << "'");
	return newRefAlpha(0, value[0]);
}

RefData*    int_creator(unistring value){
	return new RefInteger(0, atol(value.c_str()) );
}

RefData*   real_creator(unistring value){
	return new RefReal(0, atof(value.c_str()) );
}

RefData*   byte_creator(unistring value){
	if (sizeof(value.c_str()) != sizeof(char)) SYSTEMERRORn("Data for byte incorrect: '" << value << "'");
	return new RefByte(0, *(value.c_str()) );
}



RefChain* Dec (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){
	RefIntegerBase *a = ref_dynamic_cast<RefIntegerBase >(*beg);
	RefIntegerBase *b = ref_dynamic_cast<RefIntegerBase >(*end);

	if (!a || !b || (beg+1 != end)){
        RUNTIMEERRORs(sess, "error arguments");
        return 0;
    }
    a = new RefInteger(sess, a->getValue() - b->getValue());
	return new RefChain(sess, a);
}




RefChain* Div (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){
	RefIntegerBase *a = ref_dynamic_cast<RefIntegerBase >(*beg);
	RefIntegerBase *b = ref_dynamic_cast<RefIntegerBase >(*end);
    if (!a || !b || (beg+1 != end)){
        RUNTIMEERRORs(sess, "error arguments");
        return 0;
    }
    //std::cout << "\n\nDiv: " << a->getValue() << " / " << b->getValue() ;
    RefReal* c = new RefReal(sess, (float)a->getValue() / b->getValue());
    //std::cout << " = " << c->getValue();
    return new RefChain(sess, c);
}


RefChain* Sum (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){
    infint thesum = 0;
    RefIntegerBase *a;
    if (!beg) RUNTIMEERRORs(sess, "error arguments");
    //std::cout << "\n\nSum: ";
    while(beg != end+1){
		a = ref_dynamic_cast<RefIntegerBase >(*beg);

        if (! a){
            RUNTIMEERRORs(sess, "error arguments");
            return 0;
        }
        thesum += a->getValue();
        sess->MOVE_TO_next_term(beg);
    }

    //std::cout << a->getValue() << " = " << thesum ;
    a = new RefInteger(sess, thesum);
    return new RefChain(sess, a);
}


RefChain* Mul (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){
    infint thesum = 1;
    RefIntegerBase *a;
    if (!beg) RUNTIMEERRORs(sess, "error arguments");
    //std::cout << "\n\nMul: ";
    while(beg != end+1){
		a = ref_dynamic_cast<RefIntegerBase >(*beg);

        if (! a){
            RUNTIMEERRORs(sess, "error arguments");
            return 0;
        }
        thesum *= a->getValue();
        sess->MOVE_TO_next_term(beg);
    }
    a = new RefInteger(sess, thesum);
    return new RefChain(sess, a);
}




RefChain* Lenw (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){
	//TODO:оптимизировать
    infint thecount = 0;
    RefInteger *a;
    if (beg) while(beg != end+1){
        thecount++;
        sess->MOVE_TO_next_term(beg);
    }

    a = new RefInteger(sess, thecount);
    return new RefChain(sess, a);
}



RefChain* Numb (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){
    /// todo: сделать не только integer и поверять ошибки
    long l = strtol(the_explode(beg, end).c_str(), NULL, 10);
    RefInteger *a = new RefInteger(sess, l);
    return new RefChain(sess, a);
}

// Сравнивает два терма (по перегруженному оператору > или ==)
RefChain*  Compare(RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){
    RefData *a = 0;
    if (beg+1 != end){
        RUNTIMEERRORs(sess, "Must be 2 arguments");
        return 0;
    }

    if (**beg > **end){
        a = newRefAlpha(sess, '+');
    } else if (*beg == *end || **beg == **end){
        a = newRefAlpha(sess, '0');
    } else {
        a = newRefAlpha(sess, '-');
    }
    return new RefChain(sess, a);
}


RefChain* Mount (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){

      size_t length;
      char *buffer;

      std::ifstream is;
	  unistring filename = the_explode(beg, end);
	  is.open ( filename.c_str(), std::ios::binary );

	  if(! is.is_open()){
		  RUNTIMEERRORs(sess, "Can`t open file: " << filename);
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

	  RefChain *result = text_to_chain(sess, buffer, length);

      delete[] buffer;
      return result;
}

RefChain* File (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){
    if (!beg) {
		RUNTIMEERRORs(sess, "Empty args in File");
        return 0;
    }
	unistring fname = (*beg)->explode();
	if (beg == end){
		beg = 0;
	} else {
		sess->MOVE_TO_next_term(beg);
	}


	std::ofstream file;
	file.open(fname.c_str());
	if (! file.is_open()){
		RUNTIMEERRORs(sess, "Can't open file: " << fname);
		return 0;
	}

	RefChain *tmp = new RefChain(sess, begend_chain, beg, end);
	file << tmp->explode();
	file.close();
	return new RefChain(sess);
}

RefChain* Args (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){
	if (beg) RUNTIMEERRORs(sess, "Not empty args in Args : " << the_explode(beg, end));


	if (sess->getProgram()->argchain != 0) {
		//std::cout<< "\n" << sess->getProgram()->argchain << "\n" << std::flush;
		return sess->getProgram()->argchain;
	}

	RefChain *res = new RefChain(0); // не для коллектора! Хранится всю программу
	int argc = sess->getProgram()->argc;
	char** argv = sess->getProgram()->argv;

	/*if (argc > 1) (*res) += text_to_chain(sess, argv[2]);
	for (int i=3; i<argc; ++i){
		(*res) += newRefAlpha(sess, ' ');
		(*res) += text_to_chain(sess, argv[i]);
	}*/

	if (argc > 1) (*res) += new RefWord(0, argv[1]);  // не для коллектора! Хранится всю программу
	for (int i=2; i<argc; ++i){
		(*res) += new RefWord(0, argv[i]);  // не для коллектора! Хранится всю программу
	}


	sess->getProgram()->argchain = res;
	return res;
}

RefChain* Card (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){
    if (beg) {
		RUNTIMEERRORs(sess, "Not empty args in Card : " << the_explode(beg, end));
        return 0;
    }
    unistring sline; /// todo LOCALE
    std::string text = "";
    //std::cin >>  text;
    std::getline(std::cin, text);

	size_t tlen = text.length();
    RefChain *rch = new RefChain(sess, tlen);

    //for (size_t i=0; i<text.length(); i++){
    for (size_t i=0; i<tlen; i++){
		if ((unsigned int)text[i] < 128){
			*rch += RefAlpha128::alphatable+text[i];
		}else{
			*rch += newRefAlpha(sess, text[i]);
		}
    }

    // конец файла
    if (std::cin.eof()){
        *rch += new RefInteger(sess, (infint)0);
        std::cin.clear();
    }

    return rch;
}


RefChain* Implode (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){
	return new RefChain(sess, new RefWord(sess, the_explode(beg, end)));
}

RefChain* Explode (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){
    if (beg != end) RUNTIMEERRORs(sess, "must be one argument");
	RefWordBase* ww = ref_dynamic_cast<RefWordBase >(*beg);
    if (! ww) RUNTIMEERRORs(sess, "must be compund-symbol argument");

    long i = 0;
    unistring str = ww->getValue();
    RefChain *result = new RefChain(sess, str.length());
    while(str[i]){
        *result += newRefAlpha(sess, str[i++]);
    }
    return result;
}


RefChain* ExplodeAll (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){
    unistring str = the_explode(beg, end);
    RefChain *result = StrToChain(sess, str);
    return result;
}


RefChain* Prout (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){
    std::cout
    #ifdef DEBUG
            << "\n############################### STDOUT ###############################\n"
            << ":####:\t"
			<< the_debug_text(beg, end) << "\n"
            << "\n######################################################################\n"
#else
			<< chain_to_text(beg, end) << "\n"
#endif
            ;
	//std::cout << sess->debug() << "\n" << std::flush;
	//std::cout << "o: " << co::objs << "\n" << std::flush;
	//std::cout << "c: " << co::chains << "\n" << std::flush;
    return new RefChain(sess);
}

RefChain* ProutDebug (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){
    std::cerr
			<< the_debug_text(beg, end) << "\n";
    return new RefChain(sess);
}

RefChain* StdErr (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){
	std::cerr << chain_to_text(beg, end) << "\n";
    return new RefChain(sess);
}

RefChain* Print (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){
	unistring thetext = chain_to_text(beg, end);
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
    //return StrToChain(sess, thetext);
	return new RefChain(sess, begend_chain, beg, end);
}

RefChain* Exit (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){
	exit(0);
	return 0;
}

#define IS_EN_LETTER(ch)	((ch >=65 && ch <= 90)||(ch >= 97 && ch <= 122) || (ch == '_') || (ch == '-'))
#define IS_DIGIT(ch)		(ch >= 48 && ch <= 57)
#define IS_WHITE(ch)		(ch >= 00  && ch <= 32)

inline unichar NEXT_CHAR(Session *sess, RefData **&symch){
	sess->MOVE_TO_next_term(symch);
	if (!symch) return 0;
	RefAlphaBase *sym = ref_dynamic_cast<RefAlphaBase>(*symch);
	if (!sym) {
			RUNTIMEERRORs(sess, "unexpected term: " << (*symch)->debug());
	}
	return sym->getValue();
}

inline unichar AFTER_CHAR(Session *sess, RefData **symch){
	symch = sess->GET_next_term(symch);
	if (!symch) return 0;
	RefAlphaBase *sym = ref_dynamic_cast<RefAlphaBase>(*symch);
	if (!sym) {
			RUNTIMEERRORs(sess, "unexpected term: " << (*symch)->debug());
	}
	return sym->getValue();
}

inline unichar BEFORE_CHAR(Session *sess, RefData **symch){
	symch = sess->GET_pred_term(symch);
	if (!symch) return 0;
	RefAlphaBase *sym = ref_dynamic_cast<RefAlphaBase>(*symch);
	if (!sym) {
			RUNTIMEERRORs(sess, "unexpected term: " << (*symch)->debug());
	}
	return sym->getValue();
}

RefChain* closeAllBrackets(Session *sess, RefChain *currChain, PooledTuple2<unichar, RefChain*> *result_stack){
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
			default: SYSTEMERRORs(sess, "unexpected bracket-type: " << ch);
		}
		br = new RefStructBrackets(sess, currChain);
		(*chain) += br;
		currChain = chain;
		result_stack->top_pop(ch, chain);
	} while (result_stack->getLength());

	ref_assert(ch=='$');
	//std::cout << chain->debug() << "\n";
	return chain;
}

inline unichar ecran_char(unichar &ch){
	switch(ch){
		case 't': return '\t';
		case 'n': return '\n';
		case '\\':
				ch = 0; // чтобы не экранировать " если "\\"
				return '\\';
	}
	return ch;
}

inline char getRandAlpha(){
	return 65 + rand()%26;
}

RefChain* RandomIdName(RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){
	unistring word = "ffffffffffffff";
	//srand ((unsigned int) time(NULL) );

	word[0] = getRandAlpha();
	for (int i=1; i<14; ++i){
		word[i] = getRandAlpha();
	}

	return new RefChain(sess, new RefWord(sess, word));
}


RefChain* RefalTokens  (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){
	RefChain *result = new RefChain(sess);
	if (!beg) {
		return result;
	}

	sess->save_current_view_borders(beg, end, sess->current_view_lr_own());  // устанавливаем границы для GET_next_term
	RefData** symchar = beg;
	RefAlphaBase* sym = ref_dynamic_cast<RefAlphaBase>(*symchar);
	if (!sym) {
		RUNTIMEERRORs(sess, "unexpected term: " << (*symchar)->debug());
	}
	unichar ch = sym->getValue();


	PooledTuple2<unichar, RefChain*> result_stack;
	result_stack.put('$', result);

	do {
		// пробелы
		if (IS_WHITE(ch)){
			do {
				ch = NEXT_CHAR(sess, symchar);
			}while (symchar && IS_WHITE(ch));
			(*result) += newRefAlpha(sess, ' ');
			continue;
		}

		// идентификатор
		if (IS_EN_LETTER(ch)){
			unistring word = "";
			do{
				word += ch;
				ch = NEXT_CHAR(sess, symchar);
			}while(IS_EN_LETTER(ch) || IS_DIGIT(ch));
			RefChain *tmp = new RefChain(sess);
			(*tmp) += new RefWord(sess, "word");
			(*tmp) += new RefWord(sess, word);
			(*result) += new RefStructBrackets(sess, tmp);
			continue;
		}

		// целое число
		if (IS_DIGIT(ch)){
			unistring word = "";
			do{
				word += ch;
				ch = NEXT_CHAR(sess, symchar);
			}while(IS_DIGIT(ch));
			/*if (ch!=0x46){ // НЕ точка
				result += new RefInteger(sess, word);
				continue;
			}*/
			RefChain *tmp = new RefChain(sess);
			(*tmp) += new RefWord(sess, "int");
			(*tmp) += new RefInteger(sess, str2infint(word));
			(*result) += new RefStructBrackets(sess, tmp);

			continue;
		}

		if (ch == '\''){  // кавычка текстового символа
			ch = NEXT_CHAR(sess, symchar);
			RefChain *tmp = new RefChain(sess, new RefWord(sess, "text"));
			while(ch && (ch != '\'')){
				if (ch=='\\'){
					ch = NEXT_CHAR(sess, symchar);
					(*tmp) += newRefAlpha(sess, ecran_char(ch));
				} else {
					(*tmp) += (*symchar);
				}
				ch = NEXT_CHAR(sess, symchar);
			}
			(*result) += new RefStructBrackets(sess, tmp);
			ch = NEXT_CHAR(sess, symchar); // уходим от закр. кавычки
			continue;
		}


		if (ch == '"'){  // кавычка термального слова
			unichar ch_pre = '"';
			ch = NEXT_CHAR(sess, symchar);
			unistring word;
			RefChain *tmp = new RefChain(sess, new RefWord(sess, "word"));
			while(ch && (ch != '"' || ch_pre=='\\')){
				if (ch=='\\'){
					ch = NEXT_CHAR(sess, symchar);
					word += ecran_char(ch);
				} else {
					word += ch;
				}
				ch_pre = ch;
				ch = NEXT_CHAR(sess, symchar);
			}
			(*tmp) += new RefWord(sess, word);
			(*result) += new RefStructBrackets(sess, tmp);
			ch = NEXT_CHAR(sess, symchar); // уходим от закр. кавычки
			continue;
		}

		// скобки
		if (ch == '('){
			result_stack.put(')', result);
			result = new RefChain(sess, new RefWord(sess, ch));
			ch = NEXT_CHAR(sess, symchar); // уходим от закр. кавычки
			continue;
		}
		if (ch == '<'){
			result_stack.put('>', result);
			result = new RefChain(sess, new RefWord(sess, ch));
			ch = NEXT_CHAR(sess, symchar); // уходим от закр. кавычки
			continue;
		}
		if (ch == '{'){
			result_stack.put('}', result);
			result = new RefChain(sess, new RefWord(sess, ch));
			ch = NEXT_CHAR(sess, symchar); // уходим от закр. кавычки
			continue;
		}
		if (ch == '['){
			result_stack.put(']', result);
			result = new RefChain(sess, new RefWord(sess, ch));
			ch = NEXT_CHAR(sess, symchar); // уходим от закр. кавычки
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
					if (ch==')') {
						if (old_chain->at_last() == NULL){
							RefChain* t_result = new RefChain(sess, new RefWord(sess, "$error"));
							(*t_result) += (symchar ? new RefChain(sess, symchar, end-symchar+1) : new RefChain(sess));
							(*result)   += new RefStructBrackets(sess, t_result);
							return closeAllBrackets(sess, result, &result_stack);
						}
						RefAlphaBase *ab = ref_dynamic_cast<RefAlphaBase>(*(old_chain->at_last()));
						if (!ab || (ab->getValue() != ' ')){
							(*old_chain) += newRefAlpha(sess, ' ');
						}
						(*old_chain) += new RefStructBrackets(sess, result);
						//(*old_chain) += newRefAlpha(sess, ' ');
					} else {
						(*old_chain) += new RefStructBrackets(sess, result);
					}

					result = old_chain;
					//std::cout << "\n::: " << result->debug() << "\n\n";
					ch = NEXT_CHAR(sess, symchar); // уходим от ')'
					continue;
				} else {
					/*RefChain* t_result = new RefChain(sess, new RefWord(sess, "F"));
					(*t_result) += new RefStructBrackets(sess, closeAllBrackets(sess, result, &result_stack));
					(*t_result) += new RefStructBrackets(sess, new RefChain(sess, symchar, end-symchar+1));
					return t_result;*/
					RefChain* t_result = new RefChain(sess, new RefWord(sess, "$error"));
					(*t_result) += (symchar ? new RefChain(sess, symchar, end-symchar+1) : new RefChain(sess));
					(*result)   += new RefStructBrackets(sess, t_result);
					return closeAllBrackets(sess, result, &result_stack);
				}
		}

		if (
			(ch=='/' && AFTER_CHAR(sess, symchar)=='*')
		){ // коментарии   /* */
			ch = NEXT_CHAR(sess, symchar); // *
			ch = NEXT_CHAR(sess, symchar);
			RefChain* t_result = new RefChain(sess, new RefWord(sess, "comment"));
			while(symchar && (ch != '*' || AFTER_CHAR(sess, symchar)!='/')){
				(*t_result) += newRefAlpha(sess, ch);
				ch = NEXT_CHAR(sess, symchar);
			}
			(*result) += new RefStructBrackets(sess, t_result);
			if (symchar){
				ch = NEXT_CHAR(sess, symchar);  //   /
				ch = NEXT_CHAR(sess, symchar);  //
				continue;
			}
		}



		if (ch=='/' && AFTER_CHAR(sess, symchar)=='/'){ // коментарии   //
			ch = NEXT_CHAR(sess, symchar); // /
			ch = NEXT_CHAR(sess, symchar);
			RefChain* t_result = new RefChain(sess, new RefWord(sess, "comment"));
			while(symchar && (ch != '\n')){
				(*t_result) += newRefAlpha(sess, ch);
				ch = NEXT_CHAR(sess, symchar);
			}
			(*result) += new RefStructBrackets(sess, t_result);
			if (symchar){
				ch = NEXT_CHAR(sess, symchar);  //   /n..
			}
			continue;
		}


		if (ch=='*' && BEFORE_CHAR(sess, symchar)=='\n'){ // коментарии   * \n
			ch = NEXT_CHAR(sess, symchar);
			RefChain* t_result = new RefChain(sess, new RefWord(sess, "comment"));
			while(symchar && (ch != '\n')){
				(*t_result) += newRefAlpha(sess, ch);
				ch = NEXT_CHAR(sess, symchar);
			}
			(*result) += new RefStructBrackets(sess, t_result);
			if (symchar){
				ch = NEXT_CHAR(sess, symchar);  //   /n..
			}
			continue;
		}

		(*result) += new RefWord(sess, ch);
		ch = NEXT_CHAR(sess, symchar);
	} while(symchar);

	ref_assert(result_stack.getLength()>=1);

	if (result_stack.getLength()!=1){
		/*RefChain *t_result = new RefChain(sess, new RefWord(sess, "F"));
		(*t_result) += new RefStructBrackets(sess, closeAllBrackets(sess, result, &result_stack));
		(*t_result) += new RefStructBrackets(sess, symchar ? new RefChain(sess, symchar, end-symchar+1) : new RefChain(s));
		//std::cout << "\n\n" << t_result->debug() << "\n\n";
		return t_result;*/

		RefChain* t_result = new RefChain(sess, new RefWord(sess, "$error"));
		(*t_result) += (symchar ? new RefChain(sess, symchar, end-symchar+1) : new RefChain(sess));
		(*result)   += new RefStructBrackets(sess, t_result);
		return closeAllBrackets(sess, result, &result_stack);
	}

	sess->delete_current_view_borders(); // возвращаем сессию в исходное состояние
	//RefChain *tmp = new RefChain(sess, new RefWord(sess, "T"));
	//(*tmp) += result;
	//return tmp;
	return result;
}



RefChain* PrintStackTrace  (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){
	sess->printExecTrace();
	return new RefChain(sess);
}

RefChain* Eval  (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){
    //std::cout << "\nEVAL: " << chain_to_text(beg, end) << "\n";
    RefChain *exch = new RefChain(sess, 1);
    (*exch) += new RefWord(sess, "REFAL2XML");
    (*exch) += new RefChain(sess, begend_chain, beg, end);
    RefChain *xmlcode = sess->getProgram()->executeExpression( new RefChain(sess, new RefExecBrackets(sess, exch)), sess );
    RefUserModule *global = (RefUserModule*)sess->getProgram()->findModule("global");
    if (!global){
        SYSTEMERRORs(sess, "module GLOBAL not found");
    }
    unistring xml = xmlcode->explode();
    int err = loadModuleFromXmlCode(global, sess->getProgram(), xml, true);
    if (err) return 0;
    return new RefChain(sess);
}




RefChain* Mod  (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){ notrealisedERRORs(sess); }
RefChain* Trunc(RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){ notrealisedERRORs(sess); }
RefChain* Round(RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){ notrealisedERRORs(sess); }
RefChain* Symb (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){ notrealisedERRORs(sess); }
RefChain* Chr (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess) { notrealisedERRORs(sess); }
RefChain* Ord (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess) { notrealisedERRORs(sess); }
RefChain* First (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){ notrealisedERRORs(sess); }
RefChain* Last (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){ notrealisedERRORs(sess); }
RefChain* Lower (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){ notrealisedERRORs(sess); }
RefChain* Upper (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){ notrealisedERRORs(sess); }
RefChain* StdLog (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){ notrealisedERRORs(sess); }
RefChain* Time (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){ notrealisedERRORs(sess); }
RefChain* Mu (RefData** beg, RefData** end, RefChain* begend_chain, Session* sess){ notrealisedERRORs(sess); }



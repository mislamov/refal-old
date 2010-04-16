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

#include "data.h"
//#include "symbols.h"
//#include "sentence.h"
#include "session.h"
#include "program.h"

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <map>
#include <stack>
#include <set>

size_t RefChain::alloc_portion = CHAIN_SYSTEM_PORTION_SIZE_INIT;


namespace co {
	size_t objs = 0;
	size_t datas = 0;
	size_t vars = 0;
	size_t chains = 0;
	size_t stbracks = 0;
}

char* c_str(std::string str){
	size_t l = str.length();
	char *ch = new char[l];
	strncpy(ch, str.c_str(), l);
	return ch;
};

RefData::RefData(Session *sess) : RefObject(){
	if (sess){
		sess->gc_last->gc_next = this;
		sess->gc_last = this;
		set_collected();  //  00001000 - коллекционируемый
	}  else {
		gc_label = 0;  //  00000000 - НЕ коллекционируемый
	}
	//gc_label = sess->gc_currentlabel;
	co::datas++;
	this->gc_next = 0;
};

RefSegment::~RefSegment(){
}

RefSegment::RefSegment(Session *s, RefChain *o, RefData **f, RefData **t) : RefData(s){
	own=o;
	from=f-own->at_first();
	to=t-own->at_first();
}


TResult RefDataNull::init(RefData **&activeTemplate, Session* sess, RefData **&currentRight, RefData **&currentLeft, RefChain *&currentBorderOwn){ unexpectedERRORs(sess); };
TResult RefDataNull::back(RefData **&activeTemplate, Session* sess, RefData **&currentRight, RefData **&currentLeft, RefChain *&currentBorderOwn){ unexpectedERRORs(sess); };


RefChain::RefChain(Session *sess, RefData* d) : RefData(sess){

	sysize = leng = 1;
	first = (RefData**)malloc(sizeof(RefData*) * sysize);
	first[0] = d;
	co::chains++;
};

RefChain::RefChain(Session *sess, size_t size) : RefData(sess) { // size is not lenght

	sysize = size;
	first = (RefData**)malloc(sizeof(RefData*) * sysize);
	leng = 0;
	*first = 0;
	co::chains++;
};


RefChain::RefChain(Session *sess, RefChain *ownchain, RefData **from, RefData **to) : RefData(sess) { // size is not lenght
	first = 0;
	leng = sysize = 0;
	if (ownchain && ownchain->isEmpty()) return;  // если родитель имеется и он пуст - ничего не добавляем

	ref_assert(from <= to);
	ref_assert(!ownchain || ownchain->at_first() <= from);
	ref_assert(!ownchain || ownchain->at_last()  >= to);

	sysize = leng = to-from+1;
	first = (RefData**)malloc(sizeof(RefData*) * sysize);
	memcpy(first, from, sizeof(RefData*)*leng);
	co::chains++;
};



RefChain::~RefChain(){
	co::chains--;
	if (sysize && !isMemoryProtected()) {
		free(first);
	}
};

RefChain* RefChain::operator+=(RefData *ch) {
#ifdef TESTCODE
	if (leng>sysize) SYSTEMERRORn("Achtung!")
#endif

		ref_assert(!isMemoryProtected());

	if (leng == sysize){
		sysize += RefChain::alloc_portion;
		first   =   (RefData**) realloc(first, sizeof(RefData*)*(sysize) );
		//LOG("realloc");
		if (! first) RUNTIMEERRORn("memory limit");
	}
	first[leng] = ch;
	++leng;

	return this;
};

// после - ch не существует!
RefChain* RefChain::operator+=(RefChain *ch) {
	ref_assert(!isMemoryProtected());

	sysize += (ch->leng);
	first   =   (RefData**) realloc(first, sizeof(RefData*)*sysize );
	//LOG("realloc");
	if (! first) RUNTIMEERRORn("memory limit");
	memcpy(first+leng, ch->first, sizeof(RefData*)*(ch->leng));
	leng += ch->leng;
	//delete ch;
	ch = 0;
	return this;
};

RefChain* RefChain::operator+=(RefChain ch) {
	ref_assert(!isMemoryProtected());

	sysize += (ch.leng);
	first   =   (RefData**) realloc(first, sizeof(RefData*)*sysize );
	//LOG("realloc");
	if (! first) RUNTIMEERRORn("memory limit");
	memcpy(first+leng, ch.first, sizeof(RefData*)*(ch.leng));
	leng += ch.leng;
	return this;
};



RefData** RefChain::operator[](signed long idx) {
	/*#ifdef TESTCODE
	if ((idx<0 && (long)leng+idx<0) || (idx>0 && idx>=leng))
	AchtungERRORn;
	#endif*/
	//ref_assert(this!=0);
	return	leng? ((idx<0) ? first+leng+idx : first+idx) : 0;
};





unistring RefChain::debug(){
	unistring result = "";/*
						  result += "[";
						  result += "l";
						  char tmp[256];
						  result += ltoa( leng, tmp, 10);
						  result += "s";
						  result += ltoa( sysize, tmp, 10);
						  //result += " ";
						  //result += ltoa( RefChain::alloc_portion, tmp, 10);
						  result += "] ";*/

	for (size_t i=0; i<leng; i++) {
		result += (first[i] ? first[i]->debug() : " \x0000 ");
	}
	return result;
};

unistring RefChain::explode(){
	unistring result = "";

	if (!this){
		result = " $null ";
	}else{
		for (size_t i=0; i<leng; i++) {
#ifdef TESTCODE
			if (! first[i]) AchtungERRORn;
#endif
			result += first[i]->explode();
		}
	}
	return result;
};



unistring RefChain::toString(){
	unistring result = "";

	for (size_t i=0; i<leng; i++) {
		result += (first[i] ? first[i]->toString() : "");
	}
	return result;
};



unistring RefStructBrackets::explode(){		return "(" + chain->explode() + ") ";	};
unistring RefExecBrackets::explode(){	return "<" + chain->explode() + "> ";	};
unistring RefStructBrackets::toString(){		return "(" + chain->toString() + ") ";	};
unistring RefExecBrackets::toString(){	return "<" + chain->toString() + "> ";	};
unistring RefStructBrackets::debug(){		return "(" + (chain?chain->debug():"$null") + ") ";	};
unistring RefExecBrackets::debug(){	return "<" + (chain?chain->debug():"$null") + "> ";	};


TResult RefStructBrackets::init(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own){
	ref_assert(chain!=0);

	sess->MOVE_TO_next_term(r);
	RefStructBrackets *br;

	///todo: организовать стековое "путешествие" в matching, чтобы избавиться от этой рекурсии
	if (r
		&& (br=ref_dynamic_cast<RefStructBrackets>(*r))
		&& (sess->matching(
		0,
		this->chain,
		(*(br->chain))[0],
		(*(br->chain))[-1],
		br->chain,
		false
		)
		)
		){
			sess->saveBracketsFromView(this, (RefStructBrackets**)r);
			sess->MOVE_TO_next_template(tpl);
			return GO;
	}
	sess->MOVE_TO_pred_template(tpl);
	return BACK;


};
TResult RefStructBrackets::back(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own){
	// if (br->chain == this->chain) BACK;  - проверить сильно оптимизирует ли. только в сочентании с частью в init!
	RefStructBrackets** br = sess->restoreBracketsFromView(this);

	if (sess->matching(0, this->chain, (*((*br)->chain))[0],  (*((*br)->chain))[0]?(*((*br)->chain))[-1]:0, (*br)->chain, true)){
		sess->saveBracketsFromView(this, br);
		sess->MOVE_TO_next_template(tpl);
		r = (RefData**)br;
		return GO;
	}
	sess->MOVE_TO_pred_template(tpl);
	return BACK;
};


TResult RefExecBrackets::init(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own){
	AchtungERRORs(sess);
};
TResult RefExecBrackets::back(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own){
	AchtungERRORs(sess);
};

/*
RefVariable** RefChain::findVariable(unistring vname){
RefVariable *var = 0;
RefVariable **tvar = 0;
RefDataBracket *br = 0;
for (size_t i=0; i<leng; i++){
var = ref_dynamic_cast<RefVariable>( *((*this)[i]) );
if (var && var->getName()==vname) return (RefVariable**)(*this)[i];
br = ( *((*this)[i]) )->isDataBracket();
if (br && (tvar = br->chain->findVariable(vname)) && tvar) {
return tvar;
}
}
return 0;
};
*/


inline bool eq_not_empty(RefData **Al, RefData **Ar, RefData **Bl, RefData **Br){
	RefDataBracket *brA, *brB;
	while(Al<=Ar){
		brA = (*Al)->isDataBracket();
		if (brA){
			brB = (*Bl)->isDataBracket();
			if (!brB || !eq(brA->chain, brB->chain)) return false;
		} else {
			if ((*Al != *Bl) && !(**Al == **Bl)) return false;
		}
		++Al;
		++Bl;
	}
	return true;
};

inline bool eq(RefChain *ch1, RefChain *ch2){
	if (ch1->leng != ch2->leng) return false; // не одинаковые по физической длине. Переделать когда будет монтирование
	if (! ch1->leng) return true; // пустые
	return eq_not_empty((*ch1)[0], (*ch1)[-1], (*ch2)[0], (*ch2)[-1]);
};

inline bool eq(RefData **Al, RefData **Ar, RefData **Bl, RefData **Br){
	if (!Al) return !Bl;
	if (!Bl) return !Al;
	return eq_not_empty(Al, Ar, Bl, Br);
};




TResult RefLinkToVariable::init(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own){
	RefVariable *tmpvar = 0;
	RefData **ldata, **rdata;
	RefChain *lrdata_own;
	VarMap* vm = 0;
	if ( ! sess->findVar(this->lnk, ldata, rdata, lrdata_own, vm) ) {
		SYSTEMERRORs(sess, "INTERNAL ERROR: link to not exists variable! link = " << this->debug());
		return ERROR;
	}

	if (path != EmptyUniString && !vm->folowByWay(path, ldata, rdata, lrdata_own, tmpvar, vm)){
		RUNTIMEERRORs(sess, "Wrong way for variable " << lnk->toString() << " : " << path);
	}

	if (!ldata){ // пустые
		sess->MOVE_TO_next_template(tpl);
		return GO; // ссылка на пустой отрезок всегда сопоставляется с пустым значением
	}

	if (ldata==l && lr_own==lrdata_own){ // возможно, если указатель-ссылка на это выражение (ldata==l => l!=0 => сравнение pointer->theLink)
		if (rdata==r){
			sess->MOVE_TO_next_template(tpl);
			return GO;
		} else {
			sess->MOVE_TO_pred_template(tpl);
			return BACK;
		}
	}

	RefDataBracket *brA=0, *brB=0;
	while(ldata<=rdata){
		sess->MOVE_TO_next_term(r);
		if (!r){  // аргументы кончились
			sess->MOVE_TO_pred_template(tpl);
			return BACK;
		}

		brA = (*ldata)->isDataBracket();
		if (brA){
			brB = (*r)->isDataBracket();
			if (!brB || !eq(brA->chain, brB->chain)) {
				sess->MOVE_TO_pred_template(tpl);
				return BACK;
			}
		} else {
			if ((*ldata != *r) && !(**ldata == **r)) {
				sess->MOVE_TO_pred_template(tpl);
				return BACK;
			}
		}
		sess->MOVE_TO_next_term(ldata);
	}


	sess->MOVE_TO_next_template(tpl);
	return GO; // ссылка на пустой отрезок - верна
};


TResult RefLinkToVariable::back(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own){
	sess->MOVE_TO_pred_template(tpl);
	return BACK;
};


void RefVarChains::setUserType(RefUserTemplate *ntempli){
	templInstant = ntempli;
	templ = ntempli->getLeftPart();
};


size_t comp = 0;

// компиляция цепочки после построения. расстановка ссылок
// ownchain - левая часть для подстановки this. Тоже компилируется
void RefChain::compile(RefChain *ownchain, RefProgram *program){
#ifdef DEBUG
	std::cout << "compile: ["<< comp ++ <<"]" << this->explode() << "\n" << std::flush ;
#endif
	//if (isEmpty()) return; - нельзя выходить! если правая часть пуста, то левая все равно должна быть откомпилированна

	std::map<unistring, RefVariable*> vars;
	std::stack<RefData**> lnks;

	RefVariable *var;
	RefLinkToVariable *link;
	RefPointVariable *pointVar;
	RefPointLink *pointLink;
	RefDataBracket *bracks;
	RefVarChains *uservar;
	RefVariantsChains *uservarich;
	RefUserCondition *cond;
	RefRepeaterChain *rept;


	PooledTuple2<RefData**, RefData**> subchains;
	if (!this->isEmpty()){
		subchains.put(this->at_first(), this->at_afterlast());
	}
	if (ownchain && ownchain!=this && !ownchain->isEmpty()){
		subchains.put(ownchain->at_first(), ownchain->at_afterlast());  // родителя обработать раньше
	}

	while(subchains.getLength()){
		RefData
			**end = subchains.top2(),
			**point = subchains.top1();
		subchains.pop();

#ifdef DEBUG
		//std::cout << "compile: " << chain_to_text(point, end-1) << "\n";
#endif

		for(;
			point < end;
			++point){
				//std:: cout << (*point)->debug() << "~\t";

				uservar = ref_dynamic_cast<RefVarChains>(*point); // польз переменная или группа
				if (uservar){ // запоминаем заготовку для переменной
					if (! program) SYSTEMERRORn("program not null expected");
#ifdef TESTCODE
					if ((uservar->getTypeString() != EmptyUniString) && !(ref_dynamic_cast<RefUserTemplate>(program->findTemplate(uservar->getTypeString()) ))) {
						notrealisedERRORn;
					}
#endif
					if (uservar->getTypeString() != EmptyUniString) {
						uservar->setUserType((RefUserTemplate*) program->findTemplate(uservar->getTypeString()) );
					}

#ifdef TESTCODE
					if(uservar->getName()!=EmptyUniString && vars.find(uservar->getName())!=vars.end()){
						std::cout << "compile: " << chain_to_text(point, end-1) << "\n";
						std::cout << "WARN. Several same-name-variables in one compiling chain: ?." << uservar->getName() << "\n";
					};
#endif

					vars[uservar->getName()] = uservar; // todo: переделать на ссылки - так как есть безымянные переменные

					if (uservar->templInstant == 0){
						// группа
						subchains.put(point+1, end);
						if(! uservar->templ->isEmpty()) {
							subchains.put(uservar->templ->at_first(), uservar->templ->at_afterlast());
						};
						break;
					}
					continue;
				}

				pointVar = ref_dynamic_cast<RefPointVariable>(*point);  // ссылка на переменную-указатель
				if (pointVar){
					subchains.put(point+1, end);
					subchains.put((RefData**)&(pointVar->theVar), (RefData**)&(pointVar->theVar)+1);
					break;
				}

				pointLink = ref_dynamic_cast<RefPointLink>(*point);  // ссылка на переменную-указатель
				if (pointLink){
					subchains.put(point+1, end);
					subchains.put((RefData**)&(pointLink->theLink), (RefData**)&(pointLink->theLink)+1);
					break;
				}

				uservarich = ref_dynamic_cast<RefVariantsChains>(*point); // варианты
				if (uservarich){
					if (uservarich->getName() != ""){
#ifdef TESTCODE
						if (vars.find(uservarich->getName())!=vars.end()){
							std::cout << "\nWARN: several same-name-variables in one part. Error, if not a VARIANTS. Var: " << uservarich->getName() << "\n" << std::flush;
						};
#endif
						vars[uservarich->getName()] = uservarich;
					}
					subchains.put(point+1, end); // todo: if (point+1!=end) subchains.put(point+1, end); мм?
					for(int i=uservarich->templs.getCount(); i; --i){
						if (! uservarich->templs.getByIndex(i-1)->isEmpty() ){
							subchains.put(uservarich->templs.getByIndex(i-1)->at_first(), uservarich->templs.getByIndex(i-1)->at_afterlast());
						}
					}
					//continue;
					break;
				}

				rept = ref_dynamic_cast<RefRepeaterChain>(*point); // поВторитель
				if (rept){
					subchains.put(point+1, end);
					subchains.put(rept->templ->at_first(), rept->templ->at_afterlast());
					//continue;
					break;
				}


				var = ref_dynamic_cast<RefVariable>(*point);  // переменная
				if (var && var->getName()!=""){ // запоминаем переменную
					//std::cout << "\n::: " << var->debug() << "  :::\n";

					if( vars.find(var->getName())!=vars.end() ){
						SYSTEMERRORn("Unexpected variable redifinition: ?." << var->getName() << "  at chain: " << this->debug());
					}

					vars[var->getName()] = var;
					continue;
				}


				link = ref_dynamic_cast<RefLinkToVariable>(*point);  // ССЫЛКА
				if (link && (! link->lnk)){ // запоминаем ссылку
					lnks.push(point);
					continue;
				}

				bracks = (*point)->isDataBracket(); // ДАТА-СКОБКИ
				if (bracks && !bracks->chain->isEmpty()) { // смотрим в скобки
					subchains.put(point+1, end);
					subchains.put(bracks->chain->at_first(), bracks->chain->at_afterlast());
					break;
				}

				cond = ref_dynamic_cast<RefUserCondition>(*point);  // УСЛОВИЕ
				if (cond){
					subchains.put(point+1, end);
					if (! cond->getLeftPart()->isEmpty())
						subchains.put(cond->getLeftPart()->operator [](0), cond->getLeftPart()->operator [](-1)+1);
					if (! cond->getRightPart()->isEmpty())
						subchains.put(cond->getRightPart()->operator [](0), cond->getRightPart()->operator [](-1)+1);
					break;
				}
		}
	}

	// компиляция ссылок на переменные
	RefLinkToVariable** tmp = 0;
	while (! lnks.empty()){
#ifdef TESTCODE
		if (!dynamic_cast<RefLinkToVariable*>(*(lnks.top()))) AchtungERRORn;
#endif
		tmp = (RefLinkToVariable**) lnks.top();

		ref_assert((*tmp)->lnk || (*tmp)->path!="");

		if (! (*tmp)->lnk){
			size_t i = (*tmp)->path.find( varPathSeparator );
			// ссылка на часть внешней переменной
			unistring name = (*tmp)->path.substr(0, i);
			(*tmp)->path = (i!=unistring::npos) ? (*tmp)->path.substr(i+1) : EmptyUniString;

#ifdef TESTCODE
			if (vars.find(name)==vars.end()){
				SYSTEMERRORn("Variable not found ??." << name << ". Line: " << ownchain->debug() << " ==::== " << this->debug() );
			}
#endif
			ref_assert(vars.find(name)!=vars.end());

			(*tmp)->lnk = vars[name];
		}
		lnks.pop();
	}

	vars.clear();

#ifdef DEBUG
	std::cout << "compile-reult: " << this->explode() << "\n" << std::flush ;
#endif

};

// вызывается сразу после удачного сопоставления (вместо init правой границы)
TResult RefVarChains::success(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own){
#ifdef TESTCODE
	if (tpl) SYSTEMERRORs(sess, "succes and fail must get activeTemplate==0, but nownot");
#endif

	//std::cout << "RefVarChains::success\n";
	RefData **lold, **rold;
	VarMap *vm=0, *vm2=0;
	vm = sess->poptopVarMap(); // сохраняем карту переменных
	sess->restoreVar(this, lold, rold, lr_own, vm2); // начало аргумента переменной
#ifdef TESTCODE
	if (vm2) unexpectedERRORs(sess);
#endif
	if (rold != r){
		sess->MOVE_TO_next_term(rold);
		l = rold;
	} else {
		l = 0;	// значение переменной пустое
	}
	sess->saveVar(this, l, r, lr_own, vm); // сохраняем полное значение

	tpl = sess->termChainsJumpPoints.top_pop(); // выпрыгиваем из user-шаблона
	sess->popTmplate();


#ifdef TESTCODE
	if (*tpl != this) AchtungERRORs(sess);
#endif

	sess->MOVE_TO_next_template(tpl); // двигаемся дальше
	return GO;
};

// вызывается сразу после НЕудачного сопоставления (вместо back левой границы)
TResult RefVarChains::failed (RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own){
#ifdef TESTCODE
	if (tpl) SYSTEMERRORs(sess, "succes and fail must get activeTemplate==0, but nownot");
#endif

	//std::cout << "RefVarChains::faild\n";
	//delete sess->poptopVarMap(); - удалять только сборщиком
	sess->poptopVarMap();
	VarMap* tmp = 0;
	sess->restoreVar(this, l, r, lr_own, tmp);		 // забываем переменную
#ifdef TESTCODE
	if (tmp) unexpectedERRORs(sess);
#endif
	tpl = sess->termChainsJumpPoints.top_pop(); // выпрыгиваем из user-шаблона
	sess->popTmplate();


#ifdef TESTCODE
	if (*tpl != this) AchtungERRORs(sess);
#endif

	sess->MOVE_TO_pred_template(tpl);
	return BACK;
};

TResult RefVarChains::init(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own){
	//std::cout << "RefVarChains::init\n";
#ifdef TESTCODE
	if (*tpl != this) AchtungERRORs(sess);
	if (templInstant && ! dynamic_cast<RefUserTemplate*>(templInstant)) notrealisedERRORs(sess);
#endif

	if (!templ || templ->isEmpty()){
		notrealisedERRORs(sess);
		//sess->MOVE_TO_next_template(tpl);
		//return GO;
	}
	sess->saveVar(this, l=0, r, lr_own, 0);
	sess->createVarMap(this);
	sess->termChainsJumpPoints.put(tpl);
	sess->setTmplate(templ);
	tpl = templ->at_first();
	return GO;
};

// вызывается только после ранее удачного сопоставления
TResult RefVarChains::back(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own){
	//std::cout << "RefVarChains::back\n";
#ifdef TESTCODE
	if (*tpl != this) AchtungERRORs(sess);
#endif
	sess->termChainsJumpPoints.put(tpl);
	sess->setTmplate(templ);
	VarMap *vm = 0; // восстанавливаем карту переменных
	sess->restoreVar(this, l, r, lr_own, vm);
#ifdef TESTCODE
	if (!vm) unexpectedERRORs(sess);
#endif
	sess->saveVar(this, l?0:l, l?l-1:r, lr_own, 0);
	sess->putVarMap( vm );

	tpl = templ->at_last();
	return BACK;
};


unistring RefVarChains::explode() {
#ifdef DEBUG
	if (templInstant == 0 && templ == 0) return " [null] ";
#endif
#ifdef TESTCODE
	if (templInstant == 0 && templ == 0){
		//SYSTEMERRORn("RefVarChains[null, null]->explode()");
		return ("RefVarChains[null, null]->explode()");
	}

#endif
	return " " + (templInstant?templInstant->getName():("{ "+templ->explode()+" }")) + "." + getName();
};









TResult RefVariantsChains::init(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own){
#ifdef TESTCODE
	if (*tpl != this) AchtungERRORs(sess);
#endif

	if (templs.empty()){ notrealisedERRORs(sess);	}
	sess->saveVar(this, l=0, r, lr_own, 0);
	sess->createVarMap(this);
	RefChain *templ;
	sess->termChainsJumpPoints.put(tpl);
	sess->setTmplate(templ = templs.getByIndex(0));
	tpl = templ->at_first();

	sess->variants_idxs.push(0); // добавляем индекс для варианта
	return GO;
};


// вызывается сразу после удачного сопоставления (вместо init правой границы)
TResult RefVariantsChains::success(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own){
#ifdef TESTCODE
	if (tpl) SYSTEMERRORs(sess, "succes and fail must get activeTemplate==0, but nownot");
#endif

	RefData **lold, **rold;
	VarMap *vm=0, *vm2=0;
	vm = sess->poptopVarMap(); // сохраняем карту переменных
	sess->restoreVar(this, lold, rold, lr_own, vm2); // начало аргумента переменной
#ifdef TESTCODE
	if (vm2) unexpectedERRORs(sess);
#endif
	if (rold != r){
		sess->MOVE_TO_next_term(rold);
		l = rold;
	} else {
		l = 0;	// значение переменной пустое
	}
	sess->saveVar(this, l, r, lr_own, vm); // сохраняем полное значение

	tpl = sess->termChainsJumpPoints.top_pop();
	sess->popTmplate();

#ifdef TESTCODE
	if (*tpl != this) AchtungERRORs(sess);
#endif

	sess->MOVE_TO_next_template(tpl); // двигаемся дальше
	sess->variants_idxs_done.push(sess->variants_idxs.top_pop());
	return GO;
};


// вызывается сразу после НЕудачного сопоставления (вместо back левой границы)
TResult RefVariantsChains::failed (RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own){
#ifdef TESTCODE
	if (tpl) SYSTEMERRORs(sess, "succes and fail must get activeTemplate==0, but nownot");
#endif

	size_t idx = sess->variants_idxs.top();
	if (++idx == templs.getCount()){
		// варианты закончились
		//delete sess->poptopVarMap(); - only by g-collector!
		sess->poptopVarMap();
		sess->variants_idxs.pop();		//todo: перенестив varmap?
		VarMap* tmp = 0;
		sess->restoreVar(this, l, r, lr_own, tmp);		 // забываем переменную
#ifdef TESTCODE
		if (tmp) unexpectedERRORs(sess);
#endif
		tpl = sess->termChainsJumpPoints.top_pop(); // выпрыгиваем
		sess->popTmplate();

#ifdef TESTCODE
		if (*tpl != this) AchtungERRORs(sess);
#endif

		sess->MOVE_TO_pred_template(tpl);
		return BACK;
	}

	sess->variants_idxs.settop(idx);
	RefChain *templ;
	sess->popTmplate();
	sess->setTmplate(templ = templs.getByIndex(idx));
	tpl = templ->at_first();

	r = sess->preCurrentMapStack()->top3();
	return GO;
};


// вызывается только после ранее удачного сопоставления
TResult RefVariantsChains::back(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own){
	//std::cout << "RefVarChains::back\n";
#ifdef TESTCODE
	if (*tpl != this) AchtungERRORs(sess);
#endif
	sess->variants_idxs.push(sess->variants_idxs_done.top_pop());

	RefChain *templ;
	sess->termChainsJumpPoints.put(tpl);
	sess->setTmplate(templ = templs.getByIndex(sess->variants_idxs.top()));
#ifdef TESTCODE
	if (!templ) AchtungERRORs(sess);
#endif

	VarMap *vm = 0; // восстанавливаем карту переменных
	sess->restoreVar(this, l, r, lr_own, vm);
#ifdef TESTCODE
	if (!vm) unexpectedERRORs(sess);
#endif
	sess->saveVar(this, l?0:l, l?l-1:r, lr_own, 0);
	sess->putVarMap( vm );

	tpl = templ->at_last();
	return BACK;
};

unistring RefVariantsChains::explode(){
	size_t idx = templs.getCount();
	unistring res = templs.getByIndex(idx-1)->explode() + " }." + name + " ";
	for (--idx; idx; --idx){
		res = templs.getByIndex(idx-1)->explode() + " | " + res;
	}
	res = "{ " + res;
	return res;
};


unistring RefRepeaterChain::explode(){
	std::ostringstream ss;
	ss << "[ " << templ->explode() << "][" << min << ".." << max << "]";
	return ss.str();
};


TResult RefRepeaterChain::init   (RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own){
	if (templ->isEmpty()) SYSTEMERRORs(sess, "unexpected empty chain for repeater");
	// [
	if (! getMin()) { // [0..x]
		sess->MOVE_TO_next_template(tpl);
		sess->repeats_idxs_done.push(0);
		return GO;
	}
	// [n..x]
	sess->repeats_idxs.push(0);
	sess->termChainsJumpPoints.put(tpl);
	sess->setTmplate(templ);
	tpl = templ->at_first();
	return GO;
};

TResult RefRepeaterChain::back   (RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own){
	///   ]
	infint currentStep = sess->repeats_idxs_done.top_pop();

	if (currentStep < getMax()) {
		sess->repeats_idxs.push( currentStep );
		sess->termChainsJumpPoints.put(tpl);
		sess->setTmplate(templ);
		tpl = templ->at_first(); // внутри
		return GO;
	}
	--currentStep;
	sess->repeats_idxs.push( currentStep );
	sess->termChainsJumpPoints.put(tpl);
	sess->setTmplate(templ);
	tpl = templ->at_last();
	return BACK;
};

TResult RefRepeaterChain::success(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own){
#ifdef TESTCODE
	if (tpl) SYSTEMERRORs(sess, "succes and fail must get activeTemplate==0, but nownot");
#endif
	///  ]
	infint currentStep = sess->repeats_idxs.top_pop();
	++currentStep;

	if (currentStep < getMin()) {
		sess->repeats_idxs.push(currentStep);  ///todo: рптимизировать ++(...top()) ?
		tpl=templ->at_first(); // остаемся внутри варианта
		return GO;
	}
	tpl = sess->termChainsJumpPoints.top_pop(); // выпрыгиваем
	sess->popTmplate();

	sess->MOVE_TO_next_template(tpl); // уходим из варианта
	sess->repeats_idxs_done.push(currentStep);
	return GO;
};

TResult RefRepeaterChain::failed (RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own){
#ifdef TESTCODE
	if (tpl) SYSTEMERRORs(sess, "succes and fail must get activeTemplate==0, but nownot");
#endif
	///   [
	infint currentStep = sess->repeats_idxs.top();
	if (currentStep) {
		sess->repeats_idxs.settop(--currentStep);
		tpl=templ->at_last(); // внутри
		return BACK;
	}
	tpl = sess->termChainsJumpPoints.top_pop(); // выпрыгиваем
	sess->popTmplate();

	sess->repeats_idxs.pop();
	sess->MOVE_TO_pred_template(tpl); // выходим из варианта
	return BACK;

};



TResult RefMatchingCutter::init(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own){
	sess->MOVE_TO_next_template(tpl);
	return GO;
};
TResult RefMatchingCutter::back(RefData **&tpl, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own){
	// если отсекается пользовательская переменная
	// если отсекается текущая цепочка
	tpl=0;
	return BACK;
	//return FAIL;
};

/*
void RefChain::killall(){

//std::cout << "\nkillall: " << debug() << "\n";

RefDataBracket *br = 0;
for(RefData
**iter = this->first,
**iend=this->first+this->leng;
iter<iend;
++iter){
br = (*iter)->isDataBracket();
if (br && br->chain){
br->chain->killall();
delete br->chain;
br->chain = 0;
//br->gc_delete();
*iter = 0;
}
}
};
*/
void RefChain::killalldata(){

	RefDataBracket *br = 0;
	for(RefData
		**iter = this->first,
		**iend=this->first+this->leng;
	iter<iend;
	++iter){
		br = (*iter)->isDataBracket();
		if (br){
			br->chain->killalldata();
			//delete br->chain;
			br->chain->gc_delete();
			br->chain = 0;
			//br->gc_delete();
			//*iter = 0;
		}
		(*iter)->gc_delete();
		*iter = 0;
	}
};

RefDataBracket::~RefDataBracket(){
	--co::stbracks;
	//if (chain) delete chain; - нельзя удалять, так как две скобки могут смотреть на одну цепочку
};


RefVarChains::~RefVarChains(){
	//templ - удалять нельзя, если пренадлежит RefUserTemplate!
	if (!templInstant){
		templ->killalldata();
		templ->gc_delete();
	}
};

RefVariantsChains::~RefVariantsChains(){
	RefChain *tmp = 0;
	while(! templs.empty()){
		tmp = templs.top_pop();
		tmp->killalldata();
		tmp->gc_delete();
	}

};

RefRepeaterChain::~RefRepeaterChain(){
	templ->killalldata();
	templ->gc_delete();
};



TResult RefPointVariable::init(RefData **&activeTemplate, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own){
	// открытая переменная-указатель сопоставима только с указателем того же типа
	sess->MOVE_TO_next_term(r);
	RefPoint *point = 0;
	if (r && (point=ref_dynamic_cast<RefPoint>(*r)) && point->type==((RefVarChains*)this->theVar)->getUserType()){
		// указатель подходит
		//sess->saveVar(this->theVar, r, r, lr_own, point->the_namespace);
		sess->saveVar(this->theVar, point->l, point->r, point->lr_own, point->the_namespace);
		l = r;
		sess->MOVE_TO_next_template(activeTemplate);
		return GO;
	}

	sess->MOVE_TO_pred_template(activeTemplate);
	return BACK;

};
TResult RefPointVariable::back(RefData **&activeTemplate, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own){
	int i = this->theVar->getName().length();

	sess->forgotVar(this->theVar);
	//RefData **ll, **rr; RefChain *llrr_own; VarMap *vm=0;
	//sess->restoreVar(this->theVar, ll, rr, llrr_own, vm);
	sess->MOVE_TO_pred_template(activeTemplate);
	return BACK;
};


unistring RefPointLink::explode() { return "&@[" + theLink->explode() + "]"; };

TResult RefPointLink::init(RefData **&activeTemplate, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own){
	// закрытая переменная-указатель сопоставима только с указателем того же типа и equal-содержимого

	sess->MOVE_TO_next_term(r);
	if (!r) {
		sess->MOVE_TO_pred_template(activeTemplate);
		return BACK;
	}

	RefPoint *point = ref_dynamic_cast<RefPoint>(*r);


	ref_assert(this->theLink);
	ref_assert(this->theLink->lnk);
	ref_assert(ref_dynamic_cast<RefVarChains>(this->theLink->lnk));


	if (!point || point->type!=((RefVarChains*)this->theLink->lnk)->getUserType()){
		sess->MOVE_TO_pred_template(activeTemplate);
		return BACK;
	}

	// указатель подходит по типу
	// совпадает ли содержимое?

	// l==0, r==point
	RefData
		**point_l = point->l,
		**point_r = point->r;
	RefChain
		*point_lr_own = point->lr_own;

	RefData **ldata, **rdata; RefChain *lrdata_own; VarMap* vm = 0;
	if ( ! sess->findVar(theLink->lnk, ldata, rdata, lrdata_own, vm) ) {
		SYSTEMERRORs(sess, "INTERNAL ERROR: link to not exists variable! link = " << this->debug());
	}
	RefVariable *tmpvar = 0;
	if (theLink->path != EmptyUniString && !vm->folowByWay(theLink->path, ldata, rdata, lrdata_own, tmpvar, vm)){
		RUNTIMEERRORs(sess, "Wrong way for variable " << theLink->lnk->toString() << " : " << theLink->path);
	}


	sess->save_current_view_borders(point_l, point_r, point_lr_own); // активируем внешние границы

	TResult result = GO;
	if (!point_l || !ldata){ // есть пустое значение
		result = (ldata==point_l) ? GO : BACK; // если оба пустые => GO
	} else {
		ref_assert(point_r != 0);
		ref_assert(rdata   != 0);

		// todo: исправиь, когда физическая длина перестанет совпадать с логической (монтирование)
		if (rdata-ldata!=point_r-point_l){ // разные по физической длине
			result = BACK;
		} else {
			RefDataBracket *brA=0, *brB=0;
			while(ldata<=rdata && point_l<=point_r){
				brA = (*ldata)->isDataBracket();
				if (brA){
					brB = (*point_l)->isDataBracket();
					if (!brB || !eq(brA->chain, brB->chain)) {
						result = BACK;
						break;
					}
				} else {
					if ((*ldata != *point_l) && !(**ldata == **point_l)) {
						result = BACK;
						break;
					}
				}
				sess->MOVE_TO_next_term(ldata);
				++point_l;
			}

		}
	}

	sess->delete_current_view_borders(); // возврашаем исходные внешние границы


	if (result==GO || result==SUCCESS){
		sess->MOVE_TO_next_template(activeTemplate);
	} else {
		sess->MOVE_TO_pred_template(activeTemplate);
	}
	return result;
};

TResult RefPointLink::back(RefData **&activeTemplate, Session* sess, RefData **&l, RefData **&r, RefChain *&lr_own){
	sess->MOVE_TO_pred_template(activeTemplate);
	return BACK;
};

unistring RefPoint::explode(){
	std::stringstream ss;
	ss << "&" << (type?type->getName():"e") << "[";
	if (this->the_namespace!=0){
		for(size_t i=1, maxi = this->the_namespace->getLength(); i<=maxi; ++i){
			ss << this->the_namespace->get1ByIndex(i)->getName() << " ";
		}
	} else {
		ss << chain_to_text(l, r);
	}
	ss << "]";
	return ss.str();
};

TResult RefPoint::init(RefData **&activeTemplate, Session* sess, RefData **&currentRight, RefData **&currentLeft, RefChain *&currentBorderOwn){
	unexpectedERRORs(sess);
};

TResult RefPoint::back(RefData **&activeTemplate, Session* sess, RefData **&currentRight, RefData **&currentLeft, RefChain *&currentBorderOwn){
	unexpectedERRORs(sess);
};

void RefPoint::set_gc_mark(Session *sess){
	sess->gc_exclude(this->l, this->r, this->lr_own);
	the_namespace->set_gc_mark();
	the_namespace->mrk_collect();
};



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

size_t RefChain::alloc_portion = CHAIN_SYSTEM_PORTION_SIZE_INIT;

PooledTuple2<RefChain*, char*> allchains;

namespace co {
	size_t objs = 0;
	size_t datas = 0;
	size_t vars = 0;
	size_t chains = 0;
	size_t stbracks = 0;
}

char* c_str(std::string str){
	char *ch = new char[str.length()];
	strcpy(ch, str.c_str());
	return ch;
};


RefChain::RefChain(RefData* d) {
    sysize = leng = 1;
	first = (RefData**)malloc(sizeof(RefData*) * sysize);
	first[0] = d;
	co::chains++;
	allchains.put(this, "");
};

RefChain::RefChain(size_t size) { // size is not lenght
	sysize = size;
	first = (RefData**)malloc(sizeof(RefData*) * sysize);
	leng = 0;
	co::chains++;
	allchains.put(this, "");
};


RefChain* RefChain::operator+=(RefData *ch) {

	#ifdef TESTCODE
	if (leng>sysize) SYSTEMERRORn("Achtung!")
	#endif

	if (leng == sysize){
		sysize += RefChain::alloc_portion;
		first   =   (RefData**) realloc(first, sizeof(RefData*)*sysize );
		//LOG("realloc");
		if (! first) RUNTIMEERRORn("memory limit");
	}
	first[leng] = ch;
	++leng;

    return this;
};

// после - ch не существует!
RefChain* RefChain::operator+=(RefChain *ch) {
	sysize += ch->leng;
	first   =   (RefData**) realloc(first, sizeof(RefData*)*sysize );
	//LOG("realloc");
	if (! first) RUNTIMEERRORn("memory limit");
	memcpy(first+leng, ch->first, sizeof(RefData*)*(ch->leng));
	leng += ch->leng;
	delete ch;
	ch = 0;
	return this;
};

RefChain* RefChain::operator+=(RefChain ch) {
	sysize += ch.leng;
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

unistring RefStructBrackets::explode(){		return "(" + chain->explode() + ") ";	};
unistring RefExecBrackets::explode(){	return "<" + chain->explode() + "> ";	};
unistring RefStructBrackets::debug(){		return "(" + chain->debug() + ") ";	};
unistring RefExecBrackets::debug(){	return "<" + chain->debug() + "> ";	};


TResult RefStructBrackets::init(RefData **&tpl, Session* s, RefData **&l, RefData **&r){
    s->MOVE_TO_next_term(r);
	RefStructBrackets *br;

	if (r
		&& (br=ref_dynamic_cast<RefStructBrackets>(*r))
		&& (s->matching(
						0,
						this->chain,
						(*(br->chain))[0],
						(*(br->chain))[-1],
						false
						)
			)
	){
		s->saveBracketsFromView(this, (RefStructBrackets**)r);
		s->MOVE_TO_next_template(tpl);
		return GO;
	}
	s->MOVE_TO_pred_template(tpl);
	return BACK;


};
TResult RefStructBrackets::back(RefData **&tpl, Session* s, RefData **&l, RefData **&r){
	// if (br->chain == this->chain) BACK;  - проверить сильно оптимизирует ли. только в сочентании с частью в init!
	RefStructBrackets** br = s->restoreBracketsFromView(this);

	if (s->matching(0, this->chain, (*((*br)->chain))[0],  (*((*br)->chain))[0]?(*((*br)->chain))[-1]:0, true)){
		s->saveBracketsFromView(this, br);
		s->MOVE_TO_next_template(tpl);
		return GO;
	}
	s->MOVE_TO_pred_template(tpl);
	return BACK;
};


TResult RefExecBrackets::init(RefData **&tpl, Session* s, RefData **&l, RefData **&r){
	AchtungERRORs(s);
};
TResult RefExecBrackets::back(RefData **&tpl, Session* s, RefData **&l, RefData **&r){
	AchtungERRORs(s);
};

/*
RefVariable** RefChain::findVariable(unistring vname){
	RefVariable *var = 0;
	RefVariable **tvar = 0;
	RefDataBracket *br = 0;
	for (size_t i=0; i<leng; i++){
		var = ref_dynamic_cast<RefVariable>( *((*this)[i]) );
		if (var && var->getName()==vname) return (RefVariable**)(*this)[i];
		br = ref_dynamic_cast<RefDataBracket>( *((*this)[i]) );
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
		brA = ref_dynamic_cast<RefDataBracket>(*Al);
		if (brA){
			brB = ref_dynamic_cast<RefDataBracket>(*Bl);
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
	if (ch1->leng != ch2->leng) return false; // не одинаковые по длине
	if (! ch1->leng) return true; // пустые
	return eq_not_empty((*ch1)[0], (*ch1)[-1], (*ch2)[0], (*ch2)[-1]);
};

inline bool eq(RefData **Al, RefData **Ar, RefData **Bl, RefData **Br){
	if (!Al) return !Bl;
	if (!Bl) return !Al;
	return eq_not_empty(Al, Ar, Bl, Br);
};




TResult RefLinkToVariable::init(RefData **&tpl, Session* s, RefData **&l, RefData **&r){
	RefData **ldata, **rdata;
	VarMap* vm = 0;
	if ( ! s->findVar(this->lnk, ldata, rdata, vm) ) {
        SYSTEMERRORs(s, "INTERNAL ERROR: link to not exists variable! link = " << this->debug());
        return ERROR;
    };

	if (path != EmptyUniString && !vm->folowByWay(path, ldata, rdata)){
		RUNTIMEERRORs(s, "Wrong way for variable " << lnk->toString() << " : " << path);
	}


	if (!ldata){ // пустые
        s->MOVE_TO_next_template(tpl);
        return GO; // ссылка на пустой отрезок всегда сопоставляется с пустым значением
	}

	RefDataBracket *brA=0, *brB=0;
	while(ldata<=rdata){
		s->MOVE_TO_next_term(r);
		if (!r){  // аргументы кончились
				s->MOVE_TO_pred_template(tpl);
				return BACK;
		}

		brA = ref_dynamic_cast<RefDataBracket>(*ldata);
		if (brA){
			brB = ref_dynamic_cast<RefDataBracket>(*r);
			if (!brB || !eq(brA->chain, brB->chain)) {
				s->MOVE_TO_pred_template(tpl);
				return BACK;
			}
		} else {
			if ((*ldata != *r) && !(**ldata == **r)) {
				s->MOVE_TO_pred_template(tpl);
				return BACK;
			}
		}
		s->MOVE_TO_next_term(ldata);
	}


    s->MOVE_TO_next_template(tpl);
    return GO; // ссылка на пустой отрезок - верна
};


TResult RefLinkToVariable::back(RefData **&tpl, Session* s, RefData **&l, RefData **&r){
	s->MOVE_TO_pred_template(tpl);
	return BACK;
};


void RefVarChains::setTemplInstant(RefUserTemplate *ntempli){
	templInstant = ntempli;
	templ = ntempli->getLeftPart();
};



// компиляция цепочки после построения. расстановка ссылок
// ownchain - левая часть для подстановки this. Тоже компилируется
void RefChain::compile(RefChain *ownchain, RefProgram *program){
#ifdef DEBUG
	std::cout << "compile: " << this->explode() << "\n" << std::flush ;
#endif
	if (isEmpty()) return;

	std::map<unistring, RefVariable*> vars;
	std::stack<RefData**> lnks;

	RefVariable *var;
	RefLinkToVariable *link;
	RefDataBracket *bracks;
	RefVarChains *uservar;
	RefVariantsChains *uservarich;
	RefUserCondition *cond;
	RefRepeaterChain *rept;


	PooledTuple2<RefData**, RefData**> subchains;
	subchains.put(this->at(0), this->at(-1)+1);
	if (ownchain && ownchain!=this && !ownchain->isEmpty()){
		subchains.put(ownchain->at(0), ownchain->at(-1)+1);
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

			uservar = ref_dynamic_cast<RefVarChains>(*point); // польз переменная или группа
			if (uservar){ // запоминаем заготовку для переменной
				if (! program) SYSTEMERRORn("program not null expected");
				#ifdef TESTCODE
				if ((uservar->getType() != EmptyUniString) && !(ref_dynamic_cast<RefUserTemplate>(program->findTemplate(uservar->getType()) ))) {
				    notrealisedERRORn;
				}
				#endif
				if (uservar->getType() != EmptyUniString) {
					uservar->setTemplInstant((RefUserTemplate*) program->findTemplate(uservar->getType()) );
				}
				vars[uservar->getName()] = uservar; // todo: переделать на ссылки - так как есть безымянные переменные

				if (uservar->templInstant == 0){
					// группа
					subchains.put(point+1, end);
					if(! uservar->templ->isEmpty()) { subchains.put(uservar->templ->at(0), uservar->templ->at(-1)+1); };
					break;
				}
				continue;
			}

			uservarich = ref_dynamic_cast<RefVariantsChains>(*point); // вырианты
			if (uservarich){ // запоминаем заготовку для переменной
				vars[uservarich->getName()] = uservarich;
				subchains.put(point+1, end);
				for(int i=uservarich->templs.getCount(); i; --i){
					if (! uservarich->templs.getByIndex(i-1)->isEmpty() ){
						subchains.put(uservarich->templs.getByIndex(i-1)->at(0), uservarich->templs.getByIndex(i-1)->at(-1)+1);
					}
				}
				continue;
				//break;
			}


			rept = ref_dynamic_cast<RefRepeaterChain>(*point); // вырианты
			if (rept){ // запоминаем заготовку для переменной
				subchains.put(point+1, end);
				subchains.put(rept->templ->at(0), rept->templ->at(-1)+1);
				continue;
				//break;
			}



			var = ref_dynamic_cast<RefVariable>(*point);
			if (var){ // запоминаем переменную
				vars[var->getName()] = var;
				continue;
			}


			link = ref_dynamic_cast<RefLinkToVariable>(*point);
			if (link && !link->lnk){ // запоминаем ссылку
				lnks.push(point);
				continue;
			}

			bracks = ref_dynamic_cast<RefDataBracket>(*point);
			if (bracks && !bracks->chain->isEmpty()) { // смотрим в скобки
				subchains.put(point+1, end);
				subchains.put(bracks->chain->at(0), bracks->chain->at(-1)+1);
				break;
			}

			cond = ref_dynamic_cast<RefUserCondition>(*point);
			if (cond){
				subchains.put(point+1, end);
				if (! cond->getRightPart()->isEmpty())
					subchains.put(cond->getRightPart()->operator [](0), cond->getRightPart()->operator [](-1)+1);
				if (! cond->getLeftPart()->isEmpty())
					subchains.put(cond->getLeftPart()->operator [](0), cond->getLeftPart()->operator [](-1)+1);
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

			size_t i = (*tmp)->path.find( varPathSeparator );
			// ссылка на часть внешней переменной
			unistring name = (*tmp)->path.substr(0, i);
			(*tmp)->path = (i!=unistring::npos) ? (*tmp)->path.substr(i+1) : EmptyUniString;

			(*tmp)->lnk = vars[name];
			lnks.pop();
	}
};

// вызывается сразу после удачного сопоставления (вместо init правой границы)
TResult RefVarChains::success(RefData **&tpl, Session* sess, RefData **&l, RefData **&r){
#ifdef TESTCODE
	if (tpl) SYSTEMERRORs(sess, "succes and fail must get activeTemplate==0, but nownot");
#endif

	//std::cout << "RefVarChains::success\n";
	RefData **lold, **rold;
	VarMap *vm=0, *vm2=0;
	vm = sess->poptopVarMap(); // сохраняем карту переменных
	sess->restoreVar(this, lold, rold, vm2); // начало аргумента переменной
	#ifdef TESTCODE
		if (vm2) unexpectedERRORs(sess);
	#endif
	if (rold != r){
		sess->MOVE_TO_next_term(rold);
		l = rold;
	} else {
		l = 0;	// значение переменной пустое
	}
	sess->saveVar(this, l, r, vm); // сохраняем полное значение

	tpl = sess->termChainsJumpPoints.top_pop(); // выпрыгиваем из user-шаблона
	sess->popTmplate();


	#ifdef TESTCODE
	if (*tpl != this) AchtungERRORs(sess);
	#endif

	sess->MOVE_TO_next_template(tpl); // двигаемся дальше
	return GO;
};

// вызывается сразу после НЕудачного сопоставления (вместо back левой границы)
TResult RefVarChains::failed (RefData **&tpl, Session* sess, RefData **&l, RefData **&r){
#ifdef TESTCODE
	if (tpl) SYSTEMERRORs(sess, "succes and fail must get activeTemplate==0, but nownot");
#endif

	//std::cout << "RefVarChains::faild\n";
	delete sess->poptopVarMap();
	VarMap* tmp = 0;
	sess->restoreVar(this, l, r, tmp);		 // забываем переменную
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

TResult RefVarChains::init(RefData **&tpl, Session* sess, RefData **&l, RefData **&r){
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
	sess->saveVar(this, l=0, r, 0);
	sess->createVarMap(this);
	sess->termChainsJumpPoints.put(tpl);
	sess->setTmplate(templ);
	tpl = templ->at(0);
	return GO;
};

// вызывается только после ранее удачного сопоставления
TResult RefVarChains::back(RefData **&tpl, Session* sess, RefData **&l, RefData **&r){
	//std::cout << "RefVarChains::back\n";
	#ifdef TESTCODE
	if (*tpl != this) AchtungERRORs(sess);
	#endif
	sess->termChainsJumpPoints.put(tpl);
	sess->setTmplate(templ);
	VarMap *vm = 0; // восстанавливаем карту переменных
	sess->restoreVar(this, l, r, vm);
	#ifdef TESTCODE
		if (!vm) unexpectedERRORs(sess);
	#endif
	sess->saveVar(this, l?0:l, l?l-1:r, 0);
	sess->putVarMap( vm );

	tpl = templ->at(-1);
	return BACK;
};


unistring RefVarChains::explode() {
	return " " + (templInstant?templInstant->getName():("{ "+templ->explode()+" }")) + "." + getName();
};









TResult RefVariantsChains::init(RefData **&tpl, Session* sess, RefData **&l, RefData **&r){
	#ifdef TESTCODE
	if (*tpl != this) AchtungERRORs(sess);
	#endif

	if (templs.empty()){ notrealisedERRORs(sess);	}
	sess->saveVar(this, l=0, r, 0);
	sess->createVarMap(this);
	RefChain *templ;
	sess->termChainsJumpPoints.put(tpl);
	sess->setTmplate(templ = templs.getByIndex(0));
	tpl = templ->at(0);

	sess->variants_idxs.push(0); // добавляем индекс для варианта
	return GO;
};


// вызывается сразу после удачного сопоставления (вместо init правой границы)
TResult RefVariantsChains::success(RefData **&tpl, Session* sess, RefData **&l, RefData **&r){
#ifdef TESTCODE
	if (tpl) SYSTEMERRORs(sess, "succes and fail must get activeTemplate==0, but nownot");
#endif

	RefData **lold, **rold;
	VarMap *vm=0, *vm2=0;
	vm = sess->poptopVarMap(); // сохраняем карту переменных
	sess->restoreVar(this, lold, rold, vm2); // начало аргумента переменной
	#ifdef TESTCODE
	if (vm2) unexpectedERRORs(sess);
	#endif
	if (rold != r){
		sess->MOVE_TO_next_term(rold);
		l = rold;
	} else {
		l = 0;	// значение переменной пустое
	}
	sess->saveVar(this, l, r, vm); // сохраняем полное значение

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
TResult RefVariantsChains::failed (RefData **&tpl, Session* sess, RefData **&l, RefData **&r){
#ifdef TESTCODE
	if (tpl) SYSTEMERRORs(sess, "succes and fail must get activeTemplate==0, but nownot");
#endif

	size_t idx = sess->variants_idxs.top();
	if (++idx == templs.getCount()){
		// варианты закончились
		delete sess->poptopVarMap();
		sess->variants_idxs.pop();		//todo: перенестив varmap?
		VarMap* tmp = 0;
		sess->restoreVar(this, l, r, tmp);		 // забываем переменную
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
	tpl = templ->at(0);

	r = sess->preCurrentMapStack()->top3();
	return GO;
};


// вызывается только после ранее удачного сопоставления
TResult RefVariantsChains::back(RefData **&tpl, Session* sess, RefData **&l, RefData **&r){
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
	sess->restoreVar(this, l, r, vm);
	#ifdef TESTCODE
		if (!vm) unexpectedERRORs(sess);
	#endif
	sess->saveVar(this, l?0:l, l?l-1:r, 0);
	sess->putVarMap( vm );

	tpl = templ->at(-1);
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


TResult RefRepeaterChain::init   (RefData **&tpl, Session* sess, RefData **&l, RefData **&r){
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
	tpl = templ->at(0);
    return GO;
};

TResult RefRepeaterChain::back   (RefData **&tpl, Session* sess, RefData **&l, RefData **&r){
	///   ]
	infint currentStep = sess->repeats_idxs_done.top_pop();

    if (currentStep < getMax()) {
        sess->repeats_idxs.push( currentStep );
		sess->termChainsJumpPoints.put(tpl);
		sess->setTmplate(templ);
		tpl = templ->at(0); // внутри
        return GO;
    }
    --currentStep;
    sess->repeats_idxs.push( currentStep );
		sess->termChainsJumpPoints.put(tpl);
	sess->setTmplate(templ);
	tpl = templ->at(-1);
    return BACK;
};

TResult RefRepeaterChain::success(RefData **&tpl, Session* sess, RefData **&l, RefData **&r){
#ifdef TESTCODE
	if (tpl) SYSTEMERRORs(sess, "succes and fail must get activeTemplate==0, but nownot");
#endif
    ///  ]
	infint currentStep = sess->repeats_idxs.top_pop();
    ++currentStep;

    if (currentStep < getMin()) {
        sess->repeats_idxs.push(currentStep);  ///todo: рптимизировать ++(...top()) ?
		tpl=templ->at(0); // остаемся внутри варианта
        return GO;
    }
	tpl = sess->termChainsJumpPoints.top_pop(); // выпрыгиваем
	sess->popTmplate();

	sess->MOVE_TO_next_template(tpl); // уходим из варианта
	sess->repeats_idxs_done.push(currentStep);
    return GO;
};

TResult RefRepeaterChain::failed (RefData **&tpl, Session* sess, RefData **&l, RefData **&r){
#ifdef TESTCODE
	if (tpl) SYSTEMERRORs(sess, "succes and fail must get activeTemplate==0, but nownot");
#endif
	///   [
    infint currentStep = sess->repeats_idxs.top();
    if (currentStep) {
        sess->repeats_idxs.settop(--currentStep);
		tpl=templ->at(-1); // внутри
        return BACK;
    }
	tpl = sess->termChainsJumpPoints.top_pop(); // выпрыгиваем
	sess->popTmplate();

	sess->repeats_idxs.pop();
    sess->MOVE_TO_pred_template(tpl); // выходим из варианта
    return BACK;

};



TResult RefMatchingCutter::init(RefData **&tpl, Session* s, RefData **&l, RefData **&r){
	s->MOVE_TO_next_template(tpl);
	return GO;
};
TResult RefMatchingCutter::back(RefData **&tpl, Session* s, RefData **&l, RefData **&r){
	// если отсекается пользовательская переменная
	// если отсекается текущая цепочка
	tpl=0;
	return BACK;
	//return FAIL;
};


void RefChain::killall(){
	RefDataBracket *br = 0;
	for(RefData 
		**iter = this->first, 
		**iend=this->first+this->leng;
		iter<iend;
		++iter){
			br = ref_dynamic_cast<RefDataBracket>(*iter);
			if (br){
				br->chain->killall();
				delete br->chain;
			}
		}
};

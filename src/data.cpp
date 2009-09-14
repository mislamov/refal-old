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


RefChain::RefChain(RefData* d) {
    sysize = leng = 1;
	first = (RefData**)malloc(sizeof(RefData*) * sysize);
	first[0] = d;
};

RefChain::RefChain(size_t size) { // size is not lenght
	sysize = size;
	first = (RefData**)malloc(sizeof(RefData*) * sysize);
	leng = 0;
};


RefChain& RefChain::operator+=(RefData *ch) {

	#ifdef TESTCODE
	if (leng>sysize) SYSTEMERROR("Achtung!")
	#endif

	if (leng == sysize){
		sysize += RefChain::alloc_portion;
		first   =   (RefData**) realloc(first, sizeof(RefData*)*sysize );
		//LOG("realloc");
		if (! first) RUNTIMEERROR("membuffer", "memory limit");
	}
	first[leng] = ch;
	++leng;

    return *this;
};

// после - ch не существует!
RefChain& RefChain::operator+=(RefChain *ch) {
	sysize += ch->leng;
	first   =   (RefData**) realloc(first, sizeof(RefData*)*sysize );
	//LOG("realloc");
	if (! first) RUNTIMEERROR("membuffer", "memory limit");
	memcpy(first+leng, ch->first, sizeof(RefData*)*(ch->leng));
	leng += ch->leng;
	delete ch;
	ch = 0;
	return *this;
};

RefChain& RefChain::operator+=(RefChain ch) {
	sysize += ch.leng;
	first   =   (RefData**) realloc(first, sizeof(RefData*)*sysize );
	//LOG("realloc");
	if (! first) RUNTIMEERROR("membuffer", "memory limit");
	memcpy(first+leng, ch.first, sizeof(RefData*)*(ch.leng));
	leng += ch.leng;
	return *this;
};



RefData** RefChain::operator[](signed long idx) {
/*#ifdef TESTCODE
	if ((idx<0 && (long)leng+idx<0) || (idx>0 && idx>=leng)) 
		AchtungERROR;
#endif*/
	return	leng? ((idx<0) ? first+leng+idx : first+idx) : 0;
};





unistring RefChain::debug(){
		    unistring result = "";
			result += "[";
			result += " leng=";
			char tmp[256];
			result += ltoa( leng, tmp, 10);
			result += " size=";
			result += ltoa( sysize, tmp, 10);
			result += " ";
			//result += ltoa( RefChain::alloc_portion, tmp, 10);
			result += "] ";

			for (size_t i=0; i<leng; i++) {
				result += (first[i] ? first[i]->debug() : " \x0000 ");
			}
			return result;
};

unistring RefChain::explode(){
		    unistring result = "";

			for (size_t i=0; i<leng; i++) {
				#ifdef TESTCODE
					if (! first[i]) AchtungERROR;
				#endif
				result += first[i]->explode();
			}
			return result;
};

unistring RefStructBrackets::explode(){		return "(" + chain->explode() + ") ";	};
unistring RefExecBrackets::explode(){	return "<" + chain->explode() + "> ";	};


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
	AchtungERROR;
};
TResult RefExecBrackets::back(RefData **&tpl, Session* s, RefData **&l, RefData **&r){
	AchtungERROR;
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
			if ((*Al != *Bl) || !(**Al == **Bl)) return false;
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
	if ( ! s->getVariableValue(this->lnk, ldata, rdata) ) {
        SYSTEMERROR("INTERNAL ERROR: link to not exists variable! link = " << this->debug());
        return ERROR;
    };

//	std::cout << "\n@: " << chain_to_text(ldata, rdata) << "  ~  " << chain_to_text(r+1, r+2) << "...\n";

	if (!ldata){ // пустые
        s->MOVE_TO_next_template(tpl);
        return GO; // ссылка на пустой отрезок - верна
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

// компиляция цепочки после построения. расстановка ссылок
// ownchain - левая часть для подстановки this. Тоже компилируется
void RefChain::compile(RefChain *ownchain, RefProgram *program){
	if (isEmpty()) return;

	std::map<unistring, RefVariable*> vars;
	std::stack<RefData**> lnks;

	RefVariable *var;
	RefLinkToVariable *link;
	RefDataBracket *bracks;
	RefUserVar *uservar;
	RefUserCondition *cond;


	PooledTuple2<RefData**, RefData**> subchains;
	subchains.put((*this)[0], (*this)[-1]+1);
	if (ownchain && ownchain!=this && !ownchain->isEmpty()){
		subchains.put((*ownchain)[0], (*ownchain)[-1]+1);
	}

	while(subchains.getLength()){
		RefData 
			**end = subchains.top2(),
			**point = subchains.top1();
		subchains.pop();

		#ifdef DEBUG
		std::cout << "compile: " << chain_to_text(point, end-1) << "\n";
		#endif

		for(;
			point < end;
			++point){

			uservar = ref_dynamic_cast<RefUserVar>(*point);
			if (uservar){ // запоминаем заготовку для переменной
				if (! program) SYSTEMERROR("program not null expected");
				uservar->setTempl( program->findTemplate(uservar->getType()) );
				vars[uservar->getName()] = uservar;
				continue;
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
				subchains.put((*(bracks->chain))[0], (*(bracks->chain))[-1]+1);
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
			if (!dynamic_cast<RefLinkToVariable*>(*(lnks.top()))) AchtungERROR;
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


TResult RefUserVar::success(RefData **&tpl, Session* sess, RefData **&l, RefData **&r){
	RefData **lold, **rold;
	this->saveVarMap( sess->poptopVarMap() ); // сохраняем карту переменных
	sess->restoreVar(sess, this, lold, rold); // начало аргумента переменной
	if (rold != r){
		sess->MOVE_TO_next_term(rold);
		l = rold;
	} else {
		l = 0;	// значение переменной пустое
	}
	sess->saveVar(sess, this, l, r); // сохраняем полное значение

	tpl = (RefData**) sess->userVarJumpPoints.top_pop(); // выпрыгиваем из user-шаблона
	sess->popTmplate();


	#ifdef TESTCODE
	if (*tpl != this) AchtungERROR;
	#endif

	sess->MOVE_TO_next_template(tpl); // двигаемся дальше
	return GO;
};

TResult RefUserVar::failed (RefData **&tpl, Session* sess, RefData **&l, RefData **&r){
	delete sess->poptopVarMap();
	sess->restoreVar(sess, this, l, r);		 // забываем переменную
	tpl = (RefData**) sess->userVarJumpPoints.top_pop(); // выпрыгиваем из user-шаблона
	sess->popTmplate();
	

	#ifdef TESTCODE
	if (*tpl != this) AchtungERROR;
	#endif
	
	sess->MOVE_TO_pred_template(tpl);
	return BACK;
};


TResult RefUserVar::init(RefData **&tpl, Session* sess, RefData **&l, RefData **&r){
	#ifdef TESTCODE
	if (*tpl != this) AchtungERROR;
	if (! dynamic_cast<RefUserTemplate*>(templ)) notrealisedERROR;
	#endif

	RefUserTemplate* usertemplate = (RefUserTemplate*)templ;
	if (usertemplate->getLeftPart()->isEmpty()){
		notrealisedERROR;
		//sess->MOVE_TO_next_template(tpl);
		//return GO;
	}
	sess->saveVar(sess, this, l=0, r);
	sess->createVarMap();
	sess->userVarJumpPoints.put((RefUserVar**)tpl);
	sess->setTmplate(usertemplate->getLeftPart());
	tpl = usertemplate->getLeftPart()->at(0);
	return GO;
};

TResult RefUserVar::back(RefData **&tpl, Session* sess, RefData **&l, RefData **&r){
	#ifdef TESTCODE
	if (*tpl != this) AchtungERROR;
	#endif
	sess->userVarJumpPoints.put((RefUserVar**)tpl);
	sess->setTmplate(((RefUserTemplate*)templ)->getLeftPart());
	sess->putVarMap( this->restoreVarMap() );

	tpl = ((RefUserTemplate*)templ)->getLeftPart()->at(-1);
	return BACK;
};

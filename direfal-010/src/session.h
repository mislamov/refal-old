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

#ifndef SESSION_H_INCLUDED
#define SESSION_H_INCLUDED

#include <sstream>
#include <stack>

#include "data.h"
#include "function.h"
#include "poolTuples.h"

class VarMap : public PooledTuple3<RefVariable*, RefData** , RefData**>{
	VarMap(const VarMap&){ AchtungERROR; };  // неконтроллируемое копирование нам не нужно
public:
	VarMap(void *own = 0) {        pool[0].i1 = (RefVariable*)own;    };

    // ищет по имени переменной ее облать видимости
    bool findByName(unistring name, RefData** &l, RefData** &r);

	// ищет по ссылке на переменную ее облать видимости
	bool findByLink(RefVariable* var, RefData** &l, RefData** &r);

	unistring debug();
};


struct SessionStatePoint {
	size_t conditionsArgsCount;
};

// среда для вычисления пользовательской функции
class Session {
    TResult  result_sost;
	RefProgram *program;

	PooledTuple2 <RefData**, RefData**>  current_view_borders; // крайние view-элементы активного аргумента [для скобок]
	//PooledTuple2 <RefData**, RefData**> deferred_view_borders; // отложенные (успешные) view границы - для откатов [для скобок, usertype-переменных]
	//PooledTuple4 <RefData**, RefData**, RefData**, RefData**>  current_templ_borders; // активные view границы [для скобок] + точки выхода
	//PooledTuple2 <RefData**, RefData**> deferred_templ_borders; // отложенные (успешные) view границы - для откатов [для скобок, usertype-переменных]
	PooledTuple2 <RefConditionBase*, RefChain*> conditionsArgs;

	PooledStack<VarMap*>  varMapStack; // карты переменных
	PooledTuple2<RefStructBrackets*, RefStructBrackets**> bracks; // сопоставленные со скобками
	PooledStack<RefChain *> currentTemplates;
private:
	inline Session(){};
public:
	PooledStack<RefUserVar**> userVarJumpPoints;

	inline Session(RefProgram *p){ program = p; }; 
	inline RefProgram *getProgram(){ return program; };
	inline void createVarMap(){ varMapStack.put(new VarMap()); };
	inline VarMap* poptopVarMap(){ return varMapStack.top_pop(); };
	inline void putVarMap(VarMap* vm){ varMapStack.put(vm); };

	inline RefChain* tmplate(){ return currentTemplates.top(); };
	inline void setTmplate(RefChain *t){ currentTemplates.put(t); };
	inline void popTmplate(){ currentTemplates.top_pop(); };

	inline RefData** current_view_l(){ return current_view_borders.top1(); };
	inline RefData** current_view_r(){ return current_view_borders.top2(); };
	//inline RefData** current_templ_l(){ return current_templ_borders.top1(); };
	//inline RefData** current_templ_r(){ return current_templ_borders.top2(); };
	inline void saveConditionArg(RefConditionBase* cnd, RefChain *arg){ conditionsArgs.put(cnd,	arg); };
	inline RefChain* restoreConditionArg(RefConditionBase* cnd){ 
		RefConditionBase* cnd0; 
		RefChain *res; 
		conditionsArgs.top_pop(cnd0, res); 
		#ifdef TESTCODE
		if (cnd!=cnd0) AchtungERROR;
		#endif
		return res;
	};

	SessionStatePoint* getState(){ 
		SessionStatePoint *ss = new SessionStatePoint(); 
		ss->conditionsArgsCount=conditionsArgs.getLength(); 
		return ss; 
	};
	void backToState(SessionStatePoint* ss){
		#ifdef TESTCODE
		if (ss->conditionsArgsCount > conditionsArgs.getLength()) AchtungERROR;
		#endif
		// заглушка
		for(size_t i=conditionsArgs.getLength(); i!=ss->conditionsArgsCount; --i){
			conditionsArgs.pop();  //TODO: собрать тут мусор! нужен не просто pop, а delete, delete, pop
		}
	};

	// сопоставление образца tmplate с аргументом l..r
    bool  matching(RefObject *initer, RefChain *tmplate, RefData **arg_l, RefData **arg_r, bool isdemaching);

	// готовит подстановку: заменяет переменные значениями. Получаем ОВ с угловыми скобками
    RefChain*  substituteExpression(RefChainConstructor *);

	void SAVE_VAR_STATE   (RefData** activeTemplate, RefData** &l, RefData** &r); // сохраняет состояние переменной
	void RESTORE_VAR_STATE(RefData** activeTemplate, RefData** &l, RefData** &r); // восстанавливает состояние переменной

	inline void saveVar    (Session *s, RefVariable *varOrData, RefData **&l, RefData **&r);
    inline void restoreVar (Session *s, RefVariable *varOrData, RefData **&l, RefData **&r);
	inline bool findVar    (RefVariable *var, RefData **&l, RefData **&r);
	inline bool getVariableValue(RefVariable*, RefData**&, RefData**&);

	void saveBracketsFromView(RefStructBrackets* tpl, RefStructBrackets** br){
		bracks.put(tpl, br);
	};
	RefStructBrackets** restoreBracketsFromView(RefStructBrackets* tpl){
		RefStructBrackets **br  = 0;
		RefStructBrackets* tpl2 = 0;
		bracks.top_pop(tpl2, br);
		#ifdef TESTCODE
		if (tpl2 != tpl) 
			AchtungERROR;
		#endif
		return br;
	};

	unistring debug();

	inline RefData** GET_next_term (RefData** p);
	inline RefData** GET_pred_term (RefData** p);
	inline RefData** GET_next_template (RefData** p);
	inline RefData** GET_pred_template (RefData** p);
	inline void MOVE_TO_next_term (RefData** &p){ p=GET_next_term(p); };
	inline void MOVE_TO_pred_term (RefData** &p){ p=GET_pred_term(p); };
	inline void MOVE_TO_next_template (RefData** &p){ p=GET_next_template(p); };
	inline void MOVE_TO_pred_template (RefData** &p){ p=GET_pred_template(p); };

	//inline void setNewView(); - должно передаваться в аргументе matching'а
	//inline void setNewTempl(RefChain* ch);
};


inline void Session::saveVar(Session *s, RefVariable *varOrData, RefData **&l, RefData **&r) {
	varMapStack.top()->put(varOrData, l, r);
};

inline void Session::restoreVar(Session *s, RefVariable *varOrData, RefData **&l, RefData **&r) {
    varMapStack.top()->top_pop(varOrData, l, r);
};

inline bool Session::findVar(RefVariable *var, RefData **&l, RefData **&r) {
	return varMapStack.top()->findByLink(var, l, r);
};

/*
inline void Session::JUMP_View (RefChain* ch, RefData** outL, RefData** outR){		// прыгаем в подцепочку данных (скобка)
	if (ch->isEmpty()){
		current_view_borders.put(0, 0, outL, outR);
		return;
	}
	current_view_borders.put((*ch)[0], (*ch)[-1], outL, outR);
};


inline void Session::JUMP_Template (RefChain* tp, RefData** outL, RefData** outR){	// прыгаем в подшаблон (скобка/usertype-переменная)
	if (tp->isEmpty()){
		current_templ_borders.put(0, 0, outL, outR);
		return;
	}
	current_templ_borders.put((*tp)[0], (*tp)[-1], outL, outR);
};
*/

inline RefData** Session::GET_next_term(RefData** p){
	if (p == current_view_r() || !p) {
		return 0;
	}
	return p+1;
};

inline RefData** Session::GET_pred_term(RefData** p){
	if (p == current_view_l() || !p) {
		return 0;
	}
	return p-1;
};

inline RefData** Session::GET_next_template(RefData** p){
	if (tmplate()->at(-1) == p) {
		return 0;
	}
	return p+1;
};
inline RefData** Session::GET_pred_template(RefData** p){
	if (tmplate()->at(0) == p) {
		return 0;
	}
	return p-1;
};


inline bool Session::getVariableValue(RefVariable* var, RefData** &l, RefData** &r){
	#ifdef TESTCODE
	if (!var) 
		AchtungERROR;
	#endif
	return findVar(var, l, r);
};


#endif

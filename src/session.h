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

#ifndef SESSION_H_INCLUDED
#define SESSION_H_INCLUDED

#include <sstream>
#include <stack>

#include "data.h"
#include "function.h"
#include "poolTuples.h"

class VarMap : public PooledTuple4<RefVariable*, RefData** , RefData**, VarMap*>{
	RefObject *creator;
	VarMap(const VarMap&){ AchtungERRORn; };  // неконтроллируемое копирование нам не нужно
public:
	VarMap(RefObject *cr = 0) {	creator = cr;};

    // ищет по имени переменной ее облать видимости
    bool findByName(unistring name, RefData** &l, RefData** &r, VarMap*&);
	// ищет по ссылке на переменную ее облать видимости
	bool findByLink(RefVariable* var, RefData** &l, RefData** &r, VarMap*&);
	// ищет по текстовому пути
	bool folowByWay(unistring path, RefData** &l, RefData** &r);

	unistring debug();
};


struct SessionStatePoint {
	size_t conditionsArgsCount;
	VarMap* topVarMap;
	size_t topVarMap_leng;
	RefChain *currentTemplateTop;		// не должен измениться после матчинга
	RefData** termChainsJumpPointsTop;	// не должен измениться после матчинга
	size_t count_variants_idxs;		// не должен измениться после матчинга
	size_t count_variants_idxs_done;
	size_t count_repeats_idxs;	// не должен измениться после матчинга
	size_t count_repeats_idxs_done;
};

// среда для вычисления пользовательской функции
class Session {
    TResult  result_sost;
	RefProgram *program;

	PooledStack<VarMap*>  varMapStack; // карты переменных
	PooledTuple2<RefStructBrackets*, RefStructBrackets**> bracks; // сопоставленные со скобками
	PooledStack<RefChain *> currentTemplates;
	inline Session(){
		gc_first = gc_last = new RefDataNull();
	};


	PooledTuple2 <RefData**, RefData**>  current_view_borders; // крайние view-элементы активного аргумента [для скобок]
public:
	PooledTuple2 <RefConditionBase*, RefChain*> conditionsArgs;
	RefData *gc_last,  // ссылка на последний созданный дата-элемент. служит для построения пути для сборщика мусора
			*gc_first; // ссылка на первый созданный элемент

public:
	inline Session(RefProgram *p){
				gc_first = gc_last = new RefDataNull();
				program = p;
	};
	PooledStack<RefData**> termChainsJumpPoints;
	PooledTuple3<RefFunctionBase*, RefData**, RefData**> execTrace;
	PooledStack<long> variants_idxs;
	PooledStack<long> variants_idxs_done;
	PooledStack<infint> repeats_idxs;
	PooledStack<infint> repeats_idxs_done;
	inline RefProgram *getProgram(){ return program; };
	inline void createVarMap(RefObject *creator){ varMapStack.put(new VarMap(creator)); };
	inline VarMap* currentMapStack(){ return varMapStack.top(); };
	inline VarMap* preCurrentMapStack(){ return varMapStack.pretop(); };
	inline VarMap* poptopVarMap(){ return varMapStack.top_pop(); };
	inline void putVarMap(VarMap* vm){ varMapStack.put(vm); };

	inline RefChain* tmplate(){ return currentTemplates.top(); };
	inline void setTmplate(RefChain *t){ currentTemplates.put(t); };
	//inline RefChain* poptopTmplate(){ return currentTemplates.top_pop(); };
	inline void popTmplate(){ currentTemplates.pop(); };

	inline RefData** current_view_l(){ return current_view_borders.top1(); };
	inline RefData** current_view_r(){ return current_view_borders.top2(); };
	inline void save_current_view_borders(RefData** from, RefData** to){ current_view_borders.put(from, to); };
	inline void delete_current_view_borders(){ current_view_borders.pop(); };
	//inline RefData** current_templ_l(){ return current_templ_borders.top1(); };
	//inline RefData** current_templ_r(){ return current_templ_borders.top2(); };
	inline void saveConditionArg(RefConditionBase* cnd, RefChain *arg){ conditionsArgs.put(cnd,	arg); };
	inline RefChain* restoreConditionArg(RefConditionBase* cnd){
		RefConditionBase* cnd0;
		RefChain *res;
		conditionsArgs.top_pop(cnd0, res);
		#ifdef TESTCODE
		if (cnd!=cnd0) AchtungERRORs(this);
		#endif
		return res;
	};

	SessionStatePoint* getState(){
		SessionStatePoint *ss = new SessionStatePoint();
		ss->conditionsArgsCount = conditionsArgs.getLength();
		ss->topVarMap = currentMapStack();
		ss->topVarMap_leng = ss->topVarMap->getLength();
		ss->count_variants_idxs_done = variants_idxs_done.getLength();
		ss->count_repeats_idxs_done  = repeats_idxs_done.getLength();

		#ifdef TESTCODE
		ss->currentTemplateTop		= currentTemplates.empty()?0:currentTemplates.top();		// не должен измениться после матчинга
		ss->termChainsJumpPointsTop	= termChainsJumpPoints.empty()?0:termChainsJumpPoints.top();	// не должен измениться после матчинга
		ss->count_variants_idxs		= variants_idxs.getLength();			// не должен измениться после матчинга
		ss->count_repeats_idxs		= repeats_idxs.getLength();			// не должен измениться после матчинга
		#endif
		return ss;
	};

	void backToState(SessionStatePoint* ss){
		#ifdef TESTCODE
		if (ss->conditionsArgsCount > conditionsArgs.getLength()) AchtungERRORs(this);
		#endif

		conditionsArgs.setLength(ss->conditionsArgsCount);
		while(ss->topVarMap != varMapStack.top()){
			std::cout << "\nddddddddddddddddddddddddddddddddddddddddddelete varMapStack.top_pop():\n";
			varMapStack.top()->debug();
			delete varMapStack.top_pop();
			#ifdef TESTCODE
			if (varMapStack.empty()) {unexpectedERRORn;};
			#endif
		}
		ss->topVarMap->setLength( ss->topVarMap_leng );
		variants_idxs_done.setLength(ss->count_variants_idxs_done);
		repeats_idxs_done.setLength (ss->count_repeats_idxs_done);

		#ifdef TESTCODE
		if (ss->currentTemplateTop && ss->currentTemplateTop		!= currentTemplates.top()) SYSTEMERRORs(this, "unexpected  changes in SessionState");		// не должен измениться после матчинга
		if (ss->termChainsJumpPointsTop	 &&   ss->termChainsJumpPointsTop	!= termChainsJumpPoints.top()) SYSTEMERRORs(this, "unexpected  changes in SessionState");	// не должен измениться после матчинга
		if (!ss->currentTemplateTop      &&  !currentTemplates.empty()) SYSTEMERRORs(this, "unexpected  changes in SessionState");		// не должен измениться после матчинга
		if (!ss->termChainsJumpPointsTop &&  !termChainsJumpPoints.empty()) SYSTEMERRORs(this, "unexpected  changes in SessionState");	// не должен измениться после матчинга
		if (ss->count_variants_idxs		!= variants_idxs.getLength()) SYSTEMERRORs(this, "unexpected  changes in SessionState");			// не должен измениться после матчинга
		if (ss->count_repeats_idxs		!= repeats_idxs.getLength()) SYSTEMERRORs(this, "unexpected  changes in SessionState");			// не должен измениться после матчинга
		#endif

	};

	// сопоставление образца tmplate с аргументом l..r
    bool  matching(RefObject *initer, RefChain *tmplate, RefData **arg_l, RefData **arg_r, bool isdemaching);

	// готовит подстановку: заменяет переменные значениями. Получаем ОВ с угловыми скобками
    RefChain*  substituteExpression(RefChain *);

	//void SAVE_VAR_STATE   (RefData** activeTemplate, RefData** &l, RefData** &r); // сохраняет состояние переменной
	//void RESTORE_VAR_STATE(RefData** activeTemplate, RefData** &l, RefData** &r); // восстанавливает состояние переменной

	inline void saveVar    (RefVariable *var, RefData **l, RefData **r, VarMap* =0);
    inline void restoreVar (RefVariable *var, RefData **&l, RefData **&r);
    inline void restoreVar (RefVariable *var, RefData **&l, RefData **&r, VarMap*&);
	inline bool findVar    (RefVariable *var, RefData **&l, RefData **&r);
	inline bool findVar    (RefVariable *var, RefData **&l, RefData **&r, VarMap*&);

	void saveBracketsFromView(RefStructBrackets* tpl, RefStructBrackets** br){
		bracks.put(tpl, br);
	};
	RefStructBrackets** restoreBracketsFromView(RefStructBrackets* tpl){
		RefStructBrackets **br  = 0;
		RefStructBrackets* tpl2 = 0;
		bracks.top_pop(tpl2, br);
		#ifdef TESTCODE
		if (tpl2 != tpl)
			AchtungERRORs(this);
		#endif
		return br;
	};

	unistring debug();
	void printExecTrace();

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

	void gc_prepare(RefData *save_point=0); // подготовка к сборке мусора
	inline void gc_exclude(RefData *data);         // исключение точки из удаления
	void gc_exclude(RefChain *chain);              // исключение цепочки из удаления
	void gc_clean(RefData* save_point=0);          // сборка мусора
};

inline void Session::saveVar(RefVariable *var, RefData **l, RefData **r, VarMap* vm) {
//std::cout << "Session::saveVar(for " << var->toString() << ")\n";
	varMapStack.top()->put(var, l, r, vm);
};

inline void Session::restoreVar(RefVariable *var, RefData **&l, RefData **&r, VarMap* &vm) {
//std::cout << "Session::restoreVar(for " << var->toString() << ")\n";
	RefVariable *varNew = 0;
	varMapStack.top()->top_pop(varNew, l, r, vm);

	ref_assert( var == varNew );

	/*#ifdef TESTCODE
	if (var != varNew){
		SYSTEMERRORs(this, "restoreVar: tring " << (var?var->toString():"$0000")  << "  when  " << varNew->toString() << " expect!");
		//AchtungERRORs(this);
	}
	#endif*/
};
inline void Session::restoreVar(RefVariable *var, RefData **&l, RefData **&r) {
//std::cout << "Session::restoreVar(for " << var->toString() << ")\n";
	RefVariable *varNew = 0;
	VarMap* vm = 0;
	varMapStack.top()->top_pop(varNew, l, r, vm);

	ref_assert((var == varNew) && !vm);

	/*#ifdef TESTCODE
	if (var != varNew){
		SYSTEMERRORs(this, "restoreVar: tring " << (var?var->toString():"$0000")  << "  when  " << varNew->toString() << " expect!");
	}
	if (vm) {
		unexpectedERRORs(this);
	}
	#endif*/
};

inline bool Session::findVar(RefVariable *var, RefData **&l, RefData **&r, VarMap* &vm) {
	return varMapStack.top()->findByLink(var, l, r, vm);
};
inline bool Session::findVar(RefVariable *var, RefData **&l, RefData **&r) {
	VarMap* vm = 0;
	#ifdef TESTCODE
		bool res = varMapStack.top()->findByLink(var, l, r, vm);
		if (vm) {
			unexpectedERRORs(this);
		}
		return res;
	#else
		return varMapStack.top()->findByLink(var, l, r, vm);
	#endif
};


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
	if (tmplate()->at_last() == p) {
		return 0;
	}
	return p+1;
};
inline RefData** Session::GET_pred_template(RefData** p){
	if (tmplate()->at_first() == p) {
		return 0;
	}
	return p-1;
};

inline void Session::gc_exclude(RefData *data){
		data->set_gc_mark();
		if ((data)->isDataBracket()){
			RefDataBracket *br = (RefDataBracket*)data;
			gc_exclude( br->chain );
		}
};


#endif

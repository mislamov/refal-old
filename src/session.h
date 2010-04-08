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

class VarMap : public PooledTuple5<RefVariable*, RefData** , RefData**, VarMap*, RefChain*>, public RefData {
	RefObject *creator;
	VarMap(const VarMap&){ AchtungERRORn; };  // неконтроллируемое копирование нам не нужно
	~VarMap(){}; // найти удаление и заменить на коллекционирование. вармап может сохраниться в реф-указателе - поэтому удалять нельзя!
public:
	VarMap(Session *sess, RefObject *cr = 0) : RefData(sess) {	creator = cr;};

    // ищет по имени переменной ее облать видимости
    bool findByName(unistring name, RefData** &l, RefData** &r, RefChain* &lr_own, VarMap*&, RefVariable* &var);
	// ищет по ссылке на переменную ее облать видимости
	bool findByLink(RefVariable* var, RefData** &l, RefData** &r, RefChain* &lr_own, VarMap*&);
	// ищет по текстовому пути
	bool folowByWay(unistring path, RefData** &l, RefData** &r, RefChain* &lr_own, RefVariable *&var, VarMap* &);
	/*inline bool VarMap::folowByWay(unistring path, RefData** &l, RefData** &r, RefChain* &lr_own){
		RefVariable *vr;
		return folowByWay(path, l, r, lr_own, vr);
	}*/

	char gc_label;//todo:bitmap
	void mrk_collect(); // отмечает содержимое для сохранения сборщиком

	unistring debug();
	unistring RefData::explode(void){ return debug(); };
	TResult init(RefData **&, Session* sess, RefData **&, RefData **&, RefChain *&){unexpectedERRORn; };
    TResult back(RefData **&, Session* sess, RefData **&, RefData **&, RefChain *&){unexpectedERRORn; };

	bool createdByFigureBrackets(){ 
		return ref_dynamic_cast<RefVarChains>(creator) || ref_dynamic_cast<RefVariantsChains>(creator); };
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


	PooledTuple3 <RefData**, RefData**, RefChain*>  current_view_borders; // крайние view-элементы активного аргумента [для скобок] и их содержащая цепочка
public:
	PooledTuple2 <RefConditionBase*, RefChain*> conditionsArgs;
	RefData *gc_last,  // ссылка на последний созданный дата-элемент. служит для построения пути для сборщика мусора
			*gc_first; // ссылка на первый созданный элемент
	RefData** alt_r;

public:
	inline Session(RefProgram *p){
		alt_r = 0;
		gc_first = gc_last = new RefDataNull();
		program = p;
	};
	PooledStack<RefData**> termChainsJumpPoints;
	PooledTuple4<RefFunctionBase*, RefData**, RefData**, RefChain*> execTrace;
	PooledStack<long> variants_idxs;
	PooledStack<long> variants_idxs_done;
	PooledStack<infint> repeats_idxs;
	PooledStack<infint> repeats_idxs_done;
	inline RefProgram *getProgram(){ return program; };
	inline void createVarMap(RefObject *creator){ varMapStack.put(new VarMap(this, creator)); };
	inline VarMap* currentMapStack(){ return varMapStack.top(); };
	inline VarMap* preCurrentMapStack(){ return varMapStack.pretop(); };
	inline VarMap* poptopVarMap(){ return varMapStack.top_pop(); };
	inline void putVarMap(VarMap* vm){ varMapStack.put(vm); };

	inline RefChain* tmplate(){ return currentTemplates.top(); };
	inline void setTmplate(RefChain *t){ currentTemplates.put(t); };
	//inline RefChain* poptopTmplate(){ return currentTemplates.top_pop(); };
	inline void popTmplate(){ currentTemplates.pop(); };

	inline RefData** current_view_l()       { return current_view_borders.top1(); };
	inline RefData** current_view_r()       { return current_view_borders.top2(); };
	inline RefChain* current_view_lr_own(){ return current_view_borders.top3(); };
	inline void save_current_view_borders(RefData** from, RefData** to, RefChain* own){ current_view_borders.put(from, to, own); };
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
			//std::cout << "\nddddddddddddddddddddddddddddddddddddddddddelete varMapStack.top_pop():\n";
			varMapStack.top()->debug();
			//delete varMapStack.top_pop(); - нельзя. только сборщиком
			varMapStack.top_pop();
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
	bool  matching(RefObject *initer, RefChain *tmplate, RefData **arg_l, RefData **arg_r, RefChain *arg_chain, bool isdemaching);

	// готовит подстановку: заменяет переменные значениями. Получаем ОВ с угловыми скобками
    RefChain*  substituteExpression(RefChain *);

	//void SAVE_VAR_STATE   (RefData** activeTemplate, RefData** &l, RefData** &r); // сохраняет состояние переменной
	//void RESTORE_VAR_STATE(RefData** activeTemplate, RefData** &l, RefData** &r); // восстанавливает состояние переменной

	inline void saveVar    (RefVariable *var, RefData **l,  RefData **r,  RefChain*, VarMap* =0);
    inline void restoreVar (RefVariable *var, RefData **&l, RefData **&r, RefChain*&);
    inline void restoreVar (RefVariable *var, RefData **&l, RefData **&r, RefChain*&, VarMap*&);
    inline void forgotVar  (RefVariable *var);
	inline bool findVar    (RefVariable *var, RefData **&l, RefData **&r, RefChain*&);
	inline bool findVar    (RefVariable *var, RefData **&l, RefData **&r, RefChain*&, VarMap*&);

	void saveBracketsFromView(RefStructBrackets* tpl, RefStructBrackets** br){
		bracks.put(tpl, br);
	};
	RefStructBrackets** restoreBracketsFromView(RefStructBrackets* tpl){
		RefStructBrackets **br  = 0;
		RefStructBrackets* tpl2 = 0;
		bracks.top_pop(tpl2, br);
		#ifdef TESTCODE
		if (tpl2 != tpl){
			SYSTEMERRORs(this, tpl2->debug() << "  !=  " << tpl->explode());
		}
		#endif
		return br;
	};

	unistring debug();
	void printExecTrace();

	inline RefData** GET_next_term (RefData** p);
	inline RefData** GET_pred_term (RefData** p);
	inline RefData** GET_next_template (RefData** p);
	inline RefData** GET_pred_template (RefData** p);
	//todo: обязательно переделать определение границ не через 0!!! иначе не поянтно, какая из границ достигнута
	inline void MOVE_TO_next_term (RefData** &p){ p=GET_next_term(p); };
	inline void MOVE_TO_pred_term (RefData** &p){ p=GET_pred_term(p); };
	inline void MOVE_TO_next_template (RefData** &p){ p=GET_next_template(p); };
	inline void MOVE_TO_pred_template (RefData** &p){ p=GET_pred_template(p); };

	//inline void setNewView(); - должно передаваться в аргументе matching'а
	//inline void setNewTempl(RefChain* ch);

	void gc_prepare(RefData *save_point=0); // подготовка к сборке мусора
	inline void gc_exclude(RefData *data);         // исключение точки из удаления
	void gc_exclude(RefChain *chain);              // исключение цепочки из удаления
	void gc_exclude(RefData **, RefData **, RefChain*);
	void gc_clean(RefData* save_point=0);          // сборка мусора
};

inline void Session::saveVar(RefVariable *var, RefData **l, RefData **r, RefChain *lr_own, VarMap* vm) {
//std::cout << "Session::saveVar(for " << var->toString() << ")\n";
	varMapStack.top()->put(var, l, r, vm, lr_own);
};

inline void Session::restoreVar(RefVariable *var, RefData **&l, RefData **&r, RefChain *&lr_own, VarMap* &vm) {
//std::cout << "Session::restoreVar(for " << var->toString() << ")\n";
	RefVariable *varNew = 0;
	varMapStack.top()->top_pop(varNew, l, r, vm, lr_own);

	ref_assert( var == varNew );
};

inline void Session::restoreVar(RefVariable *var, RefData **&l, RefData **&r, RefChain *&lr_own) {
//std::cout << "Session::restoreVar(for " << var->toString() << ")\n";
	RefVariable *varNew = 0;
	VarMap* vm = 0;
	varMapStack.top()->top_pop(varNew, l, r, vm, lr_own);

	ref_assert((var == varNew) && !vm);

};

inline bool Session::findVar(RefVariable *var, RefData **&l, RefData **&r, RefChain*&lr_own, VarMap* &vm) {	
	if (varMapStack.top()->findByLink(var, l, r, lr_own, vm)) return true;
	
	// если переменная не найдена, то возможно это не ошибка, а ссылка внутри фигурных скобок (группы илил вариантов),
	// для которых в стак были созданы новые вармапы	
	for(
		size_t idx = varMapStack.getCount()-1;
		idx;
		--idx){
			vm = varMapStack.getByIndex(idx);
			if (vm->createdByFigureBrackets()){
				if (vm->findByLink(var, l, r, lr_own, vm)) return true;
			} else {
				return false;
			}
	}
	return false;
};
inline void Session::forgotVar(RefVariable *var) {
//std::cout << "Session::forgotVar(for " << var->toString() << ")\n";
	ref_assert(varMapStack.top()->top1()==var);
	varMapStack.top()->pop();
};
inline bool Session::findVar(RefVariable *var, RefData **&l, RefData **&r, RefChain*&lr_own) {
	VarMap* vm = 0;
	#ifdef TESTCODE
		bool res = varMapStack.top()->findByLink(var, l, r, lr_own, vm);
		if (vm) {
			unexpectedERRORs(this);
		}
		return res;
	#else
		return varMapStack.top()->findByLink(var, l, r, lr_own, vm);
	#endif
};


inline RefData** Session::GET_next_term(RefData** p){
	if (p == current_view_r() || !p) {
		alt_r = p+1;
		return 0;
	}
	return p+1;
};

inline RefData** Session::GET_pred_term(RefData** p){
	if (p == current_view_l() || !p) {
		alt_r = p-1;
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

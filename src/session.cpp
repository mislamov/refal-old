#include "session.h"

#include "function.h"
#include "program.h"

#ifdef DEBUG
#define LOGSTEP(s) \
	std::cout << (int)r << "\t" << variants_idxs.getCount()<< " "<< s << " | " << ((activeTemplate && *activeTemplate) ? (*activeTemplate)->debug():"null") << "\t\t~\t\t" << std::flush << (s=="BACK"?"":chain_to_text(r?r+1:0, arg_l?arg_r:0, 50)) << "\n" << std::flush;
#define LOGMATCH() \
	std::cout << "\n\n"<< co::objs<<" STEP: "<< ++(program->step) <<"\n###### maps:" << varMapStack.getCount() << "\n" << (isdemaching?"DMTCH|":"START| ") << (thetmplate && !thetmplate->isEmpty() ? thetmplate->debug() : "$empty") << "\t\t~\t\t" << std::flush << (!arg_l?" $empty":chain_to_text(arg_l, arg_r, 50)) << "\n" << std::flush;
#else
#define LOGSTEP(s)
#define LOGMATCH()
#endif




// сопоставляет образец tmplate с объектным выражением arg.
// isdemaching - признак того, что надо продолжить матчинг от предыдущего удачного состояния (напр в цепочке условий)
// ТОЛЬКО ДЛЯ ЦЕЛОГО ОБРАЗЦА В ПРЕДЛ. ИЛИ УСЛОВИИ
// Политика управления varMapб current_LR задается из вне.
// TODO: подумать над возможностью пердавать 2 chain в аргументах, а не 1 chain и 2 dot.
bool  Session::matching(RefObject *initer, RefChain *thetmplate, RefData **arg_l, RefData **arg_r, RefChain *arg_chain, bool isdemaching) {
#ifdef TESTCODE
	if (! varMapStack.getCount()) SYSTEMERRORs(this, "createVarMap() wanted! No varmaps in stack for matching");
#endif

	RefChain *lr_chain = arg_chain;
	//std::cout << thetmplate->debug() << "\n\t\t~  " << chain_to_text(arg_l, arg_r) << "\n" << std::flush;
	//LOG("New MATCHING : tmplateChain=" << thetmplate->debug() << "  isDematching="<<isdemaching);
    RefData **activeTemplate = 0, **l=0, **r=0;

    if (isdemaching) {
        // продолжаем ранее успешное сопоставление
		if (thetmplate->isEmpty()) return false; // дематчинг пустых векторов - неудача
        result_sost = BACK;
		activeTemplate = (*thetmplate)[-1];
		current_view_borders.put(arg_l, (!arg_l ? 0 : arg_r), lr_chain);
    } else {
        // начинаем новое сопоставление с argl..argr
		if (thetmplate->isEmpty()) return !arg_l; // дематчинг пустых векторов - неудача
        result_sost = GO;
		l = 0;
		r = arg_l ? arg_l-1 : 0;
        activeTemplate = (*thetmplate)[0];
		current_view_borders.put(arg_l, (!arg_l ? 0 : arg_r), lr_chain);
    }

	this->setTmplate(thetmplate);
	//LOGMATCH();
	//std::cout << "\n\n"<< co::objs<<" STEP: "<< ++(program->step) <<"\n###### maps:" << varMapStack.getCount() << "\n" << (isdemaching?"DMTCH|":"START| ") << (thetmplate && !thetmplate->isEmpty() ? thetmplate->debug() : "$empty") << "\t\t~\t\t" << std::flush << (!arg_l?" $empty":chain_to_text(arg_l, arg_r, 50)) << "\n" << std::flush;

	bool ireturn = false;

	while (! ireturn) {
        // сопоставляем текущий шаблон
        switch (result_sost) {

        case GO: {
			if (!activeTemplate || activeTemplate == tmplate()->at_afterlast()){ // достигнут правый край сопоставления! DataDOT
				activeTemplate = 0;
				//TODO: привести все методы к одному условию
				if (this->tmplate()!=thetmplate){ // завершилось сопоставление user-шаблона
					#ifdef TESTCODE
						if (! termChainsJumpPoints.getLength()) AchtungERRORs(this);
					#endif
					#ifdef DEBUG
						std::cout << "SUCCESS JUMP " << (* termChainsJumpPoints.top())->explode() << "\n";
					#endif
					RefVarChains* var1 = ref_dynamic_cast<RefVarChains>(* termChainsJumpPoints.top());

					if (var1) {
						result_sost = var1->success(activeTemplate, this, l, r, lr_chain);
					} else {
						RefVariantsChains* var2 = ref_dynamic_cast<RefVariantsChains>(* termChainsJumpPoints.top());
						if (var2){
							result_sost = var2->success(activeTemplate, this, l, r, lr_chain);
						} else {
							RefRepeaterChain* var3 = ref_dynamic_cast<RefRepeaterChain>(* termChainsJumpPoints.top());
							result_sost = var3->success(activeTemplate, this, l, r, lr_chain);
						}
					}
					break;
				}
				activeTemplate = activeTemplate ? GET_pred_template(activeTemplate) : tmplate()->at_last();  // когда шаблон исчерпан, а аргумент еще нет - ошибка
				result_sost = (r==arg_r) ? SUCCESS : BACK;  // не двигали r вперед => сравниваем с (*arg)[-1]
				break;
			}
            LOGSTEP("GO  ");
            #ifdef TESTCODE
            if (l && !r) {
				SYSTEMERRORs(this, "RefData::init() tring to matching with NULL address!");
			};
            #endif
            l=0;
			//ref_assert(r);
            result_sost = (*activeTemplate)->init(activeTemplate, this, l, r, lr_chain); /// ШАГ ВПЕРЕД
            break;
        }
        case BACK: {
			//if (activeTemplate== this->tmplate()->at_first()-1){ // достигнут левый край сопоставления! DataDOT
			if (!activeTemplate || activeTemplate== this->tmplate()->at_first()-1){ // достигнут левый край сопоставления! DataDOT
				activeTemplate = 0;
				//TODO: привести все методы к одному условию
				if (this->tmplate()!=thetmplate){ // завершилось сопоставление user-шаблона
					#ifdef TESTCODE
						if (! termChainsJumpPoints.getLength()) AchtungERRORs(this);
					#endif
					#ifdef DEBUG
						std::cout << "FAIL JUMP " << (* termChainsJumpPoints.top())->explode() << "\n";
					#endif
					RefVarChains* var1 = ref_dynamic_cast<RefVarChains>(* termChainsJumpPoints.top());
					if (var1){
						result_sost = var1->failed(activeTemplate, this, l, r, lr_chain);
					}else{
						RefVariantsChains* var2 = ref_dynamic_cast<RefVariantsChains>(* termChainsJumpPoints.top());
						if (var2){
							result_sost = var2->failed(activeTemplate, this, l, r, lr_chain);
						} else {
							RefRepeaterChain* var3 = ref_dynamic_cast<RefRepeaterChain>(* termChainsJumpPoints.top());
							result_sost = var3->failed(activeTemplate, this, l, r, lr_chain);
						}
					}
					break;
				}
				//activeTemplate = activeTemplate ? GET_next_template(activeTemplate) : tmplate()->at_first();  // когда шаблон исчерпан, а аргумент еще нет - ошибка
				result_sost = FAIL;
				break;
			}
            LOGSTEP("BACK");
            result_sost = (*activeTemplate)->back(activeTemplate, this, l, r, lr_chain); /// ШАГ НАЗАД
            break;
        }

        case SUCCESS :
            #ifdef DEBUG
			std::cout << "SUCCESS\n######\n";
            #endif
			ireturn = true;
			break;

        case ERROR :
            #ifdef DEBUG
			std::cout << "ERROR\n######\n";
            #endif
			ireturn = true;
			break;
        case FAIL   :
            #ifdef DEBUG
			std::cout << "FAIL\n######\n";
            #endif
			ireturn = true;
			break;

        default:
			SYSTEMERRORs(this, "Unexpected result_sost value");
            break;
        }
    };


	current_view_borders.pop();
	popTmplate();
	return (result_sost==SUCCESS);
};

#ifdef TESTCODE
unistring Session::debug(){
		std::ostringstream s;

		s << "variants_idxs: ";
		for(size_t i=0; i<variants_idxs.getCount(); ++i){
			s << variants_idxs.getByIndex(i) << " ";
		}
		s << "\n";
		s << "variants_idxs_done: ";
		for(size_t i=0; i<variants_idxs_done.getCount(); ++i){
			s << variants_idxs_done.getByIndex(i) << " ";
		}
		s << "\n";

		for (int i=varMapStack.getCount()-1; i>=0; --i){
			s << "--------------------------------------- " << i+1 << "\n";
			s << varMapStack.pool[i]->debug();
		}

	return s.str();
};
#else
unistring Session::debug(){
		std::ostringstream s;

		s << "vvvvariants_idxs: ";
		for(size_t i=0; i<variants_idxs.getCount(); ++i){
			s << variants_idxs.getByIndex(i) << " ";
		}
		s << "\n";
		s << "variants_idxs_done: ";
		for(size_t i=0; i<variants_idxs_done.getCount(); ++i){
			s << variants_idxs_done.getByIndex(i) << " ";
		}
		s << "\n";

		for (size_t i=varMapStack.getCount(); i>0; --i){
			s << "--------------------------------------- " << i+2 << "\n";
			s << varMapStack.pool[i+1]->debug();
		}
		return s.str();
};
#endif


void Session::gc_clean(RefData* save_point){
		if (!save_point) save_point = this->gc_first;
		if (save_point==this->gc_last) return; // когда нечего чистить

		// сначала сохраним активные вармапы
		//this->varMapStack.foreach( &(Session::gc_exclude) );
		for(size_t theindex = 0 ; theindex < varMapStack.idx; ++theindex){
			gc_exclude(varMapStack.getByIndex(theindex));
			varMapStack.getByIndex(theindex)->debug();

		}




		RefData *tmp=0, *pre=0, *iend=0;

//std::cout << "GC START!\n";

		#ifdef xDEBUG
		size_t tmpdbg = 0;
		/*std::cout << "\nsave_point: " << save_point <<
			"\ns_p->next: " << save_point->gc_next <<
			"\ngc_last:   " << gc_last << " " << (int)gc_last->gc_label <<
			"\ngc_last->next: " << gc_last->gc_next;*/
		#endif
		for(pre= save_point,
			iend=this->gc_last->gc_next; // null
			pre->gc_next!=iend;
			){
				if (! pre->gc_next->is_gc_mark()){
					tmp = pre->gc_next;
					pre->gc_next = pre->gc_next->gc_next;
					delete tmp;

					#ifdef xDEBUG
					++tmpdbg;
					#endif

				} else {
					pre = pre->gc_next;
				}
		}
		this->gc_last = pre;
		this->gc_last->gc_next = 0;

		#ifdef xDEBUG
				std::cout << "############ GARBAGE: " << tmpdbg << " was deleted !\n" << std::flush;
		#endif

//std::cout << "GC FINISH!\n";

};


void Session::gc_prepare(RefData *save_point){
		#ifdef xDEBUG
				size_t tmpdbg = 0;
		#endif
		for(
			RefData
			  *iter = (save_point ? save_point : this->gc_first),
			  *iend = this->gc_last->gc_next;
			iter!=iend;
			iter=iter->gc_next){
			iter->flush_gc_mark();
		#ifdef xDEBUG
			++tmpdbg;
		#endif
		}

		#ifdef xDEBUG
				std::cout << "############ GARBAGE: " << tmpdbg << " was prepared !\n" << std::flush;
		#endif
	};

void Session::gc_exclude(RefChain *chain){
	if (!chain) return;
		Session::gc_exclude(chain->at_first(), chain->at_last(), chain);
	};

void Session::gc_exclude(RefData **l, RefData **r, RefChain *own){
	own->set_gc_mark();
	if (!l) return;
	//ref_assert(l and r by own);
		for(RefData  **iter=l, **iend=r+1;
			iter<iend;
			++iter){
			(*iter)->set_gc_mark();
			if ((*iter)->isDataBracket()){ // ДАТА-скобка
				gc_exclude( ((RefDataBracket*)(*iter))->chain );
			}
			RefPoint *point = 0;
			if (point=ref_dynamic_cast<RefPoint>(*iter)){
				point->set_gc_mark(this);
			}
		}
};

/*
unistring MatchState::debug(){
		std::ostringstream s;

		s << "****\tMatchState:\t" << std::flush << chain_to_text(view_l, view_r) << "\t~\t" << tpl->debug() << "\n";
		s << varmap.debug();
		return s.str();
};
*/




// ищет по имени переменной ее облать видимости
bool VarMap::findByName(unistring name, RefData** &l, RefData** &r, RefChain *&lr_own, VarMap *&vm, RefVariable *&var) {
        //for (size_t ind = last_ind; ind>=0; --ind) {
        for (size_t ind = last_ind; ind>0; --ind) {
            if (pool[ind].i1->getName()==name) {
				var = pool[ind].i1;
                l  = pool[ind].i2;
                r  = pool[ind].i3;
				vm = pool[ind].i4;
				lr_own = pool[ind].i5;
                return true;
            }
        }
            return false;
};

// ищет по ссылке на переменную ее облать видимости
/*
bool VarMap::findByLink(RefVariable* var, RefData** &l, RefData** &r, VarMap *&vm) {
        for (size_t ind = last_ind; ind>=0; --ind) {
            if (pool[ind].i1==var) {
                l = pool[ind].i2;
                r = pool[ind].i3;
				vm = pool[ind].i4;
                return true;
            }
        }
            return false;
};
*/
bool VarMap::findByLink(RefVariable* var, RefData** &l, RefData** &r, RefChain* &lr_own, VarMap *&vm) {
        for (size_t ind = last_ind+1; ind>0; --ind) {
            if (pool[ind-1].i1==var) {
                l = pool[ind-1].i2;
                r = pool[ind-1].i3;
				vm = pool[ind-1].i4;
				lr_own = pool[ind-1].i5;
                return true;
            }
        }
        return false;
};

bool VarMap::folowByWay(unistring path, RefData** &l, RefData** &r, RefChain* &lr_own, RefVariable* &var, VarMap* &vm){
    #ifdef TESTCODE
	if (path == EmptyUniString) {
		AchtungERRORn;
	}
    #endif
	size_t t_from  = 0;
    size_t t_to    = 0;
    t_to = t_to-1;
    #ifdef TESTCODE
    size_t stmp = 0;
    stmp = stmp-3;
    stmp = stmp+3;
    if (stmp!=0) SYSTEMERRORn("Invalid size_t operation! 0-3+3 != 0 for size_t. Change session.cpp for this platform!");
    #endif

    unistring vname;
	vm = this;

	do {
        t_from = t_to+1;
        t_to   = path.find(varPathSeparator, t_from);
        vname = path.substr(t_from, t_to-t_from);

		if (!vm || !vm->findByName(vname, l, r, lr_own, vm, var)) return false;
    } while (t_to != std::string::npos);
	return true;
}


// todo: сохранять только используемые переменные и varmap-ы
void VarMap::mrk_collect(){
        for (size_t ind = last_ind+1; ind>0; --ind) {
			if (pool[ind-1].i1 != 0){
				(pool[ind-1].i1)->set_gc_mark();
			}

			RefData **from = pool[ind-1].i2;
			RefData **to   = pool[ind-1].i3;
			for(RefData** pp=from; pp<=to; ++pp){
				(*pp)->set_gc_mark();
			}

			if (pool[ind-1].i4 != 0) {
				(pool[ind-1].i4)->set_gc_mark();
				(pool[ind-1].i4)->mrk_collect();
			}
			if (pool[ind-1].i5 != 0){
				(pool[ind-1].i5)->set_gc_mark();
			}
        }
}


unistring VarMap::debug(){
		std::ostringstream s;

		s << "****\t\tVarMap pool:   (by"<< (creator?creator->debug().substr(0, 15):" 0 ") <<")" << std::flush << "\n";
		size_t ind = last_ind;
		while(ind){
			s << "****\t\t\t" << ind << ") " << std::flush << pool[ind].i1->debug() << " : " << chain_to_text( pool[ind].i2,  pool[ind].i3 ) << "\n";
			--ind;
		};
		return s.str();
};


// TODO: оптимизировать!
RefChain*  Session::substituteExpression(RefChain *chain){
	if (! chain->leng) {
		return new RefChain(this);
		//return chain; // в зависимости от того как сделана будет сборка мусора - раскомментировать строку выше
	}

	//std::cout << "\n" << chain->debug() << "\n\n" << std::flush;

	RefChain *result = new RefChain(this, chain->leng);
	RefVariable *tmpvar = 0;
	RefLinkToVariable *link = 0;
	RefDataBracket   *brack = 0;
	RefPointLink     *pointlink = 0;
	RefData **enditem = chain->at_afterlast();
	for(RefData **item = chain->at_first(); item < enditem; ++item){


		link = ref_dynamic_cast<RefLinkToVariable>(*item);  //  ССЫЛКА
		if (link){
			RefData **endi, **i;
			RefChain *i_chain;
			VarMap* vm = 0;
			if (! findVar(link->lnk, i, endi, i_chain, vm)){
				std::cout << "\n\n" << this->debug() << "\n\n" << std::flush;
				SYSTEMERRORs(this, "Variable not found for link " + link->explode());
			}
			if (link->path != EmptyUniString){
				// заглядывание в пользовательскую переменную
				if (! vm->folowByWay(link->path, i, endi, i_chain, tmpvar, vm)) RUNTIMEERRORs(this, "Wrong way for variable " << link->lnk->toString() << " : " << link->path);
			}
			if (i){
				*result += new RefChain(this, 0, i, endi);
				//*result += new RefSegment(this, i_chain, i, endi);
			}
			continue;
		}


		brack = (*item)->isDataBracket(); // ДАТА-СКОБКИ
		if (brack){
			if (ref_dynamic_cast<RefStructBrackets>(brack)){
				*result +=  new RefStructBrackets(this, substituteExpression((RefChain*) brack->chain) ); //TODO: опасно! когда RefChainConstructor != RefChain
			} else {
				// RefExecBracket
				*result +=  new RefExecBrackets(this, substituteExpression((RefChain*) brack->chain) ); //TODO: опасно! когда RefChainConstructor != RefChain
			}
			continue;
		}


		pointlink = ref_dynamic_cast<RefPointLink>(*item);  //  ССЫЛКА-УКАЗАТЕЛЬ
		if (pointlink){
			ref_assert(ref_dynamic_cast<RefVarChains>(pointlink->theLink->lnk));
			RefData **ther, **thel;  RefChain *thechain;  VarMap* thevm = 0;
			if (! findVar(pointlink->theLink->lnk, thel, ther, thechain, thevm)){
				std::cout << "\n\n" << this->debug() << "\n\n" << std::flush;
				SYSTEMERRORs(this, "Variable not found for &link " + pointlink->explode());
			}			
			if (pointlink->theLink->path != EmptyUniString){
				// заглядывание в пользовательскую переменную
				if (! thevm->folowByWay(pointlink->theLink->path, thel, ther, thechain, tmpvar, thevm)) RUNTIMEERRORs(this, "Wrong way for variable " << pointlink->theLink->lnk->toString() << " : " << pointlink->theLink->path);
			} else {
				tmpvar = pointlink->theLink->lnk;
			}

			/**
			*result +=  new RefPoint(
				((RefVarChains*)pointlink->theLink->lnk)->getUserType(),
				thel, ther, thechain, thevm,
				this);
			*/
			RefVarChains *theType = ref_dynamic_cast<RefVarChains>(tmpvar);
			if (theType){
				*result +=  new RefPoint(
					theType->getUserType(),
					thel, ther, thechain, thevm,
					this);
			} else {
				// определиться с семантикой языка: что делать с ссылками на значения НЕ пользовательского типа
				//*result += new RefChain(this, thechain, thel, ther);
				if (tmpvar!=0) RUNTIMEERRORs(this, "Can't create point to object-expression of non-user type: " << pointlink->debug() << " looks to " << (new RefChain(this, thechain, thel, ther))->debug() );
			}
			continue;
		}
		*result += *item;
	}
	return result;
};


void Session::printExecTrace(){
	unistring tab = "";
	while (execTrace.getLength()){
		std::cout << tab  << "'--- <" << execTrace.top1()->getName() << " " << chain_to_text(execTrace.top2(), execTrace.top3()) << " >\n";
		execTrace.pop();
		tab += "   ";
	}
}

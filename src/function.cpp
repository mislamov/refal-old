#include "program.h"
#include "function.h"
#include "session.h"


RefChain* RefFunctionBase::exec(RefData** l, RefData** r, Session* s){
		RefFunctionBase *tmp;

		#ifdef DEBUG
		std::cout << "EXEC : <" << getName() << "  " << chain_to_text(l, r) << " >\n";
		#endif

		s->execTrace.put(this, l, r);
		RefChain* res = eval(l, r, s);
		s->execTrace.top_pop(tmp, l, r); // ?

		#ifdef DEBUG
		std::cout << "EXEC : <" << getName() << "  " << chain_to_text(l, r) << " >  ==>>  " << res->debug() << "\n";
		#endif

		return res;
};


void RefUserFunction::initilizeAll(RefProgram *program){
            std::list<RefSentence *>::iterator 
					sent = body.begin(), // перебор предложений функции
					stopsent = body.end();
			while (sent != stopsent){
				(*sent)->leftPart->compile( (*sent)->leftPart, program );
				(*sent)->rightPart->compile( (*sent)->leftPart, program );
				++sent;                
            };  // std: body.end() - элемент после последнего

};

RefChain* RefUserFunction::eval(RefData **l, RefData **r, Session *sess){
            // перебор предложений функции
			for(std::list<RefSentence *>::iterator sent = body.begin(), send = body.end();
				sent != send;
				++sent) {
					sess->createVarMap(this);
					SessionStatePoint *state = sess->getState();

					if (sess->matching(*sent, (*sent)->leftPart, l, r, false)) {
						RefChain *tmp = sess->substituteExpression( (*sent)->rightPart ); // создаем копию rightPart'а с заменой переменных на значения

						sess->backToState(state);
						delete sess->poptopVarMap();
						return tmp;
					}
					delete sess->poptopVarMap();
			}
			RUNTIMEERRORs(sess, this->getName() << " FAIL");
};

void RefUserTemplate::initilizeAll(RefProgram *program){
	leftPart->compile(leftPart, program);
};

RefUserFunction::~RefUserFunction(){
	//std::cout << "~~~ " << getName() << "\n";

	std::list<RefSentence *>::iterator  body_it = body.begin();
	while(body_it != body.end()){
		delete (*body_it);
		++body_it;
	}
};

unistring RefUserFunction::debug(){
	unistring result = "Function " + getName() + " {\n";

	for(std::list<RefSentence *>::iterator sent = body.begin(), send = body.end();
		sent != send;
		++sent) 
	{
		result += (*sent)->leftPart->debug();
		result += "  =  ";
		result += (*sent)->rightPart->debug();
		result += "\n";
	}
	result += "}";
	return result;
};


TResult RefUserCondition::init(RefData **&tpl, Session* s, RefData **&l, RefData **&r){
	if (! ref_dynamic_cast<RefTemplateBase>(this->own)){
		if (r != s->current_view_r()){ // только в шаблоне условие может проверяться в середине аргумента
			s->MOVE_TO_pred_template(tpl);
			return BACK;
		}
	}

	RefChain *rp, *rpp = s->substituteExpression(this->rightPart);
	rp = s->getProgram()->executeExpression(rpp, s);
	//if (rp!=rpp) delete rpp;

	// сохраняем состояние
	SessionStatePoint *sess_state = s->getState();


	if (s->matching(this, leftPart, (*rp)[0], (*rp)[-1], false) == !withnot){
		if (withnot){ s->backToState(sess_state); };
		s->saveConditionArg(this, rp); // сохраняем аргумент условия для возможного отката
		s->MOVE_TO_next_template(tpl);
		return GO;
	}

	// восстанавливаем состояние
	s->backToState(sess_state);

	s->MOVE_TO_pred_template(tpl);
	return BACK;
};


TResult RefUserCondition::back(RefData **&tpl, Session* s, RefData **&l, RefData **&r){
	RefChain *rp  =  s->restoreConditionArg(this);

	// отрицательные условия всегда пробрасывают откат, так как их открытые переменные запрещено использовать
	if (!withnot && s->matching(this, leftPart, (*rp)[0], (*rp)[-1], true)){
		s->saveConditionArg(this, rp); // возвращаем аргумент условия в хранилище
		s->MOVE_TO_next_template(tpl);
		return GO;
	}
	//delete rp; // аргумент условия для отката больше не нужен
	s->MOVE_TO_pred_template(tpl);
	return BACK;
};

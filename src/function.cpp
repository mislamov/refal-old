#include "function.h"
#include "session.h"

void RefUserFunction::initilizeAll(){
            std::list<RefSentence *>::iterator 
					sent = body.begin(), // перебор предложений функции
					stopsent = body.end();
			while (sent != stopsent){
				(*sent)->leftPart->compile( (*sent)->leftPart );
				(*sent)->rightPart->compile( (*sent)->leftPart );
				++sent;                
            };  // std: body.end() - элемент после последнего

};

RefChain* RefUserFunction::eval(RefData **l, RefData **r, Session *sess){
            // перебор предложений функции
			for(std::list<RefSentence *>::iterator sent = body.begin(), send = body.end();
				sent != send;
				++sent) {
					sess->createVarMap();
					if (sess->matching(*sent, (*sent)->leftPart, l, r, false)) {
                    //LOG(step++ <<  "\tsucessfull!");
					RefChain *tmp = sess->substituteExpression( (*sent)->rightPart ); // создаем копию rightPart'а с заменой переменных на значения
					delete sess->poptopVarMap();
					return tmp;
				}
			}
			RUNTIMEERROR(getName(), "no good sentense");
};

void RefUserTemplate::initilizeAll(){
	leftPart->compile(leftPart);
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
	rp = s->program->executeExpression(rpp, s);
	if (rp!=rpp) delete rpp;

	if (s->matching(this, leftPart, (*rp)[0], (*rp)[-1], false)){
		s->saveConditionArg(this, rp); // сохраняем аргумент условия для возможного отката
		s->MOVE_TO_next_template(tpl);
		return GO;
	}
	s->MOVE_TO_pred_template(tpl);
	return BACK;
};


TResult RefUserCondition::back(RefData **&tpl, Session* s, RefData **&l, RefData **&r){
	RefChain *rp  =  s->restoreConditionArg(this);
	if (s->matching(this, leftPart, (*rp)[0], (*rp)[-1], true)){
		s->saveConditionArg(this, rp); // возвращаем аргумент условия в хранилище
		s->MOVE_TO_next_template(tpl);
		return GO;
	}
	delete rp; // аргумент условия для отката больше не нужен
	s->MOVE_TO_pred_template(tpl);
	return BACK;
};

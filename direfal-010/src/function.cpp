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

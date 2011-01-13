#include "direfal.h" 
#include "commands.h" 
#include "system.h" 

DataChain* F(DataCursor arg_from, DataCursor arg_to){
/*DEF*/	DataCursor l_tmp;
/*DEF*/	DataCursor r_tmp0;
/*DEF*/	DataCursor l_tmp0;
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	l_tmp = arg_from;
/*INC*/	if (!INC(l_tmp, arg_to)) goto sentence_after_0;
	if (! isSymbolType(l_tmp.container->type)) goto sentence_after_0;
/*SET*/	r_1 = l_tmp;
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = r_1;
/*SET*/	r_e = r_1;
/*JMP*/	goto label_e_firststep;
label_e: 
/*INC*/	if (!INC(r_e, arg_to)) goto sentence_after_0;
label_e_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor r_tmp;
/*SET*/	r_tmp = r_e;
 if (!SLIDE(r_tmp, arg_to, l_1, r_1)) goto label_e;
//// [ empty ] 
/*ISEMPTY*/	if (r_tmp!=0 && arg_to != r_tmp) goto label_e;

// подготовка подстановки 
DataChain* PHQGHUMEAYLNLF = new DataChain(); 
result->append(newRefExecBrackets(F, PHQGHUMEAYLNLF, "F")); 
PHQGHUMEAYLNLF->append_copy(l_e, r_e); 

return result; 
}
sentence_after_0: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = arg_from;
/*SET*/	l_tmp = arg_from;
/*INC*/	if (!INC(l_tmp, arg_to)) goto sentence_after_1;
	if (! isSymbolType(l_tmp.container->type)) goto sentence_after_1;
/*SET*/	r_s = l_tmp;
//// [ empty ] 
/*ISEMPTY*/	if (r_s!=0 && arg_to != r_s) goto sentence_after_1;

// подготовка подстановки 
result->append(newRefWord("T")); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = arg_from;
/*SET*/	l_tmp = arg_from;
/*INC*/	if (!INC(l_tmp, arg_to)) goto sentence_after_2;
	if (! isSymbolType(l_tmp.container->type)) goto sentence_after_2;
/*SET*/	r_s = l_tmp;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = r_s;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
result->append(newRefWord("F")); 

return result; 
}
sentence_after_2: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Go(DataCursor arg_from, DataCursor arg_to){
/*DEF*/	DataCursor l_tmp;
/*DEF*/	DataCursor r_tmp0;
/*DEF*/	DataCursor l_tmp0;
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ empty ] 
/*ISEMPTY*/	if (arg_from!=0 && arg_to != arg_from) goto sentence_after_0;

// подготовка подстановки 
DataChain* DXFIRCVSCXGGBW = new DataChain(); 
result->append(newRefExecBrackets(Prout, DXFIRCVSCXGGBW, "Prout")); 
DataChain* KFNQDUXWFNFOZV = new DataChain(); 
DXFIRCVSCXGGBW->append(newRefExecBrackets(F, KFNQDUXWFNFOZV, "F")); 
KFNQDUXWFNFOZV->append(newRefText("")); 

return result; 
}
sentence_after_0: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

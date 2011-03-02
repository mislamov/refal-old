#include "direfal.h" 
#include "commands.h" 
#include "system.h" 
#include "res.h" 

DataChain* Go(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ empty ] 
/*ISEMPTY*/	if (arg_from!=0 && arg_to != arg_from) goto sentence_after_1;

// подготовка подстановки 
DataChain* PHQGHUMEAYLNLF = new DataChain(); 
result->append(newRefExecBrackets(Begin, PHQGHUMEAYLNLF, "Begin")); 
PHQGHUMEAYLNLF->append(newRefInteger(100)); 

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Begin(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor DXFIRCVSCXGGBW;
/*SET*/	DXFIRCVSCXGGBW = arg_from;
/*INC*/	if (!INC(DXFIRCVSCXGGBW, arg_to)) goto sentence_after_1;
	if (DXFIRCVSCXGGBW.container->type != integer || DXFIRCVSCXGGBW.container->value.num != 0) goto sentence_after_1;
//// [ empty ] 
/*ISEMPTY*/	if (DXFIRCVSCXGGBW!=0 && arg_to != DXFIRCVSCXGGBW) goto sentence_after_1;

// подготовка подстановки 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor KFNQDUXWFNFOZV;
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = arg_from;
/*SET*/	KFNQDUXWFNFOZV = arg_from;
/*INC*/	if (!INC(KFNQDUXWFNFOZV, arg_to)) goto sentence_after_2;
	if (! isSymbolType(KFNQDUXWFNFOZV.container->type)) goto sentence_after_2;
/*SET*/	r_n = KFNQDUXWFNFOZV;
//// [ empty ] 
/*ISEMPTY*/	if (r_n!=0 && arg_to != r_n) goto sentence_after_2;

// подготовка подстановки 
DataChain* SRTKJPREPGGXRP = new DataChain(); 
result->append(newRefExecBrackets(Prout, SRTKJPREPGGXRP, "Prout")); 
SRTKJPREPGGXRP->append(newRefText("Who is first? (1 - pc  2 - you)")); 
DataChain* NRVYSTMWCYSYYC = new DataChain(); 
result->append(newRefExecBrackets(FirG, NRVYSTMWCYSYYC, "FirG")); 
DataChain* QPEVIKEFFMZNIM = new DataChain(); 
NRVYSTMWCYSYYC->append(newRefExecBrackets(Card, QPEVIKEFFMZNIM, "Card")); 
DataChain* KKASVWSRENZKYC = new DataChain(); 
result->append(newRefExecBrackets(Begin, KKASVWSRENZKYC, "Begin")); 
DataChain* XFXTLSGYPSFADP = new DataChain(); 
KKASVWSRENZKYC->append(newRefExecBrackets(Dec, XFXTLSGYPSFADP, "-")); 
XFXTLSGYPSFADP->append_copy(l_n, r_n); 
XFXTLSGYPSFADP->append(newRefInteger(1)); 

return result; 
}
sentence_after_2: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* FirG(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor OOEFXZBCOEJUVP;
/*SET*/	OOEFXZBCOEJUVP = arg_from;
/*INC*/	if (!INC(OOEFXZBCOEJUVP, arg_to)) goto sentence_after_1;
	if (OOEFXZBCOEJUVP.container->type != text || *(OOEFXZBCOEJUVP.container->value.text + OOEFXZBCOEJUVP.index) != '1') goto sentence_after_1;
//// [ empty ] 
/*ISEMPTY*/	if (OOEFXZBCOEJUVP!=0 && arg_to != OOEFXZBCOEJUVP) goto sentence_after_1;

// подготовка подстановки 
DataChain* NPLJVRVIPYAMYE = new DataChain(); 
result->append(newRefExecBrackets(Game, NPLJVRVIPYAMYE, "Game")); 
DataChain* HWQNQRQPMXUJJL = new DataChain(); 
NPLJVRVIPYAMYE->append(newRefStructBrackets(HWQNQRQPMXUJJL)); 
HWQNQRQPMXUJJL->append(newRefText("2")); 
DataChain* OOVAOWUXWHMSNC = new DataChain(); 
NPLJVRVIPYAMYE->append(newRefStructBrackets(OOVAOWUXWHMSNC)); 
OOVAOWUXWHMSNC->append(newRefText("1")); 
DataChain* BXCOKSFZKVATXD = new DataChain(); 
NPLJVRVIPYAMYE->append(newRefStructBrackets(BXCOKSFZKVATXD)); 
BXCOKSFZKVATXD->append(newRefText("")); 
DataChain* KNLYJYHFIXJSWN = new DataChain(); 
NPLJVRVIPYAMYE->append(newRefStructBrackets(KNLYJYHFIXJSWN)); 
KNLYJYHFIXJSWN->append(newRefText("23456789")); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor KKUFNUXXZRZBMN;
/*SET*/	KKUFNUXXZRZBMN = arg_from;
/*INC*/	if (!INC(KKUFNUXXZRZBMN, arg_to)) goto sentence_after_2;
	if (KKUFNUXXZRZBMN.container->type != text || *(KKUFNUXXZRZBMN.container->value.text + KKUFNUXXZRZBMN.index) != '2') goto sentence_after_2;
//// [ empty ] 
/*ISEMPTY*/	if (KKUFNUXXZRZBMN!=0 && arg_to != KKUFNUXXZRZBMN) goto sentence_after_2;

// подготовка подстановки 
DataChain* AUGZQRCDDIUTEI = new DataChain(); 
result->append(newRefExecBrackets(Game, AUGZQRCDDIUTEI, "Game")); 
DataChain* OJWAYYZPVSCMPS = new DataChain(); 
AUGZQRCDDIUTEI->append(newRefStructBrackets(OJWAYYZPVSCMPS)); 
OJWAYYZPVSCMPS->append(newRefText("2")); 
DataChain* AJLFVGUBFAAOVL = new DataChain(); 
AUGZQRCDDIUTEI->append(newRefStructBrackets(AJLFVGUBFAAOVL)); 
AJLFVGUBFAAOVL->append(newRefText("")); 
DataChain* ZYLNTRKDCPWSRT = new DataChain(); 
AUGZQRCDDIUTEI->append(newRefStructBrackets(ZYLNTRKDCPWSRT)); 
ZYLNTRKDCPWSRT->append(newRefText("")); 
DataChain* ESJWHDIZCOBZCN = new DataChain(); 
AUGZQRCDDIUTEI->append(newRefStructBrackets(ESJWHDIZCOBZCN)); 
ESJWHDIZCOBZCN->append(newRefText("123456789")); 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = arg_from;
/*SET*/	r_e = arg_to;

// подготовка подстановки 

return result; 
}
sentence_after_3: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Game__(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = arg_from;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* FWLQIJTVDWVXHR = new DataChain(); 
result->append(newRefExecBrackets(Prout, FWLQIJTVDWVXHR, "Prout")); 
FWLQIJTVDWVXHR->append(newRefWord("Game:")); 
FWLQIJTVDWVXHR->append_copy(l_e, r_e); 
DataChain* CBLDVGYLWGBUSB = new DataChain(); 
result->append(newRefExecBrackets(Game__, CBLDVGYLWGBUSB, "Game__")); 
CBLDVGYLWGBUSB->append_copy(l_e, r_e); 

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Game(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor MBORXTLHCSMPXO;
/*DEF*/	DataCursor HGMGNKEUFDXOTO;
/*DEF*/	DataCursor GBGXPEYANFETCU;
/*SET*/	MBORXTLHCSMPXO = arg_from;
/*INC*/	if (!INC(MBORXTLHCSMPXO, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (MBORXTLHCSMPXO.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	HGMGNKEUFDXOTO = MBORXTLHCSMPXO.container->value.bracket_data.chain->at_before_first();
	GBGXPEYANFETCU   = MBORXTLHCSMPXO.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor KEPZSHKLJUGGGE;
/*DEF*/	DataCursor l_g;
/*DEF*/	DataCursor r_g;
/*SET*/	l_g = HGMGNKEUFDXOTO;
/*SET*/	KEPZSHKLJUGGGE = HGMGNKEUFDXOTO;
/*INC*/	if (!INC(KEPZSHKLJUGGGE, GBGXPEYANFETCU)) goto sentence_after_1;
	if (! isSymbolType(KEPZSHKLJUGGGE.container->type)) goto sentence_after_1;
/*SET*/	r_g = KEPZSHKLJUGGGE;
//// [ empty ] 
/*ISEMPTY*/	if (r_g!=0 && GBGXPEYANFETCU != r_g) goto sentence_after_1;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor KJDQZJENPEVQGX;
/*DEF*/	DataCursor IEPJSRDZJAZUJL;
/*DEF*/	DataCursor LCHHBFQMKIMWZO;
/*SET*/	KJDQZJENPEVQGX = MBORXTLHCSMPXO;
/*INC*/	if (!INC(KJDQZJENPEVQGX, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (KJDQZJENPEVQGX.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	IEPJSRDZJAZUJL = KJDQZJENPEVQGX.container->value.bracket_data.chain->at_before_first();
	LCHHBFQMKIMWZO   = KJDQZJENPEVQGX.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = IEPJSRDZJAZUJL;
/*SET*/	r_1 = LCHHBFQMKIMWZO;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor BIWYBXDUUNFSKS;
/*DEF*/	DataCursor RSRTEKMQDCYZJE;
/*DEF*/	DataCursor EUHMSRQCOZIJIP;
/*SET*/	BIWYBXDUUNFSKS = KJDQZJENPEVQGX;
/*INC*/	if (!INC(BIWYBXDUUNFSKS, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (BIWYBXDUUNFSKS.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	RSRTEKMQDCYZJE = BIWYBXDUUNFSKS.container->value.bracket_data.chain->at_before_first();
	EUHMSRQCOZIJIP   = BIWYBXDUUNFSKS.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = RSRTEKMQDCYZJE;
/*SET*/	r_2 = EUHMSRQCOZIJIP;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor FIONEEDDPSZRNA;
/*DEF*/	DataCursor VYMMTATBDZQSOE;
/*DEF*/	DataCursor MUVNPPPSUACBAZ;
/*SET*/	FIONEEDDPSZRNA = BIWYBXDUUNFSKS;
/*INC*/	if (!INC(FIONEEDDPSZRNA, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (FIONEEDDPSZRNA.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	VYMMTATBDZQSOE = FIONEEDDPSZRNA.container->value.bracket_data.chain->at_before_first();
	MUVNPPPSUACBAZ   = FIONEEDDPSZRNA.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = VYMMTATBDZQSOE;
/*SET*/	r_n = MUVNPPPSUACBAZ;
//// [ empty ] 
/*ISEMPTY*/	if (FIONEEDDPSZRNA!=0 && arg_to != FIONEEDDPSZRNA) goto sentence_after_1;

// подготовка подстановки 
DataChain* UXMHECTHLEGRPU = new DataChain(); 
result->append(newRefExecBrackets(Ekran, UXMHECTHLEGRPU, "Ekran")); 
DataChain* NKDMBPPWEQTGJO = new DataChain(); 
UXMHECTHLEGRPU->append(newRefStructBrackets(NKDMBPPWEQTGJO)); 
NKDMBPPWEQTGJO->append_copy(l_1, r_1); 
DataChain* PARMOWZDQYOXYT = new DataChain(); 
UXMHECTHLEGRPU->append(newRefStructBrackets(PARMOWZDQYOXYT)); 
PARMOWZDQYOXYT->append_copy(l_2, r_2); 
DataChain* JBBHAWDYDCPRJB = new DataChain(); 
result->append(newRefExecBrackets(GameIfWin, JBBHAWDYDCPRJB, "GameIfWin")); 
DataChain* XPHOOHPKWQYUHR = new DataChain(); 
JBBHAWDYDCPRJB->append(newRefExecBrackets(Ifwin, XPHOOHPKWQYUHR, "Ifwin")); 
DataChain* QZHNBNFUVQNQQL = new DataChain(); 
XPHOOHPKWQYUHR->append(newRefStructBrackets(QZHNBNFUVQNQQL)); 
QZHNBNFUVQNQQL->append_copy(l_1, r_1); 
DataChain* RZJPXIOGVLIEXD = new DataChain(); 
XPHOOHPKWQYUHR->append(newRefStructBrackets(RZJPXIOGVLIEXD)); 
RZJPXIOGVLIEXD->append_copy(l_2, r_2); 
DataChain* ZUZOSRKRUSVOJB = new DataChain(); 
JBBHAWDYDCPRJB->append(newRefStructBrackets(ZUZOSRKRUSVOJB)); 
ZUZOSRKRUSVOJB->append_copy(l_g, r_g); 
DataChain* RZMWZPOWKJILEF = new DataChain(); 
JBBHAWDYDCPRJB->append(newRefStructBrackets(RZMWZPOWKJILEF)); 
RZMWZPOWKJILEF->append_copy(l_1, r_1); 
DataChain* RAAMDIGPNPUUHG = new DataChain(); 
JBBHAWDYDCPRJB->append(newRefStructBrackets(RAAMDIGPNPUUHG)); 
RAAMDIGPNPUUHG->append_copy(l_2, r_2); 
DataChain* XPQNJWJMWAXXMN = new DataChain(); 
JBBHAWDYDCPRJB->append(newRefStructBrackets(XPQNJWJMWAXXMN)); 
XPQNJWJMWAXXMN->append_copy(l_n, r_n); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = arg_from;
/*SET*/	r_e = arg_to;

// подготовка подстановки 

return result; 
}
sentence_after_2: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* GameIfWin(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor SNHHLQQRZUDLTF;
/*SET*/	SNHHLQQRZUDLTF = arg_from;
/*INC*/	if (!INC(SNHHLQQRZUDLTF, arg_to)) goto sentence_after_1;
	if (SNHHLQQRZUDLTF.container->type != text || *(SNHHLQQRZUDLTF.container->value.text + SNHHLQQRZUDLTF.index) != '0') goto sentence_after_1;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = SNHHLQQRZUDLTF;
/*SET*/	r_e = SNHHLQQRZUDLTF;
/*JMP*/	goto label_ZOTCJTNZXUGLSD_firststep;
label_ZOTCJTNZXUGLSD: 
/*INC*/	if (!INC(r_e, arg_to)) goto sentence_after_1;
label_ZOTCJTNZXUGLSD_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor SMZCNOCKVFAJFR;
/*DEF*/	DataCursor MXOTHOWKBJZWUC;
/*DEF*/	DataCursor WLJFRIMPMYHCHZ;
/*SET*/	SMZCNOCKVFAJFR = r_e;
/*INC*/	if (!INC(SMZCNOCKVFAJFR, arg_to)) goto label_ZOTCJTNZXUGLSD;
//// ISBRACKET 
	if (SMZCNOCKVFAJFR.container->type != struct_bracket) goto label_ZOTCJTNZXUGLSD;
//// JMP_BRACKET 
	MXOTHOWKBJZWUC = SMZCNOCKVFAJFR.container->value.bracket_data.chain->at_before_first();
	WLJFRIMPMYHCHZ   = SMZCNOCKVFAJFR.container->value.bracket_data.chain->at_last();
//// [ empty ] 
/*ISEMPTY*/	if (MXOTHOWKBJZWUC!=0 && WLJFRIMPMYHCHZ != MXOTHOWKBJZWUC) goto label_ZOTCJTNZXUGLSD;
//// [ empty ] 
/*ISEMPTY*/	if (SMZCNOCKVFAJFR!=0 && arg_to != SMZCNOCKVFAJFR) goto label_ZOTCJTNZXUGLSD;

// подготовка подстановки 
DataChain* EYHJUGIXWTBVTR = new DataChain(); 
result->append(newRefExecBrackets(Prout, EYHJUGIXWTBVTR, "Prout")); 
EYHJUGIXWTBVTR->append(newRefText("Nobody !!!.")); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor EHBBCPXIFBXVFB;
/*SET*/	EHBBCPXIFBXVFB = arg_from;
/*INC*/	if (!INC(EHBBCPXIFBXVFB, arg_to)) goto sentence_after_2;
	if (EHBBCPXIFBXVFB.container->type != text || *(EHBBCPXIFBXVFB.container->value.text + EHBBCPXIFBXVFB.index) != '1') goto sentence_after_2;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = EHBBCPXIFBXVFB;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* UBMJRMBSZTSSHF = new DataChain(); 
result->append(newRefExecBrackets(Prout, UBMJRMBSZTSSHF, "Prout")); 
UBMJRMBSZTSSHF->append(newRefText("Winner X")); 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor ROEFWSJRXJHGUZ;
/*SET*/	ROEFWSJRXJHGUZ = arg_from;
/*INC*/	if (!INC(ROEFWSJRXJHGUZ, arg_to)) goto sentence_after_3;
	if (ROEFWSJRXJHGUZ.container->type != text || *(ROEFWSJRXJHGUZ.container->value.text + ROEFWSJRXJHGUZ.index) != '2') goto sentence_after_3;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = ROEFWSJRXJHGUZ;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* IQFLDUUVEOOWQC = new DataChain(); 
result->append(newRefExecBrackets(Prout, IQFLDUUVEOOWQC, "Prout")); 
IQFLDUUVEOOWQC->append(newRefText("Winner O")); 

return result; 
}
sentence_after_3: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor UDHNEFNJHAIMUC;
/*SET*/	UDHNEFNJHAIMUC = arg_from;
/*INC*/	if (!INC(UDHNEFNJHAIMUC, arg_to)) goto sentence_after_4;
	if (UDHNEFNJHAIMUC.container->type != text || *(UDHNEFNJHAIMUC.container->value.text + UDHNEFNJHAIMUC.index) != '0') goto sentence_after_4;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = UDHNEFNJHAIMUC;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* TBRECUYKABFCVK = new DataChain(); 
result->append(newRefExecBrackets(Game1, TBRECUYKABFCVK, "Game1")); 
TBRECUYKABFCVK->append_copy(l_e, r_e); 

return result; 
}
sentence_after_4: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Game1__(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = arg_from;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* DZEZTOIDUKUHJZ = new DataChain(); 
result->append(newRefExecBrackets(Prout, DZEZTOIDUKUHJZ, "Prout")); 
DZEZTOIDUKUHJZ->append(newRefWord("Game1:")); 
DZEZTOIDUKUHJZ->append_copy(l_e, r_e); 
DataChain* EFCZZZBFKQDPQZ = new DataChain(); 
result->append(newRefExecBrackets(Game1__, EFCZZZBFKQDPQZ, "Game1__")); 
EFCZZZBFKQDPQZ->append_copy(l_e, r_e); 

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Game1(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor IKFOBUCDHTHXDJ;
/*DEF*/	DataCursor GKJELRLPAXAMCE;
/*DEF*/	DataCursor ROSWITDPTPCCLI;
/*SET*/	IKFOBUCDHTHXDJ = arg_from;
/*INC*/	if (!INC(IKFOBUCDHTHXDJ, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (IKFOBUCDHTHXDJ.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	GKJELRLPAXAMCE = IKFOBUCDHTHXDJ.container->value.bracket_data.chain->at_before_first();
	ROSWITDPTPCCLI   = IKFOBUCDHTHXDJ.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor FKELJYTIHRCQAY;
/*SET*/	FKELJYTIHRCQAY = GKJELRLPAXAMCE;
/*INC*/	if (!INC(FKELJYTIHRCQAY, ROSWITDPTPCCLI)) goto sentence_after_1;
	if (FKELJYTIHRCQAY.container->type != text || *(FKELJYTIHRCQAY.container->value.text + FKELJYTIHRCQAY.index) != '1') goto sentence_after_1;
//// [ empty ] 
/*ISEMPTY*/	if (FKELJYTIHRCQAY!=0 && ROSWITDPTPCCLI != FKELJYTIHRCQAY) goto sentence_after_1;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_12;
/*DEF*/	DataCursor r_12;
/*SET*/	l_12 = IKFOBUCDHTHXDJ;
/*SET*/	r_12 = IKFOBUCDHTHXDJ;
/*JMP*/	goto label_HNGYCDRUDMPHME_firststep;
label_HNGYCDRUDMPHME: 
/*INC*/	if (!INC(r_12, arg_to)) goto sentence_after_1;
label_HNGYCDRUDMPHME_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor CKOTRWOSPOFGHF;
/*DEF*/	DataCursor OZQVLQFXWWKMFX;
/*DEF*/	DataCursor DYYGMDCASZSGOV;
/*SET*/	CKOTRWOSPOFGHF = r_12;
/*INC*/	if (!INC(CKOTRWOSPOFGHF, arg_to)) goto label_HNGYCDRUDMPHME;
//// ISBRACKET 
	if (CKOTRWOSPOFGHF.container->type != struct_bracket) goto label_HNGYCDRUDMPHME;
//// JMP_BRACKET 
	OZQVLQFXWWKMFX = CKOTRWOSPOFGHF.container->value.bracket_data.chain->at_before_first();
	DYYGMDCASZSGOV   = CKOTRWOSPOFGHF.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = OZQVLQFXWWKMFX;
/*SET*/	r_n = DYYGMDCASZSGOV;
//// [ empty ] 
/*ISEMPTY*/	if (CKOTRWOSPOFGHF!=0 && arg_to != CKOTRWOSPOFGHF) goto label_HNGYCDRUDMPHME;

// подготовка подстановки 
DataChain* SODKJGHCWMBMXR = new DataChain(); 
result->append(newRefExecBrackets(Prout, SODKJGHCWMBMXR, "Prout")); 
SODKJGHCWMBMXR->append(newRefText("hmm ...")); 
DataChain* MHUYFYQGAJQKCK = new DataChain(); 
result->append(newRefExecBrackets(Game, MHUYFYQGAJQKCK, "Game")); 
DataChain* LZNAYXQKQOYZWM = new DataChain(); 
MHUYFYQGAJQKCK->append(newRefStructBrackets(LZNAYXQKQOYZWM)); 
LZNAYXQKQOYZWM->append(newRefText("2")); 
DataChain* YUBZAZCPKHKTKY = new DataChain(); 
MHUYFYQGAJQKCK->append(newRefExecBrackets(PlayerHod, YUBZAZCPKHKTKY, "PlayerHod")); 
YUBZAZCPKHKTKY->append(newRefText("1")); 
DataChain* DZIVCUYPURFMBI = new DataChain(); 
YUBZAZCPKHKTKY->append(newRefExecBrackets(GetHod, DZIVCUYPURFMBI, "GetHod")); 
DZIVCUYPURFMBI->append(newRefText("1")); 
DataChain* SGEKYRGZVXDHPO = new DataChain(); 
DZIVCUYPURFMBI->append(newRefStructBrackets(SGEKYRGZVXDHPO)); 
SGEKYRGZVXDHPO->append(newRefText("1")); 
DZIVCUYPURFMBI->append_copy(l_12, r_12); 
DataChain* AMVAFYRARXSVKH = new DataChain(); 
DZIVCUYPURFMBI->append(newRefStructBrackets(AMVAFYRARXSVKH)); 
AMVAFYRARXSVKH->append_copy(l_n, r_n); 
YUBZAZCPKHKTKY->append_copy(l_12, r_12); 
DataChain* TQDIHERSIGBHZJ = new DataChain(); 
YUBZAZCPKHKTKY->append(newRefStructBrackets(TQDIHERSIGBHZJ)); 
TQDIHERSIGBHZJ->append_copy(l_n, r_n); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor ZUJXMMYSPNARAE;
/*DEF*/	DataCursor WKEGJCCVHHRJVB;
/*DEF*/	DataCursor JTSQDJOOTGPKNF;
/*SET*/	ZUJXMMYSPNARAE = arg_from;
/*INC*/	if (!INC(ZUJXMMYSPNARAE, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (ZUJXMMYSPNARAE.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	WKEGJCCVHHRJVB = ZUJXMMYSPNARAE.container->value.bracket_data.chain->at_before_first();
	JTSQDJOOTGPKNF   = ZUJXMMYSPNARAE.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor PFYCGFIEOWQRWW;
/*SET*/	PFYCGFIEOWQRWW = WKEGJCCVHHRJVB;
/*INC*/	if (!INC(PFYCGFIEOWQRWW, JTSQDJOOTGPKNF)) goto sentence_after_2;
	if (PFYCGFIEOWQRWW.container->type != text || *(PFYCGFIEOWQRWW.container->value.text + PFYCGFIEOWQRWW.index) != '2') goto sentence_after_2;
//// [ empty ] 
/*ISEMPTY*/	if (PFYCGFIEOWQRWW!=0 && JTSQDJOOTGPKNF != PFYCGFIEOWQRWW) goto sentence_after_2;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_12;
/*DEF*/	DataCursor r_12;
/*SET*/	l_12 = ZUJXMMYSPNARAE;
/*SET*/	r_12 = ZUJXMMYSPNARAE;
/*JMP*/	goto label_XNVJIUPALYYNMK_firststep;
label_XNVJIUPALYYNMK: 
/*INC*/	if (!INC(r_12, arg_to)) goto sentence_after_2;
label_XNVJIUPALYYNMK_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor MNUVKLHSECDWRA;
/*DEF*/	DataCursor CGFMZKGIPDFODK;
/*DEF*/	DataCursor JMJQWIQPUOQHIM;
/*SET*/	MNUVKLHSECDWRA = r_12;
/*INC*/	if (!INC(MNUVKLHSECDWRA, arg_to)) goto label_XNVJIUPALYYNMK;
//// ISBRACKET 
	if (MNUVKLHSECDWRA.container->type != struct_bracket) goto label_XNVJIUPALYYNMK;
//// JMP_BRACKET 
	CGFMZKGIPDFODK = MNUVKLHSECDWRA.container->value.bracket_data.chain->at_before_first();
	JMJQWIQPUOQHIM   = MNUVKLHSECDWRA.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = CGFMZKGIPDFODK;
/*SET*/	r_n = JMJQWIQPUOQHIM;
//// [ empty ] 
/*ISEMPTY*/	if (MNUVKLHSECDWRA!=0 && arg_to != MNUVKLHSECDWRA) goto label_XNVJIUPALYYNMK;

// подготовка подстановки 
DataChain* VFVUZWYVIJGFUL = new DataChain(); 
result->append(newRefExecBrackets(Game, VFVUZWYVIJGFUL, "Game")); 
DataChain* LKJDUHSJAFBTLK = new DataChain(); 
VFVUZWYVIJGFUL->append(newRefStructBrackets(LKJDUHSJAFBTLK)); 
LKJDUHSJAFBTLK->append(newRefText("1")); 
DataChain* MFQRMYJFJNHHSS = new DataChain(); 
VFVUZWYVIJGFUL->append(newRefExecBrackets(PlayerHod, MFQRMYJFJNHHSS, "PlayerHod")); 
MFQRMYJFJNHHSS->append(newRefText("2")); 
DataChain* QCTYDTEAMDCJBP = new DataChain(); 
MFQRMYJFJNHHSS->append(newRefExecBrackets(Prout, QCTYDTEAMDCJBP, "Prout")); 
QCTYDTEAMDCJBP->append(newRefText("Select number for 0:")); 
DataChain* RHTNEGYIWXGCJW = new DataChain(); 
MFQRMYJFJNHHSS->append(newRefExecBrackets(Card, RHTNEGYIWXGCJW, "Card")); 
MFQRMYJFJNHHSS->append_copy(l_12, r_12); 
DataChain* LGRSMEAEARWTVJ = new DataChain(); 
MFQRMYJFJNHHSS->append(newRefStructBrackets(LGRSMEAEARWTVJ)); 
LGRSMEAEARWTVJ->append_copy(l_n, r_n); 

return result; 
}
sentence_after_2: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* PlayerHod__(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = arg_from;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* SJBAOIOJLWHYPN = new DataChain(); 
result->append(newRefExecBrackets(Prout, SJBAOIOJLWHYPN, "Prout")); 
SJBAOIOJLWHYPN->append(newRefWord("PlayerHod:")); 
SJBAOIOJLWHYPN->append_copy(l_e, r_e); 
DataChain* VRUIHOSWKIFYGT = new DataChain(); 
result->append(newRefExecBrackets(PlayerHod__, VRUIHOSWKIFYGT, "PlayerHod__")); 
VRUIHOSWKIFYGT->append_copy(l_e, r_e); 

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* PlayerHod(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor YDHACWYHSGEWZM;
/*SET*/	YDHACWYHSGEWZM = arg_from;
/*INC*/	if (!INC(YDHACWYHSGEWZM, arg_to)) goto sentence_after_1;
	if (YDHACWYHSGEWZM.container->type != text || *(YDHACWYHSGEWZM.container->value.text + YDHACWYHSGEWZM.index) != '1') goto sentence_after_1;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor TGONZLTJHGAUHN;
/*DEF*/	DataCursor l_h;
/*DEF*/	DataCursor r_h;
/*SET*/	l_h = YDHACWYHSGEWZM;
/*SET*/	TGONZLTJHGAUHN = YDHACWYHSGEWZM;
/*INC*/	if (!INC(TGONZLTJHGAUHN, arg_to)) goto sentence_after_1;
	if (! isSymbolType(TGONZLTJHGAUHN.container->type)) goto sentence_after_1;
/*SET*/	r_h = TGONZLTJHGAUHN;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor IHREQGJFWKJSMT;
/*DEF*/	DataCursor PJHAEFQZAAULDR;
/*DEF*/	DataCursor CHJCCDYRFVVRIV;
/*SET*/	IHREQGJFWKJSMT = r_h;
/*INC*/	if (!INC(IHREQGJFWKJSMT, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (IHREQGJFWKJSMT.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	PJHAEFQZAAULDR = IHREQGJFWKJSMT.container->value.bracket_data.chain->at_before_first();
	CHJCCDYRFVVRIV   = IHREQGJFWKJSMT.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = PJHAEFQZAAULDR;
/*SET*/	r_1 = CHJCCDYRFVVRIV;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor UYEEGFIVDRCYGU;
/*DEF*/	DataCursor RQDREDAKUBNFGU;
/*DEF*/	DataCursor PROQYLOBCWQXKZ;
/*SET*/	UYEEGFIVDRCYGU = IHREQGJFWKJSMT;
/*INC*/	if (!INC(UYEEGFIVDRCYGU, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (UYEEGFIVDRCYGU.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	RQDREDAKUBNFGU = UYEEGFIVDRCYGU.container->value.bracket_data.chain->at_before_first();
	PROQYLOBCWQXKZ   = UYEEGFIVDRCYGU.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = RQDREDAKUBNFGU;
/*SET*/	r_2 = PROQYLOBCWQXKZ;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor MAUSJGMHCMHGDN;
/*DEF*/	DataCursor MPHNQKAMHURKTR;
/*DEF*/	DataCursor FFACLVGRZKKLDA;
/*SET*/	MAUSJGMHCMHGDN = UYEEGFIVDRCYGU;
/*INC*/	if (!INC(MAUSJGMHCMHGDN, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (MAUSJGMHCMHGDN.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	MPHNQKAMHURKTR = MAUSJGMHCMHGDN.container->value.bracket_data.chain->at_before_first();
	FFACLVGRZKKLDA   = MAUSJGMHCMHGDN.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_n1;
/*DEF*/	DataCursor r_n1;
/*SET*/	l_n1 = MPHNQKAMHURKTR;
/*SET*/	r_n1 = MPHNQKAMHURKTR;
/*JMP*/	goto label_CLLTEOJOMONXRQ_firststep;
label_CLLTEOJOMONXRQ: 
/*INC*/	if (!INC(r_n1, FFACLVGRZKKLDA)) goto sentence_after_1;
label_CLLTEOJOMONXRQ_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor YJZGINRNNZWACX;
/*SET*/	YJZGINRNNZWACX = r_n1;
 if (!SLIDE(YJZGINRNNZWACX, FFACLVGRZKKLDA, l_h, r_h)) goto label_CLLTEOJOMONXRQ;
//// [ e.1 ] 
/*DEF*/	DataCursor l_n2;
/*DEF*/	DataCursor r_n2;
/*SET*/	l_n2 = YJZGINRNNZWACX;
/*SET*/	r_n2 = FFACLVGRZKKLDA;
//// [ empty ] 
/*ISEMPTY*/	if (MAUSJGMHCMHGDN!=0 && arg_to != MAUSJGMHCMHGDN) goto label_CLLTEOJOMONXRQ;

// подготовка подстановки 
DataChain* EWJTBOXVYNFHKS = new DataChain(); 
result->append(newRefExecBrackets(Prout, EWJTBOXVYNFHKS, "Prout")); 
EWJTBOXVYNFHKS->append(newRefText("step:")); 
EWJTBOXVYNFHKS->append_copy(l_h, r_h); 
DataChain* TCENAUMNDDXFDM = new DataChain(); 
result->append(newRefStructBrackets(TCENAUMNDDXFDM)); 
TCENAUMNDDXFDM->append_copy(l_1, r_1); 
TCENAUMNDDXFDM->append_copy(l_h, r_h); 
DataChain* VZCAUTDCCKXAAY = new DataChain(); 
result->append(newRefStructBrackets(VZCAUTDCCKXAAY)); 
VZCAUTDCCKXAAY->append_copy(l_2, r_2); 
DataChain* DZSXTTOBBGQNGV = new DataChain(); 
result->append(newRefStructBrackets(DZSXTTOBBGQNGV)); 
DZSXTTOBBGQNGV->append_copy(l_n1, r_n1); 
DZSXTTOBBGQNGV->append_copy(l_n2, r_n2); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor VPJGOJOGLMKXGB;
/*SET*/	VPJGOJOGLMKXGB = arg_from;
/*INC*/	if (!INC(VPJGOJOGLMKXGB, arg_to)) goto sentence_after_2;
	if (VPJGOJOGLMKXGB.container->type != text || *(VPJGOJOGLMKXGB.container->value.text + VPJGOJOGLMKXGB.index) != '2') goto sentence_after_2;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor FCPYPCKQCHBDDZ;
/*DEF*/	DataCursor l_h;
/*DEF*/	DataCursor r_h;
/*SET*/	l_h = VPJGOJOGLMKXGB;
/*SET*/	FCPYPCKQCHBDDZ = VPJGOJOGLMKXGB;
/*INC*/	if (!INC(FCPYPCKQCHBDDZ, arg_to)) goto sentence_after_2;
	if (! isSymbolType(FCPYPCKQCHBDDZ.container->type)) goto sentence_after_2;
/*SET*/	r_h = FCPYPCKQCHBDDZ;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor WRXBZMQRLXVOBT;
/*DEF*/	DataCursor WHXGINFGFRCCLM;
/*DEF*/	DataCursor ZNMJUGWWBSQFCI;
/*SET*/	WRXBZMQRLXVOBT = r_h;
/*INC*/	if (!INC(WRXBZMQRLXVOBT, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (WRXBZMQRLXVOBT.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	WHXGINFGFRCCLM = WRXBZMQRLXVOBT.container->value.bracket_data.chain->at_before_first();
	ZNMJUGWWBSQFCI   = WRXBZMQRLXVOBT.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = WHXGINFGFRCCLM;
/*SET*/	r_1 = ZNMJUGWWBSQFCI;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor HUBSJOLLMSQSGH;
/*DEF*/	DataCursor MCPHELSOTFLBGS;
/*DEF*/	DataCursor FNPCUZSRUPCHYN;
/*SET*/	HUBSJOLLMSQSGH = WRXBZMQRLXVOBT;
/*INC*/	if (!INC(HUBSJOLLMSQSGH, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (HUBSJOLLMSQSGH.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	MCPHELSOTFLBGS = HUBSJOLLMSQSGH.container->value.bracket_data.chain->at_before_first();
	FNPCUZSRUPCHYN   = HUBSJOLLMSQSGH.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = MCPHELSOTFLBGS;
/*SET*/	r_2 = FNPCUZSRUPCHYN;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor VZHCPQUGRIWNIQ;
/*DEF*/	DataCursor XDFJPWPXFBLKPN;
/*DEF*/	DataCursor PEELFJMTKUQPZO;
/*SET*/	VZHCPQUGRIWNIQ = HUBSJOLLMSQSGH;
/*INC*/	if (!INC(VZHCPQUGRIWNIQ, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (VZHCPQUGRIWNIQ.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	XDFJPWPXFBLKPN = VZHCPQUGRIWNIQ.container->value.bracket_data.chain->at_before_first();
	PEELFJMTKUQPZO   = VZHCPQUGRIWNIQ.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_n1;
/*DEF*/	DataCursor r_n1;
/*SET*/	l_n1 = XDFJPWPXFBLKPN;
/*SET*/	r_n1 = XDFJPWPXFBLKPN;
/*JMP*/	goto label_MWNLMBUPMKTLPT_firststep;
label_MWNLMBUPMKTLPT: 
/*INC*/	if (!INC(r_n1, PEELFJMTKUQPZO)) goto sentence_after_2;
label_MWNLMBUPMKTLPT_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor NDMPDSYDSGVFPE;
/*SET*/	NDMPDSYDSGVFPE = r_n1;
 if (!SLIDE(NDMPDSYDSGVFPE, PEELFJMTKUQPZO, l_h, r_h)) goto label_MWNLMBUPMKTLPT;
//// [ e.1 ] 
/*DEF*/	DataCursor l_n2;
/*DEF*/	DataCursor r_n2;
/*SET*/	l_n2 = NDMPDSYDSGVFPE;
/*SET*/	r_n2 = PEELFJMTKUQPZO;
//// [ empty ] 
/*ISEMPTY*/	if (VZHCPQUGRIWNIQ!=0 && arg_to != VZHCPQUGRIWNIQ) goto label_MWNLMBUPMKTLPT;

// подготовка подстановки 
DataChain* ESKMKHSSMVNONW = new DataChain(); 
result->append(newRefExecBrackets(Prout, ESKMKHSSMVNONW, "Prout")); 
ESKMKHSSMVNONW->append(newRefText("step:")); 
ESKMKHSSMVNONW->append_copy(l_h, r_h); 
DataChain* AFXWHGBIBABVQO = new DataChain(); 
result->append(newRefStructBrackets(AFXWHGBIBABVQO)); 
AFXWHGBIBABVQO->append_copy(l_1, r_1); 
DataChain* PQFOVIUSSQFQWE = new DataChain(); 
result->append(newRefStructBrackets(PQFOVIUSSQFQWE)); 
PQFOVIUSSQFQWE->append_copy(l_2, r_2); 
PQFOVIUSSQFQWE->append_copy(l_h, r_h); 
DataChain* HTXDZUJTLNTXMR = new DataChain(); 
result->append(newRefStructBrackets(HTXDZUJTLNTXMR)); 
HTXDZUJTLNTXMR->append_copy(l_n1, r_n1); 
HTXDZUJTLNTXMR->append_copy(l_n2, r_n2); 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = arg_from;
/*SET*/	r_e = arg_to;

// подготовка подстановки 

return result; 
}
sentence_after_3: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* GetHod__(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = arg_from;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* JXXWTLGGKYTBIO = new DataChain(); 
result->append(newRefExecBrackets(Prout, JXXWTLGGKYTBIO, "Prout")); 
JXXWTLGGKYTBIO->append(newRefWord("GetHod:")); 
JXXWTLGGKYTBIO->append_copy(l_e, r_e); 
DataChain* LYDNILQADOJSKK = new DataChain(); 
result->append(newRefExecBrackets(GetHod__, LYDNILQADOJSKK, "GetHod__")); 
LYDNILQADOJSKK->append_copy(l_e, r_e); 

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* GetHod(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor VFXAHHJMBOCLJA;
/*DEF*/	DataCursor l_v;
/*DEF*/	DataCursor r_v;
/*SET*/	l_v = arg_from;
/*SET*/	VFXAHHJMBOCLJA = arg_from;
/*INC*/	if (!INC(VFXAHHJMBOCLJA, arg_to)) goto sentence_after_1;
	if (! isSymbolType(VFXAHHJMBOCLJA.container->type)) goto sentence_after_1;
/*SET*/	r_v = VFXAHHJMBOCLJA;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = r_v;
/*SET*/	r_e = r_v;
/*JMP*/	goto label_RINTDWCLDVDXRO_firststep;
label_RINTDWCLDVDXRO: 
/*INC*/	if (!INC(r_e, arg_to)) goto sentence_after_1;
label_RINTDWCLDVDXRO_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor PBYJZWYYOJUOTH;
/*DEF*/	DataCursor WMLVRGLFZDZDBT;
/*DEF*/	DataCursor UBXUOFFVNCRSWS;
/*SET*/	PBYJZWYYOJUOTH = r_e;
/*INC*/	if (!INC(PBYJZWYYOJUOTH, arg_to)) goto label_RINTDWCLDVDXRO;
//// ISBRACKET 
	if (PBYJZWYYOJUOTH.container->type != struct_bracket) goto label_RINTDWCLDVDXRO;
//// JMP_BRACKET 
	WMLVRGLFZDZDBT = PBYJZWYYOJUOTH.container->value.bracket_data.chain->at_before_first();
	UBXUOFFVNCRSWS   = PBYJZWYYOJUOTH.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_not;
/*DEF*/	DataCursor r_not;
/*SET*/	l_not = WMLVRGLFZDZDBT;
/*SET*/	r_not = UBXUOFFVNCRSWS;
//// [ empty ] 
/*ISEMPTY*/	if (PBYJZWYYOJUOTH!=0 && arg_to != PBYJZWYYOJUOTH) goto label_RINTDWCLDVDXRO;

// подготовка подстановки 
DataChain* AZNMOIJOIVVGOB = new DataChain(); 
result->append(newRefExecBrackets(UseHod, AZNMOIJOIVVGOB, "UseHod")); 
AZNMOIJOIVVGOB->append_copy(l_v, r_v); 
AZNMOIJOIVVGOB->append_copy(l_e, r_e); 
DataChain* QPNCKWVNHKEBMT = new DataChain(); 
AZNMOIJOIVVGOB->append(newRefStructBrackets(QPNCKWVNHKEBMT)); 
QPNCKWVNHKEBMT->append_copy(l_not, r_not); 
DataChain* DHVYGKJISUXHAT = new DataChain(); 
AZNMOIJOIVVGOB->append(newRefStructBrackets(DHVYGKJISUXHAT)); 
DataChain* MUUDQBHMKNHFXA = new DataChain(); 
DHVYGKJISUXHAT->append(newRefExecBrackets(WriteXO, MUUDQBHMKNHFXA, "WriteXO")); 
MUUDQBHMKNHFXA->append_copy(l_e, r_e); 
DataChain* XQXKJLZZQTSJFA = new DataChain(); 
MUUDQBHMKNHFXA->append(newRefStructBrackets(XQXKJLZZQTSJFA)); 
XQXKJLZZQTSJFA->append(newRefText(">")); 
XQXKJLZZQTSJFA->append_copy(l_not, r_not); 

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* UseHod__(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = arg_from;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* EEDFUUJKOLXJOQ = new DataChain(); 
result->append(newRefExecBrackets(Prout, EEDFUUJKOLXJOQ, "Prout")); 
EEDFUUJKOLXJOQ->append(newRefWord("UseHod:")); 
EEDFUUJKOLXJOQ->append_copy(l_e, r_e); 
DataChain* KDVFEPVLHVHRWT = new DataChain(); 
result->append(newRefExecBrackets(UseHod__, KDVFEPVLHVHRWT, "UseHod__")); 
KDVFEPVLHVHRWT->append_copy(l_e, r_e); 

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* UseHod(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = arg_from;
/*SET*/	r_e = arg_from;
/*JMP*/	goto label_FDUKXFFJPSSWYX_firststep;
label_FDUKXFFJPSSWYX: 
/*INC*/	if (!INC(r_e, arg_to)) goto sentence_after_1;
label_FDUKXFFJPSSWYX_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor LIJJHEVRYXOZBA;
/*DEF*/	DataCursor FPFMOWGRGONUAT;
/*DEF*/	DataCursor DQLAHYGGYLJDDJ;
/*SET*/	LIJJHEVRYXOZBA = r_e;
/*INC*/	if (!INC(LIJJHEVRYXOZBA, arg_to)) goto label_FDUKXFFJPSSWYX;
//// ISBRACKET 
	if (LIJJHEVRYXOZBA.container->type != struct_bracket) goto label_FDUKXFFJPSSWYX;
//// JMP_BRACKET 
	FPFMOWGRGONUAT = LIJJHEVRYXOZBA.container->value.bracket_data.chain->at_before_first();
	DQLAHYGGYLJDDJ   = LIJJHEVRYXOZBA.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor HMLTEDZLODSRKE;
/*SET*/	HMLTEDZLODSRKE = FPFMOWGRGONUAT;
/*INC*/	if (!INC(HMLTEDZLODSRKE, DQLAHYGGYLJDDJ)) goto label_FDUKXFFJPSSWYX;
	if (HMLTEDZLODSRKE.container->type != text || *(HMLTEDZLODSRKE.container->value.text + HMLTEDZLODSRKE.index) != '#') goto label_FDUKXFFJPSSWYX;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor UTGTNKNTARJKPX;
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = HMLTEDZLODSRKE;
/*SET*/	UTGTNKNTARJKPX = HMLTEDZLODSRKE;
/*INC*/	if (!INC(UTGTNKNTARJKPX, DQLAHYGGYLJDDJ)) goto label_FDUKXFFJPSSWYX;
	if (! isSymbolType(UTGTNKNTARJKPX.container->type)) goto label_FDUKXFFJPSSWYX;
/*SET*/	r_s = UTGTNKNTARJKPX;
//// [ empty ] 
/*ISEMPTY*/	if (r_s!=0 && DQLAHYGGYLJDDJ != r_s) goto label_FDUKXFFJPSSWYX;
//// [ empty ] 
/*ISEMPTY*/	if (LIJJHEVRYXOZBA!=0 && arg_to != LIJJHEVRYXOZBA) goto label_FDUKXFFJPSSWYX;

// подготовка подстановки 
result->append_copy(l_s, r_s); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor XVJJMPSVKNHKWJ;
/*DEF*/	DataCursor l_v;
/*DEF*/	DataCursor r_v;
/*SET*/	l_v = arg_from;
/*SET*/	XVJJMPSVKNHKWJ = arg_from;
/*INC*/	if (!INC(XVJJMPSVKNHKWJ, arg_to)) goto sentence_after_2;
	if (! isSymbolType(XVJJMPSVKNHKWJ.container->type)) goto sentence_after_2;
/*SET*/	r_v = XVJJMPSVKNHKWJ;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = r_v;
/*SET*/	r_e = r_v;
/*JMP*/	goto label_OPMMLEBKSUCVZQ_firststep;
label_OPMMLEBKSUCVZQ: 
/*INC*/	if (!INC(r_e, arg_to)) goto sentence_after_2;
label_OPMMLEBKSUCVZQ_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor LYQNWCMBVBHRML;
/*DEF*/	DataCursor OWPJBWYVWTGTOQ;
/*DEF*/	DataCursor NMICXAPZARKNNX;
/*SET*/	LYQNWCMBVBHRML = r_e;
/*INC*/	if (!INC(LYQNWCMBVBHRML, arg_to)) goto label_OPMMLEBKSUCVZQ;
//// ISBRACKET 
	if (LYQNWCMBVBHRML.container->type != struct_bracket) goto label_OPMMLEBKSUCVZQ;
//// JMP_BRACKET 
	OWPJBWYVWTGTOQ = LYQNWCMBVBHRML.container->value.bracket_data.chain->at_before_first();
	NMICXAPZARKNNX   = LYQNWCMBVBHRML.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_not;
/*DEF*/	DataCursor r_not;
/*SET*/	l_not = OWPJBWYVWTGTOQ;
/*SET*/	r_not = NMICXAPZARKNNX;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor TUUFARZROSDQWS;
/*DEF*/	DataCursor MTCJGHECQUDOSR;
/*DEF*/	DataCursor TJXYAAYKQRXYCR;
/*SET*/	TUUFARZROSDQWS = LYQNWCMBVBHRML;
/*INC*/	if (!INC(TUUFARZROSDQWS, arg_to)) goto label_OPMMLEBKSUCVZQ;
//// ISBRACKET 
	if (TUUFARZROSDQWS.container->type != struct_bracket) goto label_OPMMLEBKSUCVZQ;
//// JMP_BRACKET 
	MTCJGHECQUDOSR = TUUFARZROSDQWS.container->value.bracket_data.chain->at_before_first();
	TJXYAAYKQRXYCR   = TUUFARZROSDQWS.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_Wr;
/*DEF*/	DataCursor r_Wr;
/*SET*/	l_Wr = MTCJGHECQUDOSR;
/*SET*/	r_Wr = TJXYAAYKQRXYCR;
//// [ empty ] 
/*ISEMPTY*/	if (TUUFARZROSDQWS!=0 && arg_to != TUUFARZROSDQWS) goto label_OPMMLEBKSUCVZQ;

// подготовка подстановки 
DataChain* XUWJXNPQJNBKCP = new DataChain(); 
result->append(newRefExecBrackets(UHod, XUWJXNPQJNBKCP, "UHod")); 
DataChain* DMOKALXAPEMVBQ = new DataChain(); 
XUWJXNPQJNBKCP->append(newRefStructBrackets(DMOKALXAPEMVBQ)); 
DataChain* LZSVXZKUTAPPWG = new DataChain(); 
DMOKALXAPEMVBQ->append(newRefExecBrackets(Switch, LZSVXZKUTAPPWG, "Switch")); 
LZSVXZKUTAPPWG->append_copy(l_v, r_v); 
LZSVXZKUTAPPWG->append_copy(l_Wr, r_Wr); 
DataChain* ZPDPYZKZCVBNTC = new DataChain(); 
XUWJXNPQJNBKCP->append(newRefStructBrackets(ZPDPYZKZCVBNTC)); 
ZPDPYZKZCVBNTC->append_copy(l_Wr, r_Wr); 
DataChain* VFXSXPJAOXTFHV = new DataChain(); 
XUWJXNPQJNBKCP->append(newRefStructBrackets(VFXSXPJAOXTFHV)); 
VFXSXPJAOXTFHV->append_copy(l_not, r_not); 

return result; 
}
sentence_after_2: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* UHod__(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = arg_from;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* XXYTGOKRCXAETA = new DataChain(); 
result->append(newRefExecBrackets(Prout, XXYTGOKRCXAETA, "Prout")); 
XXYTGOKRCXAETA->append(newRefWord("UHod:")); 
XXYTGOKRCXAETA->append_copy(l_e, r_e); 
DataChain* UQGNDMPHWZYIAY = new DataChain(); 
result->append(newRefExecBrackets(UHod__, UQGNDMPHWZYIAY, "UHod__")); 
UQGNDMPHWZYIAY->append_copy(l_e, r_e); 

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* UHod(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor ABJRQGEPPXYJST;
/*DEF*/	DataCursor TYZUVLDVYBSUXK;
/*DEF*/	DataCursor BMFZVRTNOVIDZN;
/*SET*/	ABJRQGEPPXYJST = arg_from;
/*INC*/	if (!INC(ABJRQGEPPXYJST, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (ABJRQGEPPXYJST.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	TYZUVLDVYBSUXK = ABJRQGEPPXYJST.container->value.bracket_data.chain->at_before_first();
	BMFZVRTNOVIDZN   = ABJRQGEPPXYJST.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_Sw;
/*DEF*/	DataCursor r_Sw;
/*SET*/	l_Sw = TYZUVLDVYBSUXK;
/*SET*/	r_Sw = BMFZVRTNOVIDZN;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor PGHOZVAFMSNSNQ;
/*DEF*/	DataCursor IVMVUBCWTFSRQT;
/*DEF*/	DataCursor MKNEPBHOWEJAZH;
/*SET*/	PGHOZVAFMSNSNQ = ABJRQGEPPXYJST;
/*INC*/	if (!INC(PGHOZVAFMSNSNQ, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (PGHOZVAFMSNSNQ.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	IVMVUBCWTFSRQT = PGHOZVAFMSNSNQ.container->value.bracket_data.chain->at_before_first();
	MKNEPBHOWEJAZH   = PGHOZVAFMSNSNQ.container->value.bracket_data.chain->at_last();
//// [ &.name <any> ] 
/*DEF*/	DataCursor KWCMMTPIXXXLZQ;
/*SET*/	KWCMMTPIXXXLZQ = IVMVUBCWTFSRQT;
 if (!SLIDE(KWCMMTPIXXXLZQ, MKNEPBHOWEJAZH, l_Sw, r_Sw)) goto sentence_after_1;
//// [ e.1 ] 
/*DEF*/	DataCursor l_Wr;
/*DEF*/	DataCursor r_Wr;
/*SET*/	l_Wr = KWCMMTPIXXXLZQ;
/*SET*/	r_Wr = MKNEPBHOWEJAZH;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor YSXTWWTAIDYAXY;
/*DEF*/	DataCursor QLEPRXIBEXXYFV;
/*DEF*/	DataCursor SDDYGTHCUYYFWP;
/*SET*/	YSXTWWTAIDYAXY = PGHOZVAFMSNSNQ;
/*INC*/	if (!INC(YSXTWWTAIDYAXY, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (YSXTWWTAIDYAXY.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	QLEPRXIBEXXYFV = YSXTWWTAIDYAXY.container->value.bracket_data.chain->at_before_first();
	SDDYGTHCUYYFWP   = YSXTWWTAIDYAXY.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor JSFYBGLGZMBINT;
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = QLEPRXIBEXXYFV;
/*SET*/	JSFYBGLGZMBINT = QLEPRXIBEXXYFV;
/*INC*/	if (!INC(JSFYBGLGZMBINT, SDDYGTHCUYYFWP)) goto sentence_after_1;
	if (! isSymbolType(JSFYBGLGZMBINT.container->type)) goto sentence_after_1;
/*SET*/	r_s = JSFYBGLGZMBINT;
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = r_s;
/*SET*/	r_n = SDDYGTHCUYYFWP;
//// [ empty ] 
/*ISEMPTY*/	if (YSXTWWTAIDYAXY!=0 && arg_to != YSXTWWTAIDYAXY) goto sentence_after_1;

// подготовка подстановки 
result->append_copy(l_s, r_s); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor ATTNHODTONPYZW;
/*DEF*/	DataCursor OTKGNGUPHPKXEA;
/*DEF*/	DataCursor TOWZABSDNVQHKF;
/*SET*/	ATTNHODTONPYZW = arg_from;
/*INC*/	if (!INC(ATTNHODTONPYZW, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (ATTNHODTONPYZW.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	OTKGNGUPHPKXEA = ATTNHODTONPYZW.container->value.bracket_data.chain->at_before_first();
	TOWZABSDNVQHKF   = ATTNHODTONPYZW.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_Sw;
/*DEF*/	DataCursor r_Sw;
/*SET*/	l_Sw = OTKGNGUPHPKXEA;
/*SET*/	r_Sw = TOWZABSDNVQHKF;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor CMOFISFRFQGVPM;
/*DEF*/	DataCursor VORPJFZSLZMPJJ;
/*DEF*/	DataCursor NEHRYKXJZUBUAC;
/*SET*/	CMOFISFRFQGVPM = ATTNHODTONPYZW;
/*INC*/	if (!INC(CMOFISFRFQGVPM, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (CMOFISFRFQGVPM.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	VORPJFZSLZMPJJ = CMOFISFRFQGVPM.container->value.bracket_data.chain->at_before_first();
	NEHRYKXJZUBUAC   = CMOFISFRFQGVPM.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor CLFKCYZOBGHTUO;
/*DEF*/	DataCursor l_s1;
/*DEF*/	DataCursor r_s1;
/*SET*/	l_s1 = VORPJFZSLZMPJJ;
/*SET*/	CLFKCYZOBGHTUO = VORPJFZSLZMPJJ;
/*INC*/	if (!INC(CLFKCYZOBGHTUO, NEHRYKXJZUBUAC)) goto sentence_after_2;
	if (! isSymbolType(CLFKCYZOBGHTUO.container->type)) goto sentence_after_2;
/*SET*/	r_s1 = CLFKCYZOBGHTUO;
//// [ `a` <any> ] 
/*DEF*/	DataCursor XRAJVPRECWGXXP;
/*SET*/	XRAJVPRECWGXXP = r_s1;
/*INC*/	if (!INC(XRAJVPRECWGXXP, NEHRYKXJZUBUAC)) goto sentence_after_2;
	if (XRAJVPRECWGXXP.container->type != text || *(XRAJVPRECWGXXP.container->value.text + XRAJVPRECWGXXP.index) != '=') goto sentence_after_2;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor SWCGMMVEDEWDMF;
/*DEF*/	DataCursor l_s2;
/*DEF*/	DataCursor r_s2;
/*SET*/	l_s2 = XRAJVPRECWGXXP;
/*SET*/	SWCGMMVEDEWDMF = XRAJVPRECWGXXP;
/*INC*/	if (!INC(SWCGMMVEDEWDMF, NEHRYKXJZUBUAC)) goto sentence_after_2;
	if (! isSymbolType(SWCGMMVEDEWDMF.container->type)) goto sentence_after_2;
/*SET*/	r_s2 = SWCGMMVEDEWDMF;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = r_s2;
/*SET*/	r_e = r_s2;
/*JMP*/	goto label_NQWCUQDSCILIQE_firststep;
label_NQWCUQDSCILIQE: 
/*INC*/	if (!INC(r_e, NEHRYKXJZUBUAC)) goto sentence_after_2;
label_NQWCUQDSCILIQE_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor CIHLUILGMFCSWT;
/*SET*/	CIHLUILGMFCSWT = r_e;
 if (!SLIDE(CIHLUILGMFCSWT, NEHRYKXJZUBUAC, l_Sw, r_Sw)) goto label_NQWCUQDSCILIQE;
//// [ e.1 ] 
/*DEF*/	DataCursor l_Wr;
/*DEF*/	DataCursor r_Wr;
/*SET*/	l_Wr = CIHLUILGMFCSWT;
/*SET*/	r_Wr = NEHRYKXJZUBUAC;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor JEBKRJLPGFGRAT;
/*DEF*/	DataCursor ZBSGUVZIFNHYXW;
/*DEF*/	DataCursor JSJAVWAUXPANNA;
/*SET*/	JEBKRJLPGFGRAT = CMOFISFRFQGVPM;
/*INC*/	if (!INC(JEBKRJLPGFGRAT, arg_to)) goto label_NQWCUQDSCILIQE;
//// ISBRACKET 
	if (JEBKRJLPGFGRAT.container->type != struct_bracket) goto label_NQWCUQDSCILIQE;
//// JMP_BRACKET 
	ZBSGUVZIFNHYXW = JEBKRJLPGFGRAT.container->value.bracket_data.chain->at_before_first();
	JSJAVWAUXPANNA   = JEBKRJLPGFGRAT.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor MXJDVZUHNACZYH;
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = ZBSGUVZIFNHYXW;
/*SET*/	MXJDVZUHNACZYH = ZBSGUVZIFNHYXW;
/*INC*/	if (!INC(MXJDVZUHNACZYH, JSJAVWAUXPANNA)) goto label_NQWCUQDSCILIQE;
	if (! isSymbolType(MXJDVZUHNACZYH.container->type)) goto label_NQWCUQDSCILIQE;
/*SET*/	r_s = MXJDVZUHNACZYH;
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = r_s;
/*SET*/	r_n = JSJAVWAUXPANNA;
//// [ empty ] 
/*ISEMPTY*/	if (JEBKRJLPGFGRAT!=0 && arg_to != JEBKRJLPGFGRAT) goto label_NQWCUQDSCILIQE;

// подготовка подстановки 
DataChain* EPWZOLHUSLRKVW = new DataChain(); 
result->append(newRefExecBrackets(UHod, EPWZOLHUSLRKVW, "UHod")); 
DataChain* PNVGZMIIZWUDWD = new DataChain(); 
EPWZOLHUSLRKVW->append(newRefStructBrackets(PNVGZMIIZWUDWD)); 
PNVGZMIIZWUDWD->append_copy(l_Sw, r_Sw); 
DataChain* FZLKTBQDXGYYIU = new DataChain(); 
EPWZOLHUSLRKVW->append(newRefStructBrackets(FZLKTBQDXGYYIU)); 
FZLKTBQDXGYYIU->append_copy(l_e, r_e); 
FZLKTBQDXGYYIU->append_copy(l_Sw, r_Sw); 
FZLKTBQDXGYYIU->append_copy(l_Wr, r_Wr); 
DataChain* DSJVEZKMESBJLK = new DataChain(); 
EPWZOLHUSLRKVW->append(newRefStructBrackets(DSJVEZKMESBJLK)); 
DSJVEZKMESBJLK->append_copy(l_n, r_n); 

return result; 
}
sentence_after_2: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Ekran(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	r_1 = arg_to;

// подготовка подстановки 
DataChain* YERTAHNEXHUQMJ = new DataChain(); 
result->append(newRefExecBrackets(Prout, YERTAHNEXHUQMJ, "Prout")); 
YERTAHNEXHUQMJ->append(newRefText("*===T===T===*")); 
DataChain* ICBMUSQDKLASOL = new DataChain(); 
result->append(newRefExecBrackets(Prout, ICBMUSQDKLASOL, "Prout")); 
ICBMUSQDKLASOL->append(newRefText("|")); 
DataChain* WJXPTXXEUMZFWY = new DataChain(); 
ICBMUSQDKLASOL->append(newRefExecBrackets(XO, WJXPTXXEUMZFWY, "XO")); 
WJXPTXXEUMZFWY->append(newRefText("1")); 
WJXPTXXEUMZFWY->append_copy(l_1, r_1); 
ICBMUSQDKLASOL->append(newRefText("|")); 
DataChain* UCPABQSEFFUNQP = new DataChain(); 
ICBMUSQDKLASOL->append(newRefExecBrackets(XO, UCPABQSEFFUNQP, "XO")); 
UCPABQSEFFUNQP->append(newRefText("2")); 
UCPABQSEFFUNQP->append_copy(l_1, r_1); 
ICBMUSQDKLASOL->append(newRefText("|")); 
DataChain* KFNNBECBBCJPDY = new DataChain(); 
ICBMUSQDKLASOL->append(newRefExecBrackets(XO, KFNNBECBBCJPDY, "XO")); 
KFNNBECBBCJPDY->append(newRefText("3")); 
KFNNBECBBCJPDY->append_copy(l_1, r_1); 
ICBMUSQDKLASOL->append(newRefText("|")); 
DataChain* JLIBITLLPLXELR = new DataChain(); 
result->append(newRefExecBrackets(Prout, JLIBITLLPLXELR, "Prout")); 
JLIBITLLPLXELR->append(newRefText("*===I===I===*")); 
DataChain* DKEXDTQUVPTTEY = new DataChain(); 
result->append(newRefExecBrackets(Prout, DKEXDTQUVPTTEY, "Prout")); 
DKEXDTQUVPTTEY->append(newRefText("|")); 
DataChain* HTLQLBBBVOQOZK = new DataChain(); 
DKEXDTQUVPTTEY->append(newRefExecBrackets(XO, HTLQLBBBVOQOZK, "XO")); 
HTLQLBBBVOQOZK->append(newRefText("4")); 
HTLQLBBBVOQOZK->append_copy(l_1, r_1); 
DKEXDTQUVPTTEY->append(newRefText("|")); 
DataChain* YNAYYRBAQMYJHZ = new DataChain(); 
DKEXDTQUVPTTEY->append(newRefExecBrackets(XO, YNAYYRBAQMYJHZ, "XO")); 
YNAYYRBAQMYJHZ->append(newRefText("5")); 
YNAYYRBAQMYJHZ->append_copy(l_1, r_1); 
DKEXDTQUVPTTEY->append(newRefText("|")); 
DataChain* XNDSIYFSEXWBIO = new DataChain(); 
DKEXDTQUVPTTEY->append(newRefExecBrackets(XO, XNDSIYFSEXWBIO, "XO")); 
XNDSIYFSEXWBIO->append(newRefText("6")); 
XNDSIYFSEXWBIO->append_copy(l_1, r_1); 
DKEXDTQUVPTTEY->append(newRefText("|")); 
DataChain* EWQVQRTCDLPQMV = new DataChain(); 
result->append(newRefExecBrackets(Prout, EWQVQRTCDLPQMV, "Prout")); 
EWQVQRTCDLPQMV->append(newRefText("*===I===I===*")); 
DataChain* JIFVGYMKGOTZJM = new DataChain(); 
result->append(newRefExecBrackets(Prout, JIFVGYMKGOTZJM, "Prout")); 
JIFVGYMKGOTZJM->append(newRefText("|")); 
DataChain* NZQTMRPNDEVNMT = new DataChain(); 
JIFVGYMKGOTZJM->append(newRefExecBrackets(XO, NZQTMRPNDEVNMT, "XO")); 
NZQTMRPNDEVNMT->append(newRefText("7")); 
NZQTMRPNDEVNMT->append_copy(l_1, r_1); 
JIFVGYMKGOTZJM->append(newRefText("|")); 
DataChain* HJITSSPAQNJRDO = new DataChain(); 
JIFVGYMKGOTZJM->append(newRefExecBrackets(XO, HJITSSPAQNJRDO, "XO")); 
HJITSSPAQNJRDO->append(newRefText("8")); 
HJITSSPAQNJRDO->append_copy(l_1, r_1); 
JIFVGYMKGOTZJM->append(newRefText("|")); 
DataChain* YJWPYATMLEYQSV = new DataChain(); 
JIFVGYMKGOTZJM->append(newRefExecBrackets(XO, YJWPYATMLEYQSV, "XO")); 
YJWPYATMLEYQSV->append(newRefText("9")); 
YJWPYATMLEYQSV->append_copy(l_1, r_1); 
JIFVGYMKGOTZJM->append(newRefText("|")); 
DataChain* KPAMSVBMVXRLLI = new DataChain(); 
result->append(newRefExecBrackets(Prout, KPAMSVBMVXRLLI, "Prout")); 
KPAMSVBMVXRLLI->append(newRefText("*===I===I===*")); 

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* XO(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor VFEDKJIGAVYXJV;
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	VFEDKJIGAVYXJV = arg_from;
/*INC*/	if (!INC(VFEDKJIGAVYXJV, arg_to)) goto sentence_after_1;
	if (! isSymbolType(VFEDKJIGAVYXJV.container->type)) goto sentence_after_1;
/*SET*/	r_1 = VFEDKJIGAVYXJV;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor EQVRBACUIGAIPY;
/*DEF*/	DataCursor HBBXIPBZNCWHRB;
/*DEF*/	DataCursor LIRIZXOQPTQQWE;
/*SET*/	EQVRBACUIGAIPY = r_1;
/*INC*/	if (!INC(EQVRBACUIGAIPY, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (EQVRBACUIGAIPY.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	HBBXIPBZNCWHRB = EQVRBACUIGAIPY.container->value.bracket_data.chain->at_before_first();
	LIRIZXOQPTQQWE   = EQVRBACUIGAIPY.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_21;
/*DEF*/	DataCursor r_21;
/*SET*/	l_21 = HBBXIPBZNCWHRB;
/*SET*/	r_21 = HBBXIPBZNCWHRB;
/*JMP*/	goto label_AAFJEQIOZPYFAU_firststep;
label_AAFJEQIOZPYFAU: 
/*INC*/	if (!INC(r_21, LIRIZXOQPTQQWE)) goto sentence_after_1;
label_AAFJEQIOZPYFAU_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor UQMVHXKMNXMSYA;
/*SET*/	UQMVHXKMNXMSYA = r_21;
 if (!SLIDE(UQMVHXKMNXMSYA, LIRIZXOQPTQQWE, l_1, r_1)) goto label_AAFJEQIOZPYFAU;
//// [ e.1 ] 
/*DEF*/	DataCursor l_22;
/*DEF*/	DataCursor r_22;
/*SET*/	l_22 = UQMVHXKMNXMSYA;
/*SET*/	r_22 = LIRIZXOQPTQQWE;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor MPTLZANOTLSLWU;
/*DEF*/	DataCursor HTFQJRRWBWHMQH;
/*DEF*/	DataCursor ZKHDKCRFVBEIYI;
/*SET*/	MPTLZANOTLSLWU = EQVRBACUIGAIPY;
/*INC*/	if (!INC(MPTLZANOTLSLWU, arg_to)) goto label_AAFJEQIOZPYFAU;
//// ISBRACKET 
	if (MPTLZANOTLSLWU.container->type != struct_bracket) goto label_AAFJEQIOZPYFAU;
//// JMP_BRACKET 
	HTFQJRRWBWHMQH = MPTLZANOTLSLWU.container->value.bracket_data.chain->at_before_first();
	ZKHDKCRFVBEIYI   = MPTLZANOTLSLWU.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = HTFQJRRWBWHMQH;
/*SET*/	r_3 = ZKHDKCRFVBEIYI;
//// [ empty ] 
/*ISEMPTY*/	if (MPTLZANOTLSLWU!=0 && arg_to != MPTLZANOTLSLWU) goto label_AAFJEQIOZPYFAU;

// подготовка подстановки 
result->append(newRefText("-X-")); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor PVFVPZHYUJABTQ;
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	PVFVPZHYUJABTQ = arg_from;
/*INC*/	if (!INC(PVFVPZHYUJABTQ, arg_to)) goto sentence_after_2;
	if (! isSymbolType(PVFVPZHYUJABTQ.container->type)) goto sentence_after_2;
/*SET*/	r_1 = PVFVPZHYUJABTQ;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor WWTBKDOGKEMHIB;
/*DEF*/	DataCursor YXRNXSXRZLETBQ;
/*DEF*/	DataCursor EXKRQOIERNAPLQ;
/*SET*/	WWTBKDOGKEMHIB = r_1;
/*INC*/	if (!INC(WWTBKDOGKEMHIB, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (WWTBKDOGKEMHIB.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	YXRNXSXRZLETBQ = WWTBKDOGKEMHIB.container->value.bracket_data.chain->at_before_first();
	EXKRQOIERNAPLQ   = WWTBKDOGKEMHIB.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = YXRNXSXRZLETBQ;
/*SET*/	r_2 = EXKRQOIERNAPLQ;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor YJPQOUBVJSEBAL;
/*DEF*/	DataCursor WNKSVLOIDZFPIR;
/*DEF*/	DataCursor WYCZTWZZVEWXOT;
/*SET*/	YJPQOUBVJSEBAL = WWTBKDOGKEMHIB;
/*INC*/	if (!INC(YJPQOUBVJSEBAL, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (YJPQOUBVJSEBAL.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	WNKSVLOIDZFPIR = YJPQOUBVJSEBAL.container->value.bracket_data.chain->at_before_first();
	WYCZTWZZVEWXOT   = YJPQOUBVJSEBAL.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_31;
/*DEF*/	DataCursor r_31;
/*SET*/	l_31 = WNKSVLOIDZFPIR;
/*SET*/	r_31 = WNKSVLOIDZFPIR;
/*JMP*/	goto label_AKUDKPEDUPKCZL_firststep;
label_AKUDKPEDUPKCZL: 
/*INC*/	if (!INC(r_31, WYCZTWZZVEWXOT)) goto sentence_after_2;
label_AKUDKPEDUPKCZL_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor HWUSKDNEVDCPLB;
/*SET*/	HWUSKDNEVDCPLB = r_31;
 if (!SLIDE(HWUSKDNEVDCPLB, WYCZTWZZVEWXOT, l_1, r_1)) goto label_AKUDKPEDUPKCZL;
//// [ e.1 ] 
/*DEF*/	DataCursor l_32;
/*DEF*/	DataCursor r_32;
/*SET*/	l_32 = HWUSKDNEVDCPLB;
/*SET*/	r_32 = WYCZTWZZVEWXOT;
//// [ empty ] 
/*ISEMPTY*/	if (YJPQOUBVJSEBAL!=0 && arg_to != YJPQOUBVJSEBAL) goto label_AKUDKPEDUPKCZL;

// подготовка подстановки 
result->append(newRefText("-O-")); 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor KLPJMPFDCYQTRC;
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	KLPJMPFDCYQTRC = arg_from;
/*INC*/	if (!INC(KLPJMPFDCYQTRC, arg_to)) goto sentence_after_3;
	if (! isSymbolType(KLPJMPFDCYQTRC.container->type)) goto sentence_after_3;
/*SET*/	r_1 = KLPJMPFDCYQTRC;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor VVVTRFFVPEKKQM;
/*DEF*/	DataCursor CUPRYJAUTEUVCZ;
/*DEF*/	DataCursor VICTHRXSXCLPRG;
/*SET*/	VVVTRFFVPEKKQM = r_1;
/*INC*/	if (!INC(VVVTRFFVPEKKQM, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (VVVTRFFVPEKKQM.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	CUPRYJAUTEUVCZ = VVVTRFFVPEKKQM.container->value.bracket_data.chain->at_before_first();
	VICTHRXSXCLPRG   = VVVTRFFVPEKKQM.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = CUPRYJAUTEUVCZ;
/*SET*/	r_2 = VICTHRXSXCLPRG;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor DLWXFAIGAYRUEI;
/*DEF*/	DataCursor CUFDIAMHTKBXOT;
/*DEF*/	DataCursor DIRXXGVZQMEYRO;
/*SET*/	DLWXFAIGAYRUEI = VVVTRFFVPEKKQM;
/*INC*/	if (!INC(DLWXFAIGAYRUEI, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (DLWXFAIGAYRUEI.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	CUFDIAMHTKBXOT = DLWXFAIGAYRUEI.container->value.bracket_data.chain->at_before_first();
	DIRXXGVZQMEYRO   = DLWXFAIGAYRUEI.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = CUFDIAMHTKBXOT;
/*SET*/	r_3 = DIRXXGVZQMEYRO;
//// [ empty ] 
/*ISEMPTY*/	if (DLWXFAIGAYRUEI!=0 && arg_to != DLWXFAIGAYRUEI) goto sentence_after_3;

// подготовка подстановки 
result->append_copy(l_1, r_1); 
result->append(newRefText("  ")); 

return result; 
}
sentence_after_3: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Switch(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor VFICHQNIVFJZAU;
/*SET*/	VFICHQNIVFJZAU = arg_from;
/*INC*/	if (!INC(VFICHQNIVFJZAU, arg_to)) goto sentence_after_1;
	if (VFICHQNIVFJZAU.container->type != integer || VFICHQNIVFJZAU.container->value.num != 0) goto sentence_after_1;
//// [ empty ] 
/*ISEMPTY*/	if (VFICHQNIVFJZAU!=0 && arg_to != VFICHQNIVFJZAU) goto sentence_after_1;

// подготовка подстановки 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor QFDFTGMOPSRGPU;
/*DEF*/	DataCursor l_G;
/*DEF*/	DataCursor r_G;
/*SET*/	l_G = arg_from;
/*SET*/	QFDFTGMOPSRGPU = arg_from;
/*INC*/	if (!INC(QFDFTGMOPSRGPU, arg_to)) goto sentence_after_2;
	if (! isSymbolType(QFDFTGMOPSRGPU.container->type)) goto sentence_after_2;
/*SET*/	r_G = QFDFTGMOPSRGPU;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor GXTUHLCVSPIHAZ;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_G;
/*SET*/	GXTUHLCVSPIHAZ = r_G;
/*INC*/	if (!INC(GXTUHLCVSPIHAZ, arg_to)) goto sentence_after_2;
	if (! isSymbolType(GXTUHLCVSPIHAZ.container->type)) goto sentence_after_2;
/*SET*/	r_A = GXTUHLCVSPIHAZ;
//// [ `a` <any> ] 
/*DEF*/	DataCursor RSSFSZWXBQMURW;
/*SET*/	RSSFSZWXBQMURW = r_A;
/*INC*/	if (!INC(RSSFSZWXBQMURW, arg_to)) goto sentence_after_2;
	if (RSSFSZWXBQMURW.container->type != text || *(RSSFSZWXBQMURW.container->value.text + RSSFSZWXBQMURW.index) != '=') goto sentence_after_2;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor MXCDBHUMRGJQMV;
/*DEF*/	DataCursor l_AA;
/*DEF*/	DataCursor r_AA;
/*SET*/	l_AA = RSSFSZWXBQMURW;
/*SET*/	MXCDBHUMRGJQMV = RSSFSZWXBQMURW;
/*INC*/	if (!INC(MXCDBHUMRGJQMV, arg_to)) goto sentence_after_2;
	if (! isSymbolType(MXCDBHUMRGJQMV.container->type)) goto sentence_after_2;
/*SET*/	r_AA = MXCDBHUMRGJQMV;
//// [ empty ] 
/*ISEMPTY*/	if (r_AA!=0 && arg_to != r_AA) goto sentence_after_2;

// подготовка подстановки 
result->append_copy(l_A, r_A); 
result->append(newRefText("=")); 
result->append_copy(l_AA, r_AA); 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor QXNJOMUYJNJUWR;
/*DEF*/	DataCursor l_G;
/*DEF*/	DataCursor r_G;
/*SET*/	l_G = arg_from;
/*SET*/	QXNJOMUYJNJUWR = arg_from;
/*INC*/	if (!INC(QXNJOMUYJNJUWR, arg_to)) goto sentence_after_3;
	if (! isSymbolType(QXNJOMUYJNJUWR.container->type)) goto sentence_after_3;
/*SET*/	r_G = QXNJOMUYJNJUWR;
//// [ &.name <any> ] 
/*DEF*/	DataCursor SYXWQYYXCSZPOK;
/*SET*/	SYXWQYYXCSZPOK = r_G;
 if (!SLIDE(SYXWQYYXCSZPOK, arg_to, l_G, r_G)) goto sentence_after_3;
//// [ `a` <any> ] 
/*DEF*/	DataCursor LWJDRLTBSCIEDP;
/*SET*/	LWJDRLTBSCIEDP = SYXWQYYXCSZPOK;
/*INC*/	if (!INC(LWJDRLTBSCIEDP, arg_to)) goto sentence_after_3;
	if (LWJDRLTBSCIEDP.container->type != text || *(LWJDRLTBSCIEDP.container->value.text + LWJDRLTBSCIEDP.index) != '=') goto sentence_after_3;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor IWLAQIGESJSQHS;
/*DEF*/	DataCursor l_AA;
/*DEF*/	DataCursor r_AA;
/*SET*/	l_AA = LWJDRLTBSCIEDP;
/*SET*/	IWLAQIGESJSQHS = LWJDRLTBSCIEDP;
/*INC*/	if (!INC(IWLAQIGESJSQHS, arg_to)) goto sentence_after_3;
	if (! isSymbolType(IWLAQIGESJSQHS.container->type)) goto sentence_after_3;
/*SET*/	r_AA = IWLAQIGESJSQHS;
//// [ &.name <any> ] 
/*DEF*/	DataCursor JLRGLMWANRXRFN;
/*SET*/	JLRGLMWANRXRFN = r_AA;
 if (!SLIDE(JLRGLMWANRXRFN, arg_to, l_G, r_G)) goto sentence_after_3;
//// [ `a` <any> ] 
/*DEF*/	DataCursor WAKZTGJHXAUNFQ;
/*SET*/	WAKZTGJHXAUNFQ = JLRGLMWANRXRFN;
/*INC*/	if (!INC(WAKZTGJHXAUNFQ, arg_to)) goto sentence_after_3;
	if (WAKZTGJHXAUNFQ.container->type != text || *(WAKZTGJHXAUNFQ.container->value.text + WAKZTGJHXAUNFQ.index) != '=') goto sentence_after_3;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor JVXIOHNJQRJSHY;
/*DEF*/	DataCursor l_BB;
/*DEF*/	DataCursor r_BB;
/*SET*/	l_BB = WAKZTGJHXAUNFQ;
/*SET*/	JVXIOHNJQRJSHY = WAKZTGJHXAUNFQ;
/*INC*/	if (!INC(JVXIOHNJQRJSHY, arg_to)) goto sentence_after_3;
	if (! isSymbolType(JVXIOHNJQRJSHY.container->type)) goto sentence_after_3;
/*SET*/	r_BB = JVXIOHNJQRJSHY;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = r_BB;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* YUYOPQJKZTVJGK = new DataChain(); 
result->append(newRefExecBrackets(Switch, YUYOPQJKZTVJGK, "Switch")); 
YUYOPQJKZTVJGK->append_copy(l_G, r_G); 
YUYOPQJKZTVJGK->append_copy(l_G, r_G); 
YUYOPQJKZTVJGK->append(newRefText("=")); 
DataChain* WXKEWPZHBJSUTH = new DataChain(); 
YUYOPQJKZTVJGK->append(newRefExecBrackets(Maix, WXKEWPZHBJSUTH, "Maix")); 
WXKEWPZHBJSUTH->append(newRefText("a")); 
WXKEWPZHBJSUTH->append_copy(l_AA, r_AA); 
WXKEWPZHBJSUTH->append_copy(l_BB, r_BB); 
DataChain* SYOEFJGWWYEOZL = new DataChain(); 
WXKEWPZHBJSUTH->append(newRefExecBrackets(Compare, SYOEFJGWWYEOZL, "Compare")); 
SYOEFJGWWYEOZL->append_copy(l_AA, r_AA); 
SYOEFJGWWYEOZL->append_copy(l_BB, r_BB); 
YUYOPQJKZTVJGK->append_copy(l_e, r_e); 

return result; 
}
sentence_after_3: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor UHMGABBSQRHCRT;
/*DEF*/	DataCursor l_G;
/*DEF*/	DataCursor r_G;
/*SET*/	l_G = arg_from;
/*SET*/	UHMGABBSQRHCRT = arg_from;
/*INC*/	if (!INC(UHMGABBSQRHCRT, arg_to)) goto sentence_after_4;
	if (! isSymbolType(UHMGABBSQRHCRT.container->type)) goto sentence_after_4;
/*SET*/	r_G = UHMGABBSQRHCRT;
//// [ &.name <any> ] 
/*DEF*/	DataCursor XMJVCAXXSUFAHY;
/*SET*/	XMJVCAXXSUFAHY = r_G;
 if (!SLIDE(XMJVCAXXSUFAHY, arg_to, l_G, r_G)) goto sentence_after_4;
//// [ `a` <any> ] 
/*DEF*/	DataCursor YAYZKHUHJRJSVO;
/*SET*/	YAYZKHUHJRJSVO = XMJVCAXXSUFAHY;
/*INC*/	if (!INC(YAYZKHUHJRJSVO, arg_to)) goto sentence_after_4;
	if (YAYZKHUHJRJSVO.container->type != text || *(YAYZKHUHJRJSVO.container->value.text + YAYZKHUHJRJSVO.index) != '=') goto sentence_after_4;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor QHTYDWPBSZXSBZ;
/*DEF*/	DataCursor l_AA;
/*DEF*/	DataCursor r_AA;
/*SET*/	l_AA = YAYZKHUHJRJSVO;
/*SET*/	QHTYDWPBSZXSBZ = YAYZKHUHJRJSVO;
/*INC*/	if (!INC(QHTYDWPBSZXSBZ, arg_to)) goto sentence_after_4;
	if (! isSymbolType(QHTYDWPBSZXSBZ.container->type)) goto sentence_after_4;
/*SET*/	r_AA = QHTYDWPBSZXSBZ;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor IYRVGQMLUNWSCP;
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = r_AA;
/*SET*/	IYRVGQMLUNWSCP = r_AA;
/*INC*/	if (!INC(IYRVGQMLUNWSCP, arg_to)) goto sentence_after_4;
	if (! isSymbolType(IYRVGQMLUNWSCP.container->type)) goto sentence_after_4;
/*SET*/	r_s = IYRVGQMLUNWSCP;
//// [ `a` <any> ] 
/*DEF*/	DataCursor IRZFCBTSEPLKGW;
/*SET*/	IRZFCBTSEPLKGW = r_s;
/*INC*/	if (!INC(IRZFCBTSEPLKGW, arg_to)) goto sentence_after_4;
	if (IRZFCBTSEPLKGW.container->type != text || *(IRZFCBTSEPLKGW.container->value.text + IRZFCBTSEPLKGW.index) != '=') goto sentence_after_4;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor FKHROUOYSRWMQO;
/*DEF*/	DataCursor l_BB;
/*DEF*/	DataCursor r_BB;
/*SET*/	l_BB = IRZFCBTSEPLKGW;
/*SET*/	FKHROUOYSRWMQO = IRZFCBTSEPLKGW;
/*INC*/	if (!INC(FKHROUOYSRWMQO, arg_to)) goto sentence_after_4;
	if (! isSymbolType(FKHROUOYSRWMQO.container->type)) goto sentence_after_4;
/*SET*/	r_BB = FKHROUOYSRWMQO;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = r_BB;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* PRSKWGXULSUCKB = new DataChain(); 
result->append(newRefExecBrackets(Switch, PRSKWGXULSUCKB, "Switch")); 
PRSKWGXULSUCKB->append_copy(l_G, r_G); 
PRSKWGXULSUCKB->append_copy(l_G, r_G); 
PRSKWGXULSUCKB->append(newRefText("=")); 
PRSKWGXULSUCKB->append_copy(l_AA, r_AA); 
PRSKWGXULSUCKB->append_copy(l_e, r_e); 

return result; 
}
sentence_after_4: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor SEPJEISZSGCEZW;
/*DEF*/	DataCursor l_G;
/*DEF*/	DataCursor r_G;
/*SET*/	l_G = arg_from;
/*SET*/	SEPJEISZSGCEZW = arg_from;
/*INC*/	if (!INC(SEPJEISZSGCEZW, arg_to)) goto sentence_after_5;
	if (! isSymbolType(SEPJEISZSGCEZW.container->type)) goto sentence_after_5;
/*SET*/	r_G = SEPJEISZSGCEZW;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor APQRVLWIGROVJC;
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = r_G;
/*SET*/	APQRVLWIGROVJC = r_G;
/*INC*/	if (!INC(APQRVLWIGROVJC, arg_to)) goto sentence_after_5;
	if (! isSymbolType(APQRVLWIGROVJC.container->type)) goto sentence_after_5;
/*SET*/	r_s = APQRVLWIGROVJC;
//// [ `a` <any> ] 
/*DEF*/	DataCursor DZXXPHQLSRZIHM;
/*SET*/	DZXXPHQLSRZIHM = r_s;
/*INC*/	if (!INC(DZXXPHQLSRZIHM, arg_to)) goto sentence_after_5;
	if (DZXXPHQLSRZIHM.container->type != text || *(DZXXPHQLSRZIHM.container->value.text + DZXXPHQLSRZIHM.index) != '=') goto sentence_after_5;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor GZRIOQRQETKZFB;
/*DEF*/	DataCursor l_AA;
/*DEF*/	DataCursor r_AA;
/*SET*/	l_AA = DZXXPHQLSRZIHM;
/*SET*/	GZRIOQRQETKZFB = DZXXPHQLSRZIHM;
/*INC*/	if (!INC(GZRIOQRQETKZFB, arg_to)) goto sentence_after_5;
	if (! isSymbolType(GZRIOQRQETKZFB.container->type)) goto sentence_after_5;
/*SET*/	r_AA = GZRIOQRQETKZFB;
//// [ &.name <any> ] 
/*DEF*/	DataCursor LDJIEMSFZBHZFN;
/*SET*/	LDJIEMSFZBHZFN = r_AA;
 if (!SLIDE(LDJIEMSFZBHZFN, arg_to, l_G, r_G)) goto sentence_after_5;
//// [ `a` <any> ] 
/*DEF*/	DataCursor WYWMXXGDPYLRAX;
/*SET*/	WYWMXXGDPYLRAX = LDJIEMSFZBHZFN;
/*INC*/	if (!INC(WYWMXXGDPYLRAX, arg_to)) goto sentence_after_5;
	if (WYWMXXGDPYLRAX.container->type != text || *(WYWMXXGDPYLRAX.container->value.text + WYWMXXGDPYLRAX.index) != '=') goto sentence_after_5;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor GLMTBIYLBHCWHL;
/*DEF*/	DataCursor l_BB;
/*DEF*/	DataCursor r_BB;
/*SET*/	l_BB = WYWMXXGDPYLRAX;
/*SET*/	GLMTBIYLBHCWHL = WYWMXXGDPYLRAX;
/*INC*/	if (!INC(GLMTBIYLBHCWHL, arg_to)) goto sentence_after_5;
	if (! isSymbolType(GLMTBIYLBHCWHL.container->type)) goto sentence_after_5;
/*SET*/	r_BB = GLMTBIYLBHCWHL;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = r_BB;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* JQBZXTHTOPOTMI = new DataChain(); 
result->append(newRefExecBrackets(Switch, JQBZXTHTOPOTMI, "Switch")); 
JQBZXTHTOPOTMI->append_copy(l_G, r_G); 
JQBZXTHTOPOTMI->append_copy(l_G, r_G); 
JQBZXTHTOPOTMI->append(newRefText("=")); 
JQBZXTHTOPOTMI->append_copy(l_BB, r_BB); 
JQBZXTHTOPOTMI->append_copy(l_e, r_e); 

return result; 
}
sentence_after_5: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor TNQWTOETONXWZG;
/*DEF*/	DataCursor l_G;
/*DEF*/	DataCursor r_G;
/*SET*/	l_G = arg_from;
/*SET*/	TNQWTOETONXWZG = arg_from;
/*INC*/	if (!INC(TNQWTOETONXWZG, arg_to)) goto sentence_after_6;
	if (! isSymbolType(TNQWTOETONXWZG.container->type)) goto sentence_after_6;
/*SET*/	r_G = TNQWTOETONXWZG;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor HUTIFKLGKLRNUW;
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = r_G;
/*SET*/	HUTIFKLGKLRNUW = r_G;
/*INC*/	if (!INC(HUTIFKLGKLRNUW, arg_to)) goto sentence_after_6;
	if (! isSymbolType(HUTIFKLGKLRNUW.container->type)) goto sentence_after_6;
/*SET*/	r_s = HUTIFKLGKLRNUW;
//// [ `a` <any> ] 
/*DEF*/	DataCursor KMSYQCPUIVAHQA;
/*SET*/	KMSYQCPUIVAHQA = r_s;
/*INC*/	if (!INC(KMSYQCPUIVAHQA, arg_to)) goto sentence_after_6;
	if (KMSYQCPUIVAHQA.container->type != text || *(KMSYQCPUIVAHQA.container->value.text + KMSYQCPUIVAHQA.index) != '=') goto sentence_after_6;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor TMSCKMAALKICSN;
/*DEF*/	DataCursor l_AA;
/*DEF*/	DataCursor r_AA;
/*SET*/	l_AA = KMSYQCPUIVAHQA;
/*SET*/	TMSCKMAALKICSN = KMSYQCPUIVAHQA;
/*INC*/	if (!INC(TMSCKMAALKICSN, arg_to)) goto sentence_after_6;
	if (! isSymbolType(TMSCKMAALKICSN.container->type)) goto sentence_after_6;
/*SET*/	r_AA = TMSCKMAALKICSN;
//// [ &.name <any> ] 
/*DEF*/	DataCursor XUCOVTYKRXAWZA;
/*SET*/	XUCOVTYKRXAWZA = r_AA;
 if (!SLIDE(XUCOVTYKRXAWZA, arg_to, l_s, r_s)) goto sentence_after_6;
//// [ `a` <any> ] 
/*DEF*/	DataCursor DJXWXQMNDHLDTT;
/*SET*/	DJXWXQMNDHLDTT = XUCOVTYKRXAWZA;
/*INC*/	if (!INC(DJXWXQMNDHLDTT, arg_to)) goto sentence_after_6;
	if (DJXWXQMNDHLDTT.container->type != text || *(DJXWXQMNDHLDTT.container->value.text + DJXWXQMNDHLDTT.index) != '=') goto sentence_after_6;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor XSKNXTEZNJSQTF;
/*DEF*/	DataCursor l_BB;
/*DEF*/	DataCursor r_BB;
/*SET*/	l_BB = DJXWXQMNDHLDTT;
/*SET*/	XSKNXTEZNJSQTF = DJXWXQMNDHLDTT;
/*INC*/	if (!INC(XSKNXTEZNJSQTF, arg_to)) goto sentence_after_6;
	if (! isSymbolType(XSKNXTEZNJSQTF.container->type)) goto sentence_after_6;
/*SET*/	r_BB = XSKNXTEZNJSQTF;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = r_BB;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* KWYWTTJZPPKWLB = new DataChain(); 
result->append(newRefExecBrackets(Switch, KWYWTTJZPPKWLB, "Switch")); 
KWYWTTJZPPKWLB->append_copy(l_G, r_G); 
KWYWTTJZPPKWLB->append_copy(l_s, r_s); 
KWYWTTJZPPKWLB->append(newRefText("=")); 
DataChain* MJAHTPUTIEBPBB = new DataChain(); 
KWYWTTJZPPKWLB->append(newRefExecBrackets(Maix, MJAHTPUTIEBPBB, "Maix")); 
MJAHTPUTIEBPBB->append(newRefText("i")); 
MJAHTPUTIEBPBB->append_copy(l_AA, r_AA); 
MJAHTPUTIEBPBB->append_copy(l_BB, r_BB); 
DataChain* MUEGYRHLTHXWGJ = new DataChain(); 
MJAHTPUTIEBPBB->append(newRefExecBrackets(Compare, MUEGYRHLTHXWGJ, "Compare")); 
MUEGYRHLTHXWGJ->append_copy(l_AA, r_AA); 
MUEGYRHLTHXWGJ->append_copy(l_BB, r_BB); 
KWYWTTJZPPKWLB->append_copy(l_e, r_e); 

return result; 
}
sentence_after_6: 

{
// подготовка предложения 
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = arg_from;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* PRWVHSHZYAVQYE = new DataChain(); 
result->append(newRefExecBrackets(Prout, PRWVHSHZYAVQYE, "Prout")); 
PRWVHSHZYAVQYE->append(newRefText("Sw unk: ")); 
PRWVHSHZYAVQYE->append_copy(l_e, r_e); 

return result; 
}
sentence_after_7: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Maix(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor CZTOZOABNANHRR;
/*SET*/	CZTOZOABNANHRR = arg_from;
/*INC*/	if (!INC(CZTOZOABNANHRR, arg_to)) goto sentence_after_1;
	if (CZTOZOABNANHRR.container->type != text || *(CZTOZOABNANHRR.container->value.text + CZTOZOABNANHRR.index) != 'a') goto sentence_after_1;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor BDDNDODXEUIOZI;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = CZTOZOABNANHRR;
/*SET*/	BDDNDODXEUIOZI = CZTOZOABNANHRR;
/*INC*/	if (!INC(BDDNDODXEUIOZI, arg_to)) goto sentence_after_1;
	if (! isSymbolType(BDDNDODXEUIOZI.container->type)) goto sentence_after_1;
/*SET*/	r_A = BDDNDODXEUIOZI;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor OIUOZXQTIHWAUR;
/*DEF*/	DataCursor l_B;
/*DEF*/	DataCursor r_B;
/*SET*/	l_B = r_A;
/*SET*/	OIUOZXQTIHWAUR = r_A;
/*INC*/	if (!INC(OIUOZXQTIHWAUR, arg_to)) goto sentence_after_1;
	if (! isSymbolType(OIUOZXQTIHWAUR.container->type)) goto sentence_after_1;
/*SET*/	r_B = OIUOZXQTIHWAUR;
//// [ `a` <any> ] 
/*DEF*/	DataCursor OQRDQWCVLXZIPO;
/*SET*/	OQRDQWCVLXZIPO = r_B;
/*INC*/	if (!INC(OQRDQWCVLXZIPO, arg_to)) goto sentence_after_1;
	if (OQRDQWCVLXZIPO.container->type != text || *(OQRDQWCVLXZIPO.container->value.text + OQRDQWCVLXZIPO.index) != '-') goto sentence_after_1;
//// [ empty ] 
/*ISEMPTY*/	if (OQRDQWCVLXZIPO!=0 && arg_to != OQRDQWCVLXZIPO) goto sentence_after_1;

// подготовка подстановки 
result->append_copy(l_B, r_B); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor QQTMIUUYVGAIHF;
/*SET*/	QQTMIUUYVGAIHF = arg_from;
/*INC*/	if (!INC(QQTMIUUYVGAIHF, arg_to)) goto sentence_after_2;
	if (QQTMIUUYVGAIHF.container->type != text || *(QQTMIUUYVGAIHF.container->value.text + QQTMIUUYVGAIHF.index) != 'a') goto sentence_after_2;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor SHCCXHUUYYHTGD;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = QQTMIUUYVGAIHF;
/*SET*/	SHCCXHUUYYHTGD = QQTMIUUYVGAIHF;
/*INC*/	if (!INC(SHCCXHUUYYHTGD, arg_to)) goto sentence_after_2;
	if (! isSymbolType(SHCCXHUUYYHTGD.container->type)) goto sentence_after_2;
/*SET*/	r_A = SHCCXHUUYYHTGD;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor GLFCIEBDUTOEUN;
/*DEF*/	DataCursor l_B;
/*DEF*/	DataCursor r_B;
/*SET*/	l_B = r_A;
/*SET*/	GLFCIEBDUTOEUN = r_A;
/*INC*/	if (!INC(GLFCIEBDUTOEUN, arg_to)) goto sentence_after_2;
	if (! isSymbolType(GLFCIEBDUTOEUN.container->type)) goto sentence_after_2;
/*SET*/	r_B = GLFCIEBDUTOEUN;
//// [ `a` <any> ] 
/*DEF*/	DataCursor FHDAXPHBSYWZTP;
/*SET*/	FHDAXPHBSYWZTP = r_B;
/*INC*/	if (!INC(FHDAXPHBSYWZTP, arg_to)) goto sentence_after_2;
	if (FHDAXPHBSYWZTP.container->type != text || *(FHDAXPHBSYWZTP.container->value.text + FHDAXPHBSYWZTP.index) != '+') goto sentence_after_2;
//// [ empty ] 
/*ISEMPTY*/	if (FHDAXPHBSYWZTP!=0 && arg_to != FHDAXPHBSYWZTP) goto sentence_after_2;

// подготовка подстановки 
result->append_copy(l_A, r_A); 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor MMKWDEHFKRUQBY;
/*SET*/	MMKWDEHFKRUQBY = arg_from;
/*INC*/	if (!INC(MMKWDEHFKRUQBY, arg_to)) goto sentence_after_3;
	if (MMKWDEHFKRUQBY.container->type != text || *(MMKWDEHFKRUQBY.container->value.text + MMKWDEHFKRUQBY.index) != 'i') goto sentence_after_3;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor VECMPESROMDXLL;
/*DEF*/	DataCursor l_B;
/*DEF*/	DataCursor r_B;
/*SET*/	l_B = MMKWDEHFKRUQBY;
/*SET*/	VECMPESROMDXLL = MMKWDEHFKRUQBY;
/*INC*/	if (!INC(VECMPESROMDXLL, arg_to)) goto sentence_after_3;
	if (! isSymbolType(VECMPESROMDXLL.container->type)) goto sentence_after_3;
/*SET*/	r_B = VECMPESROMDXLL;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor UBRYYESHQLZMRE;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_B;
/*SET*/	UBRYYESHQLZMRE = r_B;
/*INC*/	if (!INC(UBRYYESHQLZMRE, arg_to)) goto sentence_after_3;
	if (! isSymbolType(UBRYYESHQLZMRE.container->type)) goto sentence_after_3;
/*SET*/	r_A = UBRYYESHQLZMRE;
//// [ `a` <any> ] 
/*DEF*/	DataCursor WQNKQITXGIIGQU;
/*SET*/	WQNKQITXGIIGQU = r_A;
/*INC*/	if (!INC(WQNKQITXGIIGQU, arg_to)) goto sentence_after_3;
	if (WQNKQITXGIIGQU.container->type != text || *(WQNKQITXGIIGQU.container->value.text + WQNKQITXGIIGQU.index) != '-') goto sentence_after_3;
//// [ empty ] 
/*ISEMPTY*/	if (WQNKQITXGIIGQU!=0 && arg_to != WQNKQITXGIIGQU) goto sentence_after_3;

// подготовка подстановки 
result->append_copy(l_B, r_B); 

return result; 
}
sentence_after_3: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor WZZTDJPQSUOWKV;
/*SET*/	WZZTDJPQSUOWKV = arg_from;
/*INC*/	if (!INC(WZZTDJPQSUOWKV, arg_to)) goto sentence_after_4;
	if (WZZTDJPQSUOWKV.container->type != text || *(WZZTDJPQSUOWKV.container->value.text + WZZTDJPQSUOWKV.index) != 'i') goto sentence_after_4;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor FCCOCKVRJBFRJP;
/*DEF*/	DataCursor l_B;
/*DEF*/	DataCursor r_B;
/*SET*/	l_B = WZZTDJPQSUOWKV;
/*SET*/	FCCOCKVRJBFRJP = WZZTDJPQSUOWKV;
/*INC*/	if (!INC(FCCOCKVRJBFRJP, arg_to)) goto sentence_after_4;
	if (! isSymbolType(FCCOCKVRJBFRJP.container->type)) goto sentence_after_4;
/*SET*/	r_B = FCCOCKVRJBFRJP;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor CGDJDRWDNPOSRJ;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_B;
/*SET*/	CGDJDRWDNPOSRJ = r_B;
/*INC*/	if (!INC(CGDJDRWDNPOSRJ, arg_to)) goto sentence_after_4;
	if (! isSymbolType(CGDJDRWDNPOSRJ.container->type)) goto sentence_after_4;
/*SET*/	r_A = CGDJDRWDNPOSRJ;
//// [ `a` <any> ] 
/*DEF*/	DataCursor GDRQRVQTVPPAZH;
/*SET*/	GDRQRVQTVPPAZH = r_A;
/*INC*/	if (!INC(GDRQRVQTVPPAZH, arg_to)) goto sentence_after_4;
	if (GDRQRVQTVPPAZH.container->type != text || *(GDRQRVQTVPPAZH.container->value.text + GDRQRVQTVPPAZH.index) != '+') goto sentence_after_4;
//// [ empty ] 
/*ISEMPTY*/	if (GDRQRVQTVPPAZH!=0 && arg_to != GDRQRVQTVPPAZH) goto sentence_after_4;

// подготовка подстановки 
result->append_copy(l_A, r_A); 

return result; 
}
sentence_after_4: 

{
// подготовка предложения 
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = arg_from;
/*SET*/	r_e = arg_from;
/*JMP*/	goto label_HHWEWNVCBVDKUZ_firststep;
label_HHWEWNVCBVDKUZ: 
/*INC*/	if (!INC(r_e, arg_to)) goto sentence_after_5;
label_HHWEWNVCBVDKUZ_firststep: 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor IFIFRTWQQEOJUE;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_e;
/*SET*/	IFIFRTWQQEOJUE = r_e;
/*INC*/	if (!INC(IFIFRTWQQEOJUE, arg_to)) goto label_HHWEWNVCBVDKUZ;
	if (! isSymbolType(IFIFRTWQQEOJUE.container->type)) goto label_HHWEWNVCBVDKUZ;
/*SET*/	r_A = IFIFRTWQQEOJUE;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor QBNSKWZEEWZKAO;
/*DEF*/	DataCursor l_zn;
/*DEF*/	DataCursor r_zn;
/*SET*/	l_zn = r_A;
/*SET*/	QBNSKWZEEWZKAO = r_A;
/*INC*/	if (!INC(QBNSKWZEEWZKAO, arg_to)) goto label_HHWEWNVCBVDKUZ;
	if (! isSymbolType(QBNSKWZEEWZKAO.container->type)) goto label_HHWEWNVCBVDKUZ;
/*SET*/	r_zn = QBNSKWZEEWZKAO;
//// [ empty ] 
/*ISEMPTY*/	if (r_zn!=0 && arg_to != r_zn) goto label_HHWEWNVCBVDKUZ;

// подготовка подстановки 
result->append_copy(l_A, r_A); 

return result; 
}
sentence_after_5: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* WriteXO__(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = arg_from;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* JURSQGSCZVHHUJ = new DataChain(); 
result->append(newRefExecBrackets(Prout, JURSQGSCZVHHUJ, "Prout")); 
JURSQGSCZVHHUJ->append(newRefWord("WriteXO:")); 
JURSQGSCZVHHUJ->append_copy(l_e, r_e); 
DataChain* ZUMIGOFHWBKKFL = new DataChain(); 
result->append(newRefExecBrackets(WriteXO__, ZUMIGOFHWBKKFL, "WriteXO__")); 
ZUMIGOFHWBKKFL->append_copy(l_e, r_e); 

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* WriteXO(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ empty ] 
/*ISEMPTY*/	if (arg_from!=0 && arg_to != arg_from) goto sentence_after_1;

// подготовка подстановки 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor UWZKCTKAGXKSMF;
/*DEF*/	DataCursor AUWINSJLSOJTRX;
/*DEF*/	DataCursor HWMHLVBYPECJEI;
/*SET*/	UWZKCTKAGXKSMF = arg_from;
/*INC*/	if (!INC(UWZKCTKAGXKSMF, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (UWZKCTKAGXKSMF.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	AUWINSJLSOJTRX = UWZKCTKAGXKSMF.container->value.bracket_data.chain->at_before_first();
	HWMHLVBYPECJEI   = UWZKCTKAGXKSMF.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor WWSTNEUIQUBPGU;
/*DEF*/	DataCursor l_g;
/*DEF*/	DataCursor r_g;
/*SET*/	l_g = AUWINSJLSOJTRX;
/*SET*/	WWSTNEUIQUBPGU = AUWINSJLSOJTRX;
/*INC*/	if (!INC(WWSTNEUIQUBPGU, HWMHLVBYPECJEI)) goto sentence_after_2;
	if (! isSymbolType(WWSTNEUIQUBPGU.container->type)) goto sentence_after_2;
/*SET*/	r_g = WWSTNEUIQUBPGU;
//// [ empty ] 
/*ISEMPTY*/	if (r_g!=0 && HWMHLVBYPECJEI != r_g) goto sentence_after_2;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor GWGNMIKDWICKDI;
/*DEF*/	DataCursor LSNPDQSVMTERDF;
/*DEF*/	DataCursor BLHWBAFBGARCSF;
/*SET*/	GWGNMIKDWICKDI = UWZKCTKAGXKSMF;
/*INC*/	if (!INC(GWGNMIKDWICKDI, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (GWGNMIKDWICKDI.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	LSNPDQSVMTERDF = GWGNMIKDWICKDI.container->value.bracket_data.chain->at_before_first();
	BLHWBAFBGARCSF   = GWGNMIKDWICKDI.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = LSNPDQSVMTERDF;
/*SET*/	r_1 = BLHWBAFBGARCSF;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor IJYLBIIMOFGXEI;
/*DEF*/	DataCursor RPBTYWQZAPKKCA;
/*DEF*/	DataCursor FCOMVNTMDHZXLE;
/*SET*/	IJYLBIIMOFGXEI = GWGNMIKDWICKDI;
/*INC*/	if (!INC(IJYLBIIMOFGXEI, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (IJYLBIIMOFGXEI.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	RPBTYWQZAPKKCA = IJYLBIIMOFGXEI.container->value.bracket_data.chain->at_before_first();
	FCOMVNTMDHZXLE   = IJYLBIIMOFGXEI.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = RPBTYWQZAPKKCA;
/*SET*/	r_2 = FCOMVNTMDHZXLE;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor FPPYEBEOEQZNBH;
/*DEF*/	DataCursor YCWMFYAQQIANNY;
/*DEF*/	DataCursor HQOUIZVEAVGZJW;
/*SET*/	FPPYEBEOEQZNBH = IJYLBIIMOFGXEI;
/*INC*/	if (!INC(FPPYEBEOEQZNBH, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (FPPYEBEOEQZNBH.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	YCWMFYAQQIANNY = FPPYEBEOEQZNBH.container->value.bracket_data.chain->at_before_first();
	HQOUIZVEAVGZJW   = FPPYEBEOEQZNBH.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = YCWMFYAQQIANNY;
/*SET*/	r_n = HQOUIZVEAVGZJW;
//// [ empty ] 
/*ISEMPTY*/	if (FPPYEBEOEQZNBH!=0 && arg_to != FPPYEBEOEQZNBH) goto sentence_after_2;

// подготовка подстановки 
DataChain* OBLSGWNKVJLNIV = new DataChain(); 
result->append(newRefExecBrackets(WXOif, OBLSGWNKVJLNIV, "WXOif")); 
DataChain* QCWVZXTCTHYNMU = new DataChain(); 
OBLSGWNKVJLNIV->append(newRefStructBrackets(QCWVZXTCTHYNMU)); 
QCWVZXTCTHYNMU->append_copy(l_g, r_g); 
DataChain* XQKWWMTFISGGLG = new DataChain(); 
OBLSGWNKVJLNIV->append(newRefStructBrackets(XQKWWMTFISGGLG)); 
DataChain* COXPIPYTDBAMRY = new DataChain(); 
XQKWWMTFISGGLG->append(newRefExecBrackets(Strategy, COXPIPYTDBAMRY, "Strategy")); 
COXPIPYTDBAMRY->append_copy(l_1, r_1); 
DataChain* KBOKMWGSDDPQKR = new DataChain(); 
OBLSGWNKVJLNIV->append(newRefStructBrackets(KBOKMWGSDDPQKR)); 
DataChain* ZYJCHZTMIEPAGW = new DataChain(); 
KBOKMWGSDDPQKR->append(newRefExecBrackets(Strategy, ZYJCHZTMIEPAGW, "Strategy")); 
ZYJCHZTMIEPAGW->append_copy(l_2, r_2); 
DataChain* HROQKHWUDBCIHP = new DataChain(); 
OBLSGWNKVJLNIV->append(newRefStructBrackets(HROQKHWUDBCIHP)); 
DataChain* QWAQZXUGKVAKVL = new DataChain(); 
HROQKHWUDBCIHP->append(newRefExecBrackets(Strategy, QWAQZXUGKVAKVL, "Strategy")); 
QWAQZXUGKVAKVL->append_copy(l_n, r_n); 
DataChain* AVKSWFZSDBVQID = new DataChain(); 
OBLSGWNKVJLNIV->append(newRefStructBrackets(AVKSWFZSDBVQID)); 
AVKSWFZSDBVQID->append_copy(l_1, r_1); 
DataChain* HTBCDEYTMPPHKU = new DataChain(); 
OBLSGWNKVJLNIV->append(newRefStructBrackets(HTBCDEYTMPPHKU)); 
HTBCDEYTMPPHKU->append_copy(l_2, r_2); 
DataChain* HSXORPUFWHJRUT = new DataChain(); 
OBLSGWNKVJLNIV->append(newRefStructBrackets(HSXORPUFWHJRUT)); 
HSXORPUFWHJRUT->append_copy(l_n, r_n); 

return result; 
}
sentence_after_2: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* WXOif__(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = arg_from;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* KSSLHLRXLYDXVK = new DataChain(); 
result->append(newRefExecBrackets(Prout, KSSLHLRXLYDXVK, "Prout")); 
KSSLHLRXLYDXVK->append(newRefWord("WXOif:")); 
KSSLHLRXLYDXVK->append_copy(l_e, r_e); 
DataChain* OSAGGMPBGZVBAF = new DataChain(); 
result->append(newRefExecBrackets(WXOif__, OSAGGMPBGZVBAF, "WXOif__")); 
OSAGGMPBGZVBAF->append_copy(l_e, r_e); 

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* WXOif(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor AZJOHQSSWTORCK;
/*DEF*/	DataCursor QAXSREHNRLYJIW;
/*DEF*/	DataCursor TMHGLKOZFKMMXT;
/*SET*/	AZJOHQSSWTORCK = arg_from;
/*INC*/	if (!INC(AZJOHQSSWTORCK, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (AZJOHQSSWTORCK.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	QAXSREHNRLYJIW = AZJOHQSSWTORCK.container->value.bracket_data.chain->at_before_first();
	TMHGLKOZFKMMXT   = AZJOHQSSWTORCK.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor YVOXHFKXOPVYBJ;
/*SET*/	YVOXHFKXOPVYBJ = QAXSREHNRLYJIW;
/*INC*/	if (!INC(YVOXHFKXOPVYBJ, TMHGLKOZFKMMXT)) goto sentence_after_1;
	if (YVOXHFKXOPVYBJ.container->type != text || *(YVOXHFKXOPVYBJ.container->value.text + YVOXHFKXOPVYBJ.index) != '1') goto sentence_after_1;
//// [ empty ] 
/*ISEMPTY*/	if (YVOXHFKXOPVYBJ!=0 && TMHGLKOZFKMMXT != YVOXHFKXOPVYBJ) goto sentence_after_1;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_eee1;
/*DEF*/	DataCursor r_eee1;
/*SET*/	l_eee1 = AZJOHQSSWTORCK;
/*SET*/	r_eee1 = AZJOHQSSWTORCK;
/*JMP*/	goto label_OTTCJTUEGMPQKC_firststep;
label_OTTCJTUEGMPQKC: 
/*INC*/	if (!INC(r_eee1, arg_to)) goto sentence_after_1;
label_OTTCJTUEGMPQKC_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor DBBGCKJQTEBICH;
/*DEF*/	DataCursor ZNPPRQISWBDHOY;
/*DEF*/	DataCursor NCSAETLGBFVIOC;
/*SET*/	DBBGCKJQTEBICH = r_eee1;
/*INC*/	if (!INC(DBBGCKJQTEBICH, arg_to)) goto label_OTTCJTUEGMPQKC;
//// ISBRACKET 
	if (DBBGCKJQTEBICH.container->type != struct_bracket) goto label_OTTCJTUEGMPQKC;
//// JMP_BRACKET 
	ZNPPRQISWBDHOY = DBBGCKJQTEBICH.container->value.bracket_data.chain->at_before_first();
	NCSAETLGBFVIOC   = DBBGCKJQTEBICH.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = ZNPPRQISWBDHOY;
/*SET*/	r_1 = ZNPPRQISWBDHOY;
/*JMP*/	goto label_FWXWDRNLFFBFHV_firststep;
label_FWXWDRNLFFBFHV: 
/*INC*/	if (!INC(r_1, NCSAETLGBFVIOC)) goto label_OTTCJTUEGMPQKC;
label_FWXWDRNLFFBFHV_firststep: 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor YXZUKJWOCYHZQJ;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_1;
/*SET*/	YXZUKJWOCYHZQJ = r_1;
/*INC*/	if (!INC(YXZUKJWOCYHZQJ, NCSAETLGBFVIOC)) goto label_FWXWDRNLFFBFHV;
	if (! isSymbolType(YXZUKJWOCYHZQJ.container->type)) goto label_FWXWDRNLFFBFHV;
/*SET*/	r_A = YXZUKJWOCYHZQJ;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = r_A;
/*SET*/	r_2 = r_A;
/*JMP*/	goto label_ZDHTBRRRLLKTCH_firststep;
label_ZDHTBRRRLLKTCH: 
/*INC*/	if (!INC(r_2, NCSAETLGBFVIOC)) goto label_FWXWDRNLFFBFHV;
label_ZDHTBRRRLLKTCH_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor FNCTPIRNAWONYD;
/*SET*/	FNCTPIRNAWONYD = r_2;
 if (!SLIDE(FNCTPIRNAWONYD, NCSAETLGBFVIOC, l_A, r_A)) goto label_ZDHTBRRRLLKTCH;
//// [ e.1 ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = FNCTPIRNAWONYD;
/*SET*/	r_3 = NCSAETLGBFVIOC;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_eee2;
/*DEF*/	DataCursor r_eee2;
/*SET*/	l_eee2 = DBBGCKJQTEBICH;
/*SET*/	r_eee2 = DBBGCKJQTEBICH;
/*JMP*/	goto label_WWVUABUQCIMCNL_firststep;
label_WWVUABUQCIMCNL: 
/*INC*/	if (!INC(r_eee2, arg_to)) goto label_ZDHTBRRRLLKTCH;
label_WWVUABUQCIMCNL_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor HQODEMAKMUNMAX;
/*DEF*/	DataCursor IOMKEYWCOFQBKD;
/*DEF*/	DataCursor MZOIZGQIPZAYIX;
/*SET*/	HQODEMAKMUNMAX = r_eee2;
/*INC*/	if (!INC(HQODEMAKMUNMAX, arg_to)) goto label_WWVUABUQCIMCNL;
//// ISBRACKET 
	if (HQODEMAKMUNMAX.container->type != struct_bracket) goto label_WWVUABUQCIMCNL;
//// JMP_BRACKET 
	IOMKEYWCOFQBKD = HQODEMAKMUNMAX.container->value.bracket_data.chain->at_before_first();
	MZOIZGQIPZAYIX   = HQODEMAKMUNMAX.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_n1;
/*DEF*/	DataCursor r_n1;
/*SET*/	l_n1 = IOMKEYWCOFQBKD;
/*SET*/	r_n1 = IOMKEYWCOFQBKD;
/*JMP*/	goto label_RYDWSOVHZTKGZS_firststep;
label_RYDWSOVHZTKGZS: 
/*INC*/	if (!INC(r_n1, MZOIZGQIPZAYIX)) goto label_WWVUABUQCIMCNL;
label_RYDWSOVHZTKGZS_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor KWPTKQCEXRNNXS;
/*SET*/	KWPTKQCEXRNNXS = r_n1;
 if (!SLIDE(KWPTKQCEXRNNXS, MZOIZGQIPZAYIX, l_A, r_A)) goto label_RYDWSOVHZTKGZS;
//// [ e.1 ] 
/*DEF*/	DataCursor l_n2;
/*DEF*/	DataCursor r_n2;
/*SET*/	l_n2 = KWPTKQCEXRNNXS;
/*SET*/	r_n2 = MZOIZGQIPZAYIX;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor KYWNDQIZLZKLNI;
/*DEF*/	DataCursor SSAMQAZHLNDNVI;
/*DEF*/	DataCursor LTKOIAFMEICGGU;
/*SET*/	KYWNDQIZLZKLNI = HQODEMAKMUNMAX;
/*INC*/	if (!INC(KYWNDQIZLZKLNI, arg_to)) goto label_RYDWSOVHZTKGZS;
//// ISBRACKET 
	if (KYWNDQIZLZKLNI.container->type != struct_bracket) goto label_RYDWSOVHZTKGZS;
//// JMP_BRACKET 
	SSAMQAZHLNDNVI = KYWNDQIZLZKLNI.container->value.bracket_data.chain->at_before_first();
	LTKOIAFMEICGGU   = KYWNDQIZLZKLNI.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_e1;
/*DEF*/	DataCursor r_e1;
/*SET*/	l_e1 = SSAMQAZHLNDNVI;
/*SET*/	r_e1 = LTKOIAFMEICGGU;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor ZXHRDJZZHERUSW;
/*DEF*/	DataCursor AVNVSLONOASRUD;
/*DEF*/	DataCursor RNLDKLDKFZTAGI;
/*SET*/	ZXHRDJZZHERUSW = KYWNDQIZLZKLNI;
/*INC*/	if (!INC(ZXHRDJZZHERUSW, arg_to)) goto label_RYDWSOVHZTKGZS;
//// ISBRACKET 
	if (ZXHRDJZZHERUSW.container->type != struct_bracket) goto label_RYDWSOVHZTKGZS;
//// JMP_BRACKET 
	AVNVSLONOASRUD = ZXHRDJZZHERUSW.container->value.bracket_data.chain->at_before_first();
	RNLDKLDKFZTAGI   = ZXHRDJZZHERUSW.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_e2;
/*DEF*/	DataCursor r_e2;
/*SET*/	l_e2 = AVNVSLONOASRUD;
/*SET*/	r_e2 = RNLDKLDKFZTAGI;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor ENATJZWXCLKKUL;
/*DEF*/	DataCursor NCAQPTONEQLNBT;
/*DEF*/	DataCursor ODDBMIVAZXZMCO;
/*SET*/	ENATJZWXCLKKUL = ZXHRDJZZHERUSW;
/*INC*/	if (!INC(ENATJZWXCLKKUL, arg_to)) goto label_RYDWSOVHZTKGZS;
//// ISBRACKET 
	if (ENATJZWXCLKKUL.container->type != struct_bracket) goto label_RYDWSOVHZTKGZS;
//// JMP_BRACKET 
	NCAQPTONEQLNBT = ENATJZWXCLKKUL.container->value.bracket_data.chain->at_before_first();
	ODDBMIVAZXZMCO   = ENATJZWXCLKKUL.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = NCAQPTONEQLNBT;
/*SET*/	r_n = ODDBMIVAZXZMCO;
//// [ empty ] 
/*ISEMPTY*/	if (ENATJZWXCLKKUL!=0 && arg_to != ENATJZWXCLKKUL) goto label_RYDWSOVHZTKGZS;

// подготовка подстановки 
result->append(newRefText("#")); 
DataChain* JDHISWKAXIAGTU = new DataChain(); 
result->append(newRefExecBrackets(Lins, JDHISWKAXIAGTU, "Lins")); 
DataChain* TAFRSVPPHURAAA = new DataChain(); 
JDHISWKAXIAGTU->append(newRefStructBrackets(TAFRSVPPHURAAA)); 
TAFRSVPPHURAAA->append_copy(l_n, r_n); 
DataChain* IXZTWDYRUUMQAD = new DataChain(); 
JDHISWKAXIAGTU->append(newRefExecBrackets(AntiStrategy, IXZTWDYRUUMQAD, "AntiStrategy")); 
IXZTWDYRUUMQAD->append_copy(l_A, r_A); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor JEPVVCVOIDWMTP;
/*DEF*/	DataCursor BNMQUIOPIWPUWC;
/*DEF*/	DataCursor ZDAPDZGHAVVIYI;
/*SET*/	JEPVVCVOIDWMTP = arg_from;
/*INC*/	if (!INC(JEPVVCVOIDWMTP, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (JEPVVCVOIDWMTP.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	BNMQUIOPIWPUWC = JEPVVCVOIDWMTP.container->value.bracket_data.chain->at_before_first();
	ZDAPDZGHAVVIYI   = JEPVVCVOIDWMTP.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor ROJNOLSOWRMVVJ;
/*DEF*/	DataCursor l_g;
/*DEF*/	DataCursor r_g;
/*SET*/	l_g = BNMQUIOPIWPUWC;
/*SET*/	ROJNOLSOWRMVVJ = BNMQUIOPIWPUWC;
/*INC*/	if (!INC(ROJNOLSOWRMVVJ, ZDAPDZGHAVVIYI)) goto sentence_after_2;
	if (! isSymbolType(ROJNOLSOWRMVVJ.container->type)) goto sentence_after_2;
/*SET*/	r_g = ROJNOLSOWRMVVJ;
//// [ empty ] 
/*ISEMPTY*/	if (r_g!=0 && ZDAPDZGHAVVIYI != r_g) goto sentence_after_2;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = JEPVVCVOIDWMTP;
/*SET*/	r_e = JEPVVCVOIDWMTP;
/*JMP*/	goto label_IQSWRICMZSXAVD_firststep;
label_IQSWRICMZSXAVD: 
/*INC*/	if (!INC(r_e, arg_to)) goto sentence_after_2;
label_IQSWRICMZSXAVD_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor QAMNFHWFGEOHSK;
/*DEF*/	DataCursor KEFUTXXIBHPULN;
/*DEF*/	DataCursor LWXQWWZDGDJGEQ;
/*SET*/	QAMNFHWFGEOHSK = r_e;
/*INC*/	if (!INC(QAMNFHWFGEOHSK, arg_to)) goto label_IQSWRICMZSXAVD;
//// ISBRACKET 
	if (QAMNFHWFGEOHSK.container->type != struct_bracket) goto label_IQSWRICMZSXAVD;
//// JMP_BRACKET 
	KEFUTXXIBHPULN = QAMNFHWFGEOHSK.container->value.bracket_data.chain->at_before_first();
	LWXQWWZDGDJGEQ   = QAMNFHWFGEOHSK.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = KEFUTXXIBHPULN;
/*SET*/	r_1 = LWXQWWZDGDJGEQ;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor WAPBHLPUDOEMNN;
/*DEF*/	DataCursor TPOUAHGXJHZJBE;
/*DEF*/	DataCursor PLTTRIABWUCRJM;
/*SET*/	WAPBHLPUDOEMNN = QAMNFHWFGEOHSK;
/*INC*/	if (!INC(WAPBHLPUDOEMNN, arg_to)) goto label_IQSWRICMZSXAVD;
//// ISBRACKET 
	if (WAPBHLPUDOEMNN.container->type != struct_bracket) goto label_IQSWRICMZSXAVD;
//// JMP_BRACKET 
	TPOUAHGXJHZJBE = WAPBHLPUDOEMNN.container->value.bracket_data.chain->at_before_first();
	PLTTRIABWUCRJM   = WAPBHLPUDOEMNN.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = TPOUAHGXJHZJBE;
/*SET*/	r_2 = PLTTRIABWUCRJM;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor BVBOZVMXOBATKH;
/*DEF*/	DataCursor QSQCHLHTBOFUIK;
/*DEF*/	DataCursor WAFKCOWUUNTFHP;
/*SET*/	BVBOZVMXOBATKH = WAPBHLPUDOEMNN;
/*INC*/	if (!INC(BVBOZVMXOBATKH, arg_to)) goto label_IQSWRICMZSXAVD;
//// ISBRACKET 
	if (BVBOZVMXOBATKH.container->type != struct_bracket) goto label_IQSWRICMZSXAVD;
//// JMP_BRACKET 
	QSQCHLHTBOFUIK = BVBOZVMXOBATKH.container->value.bracket_data.chain->at_before_first();
	WAFKCOWUUNTFHP   = BVBOZVMXOBATKH.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = QSQCHLHTBOFUIK;
/*SET*/	r_n = WAFKCOWUUNTFHP;
//// [ empty ] 
/*ISEMPTY*/	if (BVBOZVMXOBATKH!=0 && arg_to != BVBOZVMXOBATKH) goto label_IQSWRICMZSXAVD;

// подготовка подстановки 
DataChain* KDEYHOKQUWQVWT = new DataChain(); 
result->append(newRefExecBrackets(WriteXO1, KDEYHOKQUWQVWT, "WriteXO1")); 
DataChain* THHHUGJZMFEUIN = new DataChain(); 
KDEYHOKQUWQVWT->append(newRefStructBrackets(THHHUGJZMFEUIN)); 
THHHUGJZMFEUIN->append_copy(l_g, r_g); 
DataChain* IPBNCIZOCKAADA = new DataChain(); 
KDEYHOKQUWQVWT->append(newRefStructBrackets(IPBNCIZOCKAADA)); 
IPBNCIZOCKAADA->append_copy(l_1, r_1); 
DataChain* LLJREQTKHUDBLP = new DataChain(); 
KDEYHOKQUWQVWT->append(newRefStructBrackets(LLJREQTKHUDBLP)); 
LLJREQTKHUDBLP->append_copy(l_2, r_2); 
DataChain* RZLSRWXOCCSLUT = new DataChain(); 
KDEYHOKQUWQVWT->append(newRefStructBrackets(RZLSRWXOCCSLUT)); 
RZLSRWXOCCSLUT->append_copy(l_n, r_n); 

return result; 
}
sentence_after_2: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Lins__(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = arg_from;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* WQZSQTIJVCWNPF = new DataChain(); 
result->append(newRefExecBrackets(Prout, WQZSQTIJVCWNPF, "Prout")); 
WQZSQTIJVCWNPF->append(newRefWord("Lins:")); 
WQZSQTIJVCWNPF->append_copy(l_e, r_e); 
DataChain* LRLUKDIAOHQJHR = new DataChain(); 
result->append(newRefExecBrackets(Lins__, LRLUKDIAOHQJHR, "Lins__")); 
LRLUKDIAOHQJHR->append_copy(l_e, r_e); 

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Lins(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor AGLGRIYKLDKDFR;
/*DEF*/	DataCursor DRXJSTCWRSXGYW;
/*DEF*/	DataCursor FNHCBKPMESUPMT;
/*SET*/	AGLGRIYKLDKDFR = arg_from;
/*INC*/	if (!INC(AGLGRIYKLDKDFR, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (AGLGRIYKLDKDFR.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	DRXJSTCWRSXGYW = AGLGRIYKLDKDFR.container->value.bracket_data.chain->at_before_first();
	FNHCBKPMESUPMT   = AGLGRIYKLDKDFR.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_n1;
/*DEF*/	DataCursor r_n1;
/*SET*/	l_n1 = DRXJSTCWRSXGYW;
/*SET*/	r_n1 = DRXJSTCWRSXGYW;
/*JMP*/	goto label_RVIPFBKTBWZFAH_firststep;
label_RVIPFBKTBWZFAH: 
/*INC*/	if (!INC(r_n1, FNHCBKPMESUPMT)) goto sentence_after_1;
label_RVIPFBKTBWZFAH_firststep: 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor OEVNHXBRHHFOBG;
/*DEF*/	DataCursor l_hod;
/*DEF*/	DataCursor r_hod;
/*SET*/	l_hod = r_n1;
/*SET*/	OEVNHXBRHHFOBG = r_n1;
/*INC*/	if (!INC(OEVNHXBRHHFOBG, FNHCBKPMESUPMT)) goto label_RVIPFBKTBWZFAH;
	if (! isSymbolType(OEVNHXBRHHFOBG.container->type)) goto label_RVIPFBKTBWZFAH;
/*SET*/	r_hod = OEVNHXBRHHFOBG;
//// [ e.1 ] 
/*DEF*/	DataCursor l_n2;
/*DEF*/	DataCursor r_n2;
/*SET*/	l_n2 = r_hod;
/*SET*/	r_n2 = FNHCBKPMESUPMT;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_as1;
/*DEF*/	DataCursor r_as1;
/*SET*/	l_as1 = AGLGRIYKLDKDFR;
/*SET*/	r_as1 = AGLGRIYKLDKDFR;
/*JMP*/	goto label_YWCVHKTDOXQTEK_firststep;
label_YWCVHKTDOXQTEK: 
/*INC*/	if (!INC(r_as1, arg_to)) goto label_RVIPFBKTBWZFAH;
label_YWCVHKTDOXQTEK_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor IWWURZBLMLDLFI;
/*SET*/	IWWURZBLMLDLFI = r_as1;
 if (!SLIDE(IWWURZBLMLDLFI, arg_to, l_hod, r_hod)) goto label_YWCVHKTDOXQTEK;
//// [ e.1 ] 
/*DEF*/	DataCursor l_as2;
/*DEF*/	DataCursor r_as2;
/*SET*/	l_as2 = IWWURZBLMLDLFI;
/*SET*/	r_as2 = arg_to;

// подготовка подстановки 
result->append_copy(l_hod, r_hod); 

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* AntiStrategy__(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = arg_from;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* BDVEMUNNLXUBYK = new DataChain(); 
result->append(newRefExecBrackets(Prout, BDVEMUNNLXUBYK, "Prout")); 
BDVEMUNNLXUBYK->append(newRefWord("AntiStrategy:")); 
BDVEMUNNLXUBYK->append_copy(l_e, r_e); 
DataChain* VVRGKTRERPTISI = new DataChain(); 
result->append(newRefExecBrackets(AntiStrategy__, VVRGKTRERPTISI, "AntiStrategy__")); 
VVRGKTRERPTISI->append_copy(l_e, r_e); 

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* AntiStrategy(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor ZXHREVNXQUEZXK;
/*SET*/	ZXHREVNXQUEZXK = arg_from;
/*INC*/	if (!INC(ZXHREVNXQUEZXK, arg_to)) goto sentence_after_1;
	if (ZXHREVNXQUEZXK.container->type != text || *(ZXHREVNXQUEZXK.container->value.text + ZXHREVNXQUEZXK.index) != '1') goto sentence_after_1;
//// [ empty ] 
/*ISEMPTY*/	if (ZXHREVNXQUEZXK!=0 && arg_to != ZXHREVNXQUEZXK) goto sentence_after_1;

// подготовка подстановки 
result->append(newRefText("123")); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor HTJHYEZKYHPFXW;
/*SET*/	HTJHYEZKYHPFXW = arg_from;
/*INC*/	if (!INC(HTJHYEZKYHPFXW, arg_to)) goto sentence_after_2;
	if (HTJHYEZKYHPFXW.container->type != text || *(HTJHYEZKYHPFXW.container->value.text + HTJHYEZKYHPFXW.index) != '2') goto sentence_after_2;
//// [ empty ] 
/*ISEMPTY*/	if (HTJHYEZKYHPFXW!=0 && arg_to != HTJHYEZKYHPFXW) goto sentence_after_2;

// подготовка подстановки 
result->append(newRefText("456")); 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor XVFHQFAWKFDJPY;
/*SET*/	XVFHQFAWKFDJPY = arg_from;
/*INC*/	if (!INC(XVFHQFAWKFDJPY, arg_to)) goto sentence_after_3;
	if (XVFHQFAWKFDJPY.container->type != text || *(XVFHQFAWKFDJPY.container->value.text + XVFHQFAWKFDJPY.index) != '3') goto sentence_after_3;
//// [ empty ] 
/*ISEMPTY*/	if (XVFHQFAWKFDJPY!=0 && arg_to != XVFHQFAWKFDJPY) goto sentence_after_3;

// подготовка подстановки 
result->append(newRefText("789")); 

return result; 
}
sentence_after_3: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor EYRFCPXSCJKCFG;
/*SET*/	EYRFCPXSCJKCFG = arg_from;
/*INC*/	if (!INC(EYRFCPXSCJKCFG, arg_to)) goto sentence_after_4;
	if (EYRFCPXSCJKCFG.container->type != text || *(EYRFCPXSCJKCFG.container->value.text + EYRFCPXSCJKCFG.index) != '4') goto sentence_after_4;
//// [ empty ] 
/*ISEMPTY*/	if (EYRFCPXSCJKCFG!=0 && arg_to != EYRFCPXSCJKCFG) goto sentence_after_4;

// подготовка подстановки 
result->append(newRefText("147")); 

return result; 
}
sentence_after_4: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor ZHWZIZCYUCEGLM;
/*SET*/	ZHWZIZCYUCEGLM = arg_from;
/*INC*/	if (!INC(ZHWZIZCYUCEGLM, arg_to)) goto sentence_after_5;
	if (ZHWZIZCYUCEGLM.container->type != text || *(ZHWZIZCYUCEGLM.container->value.text + ZHWZIZCYUCEGLM.index) != '5') goto sentence_after_5;
//// [ empty ] 
/*ISEMPTY*/	if (ZHWZIZCYUCEGLM!=0 && arg_to != ZHWZIZCYUCEGLM) goto sentence_after_5;

// подготовка подстановки 
result->append(newRefText("258")); 

return result; 
}
sentence_after_5: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor XLGIBYZZKIAJXM;
/*SET*/	XLGIBYZZKIAJXM = arg_from;
/*INC*/	if (!INC(XLGIBYZZKIAJXM, arg_to)) goto sentence_after_6;
	if (XLGIBYZZKIAJXM.container->type != text || *(XLGIBYZZKIAJXM.container->value.text + XLGIBYZZKIAJXM.index) != '6') goto sentence_after_6;
//// [ empty ] 
/*ISEMPTY*/	if (XLGIBYZZKIAJXM!=0 && arg_to != XLGIBYZZKIAJXM) goto sentence_after_6;

// подготовка подстановки 
result->append(newRefText("369")); 

return result; 
}
sentence_after_6: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor LZGPPXOOEOQXPP;
/*SET*/	LZGPPXOOEOQXPP = arg_from;
/*INC*/	if (!INC(LZGPPXOOEOQXPP, arg_to)) goto sentence_after_7;
	if (LZGPPXOOEOQXPP.container->type != text || *(LZGPPXOOEOQXPP.container->value.text + LZGPPXOOEOQXPP.index) != '7') goto sentence_after_7;
//// [ empty ] 
/*ISEMPTY*/	if (LZGPPXOOEOQXPP!=0 && arg_to != LZGPPXOOEOQXPP) goto sentence_after_7;

// подготовка подстановки 
result->append(newRefText("159")); 

return result; 
}
sentence_after_7: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor UMJCAFCUYVDCUE;
/*SET*/	UMJCAFCUYVDCUE = arg_from;
/*INC*/	if (!INC(UMJCAFCUYVDCUE, arg_to)) goto sentence_after_8;
	if (UMJCAFCUYVDCUE.container->type != text || *(UMJCAFCUYVDCUE.container->value.text + UMJCAFCUYVDCUE.index) != '8') goto sentence_after_8;
//// [ empty ] 
/*ISEMPTY*/	if (UMJCAFCUYVDCUE!=0 && arg_to != UMJCAFCUYVDCUE) goto sentence_after_8;

// подготовка подстановки 
result->append(newRefText("357")); 

return result; 
}
sentence_after_8: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* WriteXO1__(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = arg_from;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* LZQFLJNWKXGKFY = new DataChain(); 
result->append(newRefExecBrackets(Prout, LZQFLJNWKXGKFY, "Prout")); 
LZQFLJNWKXGKFY->append(newRefWord("WriteXO1:")); 
LZQFLJNWKXGKFY->append_copy(l_e, r_e); 
DataChain* LNUKBIYSPLKHJU = new DataChain(); 
result->append(newRefExecBrackets(WriteXO1__, LNUKBIYSPLKHJU, "WriteXO1__")); 
LNUKBIYSPLKHJU->append_copy(l_e, r_e); 

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* WriteXO1(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ empty ] 
/*ISEMPTY*/	if (arg_from!=0 && arg_to != arg_from) goto sentence_after_1;

// подготовка подстановки 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_eee;
/*DEF*/	DataCursor r_eee;
/*SET*/	l_eee = arg_from;
/*SET*/	r_eee = arg_from;
/*JMP*/	goto label_CFUWOHZVPHJBJY_firststep;
label_CFUWOHZVPHJBJY: 
/*INC*/	if (!INC(r_eee, arg_to)) goto sentence_after_2;
label_CFUWOHZVPHJBJY_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor OVDLNBFRKVBEMW;
/*DEF*/	DataCursor YTFJYNQMGZAGBK;
/*DEF*/	DataCursor WEKKOUXDCYNKHT;
/*SET*/	OVDLNBFRKVBEMW = r_eee;
/*INC*/	if (!INC(OVDLNBFRKVBEMW, arg_to)) goto label_CFUWOHZVPHJBJY;
//// ISBRACKET 
	if (OVDLNBFRKVBEMW.container->type != struct_bracket) goto label_CFUWOHZVPHJBJY;
//// JMP_BRACKET 
	YTFJYNQMGZAGBK = OVDLNBFRKVBEMW.container->value.bracket_data.chain->at_before_first();
	WEKKOUXDCYNKHT   = OVDLNBFRKVBEMW.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = YTFJYNQMGZAGBK;
/*SET*/	r_3 = YTFJYNQMGZAGBK;
/*JMP*/	goto label_OSFYTLUCENTOIL_firststep;
label_OSFYTLUCENTOIL: 
/*INC*/	if (!INC(r_3, WEKKOUXDCYNKHT)) goto label_CFUWOHZVPHJBJY;
label_OSFYTLUCENTOIL_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor FULDVRXLONVKXZ;
/*SET*/	FULDVRXLONVKXZ = r_3;
/*INC*/	if (!INC(FULDVRXLONVKXZ, WEKKOUXDCYNKHT)) goto label_OSFYTLUCENTOIL;
	if (FULDVRXLONVKXZ.container->type != text || *(FULDVRXLONVKXZ.container->value.text + FULDVRXLONVKXZ.index) != '>') goto label_OSFYTLUCENTOIL;
//// [ empty ] 
/*ISEMPTY*/	if (FULDVRXLONVKXZ!=0 && WEKKOUXDCYNKHT != FULDVRXLONVKXZ) goto label_OSFYTLUCENTOIL;
//// [ empty ] 
/*ISEMPTY*/	if (OVDLNBFRKVBEMW!=0 && arg_to != OVDLNBFRKVBEMW) goto label_OSFYTLUCENTOIL;

// подготовка подстановки 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor HMJYECSLDJESDC;
/*DEF*/	DataCursor PJIKVPAUDVKXGL;
/*DEF*/	DataCursor LISAAMBOVJKDQR;
/*SET*/	HMJYECSLDJESDC = arg_from;
/*INC*/	if (!INC(HMJYECSLDJESDC, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (HMJYECSLDJESDC.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	PJIKVPAUDVKXGL = HMJYECSLDJESDC.container->value.bracket_data.chain->at_before_first();
	LISAAMBOVJKDQR   = HMJYECSLDJESDC.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor KDORJFNYGHHHPT;
/*DEF*/	DataCursor l_g;
/*DEF*/	DataCursor r_g;
/*SET*/	l_g = PJIKVPAUDVKXGL;
/*SET*/	KDORJFNYGHHHPT = PJIKVPAUDVKXGL;
/*INC*/	if (!INC(KDORJFNYGHHHPT, LISAAMBOVJKDQR)) goto sentence_after_3;
	if (! isSymbolType(KDORJFNYGHHHPT.container->type)) goto sentence_after_3;
/*SET*/	r_g = KDORJFNYGHHHPT;
//// [ empty ] 
/*ISEMPTY*/	if (r_g!=0 && LISAAMBOVJKDQR != r_g) goto sentence_after_3;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_eee;
/*DEF*/	DataCursor r_eee;
/*SET*/	l_eee = HMJYECSLDJESDC;
/*SET*/	r_eee = HMJYECSLDJESDC;
/*JMP*/	goto label_ZIFAWFTZQGEMNH_firststep;
label_ZIFAWFTZQGEMNH: 
/*INC*/	if (!INC(r_eee, arg_to)) goto sentence_after_3;
label_ZIFAWFTZQGEMNH_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor PQYICTMOYFPCVK;
/*DEF*/	DataCursor CAODAKJACQAUZY;
/*DEF*/	DataCursor OWDZSFQHKPLFBY;
/*SET*/	PQYICTMOYFPCVK = r_eee;
/*INC*/	if (!INC(PQYICTMOYFPCVK, arg_to)) goto label_ZIFAWFTZQGEMNH;
//// ISBRACKET 
	if (PQYICTMOYFPCVK.container->type != struct_bracket) goto label_ZIFAWFTZQGEMNH;
//// JMP_BRACKET 
	CAODAKJACQAUZY = PQYICTMOYFPCVK.container->value.bracket_data.chain->at_before_first();
	OWDZSFQHKPLFBY   = PQYICTMOYFPCVK.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = CAODAKJACQAUZY;
/*SET*/	r_3 = CAODAKJACQAUZY;
/*JMP*/	goto label_ZMNIMDLXMJYDAX_firststep;
label_ZMNIMDLXMJYDAX: 
/*INC*/	if (!INC(r_3, OWDZSFQHKPLFBY)) goto label_ZIFAWFTZQGEMNH;
label_ZMNIMDLXMJYDAX_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor YJNECXSJJBHIQN;
/*SET*/	YJNECXSJJBHIQN = r_3;
/*INC*/	if (!INC(YJNECXSJJBHIQN, OWDZSFQHKPLFBY)) goto label_ZMNIMDLXMJYDAX;
	if (YJNECXSJJBHIQN.container->type != text || *(YJNECXSJJBHIQN.container->value.text + YJNECXSJJBHIQN.index) != '>') goto label_ZMNIMDLXMJYDAX;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor VOCDENQMWILXXZ;
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = YJNECXSJJBHIQN;
/*SET*/	VOCDENQMWILXXZ = YJNECXSJJBHIQN;
/*INC*/	if (!INC(VOCDENQMWILXXZ, OWDZSFQHKPLFBY)) goto label_ZMNIMDLXMJYDAX;
	if (! isSymbolType(VOCDENQMWILXXZ.container->type)) goto label_ZMNIMDLXMJYDAX;
/*SET*/	r_s = VOCDENQMWILXXZ;
//// [ e.1 ] 
/*DEF*/	DataCursor l_4;
/*DEF*/	DataCursor r_4;
/*SET*/	l_4 = r_s;
/*SET*/	r_4 = OWDZSFQHKPLFBY;
//// [ empty ] 
/*ISEMPTY*/	if (PQYICTMOYFPCVK!=0 && arg_to != PQYICTMOYFPCVK) goto label_ZMNIMDLXMJYDAX;

// подготовка подстановки 
DataChain* MIKPPZHDHFQSGB = new DataChain(); 
result->append(newRefExecBrackets(Length, MIKPPZHDHFQSGB, "Length")); 
DataChain* XIISYZWNHXYFVY = new DataChain(); 
MIKPPZHDHFQSGB->append(newRefExecBrackets(Optima21, XIISYZWNHXYFVY, "Optima21")); 
DataChain* DFMPDWOMCIUDCN = new DataChain(); 
XIISYZWNHXYFVY->append(newRefExecBrackets(Analiz, DFMPDWOMCIUDCN, "Analiz")); 
DataChain* YNDGCNFJITPPMY = new DataChain(); 
DFMPDWOMCIUDCN->append(newRefStructBrackets(YNDGCNFJITPPMY)); 
YNDGCNFJITPPMY->append_copy(l_g, r_g); 
DFMPDWOMCIUDCN->append_copy(l_eee, r_eee); 
DataChain* MXIISNEBPYWSGQ = new DataChain(); 
DFMPDWOMCIUDCN->append(newRefStructBrackets(MXIISNEBPYWSGQ)); 
MXIISNEBPYWSGQ->append_copy(l_3, r_3); 
MXIISNEBPYWSGQ->append(newRefText(">")); 
MXIISNEBPYWSGQ->append_copy(l_s, r_s); 
MXIISNEBPYWSGQ->append_copy(l_4, r_4); 
DataChain* SXDJPLWZFMJOOP = new DataChain(); 
result->append(newRefExecBrackets(WriteXO, SXDJPLWZFMJOOP, "WriteXO")); 
DataChain* YYIFVKMWWPGPLJ = new DataChain(); 
SXDJPLWZFMJOOP->append(newRefStructBrackets(YYIFVKMWWPGPLJ)); 
YYIFVKMWWPGPLJ->append_copy(l_g, r_g); 
SXDJPLWZFMJOOP->append_copy(l_eee, r_eee); 
DataChain* EAWPVAPIHOXUUF = new DataChain(); 
SXDJPLWZFMJOOP->append(newRefStructBrackets(EAWPVAPIHOXUUF)); 
EAWPVAPIHOXUUF->append_copy(l_3, r_3); 
EAWPVAPIHOXUUF->append_copy(l_s, r_s); 
EAWPVAPIHOXUUF->append(newRefText(">")); 
EAWPVAPIHOXUUF->append_copy(l_4, r_4); 

return result; 
}
sentence_after_3: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* First1(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor FBRWHPEVCOQRGR;
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	FBRWHPEVCOQRGR = arg_from;
/*INC*/	if (!INC(FBRWHPEVCOQRGR, arg_to)) goto sentence_after_1;
	if (! isSymbolType(FBRWHPEVCOQRGR.container->type)) goto sentence_after_1;
/*SET*/	r_1 = FBRWHPEVCOQRGR;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = r_1;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append_copy(l_1, r_1); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	r_1 = arg_to;

// подготовка подстановки 
result->append_copy(l_1, r_1); 

return result; 
}
sentence_after_2: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Length__(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = arg_from;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* QWZHIBNORKHZML = new DataChain(); 
result->append(newRefExecBrackets(Prout, QWZHIBNORKHZML, "Prout")); 
QWZHIBNORKHZML->append(newRefWord("Length:")); 
QWZHIBNORKHZML->append_copy(l_e, r_e); 
DataChain* BZFHXUNRKLIBVP = new DataChain(); 
result->append(newRefExecBrackets(Length__, BZFHXUNRKLIBVP, "Length__")); 
BZFHXUNRKLIBVP->append_copy(l_e, r_e); 

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Length(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	r_1 = arg_from;
/*JMP*/	goto label_SZZNOPFGAXZGFL_firststep;
label_SZZNOPFGAXZGFL: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_1;
label_SZZNOPFGAXZGFL_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor TLSXBTUMILOCLT;
/*SET*/	TLSXBTUMILOCLT = r_1;
/*INC*/	if (!INC(TLSXBTUMILOCLT, arg_to)) goto label_SZZNOPFGAXZGFL;
	static DataChain *XEEKWNYSBICRFX = text_to_chain("12");
	static DataCursor XEEKWNYSBICRFX_l = XEEKWNYSBICRFX->at_before_first();
	static DataCursor XEEKWNYSBICRFX_r = XEEKWNYSBICRFX->at_last();
 if (!SLIDE(TLSXBTUMILOCLT, arg_to, XEEKWNYSBICRFX_l, XEEKWNYSBICRFX_r)) goto label_SZZNOPFGAXZGFL;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = TLSXBTUMILOCLT;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
DataChain* DIOGCSEOZPSCRH = new DataChain(); 
result->append(newRefExecBrackets(DivS, DIOGCSEOZPSCRH, "DivS")); 
DataChain* JOTYCZCWMBAAOL = new DataChain(); 
DIOGCSEOZPSCRH->append(newRefExecBrackets(First1, JOTYCZCWMBAAOL, "First1")); 
DataChain* SVUBPYLONMWAJG = new DataChain(); 
JOTYCZCWMBAAOL->append(newRefExecBrackets(Lenw, SVUBPYLONMWAJG, "Lenw")); 
SVUBPYLONMWAJG->append_copy(l_1, r_1); 
SVUBPYLONMWAJG->append(newRefText("1")); 
DataChain* XZGYZAOVENFVOC = new DataChain(); 
DIOGCSEOZPSCRH->append(newRefExecBrackets(First1, XZGYZAOVENFVOC, "First1")); 
DataChain* IKQJTXGVENKSPP = new DataChain(); 
XZGYZAOVENFVOC->append(newRefExecBrackets(Lenw, IKQJTXGVENKSPP, "Lenw")); 
IKQJTXGVENKSPP->append(newRefText("2")); 
IKQJTXGVENKSPP->append_copy(l_2, r_2); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	r_1 = arg_from;
/*JMP*/	goto label_WWPLHXTGYBVMAJ_firststep;
label_WWPLHXTGYBVMAJ: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_2;
label_WWPLHXTGYBVMAJ_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor EYFAXEGSEIJIKC;
/*SET*/	EYFAXEGSEIJIKC = r_1;
/*INC*/	if (!INC(EYFAXEGSEIJIKC, arg_to)) goto label_WWPLHXTGYBVMAJ;
	if (EYFAXEGSEIJIKC.container->type != text || *(EYFAXEGSEIJIKC.container->value.text + EYFAXEGSEIJIKC.index) != '1') goto label_WWPLHXTGYBVMAJ;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = EYFAXEGSEIJIKC;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("1=")); 
result->append(newRefInteger(2000000)); 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	r_1 = arg_from;
/*JMP*/	goto label_IYPPNZDUBPTSAV_firststep;
label_IYPPNZDUBPTSAV: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_3;
label_IYPPNZDUBPTSAV_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor ESZSIPPQMOTJHK;
/*SET*/	ESZSIPPQMOTJHK = r_1;
/*INC*/	if (!INC(ESZSIPPQMOTJHK, arg_to)) goto label_IYPPNZDUBPTSAV;
	if (ESZSIPPQMOTJHK.container->type != text || *(ESZSIPPQMOTJHK.container->value.text + ESZSIPPQMOTJHK.index) != '2') goto label_IYPPNZDUBPTSAV;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = ESZSIPPQMOTJHK;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("2=")); 
result->append(newRefInteger(2000000)); 

return result; 
}
sentence_after_3: 

{
// подготовка предложения 
//// [ empty ] 
/*ISEMPTY*/	if (arg_from!=0 && arg_to != arg_from) goto sentence_after_4;

// подготовка подстановки 
result->append(newRefText("1=")); 
result->append(newRefInteger(1)); 

return result; 
}
sentence_after_4: 

{
// подготовка предложения 
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	r_1 = arg_to;

// подготовка подстановки 
DataChain* LGEXKTRMHDDAPS = new DataChain(); 
result->append(newRefExecBrackets(Prout, LGEXKTRMHDDAPS, "Prout")); 
LGEXKTRMHDDAPS->append(newRefText("Length error symbols!!! : ")); 
DataChain* WPTFVOVUJIUWBM = new DataChain(); 
result->append(newRefExecBrackets(Print, WPTFVOVUJIUWBM, "Print")); 
WPTFVOVUJIUWBM->append_copy(l_1, r_1); 

return result; 
}
sentence_after_5: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* DivS(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor IBRUCTTMRVZNJR;
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	IBRUCTTMRVZNJR = arg_from;
/*INC*/	if (!INC(IBRUCTTMRVZNJR, arg_to)) goto sentence_after_1;
	if (! isSymbolType(IBRUCTTMRVZNJR.container->type)) goto sentence_after_1;
/*SET*/	r_1 = IBRUCTTMRVZNJR;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor CHJWZWMOZECRZN;
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = r_1;
/*SET*/	CHJWZWMOZECRZN = r_1;
/*INC*/	if (!INC(CHJWZWMOZECRZN, arg_to)) goto sentence_after_1;
	if (! isSymbolType(CHJWZWMOZECRZN.container->type)) goto sentence_after_1;
/*SET*/	r_2 = CHJWZWMOZECRZN;
//// [ empty ] 
/*ISEMPTY*/	if (r_2!=0 && arg_to != r_2) goto sentence_after_1;

// подготовка подстановки 
DataChain* JKFRVKRMRDWROA = new DataChain(); 
result->append(newRefExecBrackets(IfDiv, JKFRVKRMRDWROA, "IfDiv")); 
DataChain* OCQPKTLMWXWTNU = new DataChain(); 
JKFRVKRMRDWROA->append(newRefExecBrackets(Compare, OCQPKTLMWXWTNU, "Compare")); 
OCQPKTLMWXWTNU->append_copy(l_1, r_1); 
OCQPKTLMWXWTNU->append_copy(l_2, r_2); 
JKFRVKRMRDWROA->append_copy(l_1, r_1); 
JKFRVKRMRDWROA->append_copy(l_2, r_2); 

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* IfDiv(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor AMQELRWBGBIJIL;
/*SET*/	AMQELRWBGBIJIL = arg_from;
/*INC*/	if (!INC(AMQELRWBGBIJIL, arg_to)) goto sentence_after_1;
	if (AMQELRWBGBIJIL.container->type != text || *(AMQELRWBGBIJIL.container->value.text + AMQELRWBGBIJIL.index) != '+') goto sentence_after_1;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor NHIIULLTOVBEFL;
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = AMQELRWBGBIJIL;
/*SET*/	NHIIULLTOVBEFL = AMQELRWBGBIJIL;
/*INC*/	if (!INC(NHIIULLTOVBEFL, arg_to)) goto sentence_after_1;
	if (! isSymbolType(NHIIULLTOVBEFL.container->type)) goto sentence_after_1;
/*SET*/	r_1 = NHIIULLTOVBEFL;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor WLPBHYFFHBAVHF;
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = r_1;
/*SET*/	WLPBHYFFHBAVHF = r_1;
/*INC*/	if (!INC(WLPBHYFFHBAVHF, arg_to)) goto sentence_after_1;
	if (! isSymbolType(WLPBHYFFHBAVHF.container->type)) goto sentence_after_1;
/*SET*/	r_2 = WLPBHYFFHBAVHF;
//// [ empty ] 
/*ISEMPTY*/	if (r_2!=0 && arg_to != r_2) goto sentence_after_1;

// подготовка подстановки 
result->append(newRefText("1=")); 
DataChain* GLIXLAXXTOLHGL = new DataChain(); 
result->append(newRefExecBrackets(Div, GLIXLAXXTOLHGL, "Div")); 
GLIXLAXXTOLHGL->append_copy(l_1, r_1); 
GLIXLAXXTOLHGL->append_copy(l_2, r_2); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor VWXKYVULCYJEFL;
/*DEF*/	DataCursor l_zn;
/*DEF*/	DataCursor r_zn;
/*SET*/	l_zn = arg_from;
/*SET*/	VWXKYVULCYJEFL = arg_from;
/*INC*/	if (!INC(VWXKYVULCYJEFL, arg_to)) goto sentence_after_2;
	if (! isSymbolType(VWXKYVULCYJEFL.container->type)) goto sentence_after_2;
/*SET*/	r_zn = VWXKYVULCYJEFL;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor LOQZHLTMGTUJDC;
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = r_zn;
/*SET*/	LOQZHLTMGTUJDC = r_zn;
/*INC*/	if (!INC(LOQZHLTMGTUJDC, arg_to)) goto sentence_after_2;
	if (! isSymbolType(LOQZHLTMGTUJDC.container->type)) goto sentence_after_2;
/*SET*/	r_1 = LOQZHLTMGTUJDC;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor UUGNROTLOTCPBN;
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = r_1;
/*SET*/	UUGNROTLOTCPBN = r_1;
/*INC*/	if (!INC(UUGNROTLOTCPBN, arg_to)) goto sentence_after_2;
	if (! isSymbolType(UUGNROTLOTCPBN.container->type)) goto sentence_after_2;
/*SET*/	r_2 = UUGNROTLOTCPBN;
//// [ empty ] 
/*ISEMPTY*/	if (r_2!=0 && arg_to != r_2) goto sentence_after_2;

// подготовка подстановки 
result->append(newRefText("1=")); 
DataChain* YFHEJEGCMFPTQM = new DataChain(); 
result->append(newRefExecBrackets(Div, YFHEJEGCMFPTQM, "Div")); 
YFHEJEGCMFPTQM->append_copy(l_2, r_2); 
YFHEJEGCMFPTQM->append_copy(l_1, r_1); 

return result; 
}
sentence_after_2: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* NextPl(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor VEGHMFBMVKLSQF;
/*SET*/	VEGHMFBMVKLSQF = arg_from;
/*INC*/	if (!INC(VEGHMFBMVKLSQF, arg_to)) goto sentence_after_1;
	if (VEGHMFBMVKLSQF.container->type != text || *(VEGHMFBMVKLSQF.container->value.text + VEGHMFBMVKLSQF.index) != '1') goto sentence_after_1;
//// [ empty ] 
/*ISEMPTY*/	if (VEGHMFBMVKLSQF!=0 && arg_to != VEGHMFBMVKLSQF) goto sentence_after_1;

// подготовка подстановки 
result->append(newRefText("2")); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor ZXXOOLNVLAYGUO;
/*SET*/	ZXXOOLNVLAYGUO = arg_from;
/*INC*/	if (!INC(ZXXOOLNVLAYGUO, arg_to)) goto sentence_after_2;
	if (ZXXOOLNVLAYGUO.container->type != text || *(ZXXOOLNVLAYGUO.container->value.text + ZXXOOLNVLAYGUO.index) != '2') goto sentence_after_2;
//// [ empty ] 
/*ISEMPTY*/	if (ZXXOOLNVLAYGUO!=0 && arg_to != ZXXOOLNVLAYGUO) goto sentence_after_2;

// подготовка подстановки 
result->append(newRefText("1")); 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = arg_from;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* KQTAXJLRBRUKKK = new DataChain(); 
result->append(newRefExecBrackets(Print, KQTAXJLRBRUKKK, "Print")); 
KQTAXJLRBRUKKK->append(newRefText("NextPl uncn.: ")); 
KQTAXJLRBRUKKK->append_copy(l_e, r_e); 

return result; 
}
sentence_after_3: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Optima21(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = arg_from;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* IGJMXQRBAZLPDE = new DataChain(); 
result->append(newRefExecBrackets(Optima211, IGJMXQRBAZLPDE, "Optima211")); 
IGJMXQRBAZLPDE->append_copy(l_e, r_e); 

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Optima211(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	r_1 = arg_from;
/*JMP*/	goto label_VPEZPBWSHVPCKL_firststep;
label_VPEZPBWSHVPCKL: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_1;
label_VPEZPBWSHVPCKL_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor DQGIVLQPIRQVWQ;
/*SET*/	DQGIVLQPIRQVWQ = r_1;
/*INC*/	if (!INC(DQGIVLQPIRQVWQ, arg_to)) goto label_VPEZPBWSHVPCKL;
	if (DQGIVLQPIRQVWQ.container->type != text || *(DQGIVLQPIRQVWQ.container->value.text + DQGIVLQPIRQVWQ.index) != '1') goto label_VPEZPBWSHVPCKL;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = DQGIVLQPIRQVWQ;
/*SET*/	r_2 = DQGIVLQPIRQVWQ;
/*JMP*/	goto label_QUYXPIXQIREUQA_firststep;
label_QUYXPIXQIREUQA: 
/*INC*/	if (!INC(r_2, arg_to)) goto label_VPEZPBWSHVPCKL;
label_QUYXPIXQIREUQA_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor MFFSVVNTGUXESI;
/*SET*/	MFFSVVNTGUXESI = r_2;
/*INC*/	if (!INC(MFFSVVNTGUXESI, arg_to)) goto label_QUYXPIXQIREUQA;
	if (MFFSVVNTGUXESI.container->type != text || *(MFFSVVNTGUXESI.container->value.text + MFFSVVNTGUXESI.index) != '1') goto label_QUYXPIXQIREUQA;
//// [ e.1 ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = MFFSVVNTGUXESI;
/*SET*/	r_3 = arg_to;

// подготовка подстановки 
result->append(newRefText("11")); 
DataChain* BKUREHRQBBXAJE = new DataChain(); 
result->append(newRefExecBrackets(Optima211, BKUREHRQBBXAJE, "Optima211")); 
BKUREHRQBBXAJE->append_copy(l_1, r_1); 
BKUREHRQBBXAJE->append_copy(l_3, r_3); 
result->append_copy(l_2, r_2); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	r_1 = arg_from;
/*JMP*/	goto label_FBFHKZBPKAPBSZ_firststep;
label_FBFHKZBPKAPBSZ: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_2;
label_FBFHKZBPKAPBSZ_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor YSPDAAOXRAOJOT;
/*SET*/	YSPDAAOXRAOJOT = r_1;
/*INC*/	if (!INC(YSPDAAOXRAOJOT, arg_to)) goto label_FBFHKZBPKAPBSZ;
	if (YSPDAAOXRAOJOT.container->type != text || *(YSPDAAOXRAOJOT.container->value.text + YSPDAAOXRAOJOT.index) != '1') goto label_FBFHKZBPKAPBSZ;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = YSPDAAOXRAOJOT;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("1")); 
DataChain* TSGRZUIGUSNWLY = new DataChain(); 
result->append(newRefExecBrackets(Optima211, TSGRZUIGUSNWLY, "Optima211")); 
TSGRZUIGUSNWLY->append_copy(l_1, r_1); 
TSGRZUIGUSNWLY->append_copy(l_2, r_2); 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	r_1 = arg_to;

// подготовка подстановки 
result->append_copy(l_1, r_1); 

return result; 
}
sentence_after_3: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Strategy__(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = arg_from;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* RVFNKKMSDBUHVH = new DataChain(); 
result->append(newRefExecBrackets(Prout, RVFNKKMSDBUHVH, "Prout")); 
RVFNKKMSDBUHVH->append(newRefWord("Strategy:")); 
RVFNKKMSDBUHVH->append_copy(l_e, r_e); 
DataChain* FQTDVTNLEWFQUU = new DataChain(); 
result->append(newRefExecBrackets(Strategy__, FQTDVTNLEWFQUU, "Strategy__")); 
FQTDVTNLEWFQUU->append_copy(l_e, r_e); 

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Strategy(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ empty ] 
/*ISEMPTY*/	if (arg_from!=0 && arg_to != arg_from) goto sentence_after_1;

// подготовка подстановки 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	r_1 = arg_from;
/*JMP*/	goto label_HTAINKEBBVZHTQ_firststep;
label_HTAINKEBBVZHTQ: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_2;
label_HTAINKEBBVZHTQ_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor BKDBMVHBSNJBTV;
/*SET*/	BKDBMVHBSNJBTV = r_1;
/*INC*/	if (!INC(BKDBMVHBSNJBTV, arg_to)) goto label_HTAINKEBBVZHTQ;
	if (BKDBMVHBSNJBTV.container->type != text || *(BKDBMVHBSNJBTV.container->value.text + BKDBMVHBSNJBTV.index) != '1') goto label_HTAINKEBBVZHTQ;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = BKDBMVHBSNJBTV;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("147")); 
DataChain* SMXVFJTVQUITIV = new DataChain(); 
result->append(newRefExecBrackets(Strategy, SMXVFJTVQUITIV, "Strategy")); 
SMXVFJTVQUITIV->append_copy(l_1, r_1); 
SMXVFJTVQUITIV->append_copy(l_2, r_2); 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	r_1 = arg_from;
/*JMP*/	goto label_YHZPXCDJWIKFAT_firststep;
label_YHZPXCDJWIKFAT: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_3;
label_YHZPXCDJWIKFAT_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor CANCHXSSJLUHLY;
/*SET*/	CANCHXSSJLUHLY = r_1;
/*INC*/	if (!INC(CANCHXSSJLUHLY, arg_to)) goto label_YHZPXCDJWIKFAT;
	if (CANCHXSSJLUHLY.container->type != text || *(CANCHXSSJLUHLY.container->value.text + CANCHXSSJLUHLY.index) != '2') goto label_YHZPXCDJWIKFAT;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = CANCHXSSJLUHLY;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("15")); 
DataChain* LIUEJOBCFPVNYR = new DataChain(); 
result->append(newRefExecBrackets(Strategy, LIUEJOBCFPVNYR, "Strategy")); 
LIUEJOBCFPVNYR->append_copy(l_1, r_1); 
LIUEJOBCFPVNYR->append_copy(l_2, r_2); 

return result; 
}
sentence_after_3: 

{
// подготовка предложения 
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	r_1 = arg_from;
/*JMP*/	goto label_RPKEGEQPVLHXEE_firststep;
label_RPKEGEQPVLHXEE: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_4;
label_RPKEGEQPVLHXEE_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor OCMERJMZIUDTSQ;
/*SET*/	OCMERJMZIUDTSQ = r_1;
/*INC*/	if (!INC(OCMERJMZIUDTSQ, arg_to)) goto label_RPKEGEQPVLHXEE;
	if (OCMERJMZIUDTSQ.container->type != text || *(OCMERJMZIUDTSQ.container->value.text + OCMERJMZIUDTSQ.index) != '3') goto label_RPKEGEQPVLHXEE;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = OCMERJMZIUDTSQ;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("168")); 
DataChain* EPFQDSMVSTMMWW = new DataChain(); 
result->append(newRefExecBrackets(Strategy, EPFQDSMVSTMMWW, "Strategy")); 
EPFQDSMVSTMMWW->append_copy(l_1, r_1); 
EPFQDSMVSTMMWW->append_copy(l_2, r_2); 

return result; 
}
sentence_after_4: 

{
// подготовка предложения 
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	r_1 = arg_from;
/*JMP*/	goto label_WQKNNRMQMJCCPA_firststep;
label_WQKNNRMQMJCCPA: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_5;
label_WQKNNRMQMJCCPA_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor OWAZFEURGPBFRY;
/*SET*/	OWAZFEURGPBFRY = r_1;
/*INC*/	if (!INC(OWAZFEURGPBFRY, arg_to)) goto label_WQKNNRMQMJCCPA;
	if (OWAZFEURGPBFRY.container->type != text || *(OWAZFEURGPBFRY.container->value.text + OWAZFEURGPBFRY.index) != '4') goto label_WQKNNRMQMJCCPA;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = OWAZFEURGPBFRY;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("24")); 
DataChain* ICWUOHFEREBEAC = new DataChain(); 
result->append(newRefExecBrackets(Strategy, ICWUOHFEREBEAC, "Strategy")); 
ICWUOHFEREBEAC->append_copy(l_1, r_1); 
ICWUOHFEREBEAC->append_copy(l_2, r_2); 

return result; 
}
sentence_after_5: 

{
// подготовка предложения 
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	r_1 = arg_from;
/*JMP*/	goto label_AZUVJOXYIPMSGU_firststep;
label_AZUVJOXYIPMSGU: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_6;
label_AZUVJOXYIPMSGU_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor FJIWLCFYWXTEYY;
/*SET*/	FJIWLCFYWXTEYY = r_1;
/*INC*/	if (!INC(FJIWLCFYWXTEYY, arg_to)) goto label_AZUVJOXYIPMSGU;
	if (FJIWLCFYWXTEYY.container->type != text || *(FJIWLCFYWXTEYY.container->value.text + FJIWLCFYWXTEYY.index) != '5') goto label_AZUVJOXYIPMSGU;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = FJIWLCFYWXTEYY;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("2578")); 
DataChain* YOXBSCEFTDRQEL = new DataChain(); 
result->append(newRefExecBrackets(Strategy, YOXBSCEFTDRQEL, "Strategy")); 
YOXBSCEFTDRQEL->append_copy(l_1, r_1); 
YOXBSCEFTDRQEL->append_copy(l_2, r_2); 

return result; 
}
sentence_after_6: 

{
// подготовка предложения 
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	r_1 = arg_from;
/*JMP*/	goto label_XFVCFBBJJYFSVK_firststep;
label_XFVCFBBJJYFSVK: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_7;
label_XFVCFBBJJYFSVK_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor VSAPDSHAKGDVHC;
/*SET*/	VSAPDSHAKGDVHC = r_1;
/*INC*/	if (!INC(VSAPDSHAKGDVHC, arg_to)) goto label_XFVCFBBJJYFSVK;
	if (VSAPDSHAKGDVHC.container->type != text || *(VSAPDSHAKGDVHC.container->value.text + VSAPDSHAKGDVHC.index) != '6') goto label_XFVCFBBJJYFSVK;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = VSAPDSHAKGDVHC;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("26")); 
DataChain* ASQKAUQLNFHGGT = new DataChain(); 
result->append(newRefExecBrackets(Strategy, ASQKAUQLNFHGGT, "Strategy")); 
ASQKAUQLNFHGGT->append_copy(l_1, r_1); 
ASQKAUQLNFHGGT->append_copy(l_2, r_2); 

return result; 
}
sentence_after_7: 

{
// подготовка предложения 
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	r_1 = arg_from;
/*JMP*/	goto label_AGRNFFMNPINWLE_firststep;
label_AGRNFFMNPINWLE: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_8;
label_AGRNFFMNPINWLE_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor XRQXISBFNHJZQV;
/*SET*/	XRQXISBFNHJZQV = r_1;
/*INC*/	if (!INC(XRQXISBFNHJZQV, arg_to)) goto label_AGRNFFMNPINWLE;
	if (XRQXISBFNHJZQV.container->type != text || *(XRQXISBFNHJZQV.container->value.text + XRQXISBFNHJZQV.index) != '7') goto label_AGRNFFMNPINWLE;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = XRQXISBFNHJZQV;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("348")); 
DataChain* BACPJZSNACLMNU = new DataChain(); 
result->append(newRefExecBrackets(Strategy, BACPJZSNACLMNU, "Strategy")); 
BACPJZSNACLMNU->append_copy(l_1, r_1); 
BACPJZSNACLMNU->append_copy(l_2, r_2); 

return result; 
}
sentence_after_8: 

{
// подготовка предложения 
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	r_1 = arg_from;
/*JMP*/	goto label_QNBDIFZLUJQVNF_firststep;
label_QNBDIFZLUJQVNF: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_9;
label_QNBDIFZLUJQVNF_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor JXXVKCZFKZZJQN;
/*SET*/	JXXVKCZFKZZJQN = r_1;
/*INC*/	if (!INC(JXXVKCZFKZZJQN, arg_to)) goto label_QNBDIFZLUJQVNF;
	if (JXXVKCZFKZZJQN.container->type != text || *(JXXVKCZFKZZJQN.container->value.text + JXXVKCZFKZZJQN.index) != '8') goto label_QNBDIFZLUJQVNF;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = JXXVKCZFKZZJQN;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("35")); 
DataChain* RSOSYQHQUHKJCJ = new DataChain(); 
result->append(newRefExecBrackets(Strategy, RSOSYQHQUHKJCJ, "Strategy")); 
RSOSYQHQUHKJCJ->append_copy(l_1, r_1); 
RSOSYQHQUHKJCJ->append_copy(l_2, r_2); 

return result; 
}
sentence_after_9: 

{
// подготовка предложения 
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	r_1 = arg_from;
/*JMP*/	goto label_YUGTEDOGFURKXI_firststep;
label_YUGTEDOGFURKXI: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_10;
label_YUGTEDOGFURKXI_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor YQUFOTIAJMWHYI;
/*SET*/	YQUFOTIAJMWHYI = r_1;
/*INC*/	if (!INC(YQUFOTIAJMWHYI, arg_to)) goto label_YUGTEDOGFURKXI;
	if (YQUFOTIAJMWHYI.container->type != text || *(YQUFOTIAJMWHYI.container->value.text + YQUFOTIAJMWHYI.index) != '9') goto label_YUGTEDOGFURKXI;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = YQUFOTIAJMWHYI;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("367")); 
DataChain* PZHSVBFZVTVHWY = new DataChain(); 
result->append(newRefExecBrackets(Strategy, PZHSVBFZVTVHWY, "Strategy")); 
PZHSVBFZVTVHWY->append_copy(l_1, r_1); 
PZHSVBFZVTVHWY->append_copy(l_2, r_2); 

return result; 
}
sentence_after_10: 

{
// подготовка предложения 
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	r_1 = arg_to;

// подготовка подстановки 
result->append_copy(l_1, r_1); 

return result; 
}
sentence_after_11: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Ifwin(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor CFZNMAOMAFSYVY;
/*DEF*/	DataCursor RQPIZTEUOXGTHF;
/*DEF*/	DataCursor XSMXJRWPSURSGW;
/*SET*/	CFZNMAOMAFSYVY = arg_from;
/*INC*/	if (!INC(CFZNMAOMAFSYVY, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (CFZNMAOMAFSYVY.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	RQPIZTEUOXGTHF = CFZNMAOMAFSYVY.container->value.bracket_data.chain->at_before_first();
	XSMXJRWPSURSGW   = CFZNMAOMAFSYVY.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = RQPIZTEUOXGTHF;
/*SET*/	r_1 = XSMXJRWPSURSGW;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor THHILGDHZFZAXA;
/*DEF*/	DataCursor DTKLHYHQZFDIMS;
/*DEF*/	DataCursor RUEECXKQKRUDLM;
/*SET*/	THHILGDHZFZAXA = CFZNMAOMAFSYVY;
/*INC*/	if (!INC(THHILGDHZFZAXA, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (THHILGDHZFZAXA.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	DTKLHYHQZFDIMS = THHILGDHZFZAXA.container->value.bracket_data.chain->at_before_first();
	RUEECXKQKRUDLM   = THHILGDHZFZAXA.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = DTKLHYHQZFDIMS;
/*SET*/	r_2 = RUEECXKQKRUDLM;
//// [ empty ] 
/*ISEMPTY*/	if (THHILGDHZFZAXA!=0 && arg_to != THHILGDHZFZAXA) goto sentence_after_1;

// подготовка подстановки 
DataChain* ZGDTNHMIVNNKCL = new DataChain(); 
result->append(newRefExecBrackets(Ifwin1, ZGDTNHMIVNNKCL, "Ifwin1")); 
DataChain* GARYGYDQDHLTRS = new DataChain(); 
ZGDTNHMIVNNKCL->append(newRefStructBrackets(GARYGYDQDHLTRS)); 
DataChain* THIDZYQAZFNOVK = new DataChain(); 
GARYGYDQDHLTRS->append(newRefExecBrackets(Strategy, THIDZYQAZFNOVK, "Strategy")); 
THIDZYQAZFNOVK->append_copy(l_1, r_1); 
DataChain* TQCOTCHCOLINEI = new DataChain(); 
ZGDTNHMIVNNKCL->append(newRefStructBrackets(TQCOTCHCOLINEI)); 
DataChain* YTYMRJSCYOEIVD = new DataChain(); 
TQCOTCHCOLINEI->append(newRefExecBrackets(Strategy, YTYMRJSCYOEIVD, "Strategy")); 
YTYMRJSCYOEIVD->append_copy(l_2, r_2); 

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Ifwin1(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor YHPHLJZHEZOHMI;
/*DEF*/	DataCursor URCPBLVWAAJIQU;
/*DEF*/	DataCursor GTAOQMEMJLHGOX;
/*SET*/	YHPHLJZHEZOHMI = arg_from;
/*INC*/	if (!INC(YHPHLJZHEZOHMI, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (YHPHLJZHEZOHMI.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	URCPBLVWAAJIQU = YHPHLJZHEZOHMI.container->value.bracket_data.chain->at_before_first();
	GTAOQMEMJLHGOX   = YHPHLJZHEZOHMI.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = URCPBLVWAAJIQU;
/*SET*/	r_1 = URCPBLVWAAJIQU;
/*JMP*/	goto label_PRURTYMKKTDBNO_firststep;
label_PRURTYMKKTDBNO: 
/*INC*/	if (!INC(r_1, GTAOQMEMJLHGOX)) goto sentence_after_1;
label_PRURTYMKKTDBNO_firststep: 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor XWTTGEEQIMLHCZ;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_1;
/*SET*/	XWTTGEEQIMLHCZ = r_1;
/*INC*/	if (!INC(XWTTGEEQIMLHCZ, GTAOQMEMJLHGOX)) goto label_PRURTYMKKTDBNO;
	if (! isSymbolType(XWTTGEEQIMLHCZ.container->type)) goto label_PRURTYMKKTDBNO;
/*SET*/	r_A = XWTTGEEQIMLHCZ;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = r_A;
/*SET*/	r_2 = r_A;
/*JMP*/	goto label_TCTYPHMEQDSUYV_firststep;
label_TCTYPHMEQDSUYV: 
/*INC*/	if (!INC(r_2, GTAOQMEMJLHGOX)) goto label_PRURTYMKKTDBNO;
label_TCTYPHMEQDSUYV_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor KKJOPLMZDCAKPJ;
/*SET*/	KKJOPLMZDCAKPJ = r_2;
 if (!SLIDE(KKJOPLMZDCAKPJ, GTAOQMEMJLHGOX, l_A, r_A)) goto label_TCTYPHMEQDSUYV;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = KKJOPLMZDCAKPJ;
/*SET*/	r_3 = KKJOPLMZDCAKPJ;
/*JMP*/	goto label_VOZIMHXXQHDUIQ_firststep;
label_VOZIMHXXQHDUIQ: 
/*INC*/	if (!INC(r_3, GTAOQMEMJLHGOX)) goto label_TCTYPHMEQDSUYV;
label_VOZIMHXXQHDUIQ_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor EDLNGWGOOOUPNE;
/*SET*/	EDLNGWGOOOUPNE = r_3;
 if (!SLIDE(EDLNGWGOOOUPNE, GTAOQMEMJLHGOX, l_A, r_A)) goto label_VOZIMHXXQHDUIQ;
//// [ e.1 ] 
/*DEF*/	DataCursor l_4;
/*DEF*/	DataCursor r_4;
/*SET*/	l_4 = EDLNGWGOOOUPNE;
/*SET*/	r_4 = GTAOQMEMJLHGOX;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor DKSDGPMHHDAQBS;
/*DEF*/	DataCursor QRFPDRSYKHBUTS;
/*DEF*/	DataCursor NUWJPPGDEEBJGS;
/*SET*/	DKSDGPMHHDAQBS = YHPHLJZHEZOHMI;
/*INC*/	if (!INC(DKSDGPMHHDAQBS, arg_to)) goto label_VOZIMHXXQHDUIQ;
//// ISBRACKET 
	if (DKSDGPMHHDAQBS.container->type != struct_bracket) goto label_VOZIMHXXQHDUIQ;
//// JMP_BRACKET 
	QRFPDRSYKHBUTS = DKSDGPMHHDAQBS.container->value.bracket_data.chain->at_before_first();
	NUWJPPGDEEBJGS   = DKSDGPMHHDAQBS.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = QRFPDRSYKHBUTS;
/*SET*/	r_e = NUWJPPGDEEBJGS;
//// [ empty ] 
/*ISEMPTY*/	if (DKSDGPMHHDAQBS!=0 && arg_to != DKSDGPMHHDAQBS) goto label_VOZIMHXXQHDUIQ;

// подготовка подстановки 
result->append(newRefText("1")); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor DYFOECQQNLEMKI;
/*DEF*/	DataCursor MIPECEHLBTMBWN;
/*DEF*/	DataCursor KDXYMECLSSHVKM;
/*SET*/	DYFOECQQNLEMKI = arg_from;
/*INC*/	if (!INC(DYFOECQQNLEMKI, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (DYFOECQQNLEMKI.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	MIPECEHLBTMBWN = DYFOECQQNLEMKI.container->value.bracket_data.chain->at_before_first();
	KDXYMECLSSHVKM   = DYFOECQQNLEMKI.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = MIPECEHLBTMBWN;
/*SET*/	r_e = KDXYMECLSSHVKM;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor YWJXESHOIHMLGV;
/*DEF*/	DataCursor XILJVWLLFPNJZY;
/*DEF*/	DataCursor WCPAMEVWTYGFPH;
/*SET*/	YWJXESHOIHMLGV = DYFOECQQNLEMKI;
/*INC*/	if (!INC(YWJXESHOIHMLGV, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (YWJXESHOIHMLGV.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	XILJVWLLFPNJZY = YWJXESHOIHMLGV.container->value.bracket_data.chain->at_before_first();
	WCPAMEVWTYGFPH   = YWJXESHOIHMLGV.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = XILJVWLLFPNJZY;
/*SET*/	r_1 = XILJVWLLFPNJZY;
/*JMP*/	goto label_IFUBTTNWNPHDBY_firststep;
label_IFUBTTNWNPHDBY: 
/*INC*/	if (!INC(r_1, WCPAMEVWTYGFPH)) goto sentence_after_2;
label_IFUBTTNWNPHDBY_firststep: 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor TWODCLRJPRSEQW;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_1;
/*SET*/	TWODCLRJPRSEQW = r_1;
/*INC*/	if (!INC(TWODCLRJPRSEQW, WCPAMEVWTYGFPH)) goto label_IFUBTTNWNPHDBY;
	if (! isSymbolType(TWODCLRJPRSEQW.container->type)) goto label_IFUBTTNWNPHDBY;
/*SET*/	r_A = TWODCLRJPRSEQW;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = r_A;
/*SET*/	r_2 = r_A;
/*JMP*/	goto label_RDWSVYNCGFRAZZ_firststep;
label_RDWSVYNCGFRAZZ: 
/*INC*/	if (!INC(r_2, WCPAMEVWTYGFPH)) goto label_IFUBTTNWNPHDBY;
label_RDWSVYNCGFRAZZ_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor AODGGXWWBTJQUJ;
/*SET*/	AODGGXWWBTJQUJ = r_2;
 if (!SLIDE(AODGGXWWBTJQUJ, WCPAMEVWTYGFPH, l_A, r_A)) goto label_RDWSVYNCGFRAZZ;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = AODGGXWWBTJQUJ;
/*SET*/	r_3 = AODGGXWWBTJQUJ;
/*JMP*/	goto label_RMCDPOMJRYLEDH_firststep;
label_RMCDPOMJRYLEDH: 
/*INC*/	if (!INC(r_3, WCPAMEVWTYGFPH)) goto label_RDWSVYNCGFRAZZ;
label_RMCDPOMJRYLEDH_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor UFHWKHZKTNKYTG;
/*SET*/	UFHWKHZKTNKYTG = r_3;
 if (!SLIDE(UFHWKHZKTNKYTG, WCPAMEVWTYGFPH, l_A, r_A)) goto label_RMCDPOMJRYLEDH;
//// [ e.1 ] 
/*DEF*/	DataCursor l_4;
/*DEF*/	DataCursor r_4;
/*SET*/	l_4 = UFHWKHZKTNKYTG;
/*SET*/	r_4 = WCPAMEVWTYGFPH;
//// [ empty ] 
/*ISEMPTY*/	if (YWJXESHOIHMLGV!=0 && arg_to != YWJXESHOIHMLGV) goto label_RMCDPOMJRYLEDH;

// подготовка подстановки 
result->append(newRefText("2")); 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor JPMMGVXJCNJGZU;
/*DEF*/	DataCursor HWQQSLDZCSFOJS;
/*DEF*/	DataCursor WRQCNBQYXAAGIB;
/*SET*/	JPMMGVXJCNJGZU = arg_from;
/*INC*/	if (!INC(JPMMGVXJCNJGZU, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (JPMMGVXJCNJGZU.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	HWQQSLDZCSFOJS = JPMMGVXJCNJGZU.container->value.bracket_data.chain->at_before_first();
	WRQCNBQYXAAGIB   = JPMMGVXJCNJGZU.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = HWQQSLDZCSFOJS;
/*SET*/	r_1 = WRQCNBQYXAAGIB;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor PVTXDONPEASHNR;
/*DEF*/	DataCursor OHUVOGLDXHSPRN;
/*DEF*/	DataCursor GSOQDJFQTEXYRW;
/*SET*/	PVTXDONPEASHNR = JPMMGVXJCNJGZU;
/*INC*/	if (!INC(PVTXDONPEASHNR, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (PVTXDONPEASHNR.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	OHUVOGLDXHSPRN = PVTXDONPEASHNR.container->value.bracket_data.chain->at_before_first();
	GSOQDJFQTEXYRW   = PVTXDONPEASHNR.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = OHUVOGLDXHSPRN;
/*SET*/	r_2 = GSOQDJFQTEXYRW;
//// [ empty ] 
/*ISEMPTY*/	if (PVTXDONPEASHNR!=0 && arg_to != PVTXDONPEASHNR) goto sentence_after_3;

// подготовка подстановки 
result->append(newRefText("0")); 

return result; 
}
sentence_after_3: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Analiz__(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = arg_from;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* IZZOEOWAQEZDLM = new DataChain(); 
result->append(newRefExecBrackets(Prout, IZZOEOWAQEZDLM, "Prout")); 
IZZOEOWAQEZDLM->append(newRefWord("Analiz:")); 
IZZOEOWAQEZDLM->append_copy(l_e, r_e); 
DataChain* WAFCOZVQCIEWGK = new DataChain(); 
result->append(newRefExecBrackets(Analiz__, WAFCOZVQCIEWGK, "Analiz__")); 
WAFCOZVQCIEWGK->append_copy(l_e, r_e); 

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Analiz(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	r_1 = arg_from;
/*JMP*/	goto label_EKFGRCYVZSAHPS_firststep;
label_EKFGRCYVZSAHPS: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_1;
label_EKFGRCYVZSAHPS_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor ZOBRIXWXKPICLQ;
/*DEF*/	DataCursor LJTKVNBIMPDKYE;
/*DEF*/	DataCursor BCWLFKFFRLZZMK;
/*SET*/	ZOBRIXWXKPICLQ = r_1;
/*INC*/	if (!INC(ZOBRIXWXKPICLQ, arg_to)) goto label_EKFGRCYVZSAHPS;
//// ISBRACKET 
	if (ZOBRIXWXKPICLQ.container->type != struct_bracket) goto label_EKFGRCYVZSAHPS;
//// JMP_BRACKET 
	LJTKVNBIMPDKYE = ZOBRIXWXKPICLQ.container->value.bracket_data.chain->at_before_first();
	BCWLFKFFRLZZMK   = ZOBRIXWXKPICLQ.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = LJTKVNBIMPDKYE;
/*SET*/	r_3 = LJTKVNBIMPDKYE;
/*JMP*/	goto label_VMHNLCIVWHWZTZ_firststep;
label_VMHNLCIVWHWZTZ: 
/*INC*/	if (!INC(r_3, BCWLFKFFRLZZMK)) goto label_EKFGRCYVZSAHPS;
label_VMHNLCIVWHWZTZ_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor RBXJCRTUVTXFKI;
/*SET*/	RBXJCRTUVTXFKI = r_3;
/*INC*/	if (!INC(RBXJCRTUVTXFKI, BCWLFKFFRLZZMK)) goto label_VMHNLCIVWHWZTZ;
	if (RBXJCRTUVTXFKI.container->type != text || *(RBXJCRTUVTXFKI.container->value.text + RBXJCRTUVTXFKI.index) != '>') goto label_VMHNLCIVWHWZTZ;
//// [ empty ] 
/*ISEMPTY*/	if (RBXJCRTUVTXFKI!=0 && BCWLFKFFRLZZMK != RBXJCRTUVTXFKI) goto label_VMHNLCIVWHWZTZ;
//// [ empty ] 
/*ISEMPTY*/	if (ZOBRIXWXKPICLQ!=0 && arg_to != ZOBRIXWXKPICLQ) goto label_VMHNLCIVWHWZTZ;

// подготовка подстановки 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor OZSQORQMQLESIX;
/*DEF*/	DataCursor RNERZOOWRVWPMI;
/*DEF*/	DataCursor BHHYFFUVKOUKDW;
/*SET*/	OZSQORQMQLESIX = arg_from;
/*INC*/	if (!INC(OZSQORQMQLESIX, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (OZSQORQMQLESIX.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	RNERZOOWRVWPMI = OZSQORQMQLESIX.container->value.bracket_data.chain->at_before_first();
	BHHYFFUVKOUKDW   = OZSQORQMQLESIX.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor JCVXQGLSCHJAGQ;
/*SET*/	JCVXQGLSCHJAGQ = RNERZOOWRVWPMI;
/*INC*/	if (!INC(JCVXQGLSCHJAGQ, BHHYFFUVKOUKDW)) goto sentence_after_2;
	if (JCVXQGLSCHJAGQ.container->type != text || *(JCVXQGLSCHJAGQ.container->value.text + JCVXQGLSCHJAGQ.index) != '1') goto sentence_after_2;
//// [ empty ] 
/*ISEMPTY*/	if (JCVXQGLSCHJAGQ!=0 && BHHYFFUVKOUKDW != JCVXQGLSCHJAGQ) goto sentence_after_2;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor LUDHRBEFJJFYTK;
/*DEF*/	DataCursor XLBNVMDWSYXHGS;
/*DEF*/	DataCursor CZHYJGDFGNWFPD;
/*SET*/	LUDHRBEFJJFYTK = OZSQORQMQLESIX;
/*INC*/	if (!INC(LUDHRBEFJJFYTK, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (LUDHRBEFJJFYTK.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	XLBNVMDWSYXHGS = LUDHRBEFJJFYTK.container->value.bracket_data.chain->at_before_first();
	CZHYJGDFGNWFPD   = LUDHRBEFJJFYTK.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = XLBNVMDWSYXHGS;
/*SET*/	r_1 = CZHYJGDFGNWFPD;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor TLKHPEKHJNCYLC;
/*DEF*/	DataCursor QMSSYGHWDVAEQJ;
/*DEF*/	DataCursor KZMHIYDLXDJOHN;
/*SET*/	TLKHPEKHJNCYLC = LUDHRBEFJJFYTK;
/*INC*/	if (!INC(TLKHPEKHJNCYLC, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (TLKHPEKHJNCYLC.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	QMSSYGHWDVAEQJ = TLKHPEKHJNCYLC.container->value.bracket_data.chain->at_before_first();
	KZMHIYDLXDJOHN   = TLKHPEKHJNCYLC.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = QMSSYGHWDVAEQJ;
/*SET*/	r_2 = KZMHIYDLXDJOHN;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor SCGHBTUSWZUMSQ;
/*DEF*/	DataCursor OYKIIDFWFXYAAA;
/*DEF*/	DataCursor YMOIVFHJLRWYAX;
/*SET*/	SCGHBTUSWZUMSQ = TLKHPEKHJNCYLC;
/*INC*/	if (!INC(SCGHBTUSWZUMSQ, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (SCGHBTUSWZUMSQ.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	OYKIIDFWFXYAAA = SCGHBTUSWZUMSQ.container->value.bracket_data.chain->at_before_first();
	YMOIVFHJLRWYAX   = SCGHBTUSWZUMSQ.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = OYKIIDFWFXYAAA;
/*SET*/	r_3 = OYKIIDFWFXYAAA;
/*JMP*/	goto label_AWGEURBRNBERAZ_firststep;
label_AWGEURBRNBERAZ: 
/*INC*/	if (!INC(r_3, YMOIVFHJLRWYAX)) goto sentence_after_2;
label_AWGEURBRNBERAZ_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor SXTKAQUEHJFCEW;
/*SET*/	SXTKAQUEHJFCEW = r_3;
/*INC*/	if (!INC(SXTKAQUEHJFCEW, YMOIVFHJLRWYAX)) goto label_AWGEURBRNBERAZ;
	if (SXTKAQUEHJFCEW.container->type != text || *(SXTKAQUEHJFCEW.container->value.text + SXTKAQUEHJFCEW.index) != '>') goto label_AWGEURBRNBERAZ;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor CTBFJTPQDLJHEH;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = SXTKAQUEHJFCEW;
/*SET*/	CTBFJTPQDLJHEH = SXTKAQUEHJFCEW;
/*INC*/	if (!INC(CTBFJTPQDLJHEH, YMOIVFHJLRWYAX)) goto label_AWGEURBRNBERAZ;
	if (! isSymbolType(CTBFJTPQDLJHEH.container->type)) goto label_AWGEURBRNBERAZ;
/*SET*/	r_A = CTBFJTPQDLJHEH;
//// [ e.1 ] 
/*DEF*/	DataCursor l_4;
/*DEF*/	DataCursor r_4;
/*SET*/	l_4 = r_A;
/*SET*/	r_4 = YMOIVFHJLRWYAX;
//// [ empty ] 
/*ISEMPTY*/	if (SCGHBTUSWZUMSQ!=0 && arg_to != SCGHBTUSWZUMSQ) goto label_AWGEURBRNBERAZ;

// подготовка подстановки 
DataChain* DZSCSFACXFZXFJ = new DataChain(); 
result->append(newRefExecBrackets(PolnAnaliz, DZSCSFACXFZXFJ, "PolnAnaliz")); 
DataChain* QOVERSCJZBKMZD = new DataChain(); 
DZSCSFACXFZXFJ->append(newRefStructBrackets(QOVERSCJZBKMZD)); 
QOVERSCJZBKMZD->append(newRefText("2")); 
DataChain* NDOSIYHTYAVOXH = new DataChain(); 
DZSCSFACXFZXFJ->append(newRefStructBrackets(NDOSIYHTYAVOXH)); 
NDOSIYHTYAVOXH->append_copy(l_1, r_1); 
NDOSIYHTYAVOXH->append_copy(l_A, r_A); 
DataChain* TAPYEKTUATPRWS = new DataChain(); 
DZSCSFACXFZXFJ->append(newRefStructBrackets(TAPYEKTUATPRWS)); 
TAPYEKTUATPRWS->append_copy(l_2, r_2); 
DataChain* KXZCZNFDIUEHUW = new DataChain(); 
DZSCSFACXFZXFJ->append(newRefStructBrackets(KXZCZNFDIUEHUW)); 
KXZCZNFDIUEHUW->append_copy(l_3, r_3); 
KXZCZNFDIUEHUW->append_copy(l_4, r_4); 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor YMTXDRNKLSMDUS;
/*DEF*/	DataCursor KVUTKFIUBZYBLW;
/*DEF*/	DataCursor MPARMJDSPXYWXE;
/*SET*/	YMTXDRNKLSMDUS = arg_from;
/*INC*/	if (!INC(YMTXDRNKLSMDUS, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (YMTXDRNKLSMDUS.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	KVUTKFIUBZYBLW = YMTXDRNKLSMDUS.container->value.bracket_data.chain->at_before_first();
	MPARMJDSPXYWXE   = YMTXDRNKLSMDUS.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor RFTZLKORIEBSUP;
/*SET*/	RFTZLKORIEBSUP = KVUTKFIUBZYBLW;
/*INC*/	if (!INC(RFTZLKORIEBSUP, MPARMJDSPXYWXE)) goto sentence_after_3;
	if (RFTZLKORIEBSUP.container->type != text || *(RFTZLKORIEBSUP.container->value.text + RFTZLKORIEBSUP.index) != '2') goto sentence_after_3;
//// [ empty ] 
/*ISEMPTY*/	if (RFTZLKORIEBSUP!=0 && MPARMJDSPXYWXE != RFTZLKORIEBSUP) goto sentence_after_3;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor LAITVYCICYZALW;
/*DEF*/	DataCursor UIUZTEYCTMUIFE;
/*DEF*/	DataCursor FYGAIAIOIIEDBY;
/*SET*/	LAITVYCICYZALW = YMTXDRNKLSMDUS;
/*INC*/	if (!INC(LAITVYCICYZALW, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (LAITVYCICYZALW.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	UIUZTEYCTMUIFE = LAITVYCICYZALW.container->value.bracket_data.chain->at_before_first();
	FYGAIAIOIIEDBY   = LAITVYCICYZALW.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = UIUZTEYCTMUIFE;
/*SET*/	r_1 = FYGAIAIOIIEDBY;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor WRGRTDXVDKOCSA;
/*DEF*/	DataCursor EHFCILQJOEVAJN;
/*DEF*/	DataCursor JTTKNRSPRTKRLK;
/*SET*/	WRGRTDXVDKOCSA = LAITVYCICYZALW;
/*INC*/	if (!INC(WRGRTDXVDKOCSA, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (WRGRTDXVDKOCSA.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	EHFCILQJOEVAJN = WRGRTDXVDKOCSA.container->value.bracket_data.chain->at_before_first();
	JTTKNRSPRTKRLK   = WRGRTDXVDKOCSA.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = EHFCILQJOEVAJN;
/*SET*/	r_2 = JTTKNRSPRTKRLK;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor JAPYMUZRPHZLCE;
/*DEF*/	DataCursor PAYTFAVEOPSZRN;
/*DEF*/	DataCursor KVNEHRJSTZFLVY;
/*SET*/	JAPYMUZRPHZLCE = WRGRTDXVDKOCSA;
/*INC*/	if (!INC(JAPYMUZRPHZLCE, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (JAPYMUZRPHZLCE.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	PAYTFAVEOPSZRN = JAPYMUZRPHZLCE.container->value.bracket_data.chain->at_before_first();
	KVNEHRJSTZFLVY   = JAPYMUZRPHZLCE.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = PAYTFAVEOPSZRN;
/*SET*/	r_3 = PAYTFAVEOPSZRN;
/*JMP*/	goto label_AHORKTKMGYCOUI_firststep;
label_AHORKTKMGYCOUI: 
/*INC*/	if (!INC(r_3, KVNEHRJSTZFLVY)) goto sentence_after_3;
label_AHORKTKMGYCOUI_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor ERTLPBJCSXQLGY;
/*SET*/	ERTLPBJCSXQLGY = r_3;
/*INC*/	if (!INC(ERTLPBJCSXQLGY, KVNEHRJSTZFLVY)) goto label_AHORKTKMGYCOUI;
	if (ERTLPBJCSXQLGY.container->type != text || *(ERTLPBJCSXQLGY.container->value.text + ERTLPBJCSXQLGY.index) != '>') goto label_AHORKTKMGYCOUI;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor GLMVLYQXIXIPVW;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = ERTLPBJCSXQLGY;
/*SET*/	GLMVLYQXIXIPVW = ERTLPBJCSXQLGY;
/*INC*/	if (!INC(GLMVLYQXIXIPVW, KVNEHRJSTZFLVY)) goto label_AHORKTKMGYCOUI;
	if (! isSymbolType(GLMVLYQXIXIPVW.container->type)) goto label_AHORKTKMGYCOUI;
/*SET*/	r_A = GLMVLYQXIXIPVW;
//// [ e.1 ] 
/*DEF*/	DataCursor l_4;
/*DEF*/	DataCursor r_4;
/*SET*/	l_4 = r_A;
/*SET*/	r_4 = KVNEHRJSTZFLVY;
//// [ empty ] 
/*ISEMPTY*/	if (JAPYMUZRPHZLCE!=0 && arg_to != JAPYMUZRPHZLCE) goto label_AHORKTKMGYCOUI;

// подготовка подстановки 
DataChain* MKRNJCOKVFKTQJ = new DataChain(); 
result->append(newRefExecBrackets(PolnAnaliz, MKRNJCOKVFKTQJ, "PolnAnaliz")); 
DataChain* DCUGBIDVBXRNSA = new DataChain(); 
MKRNJCOKVFKTQJ->append(newRefStructBrackets(DCUGBIDVBXRNSA)); 
DCUGBIDVBXRNSA->append(newRefText("1")); 
DataChain* QWXTBFTQSNPAVY = new DataChain(); 
MKRNJCOKVFKTQJ->append(newRefStructBrackets(QWXTBFTQSNPAVY)); 
QWXTBFTQSNPAVY->append_copy(l_1, r_1); 
DataChain* TODPJDPVYQXKSU = new DataChain(); 
MKRNJCOKVFKTQJ->append(newRefStructBrackets(TODPJDPVYQXKSU)); 
TODPJDPVYQXKSU->append_copy(l_2, r_2); 
TODPJDPVYQXKSU->append_copy(l_A, r_A); 
DataChain* VZWZTJRWOVTTLN = new DataChain(); 
MKRNJCOKVFKTQJ->append(newRefStructBrackets(VZWZTJRWOVTTLN)); 
VZWZTJRWOVTTLN->append_copy(l_3, r_3); 
VZWZTJRWOVTTLN->append_copy(l_4, r_4); 

return result; 
}
sentence_after_3: 

{
// подготовка предложения 
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = arg_from;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* KZNQDQIAUAPWKC = new DataChain(); 
result->append(newRefExecBrackets(Prout, KZNQDQIAUAPWKC, "Prout")); 
KZNQDQIAUAPWKC->append(newRefText("No point: ")); 
KZNQDQIAUAPWKC->append_copy(l_e, r_e); 

return result; 
}
sentence_after_4: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* PolnAnaliz__(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = arg_from;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* ZXRXOPENEUXFLG = new DataChain(); 
result->append(newRefExecBrackets(Prout, ZXRXOPENEUXFLG, "Prout")); 
ZXRXOPENEUXFLG->append(newRefWord("PolnAnaliz:")); 
ZXRXOPENEUXFLG->append_copy(l_e, r_e); 
DataChain* BDWJMHJGUZPEUD = new DataChain(); 
result->append(newRefExecBrackets(PolnAnaliz__, BDWJMHJGUZPEUD, "PolnAnaliz__")); 
BDWJMHJGUZPEUD->append_copy(l_e, r_e); 

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* PolnAnaliz(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor DFEIMOZYFRQMFO;
/*DEF*/	DataCursor ZISSCCRIFWQBHX;
/*DEF*/	DataCursor YEHKTUSDGZXLAE;
/*SET*/	DFEIMOZYFRQMFO = arg_from;
/*INC*/	if (!INC(DFEIMOZYFRQMFO, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (DFEIMOZYFRQMFO.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	ZISSCCRIFWQBHX = DFEIMOZYFRQMFO.container->value.bracket_data.chain->at_before_first();
	YEHKTUSDGZXLAE   = DFEIMOZYFRQMFO.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor YKEXQGQOEVJTFR;
/*DEF*/	DataCursor l_g;
/*DEF*/	DataCursor r_g;
/*SET*/	l_g = ZISSCCRIFWQBHX;
/*SET*/	YKEXQGQOEVJTFR = ZISSCCRIFWQBHX;
/*INC*/	if (!INC(YKEXQGQOEVJTFR, YEHKTUSDGZXLAE)) goto sentence_after_1;
	if (! isSymbolType(YKEXQGQOEVJTFR.container->type)) goto sentence_after_1;
/*SET*/	r_g = YKEXQGQOEVJTFR;
//// [ empty ] 
/*ISEMPTY*/	if (r_g!=0 && YEHKTUSDGZXLAE != r_g) goto sentence_after_1;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor AMUQGBDNRSMBXR;
/*DEF*/	DataCursor VBTFGLOWFFCTUJ;
/*DEF*/	DataCursor TZQWZGGTLBHROP;
/*SET*/	AMUQGBDNRSMBXR = DFEIMOZYFRQMFO;
/*INC*/	if (!INC(AMUQGBDNRSMBXR, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (AMUQGBDNRSMBXR.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	VBTFGLOWFFCTUJ = AMUQGBDNRSMBXR.container->value.bracket_data.chain->at_before_first();
	TZQWZGGTLBHROP   = AMUQGBDNRSMBXR.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = VBTFGLOWFFCTUJ;
/*SET*/	r_1 = TZQWZGGTLBHROP;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor KWKBBWVNAKWVVD;
/*DEF*/	DataCursor YCXCZOZQIWORVP;
/*DEF*/	DataCursor WKOQMQHCALYZVQ;
/*SET*/	KWKBBWVNAKWVVD = AMUQGBDNRSMBXR;
/*INC*/	if (!INC(KWKBBWVNAKWVVD, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (KWKBBWVNAKWVVD.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	YCXCZOZQIWORVP = KWKBBWVNAKWVVD.container->value.bracket_data.chain->at_before_first();
	WKOQMQHCALYZVQ   = KWKBBWVNAKWVVD.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = YCXCZOZQIWORVP;
/*SET*/	r_2 = WKOQMQHCALYZVQ;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor NKCXEKJQZVUESW;
/*DEF*/	DataCursor QKNZPYVYSDKHSO;
/*DEF*/	DataCursor ICMHCZOHEFNASL;
/*SET*/	NKCXEKJQZVUESW = KWKBBWVNAKWVVD;
/*INC*/	if (!INC(NKCXEKJQZVUESW, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (NKCXEKJQZVUESW.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	QKNZPYVYSDKHSO = NKCXEKJQZVUESW.container->value.bracket_data.chain->at_before_first();
	ICMHCZOHEFNASL   = NKCXEKJQZVUESW.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = QKNZPYVYSDKHSO;
/*SET*/	r_n = ICMHCZOHEFNASL;
//// [ empty ] 
/*ISEMPTY*/	if (NKCXEKJQZVUESW!=0 && arg_to != NKCXEKJQZVUESW) goto sentence_after_1;

// подготовка подстановки 
DataChain* XWXLLXLEWTZUWB = new DataChain(); 
result->append(newRefExecBrackets(Ifmust, XWXLLXLEWTZUWB, "Ifmust")); 
DataChain* SUVSENEIQWHNEZ = new DataChain(); 
XWXLLXLEWTZUWB->append(newRefStructBrackets(SUVSENEIQWHNEZ)); 
DataChain* OJKXHORYESUGDH = new DataChain(); 
SUVSENEIQWHNEZ->append(newRefExecBrackets(Strategy, OJKXHORYESUGDH, "Strategy")); 
OJKXHORYESUGDH->append_copy(l_1, r_1); 
DataChain* TJCKQJDFGNRDOI = new DataChain(); 
XWXLLXLEWTZUWB->append(newRefStructBrackets(TJCKQJDFGNRDOI)); 
DataChain* ZPYFMDLQLWQIOD = new DataChain(); 
TJCKQJDFGNRDOI->append(newRefExecBrackets(Strategy, ZPYFMDLQLWQIOD, "Strategy")); 
ZPYFMDLQLWQIOD->append_copy(l_2, r_2); 
DataChain* CWFYGKIVBUJFIN = new DataChain(); 
XWXLLXLEWTZUWB->append(newRefStructBrackets(CWFYGKIVBUJFIN)); 
DataChain* ZYHCEJCJOJONHG = new DataChain(); 
CWFYGKIVBUJFIN->append(newRefExecBrackets(Strategy, ZYHCEJCJOJONHG, "Strategy")); 
ZYHCEJCJOJONHG->append_copy(l_n, r_n); 
DataChain* USTQJFNECOLOCM = new DataChain(); 
XWXLLXLEWTZUWB->append(newRefStructBrackets(USTQJFNECOLOCM)); 
USTQJFNECOLOCM->append_copy(l_g, r_g); 
DataChain* FHPZXTGFPMUSCR = new DataChain(); 
XWXLLXLEWTZUWB->append(newRefStructBrackets(FHPZXTGFPMUSCR)); 
FHPZXTGFPMUSCR->append_copy(l_1, r_1); 
DataChain* LDURENNLQKWHHY = new DataChain(); 
XWXLLXLEWTZUWB->append(newRefStructBrackets(LDURENNLQKWHHY)); 
LDURENNLQKWHHY->append_copy(l_2, r_2); 
DataChain* IPQZEVBYKTBVTP = new DataChain(); 
XWXLLXLEWTZUWB->append(newRefStructBrackets(IPQZEVBYKTBVTP)); 
IPQZEVBYKTBVTP->append_copy(l_n, r_n); 

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Ifmust__(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = arg_from;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* WVTTGECAJYLQVU = new DataChain(); 
result->append(newRefExecBrackets(Prout, WVTTGECAJYLQVU, "Prout")); 
WVTTGECAJYLQVU->append(newRefWord("Ifmust:")); 
WVTTGECAJYLQVU->append_copy(l_e, r_e); 
DataChain* IZFSOAYXZILJZE = new DataChain(); 
result->append(newRefExecBrackets(Ifmust__, IZFSOAYXZILJZE, "Ifmust__")); 
IZFSOAYXZILJZE->append_copy(l_e, r_e); 

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Ifmust(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor GBLCATMVEFQRZX;
/*DEF*/	DataCursor WKTNDPBBZDRWLP;
/*DEF*/	DataCursor HLGDYWDOFNZXQL;
/*SET*/	GBLCATMVEFQRZX = arg_from;
/*INC*/	if (!INC(GBLCATMVEFQRZX, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (GBLCATMVEFQRZX.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	WKTNDPBBZDRWLP = GBLCATMVEFQRZX.container->value.bracket_data.chain->at_before_first();
	HLGDYWDOFNZXQL   = GBLCATMVEFQRZX.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_e1;
/*DEF*/	DataCursor r_e1;
/*SET*/	l_e1 = WKTNDPBBZDRWLP;
/*SET*/	r_e1 = HLGDYWDOFNZXQL;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor XVKHDJYALHVVPA;
/*DEF*/	DataCursor ANGODNLXHLSXSH;
/*DEF*/	DataCursor HTIFXICKOBIXBB;
/*SET*/	XVKHDJYALHVVPA = GBLCATMVEFQRZX;
/*INC*/	if (!INC(XVKHDJYALHVVPA, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (XVKHDJYALHVVPA.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	ANGODNLXHLSXSH = XVKHDJYALHVVPA.container->value.bracket_data.chain->at_before_first();
	HTIFXICKOBIXBB   = XVKHDJYALHVVPA.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e21;
/*DEF*/	DataCursor r_e21;
/*SET*/	l_e21 = ANGODNLXHLSXSH;
/*SET*/	r_e21 = ANGODNLXHLSXSH;
/*JMP*/	goto label_DUZVNGQIAGGCXF_firststep;
label_DUZVNGQIAGGCXF: 
/*INC*/	if (!INC(r_e21, HTIFXICKOBIXBB)) goto sentence_after_1;
label_DUZVNGQIAGGCXF_firststep: 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor GRJMARWUPAYBNQ;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_e21;
/*SET*/	GRJMARWUPAYBNQ = r_e21;
/*INC*/	if (!INC(GRJMARWUPAYBNQ, HTIFXICKOBIXBB)) goto label_DUZVNGQIAGGCXF;
	if (! isSymbolType(GRJMARWUPAYBNQ.container->type)) goto label_DUZVNGQIAGGCXF;
/*SET*/	r_A = GRJMARWUPAYBNQ;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e22;
/*DEF*/	DataCursor r_e22;
/*SET*/	l_e22 = r_A;
/*SET*/	r_e22 = r_A;
/*JMP*/	goto label_GUDBEWKGWGTOCB_firststep;
label_GUDBEWKGWGTOCB: 
/*INC*/	if (!INC(r_e22, HTIFXICKOBIXBB)) goto label_DUZVNGQIAGGCXF;
label_GUDBEWKGWGTOCB_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor LXJECCGQHBCZIB;
/*SET*/	LXJECCGQHBCZIB = r_e22;
 if (!SLIDE(LXJECCGQHBCZIB, HTIFXICKOBIXBB, l_A, r_A)) goto label_GUDBEWKGWGTOCB;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e23;
/*DEF*/	DataCursor r_e23;
/*SET*/	l_e23 = LXJECCGQHBCZIB;
/*SET*/	r_e23 = HTIFXICKOBIXBB;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor HQUFQQXVLLVMTZ;
/*DEF*/	DataCursor HFMBEZPLHQAKBM;
/*DEF*/	DataCursor MVAFQYXJYEXDSS;
/*SET*/	HQUFQQXVLLVMTZ = XVKHDJYALHVVPA;
/*INC*/	if (!INC(HQUFQQXVLLVMTZ, arg_to)) goto label_GUDBEWKGWGTOCB;
//// ISBRACKET 
	if (HQUFQQXVLLVMTZ.container->type != struct_bracket) goto label_GUDBEWKGWGTOCB;
//// JMP_BRACKET 
	HFMBEZPLHQAKBM = HQUFQQXVLLVMTZ.container->value.bracket_data.chain->at_before_first();
	MVAFQYXJYEXDSS   = HQUFQQXVLLVMTZ.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_nn1;
/*DEF*/	DataCursor r_nn1;
/*SET*/	l_nn1 = HFMBEZPLHQAKBM;
/*SET*/	r_nn1 = HFMBEZPLHQAKBM;
/*JMP*/	goto label_WBJIOUYMHLZCLT_firststep;
label_WBJIOUYMHLZCLT: 
/*INC*/	if (!INC(r_nn1, MVAFQYXJYEXDSS)) goto label_GUDBEWKGWGTOCB;
label_WBJIOUYMHLZCLT_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor JUDOBFUOIWUBGE;
/*SET*/	JUDOBFUOIWUBGE = r_nn1;
 if (!SLIDE(JUDOBFUOIWUBGE, MVAFQYXJYEXDSS, l_A, r_A)) goto label_WBJIOUYMHLZCLT;
//// [ e.1 ] 
/*DEF*/	DataCursor l_nn2;
/*DEF*/	DataCursor r_nn2;
/*SET*/	l_nn2 = JUDOBFUOIWUBGE;
/*SET*/	r_nn2 = MVAFQYXJYEXDSS;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor IDPMVKHOZHKDUC;
/*DEF*/	DataCursor OMLGLTLVEINNCA;
/*DEF*/	DataCursor IKNSUGJQCCASDX;
/*SET*/	IDPMVKHOZHKDUC = HQUFQQXVLLVMTZ;
/*INC*/	if (!INC(IDPMVKHOZHKDUC, arg_to)) goto label_WBJIOUYMHLZCLT;
//// ISBRACKET 
	if (IDPMVKHOZHKDUC.container->type != struct_bracket) goto label_WBJIOUYMHLZCLT;
//// JMP_BRACKET 
	OMLGLTLVEINNCA = IDPMVKHOZHKDUC.container->value.bracket_data.chain->at_before_first();
	IKNSUGJQCCASDX   = IDPMVKHOZHKDUC.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor DAZCRTVLLKFVTE;
/*SET*/	DAZCRTVLLKFVTE = OMLGLTLVEINNCA;
/*INC*/	if (!INC(DAZCRTVLLKFVTE, IKNSUGJQCCASDX)) goto label_WBJIOUYMHLZCLT;
	if (DAZCRTVLLKFVTE.container->type != text || *(DAZCRTVLLKFVTE.container->value.text + DAZCRTVLLKFVTE.index) != '2') goto label_WBJIOUYMHLZCLT;
//// [ empty ] 
/*ISEMPTY*/	if (DAZCRTVLLKFVTE!=0 && IKNSUGJQCCASDX != DAZCRTVLLKFVTE) goto label_WBJIOUYMHLZCLT;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e1e2;
/*DEF*/	DataCursor r_e1e2;
/*SET*/	l_e1e2 = IDPMVKHOZHKDUC;
/*SET*/	r_e1e2 = IDPMVKHOZHKDUC;
/*JMP*/	goto label_LTVKZDQOWGOLJP_firststep;
label_LTVKZDQOWGOLJP: 
/*INC*/	if (!INC(r_e1e2, arg_to)) goto label_WBJIOUYMHLZCLT;
label_LTVKZDQOWGOLJP_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor DSYQNCSDJSDCXX;
/*DEF*/	DataCursor YRGHRWPQINXMRI;
/*DEF*/	DataCursor DXPDPQUNVKWXRY;
/*SET*/	DSYQNCSDJSDCXX = r_e1e2;
/*INC*/	if (!INC(DSYQNCSDJSDCXX, arg_to)) goto label_LTVKZDQOWGOLJP;
//// ISBRACKET 
	if (DSYQNCSDJSDCXX.container->type != struct_bracket) goto label_LTVKZDQOWGOLJP;
//// JMP_BRACKET 
	YRGHRWPQINXMRI = DSYQNCSDJSDCXX.container->value.bracket_data.chain->at_before_first();
	DXPDPQUNVKWXRY   = DSYQNCSDJSDCXX.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = YRGHRWPQINXMRI;
/*SET*/	r_n = DXPDPQUNVKWXRY;
//// [ empty ] 
/*ISEMPTY*/	if (DSYQNCSDJSDCXX!=0 && arg_to != DSYQNCSDJSDCXX) goto label_LTVKZDQOWGOLJP;

// подготовка подстановки 
result->append(newRefText("2")); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor KXTLXYPPFMAJFH;
/*DEF*/	DataCursor QYUDWTIGBJTMQM;
/*DEF*/	DataCursor DLTCQZGCAIWSWF;
/*SET*/	KXTLXYPPFMAJFH = arg_from;
/*INC*/	if (!INC(KXTLXYPPFMAJFH, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (KXTLXYPPFMAJFH.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	QYUDWTIGBJTMQM = KXTLXYPPFMAJFH.container->value.bracket_data.chain->at_before_first();
	DLTCQZGCAIWSWF   = KXTLXYPPFMAJFH.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e21;
/*DEF*/	DataCursor r_e21;
/*SET*/	l_e21 = QYUDWTIGBJTMQM;
/*SET*/	r_e21 = QYUDWTIGBJTMQM;
/*JMP*/	goto label_YRYHCWWIARUHII_firststep;
label_YRYHCWWIARUHII: 
/*INC*/	if (!INC(r_e21, DLTCQZGCAIWSWF)) goto sentence_after_2;
label_YRYHCWWIARUHII_firststep: 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor BUJOPGRQNPIUGK;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_e21;
/*SET*/	BUJOPGRQNPIUGK = r_e21;
/*INC*/	if (!INC(BUJOPGRQNPIUGK, DLTCQZGCAIWSWF)) goto label_YRYHCWWIARUHII;
	if (! isSymbolType(BUJOPGRQNPIUGK.container->type)) goto label_YRYHCWWIARUHII;
/*SET*/	r_A = BUJOPGRQNPIUGK;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e22;
/*DEF*/	DataCursor r_e22;
/*SET*/	l_e22 = r_A;
/*SET*/	r_e22 = r_A;
/*JMP*/	goto label_DQTESOJACQHNWD_firststep;
label_DQTESOJACQHNWD: 
/*INC*/	if (!INC(r_e22, DLTCQZGCAIWSWF)) goto label_YRYHCWWIARUHII;
label_DQTESOJACQHNWD_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor AGNVXESFRFIEFA;
/*SET*/	AGNVXESFRFIEFA = r_e22;
 if (!SLIDE(AGNVXESFRFIEFA, DLTCQZGCAIWSWF, l_A, r_A)) goto label_DQTESOJACQHNWD;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e23;
/*DEF*/	DataCursor r_e23;
/*SET*/	l_e23 = AGNVXESFRFIEFA;
/*SET*/	r_e23 = DLTCQZGCAIWSWF;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor ABRADQEELKPKEC;
/*DEF*/	DataCursor VPSDWELPDJMMBP;
/*DEF*/	DataCursor DUPZVTVJXYDKDN;
/*SET*/	ABRADQEELKPKEC = KXTLXYPPFMAJFH;
/*INC*/	if (!INC(ABRADQEELKPKEC, arg_to)) goto label_DQTESOJACQHNWD;
//// ISBRACKET 
	if (ABRADQEELKPKEC.container->type != struct_bracket) goto label_DQTESOJACQHNWD;
//// JMP_BRACKET 
	VPSDWELPDJMMBP = ABRADQEELKPKEC.container->value.bracket_data.chain->at_before_first();
	DUPZVTVJXYDKDN   = ABRADQEELKPKEC.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_e1;
/*DEF*/	DataCursor r_e1;
/*SET*/	l_e1 = VPSDWELPDJMMBP;
/*SET*/	r_e1 = DUPZVTVJXYDKDN;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor CUGGHONUCWEGVF;
/*DEF*/	DataCursor JZBDWKBEVKGDWU;
/*DEF*/	DataCursor BTJVTOQOTHGGTD;
/*SET*/	CUGGHONUCWEGVF = ABRADQEELKPKEC;
/*INC*/	if (!INC(CUGGHONUCWEGVF, arg_to)) goto label_DQTESOJACQHNWD;
//// ISBRACKET 
	if (CUGGHONUCWEGVF.container->type != struct_bracket) goto label_DQTESOJACQHNWD;
//// JMP_BRACKET 
	JZBDWKBEVKGDWU = CUGGHONUCWEGVF.container->value.bracket_data.chain->at_before_first();
	BTJVTOQOTHGGTD   = CUGGHONUCWEGVF.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_nn1;
/*DEF*/	DataCursor r_nn1;
/*SET*/	l_nn1 = JZBDWKBEVKGDWU;
/*SET*/	r_nn1 = JZBDWKBEVKGDWU;
/*JMP*/	goto label_RDOLGJMFUBZZPN_firststep;
label_RDOLGJMFUBZZPN: 
/*INC*/	if (!INC(r_nn1, BTJVTOQOTHGGTD)) goto label_DQTESOJACQHNWD;
label_RDOLGJMFUBZZPN_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor HJAQWOTZQBLHMR;
/*SET*/	HJAQWOTZQBLHMR = r_nn1;
 if (!SLIDE(HJAQWOTZQBLHMR, BTJVTOQOTHGGTD, l_A, r_A)) goto label_RDOLGJMFUBZZPN;
//// [ e.1 ] 
/*DEF*/	DataCursor l_nn2;
/*DEF*/	DataCursor r_nn2;
/*SET*/	l_nn2 = HJAQWOTZQBLHMR;
/*SET*/	r_nn2 = BTJVTOQOTHGGTD;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor FZFGYKZMUCWWPD;
/*DEF*/	DataCursor YJVCTVFAMCGLTM;
/*DEF*/	DataCursor JTMRCJIVHSYTNW;
/*SET*/	FZFGYKZMUCWWPD = CUGGHONUCWEGVF;
/*INC*/	if (!INC(FZFGYKZMUCWWPD, arg_to)) goto label_RDOLGJMFUBZZPN;
//// ISBRACKET 
	if (FZFGYKZMUCWWPD.container->type != struct_bracket) goto label_RDOLGJMFUBZZPN;
//// JMP_BRACKET 
	YJVCTVFAMCGLTM = FZFGYKZMUCWWPD.container->value.bracket_data.chain->at_before_first();
	JTMRCJIVHSYTNW   = FZFGYKZMUCWWPD.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor MQQJVMOHFYESQX;
/*SET*/	MQQJVMOHFYESQX = YJVCTVFAMCGLTM;
/*INC*/	if (!INC(MQQJVMOHFYESQX, JTMRCJIVHSYTNW)) goto label_RDOLGJMFUBZZPN;
	if (MQQJVMOHFYESQX.container->type != text || *(MQQJVMOHFYESQX.container->value.text + MQQJVMOHFYESQX.index) != '1') goto label_RDOLGJMFUBZZPN;
//// [ empty ] 
/*ISEMPTY*/	if (MQQJVMOHFYESQX!=0 && JTMRCJIVHSYTNW != MQQJVMOHFYESQX) goto label_RDOLGJMFUBZZPN;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e1e2;
/*DEF*/	DataCursor r_e1e2;
/*SET*/	l_e1e2 = FZFGYKZMUCWWPD;
/*SET*/	r_e1e2 = FZFGYKZMUCWWPD;
/*JMP*/	goto label_XLOZMCQMVHTCEX_firststep;
label_XLOZMCQMVHTCEX: 
/*INC*/	if (!INC(r_e1e2, arg_to)) goto label_RDOLGJMFUBZZPN;
label_XLOZMCQMVHTCEX_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor AMEYKVIXDAQVSS;
/*DEF*/	DataCursor DWWOEDKLQENAFB;
/*DEF*/	DataCursor CFNHWRHDKJCSXO;
/*SET*/	AMEYKVIXDAQVSS = r_e1e2;
/*INC*/	if (!INC(AMEYKVIXDAQVSS, arg_to)) goto label_XLOZMCQMVHTCEX;
//// ISBRACKET 
	if (AMEYKVIXDAQVSS.container->type != struct_bracket) goto label_XLOZMCQMVHTCEX;
//// JMP_BRACKET 
	DWWOEDKLQENAFB = AMEYKVIXDAQVSS.container->value.bracket_data.chain->at_before_first();
	CFNHWRHDKJCSXO   = AMEYKVIXDAQVSS.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = DWWOEDKLQENAFB;
/*SET*/	r_n = CFNHWRHDKJCSXO;
//// [ empty ] 
/*ISEMPTY*/	if (AMEYKVIXDAQVSS!=0 && arg_to != AMEYKVIXDAQVSS) goto label_XLOZMCQMVHTCEX;

// подготовка подстановки 
result->append(newRefText("1")); 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor HDVRBNLBLSEEND;
/*DEF*/	DataCursor UBKXAORTEJLRCM;
/*DEF*/	DataCursor CVOVRSQRCOPNNP;
/*SET*/	HDVRBNLBLSEEND = arg_from;
/*INC*/	if (!INC(HDVRBNLBLSEEND, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (HDVRBNLBLSEEND.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	UBKXAORTEJLRCM = HDVRBNLBLSEEND.container->value.bracket_data.chain->at_before_first();
	CVOVRSQRCOPNNP   = HDVRBNLBLSEEND.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_e1;
/*DEF*/	DataCursor r_e1;
/*SET*/	l_e1 = UBKXAORTEJLRCM;
/*SET*/	r_e1 = CVOVRSQRCOPNNP;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor KUNKKCPOENVPKV;
/*DEF*/	DataCursor YGUNPABOUJVIRE;
/*DEF*/	DataCursor LEHLGECTNAZVQP;
/*SET*/	KUNKKCPOENVPKV = HDVRBNLBLSEEND;
/*INC*/	if (!INC(KUNKKCPOENVPKV, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (KUNKKCPOENVPKV.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	YGUNPABOUJVIRE = KUNKKCPOENVPKV.container->value.bracket_data.chain->at_before_first();
	LEHLGECTNAZVQP   = KUNKKCPOENVPKV.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e21;
/*DEF*/	DataCursor r_e21;
/*SET*/	l_e21 = YGUNPABOUJVIRE;
/*SET*/	r_e21 = YGUNPABOUJVIRE;
/*JMP*/	goto label_SOUUBCPYFIKGQT_firststep;
label_SOUUBCPYFIKGQT: 
/*INC*/	if (!INC(r_e21, LEHLGECTNAZVQP)) goto sentence_after_3;
label_SOUUBCPYFIKGQT_firststep: 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor UFVQQEVCPCJPMJ;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_e21;
/*SET*/	UFVQQEVCPCJPMJ = r_e21;
/*INC*/	if (!INC(UFVQQEVCPCJPMJ, LEHLGECTNAZVQP)) goto label_SOUUBCPYFIKGQT;
	if (! isSymbolType(UFVQQEVCPCJPMJ.container->type)) goto label_SOUUBCPYFIKGQT;
/*SET*/	r_A = UFVQQEVCPCJPMJ;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e22;
/*DEF*/	DataCursor r_e22;
/*SET*/	l_e22 = r_A;
/*SET*/	r_e22 = r_A;
/*JMP*/	goto label_HPUACSIASPTSKQ_firststep;
label_HPUACSIASPTSKQ: 
/*INC*/	if (!INC(r_e22, LEHLGECTNAZVQP)) goto label_SOUUBCPYFIKGQT;
label_HPUACSIASPTSKQ_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor YHITAUZFABLPQL;
/*SET*/	YHITAUZFABLPQL = r_e22;
 if (!SLIDE(YHITAUZFABLPQL, LEHLGECTNAZVQP, l_A, r_A)) goto label_HPUACSIASPTSKQ;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e23;
/*DEF*/	DataCursor r_e23;
/*SET*/	l_e23 = YHITAUZFABLPQL;
/*SET*/	r_e23 = LEHLGECTNAZVQP;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor KUKAHMLIVZAPRO;
/*DEF*/	DataCursor TLQDIUOEEYKIQZ;
/*DEF*/	DataCursor AHFAVZZRFRZZEM;
/*SET*/	KUKAHMLIVZAPRO = KUNKKCPOENVPKV;
/*INC*/	if (!INC(KUKAHMLIVZAPRO, arg_to)) goto label_HPUACSIASPTSKQ;
//// ISBRACKET 
	if (KUKAHMLIVZAPRO.container->type != struct_bracket) goto label_HPUACSIASPTSKQ;
//// JMP_BRACKET 
	TLQDIUOEEYKIQZ = KUKAHMLIVZAPRO.container->value.bracket_data.chain->at_before_first();
	AHFAVZZRFRZZEM   = KUKAHMLIVZAPRO.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_nn1;
/*DEF*/	DataCursor r_nn1;
/*SET*/	l_nn1 = TLQDIUOEEYKIQZ;
/*SET*/	r_nn1 = TLQDIUOEEYKIQZ;
/*JMP*/	goto label_IYZVOBXUOJORAW_firststep;
label_IYZVOBXUOJORAW: 
/*INC*/	if (!INC(r_nn1, AHFAVZZRFRZZEM)) goto label_HPUACSIASPTSKQ;
label_IYZVOBXUOJORAW_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor URHJOPPNNCTEHR;
/*SET*/	URHJOPPNNCTEHR = r_nn1;
 if (!SLIDE(URHJOPPNNCTEHR, AHFAVZZRFRZZEM, l_A, r_A)) goto label_IYZVOBXUOJORAW;
//// [ e.1 ] 
/*DEF*/	DataCursor l_nn2;
/*DEF*/	DataCursor r_nn2;
/*SET*/	l_nn2 = URHJOPPNNCTEHR;
/*SET*/	r_nn2 = AHFAVZZRFRZZEM;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor ULPGKOZUYWMOBC;
/*DEF*/	DataCursor DLBOFBJEJAZSRU;
/*DEF*/	DataCursor LVQTAMMEMHQPYI;
/*SET*/	ULPGKOZUYWMOBC = KUKAHMLIVZAPRO;
/*INC*/	if (!INC(ULPGKOZUYWMOBC, arg_to)) goto label_IYZVOBXUOJORAW;
//// ISBRACKET 
	if (ULPGKOZUYWMOBC.container->type != struct_bracket) goto label_IYZVOBXUOJORAW;
//// JMP_BRACKET 
	DLBOFBJEJAZSRU = ULPGKOZUYWMOBC.container->value.bracket_data.chain->at_before_first();
	LVQTAMMEMHQPYI   = ULPGKOZUYWMOBC.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor OWMNLQAEFZSIOT;
/*SET*/	OWMNLQAEFZSIOT = DLBOFBJEJAZSRU;
/*INC*/	if (!INC(OWMNLQAEFZSIOT, LVQTAMMEMHQPYI)) goto label_IYZVOBXUOJORAW;
	if (OWMNLQAEFZSIOT.container->type != text || *(OWMNLQAEFZSIOT.container->value.text + OWMNLQAEFZSIOT.index) != '1') goto label_IYZVOBXUOJORAW;
//// [ empty ] 
/*ISEMPTY*/	if (OWMNLQAEFZSIOT!=0 && LVQTAMMEMHQPYI != OWMNLQAEFZSIOT) goto label_IYZVOBXUOJORAW;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e1e2;
/*DEF*/	DataCursor r_e1e2;
/*SET*/	l_e1e2 = ULPGKOZUYWMOBC;
/*SET*/	r_e1e2 = ULPGKOZUYWMOBC;
/*JMP*/	goto label_SZRRRUGIMNJBJA_firststep;
label_SZRRRUGIMNJBJA: 
/*INC*/	if (!INC(r_e1e2, arg_to)) goto label_IYZVOBXUOJORAW;
label_SZRRRUGIMNJBJA_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor LQLRCEZJFXCHWD;
/*DEF*/	DataCursor DXONZMNJVLRJXR;
/*DEF*/	DataCursor XWKDUOOERCTEEQ;
/*SET*/	LQLRCEZJFXCHWD = r_e1e2;
/*INC*/	if (!INC(LQLRCEZJFXCHWD, arg_to)) goto label_SZRRRUGIMNJBJA;
//// ISBRACKET 
	if (LQLRCEZJFXCHWD.container->type != struct_bracket) goto label_SZRRRUGIMNJBJA;
//// JMP_BRACKET 
	DXONZMNJVLRJXR = LQLRCEZJFXCHWD.container->value.bracket_data.chain->at_before_first();
	XWKDUOOERCTEEQ   = LQLRCEZJFXCHWD.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = DXONZMNJVLRJXR;
/*SET*/	r_n = XWKDUOOERCTEEQ;
//// [ empty ] 
/*ISEMPTY*/	if (LQLRCEZJFXCHWD!=0 && arg_to != LQLRCEZJFXCHWD) goto label_SZRRRUGIMNJBJA;

// подготовка подстановки 
DataChain* DVDLRWAMNKYXJS = new DataChain(); 
result->append(newRefExecBrackets(StepShag, DVDLRWAMNKYXJS, "StepShag")); 
DataChain* XPFDLZEHBGKVYP = new DataChain(); 
DVDLRWAMNKYXJS->append(newRefExecBrackets(Lins, XPFDLZEHBGKVYP, "Lins")); 
DataChain* XFSMQHIBNGJTGR = new DataChain(); 
XPFDLZEHBGKVYP->append(newRefStructBrackets(XFSMQHIBNGJTGR)); 
XFSMQHIBNGJTGR->append_copy(l_n, r_n); 
DataChain* KPFERAYXDZNPGK = new DataChain(); 
XPFDLZEHBGKVYP->append(newRefExecBrackets(AntiStrategy, KPFERAYXDZNPGK, "AntiStrategy")); 
KPFERAYXDZNPGK->append_copy(l_A, r_A); 
DataChain* SDFPDJOBICQFQM = new DataChain(); 
DVDLRWAMNKYXJS->append(newRefStructBrackets(SDFPDJOBICQFQM)); 
SDFPDJOBICQFQM->append(newRefText("1")); 
DVDLRWAMNKYXJS->append_copy(l_e1e2, r_e1e2); 
DataChain* FSTQHPFMCPMFDC = new DataChain(); 
DVDLRWAMNKYXJS->append(newRefStructBrackets(FSTQHPFMCPMFDC)); 
FSTQHPFMCPMFDC->append_copy(l_n, r_n); 

return result; 
}
sentence_after_3: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor DCCMODLQJQGWJO;
/*DEF*/	DataCursor FNUQNPMHDVKZEB;
/*DEF*/	DataCursor NLIGKJFSWCXWCU;
/*SET*/	DCCMODLQJQGWJO = arg_from;
/*INC*/	if (!INC(DCCMODLQJQGWJO, arg_to)) goto sentence_after_4;
//// ISBRACKET 
	if (DCCMODLQJQGWJO.container->type != struct_bracket) goto sentence_after_4;
//// JMP_BRACKET 
	FNUQNPMHDVKZEB = DCCMODLQJQGWJO.container->value.bracket_data.chain->at_before_first();
	NLIGKJFSWCXWCU   = DCCMODLQJQGWJO.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e21;
/*DEF*/	DataCursor r_e21;
/*SET*/	l_e21 = FNUQNPMHDVKZEB;
/*SET*/	r_e21 = FNUQNPMHDVKZEB;
/*JMP*/	goto label_JWHEPDBSGTFFKB_firststep;
label_JWHEPDBSGTFFKB: 
/*INC*/	if (!INC(r_e21, NLIGKJFSWCXWCU)) goto sentence_after_4;
label_JWHEPDBSGTFFKB_firststep: 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor YKEUHNFZNGKPMV;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_e21;
/*SET*/	YKEUHNFZNGKPMV = r_e21;
/*INC*/	if (!INC(YKEUHNFZNGKPMV, NLIGKJFSWCXWCU)) goto label_JWHEPDBSGTFFKB;
	if (! isSymbolType(YKEUHNFZNGKPMV.container->type)) goto label_JWHEPDBSGTFFKB;
/*SET*/	r_A = YKEUHNFZNGKPMV;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e22;
/*DEF*/	DataCursor r_e22;
/*SET*/	l_e22 = r_A;
/*SET*/	r_e22 = r_A;
/*JMP*/	goto label_QTHEJJRBZHRCGG_firststep;
label_QTHEJJRBZHRCGG: 
/*INC*/	if (!INC(r_e22, NLIGKJFSWCXWCU)) goto label_JWHEPDBSGTFFKB;
label_QTHEJJRBZHRCGG_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor OEWVRXBWYSZBLQ;
/*SET*/	OEWVRXBWYSZBLQ = r_e22;
 if (!SLIDE(OEWVRXBWYSZBLQ, NLIGKJFSWCXWCU, l_A, r_A)) goto label_QTHEJJRBZHRCGG;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e23;
/*DEF*/	DataCursor r_e23;
/*SET*/	l_e23 = OEWVRXBWYSZBLQ;
/*SET*/	r_e23 = NLIGKJFSWCXWCU;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor GPWJPLTJFRQCOC;
/*DEF*/	DataCursor QXYLUTTLWHTZAS;
/*DEF*/	DataCursor NQEOYJBXKIQMAJ;
/*SET*/	GPWJPLTJFRQCOC = DCCMODLQJQGWJO;
/*INC*/	if (!INC(GPWJPLTJFRQCOC, arg_to)) goto label_QTHEJJRBZHRCGG;
//// ISBRACKET 
	if (GPWJPLTJFRQCOC.container->type != struct_bracket) goto label_QTHEJJRBZHRCGG;
//// JMP_BRACKET 
	QXYLUTTLWHTZAS = GPWJPLTJFRQCOC.container->value.bracket_data.chain->at_before_first();
	NQEOYJBXKIQMAJ   = GPWJPLTJFRQCOC.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_e1;
/*DEF*/	DataCursor r_e1;
/*SET*/	l_e1 = QXYLUTTLWHTZAS;
/*SET*/	r_e1 = NQEOYJBXKIQMAJ;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor AGFHZZFBDVFUYU;
/*DEF*/	DataCursor RLVURNWRAMCADU;
/*DEF*/	DataCursor NWUGTUESHXMGZV;
/*SET*/	AGFHZZFBDVFUYU = GPWJPLTJFRQCOC;
/*INC*/	if (!INC(AGFHZZFBDVFUYU, arg_to)) goto label_QTHEJJRBZHRCGG;
//// ISBRACKET 
	if (AGFHZZFBDVFUYU.container->type != struct_bracket) goto label_QTHEJJRBZHRCGG;
//// JMP_BRACKET 
	RLVURNWRAMCADU = AGFHZZFBDVFUYU.container->value.bracket_data.chain->at_before_first();
	NWUGTUESHXMGZV   = AGFHZZFBDVFUYU.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_nn1;
/*DEF*/	DataCursor r_nn1;
/*SET*/	l_nn1 = RLVURNWRAMCADU;
/*SET*/	r_nn1 = RLVURNWRAMCADU;
/*JMP*/	goto label_SRMCIFBVRASUCU_firststep;
label_SRMCIFBVRASUCU: 
/*INC*/	if (!INC(r_nn1, NWUGTUESHXMGZV)) goto label_QTHEJJRBZHRCGG;
label_SRMCIFBVRASUCU_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor VIVOWLZIVLIICZ;
/*SET*/	VIVOWLZIVLIICZ = r_nn1;
 if (!SLIDE(VIVOWLZIVLIICZ, NWUGTUESHXMGZV, l_A, r_A)) goto label_SRMCIFBVRASUCU;
//// [ e.1 ] 
/*DEF*/	DataCursor l_nn2;
/*DEF*/	DataCursor r_nn2;
/*SET*/	l_nn2 = VIVOWLZIVLIICZ;
/*SET*/	r_nn2 = NWUGTUESHXMGZV;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor PUSSWAFKENWEMO;
/*DEF*/	DataCursor CIMLMSLEBFIIAR;
/*DEF*/	DataCursor GFMUABIZMYQPTH;
/*SET*/	PUSSWAFKENWEMO = AGFHZZFBDVFUYU;
/*INC*/	if (!INC(PUSSWAFKENWEMO, arg_to)) goto label_SRMCIFBVRASUCU;
//// ISBRACKET 
	if (PUSSWAFKENWEMO.container->type != struct_bracket) goto label_SRMCIFBVRASUCU;
//// JMP_BRACKET 
	CIMLMSLEBFIIAR = PUSSWAFKENWEMO.container->value.bracket_data.chain->at_before_first();
	GFMUABIZMYQPTH   = PUSSWAFKENWEMO.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor DMZEIEGQCJTSJH;
/*SET*/	DMZEIEGQCJTSJH = CIMLMSLEBFIIAR;
/*INC*/	if (!INC(DMZEIEGQCJTSJH, GFMUABIZMYQPTH)) goto label_SRMCIFBVRASUCU;
	if (DMZEIEGQCJTSJH.container->type != text || *(DMZEIEGQCJTSJH.container->value.text + DMZEIEGQCJTSJH.index) != '2') goto label_SRMCIFBVRASUCU;
//// [ empty ] 
/*ISEMPTY*/	if (DMZEIEGQCJTSJH!=0 && GFMUABIZMYQPTH != DMZEIEGQCJTSJH) goto label_SRMCIFBVRASUCU;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e1e2;
/*DEF*/	DataCursor r_e1e2;
/*SET*/	l_e1e2 = PUSSWAFKENWEMO;
/*SET*/	r_e1e2 = PUSSWAFKENWEMO;
/*JMP*/	goto label_MZGRXOKCHGOALG_firststep;
label_MZGRXOKCHGOALG: 
/*INC*/	if (!INC(r_e1e2, arg_to)) goto label_SRMCIFBVRASUCU;
label_MZGRXOKCHGOALG_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor UQCNQYROKQMJSZ;
/*DEF*/	DataCursor JWSDGCOFGLCQGD;
/*DEF*/	DataCursor NDBYPQQIDCLZXS;
/*SET*/	UQCNQYROKQMJSZ = r_e1e2;
/*INC*/	if (!INC(UQCNQYROKQMJSZ, arg_to)) goto label_MZGRXOKCHGOALG;
//// ISBRACKET 
	if (UQCNQYROKQMJSZ.container->type != struct_bracket) goto label_MZGRXOKCHGOALG;
//// JMP_BRACKET 
	JWSDGCOFGLCQGD = UQCNQYROKQMJSZ.container->value.bracket_data.chain->at_before_first();
	NDBYPQQIDCLZXS   = UQCNQYROKQMJSZ.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = JWSDGCOFGLCQGD;
/*SET*/	r_n = NDBYPQQIDCLZXS;
//// [ empty ] 
/*ISEMPTY*/	if (UQCNQYROKQMJSZ!=0 && arg_to != UQCNQYROKQMJSZ) goto label_MZGRXOKCHGOALG;

// подготовка подстановки 
DataChain* QBJWIPLOXDERKL = new DataChain(); 
result->append(newRefExecBrackets(StepShag, QBJWIPLOXDERKL, "StepShag")); 
DataChain* GBXGOGNWYUNRNU = new DataChain(); 
QBJWIPLOXDERKL->append(newRefExecBrackets(Lins, GBXGOGNWYUNRNU, "Lins")); 
DataChain* MFOLBALEZROKNK = new DataChain(); 
GBXGOGNWYUNRNU->append(newRefStructBrackets(MFOLBALEZROKNK)); 
MFOLBALEZROKNK->append_copy(l_n, r_n); 
DataChain* JNWRWEBGELZBGI = new DataChain(); 
GBXGOGNWYUNRNU->append(newRefExecBrackets(AntiStrategy, JNWRWEBGELZBGI, "AntiStrategy")); 
JNWRWEBGELZBGI->append_copy(l_A, r_A); 
DataChain* QDSCWTSBXXZKGH = new DataChain(); 
QBJWIPLOXDERKL->append(newRefStructBrackets(QDSCWTSBXXZKGH)); 
QDSCWTSBXXZKGH->append(newRefText("2")); 
QBJWIPLOXDERKL->append_copy(l_e1e2, r_e1e2); 
DataChain* SKGEXLEVGXNYDQ = new DataChain(); 
QBJWIPLOXDERKL->append(newRefStructBrackets(SKGEXLEVGXNYDQ)); 
SKGEXLEVGXNYDQ->append_copy(l_n, r_n); 

return result; 
}
sentence_after_4: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor VTYJSLLQKEHTLI;
/*DEF*/	DataCursor AUYICCQDMFIEJR;
/*DEF*/	DataCursor QNRNAZCRFHPBJM;
/*SET*/	VTYJSLLQKEHTLI = arg_from;
/*INC*/	if (!INC(VTYJSLLQKEHTLI, arg_to)) goto sentence_after_5;
//// ISBRACKET 
	if (VTYJSLLQKEHTLI.container->type != struct_bracket) goto sentence_after_5;
//// JMP_BRACKET 
	AUYICCQDMFIEJR = VTYJSLLQKEHTLI.container->value.bracket_data.chain->at_before_first();
	QNRNAZCRFHPBJM   = VTYJSLLQKEHTLI.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_e1;
/*DEF*/	DataCursor r_e1;
/*SET*/	l_e1 = AUYICCQDMFIEJR;
/*SET*/	r_e1 = QNRNAZCRFHPBJM;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor RFBYQMHDABALHT;
/*DEF*/	DataCursor IGPQMWFONTEPRC;
/*DEF*/	DataCursor HDDWEQDOHSPJDG;
/*SET*/	RFBYQMHDABALHT = VTYJSLLQKEHTLI;
/*INC*/	if (!INC(RFBYQMHDABALHT, arg_to)) goto sentence_after_5;
//// ISBRACKET 
	if (RFBYQMHDABALHT.container->type != struct_bracket) goto sentence_after_5;
//// JMP_BRACKET 
	IGPQMWFONTEPRC = RFBYQMHDABALHT.container->value.bracket_data.chain->at_before_first();
	HDDWEQDOHSPJDG   = RFBYQMHDABALHT.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_e2;
/*DEF*/	DataCursor r_e2;
/*SET*/	l_e2 = IGPQMWFONTEPRC;
/*SET*/	r_e2 = HDDWEQDOHSPJDG;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor VLZMJBMWEOILEJ;
/*DEF*/	DataCursor RPKSBXEESTGPSM;
/*DEF*/	DataCursor NMALPUSWIBUBAQ;
/*SET*/	VLZMJBMWEOILEJ = RFBYQMHDABALHT;
/*INC*/	if (!INC(VLZMJBMWEOILEJ, arg_to)) goto sentence_after_5;
//// ISBRACKET 
	if (VLZMJBMWEOILEJ.container->type != struct_bracket) goto sentence_after_5;
//// JMP_BRACKET 
	RPKSBXEESTGPSM = VLZMJBMWEOILEJ.container->value.bracket_data.chain->at_before_first();
	NMALPUSWIBUBAQ   = VLZMJBMWEOILEJ.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_nn;
/*DEF*/	DataCursor r_nn;
/*SET*/	l_nn = RPKSBXEESTGPSM;
/*SET*/	r_nn = NMALPUSWIBUBAQ;
//// [ e.1 ] 
/*DEF*/	DataCursor l_hn;
/*DEF*/	DataCursor r_hn;
/*SET*/	l_hn = VLZMJBMWEOILEJ;
/*SET*/	r_hn = arg_to;

// подготовка подстановки 
DataChain* VOTCAYTBTUZDTW = new DataChain(); 
result->append(newRefExecBrackets(PolnAnalizEny, VOTCAYTBTUZDTW, "PolnAnalizEny")); 
VOTCAYTBTUZDTW->append_copy(l_hn, r_hn); 

return result; 
}
sentence_after_5: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* StepShag(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor SYSJRVRWGIXZHX;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = arg_from;
/*SET*/	SYSJRVRWGIXZHX = arg_from;
/*INC*/	if (!INC(SYSJRVRWGIXZHX, arg_to)) goto sentence_after_1;
	if (! isSymbolType(SYSJRVRWGIXZHX.container->type)) goto sentence_after_1;
/*SET*/	r_A = SYSJRVRWGIXZHX;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor WHIUHVQTKJPQZY;
/*DEF*/	DataCursor YHHTXMJFMQLFWZ;
/*DEF*/	DataCursor JFQVBENLERLKYA;
/*SET*/	WHIUHVQTKJPQZY = r_A;
/*INC*/	if (!INC(WHIUHVQTKJPQZY, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (WHIUHVQTKJPQZY.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	YHHTXMJFMQLFWZ = WHIUHVQTKJPQZY.container->value.bracket_data.chain->at_before_first();
	JFQVBENLERLKYA   = WHIUHVQTKJPQZY.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor WOLVBTYZGEWXCC;
/*SET*/	WOLVBTYZGEWXCC = YHHTXMJFMQLFWZ;
/*INC*/	if (!INC(WOLVBTYZGEWXCC, JFQVBENLERLKYA)) goto sentence_after_1;
	if (WOLVBTYZGEWXCC.container->type != text || *(WOLVBTYZGEWXCC.container->value.text + WOLVBTYZGEWXCC.index) != '1') goto sentence_after_1;
//// [ empty ] 
/*ISEMPTY*/	if (WOLVBTYZGEWXCC!=0 && JFQVBENLERLKYA != WOLVBTYZGEWXCC) goto sentence_after_1;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor JVMWGSFFVOWDLR;
/*DEF*/	DataCursor YINXFIWFHTLDYT;
/*DEF*/	DataCursor YGQKXRWDVRKCOY;
/*SET*/	JVMWGSFFVOWDLR = WHIUHVQTKJPQZY;
/*INC*/	if (!INC(JVMWGSFFVOWDLR, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (JVMWGSFFVOWDLR.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	YINXFIWFHTLDYT = JVMWGSFFVOWDLR.container->value.bracket_data.chain->at_before_first();
	YGQKXRWDVRKCOY   = JVMWGSFFVOWDLR.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = YINXFIWFHTLDYT;
/*SET*/	r_1 = YGQKXRWDVRKCOY;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor TXKCWEAGYDMHRP;
/*DEF*/	DataCursor YQUIMWRBVEZZVV;
/*DEF*/	DataCursor JPGIHCYFQZVADT;
/*SET*/	TXKCWEAGYDMHRP = JVMWGSFFVOWDLR;
/*INC*/	if (!INC(TXKCWEAGYDMHRP, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (TXKCWEAGYDMHRP.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	YQUIMWRBVEZZVV = TXKCWEAGYDMHRP.container->value.bracket_data.chain->at_before_first();
	JPGIHCYFQZVADT   = TXKCWEAGYDMHRP.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = YQUIMWRBVEZZVV;
/*SET*/	r_2 = JPGIHCYFQZVADT;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor DFYEMFQVYNBDLR;
/*DEF*/	DataCursor QHVAPGYSGGXDOR;
/*DEF*/	DataCursor KVMVQEXPJFGVPI;
/*SET*/	DFYEMFQVYNBDLR = TXKCWEAGYDMHRP;
/*INC*/	if (!INC(DFYEMFQVYNBDLR, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (DFYEMFQVYNBDLR.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	QHVAPGYSGGXDOR = DFYEMFQVYNBDLR.container->value.bracket_data.chain->at_before_first();
	KVMVQEXPJFGVPI   = DFYEMFQVYNBDLR.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_n1;
/*DEF*/	DataCursor r_n1;
/*SET*/	l_n1 = QHVAPGYSGGXDOR;
/*SET*/	r_n1 = QHVAPGYSGGXDOR;
/*JMP*/	goto label_FYIDTTGGSDYJBV_firststep;
label_FYIDTTGGSDYJBV: 
/*INC*/	if (!INC(r_n1, KVMVQEXPJFGVPI)) goto sentence_after_1;
label_FYIDTTGGSDYJBV_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor OLBMCGBRRVKUPT;
/*SET*/	OLBMCGBRRVKUPT = r_n1;
 if (!SLIDE(OLBMCGBRRVKUPT, KVMVQEXPJFGVPI, l_A, r_A)) goto label_FYIDTTGGSDYJBV;
//// [ e.1 ] 
/*DEF*/	DataCursor l_n2;
/*DEF*/	DataCursor r_n2;
/*SET*/	l_n2 = OLBMCGBRRVKUPT;
/*SET*/	r_n2 = KVMVQEXPJFGVPI;
//// [ empty ] 
/*ISEMPTY*/	if (DFYEMFQVYNBDLR!=0 && arg_to != DFYEMFQVYNBDLR) goto label_FYIDTTGGSDYJBV;

// подготовка подстановки 
DataChain* ANLZOSCTFNYSZK = new DataChain(); 
result->append(newRefExecBrackets(PolnAnaliz, ANLZOSCTFNYSZK, "PolnAnaliz")); 
DataChain* LRNZRKUXYJPWWM = new DataChain(); 
ANLZOSCTFNYSZK->append(newRefStructBrackets(LRNZRKUXYJPWWM)); 
LRNZRKUXYJPWWM->append(newRefText("2")); 
DataChain* INHPLXGXWULGXH = new DataChain(); 
ANLZOSCTFNYSZK->append(newRefStructBrackets(INHPLXGXWULGXH)); 
INHPLXGXWULGXH->append_copy(l_1, r_1); 
INHPLXGXWULGXH->append_copy(l_A, r_A); 
DataChain* LMSBZRQUAJUAXP = new DataChain(); 
ANLZOSCTFNYSZK->append(newRefStructBrackets(LMSBZRQUAJUAXP)); 
LMSBZRQUAJUAXP->append_copy(l_2, r_2); 
DataChain* DPSMWIWXXDVIPO = new DataChain(); 
ANLZOSCTFNYSZK->append(newRefStructBrackets(DPSMWIWXXDVIPO)); 
DPSMWIWXXDVIPO->append_copy(l_n1, r_n1); 
DPSMWIWXXDVIPO->append_copy(l_n2, r_n2); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor UXTLKQWWOWRQEA;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = arg_from;
/*SET*/	UXTLKQWWOWRQEA = arg_from;
/*INC*/	if (!INC(UXTLKQWWOWRQEA, arg_to)) goto sentence_after_2;
	if (! isSymbolType(UXTLKQWWOWRQEA.container->type)) goto sentence_after_2;
/*SET*/	r_A = UXTLKQWWOWRQEA;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor TQBMMILPOXBIPW;
/*DEF*/	DataCursor WEGHTFIQJQKBNJ;
/*DEF*/	DataCursor HXDKUNEBQGRIZK;
/*SET*/	TQBMMILPOXBIPW = r_A;
/*INC*/	if (!INC(TQBMMILPOXBIPW, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (TQBMMILPOXBIPW.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	WEGHTFIQJQKBNJ = TQBMMILPOXBIPW.container->value.bracket_data.chain->at_before_first();
	HXDKUNEBQGRIZK   = TQBMMILPOXBIPW.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor EKGERQQLYYFESO;
/*SET*/	EKGERQQLYYFESO = WEGHTFIQJQKBNJ;
/*INC*/	if (!INC(EKGERQQLYYFESO, HXDKUNEBQGRIZK)) goto sentence_after_2;
	if (EKGERQQLYYFESO.container->type != text || *(EKGERQQLYYFESO.container->value.text + EKGERQQLYYFESO.index) != '2') goto sentence_after_2;
//// [ empty ] 
/*ISEMPTY*/	if (EKGERQQLYYFESO!=0 && HXDKUNEBQGRIZK != EKGERQQLYYFESO) goto sentence_after_2;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor EFRMTWKYLNONCH;
/*DEF*/	DataCursor IGMTFBOURZHMFF;
/*DEF*/	DataCursor FSRCBDZDFBEOST;
/*SET*/	EFRMTWKYLNONCH = TQBMMILPOXBIPW;
/*INC*/	if (!INC(EFRMTWKYLNONCH, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (EFRMTWKYLNONCH.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	IGMTFBOURZHMFF = EFRMTWKYLNONCH.container->value.bracket_data.chain->at_before_first();
	FSRCBDZDFBEOST   = EFRMTWKYLNONCH.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = IGMTFBOURZHMFF;
/*SET*/	r_1 = FSRCBDZDFBEOST;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor FVSKREBTLJHZKR;
/*DEF*/	DataCursor GHTSGBBDHLSICU;
/*DEF*/	DataCursor TFMMJOUTFVEXDC;
/*SET*/	FVSKREBTLJHZKR = EFRMTWKYLNONCH;
/*INC*/	if (!INC(FVSKREBTLJHZKR, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (FVSKREBTLJHZKR.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	GHTSGBBDHLSICU = FVSKREBTLJHZKR.container->value.bracket_data.chain->at_before_first();
	TFMMJOUTFVEXDC   = FVSKREBTLJHZKR.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = GHTSGBBDHLSICU;
/*SET*/	r_2 = TFMMJOUTFVEXDC;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor ZSCHYTBCRKLIWC;
/*DEF*/	DataCursor XKGOQVUFYOGVFR;
/*DEF*/	DataCursor NYMOPFWPNFUZEI;
/*SET*/	ZSCHYTBCRKLIWC = FVSKREBTLJHZKR;
/*INC*/	if (!INC(ZSCHYTBCRKLIWC, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (ZSCHYTBCRKLIWC.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	XKGOQVUFYOGVFR = ZSCHYTBCRKLIWC.container->value.bracket_data.chain->at_before_first();
	NYMOPFWPNFUZEI   = ZSCHYTBCRKLIWC.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_n1;
/*DEF*/	DataCursor r_n1;
/*SET*/	l_n1 = XKGOQVUFYOGVFR;
/*SET*/	r_n1 = XKGOQVUFYOGVFR;
/*JMP*/	goto label_HXYXANSPRGGWDY_firststep;
label_HXYXANSPRGGWDY: 
/*INC*/	if (!INC(r_n1, NYMOPFWPNFUZEI)) goto sentence_after_2;
label_HXYXANSPRGGWDY_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor AFAWQGQBTDGFFC;
/*SET*/	AFAWQGQBTDGFFC = r_n1;
 if (!SLIDE(AFAWQGQBTDGFFC, NYMOPFWPNFUZEI, l_A, r_A)) goto label_HXYXANSPRGGWDY;
//// [ e.1 ] 
/*DEF*/	DataCursor l_n2;
/*DEF*/	DataCursor r_n2;
/*SET*/	l_n2 = AFAWQGQBTDGFFC;
/*SET*/	r_n2 = NYMOPFWPNFUZEI;
//// [ empty ] 
/*ISEMPTY*/	if (ZSCHYTBCRKLIWC!=0 && arg_to != ZSCHYTBCRKLIWC) goto label_HXYXANSPRGGWDY;

// подготовка подстановки 
DataChain* EGTPCYBQVRQUSQ = new DataChain(); 
result->append(newRefExecBrackets(PolnAnaliz, EGTPCYBQVRQUSQ, "PolnAnaliz")); 
DataChain* SYDYMVPEIBGXFF = new DataChain(); 
EGTPCYBQVRQUSQ->append(newRefStructBrackets(SYDYMVPEIBGXFF)); 
SYDYMVPEIBGXFF->append(newRefText("1")); 
DataChain* NOPFYMRMQHUCGO = new DataChain(); 
EGTPCYBQVRQUSQ->append(newRefStructBrackets(NOPFYMRMQHUCGO)); 
NOPFYMRMQHUCGO->append_copy(l_1, r_1); 
DataChain* MDIUXEMXBZYSLV = new DataChain(); 
EGTPCYBQVRQUSQ->append(newRefStructBrackets(MDIUXEMXBZYSLV)); 
MDIUXEMXBZYSLV->append_copy(l_2, r_2); 
MDIUXEMXBZYSLV->append_copy(l_A, r_A); 
DataChain* LITWUBNSPBMEWW = new DataChain(); 
EGTPCYBQVRQUSQ->append(newRefStructBrackets(LITWUBNSPBMEWW)); 
LITWUBNSPBMEWW->append_copy(l_n1, r_n1); 
LITWUBNSPBMEWW->append_copy(l_n2, r_n2); 

return result; 
}
sentence_after_2: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* PolnAnalizEny(DataCursor arg_from, DataCursor arg_to){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor HGPMPRKCYFDXKM;
/*DEF*/	DataCursor TUHEVOIXRWLMXW;
/*DEF*/	DataCursor GCNOYZMMYOVRTE;
/*SET*/	HGPMPRKCYFDXKM = arg_from;
/*INC*/	if (!INC(HGPMPRKCYFDXKM, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (HGPMPRKCYFDXKM.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	TUHEVOIXRWLMXW = HGPMPRKCYFDXKM.container->value.bracket_data.chain->at_before_first();
	GCNOYZMMYOVRTE   = HGPMPRKCYFDXKM.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor PQTIBDVTHMPOAQ;
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = TUHEVOIXRWLMXW;
/*SET*/	PQTIBDVTHMPOAQ = TUHEVOIXRWLMXW;
/*INC*/	if (!INC(PQTIBDVTHMPOAQ, GCNOYZMMYOVRTE)) goto sentence_after_1;
	if (! isSymbolType(PQTIBDVTHMPOAQ.container->type)) goto sentence_after_1;
/*SET*/	r_s = PQTIBDVTHMPOAQ;
//// [ empty ] 
/*ISEMPTY*/	if (r_s!=0 && GCNOYZMMYOVRTE != r_s) goto sentence_after_1;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor YDDQRXNVKIYADV;
/*DEF*/	DataCursor LOYEMCYCFCPYUW;
/*DEF*/	DataCursor KZEBCJAEDSBVQQ;
/*SET*/	YDDQRXNVKIYADV = HGPMPRKCYFDXKM;
/*INC*/	if (!INC(YDDQRXNVKIYADV, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (YDDQRXNVKIYADV.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	LOYEMCYCFCPYUW = YDDQRXNVKIYADV.container->value.bracket_data.chain->at_before_first();
	KZEBCJAEDSBVQQ   = YDDQRXNVKIYADV.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = LOYEMCYCFCPYUW;
/*SET*/	r_1 = KZEBCJAEDSBVQQ;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor IJQLGJYCJPKPXF;
/*DEF*/	DataCursor LCEONIYVQVURDI;
/*DEF*/	DataCursor AQMSRTFGWTPEPU;
/*SET*/	IJQLGJYCJPKPXF = YDDQRXNVKIYADV;
/*INC*/	if (!INC(IJQLGJYCJPKPXF, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (IJQLGJYCJPKPXF.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	LCEONIYVQVURDI = IJQLGJYCJPKPXF.container->value.bracket_data.chain->at_before_first();
	AQMSRTFGWTPEPU   = IJQLGJYCJPKPXF.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = LCEONIYVQVURDI;
/*SET*/	r_2 = AQMSRTFGWTPEPU;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor NUGEAJDGZSJEWS;
/*DEF*/	DataCursor QRMJZSSBXJVOTJ;
/*DEF*/	DataCursor VJQCFQPTBZGKET;
/*SET*/	NUGEAJDGZSJEWS = IJQLGJYCJPKPXF;
/*INC*/	if (!INC(NUGEAJDGZSJEWS, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (NUGEAJDGZSJEWS.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	QRMJZSSBXJVOTJ = NUGEAJDGZSJEWS.container->value.bracket_data.chain->at_before_first();
	VJQCFQPTBZGKET   = NUGEAJDGZSJEWS.container->value.bracket_data.chain->at_last();
//// [ empty ] 
/*ISEMPTY*/	if (QRMJZSSBXJVOTJ!=0 && VJQCFQPTBZGKET != QRMJZSSBXJVOTJ) goto sentence_after_1;
//// [ empty ] 
/*ISEMPTY*/	if (NUGEAJDGZSJEWS!=0 && arg_to != NUGEAJDGZSJEWS) goto sentence_after_1;

// подготовка подстановки 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor QKITTRHYUBKEWF;
/*DEF*/	DataCursor EKRCIHHXJEIGUT;
/*DEF*/	DataCursor WIGDBBDXRBWMBR;
/*SET*/	QKITTRHYUBKEWF = arg_from;
/*INC*/	if (!INC(QKITTRHYUBKEWF, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (QKITTRHYUBKEWF.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	EKRCIHHXJEIGUT = QKITTRHYUBKEWF.container->value.bracket_data.chain->at_before_first();
	WIGDBBDXRBWMBR   = QKITTRHYUBKEWF.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor MBVGAOWLVDJYDD;
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = EKRCIHHXJEIGUT;
/*SET*/	MBVGAOWLVDJYDD = EKRCIHHXJEIGUT;
/*INC*/	if (!INC(MBVGAOWLVDJYDD, WIGDBBDXRBWMBR)) goto sentence_after_2;
	if (! isSymbolType(MBVGAOWLVDJYDD.container->type)) goto sentence_after_2;
/*SET*/	r_s = MBVGAOWLVDJYDD;
//// [ empty ] 
/*ISEMPTY*/	if (r_s!=0 && WIGDBBDXRBWMBR != r_s) goto sentence_after_2;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor YCTCOCKMGZVARP;
/*DEF*/	DataCursor FOBGMHPAOJOIQP;
/*DEF*/	DataCursor QTXTUCRORYSMGT;
/*SET*/	YCTCOCKMGZVARP = QKITTRHYUBKEWF;
/*INC*/	if (!INC(YCTCOCKMGZVARP, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (YCTCOCKMGZVARP.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	FOBGMHPAOJOIQP = YCTCOCKMGZVARP.container->value.bracket_data.chain->at_before_first();
	QTXTUCRORYSMGT   = YCTCOCKMGZVARP.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = FOBGMHPAOJOIQP;
/*SET*/	r_1 = QTXTUCRORYSMGT;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor XCFZLBJBIPFIMU;
/*DEF*/	DataCursor NEZPQAQJASIXVW;
/*DEF*/	DataCursor OQYJVXKHCQPQIA;
/*SET*/	XCFZLBJBIPFIMU = YCTCOCKMGZVARP;
/*INC*/	if (!INC(XCFZLBJBIPFIMU, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (XCFZLBJBIPFIMU.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	NEZPQAQJASIXVW = XCFZLBJBIPFIMU.container->value.bracket_data.chain->at_before_first();
	OQYJVXKHCQPQIA   = XCFZLBJBIPFIMU.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = NEZPQAQJASIXVW;
/*SET*/	r_2 = OQYJVXKHCQPQIA;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor BUBQQDOFEHHJTZ;
/*DEF*/	DataCursor YQKTDMKAPSPBMY;
/*DEF*/	DataCursor KOYLPNZOIPZWDM;
/*SET*/	BUBQQDOFEHHJTZ = XCFZLBJBIPFIMU;
/*INC*/	if (!INC(BUBQQDOFEHHJTZ, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (BUBQQDOFEHHJTZ.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	YQKTDMKAPSPBMY = BUBQQDOFEHHJTZ.container->value.bracket_data.chain->at_before_first();
	KOYLPNZOIPZWDM   = BUBQQDOFEHHJTZ.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = YQKTDMKAPSPBMY;
/*SET*/	r_3 = YQKTDMKAPSPBMY;
/*JMP*/	goto label_KRBHDNTDKVPDEL_firststep;
label_KRBHDNTDKVPDEL: 
/*INC*/	if (!INC(r_3, KOYLPNZOIPZWDM)) goto sentence_after_2;
label_KRBHDNTDKVPDEL_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor ORQCJKQZZPINOQ;
/*SET*/	ORQCJKQZZPINOQ = r_3;
/*INC*/	if (!INC(ORQCJKQZZPINOQ, KOYLPNZOIPZWDM)) goto label_KRBHDNTDKVPDEL;
	if (ORQCJKQZZPINOQ.container->type != text || *(ORQCJKQZZPINOQ.container->value.text + ORQCJKQZZPINOQ.index) != '>') goto label_KRBHDNTDKVPDEL;
//// [ empty ] 
/*ISEMPTY*/	if (ORQCJKQZZPINOQ!=0 && KOYLPNZOIPZWDM != ORQCJKQZZPINOQ) goto label_KRBHDNTDKVPDEL;
//// [ empty ] 
/*ISEMPTY*/	if (BUBQQDOFEHHJTZ!=0 && arg_to != BUBQQDOFEHHJTZ) goto label_KRBHDNTDKVPDEL;

// подготовка подстановки 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor OAMGMRCEMOAXVU;
/*DEF*/	DataCursor FYQYPCHHGFMIZR;
/*DEF*/	DataCursor CKLYHBPJJZRRUG;
/*SET*/	OAMGMRCEMOAXVU = arg_from;
/*INC*/	if (!INC(OAMGMRCEMOAXVU, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (OAMGMRCEMOAXVU.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	FYQYPCHHGFMIZR = OAMGMRCEMOAXVU.container->value.bracket_data.chain->at_before_first();
	CKLYHBPJJZRRUG   = OAMGMRCEMOAXVU.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor OFLUIOIVOVXMRA;
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = FYQYPCHHGFMIZR;
/*SET*/	OFLUIOIVOVXMRA = FYQYPCHHGFMIZR;
/*INC*/	if (!INC(OFLUIOIVOVXMRA, CKLYHBPJJZRRUG)) goto sentence_after_3;
	if (! isSymbolType(OFLUIOIVOVXMRA.container->type)) goto sentence_after_3;
/*SET*/	r_s = OFLUIOIVOVXMRA;
//// [ empty ] 
/*ISEMPTY*/	if (r_s!=0 && CKLYHBPJJZRRUG != r_s) goto sentence_after_3;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor WZSWPFNCNFYTMC;
/*DEF*/	DataCursor FVWNRMFZGPZPOL;
/*DEF*/	DataCursor TVNBMVWTHJSVHB;
/*SET*/	WZSWPFNCNFYTMC = OAMGMRCEMOAXVU;
/*INC*/	if (!INC(WZSWPFNCNFYTMC, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (WZSWPFNCNFYTMC.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	FVWNRMFZGPZPOL = WZSWPFNCNFYTMC.container->value.bracket_data.chain->at_before_first();
	TVNBMVWTHJSVHB   = WZSWPFNCNFYTMC.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_I;
/*DEF*/	DataCursor r_I;
/*SET*/	l_I = FVWNRMFZGPZPOL;
/*SET*/	r_I = TVNBMVWTHJSVHB;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor XSEWQYCKWEXZPM;
/*DEF*/	DataCursor IEXGRJXJMDWBQY;
/*DEF*/	DataCursor UIPXARRBPHNZWK;
/*SET*/	XSEWQYCKWEXZPM = WZSWPFNCNFYTMC;
/*INC*/	if (!INC(XSEWQYCKWEXZPM, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (XSEWQYCKWEXZPM.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	IEXGRJXJMDWBQY = XSEWQYCKWEXZPM.container->value.bracket_data.chain->at_before_first();
	UIPXARRBPHNZWK   = XSEWQYCKWEXZPM.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_Y;
/*DEF*/	DataCursor r_Y;
/*SET*/	l_Y = IEXGRJXJMDWBQY;
/*SET*/	r_Y = UIPXARRBPHNZWK;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor BCLGBVOCYUZUTZ;
/*DEF*/	DataCursor YPIROCYYUCCLQZ;
/*DEF*/	DataCursor CXTAWHXKHALPUK;
/*SET*/	BCLGBVOCYUZUTZ = XSEWQYCKWEXZPM;
/*INC*/	if (!INC(BCLGBVOCYUZUTZ, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (BCLGBVOCYUZUTZ.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	YPIROCYYUCCLQZ = BCLGBVOCYUZUTZ.container->value.bracket_data.chain->at_before_first();
	CXTAWHXKHALPUK   = BCLGBVOCYUZUTZ.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = YPIROCYYUCCLQZ;
/*SET*/	r_1 = YPIROCYYUCCLQZ;
/*JMP*/	goto label_JRMGSXOCKDRAAU_firststep;
label_JRMGSXOCKDRAAU: 
/*INC*/	if (!INC(r_1, CXTAWHXKHALPUK)) goto sentence_after_3;
label_JRMGSXOCKDRAAU_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor ACXKPMRFLSPDLQ;
/*SET*/	ACXKPMRFLSPDLQ = r_1;
/*INC*/	if (!INC(ACXKPMRFLSPDLQ, CXTAWHXKHALPUK)) goto label_JRMGSXOCKDRAAU;
	if (ACXKPMRFLSPDLQ.container->type != text || *(ACXKPMRFLSPDLQ.container->value.text + ACXKPMRFLSPDLQ.index) != '>') goto label_JRMGSXOCKDRAAU;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor KEWYQJFTFWAHGQ;
/*DEF*/	DataCursor l_sss;
/*DEF*/	DataCursor r_sss;
/*SET*/	l_sss = ACXKPMRFLSPDLQ;
/*SET*/	KEWYQJFTFWAHGQ = ACXKPMRFLSPDLQ;
/*INC*/	if (!INC(KEWYQJFTFWAHGQ, CXTAWHXKHALPUK)) goto label_JRMGSXOCKDRAAU;
	if (! isSymbolType(KEWYQJFTFWAHGQ.container->type)) goto label_JRMGSXOCKDRAAU;
/*SET*/	r_sss = KEWYQJFTFWAHGQ;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = r_sss;
/*SET*/	r_2 = CXTAWHXKHALPUK;
//// [ empty ] 
/*ISEMPTY*/	if (BCLGBVOCYUZUTZ!=0 && arg_to != BCLGBVOCYUZUTZ) goto label_JRMGSXOCKDRAAU;

// подготовка подстановки 
DataChain* DSGEUEIVKRNEZU = new DataChain(); 
result->append(newRefExecBrackets(Analiz, DSGEUEIVKRNEZU, "Analiz")); 
DataChain* MCIRZFQXOZFCUH = new DataChain(); 
DSGEUEIVKRNEZU->append(newRefStructBrackets(MCIRZFQXOZFCUH)); 
MCIRZFQXOZFCUH->append_copy(l_s, r_s); 
DataChain* CNSCQKCJBCHVRS = new DataChain(); 
DSGEUEIVKRNEZU->append(newRefStructBrackets(CNSCQKCJBCHVRS)); 
CNSCQKCJBCHVRS->append_copy(l_I, r_I); 
DataChain* PZOTKDBIDWWYGO = new DataChain(); 
DSGEUEIVKRNEZU->append(newRefStructBrackets(PZOTKDBIDWWYGO)); 
PZOTKDBIDWWYGO->append_copy(l_Y, r_Y); 
DataChain* WWQHNZFJQHFGIM = new DataChain(); 
DSGEUEIVKRNEZU->append(newRefStructBrackets(WWQHNZFJQHFGIM)); 
WWQHNZFJQHFGIM->append_copy(l_1, r_1); 
WWQHNZFJQHFGIM->append(newRefText(">")); 
WWQHNZFJQHFGIM->append_copy(l_sss, r_sss); 
WWQHNZFJQHFGIM->append_copy(l_2, r_2); 
DataChain* WJGRJVQSPOOSLA = new DataChain(); 
result->append(newRefExecBrackets(PolnAnaliz, WJGRJVQSPOOSLA, "PolnAnaliz")); 
DataChain* QKXZEHZEGKWUTI = new DataChain(); 
WJGRJVQSPOOSLA->append(newRefStructBrackets(QKXZEHZEGKWUTI)); 
QKXZEHZEGKWUTI->append_copy(l_s, r_s); 
DataChain* YPZVVZTDURGODX = new DataChain(); 
WJGRJVQSPOOSLA->append(newRefStructBrackets(YPZVVZTDURGODX)); 
YPZVVZTDURGODX->append_copy(l_I, r_I); 
DataChain* VAAHGUIGPSGLHA = new DataChain(); 
WJGRJVQSPOOSLA->append(newRefStructBrackets(VAAHGUIGPSGLHA)); 
VAAHGUIGPSGLHA->append_copy(l_Y, r_Y); 
DataChain* BNQBWTQMBDSMBF = new DataChain(); 
WJGRJVQSPOOSLA->append(newRefStructBrackets(BNQBWTQMBDSMBF)); 
BNQBWTQMBDSMBF->append_copy(l_1, r_1); 
BNQBWTQMBDSMBF->append_copy(l_sss, r_sss); 
BNQBWTQMBDSMBF->append(newRefText(">")); 
BNQBWTQMBDSMBF->append_copy(l_2, r_2); 

return result; 
}
sentence_after_3: 

{
// подготовка предложения 
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_sIY;
/*DEF*/	DataCursor r_sIY;
/*SET*/	l_sIY = arg_from;
/*SET*/	r_sIY = arg_from;
/*JMP*/	goto label_ZTHYUMQUOWLDNO_firststep;
label_ZTHYUMQUOWLDNO: 
/*INC*/	if (!INC(r_sIY, arg_to)) goto sentence_after_4;
label_ZTHYUMQUOWLDNO_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor VUCOIMMQSZMSRZ;
/*DEF*/	DataCursor QPMADDCVHINJJD;
/*DEF*/	DataCursor FYWRWSDAGMVYQH;
/*SET*/	VUCOIMMQSZMSRZ = r_sIY;
/*INC*/	if (!INC(VUCOIMMQSZMSRZ, arg_to)) goto label_ZTHYUMQUOWLDNO;
//// ISBRACKET 
	if (VUCOIMMQSZMSRZ.container->type != struct_bracket) goto label_ZTHYUMQUOWLDNO;
//// JMP_BRACKET 
	QPMADDCVHINJJD = VUCOIMMQSZMSRZ.container->value.bracket_data.chain->at_before_first();
	FYWRWSDAGMVYQH   = VUCOIMMQSZMSRZ.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = QPMADDCVHINJJD;
/*SET*/	r_1 = FYWRWSDAGMVYQH;
//// [ empty ] 
/*ISEMPTY*/	if (VUCOIMMQSZMSRZ!=0 && arg_to != VUCOIMMQSZMSRZ) goto label_ZTHYUMQUOWLDNO;

// подготовка подстановки 
DataChain* TQWFYIAISTVHBZ = new DataChain(); 
result->append(newRefExecBrackets(PolnAnaliz, TQWFYIAISTVHBZ, "PolnAnaliz")); 
TQWFYIAISTVHBZ->append_copy(l_sIY, r_sIY); 
DataChain* VROOVJFTEGSKJR = new DataChain(); 
TQWFYIAISTVHBZ->append(newRefStructBrackets(VROOVJFTEGSKJR)); 
VROOVJFTEGSKJR->append(newRefText(">")); 
VROOVJFTEGSKJR->append_copy(l_1, r_1); 

return result; 
}
sentence_after_4: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

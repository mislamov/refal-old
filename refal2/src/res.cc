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
//// [ empty ] 
/*ISEMPTY*/	if (arg_from!=0 && arg_to != arg_from) goto sentence_after_1;

// подготовка подстановки 
DataChain* DXFIRCVSCXGGBW = new DataChain(); 
result->append(newRefExecBrackets(Prout, DXFIRCVSCXGGBW, "Prout")); 
DXFIRCVSCXGGBW->append(newRefText("Who is first? (1 - pc  2 - you)")); 
DataChain* KFNQDUXWFNFOZV = new DataChain(); 
result->append(newRefExecBrackets(FirG, KFNQDUXWFNFOZV, "FirG")); 
DataChain* SRTKJPREPGGXRP = new DataChain(); 
KFNQDUXWFNFOZV->append(newRefExecBrackets(Card, SRTKJPREPGGXRP, "Card")); 

return result; 
}
sentence_after_1: 

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
/*DEF*/	DataCursor NRVYSTMWCYSYYC;
/*SET*/	NRVYSTMWCYSYYC = arg_from;
/*INC*/	if (!INC(NRVYSTMWCYSYYC, arg_to)) goto sentence_after_1;
	if (NRVYSTMWCYSYYC.container->type != text || *(NRVYSTMWCYSYYC.container->value.text + NRVYSTMWCYSYYC.index) != '1') goto sentence_after_1;
//// [ empty ] 
/*ISEMPTY*/	if (NRVYSTMWCYSYYC!=0 && arg_to != NRVYSTMWCYSYYC) goto sentence_after_1;

// подготовка подстановки 
DataChain* KKASVWSRENZKYC = new DataChain(); 
result->append(newRefExecBrackets(Game, KKASVWSRENZKYC, "Game")); 
DataChain* XFXTLSGYPSFADP = new DataChain(); 
KKASVWSRENZKYC->append(newRefStructBrackets(XFXTLSGYPSFADP)); 
XFXTLSGYPSFADP->append(newRefText("2")); 
DataChain* OOEFXZBCOEJUVP = new DataChain(); 
KKASVWSRENZKYC->append(newRefStructBrackets(OOEFXZBCOEJUVP)); 
OOEFXZBCOEJUVP->append(newRefText("1")); 
DataChain* VABOYGPOEYLFPB = new DataChain(); 
KKASVWSRENZKYC->append(newRefStructBrackets(VABOYGPOEYLFPB)); 
VABOYGPOEYLFPB->append(newRefText("")); 
DataChain* NPLJVRVIPYAMYE = new DataChain(); 
KKASVWSRENZKYC->append(newRefStructBrackets(NPLJVRVIPYAMYE)); 
NPLJVRVIPYAMYE->append(newRefText("23456789")); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor HWQNQRQPMXUJJL;
/*SET*/	HWQNQRQPMXUJJL = arg_from;
/*INC*/	if (!INC(HWQNQRQPMXUJJL, arg_to)) goto sentence_after_2;
	if (HWQNQRQPMXUJJL.container->type != text || *(HWQNQRQPMXUJJL.container->value.text + HWQNQRQPMXUJJL.index) != '2') goto sentence_after_2;
//// [ empty ] 
/*ISEMPTY*/	if (HWQNQRQPMXUJJL!=0 && arg_to != HWQNQRQPMXUJJL) goto sentence_after_2;

// подготовка подстановки 
DataChain* BXCOKSFZKVATXD = new DataChain(); 
result->append(newRefExecBrackets(Game, BXCOKSFZKVATXD, "Game")); 
DataChain* KNLYJYHFIXJSWN = new DataChain(); 
BXCOKSFZKVATXD->append(newRefStructBrackets(KNLYJYHFIXJSWN)); 
KNLYJYHFIXJSWN->append(newRefText("2")); 
DataChain* KKUFNUXXZRZBMN = new DataChain(); 
BXCOKSFZKVATXD->append(newRefStructBrackets(KKUFNUXXZRZBMN)); 
KKUFNUXXZRZBMN->append(newRefText("")); 
DataChain* MGQOOKETLYHNKO = new DataChain(); 
BXCOKSFZKVATXD->append(newRefStructBrackets(MGQOOKETLYHNKO)); 
MGQOOKETLYHNKO->append(newRefText("")); 
DataChain* AUGZQRCDDIUTEI = new DataChain(); 
BXCOKSFZKVATXD->append(newRefStructBrackets(AUGZQRCDDIUTEI)); 
AUGZQRCDDIUTEI->append(newRefText("123456789")); 

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
DataChain* OJWAYYZPVSCMPS = new DataChain(); 
result->append(newRefExecBrackets(Prout, OJWAYYZPVSCMPS, "Prout")); 
OJWAYYZPVSCMPS->append(newRefWord("Game:")); 
OJWAYYZPVSCMPS->append_copy(l_e, r_e); 
DataChain* AJLFVGUBFAAOVL = new DataChain(); 
result->append(newRefExecBrackets(Game__, AJLFVGUBFAAOVL, "Game__")); 
AJLFVGUBFAAOVL->append_copy(l_e, r_e); 

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
/*DEF*/	DataCursor ZYLNTRKDCPWSRT;
/*DEF*/	DataCursor ESJWHDIZCOBZCN;
/*DEF*/	DataCursor FWLQIJTVDWVXHR;
/*SET*/	ZYLNTRKDCPWSRT = arg_from;
/*INC*/	if (!INC(ZYLNTRKDCPWSRT, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (ZYLNTRKDCPWSRT.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	ESJWHDIZCOBZCN = ZYLNTRKDCPWSRT.container->value.bracket_data.chain->at_before_first();
	FWLQIJTVDWVXHR   = ZYLNTRKDCPWSRT.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor CBLDVGYLWGBUSB;
/*DEF*/	DataCursor l_g;
/*DEF*/	DataCursor r_g;
/*SET*/	l_g = ESJWHDIZCOBZCN;
/*SET*/	CBLDVGYLWGBUSB = ESJWHDIZCOBZCN;
/*INC*/	if (!INC(CBLDVGYLWGBUSB, FWLQIJTVDWVXHR)) goto sentence_after_1;
	if (! isSymbolType(CBLDVGYLWGBUSB.container->type)) goto sentence_after_1;
/*SET*/	r_g = CBLDVGYLWGBUSB;
//// [ empty ] 
/*ISEMPTY*/	if (r_g!=0 && FWLQIJTVDWVXHR != r_g) goto sentence_after_1;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor MBORXTLHCSMPXO;
/*DEF*/	DataCursor HGMGNKEUFDXOTO;
/*DEF*/	DataCursor GBGXPEYANFETCU;
/*SET*/	MBORXTLHCSMPXO = ZYLNTRKDCPWSRT;
/*INC*/	if (!INC(MBORXTLHCSMPXO, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (MBORXTLHCSMPXO.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	HGMGNKEUFDXOTO = MBORXTLHCSMPXO.container->value.bracket_data.chain->at_before_first();
	GBGXPEYANFETCU   = MBORXTLHCSMPXO.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = HGMGNKEUFDXOTO;
/*SET*/	r_1 = GBGXPEYANFETCU;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor KEPZSHKLJUGGGE;
/*DEF*/	DataCursor KJDQZJENPEVQGX;
/*DEF*/	DataCursor IEPJSRDZJAZUJL;
/*SET*/	KEPZSHKLJUGGGE = MBORXTLHCSMPXO;
/*INC*/	if (!INC(KEPZSHKLJUGGGE, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (KEPZSHKLJUGGGE.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	KJDQZJENPEVQGX = KEPZSHKLJUGGGE.container->value.bracket_data.chain->at_before_first();
	IEPJSRDZJAZUJL   = KEPZSHKLJUGGGE.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = KJDQZJENPEVQGX;
/*SET*/	r_2 = IEPJSRDZJAZUJL;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor LCHHBFQMKIMWZO;
/*DEF*/	DataCursor BIWYBXDUUNFSKS;
/*DEF*/	DataCursor RSRTEKMQDCYZJE;
/*SET*/	LCHHBFQMKIMWZO = KEPZSHKLJUGGGE;
/*INC*/	if (!INC(LCHHBFQMKIMWZO, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (LCHHBFQMKIMWZO.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	BIWYBXDUUNFSKS = LCHHBFQMKIMWZO.container->value.bracket_data.chain->at_before_first();
	RSRTEKMQDCYZJE   = LCHHBFQMKIMWZO.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = BIWYBXDUUNFSKS;
/*SET*/	r_n = RSRTEKMQDCYZJE;
//// [ empty ] 
/*ISEMPTY*/	if (LCHHBFQMKIMWZO!=0 && arg_to != LCHHBFQMKIMWZO) goto sentence_after_1;

// подготовка подстановки 
DataChain* EUHMSRQCOZIJIP = new DataChain(); 
result->append(newRefExecBrackets(Ekran, EUHMSRQCOZIJIP, "Ekran")); 
DataChain* FIONEEDDPSZRNA = new DataChain(); 
EUHMSRQCOZIJIP->append(newRefStructBrackets(FIONEEDDPSZRNA)); 
FIONEEDDPSZRNA->append_copy(l_1, r_1); 
DataChain* VYMMTATBDZQSOE = new DataChain(); 
EUHMSRQCOZIJIP->append(newRefStructBrackets(VYMMTATBDZQSOE)); 
VYMMTATBDZQSOE->append_copy(l_2, r_2); 
DataChain* MUVNPPPSUACBAZ = new DataChain(); 
result->append(newRefExecBrackets(GameIfWin, MUVNPPPSUACBAZ, "GameIfWin")); 
DataChain* UXMHECTHLEGRPU = new DataChain(); 
MUVNPPPSUACBAZ->append(newRefExecBrackets(Ifwin, UXMHECTHLEGRPU, "Ifwin")); 
DataChain* NKDMBPPWEQTGJO = new DataChain(); 
UXMHECTHLEGRPU->append(newRefStructBrackets(NKDMBPPWEQTGJO)); 
NKDMBPPWEQTGJO->append_copy(l_1, r_1); 
DataChain* PARMOWZDQYOXYT = new DataChain(); 
UXMHECTHLEGRPU->append(newRefStructBrackets(PARMOWZDQYOXYT)); 
PARMOWZDQYOXYT->append_copy(l_2, r_2); 
DataChain* JBBHAWDYDCPRJB = new DataChain(); 
MUVNPPPSUACBAZ->append(newRefStructBrackets(JBBHAWDYDCPRJB)); 
JBBHAWDYDCPRJB->append_copy(l_g, r_g); 
DataChain* XPHOOHPKWQYUHR = new DataChain(); 
MUVNPPPSUACBAZ->append(newRefStructBrackets(XPHOOHPKWQYUHR)); 
XPHOOHPKWQYUHR->append_copy(l_1, r_1); 
DataChain* QZHNBNFUVQNQQL = new DataChain(); 
MUVNPPPSUACBAZ->append(newRefStructBrackets(QZHNBNFUVQNQQL)); 
QZHNBNFUVQNQQL->append_copy(l_2, r_2); 
DataChain* RZJPXIOGVLIEXD = new DataChain(); 
MUVNPPPSUACBAZ->append(newRefStructBrackets(RZJPXIOGVLIEXD)); 
RZJPXIOGVLIEXD->append_copy(l_n, r_n); 

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
/*DEF*/	DataCursor ZUZOSRKRUSVOJB;
/*SET*/	ZUZOSRKRUSVOJB = arg_from;
/*INC*/	if (!INC(ZUZOSRKRUSVOJB, arg_to)) goto sentence_after_1;
	if (ZUZOSRKRUSVOJB.container->type != text || *(ZUZOSRKRUSVOJB.container->value.text + ZUZOSRKRUSVOJB.index) != '0') goto sentence_after_1;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = ZUZOSRKRUSVOJB;
/*SET*/	r_e = ZUZOSRKRUSVOJB;
/*JMP*/	goto label_RZMWZPOWKJILEF_firststep;
label_RZMWZPOWKJILEF: 
/*INC*/	if (!INC(r_e, arg_to)) goto sentence_after_1;
label_RZMWZPOWKJILEF_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor RAAMDIGPNPUUHG;
/*DEF*/	DataCursor XPQNJWJMWAXXMN;
/*DEF*/	DataCursor SNHHLQQRZUDLTF;
/*SET*/	RAAMDIGPNPUUHG = r_e;
/*INC*/	if (!INC(RAAMDIGPNPUUHG, arg_to)) goto label_RZMWZPOWKJILEF;
//// ISBRACKET 
	if (RAAMDIGPNPUUHG.container->type != struct_bracket) goto label_RZMWZPOWKJILEF;
//// JMP_BRACKET 
	XPQNJWJMWAXXMN = RAAMDIGPNPUUHG.container->value.bracket_data.chain->at_before_first();
	SNHHLQQRZUDLTF   = RAAMDIGPNPUUHG.container->value.bracket_data.chain->at_last();
//// [ empty ] 
/*ISEMPTY*/	if (XPQNJWJMWAXXMN!=0 && SNHHLQQRZUDLTF != XPQNJWJMWAXXMN) goto label_RZMWZPOWKJILEF;
//// [ empty ] 
/*ISEMPTY*/	if (RAAMDIGPNPUUHG!=0 && arg_to != RAAMDIGPNPUUHG) goto label_RZMWZPOWKJILEF;

// подготовка подстановки 
DataChain* SMZCNOCKVFAJFR = new DataChain(); 
result->append(newRefExecBrackets(Prout, SMZCNOCKVFAJFR, "Prout")); 
SMZCNOCKVFAJFR->append(newRefText("Nobody !!!.")); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor MXOTHOWKBJZWUC;
/*SET*/	MXOTHOWKBJZWUC = arg_from;
/*INC*/	if (!INC(MXOTHOWKBJZWUC, arg_to)) goto sentence_after_2;
	if (MXOTHOWKBJZWUC.container->type != text || *(MXOTHOWKBJZWUC.container->value.text + MXOTHOWKBJZWUC.index) != '1') goto sentence_after_2;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = MXOTHOWKBJZWUC;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* RIWKBARXBGFCBC = new DataChain(); 
result->append(newRefExecBrackets(Prout, RIWKBARXBGFCBC, "Prout")); 
RIWKBARXBGFCBC->append(newRefText("Winner X")); 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor EYHJUGIXWTBVTR;
/*SET*/	EYHJUGIXWTBVTR = arg_from;
/*INC*/	if (!INC(EYHJUGIXWTBVTR, arg_to)) goto sentence_after_3;
	if (EYHJUGIXWTBVTR.container->type != text || *(EYHJUGIXWTBVTR.container->value.text + EYHJUGIXWTBVTR.index) != '2') goto sentence_after_3;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = EYHJUGIXWTBVTR;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* CGKCFQCKCOTZGK = new DataChain(); 
result->append(newRefExecBrackets(Prout, CGKCFQCKCOTZGK, "Prout")); 
CGKCFQCKCOTZGK->append(newRefText("Winner O")); 

return result; 
}
sentence_after_3: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor UBMJRMBSZTSSHF;
/*SET*/	UBMJRMBSZTSSHF = arg_from;
/*INC*/	if (!INC(UBMJRMBSZTSSHF, arg_to)) goto sentence_after_4;
	if (UBMJRMBSZTSSHF.container->type != text || *(UBMJRMBSZTSSHF.container->value.text + UBMJRMBSZTSSHF.index) != '0') goto sentence_after_4;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = UBMJRMBSZTSSHF;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* YUPZWWEIQURPIX = new DataChain(); 
result->append(newRefExecBrackets(Game1, YUPZWWEIQURPIX, "Game1")); 
YUPZWWEIQURPIX->append_copy(l_e, r_e); 

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
DataChain* IQFLDUUVEOOWQC = new DataChain(); 
result->append(newRefExecBrackets(Prout, IQFLDUUVEOOWQC, "Prout")); 
IQFLDUUVEOOWQC->append(newRefWord("Game1:")); 
IQFLDUUVEOOWQC->append_copy(l_e, r_e); 
DataChain* UDHNEFNJHAIMUC = new DataChain(); 
result->append(newRefExecBrackets(Game1__, UDHNEFNJHAIMUC, "Game1__")); 
UDHNEFNJHAIMUC->append_copy(l_e, r_e); 

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
/*DEF*/	DataCursor ZFSKUIDUBURISW;
/*DEF*/	DataCursor TBRECUYKABFCVK;
/*DEF*/	DataCursor DZEZTOIDUKUHJZ;
/*SET*/	ZFSKUIDUBURISW = arg_from;
/*INC*/	if (!INC(ZFSKUIDUBURISW, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (ZFSKUIDUBURISW.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	TBRECUYKABFCVK = ZFSKUIDUBURISW.container->value.bracket_data.chain->at_before_first();
	DZEZTOIDUKUHJZ   = ZFSKUIDUBURISW.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor EFCZZZBFKQDPQZ;
/*SET*/	EFCZZZBFKQDPQZ = TBRECUYKABFCVK;
/*INC*/	if (!INC(EFCZZZBFKQDPQZ, DZEZTOIDUKUHJZ)) goto sentence_after_1;
	if (EFCZZZBFKQDPQZ.container->type != text || *(EFCZZZBFKQDPQZ.container->value.text + EFCZZZBFKQDPQZ.index) != '1') goto sentence_after_1;
//// [ empty ] 
/*ISEMPTY*/	if (EFCZZZBFKQDPQZ!=0 && DZEZTOIDUKUHJZ != EFCZZZBFKQDPQZ) goto sentence_after_1;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_12;
/*DEF*/	DataCursor r_12;
/*SET*/	l_12 = ZFSKUIDUBURISW;
/*SET*/	r_12 = ZFSKUIDUBURISW;
/*JMP*/	goto label_GKJELRLPAXAMCE_firststep;
label_GKJELRLPAXAMCE: 
/*INC*/	if (!INC(r_12, arg_to)) goto sentence_after_1;
label_GKJELRLPAXAMCE_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor ROSWITDPTPCCLI;
/*DEF*/	DataCursor FKELJYTIHRCQAY;
/*DEF*/	DataCursor BNEFXNXVGZEDYY;
/*SET*/	ROSWITDPTPCCLI = r_12;
/*INC*/	if (!INC(ROSWITDPTPCCLI, arg_to)) goto label_GKJELRLPAXAMCE;
//// ISBRACKET 
	if (ROSWITDPTPCCLI.container->type != struct_bracket) goto label_GKJELRLPAXAMCE;
//// JMP_BRACKET 
	FKELJYTIHRCQAY = ROSWITDPTPCCLI.container->value.bracket_data.chain->at_before_first();
	BNEFXNXVGZEDYY   = ROSWITDPTPCCLI.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = FKELJYTIHRCQAY;
/*SET*/	r_n = BNEFXNXVGZEDYY;
//// [ empty ] 
/*ISEMPTY*/	if (ROSWITDPTPCCLI!=0 && arg_to != ROSWITDPTPCCLI) goto label_GKJELRLPAXAMCE;

// подготовка подстановки 
DataChain* HNGYCDRUDMPHME = new DataChain(); 
result->append(newRefExecBrackets(Prout, HNGYCDRUDMPHME, "Prout")); 
HNGYCDRUDMPHME->append(newRefText("hmm ...")); 
DataChain* CKOTRWOSPOFGHF = new DataChain(); 
result->append(newRefExecBrackets(Game, CKOTRWOSPOFGHF, "Game")); 
DataChain* OZQVLQFXWWKMFX = new DataChain(); 
CKOTRWOSPOFGHF->append(newRefStructBrackets(OZQVLQFXWWKMFX)); 
OZQVLQFXWWKMFX->append(newRefText("2")); 
DataChain* DYYGMDCASZSGOV = new DataChain(); 
CKOTRWOSPOFGHF->append(newRefExecBrackets(PlayerHod, DYYGMDCASZSGOV, "PlayerHod")); 
DYYGMDCASZSGOV->append(newRefText("1")); 
DataChain* SODKJGHCWMBMXR = new DataChain(); 
DYYGMDCASZSGOV->append(newRefExecBrackets(GetHod, SODKJGHCWMBMXR, "GetHod")); 
SODKJGHCWMBMXR->append(newRefText("1")); 
DataChain* MHUYFYQGAJQKCK = new DataChain(); 
SODKJGHCWMBMXR->append(newRefStructBrackets(MHUYFYQGAJQKCK)); 
MHUYFYQGAJQKCK->append(newRefText("1")); 
SODKJGHCWMBMXR->append_copy(l_12, r_12); 
DataChain* LZNAYXQKQOYZWM = new DataChain(); 
SODKJGHCWMBMXR->append(newRefStructBrackets(LZNAYXQKQOYZWM)); 
LZNAYXQKQOYZWM->append_copy(l_n, r_n); 
DYYGMDCASZSGOV->append_copy(l_12, r_12); 
DataChain* YUBZAZCPKHKTKY = new DataChain(); 
DYYGMDCASZSGOV->append(newRefStructBrackets(YUBZAZCPKHKTKY)); 
YUBZAZCPKHKTKY->append_copy(l_n, r_n); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor DZIVCUYPURFMBI;
/*DEF*/	DataCursor SGEKYRGZVXDHPO;
/*DEF*/	DataCursor AMVAFYRARXSVKH;
/*SET*/	DZIVCUYPURFMBI = arg_from;
/*INC*/	if (!INC(DZIVCUYPURFMBI, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (DZIVCUYPURFMBI.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	SGEKYRGZVXDHPO = DZIVCUYPURFMBI.container->value.bracket_data.chain->at_before_first();
	AMVAFYRARXSVKH   = DZIVCUYPURFMBI.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor TQDIHERSIGBHZJ;
/*SET*/	TQDIHERSIGBHZJ = SGEKYRGZVXDHPO;
/*INC*/	if (!INC(TQDIHERSIGBHZJ, AMVAFYRARXSVKH)) goto sentence_after_2;
	if (TQDIHERSIGBHZJ.container->type != text || *(TQDIHERSIGBHZJ.container->value.text + TQDIHERSIGBHZJ.index) != '2') goto sentence_after_2;
//// [ empty ] 
/*ISEMPTY*/	if (TQDIHERSIGBHZJ!=0 && AMVAFYRARXSVKH != TQDIHERSIGBHZJ) goto sentence_after_2;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_12;
/*DEF*/	DataCursor r_12;
/*SET*/	l_12 = DZIVCUYPURFMBI;
/*SET*/	r_12 = DZIVCUYPURFMBI;
/*JMP*/	goto label_WKEGJCCVHHRJVB_firststep;
label_WKEGJCCVHHRJVB: 
/*INC*/	if (!INC(r_12, arg_to)) goto sentence_after_2;
label_WKEGJCCVHHRJVB_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor JTSQDJOOTGPKNF;
/*DEF*/	DataCursor PFYCGFIEOWQRWW;
/*DEF*/	DataCursor WPZSQMETOGEPSP;
/*SET*/	JTSQDJOOTGPKNF = r_12;
/*INC*/	if (!INC(JTSQDJOOTGPKNF, arg_to)) goto label_WKEGJCCVHHRJVB;
//// ISBRACKET 
	if (JTSQDJOOTGPKNF.container->type != struct_bracket) goto label_WKEGJCCVHHRJVB;
//// JMP_BRACKET 
	PFYCGFIEOWQRWW = JTSQDJOOTGPKNF.container->value.bracket_data.chain->at_before_first();
	WPZSQMETOGEPSP   = JTSQDJOOTGPKNF.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = PFYCGFIEOWQRWW;
/*SET*/	r_n = WPZSQMETOGEPSP;
//// [ empty ] 
/*ISEMPTY*/	if (JTSQDJOOTGPKNF!=0 && arg_to != JTSQDJOOTGPKNF) goto label_WKEGJCCVHHRJVB;

// подготовка подстановки 
DataChain* XNVJIUPALYYNMK = new DataChain(); 
result->append(newRefExecBrackets(Game, XNVJIUPALYYNMK, "Game")); 
DataChain* MNUVKLHSECDWRA = new DataChain(); 
XNVJIUPALYYNMK->append(newRefStructBrackets(MNUVKLHSECDWRA)); 
MNUVKLHSECDWRA->append(newRefText("1")); 
DataChain* CGFMZKGIPDFODK = new DataChain(); 
XNVJIUPALYYNMK->append(newRefExecBrackets(PlayerHod, CGFMZKGIPDFODK, "PlayerHod")); 
CGFMZKGIPDFODK->append(newRefText("2")); 
DataChain* JMJQWIQPUOQHIM = new DataChain(); 
CGFMZKGIPDFODK->append(newRefExecBrackets(Prout, JMJQWIQPUOQHIM, "Prout")); 
JMJQWIQPUOQHIM->append(newRefText("Select number for 0:")); 
DataChain* VFVUZWYVIJGFUL = new DataChain(); 
CGFMZKGIPDFODK->append(newRefExecBrackets(Card, VFVUZWYVIJGFUL, "Card")); 
CGFMZKGIPDFODK->append_copy(l_12, r_12); 
DataChain* LKJDUHSJAFBTLK = new DataChain(); 
CGFMZKGIPDFODK->append(newRefStructBrackets(LKJDUHSJAFBTLK)); 
LKJDUHSJAFBTLK->append_copy(l_n, r_n); 

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
DataChain* MFQRMYJFJNHHSS = new DataChain(); 
result->append(newRefExecBrackets(Prout, MFQRMYJFJNHHSS, "Prout")); 
MFQRMYJFJNHHSS->append(newRefWord("PlayerHod:")); 
MFQRMYJFJNHHSS->append_copy(l_e, r_e); 
DataChain* QCTYDTEAMDCJBP = new DataChain(); 
result->append(newRefExecBrackets(PlayerHod__, QCTYDTEAMDCJBP, "PlayerHod__")); 
QCTYDTEAMDCJBP->append_copy(l_e, r_e); 

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
/*DEF*/	DataCursor RHTNEGYIWXGCJW;
/*SET*/	RHTNEGYIWXGCJW = arg_from;
/*INC*/	if (!INC(RHTNEGYIWXGCJW, arg_to)) goto sentence_after_1;
	if (RHTNEGYIWXGCJW.container->type != text || *(RHTNEGYIWXGCJW.container->value.text + RHTNEGYIWXGCJW.index) != '1') goto sentence_after_1;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor LGRSMEAEARWTVJ;
/*DEF*/	DataCursor l_h;
/*DEF*/	DataCursor r_h;
/*SET*/	l_h = RHTNEGYIWXGCJW;
/*SET*/	LGRSMEAEARWTVJ = RHTNEGYIWXGCJW;
/*INC*/	if (!INC(LGRSMEAEARWTVJ, arg_to)) goto sentence_after_1;
	if (! isSymbolType(LGRSMEAEARWTVJ.container->type)) goto sentence_after_1;
/*SET*/	r_h = LGRSMEAEARWTVJ;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor SJBAOIOJLWHYPN;
/*DEF*/	DataCursor VRUIHOSWKIFYGT;
/*DEF*/	DataCursor YDHACWYHSGEWZM;
/*SET*/	SJBAOIOJLWHYPN = r_h;
/*INC*/	if (!INC(SJBAOIOJLWHYPN, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (SJBAOIOJLWHYPN.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	VRUIHOSWKIFYGT = SJBAOIOJLWHYPN.container->value.bracket_data.chain->at_before_first();
	YDHACWYHSGEWZM   = SJBAOIOJLWHYPN.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = VRUIHOSWKIFYGT;
/*SET*/	r_1 = YDHACWYHSGEWZM;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor TGONZLTJHGAUHN;
/*DEF*/	DataCursor IHREQGJFWKJSMT;
/*DEF*/	DataCursor PJHAEFQZAAULDR;
/*SET*/	TGONZLTJHGAUHN = SJBAOIOJLWHYPN;
/*INC*/	if (!INC(TGONZLTJHGAUHN, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (TGONZLTJHGAUHN.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	IHREQGJFWKJSMT = TGONZLTJHGAUHN.container->value.bracket_data.chain->at_before_first();
	PJHAEFQZAAULDR   = TGONZLTJHGAUHN.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = IHREQGJFWKJSMT;
/*SET*/	r_2 = PJHAEFQZAAULDR;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor CHJCCDYRFVVRIV;
/*DEF*/	DataCursor UYEEGFIVDRCYGU;
/*DEF*/	DataCursor RQDREDAKUBNFGU;
/*SET*/	CHJCCDYRFVVRIV = TGONZLTJHGAUHN;
/*INC*/	if (!INC(CHJCCDYRFVVRIV, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (CHJCCDYRFVVRIV.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	UYEEGFIVDRCYGU = CHJCCDYRFVVRIV.container->value.bracket_data.chain->at_before_first();
	RQDREDAKUBNFGU   = CHJCCDYRFVVRIV.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_n1;
/*DEF*/	DataCursor r_n1;
/*SET*/	l_n1 = UYEEGFIVDRCYGU;
/*SET*/	r_n1 = UYEEGFIVDRCYGU;
/*JMP*/	goto label_PROQYLOBCWQXKZ_firststep;
label_PROQYLOBCWQXKZ: 
/*INC*/	if (!INC(r_n1, RQDREDAKUBNFGU)) goto sentence_after_1;
label_PROQYLOBCWQXKZ_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor MAUSJGMHCMHGDN;
/*SET*/	MAUSJGMHCMHGDN = r_n1;
 if (!SLIDE(MAUSJGMHCMHGDN, RQDREDAKUBNFGU, l_h, r_h)) goto label_PROQYLOBCWQXKZ;
//// [ e.1 ] 
/*DEF*/	DataCursor l_n2;
/*DEF*/	DataCursor r_n2;
/*SET*/	l_n2 = MAUSJGMHCMHGDN;
/*SET*/	r_n2 = RQDREDAKUBNFGU;
//// [ empty ] 
/*ISEMPTY*/	if (CHJCCDYRFVVRIV!=0 && arg_to != CHJCCDYRFVVRIV) goto label_PROQYLOBCWQXKZ;

// подготовка подстановки 
DataChain* FFACLVGRZKKLDA = new DataChain(); 
result->append(newRefExecBrackets(Prout, FFACLVGRZKKLDA, "Prout")); 
FFACLVGRZKKLDA->append(newRefText("step:")); 
FFACLVGRZKKLDA->append_copy(l_h, r_h); 
DataChain* CLLTEOJOMONXRQ = new DataChain(); 
result->append(newRefStructBrackets(CLLTEOJOMONXRQ)); 
CLLTEOJOMONXRQ->append_copy(l_1, r_1); 
CLLTEOJOMONXRQ->append_copy(l_h, r_h); 
DataChain* YJZGINRNNZWACX = new DataChain(); 
result->append(newRefStructBrackets(YJZGINRNNZWACX)); 
YJZGINRNNZWACX->append_copy(l_2, r_2); 
DataChain* XAEDRWUDXZRFUS = new DataChain(); 
result->append(newRefStructBrackets(XAEDRWUDXZRFUS)); 
XAEDRWUDXZRFUS->append_copy(l_n1, r_n1); 
XAEDRWUDXZRFUS->append_copy(l_n2, r_n2); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor EWJTBOXVYNFHKS;
/*SET*/	EWJTBOXVYNFHKS = arg_from;
/*INC*/	if (!INC(EWJTBOXVYNFHKS, arg_to)) goto sentence_after_2;
	if (EWJTBOXVYNFHKS.container->type != text || *(EWJTBOXVYNFHKS.container->value.text + EWJTBOXVYNFHKS.index) != '2') goto sentence_after_2;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor TCENAUMNDDXFDM;
/*DEF*/	DataCursor l_h;
/*DEF*/	DataCursor r_h;
/*SET*/	l_h = EWJTBOXVYNFHKS;
/*SET*/	TCENAUMNDDXFDM = EWJTBOXVYNFHKS;
/*INC*/	if (!INC(TCENAUMNDDXFDM, arg_to)) goto sentence_after_2;
	if (! isSymbolType(TCENAUMNDDXFDM.container->type)) goto sentence_after_2;
/*SET*/	r_h = TCENAUMNDDXFDM;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor VZCAUTDCCKXAAY;
/*DEF*/	DataCursor DZSXTTOBBGQNGV;
/*DEF*/	DataCursor VPJGOJOGLMKXGB;
/*SET*/	VZCAUTDCCKXAAY = r_h;
/*INC*/	if (!INC(VZCAUTDCCKXAAY, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (VZCAUTDCCKXAAY.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	DZSXTTOBBGQNGV = VZCAUTDCCKXAAY.container->value.bracket_data.chain->at_before_first();
	VPJGOJOGLMKXGB   = VZCAUTDCCKXAAY.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = DZSXTTOBBGQNGV;
/*SET*/	r_1 = VPJGOJOGLMKXGB;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor FCPYPCKQCHBDDZ;
/*DEF*/	DataCursor WRXBZMQRLXVOBT;
/*DEF*/	DataCursor WHXGINFGFRCCLM;
/*SET*/	FCPYPCKQCHBDDZ = VZCAUTDCCKXAAY;
/*INC*/	if (!INC(FCPYPCKQCHBDDZ, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (FCPYPCKQCHBDDZ.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	WRXBZMQRLXVOBT = FCPYPCKQCHBDDZ.container->value.bracket_data.chain->at_before_first();
	WHXGINFGFRCCLM   = FCPYPCKQCHBDDZ.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = WRXBZMQRLXVOBT;
/*SET*/	r_2 = WHXGINFGFRCCLM;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor ZNMJUGWWBSQFCI;
/*DEF*/	DataCursor HUBSJOLLMSQSGH;
/*DEF*/	DataCursor MCPHELSOTFLBGS;
/*SET*/	ZNMJUGWWBSQFCI = FCPYPCKQCHBDDZ;
/*INC*/	if (!INC(ZNMJUGWWBSQFCI, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (ZNMJUGWWBSQFCI.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	HUBSJOLLMSQSGH = ZNMJUGWWBSQFCI.container->value.bracket_data.chain->at_before_first();
	MCPHELSOTFLBGS   = ZNMJUGWWBSQFCI.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_n1;
/*DEF*/	DataCursor r_n1;
/*SET*/	l_n1 = HUBSJOLLMSQSGH;
/*SET*/	r_n1 = HUBSJOLLMSQSGH;
/*JMP*/	goto label_FNPCUZSRUPCHYN_firststep;
label_FNPCUZSRUPCHYN: 
/*INC*/	if (!INC(r_n1, MCPHELSOTFLBGS)) goto sentence_after_2;
label_FNPCUZSRUPCHYN_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor VZHCPQUGRIWNIQ;
/*SET*/	VZHCPQUGRIWNIQ = r_n1;
 if (!SLIDE(VZHCPQUGRIWNIQ, MCPHELSOTFLBGS, l_h, r_h)) goto label_FNPCUZSRUPCHYN;
//// [ e.1 ] 
/*DEF*/	DataCursor l_n2;
/*DEF*/	DataCursor r_n2;
/*SET*/	l_n2 = VZHCPQUGRIWNIQ;
/*SET*/	r_n2 = MCPHELSOTFLBGS;
//// [ empty ] 
/*ISEMPTY*/	if (ZNMJUGWWBSQFCI!=0 && arg_to != ZNMJUGWWBSQFCI) goto label_FNPCUZSRUPCHYN;

// подготовка подстановки 
DataChain* PEELFJMTKUQPZO = new DataChain(); 
result->append(newRefExecBrackets(Prout, PEELFJMTKUQPZO, "Prout")); 
PEELFJMTKUQPZO->append(newRefText("step:")); 
PEELFJMTKUQPZO->append_copy(l_h, r_h); 
DataChain* MWNLMBUPMKTLPT = new DataChain(); 
result->append(newRefStructBrackets(MWNLMBUPMKTLPT)); 
MWNLMBUPMKTLPT->append_copy(l_1, r_1); 
DataChain* NDMPDSYDSGVFPE = new DataChain(); 
result->append(newRefStructBrackets(NDMPDSYDSGVFPE)); 
NDMPDSYDSGVFPE->append_copy(l_2, r_2); 
NDMPDSYDSGVFPE->append_copy(l_h, r_h); 
DataChain* NEMWBORIFSUQHC = new DataChain(); 
result->append(newRefStructBrackets(NEMWBORIFSUQHC)); 
NEMWBORIFSUQHC->append_copy(l_n1, r_n1); 
NEMWBORIFSUQHC->append_copy(l_n2, r_n2); 

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
DataChain* ESKMKHSSMVNONW = new DataChain(); 
result->append(newRefExecBrackets(Prout, ESKMKHSSMVNONW, "Prout")); 
ESKMKHSSMVNONW->append(newRefWord("GetHod:")); 
ESKMKHSSMVNONW->append_copy(l_e, r_e); 
DataChain* AFXWHGBIBABVQO = new DataChain(); 
result->append(newRefExecBrackets(GetHod__, AFXWHGBIBABVQO, "GetHod__")); 
AFXWHGBIBABVQO->append_copy(l_e, r_e); 

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
/*DEF*/	DataCursor PQFOVIUSSQFQWE;
/*DEF*/	DataCursor l_v;
/*DEF*/	DataCursor r_v;
/*SET*/	l_v = arg_from;
/*SET*/	PQFOVIUSSQFQWE = arg_from;
/*INC*/	if (!INC(PQFOVIUSSQFQWE, arg_to)) goto sentence_after_1;
	if (! isSymbolType(PQFOVIUSSQFQWE.container->type)) goto sentence_after_1;
/*SET*/	r_v = PQFOVIUSSQFQWE;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = r_v;
/*SET*/	r_e = r_v;
/*JMP*/	goto label_HTXDZUJTLNTXMR_firststep;
label_HTXDZUJTLNTXMR: 
/*INC*/	if (!INC(r_e, arg_to)) goto sentence_after_1;
label_HTXDZUJTLNTXMR_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor JXXWTLGGKYTBIO;
/*DEF*/	DataCursor LYDNILQADOJSKK;
/*DEF*/	DataCursor VFXAHHJMBOCLJA;
/*SET*/	JXXWTLGGKYTBIO = r_e;
/*INC*/	if (!INC(JXXWTLGGKYTBIO, arg_to)) goto label_HTXDZUJTLNTXMR;
//// ISBRACKET 
	if (JXXWTLGGKYTBIO.container->type != struct_bracket) goto label_HTXDZUJTLNTXMR;
//// JMP_BRACKET 
	LYDNILQADOJSKK = JXXWTLGGKYTBIO.container->value.bracket_data.chain->at_before_first();
	VFXAHHJMBOCLJA   = JXXWTLGGKYTBIO.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_not;
/*DEF*/	DataCursor r_not;
/*SET*/	l_not = LYDNILQADOJSKK;
/*SET*/	r_not = VFXAHHJMBOCLJA;
//// [ empty ] 
/*ISEMPTY*/	if (JXXWTLGGKYTBIO!=0 && arg_to != JXXWTLGGKYTBIO) goto label_HTXDZUJTLNTXMR;

// подготовка подстановки 
DataChain* RINTDWCLDVDXRO = new DataChain(); 
result->append(newRefExecBrackets(UseHod, RINTDWCLDVDXRO, "UseHod")); 
RINTDWCLDVDXRO->append_copy(l_v, r_v); 
RINTDWCLDVDXRO->append_copy(l_e, r_e); 
DataChain* PBYJZWYYOJUOTH = new DataChain(); 
RINTDWCLDVDXRO->append(newRefStructBrackets(PBYJZWYYOJUOTH)); 
PBYJZWYYOJUOTH->append_copy(l_not, r_not); 
DataChain* WMLVRGLFZDZDBT = new DataChain(); 
RINTDWCLDVDXRO->append(newRefStructBrackets(WMLVRGLFZDZDBT)); 
DataChain* UBXUOFFVNCRSWS = new DataChain(); 
WMLVRGLFZDZDBT->append(newRefExecBrackets(WriteXO, UBXUOFFVNCRSWS, "WriteXO")); 
UBXUOFFVNCRSWS->append_copy(l_e, r_e); 
DataChain* AZNMOIJOIVVGOB = new DataChain(); 
UBXUOFFVNCRSWS->append(newRefStructBrackets(AZNMOIJOIVVGOB)); 
AZNMOIJOIVVGOB->append(newRefText(">")); 
AZNMOIJOIVVGOB->append_copy(l_not, r_not); 

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
DataChain* QPNCKWVNHKEBMT = new DataChain(); 
result->append(newRefExecBrackets(Prout, QPNCKWVNHKEBMT, "Prout")); 
QPNCKWVNHKEBMT->append(newRefWord("UseHod:")); 
QPNCKWVNHKEBMT->append_copy(l_e, r_e); 
DataChain* DHVYGKJISUXHAT = new DataChain(); 
result->append(newRefExecBrackets(UseHod__, DHVYGKJISUXHAT, "UseHod__")); 
DHVYGKJISUXHAT->append_copy(l_e, r_e); 

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
/*JMP*/	goto label_MUUDQBHMKNHFXA_firststep;
label_MUUDQBHMKNHFXA: 
/*INC*/	if (!INC(r_e, arg_to)) goto sentence_after_1;
label_MUUDQBHMKNHFXA_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor XQXKJLZZQTSJFA;
/*DEF*/	DataCursor EEDFUUJKOLXJOQ;
/*DEF*/	DataCursor KDVFEPVLHVHRWT;
/*SET*/	XQXKJLZZQTSJFA = r_e;
/*INC*/	if (!INC(XQXKJLZZQTSJFA, arg_to)) goto label_MUUDQBHMKNHFXA;
//// ISBRACKET 
	if (XQXKJLZZQTSJFA.container->type != struct_bracket) goto label_MUUDQBHMKNHFXA;
//// JMP_BRACKET 
	EEDFUUJKOLXJOQ = XQXKJLZZQTSJFA.container->value.bracket_data.chain->at_before_first();
	KDVFEPVLHVHRWT   = XQXKJLZZQTSJFA.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor FDUKXFFJPSSWYX;
/*SET*/	FDUKXFFJPSSWYX = EEDFUUJKOLXJOQ;
/*INC*/	if (!INC(FDUKXFFJPSSWYX, KDVFEPVLHVHRWT)) goto label_MUUDQBHMKNHFXA;
	if (FDUKXFFJPSSWYX.container->type != text || *(FDUKXFFJPSSWYX.container->value.text + FDUKXFFJPSSWYX.index) != '#') goto label_MUUDQBHMKNHFXA;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor LIJJHEVRYXOZBA;
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = FDUKXFFJPSSWYX;
/*SET*/	LIJJHEVRYXOZBA = FDUKXFFJPSSWYX;
/*INC*/	if (!INC(LIJJHEVRYXOZBA, KDVFEPVLHVHRWT)) goto label_MUUDQBHMKNHFXA;
	if (! isSymbolType(LIJJHEVRYXOZBA.container->type)) goto label_MUUDQBHMKNHFXA;
/*SET*/	r_s = LIJJHEVRYXOZBA;
//// [ empty ] 
/*ISEMPTY*/	if (r_s!=0 && KDVFEPVLHVHRWT != r_s) goto label_MUUDQBHMKNHFXA;
//// [ empty ] 
/*ISEMPTY*/	if (XQXKJLZZQTSJFA!=0 && arg_to != XQXKJLZZQTSJFA) goto label_MUUDQBHMKNHFXA;

// подготовка подстановки 
result->append_copy(l_s, r_s); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor DQLAHYGGYLJDDJ;
/*DEF*/	DataCursor l_v;
/*DEF*/	DataCursor r_v;
/*SET*/	l_v = arg_from;
/*SET*/	DQLAHYGGYLJDDJ = arg_from;
/*INC*/	if (!INC(DQLAHYGGYLJDDJ, arg_to)) goto sentence_after_2;
	if (! isSymbolType(DQLAHYGGYLJDDJ.container->type)) goto sentence_after_2;
/*SET*/	r_v = DQLAHYGGYLJDDJ;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = r_v;
/*SET*/	r_e = r_v;
/*JMP*/	goto label_HMLTEDZLODSRKE_firststep;
label_HMLTEDZLODSRKE: 
/*INC*/	if (!INC(r_e, arg_to)) goto sentence_after_2;
label_HMLTEDZLODSRKE_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor UTGTNKNTARJKPX;
/*DEF*/	DataCursor INOVGZDTHUNWOO;
/*DEF*/	DataCursor XVJJMPSVKNHKWJ;
/*SET*/	UTGTNKNTARJKPX = r_e;
/*INC*/	if (!INC(UTGTNKNTARJKPX, arg_to)) goto label_HMLTEDZLODSRKE;
//// ISBRACKET 
	if (UTGTNKNTARJKPX.container->type != struct_bracket) goto label_HMLTEDZLODSRKE;
//// JMP_BRACKET 
	INOVGZDTHUNWOO = UTGTNKNTARJKPX.container->value.bracket_data.chain->at_before_first();
	XVJJMPSVKNHKWJ   = UTGTNKNTARJKPX.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_not;
/*DEF*/	DataCursor r_not;
/*SET*/	l_not = INOVGZDTHUNWOO;
/*SET*/	r_not = XVJJMPSVKNHKWJ;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor OPMMLEBKSUCVZQ;
/*DEF*/	DataCursor LYQNWCMBVBHRML;
/*DEF*/	DataCursor OWPJBWYVWTGTOQ;
/*SET*/	OPMMLEBKSUCVZQ = UTGTNKNTARJKPX;
/*INC*/	if (!INC(OPMMLEBKSUCVZQ, arg_to)) goto label_HMLTEDZLODSRKE;
//// ISBRACKET 
	if (OPMMLEBKSUCVZQ.container->type != struct_bracket) goto label_HMLTEDZLODSRKE;
//// JMP_BRACKET 
	LYQNWCMBVBHRML = OPMMLEBKSUCVZQ.container->value.bracket_data.chain->at_before_first();
	OWPJBWYVWTGTOQ   = OPMMLEBKSUCVZQ.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_Wr;
/*DEF*/	DataCursor r_Wr;
/*SET*/	l_Wr = LYQNWCMBVBHRML;
/*SET*/	r_Wr = OWPJBWYVWTGTOQ;
//// [ empty ] 
/*ISEMPTY*/	if (OPMMLEBKSUCVZQ!=0 && arg_to != OPMMLEBKSUCVZQ) goto label_HMLTEDZLODSRKE;

// подготовка подстановки 
DataChain* NMICXAPZARKNNX = new DataChain(); 
result->append(newRefExecBrackets(UHod, NMICXAPZARKNNX, "UHod")); 
DataChain* TUUFARZROSDQWS = new DataChain(); 
NMICXAPZARKNNX->append(newRefStructBrackets(TUUFARZROSDQWS)); 
DataChain* MTCJGHECQUDOSR = new DataChain(); 
TUUFARZROSDQWS->append(newRefExecBrackets(Switch, MTCJGHECQUDOSR, "Switch")); 
MTCJGHECQUDOSR->append_copy(l_v, r_v); 
MTCJGHECQUDOSR->append_copy(l_Wr, r_Wr); 
DataChain* TJXYAAYKQRXYCR = new DataChain(); 
NMICXAPZARKNNX->append(newRefStructBrackets(TJXYAAYKQRXYCR)); 
TJXYAAYKQRXYCR->append_copy(l_Wr, r_Wr); 
DataChain* XUWJXNPQJNBKCP = new DataChain(); 
NMICXAPZARKNNX->append(newRefStructBrackets(XUWJXNPQJNBKCP)); 
XUWJXNPQJNBKCP->append_copy(l_not, r_not); 

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
DataChain* DMOKALXAPEMVBQ = new DataChain(); 
result->append(newRefExecBrackets(Prout, DMOKALXAPEMVBQ, "Prout")); 
DMOKALXAPEMVBQ->append(newRefWord("UHod:")); 
DMOKALXAPEMVBQ->append_copy(l_e, r_e); 
DataChain* LZSVXZKUTAPPWG = new DataChain(); 
result->append(newRefExecBrackets(UHod__, LZSVXZKUTAPPWG, "UHod__")); 
LZSVXZKUTAPPWG->append_copy(l_e, r_e); 

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
/*DEF*/	DataCursor ZPDPYZKZCVBNTC;
/*DEF*/	DataCursor VFXSXPJAOXTFHV;
/*DEF*/	DataCursor XXYTGOKRCXAETA;
/*SET*/	ZPDPYZKZCVBNTC = arg_from;
/*INC*/	if (!INC(ZPDPYZKZCVBNTC, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (ZPDPYZKZCVBNTC.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	VFXSXPJAOXTFHV = ZPDPYZKZCVBNTC.container->value.bracket_data.chain->at_before_first();
	XXYTGOKRCXAETA   = ZPDPYZKZCVBNTC.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_Sw;
/*DEF*/	DataCursor r_Sw;
/*SET*/	l_Sw = VFXSXPJAOXTFHV;
/*SET*/	r_Sw = XXYTGOKRCXAETA;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor UQGNDMPHWZYIAY;
/*DEF*/	DataCursor ABJRQGEPPXYJST;
/*DEF*/	DataCursor TYZUVLDVYBSUXK;
/*SET*/	UQGNDMPHWZYIAY = ZPDPYZKZCVBNTC;
/*INC*/	if (!INC(UQGNDMPHWZYIAY, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (UQGNDMPHWZYIAY.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	ABJRQGEPPXYJST = UQGNDMPHWZYIAY.container->value.bracket_data.chain->at_before_first();
	TYZUVLDVYBSUXK   = UQGNDMPHWZYIAY.container->value.bracket_data.chain->at_last();
//// [ &.name <any> ] 
/*DEF*/	DataCursor BMFZVRTNOVIDZN;
/*SET*/	BMFZVRTNOVIDZN = ABJRQGEPPXYJST;
 if (!SLIDE(BMFZVRTNOVIDZN, TYZUVLDVYBSUXK, l_Sw, r_Sw)) goto sentence_after_1;
//// [ e.1 ] 
/*DEF*/	DataCursor l_Wr;
/*DEF*/	DataCursor r_Wr;
/*SET*/	l_Wr = BMFZVRTNOVIDZN;
/*SET*/	r_Wr = TYZUVLDVYBSUXK;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor PGHOZVAFMSNSNQ;
/*DEF*/	DataCursor IVMVUBCWTFSRQT;
/*DEF*/	DataCursor MKNEPBHOWEJAZH;
/*SET*/	PGHOZVAFMSNSNQ = UQGNDMPHWZYIAY;
/*INC*/	if (!INC(PGHOZVAFMSNSNQ, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (PGHOZVAFMSNSNQ.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	IVMVUBCWTFSRQT = PGHOZVAFMSNSNQ.container->value.bracket_data.chain->at_before_first();
	MKNEPBHOWEJAZH   = PGHOZVAFMSNSNQ.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor KWCMMTPIXXXLZQ;
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = IVMVUBCWTFSRQT;
/*SET*/	KWCMMTPIXXXLZQ = IVMVUBCWTFSRQT;
/*INC*/	if (!INC(KWCMMTPIXXXLZQ, MKNEPBHOWEJAZH)) goto sentence_after_1;
	if (! isSymbolType(KWCMMTPIXXXLZQ.container->type)) goto sentence_after_1;
/*SET*/	r_s = KWCMMTPIXXXLZQ;
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = r_s;
/*SET*/	r_n = MKNEPBHOWEJAZH;
//// [ empty ] 
/*ISEMPTY*/	if (PGHOZVAFMSNSNQ!=0 && arg_to != PGHOZVAFMSNSNQ) goto sentence_after_1;

// подготовка подстановки 
result->append_copy(l_s, r_s); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor YSXTWWTAIDYAXY;
/*DEF*/	DataCursor QLEPRXIBEXXYFV;
/*DEF*/	DataCursor SDDYGTHCUYYFWP;
/*SET*/	YSXTWWTAIDYAXY = arg_from;
/*INC*/	if (!INC(YSXTWWTAIDYAXY, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (YSXTWWTAIDYAXY.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	QLEPRXIBEXXYFV = YSXTWWTAIDYAXY.container->value.bracket_data.chain->at_before_first();
	SDDYGTHCUYYFWP   = YSXTWWTAIDYAXY.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_Sw;
/*DEF*/	DataCursor r_Sw;
/*SET*/	l_Sw = QLEPRXIBEXXYFV;
/*SET*/	r_Sw = SDDYGTHCUYYFWP;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor JSFYBGLGZMBINT;
/*DEF*/	DataCursor ATTNHODTONPYZW;
/*DEF*/	DataCursor OTKGNGUPHPKXEA;
/*SET*/	JSFYBGLGZMBINT = YSXTWWTAIDYAXY;
/*INC*/	if (!INC(JSFYBGLGZMBINT, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (JSFYBGLGZMBINT.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	ATTNHODTONPYZW = JSFYBGLGZMBINT.container->value.bracket_data.chain->at_before_first();
	OTKGNGUPHPKXEA   = JSFYBGLGZMBINT.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor TOWZABSDNVQHKF;
/*DEF*/	DataCursor l_s1;
/*DEF*/	DataCursor r_s1;
/*SET*/	l_s1 = ATTNHODTONPYZW;
/*SET*/	TOWZABSDNVQHKF = ATTNHODTONPYZW;
/*INC*/	if (!INC(TOWZABSDNVQHKF, OTKGNGUPHPKXEA)) goto sentence_after_2;
	if (! isSymbolType(TOWZABSDNVQHKF.container->type)) goto sentence_after_2;
/*SET*/	r_s1 = TOWZABSDNVQHKF;
//// [ `a` <any> ] 
/*DEF*/	DataCursor CMOFISFRFQGVPM;
/*SET*/	CMOFISFRFQGVPM = r_s1;
/*INC*/	if (!INC(CMOFISFRFQGVPM, OTKGNGUPHPKXEA)) goto sentence_after_2;
	if (CMOFISFRFQGVPM.container->type != text || *(CMOFISFRFQGVPM.container->value.text + CMOFISFRFQGVPM.index) != '=') goto sentence_after_2;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor VORPJFZSLZMPJJ;
/*DEF*/	DataCursor l_s2;
/*DEF*/	DataCursor r_s2;
/*SET*/	l_s2 = CMOFISFRFQGVPM;
/*SET*/	VORPJFZSLZMPJJ = CMOFISFRFQGVPM;
/*INC*/	if (!INC(VORPJFZSLZMPJJ, OTKGNGUPHPKXEA)) goto sentence_after_2;
	if (! isSymbolType(VORPJFZSLZMPJJ.container->type)) goto sentence_after_2;
/*SET*/	r_s2 = VORPJFZSLZMPJJ;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = r_s2;
/*SET*/	r_e = r_s2;
/*JMP*/	goto label_NEHRYKXJZUBUAC_firststep;
label_NEHRYKXJZUBUAC: 
/*INC*/	if (!INC(r_e, OTKGNGUPHPKXEA)) goto sentence_after_2;
label_NEHRYKXJZUBUAC_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor CLFKCYZOBGHTUO;
/*SET*/	CLFKCYZOBGHTUO = r_e;
 if (!SLIDE(CLFKCYZOBGHTUO, OTKGNGUPHPKXEA, l_Sw, r_Sw)) goto label_NEHRYKXJZUBUAC;
//// [ e.1 ] 
/*DEF*/	DataCursor l_Wr;
/*DEF*/	DataCursor r_Wr;
/*SET*/	l_Wr = CLFKCYZOBGHTUO;
/*SET*/	r_Wr = OTKGNGUPHPKXEA;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor SWCGMMVEDEWDMF;
/*DEF*/	DataCursor NQWCUQDSCILIQE;
/*DEF*/	DataCursor CIHLUILGMFCSWT;
/*SET*/	SWCGMMVEDEWDMF = JSFYBGLGZMBINT;
/*INC*/	if (!INC(SWCGMMVEDEWDMF, arg_to)) goto label_NEHRYKXJZUBUAC;
//// ISBRACKET 
	if (SWCGMMVEDEWDMF.container->type != struct_bracket) goto label_NEHRYKXJZUBUAC;
//// JMP_BRACKET 
	NQWCUQDSCILIQE = SWCGMMVEDEWDMF.container->value.bracket_data.chain->at_before_first();
	CIHLUILGMFCSWT   = SWCGMMVEDEWDMF.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor WKKXLCBHQKVCSW;
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = NQWCUQDSCILIQE;
/*SET*/	WKKXLCBHQKVCSW = NQWCUQDSCILIQE;
/*INC*/	if (!INC(WKKXLCBHQKVCSW, CIHLUILGMFCSWT)) goto label_NEHRYKXJZUBUAC;
	if (! isSymbolType(WKKXLCBHQKVCSW.container->type)) goto label_NEHRYKXJZUBUAC;
/*SET*/	r_s = WKKXLCBHQKVCSW;
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = r_s;
/*SET*/	r_n = CIHLUILGMFCSWT;
//// [ empty ] 
/*ISEMPTY*/	if (SWCGMMVEDEWDMF!=0 && arg_to != SWCGMMVEDEWDMF) goto label_NEHRYKXJZUBUAC;

// подготовка подстановки 
DataChain* JEBKRJLPGFGRAT = new DataChain(); 
result->append(newRefExecBrackets(UHod, JEBKRJLPGFGRAT, "UHod")); 
DataChain* ZBSGUVZIFNHYXW = new DataChain(); 
JEBKRJLPGFGRAT->append(newRefStructBrackets(ZBSGUVZIFNHYXW)); 
ZBSGUVZIFNHYXW->append_copy(l_Sw, r_Sw); 
DataChain* JSJAVWAUXPANNA = new DataChain(); 
JEBKRJLPGFGRAT->append(newRefStructBrackets(JSJAVWAUXPANNA)); 
JSJAVWAUXPANNA->append_copy(l_e, r_e); 
JSJAVWAUXPANNA->append_copy(l_Sw, r_Sw); 
JSJAVWAUXPANNA->append_copy(l_Wr, r_Wr); 
DataChain* MXJDVZUHNACZYH = new DataChain(); 
JEBKRJLPGFGRAT->append(newRefStructBrackets(MXJDVZUHNACZYH)); 
MXJDVZUHNACZYH->append_copy(l_n, r_n); 

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
DataChain* EPWZOLHUSLRKVW = new DataChain(); 
result->append(newRefExecBrackets(Prout, EPWZOLHUSLRKVW, "Prout")); 
EPWZOLHUSLRKVW->append(newRefText("*===T===T===*")); 
DataChain* PNVGZMIIZWUDWD = new DataChain(); 
result->append(newRefExecBrackets(Prout, PNVGZMIIZWUDWD, "Prout")); 
PNVGZMIIZWUDWD->append(newRefText("|")); 
DataChain* FZLKTBQDXGYYIU = new DataChain(); 
PNVGZMIIZWUDWD->append(newRefExecBrackets(XO, FZLKTBQDXGYYIU, "XO")); 
FZLKTBQDXGYYIU->append(newRefText("1")); 
FZLKTBQDXGYYIU->append_copy(l_1, r_1); 
PNVGZMIIZWUDWD->append(newRefText("|")); 
DataChain* DSJVEZKMESBJLK = new DataChain(); 
PNVGZMIIZWUDWD->append(newRefExecBrackets(XO, DSJVEZKMESBJLK, "XO")); 
DSJVEZKMESBJLK->append(newRefText("2")); 
DSJVEZKMESBJLK->append_copy(l_1, r_1); 
PNVGZMIIZWUDWD->append(newRefText("|")); 
DataChain* YERTAHNEXHUQMJ = new DataChain(); 
PNVGZMIIZWUDWD->append(newRefExecBrackets(XO, YERTAHNEXHUQMJ, "XO")); 
YERTAHNEXHUQMJ->append(newRefText("3")); 
YERTAHNEXHUQMJ->append_copy(l_1, r_1); 
PNVGZMIIZWUDWD->append(newRefText("|")); 
DataChain* ICBMUSQDKLASOL = new DataChain(); 
result->append(newRefExecBrackets(Prout, ICBMUSQDKLASOL, "Prout")); 
ICBMUSQDKLASOL->append(newRefText("*===I===I===*")); 
DataChain* WJXPTXXEUMZFWY = new DataChain(); 
result->append(newRefExecBrackets(Prout, WJXPTXXEUMZFWY, "Prout")); 
WJXPTXXEUMZFWY->append(newRefText("|")); 
DataChain* UCPABQSEFFUNQP = new DataChain(); 
WJXPTXXEUMZFWY->append(newRefExecBrackets(XO, UCPABQSEFFUNQP, "XO")); 
UCPABQSEFFUNQP->append(newRefText("4")); 
UCPABQSEFFUNQP->append_copy(l_1, r_1); 
WJXPTXXEUMZFWY->append(newRefText("|")); 
DataChain* KFNNBECBBCJPDY = new DataChain(); 
WJXPTXXEUMZFWY->append(newRefExecBrackets(XO, KFNNBECBBCJPDY, "XO")); 
KFNNBECBBCJPDY->append(newRefText("5")); 
KFNNBECBBCJPDY->append_copy(l_1, r_1); 
WJXPTXXEUMZFWY->append(newRefText("|")); 
DataChain* JLIBITLLPLXELR = new DataChain(); 
WJXPTXXEUMZFWY->append(newRefExecBrackets(XO, JLIBITLLPLXELR, "XO")); 
JLIBITLLPLXELR->append(newRefText("6")); 
JLIBITLLPLXELR->append_copy(l_1, r_1); 
WJXPTXXEUMZFWY->append(newRefText("|")); 
DataChain* DKEXDTQUVPTTEY = new DataChain(); 
result->append(newRefExecBrackets(Prout, DKEXDTQUVPTTEY, "Prout")); 
DKEXDTQUVPTTEY->append(newRefText("*===I===I===*")); 
DataChain* HTLQLBBBVOQOZK = new DataChain(); 
result->append(newRefExecBrackets(Prout, HTLQLBBBVOQOZK, "Prout")); 
HTLQLBBBVOQOZK->append(newRefText("|")); 
DataChain* YNAYYRBAQMYJHZ = new DataChain(); 
HTLQLBBBVOQOZK->append(newRefExecBrackets(XO, YNAYYRBAQMYJHZ, "XO")); 
YNAYYRBAQMYJHZ->append(newRefText("7")); 
YNAYYRBAQMYJHZ->append_copy(l_1, r_1); 
HTLQLBBBVOQOZK->append(newRefText("|")); 
DataChain* XNDSIYFSEXWBIO = new DataChain(); 
HTLQLBBBVOQOZK->append(newRefExecBrackets(XO, XNDSIYFSEXWBIO, "XO")); 
XNDSIYFSEXWBIO->append(newRefText("8")); 
XNDSIYFSEXWBIO->append_copy(l_1, r_1); 
HTLQLBBBVOQOZK->append(newRefText("|")); 
DataChain* EWQVQRTCDLPQMV = new DataChain(); 
HTLQLBBBVOQOZK->append(newRefExecBrackets(XO, EWQVQRTCDLPQMV, "XO")); 
EWQVQRTCDLPQMV->append(newRefText("9")); 
EWQVQRTCDLPQMV->append_copy(l_1, r_1); 
HTLQLBBBVOQOZK->append(newRefText("|")); 
DataChain* JIFVGYMKGOTZJM = new DataChain(); 
result->append(newRefExecBrackets(Prout, JIFVGYMKGOTZJM, "Prout")); 
JIFVGYMKGOTZJM->append(newRefText("*===I===I===*")); 

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
/*DEF*/	DataCursor NZQTMRPNDEVNMT;
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	NZQTMRPNDEVNMT = arg_from;
/*INC*/	if (!INC(NZQTMRPNDEVNMT, arg_to)) goto sentence_after_1;
	if (! isSymbolType(NZQTMRPNDEVNMT.container->type)) goto sentence_after_1;
/*SET*/	r_1 = NZQTMRPNDEVNMT;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor HJITSSPAQNJRDO;
/*DEF*/	DataCursor YJWPYATMLEYQSV;
/*DEF*/	DataCursor KPAMSVBMVXRLLI;
/*SET*/	HJITSSPAQNJRDO = r_1;
/*INC*/	if (!INC(HJITSSPAQNJRDO, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (HJITSSPAQNJRDO.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	YJWPYATMLEYQSV = HJITSSPAQNJRDO.container->value.bracket_data.chain->at_before_first();
	KPAMSVBMVXRLLI   = HJITSSPAQNJRDO.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_21;
/*DEF*/	DataCursor r_21;
/*SET*/	l_21 = YJWPYATMLEYQSV;
/*SET*/	r_21 = YJWPYATMLEYQSV;
/*JMP*/	goto label_VFEDKJIGAVYXJV_firststep;
label_VFEDKJIGAVYXJV: 
/*INC*/	if (!INC(r_21, KPAMSVBMVXRLLI)) goto sentence_after_1;
label_VFEDKJIGAVYXJV_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor EQVRBACUIGAIPY;
/*SET*/	EQVRBACUIGAIPY = r_21;
 if (!SLIDE(EQVRBACUIGAIPY, KPAMSVBMVXRLLI, l_1, r_1)) goto label_VFEDKJIGAVYXJV;
//// [ e.1 ] 
/*DEF*/	DataCursor l_22;
/*DEF*/	DataCursor r_22;
/*SET*/	l_22 = EQVRBACUIGAIPY;
/*SET*/	r_22 = KPAMSVBMVXRLLI;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor HBBXIPBZNCWHRB;
/*DEF*/	DataCursor LIRIZXOQPTQQWE;
/*DEF*/	DataCursor AAFJEQIOZPYFAU;
/*SET*/	HBBXIPBZNCWHRB = HJITSSPAQNJRDO;
/*INC*/	if (!INC(HBBXIPBZNCWHRB, arg_to)) goto label_VFEDKJIGAVYXJV;
//// ISBRACKET 
	if (HBBXIPBZNCWHRB.container->type != struct_bracket) goto label_VFEDKJIGAVYXJV;
//// JMP_BRACKET 
	LIRIZXOQPTQQWE = HBBXIPBZNCWHRB.container->value.bracket_data.chain->at_before_first();
	AAFJEQIOZPYFAU   = HBBXIPBZNCWHRB.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = LIRIZXOQPTQQWE;
/*SET*/	r_3 = AAFJEQIOZPYFAU;
//// [ empty ] 
/*ISEMPTY*/	if (HBBXIPBZNCWHRB!=0 && arg_to != HBBXIPBZNCWHRB) goto label_VFEDKJIGAVYXJV;

// подготовка подстановки 
result->append(newRefText("-X-")); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor UQMVHXKMNXMSYA;
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	UQMVHXKMNXMSYA = arg_from;
/*INC*/	if (!INC(UQMVHXKMNXMSYA, arg_to)) goto sentence_after_2;
	if (! isSymbolType(UQMVHXKMNXMSYA.container->type)) goto sentence_after_2;
/*SET*/	r_1 = UQMVHXKMNXMSYA;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor MPTLZANOTLSLWU;
/*DEF*/	DataCursor HTFQJRRWBWHMQH;
/*DEF*/	DataCursor ZKHDKCRFVBEIYI;
/*SET*/	MPTLZANOTLSLWU = r_1;
/*INC*/	if (!INC(MPTLZANOTLSLWU, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (MPTLZANOTLSLWU.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	HTFQJRRWBWHMQH = MPTLZANOTLSLWU.container->value.bracket_data.chain->at_before_first();
	ZKHDKCRFVBEIYI   = MPTLZANOTLSLWU.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = HTFQJRRWBWHMQH;
/*SET*/	r_2 = ZKHDKCRFVBEIYI;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor PVFVPZHYUJABTQ;
/*DEF*/	DataCursor WWTBKDOGKEMHIB;
/*DEF*/	DataCursor YXRNXSXRZLETBQ;
/*SET*/	PVFVPZHYUJABTQ = MPTLZANOTLSLWU;
/*INC*/	if (!INC(PVFVPZHYUJABTQ, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (PVFVPZHYUJABTQ.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	WWTBKDOGKEMHIB = PVFVPZHYUJABTQ.container->value.bracket_data.chain->at_before_first();
	YXRNXSXRZLETBQ   = PVFVPZHYUJABTQ.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_31;
/*DEF*/	DataCursor r_31;
/*SET*/	l_31 = WWTBKDOGKEMHIB;
/*SET*/	r_31 = WWTBKDOGKEMHIB;
/*JMP*/	goto label_EXKRQOIERNAPLQ_firststep;
label_EXKRQOIERNAPLQ: 
/*INC*/	if (!INC(r_31, YXRNXSXRZLETBQ)) goto sentence_after_2;
label_EXKRQOIERNAPLQ_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor YJPQOUBVJSEBAL;
/*SET*/	YJPQOUBVJSEBAL = r_31;
 if (!SLIDE(YJPQOUBVJSEBAL, YXRNXSXRZLETBQ, l_1, r_1)) goto label_EXKRQOIERNAPLQ;
//// [ e.1 ] 
/*DEF*/	DataCursor l_32;
/*DEF*/	DataCursor r_32;
/*SET*/	l_32 = YJPQOUBVJSEBAL;
/*SET*/	r_32 = YXRNXSXRZLETBQ;
//// [ empty ] 
/*ISEMPTY*/	if (PVFVPZHYUJABTQ!=0 && arg_to != PVFVPZHYUJABTQ) goto label_EXKRQOIERNAPLQ;

// подготовка подстановки 
result->append(newRefText("-O-")); 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor WNKSVLOIDZFPIR;
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	WNKSVLOIDZFPIR = arg_from;
/*INC*/	if (!INC(WNKSVLOIDZFPIR, arg_to)) goto sentence_after_3;
	if (! isSymbolType(WNKSVLOIDZFPIR.container->type)) goto sentence_after_3;
/*SET*/	r_1 = WNKSVLOIDZFPIR;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor WYCZTWZZVEWXOT;
/*DEF*/	DataCursor AKUDKPEDUPKCZL;
/*DEF*/	DataCursor HWUSKDNEVDCPLB;
/*SET*/	WYCZTWZZVEWXOT = r_1;
/*INC*/	if (!INC(WYCZTWZZVEWXOT, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (WYCZTWZZVEWXOT.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	AKUDKPEDUPKCZL = WYCZTWZZVEWXOT.container->value.bracket_data.chain->at_before_first();
	HWUSKDNEVDCPLB   = WYCZTWZZVEWXOT.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = AKUDKPEDUPKCZL;
/*SET*/	r_2 = HWUSKDNEVDCPLB;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor KLPJMPFDCYQTRC;
/*DEF*/	DataCursor VVVTRFFVPEKKQM;
/*DEF*/	DataCursor CUPRYJAUTEUVCZ;
/*SET*/	KLPJMPFDCYQTRC = WYCZTWZZVEWXOT;
/*INC*/	if (!INC(KLPJMPFDCYQTRC, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (KLPJMPFDCYQTRC.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	VVVTRFFVPEKKQM = KLPJMPFDCYQTRC.container->value.bracket_data.chain->at_before_first();
	CUPRYJAUTEUVCZ   = KLPJMPFDCYQTRC.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = VVVTRFFVPEKKQM;
/*SET*/	r_3 = CUPRYJAUTEUVCZ;
//// [ empty ] 
/*ISEMPTY*/	if (KLPJMPFDCYQTRC!=0 && arg_to != KLPJMPFDCYQTRC) goto sentence_after_3;

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
/*DEF*/	DataCursor VICTHRXSXCLPRG;
/*SET*/	VICTHRXSXCLPRG = arg_from;
/*INC*/	if (!INC(VICTHRXSXCLPRG, arg_to)) goto sentence_after_1;
	if (VICTHRXSXCLPRG.container->type != integer || VICTHRXSXCLPRG.container->value.num != 0) goto sentence_after_1;
//// [ empty ] 
/*ISEMPTY*/	if (VICTHRXSXCLPRG!=0 && arg_to != VICTHRXSXCLPRG) goto sentence_after_1;

// подготовка подстановки 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor DLWXFAIGAYRUEI;
/*DEF*/	DataCursor l_G;
/*DEF*/	DataCursor r_G;
/*SET*/	l_G = arg_from;
/*SET*/	DLWXFAIGAYRUEI = arg_from;
/*INC*/	if (!INC(DLWXFAIGAYRUEI, arg_to)) goto sentence_after_2;
	if (! isSymbolType(DLWXFAIGAYRUEI.container->type)) goto sentence_after_2;
/*SET*/	r_G = DLWXFAIGAYRUEI;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor CUFDIAMHTKBXOT;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_G;
/*SET*/	CUFDIAMHTKBXOT = r_G;
/*INC*/	if (!INC(CUFDIAMHTKBXOT, arg_to)) goto sentence_after_2;
	if (! isSymbolType(CUFDIAMHTKBXOT.container->type)) goto sentence_after_2;
/*SET*/	r_A = CUFDIAMHTKBXOT;
//// [ `a` <any> ] 
/*DEF*/	DataCursor DIRXXGVZQMEYRO;
/*SET*/	DIRXXGVZQMEYRO = r_A;
/*INC*/	if (!INC(DIRXXGVZQMEYRO, arg_to)) goto sentence_after_2;
	if (DIRXXGVZQMEYRO.container->type != text || *(DIRXXGVZQMEYRO.container->value.text + DIRXXGVZQMEYRO.index) != '=') goto sentence_after_2;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor VFICHQNIVFJZAU;
/*DEF*/	DataCursor l_AA;
/*DEF*/	DataCursor r_AA;
/*SET*/	l_AA = DIRXXGVZQMEYRO;
/*SET*/	VFICHQNIVFJZAU = DIRXXGVZQMEYRO;
/*INC*/	if (!INC(VFICHQNIVFJZAU, arg_to)) goto sentence_after_2;
	if (! isSymbolType(VFICHQNIVFJZAU.container->type)) goto sentence_after_2;
/*SET*/	r_AA = VFICHQNIVFJZAU;
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
/*DEF*/	DataCursor GXTUHLCVSPIHAZ;
/*DEF*/	DataCursor l_G;
/*DEF*/	DataCursor r_G;
/*SET*/	l_G = arg_from;
/*SET*/	GXTUHLCVSPIHAZ = arg_from;
/*INC*/	if (!INC(GXTUHLCVSPIHAZ, arg_to)) goto sentence_after_3;
	if (! isSymbolType(GXTUHLCVSPIHAZ.container->type)) goto sentence_after_3;
/*SET*/	r_G = GXTUHLCVSPIHAZ;
//// [ &.name <any> ] 
/*DEF*/	DataCursor RSSFSZWXBQMURW;
/*SET*/	RSSFSZWXBQMURW = r_G;
 if (!SLIDE(RSSFSZWXBQMURW, arg_to, l_G, r_G)) goto sentence_after_3;
//// [ `a` <any> ] 
/*DEF*/	DataCursor MXCDBHUMRGJQMV;
/*SET*/	MXCDBHUMRGJQMV = RSSFSZWXBQMURW;
/*INC*/	if (!INC(MXCDBHUMRGJQMV, arg_to)) goto sentence_after_3;
	if (MXCDBHUMRGJQMV.container->type != text || *(MXCDBHUMRGJQMV.container->value.text + MXCDBHUMRGJQMV.index) != '=') goto sentence_after_3;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor NKYRTNSJVWZXSS;
/*DEF*/	DataCursor l_AA;
/*DEF*/	DataCursor r_AA;
/*SET*/	l_AA = MXCDBHUMRGJQMV;
/*SET*/	NKYRTNSJVWZXSS = MXCDBHUMRGJQMV;
/*INC*/	if (!INC(NKYRTNSJVWZXSS, arg_to)) goto sentence_after_3;
	if (! isSymbolType(NKYRTNSJVWZXSS.container->type)) goto sentence_after_3;
/*SET*/	r_AA = NKYRTNSJVWZXSS;
//// [ &.name <any> ] 
/*DEF*/	DataCursor QXNJOMUYJNJUWR;
/*SET*/	QXNJOMUYJNJUWR = r_AA;
 if (!SLIDE(QXNJOMUYJNJUWR, arg_to, l_G, r_G)) goto sentence_after_3;
//// [ `a` <any> ] 
/*DEF*/	DataCursor SYXWQYYXCSZPOK;
/*SET*/	SYXWQYYXCSZPOK = QXNJOMUYJNJUWR;
/*INC*/	if (!INC(SYXWQYYXCSZPOK, arg_to)) goto sentence_after_3;
	if (SYXWQYYXCSZPOK.container->type != text || *(SYXWQYYXCSZPOK.container->value.text + SYXWQYYXCSZPOK.index) != '=') goto sentence_after_3;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor LWJDRLTBSCIEDP;
/*DEF*/	DataCursor l_BB;
/*DEF*/	DataCursor r_BB;
/*SET*/	l_BB = SYXWQYYXCSZPOK;
/*SET*/	LWJDRLTBSCIEDP = SYXWQYYXCSZPOK;
/*INC*/	if (!INC(LWJDRLTBSCIEDP, arg_to)) goto sentence_after_3;
	if (! isSymbolType(LWJDRLTBSCIEDP.container->type)) goto sentence_after_3;
/*SET*/	r_BB = LWJDRLTBSCIEDP;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = r_BB;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* WAKZTGJHXAUNFQ = new DataChain(); 
result->append(newRefExecBrackets(Switch, WAKZTGJHXAUNFQ, "Switch")); 
WAKZTGJHXAUNFQ->append_copy(l_G, r_G); 
WAKZTGJHXAUNFQ->append_copy(l_G, r_G); 
WAKZTGJHXAUNFQ->append(newRefText("=")); 
DataChain* JVXIOHNJQRJSHY = new DataChain(); 
WAKZTGJHXAUNFQ->append(newRefExecBrackets(Maix, JVXIOHNJQRJSHY, "Maix")); 
JVXIOHNJQRJSHY->append(newRefText("a")); 
JVXIOHNJQRJSHY->append_copy(l_AA, r_AA); 
JVXIOHNJQRJSHY->append_copy(l_BB, r_BB); 
DataChain* MDOVWGEFHJESVH = new DataChain(); 
JVXIOHNJQRJSHY->append(newRefExecBrackets(Compare, MDOVWGEFHJESVH, "Compare")); 
MDOVWGEFHJESVH->append_copy(l_AA, r_AA); 
MDOVWGEFHJESVH->append_copy(l_BB, r_BB); 
WAKZTGJHXAUNFQ->append_copy(l_e, r_e); 

return result; 
}
sentence_after_3: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor TIZIOJLJDPMOXB;
/*DEF*/	DataCursor l_G;
/*DEF*/	DataCursor r_G;
/*SET*/	l_G = arg_from;
/*SET*/	TIZIOJLJDPMOXB = arg_from;
/*INC*/	if (!INC(TIZIOJLJDPMOXB, arg_to)) goto sentence_after_4;
	if (! isSymbolType(TIZIOJLJDPMOXB.container->type)) goto sentence_after_4;
/*SET*/	r_G = TIZIOJLJDPMOXB;
//// [ &.name <any> ] 
/*DEF*/	DataCursor YUYOPQJKZTVJGK;
/*SET*/	YUYOPQJKZTVJGK = r_G;
 if (!SLIDE(YUYOPQJKZTVJGK, arg_to, l_G, r_G)) goto sentence_after_4;
//// [ `a` <any> ] 
/*DEF*/	DataCursor WXKEWPZHBJSUTH;
/*SET*/	WXKEWPZHBJSUTH = YUYOPQJKZTVJGK;
/*INC*/	if (!INC(WXKEWPZHBJSUTH, arg_to)) goto sentence_after_4;
	if (WXKEWPZHBJSUTH.container->type != text || *(WXKEWPZHBJSUTH.container->value.text + WXKEWPZHBJSUTH.index) != '=') goto sentence_after_4;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor SYOEFJGWWYEOZL;
/*DEF*/	DataCursor l_AA;
/*DEF*/	DataCursor r_AA;
/*SET*/	l_AA = WXKEWPZHBJSUTH;
/*SET*/	SYOEFJGWWYEOZL = WXKEWPZHBJSUTH;
/*INC*/	if (!INC(SYOEFJGWWYEOZL, arg_to)) goto sentence_after_4;
	if (! isSymbolType(SYOEFJGWWYEOZL.container->type)) goto sentence_after_4;
/*SET*/	r_AA = SYOEFJGWWYEOZL;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor UHMGABBSQRHCRT;
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = r_AA;
/*SET*/	UHMGABBSQRHCRT = r_AA;
/*INC*/	if (!INC(UHMGABBSQRHCRT, arg_to)) goto sentence_after_4;
	if (! isSymbolType(UHMGABBSQRHCRT.container->type)) goto sentence_after_4;
/*SET*/	r_s = UHMGABBSQRHCRT;
//// [ `a` <any> ] 
/*DEF*/	DataCursor XMJVCAXXSUFAHY;
/*SET*/	XMJVCAXXSUFAHY = r_s;
/*INC*/	if (!INC(XMJVCAXXSUFAHY, arg_to)) goto sentence_after_4;
	if (XMJVCAXXSUFAHY.container->type != text || *(XMJVCAXXSUFAHY.container->value.text + XMJVCAXXSUFAHY.index) != '=') goto sentence_after_4;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor YAYZKHUHJRJSVO;
/*DEF*/	DataCursor l_BB;
/*DEF*/	DataCursor r_BB;
/*SET*/	l_BB = XMJVCAXXSUFAHY;
/*SET*/	YAYZKHUHJRJSVO = XMJVCAXXSUFAHY;
/*INC*/	if (!INC(YAYZKHUHJRJSVO, arg_to)) goto sentence_after_4;
	if (! isSymbolType(YAYZKHUHJRJSVO.container->type)) goto sentence_after_4;
/*SET*/	r_BB = YAYZKHUHJRJSVO;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = r_BB;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* IRZFCBTSEPLKGW = new DataChain(); 
result->append(newRefExecBrackets(Switch, IRZFCBTSEPLKGW, "Switch")); 
IRZFCBTSEPLKGW->append_copy(l_G, r_G); 
IRZFCBTSEPLKGW->append_copy(l_G, r_G); 
IRZFCBTSEPLKGW->append(newRefText("=")); 
IRZFCBTSEPLKGW->append_copy(l_AA, r_AA); 
IRZFCBTSEPLKGW->append_copy(l_e, r_e); 

return result; 
}
sentence_after_4: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor FKHROUOYSRWMQO;
/*DEF*/	DataCursor l_G;
/*DEF*/	DataCursor r_G;
/*SET*/	l_G = arg_from;
/*SET*/	FKHROUOYSRWMQO = arg_from;
/*INC*/	if (!INC(FKHROUOYSRWMQO, arg_to)) goto sentence_after_5;
	if (! isSymbolType(FKHROUOYSRWMQO.container->type)) goto sentence_after_5;
/*SET*/	r_G = FKHROUOYSRWMQO;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor JAHYQMFEVSDCOM;
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = r_G;
/*SET*/	JAHYQMFEVSDCOM = r_G;
/*INC*/	if (!INC(JAHYQMFEVSDCOM, arg_to)) goto sentence_after_5;
	if (! isSymbolType(JAHYQMFEVSDCOM.container->type)) goto sentence_after_5;
/*SET*/	r_s = JAHYQMFEVSDCOM;
//// [ `a` <any> ] 
/*DEF*/	DataCursor RYHGDMLXUKWYZC;
/*SET*/	RYHGDMLXUKWYZC = r_s;
/*INC*/	if (!INC(RYHGDMLXUKWYZC, arg_to)) goto sentence_after_5;
	if (RYHGDMLXUKWYZC.container->type != text || *(RYHGDMLXUKWYZC.container->value.text + RYHGDMLXUKWYZC.index) != '=') goto sentence_after_5;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor PRSKWGXULSUCKB;
/*DEF*/	DataCursor l_AA;
/*DEF*/	DataCursor r_AA;
/*SET*/	l_AA = RYHGDMLXUKWYZC;
/*SET*/	PRSKWGXULSUCKB = RYHGDMLXUKWYZC;
/*INC*/	if (!INC(PRSKWGXULSUCKB, arg_to)) goto sentence_after_5;
	if (! isSymbolType(PRSKWGXULSUCKB.container->type)) goto sentence_after_5;
/*SET*/	r_AA = PRSKWGXULSUCKB;
//// [ &.name <any> ] 
/*DEF*/	DataCursor SEPJEISZSGCEZW;
/*SET*/	SEPJEISZSGCEZW = r_AA;
 if (!SLIDE(SEPJEISZSGCEZW, arg_to, l_G, r_G)) goto sentence_after_5;
//// [ `a` <any> ] 
/*DEF*/	DataCursor APQRVLWIGROVJC;
/*SET*/	APQRVLWIGROVJC = SEPJEISZSGCEZW;
/*INC*/	if (!INC(APQRVLWIGROVJC, arg_to)) goto sentence_after_5;
	if (APQRVLWIGROVJC.container->type != text || *(APQRVLWIGROVJC.container->value.text + APQRVLWIGROVJC.index) != '=') goto sentence_after_5;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor DZXXPHQLSRZIHM;
/*DEF*/	DataCursor l_BB;
/*DEF*/	DataCursor r_BB;
/*SET*/	l_BB = APQRVLWIGROVJC;
/*SET*/	DZXXPHQLSRZIHM = APQRVLWIGROVJC;
/*INC*/	if (!INC(DZXXPHQLSRZIHM, arg_to)) goto sentence_after_5;
	if (! isSymbolType(DZXXPHQLSRZIHM.container->type)) goto sentence_after_5;
/*SET*/	r_BB = DZXXPHQLSRZIHM;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = r_BB;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* WYWMXXGDPYLRAX = new DataChain(); 
result->append(newRefExecBrackets(Switch, WYWMXXGDPYLRAX, "Switch")); 
WYWMXXGDPYLRAX->append_copy(l_G, r_G); 
WYWMXXGDPYLRAX->append_copy(l_G, r_G); 
WYWMXXGDPYLRAX->append(newRefText("=")); 
WYWMXXGDPYLRAX->append_copy(l_BB, r_BB); 
WYWMXXGDPYLRAX->append_copy(l_e, r_e); 

return result; 
}
sentence_after_5: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor GLMTBIYLBHCWHL;
/*DEF*/	DataCursor l_G;
/*DEF*/	DataCursor r_G;
/*SET*/	l_G = arg_from;
/*SET*/	GLMTBIYLBHCWHL = arg_from;
/*INC*/	if (!INC(GLMTBIYLBHCWHL, arg_to)) goto sentence_after_6;
	if (! isSymbolType(GLMTBIYLBHCWHL.container->type)) goto sentence_after_6;
/*SET*/	r_G = GLMTBIYLBHCWHL;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor SYOYHGMGOPPRZA;
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = r_G;
/*SET*/	SYOYHGMGOPPRZA = r_G;
/*INC*/	if (!INC(SYOYHGMGOPPRZA, arg_to)) goto sentence_after_6;
	if (! isSymbolType(SYOYHGMGOPPRZA.container->type)) goto sentence_after_6;
/*SET*/	r_s = SYOYHGMGOPPRZA;
//// [ `a` <any> ] 
/*DEF*/	DataCursor XQMOMSYHGAGIUP;
/*SET*/	XQMOMSYHGAGIUP = r_s;
/*INC*/	if (!INC(XQMOMSYHGAGIUP, arg_to)) goto sentence_after_6;
	if (XQMOMSYHGAGIUP.container->type != text || *(XQMOMSYHGAGIUP.container->value.text + XQMOMSYHGAGIUP.index) != '=') goto sentence_after_6;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor JQBZXTHTOPOTMI;
/*DEF*/	DataCursor l_AA;
/*DEF*/	DataCursor r_AA;
/*SET*/	l_AA = XQMOMSYHGAGIUP;
/*SET*/	JQBZXTHTOPOTMI = XQMOMSYHGAGIUP;
/*INC*/	if (!INC(JQBZXTHTOPOTMI, arg_to)) goto sentence_after_6;
	if (! isSymbolType(JQBZXTHTOPOTMI.container->type)) goto sentence_after_6;
/*SET*/	r_AA = JQBZXTHTOPOTMI;
//// [ &.name <any> ] 
/*DEF*/	DataCursor TNQWTOETONXWZG;
/*SET*/	TNQWTOETONXWZG = r_AA;
 if (!SLIDE(TNQWTOETONXWZG, arg_to, l_s, r_s)) goto sentence_after_6;
//// [ `a` <any> ] 
/*DEF*/	DataCursor HUTIFKLGKLRNUW;
/*SET*/	HUTIFKLGKLRNUW = TNQWTOETONXWZG;
/*INC*/	if (!INC(HUTIFKLGKLRNUW, arg_to)) goto sentence_after_6;
	if (HUTIFKLGKLRNUW.container->type != text || *(HUTIFKLGKLRNUW.container->value.text + HUTIFKLGKLRNUW.index) != '=') goto sentence_after_6;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor KMSYQCPUIVAHQA;
/*DEF*/	DataCursor l_BB;
/*DEF*/	DataCursor r_BB;
/*SET*/	l_BB = HUTIFKLGKLRNUW;
/*SET*/	KMSYQCPUIVAHQA = HUTIFKLGKLRNUW;
/*INC*/	if (!INC(KMSYQCPUIVAHQA, arg_to)) goto sentence_after_6;
	if (! isSymbolType(KMSYQCPUIVAHQA.container->type)) goto sentence_after_6;
/*SET*/	r_BB = KMSYQCPUIVAHQA;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = r_BB;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* DJXWXQMNDHLDTT = new DataChain(); 
result->append(newRefExecBrackets(Switch, DJXWXQMNDHLDTT, "Switch")); 
DJXWXQMNDHLDTT->append_copy(l_G, r_G); 
DJXWXQMNDHLDTT->append_copy(l_s, r_s); 
DJXWXQMNDHLDTT->append(newRefText("=")); 
DataChain* XSKNXTEZNJSQTF = new DataChain(); 
DJXWXQMNDHLDTT->append(newRefExecBrackets(Maix, XSKNXTEZNJSQTF, "Maix")); 
XSKNXTEZNJSQTF->append(newRefText("i")); 
XSKNXTEZNJSQTF->append_copy(l_AA, r_AA); 
XSKNXTEZNJSQTF->append_copy(l_BB, r_BB); 
DataChain* BCCFQMWHBVSSII = new DataChain(); 
XSKNXTEZNJSQTF->append(newRefExecBrackets(Compare, BCCFQMWHBVSSII, "Compare")); 
BCCFQMWHBVSSII->append_copy(l_AA, r_AA); 
BCCFQMWHBVSSII->append_copy(l_BB, r_BB); 
DJXWXQMNDHLDTT->append_copy(l_e, r_e); 

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
DataChain* GVIJSUXIICAAHM = new DataChain(); 
result->append(newRefExecBrackets(Prout, GVIJSUXIICAAHM, "Prout")); 
GVIJSUXIICAAHM->append(newRefText("Sw unk: ")); 
GVIJSUXIICAAHM->append_copy(l_e, r_e); 

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
/*DEF*/	DataCursor KWYWTTJZPPKWLB;
/*SET*/	KWYWTTJZPPKWLB = arg_from;
/*INC*/	if (!INC(KWYWTTJZPPKWLB, arg_to)) goto sentence_after_1;
	if (KWYWTTJZPPKWLB.container->type != text || *(KWYWTTJZPPKWLB.container->value.text + KWYWTTJZPPKWLB.index) != 'a') goto sentence_after_1;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor MJAHTPUTIEBPBB;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = KWYWTTJZPPKWLB;
/*SET*/	MJAHTPUTIEBPBB = KWYWTTJZPPKWLB;
/*INC*/	if (!INC(MJAHTPUTIEBPBB, arg_to)) goto sentence_after_1;
	if (! isSymbolType(MJAHTPUTIEBPBB.container->type)) goto sentence_after_1;
/*SET*/	r_A = MJAHTPUTIEBPBB;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor MUEGYRHLTHXWGJ;
/*DEF*/	DataCursor l_B;
/*DEF*/	DataCursor r_B;
/*SET*/	l_B = r_A;
/*SET*/	MUEGYRHLTHXWGJ = r_A;
/*INC*/	if (!INC(MUEGYRHLTHXWGJ, arg_to)) goto sentence_after_1;
	if (! isSymbolType(MUEGYRHLTHXWGJ.container->type)) goto sentence_after_1;
/*SET*/	r_B = MUEGYRHLTHXWGJ;
//// [ `a` <any> ] 
/*DEF*/	DataCursor PRWVHSHZYAVQYE;
/*SET*/	PRWVHSHZYAVQYE = r_B;
/*INC*/	if (!INC(PRWVHSHZYAVQYE, arg_to)) goto sentence_after_1;
	if (PRWVHSHZYAVQYE.container->type != text || *(PRWVHSHZYAVQYE.container->value.text + PRWVHSHZYAVQYE.index) != '-') goto sentence_after_1;
//// [ empty ] 
/*ISEMPTY*/	if (PRWVHSHZYAVQYE!=0 && arg_to != PRWVHSHZYAVQYE) goto sentence_after_1;

// подготовка подстановки 
result->append_copy(l_B, r_B); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor OIUOZXQTIHWAUR;
/*SET*/	OIUOZXQTIHWAUR = arg_from;
/*INC*/	if (!INC(OIUOZXQTIHWAUR, arg_to)) goto sentence_after_2;
	if (OIUOZXQTIHWAUR.container->type != text || *(OIUOZXQTIHWAUR.container->value.text + OIUOZXQTIHWAUR.index) != 'a') goto sentence_after_2;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor OQRDQWCVLXZIPO;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = OIUOZXQTIHWAUR;
/*SET*/	OQRDQWCVLXZIPO = OIUOZXQTIHWAUR;
/*INC*/	if (!INC(OQRDQWCVLXZIPO, arg_to)) goto sentence_after_2;
	if (! isSymbolType(OQRDQWCVLXZIPO.container->type)) goto sentence_after_2;
/*SET*/	r_A = OQRDQWCVLXZIPO;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor DIISPQNZOMCWVA;
/*DEF*/	DataCursor l_B;
/*DEF*/	DataCursor r_B;
/*SET*/	l_B = r_A;
/*SET*/	DIISPQNZOMCWVA = r_A;
/*INC*/	if (!INC(DIISPQNZOMCWVA, arg_to)) goto sentence_after_2;
	if (! isSymbolType(DIISPQNZOMCWVA.container->type)) goto sentence_after_2;
/*SET*/	r_B = DIISPQNZOMCWVA;
//// [ `a` <any> ] 
/*DEF*/	DataCursor PTGRGDFNYYTKWW;
/*SET*/	PTGRGDFNYYTKWW = r_B;
/*INC*/	if (!INC(PTGRGDFNYYTKWW, arg_to)) goto sentence_after_2;
	if (PTGRGDFNYYTKWW.container->type != text || *(PTGRGDFNYYTKWW.container->value.text + PTGRGDFNYYTKWW.index) != '+') goto sentence_after_2;
//// [ empty ] 
/*ISEMPTY*/	if (PTGRGDFNYYTKWW!=0 && arg_to != PTGRGDFNYYTKWW) goto sentence_after_2;

// подготовка подстановки 
result->append_copy(l_A, r_A); 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor GLFCIEBDUTOEUN;
/*SET*/	GLFCIEBDUTOEUN = arg_from;
/*INC*/	if (!INC(GLFCIEBDUTOEUN, arg_to)) goto sentence_after_3;
	if (GLFCIEBDUTOEUN.container->type != text || *(GLFCIEBDUTOEUN.container->value.text + GLFCIEBDUTOEUN.index) != 'i') goto sentence_after_3;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor FHDAXPHBSYWZTP;
/*DEF*/	DataCursor l_B;
/*DEF*/	DataCursor r_B;
/*SET*/	l_B = GLFCIEBDUTOEUN;
/*SET*/	FHDAXPHBSYWZTP = GLFCIEBDUTOEUN;
/*INC*/	if (!INC(FHDAXPHBSYWZTP, arg_to)) goto sentence_after_3;
	if (! isSymbolType(FHDAXPHBSYWZTP.container->type)) goto sentence_after_3;
/*SET*/	r_B = FHDAXPHBSYWZTP;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor WJNGJNCPXRJVBV;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_B;
/*SET*/	WJNGJNCPXRJVBV = r_B;
/*INC*/	if (!INC(WJNGJNCPXRJVBV, arg_to)) goto sentence_after_3;
	if (! isSymbolType(WJNGJNCPXRJVBV.container->type)) goto sentence_after_3;
/*SET*/	r_A = WJNGJNCPXRJVBV;
//// [ `a` <any> ] 
/*DEF*/	DataCursor CCEFKBEMGSDYMZ;
/*SET*/	CCEFKBEMGSDYMZ = r_A;
/*INC*/	if (!INC(CCEFKBEMGSDYMZ, arg_to)) goto sentence_after_3;
	if (CCEFKBEMGSDYMZ.container->type != text || *(CCEFKBEMGSDYMZ.container->value.text + CCEFKBEMGSDYMZ.index) != '-') goto sentence_after_3;
//// [ empty ] 
/*ISEMPTY*/	if (CCEFKBEMGSDYMZ!=0 && arg_to != CCEFKBEMGSDYMZ) goto sentence_after_3;

// подготовка подстановки 
result->append_copy(l_B, r_B); 

return result; 
}
sentence_after_3: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor UBRYYESHQLZMRE;
/*SET*/	UBRYYESHQLZMRE = arg_from;
/*INC*/	if (!INC(UBRYYESHQLZMRE, arg_to)) goto sentence_after_4;
	if (UBRYYESHQLZMRE.container->type != text || *(UBRYYESHQLZMRE.container->value.text + UBRYYESHQLZMRE.index) != 'i') goto sentence_after_4;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor WQNKQITXGIIGQU;
/*DEF*/	DataCursor l_B;
/*DEF*/	DataCursor r_B;
/*SET*/	l_B = UBRYYESHQLZMRE;
/*SET*/	WQNKQITXGIIGQU = UBRYYESHQLZMRE;
/*INC*/	if (!INC(WQNKQITXGIIGQU, arg_to)) goto sentence_after_4;
	if (! isSymbolType(WQNKQITXGIIGQU.container->type)) goto sentence_after_4;
/*SET*/	r_B = WQNKQITXGIIGQU;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor SKWTCZNLTERXBL;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_B;
/*SET*/	SKWTCZNLTERXBL = r_B;
/*INC*/	if (!INC(SKWTCZNLTERXBL, arg_to)) goto sentence_after_4;
	if (! isSymbolType(SKWTCZNLTERXBL.container->type)) goto sentence_after_4;
/*SET*/	r_A = SKWTCZNLTERXBL;
//// [ `a` <any> ] 
/*DEF*/	DataCursor TZYDYZVAHNKIXJ;
/*SET*/	TZYDYZVAHNKIXJ = r_A;
/*INC*/	if (!INC(TZYDYZVAHNKIXJ, arg_to)) goto sentence_after_4;
	if (TZYDYZVAHNKIXJ.container->type != text || *(TZYDYZVAHNKIXJ.container->value.text + TZYDYZVAHNKIXJ.index) != '+') goto sentence_after_4;
//// [ empty ] 
/*ISEMPTY*/	if (TZYDYZVAHNKIXJ!=0 && arg_to != TZYDYZVAHNKIXJ) goto sentence_after_4;

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
/*JMP*/	goto label_CGDJDRWDNPOSRJ_firststep;
label_CGDJDRWDNPOSRJ: 
/*INC*/	if (!INC(r_e, arg_to)) goto sentence_after_5;
label_CGDJDRWDNPOSRJ_firststep: 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor GDRQRVQTVPPAZH;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_e;
/*SET*/	GDRQRVQTVPPAZH = r_e;
/*INC*/	if (!INC(GDRQRVQTVPPAZH, arg_to)) goto label_CGDJDRWDNPOSRJ;
	if (! isSymbolType(GDRQRVQTVPPAZH.container->type)) goto label_CGDJDRWDNPOSRJ;
/*SET*/	r_A = GDRQRVQTVPPAZH;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor LTJQVCCLPEZTSJ;
/*DEF*/	DataCursor l_zn;
/*DEF*/	DataCursor r_zn;
/*SET*/	l_zn = r_A;
/*SET*/	LTJQVCCLPEZTSJ = r_A;
/*INC*/	if (!INC(LTJQVCCLPEZTSJ, arg_to)) goto label_CGDJDRWDNPOSRJ;
	if (! isSymbolType(LTJQVCCLPEZTSJ.container->type)) goto label_CGDJDRWDNPOSRJ;
/*SET*/	r_zn = LTJQVCCLPEZTSJ;
//// [ empty ] 
/*ISEMPTY*/	if (r_zn!=0 && arg_to != r_zn) goto label_CGDJDRWDNPOSRJ;

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
DataChain* PYNZFROTQPOXMW = new DataChain(); 
result->append(newRefExecBrackets(Prout, PYNZFROTQPOXMW, "Prout")); 
PYNZFROTQPOXMW->append(newRefWord("WriteXO:")); 
PYNZFROTQPOXMW->append_copy(l_e, r_e); 
DataChain* HHWEWNVCBVDKUZ = new DataChain(); 
result->append(newRefExecBrackets(WriteXO__, HHWEWNVCBVDKUZ, "WriteXO__")); 
HHWEWNVCBVDKUZ->append_copy(l_e, r_e); 

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
/*DEF*/	DataCursor IFIFRTWQQEOJUE;
/*DEF*/	DataCursor QBNSKWZEEWZKAO;
/*DEF*/	DataCursor JURSQGSCZVHHUJ;
/*SET*/	IFIFRTWQQEOJUE = arg_from;
/*INC*/	if (!INC(IFIFRTWQQEOJUE, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (IFIFRTWQQEOJUE.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	QBNSKWZEEWZKAO = IFIFRTWQQEOJUE.container->value.bracket_data.chain->at_before_first();
	JURSQGSCZVHHUJ   = IFIFRTWQQEOJUE.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor ZUMIGOFHWBKKFL;
/*DEF*/	DataCursor l_g;
/*DEF*/	DataCursor r_g;
/*SET*/	l_g = QBNSKWZEEWZKAO;
/*SET*/	ZUMIGOFHWBKKFL = QBNSKWZEEWZKAO;
/*INC*/	if (!INC(ZUMIGOFHWBKKFL, JURSQGSCZVHHUJ)) goto sentence_after_2;
	if (! isSymbolType(ZUMIGOFHWBKKFL.container->type)) goto sentence_after_2;
/*SET*/	r_g = ZUMIGOFHWBKKFL;
//// [ empty ] 
/*ISEMPTY*/	if (r_g!=0 && JURSQGSCZVHHUJ != r_g) goto sentence_after_2;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor UWZKCTKAGXKSMF;
/*DEF*/	DataCursor AUWINSJLSOJTRX;
/*DEF*/	DataCursor HWMHLVBYPECJEI;
/*SET*/	UWZKCTKAGXKSMF = IFIFRTWQQEOJUE;
/*INC*/	if (!INC(UWZKCTKAGXKSMF, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (UWZKCTKAGXKSMF.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	AUWINSJLSOJTRX = UWZKCTKAGXKSMF.container->value.bracket_data.chain->at_before_first();
	HWMHLVBYPECJEI   = UWZKCTKAGXKSMF.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = AUWINSJLSOJTRX;
/*SET*/	r_1 = HWMHLVBYPECJEI;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor WWSTNEUIQUBPGU;
/*DEF*/	DataCursor GWGNMIKDWICKDI;
/*DEF*/	DataCursor LSNPDQSVMTERDF;
/*SET*/	WWSTNEUIQUBPGU = UWZKCTKAGXKSMF;
/*INC*/	if (!INC(WWSTNEUIQUBPGU, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (WWSTNEUIQUBPGU.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	GWGNMIKDWICKDI = WWSTNEUIQUBPGU.container->value.bracket_data.chain->at_before_first();
	LSNPDQSVMTERDF   = WWSTNEUIQUBPGU.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = GWGNMIKDWICKDI;
/*SET*/	r_2 = LSNPDQSVMTERDF;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor BLHWBAFBGARCSF;
/*DEF*/	DataCursor IJYLBIIMOFGXEI;
/*DEF*/	DataCursor RPBTYWQZAPKKCA;
/*SET*/	BLHWBAFBGARCSF = WWSTNEUIQUBPGU;
/*INC*/	if (!INC(BLHWBAFBGARCSF, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (BLHWBAFBGARCSF.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	IJYLBIIMOFGXEI = BLHWBAFBGARCSF.container->value.bracket_data.chain->at_before_first();
	RPBTYWQZAPKKCA   = BLHWBAFBGARCSF.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = IJYLBIIMOFGXEI;
/*SET*/	r_n = RPBTYWQZAPKKCA;
//// [ empty ] 
/*ISEMPTY*/	if (BLHWBAFBGARCSF!=0 && arg_to != BLHWBAFBGARCSF) goto sentence_after_2;

// подготовка подстановки 
DataChain* FCOMVNTMDHZXLE = new DataChain(); 
result->append(newRefExecBrackets(WXOif, FCOMVNTMDHZXLE, "WXOif")); 
DataChain* FPPYEBEOEQZNBH = new DataChain(); 
FCOMVNTMDHZXLE->append(newRefStructBrackets(FPPYEBEOEQZNBH)); 
FPPYEBEOEQZNBH->append_copy(l_g, r_g); 
DataChain* YCWMFYAQQIANNY = new DataChain(); 
FCOMVNTMDHZXLE->append(newRefStructBrackets(YCWMFYAQQIANNY)); 
DataChain* HQOUIZVEAVGZJW = new DataChain(); 
YCWMFYAQQIANNY->append(newRefExecBrackets(Strategy, HQOUIZVEAVGZJW, "Strategy")); 
HQOUIZVEAVGZJW->append_copy(l_1, r_1); 
DataChain* OBLSGWNKVJLNIV = new DataChain(); 
FCOMVNTMDHZXLE->append(newRefStructBrackets(OBLSGWNKVJLNIV)); 
DataChain* QCWVZXTCTHYNMU = new DataChain(); 
OBLSGWNKVJLNIV->append(newRefExecBrackets(Strategy, QCWVZXTCTHYNMU, "Strategy")); 
QCWVZXTCTHYNMU->append_copy(l_2, r_2); 
DataChain* XQKWWMTFISGGLG = new DataChain(); 
FCOMVNTMDHZXLE->append(newRefStructBrackets(XQKWWMTFISGGLG)); 
DataChain* COXPIPYTDBAMRY = new DataChain(); 
XQKWWMTFISGGLG->append(newRefExecBrackets(Strategy, COXPIPYTDBAMRY, "Strategy")); 
COXPIPYTDBAMRY->append_copy(l_n, r_n); 
DataChain* KBOKMWGSDDPQKR = new DataChain(); 
FCOMVNTMDHZXLE->append(newRefStructBrackets(KBOKMWGSDDPQKR)); 
KBOKMWGSDDPQKR->append_copy(l_1, r_1); 
DataChain* ZYJCHZTMIEPAGW = new DataChain(); 
FCOMVNTMDHZXLE->append(newRefStructBrackets(ZYJCHZTMIEPAGW)); 
ZYJCHZTMIEPAGW->append_copy(l_2, r_2); 
DataChain* HROQKHWUDBCIHP = new DataChain(); 
FCOMVNTMDHZXLE->append(newRefStructBrackets(HROQKHWUDBCIHP)); 
HROQKHWUDBCIHP->append_copy(l_n, r_n); 

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
DataChain* QWAQZXUGKVAKVL = new DataChain(); 
result->append(newRefExecBrackets(Prout, QWAQZXUGKVAKVL, "Prout")); 
QWAQZXUGKVAKVL->append(newRefWord("WXOif:")); 
QWAQZXUGKVAKVL->append_copy(l_e, r_e); 
DataChain* AVKSWFZSDBVQID = new DataChain(); 
result->append(newRefExecBrackets(WXOif__, AVKSWFZSDBVQID, "WXOif__")); 
AVKSWFZSDBVQID->append_copy(l_e, r_e); 

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
/*DEF*/	DataCursor HTBCDEYTMPPHKU;
/*DEF*/	DataCursor HSXORPUFWHJRUT;
/*DEF*/	DataCursor KSSLHLRXLYDXVK;
/*SET*/	HTBCDEYTMPPHKU = arg_from;
/*INC*/	if (!INC(HTBCDEYTMPPHKU, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (HTBCDEYTMPPHKU.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	HSXORPUFWHJRUT = HTBCDEYTMPPHKU.container->value.bracket_data.chain->at_before_first();
	KSSLHLRXLYDXVK   = HTBCDEYTMPPHKU.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor OSAGGMPBGZVBAF;
/*SET*/	OSAGGMPBGZVBAF = HSXORPUFWHJRUT;
/*INC*/	if (!INC(OSAGGMPBGZVBAF, KSSLHLRXLYDXVK)) goto sentence_after_1;
	if (OSAGGMPBGZVBAF.container->type != text || *(OSAGGMPBGZVBAF.container->value.text + OSAGGMPBGZVBAF.index) != '1') goto sentence_after_1;
//// [ empty ] 
/*ISEMPTY*/	if (OSAGGMPBGZVBAF!=0 && KSSLHLRXLYDXVK != OSAGGMPBGZVBAF) goto sentence_after_1;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_eee1;
/*DEF*/	DataCursor r_eee1;
/*SET*/	l_eee1 = HTBCDEYTMPPHKU;
/*SET*/	r_eee1 = HTBCDEYTMPPHKU;
/*JMP*/	goto label_QAXSREHNRLYJIW_firststep;
label_QAXSREHNRLYJIW: 
/*INC*/	if (!INC(r_eee1, arg_to)) goto sentence_after_1;
label_QAXSREHNRLYJIW_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor TMHGLKOZFKMMXT;
/*DEF*/	DataCursor YVOXHFKXOPVYBJ;
/*DEF*/	DataCursor ZOXHZUBDNTOAMZ;
/*SET*/	TMHGLKOZFKMMXT = r_eee1;
/*INC*/	if (!INC(TMHGLKOZFKMMXT, arg_to)) goto label_QAXSREHNRLYJIW;
//// ISBRACKET 
	if (TMHGLKOZFKMMXT.container->type != struct_bracket) goto label_QAXSREHNRLYJIW;
//// JMP_BRACKET 
	YVOXHFKXOPVYBJ = TMHGLKOZFKMMXT.container->value.bracket_data.chain->at_before_first();
	ZOXHZUBDNTOAMZ   = TMHGLKOZFKMMXT.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = YVOXHFKXOPVYBJ;
/*SET*/	r_1 = YVOXHFKXOPVYBJ;
/*JMP*/	goto label_OTTCJTUEGMPQKC_firststep;
label_OTTCJTUEGMPQKC: 
/*INC*/	if (!INC(r_1, ZOXHZUBDNTOAMZ)) goto label_QAXSREHNRLYJIW;
label_OTTCJTUEGMPQKC_firststep: 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor DBBGCKJQTEBICH;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_1;
/*SET*/	DBBGCKJQTEBICH = r_1;
/*INC*/	if (!INC(DBBGCKJQTEBICH, ZOXHZUBDNTOAMZ)) goto label_OTTCJTUEGMPQKC;
	if (! isSymbolType(DBBGCKJQTEBICH.container->type)) goto label_OTTCJTUEGMPQKC;
/*SET*/	r_A = DBBGCKJQTEBICH;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = r_A;
/*SET*/	r_2 = r_A;
/*JMP*/	goto label_ZNPPRQISWBDHOY_firststep;
label_ZNPPRQISWBDHOY: 
/*INC*/	if (!INC(r_2, ZOXHZUBDNTOAMZ)) goto label_OTTCJTUEGMPQKC;
label_ZNPPRQISWBDHOY_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor NCSAETLGBFVIOC;
/*SET*/	NCSAETLGBFVIOC = r_2;
 if (!SLIDE(NCSAETLGBFVIOC, ZOXHZUBDNTOAMZ, l_A, r_A)) goto label_ZNPPRQISWBDHOY;
//// [ e.1 ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = NCSAETLGBFVIOC;
/*SET*/	r_3 = ZOXHZUBDNTOAMZ;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_eee2;
/*DEF*/	DataCursor r_eee2;
/*SET*/	l_eee2 = TMHGLKOZFKMMXT;
/*SET*/	r_eee2 = TMHGLKOZFKMMXT;
/*JMP*/	goto label_FWXWDRNLFFBFHV_firststep;
label_FWXWDRNLFFBFHV: 
/*INC*/	if (!INC(r_eee2, arg_to)) goto label_ZNPPRQISWBDHOY;
label_FWXWDRNLFFBFHV_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor YXZUKJWOCYHZQJ;
/*DEF*/	DataCursor ZDHTBRRRLLKTCH;
/*DEF*/	DataCursor FNCTPIRNAWONYD;
/*SET*/	YXZUKJWOCYHZQJ = r_eee2;
/*INC*/	if (!INC(YXZUKJWOCYHZQJ, arg_to)) goto label_FWXWDRNLFFBFHV;
//// ISBRACKET 
	if (YXZUKJWOCYHZQJ.container->type != struct_bracket) goto label_FWXWDRNLFFBFHV;
//// JMP_BRACKET 
	ZDHTBRRRLLKTCH = YXZUKJWOCYHZQJ.container->value.bracket_data.chain->at_before_first();
	FNCTPIRNAWONYD   = YXZUKJWOCYHZQJ.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_n1;
/*DEF*/	DataCursor r_n1;
/*SET*/	l_n1 = ZDHTBRRRLLKTCH;
/*SET*/	r_n1 = ZDHTBRRRLLKTCH;
/*JMP*/	goto label_WWVUABUQCIMCNL_firststep;
label_WWVUABUQCIMCNL: 
/*INC*/	if (!INC(r_n1, FNCTPIRNAWONYD)) goto label_FWXWDRNLFFBFHV;
label_WWVUABUQCIMCNL_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor HQODEMAKMUNMAX;
/*SET*/	HQODEMAKMUNMAX = r_n1;
 if (!SLIDE(HQODEMAKMUNMAX, FNCTPIRNAWONYD, l_A, r_A)) goto label_WWVUABUQCIMCNL;
//// [ e.1 ] 
/*DEF*/	DataCursor l_n2;
/*DEF*/	DataCursor r_n2;
/*SET*/	l_n2 = HQODEMAKMUNMAX;
/*SET*/	r_n2 = FNCTPIRNAWONYD;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor IOMKEYWCOFQBKD;
/*DEF*/	DataCursor MZOIZGQIPZAYIX;
/*DEF*/	DataCursor RYDWSOVHZTKGZS;
/*SET*/	IOMKEYWCOFQBKD = YXZUKJWOCYHZQJ;
/*INC*/	if (!INC(IOMKEYWCOFQBKD, arg_to)) goto label_WWVUABUQCIMCNL;
//// ISBRACKET 
	if (IOMKEYWCOFQBKD.container->type != struct_bracket) goto label_WWVUABUQCIMCNL;
//// JMP_BRACKET 
	MZOIZGQIPZAYIX = IOMKEYWCOFQBKD.container->value.bracket_data.chain->at_before_first();
	RYDWSOVHZTKGZS   = IOMKEYWCOFQBKD.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_e1;
/*DEF*/	DataCursor r_e1;
/*SET*/	l_e1 = MZOIZGQIPZAYIX;
/*SET*/	r_e1 = RYDWSOVHZTKGZS;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor KWPTKQCEXRNNXS;
/*DEF*/	DataCursor KYWNDQIZLZKLNI;
/*DEF*/	DataCursor SSAMQAZHLNDNVI;
/*SET*/	KWPTKQCEXRNNXS = IOMKEYWCOFQBKD;
/*INC*/	if (!INC(KWPTKQCEXRNNXS, arg_to)) goto label_WWVUABUQCIMCNL;
//// ISBRACKET 
	if (KWPTKQCEXRNNXS.container->type != struct_bracket) goto label_WWVUABUQCIMCNL;
//// JMP_BRACKET 
	KYWNDQIZLZKLNI = KWPTKQCEXRNNXS.container->value.bracket_data.chain->at_before_first();
	SSAMQAZHLNDNVI   = KWPTKQCEXRNNXS.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_e2;
/*DEF*/	DataCursor r_e2;
/*SET*/	l_e2 = KYWNDQIZLZKLNI;
/*SET*/	r_e2 = SSAMQAZHLNDNVI;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor LTKOIAFMEICGGU;
/*DEF*/	DataCursor ZXHRDJZZHERUSW;
/*DEF*/	DataCursor AVNVSLONOASRUD;
/*SET*/	LTKOIAFMEICGGU = KWPTKQCEXRNNXS;
/*INC*/	if (!INC(LTKOIAFMEICGGU, arg_to)) goto label_WWVUABUQCIMCNL;
//// ISBRACKET 
	if (LTKOIAFMEICGGU.container->type != struct_bracket) goto label_WWVUABUQCIMCNL;
//// JMP_BRACKET 
	ZXHRDJZZHERUSW = LTKOIAFMEICGGU.container->value.bracket_data.chain->at_before_first();
	AVNVSLONOASRUD   = LTKOIAFMEICGGU.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = ZXHRDJZZHERUSW;
/*SET*/	r_n = AVNVSLONOASRUD;
//// [ empty ] 
/*ISEMPTY*/	if (LTKOIAFMEICGGU!=0 && arg_to != LTKOIAFMEICGGU) goto label_WWVUABUQCIMCNL;

// подготовка подстановки 
result->append(newRefText("#")); 
DataChain* RNLDKLDKFZTAGI = new DataChain(); 
result->append(newRefExecBrackets(Lins, RNLDKLDKFZTAGI, "Lins")); 
DataChain* ENATJZWXCLKKUL = new DataChain(); 
RNLDKLDKFZTAGI->append(newRefStructBrackets(ENATJZWXCLKKUL)); 
ENATJZWXCLKKUL->append_copy(l_n, r_n); 
DataChain* NCAQPTONEQLNBT = new DataChain(); 
RNLDKLDKFZTAGI->append(newRefExecBrackets(AntiStrategy, NCAQPTONEQLNBT, "AntiStrategy")); 
NCAQPTONEQLNBT->append_copy(l_A, r_A); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor ODDBMIVAZXZMCO;
/*DEF*/	DataCursor JDHISWKAXIAGTU;
/*DEF*/	DataCursor TAFRSVPPHURAAA;
/*SET*/	ODDBMIVAZXZMCO = arg_from;
/*INC*/	if (!INC(ODDBMIVAZXZMCO, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (ODDBMIVAZXZMCO.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	JDHISWKAXIAGTU = ODDBMIVAZXZMCO.container->value.bracket_data.chain->at_before_first();
	TAFRSVPPHURAAA   = ODDBMIVAZXZMCO.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor IXZTWDYRUUMQAD;
/*DEF*/	DataCursor l_g;
/*DEF*/	DataCursor r_g;
/*SET*/	l_g = JDHISWKAXIAGTU;
/*SET*/	IXZTWDYRUUMQAD = JDHISWKAXIAGTU;
/*INC*/	if (!INC(IXZTWDYRUUMQAD, TAFRSVPPHURAAA)) goto sentence_after_2;
	if (! isSymbolType(IXZTWDYRUUMQAD.container->type)) goto sentence_after_2;
/*SET*/	r_g = IXZTWDYRUUMQAD;
//// [ empty ] 
/*ISEMPTY*/	if (r_g!=0 && TAFRSVPPHURAAA != r_g) goto sentence_after_2;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = ODDBMIVAZXZMCO;
/*SET*/	r_e = ODDBMIVAZXZMCO;
/*JMP*/	goto label_JEPVVCVOIDWMTP_firststep;
label_JEPVVCVOIDWMTP: 
/*INC*/	if (!INC(r_e, arg_to)) goto sentence_after_2;
label_JEPVVCVOIDWMTP_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor BNMQUIOPIWPUWC;
/*DEF*/	DataCursor ZDAPDZGHAVVIYI;
/*DEF*/	DataCursor ROJNOLSOWRMVVJ;
/*SET*/	BNMQUIOPIWPUWC = r_e;
/*INC*/	if (!INC(BNMQUIOPIWPUWC, arg_to)) goto label_JEPVVCVOIDWMTP;
//// ISBRACKET 
	if (BNMQUIOPIWPUWC.container->type != struct_bracket) goto label_JEPVVCVOIDWMTP;
//// JMP_BRACKET 
	ZDAPDZGHAVVIYI = BNMQUIOPIWPUWC.container->value.bracket_data.chain->at_before_first();
	ROJNOLSOWRMVVJ   = BNMQUIOPIWPUWC.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = ZDAPDZGHAVVIYI;
/*SET*/	r_1 = ROJNOLSOWRMVVJ;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor IQSWRICMZSXAVD;
/*DEF*/	DataCursor QAMNFHWFGEOHSK;
/*DEF*/	DataCursor KEFUTXXIBHPULN;
/*SET*/	IQSWRICMZSXAVD = BNMQUIOPIWPUWC;
/*INC*/	if (!INC(IQSWRICMZSXAVD, arg_to)) goto label_JEPVVCVOIDWMTP;
//// ISBRACKET 
	if (IQSWRICMZSXAVD.container->type != struct_bracket) goto label_JEPVVCVOIDWMTP;
//// JMP_BRACKET 
	QAMNFHWFGEOHSK = IQSWRICMZSXAVD.container->value.bracket_data.chain->at_before_first();
	KEFUTXXIBHPULN   = IQSWRICMZSXAVD.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = QAMNFHWFGEOHSK;
/*SET*/	r_2 = KEFUTXXIBHPULN;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor LWXQWWZDGDJGEQ;
/*DEF*/	DataCursor WAPBHLPUDOEMNN;
/*DEF*/	DataCursor TPOUAHGXJHZJBE;
/*SET*/	LWXQWWZDGDJGEQ = IQSWRICMZSXAVD;
/*INC*/	if (!INC(LWXQWWZDGDJGEQ, arg_to)) goto label_JEPVVCVOIDWMTP;
//// ISBRACKET 
	if (LWXQWWZDGDJGEQ.container->type != struct_bracket) goto label_JEPVVCVOIDWMTP;
//// JMP_BRACKET 
	WAPBHLPUDOEMNN = LWXQWWZDGDJGEQ.container->value.bracket_data.chain->at_before_first();
	TPOUAHGXJHZJBE   = LWXQWWZDGDJGEQ.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = WAPBHLPUDOEMNN;
/*SET*/	r_n = TPOUAHGXJHZJBE;
//// [ empty ] 
/*ISEMPTY*/	if (LWXQWWZDGDJGEQ!=0 && arg_to != LWXQWWZDGDJGEQ) goto label_JEPVVCVOIDWMTP;

// подготовка подстановки 
DataChain* PLTTRIABWUCRJM = new DataChain(); 
result->append(newRefExecBrackets(WriteXO1, PLTTRIABWUCRJM, "WriteXO1")); 
DataChain* BVBOZVMXOBATKH = new DataChain(); 
PLTTRIABWUCRJM->append(newRefStructBrackets(BVBOZVMXOBATKH)); 
BVBOZVMXOBATKH->append_copy(l_g, r_g); 
DataChain* QSQCHLHTBOFUIK = new DataChain(); 
PLTTRIABWUCRJM->append(newRefStructBrackets(QSQCHLHTBOFUIK)); 
QSQCHLHTBOFUIK->append_copy(l_1, r_1); 
DataChain* WAFKCOWUUNTFHP = new DataChain(); 
PLTTRIABWUCRJM->append(newRefStructBrackets(WAFKCOWUUNTFHP)); 
WAFKCOWUUNTFHP->append_copy(l_2, r_2); 
DataChain* KDEYHOKQUWQVWT = new DataChain(); 
PLTTRIABWUCRJM->append(newRefStructBrackets(KDEYHOKQUWQVWT)); 
KDEYHOKQUWQVWT->append_copy(l_n, r_n); 

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
DataChain* THHHUGJZMFEUIN = new DataChain(); 
result->append(newRefExecBrackets(Prout, THHHUGJZMFEUIN, "Prout")); 
THHHUGJZMFEUIN->append(newRefWord("Lins:")); 
THHHUGJZMFEUIN->append_copy(l_e, r_e); 
DataChain* IPBNCIZOCKAADA = new DataChain(); 
result->append(newRefExecBrackets(Lins__, IPBNCIZOCKAADA, "Lins__")); 
IPBNCIZOCKAADA->append_copy(l_e, r_e); 

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
/*DEF*/	DataCursor LLJREQTKHUDBLP;
/*DEF*/	DataCursor RZLSRWXOCCSLUT;
/*DEF*/	DataCursor WQZSQTIJVCWNPF;
/*SET*/	LLJREQTKHUDBLP = arg_from;
/*INC*/	if (!INC(LLJREQTKHUDBLP, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (LLJREQTKHUDBLP.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	RZLSRWXOCCSLUT = LLJREQTKHUDBLP.container->value.bracket_data.chain->at_before_first();
	WQZSQTIJVCWNPF   = LLJREQTKHUDBLP.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_n1;
/*DEF*/	DataCursor r_n1;
/*SET*/	l_n1 = RZLSRWXOCCSLUT;
/*SET*/	r_n1 = RZLSRWXOCCSLUT;
/*JMP*/	goto label_LRLUKDIAOHQJHR_firststep;
label_LRLUKDIAOHQJHR: 
/*INC*/	if (!INC(r_n1, WQZSQTIJVCWNPF)) goto sentence_after_1;
label_LRLUKDIAOHQJHR_firststep: 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor AGLGRIYKLDKDFR;
/*DEF*/	DataCursor l_hod;
/*DEF*/	DataCursor r_hod;
/*SET*/	l_hod = r_n1;
/*SET*/	AGLGRIYKLDKDFR = r_n1;
/*INC*/	if (!INC(AGLGRIYKLDKDFR, WQZSQTIJVCWNPF)) goto label_LRLUKDIAOHQJHR;
	if (! isSymbolType(AGLGRIYKLDKDFR.container->type)) goto label_LRLUKDIAOHQJHR;
/*SET*/	r_hod = AGLGRIYKLDKDFR;
//// [ e.1 ] 
/*DEF*/	DataCursor l_n2;
/*DEF*/	DataCursor r_n2;
/*SET*/	l_n2 = r_hod;
/*SET*/	r_n2 = WQZSQTIJVCWNPF;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_as1;
/*DEF*/	DataCursor r_as1;
/*SET*/	l_as1 = LLJREQTKHUDBLP;
/*SET*/	r_as1 = LLJREQTKHUDBLP;
/*JMP*/	goto label_DRXJSTCWRSXGYW_firststep;
label_DRXJSTCWRSXGYW: 
/*INC*/	if (!INC(r_as1, arg_to)) goto label_LRLUKDIAOHQJHR;
label_DRXJSTCWRSXGYW_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor FNHCBKPMESUPMT;
/*SET*/	FNHCBKPMESUPMT = r_as1;
 if (!SLIDE(FNHCBKPMESUPMT, arg_to, l_hod, r_hod)) goto label_DRXJSTCWRSXGYW;
//// [ e.1 ] 
/*DEF*/	DataCursor l_as2;
/*DEF*/	DataCursor r_as2;
/*SET*/	l_as2 = FNHCBKPMESUPMT;
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
DataChain* RVIPFBKTBWZFAH = new DataChain(); 
result->append(newRefExecBrackets(Prout, RVIPFBKTBWZFAH, "Prout")); 
RVIPFBKTBWZFAH->append(newRefWord("AntiStrategy:")); 
RVIPFBKTBWZFAH->append_copy(l_e, r_e); 
DataChain* OEVNHXBRHHFOBG = new DataChain(); 
result->append(newRefExecBrackets(AntiStrategy__, OEVNHXBRHHFOBG, "AntiStrategy__")); 
OEVNHXBRHHFOBG->append_copy(l_e, r_e); 

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
/*DEF*/	DataCursor YWCVHKTDOXQTEK;
/*SET*/	YWCVHKTDOXQTEK = arg_from;
/*INC*/	if (!INC(YWCVHKTDOXQTEK, arg_to)) goto sentence_after_1;
	if (YWCVHKTDOXQTEK.container->type != text || *(YWCVHKTDOXQTEK.container->value.text + YWCVHKTDOXQTEK.index) != '1') goto sentence_after_1;
//// [ empty ] 
/*ISEMPTY*/	if (YWCVHKTDOXQTEK!=0 && arg_to != YWCVHKTDOXQTEK) goto sentence_after_1;

// подготовка подстановки 
result->append(newRefText("123")); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor BDVEMUNNLXUBYK;
/*SET*/	BDVEMUNNLXUBYK = arg_from;
/*INC*/	if (!INC(BDVEMUNNLXUBYK, arg_to)) goto sentence_after_2;
	if (BDVEMUNNLXUBYK.container->type != text || *(BDVEMUNNLXUBYK.container->value.text + BDVEMUNNLXUBYK.index) != '2') goto sentence_after_2;
//// [ empty ] 
/*ISEMPTY*/	if (BDVEMUNNLXUBYK!=0 && arg_to != BDVEMUNNLXUBYK) goto sentence_after_2;

// подготовка подстановки 
result->append(newRefText("456")); 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor ZXHREVNXQUEZXK;
/*SET*/	ZXHREVNXQUEZXK = arg_from;
/*INC*/	if (!INC(ZXHREVNXQUEZXK, arg_to)) goto sentence_after_3;
	if (ZXHREVNXQUEZXK.container->type != text || *(ZXHREVNXQUEZXK.container->value.text + ZXHREVNXQUEZXK.index) != '3') goto sentence_after_3;
//// [ empty ] 
/*ISEMPTY*/	if (ZXHREVNXQUEZXK!=0 && arg_to != ZXHREVNXQUEZXK) goto sentence_after_3;

// подготовка подстановки 
result->append(newRefText("789")); 

return result; 
}
sentence_after_3: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor HTJHYEZKYHPFXW;
/*SET*/	HTJHYEZKYHPFXW = arg_from;
/*INC*/	if (!INC(HTJHYEZKYHPFXW, arg_to)) goto sentence_after_4;
	if (HTJHYEZKYHPFXW.container->type != text || *(HTJHYEZKYHPFXW.container->value.text + HTJHYEZKYHPFXW.index) != '4') goto sentence_after_4;
//// [ empty ] 
/*ISEMPTY*/	if (HTJHYEZKYHPFXW!=0 && arg_to != HTJHYEZKYHPFXW) goto sentence_after_4;

// подготовка подстановки 
result->append(newRefText("147")); 

return result; 
}
sentence_after_4: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor XVFHQFAWKFDJPY;
/*SET*/	XVFHQFAWKFDJPY = arg_from;
/*INC*/	if (!INC(XVFHQFAWKFDJPY, arg_to)) goto sentence_after_5;
	if (XVFHQFAWKFDJPY.container->type != text || *(XVFHQFAWKFDJPY.container->value.text + XVFHQFAWKFDJPY.index) != '5') goto sentence_after_5;
//// [ empty ] 
/*ISEMPTY*/	if (XVFHQFAWKFDJPY!=0 && arg_to != XVFHQFAWKFDJPY) goto sentence_after_5;

// подготовка подстановки 
result->append(newRefText("258")); 

return result; 
}
sentence_after_5: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor EYRFCPXSCJKCFG;
/*SET*/	EYRFCPXSCJKCFG = arg_from;
/*INC*/	if (!INC(EYRFCPXSCJKCFG, arg_to)) goto sentence_after_6;
	if (EYRFCPXSCJKCFG.container->type != text || *(EYRFCPXSCJKCFG.container->value.text + EYRFCPXSCJKCFG.index) != '6') goto sentence_after_6;
//// [ empty ] 
/*ISEMPTY*/	if (EYRFCPXSCJKCFG!=0 && arg_to != EYRFCPXSCJKCFG) goto sentence_after_6;

// подготовка подстановки 
result->append(newRefText("369")); 

return result; 
}
sentence_after_6: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor ZHWZIZCYUCEGLM;
/*SET*/	ZHWZIZCYUCEGLM = arg_from;
/*INC*/	if (!INC(ZHWZIZCYUCEGLM, arg_to)) goto sentence_after_7;
	if (ZHWZIZCYUCEGLM.container->type != text || *(ZHWZIZCYUCEGLM.container->value.text + ZHWZIZCYUCEGLM.index) != '7') goto sentence_after_7;
//// [ empty ] 
/*ISEMPTY*/	if (ZHWZIZCYUCEGLM!=0 && arg_to != ZHWZIZCYUCEGLM) goto sentence_after_7;

// подготовка подстановки 
result->append(newRefText("159")); 

return result; 
}
sentence_after_7: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor XLGIBYZZKIAJXM;
/*SET*/	XLGIBYZZKIAJXM = arg_from;
/*INC*/	if (!INC(XLGIBYZZKIAJXM, arg_to)) goto sentence_after_8;
	if (XLGIBYZZKIAJXM.container->type != text || *(XLGIBYZZKIAJXM.container->value.text + XLGIBYZZKIAJXM.index) != '8') goto sentence_after_8;
//// [ empty ] 
/*ISEMPTY*/	if (XLGIBYZZKIAJXM!=0 && arg_to != XLGIBYZZKIAJXM) goto sentence_after_8;

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
DataChain* LZGPPXOOEOQXPP = new DataChain(); 
result->append(newRefExecBrackets(Prout, LZGPPXOOEOQXPP, "Prout")); 
LZGPPXOOEOQXPP->append(newRefWord("WriteXO1:")); 
LZGPPXOOEOQXPP->append_copy(l_e, r_e); 
DataChain* BPMBLXNKEOFMNI = new DataChain(); 
result->append(newRefExecBrackets(WriteXO1__, BPMBLXNKEOFMNI, "WriteXO1__")); 
BPMBLXNKEOFMNI->append_copy(l_e, r_e); 

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
/*JMP*/	goto label_UMJCAFCUYVDCUE_firststep;
label_UMJCAFCUYVDCUE: 
/*INC*/	if (!INC(r_eee, arg_to)) goto sentence_after_2;
label_UMJCAFCUYVDCUE_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor TERQPJJWAKNKXT;
/*DEF*/	DataCursor LZQFLJNWKXGKFY;
/*DEF*/	DataCursor LNUKBIYSPLKHJU;
/*SET*/	TERQPJJWAKNKXT = r_eee;
/*INC*/	if (!INC(TERQPJJWAKNKXT, arg_to)) goto label_UMJCAFCUYVDCUE;
//// ISBRACKET 
	if (TERQPJJWAKNKXT.container->type != struct_bracket) goto label_UMJCAFCUYVDCUE;
//// JMP_BRACKET 
	LZQFLJNWKXGKFY = TERQPJJWAKNKXT.container->value.bracket_data.chain->at_before_first();
	LNUKBIYSPLKHJU   = TERQPJJWAKNKXT.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = LZQFLJNWKXGKFY;
/*SET*/	r_3 = LZQFLJNWKXGKFY;
/*JMP*/	goto label_CFUWOHZVPHJBJY_firststep;
label_CFUWOHZVPHJBJY: 
/*INC*/	if (!INC(r_3, LNUKBIYSPLKHJU)) goto label_UMJCAFCUYVDCUE;
label_CFUWOHZVPHJBJY_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor OVDLNBFRKVBEMW;
/*SET*/	OVDLNBFRKVBEMW = r_3;
/*INC*/	if (!INC(OVDLNBFRKVBEMW, LNUKBIYSPLKHJU)) goto label_CFUWOHZVPHJBJY;
	if (OVDLNBFRKVBEMW.container->type != text || *(OVDLNBFRKVBEMW.container->value.text + OVDLNBFRKVBEMW.index) != '>') goto label_CFUWOHZVPHJBJY;
//// [ empty ] 
/*ISEMPTY*/	if (OVDLNBFRKVBEMW!=0 && LNUKBIYSPLKHJU != OVDLNBFRKVBEMW) goto label_CFUWOHZVPHJBJY;
//// [ empty ] 
/*ISEMPTY*/	if (TERQPJJWAKNKXT!=0 && arg_to != TERQPJJWAKNKXT) goto label_CFUWOHZVPHJBJY;

// подготовка подстановки 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor WEKKOUXDCYNKHT;
/*DEF*/	DataCursor OSFYTLUCENTOIL;
/*DEF*/	DataCursor FULDVRXLONVKXZ;
/*SET*/	WEKKOUXDCYNKHT = arg_from;
/*INC*/	if (!INC(WEKKOUXDCYNKHT, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (WEKKOUXDCYNKHT.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	OSFYTLUCENTOIL = WEKKOUXDCYNKHT.container->value.bracket_data.chain->at_before_first();
	FULDVRXLONVKXZ   = WEKKOUXDCYNKHT.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor ECXEPKMZZGXLUA;
/*DEF*/	DataCursor l_g;
/*DEF*/	DataCursor r_g;
/*SET*/	l_g = OSFYTLUCENTOIL;
/*SET*/	ECXEPKMZZGXLUA = OSFYTLUCENTOIL;
/*INC*/	if (!INC(ECXEPKMZZGXLUA, FULDVRXLONVKXZ)) goto sentence_after_3;
	if (! isSymbolType(ECXEPKMZZGXLUA.container->type)) goto sentence_after_3;
/*SET*/	r_g = ECXEPKMZZGXLUA;
//// [ empty ] 
/*ISEMPTY*/	if (r_g!=0 && FULDVRXLONVKXZ != r_g) goto sentence_after_3;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_eee;
/*DEF*/	DataCursor r_eee;
/*SET*/	l_eee = WEKKOUXDCYNKHT;
/*SET*/	r_eee = WEKKOUXDCYNKHT;
/*JMP*/	goto label_HMJYECSLDJESDC_firststep;
label_HMJYECSLDJESDC: 
/*INC*/	if (!INC(r_eee, arg_to)) goto sentence_after_3;
label_HMJYECSLDJESDC_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor PJIKVPAUDVKXGL;
/*DEF*/	DataCursor LISAAMBOVJKDQR;
/*DEF*/	DataCursor KDORJFNYGHHHPT;
/*SET*/	PJIKVPAUDVKXGL = r_eee;
/*INC*/	if (!INC(PJIKVPAUDVKXGL, arg_to)) goto label_HMJYECSLDJESDC;
//// ISBRACKET 
	if (PJIKVPAUDVKXGL.container->type != struct_bracket) goto label_HMJYECSLDJESDC;
//// JMP_BRACKET 
	LISAAMBOVJKDQR = PJIKVPAUDVKXGL.container->value.bracket_data.chain->at_before_first();
	KDORJFNYGHHHPT   = PJIKVPAUDVKXGL.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = LISAAMBOVJKDQR;
/*SET*/	r_3 = LISAAMBOVJKDQR;
/*JMP*/	goto label_ZIFAWFTZQGEMNH_firststep;
label_ZIFAWFTZQGEMNH: 
/*INC*/	if (!INC(r_3, KDORJFNYGHHHPT)) goto label_HMJYECSLDJESDC;
label_ZIFAWFTZQGEMNH_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor PQYICTMOYFPCVK;
/*SET*/	PQYICTMOYFPCVK = r_3;
/*INC*/	if (!INC(PQYICTMOYFPCVK, KDORJFNYGHHHPT)) goto label_ZIFAWFTZQGEMNH;
	if (PQYICTMOYFPCVK.container->type != text || *(PQYICTMOYFPCVK.container->value.text + PQYICTMOYFPCVK.index) != '>') goto label_ZIFAWFTZQGEMNH;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor CAODAKJACQAUZY;
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = PQYICTMOYFPCVK;
/*SET*/	CAODAKJACQAUZY = PQYICTMOYFPCVK;
/*INC*/	if (!INC(CAODAKJACQAUZY, KDORJFNYGHHHPT)) goto label_ZIFAWFTZQGEMNH;
	if (! isSymbolType(CAODAKJACQAUZY.container->type)) goto label_ZIFAWFTZQGEMNH;
/*SET*/	r_s = CAODAKJACQAUZY;
//// [ e.1 ] 
/*DEF*/	DataCursor l_4;
/*DEF*/	DataCursor r_4;
/*SET*/	l_4 = r_s;
/*SET*/	r_4 = KDORJFNYGHHHPT;
//// [ empty ] 
/*ISEMPTY*/	if (PJIKVPAUDVKXGL!=0 && arg_to != PJIKVPAUDVKXGL) goto label_ZIFAWFTZQGEMNH;

// подготовка подстановки 
DataChain* ZMNIMDLXMJYDAX = new DataChain(); 
result->append(newRefExecBrackets(Length, ZMNIMDLXMJYDAX, "Length")); 
DataChain* YJNECXSJJBHIQN = new DataChain(); 
ZMNIMDLXMJYDAX->append(newRefExecBrackets(Optima21, YJNECXSJJBHIQN, "Optima21")); 
DataChain* VOCDENQMWILXXZ = new DataChain(); 
YJNECXSJJBHIQN->append(newRefExecBrackets(Analiz, VOCDENQMWILXXZ, "Analiz")); 
DataChain* OQFOTPIKPQUDMO = new DataChain(); 
VOCDENQMWILXXZ->append(newRefStructBrackets(OQFOTPIKPQUDMO)); 
OQFOTPIKPQUDMO->append_copy(l_g, r_g); 
VOCDENQMWILXXZ->append_copy(l_eee, r_eee); 
DataChain* MIKPPZHDHFQSGB = new DataChain(); 
VOCDENQMWILXXZ->append(newRefStructBrackets(MIKPPZHDHFQSGB)); 
MIKPPZHDHFQSGB->append_copy(l_3, r_3); 
MIKPPZHDHFQSGB->append(newRefText(">")); 
MIKPPZHDHFQSGB->append_copy(l_s, r_s); 
MIKPPZHDHFQSGB->append_copy(l_4, r_4); 
DataChain* XIISYZWNHXYFVY = new DataChain(); 
result->append(newRefExecBrackets(WriteXO, XIISYZWNHXYFVY, "WriteXO")); 
DataChain* DFMPDWOMCIUDCN = new DataChain(); 
XIISYZWNHXYFVY->append(newRefStructBrackets(DFMPDWOMCIUDCN)); 
DFMPDWOMCIUDCN->append_copy(l_g, r_g); 
XIISYZWNHXYFVY->append_copy(l_eee, r_eee); 
DataChain* YNDGCNFJITPPMY = new DataChain(); 
XIISYZWNHXYFVY->append(newRefStructBrackets(YNDGCNFJITPPMY)); 
YNDGCNFJITPPMY->append_copy(l_3, r_3); 
YNDGCNFJITPPMY->append_copy(l_s, r_s); 
YNDGCNFJITPPMY->append(newRefText(">")); 
YNDGCNFJITPPMY->append_copy(l_4, r_4); 

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
/*DEF*/	DataCursor MXIISNEBPYWSGQ;
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	MXIISNEBPYWSGQ = arg_from;
/*INC*/	if (!INC(MXIISNEBPYWSGQ, arg_to)) goto sentence_after_1;
	if (! isSymbolType(MXIISNEBPYWSGQ.container->type)) goto sentence_after_1;
/*SET*/	r_1 = MXIISNEBPYWSGQ;
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
DataChain* SXDJPLWZFMJOOP = new DataChain(); 
result->append(newRefExecBrackets(Prout, SXDJPLWZFMJOOP, "Prout")); 
SXDJPLWZFMJOOP->append(newRefWord("Length:")); 
SXDJPLWZFMJOOP->append_copy(l_e, r_e); 
DataChain* YYIFVKMWWPGPLJ = new DataChain(); 
result->append(newRefExecBrackets(Length__, YYIFVKMWWPGPLJ, "Length__")); 
YYIFVKMWWPGPLJ->append_copy(l_e, r_e); 

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
/*JMP*/	goto label_EAWPVAPIHOXUUF_firststep;
label_EAWPVAPIHOXUUF: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_1;
label_EAWPVAPIHOXUUF_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor FBRWHPEVCOQRGR;
/*SET*/	FBRWHPEVCOQRGR = r_1;
/*INC*/	if (!INC(FBRWHPEVCOQRGR, arg_to)) goto label_EAWPVAPIHOXUUF;
	static DataChain *BZFHXUNRKLIBVP = text_to_chain("12");
	static DataCursor BZFHXUNRKLIBVP_l = BZFHXUNRKLIBVP->at_before_first();
	static DataCursor BZFHXUNRKLIBVP_r = BZFHXUNRKLIBVP->at_last();
 if (!SLIDE(FBRWHPEVCOQRGR, arg_to, BZFHXUNRKLIBVP_l, BZFHXUNRKLIBVP_r)) goto label_EAWPVAPIHOXUUF;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = FBRWHPEVCOQRGR;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
DataChain* SZZNOPFGAXZGFL = new DataChain(); 
result->append(newRefExecBrackets(DivS, SZZNOPFGAXZGFL, "DivS")); 
DataChain* TLSXBTUMILOCLT = new DataChain(); 
SZZNOPFGAXZGFL->append(newRefExecBrackets(First1, TLSXBTUMILOCLT, "First1")); 
DataChain* GCOZGTZIUFUZIM = new DataChain(); 
TLSXBTUMILOCLT->append(newRefExecBrackets(Lenw, GCOZGTZIUFUZIM, "Lenw")); 
GCOZGTZIUFUZIM->append_copy(l_1, r_1); 
GCOZGTZIUFUZIM->append(newRefText("1")); 
DataChain* XEEKWNYSBICRFX = new DataChain(); 
SZZNOPFGAXZGFL->append(newRefExecBrackets(First1, XEEKWNYSBICRFX, "First1")); 
DataChain* DIOGCSEOZPSCRH = new DataChain(); 
XEEKWNYSBICRFX->append(newRefExecBrackets(Lenw, DIOGCSEOZPSCRH, "Lenw")); 
DIOGCSEOZPSCRH->append(newRefText("2")); 
DIOGCSEOZPSCRH->append_copy(l_2, r_2); 

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
/*JMP*/	goto label_JOTYCZCWMBAAOL_firststep;
label_JOTYCZCWMBAAOL: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_2;
label_JOTYCZCWMBAAOL_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor SVUBPYLONMWAJG;
/*SET*/	SVUBPYLONMWAJG = r_1;
/*INC*/	if (!INC(SVUBPYLONMWAJG, arg_to)) goto label_JOTYCZCWMBAAOL;
	if (SVUBPYLONMWAJG.container->type != text || *(SVUBPYLONMWAJG.container->value.text + SVUBPYLONMWAJG.index) != '1') goto label_JOTYCZCWMBAAOL;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = SVUBPYLONMWAJG;
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
/*JMP*/	goto label_IKQJTXGVENKSPP_firststep;
label_IKQJTXGVENKSPP: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_3;
label_IKQJTXGVENKSPP_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor WWPLHXTGYBVMAJ;
/*SET*/	WWPLHXTGYBVMAJ = r_1;
/*INC*/	if (!INC(WWPLHXTGYBVMAJ, arg_to)) goto label_IKQJTXGVENKSPP;
	if (WWPLHXTGYBVMAJ.container->type != text || *(WWPLHXTGYBVMAJ.container->value.text + WWPLHXTGYBVMAJ.index) != '2') goto label_IKQJTXGVENKSPP;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = WWPLHXTGYBVMAJ;
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
DataChain* MDUCLAAIOISSIS = new DataChain(); 
result->append(newRefExecBrackets(Prout, MDUCLAAIOISSIS, "Prout")); 
MDUCLAAIOISSIS->append(newRefText("Length error symbols!!! : ")); 
DataChain* IYPPNZDUBPTSAV = new DataChain(); 
result->append(newRefExecBrackets(Print, IYPPNZDUBPTSAV, "Print")); 
IYPPNZDUBPTSAV->append_copy(l_1, r_1); 

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
/*DEF*/	DataCursor ESZSIPPQMOTJHK;
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	ESZSIPPQMOTJHK = arg_from;
/*INC*/	if (!INC(ESZSIPPQMOTJHK, arg_to)) goto sentence_after_1;
	if (! isSymbolType(ESZSIPPQMOTJHK.container->type)) goto sentence_after_1;
/*SET*/	r_1 = ESZSIPPQMOTJHK;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor UDNVQZBKATNEFU;
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = r_1;
/*SET*/	UDNVQZBKATNEFU = r_1;
/*INC*/	if (!INC(UDNVQZBKATNEFU, arg_to)) goto sentence_after_1;
	if (! isSymbolType(UDNVQZBKATNEFU.container->type)) goto sentence_after_1;
/*SET*/	r_2 = UDNVQZBKATNEFU;
//// [ empty ] 
/*ISEMPTY*/	if (r_2!=0 && arg_to != r_2) goto sentence_after_1;

// подготовка подстановки 
DataChain* LGEXKTRMHDDAPS = new DataChain(); 
result->append(newRefExecBrackets(IfDiv, LGEXKTRMHDDAPS, "IfDiv")); 
DataChain* WPTFVOVUJIUWBM = new DataChain(); 
LGEXKTRMHDDAPS->append(newRefExecBrackets(Compare, WPTFVOVUJIUWBM, "Compare")); 
WPTFVOVUJIUWBM->append_copy(l_1, r_1); 
WPTFVOVUJIUWBM->append_copy(l_2, r_2); 
LGEXKTRMHDDAPS->append_copy(l_1, r_1); 
LGEXKTRMHDDAPS->append_copy(l_2, r_2); 

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
/*DEF*/	DataCursor IBRUCTTMRVZNJR;
/*SET*/	IBRUCTTMRVZNJR = arg_from;
/*INC*/	if (!INC(IBRUCTTMRVZNJR, arg_to)) goto sentence_after_1;
	if (IBRUCTTMRVZNJR.container->type != text || *(IBRUCTTMRVZNJR.container->value.text + IBRUCTTMRVZNJR.index) != '+') goto sentence_after_1;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor CHJWZWMOZECRZN;
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = IBRUCTTMRVZNJR;
/*SET*/	CHJWZWMOZECRZN = IBRUCTTMRVZNJR;
/*INC*/	if (!INC(CHJWZWMOZECRZN, arg_to)) goto sentence_after_1;
	if (! isSymbolType(CHJWZWMOZECRZN.container->type)) goto sentence_after_1;
/*SET*/	r_1 = CHJWZWMOZECRZN;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor JKFRVKRMRDWROA;
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = r_1;
/*SET*/	JKFRVKRMRDWROA = r_1;
/*INC*/	if (!INC(JKFRVKRMRDWROA, arg_to)) goto sentence_after_1;
	if (! isSymbolType(JKFRVKRMRDWROA.container->type)) goto sentence_after_1;
/*SET*/	r_2 = JKFRVKRMRDWROA;
//// [ empty ] 
/*ISEMPTY*/	if (r_2!=0 && arg_to != r_2) goto sentence_after_1;

// подготовка подстановки 
result->append(newRefText("1=")); 
DataChain* AMQELRWBGBIJIL = new DataChain(); 
result->append(newRefExecBrackets(Div, AMQELRWBGBIJIL, "Div")); 
AMQELRWBGBIJIL->append_copy(l_1, r_1); 
AMQELRWBGBIJIL->append_copy(l_2, r_2); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor NHIIULLTOVBEFL;
/*DEF*/	DataCursor l_zn;
/*DEF*/	DataCursor r_zn;
/*SET*/	l_zn = arg_from;
/*SET*/	NHIIULLTOVBEFL = arg_from;
/*INC*/	if (!INC(NHIIULLTOVBEFL, arg_to)) goto sentence_after_2;
	if (! isSymbolType(NHIIULLTOVBEFL.container->type)) goto sentence_after_2;
/*SET*/	r_zn = NHIIULLTOVBEFL;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor WLPBHYFFHBAVHF;
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = r_zn;
/*SET*/	WLPBHYFFHBAVHF = r_zn;
/*INC*/	if (!INC(WLPBHYFFHBAVHF, arg_to)) goto sentence_after_2;
	if (! isSymbolType(WLPBHYFFHBAVHF.container->type)) goto sentence_after_2;
/*SET*/	r_1 = WLPBHYFFHBAVHF;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor UAHLINDJDFPEKX;
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = r_1;
/*SET*/	UAHLINDJDFPEKX = r_1;
/*INC*/	if (!INC(UAHLINDJDFPEKX, arg_to)) goto sentence_after_2;
	if (! isSymbolType(UAHLINDJDFPEKX.container->type)) goto sentence_after_2;
/*SET*/	r_2 = UAHLINDJDFPEKX;
//// [ empty ] 
/*ISEMPTY*/	if (r_2!=0 && arg_to != r_2) goto sentence_after_2;

// подготовка подстановки 
result->append(newRefText("1=")); 
DataChain* GLIXLAXXTOLHGL = new DataChain(); 
result->append(newRefExecBrackets(Div, GLIXLAXXTOLHGL, "Div")); 
GLIXLAXXTOLHGL->append_copy(l_2, r_2); 
GLIXLAXXTOLHGL->append_copy(l_1, r_1); 

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
/*DEF*/	DataCursor VWXKYVULCYJEFL;
/*SET*/	VWXKYVULCYJEFL = arg_from;
/*INC*/	if (!INC(VWXKYVULCYJEFL, arg_to)) goto sentence_after_1;
	if (VWXKYVULCYJEFL.container->type != text || *(VWXKYVULCYJEFL.container->value.text + VWXKYVULCYJEFL.index) != '1') goto sentence_after_1;
//// [ empty ] 
/*ISEMPTY*/	if (VWXKYVULCYJEFL!=0 && arg_to != VWXKYVULCYJEFL) goto sentence_after_1;

// подготовка подстановки 
result->append(newRefText("2")); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor UUGNROTLOTCPBN;
/*SET*/	UUGNROTLOTCPBN = arg_from;
/*INC*/	if (!INC(UUGNROTLOTCPBN, arg_to)) goto sentence_after_2;
	if (UUGNROTLOTCPBN.container->type != text || *(UUGNROTLOTCPBN.container->value.text + UUGNROTLOTCPBN.index) != '2') goto sentence_after_2;
//// [ empty ] 
/*ISEMPTY*/	if (UUGNROTLOTCPBN!=0 && arg_to != UUGNROTLOTCPBN) goto sentence_after_2;

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
DataChain* VEGHMFBMVKLSQF = new DataChain(); 
result->append(newRefExecBrackets(Print, VEGHMFBMVKLSQF, "Print")); 
VEGHMFBMVKLSQF->append(newRefText("NextPl uncn.: ")); 
VEGHMFBMVKLSQF->append_copy(l_e, r_e); 

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
DataChain* UBVXCTEPVMLJOH = new DataChain(); 
result->append(newRefExecBrackets(Optima211, UBVXCTEPVMLJOH, "Optima211")); 
UBVXCTEPVMLJOH->append_copy(l_e, r_e); 

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
/*JMP*/	goto label_ZXXOOLNVLAYGUO_firststep;
label_ZXXOOLNVLAYGUO: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_1;
label_ZXXOOLNVLAYGUO_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor KQDAUPTYVJAFZZ;
/*SET*/	KQDAUPTYVJAFZZ = r_1;
/*INC*/	if (!INC(KQDAUPTYVJAFZZ, arg_to)) goto label_ZXXOOLNVLAYGUO;
	if (KQDAUPTYVJAFZZ.container->type != text || *(KQDAUPTYVJAFZZ.container->value.text + KQDAUPTYVJAFZZ.index) != '1') goto label_ZXXOOLNVLAYGUO;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = KQDAUPTYVJAFZZ;
/*SET*/	r_2 = KQDAUPTYVJAFZZ;
/*JMP*/	goto label_KQTAXJLRBRUKKK_firststep;
label_KQTAXJLRBRUKKK: 
/*INC*/	if (!INC(r_2, arg_to)) goto label_ZXXOOLNVLAYGUO;
label_KQTAXJLRBRUKKK_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor IGJMXQRBAZLPDE;
/*SET*/	IGJMXQRBAZLPDE = r_2;
/*INC*/	if (!INC(IGJMXQRBAZLPDE, arg_to)) goto label_KQTAXJLRBRUKKK;
	if (IGJMXQRBAZLPDE.container->type != text || *(IGJMXQRBAZLPDE.container->value.text + IGJMXQRBAZLPDE.index) != '1') goto label_KQTAXJLRBRUKKK;
//// [ e.1 ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = IGJMXQRBAZLPDE;
/*SET*/	r_3 = arg_to;

// подготовка подстановки 
result->append(newRefText("11")); 
DataChain* QUYXPIXQIREUQA = new DataChain(); 
result->append(newRefExecBrackets(Optima211, QUYXPIXQIREUQA, "Optima211")); 
QUYXPIXQIREUQA->append_copy(l_1, r_1); 
QUYXPIXQIREUQA->append_copy(l_3, r_3); 
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
/*JMP*/	goto label_MFFSVVNTGUXESI_firststep;
label_MFFSVVNTGUXESI: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_2;
label_MFFSVVNTGUXESI_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor DRNWWTQKDOZFPK;
/*SET*/	DRNWWTQKDOZFPK = r_1;
/*INC*/	if (!INC(DRNWWTQKDOZFPK, arg_to)) goto label_MFFSVVNTGUXESI;
	if (DRNWWTQKDOZFPK.container->type != text || *(DRNWWTQKDOZFPK.container->value.text + DRNWWTQKDOZFPK.index) != '1') goto label_MFFSVVNTGUXESI;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = DRNWWTQKDOZFPK;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("1")); 
DataChain* BKUREHRQBBXAJE = new DataChain(); 
result->append(newRefExecBrackets(Optima211, BKUREHRQBBXAJE, "Optima211")); 
BKUREHRQBBXAJE->append_copy(l_1, r_1); 
BKUREHRQBBXAJE->append_copy(l_2, r_2); 

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
DataChain* FBFHKZBPKAPBSZ = new DataChain(); 
result->append(newRefExecBrackets(Prout, FBFHKZBPKAPBSZ, "Prout")); 
FBFHKZBPKAPBSZ->append(newRefWord("Strategy:")); 
FBFHKZBPKAPBSZ->append_copy(l_e, r_e); 
DataChain* YSPDAAOXRAOJOT = new DataChain(); 
result->append(newRefExecBrackets(Strategy__, YSPDAAOXRAOJOT, "Strategy__")); 
YSPDAAOXRAOJOT->append_copy(l_e, r_e); 

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
/*JMP*/	goto label_JUFSTURTJHUDPE_firststep;
label_JUFSTURTJHUDPE: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_2;
label_JUFSTURTJHUDPE_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor TSGRZUIGUSNWLY;
/*SET*/	TSGRZUIGUSNWLY = r_1;
/*INC*/	if (!INC(TSGRZUIGUSNWLY, arg_to)) goto label_JUFSTURTJHUDPE;
	if (TSGRZUIGUSNWLY.container->type != text || *(TSGRZUIGUSNWLY.container->value.text + TSGRZUIGUSNWLY.index) != '1') goto label_JUFSTURTJHUDPE;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = TSGRZUIGUSNWLY;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("147")); 
DataChain* FQTDVTNLEWFQUU = new DataChain(); 
result->append(newRefExecBrackets(Strategy, FQTDVTNLEWFQUU, "Strategy")); 
FQTDVTNLEWFQUU->append_copy(l_1, r_1); 
FQTDVTNLEWFQUU->append_copy(l_2, r_2); 

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
/*JMP*/	goto label_HTAINKEBBVZHTQ_firststep;
label_HTAINKEBBVZHTQ: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_3;
label_HTAINKEBBVZHTQ_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor BKDBMVHBSNJBTV;
/*SET*/	BKDBMVHBSNJBTV = r_1;
/*INC*/	if (!INC(BKDBMVHBSNJBTV, arg_to)) goto label_HTAINKEBBVZHTQ;
	if (BKDBMVHBSNJBTV.container->type != text || *(BKDBMVHBSNJBTV.container->value.text + BKDBMVHBSNJBTV.index) != '2') goto label_HTAINKEBBVZHTQ;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = BKDBMVHBSNJBTV;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("15")); 
DataChain* SMXVFJTVQUITIV = new DataChain(); 
result->append(newRefExecBrackets(Strategy, SMXVFJTVQUITIV, "Strategy")); 
SMXVFJTVQUITIV->append_copy(l_1, r_1); 
SMXVFJTVQUITIV->append_copy(l_2, r_2); 

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
/*JMP*/	goto label_YHZPXCDJWIKFAT_firststep;
label_YHZPXCDJWIKFAT: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_4;
label_YHZPXCDJWIKFAT_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor CANCHXSSJLUHLY;
/*SET*/	CANCHXSSJLUHLY = r_1;
/*INC*/	if (!INC(CANCHXSSJLUHLY, arg_to)) goto label_YHZPXCDJWIKFAT;
	if (CANCHXSSJLUHLY.container->type != text || *(CANCHXSSJLUHLY.container->value.text + CANCHXSSJLUHLY.index) != '3') goto label_YHZPXCDJWIKFAT;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = CANCHXSSJLUHLY;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("168")); 
DataChain* LIUEJOBCFPVNYR = new DataChain(); 
result->append(newRefExecBrackets(Strategy, LIUEJOBCFPVNYR, "Strategy")); 
LIUEJOBCFPVNYR->append_copy(l_1, r_1); 
LIUEJOBCFPVNYR->append_copy(l_2, r_2); 

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
/*JMP*/	goto label_RPKEGEQPVLHXEE_firststep;
label_RPKEGEQPVLHXEE: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_5;
label_RPKEGEQPVLHXEE_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor OCMERJMZIUDTSQ;
/*SET*/	OCMERJMZIUDTSQ = r_1;
/*INC*/	if (!INC(OCMERJMZIUDTSQ, arg_to)) goto label_RPKEGEQPVLHXEE;
	if (OCMERJMZIUDTSQ.container->type != text || *(OCMERJMZIUDTSQ.container->value.text + OCMERJMZIUDTSQ.index) != '4') goto label_RPKEGEQPVLHXEE;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = OCMERJMZIUDTSQ;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("24")); 
DataChain* EPFQDSMVSTMMWW = new DataChain(); 
result->append(newRefExecBrackets(Strategy, EPFQDSMVSTMMWW, "Strategy")); 
EPFQDSMVSTMMWW->append_copy(l_1, r_1); 
EPFQDSMVSTMMWW->append_copy(l_2, r_2); 

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
/*JMP*/	goto label_WQKNNRMQMJCCPA_firststep;
label_WQKNNRMQMJCCPA: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_6;
label_WQKNNRMQMJCCPA_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor OWAZFEURGPBFRY;
/*SET*/	OWAZFEURGPBFRY = r_1;
/*INC*/	if (!INC(OWAZFEURGPBFRY, arg_to)) goto label_WQKNNRMQMJCCPA;
	if (OWAZFEURGPBFRY.container->type != text || *(OWAZFEURGPBFRY.container->value.text + OWAZFEURGPBFRY.index) != '5') goto label_WQKNNRMQMJCCPA;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = OWAZFEURGPBFRY;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("2578")); 
DataChain* ICWUOHFEREBEAC = new DataChain(); 
result->append(newRefExecBrackets(Strategy, ICWUOHFEREBEAC, "Strategy")); 
ICWUOHFEREBEAC->append_copy(l_1, r_1); 
ICWUOHFEREBEAC->append_copy(l_2, r_2); 

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
/*JMP*/	goto label_AZUVJOXYIPMSGU_firststep;
label_AZUVJOXYIPMSGU: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_7;
label_AZUVJOXYIPMSGU_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor FJIWLCFYWXTEYY;
/*SET*/	FJIWLCFYWXTEYY = r_1;
/*INC*/	if (!INC(FJIWLCFYWXTEYY, arg_to)) goto label_AZUVJOXYIPMSGU;
	if (FJIWLCFYWXTEYY.container->type != text || *(FJIWLCFYWXTEYY.container->value.text + FJIWLCFYWXTEYY.index) != '6') goto label_AZUVJOXYIPMSGU;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = FJIWLCFYWXTEYY;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("26")); 
DataChain* YOXBSCEFTDRQEL = new DataChain(); 
result->append(newRefExecBrackets(Strategy, YOXBSCEFTDRQEL, "Strategy")); 
YOXBSCEFTDRQEL->append_copy(l_1, r_1); 
YOXBSCEFTDRQEL->append_copy(l_2, r_2); 

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
/*JMP*/	goto label_XFVCFBBJJYFSVK_firststep;
label_XFVCFBBJJYFSVK: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_8;
label_XFVCFBBJJYFSVK_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor VSAPDSHAKGDVHC;
/*SET*/	VSAPDSHAKGDVHC = r_1;
/*INC*/	if (!INC(VSAPDSHAKGDVHC, arg_to)) goto label_XFVCFBBJJYFSVK;
	if (VSAPDSHAKGDVHC.container->type != text || *(VSAPDSHAKGDVHC.container->value.text + VSAPDSHAKGDVHC.index) != '7') goto label_XFVCFBBJJYFSVK;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = VSAPDSHAKGDVHC;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("348")); 
DataChain* ASQKAUQLNFHGGT = new DataChain(); 
result->append(newRefExecBrackets(Strategy, ASQKAUQLNFHGGT, "Strategy")); 
ASQKAUQLNFHGGT->append_copy(l_1, r_1); 
ASQKAUQLNFHGGT->append_copy(l_2, r_2); 

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
/*JMP*/	goto label_AGRNFFMNPINWLE_firststep;
label_AGRNFFMNPINWLE: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_9;
label_AGRNFFMNPINWLE_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor XRQXISBFNHJZQV;
/*SET*/	XRQXISBFNHJZQV = r_1;
/*INC*/	if (!INC(XRQXISBFNHJZQV, arg_to)) goto label_AGRNFFMNPINWLE;
	if (XRQXISBFNHJZQV.container->type != text || *(XRQXISBFNHJZQV.container->value.text + XRQXISBFNHJZQV.index) != '8') goto label_AGRNFFMNPINWLE;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = XRQXISBFNHJZQV;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("35")); 
DataChain* BACPJZSNACLMNU = new DataChain(); 
result->append(newRefExecBrackets(Strategy, BACPJZSNACLMNU, "Strategy")); 
BACPJZSNACLMNU->append_copy(l_1, r_1); 
BACPJZSNACLMNU->append_copy(l_2, r_2); 

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
/*JMP*/	goto label_QNBDIFZLUJQVNF_firststep;
label_QNBDIFZLUJQVNF: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_10;
label_QNBDIFZLUJQVNF_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor JXXVKCZFKZZJQN;
/*SET*/	JXXVKCZFKZZJQN = r_1;
/*INC*/	if (!INC(JXXVKCZFKZZJQN, arg_to)) goto label_QNBDIFZLUJQVNF;
	if (JXXVKCZFKZZJQN.container->type != text || *(JXXVKCZFKZZJQN.container->value.text + JXXVKCZFKZZJQN.index) != '9') goto label_QNBDIFZLUJQVNF;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = JXXVKCZFKZZJQN;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("367")); 
DataChain* RSOSYQHQUHKJCJ = new DataChain(); 
result->append(newRefExecBrackets(Strategy, RSOSYQHQUHKJCJ, "Strategy")); 
RSOSYQHQUHKJCJ->append_copy(l_1, r_1); 
RSOSYQHQUHKJCJ->append_copy(l_2, r_2); 

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
/*DEF*/	DataCursor YUGTEDOGFURKXI;
/*DEF*/	DataCursor YQUFOTIAJMWHYI;
/*DEF*/	DataCursor LTHMOEVLWLRXPW;
/*SET*/	YUGTEDOGFURKXI = arg_from;
/*INC*/	if (!INC(YUGTEDOGFURKXI, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (YUGTEDOGFURKXI.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	YQUFOTIAJMWHYI = YUGTEDOGFURKXI.container->value.bracket_data.chain->at_before_first();
	LTHMOEVLWLRXPW   = YUGTEDOGFURKXI.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = YQUFOTIAJMWHYI;
/*SET*/	r_1 = LTHMOEVLWLRXPW;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor PZHSVBFZVTVHWY;
/*DEF*/	DataCursor CFZNMAOMAFSYVY;
/*DEF*/	DataCursor RQPIZTEUOXGTHF;
/*SET*/	PZHSVBFZVTVHWY = YUGTEDOGFURKXI;
/*INC*/	if (!INC(PZHSVBFZVTVHWY, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (PZHSVBFZVTVHWY.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	CFZNMAOMAFSYVY = PZHSVBFZVTVHWY.container->value.bracket_data.chain->at_before_first();
	RQPIZTEUOXGTHF   = PZHSVBFZVTVHWY.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = CFZNMAOMAFSYVY;
/*SET*/	r_2 = RQPIZTEUOXGTHF;
//// [ empty ] 
/*ISEMPTY*/	if (PZHSVBFZVTVHWY!=0 && arg_to != PZHSVBFZVTVHWY) goto sentence_after_1;

// подготовка подстановки 
DataChain* XSMXJRWPSURSGW = new DataChain(); 
result->append(newRefExecBrackets(Ifwin1, XSMXJRWPSURSGW, "Ifwin1")); 
DataChain* THHILGDHZFZAXA = new DataChain(); 
XSMXJRWPSURSGW->append(newRefStructBrackets(THHILGDHZFZAXA)); 
DataChain* DTKLHYHQZFDIMS = new DataChain(); 
THHILGDHZFZAXA->append(newRefExecBrackets(Strategy, DTKLHYHQZFDIMS, "Strategy")); 
DTKLHYHQZFDIMS->append_copy(l_1, r_1); 
DataChain* RUEECXKQKRUDLM = new DataChain(); 
XSMXJRWPSURSGW->append(newRefStructBrackets(RUEECXKQKRUDLM)); 
DataChain* ZGDTNHMIVNNKCL = new DataChain(); 
RUEECXKQKRUDLM->append(newRefExecBrackets(Strategy, ZGDTNHMIVNNKCL, "Strategy")); 
ZGDTNHMIVNNKCL->append_copy(l_2, r_2); 

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
/*DEF*/	DataCursor GARYGYDQDHLTRS;
/*DEF*/	DataCursor THIDZYQAZFNOVK;
/*DEF*/	DataCursor TQCOTCHCOLINEI;
/*SET*/	GARYGYDQDHLTRS = arg_from;
/*INC*/	if (!INC(GARYGYDQDHLTRS, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (GARYGYDQDHLTRS.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	THIDZYQAZFNOVK = GARYGYDQDHLTRS.container->value.bracket_data.chain->at_before_first();
	TQCOTCHCOLINEI   = GARYGYDQDHLTRS.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = THIDZYQAZFNOVK;
/*SET*/	r_1 = THIDZYQAZFNOVK;
/*JMP*/	goto label_YTYMRJSCYOEIVD_firststep;
label_YTYMRJSCYOEIVD: 
/*INC*/	if (!INC(r_1, TQCOTCHCOLINEI)) goto sentence_after_1;
label_YTYMRJSCYOEIVD_firststep: 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor YHPHLJZHEZOHMI;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_1;
/*SET*/	YHPHLJZHEZOHMI = r_1;
/*INC*/	if (!INC(YHPHLJZHEZOHMI, TQCOTCHCOLINEI)) goto label_YTYMRJSCYOEIVD;
	if (! isSymbolType(YHPHLJZHEZOHMI.container->type)) goto label_YTYMRJSCYOEIVD;
/*SET*/	r_A = YHPHLJZHEZOHMI;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = r_A;
/*SET*/	r_2 = r_A;
/*JMP*/	goto label_URCPBLVWAAJIQU_firststep;
label_URCPBLVWAAJIQU: 
/*INC*/	if (!INC(r_2, TQCOTCHCOLINEI)) goto label_YTYMRJSCYOEIVD;
label_URCPBLVWAAJIQU_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor GTAOQMEMJLHGOX;
/*SET*/	GTAOQMEMJLHGOX = r_2;
 if (!SLIDE(GTAOQMEMJLHGOX, TQCOTCHCOLINEI, l_A, r_A)) goto label_URCPBLVWAAJIQU;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = GTAOQMEMJLHGOX;
/*SET*/	r_3 = GTAOQMEMJLHGOX;
/*JMP*/	goto label_PRURTYMKKTDBNO_firststep;
label_PRURTYMKKTDBNO: 
/*INC*/	if (!INC(r_3, TQCOTCHCOLINEI)) goto label_URCPBLVWAAJIQU;
label_PRURTYMKKTDBNO_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor XWTTGEEQIMLHCZ;
/*SET*/	XWTTGEEQIMLHCZ = r_3;
 if (!SLIDE(XWTTGEEQIMLHCZ, TQCOTCHCOLINEI, l_A, r_A)) goto label_PRURTYMKKTDBNO;
//// [ e.1 ] 
/*DEF*/	DataCursor l_4;
/*DEF*/	DataCursor r_4;
/*SET*/	l_4 = XWTTGEEQIMLHCZ;
/*SET*/	r_4 = TQCOTCHCOLINEI;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor TCTYPHMEQDSUYV;
/*DEF*/	DataCursor KKJOPLMZDCAKPJ;
/*DEF*/	DataCursor VOZIMHXXQHDUIQ;
/*SET*/	TCTYPHMEQDSUYV = GARYGYDQDHLTRS;
/*INC*/	if (!INC(TCTYPHMEQDSUYV, arg_to)) goto label_PRURTYMKKTDBNO;
//// ISBRACKET 
	if (TCTYPHMEQDSUYV.container->type != struct_bracket) goto label_PRURTYMKKTDBNO;
//// JMP_BRACKET 
	KKJOPLMZDCAKPJ = TCTYPHMEQDSUYV.container->value.bracket_data.chain->at_before_first();
	VOZIMHXXQHDUIQ   = TCTYPHMEQDSUYV.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = KKJOPLMZDCAKPJ;
/*SET*/	r_e = VOZIMHXXQHDUIQ;
//// [ empty ] 
/*ISEMPTY*/	if (TCTYPHMEQDSUYV!=0 && arg_to != TCTYPHMEQDSUYV) goto label_PRURTYMKKTDBNO;

// подготовка подстановки 
result->append(newRefText("1")); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor EDLNGWGOOOUPNE;
/*DEF*/	DataCursor DKSDGPMHHDAQBS;
/*DEF*/	DataCursor QRFPDRSYKHBUTS;
/*SET*/	EDLNGWGOOOUPNE = arg_from;
/*INC*/	if (!INC(EDLNGWGOOOUPNE, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (EDLNGWGOOOUPNE.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	DKSDGPMHHDAQBS = EDLNGWGOOOUPNE.container->value.bracket_data.chain->at_before_first();
	QRFPDRSYKHBUTS   = EDLNGWGOOOUPNE.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = DKSDGPMHHDAQBS;
/*SET*/	r_e = QRFPDRSYKHBUTS;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor NUWJPPGDEEBJGS;
/*DEF*/	DataCursor DYFOECQQNLEMKI;
/*DEF*/	DataCursor MIPECEHLBTMBWN;
/*SET*/	NUWJPPGDEEBJGS = EDLNGWGOOOUPNE;
/*INC*/	if (!INC(NUWJPPGDEEBJGS, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (NUWJPPGDEEBJGS.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	DYFOECQQNLEMKI = NUWJPPGDEEBJGS.container->value.bracket_data.chain->at_before_first();
	MIPECEHLBTMBWN   = NUWJPPGDEEBJGS.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = DYFOECQQNLEMKI;
/*SET*/	r_1 = DYFOECQQNLEMKI;
/*JMP*/	goto label_KDXYMECLSSHVKM_firststep;
label_KDXYMECLSSHVKM: 
/*INC*/	if (!INC(r_1, MIPECEHLBTMBWN)) goto sentence_after_2;
label_KDXYMECLSSHVKM_firststep: 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor YWJXESHOIHMLGV;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_1;
/*SET*/	YWJXESHOIHMLGV = r_1;
/*INC*/	if (!INC(YWJXESHOIHMLGV, MIPECEHLBTMBWN)) goto label_KDXYMECLSSHVKM;
	if (! isSymbolType(YWJXESHOIHMLGV.container->type)) goto label_KDXYMECLSSHVKM;
/*SET*/	r_A = YWJXESHOIHMLGV;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = r_A;
/*SET*/	r_2 = r_A;
/*JMP*/	goto label_XILJVWLLFPNJZY_firststep;
label_XILJVWLLFPNJZY: 
/*INC*/	if (!INC(r_2, MIPECEHLBTMBWN)) goto label_KDXYMECLSSHVKM;
label_XILJVWLLFPNJZY_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor WCPAMEVWTYGFPH;
/*SET*/	WCPAMEVWTYGFPH = r_2;
 if (!SLIDE(WCPAMEVWTYGFPH, MIPECEHLBTMBWN, l_A, r_A)) goto label_XILJVWLLFPNJZY;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = WCPAMEVWTYGFPH;
/*SET*/	r_3 = WCPAMEVWTYGFPH;
/*JMP*/	goto label_IFUBTTNWNPHDBY_firststep;
label_IFUBTTNWNPHDBY: 
/*INC*/	if (!INC(r_3, MIPECEHLBTMBWN)) goto label_XILJVWLLFPNJZY;
label_IFUBTTNWNPHDBY_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor TWODCLRJPRSEQW;
/*SET*/	TWODCLRJPRSEQW = r_3;
 if (!SLIDE(TWODCLRJPRSEQW, MIPECEHLBTMBWN, l_A, r_A)) goto label_IFUBTTNWNPHDBY;
//// [ e.1 ] 
/*DEF*/	DataCursor l_4;
/*DEF*/	DataCursor r_4;
/*SET*/	l_4 = TWODCLRJPRSEQW;
/*SET*/	r_4 = MIPECEHLBTMBWN;
//// [ empty ] 
/*ISEMPTY*/	if (NUWJPPGDEEBJGS!=0 && arg_to != NUWJPPGDEEBJGS) goto label_IFUBTTNWNPHDBY;

// подготовка подстановки 
result->append(newRefText("2")); 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor RDWSVYNCGFRAZZ;
/*DEF*/	DataCursor AODGGXWWBTJQUJ;
/*DEF*/	DataCursor RMCDPOMJRYLEDH;
/*SET*/	RDWSVYNCGFRAZZ = arg_from;
/*INC*/	if (!INC(RDWSVYNCGFRAZZ, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (RDWSVYNCGFRAZZ.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	AODGGXWWBTJQUJ = RDWSVYNCGFRAZZ.container->value.bracket_data.chain->at_before_first();
	RMCDPOMJRYLEDH   = RDWSVYNCGFRAZZ.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = AODGGXWWBTJQUJ;
/*SET*/	r_1 = RMCDPOMJRYLEDH;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor UFHWKHZKTNKYTG;
/*DEF*/	DataCursor JPMMGVXJCNJGZU;
/*DEF*/	DataCursor HWQQSLDZCSFOJS;
/*SET*/	UFHWKHZKTNKYTG = RDWSVYNCGFRAZZ;
/*INC*/	if (!INC(UFHWKHZKTNKYTG, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (UFHWKHZKTNKYTG.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	JPMMGVXJCNJGZU = UFHWKHZKTNKYTG.container->value.bracket_data.chain->at_before_first();
	HWQQSLDZCSFOJS   = UFHWKHZKTNKYTG.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = JPMMGVXJCNJGZU;
/*SET*/	r_2 = HWQQSLDZCSFOJS;
//// [ empty ] 
/*ISEMPTY*/	if (UFHWKHZKTNKYTG!=0 && arg_to != UFHWKHZKTNKYTG) goto sentence_after_3;

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
DataChain* WRQCNBQYXAAGIB = new DataChain(); 
result->append(newRefExecBrackets(Prout, WRQCNBQYXAAGIB, "Prout")); 
WRQCNBQYXAAGIB->append(newRefWord("Analiz:")); 
WRQCNBQYXAAGIB->append_copy(l_e, r_e); 
DataChain* PVTXDONPEASHNR = new DataChain(); 
result->append(newRefExecBrackets(Analiz__, PVTXDONPEASHNR, "Analiz__")); 
PVTXDONPEASHNR->append_copy(l_e, r_e); 

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
/*JMP*/	goto label_OHUVOGLDXHSPRN_firststep;
label_OHUVOGLDXHSPRN: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_1;
label_OHUVOGLDXHSPRN_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor GSOQDJFQTEXYRW;
/*DEF*/	DataCursor IZZOEOWAQEZDLM;
/*DEF*/	DataCursor WAFCOZVQCIEWGK;
/*SET*/	GSOQDJFQTEXYRW = r_1;
/*INC*/	if (!INC(GSOQDJFQTEXYRW, arg_to)) goto label_OHUVOGLDXHSPRN;
//// ISBRACKET 
	if (GSOQDJFQTEXYRW.container->type != struct_bracket) goto label_OHUVOGLDXHSPRN;
//// JMP_BRACKET 
	IZZOEOWAQEZDLM = GSOQDJFQTEXYRW.container->value.bracket_data.chain->at_before_first();
	WAFCOZVQCIEWGK   = GSOQDJFQTEXYRW.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = IZZOEOWAQEZDLM;
/*SET*/	r_3 = IZZOEOWAQEZDLM;
/*JMP*/	goto label_EKFGRCYVZSAHPS_firststep;
label_EKFGRCYVZSAHPS: 
/*INC*/	if (!INC(r_3, WAFCOZVQCIEWGK)) goto label_OHUVOGLDXHSPRN;
label_EKFGRCYVZSAHPS_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor ZOBRIXWXKPICLQ;
/*SET*/	ZOBRIXWXKPICLQ = r_3;
/*INC*/	if (!INC(ZOBRIXWXKPICLQ, WAFCOZVQCIEWGK)) goto label_EKFGRCYVZSAHPS;
	if (ZOBRIXWXKPICLQ.container->type != text || *(ZOBRIXWXKPICLQ.container->value.text + ZOBRIXWXKPICLQ.index) != '>') goto label_EKFGRCYVZSAHPS;
//// [ empty ] 
/*ISEMPTY*/	if (ZOBRIXWXKPICLQ!=0 && WAFCOZVQCIEWGK != ZOBRIXWXKPICLQ) goto label_EKFGRCYVZSAHPS;
//// [ empty ] 
/*ISEMPTY*/	if (GSOQDJFQTEXYRW!=0 && arg_to != GSOQDJFQTEXYRW) goto label_EKFGRCYVZSAHPS;

// подготовка подстановки 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor BCWLFKFFRLZZMK;
/*DEF*/	DataCursor VMHNLCIVWHWZTZ;
/*DEF*/	DataCursor RBXJCRTUVTXFKI;
/*SET*/	BCWLFKFFRLZZMK = arg_from;
/*INC*/	if (!INC(BCWLFKFFRLZZMK, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (BCWLFKFFRLZZMK.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	VMHNLCIVWHWZTZ = BCWLFKFFRLZZMK.container->value.bracket_data.chain->at_before_first();
	RBXJCRTUVTXFKI   = BCWLFKFFRLZZMK.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor DXHOAFYESYVIZV;
/*SET*/	DXHOAFYESYVIZV = VMHNLCIVWHWZTZ;
/*INC*/	if (!INC(DXHOAFYESYVIZV, RBXJCRTUVTXFKI)) goto sentence_after_2;
	if (DXHOAFYESYVIZV.container->type != text || *(DXHOAFYESYVIZV.container->value.text + DXHOAFYESYVIZV.index) != '1') goto sentence_after_2;
//// [ empty ] 
/*ISEMPTY*/	if (DXHOAFYESYVIZV!=0 && RBXJCRTUVTXFKI != DXHOAFYESYVIZV) goto sentence_after_2;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor RNERZOOWRVWPMI;
/*DEF*/	DataCursor BHHYFFUVKOUKDW;
/*DEF*/	DataCursor JCVXQGLSCHJAGQ;
/*SET*/	RNERZOOWRVWPMI = BCWLFKFFRLZZMK;
/*INC*/	if (!INC(RNERZOOWRVWPMI, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (RNERZOOWRVWPMI.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	BHHYFFUVKOUKDW = RNERZOOWRVWPMI.container->value.bracket_data.chain->at_before_first();
	JCVXQGLSCHJAGQ   = RNERZOOWRVWPMI.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = BHHYFFUVKOUKDW;
/*SET*/	r_1 = JCVXQGLSCHJAGQ;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor UEHPNHKYCPMJTG;
/*DEF*/	DataCursor LUDHRBEFJJFYTK;
/*DEF*/	DataCursor XLBNVMDWSYXHGS;
/*SET*/	UEHPNHKYCPMJTG = RNERZOOWRVWPMI;
/*INC*/	if (!INC(UEHPNHKYCPMJTG, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (UEHPNHKYCPMJTG.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	LUDHRBEFJJFYTK = UEHPNHKYCPMJTG.container->value.bracket_data.chain->at_before_first();
	XLBNVMDWSYXHGS   = UEHPNHKYCPMJTG.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = LUDHRBEFJJFYTK;
/*SET*/	r_2 = XLBNVMDWSYXHGS;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor CZHYJGDFGNWFPD;
/*DEF*/	DataCursor TLKHPEKHJNCYLC;
/*DEF*/	DataCursor QMSSYGHWDVAEQJ;
/*SET*/	CZHYJGDFGNWFPD = UEHPNHKYCPMJTG;
/*INC*/	if (!INC(CZHYJGDFGNWFPD, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (CZHYJGDFGNWFPD.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	TLKHPEKHJNCYLC = CZHYJGDFGNWFPD.container->value.bracket_data.chain->at_before_first();
	QMSSYGHWDVAEQJ   = CZHYJGDFGNWFPD.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = TLKHPEKHJNCYLC;
/*SET*/	r_3 = TLKHPEKHJNCYLC;
/*JMP*/	goto label_KZMHIYDLXDJOHN_firststep;
label_KZMHIYDLXDJOHN: 
/*INC*/	if (!INC(r_3, QMSSYGHWDVAEQJ)) goto sentence_after_2;
label_KZMHIYDLXDJOHN_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor SCGHBTUSWZUMSQ;
/*SET*/	SCGHBTUSWZUMSQ = r_3;
/*INC*/	if (!INC(SCGHBTUSWZUMSQ, QMSSYGHWDVAEQJ)) goto label_KZMHIYDLXDJOHN;
	if (SCGHBTUSWZUMSQ.container->type != text || *(SCGHBTUSWZUMSQ.container->value.text + SCGHBTUSWZUMSQ.index) != '>') goto label_KZMHIYDLXDJOHN;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor OYKIIDFWFXYAAA;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = SCGHBTUSWZUMSQ;
/*SET*/	OYKIIDFWFXYAAA = SCGHBTUSWZUMSQ;
/*INC*/	if (!INC(OYKIIDFWFXYAAA, QMSSYGHWDVAEQJ)) goto label_KZMHIYDLXDJOHN;
	if (! isSymbolType(OYKIIDFWFXYAAA.container->type)) goto label_KZMHIYDLXDJOHN;
/*SET*/	r_A = OYKIIDFWFXYAAA;
//// [ e.1 ] 
/*DEF*/	DataCursor l_4;
/*DEF*/	DataCursor r_4;
/*SET*/	l_4 = r_A;
/*SET*/	r_4 = QMSSYGHWDVAEQJ;
//// [ empty ] 
/*ISEMPTY*/	if (CZHYJGDFGNWFPD!=0 && arg_to != CZHYJGDFGNWFPD) goto label_KZMHIYDLXDJOHN;

// подготовка подстановки 
DataChain* AWGEURBRNBERAZ = new DataChain(); 
result->append(newRefExecBrackets(PolnAnaliz, AWGEURBRNBERAZ, "PolnAnaliz")); 
DataChain* SXTKAQUEHJFCEW = new DataChain(); 
AWGEURBRNBERAZ->append(newRefStructBrackets(SXTKAQUEHJFCEW)); 
SXTKAQUEHJFCEW->append(newRefText("2")); 
DataChain* CTBFJTPQDLJHEH = new DataChain(); 
AWGEURBRNBERAZ->append(newRefStructBrackets(CTBFJTPQDLJHEH)); 
CTBFJTPQDLJHEH->append_copy(l_1, r_1); 
CTBFJTPQDLJHEH->append_copy(l_A, r_A); 
DataChain* JOBMARGUQWSOKL = new DataChain(); 
AWGEURBRNBERAZ->append(newRefStructBrackets(JOBMARGUQWSOKL)); 
JOBMARGUQWSOKL->append_copy(l_2, r_2); 
DataChain* DZSCSFACXFZXFJ = new DataChain(); 
AWGEURBRNBERAZ->append(newRefStructBrackets(DZSCSFACXFZXFJ)); 
DZSCSFACXFZXFJ->append_copy(l_3, r_3); 
DZSCSFACXFZXFJ->append_copy(l_4, r_4); 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor QOVERSCJZBKMZD;
/*DEF*/	DataCursor NDOSIYHTYAVOXH;
/*DEF*/	DataCursor TAPYEKTUATPRWS;
/*SET*/	QOVERSCJZBKMZD = arg_from;
/*INC*/	if (!INC(QOVERSCJZBKMZD, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (QOVERSCJZBKMZD.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	NDOSIYHTYAVOXH = QOVERSCJZBKMZD.container->value.bracket_data.chain->at_before_first();
	TAPYEKTUATPRWS   = QOVERSCJZBKMZD.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor KXZCZNFDIUEHUW;
/*SET*/	KXZCZNFDIUEHUW = NDOSIYHTYAVOXH;
/*INC*/	if (!INC(KXZCZNFDIUEHUW, TAPYEKTUATPRWS)) goto sentence_after_3;
	if (KXZCZNFDIUEHUW.container->type != text || *(KXZCZNFDIUEHUW.container->value.text + KXZCZNFDIUEHUW.index) != '2') goto sentence_after_3;
//// [ empty ] 
/*ISEMPTY*/	if (KXZCZNFDIUEHUW!=0 && TAPYEKTUATPRWS != KXZCZNFDIUEHUW) goto sentence_after_3;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor KVUTKFIUBZYBLW;
/*DEF*/	DataCursor MPARMJDSPXYWXE;
/*DEF*/	DataCursor RFTZLKORIEBSUP;
/*SET*/	KVUTKFIUBZYBLW = QOVERSCJZBKMZD;
/*INC*/	if (!INC(KVUTKFIUBZYBLW, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (KVUTKFIUBZYBLW.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	MPARMJDSPXYWXE = KVUTKFIUBZYBLW.container->value.bracket_data.chain->at_before_first();
	RFTZLKORIEBSUP   = KVUTKFIUBZYBLW.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = MPARMJDSPXYWXE;
/*SET*/	r_1 = RFTZLKORIEBSUP;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor CPXCJWKUVEEREN;
/*DEF*/	DataCursor LAITVYCICYZALW;
/*DEF*/	DataCursor UIUZTEYCTMUIFE;
/*SET*/	CPXCJWKUVEEREN = KVUTKFIUBZYBLW;
/*INC*/	if (!INC(CPXCJWKUVEEREN, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (CPXCJWKUVEEREN.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	LAITVYCICYZALW = CPXCJWKUVEEREN.container->value.bracket_data.chain->at_before_first();
	UIUZTEYCTMUIFE   = CPXCJWKUVEEREN.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = LAITVYCICYZALW;
/*SET*/	r_2 = UIUZTEYCTMUIFE;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor FYGAIAIOIIEDBY;
/*DEF*/	DataCursor WRGRTDXVDKOCSA;
/*DEF*/	DataCursor EHFCILQJOEVAJN;
/*SET*/	FYGAIAIOIIEDBY = CPXCJWKUVEEREN;
/*INC*/	if (!INC(FYGAIAIOIIEDBY, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (FYGAIAIOIIEDBY.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	WRGRTDXVDKOCSA = FYGAIAIOIIEDBY.container->value.bracket_data.chain->at_before_first();
	EHFCILQJOEVAJN   = FYGAIAIOIIEDBY.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = WRGRTDXVDKOCSA;
/*SET*/	r_3 = WRGRTDXVDKOCSA;
/*JMP*/	goto label_JTTKNRSPRTKRLK_firststep;
label_JTTKNRSPRTKRLK: 
/*INC*/	if (!INC(r_3, EHFCILQJOEVAJN)) goto sentence_after_3;
label_JTTKNRSPRTKRLK_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor JAPYMUZRPHZLCE;
/*SET*/	JAPYMUZRPHZLCE = r_3;
/*INC*/	if (!INC(JAPYMUZRPHZLCE, EHFCILQJOEVAJN)) goto label_JTTKNRSPRTKRLK;
	if (JAPYMUZRPHZLCE.container->type != text || *(JAPYMUZRPHZLCE.container->value.text + JAPYMUZRPHZLCE.index) != '>') goto label_JTTKNRSPRTKRLK;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor PAYTFAVEOPSZRN;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = JAPYMUZRPHZLCE;
/*SET*/	PAYTFAVEOPSZRN = JAPYMUZRPHZLCE;
/*INC*/	if (!INC(PAYTFAVEOPSZRN, EHFCILQJOEVAJN)) goto label_JTTKNRSPRTKRLK;
	if (! isSymbolType(PAYTFAVEOPSZRN.container->type)) goto label_JTTKNRSPRTKRLK;
/*SET*/	r_A = PAYTFAVEOPSZRN;
//// [ e.1 ] 
/*DEF*/	DataCursor l_4;
/*DEF*/	DataCursor r_4;
/*SET*/	l_4 = r_A;
/*SET*/	r_4 = EHFCILQJOEVAJN;
//// [ empty ] 
/*ISEMPTY*/	if (FYGAIAIOIIEDBY!=0 && arg_to != FYGAIAIOIIEDBY) goto label_JTTKNRSPRTKRLK;

// подготовка подстановки 
DataChain* AHORKTKMGYCOUI = new DataChain(); 
result->append(newRefExecBrackets(PolnAnaliz, AHORKTKMGYCOUI, "PolnAnaliz")); 
DataChain* ERTLPBJCSXQLGY = new DataChain(); 
AHORKTKMGYCOUI->append(newRefStructBrackets(ERTLPBJCSXQLGY)); 
ERTLPBJCSXQLGY->append(newRefText("1")); 
DataChain* GLMVLYQXIXIPVW = new DataChain(); 
AHORKTKMGYCOUI->append(newRefStructBrackets(GLMVLYQXIXIPVW)); 
GLMVLYQXIXIPVW->append_copy(l_1, r_1); 
DataChain* OQLNKAEQMARVXU = new DataChain(); 
AHORKTKMGYCOUI->append(newRefStructBrackets(OQLNKAEQMARVXU)); 
OQLNKAEQMARVXU->append_copy(l_2, r_2); 
OQLNKAEQMARVXU->append_copy(l_A, r_A); 
DataChain* MKRNJCOKVFKTQJ = new DataChain(); 
AHORKTKMGYCOUI->append(newRefStructBrackets(MKRNJCOKVFKTQJ)); 
MKRNJCOKVFKTQJ->append_copy(l_3, r_3); 
MKRNJCOKVFKTQJ->append_copy(l_4, r_4); 

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
DataChain* DCUGBIDVBXRNSA = new DataChain(); 
result->append(newRefExecBrackets(Prout, DCUGBIDVBXRNSA, "Prout")); 
DCUGBIDVBXRNSA->append(newRefText("No point: ")); 
DCUGBIDVBXRNSA->append_copy(l_e, r_e); 

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
DataChain* QWXTBFTQSNPAVY = new DataChain(); 
result->append(newRefExecBrackets(Prout, QWXTBFTQSNPAVY, "Prout")); 
QWXTBFTQSNPAVY->append(newRefWord("PolnAnaliz:")); 
QWXTBFTQSNPAVY->append_copy(l_e, r_e); 
DataChain* TODPJDPVYQXKSU = new DataChain(); 
result->append(newRefExecBrackets(PolnAnaliz__, TODPJDPVYQXKSU, "PolnAnaliz__")); 
TODPJDPVYQXKSU->append_copy(l_e, r_e); 

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
/*DEF*/	DataCursor VZWZTJRWOVTTLN;
/*DEF*/	DataCursor KZNQDQIAUAPWKC;
/*DEF*/	DataCursor ZXRXOPENEUXFLG;
/*SET*/	VZWZTJRWOVTTLN = arg_from;
/*INC*/	if (!INC(VZWZTJRWOVTTLN, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (VZWZTJRWOVTTLN.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	KZNQDQIAUAPWKC = VZWZTJRWOVTTLN.container->value.bracket_data.chain->at_before_first();
	ZXRXOPENEUXFLG   = VZWZTJRWOVTTLN.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor BDWJMHJGUZPEUD;
/*DEF*/	DataCursor l_g;
/*DEF*/	DataCursor r_g;
/*SET*/	l_g = KZNQDQIAUAPWKC;
/*SET*/	BDWJMHJGUZPEUD = KZNQDQIAUAPWKC;
/*INC*/	if (!INC(BDWJMHJGUZPEUD, ZXRXOPENEUXFLG)) goto sentence_after_1;
	if (! isSymbolType(BDWJMHJGUZPEUD.container->type)) goto sentence_after_1;
/*SET*/	r_g = BDWJMHJGUZPEUD;
//// [ empty ] 
/*ISEMPTY*/	if (r_g!=0 && ZXRXOPENEUXFLG != r_g) goto sentence_after_1;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor DFEIMOZYFRQMFO;
/*DEF*/	DataCursor ZISSCCRIFWQBHX;
/*DEF*/	DataCursor YEHKTUSDGZXLAE;
/*SET*/	DFEIMOZYFRQMFO = VZWZTJRWOVTTLN;
/*INC*/	if (!INC(DFEIMOZYFRQMFO, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (DFEIMOZYFRQMFO.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	ZISSCCRIFWQBHX = DFEIMOZYFRQMFO.container->value.bracket_data.chain->at_before_first();
	YEHKTUSDGZXLAE   = DFEIMOZYFRQMFO.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = ZISSCCRIFWQBHX;
/*SET*/	r_1 = YEHKTUSDGZXLAE;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor YKEXQGQOEVJTFR;
/*DEF*/	DataCursor AMUQGBDNRSMBXR;
/*DEF*/	DataCursor VBTFGLOWFFCTUJ;
/*SET*/	YKEXQGQOEVJTFR = DFEIMOZYFRQMFO;
/*INC*/	if (!INC(YKEXQGQOEVJTFR, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (YKEXQGQOEVJTFR.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	AMUQGBDNRSMBXR = YKEXQGQOEVJTFR.container->value.bracket_data.chain->at_before_first();
	VBTFGLOWFFCTUJ   = YKEXQGQOEVJTFR.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = AMUQGBDNRSMBXR;
/*SET*/	r_2 = VBTFGLOWFFCTUJ;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor TZQWZGGTLBHROP;
/*DEF*/	DataCursor KWKBBWVNAKWVVD;
/*DEF*/	DataCursor YCXCZOZQIWORVP;
/*SET*/	TZQWZGGTLBHROP = YKEXQGQOEVJTFR;
/*INC*/	if (!INC(TZQWZGGTLBHROP, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (TZQWZGGTLBHROP.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	KWKBBWVNAKWVVD = TZQWZGGTLBHROP.container->value.bracket_data.chain->at_before_first();
	YCXCZOZQIWORVP   = TZQWZGGTLBHROP.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = KWKBBWVNAKWVVD;
/*SET*/	r_n = YCXCZOZQIWORVP;
//// [ empty ] 
/*ISEMPTY*/	if (TZQWZGGTLBHROP!=0 && arg_to != TZQWZGGTLBHROP) goto sentence_after_1;

// подготовка подстановки 
DataChain* WKOQMQHCALYZVQ = new DataChain(); 
result->append(newRefExecBrackets(Ifmust, WKOQMQHCALYZVQ, "Ifmust")); 
DataChain* NKCXEKJQZVUESW = new DataChain(); 
WKOQMQHCALYZVQ->append(newRefStructBrackets(NKCXEKJQZVUESW)); 
DataChain* QKNZPYVYSDKHSO = new DataChain(); 
NKCXEKJQZVUESW->append(newRefExecBrackets(Strategy, QKNZPYVYSDKHSO, "Strategy")); 
QKNZPYVYSDKHSO->append_copy(l_1, r_1); 
DataChain* ICMHCZOHEFNASL = new DataChain(); 
WKOQMQHCALYZVQ->append(newRefStructBrackets(ICMHCZOHEFNASL)); 
DataChain* XWXLLXLEWTZUWB = new DataChain(); 
ICMHCZOHEFNASL->append(newRefExecBrackets(Strategy, XWXLLXLEWTZUWB, "Strategy")); 
XWXLLXLEWTZUWB->append_copy(l_2, r_2); 
DataChain* SUVSENEIQWHNEZ = new DataChain(); 
WKOQMQHCALYZVQ->append(newRefStructBrackets(SUVSENEIQWHNEZ)); 
DataChain* OJKXHORYESUGDH = new DataChain(); 
SUVSENEIQWHNEZ->append(newRefExecBrackets(Strategy, OJKXHORYESUGDH, "Strategy")); 
OJKXHORYESUGDH->append_copy(l_n, r_n); 
DataChain* TJCKQJDFGNRDOI = new DataChain(); 
WKOQMQHCALYZVQ->append(newRefStructBrackets(TJCKQJDFGNRDOI)); 
TJCKQJDFGNRDOI->append_copy(l_g, r_g); 
DataChain* ZPYFMDLQLWQIOD = new DataChain(); 
WKOQMQHCALYZVQ->append(newRefStructBrackets(ZPYFMDLQLWQIOD)); 
ZPYFMDLQLWQIOD->append_copy(l_1, r_1); 
DataChain* CWFYGKIVBUJFIN = new DataChain(); 
WKOQMQHCALYZVQ->append(newRefStructBrackets(CWFYGKIVBUJFIN)); 
CWFYGKIVBUJFIN->append_copy(l_2, r_2); 
DataChain* ZYHCEJCJOJONHG = new DataChain(); 
WKOQMQHCALYZVQ->append(newRefStructBrackets(ZYHCEJCJOJONHG)); 
ZYHCEJCJOJONHG->append_copy(l_n, r_n); 

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
DataChain* USTQJFNECOLOCM = new DataChain(); 
result->append(newRefExecBrackets(Prout, USTQJFNECOLOCM, "Prout")); 
USTQJFNECOLOCM->append(newRefWord("Ifmust:")); 
USTQJFNECOLOCM->append_copy(l_e, r_e); 
DataChain* FHPZXTGFPMUSCR = new DataChain(); 
result->append(newRefExecBrackets(Ifmust__, FHPZXTGFPMUSCR, "Ifmust__")); 
FHPZXTGFPMUSCR->append_copy(l_e, r_e); 

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
/*DEF*/	DataCursor LDURENNLQKWHHY;
/*DEF*/	DataCursor IPQZEVBYKTBVTP;
/*DEF*/	DataCursor WVTTGECAJYLQVU;
/*SET*/	LDURENNLQKWHHY = arg_from;
/*INC*/	if (!INC(LDURENNLQKWHHY, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (LDURENNLQKWHHY.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	IPQZEVBYKTBVTP = LDURENNLQKWHHY.container->value.bracket_data.chain->at_before_first();
	WVTTGECAJYLQVU   = LDURENNLQKWHHY.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_e1;
/*DEF*/	DataCursor r_e1;
/*SET*/	l_e1 = IPQZEVBYKTBVTP;
/*SET*/	r_e1 = WVTTGECAJYLQVU;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor IZFSOAYXZILJZE;
/*DEF*/	DataCursor GBLCATMVEFQRZX;
/*DEF*/	DataCursor WKTNDPBBZDRWLP;
/*SET*/	IZFSOAYXZILJZE = LDURENNLQKWHHY;
/*INC*/	if (!INC(IZFSOAYXZILJZE, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (IZFSOAYXZILJZE.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	GBLCATMVEFQRZX = IZFSOAYXZILJZE.container->value.bracket_data.chain->at_before_first();
	WKTNDPBBZDRWLP   = IZFSOAYXZILJZE.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e21;
/*DEF*/	DataCursor r_e21;
/*SET*/	l_e21 = GBLCATMVEFQRZX;
/*SET*/	r_e21 = GBLCATMVEFQRZX;
/*JMP*/	goto label_HLGDYWDOFNZXQL_firststep;
label_HLGDYWDOFNZXQL: 
/*INC*/	if (!INC(r_e21, WKTNDPBBZDRWLP)) goto sentence_after_1;
label_HLGDYWDOFNZXQL_firststep: 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor XVKHDJYALHVVPA;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_e21;
/*SET*/	XVKHDJYALHVVPA = r_e21;
/*INC*/	if (!INC(XVKHDJYALHVVPA, WKTNDPBBZDRWLP)) goto label_HLGDYWDOFNZXQL;
	if (! isSymbolType(XVKHDJYALHVVPA.container->type)) goto label_HLGDYWDOFNZXQL;
/*SET*/	r_A = XVKHDJYALHVVPA;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e22;
/*DEF*/	DataCursor r_e22;
/*SET*/	l_e22 = r_A;
/*SET*/	r_e22 = r_A;
/*JMP*/	goto label_ANGODNLXHLSXSH_firststep;
label_ANGODNLXHLSXSH: 
/*INC*/	if (!INC(r_e22, WKTNDPBBZDRWLP)) goto label_HLGDYWDOFNZXQL;
label_ANGODNLXHLSXSH_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor HTIFXICKOBIXBB;
/*SET*/	HTIFXICKOBIXBB = r_e22;
 if (!SLIDE(HTIFXICKOBIXBB, WKTNDPBBZDRWLP, l_A, r_A)) goto label_ANGODNLXHLSXSH;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e23;
/*DEF*/	DataCursor r_e23;
/*SET*/	l_e23 = HTIFXICKOBIXBB;
/*SET*/	r_e23 = WKTNDPBBZDRWLP;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor DUZVNGQIAGGCXF;
/*DEF*/	DataCursor GRJMARWUPAYBNQ;
/*DEF*/	DataCursor GUDBEWKGWGTOCB;
/*SET*/	DUZVNGQIAGGCXF = IZFSOAYXZILJZE;
/*INC*/	if (!INC(DUZVNGQIAGGCXF, arg_to)) goto label_ANGODNLXHLSXSH;
//// ISBRACKET 
	if (DUZVNGQIAGGCXF.container->type != struct_bracket) goto label_ANGODNLXHLSXSH;
//// JMP_BRACKET 
	GRJMARWUPAYBNQ = DUZVNGQIAGGCXF.container->value.bracket_data.chain->at_before_first();
	GUDBEWKGWGTOCB   = DUZVNGQIAGGCXF.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_nn1;
/*DEF*/	DataCursor r_nn1;
/*SET*/	l_nn1 = GRJMARWUPAYBNQ;
/*SET*/	r_nn1 = GRJMARWUPAYBNQ;
/*JMP*/	goto label_LXJECCGQHBCZIB_firststep;
label_LXJECCGQHBCZIB: 
/*INC*/	if (!INC(r_nn1, GUDBEWKGWGTOCB)) goto label_ANGODNLXHLSXSH;
label_LXJECCGQHBCZIB_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor HQUFQQXVLLVMTZ;
/*SET*/	HQUFQQXVLLVMTZ = r_nn1;
 if (!SLIDE(HQUFQQXVLLVMTZ, GUDBEWKGWGTOCB, l_A, r_A)) goto label_LXJECCGQHBCZIB;
//// [ e.1 ] 
/*DEF*/	DataCursor l_nn2;
/*DEF*/	DataCursor r_nn2;
/*SET*/	l_nn2 = HQUFQQXVLLVMTZ;
/*SET*/	r_nn2 = GUDBEWKGWGTOCB;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor HFMBEZPLHQAKBM;
/*DEF*/	DataCursor MVAFQYXJYEXDSS;
/*DEF*/	DataCursor WBJIOUYMHLZCLT;
/*SET*/	HFMBEZPLHQAKBM = DUZVNGQIAGGCXF;
/*INC*/	if (!INC(HFMBEZPLHQAKBM, arg_to)) goto label_LXJECCGQHBCZIB;
//// ISBRACKET 
	if (HFMBEZPLHQAKBM.container->type != struct_bracket) goto label_LXJECCGQHBCZIB;
//// JMP_BRACKET 
	MVAFQYXJYEXDSS = HFMBEZPLHQAKBM.container->value.bracket_data.chain->at_before_first();
	WBJIOUYMHLZCLT   = HFMBEZPLHQAKBM.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor JUDOBFUOIWUBGE;
/*SET*/	JUDOBFUOIWUBGE = MVAFQYXJYEXDSS;
/*INC*/	if (!INC(JUDOBFUOIWUBGE, WBJIOUYMHLZCLT)) goto label_LXJECCGQHBCZIB;
	if (JUDOBFUOIWUBGE.container->type != text || *(JUDOBFUOIWUBGE.container->value.text + JUDOBFUOIWUBGE.index) != '2') goto label_LXJECCGQHBCZIB;
//// [ empty ] 
/*ISEMPTY*/	if (JUDOBFUOIWUBGE!=0 && WBJIOUYMHLZCLT != JUDOBFUOIWUBGE) goto label_LXJECCGQHBCZIB;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e1e2;
/*DEF*/	DataCursor r_e1e2;
/*SET*/	l_e1e2 = HFMBEZPLHQAKBM;
/*SET*/	r_e1e2 = HFMBEZPLHQAKBM;
/*JMP*/	goto label_OMLGLTLVEINNCA_firststep;
label_OMLGLTLVEINNCA: 
/*INC*/	if (!INC(r_e1e2, arg_to)) goto label_LXJECCGQHBCZIB;
label_OMLGLTLVEINNCA_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor IKNSUGJQCCASDX;
/*DEF*/	DataCursor DAZCRTVLLKFVTE;
/*DEF*/	DataCursor ZAZZCSCTLEGENL;
/*SET*/	IKNSUGJQCCASDX = r_e1e2;
/*INC*/	if (!INC(IKNSUGJQCCASDX, arg_to)) goto label_OMLGLTLVEINNCA;
//// ISBRACKET 
	if (IKNSUGJQCCASDX.container->type != struct_bracket) goto label_OMLGLTLVEINNCA;
//// JMP_BRACKET 
	DAZCRTVLLKFVTE = IKNSUGJQCCASDX.container->value.bracket_data.chain->at_before_first();
	ZAZZCSCTLEGENL   = IKNSUGJQCCASDX.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = DAZCRTVLLKFVTE;
/*SET*/	r_n = ZAZZCSCTLEGENL;
//// [ empty ] 
/*ISEMPTY*/	if (IKNSUGJQCCASDX!=0 && arg_to != IKNSUGJQCCASDX) goto label_OMLGLTLVEINNCA;

// подготовка подстановки 
result->append(newRefText("2")); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor LTVKZDQOWGOLJP;
/*DEF*/	DataCursor DSYQNCSDJSDCXX;
/*DEF*/	DataCursor YRGHRWPQINXMRI;
/*SET*/	LTVKZDQOWGOLJP = arg_from;
/*INC*/	if (!INC(LTVKZDQOWGOLJP, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (LTVKZDQOWGOLJP.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	DSYQNCSDJSDCXX = LTVKZDQOWGOLJP.container->value.bracket_data.chain->at_before_first();
	YRGHRWPQINXMRI   = LTVKZDQOWGOLJP.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e21;
/*DEF*/	DataCursor r_e21;
/*SET*/	l_e21 = DSYQNCSDJSDCXX;
/*SET*/	r_e21 = DSYQNCSDJSDCXX;
/*JMP*/	goto label_DXPDPQUNVKWXRY_firststep;
label_DXPDPQUNVKWXRY: 
/*INC*/	if (!INC(r_e21, YRGHRWPQINXMRI)) goto sentence_after_2;
label_DXPDPQUNVKWXRY_firststep: 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor KXTLXYPPFMAJFH;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_e21;
/*SET*/	KXTLXYPPFMAJFH = r_e21;
/*INC*/	if (!INC(KXTLXYPPFMAJFH, YRGHRWPQINXMRI)) goto label_DXPDPQUNVKWXRY;
	if (! isSymbolType(KXTLXYPPFMAJFH.container->type)) goto label_DXPDPQUNVKWXRY;
/*SET*/	r_A = KXTLXYPPFMAJFH;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e22;
/*DEF*/	DataCursor r_e22;
/*SET*/	l_e22 = r_A;
/*SET*/	r_e22 = r_A;
/*JMP*/	goto label_QYUDWTIGBJTMQM_firststep;
label_QYUDWTIGBJTMQM: 
/*INC*/	if (!INC(r_e22, YRGHRWPQINXMRI)) goto label_DXPDPQUNVKWXRY;
label_QYUDWTIGBJTMQM_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor DLTCQZGCAIWSWF;
/*SET*/	DLTCQZGCAIWSWF = r_e22;
 if (!SLIDE(DLTCQZGCAIWSWF, YRGHRWPQINXMRI, l_A, r_A)) goto label_QYUDWTIGBJTMQM;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e23;
/*DEF*/	DataCursor r_e23;
/*SET*/	l_e23 = DLTCQZGCAIWSWF;
/*SET*/	r_e23 = YRGHRWPQINXMRI;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor YRYHCWWIARUHII;
/*DEF*/	DataCursor BUJOPGRQNPIUGK;
/*DEF*/	DataCursor DQTESOJACQHNWD;
/*SET*/	YRYHCWWIARUHII = LTVKZDQOWGOLJP;
/*INC*/	if (!INC(YRYHCWWIARUHII, arg_to)) goto label_QYUDWTIGBJTMQM;
//// ISBRACKET 
	if (YRYHCWWIARUHII.container->type != struct_bracket) goto label_QYUDWTIGBJTMQM;
//// JMP_BRACKET 
	BUJOPGRQNPIUGK = YRYHCWWIARUHII.container->value.bracket_data.chain->at_before_first();
	DQTESOJACQHNWD   = YRYHCWWIARUHII.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_e1;
/*DEF*/	DataCursor r_e1;
/*SET*/	l_e1 = BUJOPGRQNPIUGK;
/*SET*/	r_e1 = DQTESOJACQHNWD;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor AGNVXESFRFIEFA;
/*DEF*/	DataCursor ABRADQEELKPKEC;
/*DEF*/	DataCursor VPSDWELPDJMMBP;
/*SET*/	AGNVXESFRFIEFA = YRYHCWWIARUHII;
/*INC*/	if (!INC(AGNVXESFRFIEFA, arg_to)) goto label_QYUDWTIGBJTMQM;
//// ISBRACKET 
	if (AGNVXESFRFIEFA.container->type != struct_bracket) goto label_QYUDWTIGBJTMQM;
//// JMP_BRACKET 
	ABRADQEELKPKEC = AGNVXESFRFIEFA.container->value.bracket_data.chain->at_before_first();
	VPSDWELPDJMMBP   = AGNVXESFRFIEFA.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_nn1;
/*DEF*/	DataCursor r_nn1;
/*SET*/	l_nn1 = ABRADQEELKPKEC;
/*SET*/	r_nn1 = ABRADQEELKPKEC;
/*JMP*/	goto label_DUPZVTVJXYDKDN_firststep;
label_DUPZVTVJXYDKDN: 
/*INC*/	if (!INC(r_nn1, VPSDWELPDJMMBP)) goto label_QYUDWTIGBJTMQM;
label_DUPZVTVJXYDKDN_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor CUGGHONUCWEGVF;
/*SET*/	CUGGHONUCWEGVF = r_nn1;
 if (!SLIDE(CUGGHONUCWEGVF, VPSDWELPDJMMBP, l_A, r_A)) goto label_DUPZVTVJXYDKDN;
//// [ e.1 ] 
/*DEF*/	DataCursor l_nn2;
/*DEF*/	DataCursor r_nn2;
/*SET*/	l_nn2 = CUGGHONUCWEGVF;
/*SET*/	r_nn2 = VPSDWELPDJMMBP;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor JZBDWKBEVKGDWU;
/*DEF*/	DataCursor BTJVTOQOTHGGTD;
/*DEF*/	DataCursor RDOLGJMFUBZZPN;
/*SET*/	JZBDWKBEVKGDWU = AGNVXESFRFIEFA;
/*INC*/	if (!INC(JZBDWKBEVKGDWU, arg_to)) goto label_DUPZVTVJXYDKDN;
//// ISBRACKET 
	if (JZBDWKBEVKGDWU.container->type != struct_bracket) goto label_DUPZVTVJXYDKDN;
//// JMP_BRACKET 
	BTJVTOQOTHGGTD = JZBDWKBEVKGDWU.container->value.bracket_data.chain->at_before_first();
	RDOLGJMFUBZZPN   = JZBDWKBEVKGDWU.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor HJAQWOTZQBLHMR;
/*SET*/	HJAQWOTZQBLHMR = BTJVTOQOTHGGTD;
/*INC*/	if (!INC(HJAQWOTZQBLHMR, RDOLGJMFUBZZPN)) goto label_DUPZVTVJXYDKDN;
	if (HJAQWOTZQBLHMR.container->type != text || *(HJAQWOTZQBLHMR.container->value.text + HJAQWOTZQBLHMR.index) != '1') goto label_DUPZVTVJXYDKDN;
//// [ empty ] 
/*ISEMPTY*/	if (HJAQWOTZQBLHMR!=0 && RDOLGJMFUBZZPN != HJAQWOTZQBLHMR) goto label_DUPZVTVJXYDKDN;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e1e2;
/*DEF*/	DataCursor r_e1e2;
/*SET*/	l_e1e2 = JZBDWKBEVKGDWU;
/*SET*/	r_e1e2 = JZBDWKBEVKGDWU;
/*JMP*/	goto label_YJVCTVFAMCGLTM_firststep;
label_YJVCTVFAMCGLTM: 
/*INC*/	if (!INC(r_e1e2, arg_to)) goto label_DUPZVTVJXYDKDN;
label_YJVCTVFAMCGLTM_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor JTMRCJIVHSYTNW;
/*DEF*/	DataCursor MQQJVMOHFYESQX;
/*DEF*/	DataCursor DVRJGFVGYMHLWD;
/*SET*/	JTMRCJIVHSYTNW = r_e1e2;
/*INC*/	if (!INC(JTMRCJIVHSYTNW, arg_to)) goto label_YJVCTVFAMCGLTM;
//// ISBRACKET 
	if (JTMRCJIVHSYTNW.container->type != struct_bracket) goto label_YJVCTVFAMCGLTM;
//// JMP_BRACKET 
	MQQJVMOHFYESQX = JTMRCJIVHSYTNW.container->value.bracket_data.chain->at_before_first();
	DVRJGFVGYMHLWD   = JTMRCJIVHSYTNW.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = MQQJVMOHFYESQX;
/*SET*/	r_n = DVRJGFVGYMHLWD;
//// [ empty ] 
/*ISEMPTY*/	if (JTMRCJIVHSYTNW!=0 && arg_to != JTMRCJIVHSYTNW) goto label_YJVCTVFAMCGLTM;

// подготовка подстановки 
result->append(newRefText("1")); 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor XLOZMCQMVHTCEX;
/*DEF*/	DataCursor AMEYKVIXDAQVSS;
/*DEF*/	DataCursor DWWOEDKLQENAFB;
/*SET*/	XLOZMCQMVHTCEX = arg_from;
/*INC*/	if (!INC(XLOZMCQMVHTCEX, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (XLOZMCQMVHTCEX.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	AMEYKVIXDAQVSS = XLOZMCQMVHTCEX.container->value.bracket_data.chain->at_before_first();
	DWWOEDKLQENAFB   = XLOZMCQMVHTCEX.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_e1;
/*DEF*/	DataCursor r_e1;
/*SET*/	l_e1 = AMEYKVIXDAQVSS;
/*SET*/	r_e1 = DWWOEDKLQENAFB;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor CFNHWRHDKJCSXO;
/*DEF*/	DataCursor HDVRBNLBLSEEND;
/*DEF*/	DataCursor UBKXAORTEJLRCM;
/*SET*/	CFNHWRHDKJCSXO = XLOZMCQMVHTCEX;
/*INC*/	if (!INC(CFNHWRHDKJCSXO, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (CFNHWRHDKJCSXO.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	HDVRBNLBLSEEND = CFNHWRHDKJCSXO.container->value.bracket_data.chain->at_before_first();
	UBKXAORTEJLRCM   = CFNHWRHDKJCSXO.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e21;
/*DEF*/	DataCursor r_e21;
/*SET*/	l_e21 = HDVRBNLBLSEEND;
/*SET*/	r_e21 = HDVRBNLBLSEEND;
/*JMP*/	goto label_CVOVRSQRCOPNNP_firststep;
label_CVOVRSQRCOPNNP: 
/*INC*/	if (!INC(r_e21, UBKXAORTEJLRCM)) goto sentence_after_3;
label_CVOVRSQRCOPNNP_firststep: 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor KUNKKCPOENVPKV;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_e21;
/*SET*/	KUNKKCPOENVPKV = r_e21;
/*INC*/	if (!INC(KUNKKCPOENVPKV, UBKXAORTEJLRCM)) goto label_CVOVRSQRCOPNNP;
	if (! isSymbolType(KUNKKCPOENVPKV.container->type)) goto label_CVOVRSQRCOPNNP;
/*SET*/	r_A = KUNKKCPOENVPKV;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e22;
/*DEF*/	DataCursor r_e22;
/*SET*/	l_e22 = r_A;
/*SET*/	r_e22 = r_A;
/*JMP*/	goto label_YGUNPABOUJVIRE_firststep;
label_YGUNPABOUJVIRE: 
/*INC*/	if (!INC(r_e22, UBKXAORTEJLRCM)) goto label_CVOVRSQRCOPNNP;
label_YGUNPABOUJVIRE_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor LEHLGECTNAZVQP;
/*SET*/	LEHLGECTNAZVQP = r_e22;
 if (!SLIDE(LEHLGECTNAZVQP, UBKXAORTEJLRCM, l_A, r_A)) goto label_YGUNPABOUJVIRE;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e23;
/*DEF*/	DataCursor r_e23;
/*SET*/	l_e23 = LEHLGECTNAZVQP;
/*SET*/	r_e23 = UBKXAORTEJLRCM;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor SOUUBCPYFIKGQT;
/*DEF*/	DataCursor UFVQQEVCPCJPMJ;
/*DEF*/	DataCursor HPUACSIASPTSKQ;
/*SET*/	SOUUBCPYFIKGQT = CFNHWRHDKJCSXO;
/*INC*/	if (!INC(SOUUBCPYFIKGQT, arg_to)) goto label_YGUNPABOUJVIRE;
//// ISBRACKET 
	if (SOUUBCPYFIKGQT.container->type != struct_bracket) goto label_YGUNPABOUJVIRE;
//// JMP_BRACKET 
	UFVQQEVCPCJPMJ = SOUUBCPYFIKGQT.container->value.bracket_data.chain->at_before_first();
	HPUACSIASPTSKQ   = SOUUBCPYFIKGQT.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_nn1;
/*DEF*/	DataCursor r_nn1;
/*SET*/	l_nn1 = UFVQQEVCPCJPMJ;
/*SET*/	r_nn1 = UFVQQEVCPCJPMJ;
/*JMP*/	goto label_YHITAUZFABLPQL_firststep;
label_YHITAUZFABLPQL: 
/*INC*/	if (!INC(r_nn1, HPUACSIASPTSKQ)) goto label_YGUNPABOUJVIRE;
label_YHITAUZFABLPQL_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor KUKAHMLIVZAPRO;
/*SET*/	KUKAHMLIVZAPRO = r_nn1;
 if (!SLIDE(KUKAHMLIVZAPRO, HPUACSIASPTSKQ, l_A, r_A)) goto label_YHITAUZFABLPQL;
//// [ e.1 ] 
/*DEF*/	DataCursor l_nn2;
/*DEF*/	DataCursor r_nn2;
/*SET*/	l_nn2 = KUKAHMLIVZAPRO;
/*SET*/	r_nn2 = HPUACSIASPTSKQ;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor TLQDIUOEEYKIQZ;
/*DEF*/	DataCursor AHFAVZZRFRZZEM;
/*DEF*/	DataCursor IYZVOBXUOJORAW;
/*SET*/	TLQDIUOEEYKIQZ = SOUUBCPYFIKGQT;
/*INC*/	if (!INC(TLQDIUOEEYKIQZ, arg_to)) goto label_YHITAUZFABLPQL;
//// ISBRACKET 
	if (TLQDIUOEEYKIQZ.container->type != struct_bracket) goto label_YHITAUZFABLPQL;
//// JMP_BRACKET 
	AHFAVZZRFRZZEM = TLQDIUOEEYKIQZ.container->value.bracket_data.chain->at_before_first();
	IYZVOBXUOJORAW   = TLQDIUOEEYKIQZ.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor URHJOPPNNCTEHR;
/*SET*/	URHJOPPNNCTEHR = AHFAVZZRFRZZEM;
/*INC*/	if (!INC(URHJOPPNNCTEHR, IYZVOBXUOJORAW)) goto label_YHITAUZFABLPQL;
	if (URHJOPPNNCTEHR.container->type != text || *(URHJOPPNNCTEHR.container->value.text + URHJOPPNNCTEHR.index) != '1') goto label_YHITAUZFABLPQL;
//// [ empty ] 
/*ISEMPTY*/	if (URHJOPPNNCTEHR!=0 && IYZVOBXUOJORAW != URHJOPPNNCTEHR) goto label_YHITAUZFABLPQL;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e1e2;
/*DEF*/	DataCursor r_e1e2;
/*SET*/	l_e1e2 = TLQDIUOEEYKIQZ;
/*SET*/	r_e1e2 = TLQDIUOEEYKIQZ;
/*JMP*/	goto label_DLBOFBJEJAZSRU_firststep;
label_DLBOFBJEJAZSRU: 
/*INC*/	if (!INC(r_e1e2, arg_to)) goto label_YHITAUZFABLPQL;
label_DLBOFBJEJAZSRU_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor LVQTAMMEMHQPYI;
/*DEF*/	DataCursor OWMNLQAEFZSIOT;
/*DEF*/	DataCursor PXJWOCJEUMCJDQ;
/*SET*/	LVQTAMMEMHQPYI = r_e1e2;
/*INC*/	if (!INC(LVQTAMMEMHQPYI, arg_to)) goto label_DLBOFBJEJAZSRU;
//// ISBRACKET 
	if (LVQTAMMEMHQPYI.container->type != struct_bracket) goto label_DLBOFBJEJAZSRU;
//// JMP_BRACKET 
	OWMNLQAEFZSIOT = LVQTAMMEMHQPYI.container->value.bracket_data.chain->at_before_first();
	PXJWOCJEUMCJDQ   = LVQTAMMEMHQPYI.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = OWMNLQAEFZSIOT;
/*SET*/	r_n = PXJWOCJEUMCJDQ;
//// [ empty ] 
/*ISEMPTY*/	if (LVQTAMMEMHQPYI!=0 && arg_to != LVQTAMMEMHQPYI) goto label_DLBOFBJEJAZSRU;

// подготовка подстановки 
DataChain* SZRRRUGIMNJBJA = new DataChain(); 
result->append(newRefExecBrackets(StepShag, SZRRRUGIMNJBJA, "StepShag")); 
DataChain* LQLRCEZJFXCHWD = new DataChain(); 
SZRRRUGIMNJBJA->append(newRefExecBrackets(Lins, LQLRCEZJFXCHWD, "Lins")); 
DataChain* DXONZMNJVLRJXR = new DataChain(); 
LQLRCEZJFXCHWD->append(newRefStructBrackets(DXONZMNJVLRJXR)); 
DXONZMNJVLRJXR->append_copy(l_n, r_n); 
DataChain* XWKDUOOERCTEEQ = new DataChain(); 
LQLRCEZJFXCHWD->append(newRefExecBrackets(AntiStrategy, XWKDUOOERCTEEQ, "AntiStrategy")); 
XWKDUOOERCTEEQ->append_copy(l_A, r_A); 
DataChain* DVDLRWAMNKYXJS = new DataChain(); 
SZRRRUGIMNJBJA->append(newRefStructBrackets(DVDLRWAMNKYXJS)); 
DVDLRWAMNKYXJS->append(newRefText("1")); 
SZRRRUGIMNJBJA->append_copy(l_e1e2, r_e1e2); 
DataChain* XPFDLZEHBGKVYP = new DataChain(); 
SZRRRUGIMNJBJA->append(newRefStructBrackets(XPFDLZEHBGKVYP)); 
XPFDLZEHBGKVYP->append_copy(l_n, r_n); 

return result; 
}
sentence_after_3: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor XFSMQHIBNGJTGR;
/*DEF*/	DataCursor KPFERAYXDZNPGK;
/*DEF*/	DataCursor SDFPDJOBICQFQM;
/*SET*/	XFSMQHIBNGJTGR = arg_from;
/*INC*/	if (!INC(XFSMQHIBNGJTGR, arg_to)) goto sentence_after_4;
//// ISBRACKET 
	if (XFSMQHIBNGJTGR.container->type != struct_bracket) goto sentence_after_4;
//// JMP_BRACKET 
	KPFERAYXDZNPGK = XFSMQHIBNGJTGR.container->value.bracket_data.chain->at_before_first();
	SDFPDJOBICQFQM   = XFSMQHIBNGJTGR.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e21;
/*DEF*/	DataCursor r_e21;
/*SET*/	l_e21 = KPFERAYXDZNPGK;
/*SET*/	r_e21 = KPFERAYXDZNPGK;
/*JMP*/	goto label_FSTQHPFMCPMFDC_firststep;
label_FSTQHPFMCPMFDC: 
/*INC*/	if (!INC(r_e21, SDFPDJOBICQFQM)) goto sentence_after_4;
label_FSTQHPFMCPMFDC_firststep: 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor DCCMODLQJQGWJO;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_e21;
/*SET*/	DCCMODLQJQGWJO = r_e21;
/*INC*/	if (!INC(DCCMODLQJQGWJO, SDFPDJOBICQFQM)) goto label_FSTQHPFMCPMFDC;
	if (! isSymbolType(DCCMODLQJQGWJO.container->type)) goto label_FSTQHPFMCPMFDC;
/*SET*/	r_A = DCCMODLQJQGWJO;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e22;
/*DEF*/	DataCursor r_e22;
/*SET*/	l_e22 = r_A;
/*SET*/	r_e22 = r_A;
/*JMP*/	goto label_FNUQNPMHDVKZEB_firststep;
label_FNUQNPMHDVKZEB: 
/*INC*/	if (!INC(r_e22, SDFPDJOBICQFQM)) goto label_FSTQHPFMCPMFDC;
label_FNUQNPMHDVKZEB_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor NLIGKJFSWCXWCU;
/*SET*/	NLIGKJFSWCXWCU = r_e22;
 if (!SLIDE(NLIGKJFSWCXWCU, SDFPDJOBICQFQM, l_A, r_A)) goto label_FNUQNPMHDVKZEB;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e23;
/*DEF*/	DataCursor r_e23;
/*SET*/	l_e23 = NLIGKJFSWCXWCU;
/*SET*/	r_e23 = SDFPDJOBICQFQM;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor JWHEPDBSGTFFKB;
/*DEF*/	DataCursor YKEUHNFZNGKPMV;
/*DEF*/	DataCursor QTHEJJRBZHRCGG;
/*SET*/	JWHEPDBSGTFFKB = XFSMQHIBNGJTGR;
/*INC*/	if (!INC(JWHEPDBSGTFFKB, arg_to)) goto label_FNUQNPMHDVKZEB;
//// ISBRACKET 
	if (JWHEPDBSGTFFKB.container->type != struct_bracket) goto label_FNUQNPMHDVKZEB;
//// JMP_BRACKET 
	YKEUHNFZNGKPMV = JWHEPDBSGTFFKB.container->value.bracket_data.chain->at_before_first();
	QTHEJJRBZHRCGG   = JWHEPDBSGTFFKB.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_e1;
/*DEF*/	DataCursor r_e1;
/*SET*/	l_e1 = YKEUHNFZNGKPMV;
/*SET*/	r_e1 = QTHEJJRBZHRCGG;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor OEWVRXBWYSZBLQ;
/*DEF*/	DataCursor GPWJPLTJFRQCOC;
/*DEF*/	DataCursor QXYLUTTLWHTZAS;
/*SET*/	OEWVRXBWYSZBLQ = JWHEPDBSGTFFKB;
/*INC*/	if (!INC(OEWVRXBWYSZBLQ, arg_to)) goto label_FNUQNPMHDVKZEB;
//// ISBRACKET 
	if (OEWVRXBWYSZBLQ.container->type != struct_bracket) goto label_FNUQNPMHDVKZEB;
//// JMP_BRACKET 
	GPWJPLTJFRQCOC = OEWVRXBWYSZBLQ.container->value.bracket_data.chain->at_before_first();
	QXYLUTTLWHTZAS   = OEWVRXBWYSZBLQ.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_nn1;
/*DEF*/	DataCursor r_nn1;
/*SET*/	l_nn1 = GPWJPLTJFRQCOC;
/*SET*/	r_nn1 = GPWJPLTJFRQCOC;
/*JMP*/	goto label_NQEOYJBXKIQMAJ_firststep;
label_NQEOYJBXKIQMAJ: 
/*INC*/	if (!INC(r_nn1, QXYLUTTLWHTZAS)) goto label_FNUQNPMHDVKZEB;
label_NQEOYJBXKIQMAJ_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor AGFHZZFBDVFUYU;
/*SET*/	AGFHZZFBDVFUYU = r_nn1;
 if (!SLIDE(AGFHZZFBDVFUYU, QXYLUTTLWHTZAS, l_A, r_A)) goto label_NQEOYJBXKIQMAJ;
//// [ e.1 ] 
/*DEF*/	DataCursor l_nn2;
/*DEF*/	DataCursor r_nn2;
/*SET*/	l_nn2 = AGFHZZFBDVFUYU;
/*SET*/	r_nn2 = QXYLUTTLWHTZAS;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor RLVURNWRAMCADU;
/*DEF*/	DataCursor NWUGTUESHXMGZV;
/*DEF*/	DataCursor SRMCIFBVRASUCU;
/*SET*/	RLVURNWRAMCADU = OEWVRXBWYSZBLQ;
/*INC*/	if (!INC(RLVURNWRAMCADU, arg_to)) goto label_NQEOYJBXKIQMAJ;
//// ISBRACKET 
	if (RLVURNWRAMCADU.container->type != struct_bracket) goto label_NQEOYJBXKIQMAJ;
//// JMP_BRACKET 
	NWUGTUESHXMGZV = RLVURNWRAMCADU.container->value.bracket_data.chain->at_before_first();
	SRMCIFBVRASUCU   = RLVURNWRAMCADU.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor VIVOWLZIVLIICZ;
/*SET*/	VIVOWLZIVLIICZ = NWUGTUESHXMGZV;
/*INC*/	if (!INC(VIVOWLZIVLIICZ, SRMCIFBVRASUCU)) goto label_NQEOYJBXKIQMAJ;
	if (VIVOWLZIVLIICZ.container->type != text || *(VIVOWLZIVLIICZ.container->value.text + VIVOWLZIVLIICZ.index) != '2') goto label_NQEOYJBXKIQMAJ;
//// [ empty ] 
/*ISEMPTY*/	if (VIVOWLZIVLIICZ!=0 && SRMCIFBVRASUCU != VIVOWLZIVLIICZ) goto label_NQEOYJBXKIQMAJ;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e1e2;
/*DEF*/	DataCursor r_e1e2;
/*SET*/	l_e1e2 = RLVURNWRAMCADU;
/*SET*/	r_e1e2 = RLVURNWRAMCADU;
/*JMP*/	goto label_CIMLMSLEBFIIAR_firststep;
label_CIMLMSLEBFIIAR: 
/*INC*/	if (!INC(r_e1e2, arg_to)) goto label_NQEOYJBXKIQMAJ;
label_CIMLMSLEBFIIAR_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor GFMUABIZMYQPTH;
/*DEF*/	DataCursor DMZEIEGQCJTSJH;
/*DEF*/	DataCursor QKMVWZEDALKJDV;
/*SET*/	GFMUABIZMYQPTH = r_e1e2;
/*INC*/	if (!INC(GFMUABIZMYQPTH, arg_to)) goto label_CIMLMSLEBFIIAR;
//// ISBRACKET 
	if (GFMUABIZMYQPTH.container->type != struct_bracket) goto label_CIMLMSLEBFIIAR;
//// JMP_BRACKET 
	DMZEIEGQCJTSJH = GFMUABIZMYQPTH.container->value.bracket_data.chain->at_before_first();
	QKMVWZEDALKJDV   = GFMUABIZMYQPTH.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = DMZEIEGQCJTSJH;
/*SET*/	r_n = QKMVWZEDALKJDV;
//// [ empty ] 
/*ISEMPTY*/	if (GFMUABIZMYQPTH!=0 && arg_to != GFMUABIZMYQPTH) goto label_CIMLMSLEBFIIAR;

// подготовка подстановки 
DataChain* MZGRXOKCHGOALG = new DataChain(); 
result->append(newRefExecBrackets(StepShag, MZGRXOKCHGOALG, "StepShag")); 
DataChain* UQCNQYROKQMJSZ = new DataChain(); 
MZGRXOKCHGOALG->append(newRefExecBrackets(Lins, UQCNQYROKQMJSZ, "Lins")); 
DataChain* JWSDGCOFGLCQGD = new DataChain(); 
UQCNQYROKQMJSZ->append(newRefStructBrackets(JWSDGCOFGLCQGD)); 
JWSDGCOFGLCQGD->append_copy(l_n, r_n); 
DataChain* NDBYPQQIDCLZXS = new DataChain(); 
UQCNQYROKQMJSZ->append(newRefExecBrackets(AntiStrategy, NDBYPQQIDCLZXS, "AntiStrategy")); 
NDBYPQQIDCLZXS->append_copy(l_A, r_A); 
DataChain* QBJWIPLOXDERKL = new DataChain(); 
MZGRXOKCHGOALG->append(newRefStructBrackets(QBJWIPLOXDERKL)); 
QBJWIPLOXDERKL->append(newRefText("2")); 
MZGRXOKCHGOALG->append_copy(l_e1e2, r_e1e2); 
DataChain* GBXGOGNWYUNRNU = new DataChain(); 
MZGRXOKCHGOALG->append(newRefStructBrackets(GBXGOGNWYUNRNU)); 
GBXGOGNWYUNRNU->append_copy(l_n, r_n); 

return result; 
}
sentence_after_4: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor MFOLBALEZROKNK;
/*DEF*/	DataCursor JNWRWEBGELZBGI;
/*DEF*/	DataCursor QDSCWTSBXXZKGH;
/*SET*/	MFOLBALEZROKNK = arg_from;
/*INC*/	if (!INC(MFOLBALEZROKNK, arg_to)) goto sentence_after_5;
//// ISBRACKET 
	if (MFOLBALEZROKNK.container->type != struct_bracket) goto sentence_after_5;
//// JMP_BRACKET 
	JNWRWEBGELZBGI = MFOLBALEZROKNK.container->value.bracket_data.chain->at_before_first();
	QDSCWTSBXXZKGH   = MFOLBALEZROKNK.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_e1;
/*DEF*/	DataCursor r_e1;
/*SET*/	l_e1 = JNWRWEBGELZBGI;
/*SET*/	r_e1 = QDSCWTSBXXZKGH;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor SKGEXLEVGXNYDQ;
/*DEF*/	DataCursor VTYJSLLQKEHTLI;
/*DEF*/	DataCursor AUYICCQDMFIEJR;
/*SET*/	SKGEXLEVGXNYDQ = MFOLBALEZROKNK;
/*INC*/	if (!INC(SKGEXLEVGXNYDQ, arg_to)) goto sentence_after_5;
//// ISBRACKET 
	if (SKGEXLEVGXNYDQ.container->type != struct_bracket) goto sentence_after_5;
//// JMP_BRACKET 
	VTYJSLLQKEHTLI = SKGEXLEVGXNYDQ.container->value.bracket_data.chain->at_before_first();
	AUYICCQDMFIEJR   = SKGEXLEVGXNYDQ.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_e2;
/*DEF*/	DataCursor r_e2;
/*SET*/	l_e2 = VTYJSLLQKEHTLI;
/*SET*/	r_e2 = AUYICCQDMFIEJR;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor QNRNAZCRFHPBJM;
/*DEF*/	DataCursor RFBYQMHDABALHT;
/*DEF*/	DataCursor IGPQMWFONTEPRC;
/*SET*/	QNRNAZCRFHPBJM = SKGEXLEVGXNYDQ;
/*INC*/	if (!INC(QNRNAZCRFHPBJM, arg_to)) goto sentence_after_5;
//// ISBRACKET 
	if (QNRNAZCRFHPBJM.container->type != struct_bracket) goto sentence_after_5;
//// JMP_BRACKET 
	RFBYQMHDABALHT = QNRNAZCRFHPBJM.container->value.bracket_data.chain->at_before_first();
	IGPQMWFONTEPRC   = QNRNAZCRFHPBJM.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_nn;
/*DEF*/	DataCursor r_nn;
/*SET*/	l_nn = RFBYQMHDABALHT;
/*SET*/	r_nn = IGPQMWFONTEPRC;
//// [ e.1 ] 
/*DEF*/	DataCursor l_hn;
/*DEF*/	DataCursor r_hn;
/*SET*/	l_hn = QNRNAZCRFHPBJM;
/*SET*/	r_hn = arg_to;

// подготовка подстановки 
DataChain* HDDWEQDOHSPJDG = new DataChain(); 
result->append(newRefExecBrackets(PolnAnalizEny, HDDWEQDOHSPJDG, "PolnAnalizEny")); 
HDDWEQDOHSPJDG->append_copy(l_hn, r_hn); 

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
/*DEF*/	DataCursor VLZMJBMWEOILEJ;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = arg_from;
/*SET*/	VLZMJBMWEOILEJ = arg_from;
/*INC*/	if (!INC(VLZMJBMWEOILEJ, arg_to)) goto sentence_after_1;
	if (! isSymbolType(VLZMJBMWEOILEJ.container->type)) goto sentence_after_1;
/*SET*/	r_A = VLZMJBMWEOILEJ;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor RPKSBXEESTGPSM;
/*DEF*/	DataCursor NMALPUSWIBUBAQ;
/*DEF*/	DataCursor VOTCAYTBTUZDTW;
/*SET*/	RPKSBXEESTGPSM = r_A;
/*INC*/	if (!INC(RPKSBXEESTGPSM, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (RPKSBXEESTGPSM.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	NMALPUSWIBUBAQ = RPKSBXEESTGPSM.container->value.bracket_data.chain->at_before_first();
	VOTCAYTBTUZDTW   = RPKSBXEESTGPSM.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor SYSJRVRWGIXZHX;
/*SET*/	SYSJRVRWGIXZHX = NMALPUSWIBUBAQ;
/*INC*/	if (!INC(SYSJRVRWGIXZHX, VOTCAYTBTUZDTW)) goto sentence_after_1;
	if (SYSJRVRWGIXZHX.container->type != text || *(SYSJRVRWGIXZHX.container->value.text + SYSJRVRWGIXZHX.index) != '1') goto sentence_after_1;
//// [ empty ] 
/*ISEMPTY*/	if (SYSJRVRWGIXZHX!=0 && VOTCAYTBTUZDTW != SYSJRVRWGIXZHX) goto sentence_after_1;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor YHHTXMJFMQLFWZ;
/*DEF*/	DataCursor JFQVBENLERLKYA;
/*DEF*/	DataCursor WOLVBTYZGEWXCC;
/*SET*/	YHHTXMJFMQLFWZ = RPKSBXEESTGPSM;
/*INC*/	if (!INC(YHHTXMJFMQLFWZ, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (YHHTXMJFMQLFWZ.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	JFQVBENLERLKYA = YHHTXMJFMQLFWZ.container->value.bracket_data.chain->at_before_first();
	WOLVBTYZGEWXCC   = YHHTXMJFMQLFWZ.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = JFQVBENLERLKYA;
/*SET*/	r_1 = WOLVBTYZGEWXCC;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor HSWMWGHBBANCUE;
/*DEF*/	DataCursor JVMWGSFFVOWDLR;
/*DEF*/	DataCursor YINXFIWFHTLDYT;
/*SET*/	HSWMWGHBBANCUE = YHHTXMJFMQLFWZ;
/*INC*/	if (!INC(HSWMWGHBBANCUE, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (HSWMWGHBBANCUE.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	JVMWGSFFVOWDLR = HSWMWGHBBANCUE.container->value.bracket_data.chain->at_before_first();
	YINXFIWFHTLDYT   = HSWMWGHBBANCUE.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = JVMWGSFFVOWDLR;
/*SET*/	r_2 = YINXFIWFHTLDYT;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor YGQKXRWDVRKCOY;
/*DEF*/	DataCursor TXKCWEAGYDMHRP;
/*DEF*/	DataCursor YQUIMWRBVEZZVV;
/*SET*/	YGQKXRWDVRKCOY = HSWMWGHBBANCUE;
/*INC*/	if (!INC(YGQKXRWDVRKCOY, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (YGQKXRWDVRKCOY.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	TXKCWEAGYDMHRP = YGQKXRWDVRKCOY.container->value.bracket_data.chain->at_before_first();
	YQUIMWRBVEZZVV   = YGQKXRWDVRKCOY.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_n1;
/*DEF*/	DataCursor r_n1;
/*SET*/	l_n1 = TXKCWEAGYDMHRP;
/*SET*/	r_n1 = TXKCWEAGYDMHRP;
/*JMP*/	goto label_JPGIHCYFQZVADT_firststep;
label_JPGIHCYFQZVADT: 
/*INC*/	if (!INC(r_n1, YQUIMWRBVEZZVV)) goto sentence_after_1;
label_JPGIHCYFQZVADT_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor DFYEMFQVYNBDLR;
/*SET*/	DFYEMFQVYNBDLR = r_n1;
 if (!SLIDE(DFYEMFQVYNBDLR, YQUIMWRBVEZZVV, l_A, r_A)) goto label_JPGIHCYFQZVADT;
//// [ e.1 ] 
/*DEF*/	DataCursor l_n2;
/*DEF*/	DataCursor r_n2;
/*SET*/	l_n2 = DFYEMFQVYNBDLR;
/*SET*/	r_n2 = YQUIMWRBVEZZVV;
//// [ empty ] 
/*ISEMPTY*/	if (YGQKXRWDVRKCOY!=0 && arg_to != YGQKXRWDVRKCOY) goto label_JPGIHCYFQZVADT;

// подготовка подстановки 
DataChain* QHVAPGYSGGXDOR = new DataChain(); 
result->append(newRefExecBrackets(PolnAnaliz, QHVAPGYSGGXDOR, "PolnAnaliz")); 
DataChain* KVMVQEXPJFGVPI = new DataChain(); 
QHVAPGYSGGXDOR->append(newRefStructBrackets(KVMVQEXPJFGVPI)); 
KVMVQEXPJFGVPI->append(newRefText("2")); 
DataChain* FYIDTTGGSDYJBV = new DataChain(); 
QHVAPGYSGGXDOR->append(newRefStructBrackets(FYIDTTGGSDYJBV)); 
FYIDTTGGSDYJBV->append_copy(l_1, r_1); 
FYIDTTGGSDYJBV->append_copy(l_A, r_A); 
DataChain* OLBMCGBRRVKUPT = new DataChain(); 
QHVAPGYSGGXDOR->append(newRefStructBrackets(OLBMCGBRRVKUPT)); 
OLBMCGBRRVKUPT->append_copy(l_2, r_2); 
DataChain* ANLZOSCTFNYSZK = new DataChain(); 
QHVAPGYSGGXDOR->append(newRefStructBrackets(ANLZOSCTFNYSZK)); 
ANLZOSCTFNYSZK->append_copy(l_n1, r_n1); 
ANLZOSCTFNYSZK->append_copy(l_n2, r_n2); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor LRNZRKUXYJPWWM;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = arg_from;
/*SET*/	LRNZRKUXYJPWWM = arg_from;
/*INC*/	if (!INC(LRNZRKUXYJPWWM, arg_to)) goto sentence_after_2;
	if (! isSymbolType(LRNZRKUXYJPWWM.container->type)) goto sentence_after_2;
/*SET*/	r_A = LRNZRKUXYJPWWM;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor INHPLXGXWULGXH;
/*DEF*/	DataCursor LMSBZRQUAJUAXP;
/*DEF*/	DataCursor DPSMWIWXXDVIPO;
/*SET*/	INHPLXGXWULGXH = r_A;
/*INC*/	if (!INC(INHPLXGXWULGXH, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (INHPLXGXWULGXH.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	LMSBZRQUAJUAXP = INHPLXGXWULGXH.container->value.bracket_data.chain->at_before_first();
	DPSMWIWXXDVIPO   = INHPLXGXWULGXH.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor UXTLKQWWOWRQEA;
/*SET*/	UXTLKQWWOWRQEA = LMSBZRQUAJUAXP;
/*INC*/	if (!INC(UXTLKQWWOWRQEA, DPSMWIWXXDVIPO)) goto sentence_after_2;
	if (UXTLKQWWOWRQEA.container->type != text || *(UXTLKQWWOWRQEA.container->value.text + UXTLKQWWOWRQEA.index) != '2') goto sentence_after_2;
//// [ empty ] 
/*ISEMPTY*/	if (UXTLKQWWOWRQEA!=0 && DPSMWIWXXDVIPO != UXTLKQWWOWRQEA) goto sentence_after_2;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor WEGHTFIQJQKBNJ;
/*DEF*/	DataCursor HXDKUNEBQGRIZK;
/*DEF*/	DataCursor EKGERQQLYYFESO;
/*SET*/	WEGHTFIQJQKBNJ = INHPLXGXWULGXH;
/*INC*/	if (!INC(WEGHTFIQJQKBNJ, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (WEGHTFIQJQKBNJ.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	HXDKUNEBQGRIZK = WEGHTFIQJQKBNJ.container->value.bracket_data.chain->at_before_first();
	EKGERQQLYYFESO   = WEGHTFIQJQKBNJ.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = HXDKUNEBQGRIZK;
/*SET*/	r_1 = EKGERQQLYYFESO;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor YKMVAYQBNKSTMD;
/*DEF*/	DataCursor EFRMTWKYLNONCH;
/*DEF*/	DataCursor IGMTFBOURZHMFF;
/*SET*/	YKMVAYQBNKSTMD = WEGHTFIQJQKBNJ;
/*INC*/	if (!INC(YKMVAYQBNKSTMD, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (YKMVAYQBNKSTMD.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	EFRMTWKYLNONCH = YKMVAYQBNKSTMD.container->value.bracket_data.chain->at_before_first();
	IGMTFBOURZHMFF   = YKMVAYQBNKSTMD.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = EFRMTWKYLNONCH;
/*SET*/	r_2 = IGMTFBOURZHMFF;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor FSRCBDZDFBEOST;
/*DEF*/	DataCursor FVSKREBTLJHZKR;
/*DEF*/	DataCursor GHTSGBBDHLSICU;
/*SET*/	FSRCBDZDFBEOST = YKMVAYQBNKSTMD;
/*INC*/	if (!INC(FSRCBDZDFBEOST, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (FSRCBDZDFBEOST.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	FVSKREBTLJHZKR = FSRCBDZDFBEOST.container->value.bracket_data.chain->at_before_first();
	GHTSGBBDHLSICU   = FSRCBDZDFBEOST.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_n1;
/*DEF*/	DataCursor r_n1;
/*SET*/	l_n1 = FVSKREBTLJHZKR;
/*SET*/	r_n1 = FVSKREBTLJHZKR;
/*JMP*/	goto label_TFMMJOUTFVEXDC_firststep;
label_TFMMJOUTFVEXDC: 
/*INC*/	if (!INC(r_n1, GHTSGBBDHLSICU)) goto sentence_after_2;
label_TFMMJOUTFVEXDC_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor ZSCHYTBCRKLIWC;
/*SET*/	ZSCHYTBCRKLIWC = r_n1;
 if (!SLIDE(ZSCHYTBCRKLIWC, GHTSGBBDHLSICU, l_A, r_A)) goto label_TFMMJOUTFVEXDC;
//// [ e.1 ] 
/*DEF*/	DataCursor l_n2;
/*DEF*/	DataCursor r_n2;
/*SET*/	l_n2 = ZSCHYTBCRKLIWC;
/*SET*/	r_n2 = GHTSGBBDHLSICU;
//// [ empty ] 
/*ISEMPTY*/	if (FSRCBDZDFBEOST!=0 && arg_to != FSRCBDZDFBEOST) goto label_TFMMJOUTFVEXDC;

// подготовка подстановки 
DataChain* XKGOQVUFYOGVFR = new DataChain(); 
result->append(newRefExecBrackets(PolnAnaliz, XKGOQVUFYOGVFR, "PolnAnaliz")); 
DataChain* NYMOPFWPNFUZEI = new DataChain(); 
XKGOQVUFYOGVFR->append(newRefStructBrackets(NYMOPFWPNFUZEI)); 
NYMOPFWPNFUZEI->append(newRefText("1")); 
DataChain* HXYXANSPRGGWDY = new DataChain(); 
XKGOQVUFYOGVFR->append(newRefStructBrackets(HXYXANSPRGGWDY)); 
HXYXANSPRGGWDY->append_copy(l_1, r_1); 
DataChain* AFAWQGQBTDGFFC = new DataChain(); 
XKGOQVUFYOGVFR->append(newRefStructBrackets(AFAWQGQBTDGFFC)); 
AFAWQGQBTDGFFC->append_copy(l_2, r_2); 
AFAWQGQBTDGFFC->append_copy(l_A, r_A); 
DataChain* EGTPCYBQVRQUSQ = new DataChain(); 
XKGOQVUFYOGVFR->append(newRefStructBrackets(EGTPCYBQVRQUSQ)); 
EGTPCYBQVRQUSQ->append_copy(l_n1, r_n1); 
EGTPCYBQVRQUSQ->append_copy(l_n2, r_n2); 

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
/*DEF*/	DataCursor SYDYMVPEIBGXFF;
/*DEF*/	DataCursor NOPFYMRMQHUCGO;
/*DEF*/	DataCursor MDIUXEMXBZYSLV;
/*SET*/	SYDYMVPEIBGXFF = arg_from;
/*INC*/	if (!INC(SYDYMVPEIBGXFF, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (SYDYMVPEIBGXFF.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	NOPFYMRMQHUCGO = SYDYMVPEIBGXFF.container->value.bracket_data.chain->at_before_first();
	MDIUXEMXBZYSLV   = SYDYMVPEIBGXFF.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor LITWUBNSPBMEWW;
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = NOPFYMRMQHUCGO;
/*SET*/	LITWUBNSPBMEWW = NOPFYMRMQHUCGO;
/*INC*/	if (!INC(LITWUBNSPBMEWW, MDIUXEMXBZYSLV)) goto sentence_after_1;
	if (! isSymbolType(LITWUBNSPBMEWW.container->type)) goto sentence_after_1;
/*SET*/	r_s = LITWUBNSPBMEWW;
//// [ empty ] 
/*ISEMPTY*/	if (r_s!=0 && MDIUXEMXBZYSLV != r_s) goto sentence_after_1;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor HGPMPRKCYFDXKM;
/*DEF*/	DataCursor TUHEVOIXRWLMXW;
/*DEF*/	DataCursor GCNOYZMMYOVRTE;
/*SET*/	HGPMPRKCYFDXKM = SYDYMVPEIBGXFF;
/*INC*/	if (!INC(HGPMPRKCYFDXKM, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (HGPMPRKCYFDXKM.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	TUHEVOIXRWLMXW = HGPMPRKCYFDXKM.container->value.bracket_data.chain->at_before_first();
	GCNOYZMMYOVRTE   = HGPMPRKCYFDXKM.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = TUHEVOIXRWLMXW;
/*SET*/	r_1 = GCNOYZMMYOVRTE;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor PQTIBDVTHMPOAQ;
/*DEF*/	DataCursor YDDQRXNVKIYADV;
/*DEF*/	DataCursor LOYEMCYCFCPYUW;
/*SET*/	PQTIBDVTHMPOAQ = HGPMPRKCYFDXKM;
/*INC*/	if (!INC(PQTIBDVTHMPOAQ, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (PQTIBDVTHMPOAQ.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	YDDQRXNVKIYADV = PQTIBDVTHMPOAQ.container->value.bracket_data.chain->at_before_first();
	LOYEMCYCFCPYUW   = PQTIBDVTHMPOAQ.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = YDDQRXNVKIYADV;
/*SET*/	r_2 = LOYEMCYCFCPYUW;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor KZEBCJAEDSBVQQ;
/*DEF*/	DataCursor IJQLGJYCJPKPXF;
/*DEF*/	DataCursor LCEONIYVQVURDI;
/*SET*/	KZEBCJAEDSBVQQ = PQTIBDVTHMPOAQ;
/*INC*/	if (!INC(KZEBCJAEDSBVQQ, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (KZEBCJAEDSBVQQ.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	IJQLGJYCJPKPXF = KZEBCJAEDSBVQQ.container->value.bracket_data.chain->at_before_first();
	LCEONIYVQVURDI   = KZEBCJAEDSBVQQ.container->value.bracket_data.chain->at_last();
//// [ empty ] 
/*ISEMPTY*/	if (IJQLGJYCJPKPXF!=0 && LCEONIYVQVURDI != IJQLGJYCJPKPXF) goto sentence_after_1;
//// [ empty ] 
/*ISEMPTY*/	if (KZEBCJAEDSBVQQ!=0 && arg_to != KZEBCJAEDSBVQQ) goto sentence_after_1;

// подготовка подстановки 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor AQMSRTFGWTPEPU;
/*DEF*/	DataCursor NUGEAJDGZSJEWS;
/*DEF*/	DataCursor QRMJZSSBXJVOTJ;
/*SET*/	AQMSRTFGWTPEPU = arg_from;
/*INC*/	if (!INC(AQMSRTFGWTPEPU, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (AQMSRTFGWTPEPU.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	NUGEAJDGZSJEWS = AQMSRTFGWTPEPU.container->value.bracket_data.chain->at_before_first();
	QRMJZSSBXJVOTJ   = AQMSRTFGWTPEPU.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor VJQCFQPTBZGKET;
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = NUGEAJDGZSJEWS;
/*SET*/	VJQCFQPTBZGKET = NUGEAJDGZSJEWS;
/*INC*/	if (!INC(VJQCFQPTBZGKET, QRMJZSSBXJVOTJ)) goto sentence_after_2;
	if (! isSymbolType(VJQCFQPTBZGKET.container->type)) goto sentence_after_2;
/*SET*/	r_s = VJQCFQPTBZGKET;
//// [ empty ] 
/*ISEMPTY*/	if (r_s!=0 && QRMJZSSBXJVOTJ != r_s) goto sentence_after_2;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor QKITTRHYUBKEWF;
/*DEF*/	DataCursor EKRCIHHXJEIGUT;
/*DEF*/	DataCursor WIGDBBDXRBWMBR;
/*SET*/	QKITTRHYUBKEWF = AQMSRTFGWTPEPU;
/*INC*/	if (!INC(QKITTRHYUBKEWF, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (QKITTRHYUBKEWF.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	EKRCIHHXJEIGUT = QKITTRHYUBKEWF.container->value.bracket_data.chain->at_before_first();
	WIGDBBDXRBWMBR   = QKITTRHYUBKEWF.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = EKRCIHHXJEIGUT;
/*SET*/	r_1 = WIGDBBDXRBWMBR;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor MBVGAOWLVDJYDD;
/*DEF*/	DataCursor YCTCOCKMGZVARP;
/*DEF*/	DataCursor FOBGMHPAOJOIQP;
/*SET*/	MBVGAOWLVDJYDD = QKITTRHYUBKEWF;
/*INC*/	if (!INC(MBVGAOWLVDJYDD, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (MBVGAOWLVDJYDD.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	YCTCOCKMGZVARP = MBVGAOWLVDJYDD.container->value.bracket_data.chain->at_before_first();
	FOBGMHPAOJOIQP   = MBVGAOWLVDJYDD.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = YCTCOCKMGZVARP;
/*SET*/	r_2 = FOBGMHPAOJOIQP;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor QTXTUCRORYSMGT;
/*DEF*/	DataCursor XCFZLBJBIPFIMU;
/*DEF*/	DataCursor NEZPQAQJASIXVW;
/*SET*/	QTXTUCRORYSMGT = MBVGAOWLVDJYDD;
/*INC*/	if (!INC(QTXTUCRORYSMGT, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (QTXTUCRORYSMGT.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	XCFZLBJBIPFIMU = QTXTUCRORYSMGT.container->value.bracket_data.chain->at_before_first();
	NEZPQAQJASIXVW   = QTXTUCRORYSMGT.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = XCFZLBJBIPFIMU;
/*SET*/	r_3 = XCFZLBJBIPFIMU;
/*JMP*/	goto label_OQYJVXKHCQPQIA_firststep;
label_OQYJVXKHCQPQIA: 
/*INC*/	if (!INC(r_3, NEZPQAQJASIXVW)) goto sentence_after_2;
label_OQYJVXKHCQPQIA_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor BUBQQDOFEHHJTZ;
/*SET*/	BUBQQDOFEHHJTZ = r_3;
/*INC*/	if (!INC(BUBQQDOFEHHJTZ, NEZPQAQJASIXVW)) goto label_OQYJVXKHCQPQIA;
	if (BUBQQDOFEHHJTZ.container->type != text || *(BUBQQDOFEHHJTZ.container->value.text + BUBQQDOFEHHJTZ.index) != '>') goto label_OQYJVXKHCQPQIA;
//// [ empty ] 
/*ISEMPTY*/	if (BUBQQDOFEHHJTZ!=0 && NEZPQAQJASIXVW != BUBQQDOFEHHJTZ) goto label_OQYJVXKHCQPQIA;
//// [ empty ] 
/*ISEMPTY*/	if (QTXTUCRORYSMGT!=0 && arg_to != QTXTUCRORYSMGT) goto label_OQYJVXKHCQPQIA;

// подготовка подстановки 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor KOYLPNZOIPZWDM;
/*DEF*/	DataCursor KRBHDNTDKVPDEL;
/*DEF*/	DataCursor ORQCJKQZZPINOQ;
/*SET*/	KOYLPNZOIPZWDM = arg_from;
/*INC*/	if (!INC(KOYLPNZOIPZWDM, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (KOYLPNZOIPZWDM.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	KRBHDNTDKVPDEL = KOYLPNZOIPZWDM.container->value.bracket_data.chain->at_before_first();
	ORQCJKQZZPINOQ   = KOYLPNZOIPZWDM.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor LUIBJGNQQLFEWI;
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = KRBHDNTDKVPDEL;
/*SET*/	LUIBJGNQQLFEWI = KRBHDNTDKVPDEL;
/*INC*/	if (!INC(LUIBJGNQQLFEWI, ORQCJKQZZPINOQ)) goto sentence_after_3;
	if (! isSymbolType(LUIBJGNQQLFEWI.container->type)) goto sentence_after_3;
/*SET*/	r_s = LUIBJGNQQLFEWI;
//// [ empty ] 
/*ISEMPTY*/	if (r_s!=0 && ORQCJKQZZPINOQ != r_s) goto sentence_after_3;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor OAMGMRCEMOAXVU;
/*DEF*/	DataCursor FYQYPCHHGFMIZR;
/*DEF*/	DataCursor CKLYHBPJJZRRUG;
/*SET*/	OAMGMRCEMOAXVU = KOYLPNZOIPZWDM;
/*INC*/	if (!INC(OAMGMRCEMOAXVU, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (OAMGMRCEMOAXVU.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	FYQYPCHHGFMIZR = OAMGMRCEMOAXVU.container->value.bracket_data.chain->at_before_first();
	CKLYHBPJJZRRUG   = OAMGMRCEMOAXVU.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_I;
/*DEF*/	DataCursor r_I;
/*SET*/	l_I = FYQYPCHHGFMIZR;
/*SET*/	r_I = CKLYHBPJJZRRUG;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor OFLUIOIVOVXMRA;
/*DEF*/	DataCursor WZSWPFNCNFYTMC;
/*DEF*/	DataCursor FVWNRMFZGPZPOL;
/*SET*/	OFLUIOIVOVXMRA = OAMGMRCEMOAXVU;
/*INC*/	if (!INC(OFLUIOIVOVXMRA, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (OFLUIOIVOVXMRA.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	WZSWPFNCNFYTMC = OFLUIOIVOVXMRA.container->value.bracket_data.chain->at_before_first();
	FVWNRMFZGPZPOL   = OFLUIOIVOVXMRA.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_Y;
/*DEF*/	DataCursor r_Y;
/*SET*/	l_Y = WZSWPFNCNFYTMC;
/*SET*/	r_Y = FVWNRMFZGPZPOL;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor TVNBMVWTHJSVHB;
/*DEF*/	DataCursor XSEWQYCKWEXZPM;
/*DEF*/	DataCursor IEXGRJXJMDWBQY;
/*SET*/	TVNBMVWTHJSVHB = OFLUIOIVOVXMRA;
/*INC*/	if (!INC(TVNBMVWTHJSVHB, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (TVNBMVWTHJSVHB.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	XSEWQYCKWEXZPM = TVNBMVWTHJSVHB.container->value.bracket_data.chain->at_before_first();
	IEXGRJXJMDWBQY   = TVNBMVWTHJSVHB.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = XSEWQYCKWEXZPM;
/*SET*/	r_1 = XSEWQYCKWEXZPM;
/*JMP*/	goto label_UIPXARRBPHNZWK_firststep;
label_UIPXARRBPHNZWK: 
/*INC*/	if (!INC(r_1, IEXGRJXJMDWBQY)) goto sentence_after_3;
label_UIPXARRBPHNZWK_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor BCLGBVOCYUZUTZ;
/*SET*/	BCLGBVOCYUZUTZ = r_1;
/*INC*/	if (!INC(BCLGBVOCYUZUTZ, IEXGRJXJMDWBQY)) goto label_UIPXARRBPHNZWK;
	if (BCLGBVOCYUZUTZ.container->type != text || *(BCLGBVOCYUZUTZ.container->value.text + BCLGBVOCYUZUTZ.index) != '>') goto label_UIPXARRBPHNZWK;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor YPIROCYYUCCLQZ;
/*DEF*/	DataCursor l_sss;
/*DEF*/	DataCursor r_sss;
/*SET*/	l_sss = BCLGBVOCYUZUTZ;
/*SET*/	YPIROCYYUCCLQZ = BCLGBVOCYUZUTZ;
/*INC*/	if (!INC(YPIROCYYUCCLQZ, IEXGRJXJMDWBQY)) goto label_UIPXARRBPHNZWK;
	if (! isSymbolType(YPIROCYYUCCLQZ.container->type)) goto label_UIPXARRBPHNZWK;
/*SET*/	r_sss = YPIROCYYUCCLQZ;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = r_sss;
/*SET*/	r_2 = IEXGRJXJMDWBQY;
//// [ empty ] 
/*ISEMPTY*/	if (TVNBMVWTHJSVHB!=0 && arg_to != TVNBMVWTHJSVHB) goto label_UIPXARRBPHNZWK;

// подготовка подстановки 
DataChain* JRMGSXOCKDRAAU = new DataChain(); 
result->append(newRefExecBrackets(Analiz, JRMGSXOCKDRAAU, "Analiz")); 
DataChain* ACXKPMRFLSPDLQ = new DataChain(); 
JRMGSXOCKDRAAU->append(newRefStructBrackets(ACXKPMRFLSPDLQ)); 
ACXKPMRFLSPDLQ->append_copy(l_s, r_s); 
DataChain* KEWYQJFTFWAHGQ = new DataChain(); 
JRMGSXOCKDRAAU->append(newRefStructBrackets(KEWYQJFTFWAHGQ)); 
KEWYQJFTFWAHGQ->append_copy(l_I, r_I); 
DataChain* OHKQNKTTIQFYRH = new DataChain(); 
JRMGSXOCKDRAAU->append(newRefStructBrackets(OHKQNKTTIQFYRH)); 
OHKQNKTTIQFYRH->append_copy(l_Y, r_Y); 
DataChain* DSGEUEIVKRNEZU = new DataChain(); 
JRMGSXOCKDRAAU->append(newRefStructBrackets(DSGEUEIVKRNEZU)); 
DSGEUEIVKRNEZU->append_copy(l_1, r_1); 
DSGEUEIVKRNEZU->append(newRefText(">")); 
DSGEUEIVKRNEZU->append_copy(l_sss, r_sss); 
DSGEUEIVKRNEZU->append_copy(l_2, r_2); 
DataChain* MCIRZFQXOZFCUH = new DataChain(); 
result->append(newRefExecBrackets(PolnAnaliz, MCIRZFQXOZFCUH, "PolnAnaliz")); 
DataChain* CNSCQKCJBCHVRS = new DataChain(); 
MCIRZFQXOZFCUH->append(newRefStructBrackets(CNSCQKCJBCHVRS)); 
CNSCQKCJBCHVRS->append_copy(l_s, r_s); 
DataChain* PZOTKDBIDWWYGO = new DataChain(); 
MCIRZFQXOZFCUH->append(newRefStructBrackets(PZOTKDBIDWWYGO)); 
PZOTKDBIDWWYGO->append_copy(l_I, r_I); 
DataChain* WWQHNZFJQHFGIM = new DataChain(); 
MCIRZFQXOZFCUH->append(newRefStructBrackets(WWQHNZFJQHFGIM)); 
WWQHNZFJQHFGIM->append_copy(l_Y, r_Y); 
DataChain* WJGRJVQSPOOSLA = new DataChain(); 
MCIRZFQXOZFCUH->append(newRefStructBrackets(WJGRJVQSPOOSLA)); 
WJGRJVQSPOOSLA->append_copy(l_1, r_1); 
WJGRJVQSPOOSLA->append_copy(l_sss, r_sss); 
WJGRJVQSPOOSLA->append(newRefText(">")); 
WJGRJVQSPOOSLA->append_copy(l_2, r_2); 

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
/*JMP*/	goto label_QKXZEHZEGKWUTI_firststep;
label_QKXZEHZEGKWUTI: 
/*INC*/	if (!INC(r_sIY, arg_to)) goto sentence_after_4;
label_QKXZEHZEGKWUTI_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor YPZVVZTDURGODX;
/*DEF*/	DataCursor VAAHGUIGPSGLHA;
/*DEF*/	DataCursor BNQBWTQMBDSMBF;
/*SET*/	YPZVVZTDURGODX = r_sIY;
/*INC*/	if (!INC(YPZVVZTDURGODX, arg_to)) goto label_QKXZEHZEGKWUTI;
//// ISBRACKET 
	if (YPZVVZTDURGODX.container->type != struct_bracket) goto label_QKXZEHZEGKWUTI;
//// JMP_BRACKET 
	VAAHGUIGPSGLHA = YPZVVZTDURGODX.container->value.bracket_data.chain->at_before_first();
	BNQBWTQMBDSMBF   = YPZVVZTDURGODX.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = VAAHGUIGPSGLHA;
/*SET*/	r_1 = BNQBWTQMBDSMBF;
//// [ empty ] 
/*ISEMPTY*/	if (YPZVVZTDURGODX!=0 && arg_to != YPZVVZTDURGODX) goto label_QKXZEHZEGKWUTI;

// подготовка подстановки 
DataChain* ZTHYUMQUOWLDNO = new DataChain(); 
result->append(newRefExecBrackets(PolnAnaliz, ZTHYUMQUOWLDNO, "PolnAnaliz")); 
ZTHYUMQUOWLDNO->append_copy(l_sIY, r_sIY); 
DataChain* VUCOIMMQSZMSRZ = new DataChain(); 
ZTHYUMQUOWLDNO->append(newRefStructBrackets(VUCOIMMQSZMSRZ)); 
VUCOIMMQSZMSRZ->append(newRefText(">")); 
VUCOIMMQSZMSRZ->append_copy(l_1, r_1); 

return result; 
}
sentence_after_4: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

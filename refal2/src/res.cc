#include "direfal.h" 
#include "commands.h" 
#include "system.h" 
#include "res.h" 

DataChain* Go(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ empty ] 
/*ISEMPTY*/	if (arg_from!=0 && arg_to != arg_from) goto sentence_after_1;

// подготовка подстановки 
DataChain* PHQGHUMEAYLNLF = new DataChain(); 
DataContainer* PHQGHUMEAYLNLF_execbr = newRefExecBrackets(Begin, PHQGHUMEAYLNLF, "Begin");
result->append(PHQGHUMEAYLNLF_execbr);
PHQGHUMEAYLNLF->append(newRefInteger(100)); 
context->pushExecuteCall(PHQGHUMEAYLNLF_execbr);

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Begin(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
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
DataContainer* SRTKJPREPGGXRP_execbr = newRefExecBrackets(Prout, SRTKJPREPGGXRP, "Prout");
result->append(SRTKJPREPGGXRP_execbr);
SRTKJPREPGGXRP->append(newRefText("Who is first? (1 - pc  2 - you)")); 
context->pushExecuteCall(SRTKJPREPGGXRP_execbr);
DataChain* NRVYSTMWCYSYYC = new DataChain(); 
DataContainer* NRVYSTMWCYSYYC_execbr = newRefExecBrackets(FirG, NRVYSTMWCYSYYC, "FirG");
result->append(NRVYSTMWCYSYYC_execbr);
DataChain* QPEVIKEFFMZNIM = new DataChain(); 
DataContainer* QPEVIKEFFMZNIM_execbr = newRefExecBrackets(Card, QPEVIKEFFMZNIM, "Card");
NRVYSTMWCYSYYC->append(QPEVIKEFFMZNIM_execbr);
context->pushExecuteCall(QPEVIKEFFMZNIM_execbr);
context->pushExecuteCall(NRVYSTMWCYSYYC_execbr);
DataChain* KKASVWSRENZKYC = new DataChain(); 
DataContainer* KKASVWSRENZKYC_execbr = newRefExecBrackets(Begin, KKASVWSRENZKYC, "Begin");
result->append(KKASVWSRENZKYC_execbr);
DataChain* XFXTLSGYPSFADP = new DataChain(); 
DataContainer* XFXTLSGYPSFADP_execbr = newRefExecBrackets(Dec, XFXTLSGYPSFADP, "-");
KKASVWSRENZKYC->append(XFXTLSGYPSFADP_execbr);
XFXTLSGYPSFADP->append_copy(l_n, r_n); 
XFXTLSGYPSFADP->append(newRefInteger(1)); 
context->pushExecuteCall(XFXTLSGYPSFADP_execbr);
context->pushExecuteCall(KKASVWSRENZKYC_execbr);

return result; 
}
sentence_after_2: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* FirG(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
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
DataContainer* NPLJVRVIPYAMYE_execbr = newRefExecBrackets(Game, NPLJVRVIPYAMYE, "Game");
result->append(NPLJVRVIPYAMYE_execbr);
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
context->pushExecuteCall(NPLJVRVIPYAMYE_execbr);

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
DataContainer* AUGZQRCDDIUTEI_execbr = newRefExecBrackets(Game, AUGZQRCDDIUTEI, "Game");
result->append(AUGZQRCDDIUTEI_execbr);
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
context->pushExecuteCall(AUGZQRCDDIUTEI_execbr);

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
DataChain* FWLQIJTVDWVXHR = new DataChain(); 
DataContainer* FWLQIJTVDWVXHR_execbr = newRefExecBrackets(Exit, FWLQIJTVDWVXHR, "Exit");
result->append(FWLQIJTVDWVXHR_execbr);
FWLQIJTVDWVXHR->append(newRefInteger(0)); 
context->pushExecuteCall(FWLQIJTVDWVXHR_execbr);

return result; 
}
sentence_after_3: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Game__(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
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
DataChain* CBLDVGYLWGBUSB = new DataChain(); 
DataContainer* CBLDVGYLWGBUSB_execbr = newRefExecBrackets(Prout, CBLDVGYLWGBUSB, "Prout");
result->append(CBLDVGYLWGBUSB_execbr);
CBLDVGYLWGBUSB->append(newRefWord("Game:")); 
CBLDVGYLWGBUSB->append_copy(l_e, r_e); 
context->pushExecuteCall(CBLDVGYLWGBUSB_execbr);
DataChain* MBORXTLHCSMPXO = new DataChain(); 
DataContainer* MBORXTLHCSMPXO_execbr = newRefExecBrackets(Game__, MBORXTLHCSMPXO, "Game__");
result->append(MBORXTLHCSMPXO_execbr);
MBORXTLHCSMPXO->append_copy(l_e, r_e); 
context->pushExecuteCall(MBORXTLHCSMPXO_execbr);

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Game(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor HGMGNKEUFDXOTO;
/*DEF*/	DataCursor GBGXPEYANFETCU;
/*DEF*/	DataCursor KEPZSHKLJUGGGE;
/*SET*/	HGMGNKEUFDXOTO = arg_from;
/*INC*/	if (!INC(HGMGNKEUFDXOTO, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (HGMGNKEUFDXOTO.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	GBGXPEYANFETCU = HGMGNKEUFDXOTO.container->value.bracket_data.chain->at_before_first();
	KEPZSHKLJUGGGE   = HGMGNKEUFDXOTO.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor KJDQZJENPEVQGX;
/*DEF*/	DataCursor l_g;
/*DEF*/	DataCursor r_g;
/*SET*/	l_g = GBGXPEYANFETCU;
/*SET*/	KJDQZJENPEVQGX = GBGXPEYANFETCU;
/*INC*/	if (!INC(KJDQZJENPEVQGX, KEPZSHKLJUGGGE)) goto sentence_after_1;
	if (! isSymbolType(KJDQZJENPEVQGX.container->type)) goto sentence_after_1;
/*SET*/	r_g = KJDQZJENPEVQGX;
//// [ empty ] 
/*ISEMPTY*/	if (r_g!=0 && KEPZSHKLJUGGGE != r_g) goto sentence_after_1;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor IEPJSRDZJAZUJL;
/*DEF*/	DataCursor LCHHBFQMKIMWZO;
/*DEF*/	DataCursor BIWYBXDUUNFSKS;
/*SET*/	IEPJSRDZJAZUJL = HGMGNKEUFDXOTO;
/*INC*/	if (!INC(IEPJSRDZJAZUJL, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (IEPJSRDZJAZUJL.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	LCHHBFQMKIMWZO = IEPJSRDZJAZUJL.container->value.bracket_data.chain->at_before_first();
	BIWYBXDUUNFSKS   = IEPJSRDZJAZUJL.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = LCHHBFQMKIMWZO;
/*SET*/	r_1 = BIWYBXDUUNFSKS;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor RSRTEKMQDCYZJE;
/*DEF*/	DataCursor EUHMSRQCOZIJIP;
/*DEF*/	DataCursor FIONEEDDPSZRNA;
/*SET*/	RSRTEKMQDCYZJE = IEPJSRDZJAZUJL;
/*INC*/	if (!INC(RSRTEKMQDCYZJE, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (RSRTEKMQDCYZJE.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	EUHMSRQCOZIJIP = RSRTEKMQDCYZJE.container->value.bracket_data.chain->at_before_first();
	FIONEEDDPSZRNA   = RSRTEKMQDCYZJE.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = EUHMSRQCOZIJIP;
/*SET*/	r_2 = FIONEEDDPSZRNA;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor VYMMTATBDZQSOE;
/*DEF*/	DataCursor MUVNPPPSUACBAZ;
/*DEF*/	DataCursor UXMHECTHLEGRPU;
/*SET*/	VYMMTATBDZQSOE = RSRTEKMQDCYZJE;
/*INC*/	if (!INC(VYMMTATBDZQSOE, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (VYMMTATBDZQSOE.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	MUVNPPPSUACBAZ = VYMMTATBDZQSOE.container->value.bracket_data.chain->at_before_first();
	UXMHECTHLEGRPU   = VYMMTATBDZQSOE.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = MUVNPPPSUACBAZ;
/*SET*/	r_n = UXMHECTHLEGRPU;
//// [ empty ] 
/*ISEMPTY*/	if (VYMMTATBDZQSOE!=0 && arg_to != VYMMTATBDZQSOE) goto sentence_after_1;

// подготовка подстановки 
DataChain* NKDMBPPWEQTGJO = new DataChain(); 
DataContainer* NKDMBPPWEQTGJO_execbr = newRefExecBrackets(Ekran, NKDMBPPWEQTGJO, "Ekran");
result->append(NKDMBPPWEQTGJO_execbr);
DataChain* PARMOWZDQYOXYT = new DataChain(); 
NKDMBPPWEQTGJO->append(newRefStructBrackets(PARMOWZDQYOXYT)); 
PARMOWZDQYOXYT->append_copy(l_1, r_1); 
DataChain* JBBHAWDYDCPRJB = new DataChain(); 
NKDMBPPWEQTGJO->append(newRefStructBrackets(JBBHAWDYDCPRJB)); 
JBBHAWDYDCPRJB->append_copy(l_2, r_2); 
context->pushExecuteCall(NKDMBPPWEQTGJO_execbr);
DataChain* XPHOOHPKWQYUHR = new DataChain(); 
DataContainer* XPHOOHPKWQYUHR_execbr = newRefExecBrackets(GameIfWin, XPHOOHPKWQYUHR, "GameIfWin");
result->append(XPHOOHPKWQYUHR_execbr);
DataChain* QZHNBNFUVQNQQL = new DataChain(); 
DataContainer* QZHNBNFUVQNQQL_execbr = newRefExecBrackets(Ifwin, QZHNBNFUVQNQQL, "Ifwin");
XPHOOHPKWQYUHR->append(QZHNBNFUVQNQQL_execbr);
DataChain* RZJPXIOGVLIEXD = new DataChain(); 
QZHNBNFUVQNQQL->append(newRefStructBrackets(RZJPXIOGVLIEXD)); 
RZJPXIOGVLIEXD->append_copy(l_1, r_1); 
DataChain* ZUZOSRKRUSVOJB = new DataChain(); 
QZHNBNFUVQNQQL->append(newRefStructBrackets(ZUZOSRKRUSVOJB)); 
ZUZOSRKRUSVOJB->append_copy(l_2, r_2); 
context->pushExecuteCall(QZHNBNFUVQNQQL_execbr);
DataChain* RZMWZPOWKJILEF = new DataChain(); 
XPHOOHPKWQYUHR->append(newRefStructBrackets(RZMWZPOWKJILEF)); 
RZMWZPOWKJILEF->append_copy(l_g, r_g); 
DataChain* RAAMDIGPNPUUHG = new DataChain(); 
XPHOOHPKWQYUHR->append(newRefStructBrackets(RAAMDIGPNPUUHG)); 
RAAMDIGPNPUUHG->append_copy(l_1, r_1); 
DataChain* XPQNJWJMWAXXMN = new DataChain(); 
XPHOOHPKWQYUHR->append(newRefStructBrackets(XPQNJWJMWAXXMN)); 
XPQNJWJMWAXXMN->append_copy(l_2, r_2); 
DataChain* SNHHLQQRZUDLTF = new DataChain(); 
XPHOOHPKWQYUHR->append(newRefStructBrackets(SNHHLQQRZUDLTF)); 
SNHHLQQRZUDLTF->append_copy(l_n, r_n); 
context->pushExecuteCall(XPHOOHPKWQYUHR_execbr);

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

DataChain* GameIfWin(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor ZOTCJTNZXUGLSD;
/*SET*/	ZOTCJTNZXUGLSD = arg_from;
/*INC*/	if (!INC(ZOTCJTNZXUGLSD, arg_to)) goto sentence_after_1;
	if (ZOTCJTNZXUGLSD.container->type != text || *(ZOTCJTNZXUGLSD.container->value.text + ZOTCJTNZXUGLSD.index) != '0') goto sentence_after_1;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = ZOTCJTNZXUGLSD;
/*SET*/	r_e = ZOTCJTNZXUGLSD;
/*JMP*/	goto label_SMZCNOCKVFAJFR_firststep;
label_SMZCNOCKVFAJFR: 
/*INC*/	if (!INC(r_e, arg_to)) goto sentence_after_1;
label_SMZCNOCKVFAJFR_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor MXOTHOWKBJZWUC;
/*DEF*/	DataCursor WLJFRIMPMYHCHZ;
/*DEF*/	DataCursor RIWKBARXBGFCBC;
/*SET*/	MXOTHOWKBJZWUC = r_e;
/*INC*/	if (!INC(MXOTHOWKBJZWUC, arg_to)) goto label_SMZCNOCKVFAJFR;
//// ISBRACKET 
	if (MXOTHOWKBJZWUC.container->type != struct_bracket) goto label_SMZCNOCKVFAJFR;
//// JMP_BRACKET 
	WLJFRIMPMYHCHZ = MXOTHOWKBJZWUC.container->value.bracket_data.chain->at_before_first();
	RIWKBARXBGFCBC   = MXOTHOWKBJZWUC.container->value.bracket_data.chain->at_last();
//// [ empty ] 
/*ISEMPTY*/	if (WLJFRIMPMYHCHZ!=0 && RIWKBARXBGFCBC != WLJFRIMPMYHCHZ) goto label_SMZCNOCKVFAJFR;
//// [ empty ] 
/*ISEMPTY*/	if (MXOTHOWKBJZWUC!=0 && arg_to != MXOTHOWKBJZWUC) goto label_SMZCNOCKVFAJFR;

// подготовка подстановки 
DataChain* EHBBCPXIFBXVFB = new DataChain(); 
DataContainer* EHBBCPXIFBXVFB_execbr = newRefExecBrackets(Prout, EHBBCPXIFBXVFB, "Prout");
result->append(EHBBCPXIFBXVFB_execbr);
EHBBCPXIFBXVFB->append(newRefText("Nobody !!!.")); 
context->pushExecuteCall(EHBBCPXIFBXVFB_execbr);

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor CGKCFQCKCOTZGK;
/*SET*/	CGKCFQCKCOTZGK = arg_from;
/*INC*/	if (!INC(CGKCFQCKCOTZGK, arg_to)) goto sentence_after_2;
	if (CGKCFQCKCOTZGK.container->type != text || *(CGKCFQCKCOTZGK.container->value.text + CGKCFQCKCOTZGK.index) != '1') goto sentence_after_2;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = CGKCFQCKCOTZGK;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* ROEFWSJRXJHGUZ = new DataChain(); 
DataContainer* ROEFWSJRXJHGUZ_execbr = newRefExecBrackets(Prout, ROEFWSJRXJHGUZ, "Prout");
result->append(ROEFWSJRXJHGUZ_execbr);
ROEFWSJRXJHGUZ->append(newRefText("Winner X")); 
context->pushExecuteCall(ROEFWSJRXJHGUZ_execbr);

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor YUPZWWEIQURPIX;
/*SET*/	YUPZWWEIQURPIX = arg_from;
/*INC*/	if (!INC(YUPZWWEIQURPIX, arg_to)) goto sentence_after_3;
	if (YUPZWWEIQURPIX.container->type != text || *(YUPZWWEIQURPIX.container->value.text + YUPZWWEIQURPIX.index) != '2') goto sentence_after_3;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = YUPZWWEIQURPIX;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* UDHNEFNJHAIMUC = new DataChain(); 
DataContainer* UDHNEFNJHAIMUC_execbr = newRefExecBrackets(Prout, UDHNEFNJHAIMUC, "Prout");
result->append(UDHNEFNJHAIMUC_execbr);
UDHNEFNJHAIMUC->append(newRefText("Winner O")); 
context->pushExecuteCall(UDHNEFNJHAIMUC_execbr);

return result; 
}
sentence_after_3: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor ZFSKUIDUBURISW;
/*SET*/	ZFSKUIDUBURISW = arg_from;
/*INC*/	if (!INC(ZFSKUIDUBURISW, arg_to)) goto sentence_after_4;
	if (ZFSKUIDUBURISW.container->type != text || *(ZFSKUIDUBURISW.container->value.text + ZFSKUIDUBURISW.index) != '0') goto sentence_after_4;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = ZFSKUIDUBURISW;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* DZEZTOIDUKUHJZ = new DataChain(); 
DataContainer* DZEZTOIDUKUHJZ_execbr = newRefExecBrackets(Game1, DZEZTOIDUKUHJZ, "Game1");
result->append(DZEZTOIDUKUHJZ_execbr);
DZEZTOIDUKUHJZ->append_copy(l_e, r_e); 
context->pushExecuteCall(DZEZTOIDUKUHJZ_execbr);

return result; 
}
sentence_after_4: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Game1__(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
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
DataChain* EFCZZZBFKQDPQZ = new DataChain(); 
DataContainer* EFCZZZBFKQDPQZ_execbr = newRefExecBrackets(Prout, EFCZZZBFKQDPQZ, "Prout");
result->append(EFCZZZBFKQDPQZ_execbr);
EFCZZZBFKQDPQZ->append(newRefWord("Game1:")); 
EFCZZZBFKQDPQZ->append_copy(l_e, r_e); 
context->pushExecuteCall(EFCZZZBFKQDPQZ_execbr);
DataChain* IKFOBUCDHTHXDJ = new DataChain(); 
DataContainer* IKFOBUCDHTHXDJ_execbr = newRefExecBrackets(Game1__, IKFOBUCDHTHXDJ, "Game1__");
result->append(IKFOBUCDHTHXDJ_execbr);
IKFOBUCDHTHXDJ->append_copy(l_e, r_e); 
context->pushExecuteCall(IKFOBUCDHTHXDJ_execbr);

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Game1(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor GKJELRLPAXAMCE;
/*DEF*/	DataCursor ROSWITDPTPCCLI;
/*DEF*/	DataCursor FKELJYTIHRCQAY;
/*SET*/	GKJELRLPAXAMCE = arg_from;
/*INC*/	if (!INC(GKJELRLPAXAMCE, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (GKJELRLPAXAMCE.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	ROSWITDPTPCCLI = GKJELRLPAXAMCE.container->value.bracket_data.chain->at_before_first();
	FKELJYTIHRCQAY   = GKJELRLPAXAMCE.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor BNEFXNXVGZEDYY;
/*SET*/	BNEFXNXVGZEDYY = ROSWITDPTPCCLI;
/*INC*/	if (!INC(BNEFXNXVGZEDYY, FKELJYTIHRCQAY)) goto sentence_after_1;
	if (BNEFXNXVGZEDYY.container->type != text || *(BNEFXNXVGZEDYY.container->value.text + BNEFXNXVGZEDYY.index) != '1') goto sentence_after_1;
//// [ empty ] 
/*ISEMPTY*/	if (BNEFXNXVGZEDYY!=0 && FKELJYTIHRCQAY != BNEFXNXVGZEDYY) goto sentence_after_1;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_12;
/*DEF*/	DataCursor r_12;
/*SET*/	l_12 = GKJELRLPAXAMCE;
/*SET*/	r_12 = GKJELRLPAXAMCE;
/*JMP*/	goto label_CKOTRWOSPOFGHF_firststep;
label_CKOTRWOSPOFGHF: 
/*INC*/	if (!INC(r_12, arg_to)) goto sentence_after_1;
label_CKOTRWOSPOFGHF_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor OZQVLQFXWWKMFX;
/*DEF*/	DataCursor DYYGMDCASZSGOV;
/*DEF*/	DataCursor SODKJGHCWMBMXR;
/*SET*/	OZQVLQFXWWKMFX = r_12;
/*INC*/	if (!INC(OZQVLQFXWWKMFX, arg_to)) goto label_CKOTRWOSPOFGHF;
//// ISBRACKET 
	if (OZQVLQFXWWKMFX.container->type != struct_bracket) goto label_CKOTRWOSPOFGHF;
//// JMP_BRACKET 
	DYYGMDCASZSGOV = OZQVLQFXWWKMFX.container->value.bracket_data.chain->at_before_first();
	SODKJGHCWMBMXR   = OZQVLQFXWWKMFX.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = DYYGMDCASZSGOV;
/*SET*/	r_n = SODKJGHCWMBMXR;
//// [ empty ] 
/*ISEMPTY*/	if (OZQVLQFXWWKMFX!=0 && arg_to != OZQVLQFXWWKMFX) goto label_CKOTRWOSPOFGHF;

// подготовка подстановки 
DataChain* MHUYFYQGAJQKCK = new DataChain(); 
DataContainer* MHUYFYQGAJQKCK_execbr = newRefExecBrackets(Prout, MHUYFYQGAJQKCK, "Prout");
result->append(MHUYFYQGAJQKCK_execbr);
MHUYFYQGAJQKCK->append(newRefText("hmm ...")); 
context->pushExecuteCall(MHUYFYQGAJQKCK_execbr);
DataChain* LZNAYXQKQOYZWM = new DataChain(); 
DataContainer* LZNAYXQKQOYZWM_execbr = newRefExecBrackets(Game, LZNAYXQKQOYZWM, "Game");
result->append(LZNAYXQKQOYZWM_execbr);
DataChain* YUBZAZCPKHKTKY = new DataChain(); 
LZNAYXQKQOYZWM->append(newRefStructBrackets(YUBZAZCPKHKTKY)); 
YUBZAZCPKHKTKY->append(newRefText("2")); 
DataChain* DZIVCUYPURFMBI = new DataChain(); 
DataContainer* DZIVCUYPURFMBI_execbr = newRefExecBrackets(PlayerHod, DZIVCUYPURFMBI, "PlayerHod");
LZNAYXQKQOYZWM->append(DZIVCUYPURFMBI_execbr);
DZIVCUYPURFMBI->append(newRefText("1")); 
DataChain* SGEKYRGZVXDHPO = new DataChain(); 
DataContainer* SGEKYRGZVXDHPO_execbr = newRefExecBrackets(GetHod, SGEKYRGZVXDHPO, "GetHod");
DZIVCUYPURFMBI->append(SGEKYRGZVXDHPO_execbr);
SGEKYRGZVXDHPO->append(newRefText("1")); 
DataChain* AMVAFYRARXSVKH = new DataChain(); 
SGEKYRGZVXDHPO->append(newRefStructBrackets(AMVAFYRARXSVKH)); 
AMVAFYRARXSVKH->append(newRefText("1")); 
SGEKYRGZVXDHPO->append_copy(l_12, r_12); 
DataChain* TQDIHERSIGBHZJ = new DataChain(); 
SGEKYRGZVXDHPO->append(newRefStructBrackets(TQDIHERSIGBHZJ)); 
TQDIHERSIGBHZJ->append_copy(l_n, r_n); 
context->pushExecuteCall(SGEKYRGZVXDHPO_execbr);
DZIVCUYPURFMBI->append_copy(l_12, r_12); 
DataChain* ZUJXMMYSPNARAE = new DataChain(); 
DZIVCUYPURFMBI->append(newRefStructBrackets(ZUJXMMYSPNARAE)); 
ZUJXMMYSPNARAE->append_copy(l_n, r_n); 
context->pushExecuteCall(DZIVCUYPURFMBI_execbr);
context->pushExecuteCall(LZNAYXQKQOYZWM_execbr);

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor WKEGJCCVHHRJVB;
/*DEF*/	DataCursor JTSQDJOOTGPKNF;
/*DEF*/	DataCursor PFYCGFIEOWQRWW;
/*SET*/	WKEGJCCVHHRJVB = arg_from;
/*INC*/	if (!INC(WKEGJCCVHHRJVB, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (WKEGJCCVHHRJVB.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	JTSQDJOOTGPKNF = WKEGJCCVHHRJVB.container->value.bracket_data.chain->at_before_first();
	PFYCGFIEOWQRWW   = WKEGJCCVHHRJVB.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor WPZSQMETOGEPSP;
/*SET*/	WPZSQMETOGEPSP = JTSQDJOOTGPKNF;
/*INC*/	if (!INC(WPZSQMETOGEPSP, PFYCGFIEOWQRWW)) goto sentence_after_2;
	if (WPZSQMETOGEPSP.container->type != text || *(WPZSQMETOGEPSP.container->value.text + WPZSQMETOGEPSP.index) != '2') goto sentence_after_2;
//// [ empty ] 
/*ISEMPTY*/	if (WPZSQMETOGEPSP!=0 && PFYCGFIEOWQRWW != WPZSQMETOGEPSP) goto sentence_after_2;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_12;
/*DEF*/	DataCursor r_12;
/*SET*/	l_12 = WKEGJCCVHHRJVB;
/*SET*/	r_12 = WKEGJCCVHHRJVB;
/*JMP*/	goto label_MNUVKLHSECDWRA_firststep;
label_MNUVKLHSECDWRA: 
/*INC*/	if (!INC(r_12, arg_to)) goto sentence_after_2;
label_MNUVKLHSECDWRA_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor CGFMZKGIPDFODK;
/*DEF*/	DataCursor JMJQWIQPUOQHIM;
/*DEF*/	DataCursor VFVUZWYVIJGFUL;
/*SET*/	CGFMZKGIPDFODK = r_12;
/*INC*/	if (!INC(CGFMZKGIPDFODK, arg_to)) goto label_MNUVKLHSECDWRA;
//// ISBRACKET 
	if (CGFMZKGIPDFODK.container->type != struct_bracket) goto label_MNUVKLHSECDWRA;
//// JMP_BRACKET 
	JMJQWIQPUOQHIM = CGFMZKGIPDFODK.container->value.bracket_data.chain->at_before_first();
	VFVUZWYVIJGFUL   = CGFMZKGIPDFODK.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = JMJQWIQPUOQHIM;
/*SET*/	r_n = VFVUZWYVIJGFUL;
//// [ empty ] 
/*ISEMPTY*/	if (CGFMZKGIPDFODK!=0 && arg_to != CGFMZKGIPDFODK) goto label_MNUVKLHSECDWRA;

// подготовка подстановки 
DataChain* LKJDUHSJAFBTLK = new DataChain(); 
DataContainer* LKJDUHSJAFBTLK_execbr = newRefExecBrackets(Game, LKJDUHSJAFBTLK, "Game");
result->append(LKJDUHSJAFBTLK_execbr);
DataChain* MFQRMYJFJNHHSS = new DataChain(); 
LKJDUHSJAFBTLK->append(newRefStructBrackets(MFQRMYJFJNHHSS)); 
MFQRMYJFJNHHSS->append(newRefText("1")); 
DataChain* QCTYDTEAMDCJBP = new DataChain(); 
DataContainer* QCTYDTEAMDCJBP_execbr = newRefExecBrackets(PlayerHod, QCTYDTEAMDCJBP, "PlayerHod");
LKJDUHSJAFBTLK->append(QCTYDTEAMDCJBP_execbr);
QCTYDTEAMDCJBP->append(newRefText("2")); 
DataChain* RHTNEGYIWXGCJW = new DataChain(); 
DataContainer* RHTNEGYIWXGCJW_execbr = newRefExecBrackets(Prout, RHTNEGYIWXGCJW, "Prout");
QCTYDTEAMDCJBP->append(RHTNEGYIWXGCJW_execbr);
RHTNEGYIWXGCJW->append(newRefText("Select number for 0:")); 
context->pushExecuteCall(RHTNEGYIWXGCJW_execbr);
DataChain* LGRSMEAEARWTVJ = new DataChain(); 
DataContainer* LGRSMEAEARWTVJ_execbr = newRefExecBrackets(Card, LGRSMEAEARWTVJ, "Card");
QCTYDTEAMDCJBP->append(LGRSMEAEARWTVJ_execbr);
context->pushExecuteCall(LGRSMEAEARWTVJ_execbr);
QCTYDTEAMDCJBP->append_copy(l_12, r_12); 
DataChain* SJBAOIOJLWHYPN = new DataChain(); 
QCTYDTEAMDCJBP->append(newRefStructBrackets(SJBAOIOJLWHYPN)); 
SJBAOIOJLWHYPN->append_copy(l_n, r_n); 
context->pushExecuteCall(QCTYDTEAMDCJBP_execbr);
context->pushExecuteCall(LKJDUHSJAFBTLK_execbr);

return result; 
}
sentence_after_2: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* PlayerHod__(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
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
DataChain* VRUIHOSWKIFYGT = new DataChain(); 
DataContainer* VRUIHOSWKIFYGT_execbr = newRefExecBrackets(Prout, VRUIHOSWKIFYGT, "Prout");
result->append(VRUIHOSWKIFYGT_execbr);
VRUIHOSWKIFYGT->append(newRefWord("PlayerHod:")); 
VRUIHOSWKIFYGT->append_copy(l_e, r_e); 
context->pushExecuteCall(VRUIHOSWKIFYGT_execbr);
DataChain* YDHACWYHSGEWZM = new DataChain(); 
DataContainer* YDHACWYHSGEWZM_execbr = newRefExecBrackets(PlayerHod__, YDHACWYHSGEWZM, "PlayerHod__");
result->append(YDHACWYHSGEWZM_execbr);
YDHACWYHSGEWZM->append_copy(l_e, r_e); 
context->pushExecuteCall(YDHACWYHSGEWZM_execbr);

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* PlayerHod(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor TGONZLTJHGAUHN;
/*SET*/	TGONZLTJHGAUHN = arg_from;
/*INC*/	if (!INC(TGONZLTJHGAUHN, arg_to)) goto sentence_after_1;
	if (TGONZLTJHGAUHN.container->type != text || *(TGONZLTJHGAUHN.container->value.text + TGONZLTJHGAUHN.index) != '1') goto sentence_after_1;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor IHREQGJFWKJSMT;
/*DEF*/	DataCursor l_h;
/*DEF*/	DataCursor r_h;
/*SET*/	l_h = TGONZLTJHGAUHN;
/*SET*/	IHREQGJFWKJSMT = TGONZLTJHGAUHN;
/*INC*/	if (!INC(IHREQGJFWKJSMT, arg_to)) goto sentence_after_1;
	if (! isSymbolType(IHREQGJFWKJSMT.container->type)) goto sentence_after_1;
/*SET*/	r_h = IHREQGJFWKJSMT;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor PJHAEFQZAAULDR;
/*DEF*/	DataCursor CHJCCDYRFVVRIV;
/*DEF*/	DataCursor UYEEGFIVDRCYGU;
/*SET*/	PJHAEFQZAAULDR = r_h;
/*INC*/	if (!INC(PJHAEFQZAAULDR, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (PJHAEFQZAAULDR.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	CHJCCDYRFVVRIV = PJHAEFQZAAULDR.container->value.bracket_data.chain->at_before_first();
	UYEEGFIVDRCYGU   = PJHAEFQZAAULDR.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = CHJCCDYRFVVRIV;
/*SET*/	r_1 = UYEEGFIVDRCYGU;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor RQDREDAKUBNFGU;
/*DEF*/	DataCursor PROQYLOBCWQXKZ;
/*DEF*/	DataCursor MAUSJGMHCMHGDN;
/*SET*/	RQDREDAKUBNFGU = PJHAEFQZAAULDR;
/*INC*/	if (!INC(RQDREDAKUBNFGU, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (RQDREDAKUBNFGU.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	PROQYLOBCWQXKZ = RQDREDAKUBNFGU.container->value.bracket_data.chain->at_before_first();
	MAUSJGMHCMHGDN   = RQDREDAKUBNFGU.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = PROQYLOBCWQXKZ;
/*SET*/	r_2 = MAUSJGMHCMHGDN;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor MPHNQKAMHURKTR;
/*DEF*/	DataCursor FFACLVGRZKKLDA;
/*DEF*/	DataCursor CLLTEOJOMONXRQ;
/*SET*/	MPHNQKAMHURKTR = RQDREDAKUBNFGU;
/*INC*/	if (!INC(MPHNQKAMHURKTR, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (MPHNQKAMHURKTR.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	FFACLVGRZKKLDA = MPHNQKAMHURKTR.container->value.bracket_data.chain->at_before_first();
	CLLTEOJOMONXRQ   = MPHNQKAMHURKTR.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_n1;
/*DEF*/	DataCursor r_n1;
/*SET*/	l_n1 = FFACLVGRZKKLDA;
/*SET*/	r_n1 = FFACLVGRZKKLDA;
/*JMP*/	goto label_YJZGINRNNZWACX_firststep;
label_YJZGINRNNZWACX: 
/*INC*/	if (!INC(r_n1, CLLTEOJOMONXRQ)) goto sentence_after_1;
label_YJZGINRNNZWACX_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor XAEDRWUDXZRFUS;
/*SET*/	XAEDRWUDXZRFUS = r_n1;
 if (!SLIDE(XAEDRWUDXZRFUS, CLLTEOJOMONXRQ, l_h, r_h)) goto label_YJZGINRNNZWACX;
//// [ e.1 ] 
/*DEF*/	DataCursor l_n2;
/*DEF*/	DataCursor r_n2;
/*SET*/	l_n2 = XAEDRWUDXZRFUS;
/*SET*/	r_n2 = CLLTEOJOMONXRQ;
//// [ empty ] 
/*ISEMPTY*/	if (MPHNQKAMHURKTR!=0 && arg_to != MPHNQKAMHURKTR) goto label_YJZGINRNNZWACX;

// подготовка подстановки 
DataChain* TCENAUMNDDXFDM = new DataChain(); 
DataContainer* TCENAUMNDDXFDM_execbr = newRefExecBrackets(Prout, TCENAUMNDDXFDM, "Prout");
result->append(TCENAUMNDDXFDM_execbr);
TCENAUMNDDXFDM->append(newRefText("step:")); 
TCENAUMNDDXFDM->append_copy(l_h, r_h); 
context->pushExecuteCall(TCENAUMNDDXFDM_execbr);
DataChain* VZCAUTDCCKXAAY = new DataChain(); 
result->append(newRefStructBrackets(VZCAUTDCCKXAAY)); 
VZCAUTDCCKXAAY->append_copy(l_1, r_1); 
VZCAUTDCCKXAAY->append_copy(l_h, r_h); 
DataChain* DZSXTTOBBGQNGV = new DataChain(); 
result->append(newRefStructBrackets(DZSXTTOBBGQNGV)); 
DZSXTTOBBGQNGV->append_copy(l_2, r_2); 
DataChain* VPJGOJOGLMKXGB = new DataChain(); 
result->append(newRefStructBrackets(VPJGOJOGLMKXGB)); 
VPJGOJOGLMKXGB->append_copy(l_n1, r_n1); 
VPJGOJOGLMKXGB->append_copy(l_n2, r_n2); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor FCPYPCKQCHBDDZ;
/*SET*/	FCPYPCKQCHBDDZ = arg_from;
/*INC*/	if (!INC(FCPYPCKQCHBDDZ, arg_to)) goto sentence_after_2;
	if (FCPYPCKQCHBDDZ.container->type != text || *(FCPYPCKQCHBDDZ.container->value.text + FCPYPCKQCHBDDZ.index) != '2') goto sentence_after_2;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor WRXBZMQRLXVOBT;
/*DEF*/	DataCursor l_h;
/*DEF*/	DataCursor r_h;
/*SET*/	l_h = FCPYPCKQCHBDDZ;
/*SET*/	WRXBZMQRLXVOBT = FCPYPCKQCHBDDZ;
/*INC*/	if (!INC(WRXBZMQRLXVOBT, arg_to)) goto sentence_after_2;
	if (! isSymbolType(WRXBZMQRLXVOBT.container->type)) goto sentence_after_2;
/*SET*/	r_h = WRXBZMQRLXVOBT;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor WHXGINFGFRCCLM;
/*DEF*/	DataCursor ZNMJUGWWBSQFCI;
/*DEF*/	DataCursor HUBSJOLLMSQSGH;
/*SET*/	WHXGINFGFRCCLM = r_h;
/*INC*/	if (!INC(WHXGINFGFRCCLM, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (WHXGINFGFRCCLM.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	ZNMJUGWWBSQFCI = WHXGINFGFRCCLM.container->value.bracket_data.chain->at_before_first();
	HUBSJOLLMSQSGH   = WHXGINFGFRCCLM.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = ZNMJUGWWBSQFCI;
/*SET*/	r_1 = HUBSJOLLMSQSGH;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor MCPHELSOTFLBGS;
/*DEF*/	DataCursor FNPCUZSRUPCHYN;
/*DEF*/	DataCursor VZHCPQUGRIWNIQ;
/*SET*/	MCPHELSOTFLBGS = WHXGINFGFRCCLM;
/*INC*/	if (!INC(MCPHELSOTFLBGS, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (MCPHELSOTFLBGS.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	FNPCUZSRUPCHYN = MCPHELSOTFLBGS.container->value.bracket_data.chain->at_before_first();
	VZHCPQUGRIWNIQ   = MCPHELSOTFLBGS.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = FNPCUZSRUPCHYN;
/*SET*/	r_2 = VZHCPQUGRIWNIQ;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor XDFJPWPXFBLKPN;
/*DEF*/	DataCursor PEELFJMTKUQPZO;
/*DEF*/	DataCursor MWNLMBUPMKTLPT;
/*SET*/	XDFJPWPXFBLKPN = MCPHELSOTFLBGS;
/*INC*/	if (!INC(XDFJPWPXFBLKPN, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (XDFJPWPXFBLKPN.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	PEELFJMTKUQPZO = XDFJPWPXFBLKPN.container->value.bracket_data.chain->at_before_first();
	MWNLMBUPMKTLPT   = XDFJPWPXFBLKPN.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_n1;
/*DEF*/	DataCursor r_n1;
/*SET*/	l_n1 = PEELFJMTKUQPZO;
/*SET*/	r_n1 = PEELFJMTKUQPZO;
/*JMP*/	goto label_NDMPDSYDSGVFPE_firststep;
label_NDMPDSYDSGVFPE: 
/*INC*/	if (!INC(r_n1, MWNLMBUPMKTLPT)) goto sentence_after_2;
label_NDMPDSYDSGVFPE_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor NEMWBORIFSUQHC;
/*SET*/	NEMWBORIFSUQHC = r_n1;
 if (!SLIDE(NEMWBORIFSUQHC, MWNLMBUPMKTLPT, l_h, r_h)) goto label_NDMPDSYDSGVFPE;
//// [ e.1 ] 
/*DEF*/	DataCursor l_n2;
/*DEF*/	DataCursor r_n2;
/*SET*/	l_n2 = NEMWBORIFSUQHC;
/*SET*/	r_n2 = MWNLMBUPMKTLPT;
//// [ empty ] 
/*ISEMPTY*/	if (XDFJPWPXFBLKPN!=0 && arg_to != XDFJPWPXFBLKPN) goto label_NDMPDSYDSGVFPE;

// подготовка подстановки 
DataChain* AFXWHGBIBABVQO = new DataChain(); 
DataContainer* AFXWHGBIBABVQO_execbr = newRefExecBrackets(Prout, AFXWHGBIBABVQO, "Prout");
result->append(AFXWHGBIBABVQO_execbr);
AFXWHGBIBABVQO->append(newRefText("step:")); 
AFXWHGBIBABVQO->append_copy(l_h, r_h); 
context->pushExecuteCall(AFXWHGBIBABVQO_execbr);
DataChain* PQFOVIUSSQFQWE = new DataChain(); 
result->append(newRefStructBrackets(PQFOVIUSSQFQWE)); 
PQFOVIUSSQFQWE->append_copy(l_1, r_1); 
DataChain* HTXDZUJTLNTXMR = new DataChain(); 
result->append(newRefStructBrackets(HTXDZUJTLNTXMR)); 
HTXDZUJTLNTXMR->append_copy(l_2, r_2); 
HTXDZUJTLNTXMR->append_copy(l_h, r_h); 
DataChain* JXXWTLGGKYTBIO = new DataChain(); 
result->append(newRefStructBrackets(JXXWTLGGKYTBIO)); 
JXXWTLGGKYTBIO->append_copy(l_n1, r_n1); 
JXXWTLGGKYTBIO->append_copy(l_n2, r_n2); 

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

DataChain* GetHod__(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
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
DataChain* LYDNILQADOJSKK = new DataChain(); 
DataContainer* LYDNILQADOJSKK_execbr = newRefExecBrackets(Prout, LYDNILQADOJSKK, "Prout");
result->append(LYDNILQADOJSKK_execbr);
LYDNILQADOJSKK->append(newRefWord("GetHod:")); 
LYDNILQADOJSKK->append_copy(l_e, r_e); 
context->pushExecuteCall(LYDNILQADOJSKK_execbr);
DataChain* VFXAHHJMBOCLJA = new DataChain(); 
DataContainer* VFXAHHJMBOCLJA_execbr = newRefExecBrackets(GetHod__, VFXAHHJMBOCLJA, "GetHod__");
result->append(VFXAHHJMBOCLJA_execbr);
VFXAHHJMBOCLJA->append_copy(l_e, r_e); 
context->pushExecuteCall(VFXAHHJMBOCLJA_execbr);

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* GetHod(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor RINTDWCLDVDXRO;
/*DEF*/	DataCursor l_v;
/*DEF*/	DataCursor r_v;
/*SET*/	l_v = arg_from;
/*SET*/	RINTDWCLDVDXRO = arg_from;
/*INC*/	if (!INC(RINTDWCLDVDXRO, arg_to)) goto sentence_after_1;
	if (! isSymbolType(RINTDWCLDVDXRO.container->type)) goto sentence_after_1;
/*SET*/	r_v = RINTDWCLDVDXRO;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = r_v;
/*SET*/	r_e = r_v;
/*JMP*/	goto label_PBYJZWYYOJUOTH_firststep;
label_PBYJZWYYOJUOTH: 
/*INC*/	if (!INC(r_e, arg_to)) goto sentence_after_1;
label_PBYJZWYYOJUOTH_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor WMLVRGLFZDZDBT;
/*DEF*/	DataCursor UBXUOFFVNCRSWS;
/*DEF*/	DataCursor AZNMOIJOIVVGOB;
/*SET*/	WMLVRGLFZDZDBT = r_e;
/*INC*/	if (!INC(WMLVRGLFZDZDBT, arg_to)) goto label_PBYJZWYYOJUOTH;
//// ISBRACKET 
	if (WMLVRGLFZDZDBT.container->type != struct_bracket) goto label_PBYJZWYYOJUOTH;
//// JMP_BRACKET 
	UBXUOFFVNCRSWS = WMLVRGLFZDZDBT.container->value.bracket_data.chain->at_before_first();
	AZNMOIJOIVVGOB   = WMLVRGLFZDZDBT.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_not;
/*DEF*/	DataCursor r_not;
/*SET*/	l_not = UBXUOFFVNCRSWS;
/*SET*/	r_not = AZNMOIJOIVVGOB;
//// [ empty ] 
/*ISEMPTY*/	if (WMLVRGLFZDZDBT!=0 && arg_to != WMLVRGLFZDZDBT) goto label_PBYJZWYYOJUOTH;

// подготовка подстановки 
DataChain* QPNCKWVNHKEBMT = new DataChain(); 
DataContainer* QPNCKWVNHKEBMT_execbr = newRefExecBrackets(UseHod, QPNCKWVNHKEBMT, "UseHod");
result->append(QPNCKWVNHKEBMT_execbr);
QPNCKWVNHKEBMT->append_copy(l_v, r_v); 
QPNCKWVNHKEBMT->append_copy(l_e, r_e); 
DataChain* DHVYGKJISUXHAT = new DataChain(); 
QPNCKWVNHKEBMT->append(newRefStructBrackets(DHVYGKJISUXHAT)); 
DHVYGKJISUXHAT->append_copy(l_not, r_not); 
DataChain* MUUDQBHMKNHFXA = new DataChain(); 
QPNCKWVNHKEBMT->append(newRefStructBrackets(MUUDQBHMKNHFXA)); 
DataChain* XQXKJLZZQTSJFA = new DataChain(); 
DataContainer* XQXKJLZZQTSJFA_execbr = newRefExecBrackets(WriteXO, XQXKJLZZQTSJFA, "WriteXO");
MUUDQBHMKNHFXA->append(XQXKJLZZQTSJFA_execbr);
XQXKJLZZQTSJFA->append_copy(l_e, r_e); 
DataChain* EEDFUUJKOLXJOQ = new DataChain(); 
XQXKJLZZQTSJFA->append(newRefStructBrackets(EEDFUUJKOLXJOQ)); 
EEDFUUJKOLXJOQ->append(newRefText(">")); 
EEDFUUJKOLXJOQ->append_copy(l_not, r_not); 
context->pushExecuteCall(XQXKJLZZQTSJFA_execbr);
context->pushExecuteCall(QPNCKWVNHKEBMT_execbr);

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* UseHod__(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
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
DataChain* KDVFEPVLHVHRWT = new DataChain(); 
DataContainer* KDVFEPVLHVHRWT_execbr = newRefExecBrackets(Prout, KDVFEPVLHVHRWT, "Prout");
result->append(KDVFEPVLHVHRWT_execbr);
KDVFEPVLHVHRWT->append(newRefWord("UseHod:")); 
KDVFEPVLHVHRWT->append_copy(l_e, r_e); 
context->pushExecuteCall(KDVFEPVLHVHRWT_execbr);
DataChain* FDUKXFFJPSSWYX = new DataChain(); 
DataContainer* FDUKXFFJPSSWYX_execbr = newRefExecBrackets(UseHod__, FDUKXFFJPSSWYX, "UseHod__");
result->append(FDUKXFFJPSSWYX_execbr);
FDUKXFFJPSSWYX->append_copy(l_e, r_e); 
context->pushExecuteCall(FDUKXFFJPSSWYX_execbr);

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* UseHod(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = arg_from;
/*SET*/	r_e = arg_from;
/*JMP*/	goto label_LIJJHEVRYXOZBA_firststep;
label_LIJJHEVRYXOZBA: 
/*INC*/	if (!INC(r_e, arg_to)) goto sentence_after_1;
label_LIJJHEVRYXOZBA_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor FPFMOWGRGONUAT;
/*DEF*/	DataCursor DQLAHYGGYLJDDJ;
/*DEF*/	DataCursor HMLTEDZLODSRKE;
/*SET*/	FPFMOWGRGONUAT = r_e;
/*INC*/	if (!INC(FPFMOWGRGONUAT, arg_to)) goto label_LIJJHEVRYXOZBA;
//// ISBRACKET 
	if (FPFMOWGRGONUAT.container->type != struct_bracket) goto label_LIJJHEVRYXOZBA;
//// JMP_BRACKET 
	DQLAHYGGYLJDDJ = FPFMOWGRGONUAT.container->value.bracket_data.chain->at_before_first();
	HMLTEDZLODSRKE   = FPFMOWGRGONUAT.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor UTGTNKNTARJKPX;
/*SET*/	UTGTNKNTARJKPX = DQLAHYGGYLJDDJ;
/*INC*/	if (!INC(UTGTNKNTARJKPX, HMLTEDZLODSRKE)) goto label_LIJJHEVRYXOZBA;
	if (UTGTNKNTARJKPX.container->type != text || *(UTGTNKNTARJKPX.container->value.text + UTGTNKNTARJKPX.index) != '#') goto label_LIJJHEVRYXOZBA;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor INOVGZDTHUNWOO;
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = UTGTNKNTARJKPX;
/*SET*/	INOVGZDTHUNWOO = UTGTNKNTARJKPX;
/*INC*/	if (!INC(INOVGZDTHUNWOO, HMLTEDZLODSRKE)) goto label_LIJJHEVRYXOZBA;
	if (! isSymbolType(INOVGZDTHUNWOO.container->type)) goto label_LIJJHEVRYXOZBA;
/*SET*/	r_s = INOVGZDTHUNWOO;
//// [ empty ] 
/*ISEMPTY*/	if (r_s!=0 && HMLTEDZLODSRKE != r_s) goto label_LIJJHEVRYXOZBA;
//// [ empty ] 
/*ISEMPTY*/	if (FPFMOWGRGONUAT!=0 && arg_to != FPFMOWGRGONUAT) goto label_LIJJHEVRYXOZBA;

// подготовка подстановки 
result->append_copy(l_s, r_s); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor OPMMLEBKSUCVZQ;
/*DEF*/	DataCursor l_v;
/*DEF*/	DataCursor r_v;
/*SET*/	l_v = arg_from;
/*SET*/	OPMMLEBKSUCVZQ = arg_from;
/*INC*/	if (!INC(OPMMLEBKSUCVZQ, arg_to)) goto sentence_after_2;
	if (! isSymbolType(OPMMLEBKSUCVZQ.container->type)) goto sentence_after_2;
/*SET*/	r_v = OPMMLEBKSUCVZQ;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = r_v;
/*SET*/	r_e = r_v;
/*JMP*/	goto label_LYQNWCMBVBHRML_firststep;
label_LYQNWCMBVBHRML: 
/*INC*/	if (!INC(r_e, arg_to)) goto sentence_after_2;
label_LYQNWCMBVBHRML_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor OWPJBWYVWTGTOQ;
/*DEF*/	DataCursor NMICXAPZARKNNX;
/*DEF*/	DataCursor TUUFARZROSDQWS;
/*SET*/	OWPJBWYVWTGTOQ = r_e;
/*INC*/	if (!INC(OWPJBWYVWTGTOQ, arg_to)) goto label_LYQNWCMBVBHRML;
//// ISBRACKET 
	if (OWPJBWYVWTGTOQ.container->type != struct_bracket) goto label_LYQNWCMBVBHRML;
//// JMP_BRACKET 
	NMICXAPZARKNNX = OWPJBWYVWTGTOQ.container->value.bracket_data.chain->at_before_first();
	TUUFARZROSDQWS   = OWPJBWYVWTGTOQ.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_not;
/*DEF*/	DataCursor r_not;
/*SET*/	l_not = NMICXAPZARKNNX;
/*SET*/	r_not = TUUFARZROSDQWS;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor MTCJGHECQUDOSR;
/*DEF*/	DataCursor TJXYAAYKQRXYCR;
/*DEF*/	DataCursor XUWJXNPQJNBKCP;
/*SET*/	MTCJGHECQUDOSR = OWPJBWYVWTGTOQ;
/*INC*/	if (!INC(MTCJGHECQUDOSR, arg_to)) goto label_LYQNWCMBVBHRML;
//// ISBRACKET 
	if (MTCJGHECQUDOSR.container->type != struct_bracket) goto label_LYQNWCMBVBHRML;
//// JMP_BRACKET 
	TJXYAAYKQRXYCR = MTCJGHECQUDOSR.container->value.bracket_data.chain->at_before_first();
	XUWJXNPQJNBKCP   = MTCJGHECQUDOSR.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_Wr;
/*DEF*/	DataCursor r_Wr;
/*SET*/	l_Wr = TJXYAAYKQRXYCR;
/*SET*/	r_Wr = XUWJXNPQJNBKCP;
//// [ empty ] 
/*ISEMPTY*/	if (MTCJGHECQUDOSR!=0 && arg_to != MTCJGHECQUDOSR) goto label_LYQNWCMBVBHRML;

// подготовка подстановки 
DataChain* DMOKALXAPEMVBQ = new DataChain(); 
DataContainer* DMOKALXAPEMVBQ_execbr = newRefExecBrackets(UHod, DMOKALXAPEMVBQ, "UHod");
result->append(DMOKALXAPEMVBQ_execbr);
DataChain* LZSVXZKUTAPPWG = new DataChain(); 
DMOKALXAPEMVBQ->append(newRefStructBrackets(LZSVXZKUTAPPWG)); 
DataChain* ZPDPYZKZCVBNTC = new DataChain(); 
DataContainer* ZPDPYZKZCVBNTC_execbr = newRefExecBrackets(Switch, ZPDPYZKZCVBNTC, "Switch");
LZSVXZKUTAPPWG->append(ZPDPYZKZCVBNTC_execbr);
ZPDPYZKZCVBNTC->append_copy(l_v, r_v); 
ZPDPYZKZCVBNTC->append_copy(l_Wr, r_Wr); 
context->pushExecuteCall(ZPDPYZKZCVBNTC_execbr);
DataChain* VFXSXPJAOXTFHV = new DataChain(); 
DMOKALXAPEMVBQ->append(newRefStructBrackets(VFXSXPJAOXTFHV)); 
VFXSXPJAOXTFHV->append_copy(l_Wr, r_Wr); 
DataChain* XXYTGOKRCXAETA = new DataChain(); 
DMOKALXAPEMVBQ->append(newRefStructBrackets(XXYTGOKRCXAETA)); 
XXYTGOKRCXAETA->append_copy(l_not, r_not); 
context->pushExecuteCall(DMOKALXAPEMVBQ_execbr);

return result; 
}
sentence_after_2: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* UHod__(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
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
DataChain* UQGNDMPHWZYIAY = new DataChain(); 
DataContainer* UQGNDMPHWZYIAY_execbr = newRefExecBrackets(Prout, UQGNDMPHWZYIAY, "Prout");
result->append(UQGNDMPHWZYIAY_execbr);
UQGNDMPHWZYIAY->append(newRefWord("UHod:")); 
UQGNDMPHWZYIAY->append_copy(l_e, r_e); 
context->pushExecuteCall(UQGNDMPHWZYIAY_execbr);
DataChain* ABJRQGEPPXYJST = new DataChain(); 
DataContainer* ABJRQGEPPXYJST_execbr = newRefExecBrackets(UHod__, ABJRQGEPPXYJST, "UHod__");
result->append(ABJRQGEPPXYJST_execbr);
ABJRQGEPPXYJST->append_copy(l_e, r_e); 
context->pushExecuteCall(ABJRQGEPPXYJST_execbr);

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* UHod(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor TYZUVLDVYBSUXK;
/*DEF*/	DataCursor BMFZVRTNOVIDZN;
/*DEF*/	DataCursor PGHOZVAFMSNSNQ;
/*SET*/	TYZUVLDVYBSUXK = arg_from;
/*INC*/	if (!INC(TYZUVLDVYBSUXK, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (TYZUVLDVYBSUXK.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	BMFZVRTNOVIDZN = TYZUVLDVYBSUXK.container->value.bracket_data.chain->at_before_first();
	PGHOZVAFMSNSNQ   = TYZUVLDVYBSUXK.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_Sw;
/*DEF*/	DataCursor r_Sw;
/*SET*/	l_Sw = BMFZVRTNOVIDZN;
/*SET*/	r_Sw = PGHOZVAFMSNSNQ;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor IVMVUBCWTFSRQT;
/*DEF*/	DataCursor MKNEPBHOWEJAZH;
/*DEF*/	DataCursor KWCMMTPIXXXLZQ;
/*SET*/	IVMVUBCWTFSRQT = TYZUVLDVYBSUXK;
/*INC*/	if (!INC(IVMVUBCWTFSRQT, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (IVMVUBCWTFSRQT.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	MKNEPBHOWEJAZH = IVMVUBCWTFSRQT.container->value.bracket_data.chain->at_before_first();
	KWCMMTPIXXXLZQ   = IVMVUBCWTFSRQT.container->value.bracket_data.chain->at_last();
//// [ &.name <any> ] 
/*DEF*/	DataCursor YSXTWWTAIDYAXY;
/*SET*/	YSXTWWTAIDYAXY = MKNEPBHOWEJAZH;
 if (!SLIDE(YSXTWWTAIDYAXY, KWCMMTPIXXXLZQ, l_Sw, r_Sw)) goto sentence_after_1;
//// [ e.1 ] 
/*DEF*/	DataCursor l_Wr;
/*DEF*/	DataCursor r_Wr;
/*SET*/	l_Wr = YSXTWWTAIDYAXY;
/*SET*/	r_Wr = KWCMMTPIXXXLZQ;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor QLEPRXIBEXXYFV;
/*DEF*/	DataCursor SDDYGTHCUYYFWP;
/*DEF*/	DataCursor JSFYBGLGZMBINT;
/*SET*/	QLEPRXIBEXXYFV = IVMVUBCWTFSRQT;
/*INC*/	if (!INC(QLEPRXIBEXXYFV, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (QLEPRXIBEXXYFV.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	SDDYGTHCUYYFWP = QLEPRXIBEXXYFV.container->value.bracket_data.chain->at_before_first();
	JSFYBGLGZMBINT   = QLEPRXIBEXXYFV.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor ATTNHODTONPYZW;
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = SDDYGTHCUYYFWP;
/*SET*/	ATTNHODTONPYZW = SDDYGTHCUYYFWP;
/*INC*/	if (!INC(ATTNHODTONPYZW, JSFYBGLGZMBINT)) goto sentence_after_1;
	if (! isSymbolType(ATTNHODTONPYZW.container->type)) goto sentence_after_1;
/*SET*/	r_s = ATTNHODTONPYZW;
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = r_s;
/*SET*/	r_n = JSFYBGLGZMBINT;
//// [ empty ] 
/*ISEMPTY*/	if (QLEPRXIBEXXYFV!=0 && arg_to != QLEPRXIBEXXYFV) goto sentence_after_1;

// подготовка подстановки 
result->append_copy(l_s, r_s); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor OTKGNGUPHPKXEA;
/*DEF*/	DataCursor TOWZABSDNVQHKF;
/*DEF*/	DataCursor CMOFISFRFQGVPM;
/*SET*/	OTKGNGUPHPKXEA = arg_from;
/*INC*/	if (!INC(OTKGNGUPHPKXEA, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (OTKGNGUPHPKXEA.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	TOWZABSDNVQHKF = OTKGNGUPHPKXEA.container->value.bracket_data.chain->at_before_first();
	CMOFISFRFQGVPM   = OTKGNGUPHPKXEA.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_Sw;
/*DEF*/	DataCursor r_Sw;
/*SET*/	l_Sw = TOWZABSDNVQHKF;
/*SET*/	r_Sw = CMOFISFRFQGVPM;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor VORPJFZSLZMPJJ;
/*DEF*/	DataCursor NEHRYKXJZUBUAC;
/*DEF*/	DataCursor CLFKCYZOBGHTUO;
/*SET*/	VORPJFZSLZMPJJ = OTKGNGUPHPKXEA;
/*INC*/	if (!INC(VORPJFZSLZMPJJ, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (VORPJFZSLZMPJJ.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	NEHRYKXJZUBUAC = VORPJFZSLZMPJJ.container->value.bracket_data.chain->at_before_first();
	CLFKCYZOBGHTUO   = VORPJFZSLZMPJJ.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor XRAJVPRECWGXXP;
/*DEF*/	DataCursor l_s1;
/*DEF*/	DataCursor r_s1;
/*SET*/	l_s1 = NEHRYKXJZUBUAC;
/*SET*/	XRAJVPRECWGXXP = NEHRYKXJZUBUAC;
/*INC*/	if (!INC(XRAJVPRECWGXXP, CLFKCYZOBGHTUO)) goto sentence_after_2;
	if (! isSymbolType(XRAJVPRECWGXXP.container->type)) goto sentence_after_2;
/*SET*/	r_s1 = XRAJVPRECWGXXP;
//// [ `a` <any> ] 
/*DEF*/	DataCursor SWCGMMVEDEWDMF;
/*SET*/	SWCGMMVEDEWDMF = r_s1;
/*INC*/	if (!INC(SWCGMMVEDEWDMF, CLFKCYZOBGHTUO)) goto sentence_after_2;
	if (SWCGMMVEDEWDMF.container->type != text || *(SWCGMMVEDEWDMF.container->value.text + SWCGMMVEDEWDMF.index) != '=') goto sentence_after_2;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor NQWCUQDSCILIQE;
/*DEF*/	DataCursor l_s2;
/*DEF*/	DataCursor r_s2;
/*SET*/	l_s2 = SWCGMMVEDEWDMF;
/*SET*/	NQWCUQDSCILIQE = SWCGMMVEDEWDMF;
/*INC*/	if (!INC(NQWCUQDSCILIQE, CLFKCYZOBGHTUO)) goto sentence_after_2;
	if (! isSymbolType(NQWCUQDSCILIQE.container->type)) goto sentence_after_2;
/*SET*/	r_s2 = NQWCUQDSCILIQE;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = r_s2;
/*SET*/	r_e = r_s2;
/*JMP*/	goto label_CIHLUILGMFCSWT_firststep;
label_CIHLUILGMFCSWT: 
/*INC*/	if (!INC(r_e, CLFKCYZOBGHTUO)) goto sentence_after_2;
label_CIHLUILGMFCSWT_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor WKKXLCBHQKVCSW;
/*SET*/	WKKXLCBHQKVCSW = r_e;
 if (!SLIDE(WKKXLCBHQKVCSW, CLFKCYZOBGHTUO, l_Sw, r_Sw)) goto label_CIHLUILGMFCSWT;
//// [ e.1 ] 
/*DEF*/	DataCursor l_Wr;
/*DEF*/	DataCursor r_Wr;
/*SET*/	l_Wr = WKKXLCBHQKVCSW;
/*SET*/	r_Wr = CLFKCYZOBGHTUO;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor ZBSGUVZIFNHYXW;
/*DEF*/	DataCursor JSJAVWAUXPANNA;
/*DEF*/	DataCursor MXJDVZUHNACZYH;
/*SET*/	ZBSGUVZIFNHYXW = VORPJFZSLZMPJJ;
/*INC*/	if (!INC(ZBSGUVZIFNHYXW, arg_to)) goto label_CIHLUILGMFCSWT;
//// ISBRACKET 
	if (ZBSGUVZIFNHYXW.container->type != struct_bracket) goto label_CIHLUILGMFCSWT;
//// JMP_BRACKET 
	JSJAVWAUXPANNA = ZBSGUVZIFNHYXW.container->value.bracket_data.chain->at_before_first();
	MXJDVZUHNACZYH   = ZBSGUVZIFNHYXW.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor EPWZOLHUSLRKVW;
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = JSJAVWAUXPANNA;
/*SET*/	EPWZOLHUSLRKVW = JSJAVWAUXPANNA;
/*INC*/	if (!INC(EPWZOLHUSLRKVW, MXJDVZUHNACZYH)) goto label_CIHLUILGMFCSWT;
	if (! isSymbolType(EPWZOLHUSLRKVW.container->type)) goto label_CIHLUILGMFCSWT;
/*SET*/	r_s = EPWZOLHUSLRKVW;
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = r_s;
/*SET*/	r_n = MXJDVZUHNACZYH;
//// [ empty ] 
/*ISEMPTY*/	if (ZBSGUVZIFNHYXW!=0 && arg_to != ZBSGUVZIFNHYXW) goto label_CIHLUILGMFCSWT;

// подготовка подстановки 
DataChain* PNVGZMIIZWUDWD = new DataChain(); 
DataContainer* PNVGZMIIZWUDWD_execbr = newRefExecBrackets(UHod, PNVGZMIIZWUDWD, "UHod");
result->append(PNVGZMIIZWUDWD_execbr);
DataChain* FZLKTBQDXGYYIU = new DataChain(); 
PNVGZMIIZWUDWD->append(newRefStructBrackets(FZLKTBQDXGYYIU)); 
FZLKTBQDXGYYIU->append_copy(l_Sw, r_Sw); 
DataChain* DSJVEZKMESBJLK = new DataChain(); 
PNVGZMIIZWUDWD->append(newRefStructBrackets(DSJVEZKMESBJLK)); 
DSJVEZKMESBJLK->append_copy(l_e, r_e); 
DSJVEZKMESBJLK->append_copy(l_Sw, r_Sw); 
DSJVEZKMESBJLK->append_copy(l_Wr, r_Wr); 
DataChain* YERTAHNEXHUQMJ = new DataChain(); 
PNVGZMIIZWUDWD->append(newRefStructBrackets(YERTAHNEXHUQMJ)); 
YERTAHNEXHUQMJ->append_copy(l_n, r_n); 
context->pushExecuteCall(PNVGZMIIZWUDWD_execbr);

return result; 
}
sentence_after_2: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Ekran(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
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
DataChain* ICBMUSQDKLASOL = new DataChain(); 
DataContainer* ICBMUSQDKLASOL_execbr = newRefExecBrackets(Prout, ICBMUSQDKLASOL, "Prout");
result->append(ICBMUSQDKLASOL_execbr);
ICBMUSQDKLASOL->append(newRefText("*===T===T===*")); 
context->pushExecuteCall(ICBMUSQDKLASOL_execbr);
DataChain* WJXPTXXEUMZFWY = new DataChain(); 
DataContainer* WJXPTXXEUMZFWY_execbr = newRefExecBrackets(Prout, WJXPTXXEUMZFWY, "Prout");
result->append(WJXPTXXEUMZFWY_execbr);
WJXPTXXEUMZFWY->append(newRefText("|")); 
DataChain* UCPABQSEFFUNQP = new DataChain(); 
DataContainer* UCPABQSEFFUNQP_execbr = newRefExecBrackets(XO, UCPABQSEFFUNQP, "XO");
WJXPTXXEUMZFWY->append(UCPABQSEFFUNQP_execbr);
UCPABQSEFFUNQP->append(newRefText("1")); 
UCPABQSEFFUNQP->append_copy(l_1, r_1); 
context->pushExecuteCall(UCPABQSEFFUNQP_execbr);
WJXPTXXEUMZFWY->append(newRefText("|")); 
DataChain* KFNNBECBBCJPDY = new DataChain(); 
DataContainer* KFNNBECBBCJPDY_execbr = newRefExecBrackets(XO, KFNNBECBBCJPDY, "XO");
WJXPTXXEUMZFWY->append(KFNNBECBBCJPDY_execbr);
KFNNBECBBCJPDY->append(newRefText("2")); 
KFNNBECBBCJPDY->append_copy(l_1, r_1); 
context->pushExecuteCall(KFNNBECBBCJPDY_execbr);
WJXPTXXEUMZFWY->append(newRefText("|")); 
DataChain* JLIBITLLPLXELR = new DataChain(); 
DataContainer* JLIBITLLPLXELR_execbr = newRefExecBrackets(XO, JLIBITLLPLXELR, "XO");
WJXPTXXEUMZFWY->append(JLIBITLLPLXELR_execbr);
JLIBITLLPLXELR->append(newRefText("3")); 
JLIBITLLPLXELR->append_copy(l_1, r_1); 
context->pushExecuteCall(JLIBITLLPLXELR_execbr);
WJXPTXXEUMZFWY->append(newRefText("|")); 
context->pushExecuteCall(WJXPTXXEUMZFWY_execbr);
DataChain* DKEXDTQUVPTTEY = new DataChain(); 
DataContainer* DKEXDTQUVPTTEY_execbr = newRefExecBrackets(Prout, DKEXDTQUVPTTEY, "Prout");
result->append(DKEXDTQUVPTTEY_execbr);
DKEXDTQUVPTTEY->append(newRefText("*===I===I===*")); 
context->pushExecuteCall(DKEXDTQUVPTTEY_execbr);
DataChain* HTLQLBBBVOQOZK = new DataChain(); 
DataContainer* HTLQLBBBVOQOZK_execbr = newRefExecBrackets(Prout, HTLQLBBBVOQOZK, "Prout");
result->append(HTLQLBBBVOQOZK_execbr);
HTLQLBBBVOQOZK->append(newRefText("|")); 
DataChain* YNAYYRBAQMYJHZ = new DataChain(); 
DataContainer* YNAYYRBAQMYJHZ_execbr = newRefExecBrackets(XO, YNAYYRBAQMYJHZ, "XO");
HTLQLBBBVOQOZK->append(YNAYYRBAQMYJHZ_execbr);
YNAYYRBAQMYJHZ->append(newRefText("4")); 
YNAYYRBAQMYJHZ->append_copy(l_1, r_1); 
context->pushExecuteCall(YNAYYRBAQMYJHZ_execbr);
HTLQLBBBVOQOZK->append(newRefText("|")); 
DataChain* XNDSIYFSEXWBIO = new DataChain(); 
DataContainer* XNDSIYFSEXWBIO_execbr = newRefExecBrackets(XO, XNDSIYFSEXWBIO, "XO");
HTLQLBBBVOQOZK->append(XNDSIYFSEXWBIO_execbr);
XNDSIYFSEXWBIO->append(newRefText("5")); 
XNDSIYFSEXWBIO->append_copy(l_1, r_1); 
context->pushExecuteCall(XNDSIYFSEXWBIO_execbr);
HTLQLBBBVOQOZK->append(newRefText("|")); 
DataChain* EWQVQRTCDLPQMV = new DataChain(); 
DataContainer* EWQVQRTCDLPQMV_execbr = newRefExecBrackets(XO, EWQVQRTCDLPQMV, "XO");
HTLQLBBBVOQOZK->append(EWQVQRTCDLPQMV_execbr);
EWQVQRTCDLPQMV->append(newRefText("6")); 
EWQVQRTCDLPQMV->append_copy(l_1, r_1); 
context->pushExecuteCall(EWQVQRTCDLPQMV_execbr);
HTLQLBBBVOQOZK->append(newRefText("|")); 
context->pushExecuteCall(HTLQLBBBVOQOZK_execbr);
DataChain* JIFVGYMKGOTZJM = new DataChain(); 
DataContainer* JIFVGYMKGOTZJM_execbr = newRefExecBrackets(Prout, JIFVGYMKGOTZJM, "Prout");
result->append(JIFVGYMKGOTZJM_execbr);
JIFVGYMKGOTZJM->append(newRefText("*===I===I===*")); 
context->pushExecuteCall(JIFVGYMKGOTZJM_execbr);
DataChain* NZQTMRPNDEVNMT = new DataChain(); 
DataContainer* NZQTMRPNDEVNMT_execbr = newRefExecBrackets(Prout, NZQTMRPNDEVNMT, "Prout");
result->append(NZQTMRPNDEVNMT_execbr);
NZQTMRPNDEVNMT->append(newRefText("|")); 
DataChain* HJITSSPAQNJRDO = new DataChain(); 
DataContainer* HJITSSPAQNJRDO_execbr = newRefExecBrackets(XO, HJITSSPAQNJRDO, "XO");
NZQTMRPNDEVNMT->append(HJITSSPAQNJRDO_execbr);
HJITSSPAQNJRDO->append(newRefText("7")); 
HJITSSPAQNJRDO->append_copy(l_1, r_1); 
context->pushExecuteCall(HJITSSPAQNJRDO_execbr);
NZQTMRPNDEVNMT->append(newRefText("|")); 
DataChain* YJWPYATMLEYQSV = new DataChain(); 
DataContainer* YJWPYATMLEYQSV_execbr = newRefExecBrackets(XO, YJWPYATMLEYQSV, "XO");
NZQTMRPNDEVNMT->append(YJWPYATMLEYQSV_execbr);
YJWPYATMLEYQSV->append(newRefText("8")); 
YJWPYATMLEYQSV->append_copy(l_1, r_1); 
context->pushExecuteCall(YJWPYATMLEYQSV_execbr);
NZQTMRPNDEVNMT->append(newRefText("|")); 
DataChain* KPAMSVBMVXRLLI = new DataChain(); 
DataContainer* KPAMSVBMVXRLLI_execbr = newRefExecBrackets(XO, KPAMSVBMVXRLLI, "XO");
NZQTMRPNDEVNMT->append(KPAMSVBMVXRLLI_execbr);
KPAMSVBMVXRLLI->append(newRefText("9")); 
KPAMSVBMVXRLLI->append_copy(l_1, r_1); 
context->pushExecuteCall(KPAMSVBMVXRLLI_execbr);
NZQTMRPNDEVNMT->append(newRefText("|")); 
context->pushExecuteCall(NZQTMRPNDEVNMT_execbr);
DataChain* VFEDKJIGAVYXJV = new DataChain(); 
DataContainer* VFEDKJIGAVYXJV_execbr = newRefExecBrackets(Prout, VFEDKJIGAVYXJV, "Prout");
result->append(VFEDKJIGAVYXJV_execbr);
VFEDKJIGAVYXJV->append(newRefText("*===I===I===*")); 
context->pushExecuteCall(VFEDKJIGAVYXJV_execbr);

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* XO(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor EQVRBACUIGAIPY;
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	EQVRBACUIGAIPY = arg_from;
/*INC*/	if (!INC(EQVRBACUIGAIPY, arg_to)) goto sentence_after_1;
	if (! isSymbolType(EQVRBACUIGAIPY.container->type)) goto sentence_after_1;
/*SET*/	r_1 = EQVRBACUIGAIPY;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor HBBXIPBZNCWHRB;
/*DEF*/	DataCursor LIRIZXOQPTQQWE;
/*DEF*/	DataCursor AAFJEQIOZPYFAU;
/*SET*/	HBBXIPBZNCWHRB = r_1;
/*INC*/	if (!INC(HBBXIPBZNCWHRB, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (HBBXIPBZNCWHRB.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	LIRIZXOQPTQQWE = HBBXIPBZNCWHRB.container->value.bracket_data.chain->at_before_first();
	AAFJEQIOZPYFAU   = HBBXIPBZNCWHRB.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_21;
/*DEF*/	DataCursor r_21;
/*SET*/	l_21 = LIRIZXOQPTQQWE;
/*SET*/	r_21 = LIRIZXOQPTQQWE;
/*JMP*/	goto label_UQMVHXKMNXMSYA_firststep;
label_UQMVHXKMNXMSYA: 
/*INC*/	if (!INC(r_21, AAFJEQIOZPYFAU)) goto sentence_after_1;
label_UQMVHXKMNXMSYA_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor MPTLZANOTLSLWU;
/*SET*/	MPTLZANOTLSLWU = r_21;
 if (!SLIDE(MPTLZANOTLSLWU, AAFJEQIOZPYFAU, l_1, r_1)) goto label_UQMVHXKMNXMSYA;
//// [ e.1 ] 
/*DEF*/	DataCursor l_22;
/*DEF*/	DataCursor r_22;
/*SET*/	l_22 = MPTLZANOTLSLWU;
/*SET*/	r_22 = AAFJEQIOZPYFAU;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor HTFQJRRWBWHMQH;
/*DEF*/	DataCursor ZKHDKCRFVBEIYI;
/*DEF*/	DataCursor PVFVPZHYUJABTQ;
/*SET*/	HTFQJRRWBWHMQH = HBBXIPBZNCWHRB;
/*INC*/	if (!INC(HTFQJRRWBWHMQH, arg_to)) goto label_UQMVHXKMNXMSYA;
//// ISBRACKET 
	if (HTFQJRRWBWHMQH.container->type != struct_bracket) goto label_UQMVHXKMNXMSYA;
//// JMP_BRACKET 
	ZKHDKCRFVBEIYI = HTFQJRRWBWHMQH.container->value.bracket_data.chain->at_before_first();
	PVFVPZHYUJABTQ   = HTFQJRRWBWHMQH.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = ZKHDKCRFVBEIYI;
/*SET*/	r_3 = PVFVPZHYUJABTQ;
//// [ empty ] 
/*ISEMPTY*/	if (HTFQJRRWBWHMQH!=0 && arg_to != HTFQJRRWBWHMQH) goto label_UQMVHXKMNXMSYA;

// подготовка подстановки 
result->append(newRefText("-X-")); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor WWTBKDOGKEMHIB;
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	WWTBKDOGKEMHIB = arg_from;
/*INC*/	if (!INC(WWTBKDOGKEMHIB, arg_to)) goto sentence_after_2;
	if (! isSymbolType(WWTBKDOGKEMHIB.container->type)) goto sentence_after_2;
/*SET*/	r_1 = WWTBKDOGKEMHIB;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor YXRNXSXRZLETBQ;
/*DEF*/	DataCursor EXKRQOIERNAPLQ;
/*DEF*/	DataCursor YJPQOUBVJSEBAL;
/*SET*/	YXRNXSXRZLETBQ = r_1;
/*INC*/	if (!INC(YXRNXSXRZLETBQ, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (YXRNXSXRZLETBQ.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	EXKRQOIERNAPLQ = YXRNXSXRZLETBQ.container->value.bracket_data.chain->at_before_first();
	YJPQOUBVJSEBAL   = YXRNXSXRZLETBQ.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = EXKRQOIERNAPLQ;
/*SET*/	r_2 = YJPQOUBVJSEBAL;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor WNKSVLOIDZFPIR;
/*DEF*/	DataCursor WYCZTWZZVEWXOT;
/*DEF*/	DataCursor AKUDKPEDUPKCZL;
/*SET*/	WNKSVLOIDZFPIR = YXRNXSXRZLETBQ;
/*INC*/	if (!INC(WNKSVLOIDZFPIR, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (WNKSVLOIDZFPIR.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	WYCZTWZZVEWXOT = WNKSVLOIDZFPIR.container->value.bracket_data.chain->at_before_first();
	AKUDKPEDUPKCZL   = WNKSVLOIDZFPIR.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_31;
/*DEF*/	DataCursor r_31;
/*SET*/	l_31 = WYCZTWZZVEWXOT;
/*SET*/	r_31 = WYCZTWZZVEWXOT;
/*JMP*/	goto label_HWUSKDNEVDCPLB_firststep;
label_HWUSKDNEVDCPLB: 
/*INC*/	if (!INC(r_31, AKUDKPEDUPKCZL)) goto sentence_after_2;
label_HWUSKDNEVDCPLB_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor KLPJMPFDCYQTRC;
/*SET*/	KLPJMPFDCYQTRC = r_31;
 if (!SLIDE(KLPJMPFDCYQTRC, AKUDKPEDUPKCZL, l_1, r_1)) goto label_HWUSKDNEVDCPLB;
//// [ e.1 ] 
/*DEF*/	DataCursor l_32;
/*DEF*/	DataCursor r_32;
/*SET*/	l_32 = KLPJMPFDCYQTRC;
/*SET*/	r_32 = AKUDKPEDUPKCZL;
//// [ empty ] 
/*ISEMPTY*/	if (WNKSVLOIDZFPIR!=0 && arg_to != WNKSVLOIDZFPIR) goto label_HWUSKDNEVDCPLB;

// подготовка подстановки 
result->append(newRefText("-O-")); 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor VVVTRFFVPEKKQM;
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	VVVTRFFVPEKKQM = arg_from;
/*INC*/	if (!INC(VVVTRFFVPEKKQM, arg_to)) goto sentence_after_3;
	if (! isSymbolType(VVVTRFFVPEKKQM.container->type)) goto sentence_after_3;
/*SET*/	r_1 = VVVTRFFVPEKKQM;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor CUPRYJAUTEUVCZ;
/*DEF*/	DataCursor VICTHRXSXCLPRG;
/*DEF*/	DataCursor DLWXFAIGAYRUEI;
/*SET*/	CUPRYJAUTEUVCZ = r_1;
/*INC*/	if (!INC(CUPRYJAUTEUVCZ, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (CUPRYJAUTEUVCZ.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	VICTHRXSXCLPRG = CUPRYJAUTEUVCZ.container->value.bracket_data.chain->at_before_first();
	DLWXFAIGAYRUEI   = CUPRYJAUTEUVCZ.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = VICTHRXSXCLPRG;
/*SET*/	r_2 = DLWXFAIGAYRUEI;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor CUFDIAMHTKBXOT;
/*DEF*/	DataCursor DIRXXGVZQMEYRO;
/*DEF*/	DataCursor VFICHQNIVFJZAU;
/*SET*/	CUFDIAMHTKBXOT = CUPRYJAUTEUVCZ;
/*INC*/	if (!INC(CUFDIAMHTKBXOT, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (CUFDIAMHTKBXOT.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	DIRXXGVZQMEYRO = CUFDIAMHTKBXOT.container->value.bracket_data.chain->at_before_first();
	VFICHQNIVFJZAU   = CUFDIAMHTKBXOT.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = DIRXXGVZQMEYRO;
/*SET*/	r_3 = VFICHQNIVFJZAU;
//// [ empty ] 
/*ISEMPTY*/	if (CUFDIAMHTKBXOT!=0 && arg_to != CUFDIAMHTKBXOT) goto sentence_after_3;

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

DataChain* Switch(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor QFDFTGMOPSRGPU;
/*SET*/	QFDFTGMOPSRGPU = arg_from;
/*INC*/	if (!INC(QFDFTGMOPSRGPU, arg_to)) goto sentence_after_1;
	if (QFDFTGMOPSRGPU.container->type != integer || QFDFTGMOPSRGPU.container->value.num != 0) goto sentence_after_1;
//// [ empty ] 
/*ISEMPTY*/	if (QFDFTGMOPSRGPU!=0 && arg_to != QFDFTGMOPSRGPU) goto sentence_after_1;

// подготовка подстановки 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor GXTUHLCVSPIHAZ;
/*DEF*/	DataCursor l_G;
/*DEF*/	DataCursor r_G;
/*SET*/	l_G = arg_from;
/*SET*/	GXTUHLCVSPIHAZ = arg_from;
/*INC*/	if (!INC(GXTUHLCVSPIHAZ, arg_to)) goto sentence_after_2;
	if (! isSymbolType(GXTUHLCVSPIHAZ.container->type)) goto sentence_after_2;
/*SET*/	r_G = GXTUHLCVSPIHAZ;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor RSSFSZWXBQMURW;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_G;
/*SET*/	RSSFSZWXBQMURW = r_G;
/*INC*/	if (!INC(RSSFSZWXBQMURW, arg_to)) goto sentence_after_2;
	if (! isSymbolType(RSSFSZWXBQMURW.container->type)) goto sentence_after_2;
/*SET*/	r_A = RSSFSZWXBQMURW;
//// [ `a` <any> ] 
/*DEF*/	DataCursor MXCDBHUMRGJQMV;
/*SET*/	MXCDBHUMRGJQMV = r_A;
/*INC*/	if (!INC(MXCDBHUMRGJQMV, arg_to)) goto sentence_after_2;
	if (MXCDBHUMRGJQMV.container->type != text || *(MXCDBHUMRGJQMV.container->value.text + MXCDBHUMRGJQMV.index) != '=') goto sentence_after_2;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor NKYRTNSJVWZXSS;
/*DEF*/	DataCursor l_AA;
/*DEF*/	DataCursor r_AA;
/*SET*/	l_AA = MXCDBHUMRGJQMV;
/*SET*/	NKYRTNSJVWZXSS = MXCDBHUMRGJQMV;
/*INC*/	if (!INC(NKYRTNSJVWZXSS, arg_to)) goto sentence_after_2;
	if (! isSymbolType(NKYRTNSJVWZXSS.container->type)) goto sentence_after_2;
/*SET*/	r_AA = NKYRTNSJVWZXSS;
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
/*DEF*/	DataCursor SYXWQYYXCSZPOK;
/*DEF*/	DataCursor l_G;
/*DEF*/	DataCursor r_G;
/*SET*/	l_G = arg_from;
/*SET*/	SYXWQYYXCSZPOK = arg_from;
/*INC*/	if (!INC(SYXWQYYXCSZPOK, arg_to)) goto sentence_after_3;
	if (! isSymbolType(SYXWQYYXCSZPOK.container->type)) goto sentence_after_3;
/*SET*/	r_G = SYXWQYYXCSZPOK;
//// [ &.name <any> ] 
/*DEF*/	DataCursor LWJDRLTBSCIEDP;
/*SET*/	LWJDRLTBSCIEDP = r_G;
 if (!SLIDE(LWJDRLTBSCIEDP, arg_to, l_G, r_G)) goto sentence_after_3;
//// [ `a` <any> ] 
/*DEF*/	DataCursor IWLAQIGESJSQHS;
/*SET*/	IWLAQIGESJSQHS = LWJDRLTBSCIEDP;
/*INC*/	if (!INC(IWLAQIGESJSQHS, arg_to)) goto sentence_after_3;
	if (IWLAQIGESJSQHS.container->type != text || *(IWLAQIGESJSQHS.container->value.text + IWLAQIGESJSQHS.index) != '=') goto sentence_after_3;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor JLRGLMWANRXRFN;
/*DEF*/	DataCursor l_AA;
/*DEF*/	DataCursor r_AA;
/*SET*/	l_AA = IWLAQIGESJSQHS;
/*SET*/	JLRGLMWANRXRFN = IWLAQIGESJSQHS;
/*INC*/	if (!INC(JLRGLMWANRXRFN, arg_to)) goto sentence_after_3;
	if (! isSymbolType(JLRGLMWANRXRFN.container->type)) goto sentence_after_3;
/*SET*/	r_AA = JLRGLMWANRXRFN;
//// [ &.name <any> ] 
/*DEF*/	DataCursor WAKZTGJHXAUNFQ;
/*SET*/	WAKZTGJHXAUNFQ = r_AA;
 if (!SLIDE(WAKZTGJHXAUNFQ, arg_to, l_G, r_G)) goto sentence_after_3;
//// [ `a` <any> ] 
/*DEF*/	DataCursor JVXIOHNJQRJSHY;
/*SET*/	JVXIOHNJQRJSHY = WAKZTGJHXAUNFQ;
/*INC*/	if (!INC(JVXIOHNJQRJSHY, arg_to)) goto sentence_after_3;
	if (JVXIOHNJQRJSHY.container->type != text || *(JVXIOHNJQRJSHY.container->value.text + JVXIOHNJQRJSHY.index) != '=') goto sentence_after_3;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor MDOVWGEFHJESVH;
/*DEF*/	DataCursor l_BB;
/*DEF*/	DataCursor r_BB;
/*SET*/	l_BB = JVXIOHNJQRJSHY;
/*SET*/	MDOVWGEFHJESVH = JVXIOHNJQRJSHY;
/*INC*/	if (!INC(MDOVWGEFHJESVH, arg_to)) goto sentence_after_3;
	if (! isSymbolType(MDOVWGEFHJESVH.container->type)) goto sentence_after_3;
/*SET*/	r_BB = MDOVWGEFHJESVH;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = r_BB;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* WXKEWPZHBJSUTH = new DataChain(); 
DataContainer* WXKEWPZHBJSUTH_execbr = newRefExecBrackets(Switch, WXKEWPZHBJSUTH, "Switch");
result->append(WXKEWPZHBJSUTH_execbr);
WXKEWPZHBJSUTH->append_copy(l_G, r_G); 
WXKEWPZHBJSUTH->append_copy(l_G, r_G); 
WXKEWPZHBJSUTH->append(newRefText("=")); 
DataChain* SYOEFJGWWYEOZL = new DataChain(); 
DataContainer* SYOEFJGWWYEOZL_execbr = newRefExecBrackets(Maix, SYOEFJGWWYEOZL, "Maix");
WXKEWPZHBJSUTH->append(SYOEFJGWWYEOZL_execbr);
SYOEFJGWWYEOZL->append(newRefText("a")); 
SYOEFJGWWYEOZL->append_copy(l_AA, r_AA); 
SYOEFJGWWYEOZL->append_copy(l_BB, r_BB); 
DataChain* UHMGABBSQRHCRT = new DataChain(); 
DataContainer* UHMGABBSQRHCRT_execbr = newRefExecBrackets(Compare, UHMGABBSQRHCRT, "Compare");
SYOEFJGWWYEOZL->append(UHMGABBSQRHCRT_execbr);
UHMGABBSQRHCRT->append_copy(l_AA, r_AA); 
UHMGABBSQRHCRT->append_copy(l_BB, r_BB); 
context->pushExecuteCall(UHMGABBSQRHCRT_execbr);
context->pushExecuteCall(SYOEFJGWWYEOZL_execbr);
WXKEWPZHBJSUTH->append_copy(l_e, r_e); 
context->pushExecuteCall(WXKEWPZHBJSUTH_execbr);

return result; 
}
sentence_after_3: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor XMJVCAXXSUFAHY;
/*DEF*/	DataCursor l_G;
/*DEF*/	DataCursor r_G;
/*SET*/	l_G = arg_from;
/*SET*/	XMJVCAXXSUFAHY = arg_from;
/*INC*/	if (!INC(XMJVCAXXSUFAHY, arg_to)) goto sentence_after_4;
	if (! isSymbolType(XMJVCAXXSUFAHY.container->type)) goto sentence_after_4;
/*SET*/	r_G = XMJVCAXXSUFAHY;
//// [ &.name <any> ] 
/*DEF*/	DataCursor YAYZKHUHJRJSVO;
/*SET*/	YAYZKHUHJRJSVO = r_G;
 if (!SLIDE(YAYZKHUHJRJSVO, arg_to, l_G, r_G)) goto sentence_after_4;
//// [ `a` <any> ] 
/*DEF*/	DataCursor QHTYDWPBSZXSBZ;
/*SET*/	QHTYDWPBSZXSBZ = YAYZKHUHJRJSVO;
/*INC*/	if (!INC(QHTYDWPBSZXSBZ, arg_to)) goto sentence_after_4;
	if (QHTYDWPBSZXSBZ.container->type != text || *(QHTYDWPBSZXSBZ.container->value.text + QHTYDWPBSZXSBZ.index) != '=') goto sentence_after_4;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor IYRVGQMLUNWSCP;
/*DEF*/	DataCursor l_AA;
/*DEF*/	DataCursor r_AA;
/*SET*/	l_AA = QHTYDWPBSZXSBZ;
/*SET*/	IYRVGQMLUNWSCP = QHTYDWPBSZXSBZ;
/*INC*/	if (!INC(IYRVGQMLUNWSCP, arg_to)) goto sentence_after_4;
	if (! isSymbolType(IYRVGQMLUNWSCP.container->type)) goto sentence_after_4;
/*SET*/	r_AA = IYRVGQMLUNWSCP;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor IRZFCBTSEPLKGW;
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = r_AA;
/*SET*/	IRZFCBTSEPLKGW = r_AA;
/*INC*/	if (!INC(IRZFCBTSEPLKGW, arg_to)) goto sentence_after_4;
	if (! isSymbolType(IRZFCBTSEPLKGW.container->type)) goto sentence_after_4;
/*SET*/	r_s = IRZFCBTSEPLKGW;
//// [ `a` <any> ] 
/*DEF*/	DataCursor FKHROUOYSRWMQO;
/*SET*/	FKHROUOYSRWMQO = r_s;
/*INC*/	if (!INC(FKHROUOYSRWMQO, arg_to)) goto sentence_after_4;
	if (FKHROUOYSRWMQO.container->type != text || *(FKHROUOYSRWMQO.container->value.text + FKHROUOYSRWMQO.index) != '=') goto sentence_after_4;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor JAHYQMFEVSDCOM;
/*DEF*/	DataCursor l_BB;
/*DEF*/	DataCursor r_BB;
/*SET*/	l_BB = FKHROUOYSRWMQO;
/*SET*/	JAHYQMFEVSDCOM = FKHROUOYSRWMQO;
/*INC*/	if (!INC(JAHYQMFEVSDCOM, arg_to)) goto sentence_after_4;
	if (! isSymbolType(JAHYQMFEVSDCOM.container->type)) goto sentence_after_4;
/*SET*/	r_BB = JAHYQMFEVSDCOM;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = r_BB;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* SEPJEISZSGCEZW = new DataChain(); 
DataContainer* SEPJEISZSGCEZW_execbr = newRefExecBrackets(Switch, SEPJEISZSGCEZW, "Switch");
result->append(SEPJEISZSGCEZW_execbr);
SEPJEISZSGCEZW->append_copy(l_G, r_G); 
SEPJEISZSGCEZW->append_copy(l_G, r_G); 
SEPJEISZSGCEZW->append(newRefText("=")); 
SEPJEISZSGCEZW->append_copy(l_AA, r_AA); 
SEPJEISZSGCEZW->append_copy(l_e, r_e); 
context->pushExecuteCall(SEPJEISZSGCEZW_execbr);

return result; 
}
sentence_after_4: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor APQRVLWIGROVJC;
/*DEF*/	DataCursor l_G;
/*DEF*/	DataCursor r_G;
/*SET*/	l_G = arg_from;
/*SET*/	APQRVLWIGROVJC = arg_from;
/*INC*/	if (!INC(APQRVLWIGROVJC, arg_to)) goto sentence_after_5;
	if (! isSymbolType(APQRVLWIGROVJC.container->type)) goto sentence_after_5;
/*SET*/	r_G = APQRVLWIGROVJC;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor DZXXPHQLSRZIHM;
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = r_G;
/*SET*/	DZXXPHQLSRZIHM = r_G;
/*INC*/	if (!INC(DZXXPHQLSRZIHM, arg_to)) goto sentence_after_5;
	if (! isSymbolType(DZXXPHQLSRZIHM.container->type)) goto sentence_after_5;
/*SET*/	r_s = DZXXPHQLSRZIHM;
//// [ `a` <any> ] 
/*DEF*/	DataCursor GZRIOQRQETKZFB;
/*SET*/	GZRIOQRQETKZFB = r_s;
/*INC*/	if (!INC(GZRIOQRQETKZFB, arg_to)) goto sentence_after_5;
	if (GZRIOQRQETKZFB.container->type != text || *(GZRIOQRQETKZFB.container->value.text + GZRIOQRQETKZFB.index) != '=') goto sentence_after_5;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor LDJIEMSFZBHZFN;
/*DEF*/	DataCursor l_AA;
/*DEF*/	DataCursor r_AA;
/*SET*/	l_AA = GZRIOQRQETKZFB;
/*SET*/	LDJIEMSFZBHZFN = GZRIOQRQETKZFB;
/*INC*/	if (!INC(LDJIEMSFZBHZFN, arg_to)) goto sentence_after_5;
	if (! isSymbolType(LDJIEMSFZBHZFN.container->type)) goto sentence_after_5;
/*SET*/	r_AA = LDJIEMSFZBHZFN;
//// [ &.name <any> ] 
/*DEF*/	DataCursor WYWMXXGDPYLRAX;
/*SET*/	WYWMXXGDPYLRAX = r_AA;
 if (!SLIDE(WYWMXXGDPYLRAX, arg_to, l_G, r_G)) goto sentence_after_5;
//// [ `a` <any> ] 
/*DEF*/	DataCursor GLMTBIYLBHCWHL;
/*SET*/	GLMTBIYLBHCWHL = WYWMXXGDPYLRAX;
/*INC*/	if (!INC(GLMTBIYLBHCWHL, arg_to)) goto sentence_after_5;
	if (GLMTBIYLBHCWHL.container->type != text || *(GLMTBIYLBHCWHL.container->value.text + GLMTBIYLBHCWHL.index) != '=') goto sentence_after_5;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor SYOYHGMGOPPRZA;
/*DEF*/	DataCursor l_BB;
/*DEF*/	DataCursor r_BB;
/*SET*/	l_BB = GLMTBIYLBHCWHL;
/*SET*/	SYOYHGMGOPPRZA = GLMTBIYLBHCWHL;
/*INC*/	if (!INC(SYOYHGMGOPPRZA, arg_to)) goto sentence_after_5;
	if (! isSymbolType(SYOYHGMGOPPRZA.container->type)) goto sentence_after_5;
/*SET*/	r_BB = SYOYHGMGOPPRZA;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = r_BB;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* TNQWTOETONXWZG = new DataChain(); 
DataContainer* TNQWTOETONXWZG_execbr = newRefExecBrackets(Switch, TNQWTOETONXWZG, "Switch");
result->append(TNQWTOETONXWZG_execbr);
TNQWTOETONXWZG->append_copy(l_G, r_G); 
TNQWTOETONXWZG->append_copy(l_G, r_G); 
TNQWTOETONXWZG->append(newRefText("=")); 
TNQWTOETONXWZG->append_copy(l_BB, r_BB); 
TNQWTOETONXWZG->append_copy(l_e, r_e); 
context->pushExecuteCall(TNQWTOETONXWZG_execbr);

return result; 
}
sentence_after_5: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor HUTIFKLGKLRNUW;
/*DEF*/	DataCursor l_G;
/*DEF*/	DataCursor r_G;
/*SET*/	l_G = arg_from;
/*SET*/	HUTIFKLGKLRNUW = arg_from;
/*INC*/	if (!INC(HUTIFKLGKLRNUW, arg_to)) goto sentence_after_6;
	if (! isSymbolType(HUTIFKLGKLRNUW.container->type)) goto sentence_after_6;
/*SET*/	r_G = HUTIFKLGKLRNUW;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor KMSYQCPUIVAHQA;
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = r_G;
/*SET*/	KMSYQCPUIVAHQA = r_G;
/*INC*/	if (!INC(KMSYQCPUIVAHQA, arg_to)) goto sentence_after_6;
	if (! isSymbolType(KMSYQCPUIVAHQA.container->type)) goto sentence_after_6;
/*SET*/	r_s = KMSYQCPUIVAHQA;
//// [ `a` <any> ] 
/*DEF*/	DataCursor TMSCKMAALKICSN;
/*SET*/	TMSCKMAALKICSN = r_s;
/*INC*/	if (!INC(TMSCKMAALKICSN, arg_to)) goto sentence_after_6;
	if (TMSCKMAALKICSN.container->type != text || *(TMSCKMAALKICSN.container->value.text + TMSCKMAALKICSN.index) != '=') goto sentence_after_6;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor XUCOVTYKRXAWZA;
/*DEF*/	DataCursor l_AA;
/*DEF*/	DataCursor r_AA;
/*SET*/	l_AA = TMSCKMAALKICSN;
/*SET*/	XUCOVTYKRXAWZA = TMSCKMAALKICSN;
/*INC*/	if (!INC(XUCOVTYKRXAWZA, arg_to)) goto sentence_after_6;
	if (! isSymbolType(XUCOVTYKRXAWZA.container->type)) goto sentence_after_6;
/*SET*/	r_AA = XUCOVTYKRXAWZA;
//// [ &.name <any> ] 
/*DEF*/	DataCursor DJXWXQMNDHLDTT;
/*SET*/	DJXWXQMNDHLDTT = r_AA;
 if (!SLIDE(DJXWXQMNDHLDTT, arg_to, l_s, r_s)) goto sentence_after_6;
//// [ `a` <any> ] 
/*DEF*/	DataCursor XSKNXTEZNJSQTF;
/*SET*/	XSKNXTEZNJSQTF = DJXWXQMNDHLDTT;
/*INC*/	if (!INC(XSKNXTEZNJSQTF, arg_to)) goto sentence_after_6;
	if (XSKNXTEZNJSQTF.container->type != text || *(XSKNXTEZNJSQTF.container->value.text + XSKNXTEZNJSQTF.index) != '=') goto sentence_after_6;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor BCCFQMWHBVSSII;
/*DEF*/	DataCursor l_BB;
/*DEF*/	DataCursor r_BB;
/*SET*/	l_BB = XSKNXTEZNJSQTF;
/*SET*/	BCCFQMWHBVSSII = XSKNXTEZNJSQTF;
/*INC*/	if (!INC(BCCFQMWHBVSSII, arg_to)) goto sentence_after_6;
	if (! isSymbolType(BCCFQMWHBVSSII.container->type)) goto sentence_after_6;
/*SET*/	r_BB = BCCFQMWHBVSSII;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = r_BB;
/*SET*/	r_e = arg_to;

// подготовка подстановки 
DataChain* MJAHTPUTIEBPBB = new DataChain(); 
DataContainer* MJAHTPUTIEBPBB_execbr = newRefExecBrackets(Switch, MJAHTPUTIEBPBB, "Switch");
result->append(MJAHTPUTIEBPBB_execbr);
MJAHTPUTIEBPBB->append_copy(l_G, r_G); 
MJAHTPUTIEBPBB->append_copy(l_s, r_s); 
MJAHTPUTIEBPBB->append(newRefText("=")); 
DataChain* MUEGYRHLTHXWGJ = new DataChain(); 
DataContainer* MUEGYRHLTHXWGJ_execbr = newRefExecBrackets(Maix, MUEGYRHLTHXWGJ, "Maix");
MJAHTPUTIEBPBB->append(MUEGYRHLTHXWGJ_execbr);
MUEGYRHLTHXWGJ->append(newRefText("i")); 
MUEGYRHLTHXWGJ->append_copy(l_AA, r_AA); 
MUEGYRHLTHXWGJ->append_copy(l_BB, r_BB); 
DataChain* PRWVHSHZYAVQYE = new DataChain(); 
DataContainer* PRWVHSHZYAVQYE_execbr = newRefExecBrackets(Compare, PRWVHSHZYAVQYE, "Compare");
MUEGYRHLTHXWGJ->append(PRWVHSHZYAVQYE_execbr);
PRWVHSHZYAVQYE->append_copy(l_AA, r_AA); 
PRWVHSHZYAVQYE->append_copy(l_BB, r_BB); 
context->pushExecuteCall(PRWVHSHZYAVQYE_execbr);
context->pushExecuteCall(MUEGYRHLTHXWGJ_execbr);
MJAHTPUTIEBPBB->append_copy(l_e, r_e); 
context->pushExecuteCall(MJAHTPUTIEBPBB_execbr);

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
DataChain* CZTOZOABNANHRR = new DataChain(); 
DataContainer* CZTOZOABNANHRR_execbr = newRefExecBrackets(Prout, CZTOZOABNANHRR, "Prout");
result->append(CZTOZOABNANHRR_execbr);
CZTOZOABNANHRR->append(newRefText("Sw unk: ")); 
CZTOZOABNANHRR->append_copy(l_e, r_e); 
context->pushExecuteCall(CZTOZOABNANHRR_execbr);

return result; 
}
sentence_after_7: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Maix(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor BDDNDODXEUIOZI;
/*SET*/	BDDNDODXEUIOZI = arg_from;
/*INC*/	if (!INC(BDDNDODXEUIOZI, arg_to)) goto sentence_after_1;
	if (BDDNDODXEUIOZI.container->type != text || *(BDDNDODXEUIOZI.container->value.text + BDDNDODXEUIOZI.index) != 'a') goto sentence_after_1;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor OIUOZXQTIHWAUR;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = BDDNDODXEUIOZI;
/*SET*/	OIUOZXQTIHWAUR = BDDNDODXEUIOZI;
/*INC*/	if (!INC(OIUOZXQTIHWAUR, arg_to)) goto sentence_after_1;
	if (! isSymbolType(OIUOZXQTIHWAUR.container->type)) goto sentence_after_1;
/*SET*/	r_A = OIUOZXQTIHWAUR;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor OQRDQWCVLXZIPO;
/*DEF*/	DataCursor l_B;
/*DEF*/	DataCursor r_B;
/*SET*/	l_B = r_A;
/*SET*/	OQRDQWCVLXZIPO = r_A;
/*INC*/	if (!INC(OQRDQWCVLXZIPO, arg_to)) goto sentence_after_1;
	if (! isSymbolType(OQRDQWCVLXZIPO.container->type)) goto sentence_after_1;
/*SET*/	r_B = OQRDQWCVLXZIPO;
//// [ `a` <any> ] 
/*DEF*/	DataCursor DIISPQNZOMCWVA;
/*SET*/	DIISPQNZOMCWVA = r_B;
/*INC*/	if (!INC(DIISPQNZOMCWVA, arg_to)) goto sentence_after_1;
	if (DIISPQNZOMCWVA.container->type != text || *(DIISPQNZOMCWVA.container->value.text + DIISPQNZOMCWVA.index) != '-') goto sentence_after_1;
//// [ empty ] 
/*ISEMPTY*/	if (DIISPQNZOMCWVA!=0 && arg_to != DIISPQNZOMCWVA) goto sentence_after_1;

// подготовка подстановки 
result->append_copy(l_B, r_B); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor SHCCXHUUYYHTGD;
/*SET*/	SHCCXHUUYYHTGD = arg_from;
/*INC*/	if (!INC(SHCCXHUUYYHTGD, arg_to)) goto sentence_after_2;
	if (SHCCXHUUYYHTGD.container->type != text || *(SHCCXHUUYYHTGD.container->value.text + SHCCXHUUYYHTGD.index) != 'a') goto sentence_after_2;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor GLFCIEBDUTOEUN;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = SHCCXHUUYYHTGD;
/*SET*/	GLFCIEBDUTOEUN = SHCCXHUUYYHTGD;
/*INC*/	if (!INC(GLFCIEBDUTOEUN, arg_to)) goto sentence_after_2;
	if (! isSymbolType(GLFCIEBDUTOEUN.container->type)) goto sentence_after_2;
/*SET*/	r_A = GLFCIEBDUTOEUN;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor FHDAXPHBSYWZTP;
/*DEF*/	DataCursor l_B;
/*DEF*/	DataCursor r_B;
/*SET*/	l_B = r_A;
/*SET*/	FHDAXPHBSYWZTP = r_A;
/*INC*/	if (!INC(FHDAXPHBSYWZTP, arg_to)) goto sentence_after_2;
	if (! isSymbolType(FHDAXPHBSYWZTP.container->type)) goto sentence_after_2;
/*SET*/	r_B = FHDAXPHBSYWZTP;
//// [ `a` <any> ] 
/*DEF*/	DataCursor WJNGJNCPXRJVBV;
/*SET*/	WJNGJNCPXRJVBV = r_B;
/*INC*/	if (!INC(WJNGJNCPXRJVBV, arg_to)) goto sentence_after_2;
	if (WJNGJNCPXRJVBV.container->type != text || *(WJNGJNCPXRJVBV.container->value.text + WJNGJNCPXRJVBV.index) != '+') goto sentence_after_2;
//// [ empty ] 
/*ISEMPTY*/	if (WJNGJNCPXRJVBV!=0 && arg_to != WJNGJNCPXRJVBV) goto sentence_after_2;

// подготовка подстановки 
result->append_copy(l_A, r_A); 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor VECMPESROMDXLL;
/*SET*/	VECMPESROMDXLL = arg_from;
/*INC*/	if (!INC(VECMPESROMDXLL, arg_to)) goto sentence_after_3;
	if (VECMPESROMDXLL.container->type != text || *(VECMPESROMDXLL.container->value.text + VECMPESROMDXLL.index) != 'i') goto sentence_after_3;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor UBRYYESHQLZMRE;
/*DEF*/	DataCursor l_B;
/*DEF*/	DataCursor r_B;
/*SET*/	l_B = VECMPESROMDXLL;
/*SET*/	UBRYYESHQLZMRE = VECMPESROMDXLL;
/*INC*/	if (!INC(UBRYYESHQLZMRE, arg_to)) goto sentence_after_3;
	if (! isSymbolType(UBRYYESHQLZMRE.container->type)) goto sentence_after_3;
/*SET*/	r_B = UBRYYESHQLZMRE;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor WQNKQITXGIIGQU;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_B;
/*SET*/	WQNKQITXGIIGQU = r_B;
/*INC*/	if (!INC(WQNKQITXGIIGQU, arg_to)) goto sentence_after_3;
	if (! isSymbolType(WQNKQITXGIIGQU.container->type)) goto sentence_after_3;
/*SET*/	r_A = WQNKQITXGIIGQU;
//// [ `a` <any> ] 
/*DEF*/	DataCursor SKWTCZNLTERXBL;
/*SET*/	SKWTCZNLTERXBL = r_A;
/*INC*/	if (!INC(SKWTCZNLTERXBL, arg_to)) goto sentence_after_3;
	if (SKWTCZNLTERXBL.container->type != text || *(SKWTCZNLTERXBL.container->value.text + SKWTCZNLTERXBL.index) != '-') goto sentence_after_3;
//// [ empty ] 
/*ISEMPTY*/	if (SKWTCZNLTERXBL!=0 && arg_to != SKWTCZNLTERXBL) goto sentence_after_3;

// подготовка подстановки 
result->append_copy(l_B, r_B); 

return result; 
}
sentence_after_3: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor FCCOCKVRJBFRJP;
/*SET*/	FCCOCKVRJBFRJP = arg_from;
/*INC*/	if (!INC(FCCOCKVRJBFRJP, arg_to)) goto sentence_after_4;
	if (FCCOCKVRJBFRJP.container->type != text || *(FCCOCKVRJBFRJP.container->value.text + FCCOCKVRJBFRJP.index) != 'i') goto sentence_after_4;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor CGDJDRWDNPOSRJ;
/*DEF*/	DataCursor l_B;
/*DEF*/	DataCursor r_B;
/*SET*/	l_B = FCCOCKVRJBFRJP;
/*SET*/	CGDJDRWDNPOSRJ = FCCOCKVRJBFRJP;
/*INC*/	if (!INC(CGDJDRWDNPOSRJ, arg_to)) goto sentence_after_4;
	if (! isSymbolType(CGDJDRWDNPOSRJ.container->type)) goto sentence_after_4;
/*SET*/	r_B = CGDJDRWDNPOSRJ;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor GDRQRVQTVPPAZH;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_B;
/*SET*/	GDRQRVQTVPPAZH = r_B;
/*INC*/	if (!INC(GDRQRVQTVPPAZH, arg_to)) goto sentence_after_4;
	if (! isSymbolType(GDRQRVQTVPPAZH.container->type)) goto sentence_after_4;
/*SET*/	r_A = GDRQRVQTVPPAZH;
//// [ `a` <any> ] 
/*DEF*/	DataCursor LTJQVCCLPEZTSJ;
/*SET*/	LTJQVCCLPEZTSJ = r_A;
/*INC*/	if (!INC(LTJQVCCLPEZTSJ, arg_to)) goto sentence_after_4;
	if (LTJQVCCLPEZTSJ.container->type != text || *(LTJQVCCLPEZTSJ.container->value.text + LTJQVCCLPEZTSJ.index) != '+') goto sentence_after_4;
//// [ empty ] 
/*ISEMPTY*/	if (LTJQVCCLPEZTSJ!=0 && arg_to != LTJQVCCLPEZTSJ) goto sentence_after_4;

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
/*JMP*/	goto label_IFIFRTWQQEOJUE_firststep;
label_IFIFRTWQQEOJUE: 
/*INC*/	if (!INC(r_e, arg_to)) goto sentence_after_5;
label_IFIFRTWQQEOJUE_firststep: 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor QBNSKWZEEWZKAO;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_e;
/*SET*/	QBNSKWZEEWZKAO = r_e;
/*INC*/	if (!INC(QBNSKWZEEWZKAO, arg_to)) goto label_IFIFRTWQQEOJUE;
	if (! isSymbolType(QBNSKWZEEWZKAO.container->type)) goto label_IFIFRTWQQEOJUE;
/*SET*/	r_A = QBNSKWZEEWZKAO;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor JURSQGSCZVHHUJ;
/*DEF*/	DataCursor l_zn;
/*DEF*/	DataCursor r_zn;
/*SET*/	l_zn = r_A;
/*SET*/	JURSQGSCZVHHUJ = r_A;
/*INC*/	if (!INC(JURSQGSCZVHHUJ, arg_to)) goto label_IFIFRTWQQEOJUE;
	if (! isSymbolType(JURSQGSCZVHHUJ.container->type)) goto label_IFIFRTWQQEOJUE;
/*SET*/	r_zn = JURSQGSCZVHHUJ;
//// [ empty ] 
/*ISEMPTY*/	if (r_zn!=0 && arg_to != r_zn) goto label_IFIFRTWQQEOJUE;

// подготовка подстановки 
result->append_copy(l_A, r_A); 

return result; 
}
sentence_after_5: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* WriteXO__(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
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
DataChain* ZUMIGOFHWBKKFL = new DataChain(); 
DataContainer* ZUMIGOFHWBKKFL_execbr = newRefExecBrackets(Prout, ZUMIGOFHWBKKFL, "Prout");
result->append(ZUMIGOFHWBKKFL_execbr);
ZUMIGOFHWBKKFL->append(newRefWord("WriteXO:")); 
ZUMIGOFHWBKKFL->append_copy(l_e, r_e); 
context->pushExecuteCall(ZUMIGOFHWBKKFL_execbr);
DataChain* UWZKCTKAGXKSMF = new DataChain(); 
DataContainer* UWZKCTKAGXKSMF_execbr = newRefExecBrackets(WriteXO__, UWZKCTKAGXKSMF, "WriteXO__");
result->append(UWZKCTKAGXKSMF_execbr);
UWZKCTKAGXKSMF->append_copy(l_e, r_e); 
context->pushExecuteCall(UWZKCTKAGXKSMF_execbr);

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* WriteXO(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
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
/*DEF*/	DataCursor AUWINSJLSOJTRX;
/*DEF*/	DataCursor HWMHLVBYPECJEI;
/*DEF*/	DataCursor WWSTNEUIQUBPGU;
/*SET*/	AUWINSJLSOJTRX = arg_from;
/*INC*/	if (!INC(AUWINSJLSOJTRX, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (AUWINSJLSOJTRX.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	HWMHLVBYPECJEI = AUWINSJLSOJTRX.container->value.bracket_data.chain->at_before_first();
	WWSTNEUIQUBPGU   = AUWINSJLSOJTRX.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor GWGNMIKDWICKDI;
/*DEF*/	DataCursor l_g;
/*DEF*/	DataCursor r_g;
/*SET*/	l_g = HWMHLVBYPECJEI;
/*SET*/	GWGNMIKDWICKDI = HWMHLVBYPECJEI;
/*INC*/	if (!INC(GWGNMIKDWICKDI, WWSTNEUIQUBPGU)) goto sentence_after_2;
	if (! isSymbolType(GWGNMIKDWICKDI.container->type)) goto sentence_after_2;
/*SET*/	r_g = GWGNMIKDWICKDI;
//// [ empty ] 
/*ISEMPTY*/	if (r_g!=0 && WWSTNEUIQUBPGU != r_g) goto sentence_after_2;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor LSNPDQSVMTERDF;
/*DEF*/	DataCursor BLHWBAFBGARCSF;
/*DEF*/	DataCursor IJYLBIIMOFGXEI;
/*SET*/	LSNPDQSVMTERDF = AUWINSJLSOJTRX;
/*INC*/	if (!INC(LSNPDQSVMTERDF, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (LSNPDQSVMTERDF.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	BLHWBAFBGARCSF = LSNPDQSVMTERDF.container->value.bracket_data.chain->at_before_first();
	IJYLBIIMOFGXEI   = LSNPDQSVMTERDF.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = BLHWBAFBGARCSF;
/*SET*/	r_1 = IJYLBIIMOFGXEI;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor RPBTYWQZAPKKCA;
/*DEF*/	DataCursor FCOMVNTMDHZXLE;
/*DEF*/	DataCursor FPPYEBEOEQZNBH;
/*SET*/	RPBTYWQZAPKKCA = LSNPDQSVMTERDF;
/*INC*/	if (!INC(RPBTYWQZAPKKCA, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (RPBTYWQZAPKKCA.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	FCOMVNTMDHZXLE = RPBTYWQZAPKKCA.container->value.bracket_data.chain->at_before_first();
	FPPYEBEOEQZNBH   = RPBTYWQZAPKKCA.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = FCOMVNTMDHZXLE;
/*SET*/	r_2 = FPPYEBEOEQZNBH;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor YCWMFYAQQIANNY;
/*DEF*/	DataCursor HQOUIZVEAVGZJW;
/*DEF*/	DataCursor OBLSGWNKVJLNIV;
/*SET*/	YCWMFYAQQIANNY = RPBTYWQZAPKKCA;
/*INC*/	if (!INC(YCWMFYAQQIANNY, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (YCWMFYAQQIANNY.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	HQOUIZVEAVGZJW = YCWMFYAQQIANNY.container->value.bracket_data.chain->at_before_first();
	OBLSGWNKVJLNIV   = YCWMFYAQQIANNY.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = HQOUIZVEAVGZJW;
/*SET*/	r_n = OBLSGWNKVJLNIV;
//// [ empty ] 
/*ISEMPTY*/	if (YCWMFYAQQIANNY!=0 && arg_to != YCWMFYAQQIANNY) goto sentence_after_2;

// подготовка подстановки 
DataChain* QCWVZXTCTHYNMU = new DataChain(); 
DataContainer* QCWVZXTCTHYNMU_execbr = newRefExecBrackets(WXOif, QCWVZXTCTHYNMU, "WXOif");
result->append(QCWVZXTCTHYNMU_execbr);
DataChain* XQKWWMTFISGGLG = new DataChain(); 
QCWVZXTCTHYNMU->append(newRefStructBrackets(XQKWWMTFISGGLG)); 
XQKWWMTFISGGLG->append_copy(l_g, r_g); 
DataChain* COXPIPYTDBAMRY = new DataChain(); 
QCWVZXTCTHYNMU->append(newRefStructBrackets(COXPIPYTDBAMRY)); 
DataChain* KBOKMWGSDDPQKR = new DataChain(); 
DataContainer* KBOKMWGSDDPQKR_execbr = newRefExecBrackets(Strategy, KBOKMWGSDDPQKR, "Strategy");
COXPIPYTDBAMRY->append(KBOKMWGSDDPQKR_execbr);
KBOKMWGSDDPQKR->append_copy(l_1, r_1); 
context->pushExecuteCall(KBOKMWGSDDPQKR_execbr);
DataChain* ZYJCHZTMIEPAGW = new DataChain(); 
QCWVZXTCTHYNMU->append(newRefStructBrackets(ZYJCHZTMIEPAGW)); 
DataChain* HROQKHWUDBCIHP = new DataChain(); 
DataContainer* HROQKHWUDBCIHP_execbr = newRefExecBrackets(Strategy, HROQKHWUDBCIHP, "Strategy");
ZYJCHZTMIEPAGW->append(HROQKHWUDBCIHP_execbr);
HROQKHWUDBCIHP->append_copy(l_2, r_2); 
context->pushExecuteCall(HROQKHWUDBCIHP_execbr);
DataChain* QWAQZXUGKVAKVL = new DataChain(); 
QCWVZXTCTHYNMU->append(newRefStructBrackets(QWAQZXUGKVAKVL)); 
DataChain* AVKSWFZSDBVQID = new DataChain(); 
DataContainer* AVKSWFZSDBVQID_execbr = newRefExecBrackets(Strategy, AVKSWFZSDBVQID, "Strategy");
QWAQZXUGKVAKVL->append(AVKSWFZSDBVQID_execbr);
AVKSWFZSDBVQID->append_copy(l_n, r_n); 
context->pushExecuteCall(AVKSWFZSDBVQID_execbr);
DataChain* HTBCDEYTMPPHKU = new DataChain(); 
QCWVZXTCTHYNMU->append(newRefStructBrackets(HTBCDEYTMPPHKU)); 
HTBCDEYTMPPHKU->append_copy(l_1, r_1); 
DataChain* HSXORPUFWHJRUT = new DataChain(); 
QCWVZXTCTHYNMU->append(newRefStructBrackets(HSXORPUFWHJRUT)); 
HSXORPUFWHJRUT->append_copy(l_2, r_2); 
DataChain* KSSLHLRXLYDXVK = new DataChain(); 
QCWVZXTCTHYNMU->append(newRefStructBrackets(KSSLHLRXLYDXVK)); 
KSSLHLRXLYDXVK->append_copy(l_n, r_n); 
context->pushExecuteCall(QCWVZXTCTHYNMU_execbr);

return result; 
}
sentence_after_2: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* WXOif__(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
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
DataChain* OSAGGMPBGZVBAF = new DataChain(); 
DataContainer* OSAGGMPBGZVBAF_execbr = newRefExecBrackets(Prout, OSAGGMPBGZVBAF, "Prout");
result->append(OSAGGMPBGZVBAF_execbr);
OSAGGMPBGZVBAF->append(newRefWord("WXOif:")); 
OSAGGMPBGZVBAF->append_copy(l_e, r_e); 
context->pushExecuteCall(OSAGGMPBGZVBAF_execbr);
DataChain* AZJOHQSSWTORCK = new DataChain(); 
DataContainer* AZJOHQSSWTORCK_execbr = newRefExecBrackets(WXOif__, AZJOHQSSWTORCK, "WXOif__");
result->append(AZJOHQSSWTORCK_execbr);
AZJOHQSSWTORCK->append_copy(l_e, r_e); 
context->pushExecuteCall(AZJOHQSSWTORCK_execbr);

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* WXOif(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor QAXSREHNRLYJIW;
/*DEF*/	DataCursor TMHGLKOZFKMMXT;
/*DEF*/	DataCursor YVOXHFKXOPVYBJ;
/*SET*/	QAXSREHNRLYJIW = arg_from;
/*INC*/	if (!INC(QAXSREHNRLYJIW, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (QAXSREHNRLYJIW.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	TMHGLKOZFKMMXT = QAXSREHNRLYJIW.container->value.bracket_data.chain->at_before_first();
	YVOXHFKXOPVYBJ   = QAXSREHNRLYJIW.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor ZOXHZUBDNTOAMZ;
/*SET*/	ZOXHZUBDNTOAMZ = TMHGLKOZFKMMXT;
/*INC*/	if (!INC(ZOXHZUBDNTOAMZ, YVOXHFKXOPVYBJ)) goto sentence_after_1;
	if (ZOXHZUBDNTOAMZ.container->type != text || *(ZOXHZUBDNTOAMZ.container->value.text + ZOXHZUBDNTOAMZ.index) != '1') goto sentence_after_1;
//// [ empty ] 
/*ISEMPTY*/	if (ZOXHZUBDNTOAMZ!=0 && YVOXHFKXOPVYBJ != ZOXHZUBDNTOAMZ) goto sentence_after_1;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_eee1;
/*DEF*/	DataCursor r_eee1;
/*SET*/	l_eee1 = QAXSREHNRLYJIW;
/*SET*/	r_eee1 = QAXSREHNRLYJIW;
/*JMP*/	goto label_DBBGCKJQTEBICH_firststep;
label_DBBGCKJQTEBICH: 
/*INC*/	if (!INC(r_eee1, arg_to)) goto sentence_after_1;
label_DBBGCKJQTEBICH_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor ZNPPRQISWBDHOY;
/*DEF*/	DataCursor NCSAETLGBFVIOC;
/*DEF*/	DataCursor FWXWDRNLFFBFHV;
/*SET*/	ZNPPRQISWBDHOY = r_eee1;
/*INC*/	if (!INC(ZNPPRQISWBDHOY, arg_to)) goto label_DBBGCKJQTEBICH;
//// ISBRACKET 
	if (ZNPPRQISWBDHOY.container->type != struct_bracket) goto label_DBBGCKJQTEBICH;
//// JMP_BRACKET 
	NCSAETLGBFVIOC = ZNPPRQISWBDHOY.container->value.bracket_data.chain->at_before_first();
	FWXWDRNLFFBFHV   = ZNPPRQISWBDHOY.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = NCSAETLGBFVIOC;
/*SET*/	r_1 = NCSAETLGBFVIOC;
/*JMP*/	goto label_YXZUKJWOCYHZQJ_firststep;
label_YXZUKJWOCYHZQJ: 
/*INC*/	if (!INC(r_1, FWXWDRNLFFBFHV)) goto label_DBBGCKJQTEBICH;
label_YXZUKJWOCYHZQJ_firststep: 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor ZDHTBRRRLLKTCH;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_1;
/*SET*/	ZDHTBRRRLLKTCH = r_1;
/*INC*/	if (!INC(ZDHTBRRRLLKTCH, FWXWDRNLFFBFHV)) goto label_YXZUKJWOCYHZQJ;
	if (! isSymbolType(ZDHTBRRRLLKTCH.container->type)) goto label_YXZUKJWOCYHZQJ;
/*SET*/	r_A = ZDHTBRRRLLKTCH;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = r_A;
/*SET*/	r_2 = r_A;
/*JMP*/	goto label_FNCTPIRNAWONYD_firststep;
label_FNCTPIRNAWONYD: 
/*INC*/	if (!INC(r_2, FWXWDRNLFFBFHV)) goto label_YXZUKJWOCYHZQJ;
label_FNCTPIRNAWONYD_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor WWVUABUQCIMCNL;
/*SET*/	WWVUABUQCIMCNL = r_2;
 if (!SLIDE(WWVUABUQCIMCNL, FWXWDRNLFFBFHV, l_A, r_A)) goto label_FNCTPIRNAWONYD;
//// [ e.1 ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = WWVUABUQCIMCNL;
/*SET*/	r_3 = FWXWDRNLFFBFHV;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_eee2;
/*DEF*/	DataCursor r_eee2;
/*SET*/	l_eee2 = ZNPPRQISWBDHOY;
/*SET*/	r_eee2 = ZNPPRQISWBDHOY;
/*JMP*/	goto label_HQODEMAKMUNMAX_firststep;
label_HQODEMAKMUNMAX: 
/*INC*/	if (!INC(r_eee2, arg_to)) goto label_FNCTPIRNAWONYD;
label_HQODEMAKMUNMAX_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor IOMKEYWCOFQBKD;
/*DEF*/	DataCursor MZOIZGQIPZAYIX;
/*DEF*/	DataCursor RYDWSOVHZTKGZS;
/*SET*/	IOMKEYWCOFQBKD = r_eee2;
/*INC*/	if (!INC(IOMKEYWCOFQBKD, arg_to)) goto label_HQODEMAKMUNMAX;
//// ISBRACKET 
	if (IOMKEYWCOFQBKD.container->type != struct_bracket) goto label_HQODEMAKMUNMAX;
//// JMP_BRACKET 
	MZOIZGQIPZAYIX = IOMKEYWCOFQBKD.container->value.bracket_data.chain->at_before_first();
	RYDWSOVHZTKGZS   = IOMKEYWCOFQBKD.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_n1;
/*DEF*/	DataCursor r_n1;
/*SET*/	l_n1 = MZOIZGQIPZAYIX;
/*SET*/	r_n1 = MZOIZGQIPZAYIX;
/*JMP*/	goto label_KWPTKQCEXRNNXS_firststep;
label_KWPTKQCEXRNNXS: 
/*INC*/	if (!INC(r_n1, RYDWSOVHZTKGZS)) goto label_HQODEMAKMUNMAX;
label_KWPTKQCEXRNNXS_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor KYWNDQIZLZKLNI;
/*SET*/	KYWNDQIZLZKLNI = r_n1;
 if (!SLIDE(KYWNDQIZLZKLNI, RYDWSOVHZTKGZS, l_A, r_A)) goto label_KWPTKQCEXRNNXS;
//// [ e.1 ] 
/*DEF*/	DataCursor l_n2;
/*DEF*/	DataCursor r_n2;
/*SET*/	l_n2 = KYWNDQIZLZKLNI;
/*SET*/	r_n2 = RYDWSOVHZTKGZS;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor SSAMQAZHLNDNVI;
/*DEF*/	DataCursor LTKOIAFMEICGGU;
/*DEF*/	DataCursor ZXHRDJZZHERUSW;
/*SET*/	SSAMQAZHLNDNVI = IOMKEYWCOFQBKD;
/*INC*/	if (!INC(SSAMQAZHLNDNVI, arg_to)) goto label_KWPTKQCEXRNNXS;
//// ISBRACKET 
	if (SSAMQAZHLNDNVI.container->type != struct_bracket) goto label_KWPTKQCEXRNNXS;
//// JMP_BRACKET 
	LTKOIAFMEICGGU = SSAMQAZHLNDNVI.container->value.bracket_data.chain->at_before_first();
	ZXHRDJZZHERUSW   = SSAMQAZHLNDNVI.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_e1;
/*DEF*/	DataCursor r_e1;
/*SET*/	l_e1 = LTKOIAFMEICGGU;
/*SET*/	r_e1 = ZXHRDJZZHERUSW;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor AVNVSLONOASRUD;
/*DEF*/	DataCursor RNLDKLDKFZTAGI;
/*DEF*/	DataCursor ENATJZWXCLKKUL;
/*SET*/	AVNVSLONOASRUD = SSAMQAZHLNDNVI;
/*INC*/	if (!INC(AVNVSLONOASRUD, arg_to)) goto label_KWPTKQCEXRNNXS;
//// ISBRACKET 
	if (AVNVSLONOASRUD.container->type != struct_bracket) goto label_KWPTKQCEXRNNXS;
//// JMP_BRACKET 
	RNLDKLDKFZTAGI = AVNVSLONOASRUD.container->value.bracket_data.chain->at_before_first();
	ENATJZWXCLKKUL   = AVNVSLONOASRUD.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_e2;
/*DEF*/	DataCursor r_e2;
/*SET*/	l_e2 = RNLDKLDKFZTAGI;
/*SET*/	r_e2 = ENATJZWXCLKKUL;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor NCAQPTONEQLNBT;
/*DEF*/	DataCursor ODDBMIVAZXZMCO;
/*DEF*/	DataCursor JDHISWKAXIAGTU;
/*SET*/	NCAQPTONEQLNBT = AVNVSLONOASRUD;
/*INC*/	if (!INC(NCAQPTONEQLNBT, arg_to)) goto label_KWPTKQCEXRNNXS;
//// ISBRACKET 
	if (NCAQPTONEQLNBT.container->type != struct_bracket) goto label_KWPTKQCEXRNNXS;
//// JMP_BRACKET 
	ODDBMIVAZXZMCO = NCAQPTONEQLNBT.container->value.bracket_data.chain->at_before_first();
	JDHISWKAXIAGTU   = NCAQPTONEQLNBT.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = ODDBMIVAZXZMCO;
/*SET*/	r_n = JDHISWKAXIAGTU;
//// [ empty ] 
/*ISEMPTY*/	if (NCAQPTONEQLNBT!=0 && arg_to != NCAQPTONEQLNBT) goto label_KWPTKQCEXRNNXS;

// подготовка подстановки 
result->append(newRefText("#")); 
DataChain* TAFRSVPPHURAAA = new DataChain(); 
DataContainer* TAFRSVPPHURAAA_execbr = newRefExecBrackets(Lins, TAFRSVPPHURAAA, "Lins");
result->append(TAFRSVPPHURAAA_execbr);
DataChain* IXZTWDYRUUMQAD = new DataChain(); 
TAFRSVPPHURAAA->append(newRefStructBrackets(IXZTWDYRUUMQAD)); 
IXZTWDYRUUMQAD->append_copy(l_n, r_n); 
DataChain* JEPVVCVOIDWMTP = new DataChain(); 
DataContainer* JEPVVCVOIDWMTP_execbr = newRefExecBrackets(AntiStrategy, JEPVVCVOIDWMTP, "AntiStrategy");
TAFRSVPPHURAAA->append(JEPVVCVOIDWMTP_execbr);
JEPVVCVOIDWMTP->append_copy(l_A, r_A); 
context->pushExecuteCall(JEPVVCVOIDWMTP_execbr);
context->pushExecuteCall(TAFRSVPPHURAAA_execbr);

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor BNMQUIOPIWPUWC;
/*DEF*/	DataCursor ZDAPDZGHAVVIYI;
/*DEF*/	DataCursor ROJNOLSOWRMVVJ;
/*SET*/	BNMQUIOPIWPUWC = arg_from;
/*INC*/	if (!INC(BNMQUIOPIWPUWC, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (BNMQUIOPIWPUWC.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	ZDAPDZGHAVVIYI = BNMQUIOPIWPUWC.container->value.bracket_data.chain->at_before_first();
	ROJNOLSOWRMVVJ   = BNMQUIOPIWPUWC.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor IQSWRICMZSXAVD;
/*DEF*/	DataCursor l_g;
/*DEF*/	DataCursor r_g;
/*SET*/	l_g = ZDAPDZGHAVVIYI;
/*SET*/	IQSWRICMZSXAVD = ZDAPDZGHAVVIYI;
/*INC*/	if (!INC(IQSWRICMZSXAVD, ROJNOLSOWRMVVJ)) goto sentence_after_2;
	if (! isSymbolType(IQSWRICMZSXAVD.container->type)) goto sentence_after_2;
/*SET*/	r_g = IQSWRICMZSXAVD;
//// [ empty ] 
/*ISEMPTY*/	if (r_g!=0 && ROJNOLSOWRMVVJ != r_g) goto sentence_after_2;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = BNMQUIOPIWPUWC;
/*SET*/	r_e = BNMQUIOPIWPUWC;
/*JMP*/	goto label_QAMNFHWFGEOHSK_firststep;
label_QAMNFHWFGEOHSK: 
/*INC*/	if (!INC(r_e, arg_to)) goto sentence_after_2;
label_QAMNFHWFGEOHSK_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor KEFUTXXIBHPULN;
/*DEF*/	DataCursor LWXQWWZDGDJGEQ;
/*DEF*/	DataCursor WAPBHLPUDOEMNN;
/*SET*/	KEFUTXXIBHPULN = r_e;
/*INC*/	if (!INC(KEFUTXXIBHPULN, arg_to)) goto label_QAMNFHWFGEOHSK;
//// ISBRACKET 
	if (KEFUTXXIBHPULN.container->type != struct_bracket) goto label_QAMNFHWFGEOHSK;
//// JMP_BRACKET 
	LWXQWWZDGDJGEQ = KEFUTXXIBHPULN.container->value.bracket_data.chain->at_before_first();
	WAPBHLPUDOEMNN   = KEFUTXXIBHPULN.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = LWXQWWZDGDJGEQ;
/*SET*/	r_1 = WAPBHLPUDOEMNN;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor TPOUAHGXJHZJBE;
/*DEF*/	DataCursor PLTTRIABWUCRJM;
/*DEF*/	DataCursor BVBOZVMXOBATKH;
/*SET*/	TPOUAHGXJHZJBE = KEFUTXXIBHPULN;
/*INC*/	if (!INC(TPOUAHGXJHZJBE, arg_to)) goto label_QAMNFHWFGEOHSK;
//// ISBRACKET 
	if (TPOUAHGXJHZJBE.container->type != struct_bracket) goto label_QAMNFHWFGEOHSK;
//// JMP_BRACKET 
	PLTTRIABWUCRJM = TPOUAHGXJHZJBE.container->value.bracket_data.chain->at_before_first();
	BVBOZVMXOBATKH   = TPOUAHGXJHZJBE.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = PLTTRIABWUCRJM;
/*SET*/	r_2 = BVBOZVMXOBATKH;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor QSQCHLHTBOFUIK;
/*DEF*/	DataCursor WAFKCOWUUNTFHP;
/*DEF*/	DataCursor KDEYHOKQUWQVWT;
/*SET*/	QSQCHLHTBOFUIK = TPOUAHGXJHZJBE;
/*INC*/	if (!INC(QSQCHLHTBOFUIK, arg_to)) goto label_QAMNFHWFGEOHSK;
//// ISBRACKET 
	if (QSQCHLHTBOFUIK.container->type != struct_bracket) goto label_QAMNFHWFGEOHSK;
//// JMP_BRACKET 
	WAFKCOWUUNTFHP = QSQCHLHTBOFUIK.container->value.bracket_data.chain->at_before_first();
	KDEYHOKQUWQVWT   = QSQCHLHTBOFUIK.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = WAFKCOWUUNTFHP;
/*SET*/	r_n = KDEYHOKQUWQVWT;
//// [ empty ] 
/*ISEMPTY*/	if (QSQCHLHTBOFUIK!=0 && arg_to != QSQCHLHTBOFUIK) goto label_QAMNFHWFGEOHSK;

// подготовка подстановки 
DataChain* THHHUGJZMFEUIN = new DataChain(); 
DataContainer* THHHUGJZMFEUIN_execbr = newRefExecBrackets(WriteXO1, THHHUGJZMFEUIN, "WriteXO1");
result->append(THHHUGJZMFEUIN_execbr);
DataChain* IPBNCIZOCKAADA = new DataChain(); 
THHHUGJZMFEUIN->append(newRefStructBrackets(IPBNCIZOCKAADA)); 
IPBNCIZOCKAADA->append_copy(l_g, r_g); 
DataChain* LLJREQTKHUDBLP = new DataChain(); 
THHHUGJZMFEUIN->append(newRefStructBrackets(LLJREQTKHUDBLP)); 
LLJREQTKHUDBLP->append_copy(l_1, r_1); 
DataChain* RZLSRWXOCCSLUT = new DataChain(); 
THHHUGJZMFEUIN->append(newRefStructBrackets(RZLSRWXOCCSLUT)); 
RZLSRWXOCCSLUT->append_copy(l_2, r_2); 
DataChain* WQZSQTIJVCWNPF = new DataChain(); 
THHHUGJZMFEUIN->append(newRefStructBrackets(WQZSQTIJVCWNPF)); 
WQZSQTIJVCWNPF->append_copy(l_n, r_n); 
context->pushExecuteCall(THHHUGJZMFEUIN_execbr);

return result; 
}
sentence_after_2: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Lins__(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
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
DataChain* LRLUKDIAOHQJHR = new DataChain(); 
DataContainer* LRLUKDIAOHQJHR_execbr = newRefExecBrackets(Prout, LRLUKDIAOHQJHR, "Prout");
result->append(LRLUKDIAOHQJHR_execbr);
LRLUKDIAOHQJHR->append(newRefWord("Lins:")); 
LRLUKDIAOHQJHR->append_copy(l_e, r_e); 
context->pushExecuteCall(LRLUKDIAOHQJHR_execbr);
DataChain* AGLGRIYKLDKDFR = new DataChain(); 
DataContainer* AGLGRIYKLDKDFR_execbr = newRefExecBrackets(Lins__, AGLGRIYKLDKDFR, "Lins__");
result->append(AGLGRIYKLDKDFR_execbr);
AGLGRIYKLDKDFR->append_copy(l_e, r_e); 
context->pushExecuteCall(AGLGRIYKLDKDFR_execbr);

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Lins(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor DRXJSTCWRSXGYW;
/*DEF*/	DataCursor FNHCBKPMESUPMT;
/*DEF*/	DataCursor RVIPFBKTBWZFAH;
/*SET*/	DRXJSTCWRSXGYW = arg_from;
/*INC*/	if (!INC(DRXJSTCWRSXGYW, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (DRXJSTCWRSXGYW.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	FNHCBKPMESUPMT = DRXJSTCWRSXGYW.container->value.bracket_data.chain->at_before_first();
	RVIPFBKTBWZFAH   = DRXJSTCWRSXGYW.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_n1;
/*DEF*/	DataCursor r_n1;
/*SET*/	l_n1 = FNHCBKPMESUPMT;
/*SET*/	r_n1 = FNHCBKPMESUPMT;
/*JMP*/	goto label_OEVNHXBRHHFOBG_firststep;
label_OEVNHXBRHHFOBG: 
/*INC*/	if (!INC(r_n1, RVIPFBKTBWZFAH)) goto sentence_after_1;
label_OEVNHXBRHHFOBG_firststep: 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor YWCVHKTDOXQTEK;
/*DEF*/	DataCursor l_hod;
/*DEF*/	DataCursor r_hod;
/*SET*/	l_hod = r_n1;
/*SET*/	YWCVHKTDOXQTEK = r_n1;
/*INC*/	if (!INC(YWCVHKTDOXQTEK, RVIPFBKTBWZFAH)) goto label_OEVNHXBRHHFOBG;
	if (! isSymbolType(YWCVHKTDOXQTEK.container->type)) goto label_OEVNHXBRHHFOBG;
/*SET*/	r_hod = YWCVHKTDOXQTEK;
//// [ e.1 ] 
/*DEF*/	DataCursor l_n2;
/*DEF*/	DataCursor r_n2;
/*SET*/	l_n2 = r_hod;
/*SET*/	r_n2 = RVIPFBKTBWZFAH;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_as1;
/*DEF*/	DataCursor r_as1;
/*SET*/	l_as1 = DRXJSTCWRSXGYW;
/*SET*/	r_as1 = DRXJSTCWRSXGYW;
/*JMP*/	goto label_IWWURZBLMLDLFI_firststep;
label_IWWURZBLMLDLFI: 
/*INC*/	if (!INC(r_as1, arg_to)) goto label_OEVNHXBRHHFOBG;
label_IWWURZBLMLDLFI_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor BDVEMUNNLXUBYK;
/*SET*/	BDVEMUNNLXUBYK = r_as1;
 if (!SLIDE(BDVEMUNNLXUBYK, arg_to, l_hod, r_hod)) goto label_IWWURZBLMLDLFI;
//// [ e.1 ] 
/*DEF*/	DataCursor l_as2;
/*DEF*/	DataCursor r_as2;
/*SET*/	l_as2 = BDVEMUNNLXUBYK;
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

DataChain* AntiStrategy__(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
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
DataChain* VVRGKTRERPTISI = new DataChain(); 
DataContainer* VVRGKTRERPTISI_execbr = newRefExecBrackets(Prout, VVRGKTRERPTISI, "Prout");
result->append(VVRGKTRERPTISI_execbr);
VVRGKTRERPTISI->append(newRefWord("AntiStrategy:")); 
VVRGKTRERPTISI->append_copy(l_e, r_e); 
context->pushExecuteCall(VVRGKTRERPTISI_execbr);
DataChain* ZXHREVNXQUEZXK = new DataChain(); 
DataContainer* ZXHREVNXQUEZXK_execbr = newRefExecBrackets(AntiStrategy__, ZXHREVNXQUEZXK, "AntiStrategy__");
result->append(ZXHREVNXQUEZXK_execbr);
ZXHREVNXQUEZXK->append_copy(l_e, r_e); 
context->pushExecuteCall(ZXHREVNXQUEZXK_execbr);

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* AntiStrategy(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor UGROOHRHUDIDGV;
/*SET*/	UGROOHRHUDIDGV = arg_from;
/*INC*/	if (!INC(UGROOHRHUDIDGV, arg_to)) goto sentence_after_1;
	if (UGROOHRHUDIDGV.container->type != text || *(UGROOHRHUDIDGV.container->value.text + UGROOHRHUDIDGV.index) != '1') goto sentence_after_1;
//// [ empty ] 
/*ISEMPTY*/	if (UGROOHRHUDIDGV!=0 && arg_to != UGROOHRHUDIDGV) goto sentence_after_1;

// подготовка подстановки 
result->append(newRefText("123")); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor GPRPSEACCXKWVI;
/*SET*/	GPRPSEACCXKWVI = arg_from;
/*INC*/	if (!INC(GPRPSEACCXKWVI, arg_to)) goto sentence_after_2;
	if (GPRPSEACCXKWVI.container->type != text || *(GPRPSEACCXKWVI.container->value.text + GPRPSEACCXKWVI.index) != '2') goto sentence_after_2;
//// [ empty ] 
/*ISEMPTY*/	if (GPRPSEACCXKWVI!=0 && arg_to != GPRPSEACCXKWVI) goto sentence_after_2;

// подготовка подстановки 
result->append(newRefText("456")); 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor EEVDGGATFIEKIX;
/*SET*/	EEVDGGATFIEKIX = arg_from;
/*INC*/	if (!INC(EEVDGGATFIEKIX, arg_to)) goto sentence_after_3;
	if (EEVDGGATFIEKIX.container->type != text || *(EEVDGGATFIEKIX.container->value.text + EEVDGGATFIEKIX.index) != '3') goto sentence_after_3;
//// [ empty ] 
/*ISEMPTY*/	if (EEVDGGATFIEKIX!=0 && arg_to != EEVDGGATFIEKIX) goto sentence_after_3;

// подготовка подстановки 
result->append(newRefText("789")); 

return result; 
}
sentence_after_3: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor QMYHJMJTIMDSPI;
/*SET*/	QMYHJMJTIMDSPI = arg_from;
/*INC*/	if (!INC(QMYHJMJTIMDSPI, arg_to)) goto sentence_after_4;
	if (QMYHJMJTIMDSPI.container->type != text || *(QMYHJMJTIMDSPI.container->value.text + QMYHJMJTIMDSPI.index) != '4') goto sentence_after_4;
//// [ empty ] 
/*ISEMPTY*/	if (QMYHJMJTIMDSPI!=0 && arg_to != QMYHJMJTIMDSPI) goto sentence_after_4;

// подготовка подстановки 
result->append(newRefText("147")); 

return result; 
}
sentence_after_4: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor MBGYGFVTQVZQAT;
/*SET*/	MBGYGFVTQVZQAT = arg_from;
/*INC*/	if (!INC(MBGYGFVTQVZQAT, arg_to)) goto sentence_after_5;
	if (MBGYGFVTQVZQAT.container->type != text || *(MBGYGFVTQVZQAT.container->value.text + MBGYGFVTQVZQAT.index) != '5') goto sentence_after_5;
//// [ empty ] 
/*ISEMPTY*/	if (MBGYGFVTQVZQAT!=0 && arg_to != MBGYGFVTQVZQAT) goto sentence_after_5;

// подготовка подстановки 
result->append(newRefText("258")); 

return result; 
}
sentence_after_5: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor BHMKQLWHQNGHLV;
/*SET*/	BHMKQLWHQNGHLV = arg_from;
/*INC*/	if (!INC(BHMKQLWHQNGHLV, arg_to)) goto sentence_after_6;
	if (BHMKQLWHQNGHLV.container->type != text || *(BHMKQLWHQNGHLV.container->value.text + BHMKQLWHQNGHLV.index) != '6') goto sentence_after_6;
//// [ empty ] 
/*ISEMPTY*/	if (BHMKQLWHQNGHLV!=0 && arg_to != BHMKQLWHQNGHLV) goto sentence_after_6;

// подготовка подстановки 
result->append(newRefText("369")); 

return result; 
}
sentence_after_6: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor BPMBLXNKEOFMNI;
/*SET*/	BPMBLXNKEOFMNI = arg_from;
/*INC*/	if (!INC(BPMBLXNKEOFMNI, arg_to)) goto sentence_after_7;
	if (BPMBLXNKEOFMNI.container->type != text || *(BPMBLXNKEOFMNI.container->value.text + BPMBLXNKEOFMNI.index) != '7') goto sentence_after_7;
//// [ empty ] 
/*ISEMPTY*/	if (BPMBLXNKEOFMNI!=0 && arg_to != BPMBLXNKEOFMNI) goto sentence_after_7;

// подготовка подстановки 
result->append(newRefText("159")); 

return result; 
}
sentence_after_7: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor TERQPJJWAKNKXT;
/*SET*/	TERQPJJWAKNKXT = arg_from;
/*INC*/	if (!INC(TERQPJJWAKNKXT, arg_to)) goto sentence_after_8;
	if (TERQPJJWAKNKXT.container->type != text || *(TERQPJJWAKNKXT.container->value.text + TERQPJJWAKNKXT.index) != '8') goto sentence_after_8;
//// [ empty ] 
/*ISEMPTY*/	if (TERQPJJWAKNKXT!=0 && arg_to != TERQPJJWAKNKXT) goto sentence_after_8;

// подготовка подстановки 
result->append(newRefText("357")); 

return result; 
}
sentence_after_8: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* WriteXO1__(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
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
DataChain* LNUKBIYSPLKHJU = new DataChain(); 
DataContainer* LNUKBIYSPLKHJU_execbr = newRefExecBrackets(Prout, LNUKBIYSPLKHJU, "Prout");
result->append(LNUKBIYSPLKHJU_execbr);
LNUKBIYSPLKHJU->append(newRefWord("WriteXO1:")); 
LNUKBIYSPLKHJU->append_copy(l_e, r_e); 
context->pushExecuteCall(LNUKBIYSPLKHJU_execbr);
DataChain* CFUWOHZVPHJBJY = new DataChain(); 
DataContainer* CFUWOHZVPHJBJY_execbr = newRefExecBrackets(WriteXO1__, CFUWOHZVPHJBJY, "WriteXO1__");
result->append(CFUWOHZVPHJBJY_execbr);
CFUWOHZVPHJBJY->append_copy(l_e, r_e); 
context->pushExecuteCall(CFUWOHZVPHJBJY_execbr);

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* WriteXO1(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
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
/*JMP*/	goto label_OVDLNBFRKVBEMW_firststep;
label_OVDLNBFRKVBEMW: 
/*INC*/	if (!INC(r_eee, arg_to)) goto sentence_after_2;
label_OVDLNBFRKVBEMW_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor YTFJYNQMGZAGBK;
/*DEF*/	DataCursor WEKKOUXDCYNKHT;
/*DEF*/	DataCursor OSFYTLUCENTOIL;
/*SET*/	YTFJYNQMGZAGBK = r_eee;
/*INC*/	if (!INC(YTFJYNQMGZAGBK, arg_to)) goto label_OVDLNBFRKVBEMW;
//// ISBRACKET 
	if (YTFJYNQMGZAGBK.container->type != struct_bracket) goto label_OVDLNBFRKVBEMW;
//// JMP_BRACKET 
	WEKKOUXDCYNKHT = YTFJYNQMGZAGBK.container->value.bracket_data.chain->at_before_first();
	OSFYTLUCENTOIL   = YTFJYNQMGZAGBK.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = WEKKOUXDCYNKHT;
/*SET*/	r_3 = WEKKOUXDCYNKHT;
/*JMP*/	goto label_FULDVRXLONVKXZ_firststep;
label_FULDVRXLONVKXZ: 
/*INC*/	if (!INC(r_3, OSFYTLUCENTOIL)) goto label_OVDLNBFRKVBEMW;
label_FULDVRXLONVKXZ_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor ECXEPKMZZGXLUA;
/*SET*/	ECXEPKMZZGXLUA = r_3;
/*INC*/	if (!INC(ECXEPKMZZGXLUA, OSFYTLUCENTOIL)) goto label_FULDVRXLONVKXZ;
	if (ECXEPKMZZGXLUA.container->type != text || *(ECXEPKMZZGXLUA.container->value.text + ECXEPKMZZGXLUA.index) != '>') goto label_FULDVRXLONVKXZ;
//// [ empty ] 
/*ISEMPTY*/	if (ECXEPKMZZGXLUA!=0 && OSFYTLUCENTOIL != ECXEPKMZZGXLUA) goto label_FULDVRXLONVKXZ;
//// [ empty ] 
/*ISEMPTY*/	if (YTFJYNQMGZAGBK!=0 && arg_to != YTFJYNQMGZAGBK) goto label_FULDVRXLONVKXZ;

// подготовка подстановки 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor PJIKVPAUDVKXGL;
/*DEF*/	DataCursor LISAAMBOVJKDQR;
/*DEF*/	DataCursor KDORJFNYGHHHPT;
/*SET*/	PJIKVPAUDVKXGL = arg_from;
/*INC*/	if (!INC(PJIKVPAUDVKXGL, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (PJIKVPAUDVKXGL.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	LISAAMBOVJKDQR = PJIKVPAUDVKXGL.container->value.bracket_data.chain->at_before_first();
	KDORJFNYGHHHPT   = PJIKVPAUDVKXGL.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor ZIFAWFTZQGEMNH;
/*DEF*/	DataCursor l_g;
/*DEF*/	DataCursor r_g;
/*SET*/	l_g = LISAAMBOVJKDQR;
/*SET*/	ZIFAWFTZQGEMNH = LISAAMBOVJKDQR;
/*INC*/	if (!INC(ZIFAWFTZQGEMNH, KDORJFNYGHHHPT)) goto sentence_after_3;
	if (! isSymbolType(ZIFAWFTZQGEMNH.container->type)) goto sentence_after_3;
/*SET*/	r_g = ZIFAWFTZQGEMNH;
//// [ empty ] 
/*ISEMPTY*/	if (r_g!=0 && KDORJFNYGHHHPT != r_g) goto sentence_after_3;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_eee;
/*DEF*/	DataCursor r_eee;
/*SET*/	l_eee = PJIKVPAUDVKXGL;
/*SET*/	r_eee = PJIKVPAUDVKXGL;
/*JMP*/	goto label_PQYICTMOYFPCVK_firststep;
label_PQYICTMOYFPCVK: 
/*INC*/	if (!INC(r_eee, arg_to)) goto sentence_after_3;
label_PQYICTMOYFPCVK_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor CAODAKJACQAUZY;
/*DEF*/	DataCursor OWDZSFQHKPLFBY;
/*DEF*/	DataCursor ZMNIMDLXMJYDAX;
/*SET*/	CAODAKJACQAUZY = r_eee;
/*INC*/	if (!INC(CAODAKJACQAUZY, arg_to)) goto label_PQYICTMOYFPCVK;
//// ISBRACKET 
	if (CAODAKJACQAUZY.container->type != struct_bracket) goto label_PQYICTMOYFPCVK;
//// JMP_BRACKET 
	OWDZSFQHKPLFBY = CAODAKJACQAUZY.container->value.bracket_data.chain->at_before_first();
	ZMNIMDLXMJYDAX   = CAODAKJACQAUZY.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = OWDZSFQHKPLFBY;
/*SET*/	r_3 = OWDZSFQHKPLFBY;
/*JMP*/	goto label_YJNECXSJJBHIQN_firststep;
label_YJNECXSJJBHIQN: 
/*INC*/	if (!INC(r_3, ZMNIMDLXMJYDAX)) goto label_PQYICTMOYFPCVK;
label_YJNECXSJJBHIQN_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor VOCDENQMWILXXZ;
/*SET*/	VOCDENQMWILXXZ = r_3;
/*INC*/	if (!INC(VOCDENQMWILXXZ, ZMNIMDLXMJYDAX)) goto label_YJNECXSJJBHIQN;
	if (VOCDENQMWILXXZ.container->type != text || *(VOCDENQMWILXXZ.container->value.text + VOCDENQMWILXXZ.index) != '>') goto label_YJNECXSJJBHIQN;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor OQFOTPIKPQUDMO;
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = VOCDENQMWILXXZ;
/*SET*/	OQFOTPIKPQUDMO = VOCDENQMWILXXZ;
/*INC*/	if (!INC(OQFOTPIKPQUDMO, ZMNIMDLXMJYDAX)) goto label_YJNECXSJJBHIQN;
	if (! isSymbolType(OQFOTPIKPQUDMO.container->type)) goto label_YJNECXSJJBHIQN;
/*SET*/	r_s = OQFOTPIKPQUDMO;
//// [ e.1 ] 
/*DEF*/	DataCursor l_4;
/*DEF*/	DataCursor r_4;
/*SET*/	l_4 = r_s;
/*SET*/	r_4 = ZMNIMDLXMJYDAX;
//// [ empty ] 
/*ISEMPTY*/	if (CAODAKJACQAUZY!=0 && arg_to != CAODAKJACQAUZY) goto label_YJNECXSJJBHIQN;

// подготовка подстановки 
DataChain* XIISYZWNHXYFVY = new DataChain(); 
DataContainer* XIISYZWNHXYFVY_execbr = newRefExecBrackets(Length, XIISYZWNHXYFVY, "Length");
result->append(XIISYZWNHXYFVY_execbr);
DataChain* DFMPDWOMCIUDCN = new DataChain(); 
DataContainer* DFMPDWOMCIUDCN_execbr = newRefExecBrackets(Optima21, DFMPDWOMCIUDCN, "Optima21");
XIISYZWNHXYFVY->append(DFMPDWOMCIUDCN_execbr);
DataChain* YNDGCNFJITPPMY = new DataChain(); 
DataContainer* YNDGCNFJITPPMY_execbr = newRefExecBrackets(Analiz, YNDGCNFJITPPMY, "Analiz");
DFMPDWOMCIUDCN->append(YNDGCNFJITPPMY_execbr);
DataChain* MXIISNEBPYWSGQ = new DataChain(); 
YNDGCNFJITPPMY->append(newRefStructBrackets(MXIISNEBPYWSGQ)); 
MXIISNEBPYWSGQ->append_copy(l_g, r_g); 
YNDGCNFJITPPMY->append_copy(l_eee, r_eee); 
DataChain* SXDJPLWZFMJOOP = new DataChain(); 
YNDGCNFJITPPMY->append(newRefStructBrackets(SXDJPLWZFMJOOP)); 
SXDJPLWZFMJOOP->append_copy(l_3, r_3); 
SXDJPLWZFMJOOP->append(newRefText(">")); 
SXDJPLWZFMJOOP->append_copy(l_s, r_s); 
SXDJPLWZFMJOOP->append_copy(l_4, r_4); 
context->pushExecuteCall(YNDGCNFJITPPMY_execbr);
context->pushExecuteCall(DFMPDWOMCIUDCN_execbr);
context->pushExecuteCall(XIISYZWNHXYFVY_execbr);
DataChain* YYIFVKMWWPGPLJ = new DataChain(); 
DataContainer* YYIFVKMWWPGPLJ_execbr = newRefExecBrackets(WriteXO, YYIFVKMWWPGPLJ, "WriteXO");
result->append(YYIFVKMWWPGPLJ_execbr);
DataChain* EAWPVAPIHOXUUF = new DataChain(); 
YYIFVKMWWPGPLJ->append(newRefStructBrackets(EAWPVAPIHOXUUF)); 
EAWPVAPIHOXUUF->append_copy(l_g, r_g); 
YYIFVKMWWPGPLJ->append_copy(l_eee, r_eee); 
DataChain* FBRWHPEVCOQRGR = new DataChain(); 
YYIFVKMWWPGPLJ->append(newRefStructBrackets(FBRWHPEVCOQRGR)); 
FBRWHPEVCOQRGR->append_copy(l_3, r_3); 
FBRWHPEVCOQRGR->append_copy(l_s, r_s); 
FBRWHPEVCOQRGR->append(newRefText(">")); 
FBRWHPEVCOQRGR->append_copy(l_4, r_4); 
context->pushExecuteCall(YYIFVKMWWPGPLJ_execbr);

return result; 
}
sentence_after_3: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* First1(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor QWZHIBNORKHZML;
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	QWZHIBNORKHZML = arg_from;
/*INC*/	if (!INC(QWZHIBNORKHZML, arg_to)) goto sentence_after_1;
	if (! isSymbolType(QWZHIBNORKHZML.container->type)) goto sentence_after_1;
/*SET*/	r_1 = QWZHIBNORKHZML;
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

DataChain* Length__(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
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
DataChain* BZFHXUNRKLIBVP = new DataChain(); 
DataContainer* BZFHXUNRKLIBVP_execbr = newRefExecBrackets(Prout, BZFHXUNRKLIBVP, "Prout");
result->append(BZFHXUNRKLIBVP_execbr);
BZFHXUNRKLIBVP->append(newRefWord("Length:")); 
BZFHXUNRKLIBVP->append_copy(l_e, r_e); 
context->pushExecuteCall(BZFHXUNRKLIBVP_execbr);
DataChain* SZZNOPFGAXZGFL = new DataChain(); 
DataContainer* SZZNOPFGAXZGFL_execbr = newRefExecBrackets(Length__, SZZNOPFGAXZGFL, "Length__");
result->append(SZZNOPFGAXZGFL_execbr);
SZZNOPFGAXZGFL->append_copy(l_e, r_e); 
context->pushExecuteCall(SZZNOPFGAXZGFL_execbr);

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Length(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	r_1 = arg_from;
/*JMP*/	goto label_TLSXBTUMILOCLT_firststep;
label_TLSXBTUMILOCLT: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_1;
label_TLSXBTUMILOCLT_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor GCOZGTZIUFUZIM;
/*SET*/	GCOZGTZIUFUZIM = r_1;
/*INC*/	if (!INC(GCOZGTZIUFUZIM, arg_to)) goto label_TLSXBTUMILOCLT;
	static DataChain *DIOGCSEOZPSCRH = text_to_chain("12");
	static DataCursor DIOGCSEOZPSCRH_l = DIOGCSEOZPSCRH->at_before_first();
	static DataCursor DIOGCSEOZPSCRH_r = DIOGCSEOZPSCRH->at_last();
 if (!SLIDE(GCOZGTZIUFUZIM, arg_to, DIOGCSEOZPSCRH_l, DIOGCSEOZPSCRH_r)) goto label_TLSXBTUMILOCLT;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = GCOZGTZIUFUZIM;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
DataChain* JOTYCZCWMBAAOL = new DataChain(); 
DataContainer* JOTYCZCWMBAAOL_execbr = newRefExecBrackets(DivS, JOTYCZCWMBAAOL, "DivS");
result->append(JOTYCZCWMBAAOL_execbr);
DataChain* SVUBPYLONMWAJG = new DataChain(); 
DataContainer* SVUBPYLONMWAJG_execbr = newRefExecBrackets(First1, SVUBPYLONMWAJG, "First1");
JOTYCZCWMBAAOL->append(SVUBPYLONMWAJG_execbr);
DataChain* XZGYZAOVENFVOC = new DataChain(); 
DataContainer* XZGYZAOVENFVOC_execbr = newRefExecBrackets(Lenw, XZGYZAOVENFVOC, "Lenw");
SVUBPYLONMWAJG->append(XZGYZAOVENFVOC_execbr);
XZGYZAOVENFVOC->append_copy(l_1, r_1); 
XZGYZAOVENFVOC->append(newRefText("1")); 
context->pushExecuteCall(XZGYZAOVENFVOC_execbr);
context->pushExecuteCall(SVUBPYLONMWAJG_execbr);
DataChain* IKQJTXGVENKSPP = new DataChain(); 
DataContainer* IKQJTXGVENKSPP_execbr = newRefExecBrackets(First1, IKQJTXGVENKSPP, "First1");
JOTYCZCWMBAAOL->append(IKQJTXGVENKSPP_execbr);
DataChain* WWPLHXTGYBVMAJ = new DataChain(); 
DataContainer* WWPLHXTGYBVMAJ_execbr = newRefExecBrackets(Lenw, WWPLHXTGYBVMAJ, "Lenw");
IKQJTXGVENKSPP->append(WWPLHXTGYBVMAJ_execbr);
WWPLHXTGYBVMAJ->append(newRefText("2")); 
WWPLHXTGYBVMAJ->append_copy(l_2, r_2); 
context->pushExecuteCall(WWPLHXTGYBVMAJ_execbr);
context->pushExecuteCall(IKQJTXGVENKSPP_execbr);
context->pushExecuteCall(JOTYCZCWMBAAOL_execbr);

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
/*JMP*/	goto label_EYFAXEGSEIJIKC_firststep;
label_EYFAXEGSEIJIKC: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_2;
label_EYFAXEGSEIJIKC_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor MDUCLAAIOISSIS;
/*SET*/	MDUCLAAIOISSIS = r_1;
/*INC*/	if (!INC(MDUCLAAIOISSIS, arg_to)) goto label_EYFAXEGSEIJIKC;
	if (MDUCLAAIOISSIS.container->type != text || *(MDUCLAAIOISSIS.container->value.text + MDUCLAAIOISSIS.index) != '1') goto label_EYFAXEGSEIJIKC;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = MDUCLAAIOISSIS;
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
/*JMP*/	goto label_ESZSIPPQMOTJHK_firststep;
label_ESZSIPPQMOTJHK: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_3;
label_ESZSIPPQMOTJHK_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor UDNVQZBKATNEFU;
/*SET*/	UDNVQZBKATNEFU = r_1;
/*INC*/	if (!INC(UDNVQZBKATNEFU, arg_to)) goto label_ESZSIPPQMOTJHK;
	if (UDNVQZBKATNEFU.container->type != text || *(UDNVQZBKATNEFU.container->value.text + UDNVQZBKATNEFU.index) != '2') goto label_ESZSIPPQMOTJHK;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = UDNVQZBKATNEFU;
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
DataChain* WPTFVOVUJIUWBM = new DataChain(); 
DataContainer* WPTFVOVUJIUWBM_execbr = newRefExecBrackets(Prout, WPTFVOVUJIUWBM, "Prout");
result->append(WPTFVOVUJIUWBM_execbr);
WPTFVOVUJIUWBM->append(newRefText("Length error symbols!!! : ")); 
context->pushExecuteCall(WPTFVOVUJIUWBM_execbr);
DataChain* IBRUCTTMRVZNJR = new DataChain(); 
DataContainer* IBRUCTTMRVZNJR_execbr = newRefExecBrackets(Print, IBRUCTTMRVZNJR, "Print");
result->append(IBRUCTTMRVZNJR_execbr);
IBRUCTTMRVZNJR->append_copy(l_1, r_1); 
context->pushExecuteCall(IBRUCTTMRVZNJR_execbr);

return result; 
}
sentence_after_5: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* DivS(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor CHJWZWMOZECRZN;
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	CHJWZWMOZECRZN = arg_from;
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
DataChain* OCQPKTLMWXWTNU = new DataChain(); 
DataContainer* OCQPKTLMWXWTNU_execbr = newRefExecBrackets(IfDiv, OCQPKTLMWXWTNU, "IfDiv");
result->append(OCQPKTLMWXWTNU_execbr);
DataChain* AMQELRWBGBIJIL = new DataChain(); 
DataContainer* AMQELRWBGBIJIL_execbr = newRefExecBrackets(Compare, AMQELRWBGBIJIL, "Compare");
OCQPKTLMWXWTNU->append(AMQELRWBGBIJIL_execbr);
AMQELRWBGBIJIL->append_copy(l_1, r_1); 
AMQELRWBGBIJIL->append_copy(l_2, r_2); 
context->pushExecuteCall(AMQELRWBGBIJIL_execbr);
OCQPKTLMWXWTNU->append_copy(l_1, r_1); 
OCQPKTLMWXWTNU->append_copy(l_2, r_2); 
context->pushExecuteCall(OCQPKTLMWXWTNU_execbr);

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* IfDiv(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor NHIIULLTOVBEFL;
/*SET*/	NHIIULLTOVBEFL = arg_from;
/*INC*/	if (!INC(NHIIULLTOVBEFL, arg_to)) goto sentence_after_1;
	if (NHIIULLTOVBEFL.container->type != text || *(NHIIULLTOVBEFL.container->value.text + NHIIULLTOVBEFL.index) != '+') goto sentence_after_1;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor WLPBHYFFHBAVHF;
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = NHIIULLTOVBEFL;
/*SET*/	WLPBHYFFHBAVHF = NHIIULLTOVBEFL;
/*INC*/	if (!INC(WLPBHYFFHBAVHF, arg_to)) goto sentence_after_1;
	if (! isSymbolType(WLPBHYFFHBAVHF.container->type)) goto sentence_after_1;
/*SET*/	r_1 = WLPBHYFFHBAVHF;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor UAHLINDJDFPEKX;
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = r_1;
/*SET*/	UAHLINDJDFPEKX = r_1;
/*INC*/	if (!INC(UAHLINDJDFPEKX, arg_to)) goto sentence_after_1;
	if (! isSymbolType(UAHLINDJDFPEKX.container->type)) goto sentence_after_1;
/*SET*/	r_2 = UAHLINDJDFPEKX;
//// [ empty ] 
/*ISEMPTY*/	if (r_2!=0 && arg_to != r_2) goto sentence_after_1;

// подготовка подстановки 
result->append(newRefText("1=")); 
DataChain* VWXKYVULCYJEFL = new DataChain(); 
DataContainer* VWXKYVULCYJEFL_execbr = newRefExecBrackets(Div, VWXKYVULCYJEFL, "Div");
result->append(VWXKYVULCYJEFL_execbr);
VWXKYVULCYJEFL->append_copy(l_1, r_1); 
VWXKYVULCYJEFL->append_copy(l_2, r_2); 
context->pushExecuteCall(VWXKYVULCYJEFL_execbr);

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor LOQZHLTMGTUJDC;
/*DEF*/	DataCursor l_zn;
/*DEF*/	DataCursor r_zn;
/*SET*/	l_zn = arg_from;
/*SET*/	LOQZHLTMGTUJDC = arg_from;
/*INC*/	if (!INC(LOQZHLTMGTUJDC, arg_to)) goto sentence_after_2;
	if (! isSymbolType(LOQZHLTMGTUJDC.container->type)) goto sentence_after_2;
/*SET*/	r_zn = LOQZHLTMGTUJDC;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor UUGNROTLOTCPBN;
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = r_zn;
/*SET*/	UUGNROTLOTCPBN = r_zn;
/*INC*/	if (!INC(UUGNROTLOTCPBN, arg_to)) goto sentence_after_2;
	if (! isSymbolType(UUGNROTLOTCPBN.container->type)) goto sentence_after_2;
/*SET*/	r_1 = UUGNROTLOTCPBN;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor YFHEJEGCMFPTQM;
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = r_1;
/*SET*/	YFHEJEGCMFPTQM = r_1;
/*INC*/	if (!INC(YFHEJEGCMFPTQM, arg_to)) goto sentence_after_2;
	if (! isSymbolType(YFHEJEGCMFPTQM.container->type)) goto sentence_after_2;
/*SET*/	r_2 = YFHEJEGCMFPTQM;
//// [ empty ] 
/*ISEMPTY*/	if (r_2!=0 && arg_to != r_2) goto sentence_after_2;

// подготовка подстановки 
result->append(newRefText("1=")); 
DataChain* VEGHMFBMVKLSQF = new DataChain(); 
DataContainer* VEGHMFBMVKLSQF_execbr = newRefExecBrackets(Div, VEGHMFBMVKLSQF, "Div");
result->append(VEGHMFBMVKLSQF_execbr);
VEGHMFBMVKLSQF->append_copy(l_2, r_2); 
VEGHMFBMVKLSQF->append_copy(l_1, r_1); 
context->pushExecuteCall(VEGHMFBMVKLSQF_execbr);

return result; 
}
sentence_after_2: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* NextPl(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor UBVXCTEPVMLJOH;
/*SET*/	UBVXCTEPVMLJOH = arg_from;
/*INC*/	if (!INC(UBVXCTEPVMLJOH, arg_to)) goto sentence_after_1;
	if (UBVXCTEPVMLJOH.container->type != text || *(UBVXCTEPVMLJOH.container->value.text + UBVXCTEPVMLJOH.index) != '1') goto sentence_after_1;
//// [ empty ] 
/*ISEMPTY*/	if (UBVXCTEPVMLJOH!=0 && arg_to != UBVXCTEPVMLJOH) goto sentence_after_1;

// подготовка подстановки 
result->append(newRefText("2")); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ `a` <any> ] 
/*DEF*/	DataCursor KQDAUPTYVJAFZZ;
/*SET*/	KQDAUPTYVJAFZZ = arg_from;
/*INC*/	if (!INC(KQDAUPTYVJAFZZ, arg_to)) goto sentence_after_2;
	if (KQDAUPTYVJAFZZ.container->type != text || *(KQDAUPTYVJAFZZ.container->value.text + KQDAUPTYVJAFZZ.index) != '2') goto sentence_after_2;
//// [ empty ] 
/*ISEMPTY*/	if (KQDAUPTYVJAFZZ!=0 && arg_to != KQDAUPTYVJAFZZ) goto sentence_after_2;

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
DataChain* IGJMXQRBAZLPDE = new DataChain(); 
DataContainer* IGJMXQRBAZLPDE_execbr = newRefExecBrackets(Print, IGJMXQRBAZLPDE, "Print");
result->append(IGJMXQRBAZLPDE_execbr);
IGJMXQRBAZLPDE->append(newRefText("NextPl uncn.: ")); 
IGJMXQRBAZLPDE->append_copy(l_e, r_e); 
context->pushExecuteCall(IGJMXQRBAZLPDE_execbr);

return result; 
}
sentence_after_3: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Optima21(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
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
DataChain* VPEZPBWSHVPCKL = new DataChain(); 
DataContainer* VPEZPBWSHVPCKL_execbr = newRefExecBrackets(Optima211, VPEZPBWSHVPCKL, "Optima211");
result->append(VPEZPBWSHVPCKL_execbr);
VPEZPBWSHVPCKL->append_copy(l_e, r_e); 
context->pushExecuteCall(VPEZPBWSHVPCKL_execbr);

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Optima211(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	r_1 = arg_from;
/*JMP*/	goto label_DQGIVLQPIRQVWQ_firststep;
label_DQGIVLQPIRQVWQ: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_1;
label_DQGIVLQPIRQVWQ_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor QUYXPIXQIREUQA;
/*SET*/	QUYXPIXQIREUQA = r_1;
/*INC*/	if (!INC(QUYXPIXQIREUQA, arg_to)) goto label_DQGIVLQPIRQVWQ;
	if (QUYXPIXQIREUQA.container->type != text || *(QUYXPIXQIREUQA.container->value.text + QUYXPIXQIREUQA.index) != '1') goto label_DQGIVLQPIRQVWQ;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = QUYXPIXQIREUQA;
/*SET*/	r_2 = QUYXPIXQIREUQA;
/*JMP*/	goto label_MFFSVVNTGUXESI_firststep;
label_MFFSVVNTGUXESI: 
/*INC*/	if (!INC(r_2, arg_to)) goto label_DQGIVLQPIRQVWQ;
label_MFFSVVNTGUXESI_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor DRNWWTQKDOZFPK;
/*SET*/	DRNWWTQKDOZFPK = r_2;
/*INC*/	if (!INC(DRNWWTQKDOZFPK, arg_to)) goto label_MFFSVVNTGUXESI;
	if (DRNWWTQKDOZFPK.container->type != text || *(DRNWWTQKDOZFPK.container->value.text + DRNWWTQKDOZFPK.index) != '1') goto label_MFFSVVNTGUXESI;
//// [ e.1 ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = DRNWWTQKDOZFPK;
/*SET*/	r_3 = arg_to;

// подготовка подстановки 
result->append(newRefText("11")); 
DataChain* FBFHKZBPKAPBSZ = new DataChain(); 
DataContainer* FBFHKZBPKAPBSZ_execbr = newRefExecBrackets(Optima211, FBFHKZBPKAPBSZ, "Optima211");
result->append(FBFHKZBPKAPBSZ_execbr);
FBFHKZBPKAPBSZ->append_copy(l_1, r_1); 
FBFHKZBPKAPBSZ->append_copy(l_3, r_3); 
context->pushExecuteCall(FBFHKZBPKAPBSZ_execbr);
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
/*JMP*/	goto label_YSPDAAOXRAOJOT_firststep;
label_YSPDAAOXRAOJOT: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_2;
label_YSPDAAOXRAOJOT_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor JUFSTURTJHUDPE;
/*SET*/	JUFSTURTJHUDPE = r_1;
/*INC*/	if (!INC(JUFSTURTJHUDPE, arg_to)) goto label_YSPDAAOXRAOJOT;
	if (JUFSTURTJHUDPE.container->type != text || *(JUFSTURTJHUDPE.container->value.text + JUFSTURTJHUDPE.index) != '1') goto label_YSPDAAOXRAOJOT;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = JUFSTURTJHUDPE;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("1")); 
DataChain* RVFNKKMSDBUHVH = new DataChain(); 
DataContainer* RVFNKKMSDBUHVH_execbr = newRefExecBrackets(Optima211, RVFNKKMSDBUHVH, "Optima211");
result->append(RVFNKKMSDBUHVH_execbr);
RVFNKKMSDBUHVH->append_copy(l_1, r_1); 
RVFNKKMSDBUHVH->append_copy(l_2, r_2); 
context->pushExecuteCall(RVFNKKMSDBUHVH_execbr);

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

DataChain* Strategy__(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
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
DataChain* FQTDVTNLEWFQUU = new DataChain(); 
DataContainer* FQTDVTNLEWFQUU_execbr = newRefExecBrackets(Prout, FQTDVTNLEWFQUU, "Prout");
result->append(FQTDVTNLEWFQUU_execbr);
FQTDVTNLEWFQUU->append(newRefWord("Strategy:")); 
FQTDVTNLEWFQUU->append_copy(l_e, r_e); 
context->pushExecuteCall(FQTDVTNLEWFQUU_execbr);
DataChain* HTAINKEBBVZHTQ = new DataChain(); 
DataContainer* HTAINKEBBVZHTQ_execbr = newRefExecBrackets(Strategy__, HTAINKEBBVZHTQ, "Strategy__");
result->append(HTAINKEBBVZHTQ_execbr);
HTAINKEBBVZHTQ->append_copy(l_e, r_e); 
context->pushExecuteCall(HTAINKEBBVZHTQ_execbr);

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Strategy(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
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
/*JMP*/	goto label_BKDBMVHBSNJBTV_firststep;
label_BKDBMVHBSNJBTV: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_2;
label_BKDBMVHBSNJBTV_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor JTQNBCHIWFUQLZ;
/*SET*/	JTQNBCHIWFUQLZ = r_1;
/*INC*/	if (!INC(JTQNBCHIWFUQLZ, arg_to)) goto label_BKDBMVHBSNJBTV;
	if (JTQNBCHIWFUQLZ.container->type != text || *(JTQNBCHIWFUQLZ.container->value.text + JTQNBCHIWFUQLZ.index) != '1') goto label_BKDBMVHBSNJBTV;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = JTQNBCHIWFUQLZ;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("147")); 
DataChain* YHZPXCDJWIKFAT = new DataChain(); 
DataContainer* YHZPXCDJWIKFAT_execbr = newRefExecBrackets(Strategy, YHZPXCDJWIKFAT, "Strategy");
result->append(YHZPXCDJWIKFAT_execbr);
YHZPXCDJWIKFAT->append_copy(l_1, r_1); 
YHZPXCDJWIKFAT->append_copy(l_2, r_2); 
context->pushExecuteCall(YHZPXCDJWIKFAT_execbr);

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
/*JMP*/	goto label_CANCHXSSJLUHLY_firststep;
label_CANCHXSSJLUHLY: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_3;
label_CANCHXSSJLUHLY_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor OEBCGNSQFZXXWG;
/*SET*/	OEBCGNSQFZXXWG = r_1;
/*INC*/	if (!INC(OEBCGNSQFZXXWG, arg_to)) goto label_CANCHXSSJLUHLY;
	if (OEBCGNSQFZXXWG.container->type != text || *(OEBCGNSQFZXXWG.container->value.text + OEBCGNSQFZXXWG.index) != '2') goto label_CANCHXSSJLUHLY;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = OEBCGNSQFZXXWG;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("15")); 
DataChain* RPKEGEQPVLHXEE = new DataChain(); 
DataContainer* RPKEGEQPVLHXEE_execbr = newRefExecBrackets(Strategy, RPKEGEQPVLHXEE, "Strategy");
result->append(RPKEGEQPVLHXEE_execbr);
RPKEGEQPVLHXEE->append_copy(l_1, r_1); 
RPKEGEQPVLHXEE->append_copy(l_2, r_2); 
context->pushExecuteCall(RPKEGEQPVLHXEE_execbr);

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
/*JMP*/	goto label_OCMERJMZIUDTSQ_firststep;
label_OCMERJMZIUDTSQ: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_4;
label_OCMERJMZIUDTSQ_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor QOZVEJNRTIBVNJ;
/*SET*/	QOZVEJNRTIBVNJ = r_1;
/*INC*/	if (!INC(QOZVEJNRTIBVNJ, arg_to)) goto label_OCMERJMZIUDTSQ;
	if (QOZVEJNRTIBVNJ.container->type != text || *(QOZVEJNRTIBVNJ.container->value.text + QOZVEJNRTIBVNJ.index) != '3') goto label_OCMERJMZIUDTSQ;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = QOZVEJNRTIBVNJ;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("168")); 
DataChain* WQKNNRMQMJCCPA = new DataChain(); 
DataContainer* WQKNNRMQMJCCPA_execbr = newRefExecBrackets(Strategy, WQKNNRMQMJCCPA, "Strategy");
result->append(WQKNNRMQMJCCPA_execbr);
WQKNNRMQMJCCPA->append_copy(l_1, r_1); 
WQKNNRMQMJCCPA->append_copy(l_2, r_2); 
context->pushExecuteCall(WQKNNRMQMJCCPA_execbr);

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
/*JMP*/	goto label_OWAZFEURGPBFRY_firststep;
label_OWAZFEURGPBFRY: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_5;
label_OWAZFEURGPBFRY_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor EDQJRLTMYMHYSO;
/*SET*/	EDQJRLTMYMHYSO = r_1;
/*INC*/	if (!INC(EDQJRLTMYMHYSO, arg_to)) goto label_OWAZFEURGPBFRY;
	if (EDQJRLTMYMHYSO.container->type != text || *(EDQJRLTMYMHYSO.container->value.text + EDQJRLTMYMHYSO.index) != '4') goto label_OWAZFEURGPBFRY;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = EDQJRLTMYMHYSO;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("24")); 
DataChain* AZUVJOXYIPMSGU = new DataChain(); 
DataContainer* AZUVJOXYIPMSGU_execbr = newRefExecBrackets(Strategy, AZUVJOXYIPMSGU, "Strategy");
result->append(AZUVJOXYIPMSGU_execbr);
AZUVJOXYIPMSGU->append_copy(l_1, r_1); 
AZUVJOXYIPMSGU->append_copy(l_2, r_2); 
context->pushExecuteCall(AZUVJOXYIPMSGU_execbr);

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
/*JMP*/	goto label_FJIWLCFYWXTEYY_firststep;
label_FJIWLCFYWXTEYY: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_6;
label_FJIWLCFYWXTEYY_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor QDHXWJHIUDGHYX;
/*SET*/	QDHXWJHIUDGHYX = r_1;
/*INC*/	if (!INC(QDHXWJHIUDGHYX, arg_to)) goto label_FJIWLCFYWXTEYY;
	if (QDHXWJHIUDGHYX.container->type != text || *(QDHXWJHIUDGHYX.container->value.text + QDHXWJHIUDGHYX.index) != '5') goto label_FJIWLCFYWXTEYY;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = QDHXWJHIUDGHYX;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("2578")); 
DataChain* XFVCFBBJJYFSVK = new DataChain(); 
DataContainer* XFVCFBBJJYFSVK_execbr = newRefExecBrackets(Strategy, XFVCFBBJJYFSVK, "Strategy");
result->append(XFVCFBBJJYFSVK_execbr);
XFVCFBBJJYFSVK->append_copy(l_1, r_1); 
XFVCFBBJJYFSVK->append_copy(l_2, r_2); 
context->pushExecuteCall(XFVCFBBJJYFSVK_execbr);

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
/*JMP*/	goto label_VSAPDSHAKGDVHC_firststep;
label_VSAPDSHAKGDVHC: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_7;
label_VSAPDSHAKGDVHC_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor FMCEZTGJCMHXLH;
/*SET*/	FMCEZTGJCMHXLH = r_1;
/*INC*/	if (!INC(FMCEZTGJCMHXLH, arg_to)) goto label_VSAPDSHAKGDVHC;
	if (FMCEZTGJCMHXLH.container->type != text || *(FMCEZTGJCMHXLH.container->value.text + FMCEZTGJCMHXLH.index) != '6') goto label_VSAPDSHAKGDVHC;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = FMCEZTGJCMHXLH;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("26")); 
DataChain* AGRNFFMNPINWLE = new DataChain(); 
DataContainer* AGRNFFMNPINWLE_execbr = newRefExecBrackets(Strategy, AGRNFFMNPINWLE, "Strategy");
result->append(AGRNFFMNPINWLE_execbr);
AGRNFFMNPINWLE->append_copy(l_1, r_1); 
AGRNFFMNPINWLE->append_copy(l_2, r_2); 
context->pushExecuteCall(AGRNFFMNPINWLE_execbr);

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
/*JMP*/	goto label_XRQXISBFNHJZQV_firststep;
label_XRQXISBFNHJZQV: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_8;
label_XRQXISBFNHJZQV_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor OXKUKYLZCRUPMI;
/*SET*/	OXKUKYLZCRUPMI = r_1;
/*INC*/	if (!INC(OXKUKYLZCRUPMI, arg_to)) goto label_XRQXISBFNHJZQV;
	if (OXKUKYLZCRUPMI.container->type != text || *(OXKUKYLZCRUPMI.container->value.text + OXKUKYLZCRUPMI.index) != '7') goto label_XRQXISBFNHJZQV;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = OXKUKYLZCRUPMI;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("348")); 
DataChain* QNBDIFZLUJQVNF = new DataChain(); 
DataContainer* QNBDIFZLUJQVNF_execbr = newRefExecBrackets(Strategy, QNBDIFZLUJQVNF, "Strategy");
result->append(QNBDIFZLUJQVNF_execbr);
QNBDIFZLUJQVNF->append_copy(l_1, r_1); 
QNBDIFZLUJQVNF->append_copy(l_2, r_2); 
context->pushExecuteCall(QNBDIFZLUJQVNF_execbr);

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
/*JMP*/	goto label_JXXVKCZFKZZJQN_firststep;
label_JXXVKCZFKZZJQN: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_9;
label_JXXVKCZFKZZJQN_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor AQPOHYGJSJTAKZ;
/*SET*/	AQPOHYGJSJTAKZ = r_1;
/*INC*/	if (!INC(AQPOHYGJSJTAKZ, arg_to)) goto label_JXXVKCZFKZZJQN;
	if (AQPOHYGJSJTAKZ.container->type != text || *(AQPOHYGJSJTAKZ.container->value.text + AQPOHYGJSJTAKZ.index) != '8') goto label_JXXVKCZFKZZJQN;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = AQPOHYGJSJTAKZ;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("35")); 
DataChain* YUGTEDOGFURKXI = new DataChain(); 
DataContainer* YUGTEDOGFURKXI_execbr = newRefExecBrackets(Strategy, YUGTEDOGFURKXI, "Strategy");
result->append(YUGTEDOGFURKXI_execbr);
YUGTEDOGFURKXI->append_copy(l_1, r_1); 
YUGTEDOGFURKXI->append_copy(l_2, r_2); 
context->pushExecuteCall(YUGTEDOGFURKXI_execbr);

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
/*JMP*/	goto label_YQUFOTIAJMWHYI_firststep;
label_YQUFOTIAJMWHYI: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_10;
label_YQUFOTIAJMWHYI_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor LTHMOEVLWLRXPW;
/*SET*/	LTHMOEVLWLRXPW = r_1;
/*INC*/	if (!INC(LTHMOEVLWLRXPW, arg_to)) goto label_YQUFOTIAJMWHYI;
	if (LTHMOEVLWLRXPW.container->type != text || *(LTHMOEVLWLRXPW.container->value.text + LTHMOEVLWLRXPW.index) != '9') goto label_YQUFOTIAJMWHYI;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = LTHMOEVLWLRXPW;
/*SET*/	r_2 = arg_to;

// подготовка подстановки 
result->append(newRefText("367")); 
DataChain* CFZNMAOMAFSYVY = new DataChain(); 
DataContainer* CFZNMAOMAFSYVY_execbr = newRefExecBrackets(Strategy, CFZNMAOMAFSYVY, "Strategy");
result->append(CFZNMAOMAFSYVY_execbr);
CFZNMAOMAFSYVY->append_copy(l_1, r_1); 
CFZNMAOMAFSYVY->append_copy(l_2, r_2); 
context->pushExecuteCall(CFZNMAOMAFSYVY_execbr);

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

DataChain* Ifwin(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor RQPIZTEUOXGTHF;
/*DEF*/	DataCursor XSMXJRWPSURSGW;
/*DEF*/	DataCursor THHILGDHZFZAXA;
/*SET*/	RQPIZTEUOXGTHF = arg_from;
/*INC*/	if (!INC(RQPIZTEUOXGTHF, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (RQPIZTEUOXGTHF.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	XSMXJRWPSURSGW = RQPIZTEUOXGTHF.container->value.bracket_data.chain->at_before_first();
	THHILGDHZFZAXA   = RQPIZTEUOXGTHF.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = XSMXJRWPSURSGW;
/*SET*/	r_1 = THHILGDHZFZAXA;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor DTKLHYHQZFDIMS;
/*DEF*/	DataCursor RUEECXKQKRUDLM;
/*DEF*/	DataCursor ZGDTNHMIVNNKCL;
/*SET*/	DTKLHYHQZFDIMS = RQPIZTEUOXGTHF;
/*INC*/	if (!INC(DTKLHYHQZFDIMS, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (DTKLHYHQZFDIMS.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	RUEECXKQKRUDLM = DTKLHYHQZFDIMS.container->value.bracket_data.chain->at_before_first();
	ZGDTNHMIVNNKCL   = DTKLHYHQZFDIMS.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = RUEECXKQKRUDLM;
/*SET*/	r_2 = ZGDTNHMIVNNKCL;
//// [ empty ] 
/*ISEMPTY*/	if (DTKLHYHQZFDIMS!=0 && arg_to != DTKLHYHQZFDIMS) goto sentence_after_1;

// подготовка подстановки 
DataChain* GARYGYDQDHLTRS = new DataChain(); 
DataContainer* GARYGYDQDHLTRS_execbr = newRefExecBrackets(Ifwin1, GARYGYDQDHLTRS, "Ifwin1");
result->append(GARYGYDQDHLTRS_execbr);
DataChain* THIDZYQAZFNOVK = new DataChain(); 
GARYGYDQDHLTRS->append(newRefStructBrackets(THIDZYQAZFNOVK)); 
DataChain* TQCOTCHCOLINEI = new DataChain(); 
DataContainer* TQCOTCHCOLINEI_execbr = newRefExecBrackets(Strategy, TQCOTCHCOLINEI, "Strategy");
THIDZYQAZFNOVK->append(TQCOTCHCOLINEI_execbr);
TQCOTCHCOLINEI->append_copy(l_1, r_1); 
context->pushExecuteCall(TQCOTCHCOLINEI_execbr);
DataChain* YTYMRJSCYOEIVD = new DataChain(); 
GARYGYDQDHLTRS->append(newRefStructBrackets(YTYMRJSCYOEIVD)); 
DataChain* YHPHLJZHEZOHMI = new DataChain(); 
DataContainer* YHPHLJZHEZOHMI_execbr = newRefExecBrackets(Strategy, YHPHLJZHEZOHMI, "Strategy");
YTYMRJSCYOEIVD->append(YHPHLJZHEZOHMI_execbr);
YHPHLJZHEZOHMI->append_copy(l_2, r_2); 
context->pushExecuteCall(YHPHLJZHEZOHMI_execbr);
context->pushExecuteCall(GARYGYDQDHLTRS_execbr);

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Ifwin1(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor URCPBLVWAAJIQU;
/*DEF*/	DataCursor GTAOQMEMJLHGOX;
/*DEF*/	DataCursor PRURTYMKKTDBNO;
/*SET*/	URCPBLVWAAJIQU = arg_from;
/*INC*/	if (!INC(URCPBLVWAAJIQU, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (URCPBLVWAAJIQU.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	GTAOQMEMJLHGOX = URCPBLVWAAJIQU.container->value.bracket_data.chain->at_before_first();
	PRURTYMKKTDBNO   = URCPBLVWAAJIQU.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = GTAOQMEMJLHGOX;
/*SET*/	r_1 = GTAOQMEMJLHGOX;
/*JMP*/	goto label_XWTTGEEQIMLHCZ_firststep;
label_XWTTGEEQIMLHCZ: 
/*INC*/	if (!INC(r_1, PRURTYMKKTDBNO)) goto sentence_after_1;
label_XWTTGEEQIMLHCZ_firststep: 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor TCTYPHMEQDSUYV;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_1;
/*SET*/	TCTYPHMEQDSUYV = r_1;
/*INC*/	if (!INC(TCTYPHMEQDSUYV, PRURTYMKKTDBNO)) goto label_XWTTGEEQIMLHCZ;
	if (! isSymbolType(TCTYPHMEQDSUYV.container->type)) goto label_XWTTGEEQIMLHCZ;
/*SET*/	r_A = TCTYPHMEQDSUYV;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = r_A;
/*SET*/	r_2 = r_A;
/*JMP*/	goto label_KKJOPLMZDCAKPJ_firststep;
label_KKJOPLMZDCAKPJ: 
/*INC*/	if (!INC(r_2, PRURTYMKKTDBNO)) goto label_XWTTGEEQIMLHCZ;
label_KKJOPLMZDCAKPJ_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor VOZIMHXXQHDUIQ;
/*SET*/	VOZIMHXXQHDUIQ = r_2;
 if (!SLIDE(VOZIMHXXQHDUIQ, PRURTYMKKTDBNO, l_A, r_A)) goto label_KKJOPLMZDCAKPJ;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = VOZIMHXXQHDUIQ;
/*SET*/	r_3 = VOZIMHXXQHDUIQ;
/*JMP*/	goto label_EDLNGWGOOOUPNE_firststep;
label_EDLNGWGOOOUPNE: 
/*INC*/	if (!INC(r_3, PRURTYMKKTDBNO)) goto label_KKJOPLMZDCAKPJ;
label_EDLNGWGOOOUPNE_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor DKSDGPMHHDAQBS;
/*SET*/	DKSDGPMHHDAQBS = r_3;
 if (!SLIDE(DKSDGPMHHDAQBS, PRURTYMKKTDBNO, l_A, r_A)) goto label_EDLNGWGOOOUPNE;
//// [ e.1 ] 
/*DEF*/	DataCursor l_4;
/*DEF*/	DataCursor r_4;
/*SET*/	l_4 = DKSDGPMHHDAQBS;
/*SET*/	r_4 = PRURTYMKKTDBNO;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor QRFPDRSYKHBUTS;
/*DEF*/	DataCursor NUWJPPGDEEBJGS;
/*DEF*/	DataCursor DYFOECQQNLEMKI;
/*SET*/	QRFPDRSYKHBUTS = URCPBLVWAAJIQU;
/*INC*/	if (!INC(QRFPDRSYKHBUTS, arg_to)) goto label_EDLNGWGOOOUPNE;
//// ISBRACKET 
	if (QRFPDRSYKHBUTS.container->type != struct_bracket) goto label_EDLNGWGOOOUPNE;
//// JMP_BRACKET 
	NUWJPPGDEEBJGS = QRFPDRSYKHBUTS.container->value.bracket_data.chain->at_before_first();
	DYFOECQQNLEMKI   = QRFPDRSYKHBUTS.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = NUWJPPGDEEBJGS;
/*SET*/	r_e = DYFOECQQNLEMKI;
//// [ empty ] 
/*ISEMPTY*/	if (QRFPDRSYKHBUTS!=0 && arg_to != QRFPDRSYKHBUTS) goto label_EDLNGWGOOOUPNE;

// подготовка подстановки 
result->append(newRefText("1")); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor MIPECEHLBTMBWN;
/*DEF*/	DataCursor KDXYMECLSSHVKM;
/*DEF*/	DataCursor YWJXESHOIHMLGV;
/*SET*/	MIPECEHLBTMBWN = arg_from;
/*INC*/	if (!INC(MIPECEHLBTMBWN, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (MIPECEHLBTMBWN.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	KDXYMECLSSHVKM = MIPECEHLBTMBWN.container->value.bracket_data.chain->at_before_first();
	YWJXESHOIHMLGV   = MIPECEHLBTMBWN.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_e;
/*DEF*/	DataCursor r_e;
/*SET*/	l_e = KDXYMECLSSHVKM;
/*SET*/	r_e = YWJXESHOIHMLGV;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor XILJVWLLFPNJZY;
/*DEF*/	DataCursor WCPAMEVWTYGFPH;
/*DEF*/	DataCursor IFUBTTNWNPHDBY;
/*SET*/	XILJVWLLFPNJZY = MIPECEHLBTMBWN;
/*INC*/	if (!INC(XILJVWLLFPNJZY, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (XILJVWLLFPNJZY.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	WCPAMEVWTYGFPH = XILJVWLLFPNJZY.container->value.bracket_data.chain->at_before_first();
	IFUBTTNWNPHDBY   = XILJVWLLFPNJZY.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = WCPAMEVWTYGFPH;
/*SET*/	r_1 = WCPAMEVWTYGFPH;
/*JMP*/	goto label_TWODCLRJPRSEQW_firststep;
label_TWODCLRJPRSEQW: 
/*INC*/	if (!INC(r_1, IFUBTTNWNPHDBY)) goto sentence_after_2;
label_TWODCLRJPRSEQW_firststep: 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor RDWSVYNCGFRAZZ;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_1;
/*SET*/	RDWSVYNCGFRAZZ = r_1;
/*INC*/	if (!INC(RDWSVYNCGFRAZZ, IFUBTTNWNPHDBY)) goto label_TWODCLRJPRSEQW;
	if (! isSymbolType(RDWSVYNCGFRAZZ.container->type)) goto label_TWODCLRJPRSEQW;
/*SET*/	r_A = RDWSVYNCGFRAZZ;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = r_A;
/*SET*/	r_2 = r_A;
/*JMP*/	goto label_AODGGXWWBTJQUJ_firststep;
label_AODGGXWWBTJQUJ: 
/*INC*/	if (!INC(r_2, IFUBTTNWNPHDBY)) goto label_TWODCLRJPRSEQW;
label_AODGGXWWBTJQUJ_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor RMCDPOMJRYLEDH;
/*SET*/	RMCDPOMJRYLEDH = r_2;
 if (!SLIDE(RMCDPOMJRYLEDH, IFUBTTNWNPHDBY, l_A, r_A)) goto label_AODGGXWWBTJQUJ;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = RMCDPOMJRYLEDH;
/*SET*/	r_3 = RMCDPOMJRYLEDH;
/*JMP*/	goto label_UFHWKHZKTNKYTG_firststep;
label_UFHWKHZKTNKYTG: 
/*INC*/	if (!INC(r_3, IFUBTTNWNPHDBY)) goto label_AODGGXWWBTJQUJ;
label_UFHWKHZKTNKYTG_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor JPMMGVXJCNJGZU;
/*SET*/	JPMMGVXJCNJGZU = r_3;
 if (!SLIDE(JPMMGVXJCNJGZU, IFUBTTNWNPHDBY, l_A, r_A)) goto label_UFHWKHZKTNKYTG;
//// [ e.1 ] 
/*DEF*/	DataCursor l_4;
/*DEF*/	DataCursor r_4;
/*SET*/	l_4 = JPMMGVXJCNJGZU;
/*SET*/	r_4 = IFUBTTNWNPHDBY;
//// [ empty ] 
/*ISEMPTY*/	if (XILJVWLLFPNJZY!=0 && arg_to != XILJVWLLFPNJZY) goto label_UFHWKHZKTNKYTG;

// подготовка подстановки 
result->append(newRefText("2")); 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor HWQQSLDZCSFOJS;
/*DEF*/	DataCursor WRQCNBQYXAAGIB;
/*DEF*/	DataCursor PVTXDONPEASHNR;
/*SET*/	HWQQSLDZCSFOJS = arg_from;
/*INC*/	if (!INC(HWQQSLDZCSFOJS, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (HWQQSLDZCSFOJS.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	WRQCNBQYXAAGIB = HWQQSLDZCSFOJS.container->value.bracket_data.chain->at_before_first();
	PVTXDONPEASHNR   = HWQQSLDZCSFOJS.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = WRQCNBQYXAAGIB;
/*SET*/	r_1 = PVTXDONPEASHNR;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor OHUVOGLDXHSPRN;
/*DEF*/	DataCursor GSOQDJFQTEXYRW;
/*DEF*/	DataCursor IZZOEOWAQEZDLM;
/*SET*/	OHUVOGLDXHSPRN = HWQQSLDZCSFOJS;
/*INC*/	if (!INC(OHUVOGLDXHSPRN, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (OHUVOGLDXHSPRN.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	GSOQDJFQTEXYRW = OHUVOGLDXHSPRN.container->value.bracket_data.chain->at_before_first();
	IZZOEOWAQEZDLM   = OHUVOGLDXHSPRN.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = GSOQDJFQTEXYRW;
/*SET*/	r_2 = IZZOEOWAQEZDLM;
//// [ empty ] 
/*ISEMPTY*/	if (OHUVOGLDXHSPRN!=0 && arg_to != OHUVOGLDXHSPRN) goto sentence_after_3;

// подготовка подстановки 
result->append(newRefText("0")); 

return result; 
}
sentence_after_3: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Analiz__(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
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
DataChain* WAFCOZVQCIEWGK = new DataChain(); 
DataContainer* WAFCOZVQCIEWGK_execbr = newRefExecBrackets(Prout, WAFCOZVQCIEWGK, "Prout");
result->append(WAFCOZVQCIEWGK_execbr);
WAFCOZVQCIEWGK->append(newRefWord("Analiz:")); 
WAFCOZVQCIEWGK->append_copy(l_e, r_e); 
context->pushExecuteCall(WAFCOZVQCIEWGK_execbr);
DataChain* EKFGRCYVZSAHPS = new DataChain(); 
DataContainer* EKFGRCYVZSAHPS_execbr = newRefExecBrackets(Analiz__, EKFGRCYVZSAHPS, "Analiz__");
result->append(EKFGRCYVZSAHPS_execbr);
EKFGRCYVZSAHPS->append_copy(l_e, r_e); 
context->pushExecuteCall(EKFGRCYVZSAHPS_execbr);

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Analiz(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = arg_from;
/*SET*/	r_1 = arg_from;
/*JMP*/	goto label_ZOBRIXWXKPICLQ_firststep;
label_ZOBRIXWXKPICLQ: 
/*INC*/	if (!INC(r_1, arg_to)) goto sentence_after_1;
label_ZOBRIXWXKPICLQ_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor LJTKVNBIMPDKYE;
/*DEF*/	DataCursor BCWLFKFFRLZZMK;
/*DEF*/	DataCursor VMHNLCIVWHWZTZ;
/*SET*/	LJTKVNBIMPDKYE = r_1;
/*INC*/	if (!INC(LJTKVNBIMPDKYE, arg_to)) goto label_ZOBRIXWXKPICLQ;
//// ISBRACKET 
	if (LJTKVNBIMPDKYE.container->type != struct_bracket) goto label_ZOBRIXWXKPICLQ;
//// JMP_BRACKET 
	BCWLFKFFRLZZMK = LJTKVNBIMPDKYE.container->value.bracket_data.chain->at_before_first();
	VMHNLCIVWHWZTZ   = LJTKVNBIMPDKYE.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = BCWLFKFFRLZZMK;
/*SET*/	r_3 = BCWLFKFFRLZZMK;
/*JMP*/	goto label_RBXJCRTUVTXFKI_firststep;
label_RBXJCRTUVTXFKI: 
/*INC*/	if (!INC(r_3, VMHNLCIVWHWZTZ)) goto label_ZOBRIXWXKPICLQ;
label_RBXJCRTUVTXFKI_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor DXHOAFYESYVIZV;
/*SET*/	DXHOAFYESYVIZV = r_3;
/*INC*/	if (!INC(DXHOAFYESYVIZV, VMHNLCIVWHWZTZ)) goto label_RBXJCRTUVTXFKI;
	if (DXHOAFYESYVIZV.container->type != text || *(DXHOAFYESYVIZV.container->value.text + DXHOAFYESYVIZV.index) != '>') goto label_RBXJCRTUVTXFKI;
//// [ empty ] 
/*ISEMPTY*/	if (DXHOAFYESYVIZV!=0 && VMHNLCIVWHWZTZ != DXHOAFYESYVIZV) goto label_RBXJCRTUVTXFKI;
//// [ empty ] 
/*ISEMPTY*/	if (LJTKVNBIMPDKYE!=0 && arg_to != LJTKVNBIMPDKYE) goto label_RBXJCRTUVTXFKI;

// подготовка подстановки 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor RNERZOOWRVWPMI;
/*DEF*/	DataCursor BHHYFFUVKOUKDW;
/*DEF*/	DataCursor JCVXQGLSCHJAGQ;
/*SET*/	RNERZOOWRVWPMI = arg_from;
/*INC*/	if (!INC(RNERZOOWRVWPMI, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (RNERZOOWRVWPMI.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	BHHYFFUVKOUKDW = RNERZOOWRVWPMI.container->value.bracket_data.chain->at_before_first();
	JCVXQGLSCHJAGQ   = RNERZOOWRVWPMI.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor UEHPNHKYCPMJTG;
/*SET*/	UEHPNHKYCPMJTG = BHHYFFUVKOUKDW;
/*INC*/	if (!INC(UEHPNHKYCPMJTG, JCVXQGLSCHJAGQ)) goto sentence_after_2;
	if (UEHPNHKYCPMJTG.container->type != text || *(UEHPNHKYCPMJTG.container->value.text + UEHPNHKYCPMJTG.index) != '1') goto sentence_after_2;
//// [ empty ] 
/*ISEMPTY*/	if (UEHPNHKYCPMJTG!=0 && JCVXQGLSCHJAGQ != UEHPNHKYCPMJTG) goto sentence_after_2;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor XLBNVMDWSYXHGS;
/*DEF*/	DataCursor CZHYJGDFGNWFPD;
/*DEF*/	DataCursor TLKHPEKHJNCYLC;
/*SET*/	XLBNVMDWSYXHGS = RNERZOOWRVWPMI;
/*INC*/	if (!INC(XLBNVMDWSYXHGS, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (XLBNVMDWSYXHGS.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	CZHYJGDFGNWFPD = XLBNVMDWSYXHGS.container->value.bracket_data.chain->at_before_first();
	TLKHPEKHJNCYLC   = XLBNVMDWSYXHGS.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = CZHYJGDFGNWFPD;
/*SET*/	r_1 = TLKHPEKHJNCYLC;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor QMSSYGHWDVAEQJ;
/*DEF*/	DataCursor KZMHIYDLXDJOHN;
/*DEF*/	DataCursor SCGHBTUSWZUMSQ;
/*SET*/	QMSSYGHWDVAEQJ = XLBNVMDWSYXHGS;
/*INC*/	if (!INC(QMSSYGHWDVAEQJ, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (QMSSYGHWDVAEQJ.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	KZMHIYDLXDJOHN = QMSSYGHWDVAEQJ.container->value.bracket_data.chain->at_before_first();
	SCGHBTUSWZUMSQ   = QMSSYGHWDVAEQJ.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = KZMHIYDLXDJOHN;
/*SET*/	r_2 = SCGHBTUSWZUMSQ;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor OYKIIDFWFXYAAA;
/*DEF*/	DataCursor YMOIVFHJLRWYAX;
/*DEF*/	DataCursor AWGEURBRNBERAZ;
/*SET*/	OYKIIDFWFXYAAA = QMSSYGHWDVAEQJ;
/*INC*/	if (!INC(OYKIIDFWFXYAAA, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (OYKIIDFWFXYAAA.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	YMOIVFHJLRWYAX = OYKIIDFWFXYAAA.container->value.bracket_data.chain->at_before_first();
	AWGEURBRNBERAZ   = OYKIIDFWFXYAAA.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = YMOIVFHJLRWYAX;
/*SET*/	r_3 = YMOIVFHJLRWYAX;
/*JMP*/	goto label_SXTKAQUEHJFCEW_firststep;
label_SXTKAQUEHJFCEW: 
/*INC*/	if (!INC(r_3, AWGEURBRNBERAZ)) goto sentence_after_2;
label_SXTKAQUEHJFCEW_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor CTBFJTPQDLJHEH;
/*SET*/	CTBFJTPQDLJHEH = r_3;
/*INC*/	if (!INC(CTBFJTPQDLJHEH, AWGEURBRNBERAZ)) goto label_SXTKAQUEHJFCEW;
	if (CTBFJTPQDLJHEH.container->type != text || *(CTBFJTPQDLJHEH.container->value.text + CTBFJTPQDLJHEH.index) != '>') goto label_SXTKAQUEHJFCEW;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor JOBMARGUQWSOKL;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = CTBFJTPQDLJHEH;
/*SET*/	JOBMARGUQWSOKL = CTBFJTPQDLJHEH;
/*INC*/	if (!INC(JOBMARGUQWSOKL, AWGEURBRNBERAZ)) goto label_SXTKAQUEHJFCEW;
	if (! isSymbolType(JOBMARGUQWSOKL.container->type)) goto label_SXTKAQUEHJFCEW;
/*SET*/	r_A = JOBMARGUQWSOKL;
//// [ e.1 ] 
/*DEF*/	DataCursor l_4;
/*DEF*/	DataCursor r_4;
/*SET*/	l_4 = r_A;
/*SET*/	r_4 = AWGEURBRNBERAZ;
//// [ empty ] 
/*ISEMPTY*/	if (OYKIIDFWFXYAAA!=0 && arg_to != OYKIIDFWFXYAAA) goto label_SXTKAQUEHJFCEW;

// подготовка подстановки 
DataChain* QOVERSCJZBKMZD = new DataChain(); 
DataContainer* QOVERSCJZBKMZD_execbr = newRefExecBrackets(PolnAnaliz, QOVERSCJZBKMZD, "PolnAnaliz");
result->append(QOVERSCJZBKMZD_execbr);
DataChain* NDOSIYHTYAVOXH = new DataChain(); 
QOVERSCJZBKMZD->append(newRefStructBrackets(NDOSIYHTYAVOXH)); 
NDOSIYHTYAVOXH->append(newRefText("2")); 
DataChain* TAPYEKTUATPRWS = new DataChain(); 
QOVERSCJZBKMZD->append(newRefStructBrackets(TAPYEKTUATPRWS)); 
TAPYEKTUATPRWS->append_copy(l_1, r_1); 
TAPYEKTUATPRWS->append_copy(l_A, r_A); 
DataChain* KXZCZNFDIUEHUW = new DataChain(); 
QOVERSCJZBKMZD->append(newRefStructBrackets(KXZCZNFDIUEHUW)); 
KXZCZNFDIUEHUW->append_copy(l_2, r_2); 
DataChain* YMTXDRNKLSMDUS = new DataChain(); 
QOVERSCJZBKMZD->append(newRefStructBrackets(YMTXDRNKLSMDUS)); 
YMTXDRNKLSMDUS->append_copy(l_3, r_3); 
YMTXDRNKLSMDUS->append_copy(l_4, r_4); 
context->pushExecuteCall(QOVERSCJZBKMZD_execbr);

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor KVUTKFIUBZYBLW;
/*DEF*/	DataCursor MPARMJDSPXYWXE;
/*DEF*/	DataCursor RFTZLKORIEBSUP;
/*SET*/	KVUTKFIUBZYBLW = arg_from;
/*INC*/	if (!INC(KVUTKFIUBZYBLW, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (KVUTKFIUBZYBLW.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	MPARMJDSPXYWXE = KVUTKFIUBZYBLW.container->value.bracket_data.chain->at_before_first();
	RFTZLKORIEBSUP   = KVUTKFIUBZYBLW.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor CPXCJWKUVEEREN;
/*SET*/	CPXCJWKUVEEREN = MPARMJDSPXYWXE;
/*INC*/	if (!INC(CPXCJWKUVEEREN, RFTZLKORIEBSUP)) goto sentence_after_3;
	if (CPXCJWKUVEEREN.container->type != text || *(CPXCJWKUVEEREN.container->value.text + CPXCJWKUVEEREN.index) != '2') goto sentence_after_3;
//// [ empty ] 
/*ISEMPTY*/	if (CPXCJWKUVEEREN!=0 && RFTZLKORIEBSUP != CPXCJWKUVEEREN) goto sentence_after_3;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor UIUZTEYCTMUIFE;
/*DEF*/	DataCursor FYGAIAIOIIEDBY;
/*DEF*/	DataCursor WRGRTDXVDKOCSA;
/*SET*/	UIUZTEYCTMUIFE = KVUTKFIUBZYBLW;
/*INC*/	if (!INC(UIUZTEYCTMUIFE, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (UIUZTEYCTMUIFE.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	FYGAIAIOIIEDBY = UIUZTEYCTMUIFE.container->value.bracket_data.chain->at_before_first();
	WRGRTDXVDKOCSA   = UIUZTEYCTMUIFE.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = FYGAIAIOIIEDBY;
/*SET*/	r_1 = WRGRTDXVDKOCSA;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor EHFCILQJOEVAJN;
/*DEF*/	DataCursor JTTKNRSPRTKRLK;
/*DEF*/	DataCursor JAPYMUZRPHZLCE;
/*SET*/	EHFCILQJOEVAJN = UIUZTEYCTMUIFE;
/*INC*/	if (!INC(EHFCILQJOEVAJN, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (EHFCILQJOEVAJN.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	JTTKNRSPRTKRLK = EHFCILQJOEVAJN.container->value.bracket_data.chain->at_before_first();
	JAPYMUZRPHZLCE   = EHFCILQJOEVAJN.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = JTTKNRSPRTKRLK;
/*SET*/	r_2 = JAPYMUZRPHZLCE;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor PAYTFAVEOPSZRN;
/*DEF*/	DataCursor KVNEHRJSTZFLVY;
/*DEF*/	DataCursor AHORKTKMGYCOUI;
/*SET*/	PAYTFAVEOPSZRN = EHFCILQJOEVAJN;
/*INC*/	if (!INC(PAYTFAVEOPSZRN, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (PAYTFAVEOPSZRN.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	KVNEHRJSTZFLVY = PAYTFAVEOPSZRN.container->value.bracket_data.chain->at_before_first();
	AHORKTKMGYCOUI   = PAYTFAVEOPSZRN.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = KVNEHRJSTZFLVY;
/*SET*/	r_3 = KVNEHRJSTZFLVY;
/*JMP*/	goto label_ERTLPBJCSXQLGY_firststep;
label_ERTLPBJCSXQLGY: 
/*INC*/	if (!INC(r_3, AHORKTKMGYCOUI)) goto sentence_after_3;
label_ERTLPBJCSXQLGY_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor GLMVLYQXIXIPVW;
/*SET*/	GLMVLYQXIXIPVW = r_3;
/*INC*/	if (!INC(GLMVLYQXIXIPVW, AHORKTKMGYCOUI)) goto label_ERTLPBJCSXQLGY;
	if (GLMVLYQXIXIPVW.container->type != text || *(GLMVLYQXIXIPVW.container->value.text + GLMVLYQXIXIPVW.index) != '>') goto label_ERTLPBJCSXQLGY;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor OQLNKAEQMARVXU;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = GLMVLYQXIXIPVW;
/*SET*/	OQLNKAEQMARVXU = GLMVLYQXIXIPVW;
/*INC*/	if (!INC(OQLNKAEQMARVXU, AHORKTKMGYCOUI)) goto label_ERTLPBJCSXQLGY;
	if (! isSymbolType(OQLNKAEQMARVXU.container->type)) goto label_ERTLPBJCSXQLGY;
/*SET*/	r_A = OQLNKAEQMARVXU;
//// [ e.1 ] 
/*DEF*/	DataCursor l_4;
/*DEF*/	DataCursor r_4;
/*SET*/	l_4 = r_A;
/*SET*/	r_4 = AHORKTKMGYCOUI;
//// [ empty ] 
/*ISEMPTY*/	if (PAYTFAVEOPSZRN!=0 && arg_to != PAYTFAVEOPSZRN) goto label_ERTLPBJCSXQLGY;

// подготовка подстановки 
DataChain* DCUGBIDVBXRNSA = new DataChain(); 
DataContainer* DCUGBIDVBXRNSA_execbr = newRefExecBrackets(PolnAnaliz, DCUGBIDVBXRNSA, "PolnAnaliz");
result->append(DCUGBIDVBXRNSA_execbr);
DataChain* QWXTBFTQSNPAVY = new DataChain(); 
DCUGBIDVBXRNSA->append(newRefStructBrackets(QWXTBFTQSNPAVY)); 
QWXTBFTQSNPAVY->append(newRefText("1")); 
DataChain* TODPJDPVYQXKSU = new DataChain(); 
DCUGBIDVBXRNSA->append(newRefStructBrackets(TODPJDPVYQXKSU)); 
TODPJDPVYQXKSU->append_copy(l_1, r_1); 
DataChain* VZWZTJRWOVTTLN = new DataChain(); 
DCUGBIDVBXRNSA->append(newRefStructBrackets(VZWZTJRWOVTTLN)); 
VZWZTJRWOVTTLN->append_copy(l_2, r_2); 
VZWZTJRWOVTTLN->append_copy(l_A, r_A); 
DataChain* KZNQDQIAUAPWKC = new DataChain(); 
DCUGBIDVBXRNSA->append(newRefStructBrackets(KZNQDQIAUAPWKC)); 
KZNQDQIAUAPWKC->append_copy(l_3, r_3); 
KZNQDQIAUAPWKC->append_copy(l_4, r_4); 
context->pushExecuteCall(DCUGBIDVBXRNSA_execbr);

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
DataChain* ZXRXOPENEUXFLG = new DataChain(); 
DataContainer* ZXRXOPENEUXFLG_execbr = newRefExecBrackets(Prout, ZXRXOPENEUXFLG, "Prout");
result->append(ZXRXOPENEUXFLG_execbr);
ZXRXOPENEUXFLG->append(newRefText("No point: ")); 
ZXRXOPENEUXFLG->append_copy(l_e, r_e); 
context->pushExecuteCall(ZXRXOPENEUXFLG_execbr);

return result; 
}
sentence_after_4: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* PolnAnaliz__(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
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
DataChain* BDWJMHJGUZPEUD = new DataChain(); 
DataContainer* BDWJMHJGUZPEUD_execbr = newRefExecBrackets(Prout, BDWJMHJGUZPEUD, "Prout");
result->append(BDWJMHJGUZPEUD_execbr);
BDWJMHJGUZPEUD->append(newRefWord("PolnAnaliz:")); 
BDWJMHJGUZPEUD->append_copy(l_e, r_e); 
context->pushExecuteCall(BDWJMHJGUZPEUD_execbr);
DataChain* DFEIMOZYFRQMFO = new DataChain(); 
DataContainer* DFEIMOZYFRQMFO_execbr = newRefExecBrackets(PolnAnaliz__, DFEIMOZYFRQMFO, "PolnAnaliz__");
result->append(DFEIMOZYFRQMFO_execbr);
DFEIMOZYFRQMFO->append_copy(l_e, r_e); 
context->pushExecuteCall(DFEIMOZYFRQMFO_execbr);

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* PolnAnaliz(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor ZISSCCRIFWQBHX;
/*DEF*/	DataCursor YEHKTUSDGZXLAE;
/*DEF*/	DataCursor YKEXQGQOEVJTFR;
/*SET*/	ZISSCCRIFWQBHX = arg_from;
/*INC*/	if (!INC(ZISSCCRIFWQBHX, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (ZISSCCRIFWQBHX.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	YEHKTUSDGZXLAE = ZISSCCRIFWQBHX.container->value.bracket_data.chain->at_before_first();
	YKEXQGQOEVJTFR   = ZISSCCRIFWQBHX.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor AMUQGBDNRSMBXR;
/*DEF*/	DataCursor l_g;
/*DEF*/	DataCursor r_g;
/*SET*/	l_g = YEHKTUSDGZXLAE;
/*SET*/	AMUQGBDNRSMBXR = YEHKTUSDGZXLAE;
/*INC*/	if (!INC(AMUQGBDNRSMBXR, YKEXQGQOEVJTFR)) goto sentence_after_1;
	if (! isSymbolType(AMUQGBDNRSMBXR.container->type)) goto sentence_after_1;
/*SET*/	r_g = AMUQGBDNRSMBXR;
//// [ empty ] 
/*ISEMPTY*/	if (r_g!=0 && YKEXQGQOEVJTFR != r_g) goto sentence_after_1;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor VBTFGLOWFFCTUJ;
/*DEF*/	DataCursor TZQWZGGTLBHROP;
/*DEF*/	DataCursor KWKBBWVNAKWVVD;
/*SET*/	VBTFGLOWFFCTUJ = ZISSCCRIFWQBHX;
/*INC*/	if (!INC(VBTFGLOWFFCTUJ, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (VBTFGLOWFFCTUJ.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	TZQWZGGTLBHROP = VBTFGLOWFFCTUJ.container->value.bracket_data.chain->at_before_first();
	KWKBBWVNAKWVVD   = VBTFGLOWFFCTUJ.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = TZQWZGGTLBHROP;
/*SET*/	r_1 = KWKBBWVNAKWVVD;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor YCXCZOZQIWORVP;
/*DEF*/	DataCursor WKOQMQHCALYZVQ;
/*DEF*/	DataCursor NKCXEKJQZVUESW;
/*SET*/	YCXCZOZQIWORVP = VBTFGLOWFFCTUJ;
/*INC*/	if (!INC(YCXCZOZQIWORVP, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (YCXCZOZQIWORVP.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	WKOQMQHCALYZVQ = YCXCZOZQIWORVP.container->value.bracket_data.chain->at_before_first();
	NKCXEKJQZVUESW   = YCXCZOZQIWORVP.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = WKOQMQHCALYZVQ;
/*SET*/	r_2 = NKCXEKJQZVUESW;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor QKNZPYVYSDKHSO;
/*DEF*/	DataCursor ICMHCZOHEFNASL;
/*DEF*/	DataCursor XWXLLXLEWTZUWB;
/*SET*/	QKNZPYVYSDKHSO = YCXCZOZQIWORVP;
/*INC*/	if (!INC(QKNZPYVYSDKHSO, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (QKNZPYVYSDKHSO.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	ICMHCZOHEFNASL = QKNZPYVYSDKHSO.container->value.bracket_data.chain->at_before_first();
	XWXLLXLEWTZUWB   = QKNZPYVYSDKHSO.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = ICMHCZOHEFNASL;
/*SET*/	r_n = XWXLLXLEWTZUWB;
//// [ empty ] 
/*ISEMPTY*/	if (QKNZPYVYSDKHSO!=0 && arg_to != QKNZPYVYSDKHSO) goto sentence_after_1;

// подготовка подстановки 
DataChain* SUVSENEIQWHNEZ = new DataChain(); 
DataContainer* SUVSENEIQWHNEZ_execbr = newRefExecBrackets(Ifmust, SUVSENEIQWHNEZ, "Ifmust");
result->append(SUVSENEIQWHNEZ_execbr);
DataChain* OJKXHORYESUGDH = new DataChain(); 
SUVSENEIQWHNEZ->append(newRefStructBrackets(OJKXHORYESUGDH)); 
DataChain* TJCKQJDFGNRDOI = new DataChain(); 
DataContainer* TJCKQJDFGNRDOI_execbr = newRefExecBrackets(Strategy, TJCKQJDFGNRDOI, "Strategy");
OJKXHORYESUGDH->append(TJCKQJDFGNRDOI_execbr);
TJCKQJDFGNRDOI->append_copy(l_1, r_1); 
context->pushExecuteCall(TJCKQJDFGNRDOI_execbr);
DataChain* ZPYFMDLQLWQIOD = new DataChain(); 
SUVSENEIQWHNEZ->append(newRefStructBrackets(ZPYFMDLQLWQIOD)); 
DataChain* CWFYGKIVBUJFIN = new DataChain(); 
DataContainer* CWFYGKIVBUJFIN_execbr = newRefExecBrackets(Strategy, CWFYGKIVBUJFIN, "Strategy");
ZPYFMDLQLWQIOD->append(CWFYGKIVBUJFIN_execbr);
CWFYGKIVBUJFIN->append_copy(l_2, r_2); 
context->pushExecuteCall(CWFYGKIVBUJFIN_execbr);
DataChain* ZYHCEJCJOJONHG = new DataChain(); 
SUVSENEIQWHNEZ->append(newRefStructBrackets(ZYHCEJCJOJONHG)); 
DataChain* USTQJFNECOLOCM = new DataChain(); 
DataContainer* USTQJFNECOLOCM_execbr = newRefExecBrackets(Strategy, USTQJFNECOLOCM, "Strategy");
ZYHCEJCJOJONHG->append(USTQJFNECOLOCM_execbr);
USTQJFNECOLOCM->append_copy(l_n, r_n); 
context->pushExecuteCall(USTQJFNECOLOCM_execbr);
DataChain* FHPZXTGFPMUSCR = new DataChain(); 
SUVSENEIQWHNEZ->append(newRefStructBrackets(FHPZXTGFPMUSCR)); 
FHPZXTGFPMUSCR->append_copy(l_g, r_g); 
DataChain* LDURENNLQKWHHY = new DataChain(); 
SUVSENEIQWHNEZ->append(newRefStructBrackets(LDURENNLQKWHHY)); 
LDURENNLQKWHHY->append_copy(l_1, r_1); 
DataChain* IPQZEVBYKTBVTP = new DataChain(); 
SUVSENEIQWHNEZ->append(newRefStructBrackets(IPQZEVBYKTBVTP)); 
IPQZEVBYKTBVTP->append_copy(l_2, r_2); 
DataChain* WVTTGECAJYLQVU = new DataChain(); 
SUVSENEIQWHNEZ->append(newRefStructBrackets(WVTTGECAJYLQVU)); 
WVTTGECAJYLQVU->append_copy(l_n, r_n); 
context->pushExecuteCall(SUVSENEIQWHNEZ_execbr);

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Ifmust__(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
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
DataChain* IZFSOAYXZILJZE = new DataChain(); 
DataContainer* IZFSOAYXZILJZE_execbr = newRefExecBrackets(Prout, IZFSOAYXZILJZE, "Prout");
result->append(IZFSOAYXZILJZE_execbr);
IZFSOAYXZILJZE->append(newRefWord("Ifmust:")); 
IZFSOAYXZILJZE->append_copy(l_e, r_e); 
context->pushExecuteCall(IZFSOAYXZILJZE_execbr);
DataChain* GBLCATMVEFQRZX = new DataChain(); 
DataContainer* GBLCATMVEFQRZX_execbr = newRefExecBrackets(Ifmust__, GBLCATMVEFQRZX, "Ifmust__");
result->append(GBLCATMVEFQRZX_execbr);
GBLCATMVEFQRZX->append_copy(l_e, r_e); 
context->pushExecuteCall(GBLCATMVEFQRZX_execbr);

return result; 
}
sentence_after_1: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* Ifmust(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor WKTNDPBBZDRWLP;
/*DEF*/	DataCursor HLGDYWDOFNZXQL;
/*DEF*/	DataCursor XVKHDJYALHVVPA;
/*SET*/	WKTNDPBBZDRWLP = arg_from;
/*INC*/	if (!INC(WKTNDPBBZDRWLP, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (WKTNDPBBZDRWLP.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	HLGDYWDOFNZXQL = WKTNDPBBZDRWLP.container->value.bracket_data.chain->at_before_first();
	XVKHDJYALHVVPA   = WKTNDPBBZDRWLP.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_e1;
/*DEF*/	DataCursor r_e1;
/*SET*/	l_e1 = HLGDYWDOFNZXQL;
/*SET*/	r_e1 = XVKHDJYALHVVPA;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor ANGODNLXHLSXSH;
/*DEF*/	DataCursor HTIFXICKOBIXBB;
/*DEF*/	DataCursor DUZVNGQIAGGCXF;
/*SET*/	ANGODNLXHLSXSH = WKTNDPBBZDRWLP;
/*INC*/	if (!INC(ANGODNLXHLSXSH, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (ANGODNLXHLSXSH.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	HTIFXICKOBIXBB = ANGODNLXHLSXSH.container->value.bracket_data.chain->at_before_first();
	DUZVNGQIAGGCXF   = ANGODNLXHLSXSH.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e21;
/*DEF*/	DataCursor r_e21;
/*SET*/	l_e21 = HTIFXICKOBIXBB;
/*SET*/	r_e21 = HTIFXICKOBIXBB;
/*JMP*/	goto label_GRJMARWUPAYBNQ_firststep;
label_GRJMARWUPAYBNQ: 
/*INC*/	if (!INC(r_e21, DUZVNGQIAGGCXF)) goto sentence_after_1;
label_GRJMARWUPAYBNQ_firststep: 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor GUDBEWKGWGTOCB;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_e21;
/*SET*/	GUDBEWKGWGTOCB = r_e21;
/*INC*/	if (!INC(GUDBEWKGWGTOCB, DUZVNGQIAGGCXF)) goto label_GRJMARWUPAYBNQ;
	if (! isSymbolType(GUDBEWKGWGTOCB.container->type)) goto label_GRJMARWUPAYBNQ;
/*SET*/	r_A = GUDBEWKGWGTOCB;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e22;
/*DEF*/	DataCursor r_e22;
/*SET*/	l_e22 = r_A;
/*SET*/	r_e22 = r_A;
/*JMP*/	goto label_LXJECCGQHBCZIB_firststep;
label_LXJECCGQHBCZIB: 
/*INC*/	if (!INC(r_e22, DUZVNGQIAGGCXF)) goto label_GRJMARWUPAYBNQ;
label_LXJECCGQHBCZIB_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor HQUFQQXVLLVMTZ;
/*SET*/	HQUFQQXVLLVMTZ = r_e22;
 if (!SLIDE(HQUFQQXVLLVMTZ, DUZVNGQIAGGCXF, l_A, r_A)) goto label_LXJECCGQHBCZIB;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e23;
/*DEF*/	DataCursor r_e23;
/*SET*/	l_e23 = HQUFQQXVLLVMTZ;
/*SET*/	r_e23 = DUZVNGQIAGGCXF;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor HFMBEZPLHQAKBM;
/*DEF*/	DataCursor MVAFQYXJYEXDSS;
/*DEF*/	DataCursor WBJIOUYMHLZCLT;
/*SET*/	HFMBEZPLHQAKBM = ANGODNLXHLSXSH;
/*INC*/	if (!INC(HFMBEZPLHQAKBM, arg_to)) goto label_LXJECCGQHBCZIB;
//// ISBRACKET 
	if (HFMBEZPLHQAKBM.container->type != struct_bracket) goto label_LXJECCGQHBCZIB;
//// JMP_BRACKET 
	MVAFQYXJYEXDSS = HFMBEZPLHQAKBM.container->value.bracket_data.chain->at_before_first();
	WBJIOUYMHLZCLT   = HFMBEZPLHQAKBM.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_nn1;
/*DEF*/	DataCursor r_nn1;
/*SET*/	l_nn1 = MVAFQYXJYEXDSS;
/*SET*/	r_nn1 = MVAFQYXJYEXDSS;
/*JMP*/	goto label_JUDOBFUOIWUBGE_firststep;
label_JUDOBFUOIWUBGE: 
/*INC*/	if (!INC(r_nn1, WBJIOUYMHLZCLT)) goto label_LXJECCGQHBCZIB;
label_JUDOBFUOIWUBGE_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor IDPMVKHOZHKDUC;
/*SET*/	IDPMVKHOZHKDUC = r_nn1;
 if (!SLIDE(IDPMVKHOZHKDUC, WBJIOUYMHLZCLT, l_A, r_A)) goto label_JUDOBFUOIWUBGE;
//// [ e.1 ] 
/*DEF*/	DataCursor l_nn2;
/*DEF*/	DataCursor r_nn2;
/*SET*/	l_nn2 = IDPMVKHOZHKDUC;
/*SET*/	r_nn2 = WBJIOUYMHLZCLT;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor OMLGLTLVEINNCA;
/*DEF*/	DataCursor IKNSUGJQCCASDX;
/*DEF*/	DataCursor DAZCRTVLLKFVTE;
/*SET*/	OMLGLTLVEINNCA = HFMBEZPLHQAKBM;
/*INC*/	if (!INC(OMLGLTLVEINNCA, arg_to)) goto label_JUDOBFUOIWUBGE;
//// ISBRACKET 
	if (OMLGLTLVEINNCA.container->type != struct_bracket) goto label_JUDOBFUOIWUBGE;
//// JMP_BRACKET 
	IKNSUGJQCCASDX = OMLGLTLVEINNCA.container->value.bracket_data.chain->at_before_first();
	DAZCRTVLLKFVTE   = OMLGLTLVEINNCA.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor ZAZZCSCTLEGENL;
/*SET*/	ZAZZCSCTLEGENL = IKNSUGJQCCASDX;
/*INC*/	if (!INC(ZAZZCSCTLEGENL, DAZCRTVLLKFVTE)) goto label_JUDOBFUOIWUBGE;
	if (ZAZZCSCTLEGENL.container->type != text || *(ZAZZCSCTLEGENL.container->value.text + ZAZZCSCTLEGENL.index) != '2') goto label_JUDOBFUOIWUBGE;
//// [ empty ] 
/*ISEMPTY*/	if (ZAZZCSCTLEGENL!=0 && DAZCRTVLLKFVTE != ZAZZCSCTLEGENL) goto label_JUDOBFUOIWUBGE;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e1e2;
/*DEF*/	DataCursor r_e1e2;
/*SET*/	l_e1e2 = OMLGLTLVEINNCA;
/*SET*/	r_e1e2 = OMLGLTLVEINNCA;
/*JMP*/	goto label_DSYQNCSDJSDCXX_firststep;
label_DSYQNCSDJSDCXX: 
/*INC*/	if (!INC(r_e1e2, arg_to)) goto label_JUDOBFUOIWUBGE;
label_DSYQNCSDJSDCXX_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor YRGHRWPQINXMRI;
/*DEF*/	DataCursor DXPDPQUNVKWXRY;
/*DEF*/	DataCursor KXTLXYPPFMAJFH;
/*SET*/	YRGHRWPQINXMRI = r_e1e2;
/*INC*/	if (!INC(YRGHRWPQINXMRI, arg_to)) goto label_DSYQNCSDJSDCXX;
//// ISBRACKET 
	if (YRGHRWPQINXMRI.container->type != struct_bracket) goto label_DSYQNCSDJSDCXX;
//// JMP_BRACKET 
	DXPDPQUNVKWXRY = YRGHRWPQINXMRI.container->value.bracket_data.chain->at_before_first();
	KXTLXYPPFMAJFH   = YRGHRWPQINXMRI.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = DXPDPQUNVKWXRY;
/*SET*/	r_n = KXTLXYPPFMAJFH;
//// [ empty ] 
/*ISEMPTY*/	if (YRGHRWPQINXMRI!=0 && arg_to != YRGHRWPQINXMRI) goto label_DSYQNCSDJSDCXX;

// подготовка подстановки 
result->append(newRefText("2")); 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor QYUDWTIGBJTMQM;
/*DEF*/	DataCursor DLTCQZGCAIWSWF;
/*DEF*/	DataCursor YRYHCWWIARUHII;
/*SET*/	QYUDWTIGBJTMQM = arg_from;
/*INC*/	if (!INC(QYUDWTIGBJTMQM, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (QYUDWTIGBJTMQM.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	DLTCQZGCAIWSWF = QYUDWTIGBJTMQM.container->value.bracket_data.chain->at_before_first();
	YRYHCWWIARUHII   = QYUDWTIGBJTMQM.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e21;
/*DEF*/	DataCursor r_e21;
/*SET*/	l_e21 = DLTCQZGCAIWSWF;
/*SET*/	r_e21 = DLTCQZGCAIWSWF;
/*JMP*/	goto label_BUJOPGRQNPIUGK_firststep;
label_BUJOPGRQNPIUGK: 
/*INC*/	if (!INC(r_e21, YRYHCWWIARUHII)) goto sentence_after_2;
label_BUJOPGRQNPIUGK_firststep: 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor DQTESOJACQHNWD;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_e21;
/*SET*/	DQTESOJACQHNWD = r_e21;
/*INC*/	if (!INC(DQTESOJACQHNWD, YRYHCWWIARUHII)) goto label_BUJOPGRQNPIUGK;
	if (! isSymbolType(DQTESOJACQHNWD.container->type)) goto label_BUJOPGRQNPIUGK;
/*SET*/	r_A = DQTESOJACQHNWD;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e22;
/*DEF*/	DataCursor r_e22;
/*SET*/	l_e22 = r_A;
/*SET*/	r_e22 = r_A;
/*JMP*/	goto label_AGNVXESFRFIEFA_firststep;
label_AGNVXESFRFIEFA: 
/*INC*/	if (!INC(r_e22, YRYHCWWIARUHII)) goto label_BUJOPGRQNPIUGK;
label_AGNVXESFRFIEFA_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor ABRADQEELKPKEC;
/*SET*/	ABRADQEELKPKEC = r_e22;
 if (!SLIDE(ABRADQEELKPKEC, YRYHCWWIARUHII, l_A, r_A)) goto label_AGNVXESFRFIEFA;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e23;
/*DEF*/	DataCursor r_e23;
/*SET*/	l_e23 = ABRADQEELKPKEC;
/*SET*/	r_e23 = YRYHCWWIARUHII;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor VPSDWELPDJMMBP;
/*DEF*/	DataCursor DUPZVTVJXYDKDN;
/*DEF*/	DataCursor CUGGHONUCWEGVF;
/*SET*/	VPSDWELPDJMMBP = QYUDWTIGBJTMQM;
/*INC*/	if (!INC(VPSDWELPDJMMBP, arg_to)) goto label_AGNVXESFRFIEFA;
//// ISBRACKET 
	if (VPSDWELPDJMMBP.container->type != struct_bracket) goto label_AGNVXESFRFIEFA;
//// JMP_BRACKET 
	DUPZVTVJXYDKDN = VPSDWELPDJMMBP.container->value.bracket_data.chain->at_before_first();
	CUGGHONUCWEGVF   = VPSDWELPDJMMBP.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_e1;
/*DEF*/	DataCursor r_e1;
/*SET*/	l_e1 = DUPZVTVJXYDKDN;
/*SET*/	r_e1 = CUGGHONUCWEGVF;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor JZBDWKBEVKGDWU;
/*DEF*/	DataCursor BTJVTOQOTHGGTD;
/*DEF*/	DataCursor RDOLGJMFUBZZPN;
/*SET*/	JZBDWKBEVKGDWU = VPSDWELPDJMMBP;
/*INC*/	if (!INC(JZBDWKBEVKGDWU, arg_to)) goto label_AGNVXESFRFIEFA;
//// ISBRACKET 
	if (JZBDWKBEVKGDWU.container->type != struct_bracket) goto label_AGNVXESFRFIEFA;
//// JMP_BRACKET 
	BTJVTOQOTHGGTD = JZBDWKBEVKGDWU.container->value.bracket_data.chain->at_before_first();
	RDOLGJMFUBZZPN   = JZBDWKBEVKGDWU.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_nn1;
/*DEF*/	DataCursor r_nn1;
/*SET*/	l_nn1 = BTJVTOQOTHGGTD;
/*SET*/	r_nn1 = BTJVTOQOTHGGTD;
/*JMP*/	goto label_HJAQWOTZQBLHMR_firststep;
label_HJAQWOTZQBLHMR: 
/*INC*/	if (!INC(r_nn1, RDOLGJMFUBZZPN)) goto label_AGNVXESFRFIEFA;
label_HJAQWOTZQBLHMR_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor FZFGYKZMUCWWPD;
/*SET*/	FZFGYKZMUCWWPD = r_nn1;
 if (!SLIDE(FZFGYKZMUCWWPD, RDOLGJMFUBZZPN, l_A, r_A)) goto label_HJAQWOTZQBLHMR;
//// [ e.1 ] 
/*DEF*/	DataCursor l_nn2;
/*DEF*/	DataCursor r_nn2;
/*SET*/	l_nn2 = FZFGYKZMUCWWPD;
/*SET*/	r_nn2 = RDOLGJMFUBZZPN;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor YJVCTVFAMCGLTM;
/*DEF*/	DataCursor JTMRCJIVHSYTNW;
/*DEF*/	DataCursor MQQJVMOHFYESQX;
/*SET*/	YJVCTVFAMCGLTM = JZBDWKBEVKGDWU;
/*INC*/	if (!INC(YJVCTVFAMCGLTM, arg_to)) goto label_HJAQWOTZQBLHMR;
//// ISBRACKET 
	if (YJVCTVFAMCGLTM.container->type != struct_bracket) goto label_HJAQWOTZQBLHMR;
//// JMP_BRACKET 
	JTMRCJIVHSYTNW = YJVCTVFAMCGLTM.container->value.bracket_data.chain->at_before_first();
	MQQJVMOHFYESQX   = YJVCTVFAMCGLTM.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor DVRJGFVGYMHLWD;
/*SET*/	DVRJGFVGYMHLWD = JTMRCJIVHSYTNW;
/*INC*/	if (!INC(DVRJGFVGYMHLWD, MQQJVMOHFYESQX)) goto label_HJAQWOTZQBLHMR;
	if (DVRJGFVGYMHLWD.container->type != text || *(DVRJGFVGYMHLWD.container->value.text + DVRJGFVGYMHLWD.index) != '1') goto label_HJAQWOTZQBLHMR;
//// [ empty ] 
/*ISEMPTY*/	if (DVRJGFVGYMHLWD!=0 && MQQJVMOHFYESQX != DVRJGFVGYMHLWD) goto label_HJAQWOTZQBLHMR;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e1e2;
/*DEF*/	DataCursor r_e1e2;
/*SET*/	l_e1e2 = YJVCTVFAMCGLTM;
/*SET*/	r_e1e2 = YJVCTVFAMCGLTM;
/*JMP*/	goto label_AMEYKVIXDAQVSS_firststep;
label_AMEYKVIXDAQVSS: 
/*INC*/	if (!INC(r_e1e2, arg_to)) goto label_HJAQWOTZQBLHMR;
label_AMEYKVIXDAQVSS_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor DWWOEDKLQENAFB;
/*DEF*/	DataCursor CFNHWRHDKJCSXO;
/*DEF*/	DataCursor HDVRBNLBLSEEND;
/*SET*/	DWWOEDKLQENAFB = r_e1e2;
/*INC*/	if (!INC(DWWOEDKLQENAFB, arg_to)) goto label_AMEYKVIXDAQVSS;
//// ISBRACKET 
	if (DWWOEDKLQENAFB.container->type != struct_bracket) goto label_AMEYKVIXDAQVSS;
//// JMP_BRACKET 
	CFNHWRHDKJCSXO = DWWOEDKLQENAFB.container->value.bracket_data.chain->at_before_first();
	HDVRBNLBLSEEND   = DWWOEDKLQENAFB.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = CFNHWRHDKJCSXO;
/*SET*/	r_n = HDVRBNLBLSEEND;
//// [ empty ] 
/*ISEMPTY*/	if (DWWOEDKLQENAFB!=0 && arg_to != DWWOEDKLQENAFB) goto label_AMEYKVIXDAQVSS;

// подготовка подстановки 
result->append(newRefText("1")); 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor UBKXAORTEJLRCM;
/*DEF*/	DataCursor CVOVRSQRCOPNNP;
/*DEF*/	DataCursor KUNKKCPOENVPKV;
/*SET*/	UBKXAORTEJLRCM = arg_from;
/*INC*/	if (!INC(UBKXAORTEJLRCM, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (UBKXAORTEJLRCM.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	CVOVRSQRCOPNNP = UBKXAORTEJLRCM.container->value.bracket_data.chain->at_before_first();
	KUNKKCPOENVPKV   = UBKXAORTEJLRCM.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_e1;
/*DEF*/	DataCursor r_e1;
/*SET*/	l_e1 = CVOVRSQRCOPNNP;
/*SET*/	r_e1 = KUNKKCPOENVPKV;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor YGUNPABOUJVIRE;
/*DEF*/	DataCursor LEHLGECTNAZVQP;
/*DEF*/	DataCursor SOUUBCPYFIKGQT;
/*SET*/	YGUNPABOUJVIRE = UBKXAORTEJLRCM;
/*INC*/	if (!INC(YGUNPABOUJVIRE, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (YGUNPABOUJVIRE.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	LEHLGECTNAZVQP = YGUNPABOUJVIRE.container->value.bracket_data.chain->at_before_first();
	SOUUBCPYFIKGQT   = YGUNPABOUJVIRE.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e21;
/*DEF*/	DataCursor r_e21;
/*SET*/	l_e21 = LEHLGECTNAZVQP;
/*SET*/	r_e21 = LEHLGECTNAZVQP;
/*JMP*/	goto label_UFVQQEVCPCJPMJ_firststep;
label_UFVQQEVCPCJPMJ: 
/*INC*/	if (!INC(r_e21, SOUUBCPYFIKGQT)) goto sentence_after_3;
label_UFVQQEVCPCJPMJ_firststep: 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor HPUACSIASPTSKQ;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_e21;
/*SET*/	HPUACSIASPTSKQ = r_e21;
/*INC*/	if (!INC(HPUACSIASPTSKQ, SOUUBCPYFIKGQT)) goto label_UFVQQEVCPCJPMJ;
	if (! isSymbolType(HPUACSIASPTSKQ.container->type)) goto label_UFVQQEVCPCJPMJ;
/*SET*/	r_A = HPUACSIASPTSKQ;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e22;
/*DEF*/	DataCursor r_e22;
/*SET*/	l_e22 = r_A;
/*SET*/	r_e22 = r_A;
/*JMP*/	goto label_YHITAUZFABLPQL_firststep;
label_YHITAUZFABLPQL: 
/*INC*/	if (!INC(r_e22, SOUUBCPYFIKGQT)) goto label_UFVQQEVCPCJPMJ;
label_YHITAUZFABLPQL_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor KUKAHMLIVZAPRO;
/*SET*/	KUKAHMLIVZAPRO = r_e22;
 if (!SLIDE(KUKAHMLIVZAPRO, SOUUBCPYFIKGQT, l_A, r_A)) goto label_YHITAUZFABLPQL;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e23;
/*DEF*/	DataCursor r_e23;
/*SET*/	l_e23 = KUKAHMLIVZAPRO;
/*SET*/	r_e23 = SOUUBCPYFIKGQT;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor TLQDIUOEEYKIQZ;
/*DEF*/	DataCursor AHFAVZZRFRZZEM;
/*DEF*/	DataCursor IYZVOBXUOJORAW;
/*SET*/	TLQDIUOEEYKIQZ = YGUNPABOUJVIRE;
/*INC*/	if (!INC(TLQDIUOEEYKIQZ, arg_to)) goto label_YHITAUZFABLPQL;
//// ISBRACKET 
	if (TLQDIUOEEYKIQZ.container->type != struct_bracket) goto label_YHITAUZFABLPQL;
//// JMP_BRACKET 
	AHFAVZZRFRZZEM = TLQDIUOEEYKIQZ.container->value.bracket_data.chain->at_before_first();
	IYZVOBXUOJORAW   = TLQDIUOEEYKIQZ.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_nn1;
/*DEF*/	DataCursor r_nn1;
/*SET*/	l_nn1 = AHFAVZZRFRZZEM;
/*SET*/	r_nn1 = AHFAVZZRFRZZEM;
/*JMP*/	goto label_URHJOPPNNCTEHR_firststep;
label_URHJOPPNNCTEHR: 
/*INC*/	if (!INC(r_nn1, IYZVOBXUOJORAW)) goto label_YHITAUZFABLPQL;
label_URHJOPPNNCTEHR_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor ULPGKOZUYWMOBC;
/*SET*/	ULPGKOZUYWMOBC = r_nn1;
 if (!SLIDE(ULPGKOZUYWMOBC, IYZVOBXUOJORAW, l_A, r_A)) goto label_URHJOPPNNCTEHR;
//// [ e.1 ] 
/*DEF*/	DataCursor l_nn2;
/*DEF*/	DataCursor r_nn2;
/*SET*/	l_nn2 = ULPGKOZUYWMOBC;
/*SET*/	r_nn2 = IYZVOBXUOJORAW;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor DLBOFBJEJAZSRU;
/*DEF*/	DataCursor LVQTAMMEMHQPYI;
/*DEF*/	DataCursor OWMNLQAEFZSIOT;
/*SET*/	DLBOFBJEJAZSRU = TLQDIUOEEYKIQZ;
/*INC*/	if (!INC(DLBOFBJEJAZSRU, arg_to)) goto label_URHJOPPNNCTEHR;
//// ISBRACKET 
	if (DLBOFBJEJAZSRU.container->type != struct_bracket) goto label_URHJOPPNNCTEHR;
//// JMP_BRACKET 
	LVQTAMMEMHQPYI = DLBOFBJEJAZSRU.container->value.bracket_data.chain->at_before_first();
	OWMNLQAEFZSIOT   = DLBOFBJEJAZSRU.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor PXJWOCJEUMCJDQ;
/*SET*/	PXJWOCJEUMCJDQ = LVQTAMMEMHQPYI;
/*INC*/	if (!INC(PXJWOCJEUMCJDQ, OWMNLQAEFZSIOT)) goto label_URHJOPPNNCTEHR;
	if (PXJWOCJEUMCJDQ.container->type != text || *(PXJWOCJEUMCJDQ.container->value.text + PXJWOCJEUMCJDQ.index) != '1') goto label_URHJOPPNNCTEHR;
//// [ empty ] 
/*ISEMPTY*/	if (PXJWOCJEUMCJDQ!=0 && OWMNLQAEFZSIOT != PXJWOCJEUMCJDQ) goto label_URHJOPPNNCTEHR;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e1e2;
/*DEF*/	DataCursor r_e1e2;
/*SET*/	l_e1e2 = DLBOFBJEJAZSRU;
/*SET*/	r_e1e2 = DLBOFBJEJAZSRU;
/*JMP*/	goto label_LQLRCEZJFXCHWD_firststep;
label_LQLRCEZJFXCHWD: 
/*INC*/	if (!INC(r_e1e2, arg_to)) goto label_URHJOPPNNCTEHR;
label_LQLRCEZJFXCHWD_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor DXONZMNJVLRJXR;
/*DEF*/	DataCursor XWKDUOOERCTEEQ;
/*DEF*/	DataCursor DVDLRWAMNKYXJS;
/*SET*/	DXONZMNJVLRJXR = r_e1e2;
/*INC*/	if (!INC(DXONZMNJVLRJXR, arg_to)) goto label_LQLRCEZJFXCHWD;
//// ISBRACKET 
	if (DXONZMNJVLRJXR.container->type != struct_bracket) goto label_LQLRCEZJFXCHWD;
//// JMP_BRACKET 
	XWKDUOOERCTEEQ = DXONZMNJVLRJXR.container->value.bracket_data.chain->at_before_first();
	DVDLRWAMNKYXJS   = DXONZMNJVLRJXR.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = XWKDUOOERCTEEQ;
/*SET*/	r_n = DVDLRWAMNKYXJS;
//// [ empty ] 
/*ISEMPTY*/	if (DXONZMNJVLRJXR!=0 && arg_to != DXONZMNJVLRJXR) goto label_LQLRCEZJFXCHWD;

// подготовка подстановки 
DataChain* XPFDLZEHBGKVYP = new DataChain(); 
DataContainer* XPFDLZEHBGKVYP_execbr = newRefExecBrackets(StepShag, XPFDLZEHBGKVYP, "StepShag");
result->append(XPFDLZEHBGKVYP_execbr);
DataChain* XFSMQHIBNGJTGR = new DataChain(); 
DataContainer* XFSMQHIBNGJTGR_execbr = newRefExecBrackets(Lins, XFSMQHIBNGJTGR, "Lins");
XPFDLZEHBGKVYP->append(XFSMQHIBNGJTGR_execbr);
DataChain* KPFERAYXDZNPGK = new DataChain(); 
XFSMQHIBNGJTGR->append(newRefStructBrackets(KPFERAYXDZNPGK)); 
KPFERAYXDZNPGK->append_copy(l_n, r_n); 
DataChain* SDFPDJOBICQFQM = new DataChain(); 
DataContainer* SDFPDJOBICQFQM_execbr = newRefExecBrackets(AntiStrategy, SDFPDJOBICQFQM, "AntiStrategy");
XFSMQHIBNGJTGR->append(SDFPDJOBICQFQM_execbr);
SDFPDJOBICQFQM->append_copy(l_A, r_A); 
context->pushExecuteCall(SDFPDJOBICQFQM_execbr);
context->pushExecuteCall(XFSMQHIBNGJTGR_execbr);
DataChain* FSTQHPFMCPMFDC = new DataChain(); 
XPFDLZEHBGKVYP->append(newRefStructBrackets(FSTQHPFMCPMFDC)); 
FSTQHPFMCPMFDC->append(newRefText("1")); 
XPFDLZEHBGKVYP->append_copy(l_e1e2, r_e1e2); 
DataChain* DCCMODLQJQGWJO = new DataChain(); 
XPFDLZEHBGKVYP->append(newRefStructBrackets(DCCMODLQJQGWJO)); 
DCCMODLQJQGWJO->append_copy(l_n, r_n); 
context->pushExecuteCall(XPFDLZEHBGKVYP_execbr);

return result; 
}
sentence_after_3: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor FNUQNPMHDVKZEB;
/*DEF*/	DataCursor NLIGKJFSWCXWCU;
/*DEF*/	DataCursor JWHEPDBSGTFFKB;
/*SET*/	FNUQNPMHDVKZEB = arg_from;
/*INC*/	if (!INC(FNUQNPMHDVKZEB, arg_to)) goto sentence_after_4;
//// ISBRACKET 
	if (FNUQNPMHDVKZEB.container->type != struct_bracket) goto sentence_after_4;
//// JMP_BRACKET 
	NLIGKJFSWCXWCU = FNUQNPMHDVKZEB.container->value.bracket_data.chain->at_before_first();
	JWHEPDBSGTFFKB   = FNUQNPMHDVKZEB.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e21;
/*DEF*/	DataCursor r_e21;
/*SET*/	l_e21 = NLIGKJFSWCXWCU;
/*SET*/	r_e21 = NLIGKJFSWCXWCU;
/*JMP*/	goto label_YKEUHNFZNGKPMV_firststep;
label_YKEUHNFZNGKPMV: 
/*INC*/	if (!INC(r_e21, JWHEPDBSGTFFKB)) goto sentence_after_4;
label_YKEUHNFZNGKPMV_firststep: 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor QTHEJJRBZHRCGG;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = r_e21;
/*SET*/	QTHEJJRBZHRCGG = r_e21;
/*INC*/	if (!INC(QTHEJJRBZHRCGG, JWHEPDBSGTFFKB)) goto label_YKEUHNFZNGKPMV;
	if (! isSymbolType(QTHEJJRBZHRCGG.container->type)) goto label_YKEUHNFZNGKPMV;
/*SET*/	r_A = QTHEJJRBZHRCGG;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e22;
/*DEF*/	DataCursor r_e22;
/*SET*/	l_e22 = r_A;
/*SET*/	r_e22 = r_A;
/*JMP*/	goto label_OEWVRXBWYSZBLQ_firststep;
label_OEWVRXBWYSZBLQ: 
/*INC*/	if (!INC(r_e22, JWHEPDBSGTFFKB)) goto label_YKEUHNFZNGKPMV;
label_OEWVRXBWYSZBLQ_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor GPWJPLTJFRQCOC;
/*SET*/	GPWJPLTJFRQCOC = r_e22;
 if (!SLIDE(GPWJPLTJFRQCOC, JWHEPDBSGTFFKB, l_A, r_A)) goto label_OEWVRXBWYSZBLQ;
//// [ e.1 ] 
/*DEF*/	DataCursor l_e23;
/*DEF*/	DataCursor r_e23;
/*SET*/	l_e23 = GPWJPLTJFRQCOC;
/*SET*/	r_e23 = JWHEPDBSGTFFKB;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor QXYLUTTLWHTZAS;
/*DEF*/	DataCursor NQEOYJBXKIQMAJ;
/*DEF*/	DataCursor AGFHZZFBDVFUYU;
/*SET*/	QXYLUTTLWHTZAS = FNUQNPMHDVKZEB;
/*INC*/	if (!INC(QXYLUTTLWHTZAS, arg_to)) goto label_OEWVRXBWYSZBLQ;
//// ISBRACKET 
	if (QXYLUTTLWHTZAS.container->type != struct_bracket) goto label_OEWVRXBWYSZBLQ;
//// JMP_BRACKET 
	NQEOYJBXKIQMAJ = QXYLUTTLWHTZAS.container->value.bracket_data.chain->at_before_first();
	AGFHZZFBDVFUYU   = QXYLUTTLWHTZAS.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_e1;
/*DEF*/	DataCursor r_e1;
/*SET*/	l_e1 = NQEOYJBXKIQMAJ;
/*SET*/	r_e1 = AGFHZZFBDVFUYU;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor RLVURNWRAMCADU;
/*DEF*/	DataCursor NWUGTUESHXMGZV;
/*DEF*/	DataCursor SRMCIFBVRASUCU;
/*SET*/	RLVURNWRAMCADU = QXYLUTTLWHTZAS;
/*INC*/	if (!INC(RLVURNWRAMCADU, arg_to)) goto label_OEWVRXBWYSZBLQ;
//// ISBRACKET 
	if (RLVURNWRAMCADU.container->type != struct_bracket) goto label_OEWVRXBWYSZBLQ;
//// JMP_BRACKET 
	NWUGTUESHXMGZV = RLVURNWRAMCADU.container->value.bracket_data.chain->at_before_first();
	SRMCIFBVRASUCU   = RLVURNWRAMCADU.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_nn1;
/*DEF*/	DataCursor r_nn1;
/*SET*/	l_nn1 = NWUGTUESHXMGZV;
/*SET*/	r_nn1 = NWUGTUESHXMGZV;
/*JMP*/	goto label_VIVOWLZIVLIICZ_firststep;
label_VIVOWLZIVLIICZ: 
/*INC*/	if (!INC(r_nn1, SRMCIFBVRASUCU)) goto label_OEWVRXBWYSZBLQ;
label_VIVOWLZIVLIICZ_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor PUSSWAFKENWEMO;
/*SET*/	PUSSWAFKENWEMO = r_nn1;
 if (!SLIDE(PUSSWAFKENWEMO, SRMCIFBVRASUCU, l_A, r_A)) goto label_VIVOWLZIVLIICZ;
//// [ e.1 ] 
/*DEF*/	DataCursor l_nn2;
/*DEF*/	DataCursor r_nn2;
/*SET*/	l_nn2 = PUSSWAFKENWEMO;
/*SET*/	r_nn2 = SRMCIFBVRASUCU;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor CIMLMSLEBFIIAR;
/*DEF*/	DataCursor GFMUABIZMYQPTH;
/*DEF*/	DataCursor DMZEIEGQCJTSJH;
/*SET*/	CIMLMSLEBFIIAR = RLVURNWRAMCADU;
/*INC*/	if (!INC(CIMLMSLEBFIIAR, arg_to)) goto label_VIVOWLZIVLIICZ;
//// ISBRACKET 
	if (CIMLMSLEBFIIAR.container->type != struct_bracket) goto label_VIVOWLZIVLIICZ;
//// JMP_BRACKET 
	GFMUABIZMYQPTH = CIMLMSLEBFIIAR.container->value.bracket_data.chain->at_before_first();
	DMZEIEGQCJTSJH   = CIMLMSLEBFIIAR.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor QKMVWZEDALKJDV;
/*SET*/	QKMVWZEDALKJDV = GFMUABIZMYQPTH;
/*INC*/	if (!INC(QKMVWZEDALKJDV, DMZEIEGQCJTSJH)) goto label_VIVOWLZIVLIICZ;
	if (QKMVWZEDALKJDV.container->type != text || *(QKMVWZEDALKJDV.container->value.text + QKMVWZEDALKJDV.index) != '2') goto label_VIVOWLZIVLIICZ;
//// [ empty ] 
/*ISEMPTY*/	if (QKMVWZEDALKJDV!=0 && DMZEIEGQCJTSJH != QKMVWZEDALKJDV) goto label_VIVOWLZIVLIICZ;
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_e1e2;
/*DEF*/	DataCursor r_e1e2;
/*SET*/	l_e1e2 = CIMLMSLEBFIIAR;
/*SET*/	r_e1e2 = CIMLMSLEBFIIAR;
/*JMP*/	goto label_UQCNQYROKQMJSZ_firststep;
label_UQCNQYROKQMJSZ: 
/*INC*/	if (!INC(r_e1e2, arg_to)) goto label_VIVOWLZIVLIICZ;
label_UQCNQYROKQMJSZ_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor JWSDGCOFGLCQGD;
/*DEF*/	DataCursor NDBYPQQIDCLZXS;
/*DEF*/	DataCursor QBJWIPLOXDERKL;
/*SET*/	JWSDGCOFGLCQGD = r_e1e2;
/*INC*/	if (!INC(JWSDGCOFGLCQGD, arg_to)) goto label_UQCNQYROKQMJSZ;
//// ISBRACKET 
	if (JWSDGCOFGLCQGD.container->type != struct_bracket) goto label_UQCNQYROKQMJSZ;
//// JMP_BRACKET 
	NDBYPQQIDCLZXS = JWSDGCOFGLCQGD.container->value.bracket_data.chain->at_before_first();
	QBJWIPLOXDERKL   = JWSDGCOFGLCQGD.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_n;
/*DEF*/	DataCursor r_n;
/*SET*/	l_n = NDBYPQQIDCLZXS;
/*SET*/	r_n = QBJWIPLOXDERKL;
//// [ empty ] 
/*ISEMPTY*/	if (JWSDGCOFGLCQGD!=0 && arg_to != JWSDGCOFGLCQGD) goto label_UQCNQYROKQMJSZ;

// подготовка подстановки 
DataChain* GBXGOGNWYUNRNU = new DataChain(); 
DataContainer* GBXGOGNWYUNRNU_execbr = newRefExecBrackets(StepShag, GBXGOGNWYUNRNU, "StepShag");
result->append(GBXGOGNWYUNRNU_execbr);
DataChain* MFOLBALEZROKNK = new DataChain(); 
DataContainer* MFOLBALEZROKNK_execbr = newRefExecBrackets(Lins, MFOLBALEZROKNK, "Lins");
GBXGOGNWYUNRNU->append(MFOLBALEZROKNK_execbr);
DataChain* JNWRWEBGELZBGI = new DataChain(); 
MFOLBALEZROKNK->append(newRefStructBrackets(JNWRWEBGELZBGI)); 
JNWRWEBGELZBGI->append_copy(l_n, r_n); 
DataChain* QDSCWTSBXXZKGH = new DataChain(); 
DataContainer* QDSCWTSBXXZKGH_execbr = newRefExecBrackets(AntiStrategy, QDSCWTSBXXZKGH, "AntiStrategy");
MFOLBALEZROKNK->append(QDSCWTSBXXZKGH_execbr);
QDSCWTSBXXZKGH->append_copy(l_A, r_A); 
context->pushExecuteCall(QDSCWTSBXXZKGH_execbr);
context->pushExecuteCall(MFOLBALEZROKNK_execbr);
DataChain* SKGEXLEVGXNYDQ = new DataChain(); 
GBXGOGNWYUNRNU->append(newRefStructBrackets(SKGEXLEVGXNYDQ)); 
SKGEXLEVGXNYDQ->append(newRefText("2")); 
GBXGOGNWYUNRNU->append_copy(l_e1e2, r_e1e2); 
DataChain* VTYJSLLQKEHTLI = new DataChain(); 
GBXGOGNWYUNRNU->append(newRefStructBrackets(VTYJSLLQKEHTLI)); 
VTYJSLLQKEHTLI->append_copy(l_n, r_n); 
context->pushExecuteCall(GBXGOGNWYUNRNU_execbr);

return result; 
}
sentence_after_4: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor AUYICCQDMFIEJR;
/*DEF*/	DataCursor QNRNAZCRFHPBJM;
/*DEF*/	DataCursor RFBYQMHDABALHT;
/*SET*/	AUYICCQDMFIEJR = arg_from;
/*INC*/	if (!INC(AUYICCQDMFIEJR, arg_to)) goto sentence_after_5;
//// ISBRACKET 
	if (AUYICCQDMFIEJR.container->type != struct_bracket) goto sentence_after_5;
//// JMP_BRACKET 
	QNRNAZCRFHPBJM = AUYICCQDMFIEJR.container->value.bracket_data.chain->at_before_first();
	RFBYQMHDABALHT   = AUYICCQDMFIEJR.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_e1;
/*DEF*/	DataCursor r_e1;
/*SET*/	l_e1 = QNRNAZCRFHPBJM;
/*SET*/	r_e1 = RFBYQMHDABALHT;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor IGPQMWFONTEPRC;
/*DEF*/	DataCursor HDDWEQDOHSPJDG;
/*DEF*/	DataCursor VLZMJBMWEOILEJ;
/*SET*/	IGPQMWFONTEPRC = AUYICCQDMFIEJR;
/*INC*/	if (!INC(IGPQMWFONTEPRC, arg_to)) goto sentence_after_5;
//// ISBRACKET 
	if (IGPQMWFONTEPRC.container->type != struct_bracket) goto sentence_after_5;
//// JMP_BRACKET 
	HDDWEQDOHSPJDG = IGPQMWFONTEPRC.container->value.bracket_data.chain->at_before_first();
	VLZMJBMWEOILEJ   = IGPQMWFONTEPRC.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_e2;
/*DEF*/	DataCursor r_e2;
/*SET*/	l_e2 = HDDWEQDOHSPJDG;
/*SET*/	r_e2 = VLZMJBMWEOILEJ;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor RPKSBXEESTGPSM;
/*DEF*/	DataCursor NMALPUSWIBUBAQ;
/*DEF*/	DataCursor VOTCAYTBTUZDTW;
/*SET*/	RPKSBXEESTGPSM = IGPQMWFONTEPRC;
/*INC*/	if (!INC(RPKSBXEESTGPSM, arg_to)) goto sentence_after_5;
//// ISBRACKET 
	if (RPKSBXEESTGPSM.container->type != struct_bracket) goto sentence_after_5;
//// JMP_BRACKET 
	NMALPUSWIBUBAQ = RPKSBXEESTGPSM.container->value.bracket_data.chain->at_before_first();
	VOTCAYTBTUZDTW   = RPKSBXEESTGPSM.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_nn;
/*DEF*/	DataCursor r_nn;
/*SET*/	l_nn = NMALPUSWIBUBAQ;
/*SET*/	r_nn = VOTCAYTBTUZDTW;
//// [ e.1 ] 
/*DEF*/	DataCursor l_hn;
/*DEF*/	DataCursor r_hn;
/*SET*/	l_hn = RPKSBXEESTGPSM;
/*SET*/	r_hn = arg_to;

// подготовка подстановки 
DataChain* SYSJRVRWGIXZHX = new DataChain(); 
DataContainer* SYSJRVRWGIXZHX_execbr = newRefExecBrackets(PolnAnalizEny, SYSJRVRWGIXZHX, "PolnAnalizEny");
result->append(SYSJRVRWGIXZHX_execbr);
SYSJRVRWGIXZHX->append_copy(l_hn, r_hn); 
context->pushExecuteCall(SYSJRVRWGIXZHX_execbr);

return result; 
}
sentence_after_5: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* StepShag(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor WHIUHVQTKJPQZY;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = arg_from;
/*SET*/	WHIUHVQTKJPQZY = arg_from;
/*INC*/	if (!INC(WHIUHVQTKJPQZY, arg_to)) goto sentence_after_1;
	if (! isSymbolType(WHIUHVQTKJPQZY.container->type)) goto sentence_after_1;
/*SET*/	r_A = WHIUHVQTKJPQZY;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor YHHTXMJFMQLFWZ;
/*DEF*/	DataCursor JFQVBENLERLKYA;
/*DEF*/	DataCursor WOLVBTYZGEWXCC;
/*SET*/	YHHTXMJFMQLFWZ = r_A;
/*INC*/	if (!INC(YHHTXMJFMQLFWZ, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (YHHTXMJFMQLFWZ.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	JFQVBENLERLKYA = YHHTXMJFMQLFWZ.container->value.bracket_data.chain->at_before_first();
	WOLVBTYZGEWXCC   = YHHTXMJFMQLFWZ.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor HSWMWGHBBANCUE;
/*SET*/	HSWMWGHBBANCUE = JFQVBENLERLKYA;
/*INC*/	if (!INC(HSWMWGHBBANCUE, WOLVBTYZGEWXCC)) goto sentence_after_1;
	if (HSWMWGHBBANCUE.container->type != text || *(HSWMWGHBBANCUE.container->value.text + HSWMWGHBBANCUE.index) != '1') goto sentence_after_1;
//// [ empty ] 
/*ISEMPTY*/	if (HSWMWGHBBANCUE!=0 && WOLVBTYZGEWXCC != HSWMWGHBBANCUE) goto sentence_after_1;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor YINXFIWFHTLDYT;
/*DEF*/	DataCursor YGQKXRWDVRKCOY;
/*DEF*/	DataCursor TXKCWEAGYDMHRP;
/*SET*/	YINXFIWFHTLDYT = YHHTXMJFMQLFWZ;
/*INC*/	if (!INC(YINXFIWFHTLDYT, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (YINXFIWFHTLDYT.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	YGQKXRWDVRKCOY = YINXFIWFHTLDYT.container->value.bracket_data.chain->at_before_first();
	TXKCWEAGYDMHRP   = YINXFIWFHTLDYT.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = YGQKXRWDVRKCOY;
/*SET*/	r_1 = TXKCWEAGYDMHRP;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor YQUIMWRBVEZZVV;
/*DEF*/	DataCursor JPGIHCYFQZVADT;
/*DEF*/	DataCursor DFYEMFQVYNBDLR;
/*SET*/	YQUIMWRBVEZZVV = YINXFIWFHTLDYT;
/*INC*/	if (!INC(YQUIMWRBVEZZVV, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (YQUIMWRBVEZZVV.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	JPGIHCYFQZVADT = YQUIMWRBVEZZVV.container->value.bracket_data.chain->at_before_first();
	DFYEMFQVYNBDLR   = YQUIMWRBVEZZVV.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = JPGIHCYFQZVADT;
/*SET*/	r_2 = DFYEMFQVYNBDLR;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor QHVAPGYSGGXDOR;
/*DEF*/	DataCursor KVMVQEXPJFGVPI;
/*DEF*/	DataCursor FYIDTTGGSDYJBV;
/*SET*/	QHVAPGYSGGXDOR = YQUIMWRBVEZZVV;
/*INC*/	if (!INC(QHVAPGYSGGXDOR, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (QHVAPGYSGGXDOR.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	KVMVQEXPJFGVPI = QHVAPGYSGGXDOR.container->value.bracket_data.chain->at_before_first();
	FYIDTTGGSDYJBV   = QHVAPGYSGGXDOR.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_n1;
/*DEF*/	DataCursor r_n1;
/*SET*/	l_n1 = KVMVQEXPJFGVPI;
/*SET*/	r_n1 = KVMVQEXPJFGVPI;
/*JMP*/	goto label_OLBMCGBRRVKUPT_firststep;
label_OLBMCGBRRVKUPT: 
/*INC*/	if (!INC(r_n1, FYIDTTGGSDYJBV)) goto sentence_after_1;
label_OLBMCGBRRVKUPT_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor ANLZOSCTFNYSZK;
/*SET*/	ANLZOSCTFNYSZK = r_n1;
 if (!SLIDE(ANLZOSCTFNYSZK, FYIDTTGGSDYJBV, l_A, r_A)) goto label_OLBMCGBRRVKUPT;
//// [ e.1 ] 
/*DEF*/	DataCursor l_n2;
/*DEF*/	DataCursor r_n2;
/*SET*/	l_n2 = ANLZOSCTFNYSZK;
/*SET*/	r_n2 = FYIDTTGGSDYJBV;
//// [ empty ] 
/*ISEMPTY*/	if (QHVAPGYSGGXDOR!=0 && arg_to != QHVAPGYSGGXDOR) goto label_OLBMCGBRRVKUPT;

// подготовка подстановки 
DataChain* LRNZRKUXYJPWWM = new DataChain(); 
DataContainer* LRNZRKUXYJPWWM_execbr = newRefExecBrackets(PolnAnaliz, LRNZRKUXYJPWWM, "PolnAnaliz");
result->append(LRNZRKUXYJPWWM_execbr);
DataChain* INHPLXGXWULGXH = new DataChain(); 
LRNZRKUXYJPWWM->append(newRefStructBrackets(INHPLXGXWULGXH)); 
INHPLXGXWULGXH->append(newRefText("2")); 
DataChain* LMSBZRQUAJUAXP = new DataChain(); 
LRNZRKUXYJPWWM->append(newRefStructBrackets(LMSBZRQUAJUAXP)); 
LMSBZRQUAJUAXP->append_copy(l_1, r_1); 
LMSBZRQUAJUAXP->append_copy(l_A, r_A); 
DataChain* DPSMWIWXXDVIPO = new DataChain(); 
LRNZRKUXYJPWWM->append(newRefStructBrackets(DPSMWIWXXDVIPO)); 
DPSMWIWXXDVIPO->append_copy(l_2, r_2); 
DataChain* UXTLKQWWOWRQEA = new DataChain(); 
LRNZRKUXYJPWWM->append(newRefStructBrackets(UXTLKQWWOWRQEA)); 
UXTLKQWWOWRQEA->append_copy(l_n1, r_n1); 
UXTLKQWWOWRQEA->append_copy(l_n2, r_n2); 
context->pushExecuteCall(LRNZRKUXYJPWWM_execbr);

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ s.1 <any> ] 
/*DEF*/	DataCursor TQBMMILPOXBIPW;
/*DEF*/	DataCursor l_A;
/*DEF*/	DataCursor r_A;
/*SET*/	l_A = arg_from;
/*SET*/	TQBMMILPOXBIPW = arg_from;
/*INC*/	if (!INC(TQBMMILPOXBIPW, arg_to)) goto sentence_after_2;
	if (! isSymbolType(TQBMMILPOXBIPW.container->type)) goto sentence_after_2;
/*SET*/	r_A = TQBMMILPOXBIPW;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor WEGHTFIQJQKBNJ;
/*DEF*/	DataCursor HXDKUNEBQGRIZK;
/*DEF*/	DataCursor EKGERQQLYYFESO;
/*SET*/	WEGHTFIQJQKBNJ = r_A;
/*INC*/	if (!INC(WEGHTFIQJQKBNJ, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (WEGHTFIQJQKBNJ.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	HXDKUNEBQGRIZK = WEGHTFIQJQKBNJ.container->value.bracket_data.chain->at_before_first();
	EKGERQQLYYFESO   = WEGHTFIQJQKBNJ.container->value.bracket_data.chain->at_last();
//// [ `a` <any> ] 
/*DEF*/	DataCursor YKMVAYQBNKSTMD;
/*SET*/	YKMVAYQBNKSTMD = HXDKUNEBQGRIZK;
/*INC*/	if (!INC(YKMVAYQBNKSTMD, EKGERQQLYYFESO)) goto sentence_after_2;
	if (YKMVAYQBNKSTMD.container->type != text || *(YKMVAYQBNKSTMD.container->value.text + YKMVAYQBNKSTMD.index) != '2') goto sentence_after_2;
//// [ empty ] 
/*ISEMPTY*/	if (YKMVAYQBNKSTMD!=0 && EKGERQQLYYFESO != YKMVAYQBNKSTMD) goto sentence_after_2;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor IGMTFBOURZHMFF;
/*DEF*/	DataCursor FSRCBDZDFBEOST;
/*DEF*/	DataCursor FVSKREBTLJHZKR;
/*SET*/	IGMTFBOURZHMFF = WEGHTFIQJQKBNJ;
/*INC*/	if (!INC(IGMTFBOURZHMFF, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (IGMTFBOURZHMFF.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	FSRCBDZDFBEOST = IGMTFBOURZHMFF.container->value.bracket_data.chain->at_before_first();
	FVSKREBTLJHZKR   = IGMTFBOURZHMFF.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = FSRCBDZDFBEOST;
/*SET*/	r_1 = FVSKREBTLJHZKR;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor GHTSGBBDHLSICU;
/*DEF*/	DataCursor TFMMJOUTFVEXDC;
/*DEF*/	DataCursor ZSCHYTBCRKLIWC;
/*SET*/	GHTSGBBDHLSICU = IGMTFBOURZHMFF;
/*INC*/	if (!INC(GHTSGBBDHLSICU, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (GHTSGBBDHLSICU.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	TFMMJOUTFVEXDC = GHTSGBBDHLSICU.container->value.bracket_data.chain->at_before_first();
	ZSCHYTBCRKLIWC   = GHTSGBBDHLSICU.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = TFMMJOUTFVEXDC;
/*SET*/	r_2 = ZSCHYTBCRKLIWC;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor XKGOQVUFYOGVFR;
/*DEF*/	DataCursor NYMOPFWPNFUZEI;
/*DEF*/	DataCursor HXYXANSPRGGWDY;
/*SET*/	XKGOQVUFYOGVFR = GHTSGBBDHLSICU;
/*INC*/	if (!INC(XKGOQVUFYOGVFR, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (XKGOQVUFYOGVFR.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	NYMOPFWPNFUZEI = XKGOQVUFYOGVFR.container->value.bracket_data.chain->at_before_first();
	HXYXANSPRGGWDY   = XKGOQVUFYOGVFR.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_n1;
/*DEF*/	DataCursor r_n1;
/*SET*/	l_n1 = NYMOPFWPNFUZEI;
/*SET*/	r_n1 = NYMOPFWPNFUZEI;
/*JMP*/	goto label_AFAWQGQBTDGFFC_firststep;
label_AFAWQGQBTDGFFC: 
/*INC*/	if (!INC(r_n1, HXYXANSPRGGWDY)) goto sentence_after_2;
label_AFAWQGQBTDGFFC_firststep: 
//// [ &.name <any> ] 
/*DEF*/	DataCursor EGTPCYBQVRQUSQ;
/*SET*/	EGTPCYBQVRQUSQ = r_n1;
 if (!SLIDE(EGTPCYBQVRQUSQ, HXYXANSPRGGWDY, l_A, r_A)) goto label_AFAWQGQBTDGFFC;
//// [ e.1 ] 
/*DEF*/	DataCursor l_n2;
/*DEF*/	DataCursor r_n2;
/*SET*/	l_n2 = EGTPCYBQVRQUSQ;
/*SET*/	r_n2 = HXYXANSPRGGWDY;
//// [ empty ] 
/*ISEMPTY*/	if (XKGOQVUFYOGVFR!=0 && arg_to != XKGOQVUFYOGVFR) goto label_AFAWQGQBTDGFFC;

// подготовка подстановки 
DataChain* SYDYMVPEIBGXFF = new DataChain(); 
DataContainer* SYDYMVPEIBGXFF_execbr = newRefExecBrackets(PolnAnaliz, SYDYMVPEIBGXFF, "PolnAnaliz");
result->append(SYDYMVPEIBGXFF_execbr);
DataChain* NOPFYMRMQHUCGO = new DataChain(); 
SYDYMVPEIBGXFF->append(newRefStructBrackets(NOPFYMRMQHUCGO)); 
NOPFYMRMQHUCGO->append(newRefText("1")); 
DataChain* MDIUXEMXBZYSLV = new DataChain(); 
SYDYMVPEIBGXFF->append(newRefStructBrackets(MDIUXEMXBZYSLV)); 
MDIUXEMXBZYSLV->append_copy(l_1, r_1); 
DataChain* LITWUBNSPBMEWW = new DataChain(); 
SYDYMVPEIBGXFF->append(newRefStructBrackets(LITWUBNSPBMEWW)); 
LITWUBNSPBMEWW->append_copy(l_2, r_2); 
LITWUBNSPBMEWW->append_copy(l_A, r_A); 
DataChain* HGPMPRKCYFDXKM = new DataChain(); 
SYDYMVPEIBGXFF->append(newRefStructBrackets(HGPMPRKCYFDXKM)); 
HGPMPRKCYFDXKM->append_copy(l_n1, r_n1); 
HGPMPRKCYFDXKM->append_copy(l_n2, r_n2); 
context->pushExecuteCall(SYDYMVPEIBGXFF_execbr);

return result; 
}
sentence_after_2: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

DataChain* PolnAnalizEny(DataCursor arg_from, DataCursor arg_to, ExecContext *context){
DataChain *result = new DataChain(); 
DataChain *tmp_chain = new DataChain(); 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor TUHEVOIXRWLMXW;
/*DEF*/	DataCursor GCNOYZMMYOVRTE;
/*DEF*/	DataCursor PQTIBDVTHMPOAQ;
/*SET*/	TUHEVOIXRWLMXW = arg_from;
/*INC*/	if (!INC(TUHEVOIXRWLMXW, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (TUHEVOIXRWLMXW.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	GCNOYZMMYOVRTE = TUHEVOIXRWLMXW.container->value.bracket_data.chain->at_before_first();
	PQTIBDVTHMPOAQ   = TUHEVOIXRWLMXW.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor YDDQRXNVKIYADV;
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = GCNOYZMMYOVRTE;
/*SET*/	YDDQRXNVKIYADV = GCNOYZMMYOVRTE;
/*INC*/	if (!INC(YDDQRXNVKIYADV, PQTIBDVTHMPOAQ)) goto sentence_after_1;
	if (! isSymbolType(YDDQRXNVKIYADV.container->type)) goto sentence_after_1;
/*SET*/	r_s = YDDQRXNVKIYADV;
//// [ empty ] 
/*ISEMPTY*/	if (r_s!=0 && PQTIBDVTHMPOAQ != r_s) goto sentence_after_1;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor LOYEMCYCFCPYUW;
/*DEF*/	DataCursor KZEBCJAEDSBVQQ;
/*DEF*/	DataCursor IJQLGJYCJPKPXF;
/*SET*/	LOYEMCYCFCPYUW = TUHEVOIXRWLMXW;
/*INC*/	if (!INC(LOYEMCYCFCPYUW, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (LOYEMCYCFCPYUW.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	KZEBCJAEDSBVQQ = LOYEMCYCFCPYUW.container->value.bracket_data.chain->at_before_first();
	IJQLGJYCJPKPXF   = LOYEMCYCFCPYUW.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = KZEBCJAEDSBVQQ;
/*SET*/	r_1 = IJQLGJYCJPKPXF;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor LCEONIYVQVURDI;
/*DEF*/	DataCursor AQMSRTFGWTPEPU;
/*DEF*/	DataCursor NUGEAJDGZSJEWS;
/*SET*/	LCEONIYVQVURDI = LOYEMCYCFCPYUW;
/*INC*/	if (!INC(LCEONIYVQVURDI, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (LCEONIYVQVURDI.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	AQMSRTFGWTPEPU = LCEONIYVQVURDI.container->value.bracket_data.chain->at_before_first();
	NUGEAJDGZSJEWS   = LCEONIYVQVURDI.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = AQMSRTFGWTPEPU;
/*SET*/	r_2 = NUGEAJDGZSJEWS;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor QRMJZSSBXJVOTJ;
/*DEF*/	DataCursor VJQCFQPTBZGKET;
/*DEF*/	DataCursor QKITTRHYUBKEWF;
/*SET*/	QRMJZSSBXJVOTJ = LCEONIYVQVURDI;
/*INC*/	if (!INC(QRMJZSSBXJVOTJ, arg_to)) goto sentence_after_1;
//// ISBRACKET 
	if (QRMJZSSBXJVOTJ.container->type != struct_bracket) goto sentence_after_1;
//// JMP_BRACKET 
	VJQCFQPTBZGKET = QRMJZSSBXJVOTJ.container->value.bracket_data.chain->at_before_first();
	QKITTRHYUBKEWF   = QRMJZSSBXJVOTJ.container->value.bracket_data.chain->at_last();
//// [ empty ] 
/*ISEMPTY*/	if (VJQCFQPTBZGKET!=0 && QKITTRHYUBKEWF != VJQCFQPTBZGKET) goto sentence_after_1;
//// [ empty ] 
/*ISEMPTY*/	if (QRMJZSSBXJVOTJ!=0 && arg_to != QRMJZSSBXJVOTJ) goto sentence_after_1;

// подготовка подстановки 

return result; 
}
sentence_after_1: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor EKRCIHHXJEIGUT;
/*DEF*/	DataCursor WIGDBBDXRBWMBR;
/*DEF*/	DataCursor MBVGAOWLVDJYDD;
/*SET*/	EKRCIHHXJEIGUT = arg_from;
/*INC*/	if (!INC(EKRCIHHXJEIGUT, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (EKRCIHHXJEIGUT.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	WIGDBBDXRBWMBR = EKRCIHHXJEIGUT.container->value.bracket_data.chain->at_before_first();
	MBVGAOWLVDJYDD   = EKRCIHHXJEIGUT.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor YCTCOCKMGZVARP;
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = WIGDBBDXRBWMBR;
/*SET*/	YCTCOCKMGZVARP = WIGDBBDXRBWMBR;
/*INC*/	if (!INC(YCTCOCKMGZVARP, MBVGAOWLVDJYDD)) goto sentence_after_2;
	if (! isSymbolType(YCTCOCKMGZVARP.container->type)) goto sentence_after_2;
/*SET*/	r_s = YCTCOCKMGZVARP;
//// [ empty ] 
/*ISEMPTY*/	if (r_s!=0 && MBVGAOWLVDJYDD != r_s) goto sentence_after_2;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor FOBGMHPAOJOIQP;
/*DEF*/	DataCursor QTXTUCRORYSMGT;
/*DEF*/	DataCursor XCFZLBJBIPFIMU;
/*SET*/	FOBGMHPAOJOIQP = EKRCIHHXJEIGUT;
/*INC*/	if (!INC(FOBGMHPAOJOIQP, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (FOBGMHPAOJOIQP.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	QTXTUCRORYSMGT = FOBGMHPAOJOIQP.container->value.bracket_data.chain->at_before_first();
	XCFZLBJBIPFIMU   = FOBGMHPAOJOIQP.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = QTXTUCRORYSMGT;
/*SET*/	r_1 = XCFZLBJBIPFIMU;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor NEZPQAQJASIXVW;
/*DEF*/	DataCursor OQYJVXKHCQPQIA;
/*DEF*/	DataCursor BUBQQDOFEHHJTZ;
/*SET*/	NEZPQAQJASIXVW = FOBGMHPAOJOIQP;
/*INC*/	if (!INC(NEZPQAQJASIXVW, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (NEZPQAQJASIXVW.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	OQYJVXKHCQPQIA = NEZPQAQJASIXVW.container->value.bracket_data.chain->at_before_first();
	BUBQQDOFEHHJTZ   = NEZPQAQJASIXVW.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = OQYJVXKHCQPQIA;
/*SET*/	r_2 = BUBQQDOFEHHJTZ;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor YQKTDMKAPSPBMY;
/*DEF*/	DataCursor KOYLPNZOIPZWDM;
/*DEF*/	DataCursor KRBHDNTDKVPDEL;
/*SET*/	YQKTDMKAPSPBMY = NEZPQAQJASIXVW;
/*INC*/	if (!INC(YQKTDMKAPSPBMY, arg_to)) goto sentence_after_2;
//// ISBRACKET 
	if (YQKTDMKAPSPBMY.container->type != struct_bracket) goto sentence_after_2;
//// JMP_BRACKET 
	KOYLPNZOIPZWDM = YQKTDMKAPSPBMY.container->value.bracket_data.chain->at_before_first();
	KRBHDNTDKVPDEL   = YQKTDMKAPSPBMY.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_3;
/*DEF*/	DataCursor r_3;
/*SET*/	l_3 = KOYLPNZOIPZWDM;
/*SET*/	r_3 = KOYLPNZOIPZWDM;
/*JMP*/	goto label_ORQCJKQZZPINOQ_firststep;
label_ORQCJKQZZPINOQ: 
/*INC*/	if (!INC(r_3, KRBHDNTDKVPDEL)) goto sentence_after_2;
label_ORQCJKQZZPINOQ_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor LUIBJGNQQLFEWI;
/*SET*/	LUIBJGNQQLFEWI = r_3;
/*INC*/	if (!INC(LUIBJGNQQLFEWI, KRBHDNTDKVPDEL)) goto label_ORQCJKQZZPINOQ;
	if (LUIBJGNQQLFEWI.container->type != text || *(LUIBJGNQQLFEWI.container->value.text + LUIBJGNQQLFEWI.index) != '>') goto label_ORQCJKQZZPINOQ;
//// [ empty ] 
/*ISEMPTY*/	if (LUIBJGNQQLFEWI!=0 && KRBHDNTDKVPDEL != LUIBJGNQQLFEWI) goto label_ORQCJKQZZPINOQ;
//// [ empty ] 
/*ISEMPTY*/	if (YQKTDMKAPSPBMY!=0 && arg_to != YQKTDMKAPSPBMY) goto label_ORQCJKQZZPINOQ;

// подготовка подстановки 

return result; 
}
sentence_after_2: 

{
// подготовка предложения 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor FYQYPCHHGFMIZR;
/*DEF*/	DataCursor CKLYHBPJJZRRUG;
/*DEF*/	DataCursor OFLUIOIVOVXMRA;
/*SET*/	FYQYPCHHGFMIZR = arg_from;
/*INC*/	if (!INC(FYQYPCHHGFMIZR, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (FYQYPCHHGFMIZR.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	CKLYHBPJJZRRUG = FYQYPCHHGFMIZR.container->value.bracket_data.chain->at_before_first();
	OFLUIOIVOVXMRA   = FYQYPCHHGFMIZR.container->value.bracket_data.chain->at_last();
//// [ s.1 <any> ] 
/*DEF*/	DataCursor WZSWPFNCNFYTMC;
/*DEF*/	DataCursor l_s;
/*DEF*/	DataCursor r_s;
/*SET*/	l_s = CKLYHBPJJZRRUG;
/*SET*/	WZSWPFNCNFYTMC = CKLYHBPJJZRRUG;
/*INC*/	if (!INC(WZSWPFNCNFYTMC, OFLUIOIVOVXMRA)) goto sentence_after_3;
	if (! isSymbolType(WZSWPFNCNFYTMC.container->type)) goto sentence_after_3;
/*SET*/	r_s = WZSWPFNCNFYTMC;
//// [ empty ] 
/*ISEMPTY*/	if (r_s!=0 && OFLUIOIVOVXMRA != r_s) goto sentence_after_3;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor FVWNRMFZGPZPOL;
/*DEF*/	DataCursor TVNBMVWTHJSVHB;
/*DEF*/	DataCursor XSEWQYCKWEXZPM;
/*SET*/	FVWNRMFZGPZPOL = FYQYPCHHGFMIZR;
/*INC*/	if (!INC(FVWNRMFZGPZPOL, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (FVWNRMFZGPZPOL.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	TVNBMVWTHJSVHB = FVWNRMFZGPZPOL.container->value.bracket_data.chain->at_before_first();
	XSEWQYCKWEXZPM   = FVWNRMFZGPZPOL.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_I;
/*DEF*/	DataCursor r_I;
/*SET*/	l_I = TVNBMVWTHJSVHB;
/*SET*/	r_I = XSEWQYCKWEXZPM;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor IEXGRJXJMDWBQY;
/*DEF*/	DataCursor UIPXARRBPHNZWK;
/*DEF*/	DataCursor BCLGBVOCYUZUTZ;
/*SET*/	IEXGRJXJMDWBQY = FVWNRMFZGPZPOL;
/*INC*/	if (!INC(IEXGRJXJMDWBQY, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (IEXGRJXJMDWBQY.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	UIPXARRBPHNZWK = IEXGRJXJMDWBQY.container->value.bracket_data.chain->at_before_first();
	BCLGBVOCYUZUTZ   = IEXGRJXJMDWBQY.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_Y;
/*DEF*/	DataCursor r_Y;
/*SET*/	l_Y = UIPXARRBPHNZWK;
/*SET*/	r_Y = BCLGBVOCYUZUTZ;
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor YPIROCYYUCCLQZ;
/*DEF*/	DataCursor CXTAWHXKHALPUK;
/*DEF*/	DataCursor JRMGSXOCKDRAAU;
/*SET*/	YPIROCYYUCCLQZ = IEXGRJXJMDWBQY;
/*INC*/	if (!INC(YPIROCYYUCCLQZ, arg_to)) goto sentence_after_3;
//// ISBRACKET 
	if (YPIROCYYUCCLQZ.container->type != struct_bracket) goto sentence_after_3;
//// JMP_BRACKET 
	CXTAWHXKHALPUK = YPIROCYYUCCLQZ.container->value.bracket_data.chain->at_before_first();
	JRMGSXOCKDRAAU   = YPIROCYYUCCLQZ.container->value.bracket_data.chain->at_last();
//// [ e.1 <any> ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = CXTAWHXKHALPUK;
/*SET*/	r_1 = CXTAWHXKHALPUK;
/*JMP*/	goto label_ACXKPMRFLSPDLQ_firststep;
label_ACXKPMRFLSPDLQ: 
/*INC*/	if (!INC(r_1, JRMGSXOCKDRAAU)) goto sentence_after_3;
label_ACXKPMRFLSPDLQ_firststep: 
//// [ `a` <any> ] 
/*DEF*/	DataCursor KEWYQJFTFWAHGQ;
/*SET*/	KEWYQJFTFWAHGQ = r_1;
/*INC*/	if (!INC(KEWYQJFTFWAHGQ, JRMGSXOCKDRAAU)) goto label_ACXKPMRFLSPDLQ;
	if (KEWYQJFTFWAHGQ.container->type != text || *(KEWYQJFTFWAHGQ.container->value.text + KEWYQJFTFWAHGQ.index) != '>') goto label_ACXKPMRFLSPDLQ;
//// [ s.1 <any> ] 
/*DEF*/	DataCursor OHKQNKTTIQFYRH;
/*DEF*/	DataCursor l_sss;
/*DEF*/	DataCursor r_sss;
/*SET*/	l_sss = KEWYQJFTFWAHGQ;
/*SET*/	OHKQNKTTIQFYRH = KEWYQJFTFWAHGQ;
/*INC*/	if (!INC(OHKQNKTTIQFYRH, JRMGSXOCKDRAAU)) goto label_ACXKPMRFLSPDLQ;
	if (! isSymbolType(OHKQNKTTIQFYRH.container->type)) goto label_ACXKPMRFLSPDLQ;
/*SET*/	r_sss = OHKQNKTTIQFYRH;
//// [ e.1 ] 
/*DEF*/	DataCursor l_2;
/*DEF*/	DataCursor r_2;
/*SET*/	l_2 = r_sss;
/*SET*/	r_2 = JRMGSXOCKDRAAU;
//// [ empty ] 
/*ISEMPTY*/	if (YPIROCYYUCCLQZ!=0 && arg_to != YPIROCYYUCCLQZ) goto label_ACXKPMRFLSPDLQ;

// подготовка подстановки 
DataChain* MCIRZFQXOZFCUH = new DataChain(); 
DataContainer* MCIRZFQXOZFCUH_execbr = newRefExecBrackets(Analiz, MCIRZFQXOZFCUH, "Analiz");
result->append(MCIRZFQXOZFCUH_execbr);
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
WJGRJVQSPOOSLA->append(newRefText(">")); 
WJGRJVQSPOOSLA->append_copy(l_sss, r_sss); 
WJGRJVQSPOOSLA->append_copy(l_2, r_2); 
context->pushExecuteCall(MCIRZFQXOZFCUH_execbr);
DataChain* QKXZEHZEGKWUTI = new DataChain(); 
DataContainer* QKXZEHZEGKWUTI_execbr = newRefExecBrackets(PolnAnaliz, QKXZEHZEGKWUTI, "PolnAnaliz");
result->append(QKXZEHZEGKWUTI_execbr);
DataChain* YPZVVZTDURGODX = new DataChain(); 
QKXZEHZEGKWUTI->append(newRefStructBrackets(YPZVVZTDURGODX)); 
YPZVVZTDURGODX->append_copy(l_s, r_s); 
DataChain* VAAHGUIGPSGLHA = new DataChain(); 
QKXZEHZEGKWUTI->append(newRefStructBrackets(VAAHGUIGPSGLHA)); 
VAAHGUIGPSGLHA->append_copy(l_I, r_I); 
DataChain* BNQBWTQMBDSMBF = new DataChain(); 
QKXZEHZEGKWUTI->append(newRefStructBrackets(BNQBWTQMBDSMBF)); 
BNQBWTQMBDSMBF->append_copy(l_Y, r_Y); 
DataChain* ZTHYUMQUOWLDNO = new DataChain(); 
QKXZEHZEGKWUTI->append(newRefStructBrackets(ZTHYUMQUOWLDNO)); 
ZTHYUMQUOWLDNO->append_copy(l_1, r_1); 
ZTHYUMQUOWLDNO->append_copy(l_sss, r_sss); 
ZTHYUMQUOWLDNO->append(newRefText(">")); 
ZTHYUMQUOWLDNO->append_copy(l_2, r_2); 
context->pushExecuteCall(QKXZEHZEGKWUTI_execbr);

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
/*JMP*/	goto label_VUCOIMMQSZMSRZ_firststep;
label_VUCOIMMQSZMSRZ: 
/*INC*/	if (!INC(r_sIY, arg_to)) goto sentence_after_4;
label_VUCOIMMQSZMSRZ_firststep: 
//// [ (<any>) <any> ] 
/*DEF*/	DataCursor QPMADDCVHINJJD;
/*DEF*/	DataCursor FYWRWSDAGMVYQH;
/*DEF*/	DataCursor TQWFYIAISTVHBZ;
/*SET*/	QPMADDCVHINJJD = r_sIY;
/*INC*/	if (!INC(QPMADDCVHINJJD, arg_to)) goto label_VUCOIMMQSZMSRZ;
//// ISBRACKET 
	if (QPMADDCVHINJJD.container->type != struct_bracket) goto label_VUCOIMMQSZMSRZ;
//// JMP_BRACKET 
	FYWRWSDAGMVYQH = QPMADDCVHINJJD.container->value.bracket_data.chain->at_before_first();
	TQWFYIAISTVHBZ   = QPMADDCVHINJJD.container->value.bracket_data.chain->at_last();
//// [ e.1 ] 
/*DEF*/	DataCursor l_1;
/*DEF*/	DataCursor r_1;
/*SET*/	l_1 = FYWRWSDAGMVYQH;
/*SET*/	r_1 = TQWFYIAISTVHBZ;
//// [ empty ] 
/*ISEMPTY*/	if (QPMADDCVHINJJD!=0 && arg_to != QPMADDCVHINJJD) goto label_VUCOIMMQSZMSRZ;

// подготовка подстановки 
DataChain* VROOVJFTEGSKJR = new DataChain(); 
DataContainer* VROOVJFTEGSKJR_execbr = newRefExecBrackets(PolnAnaliz, VROOVJFTEGSKJR, "PolnAnaliz");
result->append(VROOVJFTEGSKJR_execbr);
VROOVJFTEGSKJR->append_copy(l_sIY, r_sIY); 
DataChain* JYNGLSSHITXZGF = new DataChain(); 
VROOVJFTEGSKJR->append(newRefStructBrackets(JYNGLSSHITXZGF)); 
JYNGLSSHITXZGF->append(newRefText(">")); 
JYNGLSSHITXZGF->append_copy(l_1, r_1); 
context->pushExecuteCall(VROOVJFTEGSKJR_execbr);

return result; 
}
sentence_after_4: 

// подготовка к возвращению неуспеха
std::cout << "fail!";
return 0;

}

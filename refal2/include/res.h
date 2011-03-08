#include "direfal.h" 
#include "system.h" 

DataChain* Go(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
//   =  <Begin 100  >
DataChain* Begin(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// 0    =  
// s.n   =  <Prout 'Who is first? (1 - pc  2 - you)' ><FirG <Card >><Begin <- @.n 1  >>
DataChain* FirG(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// '1'   =  <Game ('2' )('1' )('' )('23456789' )>
// '2'   =  <Game ('2' )('' )('' )('123456789' )>
// e.e   =  
DataChain* Game__(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// e.e   =  <Prout Game: @.e ><Game__ @.e >
DataChain* Game(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// (s.g )(e.1  )(e.2  )(e.n )  =  <Ekran (@.1  )(@.2  )><GameIfWin <Ifwin (@.1  )(@.2  )>(@.g )(@.1  )(@.2  )(@.n )>
// e.e   =  
DataChain* GameIfWin(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// '0' e.e ()  =  <Prout 'Nobody !!!.' >
// '1' e.e   =  <Prout 'Winner X' >
// '2' e.e   =  <Prout 'Winner O' >
// '0' e.e   =  <Game1 @.e >
DataChain* Game1__(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// e.e   =  <Prout Game1: @.e ><Game1__ @.e >
DataChain* Game1(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// ('1' )e.12  (e.n )  =  <Prout 'hmm ...' ><Game ('2' )<PlayerHod '1' <GetHod '1' ('1' )@.12  (@.n )>@.12  (@.n )>>
// ('2' )e.12  (e.n )  =  <Game ('1' )<PlayerHod '2' <Prout 'Select number for 0:' ><Card >@.12  (@.n )>>
DataChain* PlayerHod__(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// e.e   =  <Prout PlayerHod: @.e ><PlayerHod__ @.e >
DataChain* PlayerHod(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// '1' s.h (e.1  )(e.2  )(e.n1 @.h e.n2 )  =  <Prout 'step:' @.h >(@.1  @.h )(@.2  )(@.n1 @.n2 )
// '2' s.h (e.1  )(e.2  )(e.n1 @.h e.n2 )  =  <Prout 'step:' @.h >(@.1  )(@.2  @.h )(@.n1 @.n2 )
// e.e   =  
DataChain* GetHod__(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// e.e   =  <Prout GetHod: @.e ><GetHod__ @.e >
DataChain* GetHod(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// s.v e.e (e.not )  =  <UseHod @.v @.e (@.not )(<WriteXO @.e ('>' @.not )>)>
DataChain* UseHod__(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// e.e   =  <Prout UseHod: @.e ><UseHod__ @.e >
DataChain* UseHod(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// e.e ('#' s.s )  =  @.s 
// s.v e.e (e.not )(e.Wr )  =  <UHod (<Switch @.v @.Wr >)(@.Wr )(@.not )>
DataChain* UHod__(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// e.e   =  <Prout UHod: @.e ><UHod__ @.e >
DataChain* UHod(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// (e.Sw )(@.Sw e.Wr )(s.s e.n )  =  @.s 
// (e.Sw )(s.s1 '=' s.s2 e.e @.Sw e.Wr )(s.s e.n )  =  <UHod (@.Sw )(@.e @.Sw @.Wr )(@.n )>
DataChain* Ekran(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// e.1    =  <Prout '*===T===T===*' ><Prout '|' <XO '1' @.1  >'|' <XO '2' @.1  >'|' <XO '3' @.1  >'|' ><Prout '*===I===I===*' ><Prout '|' <XO '4' @.1  >'|' <XO '5' @.1  >'|' <XO '6' @.1  >'|' ><Prout '*===I===I===*' ><Prout '|' <XO '7' @.1  >'|' <XO '8' @.1  >'|' <XO '9' @.1  >'|' ><Prout '*===I===I===*' >
DataChain* XO(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// s.1  (e.21  @.1  e.22  )(e.3  )  =  '-X-' 
// s.1  (e.2  )(e.31  @.1  e.32  )  =  '-O-' 
// s.1  (e.2  )(e.3  )  =  @.1  '  ' 
DataChain* Switch(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// 0    =  
// s.G s.A '=' s.AA   =  @.A '=' @.AA 
// s.G @.G '=' s.AA @.G '=' s.BB e.e   =  <Switch @.G @.G '=' <Maix 'a' @.AA @.BB <Compare @.AA @.BB >>@.e >
// s.G @.G '=' s.AA s.s '=' s.BB e.e   =  <Switch @.G @.G '=' @.AA @.e >
// s.G s.s '=' s.AA @.G '=' s.BB e.e   =  <Switch @.G @.G '=' @.BB @.e >
// s.G s.s '=' s.AA @.s '=' s.BB e.e   =  <Switch @.G @.s '=' <Maix 'i' @.AA @.BB <Compare @.AA @.BB >>@.e >
// e.e   =  <Prout 'Sw unk: ' @.e >
DataChain* Maix(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// 'a' s.A s.B '-'   =  @.B 
// 'a' s.A s.B '+'   =  @.A 
// 'i' s.B s.A '-'   =  @.B 
// 'i' s.B s.A '+'   =  @.A 
// e.e s.A s.zn   =  @.A 
DataChain* WriteXO__(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// e.e   =  <Prout WriteXO: @.e ><WriteXO__ @.e >
DataChain* WriteXO(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
//   =  
// (s.g )(e.1  )(e.2  )(e.n )  =  <WXOif (@.g )(<Strategy @.1  >)(<Strategy @.2  >)(<Strategy @.n >)(@.1  )(@.2  )(@.n )>
DataChain* WXOif__(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// e.e   =  <Prout WXOif: @.e ><WXOif__ @.e >
DataChain* WXOif(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// ('1' )e.eee1 (e.1  s.A e.2  @.A e.3  )e.eee2 (e.n1 @.A e.n2 )(e.e1 )(e.e2 )(e.n )  =  '#' <Lins (@.n )<AntiStrategy @.A >>
// (s.g )e.e (e.1  )(e.2  )(e.n )  =  <WriteXO1 (@.g )(@.1  )(@.2  )(@.n )>
DataChain* Lins__(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// e.e   =  <Prout Lins: @.e ><Lins__ @.e >
DataChain* Lins(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// (e.n1 s.hod e.n2 )e.as1 @.hod e.as2   =  @.hod 
DataChain* AntiStrategy__(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// e.e   =  <Prout AntiStrategy: @.e ><AntiStrategy__ @.e >
DataChain* AntiStrategy(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// '1'   =  '123' 
// '2'   =  '456' 
// '3'   =  '789' 
// '4'   =  '147' 
// '5'   =  '258' 
// '6'   =  '369' 
// '7'   =  '159' 
// '8'   =  '357' 
DataChain* WriteXO1__(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// e.e   =  <Prout WriteXO1: @.e ><WriteXO1__ @.e >
DataChain* WriteXO1(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
//   =  
// e.eee (e.3  '>' )  =  
// (s.g )e.eee (e.3  '>' s.s e.4  )  =  <Length <Optima21 <Analiz (@.g )@.eee (@.3  '>' @.s @.4  )>>><WriteXO (@.g )@.eee (@.3  @.s '>' @.4  )>
DataChain* First1(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// s.1  e.2    =  @.1  
// e.1    =  @.1  
DataChain* Length__(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// e.e   =  <Prout Length: @.e ><Length__ @.e >
DataChain* Length(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// e.1  '12' e.2    =  <DivS <First1 <Lenw @.1  '1' >><First1 <Lenw '2' @.2  >>>
// e.1  '1' e.2    =  '1=' 2000000  
// e.1  '2' e.2    =  '2=' 2000000  
//   =  '1=' 1  
// e.1    =  <Prout 'Length error symbols!!! : ' ><Print @.1  >
DataChain* DivS(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// s.1  s.2    =  <IfDiv <Compare @.1  @.2  >@.1  @.2  >
DataChain* IfDiv(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// '+' s.1  s.2    =  '1=' <Div @.1  @.2  >
// s.zn s.1  s.2    =  '1=' <Div @.2  @.1  >
DataChain* NextPl(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// '1'   =  '2' 
// '2'   =  '1' 
// e.e   =  <Print 'NextPl uncn.: ' @.e >
DataChain* Optima21(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// e.e   =  <Optima211 @.e >
DataChain* Optima211(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// e.1  '1' e.2  '1' e.3    =  '11' <Optima211 @.1  @.3  >@.2  
// e.1  '1' e.2    =  '1' <Optima211 @.1  @.2  >
// e.1    =  @.1  
DataChain* Strategy__(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// e.e   =  <Prout Strategy: @.e ><Strategy__ @.e >
DataChain* Strategy(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
//   =  
// e.1  '1' e.2    =  '147' <Strategy @.1  @.2  >
// e.1  '2' e.2    =  '15' <Strategy @.1  @.2  >
// e.1  '3' e.2    =  '168' <Strategy @.1  @.2  >
// e.1  '4' e.2    =  '24' <Strategy @.1  @.2  >
// e.1  '5' e.2    =  '2578' <Strategy @.1  @.2  >
// e.1  '6' e.2    =  '26' <Strategy @.1  @.2  >
// e.1  '7' e.2    =  '348' <Strategy @.1  @.2  >
// e.1  '8' e.2    =  '35' <Strategy @.1  @.2  >
// e.1  '9' e.2    =  '367' <Strategy @.1  @.2  >
// e.1    =  @.1  
DataChain* Ifwin(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// (e.1  )(e.2  )  =  <Ifwin1 (<Strategy @.1  >)(<Strategy @.2  >)>
DataChain* Ifwin1(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// (e.1  s.A e.2  @.A e.3  @.A e.4  )(e.e )  =  '1' 
// (e.e )(e.1  s.A e.2  @.A e.3  @.A e.4  )  =  '2' 
// (e.1  )(e.2  )  =  '0' 
DataChain* Analiz__(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// e.e   =  <Prout Analiz: @.e ><Analiz__ @.e >
DataChain* Analiz(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// e.1  (e.3  '>' )  =  
// ('1' )(e.1  )(e.2  )(e.3  '>' s.A e.4  )  =  <PolnAnaliz ('2' )(@.1  @.A )(@.2  )(@.3  @.4  )>
// ('2' )(e.1  )(e.2  )(e.3  '>' s.A e.4  )  =  <PolnAnaliz ('1' )(@.1  )(@.2  @.A )(@.3  @.4  )>
// e.e   =  <Prout 'No point: ' @.e >
DataChain* PolnAnaliz__(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// e.e   =  <Prout PolnAnaliz: @.e ><PolnAnaliz__ @.e >
DataChain* PolnAnaliz(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// (s.g )(e.1  )(e.2  )(e.n )  =  <Ifmust (<Strategy @.1  >)(<Strategy @.2  >)(<Strategy @.n >)(@.g )(@.1  )(@.2  )(@.n )>
DataChain* Ifmust__(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// e.e   =  <Prout Ifmust: @.e ><Ifmust__ @.e >
DataChain* Ifmust(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// (e.e1 )(e.e21 s.A e.e22 @.A e.e23 )(e.nn1 @.A e.nn2 )('2' )e.e1e2 (e.n )  =  '2' 
// (e.e21 s.A e.e22 @.A e.e23 )(e.e1 )(e.nn1 @.A e.nn2 )('1' )e.e1e2 (e.n )  =  '1' 
// (e.e1 )(e.e21 s.A e.e22 @.A e.e23 )(e.nn1 @.A e.nn2 )('1' )e.e1e2 (e.n )  =  <StepShag <Lins (@.n )<AntiStrategy @.A >>('1' )@.e1e2 (@.n )>
// (e.e21 s.A e.e22 @.A e.e23 )(e.e1 )(e.nn1 @.A e.nn2 )('2' )e.e1e2 (e.n )  =  <StepShag <Lins (@.n )<AntiStrategy @.A >>('2' )@.e1e2 (@.n )>
// (e.e1 )(e.e2 )(e.nn )e.hn   =  <PolnAnalizEny @.hn >
DataChain* StepShag(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// s.A ('1' )(e.1  )(e.2  )(e.n1 @.A e.n2 )  =  <PolnAnaliz ('2' )(@.1  @.A )(@.2  )(@.n1 @.n2 )>
// s.A ('2' )(e.1  )(e.2  )(e.n1 @.A e.n2 )  =  <PolnAnaliz ('1' )(@.1  )(@.2  @.A )(@.n1 @.n2 )>
DataChain* PolnAnalizEny(DataCursor arg_from, DataCursor arg_to, ExecContext *context);
// (s.s )(e.1  )(e.2  )()  =  
// (s.s )(e.1  )(e.2  )(e.3  '>' )  =  
// (s.s )(e.I )(e.Y )(e.1  '>' s.sss e.2  )  =  <Analiz (@.s )(@.I )(@.Y )(@.1  '>' @.sss @.2  )><PolnAnaliz (@.s )(@.I )(@.Y )(@.1  @.sss '>' @.2  )>
// e.sIY (e.1  )  =  <PolnAnaliz @.sIY ('>' @.1  )>
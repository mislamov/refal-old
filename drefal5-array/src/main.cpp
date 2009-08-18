#include <iostream>

#include "kernel\symbols.h"
#include "kernel\session.h"
#include "kernel\variables.h"

using namespace std;

int main() {
    Session *sess = new Session();

    RefChain chain1, chain2;
	ChainSubstitution chain3;

	RefData_DOT *dot1 = new RefData_DOT();
	RefStructBracket * brack1 = new RefStructBracket();
	RefStructBracket * brack2 = new RefStructBracket();
	RefStructBracket * brack3 = new RefStructBracket();
	

	chain1 += brack2;
	chain1 += brack2;
	chain1 += brack1;
    chain1 += new RefAlpha('A');
	chain1 += brack1;

	chain1 += new RefAlpha('B');
    chain1 += new RefAlpha('C');
    chain1 += new RefAlpha('D');
    chain1 += new RefAlpha('E');
    chain1 += new RefAlpha('F');
    chain1 += new RefAlpha('C');
    chain1 += new RefAlpha('D');
    chain1 += new RefAlpha('F');

	chain2 += dot1;
    chain2 += new RefVariable_e("e1");
	chain2 += new RefVariable_e("e2");
	chain2 += brack3;
	chain2 += new RefVariable_s("s3");
	chain2 += brack3;
	chain2 += new RefVariable_e("e4");
    chain2 += new RefLinkToVariable("e2", &chain2);;
    chain2 += new RefVariable_e("e5");

    //chain2 += new RefAlpha('A');
	//chain2 += new RefAlpha('C');
    //chain2 += new RefAlpha('D');
	chain2 += dot1;

	chain3 += new RefAlpha('X');
	chain3 += new RefLinkToVariable("e2", &chain2);
	chain3 += new RefLinkToVariable("e5", &chain2);
	chain3 += new RefAlpha('Y');


    std::cout << chain1.toString() << "\n";
    std::cout << chain2.toString() << "\n";
    std::cout << chain3.toString() << "\n";

	//RefChain chain3(chain1.first+1, chain1.first+2);
	//std::cout << chain3.toString() << "\n";
	//chain1+=chain2;
	//std::cout << chain1.toString() << "\n";

	

    if (sess->matching(&chain1, &chain2, chain1.get_first(), chain1.get_last(), false, false)){
        LOG("TRUE");
		sess->showDebugInfo();

		RefChain *chain4 = sess->substituteExpression(&chain3);
		if (chain4) {
			LOG("RESULT: " << chain4->toString())
		}else {
			LOG("FAIL construct");
		}
    } else {
        LOG("FALSE");
    }
    return 0;
}

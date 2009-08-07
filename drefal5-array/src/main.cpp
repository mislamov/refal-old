#include <iostream>

#include "kernel\symbols.h"
#include "kernel\session.h"
#include "kernel\variables.h"

using namespace std;

int main() {
    Session *sess = new Session();

    RefChain chain1, chain2;



    chain1 += new RefAlpha('[');
    chain1 += new RefAlpha('A');
    chain1 += new RefAlpha('B');
    chain1 += new RefInteger(315);
    chain1 += new RefAlpha('D');

    chain2 += new RefAlpha('A');
    chain2 += new RefVariable_e("1");
//    chain2 += new RefAlpha('C');
    chain2 += new RefAlpha('D');

    std::cout << chain1.toString() << "\n";
    std::cout << chain2.toString() << "\n";

//    RefChain chain3(chain1.first+1, chain1.first+2);
//    std::cout << chain3.toString() << "\n";
//    chain1+=chain2;
//    std::cout << chain1.toString() << "\n";

    if (sess->matching(&chain1, &chain2, chain1.get_first(), chain1.get_last(), false, false)){
        LOG("TRUE");
    } else {
        LOG("FALSE");
    }

    return 0;
}

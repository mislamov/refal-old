
#include "system.h"
#include "../kernel/rfunction.h"
#include "../kernel/data.h"
#include "../kernel/kernel.h"
#include "../kernel/refsymbolbase.hxx"


RefChain* Dec (RefData* beg, RefData* end, Session* s){
    RefInteger *a = dynamic_cast<RefInteger *>(beg);
    RefInteger *b = dynamic_cast<RefInteger *>(end);
    if (beg->next != end){
        RUNTIMEERROR("Dec", "error arguments");
        return 0;
    };
    std::cout << "\n\nDec: " << a->getValue() << "-" << b->getValue() ;
    a = new RefInteger(a->getValue() - b->getValue());
    std::cout << " = " << a->getValue();
    return new RefChain(a, a);
};

RefChain* Div (RefData* beg, RefData* end, Session* s){
    RefInteger *a = dynamic_cast<RefInteger *>(beg);
    RefInteger *b = dynamic_cast<RefInteger *>(end);
    if (beg->next != end){
        RUNTIMEERROR("Div", "error arguments");
        return 0;
    };
    std::cout << "\n\nDiv: " << a->getValue() << " / " << b->getValue() ;
    RefReal* c = new RefReal((float)a->getValue() / b->getValue());
    std::cout << " = " << c->getValue();
    return new RefChain(c, c);
};


RefChain* Sum (RefData* beg, RefData* end, Session* s){
    infint thesum = 0;
    RefInteger *a;
    std::cout << "\n\nSum: ";
    while(beg != end->next){
        a = dynamic_cast<RefInteger *>(beg);
        if (! a){
            RUNTIMEERROR("Sum", "error arguments");
            return 0;
        }
        thesum += a->getValue();
        std::cout << a->getValue() << ", ";
        move_to_next_point(beg, 0, s);
    }

    std::cout << a->getValue() << " = " << thesum ;
    a = new RefInteger(thesum);
    return new RefChain(a, a);
};


RefChain* Mul (RefData* beg, RefData* end, Session* s){
    infint thesum = 1;
    RefInteger *a;
    std::cout << "\n\nMul: ";
    while(beg != end->next){
        a = dynamic_cast<RefInteger *>(beg);
        if (! a){
            RUNTIMEERROR("Mul", "error arguments");
            return 0;
        }
        thesum *= a->getValue();
        std::cout << a->getValue() << " * ";
        move_to_next_point(beg, 0, s);
    }
    a = new RefInteger(thesum);
    std::cout << " = " << thesum;
    return new RefChain(a, a);
};




RefChain* Card (RefData* beg, RefData* end, Session* s){
    if (beg) {
        RUNTIMEERROR("Card", "Not empty args in Card : " << vectorToString(beg, end));
        return 0;
    }
    unistring sline; /// todo LOCALE
    std::string text = "";
    //std::cin >>  text;
    std::getline(std::cin, text);

    RefChain *rch = new RefChain();

    //for (size_t i=0; i<text.length(); i++){
    for (size_t i=0; i<text.length(); i++){
        *rch += new RefAlpha(text[i]);
    }
    return rch;
}


bool  system_DEC::eval(RefData* lft, RefData* rht, RefChain* &result, Session* s){
    result = Dec(lft, rht, s);
    if (result) return true;
    return false;
};

bool  system_DIV::eval(RefData* lft, RefData* rht, RefChain* &result, Session* s){
    result = Div(lft, rht, s);
    if (result) return true;
    return false;
};

bool system_MUL::eval(RefData* lft, RefData* rht, RefChain* &result, Session* s){
    result = Mul(lft, rht, s);
    if (result) return true;
    return false;
};

bool system_SUM::eval(RefData* lft, RefData* rht, RefChain* &result, Session* s){
    result = Sum(lft, rht, s);
    if (result) return true;
    return false;
};

bool system_CARD::eval(RefData* lft, RefData* rht, RefChain* &result, Session* s){
    result = Card(lft, rht, s);
    if (result) return true;
    return false;
};

bool system_PROUT::eval(RefData* lft, RefData* rht, RefChain* &result, Session* s){
    std::cout << "\n############################### STDOUT ###############################\n"
            << ":####\t\t" << vectorToString(lft, rht)
            << "\n######################################################################\n";
    return true;
};

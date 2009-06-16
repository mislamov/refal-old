
#include <iostream>
#include <sstream>

#define unistring std::string
#define SYSTEMERROR(s) { std::cerr << "\nERROR: " << s << std::flush; }

using namespace std;

class RefData {
public:
    double data;
    RefData(double d) {
        //std::cout << "\n+\n";
        data = d;
    };
    ~RefData() {};
    virtual unistring toString() {
        stringstream s;
        s << data << " ";
        return s.str();
    };

};

class RefDataBig : public RefData {
public:
    float data2;
    RefDataBig(float d2, double d) : RefData(d) {
        data2 = d2;
    };
    virtual unistring toString() {
        stringstream s;
        s << data << "+" << data2 << " ";
        return s.str();
    };
};

class Session;

class RefChain {
    size_t leng;

    bool theProtect;

public:
    RefData** first;
    RefData** after;

    void noProtectOnly(){
        if (! theProtect) return;
        std::cerr << "\nPROTECT!\n" << std::flush;
        abort();
    };

    void clear(){ noProtectOnly(); free(first); }; // уничтожение всего что ммежду first и second включительно
    ~RefChain() {};

    RefChain(RefData **l=0, RefData **r=0);

    RefChain& operator+=(RefChain &ch); // к левому аргумент пристыковываетс€ копи€ правого!
    RefChain& operator+=(RefData *ch);  // рефдата ѕќ√Ћјўј≈“—я цепочкой!!!
    RefChain* Copy(Session *s =0);

    virtual unistring toString();
    unistring explode(); // голый текст без форматировани€
};

int main() {

    RefChain chain1, chain2;

    chain1 += new RefData('A');
    chain1 += new RefData('B');
    chain1 += new RefDataBig(3.15, 'C');
    chain1 += new RefData('D');

    chain2 += new RefData('a');
    chain2 += new RefData('b');
    chain2 += new RefData('c');
    chain2 += new RefData('d');

    std::cout << chain1.toString() << "\n";
    std::cout << chain2.toString() << "\n";

    RefChain chain3(chain1.first+1, chain1.first+2);
    std::cout << chain3.toString() << "\n";

    chain1+=chain2;

    std::cout << chain1.toString() << "\n";

    return 0;
};


RefChain::RefChain(RefData **l, RefData **r) {
    #ifdef TESTCODE
    co::chaincount++;
    #endif
    if (!l) {
        theProtect = false;
        first = 0;
        after = r;
        leng = 0;
    } else {
        theProtect = true;
        first  = l;
        leng = r-l+1;
    }
};


RefChain& RefChain::operator+=(RefData *ch) {
    noProtectOnly();

    #ifdef TESTCODE
    if (!this->second) SYSTEMERROR("bad chain!");
    #endif

    if (! this->first && !this->after) {
        first = (RefData**)malloc( sizeof(RefData*) );
        if (!first) std::cerr << "NO MEMORY";
        memcpy(first, &ch, sizeof(RefData*));
        leng = 1;
        return *this;
    }


    first   =  (RefData**) realloc(first, (++leng)*sizeof(RefData*));

    if (! this->first) {
        std::cerr << "\nNO MEMORY !";
    }
    memcpy(first+leng-1, &ch, sizeof(RefData*));

    return *this;
};


unistring RefChain::toString() {
    unistring result = "";
    for (size_t i=0; i<leng; i++) {
        result += first[i]->toString();
    }
    return result;
};


RefChain& RefChain::operator+=(RefChain &ch) {
    noProtectOnly();

    if (! ch.first) return *this; // пустой вектор не прибавл€ем

    if (! this->first) { // прибавл€ем к пустому вектору.
        this->first = ch.first;
        this->leng  = ch.leng;
        return *this;
    }

    first = (RefData**) realloc(first, (leng+ch.leng)*sizeof(RefData*));
    memcpy(first+leng, ch.first, ch.leng*sizeof(RefData*));

    leng += ch.leng;
    return *this;
};


RefChain* RefChain::Copy(Session *s){
    if (!first) return new RefChain();

    SYSTEMERROR("zaglushka");

    RefData **pend = first+leng, **piter = first;



};
//*/


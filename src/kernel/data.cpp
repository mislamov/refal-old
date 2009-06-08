// D-Refal - sentential program language
// Copyright (C) 2008-2009 Islamov Marat Shamilevich
// islamov.marat@gmail.com
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

#include "data.h"
#include "datastructs.h"
#include "kernel.h"
#include "session.h"

#include <stdlib.h>
#include <iostream>


RefObject::RefObject(){
    #ifdef TESTCODE
    co::ocount++;
    #endif
};
RefObject::~RefObject(){
    #ifdef TESTCODE
    co::ocount--;
    #endif
    };


RefData::RefData(RefData *pr) : RefObject() { // создаемся после pr
    this->isSystem = false;
    #ifdef TESTCODE
    co::datacount++;
    #endif

	is_system (true);
//	is_symbol = true;
    if (pr) {
        this->next = pr->next;
        this->pred = pr;
        if (pr->next){
            pr->next->pred = this;
        }
        pr->next = this;
    } else {
        this->next = this->pred = 0;
    }
}

RefData::~RefData(){
    #ifdef TESTCODE
    co::datacount--;
    #endif
    if (next) next->pred = pred;
    if (pred) pred->next = next;
};

RefData*  RefData::next_term( ThisId ThisId, Session *s) {
    return next;
};
RefData*  RefData::pred_term( ThisId ThisId, Session *s) {
    return pred;
};



RefData* RefData::predInsert(RefData *whom){
    whom->next = this;
    whom->pred = this->pred;
    if (this->pred) this->pred->next = whom;
    this->pred = whom;
    return whom;
};
RefData* RefData::afterInsert(RefData *whom){
    whom->next = this->next;
    whom->pred = this;
    if (this->next) this->next->pred = whom;
    this->next = whom;
    return whom;
};

/*
RefData*  RefData::take_copy ( ThisId ThisId) {
    return this;
}
; // возвращает копию если новый создатель
RefData*  RefData::take_copy_force ( ThisId ThisId) {
    return this;
}
; // возвращает копию - независимо от создателя
void       RefData::drop   ( ThisId ThisId) {
    return;
};
*/


//////////////////////////////////////////////////////////////////

TResult RefData::init(RefData*&tpl, Session* s, RefData *&, RefData *&) {
    SYSTEMERROR("unexpected called for " << toString());
    return ERROR;
}

TResult RefData::back(RefData*&tpl,Session* s, RefData *&, RefData *&) {
    SYSTEMERROR("unexpected called for " << toString());
    return ERROR;
}


RefBracketBase::RefBracketBase( RefData *rp) : RefData(rp){ // открывающая
    other = 0;
    is_opened = true;
    is_system (false);
};




/*
RefData* RefBracketBase::Copy( RefData *rp){ // открывающая
    return new RefBracketBase(rp, getName());
};
*/
RefBracketBase::RefBracketBase( RefBracketBase *dr, RefData *rp) : RefData(rp){ // закрывающая
        other = dr;
        is_opened = false;
        dr->other = this;
        is_system (false);
//        if (name == EmptyUniString) { /*name == other->getName();*/ }
};


bool RefBracketBase::isOpen(){
    return is_opened;
};

RefBracketBase * RefBracketBase::getOther(){
    return other;
};

bool   RefBracketBase::operator==(RefData &rd){ return false; };

RefData*  RefBracketBase::beginOfTerm(){ return (isOpen()?this:getOther()); };
RefData*  RefBracketBase::endOfTerm () { return (isOpen()?getOther():this); };

//TResult RefBracketBase::init(RefData*&tpl,Session* s, RefData *&){ SYSTEMERROR(" RefBracketBase::init zagluska!"); };
//TResult RefBracketBase::back(RefData*&tpl,Session* s, RefData *&, RefData *&){ SYSTEMERROR(" RefBracketBase::back zagluska!"); };







// only for ObjectExpressions !!! Возвращает копию цепочки. Вместо ссылок на переменные - значения. Так как применяется для правых частей
// то открытых переменных быть не должно!
RefChain* RefChain::Copy(Session *s){
    //#ifdef DEBUG
    //std::cout << "\n{ RefChain for copy: " << std::flush << this->toString() << std::flush;
    //#endif
    RefData  *srcL = this->first;
    RefData  *srcR = this->second;

    if (!srcL) {
        return new RefChain(0, 0);
    }
    #ifdef TESTCODE
        if (!srcL)
            SYSTEMERROR("trying to take a Copy of empty Chian: this->first=NULL");
        if (!srcR)
            SYSTEMERROR("trying to take a Copy of empty Chian: this->second=NULL");
    #endif

    RefChain  *hlpChain, *hlpChain2, *newChain = new RefChain(new RefNULL());
    RefData *src = srcL;
    RefData *a, *b, *dstHlp, *dst = newChain->first;


    while(src != srcR->next_term(0,0)){ /// todo: когда будут монтированные данные - добавить сессию

        RefLinkToVariable *tmplnk = ref_dynamic_cast<RefLinkToVariable >(src);


        #ifdef TESTCODE
        if (ref_dynamic_cast<RefVariable >(src)) SYSTEMERROR("unexpected variable in RefChain::Copy : "<<src->toString());
        if(!s && tmplnk) SYSTEMERROR("UNEXPECTED LINK to variable when Copy: " << tmplnk->toString());
        #endif


        if (s && tmplnk){
            TVarBody *tbody = s->getVarBody( tmplnk->getName() );
            if (tmplnk->getPath() != EmptyUniString){
                    tbody = tbody->folowByWay(tmplnk->getPath());
            }
            //#ifdef TESTCODE ///todo: когда препроцессор будет определять корявые ссылки правых частей предложений, раскомментировать
            if (!tbody ) {
                s->showStatus(); SYSTEMERROR("VAR BODY NOT FOUND for " << tmplnk->toString());
            }
            //#endif
            if (!(tbody->first)){
                //src = move_to_next_term(src, 0, 0);
                MOVE_TO_NEXT_TERM(src, 0, 0);
                continue;
            };
            RefChain *ch = RefChain(tbody->first, tbody->second).Copy();
            dst->next = ch->first;
            ch->first->pred = dst;
            dst = ch->second;
            delete ch;
            //move_to_next_term(src, 0, 0);
            MOVE_TO_NEXT_TERM(src, 0, 0);
            continue;
        }

        RefBracketBase *br = ref_dynamic_cast<RefBracketBase >(src);
        if (br){ // копируем скобки
            #ifdef TESTCODE
            if (! br->isOpen()){
                SYSTEMERROR("unexpected closed bracket : " << br->toString());
            }
            #endif
            dst     = br->Copy(dst);      // это NULLDOT
            //dstHlp  =  (br->Copy( ref_dynamic_cast<RefBracketBase *>(dst->pred), dst)); // other, rp    }
            dstHlp  =  (br->Copy( (RefBracketBase *)(dst->pred), dst)); // other, rp    }


            #ifdef TESTCODE
            if (!br->other) SYSTEMERROR("br->other == NULL  br=" << br->toString());
            if (!br->next ) SYSTEMERROR("br->next == NULL  br=" << br->toString());
            if (!br->next->next) SYSTEMERROR("br->next->next == NULL  br->next="  << br->next->toString());
            #endif


            if (br->next->next != br->other) { // не пустые скобки
                hlpChain  = new RefChain(br->next->next, br->other->pred);
                hlpChain2 = hlpChain->Copy(s);
                // тут нельзя удалять содержимое цепочки - так как тут же постоянный шаблон функции!
                delete hlpChain;
                // теперь в hlpChain2 нужная подцепь
                a = hlpChain2->first;
                b = hlpChain2->second;
                delete hlpChain2;

                if (!a){
                    /// пустая цепь
                    /// todo проанализировать и проверить нужны ли эти 2 строки
                    dst->next = dstHlp;
                    dstHlp->pred = dst;
                } else {
                    /// цепь не пуста
                    a->pred = dst;
                    dst->next = a;
                    b->next = dstHlp;
                    dstHlp->pred = b;
                }
            }
            dst = dstHlp;
            src = br->other;

        } else {
            dst = src->Copy(dst);
        }
        //src = move_to_next_term(src, 0, s);
        MOVE_TO_NEXT_TERM(src, 0, s);
    }
    newChain->second = dst;

    if( dst == newChain->first){ // пустая
        delete dst;
        newChain->first = newChain->second = 0;
    } else {
        // уходим от RefNULL в начале цепочки
        newChain->first = newChain->first->next;
        // удаляем RefNULL в начале цепочки
        delete newChain->first->pred;
        ///newChain->first->pred = 0;
    }

    //std::cout << "\n} RefChain::Copy() return " << (newChain->first->pred? newChain->first->pred->toString() : "0") << " <- " <<  newChain->toString() << " -> " << (newChain->second->next? newChain->second->next->toString() : "0");

    return newChain;

}

void RefChain::clear(){
        //std::cout << "\n\n---RefChain::clear() - zaglushka---: " << this->toString() << "\n\n" << std::flush;
        delChain(first, second);
        return;
};


RefChain& RefChain::operator+=(RefData *ch){
            //std::cout << "\n\n"; print_vector(this->first); std::cout << " + "; print_vector(ch);
            if (! this->first && !this->second){
                    first = second = ch;
                    return *this;
            }

#ifdef TESTCODE
            if ((this->first->pred) || (ch->next) || (this->second->next) || (ch->pred)){
                SYSTEMERROR("not nulled outboards of summed chain and [" << ch->toString() << "]");
            }
#endif
            RefChain *a = this;//->Copy();
            //std::cout << "\n[  copy a: "; print_vector(a->first); std::cout << "]  ";
            RefData *b = ch;//->Copy();
            //std::cout << "\n[  copy b: "; print_vector(b->first); std::cout << "]  ";
            a->second->next = b;
            b->pred  = a->second;
            a->second  =  b;

            //std::cout << "\n\n = "; print_vector(a->first);

            return *a;
};

RefChain& RefChain::operator+=(RefChain &ch){
            //std::cout << "\n\n"; print_vector(this->first); std::cout << " + "; print_vector(ch.first);
#ifdef TESTCODE
            if ((this->first && this->first->pred) || (ch.second && ch.second->next) || (this->second && this->second->next) || (ch.first && ch.first->pred)){
                SYSTEMERROR("not nulled outboards of summed chains!");
                //return 0;
            }
#endif
            if (! ch.first) return *this; // пустой вектор не прибавляем
            if (! this->first){ // прибавляем к пустому вектору.
                RefChain *cop = ch.Copy();
                if (! this->second) {
                    this->first  = cop->first;
                    this->second = cop->second;
                    delete cop;
                    return *this;
                }
                this->second->next = cop->first;
                if (cop->first) cop->first->pred = this->second;
                this->second = cop->second;
                delete cop;
                return *this;
            }

            RefChain *b = ch.Copy();
            this->second->next = b->first;
            if (b->first) b->first->pred  = this->second;
            this->second  =  b->second;
            //b->first = b->second = 0; // на всякий случай
            delete b;
            //std::cout << "\n\n = "; print_vector(this->first);

            return *this;
};



RefChain::RefChain(RefData *l, RefData *r){
    #ifdef TESTCODE
        co::chaincount++;
    #endif
        if (!l){
            first = 0;
            second = r;
        } else {
            first  = l;
            second = (r?r:l);
        }
};

RefChain::~RefChain(){
    #ifdef TESTCODE
    co::chaincount--;
    #endif
};


RefChain* RefChain::aroundByDots(){
    RefData * l =  this->first;
    RefData * r =  this->second;
    //std::cout << "\ninitializationTemplate::\t" << tpl->toString();

    #ifdef TESTCODE
    if (dynamic_cast<RefData_DOT *>(l) || dynamic_cast<RefData_DOT *>(r)){
        SYSTEMERROR(" situation : l or r already DataDOTs !");
    }
    #endif
    // снабжаем область зрения датадотами
    RefData_DOT *leftd = new RefData_DOT();
    RefData_DOT *rightd = new RefData_DOT(leftd, 0);
    if (l) {
        #ifdef TESTCODE
        if (!r) SYSTEMERROR("!r && l  !!! l="<<l<< " r="<<r);
        #endif
        l->predInsert(leftd);
        r->afterInsert(rightd);
    } else {
        if (r){
            r->afterInsert(leftd);
            leftd->afterInsert(rightd);
        } else {
            leftd->afterInsert( rightd );
        }
    }
    this->first = leftd;
    this->second = rightd;

    return this;
};


RefChain* RefChain::dearoundByDots(){

    #ifdef TESTCODE
    if (! first || ! second || !dynamic_cast<RefData_DOT *>(first) || !dynamic_cast<RefData_DOT *>(second) || !(first->next) || !(second->pred)) {
        SYSTEMERROR("polezrenija ne emeet vida  DOT[ - ... - ]DOT libo narusheni ssilki next-pred!!!");
    }
    #endif

    RefData *d1 = first, *d2=second; // сохраняем доты для удаления

    if (first->next == second){ // если пустое поле зрения  dot[ <-> dot]
        if (first  ->pred) first  ->pred->next = second ->next;
        if (second ->next) second ->next->pred = first  ->pred;
        second = first->pred;
        first = 0;
    } else {    // не пустое поле зрения  dot[ - ... - ]dot
        /*if (first  ->next) */ first  ->next->pred = first  ->pred;
        /*if (second ->pred) */ second ->pred->next = second ->next;
        if (first  ->pred) first  ->pred->next = first  ->next;
        if (second ->next) second ->next->pred = second ->pred;
        first  = first->next;
        second = second->pred;
    }

    d1  ->next = d1  ->pred = d2 ->next = d2 ->pred = 0; // обрубаем ссылки дот чтоб безопасно их удалить, иначе ссылки выровняются
    delete d1;
    delete d2;

    return this;
}
////////////////////////////////////////////
//


RefNULL::RefNULL(RefData *pr) : RefData(pr) {
    is_system (true);
};
bool RefNULL::operator==(RefData&) {
    return false;
};



RefData*  RefNULL::Copy(RefData *d) {
    return new RefNULL(d);
}

TResult RefNULL::init(RefData*&tpl, Session* s, RefData *&, RefData *&){
    SYSTEMERROR("RefNULL::init() tring!");
};
TResult RefNULL::back(RefData*&tpl, Session* s, RefData *&, RefData *&){
    LOG("vremenno RefNULL::back - potom produmat kak ubrat Ref_NULL iz skobok voobshe!");
    tpl=tpl->getPred();
    return BACK;
    SYSTEMERROR("RefNULL::RefNULL() tring!");
};






unistring RefLinkToVariable::toString(){
    std::ostringstream s;
    s << "[LNK::name=" << getName() << "/" << getPath() << "]." << (long)this ;
    return s.str();
};

bool RefLinkToVariable::operator==(RefData&){
    return false;
};


TResult RefLinkToVariable::init(RefData*&tpl,Session* s, RefData *&l, RefData *&r){

    TVarBody *pd  = s->getVarBody( getName() ) ; /// todo: ссылки
    if (getPath() != EmptyUniString){
        // поиск подпути
        pd = pd->folowByWay(getPath());
    }

    if ( !pd ) {
        SYSTEMERROR("INTERNAL ERROR: link to not exists variable: " << getName());
        return ERROR;
    };

    RefData
        *ldata = pd->first,
        *rdata = pd->second;

    if (!ldata ) {
        tpl = tpl->getNext();
        return GO; // ссылка на пустой отрезок - верна
    }

    MOVE_TO_NEXT_TERM(r, 0, s);
    if (r/*->myid()*/==ldata/*->myid()*/){ // сопоставление с собой
        r = rdata;
        tpl = tpl->getNext();
        return GO;
    }

    RefData *lend = rdata;
    MOVE_TO_NEXT_TERM(lend, 0/*myid()*/, s); // граница сравнения

    MOVE_TO_PRED_TERM(r, 0/*myid()*/, s); /// todo: оптимизировать
    while ((ldata!=lend) /*&& !(ldata->dynamic_same(rdata))*/) { // проверка на конец сравниваемого
        MOVE_TO_NEXT_TERM(r, 0/*myid()*/, s);
        if ( !(*r == *ldata)) {
            tpl=tpl->getPred();
            return BACK;
        }

        MOVE_TO_NEXT_TERM(ldata, 0/*myid()*/, s);
    };
    tpl = tpl->getNext();
    return GO;
};

TResult RefLinkToVariable::back(RefData*&tpl,Session* s, RefData *&currentRight, RefData *&currentLeft){
    tpl=tpl->getPred();
    return BACK;
};
RefData*  RefLinkToVariable::Copy(RefData* where){
    return new RefLinkToVariable(getName(), where);
};

RefLinkToVariable::RefLinkToVariable(unistring name, RefData *rp) : RefData(rp) {
    setName(name);
    is_system (false);
};





unistring RefChain::toString(){ return vectorToString(first, second); };
unistring RefChain::explode() { return vectorExplode(first, second); };


/// todo: оптимизировать грязный код
void delChain(RefData*a, RefData*b){
    //std::cout << "\ndelChain: " << vectorToString(a, b) << "\n";
//return;
    if (!a && !b) return;
    //if (!a) return;
    #ifdef TESTCODE
    if ((!a && b)) SYSTEMERROR("Delete Chain error: !a && b, b=" << b->toString());
    #endif

    if (a->pred) {
        a->pred->next = 0;
    }
    a->pred = 0;
    if (b) {
        if (b->next) {
            b->next->pred = 0;
        }
        b->next = 0;
    }
    while (a->next){
       a = a->next;
       delete a->pred;
    }
    delete a;
};



RefVariable::~RefVariable(){
    #ifdef TESTCODE
    co::varcount--;
    #endif
    };
RefVariable::RefVariable(unistring name, RefData *rp) : RefVariableBase(rp) {
    #ifdef TESTCODE
    co::varcount++;
    #endif

    is_system (false);
    setName(name);
    };




RefData*  move_to_next_term(RefData* &point, ThisId id, Session *s) {
    #ifdef TESTCODE
    if (!point) SYSTEMERROR("point is null");
    //if (!(s->subChainFrom) && !(s->subChainTo)) SYSTEMERROR("subChain links not set!!!");
    #endif

    while ((point = point->next_term(id, s)) && point->is_system());
    //do point = point->next_term(id, s);
    //while (point && point->is_system());
    return point;
};

RefData*  move_to_pred_term(RefData* &point, ThisId id, Session *s) {
    #ifdef TESTCODE
    if (!point) SYSTEMERROR("point is null");
    //if (!s->subChainFrom && !s->subChainTo) SYSTEMERROR("subChain links not set!!!");
    #endif

    do point = point->pred_term(id, s);
    while (point && point->is_system());
    return point;
};




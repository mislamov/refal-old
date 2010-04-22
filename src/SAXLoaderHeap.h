#include "DiRefal.h"

class LoaderHeap {
        std::map<unistring, std::stack<RefObject*> > stackstags;

    public:
        std::stack<RefChain *>  stckChains;

		RefUserModule *currentModule;
		RefProgram    *currentProgram;
		RefUserCondition*  currentCondition;
        std::stack<unistring >  activeTag;
        unistring currentchars;
        unistring templateOrSent;


        RefObject *extractValueFromStack(unistring name){
            std::stack<RefObject*>  &svalue   = stackstags[name];
            //std::cout << "\n--stackstags["<<name<<"]("<< stackstags[name].size() <<")" << std::flush;
            #ifdef TESTCODE
            if (svalue.empty()) SYSTEMERRORn("unexpected extracter query: " << name);
            #endif
            RefObject* value = svalue.top();
            //std::cout << "\n--extractValueFromStack["<<name<<"]::" << value->toString();
            svalue.pop();
            //std::cout << "\n"<< "--stackstags["<<name<<"].count="<< (stackstags[name].size()) <<"\n";
            return value;
        }
        RefObject *getValueFromStack(unistring name){
            std::stack<RefObject*>  &svalue   = stackstags[name];
            //std::cout << "\n~~getValueFromStack[" << name << "] " << stackstags[name].size() << std::flush;
            //std::cout << "\n~~getValueFromStack[" << name << "] " << svalue.size() << std::flush;
            #ifdef TESTCODE
            //std::cout << "\nsvalue.size()==" << svalue.size() << "   svalue.size()==0:" << bool(svalue.size()==0);
            if ( svalue.size()==0 )
                SYSTEMERRORn("unexpected extracter query: " << name << std::flush);
            #endif
            RefObject* value = svalue.top();
            //svalue.pop();
            //std::cout << "\n~~getValueFromStack::" << value->toString();
            //std::cout << "\n"<< "~~stackstags["<<name<<"].count="<< (stackstags[name].size()) <<"\n";
            return value;
        }
        void createChainToStack(){
            stckChains.push(new RefChain(0));
        }
		void createSubstitutionToStack(){
			stckChains.push(new RefChain(0));
        }
		void createPatternToStack(){
			stckChains.push(new RefChain(0));
        }

        RefChain* extractCurrChainFromStack(){
            #ifdef TESTCODE
            if (stckChains.empty()) SYSTEMERRORn("tring extract from empty stckChains");
            #endif
            RefChain *r = stckChains.top();
            stckChains.pop();
            return r;
        }
        RefChain* getCurrChain(){
			if (stckChains.size()==0) SYSTEMERRORn("stckChains stack is empty");
            return stckChains.top();
        }

		RefObject* putValueToStack(unistring name, RefObject* o){
            /** /
            std::cout<<"\n++putValueToStack(";
            std::cout<<name;
            std::cout<<", ";
            std::cout<<(long)o;
            std::cout << o->toString();
            std::cout << ")";// */
            stackstags[name].push(o);
            //std::cout << "\n"<< "++stackstags["<<name<<"].count="<< (stackstags[name].size()) <<"\n";
            return o;
        }
        void setChars(unistring ch){
            currentchars = ch;
        }
        unistring getChars(){
            return currentchars + (currentchars="");
        }


        //RefData *getNewEmptyRefSymbolByTypeName(unistring);
        RefVariable *getVariableByTypename(unistring vtype, unistring vname);


        LoaderHeap(RefUserModule *m, RefProgram *p){
            currentModule  = m;
			currentProgram = p;
        };
};

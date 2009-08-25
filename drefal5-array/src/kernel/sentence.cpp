#include "sentence.h"
#include "program.h"


unistring RefCondition::toString() {
        std::ostringstream s;
        s << " @Condition/" << (isReverse?"$not$":"") <<  (ref_dynamic_cast<RefUserFunction>(own)?"F":"T") << "$" << rightPart->toString() << "::" << leftPart->toString() << ' ';
        return s.str();
}
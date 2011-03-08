#ifndef commands_h
#define commands_h

#include "direfal.h"

bool INC (DataCursor &l, DataCursor r);
bool SLIDE(DataCursor &curr, const DataCursor end, DataCursor l, const DataCursor r);

#endif

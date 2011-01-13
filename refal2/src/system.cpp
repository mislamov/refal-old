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
#include <fstream>
//#include <stdlib>
//#include <stdlib.h>
#include <time.h>

#include "system.h"




DataChain* Dec  (DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Div  (DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Mul  (DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Sum  (DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };

DataChain* Mod  (DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Trunc(DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Round(DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Symb (DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Chr (DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Ord (DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* First (DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Last (DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Lower (DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Upper (DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* StdLog (DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Time (DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Mu (DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };


DataChain* Numb (DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  }; // строку в число
DataChain* Lenw (DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Compare (DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  }; // Сравнивает два терма (по перегруженному оператору > или ==)
DataChain* Implode (DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Explode (DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* ExplodeAll (DataCursor beg, DataCursor end){ SYSTEMERRORn("NYR"); };

DataChain* Add   (DataCursor prebeg, DataCursor end){
	++prebeg;
	DataChain *result = new DataChain();
	DataContainerValue value;
	value.num = prebeg.container->value.num;

	for (DataCursor i=prebeg+1, iend=end+1; i!=iend; ++i){
		if (i.container->type!=integer){
			SYSTEMERRORn("Function Add: bad argument!");
		}
		value.num += i.container->value.num;
	}

	result->append(new DataContainer(integer, value));
	return result; 
}

DataChain* Sub   (DataCursor prebeg, DataCursor end){ 
	++prebeg;
	if (prebeg.container->type!=integer || end.container->type!=integer || prebeg.container->next!=end.container){
		SYSTEMERRORn("Function Sub: bad arguments! ");
	}

	DataChain *result = new DataChain();
	DataContainerValue value;
	value.num = prebeg.container->value.num - end.container->value.num;
	result->append(new DataContainer(integer, value));
	return result; 
};

DataChain* Mount (DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* File  (DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Args  (DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Card  (DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };

DataChain* Prout (DataCursor beg, DataCursor end){  
	std::cout << chain_to_text(beg, end) << '\n';
	return 0;
};

DataChain* ProutDebug (DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* StdErr(DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Print (DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Exit  (DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };

DataChain* RandomIdName(DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };

DataChain* RefalTokens  (DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* PrintStackTrace   (DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Eval  (DataCursor beg, DataCursor end){  SYSTEMERRORn("NYR");  };



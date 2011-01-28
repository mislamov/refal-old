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

extern int debug;


DataChain* Dec  (DataCursor prebeg, DataCursor end){  
	return Sub(prebeg, end);  
};

DataChain* Div  (DataCursor prebeg, DataCursor end){  
	++prebeg;
	if (prebeg+1 != end) RUNTIMEERRORn("2 arguments expected");
	if (prebeg.container->type != end.container->type)  RUNTIMEERRORn("different types arguments");
	if (prebeg.container->type != integer)  RUNTIMEERRORn("2 integers expected");
	return (new DataChain())->append(newRefInteger( prebeg.container->value.num / end.container->value.num ));
};

DataChain* Mul  (DataCursor prebeg, DataCursor end){  
	++prebeg;
	if (prebeg+1 != end) RUNTIMEERRORn("2 arguments expected");
	if (prebeg.container->type != end.container->type)  RUNTIMEERRORn("different types arguments");
	if (prebeg.container->type != integer)  RUNTIMEERRORn("2 integers expected");
	return (new DataChain())->append(newRefInteger( prebeg.container->value.num * end.container->value.num ));
};

DataChain* Sum  (DataCursor prebeg, DataCursor end){  
	return Add(prebeg, end);
};

DataChain* Mod  (DataCursor prebeg, DataCursor end){  
	++prebeg;
	if (prebeg+1 != end) RUNTIMEERRORn("2 arguments expected");
	if (prebeg.container->type != end.container->type)  RUNTIMEERRORn("different types arguments");
	if (prebeg.container->type != integer)  RUNTIMEERRORn("2 integers expected");
	return (new DataChain())->append(newRefInteger( prebeg.container->value.num % end.container->value.num ));
};

DataChain* Trunc(DataCursor prebeg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Round(DataCursor prebeg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Symb (DataCursor prebeg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Chr (DataCursor prebeg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Ord (DataCursor prebeg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* First (DataCursor prebeg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Last (DataCursor prebeg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Lower (DataCursor prebeg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Upper (DataCursor prebeg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* StdLog (DataCursor prebeg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Time (DataCursor prebeg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Mu (DataCursor prebeg, DataCursor end){  SYSTEMERRORn("NYR");  };


DataChain* Numb (DataCursor prebeg, DataCursor end){  SYSTEMERRORn("NYR");  }; // строку в число

DataChain* Lenw (DataCursor prebeg, DataCursor end){  
	DataChain *result = new DataChain();
	if (prebeg==end) return result->append(newRefInteger(0));
	++prebeg;
	if (prebeg.container==end.container){
		return result->append(newRefInteger( end.index-prebeg.index+1 ));
	}

	infint lenw = 0;
	if (prebeg.index > 0){
		lenw += (prebeg.container->leng - prebeg.index);
		prebeg.next_container();
	}

	while (prebeg.container!=end.container){
		lenw += prebeg.container->leng;
		prebeg.next_container();
	}

	lenw += (end.index+1);

	return result->append(newRefInteger( lenw ));
};

inline unistring thecompare(infint a, infint b){
	return (a==b)?"0":(a>b?"+":"-");
};

DataChain* Compare (DataCursor prebeg, DataCursor end){   // Сравнивает два терма (по перегруженному оператору > или ==)
	++prebeg;
	if (prebeg+1 != end) RUNTIMEERRORn("2 arguments expected");
	if (prebeg.container->type != end.container->type)  RUNTIMEERRORn("different types arguments");
	if (prebeg.container->type != integer)  RUNTIMEERRORn("2 integers expected");
	return (new DataChain())->append(newRefText( thecompare(prebeg.container->value.num, end.container->value.num) ));
};
DataChain* Implode (DataCursor prebeg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Explode (DataCursor prebeg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* ExplodeAll (DataCursor prebeg, DataCursor end){ SYSTEMERRORn("NYR"); };

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

DataChain* Mount (DataCursor prebeg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* File  (DataCursor prebeg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Args  (DataCursor prebeg, DataCursor end){  SYSTEMERRORn("NYR");  };

inline unistring readline(std::istream &strm){
	unistring s;
	std::getline(strm, s);
	return s;
}

DataChain* Card  (DataCursor prebeg, DataCursor end){  
	if (prebeg != end) RUNTIMEERRORn("unexpected argument");
	
	unistring str = readline(std::cin);
	if (str.length()==0) return std::cin.eof() ? (new DataChain())->append(newRefInteger(0)) : 0;

	/*DataContainerValue value;
	size_t len = str.length();
	unichar *line = new unichar[len];
	strncpy(line, str.c_str(), len);
	value.text = line;
	DataChain *result = (new DataChain())->append(new DataContainer(text, value, len));*/

	DataChain *result = new DataChain();
	result->append( newRefText(str) );
	if (std::cin.eof()){
		result->append( newRefInteger(0) );
	}

	return result;
};

DataChain* Prout (DataCursor prebeg, DataCursor end){  
	std::cout << chain_to_text(prebeg, end) << '\n' << std::flush;
	return 0;
};

DataChain* ProutDebug (DataCursor prebeg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* StdErr(DataCursor prebeg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Print (DataCursor prebeg, DataCursor end){  
	if (prebeg==end) return 0;
	DataChain *chain = new DataChain();
	chain->append_copy(prebeg+1, end);
	std::cout << chain_to_text(prebeg, end) << '\n' << std::flush;
	return chain;
};
DataChain* Exit  (DataCursor prebeg, DataCursor end){  SYSTEMERRORn("NYR");  };

DataChain* RandomIdName(DataCursor prebeg, DataCursor end){  SYSTEMERRORn("NYR");  };

DataChain* RefalTokens  (DataCursor prebeg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* PrintStackTrace   (DataCursor prebeg, DataCursor end){  SYSTEMERRORn("NYR");  };
DataChain* Eval  (DataCursor prebeg, DataCursor end){  SYSTEMERRORn("NYR");  };

DataChain* DebugStart(DataCursor prebeg, DataCursor end){ debug = 1; return 0; }
DataChain* DebugStop(DataCursor prebeg, DataCursor end){ debug = 0; return 0; }

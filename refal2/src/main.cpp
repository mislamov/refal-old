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

#include "direfal.h"

#include <ctime>
#include <iostream>
#include <fstream>

std::string stringtime(struct tm *timeptr)
{
	char result[256];
	strftime(result, 255, "%H:%M", timeptr);
	return result;
}

void help(char *pname)
{
	std::cout << REFVERSION << "\n" << std::flush;
	std::cout << "Usage: "<< pname <<" [-h|--help] [-v|--verbose] [-d|--debug] filename [arg1 arg2 ... argN]\n" << std::flush;
	std::cout << "\t-h (or --help) to see this message\n" << std::flush;
	std::cout << "\t-v (or --verbose) to see more information about program execution\n" << std::flush;
	std::cout << "\t-d (or --debug) to loging debug information into *.debug file\n" << std::flush;
	std::cout << "\t--createxml to create compiled *.xml file of program\n" << std::flush;
}



extern DataChain* Go(DataCursor arg_from, DataCursor arg_to);
extern DataChain* FN(DataCursor arg_from, DataCursor arg_to);

//*
DataCursor findExec (DataChain *ch)
{
	//std::cout << ch->debug() << "\n" << std::flush;

	if (!ch || ch->isEmpty()) return 0;
	for (
		DataCursor i=ch->at_first(),
		iend=ch->at_after_last();
	i!=iend;
	++i)
	{
		if (i.container->type != exec_bracket && i.container->type != struct_bracket) continue;

		// <...>
		if (i.container->type == exec_bracket){
			DataCursor bb = findExec((DataChain*)i.container->value.bracket_data.chain);
			if (!bb) return i;
			return bb;
		}

		// (...)
		DataCursor bb = findExec((DataChain*)i.container->value.bracket_data.chain);
		if (bb!=0) return bb;
	}

	return 0;
}
//*/
int debug = 0;

int main ( int , char **)
{
	ExecContext execContext;
	DataChain *ch = text_to_chain("");

	DataChain* result = Go(ch->at_before_first(), ch->at_last());
    DataCursor b = 0, bb = 0;

	while (true)
	{
		if (debug)
			std::cout << (result ? result->debug() : "null") << "\n";

        if (bb!=0){
            b = bb;
        } else {
            b = findExec(result);
        }
		if (!b) break;

		ref_assert( b.container->type == exec_bracket );
		BracketData  exb = b.container->value.bracket_data;
		ch = exb.fn(exb.chain->at_before_first(), exb.chain->at_last());
		bb = findExec(ch);

		//if (ch) std::cout << ch->debug() << "\n";

		b.replaceBy( ch );

		//delete result; // опусташенная цепочка
		//delete b.container->value.bracket_data.chain; // <...>
		//delete b.container; // <...>
		//std::cout << (result ? result->debug() : "null") << "\n\n\n";
	}

	std::getchar();
	return 0;
}

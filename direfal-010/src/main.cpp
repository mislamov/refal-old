// DiRefal - sentential program language
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

int main ( int argv, char **argc ) {
	RefProgram *program = new RefProgram();
	Session *sess = new Session();

	RefChain *ch1 = new RefChain();
	RefChain *ch2 = new RefChain();
	RefChain *ch3 = new RefChain();
	RefChain *ch4 = new RefChain();

	ch3 = textToChain("xyz");
	ch4 = textToChain("x");
	*ch4 += new RefVariable_t("yyy");
	*ch4 += textToChain("z");

	ch1 = textToChain("Ab");
	*ch1 += RefChain::makeStructTerm( ch3 );
	*ch1 += textToChain("cde");

	*ch2 += new RefVariable_e("1");
	*ch2 += new RefVariable_s("yy");
	//*ch2 += new RefVariable_e("2");
	*ch2 += new RefAlpha('c');
	*ch2 += new RefAlpha('d');
	*ch2 += new RefAlpha('e');

	std::cout << "\n\n" ;
	std::cout << ch1->debug() << "\n";
	std::cout << ch2->debug() << "\n";
	std::cout << "\n\n" ;


	sess->createVarMap();
	if (sess->matching(0, ch2, ch1, false)){
		std::cout << "TRUE\n";
	} else {
		std::cout << "FALSE\n";
	}

	return 0;
}
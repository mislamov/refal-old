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
#ifndef MODULE_SDK_H_INCLUDED
#define MODULE_SDK_H_INCLUDED



#define BEGIN_DLL_MODULE(mod_name, class_name) \
	class class_name : public RefDllModule {	\
	public:	\
		std::map<unistring, RefData*(*)(unistring)> dataConstructors;	\
		unistring getName(){ return mod_name; };	\
		unistring explode(){SYSTEMERROR("unrelised");}; \
		class_name() : RefDllModule() {




#define DEFINE_MODULE_FUNCTION(func) \
class rf_module_##func : public RefBuildInFunction { \
	public: \
	rf_module_##func() : RefBuildInFunction(){ LOG("new " << getName()); } \
		virtual ~rf_module_##func(){ LOG("delete " << getName()); };  \
		unistring explode(){ return "$" #func ; };  \
		unistring getName(){ return #func; };  \
		RefChain* eval(RefData** fr, RefData** to, Session* s){ return func(fr, to, s); };		\
	};  \
	setObjectByName(#func,  new rf_module_##func());



#define DEFINE_MODULE_FUNCTION_ALIAS(alias, func) \
	setObjectByName(#alias,  getObjectByName(#func));


#define END_DLL_MODULE   };};



#endif

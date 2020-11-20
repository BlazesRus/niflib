/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/NiTFixedStringMap.h"
#include "../../include/gen/NiTFixedStringMapItem.h"
using namespace Niflib;

//Constructor
NiTFixedStringMap::NiTFixedStringMap() : numStrings((unsigned int)0) {};

//Copy Constructor
NiTFixedStringMap::NiTFixedStringMap( const NiTFixedStringMap & src ) {
	*this = src;
};

//Copy Operator
NiTFixedStringMap & NiTFixedStringMap::operator=( const NiTFixedStringMap & src ) {
	this->numStrings = src.numStrings;
	this->strings = src.strings;
	return *this;
};

//Destructor
NiTFixedStringMap::~NiTFixedStringMap() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

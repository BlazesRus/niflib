/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/StringPalette.h"
using namespace Niflib;

//Constructor
StringPalette::StringPalette() : length((unsigned int)0) {};

//Copy Constructor
StringPalette::StringPalette( const StringPalette & src ) {
	*this = src;
};

//Copy Operator
StringPalette & StringPalette::operator=( const StringPalette & src ) {
	this->palette = src.palette;
	this->length = src.length;
	return *this;
};

//Destructor
StringPalette::~StringPalette() {};

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//

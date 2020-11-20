/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/SizedString16.h"
using namespace Niflib;

//Constructor
SizedString16::SizedString16() : length((unsigned short)0) {};

//Copy Constructor
SizedString16::SizedString16( const SizedString16 & src ) {
	*this = src;
};

//Copy Operator
SizedString16 & SizedString16::operator=( const SizedString16 & src ) {
	this->length = src.length;
	this->value = src.value;
	return *this;
};

//Destructor
SizedString16::~SizedString16() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

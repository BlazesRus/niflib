/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/Region.h"
using namespace Niflib;

//Constructor
Region::Region() : startIndex((unsigned int)0), numIndices((unsigned int)0) {};

//Copy Constructor
Region::Region( const Region & src ) {
	*this = src;
};

//Copy Operator
Region & Region::operator=( const Region & src ) {
	this->startIndex = src.startIndex;
	this->numIndices = src.numIndices;
	return *this;
};

//Destructor
Region::~Region() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/ConstraintInfo.h"
using namespace Niflib;

//Constructor
ConstraintInfo::ConstraintInfo() {};

//Copy Constructor
ConstraintInfo::ConstraintInfo( const ConstraintInfo & src ) {
	*this = src;
};

//Copy Operator
ConstraintInfo & ConstraintInfo::operator=( const ConstraintInfo & src ) {
	this->pivotInA = src.pivotInA;
	this->pivotInB = src.pivotInB;
	return *this;
};

//Destructor
ConstraintInfo::~ConstraintInfo() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

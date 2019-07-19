/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/NxSpringDesc.h"
using namespace Niflib;

//Constructor
NxSpringDesc::NxSpringDesc() : spring(0.0f), damper(0.0f), targetValue(0.0f) {};

//Copy Constructor
NxSpringDesc::NxSpringDesc( const NxSpringDesc & src ) {
	*this = src;
};

//Copy Operator
NxSpringDesc & NxSpringDesc::operator=( const NxSpringDesc & src ) {
	this->spring = src.spring;
	this->damper = src.damper;
	this->targetValue = src.targetValue;
	return *this;
};

//Destructor
NxSpringDesc::~NxSpringDesc() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

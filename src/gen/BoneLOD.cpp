/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/BoneLOD.h"
using namespace Niflib;

//Constructor
BoneLOD::BoneLOD() : distance((unsigned int)0) {};

//Copy Constructor
BoneLOD::BoneLOD( const BoneLOD & src ) {
	*this = src;
};

//Copy Operator
BoneLOD & BoneLOD::operator=( const BoneLOD & src ) {
	this->distance = src.distance;
	this->boneName = src.boneName;
	return *this;
};

//Destructor
BoneLOD::~BoneLOD() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

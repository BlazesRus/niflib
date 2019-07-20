/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/BSSkinBoneTrans.h"
#include "../../include/gen/NiBound.h"
using namespace Niflib;

//Constructor
BSSkinBoneTrans::BSSkinBoneTrans() : scale(0.0f) {};

//Copy Constructor
BSSkinBoneTrans::BSSkinBoneTrans( const BSSkinBoneTrans & src ) {
	*this = src;
};

//Copy Operator
BSSkinBoneTrans & BSSkinBoneTrans::operator=( const BSSkinBoneTrans & src ) {
	this->boundingSphere = src.boundingSphere;
	this->rotation = src.rotation;
	this->translation = src.translation;
	this->scale = src.scale;
	return *this;
};

//Destructor
BSSkinBoneTrans::~BSSkinBoneTrans() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/BSTreadTransform.h"
#include "../../include/gen/NiQuatTransform.h"
using namespace Niflib;

//Constructor
BSTreadTransform::BSTreadTransform() {};

//Copy Constructor
BSTreadTransform::BSTreadTransform( const BSTreadTransform & src ) {
	*this = src;
};

//Copy Operator
BSTreadTransform & BSTreadTransform::operator=( const BSTreadTransform & src ) {
	this->name = src.name;
	this->transform1 = src.transform1;
	this->transform2 = src.transform2;
	return *this;
};

//Destructor
BSTreadTransform::~BSTreadTransform() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

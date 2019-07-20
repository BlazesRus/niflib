/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/NxJointLimitSoftDesc.h"
using namespace Niflib;

//Constructor
NxJointLimitSoftDesc::NxJointLimitSoftDesc() : value(0.0f), restitution(0.0f), spring(0.0f), damping(0.0f) {};

//Copy Constructor
NxJointLimitSoftDesc::NxJointLimitSoftDesc( const NxJointLimitSoftDesc & src ) {
	*this = src;
};

//Copy Operator
NxJointLimitSoftDesc & NxJointLimitSoftDesc::operator=( const NxJointLimitSoftDesc & src ) {
	this->value = src.value;
	this->restitution = src.restitution;
	this->spring = src.spring;
	this->damping = src.damping;
	return *this;
};

//Destructor
NxJointLimitSoftDesc::~NxJointLimitSoftDesc() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

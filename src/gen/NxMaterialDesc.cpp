/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/NxMaterialDesc.h"
#include "../../include/gen/NxSpringDesc.h"
using namespace Niflib;

//Constructor
NxMaterialDesc::NxMaterialDesc() : dynamicFriction(0.0f), staticFriction(0.0f), restitution(0.0f), dynamicFrictionV(0.0f), staticFrictionV(0.0f), flags((NxMaterialFlag)0), frictionCombineMode((NxCombineMode)0), restitutionCombineMode((NxCombineMode)0), hasSpring(false) {};

//Copy Constructor
NxMaterialDesc::NxMaterialDesc( const NxMaterialDesc & src ) {
	*this = src;
};

//Copy Operator
NxMaterialDesc & NxMaterialDesc::operator=( const NxMaterialDesc & src ) {
	this->dynamicFriction = src.dynamicFriction;
	this->staticFriction = src.staticFriction;
	this->restitution = src.restitution;
	this->dynamicFrictionV = src.dynamicFrictionV;
	this->staticFrictionV = src.staticFrictionV;
	this->directionOfAnisotropy = src.directionOfAnisotropy;
	this->flags = src.flags;
	this->frictionCombineMode = src.frictionCombineMode;
	this->restitutionCombineMode = src.restitutionCombineMode;
	this->hasSpring = src.hasSpring;
	this->spring = src.spring;
	return *this;
};

//Destructor
NxMaterialDesc::~NxMaterialDesc() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/PhysXMaterialRef.h"
#include "../../include/obj/NiPhysXMaterialDesc.h"
using namespace Niflib;

//Constructor
PhysXMaterialRef::PhysXMaterialRef() : key((unsigned short)0), materialDesc(NULL) {};

//Copy Constructor
PhysXMaterialRef::PhysXMaterialRef( const PhysXMaterialRef & src ) {
	*this = src;
};

//Copy Operator
PhysXMaterialRef & PhysXMaterialRef::operator=( const PhysXMaterialRef & src ) {
	this->key = src.key;
	this->materialDesc = src.materialDesc;
	return *this;
};

//Destructor
PhysXMaterialRef::~PhysXMaterialRef() {};

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//

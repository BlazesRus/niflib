/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/PhysXClothAttachmentPosition.h"
using namespace Niflib;

//Constructor
PhysXClothAttachmentPosition::PhysXClothAttachmentPosition() : vertexId((unsigned int)0), flags((unsigned int)0) {};

//Copy Constructor
PhysXClothAttachmentPosition::PhysXClothAttachmentPosition( const PhysXClothAttachmentPosition & src ) {
	*this = src;
};

//Copy Operator
PhysXClothAttachmentPosition & PhysXClothAttachmentPosition::operator=( const PhysXClothAttachmentPosition & src ) {
	this->vertexId = src.vertexId;
	this->position = src.position;
	this->flags = src.flags;
	return *this;
};

//Destructor
PhysXClothAttachmentPosition::~PhysXClothAttachmentPosition() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/PhysXClothAttachment.h"
#include "../../include/gen/PhysXClothAttachmentPosition.h"
#include "../../include/obj/NiPhysXShapeDesc.h"
using namespace Niflib;

//Constructor
PhysXClothAttachment::PhysXClothAttachment() : shape(NULL), numVertices((unsigned int)0), flags((unsigned int)0) {};

//Copy Constructor
PhysXClothAttachment::PhysXClothAttachment( const PhysXClothAttachment & src ) {
	*this = src;
};

//Copy Operator
PhysXClothAttachment & PhysXClothAttachment::operator=( const PhysXClothAttachment & src ) {
	this->shape = src.shape;
	this->numVertices = src.numVertices;
	this->flags = src.flags;
	this->positions = src.positions;
	return *this;
};

//Destructor
PhysXClothAttachment::~PhysXClothAttachment() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/NiQuatTransform.h"
using namespace Niflib;

//Constructor
NiQuatTransform::NiQuatTransform() : scale(1.0f) {};

//Copy Constructor
NiQuatTransform::NiQuatTransform( const NiQuatTransform & src ) {
	*this = src;
};

//Copy Operator
NiQuatTransform & NiQuatTransform::operator=( const NiQuatTransform & src ) {
	this->translation = src.translation;
	this->rotation = src.rotation;
	this->scale = src.scale;
	this->trsValid = src.trsValid;
	return *this;
};

//Destructor
NiQuatTransform::~NiQuatTransform() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

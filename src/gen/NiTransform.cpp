/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/NiTransform.h"
using namespace Niflib;

//Constructor
NiTransform::NiTransform() : scale(1.0f) {};

//Copy Constructor
NiTransform::NiTransform( const NiTransform & src ) {
	*this = src;
};

//Copy Operator
NiTransform & NiTransform::operator=( const NiTransform & src ) {
	this->rotation = src.rotation;
	this->translation = src.translation;
	this->scale = src.scale;
	return *this;
};

//Destructor
NiTransform::~NiTransform() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/MorphWeight.h"
#include "../../include/obj/NiInterpolator.h"
using namespace Niflib;

//Constructor
MorphWeight::MorphWeight() : interpolator(NULL), weight(0.0f) {};

//Copy Constructor
MorphWeight::MorphWeight( const MorphWeight & src ) {
	*this = src;
};

//Copy Operator
MorphWeight & MorphWeight::operator=( const MorphWeight & src ) {
	this->interpolator = src.interpolator;
	this->weight = src.weight;
	return *this;
};

//Destructor
MorphWeight::~MorphWeight() {};

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//

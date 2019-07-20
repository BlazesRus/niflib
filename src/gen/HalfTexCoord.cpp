/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/HalfTexCoord.h"
using namespace Niflib;

//Constructor
HalfTexCoord::HalfTexCoord() : u((hfloat)0), v((hfloat)0) {};

//Copy Constructor
HalfTexCoord::HalfTexCoord( const HalfTexCoord & src ) {
	*this = src;
};

//Copy Operator
HalfTexCoord & HalfTexCoord::operator=( const HalfTexCoord & src ) {
	this->u = src.u;
	this->v = src.v;
	return *this;
};

//Destructor
HalfTexCoord::~HalfTexCoord() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

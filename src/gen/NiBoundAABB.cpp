/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/NiBoundAABB.h"
using namespace Niflib;

//Constructor
NiBoundAABB::NiBoundAABB() : numCorners((unsigned short)2) {};

//Copy Constructor
NiBoundAABB::NiBoundAABB( const NiBoundAABB & src ) {
	*this = src;
};

//Copy Operator
NiBoundAABB & NiBoundAABB::operator=( const NiBoundAABB & src ) {
	this->numCorners = src.numCorners;
	this->corners = src.corners;
	return *this;
};

//Destructor
NiBoundAABB::~NiBoundAABB() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

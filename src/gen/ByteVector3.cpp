/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/ByteVector3.h"
using namespace Niflib;

//Constructor
ByteVector3::ByteVector3() : x((byte)0), y((byte)0), z((byte)0) {};

//Copy Constructor
ByteVector3::ByteVector3( const ByteVector3 & src ) {
	*this = src;
};

//Copy Operator
ByteVector3 & ByteVector3::operator=( const ByteVector3 & src ) {
	this->x = src.x;
	this->y = src.y;
	this->z = src.z;
	return *this;
};

//Destructor
ByteVector3::~ByteVector3() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

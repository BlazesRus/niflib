/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/ByteColor3.h"
using namespace Niflib;

//Constructor
ByteColor3::ByteColor3() : r((byte)0), g((byte)0), b((byte)0) {};

//Copy Constructor
ByteColor3::ByteColor3( const ByteColor3 & src ) {
	*this = src;
};

//Copy Operator
ByteColor3 & ByteColor3::operator=( const ByteColor3 & src ) {
	this->r = src.r;
	this->g = src.g;
	this->b = src.b;
	return *this;
};

//Destructor
ByteColor3::~ByteColor3() {};

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//

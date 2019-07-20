/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/ByteColor4.h"
using namespace Niflib;

//Constructor
ByteColor4::ByteColor4() : r((byte)0), g((byte)0), b((byte)0), a((byte)0) {};

//Copy Constructor
ByteColor4::ByteColor4( const ByteColor4 & src ) {
	*this = src;
};

//Copy Operator
ByteColor4 & ByteColor4::operator=( const ByteColor4 & src ) {
	this->r = src.r;
	this->g = src.g;
	this->b = src.b;
	this->a = src.a;
	return *this;
};

//Destructor
ByteColor4::~ByteColor4() {};

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//

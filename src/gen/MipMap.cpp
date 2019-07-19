/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/MipMap.h"
using namespace Niflib;

//Constructor
MipMap::MipMap() : width((unsigned int)0), height((unsigned int)0), offset((unsigned int)0) {};

//Copy Constructor
MipMap::MipMap( const MipMap & src ) {
	*this = src;
};

//Copy Operator
MipMap & MipMap::operator=( const MipMap & src ) {
	this->width = src.width;
	this->height = src.height;
	this->offset = src.offset;
	return *this;
};

//Destructor
MipMap::~MipMap() {};

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//

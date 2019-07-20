/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/LODRange.h"
using namespace Niflib;

//Constructor
LODRange::LODRange() : nearExtent(0.0f), farExtent(0.0f) {};

//Copy Constructor
LODRange::LODRange( const LODRange & src ) {
	*this = src;
};

//Copy Operator
LODRange & LODRange::operator=( const LODRange & src ) {
	this->nearExtent = src.nearExtent;
	this->farExtent = src.farExtent;
	this->unknownInts = src.unknownInts;
	return *this;
};

//Destructor
LODRange::~LODRange() {};

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//

/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/ByteArray.h"
using namespace Niflib;

//Constructor
ByteArray::ByteArray() : dataSize((unsigned int)0) {};

//Copy Constructor
ByteArray::ByteArray( const ByteArray & src ) {
	*this = src;
};

//Copy Operator
ByteArray & ByteArray::operator=( const ByteArray & src ) {
	this->dataSize = src.dataSize;
	this->data = src.data;
	return *this;
};

//Destructor
ByteArray::~ByteArray() {};

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//

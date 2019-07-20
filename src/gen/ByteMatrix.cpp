/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/ByteMatrix.h"
using namespace Niflib;

//Constructor
ByteMatrix::ByteMatrix() : dataSize1((unsigned int)0), dataSize2((unsigned int)0) {};

//Copy Constructor
ByteMatrix::ByteMatrix( const ByteMatrix & src ) {
	*this = src;
};

//Copy Operator
ByteMatrix & ByteMatrix::operator=( const ByteMatrix & src ) {
	this->dataSize1 = src.dataSize1;
	this->dataSize2 = src.dataSize2;
	this->data = src.data;
	return *this;
};

//Destructor
ByteMatrix::~ByteMatrix() {};

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//

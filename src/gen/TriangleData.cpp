/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/TriangleData.h"
using namespace Niflib;

//Constructor
TriangleData::TriangleData() : weldingInfo((unsigned short)0) {};

//Copy Constructor
TriangleData::TriangleData( const TriangleData & src ) {
	*this = src;
};

//Copy Operator
TriangleData & TriangleData::operator=( const TriangleData & src ) {
	this->triangle = src.triangle;
	this->weldingInfo = src.weldingInfo;
	this->normal = src.normal;
	return *this;
};

//Destructor
TriangleData::~TriangleData() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

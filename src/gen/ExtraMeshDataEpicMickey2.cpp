/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/ExtraMeshDataEpicMickey2.h"
using namespace Niflib;

//Constructor
ExtraMeshDataEpicMickey2::ExtraMeshDataEpicMickey2() : start((int)0), end((int)0) {};

//Copy Constructor
ExtraMeshDataEpicMickey2::ExtraMeshDataEpicMickey2( const ExtraMeshDataEpicMickey2 & src ) {
	*this = src;
};

//Copy Operator
ExtraMeshDataEpicMickey2 & ExtraMeshDataEpicMickey2::operator=( const ExtraMeshDataEpicMickey2 & src ) {
	this->start = src.start;
	this->end = src.end;
	this->unknownShorts = src.unknownShorts;
	return *this;
};

//Destructor
ExtraMeshDataEpicMickey2::~ExtraMeshDataEpicMickey2() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

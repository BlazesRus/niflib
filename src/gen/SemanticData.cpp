/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/SemanticData.h"
using namespace Niflib;

//Constructor
SemanticData::SemanticData() : index((unsigned int)0) {};

//Copy Constructor
SemanticData::SemanticData( const SemanticData & src ) {
	*this = src;
};

//Copy Operator
SemanticData & SemanticData::operator=( const SemanticData & src ) {
	this->name = src.name;
	this->index = src.index;
	return *this;
};

//Destructor
SemanticData::~SemanticData() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

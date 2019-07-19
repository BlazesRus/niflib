/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/MatchGroup.h"
using namespace Niflib;

//Constructor
MatchGroup::MatchGroup() : numVertices((unsigned short)0) {};

//Copy Constructor
MatchGroup::MatchGroup( const MatchGroup & src ) {
	*this = src;
};

//Copy Operator
MatchGroup & MatchGroup::operator=( const MatchGroup & src ) {
	this->numVertices = src.numVertices;
	this->vertexIndices = src.vertexIndices;
	return *this;
};

//Destructor
MatchGroup::~MatchGroup() {};

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//

/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/BoneVertData.h"
using namespace Niflib;

//Constructor
BoneVertData::BoneVertData() : index((unsigned short)0), weight(0.0f) {};

//Copy Constructor
BoneVertData::BoneVertData( const BoneVertData & src ) {
	*this = src;
};

//Copy Operator
BoneVertData & BoneVertData::operator=( const BoneVertData & src ) {
	this->index = src.index;
	this->weight = src.weight;
	return *this;
};

//Destructor
BoneVertData::~BoneVertData() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

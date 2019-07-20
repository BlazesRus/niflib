/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/OldSkinData.h"
using namespace Niflib;

//Constructor
OldSkinData::OldSkinData() : vertexWeight(0.0f), vertexIndex((unsigned short)0) {};

//Copy Constructor
OldSkinData::OldSkinData( const OldSkinData & src ) {
	*this = src;
};

//Copy Operator
OldSkinData & OldSkinData::operator=( const OldSkinData & src ) {
	this->vertexWeight = src.vertexWeight;
	this->vertexIndex = src.vertexIndex;
	this->unknownVector = src.unknownVector;
	return *this;
};

//Destructor
OldSkinData::~OldSkinData() {};

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//

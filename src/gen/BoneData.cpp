/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/BoneData.h"
#include "../../include/gen/BoneVertData.h"
#include "../../include/gen/NiTransform.h"
using namespace Niflib;

//Constructor
BoneData::BoneData() : boundingSphereRadius(0.0f), numVertices((unsigned short)0) {};

//Copy Constructor
BoneData::BoneData( const BoneData & src ) {
	*this = src;
};

//Copy Operator
BoneData & BoneData::operator=( const BoneData & src ) {
	this->skinTransform = src.skinTransform;
	this->boundingSphereOffset = src.boundingSphereOffset;
	this->boundingSphereRadius = src.boundingSphereRadius;
	this->unknown13Shorts = src.unknown13Shorts;
	this->numVertices = src.numVertices;
	this->vertexWeights = src.vertexWeights;
	return *this;
};

//Destructor
BoneData::~BoneData() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

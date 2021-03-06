/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/BSPackedSharedGeomData.h"
#include "../../include/gen/BSPackedGeomDataCombined.h"
#include "../../include/gen/BSVertexDesc.h"
#include "../../include/gen/NiBound.h"
#include "../../include/gen/NiTransform.h"
using namespace Niflib;

//Constructor
BSPackedSharedGeomData::BSPackedSharedGeomData() : numVerts((unsigned int)0), lodLevels((unsigned int)0), triCountLod0((unsigned int)0), triOffsetLod0((unsigned int)0), triCountLod1((unsigned int)0), triOffsetLod1((unsigned int)0), triCountLod2((unsigned int)0), triOffsetLod2((unsigned int)0), numCombined((unsigned int)0) {};

//Copy Constructor
BSPackedSharedGeomData::BSPackedSharedGeomData( const BSPackedSharedGeomData & src ) {
	*this = src;
};

//Copy Operator
BSPackedSharedGeomData & BSPackedSharedGeomData::operator=( const BSPackedSharedGeomData & src ) {
	this->numVerts = src.numVerts;
	this->lodLevels = src.lodLevels;
	this->triCountLod0 = src.triCountLod0;
	this->triOffsetLod0 = src.triOffsetLod0;
	this->triCountLod1 = src.triCountLod1;
	this->triOffsetLod1 = src.triOffsetLod1;
	this->triCountLod2 = src.triCountLod2;
	this->triOffsetLod2 = src.triOffsetLod2;
	this->numCombined = src.numCombined;
	this->combined = src.combined;
	this->vertexDesc = src.vertexDesc;
	return *this;
};

//Destructor
BSPackedSharedGeomData::~BSPackedSharedGeomData() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

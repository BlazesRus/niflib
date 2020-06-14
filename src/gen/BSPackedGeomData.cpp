/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/BSPackedGeomData.h"
#include "../../include/gen/BSPackedGeomDataCombined.h"
#include "../../include/gen/BSVertexData.h"
#include "../../include/gen/BSVertexDesc.h"
#include "../../include/gen/ByteColor4.h"
#include "../../include/gen/ByteVector3.h"
#include "../../include/gen/HalfTexCoord.h"
#include "../../include/gen/HalfVector3.h"
#include "../../include/gen/NiBound.h"
#include "../../include/gen/NiTransform.h"
//#include "../../include/obj/BSPackedCombinedSharedGeomDataExtra.h"
using namespace Niflib;

//Constructor
BSPackedGeomData::BSPackedGeomData() : numVerts((unsigned int)0), lodLevels((unsigned int)0), triCountLod0((unsigned int)0), triOffsetLod0((unsigned int)0), triCountLod1((unsigned int)0), triOffsetLod1((unsigned int)0), triCountLod2((unsigned int)0), triOffsetLod2((unsigned int)0), numCombined((unsigned int)0) {};

//Copy Constructor
BSPackedGeomData::BSPackedGeomData( const BSPackedGeomData & src ) {
	*this = src;
};

//Copy Operator
BSPackedGeomData & BSPackedGeomData::operator=( const BSPackedGeomData & src ) {
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
	this->vertexData = src.vertexData;
	this->triangles = src.triangles;
	return *this;
};

//Destructor
BSPackedGeomData::~BSPackedGeomData() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

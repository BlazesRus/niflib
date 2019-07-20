/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/BSVertexData.h"
#include "../../include/gen/ByteVector3.h"
#include "../../include/gen/HalfTexCoord.h"
#include "../../include/gen/HalfVector3.h"
using namespace Niflib;

//Constructor
BSVertexData::BSVertexData() : bitangentX((hfloat)0), unknownShort((unsigned short)0), unknownInt((unsigned int)0), bitangentY((byte)0), bitangentZ((byte)0), eyeData(0.0f) {};

//Copy Constructor
BSVertexData::BSVertexData( const BSVertexData & src ) {
	*this = src;
};

//Copy Operator
BSVertexData & BSVertexData::operator=( const BSVertexData & src ) {
	this->vertex = src.vertex;
	this->bitangentX = src.bitangentX;
	this->unknownShort = src.unknownShort;
	this->unknownInt = src.unknownInt;
	this->uv = src.uv;
	this->normal = src.normal;
	this->bitangentY = src.bitangentY;
	this->tangent = src.tangent;
	this->bitangentZ = src.bitangentZ;
	this->vertexColors = src.vertexColors;
	this->boneWeights = src.boneWeights;
	this->boneIndices = src.boneIndices;
	this->eyeData = src.eyeData;
	return *this;
};

//Destructor
BSVertexData::~BSVertexData() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

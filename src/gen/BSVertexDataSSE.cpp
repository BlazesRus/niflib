/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/BSVertexDataSSE.h"
#include "../../include/gen/ByteVector3.h"
#include "../../include/gen/HalfTexCoord.h"
using namespace Niflib;

//Constructor
BSVertexDataSSE::BSVertexDataSSE() : bitangentX(0.0f), unknownInt((int)0), bitangentY((byte)0), bitangentZ((byte)0), eyeData(0.0f) {};

//Copy Constructor
BSVertexDataSSE::BSVertexDataSSE( const BSVertexDataSSE & src ) {
	*this = src;
};

//Copy Operator
BSVertexDataSSE & BSVertexDataSSE::operator=( const BSVertexDataSSE & src ) {
	this->vertex = src.vertex;
	this->bitangentX = src.bitangentX;
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
BSVertexDataSSE::~BSVertexDataSSE() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

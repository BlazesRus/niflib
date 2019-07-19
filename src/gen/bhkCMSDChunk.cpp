/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/bhkCMSDChunk.h"
using namespace Niflib;

//Constructor
bhkCMSDChunk::bhkCMSDChunk() : materialIndex((unsigned int)0), reference((unsigned short)0), transformIndex((unsigned short)0), numVertices((unsigned int)0), numIndices((unsigned int)0), numStrips((unsigned int)0), numWeldingInfo((unsigned int)0) {};

//Copy Constructor
bhkCMSDChunk::bhkCMSDChunk( const bhkCMSDChunk & src ) {
	*this = src;
};

//Copy Operator
bhkCMSDChunk & bhkCMSDChunk::operator=( const bhkCMSDChunk & src ) {
	this->translation = src.translation;
	this->materialIndex = src.materialIndex;
	this->reference = src.reference;
	this->transformIndex = src.transformIndex;
	this->numVertices = src.numVertices;
	this->vertices = src.vertices;
	this->numIndices = src.numIndices;
	this->indices = src.indices;
	this->numStrips = src.numStrips;
	this->strips = src.strips;
	this->numWeldingInfo = src.numWeldingInfo;
	this->weldingInfo = src.weldingInfo;
	return *this;
};

//Destructor
bhkCMSDChunk::~bhkCMSDChunk() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

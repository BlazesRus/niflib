/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/DataStreamRef.h"
#include "../../include/gen/SemanticData.h"
#include "../../include/obj/NiDataStream.h"
using namespace Niflib;

//Constructor
DataStreamRef::DataStreamRef() : stream(NULL), isPerInstance(0), numSubmeshes((unsigned short)1), numComponents((unsigned int)1) {};

//Copy Constructor
DataStreamRef::DataStreamRef( const DataStreamRef & src ) {
	*this = src;
};

//Copy Operator
DataStreamRef & DataStreamRef::operator=( const DataStreamRef & src ) {
	this->stream = src.stream;
	this->isPerInstance = src.isPerInstance;
	this->numSubmeshes = src.numSubmeshes;
	this->submeshToRegionMap = src.submeshToRegionMap;
	this->numComponents = src.numComponents;
	this->componentSemantics = src.componentSemantics;
	return *this;
};

//Destructor
DataStreamRef::~DataStreamRef() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/MaterialData.h"
using namespace Niflib;

//Constructor
MaterialData::MaterialData() : hasShader(false), shaderExtraData((int)0), numMaterials((unsigned int)0), activeMaterial((int)-1), unknownByte((byte)255), unknownInteger2((int)0), materialNeedsUpdate(false) {};

//Copy Constructor
MaterialData::MaterialData( const MaterialData & src ) {
	*this = src;
};

//Copy Operator
MaterialData & MaterialData::operator=( const MaterialData & src ) {
	this->hasShader = src.hasShader;
	this->shaderName = src.shaderName;
	this->shaderExtraData = src.shaderExtraData;
	this->numMaterials = src.numMaterials;
	this->materialName = src.materialName;
	this->materialExtraData = src.materialExtraData;
	this->activeMaterial = src.activeMaterial;
	this->unknownByte = src.unknownByte;
	this->unknownInteger2 = src.unknownInteger2;
	this->materialNeedsUpdate = src.materialNeedsUpdate;
	return *this;
};

//Destructor
MaterialData::~MaterialData() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

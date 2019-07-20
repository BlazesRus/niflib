/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/ShaderTexDesc.h"
#include "../../include/gen/TexDesc.h"
#include "../../include/obj/NiImage.h"
#include "../../include/obj/NiSourceTexture.h"
using namespace Niflib;

//Constructor
ShaderTexDesc::ShaderTexDesc() : hasMap(false), mapId((unsigned int)0) {};

//Copy Constructor
ShaderTexDesc::ShaderTexDesc( const ShaderTexDesc & src ) {
	*this = src;
};

//Copy Operator
ShaderTexDesc & ShaderTexDesc::operator=( const ShaderTexDesc & src ) {
	this->hasMap = src.hasMap;
	this->map = src.map;
	this->mapId = src.mapId;
	return *this;
};

//Destructor
ShaderTexDesc::~ShaderTexDesc() {};

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//

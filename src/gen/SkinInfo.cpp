/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/SkinInfo.h"
#include "../../include/obj/NiSkinInstance.h"
#include "../../include/obj/NiTriBasedGeom.h"
using namespace Niflib;

//Constructor
SkinInfo::SkinInfo() : shape(NULL), skinInstance(NULL) {};

//Copy Constructor
SkinInfo::SkinInfo( const SkinInfo & src ) {
	*this = src;
};

//Copy Operator
SkinInfo & SkinInfo::operator=( const SkinInfo & src ) {
	this->shape = src.shape;
	this->skinInstance = src.skinInstance;
	return *this;
};

//Destructor
SkinInfo::~SkinInfo() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/SkinInfoSet.h"
#include "../../include/gen/SkinInfo.h"
#include "../../include/obj/NiSkinInstance.h"
#include "../../include/obj/NiTriBasedGeom.h"
using namespace Niflib;

//Constructor
SkinInfoSet::SkinInfoSet() : numSkinInfo((unsigned int)0) {};

//Copy Constructor
SkinInfoSet::SkinInfoSet( const SkinInfoSet & src ) {
	*this = src;
};

//Copy Operator
SkinInfoSet & SkinInfoSet::operator=( const SkinInfoSet & src ) {
	this->numSkinInfo = src.numSkinInfo;
	this->skinInfo = src.skinInfo;
	return *this;
};

//Destructor
SkinInfoSet::~SkinInfoSet() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

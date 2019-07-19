/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/bhkCMSDMaterial.h"
#include "../../include/gen/HavokFilter.h"
using namespace Niflib;

//Constructor
bhkCMSDMaterial::bhkCMSDMaterial() : material((SkyrimHavokMaterial)0) {};

//Copy Constructor
bhkCMSDMaterial::bhkCMSDMaterial( const bhkCMSDMaterial & src ) {
	*this = src;
};

//Copy Operator
bhkCMSDMaterial & bhkCMSDMaterial::operator=( const bhkCMSDMaterial & src ) {
	this->material = src.material;
	this->filter = src.filter;
	return *this;
};

//Destructor
bhkCMSDMaterial::~bhkCMSDMaterial() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

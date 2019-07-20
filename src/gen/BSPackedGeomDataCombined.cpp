/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/BSPackedGeomDataCombined.h"
#include "../../include/gen/NiBound.h"
#include "../../include/gen/NiTransform.h"
using namespace Niflib;

//Constructor
BSPackedGeomDataCombined::BSPackedGeomDataCombined() : grayscaleToPaletteScale(0.0f) {};

//Copy Constructor
BSPackedGeomDataCombined::BSPackedGeomDataCombined( const BSPackedGeomDataCombined & src ) {
	*this = src;
};

//Copy Operator
BSPackedGeomDataCombined & BSPackedGeomDataCombined::operator=( const BSPackedGeomDataCombined & src ) {
	this->grayscaleToPaletteScale = src.grayscaleToPaletteScale;
	this->transform = src.transform;
	this->boundingSphere = src.boundingSphere;
	return *this;
};

//Destructor
BSPackedGeomDataCombined::~BSPackedGeomDataCombined() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

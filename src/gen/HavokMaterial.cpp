/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/HavokMaterial.h"
using namespace Niflib;

//Constructor
HavokMaterial::HavokMaterial() : material_ob((OblivionHavokMaterial)0), material_fo((Fallout3HavokMaterial)0), material_sk((SkyrimHavokMaterial)0) {};

//Copy Constructor
HavokMaterial::HavokMaterial( const HavokMaterial & src ) {
	*this = src;
};

//Copy Operator
HavokMaterial & HavokMaterial::operator=( const HavokMaterial & src ) {
	this->material_ob = src.material_ob;
	this->material_fo = src.material_fo;
	this->material_sk = src.material_sk;
	return *this;
};

//Destructor
HavokMaterial::~HavokMaterial() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

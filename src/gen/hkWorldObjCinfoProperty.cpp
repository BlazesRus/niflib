/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/hkWorldObjCinfoProperty.h"
using namespace Niflib;

//Constructor
hkWorldObjCinfoProperty::hkWorldObjCinfoProperty() : data((unsigned int)0), size((unsigned int)0), capacityAndFlags((unsigned int)0x80000000) {};

//Copy Constructor
hkWorldObjCinfoProperty::hkWorldObjCinfoProperty( const hkWorldObjCinfoProperty & src ) {
	*this = src;
};

//Copy Operator
hkWorldObjCinfoProperty & hkWorldObjCinfoProperty::operator=( const hkWorldObjCinfoProperty & src ) {
	this->data = src.data;
	this->size = src.size;
	this->capacityAndFlags = src.capacityAndFlags;
	return *this;
};

//Destructor
hkWorldObjCinfoProperty::~hkWorldObjCinfoProperty() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

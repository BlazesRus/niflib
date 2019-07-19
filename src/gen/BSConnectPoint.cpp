/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/BSConnectPoint.h"
using namespace Niflib;

//Constructor
BSConnectPoint::BSConnectPoint() : parent((string)WorkshopConnectPoints), scale(1.0f) {};

//Copy Constructor
BSConnectPoint::BSConnectPoint( const BSConnectPoint & src ) {
	*this = src;
};

//Copy Operator
BSConnectPoint & BSConnectPoint::operator=( const BSConnectPoint & src ) {
	this->parent = src.parent;
	this->name = src.name;
	this->rotation = src.rotation;
	this->translation = src.translation;
	this->scale = src.scale;
	return *this;
};

//Destructor
BSConnectPoint::~BSConnectPoint() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

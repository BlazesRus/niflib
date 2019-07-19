/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/AVObject.h"
#include "../../include/obj/NiAVObject.h"
using namespace Niflib;

//Constructor
AVObject::AVObject() : avObject(NULL) {};

//Copy Constructor
AVObject::AVObject( const AVObject & src ) {
	*this = src;
};

//Copy Operator
AVObject & AVObject::operator=( const AVObject & src ) {
	this->name = src.name;
	this->avObject = src.avObject;
	return *this;
};

//Destructor
AVObject::~AVObject() {};

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//

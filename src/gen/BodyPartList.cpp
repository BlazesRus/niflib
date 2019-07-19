/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/BodyPartList.h"
using namespace Niflib;

//Constructor
BodyPartList::BodyPartList() : partFlag((BSPartFlag)257), bodyPart((BSDismemberBodyPartType)0) {};

//Copy Constructor
BodyPartList::BodyPartList( const BodyPartList & src ) {
	*this = src;
};

//Copy Operator
BodyPartList & BodyPartList::operator=( const BodyPartList & src ) {
	this->partFlag = src.partFlag;
	this->bodyPart = src.bodyPart;
	return *this;
};

//Destructor
BodyPartList::~BodyPartList() {};

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//

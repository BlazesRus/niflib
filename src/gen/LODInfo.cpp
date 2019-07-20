/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/LODInfo.h"
using namespace Niflib;

//Constructor
LODInfo::LODInfo() : numBones((unsigned int)0), numActiveSkins((unsigned int)0) {};

//Copy Constructor
LODInfo::LODInfo( const LODInfo & src ) {
	*this = src;
};

//Copy Operator
LODInfo & LODInfo::operator=( const LODInfo & src ) {
	this->numBones = src.numBones;
	this->numActiveSkins = src.numActiveSkins;
	this->skinIndices = src.skinIndices;
	return *this;
};

//Destructor
LODInfo::~LODInfo() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

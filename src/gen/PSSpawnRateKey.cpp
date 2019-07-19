/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/PSSpawnRateKey.h"
using namespace Niflib;

//Constructor
PSSpawnRateKey::PSSpawnRateKey() : value(0.0f), time(0.0f) {};

//Copy Constructor
PSSpawnRateKey::PSSpawnRateKey( const PSSpawnRateKey & src ) {
	*this = src;
};

//Copy Operator
PSSpawnRateKey & PSSpawnRateKey::operator=( const PSSpawnRateKey & src ) {
	this->value = src.value;
	this->time = src.time;
	return *this;
};

//Destructor
PSSpawnRateKey::~PSSpawnRateKey() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

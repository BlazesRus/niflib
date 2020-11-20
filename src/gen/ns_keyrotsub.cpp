/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/ns_keyrotsub.h"
#include "../../include/gen/TBC.h"
#include "../../include/gen/ns_keylin.h"
#include "../../include/gen/ns_keytan.h"
#include "../../include/gen/ns_keytbc.h"
#include "../../include/gen/ns_keyvecarray.h"
using namespace Niflib;

//Constructor
ns_keyrotsub::ns_keyrotsub() : time(0.0f) {};

//Copy Constructor
ns_keyrotsub::ns_keyrotsub( const ns_keyrotsub & src ) {
	*this = src;
};

//Copy Operator
ns_keyrotsub & ns_keyrotsub::operator=( const ns_keyrotsub & src ) {
	this->time = src.time;
	this->subKeys = src.subKeys;
	return *this;
};

//Destructor
ns_keyrotsub::~ns_keyrotsub() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

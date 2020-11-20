/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/NiTFixedStringMapItem.h"
using namespace Niflib;

//Constructor
NiTFixedStringMapItem::NiTFixedStringMapItem() {};

//Copy Constructor
NiTFixedStringMapItem::NiTFixedStringMapItem( const NiTFixedStringMapItem & src ) {
	*this = src;
};

//Copy Operator
NiTFixedStringMapItem & NiTFixedStringMapItem::operator=( const NiTFixedStringMapItem & src ) {
	this->string = src.string;
	this->value = src.value;
	return *this;
};

//Destructor
NiTFixedStringMapItem::~NiTFixedStringMapItem() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

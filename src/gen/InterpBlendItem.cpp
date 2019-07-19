/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/InterpBlendItem.h"
#include "../../include/obj/NiInterpolator.h"
using namespace Niflib;

//Constructor
InterpBlendItem::InterpBlendItem() : interpolator(NULL), weight(0.0f), normalizedWeight(0.0f), priority((byte)0), easeSpinner(0.0f) {};

//Copy Constructor
InterpBlendItem::InterpBlendItem( const InterpBlendItem & src ) {
	*this = src;
};

//Copy Operator
InterpBlendItem & InterpBlendItem::operator=( const InterpBlendItem & src ) {
	this->interpolator = src.interpolator;
	this->weight = src.weight;
	this->normalizedWeight = src.normalizedWeight;
	this->priority = src.priority;
	this->easeSpinner = src.easeSpinner;
	return *this;
};

//Destructor
InterpBlendItem::~InterpBlendItem() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

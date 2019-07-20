/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/ElementReference.h"
#include "../../include/gen/SemanticData.h"
using namespace Niflib;

//Constructor
ElementReference::ElementReference() : normalizeFlag((unsigned int)0) {};

//Copy Constructor
ElementReference::ElementReference( const ElementReference & src ) {
	*this = src;
};

//Copy Operator
ElementReference & ElementReference::operator=( const ElementReference & src ) {
	this->semantic = src.semantic;
	this->normalizeFlag = src.normalizeFlag;
	return *this;
};

//Destructor
ElementReference::~ElementReference() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

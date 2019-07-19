/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/ExtraMeshDataEpicMickey.h"
using namespace Niflib;

//Constructor
ExtraMeshDataEpicMickey::ExtraMeshDataEpicMickey() : unknownInt1((int)0), unknownInt2((int)0), unknownInt3((int)0), unknownInt4(0.0f), unknownInt5(0.0f), unknownInt6(0.0f) {};

//Copy Constructor
ExtraMeshDataEpicMickey::ExtraMeshDataEpicMickey( const ExtraMeshDataEpicMickey & src ) {
	*this = src;
};

//Copy Operator
ExtraMeshDataEpicMickey & ExtraMeshDataEpicMickey::operator=( const ExtraMeshDataEpicMickey & src ) {
	this->unknownInt1 = src.unknownInt1;
	this->unknownInt2 = src.unknownInt2;
	this->unknownInt3 = src.unknownInt3;
	this->unknownInt4 = src.unknownInt4;
	this->unknownInt5 = src.unknownInt5;
	this->unknownInt6 = src.unknownInt6;
	return *this;
};

//Destructor
ExtraMeshDataEpicMickey::~ExtraMeshDataEpicMickey() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/NiCurve3.h"
using namespace Niflib;

//Constructor
NiCurve3::NiCurve3() : degree((unsigned int)0), numControlPoints((unsigned int)0), numKnots((unsigned int)0) {};

//Copy Constructor
NiCurve3::NiCurve3( const NiCurve3 & src ) {
	*this = src;
};

//Copy Operator
NiCurve3 & NiCurve3::operator=( const NiCurve3 & src ) {
	this->degree = src.degree;
	this->numControlPoints = src.numControlPoints;
	this->controlPoints = src.controlPoints;
	this->numKnots = src.numKnots;
	this->knots = src.knots;
	return *this;
};

//Destructor
NiCurve3::~NiCurve3() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

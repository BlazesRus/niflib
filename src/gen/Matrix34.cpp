/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/Matrix34.h"
using namespace Niflib;

//Constructor
Matrix34::Matrix34() : m11(1.0f), m21(0.0f), m31(0.0f), m12(0.0f), m22(1.0f), m32(0.0f), m13(0.0f), m23(0.0f), m33(1.0f), m14(0.0f), m24(0.0f), m34(0.0f) {};

//Copy Constructor
Matrix34::Matrix34( const Matrix34 & src ) {
	*this = src;
};

//Copy Operator
Matrix34 & Matrix34::operator=( const Matrix34 & src ) {
	this->m11 = src.m11;
	this->m21 = src.m21;
	this->m31 = src.m31;
	this->m12 = src.m12;
	this->m22 = src.m22;
	this->m32 = src.m32;
	this->m13 = src.m13;
	this->m23 = src.m23;
	this->m33 = src.m33;
	this->m14 = src.m14;
	this->m24 = src.m24;
	this->m34 = src.m34;
	return *this;
};

//Destructor
Matrix34::~Matrix34() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/HavokFilter.h"
using namespace Niflib;

//Constructor
HavokFilter::HavokFilter() : layer_ob((OblivionLayer)OL_STATIC), layer_fo((Fallout3Layer)FOL_STATIC), layer_sk((SkyrimLayer)SKYL_STATIC), flagsAndPartNumber((byte)0), group((unsigned short)0) {};

//Copy Constructor
HavokFilter::HavokFilter( const HavokFilter & src ) {
	*this = src;
};

//Copy Operator
HavokFilter & HavokFilter::operator=( const HavokFilter & src ) {
	this->layer_ob = src.layer_ob;
	this->layer_fo = src.layer_fo;
	this->layer_sk = src.layer_sk;
	this->flagsAndPartNumber = src.flagsAndPartNumber;
	this->group = src.group;
	return *this;
};

//Destructor
HavokFilter::~HavokFilter() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

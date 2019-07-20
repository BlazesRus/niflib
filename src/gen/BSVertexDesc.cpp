/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/BSVertexDesc.h"
using namespace Niflib;

//Constructor
BSVertexDesc::BSVertexDesc() : vf1((byte)0), vf2((byte)0), vf3((byte)0), vf4((byte)0), vf5((byte)0), vertexAttributes((VertexFlags)0), vf8((byte)0) {};

//Copy Constructor
BSVertexDesc::BSVertexDesc( const BSVertexDesc & src ) {
	*this = src;
};

//Copy Operator
BSVertexDesc & BSVertexDesc::operator=( const BSVertexDesc & src ) {
	this->vf1 = src.vf1;
	this->vf2 = src.vf2;
	this->vf3 = src.vf3;
	this->vf4 = src.vf4;
	this->vf5 = src.vf5;
	this->vertexAttributes = src.vertexAttributes;
	this->vf8 = src.vf8;
	return *this;
};

//Destructor
BSVertexDesc::~BSVertexDesc() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

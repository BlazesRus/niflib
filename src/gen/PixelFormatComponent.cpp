/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/PixelFormatComponent.h"
using namespace Niflib;

//Constructor
PixelFormatComponent::PixelFormatComponent() : type((PixelComponent)0), convention((PixelRepresentation)0), bitsPerChannel((byte)0), isSigned(false) {};

//Copy Constructor
PixelFormatComponent::PixelFormatComponent( const PixelFormatComponent & src ) {
	*this = src;
};

//Copy Operator
PixelFormatComponent & PixelFormatComponent::operator=( const PixelFormatComponent & src ) {
	this->type = src.type;
	this->convention = src.convention;
	this->bitsPerChannel = src.bitsPerChannel;
	this->isSigned = src.isSigned;
	return *this;
};

//Destructor
PixelFormatComponent::~PixelFormatComponent() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/FormatPrefs.h"
using namespace Niflib;

//Constructor
FormatPrefs::FormatPrefs() : pixelLayout((PixelLayout)0), useMipmaps((MipMapFormat)MIP_FMT_DEFAULT), alphaFormat((AlphaFormat)ALPHA_DEFAULT) {};

//Copy Constructor
FormatPrefs::FormatPrefs( const FormatPrefs & src ) {
	*this = src;
};

//Copy Operator
FormatPrefs & FormatPrefs::operator=( const FormatPrefs & src ) {
	this->pixelLayout = src.pixelLayout;
	this->useMipmaps = src.useMipmaps;
	this->alphaFormat = src.alphaFormat;
	return *this;
};

//Destructor
FormatPrefs::~FormatPrefs() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/ChannelData.h"
using namespace Niflib;

//Constructor
ChannelData::ChannelData() : type((ChannelType)0), convention((ChannelConvention)0), bitsPerChannel((byte)0), unknownByte1((byte)0) {};

//Copy Constructor
ChannelData::ChannelData( const ChannelData & src ) {
	*this = src;
};

//Copy Operator
ChannelData & ChannelData::operator=( const ChannelData & src ) {
	this->type = src.type;
	this->convention = src.convention;
	this->bitsPerChannel = src.bitsPerChannel;
	this->unknownByte1 = src.unknownByte1;
	return *this;
};

//Destructor
ChannelData::~ChannelData() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

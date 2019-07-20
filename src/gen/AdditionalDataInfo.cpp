/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/AdditionalDataInfo.h"
using namespace Niflib;

//Constructor
AdditionalDataInfo::AdditionalDataInfo() : dataType((int)0), numChannelBytesPerElement((int)0), numChannelBytes((int)0), numTotalBytesPerElement((int)0), blockIndex((int)0), channelOffset((int)0), unknownByte1((byte)2) {};

//Copy Constructor
AdditionalDataInfo::AdditionalDataInfo( const AdditionalDataInfo & src ) {
	*this = src;
};

//Copy Operator
AdditionalDataInfo & AdditionalDataInfo::operator=( const AdditionalDataInfo & src ) {
	this->dataType = src.dataType;
	this->numChannelBytesPerElement = src.numChannelBytesPerElement;
	this->numChannelBytes = src.numChannelBytes;
	this->numTotalBytesPerElement = src.numTotalBytesPerElement;
	this->blockIndex = src.blockIndex;
	this->channelOffset = src.channelOffset;
	this->unknownByte1 = src.unknownByte1;
	return *this;
};

//Destructor
AdditionalDataInfo::~AdditionalDataInfo() {};

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//

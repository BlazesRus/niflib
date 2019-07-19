/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/ExportInfo.h"
using namespace Niflib;

//Constructor
ExportInfo::ExportInfo() {};

//Copy Constructor
ExportInfo::ExportInfo( const ExportInfo & src ) {
	*this = src;
};

//Copy Operator
ExportInfo & ExportInfo::operator=( const ExportInfo & src ) {
	this->author = src.author;
	this->processScript = src.processScript;
	this->exportScript = src.exportScript;
	return *this;
};

//Destructor
ExportInfo::~ExportInfo() {};

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//

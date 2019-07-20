/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/ControlledBlock.h"
#include "../../include/obj/NiBlendInterpolator.h"
#include "../../include/obj/NiInterpolator.h"
#include "../../include/obj/NiStringPalette.h"
#include "../../include/obj/NiTimeController.h"
using namespace Niflib;

//Constructor
ControlledBlock::ControlledBlock() : interpolator(NULL), controller(NULL), blendInterpolator(NULL), blendIndex((unsigned short)0), priority((byte)0), stringPalette(NULL), nodeNameOffset((unsigned int)-1), propertyTypeOffset((unsigned int)-1), controllerTypeOffset((unsigned int)-1), controllerIdOffset((unsigned int)-1), interpolatorIdOffset((unsigned int)-1) {};

//Copy Constructor
ControlledBlock::ControlledBlock( const ControlledBlock & src ) {
	*this = src;
};

//Copy Operator
ControlledBlock & ControlledBlock::operator=( const ControlledBlock & src ) {
	this->targetName = src.targetName;
	this->interpolator = src.interpolator;
	this->controller = src.controller;
	this->blendInterpolator = src.blendInterpolator;
	this->blendIndex = src.blendIndex;
	this->priority = src.priority;
	this->nodeName = src.nodeName;
	this->propertyType = src.propertyType;
	this->controllerType = src.controllerType;
	this->controllerId = src.controllerId;
	this->interpolatorId = src.interpolatorId;
	this->stringPalette = src.stringPalette;
	this->nodeNameOffset = src.nodeNameOffset;
	this->propertyTypeOffset = src.propertyTypeOffset;
	this->controllerTypeOffset = src.controllerTypeOffset;
	this->controllerIdOffset = src.controllerIdOffset;
	this->interpolatorIdOffset = src.interpolatorIdOffset;
	return *this;
};

//Destructor
ControlledBlock::~ControlledBlock() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

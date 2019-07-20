/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/TexDesc.h"
#include "../../include/obj/NiImage.h"
#include "../../include/obj/NiSourceTexture.h"
using namespace Niflib;

//Constructor
TexDesc::TexDesc() : image(NULL), source(NULL), clampMode((TexClampMode)WRAP_S_WRAP_T), filterMode((TexFilterMode)FILTER_TRILERP), flags((unsigned short)0), maxAnisotropy((unsigned short)0), uvSet((unsigned int)0), ps2L((short)0), ps2K((short)-75), unknown1((unsigned short)0), hasTextureTransform(false), scale(1.0, 1.0), rotation(0.0f), transformMethod((TransformMethod)0) {};

//Copy Constructor
TexDesc::TexDesc( const TexDesc & src ) {
	*this = src;
};

//Copy Operator
TexDesc & TexDesc::operator=( const TexDesc & src ) {
	this->image = src.image;
	this->source = src.source;
	this->clampMode = src.clampMode;
	this->filterMode = src.filterMode;
	this->flags = src.flags;
	this->maxAnisotropy = src.maxAnisotropy;
	this->uvSet = src.uvSet;
	this->ps2L = src.ps2L;
	this->ps2K = src.ps2K;
	this->unknown1 = src.unknown1;
	this->hasTextureTransform = src.hasTextureTransform;
	this->translation = src.translation;
	this->scale = src.scale;
	this->rotation = src.rotation;
	this->transformMethod = src.transformMethod;
	this->center = src.center;
	return *this;
};

//Destructor
TexDesc::~TexDesc() {};

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//

/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/Particle.h"
using namespace Niflib;

//Constructor
Particle::Particle() : lifetime(0.0f), lifespan(0.0f), timestamp(0.0f), unknownShort((unsigned short)0), vertexId((unsigned short)0) {};

//Copy Constructor
Particle::Particle( const Particle & src ) {
	*this = src;
};

//Copy Operator
Particle & Particle::operator=( const Particle & src ) {
	this->velocity = src.velocity;
	this->unknownVector = src.unknownVector;
	this->lifetime = src.lifetime;
	this->lifespan = src.lifespan;
	this->timestamp = src.timestamp;
	this->unknownShort = src.unknownShort;
	this->vertexId = src.vertexId;
	return *this;
};

//Destructor
Particle::~Particle() {};

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//

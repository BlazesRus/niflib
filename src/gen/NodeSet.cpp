/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/NodeSet.h"
#include "../../include/obj/NiNode.h"
using namespace Niflib;

//Constructor
NodeSet::NodeSet() : numNodes((unsigned int)0) {};

//Copy Constructor
NodeSet::NodeSet( const NodeSet & src ) {
	*this = src;
};

//Copy Operator
NodeSet & NodeSet::operator=( const NodeSet & src ) {
	this->numNodes = src.numNodes;
	this->nodes = src.nodes;
	return *this;
};

//Destructor
NodeSet::~NodeSet() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

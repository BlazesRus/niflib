/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _NODESET_H_
#define _NODESET_H_

#include "../NIF_IO.h"

namespace Niflib {

// Forward define of referenced NIF objects
class NiNode;

/*! A set of NiNode references. */
struct NodeSet {
	/*! Default Constructor */
	NIFLIB_API NodeSet();
	/*! Default Destructor */
	NIFLIB_API ~NodeSet();
	/*! Copy Constructor */
	NIFLIB_API NodeSet( const NodeSet & src );
	/*! Copy Operator */
	NIFLIB_API NodeSet & operator=( const NodeSet & src );
	/*! Number of node references that follow. */
	mutable unsigned int numNodes;
	/*! The list of NiNode references. */
	vector<NiNode * > nodes;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif

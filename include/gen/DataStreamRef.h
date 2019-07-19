/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _DATASTREAMREF_H_
#define _DATASTREAMREF_H_

#include "../NIF_IO.h"

// Include structures
#include "../Ref.h"
#include "SemanticData.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiDataStream;

struct DataStreamRef {
	/*! Default Constructor */
	NIFLIB_API DataStreamRef();
	/*! Default Destructor */
	NIFLIB_API ~DataStreamRef();
	/*! Copy Constructor */
	NIFLIB_API DataStreamRef( const DataStreamRef & src );
	/*! Copy Operator */
	NIFLIB_API DataStreamRef & operator=( const DataStreamRef & src );
	/*!
	 * Reference to a data stream object which holds the data used by
	 *             this reference.
	 */
	Ref<NiDataStream > stream;
	/*!
	 * Sets whether this stream data is per-instance data for use in
	 *             hardware instancing.
	 */
	bool isPerInstance;
	/*!
	 * The number of submesh-to-region mappings that this data stream
	 *             has.
	 */
	mutable unsigned short numSubmeshes;
	vector<unsigned short > submeshToRegionMap;
	mutable unsigned int numComponents;
	/*! Describes the semantic of each component. */
	vector<SemanticData > componentSemantics;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif

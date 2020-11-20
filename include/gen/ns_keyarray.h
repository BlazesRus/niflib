/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _NS_KEYARRAY_H_
#define _NS_KEYARRAY_H_

#include "../NIF_IO.h"

// Include structures
#include "ns_keylin.h"
namespace Niflib {


/*!
 * Array of keys, not interpolated (!!! for NifSkope only, use keyarray for regular
 * use).
 */
template <class T >
struct ns_keyarray {
	/*! Number of keys. */
	mutable unsigned int numKeys;
	/*! The keys. */
	vector<ns_keylin<T > > keys;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif

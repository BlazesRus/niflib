/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _NS_KEYROTARRAY_H_
#define _NS_KEYROTARRAY_H_

#include "../NIF_IO.h"

// Include structures
#include "ns_keylin.h"
#include "ns_keytbc.h"
#include "ns_keyrotsub.h"
namespace Niflib {


/*! Array of rotation keys (!!! for NifSkope only, use keyrotarray for regular use). */
template <class T >
struct ns_keyrotarray {
	/*! Number of rotation keys. */
	mutable unsigned int numKeys;
	/*! The key type (1, 2, 3, or 4). */
	unsigned int keyType;
	/*! Linear keys. */
	vector<ns_keylin<T > > keys;
	/*! Special rotation keys (3 float arrays, one for each axis). */
	vector<ns_keyrotsub > keysSub;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif

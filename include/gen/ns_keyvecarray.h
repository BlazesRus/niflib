/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _NS_KEYVECARRAY_H_
#define _NS_KEYVECARRAY_H_

#include "../NIF_IO.h"

// Include structures
#include "ns_keylin.h"
#include "ns_keytan.h"
#include "ns_keytbc.h"
namespace Niflib {


/*!
 * Array of interpolable keys (!!! for NifSkope only, use keyvecarray for regular
 * use).
 */
template <class T >
struct ns_keyvecarray {
	/*! Number of keys. */
	mutable unsigned int numKeys;
	/*! The key type (1, 2, or 3). */
	unsigned int keyType;
	/*! Linearly interpolated keys. */
	vector<ns_keylin<T > > keys;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif

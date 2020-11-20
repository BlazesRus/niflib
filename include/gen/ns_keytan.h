/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _NS_KEYTAN_H_
#define _NS_KEYTAN_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * Key with tangents (!!! for NifSkope only, use keyvec instead for regular
 * purposes).
 */
template <class T >
struct ns_keytan {
	/*! The key time. */
	float time;
	/*! The key value. */
	T value;
	/*! Forward tangent. */
	T forward;
	/*! Backward tangent. */
	T backward;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif

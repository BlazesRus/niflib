/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _NS_KEYLIN_H_
#define _NS_KEYLIN_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * Linear key type (!!! for NifSkope optimizer only, use key, keyrot, or keyvec for
 * regular use).
 */
template <class T >
struct ns_keylin {
	/*! Key time. */
	float time;
	/*! The key value. */
	T value;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif

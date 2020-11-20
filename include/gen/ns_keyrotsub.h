/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _NS_KEYROTSUB_H_
#define _NS_KEYROTSUB_H_

#include "../NIF_IO.h"

// Include structures
#include "ns_keyvecarray.h"
namespace Niflib {


/*! Rotation subkey (!!! Nifskope only). */
struct ns_keyrotsub {
	/*! Default Constructor */
	NIFLIB_API ns_keyrotsub();
	/*! Default Destructor */
	NIFLIB_API ~ns_keyrotsub();
	/*! Copy Constructor */
	NIFLIB_API ns_keyrotsub( const ns_keyrotsub & src );
	/*! Copy Operator */
	NIFLIB_API ns_keyrotsub & operator=( const ns_keyrotsub & src );
	/*! Time. */
	float time;
	/*! The sub keys, one for every axis. */
	Niflib::NifArray<3,ns_keyvecarray<float > > subKeys;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif

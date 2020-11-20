/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _NS_KEYTBC_H_
#define _NS_KEYTBC_H_

#include "../NIF_IO.h"

// Include structures
#include "TBC.h"
namespace Niflib {


/*! A TBC key (!!! for NifSkope only, use keyvec for regular purposes). */
template <class T >
struct ns_keytbc {
	/*! The key time. */
	float time;
	/*! The key value. */
	T value;
	/*! Tension, bias, continuity. */
	TBC tbc;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif

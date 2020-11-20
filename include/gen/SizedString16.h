/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _SIZEDSTRING16_H_
#define _SIZEDSTRING16_H_

#include "../NIF_IO.h"

namespace Niflib {


/*! A string of given length, using a ushort to store string length. */
struct SizedString16 {
	/*! Default Constructor */
	NIFLIB_API SizedString16();
	/*! Default Destructor */
	NIFLIB_API ~SizedString16();
	/*! Copy Constructor */
	NIFLIB_API SizedString16( const SizedString16 & src );
	/*! Copy Operator */
	NIFLIB_API SizedString16 & operator=( const SizedString16 & src );
	/*! The string length. */
	mutable unsigned short length;
	/*! The string itself. */
	vector<byte > value;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif

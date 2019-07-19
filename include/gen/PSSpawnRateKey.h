/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _PSSPAWNRATEKEY_H_
#define _PSSPAWNRATEKEY_H_

#include "../NIF_IO.h"

namespace Niflib {


struct PSSpawnRateKey {
	/*! Default Constructor */
	NIFLIB_API PSSpawnRateKey();
	/*! Default Destructor */
	NIFLIB_API ~PSSpawnRateKey();
	/*! Copy Constructor */
	NIFLIB_API PSSpawnRateKey( const PSSpawnRateKey & src );
	/*! Copy Operator */
	NIFLIB_API PSSpawnRateKey & operator=( const PSSpawnRateKey & src );
	float value;
	float time;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif

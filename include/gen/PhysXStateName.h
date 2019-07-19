/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _PHYSXSTATENAME_H_
#define _PHYSXSTATENAME_H_

#include "../NIF_IO.h"

namespace Niflib {


struct PhysXStateName {
	/*! Default Constructor */
	NIFLIB_API PhysXStateName();
	/*! Default Destructor */
	NIFLIB_API ~PhysXStateName();
	/*! Copy Constructor */
	NIFLIB_API PhysXStateName( const PhysXStateName & src );
	/*! Copy Operator */
	NIFLIB_API PhysXStateName & operator=( const PhysXStateName & src );
	IndexString name;
	unsigned int index;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif

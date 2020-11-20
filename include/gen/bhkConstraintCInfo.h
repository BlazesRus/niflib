/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BHKCONSTRAINTCINFO_H_
#define _BHKCONSTRAINTCINFO_H_

#include "../NIF_IO.h"

namespace Niflib {

// Forward define of referenced NIF objects
class bhkEntity;

/*! Bethesda extension of hkpConstraintInstance. */
struct bhkConstraintCInfo {
	/*! Default Constructor */
	NIFLIB_API bhkConstraintCInfo();
	/*! Default Destructor */
	NIFLIB_API ~bhkConstraintCInfo();
	/*! Copy Constructor */
	NIFLIB_API bhkConstraintCInfo( const bhkConstraintCInfo & src );
	/*! Copy Operator */
	NIFLIB_API bhkConstraintCInfo & operator=( const bhkConstraintCInfo & src );
	/*! Always 2 (Hardcoded). Number of bodies affected by this constraint. */
	unsigned int numEntities;
	/*! The entity affected by this constraint. */
	bhkEntity * entityA;
	/*! The entity affected by this constraint. */
	bhkEntity * entityB;
	/*! Either PSI or TOI priority. TOI is higher priority. */
	ConstraintPriority priority;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif

/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BHKCONSTRAINTCHAINCINFO_H_
#define _BHKCONSTRAINTCHAINCINFO_H_

#include "../NIF_IO.h"

// Include structures
#include "bhkConstraintCInfo.h"
namespace Niflib {

// Forward define of referenced NIF objects
class bhkRigidBody;

/*! Bethesda extension of hkpConstraintChainInstance. */
struct bhkConstraintChainCInfo {
	/*! Default Constructor */
	NIFLIB_API bhkConstraintChainCInfo();
	/*! Default Destructor */
	NIFLIB_API ~bhkConstraintChainCInfo();
	/*! Copy Constructor */
	NIFLIB_API bhkConstraintChainCInfo( const bhkConstraintChainCInfo & src );
	/*! Copy Operator */
	NIFLIB_API bhkConstraintChainCInfo & operator=( const bhkConstraintChainCInfo & src );
	mutable unsigned int numChainedEntities;
	vector<bhkRigidBody * > chainedEntities;
	bhkConstraintCInfo constraintInfo;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif

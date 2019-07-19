/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#ifndef _NIPSYSSPAWNMODIFIER_H_
#define _NIPSYSSPAWNMODIFIER_H_

//--BEGIN FILE HEAD CUSTOM CODE--//
//--END CUSTOM CODE--//

#include "NiPSysModifier.h"
namespace Niflib {

class NiPSysSpawnModifier;
typedef Ref<NiPSysSpawnModifier> NiPSysSpawnModifierRef;

/*! Particle modifier that spawns additional copies of a particle. */
class NiPSysSpawnModifier : public NiPSysModifier {
public:
	/*! Constructor */
	NIFLIB_API NiPSysSpawnModifier();
	
	/*! Destructor */
	NIFLIB_API virtual ~NiPSysSpawnModifier();
	
	/*!
	 * A constant value which uniquly identifies objects of this type.
	 */
	NIFLIB_API static const Type TYPE;
	
	/*!
	 * A factory function used during file reading to create an instance of this type of object.
	 * \return A pointer to a newly allocated instance of this type of object.
	 */
	NIFLIB_API static NiObject * Create();
	
	/*!
	 * Summarizes the information contained in this object in English.
	 * \param[in] verbose Determines whether or not detailed information about large areas of data will be printed out.
	 * \return A string containing a summary of the information within the object in English.  This is the function that Niflyze calls to generate its analysis, so the output is the same.
	 */
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	
	/*!
	 * Used to determine the type of a particular instance of this object.
	 * \return The type constant for the actual type of the object.
	 */
	NIFLIB_API virtual const Type & GetType() const;

	//--BEGIN MISC CUSTOM CODE--//
	//--END CUSTOM CODE--//
protected:
	/*!
	 * Number of allowed generations for spawning. Particles whose generations are >=
	 * will not be spawned.
	 */
	unsigned short numSpawnGenerations;
	/*!
	 * The likelihood of a particular particle being spawned. Must be between 0.0 and
	 * 1.0.
	 */
	float percentageSpawned;
	/*! The minimum particles to spawn for any given original particle. */
	unsigned short minNumToSpawn;
	/*! The maximum particles to spawn for any given original particle. */
	unsigned short maxNumToSpawn;
	/*! WorldShift */
	int unknownInt;
	/*! How much the spawned particle speed can vary. */
	float spawnSpeedVariation;
	/*! How much the spawned particle direction can vary. */
	float spawnDirVariation;
	/*! Lifespan assigned to spawned particles. */
	float lifeSpan;
	/*! The amount the lifespan can vary. */
	float lifeSpanVariation;
public:
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const;
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual list<NiObject *> GetPtrs() const;
};

//--BEGIN FILE FOOT CUSTOM CODE--//
//--END CUSTOM CODE--//

}
#endif

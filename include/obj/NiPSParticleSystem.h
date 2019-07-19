/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#ifndef _NIPSPARTICLESYSTEM_H_
#define _NIPSPARTICLESYSTEM_H_

//--BEGIN FILE HEAD CUSTOM CODE--//

//--END CUSTOM CODE--//

#include "NiMesh.h"

// Include structures
#include "../Ref.h"
#include "../gen/PSSpawnRateKey.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiPSSimulator;
class NiPSBoundUpdater;
class NiPSEmitter;
class NiPSSpawner;
class NiPSParticleSystem;
typedef Ref<NiPSParticleSystem> NiPSParticleSystemRef;

/*! Represents a particle system. */
class NiPSParticleSystem : public NiMesh {
public:
	/*! Constructor */
	NIFLIB_API NiPSParticleSystem();
	
	/*! Destructor */
	NIFLIB_API virtual ~NiPSParticleSystem();
	
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
	Ref<NiPSSimulator > simulator;
	Ref<NiPSBoundUpdater > generator;
	mutable unsigned int numEmitters;
	vector<Ref<NiPSEmitter > > emitters;
	mutable unsigned int numSpawners;
	vector<Ref<NiPSSpawner > > spawners;
	Ref<NiPSSpawner > deathSpawner;
	unsigned int maxNumParticles;
	bool hasColors;
	bool hasRotations;
	bool hasRotationAxes;
	bool hasAnimatedTextures;
	bool worldSpace;
	AlignMethod normalMethod;
	Vector3 normalDirection;
	AlignMethod upMethod;
	Vector3 upDirection;
	Ref<NiPSSpawner > livingSpawner;
	mutable byte numSpawnRateKeys;
	vector<PSSpawnRateKey > spawnRateKeys;
	bool pre_rpi;
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

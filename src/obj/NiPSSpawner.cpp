/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

//--BEGIN FILE HEAD CUSTOM CODE--//

//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/ObjectRegistry.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/NiPSSpawner.h"
#include "../../include/obj/NiPSParticleSystem.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSSpawner::TYPE("NiPSSpawner", &NiObject::TYPE );

NiPSSpawner::NiPSSpawner() : masterParticleSystem(NULL), percentageSpawned(0.0f), spawnSpeedFactor(0.0f), spawnSpeedFactorVar(0.0f), spawnDirChaos(0.0f), lifeSpan(0.0f), lifeSpanVar(0.0f), numSpawnGenerations((unsigned short)0), minToSpawn((unsigned int)0), maxToSpawn((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiPSSpawner::~NiPSSpawner() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiPSSpawner::GetType() const {
	return TYPE;
}

NiObject * NiPSSpawner::Create() {
	return new NiPSSpawner;
}

void NiPSSpawner::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	if ( info.version >= 0x14060100 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( percentageSpawned, in, info );
	if ( info.version >= 0x14060100 ) {
		NifStream( spawnSpeedFactor, in, info );
	};
	NifStream( spawnSpeedFactorVar, in, info );
	NifStream( spawnDirChaos, in, info );
	NifStream( lifeSpan, in, info );
	NifStream( lifeSpanVar, in, info );
	NifStream( numSpawnGenerations, in, info );
	NifStream( minToSpawn, in, info );
	NifStream( maxToSpawn, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPSSpawner::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, missing_link_stack, info );
	if ( info.version >= 0x14060100 ) {
		WriteRef( StaticCast<NiObject>(masterParticleSystem), out, info, link_map, missing_link_stack );
	};
	NifStream( percentageSpawned, out, info );
	if ( info.version >= 0x14060100 ) {
		NifStream( spawnSpeedFactor, out, info );
	};
	NifStream( spawnSpeedFactorVar, out, info );
	NifStream( spawnDirChaos, out, info );
	NifStream( lifeSpan, out, info );
	NifStream( lifeSpanVar, out, info );
	NifStream( numSpawnGenerations, out, info );
	NifStream( minToSpawn, out, info );
	NifStream( maxToSpawn, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiPSSpawner::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	out << NiObject::asString();
	out << "  Master Particle System:  " << masterParticleSystem << endl;
	out << "  Percentage Spawned:  " << percentageSpawned << endl;
	out << "  Spawn Speed Factor:  " << spawnSpeedFactor << endl;
	out << "  Spawn Speed Factor Var:  " << spawnSpeedFactorVar << endl;
	out << "  Spawn Dir Chaos:  " << spawnDirChaos << endl;
	out << "  Life Span:  " << lifeSpan << endl;
	out << "  Life Span Var:  " << lifeSpanVar << endl;
	out << "  Num Spawn Generations:  " << numSpawnGenerations << endl;
	out << "  Min to Spawn:  " << minToSpawn << endl;
	out << "  Max to Spawn:  " << maxToSpawn << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPSSpawner::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, missing_link_stack, info );
	if ( info.version >= 0x14060100 ) {
		masterParticleSystem = FixLink<NiPSParticleSystem>( objects, link_stack, missing_link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPSSpawner::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

std::list<NiObject *> NiPSSpawner::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiObject::GetPtrs();
	if ( masterParticleSystem != NULL )
		ptrs.push_back((NiObject *)(masterParticleSystem));
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

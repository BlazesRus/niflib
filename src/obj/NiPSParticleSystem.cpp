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
#include "../../include/obj/NiPSParticleSystem.h"
#include "../../include/gen/PSSpawnRateKey.h"
#include "../../include/obj/NiPSBoundUpdater.h"
#include "../../include/obj/NiPSEmitter.h"
#include "../../include/obj/NiPSSimulator.h"
#include "../../include/obj/NiPSSpawner.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSParticleSystem::TYPE("NiPSParticleSystem", &NiMesh::TYPE );

NiPSParticleSystem::NiPSParticleSystem() : simulator(NULL), generator(NULL), numEmitters((unsigned int)0), numSpawners((unsigned int)0), deathSpawner(NULL), maxNumParticles((unsigned int)0), hasColors(false), hasRotations(false), hasRotationAxes(false), hasAnimatedTextures(false), worldSpace(false), normalMethod((AlignMethod)0), upMethod((AlignMethod)0), livingSpawner(NULL), numSpawnRateKeys((byte)0), pre_rpi(false) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiPSParticleSystem::~NiPSParticleSystem() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiPSParticleSystem::GetType() const {
	return TYPE;
}

NiObject * NiPSParticleSystem::Create() {
	return new NiPSParticleSystem;
}

void NiPSParticleSystem::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiMesh::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( numEmitters, in, info );
	emitters.resize(numEmitters);
	for (unsigned int i1 = 0; i1 < emitters.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( numSpawners, in, info );
	spawners.resize(numSpawners);
	for (unsigned int i1 = 0; i1 < spawners.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( maxNumParticles, in, info );
	NifStream( hasColors, in, info );
	NifStream( hasRotations, in, info );
	NifStream( hasRotationAxes, in, info );
	if ( info.version >= 0x14060100 ) {
		NifStream( hasAnimatedTextures, in, info );
	};
	NifStream( worldSpace, in, info );
	if ( info.version >= 0x14060100 ) {
		NifStream( normalMethod, in, info );
		NifStream( normalDirection, in, info );
		NifStream( upMethod, in, info );
		NifStream( upDirection, in, info );
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
		NifStream( numSpawnRateKeys, in, info );
		spawnRateKeys.resize(numSpawnRateKeys);
		for (unsigned int i2 = 0; i2 < spawnRateKeys.size(); i2++) {
			NifStream( spawnRateKeys[i2].value, in, info );
			NifStream( spawnRateKeys[i2].time, in, info );
		};
		NifStream( pre_rpi, in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPSParticleSystem::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiMesh::Write( out, link_map, missing_link_stack, info );
	numSpawnRateKeys = (byte)(spawnRateKeys.size());
	numSpawners = (unsigned int)(spawners.size());
	numEmitters = (unsigned int)(emitters.size());
	WriteRef( StaticCast<NiObject>(simulator), out, info, link_map, missing_link_stack );
	WriteRef( StaticCast<NiObject>(generator), out, info, link_map, missing_link_stack );
	NifStream( numEmitters, out, info );
	for (unsigned int i1 = 0; i1 < emitters.size(); i1++) {
		WriteRef( StaticCast<NiObject>(emitters[i1]), out, info, link_map, missing_link_stack );
	};
	NifStream( numSpawners, out, info );
	for (unsigned int i1 = 0; i1 < spawners.size(); i1++) {
		WriteRef( StaticCast<NiObject>(spawners[i1]), out, info, link_map, missing_link_stack );
	};
	WriteRef( StaticCast<NiObject>(deathSpawner), out, info, link_map, missing_link_stack );
	NifStream( maxNumParticles, out, info );
	NifStream( hasColors, out, info );
	NifStream( hasRotations, out, info );
	NifStream( hasRotationAxes, out, info );
	if ( info.version >= 0x14060100 ) {
		NifStream( hasAnimatedTextures, out, info );
	};
	NifStream( worldSpace, out, info );
	if ( info.version >= 0x14060100 ) {
		NifStream( normalMethod, out, info );
		NifStream( normalDirection, out, info );
		NifStream( upMethod, out, info );
		NifStream( upDirection, out, info );
		WriteRef( StaticCast<NiObject>(livingSpawner), out, info, link_map, missing_link_stack );
		NifStream( numSpawnRateKeys, out, info );
		for (unsigned int i2 = 0; i2 < spawnRateKeys.size(); i2++) {
			NifStream( spawnRateKeys[i2].value, out, info );
			NifStream( spawnRateKeys[i2].time, out, info );
		};
		NifStream( pre_rpi, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiPSParticleSystem::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiMesh::asString();
	numSpawnRateKeys = (byte)(spawnRateKeys.size());
	numSpawners = (unsigned int)(spawners.size());
	numEmitters = (unsigned int)(emitters.size());
	out << "  Simulator:  " << simulator << endl;
	out << "  Generator:  " << generator << endl;
	out << "  Num Emitters:  " << numEmitters << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < emitters.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Emitters[" << i1 << "]:  " << emitters[i1] << endl;
		array_output_count++;
	};
	out << "  Num Spawners:  " << numSpawners << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < spawners.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Spawners[" << i1 << "]:  " << spawners[i1] << endl;
		array_output_count++;
	};
	out << "  Death Spawner:  " << deathSpawner << endl;
	out << "  Max Num Particles:  " << maxNumParticles << endl;
	out << "  Has Colors:  " << hasColors << endl;
	out << "  Has Rotations:  " << hasRotations << endl;
	out << "  Has Rotation Axes:  " << hasRotationAxes << endl;
	out << "  Has Animated Textures:  " << hasAnimatedTextures << endl;
	out << "  World Space:  " << worldSpace << endl;
	out << "  Normal Method:  " << normalMethod << endl;
	out << "  Normal Direction:  " << normalDirection << endl;
	out << "  Up Method:  " << upMethod << endl;
	out << "  Up Direction:  " << upDirection << endl;
	out << "  Living Spawner:  " << livingSpawner << endl;
	out << "  Num Spawn Rate Keys:  " << numSpawnRateKeys << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < spawnRateKeys.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Value:  " << spawnRateKeys[i1].value << endl;
		out << "    Time:  " << spawnRateKeys[i1].time << endl;
	};
	out << "  Pre-RPI:  " << pre_rpi << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPSParticleSystem::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiMesh::FixLinks( objects, link_stack, missing_link_stack, info );
	simulator = FixLink<NiPSSimulator>( objects, link_stack, missing_link_stack, info );
	generator = FixLink<NiPSBoundUpdater>( objects, link_stack, missing_link_stack, info );
	for (unsigned int i1 = 0; i1 < emitters.size(); i1++) {
		emitters[i1] = FixLink<NiPSEmitter>( objects, link_stack, missing_link_stack, info );
	};
	for (unsigned int i1 = 0; i1 < spawners.size(); i1++) {
		spawners[i1] = FixLink<NiPSSpawner>( objects, link_stack, missing_link_stack, info );
	};
	deathSpawner = FixLink<NiPSSpawner>( objects, link_stack, missing_link_stack, info );
	if ( info.version >= 0x14060100 ) {
		livingSpawner = FixLink<NiPSSpawner>( objects, link_stack, missing_link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPSParticleSystem::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiMesh::GetRefs();
	if ( simulator != NULL )
		refs.push_back(StaticCast<NiObject>(simulator));
	if ( generator != NULL )
		refs.push_back(StaticCast<NiObject>(generator));
	for (unsigned int i1 = 0; i1 < emitters.size(); i1++) {
		if ( emitters[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(emitters[i1]));
	};
	for (unsigned int i1 = 0; i1 < spawners.size(); i1++) {
		if ( spawners[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(spawners[i1]));
	};
	if ( deathSpawner != NULL )
		refs.push_back(StaticCast<NiObject>(deathSpawner));
	if ( livingSpawner != NULL )
		refs.push_back(StaticCast<NiObject>(livingSpawner));
	return refs;
}

std::list<NiObject *> NiPSParticleSystem::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiMesh::GetPtrs();
	for (unsigned int i1 = 0; i1 < emitters.size(); i1++) {
	};
	for (unsigned int i1 = 0; i1 < spawners.size(); i1++) {
	};
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

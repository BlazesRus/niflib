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
#include "../../include/obj/NiPSMeshParticleSystem.h"
#include "../../include/obj/NiAVObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSMeshParticleSystem::TYPE("NiPSMeshParticleSystem", &NiPSParticleSystem::TYPE );

NiPSMeshParticleSystem::NiPSMeshParticleSystem() : numGenerations((unsigned int)0), poolSize((unsigned int)0), auto_fillPools(false) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiPSMeshParticleSystem::~NiPSMeshParticleSystem() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiPSMeshParticleSystem::GetType() const {
	return TYPE;
}

NiObject * NiPSMeshParticleSystem::Create() {
	return new NiPSMeshParticleSystem;
}

void NiPSMeshParticleSystem::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiPSParticleSystem::Read( in, link_stack, info );
	NifStream( numGenerations, in, info );
	masterParticles.resize(numGenerations);
	for (unsigned int i1 = 0; i1 < masterParticles.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( poolSize, in, info );
	NifStream( auto_fillPools, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPSMeshParticleSystem::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPSParticleSystem::Write( out, link_map, missing_link_stack, info );
	numGenerations = (unsigned int)(masterParticles.size());
	NifStream( numGenerations, out, info );
	for (unsigned int i1 = 0; i1 < masterParticles.size(); i1++) {
		WriteRef( StaticCast<NiObject>(masterParticles[i1]), out, info, link_map, missing_link_stack );
	};
	NifStream( poolSize, out, info );
	NifStream( auto_fillPools, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiPSMeshParticleSystem::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPSParticleSystem::asString();
	numGenerations = (unsigned int)(masterParticles.size());
	out << "  Num Generations:  " << numGenerations << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < masterParticles.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Master Particles[" << i1 << "]:  " << masterParticles[i1] << endl;
		array_output_count++;
	};
	out << "  Pool Size:  " << poolSize << endl;
	out << "  Auto-Fill Pools:  " << auto_fillPools << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPSMeshParticleSystem::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPSParticleSystem::FixLinks( objects, link_stack, missing_link_stack, info );
	for (unsigned int i1 = 0; i1 < masterParticles.size(); i1++) {
		masterParticles[i1] = FixLink<NiAVObject>( objects, link_stack, missing_link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPSMeshParticleSystem::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSParticleSystem::GetRefs();
	for (unsigned int i1 = 0; i1 < masterParticles.size(); i1++) {
		if ( masterParticles[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(masterParticles[i1]));
	};
	return refs;
}

std::list<NiObject *> NiPSMeshParticleSystem::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiPSParticleSystem::GetPtrs();
	for (unsigned int i1 = 0; i1 < masterParticles.size(); i1++) {
	};
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

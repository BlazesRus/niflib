/* Copyright (c) 2019, NIF File Format Library and Tools
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
#include "../../include/obj/NiParticleBomb.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiParticleBomb::TYPE("NiParticleBomb", &NiParticleModifier::TYPE );

NiParticleBomb::NiParticleBomb() : decay(0.0f), duration(0.0f), deltav(0.0f), start(0.0f), decayType((DecayType)0), symmetryType((SymmetryType)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiParticleBomb::~NiParticleBomb() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiParticleBomb::GetType() const {
	return TYPE;
}

NiObject * NiParticleBomb::Create() {
	return new NiParticleBomb;
}

void NiParticleBomb::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiParticleModifier::Read( in, link_stack, info );
	NifStream( decay, in, info );
	NifStream( duration, in, info );
	NifStream( deltav, in, info );
	NifStream( start, in, info );
	NifStream( decayType, in, info );
	if ( info.version >= 0x0401000C ) {
		NifStream( symmetryType, in, info );
	};
	NifStream( position, in, info );
	NifStream( direction, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiParticleBomb::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiParticleModifier::Write( out, link_map, missing_link_stack, info );
	NifStream( decay, out, info );
	NifStream( duration, out, info );
	NifStream( deltav, out, info );
	NifStream( start, out, info );
	NifStream( decayType, out, info );
	if ( info.version >= 0x0401000C ) {
		NifStream( symmetryType, out, info );
	};
	NifStream( position, out, info );
	NifStream( direction, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiParticleBomb::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	out << NiParticleModifier::asString();
	out << "  Decay:  " << decay << endl;
	out << "  Duration:  " << duration << endl;
	out << "  DeltaV:  " << deltav << endl;
	out << "  Start:  " << start << endl;
	out << "  Decay Type:  " << decayType << endl;
	out << "  Symmetry Type:  " << symmetryType << endl;
	out << "  Position:  " << position << endl;
	out << "  Direction:  " << direction << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiParticleBomb::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiParticleModifier::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiParticleBomb::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiParticleModifier::GetRefs();
	return refs;
}

std::list<NiObject *> NiParticleBomb::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiParticleModifier::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//

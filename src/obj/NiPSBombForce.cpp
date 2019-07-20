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
#include "../../include/obj/NiPSBombForce.h"
#include "../../include/obj/NiAVObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSBombForce::TYPE("NiPSBombForce", &NiPSForce::TYPE );

NiPSBombForce::NiPSBombForce() : decay(0.0f), deltaV(0.0f), decayType((DecayType)0), symmetryType((SymmetryType)0), bombObject(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiPSBombForce::~NiPSBombForce() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiPSBombForce::GetType() const {
	return TYPE;
}

NiObject * NiPSBombForce::Create() {
	return new NiPSBombForce;
}

void NiPSBombForce::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiPSForce::Read( in, link_stack, info );
	NifStream( bombAxis, in, info );
	NifStream( decay, in, info );
	NifStream( deltaV, in, info );
	NifStream( decayType, in, info );
	NifStream( symmetryType, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPSBombForce::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPSForce::Write( out, link_map, missing_link_stack, info );
	NifStream( bombAxis, out, info );
	NifStream( decay, out, info );
	NifStream( deltaV, out, info );
	NifStream( decayType, out, info );
	NifStream( symmetryType, out, info );
	WriteRef( StaticCast<NiObject>(bombObject), out, info, link_map, missing_link_stack );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiPSBombForce::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	out << NiPSForce::asString();
	out << "  Bomb Axis:  " << bombAxis << endl;
	out << "  Decay:  " << decay << endl;
	out << "  Delta V:  " << deltaV << endl;
	out << "  Decay Type:  " << decayType << endl;
	out << "  Symmetry Type:  " << symmetryType << endl;
	out << "  Bomb Object:  " << bombObject << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPSBombForce::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPSForce::FixLinks( objects, link_stack, missing_link_stack, info );
	bombObject = FixLink<NiAVObject>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPSBombForce::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSForce::GetRefs();
	return refs;
}

std::list<NiObject *> NiPSBombForce::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiPSForce::GetPtrs();
	if ( bombObject != NULL )
		ptrs.push_back((NiObject *)(bombObject));
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

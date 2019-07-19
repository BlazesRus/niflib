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
#include "../../include/obj/NiPSysAirFieldModifier.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysAirFieldModifier::TYPE("NiPSysAirFieldModifier", &NiPSysFieldModifier::TYPE );

NiPSysAirFieldModifier::NiPSysAirFieldModifier() : direction(-1.0, 0.0, 0.0), airFriction(0.0f), inheritVelocity(0.0f), inheritRotation(false), componentOnly(false), enableSpread(false), spread(0.0f) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiPSysAirFieldModifier::~NiPSysAirFieldModifier() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiPSysAirFieldModifier::GetType() const {
	return TYPE;
}

NiObject * NiPSysAirFieldModifier::Create() {
	return new NiPSysAirFieldModifier;
}

void NiPSysAirFieldModifier::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPSysFieldModifier::Read( in, link_stack, info );
	NifStream( direction, in, info );
	NifStream( airFriction, in, info );
	NifStream( inheritVelocity, in, info );
	NifStream( inheritRotation, in, info );
	NifStream( componentOnly, in, info );
	NifStream( enableSpread, in, info );
	NifStream( spread, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPSysAirFieldModifier::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPSysFieldModifier::Write( out, link_map, missing_link_stack, info );
	NifStream( direction, out, info );
	NifStream( airFriction, out, info );
	NifStream( inheritVelocity, out, info );
	NifStream( inheritRotation, out, info );
	NifStream( componentOnly, out, info );
	NifStream( enableSpread, out, info );
	NifStream( spread, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiPSysAirFieldModifier::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	out << NiPSysFieldModifier::asString();
	out << "  Direction:  " << direction << endl;
	out << "  Air Friction:  " << airFriction << endl;
	out << "  Inherit Velocity:  " << inheritVelocity << endl;
	out << "  Inherit Rotation:  " << inheritRotation << endl;
	out << "  Component Only:  " << componentOnly << endl;
	out << "  Enable Spread:  " << enableSpread << endl;
	out << "  Spread:  " << spread << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPSysAirFieldModifier::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPSysFieldModifier::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPSysAirFieldModifier::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysFieldModifier::GetRefs();
	return refs;
}

std::list<NiObject *> NiPSysAirFieldModifier::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiPSysFieldModifier::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

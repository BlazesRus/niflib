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
#include "../../include/obj/NiPhysXKinematicSrc.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPhysXKinematicSrc::TYPE("NiPhysXKinematicSrc", &NiPhysXRigidBodySrc::TYPE );

NiPhysXKinematicSrc::NiPhysXKinematicSrc() {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiPhysXKinematicSrc::~NiPhysXKinematicSrc() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiPhysXKinematicSrc::GetType() const {
	return TYPE;
}

NiObject * NiPhysXKinematicSrc::Create() {
	return new NiPhysXKinematicSrc;
}

void NiPhysXKinematicSrc::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPhysXRigidBodySrc::Read( in, link_stack, info );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPhysXKinematicSrc::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPhysXRigidBodySrc::Write( out, link_map, missing_link_stack, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiPhysXKinematicSrc::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	out << NiPhysXRigidBodySrc::asString();
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPhysXKinematicSrc::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPhysXRigidBodySrc::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPhysXKinematicSrc::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPhysXRigidBodySrc::GetRefs();
	return refs;
}

std::list<NiObject *> NiPhysXKinematicSrc::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiPhysXRigidBodySrc::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

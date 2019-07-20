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
#include "../../include/obj/bhkBlendCollisionObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkBlendCollisionObject::TYPE("bhkBlendCollisionObject", &bhkCollisionObject::TYPE );

bhkBlendCollisionObject::bhkBlendCollisionObject() : heirGain(0.0f), velGain(0.0f) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

bhkBlendCollisionObject::~bhkBlendCollisionObject() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & bhkBlendCollisionObject::GetType() const {
	return TYPE;
}

NiObject * bhkBlendCollisionObject::Create() {
	return new bhkBlendCollisionObject;
}

void bhkBlendCollisionObject::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkCollisionObject::Read( in, link_stack, info );
	NifStream( heirGain, in, info );
	NifStream( velGain, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkBlendCollisionObject::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkCollisionObject::Write( out, link_map, missing_link_stack, info );
	NifStream( heirGain, out, info );
	NifStream( velGain, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string bhkBlendCollisionObject::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	out << bhkCollisionObject::asString();
	out << "  Heir Gain:  " << heirGain << endl;
	out << "  Vel Gain:  " << velGain << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkBlendCollisionObject::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkCollisionObject::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> bhkBlendCollisionObject::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkCollisionObject::GetRefs();
	return refs;
}

std::list<NiObject *> bhkBlendCollisionObject::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = bhkCollisionObject::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//

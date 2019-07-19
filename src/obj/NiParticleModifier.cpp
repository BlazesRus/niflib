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
#include "../../include/obj/NiParticleModifier.h"
#include "../../include/obj/NiParticleSystemController.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiParticleModifier::TYPE("NiParticleModifier", &NiObject::TYPE );

NiParticleModifier::NiParticleModifier() : nextModifier(NULL), controller(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiParticleModifier::~NiParticleModifier() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiParticleModifier::GetType() const {
	return TYPE;
}

NiObject * NiParticleModifier::Create() {
	return new NiParticleModifier;
}

void NiParticleModifier::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	if ( info.version >= 0x04000002 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiParticleModifier::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, missing_link_stack, info );
	WriteRef( StaticCast<NiObject>(nextModifier), out, info, link_map, missing_link_stack );
	if ( info.version >= 0x04000002 ) {
		WriteRef( StaticCast<NiObject>(controller), out, info, link_map, missing_link_stack );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiParticleModifier::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	out << NiObject::asString();
	out << "  Next Modifier:  " << nextModifier << endl;
	out << "  Controller:  " << controller << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiParticleModifier::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, missing_link_stack, info );
	nextModifier = FixLink<NiParticleModifier>( objects, link_stack, missing_link_stack, info );
	if ( info.version >= 0x04000002 ) {
		controller = FixLink<NiParticleSystemController>( objects, link_stack, missing_link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiParticleModifier::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( nextModifier != NULL )
		refs.push_back(StaticCast<NiObject>(nextModifier));
	return refs;
}

std::list<NiObject *> NiParticleModifier::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiObject::GetPtrs();
	if ( controller != NULL )
		ptrs.push_back((NiObject *)(controller));
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

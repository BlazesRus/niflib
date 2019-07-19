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
#include "../../include/obj/NiPSBoxEmitter.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSBoxEmitter::TYPE("NiPSBoxEmitter", &NiPSVolumeEmitter::TYPE );

NiPSBoxEmitter::NiPSBoxEmitter() : emitterWidth(0.0f), emitterHeight(0.0f), emitterDepth(0.0f) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiPSBoxEmitter::~NiPSBoxEmitter() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiPSBoxEmitter::GetType() const {
	return TYPE;
}

NiObject * NiPSBoxEmitter::Create() {
	return new NiPSBoxEmitter;
}

void NiPSBoxEmitter::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPSVolumeEmitter::Read( in, link_stack, info );
	NifStream( emitterWidth, in, info );
	NifStream( emitterHeight, in, info );
	NifStream( emitterDepth, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPSBoxEmitter::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPSVolumeEmitter::Write( out, link_map, missing_link_stack, info );
	NifStream( emitterWidth, out, info );
	NifStream( emitterHeight, out, info );
	NifStream( emitterDepth, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiPSBoxEmitter::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	out << NiPSVolumeEmitter::asString();
	out << "  Emitter Width:  " << emitterWidth << endl;
	out << "  Emitter Height:  " << emitterHeight << endl;
	out << "  Emitter Depth:  " << emitterDepth << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPSBoxEmitter::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPSVolumeEmitter::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPSBoxEmitter::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSVolumeEmitter::GetRefs();
	return refs;
}

std::list<NiObject *> NiPSBoxEmitter::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiPSVolumeEmitter::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

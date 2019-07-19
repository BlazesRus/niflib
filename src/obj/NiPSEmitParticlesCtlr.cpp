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
#include "../../include/obj/NiPSEmitParticlesCtlr.h"
#include "../../include/obj/NiInterpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSEmitParticlesCtlr::TYPE("NiPSEmitParticlesCtlr", &NiPSEmitterCtlr::TYPE );

NiPSEmitParticlesCtlr::NiPSEmitParticlesCtlr() : emitterActiveInterpolator(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiPSEmitParticlesCtlr::~NiPSEmitParticlesCtlr() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiPSEmitParticlesCtlr::GetType() const {
	return TYPE;
}

NiObject * NiPSEmitParticlesCtlr::Create() {
	return new NiPSEmitParticlesCtlr;
}

void NiPSEmitParticlesCtlr::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiPSEmitterCtlr::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPSEmitParticlesCtlr::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPSEmitterCtlr::Write( out, link_map, missing_link_stack, info );
	WriteRef( StaticCast<NiObject>(emitterActiveInterpolator), out, info, link_map, missing_link_stack );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiPSEmitParticlesCtlr::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	out << NiPSEmitterCtlr::asString();
	out << "  Emitter Active Interpolator:  " << emitterActiveInterpolator << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPSEmitParticlesCtlr::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPSEmitterCtlr::FixLinks( objects, link_stack, missing_link_stack, info );
	emitterActiveInterpolator = FixLink<NiInterpolator>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPSEmitParticlesCtlr::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSEmitterCtlr::GetRefs();
	if ( emitterActiveInterpolator != NULL )
		refs.push_back(StaticCast<NiObject>(emitterActiveInterpolator));
	return refs;
}

std::list<NiObject *> NiPSEmitParticlesCtlr::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiPSEmitterCtlr::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

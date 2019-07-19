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
#include "../../include/obj/BSPSysMultiTargetEmitterCtlr.h"
#include "../../include/obj/BSMasterParticleSystem.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSPSysMultiTargetEmitterCtlr::TYPE("BSPSysMultiTargetEmitterCtlr", &NiPSysEmitterCtlr::TYPE );

BSPSysMultiTargetEmitterCtlr::BSPSysMultiTargetEmitterCtlr() : maxEmitters((unsigned short)0), masterParticleSystem(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

BSPSysMultiTargetEmitterCtlr::~BSPSysMultiTargetEmitterCtlr() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & BSPSysMultiTargetEmitterCtlr::GetType() const {
	return TYPE;
}

NiObject * BSPSysMultiTargetEmitterCtlr::Create() {
	return new BSPSysMultiTargetEmitterCtlr;
}

void BSPSysMultiTargetEmitterCtlr::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiPSysEmitterCtlr::Read( in, link_stack, info );
	NifStream( maxEmitters, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSPSysMultiTargetEmitterCtlr::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPSysEmitterCtlr::Write( out, link_map, missing_link_stack, info );
	NifStream( maxEmitters, out, info );
	WriteRef( StaticCast<NiObject>(masterParticleSystem), out, info, link_map, missing_link_stack );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string BSPSysMultiTargetEmitterCtlr::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	out << NiPSysEmitterCtlr::asString();
	out << "  Max Emitters:  " << maxEmitters << endl;
	out << "  Master Particle System:  " << masterParticleSystem << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSPSysMultiTargetEmitterCtlr::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPSysEmitterCtlr::FixLinks( objects, link_stack, missing_link_stack, info );
	masterParticleSystem = FixLink<BSMasterParticleSystem>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> BSPSysMultiTargetEmitterCtlr::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysEmitterCtlr::GetRefs();
	return refs;
}

std::list<NiObject *> BSPSysMultiTargetEmitterCtlr::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiPSysEmitterCtlr::GetPtrs();
	if ( masterParticleSystem != NULL )
		ptrs.push_back((NiObject *)(masterParticleSystem));
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

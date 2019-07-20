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
#include "../../include/obj/NiMeshHWInstance.h"
#include "../../include/obj/NiInstancingMeshModifier.h"
#include "../../include/obj/NiMesh.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiMeshHWInstance::TYPE("NiMeshHWInstance", &NiAVObject::TYPE );

NiMeshHWInstance::NiMeshHWInstance() : masterMesh(NULL), meshModifier(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiMeshHWInstance::~NiMeshHWInstance() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiMeshHWInstance::GetType() const {
	return TYPE;
}

NiObject * NiMeshHWInstance::Create() {
	return new NiMeshHWInstance;
}

void NiMeshHWInstance::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiAVObject::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiMeshHWInstance::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiAVObject::Write( out, link_map, missing_link_stack, info );
	WriteRef( StaticCast<NiObject>(masterMesh), out, info, link_map, missing_link_stack );
	WriteRef( StaticCast<NiObject>(meshModifier), out, info, link_map, missing_link_stack );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiMeshHWInstance::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	out << NiAVObject::asString();
	out << "  Master Mesh:  " << masterMesh << endl;
	out << "  Mesh Modifier:  " << meshModifier << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiMeshHWInstance::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiAVObject::FixLinks( objects, link_stack, missing_link_stack, info );
	masterMesh = FixLink<NiMesh>( objects, link_stack, missing_link_stack, info );
	meshModifier = FixLink<NiInstancingMeshModifier>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiMeshHWInstance::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiAVObject::GetRefs();
	if ( masterMesh != NULL )
		refs.push_back(StaticCast<NiObject>(masterMesh));
	if ( meshModifier != NULL )
		refs.push_back(StaticCast<NiObject>(meshModifier));
	return refs;
}

std::list<NiObject *> NiMeshHWInstance::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiAVObject::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

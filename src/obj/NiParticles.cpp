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
#include "../../include/obj/NiParticles.h"
#include "../../include/gen/BSVertexDesc.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiParticles::TYPE("NiParticles", &NiGeometry::TYPE );

NiParticles::NiParticles() {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiParticles::~NiParticles() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiParticles::GetType() const {
	return TYPE;
}

NiObject * NiParticles::Create() {
	return new NiParticles;
}

void NiParticles::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiGeometry::Read( in, link_stack, info );
	if ( (info.userVersion2 >= 100) ) {
		NifStream( vertexDesc.vf1, in, info );
		NifStream( vertexDesc.vf2, in, info );
		NifStream( vertexDesc.vf3, in, info );
		NifStream( vertexDesc.vf4, in, info );
		NifStream( vertexDesc.vf5, in, info );
		NifStream( vertexDesc.vertexAttributes, in, info );
		NifStream( vertexDesc.vf8, in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiParticles::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiGeometry::Write( out, link_map, missing_link_stack, info );
	if ( (info.userVersion2 >= 100) ) {
		NifStream( vertexDesc.vf1, out, info );
		NifStream( vertexDesc.vf2, out, info );
		NifStream( vertexDesc.vf3, out, info );
		NifStream( vertexDesc.vf4, out, info );
		NifStream( vertexDesc.vf5, out, info );
		NifStream( vertexDesc.vertexAttributes, out, info );
		NifStream( vertexDesc.vf8, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiParticles::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	out << NiGeometry::asString();
	out << "  VF1:  " << vertexDesc.vf1 << endl;
	out << "  VF2:  " << vertexDesc.vf2 << endl;
	out << "  VF3:  " << vertexDesc.vf3 << endl;
	out << "  VF4:  " << vertexDesc.vf4 << endl;
	out << "  VF5:  " << vertexDesc.vf5 << endl;
	out << "  Vertex Attributes:  " << vertexDesc.vertexAttributes << endl;
	out << "  VF8:  " << vertexDesc.vf8 << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiParticles::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiGeometry::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiParticles::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiGeometry::GetRefs();
	return refs;
}

std::list<NiObject *> NiParticles::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiGeometry::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//

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
#include "../../include/obj/NiPSMeshEmitter.h"
#include "../../include/obj/NiAVObject.h"
#include "../../include/obj/NiMesh.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSMeshEmitter::TYPE("NiPSMeshEmitter", &NiPSEmitter::TYPE );

NiPSMeshEmitter::NiPSMeshEmitter() : numMeshEmitters((unsigned int)0), emitterObject(NULL), meshEmissionType((EmitFrom)0), initialVelocityType((VelocityType)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiPSMeshEmitter::~NiPSMeshEmitter() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiPSMeshEmitter::GetType() const {
	return TYPE;
}

NiObject * NiPSMeshEmitter::Create() {
	return new NiPSMeshEmitter;
}

void NiPSMeshEmitter::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiPSEmitter::Read( in, link_stack, info );
	NifStream( numMeshEmitters, in, info );
	meshEmitters.resize(numMeshEmitters);
	for (unsigned int i1 = 0; i1 < meshEmitters.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	if ( info.version <= 0x14060000 ) {
		NifStream( emitAxis, in, info );
	};
	if ( info.version >= 0x14060100 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( meshEmissionType, in, info );
	NifStream( initialVelocityType, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPSMeshEmitter::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPSEmitter::Write( out, link_map, missing_link_stack, info );
	numMeshEmitters = (unsigned int)(meshEmitters.size());
	NifStream( numMeshEmitters, out, info );
	for (unsigned int i1 = 0; i1 < meshEmitters.size(); i1++) {
		WriteRef( StaticCast<NiObject>(meshEmitters[i1]), out, info, link_map, missing_link_stack );
	};
	if ( info.version <= 0x14060000 ) {
		NifStream( emitAxis, out, info );
	};
	if ( info.version >= 0x14060100 ) {
		WriteRef( StaticCast<NiObject>(emitterObject), out, info, link_map, missing_link_stack );
	};
	NifStream( meshEmissionType, out, info );
	NifStream( initialVelocityType, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiPSMeshEmitter::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPSEmitter::asString();
	numMeshEmitters = (unsigned int)(meshEmitters.size());
	out << "  Num Mesh Emitters:  " << numMeshEmitters << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < meshEmitters.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Mesh Emitters[" << i1 << "]:  " << meshEmitters[i1] << endl;
		array_output_count++;
	};
	out << "  Emit Axis:  " << emitAxis << endl;
	out << "  Emitter Object:  " << emitterObject << endl;
	out << "  Mesh Emission Type:  " << meshEmissionType << endl;
	out << "  Initial Velocity Type:  " << initialVelocityType << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPSMeshEmitter::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPSEmitter::FixLinks( objects, link_stack, missing_link_stack, info );
	for (unsigned int i1 = 0; i1 < meshEmitters.size(); i1++) {
		meshEmitters[i1] = FixLink<NiMesh>( objects, link_stack, missing_link_stack, info );
	};
	if ( info.version >= 0x14060100 ) {
		emitterObject = FixLink<NiAVObject>( objects, link_stack, missing_link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPSMeshEmitter::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSEmitter::GetRefs();
	for (unsigned int i1 = 0; i1 < meshEmitters.size(); i1++) {
	};
	return refs;
}

std::list<NiObject *> NiPSMeshEmitter::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiPSEmitter::GetPtrs();
	for (unsigned int i1 = 0; i1 < meshEmitters.size(); i1++) {
		if ( meshEmitters[i1] != NULL )
			ptrs.push_back((NiObject *)(meshEmitters[i1]));
	};
	if ( emitterObject != NULL )
		ptrs.push_back((NiObject *)(emitterObject));
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

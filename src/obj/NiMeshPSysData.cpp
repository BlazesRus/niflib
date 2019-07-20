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
#include "../../include/obj/NiMeshPSysData.h"
#include "../../include/obj/NiNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiMeshPSysData::TYPE("NiMeshPSysData", &NiPSysData::TYPE );

NiMeshPSysData::NiMeshPSysData() : defaultPoolSize((unsigned int)0), fillPoolsOnLoad(false), numGenerations((unsigned int)0), particleMeshes(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiMeshPSysData::~NiMeshPSysData() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiMeshPSysData::GetType() const {
	return TYPE;
}

NiObject * NiMeshPSysData::Create() {
	return new NiMeshPSysData;
}

void NiMeshPSysData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiPSysData::Read( in, link_stack, info );
	if ( info.version >= 0x0A020000 ) {
		NifStream( defaultPoolSize, in, info );
		NifStream( fillPoolsOnLoad, in, info );
		NifStream( numGenerations, in, info );
		generations.resize(numGenerations);
		for (unsigned int i2 = 0; i2 < generations.size(); i2++) {
			NifStream( generations[i2], in, info );
		};
	};
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiMeshPSysData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiPSysData::Write( out, link_map, missing_link_stack, info );
	numGenerations = (unsigned int)(generations.size());
	if ( info.version >= 0x0A020000 ) {
		NifStream( defaultPoolSize, out, info );
		NifStream( fillPoolsOnLoad, out, info );
		NifStream( numGenerations, out, info );
		for (unsigned int i2 = 0; i2 < generations.size(); i2++) {
			NifStream( generations[i2], out, info );
		};
	};
	WriteRef( StaticCast<NiObject>(particleMeshes), out, info, link_map, missing_link_stack );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiMeshPSysData::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPSysData::asString();
	numGenerations = (unsigned int)(generations.size());
	out << "  Default Pool Size:  " << defaultPoolSize << endl;
	out << "  Fill Pools On Load:  " << fillPoolsOnLoad << endl;
	out << "  Num Generations:  " << numGenerations << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < generations.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Generations[" << i1 << "]:  " << generations[i1] << endl;
		array_output_count++;
	};
	out << "  Particle Meshes:  " << particleMeshes << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiMeshPSysData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiPSysData::FixLinks( objects, link_stack, missing_link_stack, info );
	particleMeshes = FixLink<NiNode>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiMeshPSysData::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysData::GetRefs();
	if ( particleMeshes != NULL )
		refs.push_back(StaticCast<NiObject>(particleMeshes));
	return refs;
}

std::list<NiObject *> NiMeshPSysData::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiPSysData::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//

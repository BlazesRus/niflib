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
#include "../../include/obj/NiInstancingMeshModifier.h"
#include "../../include/gen/NiBound.h"
#include "../../include/obj/NiMesh.h"
#include "../../include/obj/NiMeshHWInstance.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiInstancingMeshModifier::TYPE("NiInstancingMeshModifier", &NiMeshModifier::TYPE );

NiInstancingMeshModifier::NiInstancingMeshModifier() : hasInstanceNodes(false), perInstanceCulling(false), hasStaticBounds(false), affectedMesh(NULL), numInstanceNodes((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiInstancingMeshModifier::~NiInstancingMeshModifier() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiInstancingMeshModifier::GetType() const {
	return TYPE;
}

NiObject * NiInstancingMeshModifier::Create() {
	return new NiInstancingMeshModifier;
}

void NiInstancingMeshModifier::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiMeshModifier::Read( in, link_stack, info );
	NifStream( hasInstanceNodes, in, info );
	NifStream( perInstanceCulling, in, info );
	NifStream( hasStaticBounds, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	if ( hasStaticBounds ) {
		NifStream( bound.center, in, info );
		NifStream( bound.radius, in, info );
	};
	if ( hasInstanceNodes ) {
		NifStream( numInstanceNodes, in, info );
		instanceNodes.resize(numInstanceNodes);
		for (unsigned int i2 = 0; i2 < instanceNodes.size(); i2++) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiInstancingMeshModifier::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiMeshModifier::Write( out, link_map, missing_link_stack, info );
	numInstanceNodes = (unsigned int)(instanceNodes.size());
	NifStream( hasInstanceNodes, out, info );
	NifStream( perInstanceCulling, out, info );
	NifStream( hasStaticBounds, out, info );
	WriteRef( StaticCast<NiObject>(affectedMesh), out, info, link_map, missing_link_stack );
	if ( hasStaticBounds ) {
		NifStream( bound.center, out, info );
		NifStream( bound.radius, out, info );
	};
	if ( hasInstanceNodes ) {
		NifStream( numInstanceNodes, out, info );
		for (unsigned int i2 = 0; i2 < instanceNodes.size(); i2++) {
			WriteRef( StaticCast<NiObject>(instanceNodes[i2]), out, info, link_map, missing_link_stack );
		};
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiInstancingMeshModifier::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiMeshModifier::asString();
	numInstanceNodes = (unsigned int)(instanceNodes.size());
	out << "  Has Instance Nodes:  " << hasInstanceNodes << endl;
	out << "  Per Instance Culling:  " << perInstanceCulling << endl;
	out << "  Has Static Bounds:  " << hasStaticBounds << endl;
	out << "  Affected Mesh:  " << affectedMesh << endl;
	if ( hasStaticBounds ) {
		out << "    Center:  " << bound.center << endl;
		out << "    Radius:  " << bound.radius << endl;
	};
	if ( hasInstanceNodes ) {
		out << "    Num Instance Nodes:  " << numInstanceNodes << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < instanceNodes.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Instance Nodes[" << i2 << "]:  " << instanceNodes[i2] << endl;
			array_output_count++;
		};
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiInstancingMeshModifier::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiMeshModifier::FixLinks( objects, link_stack, missing_link_stack, info );
	affectedMesh = FixLink<NiMesh>( objects, link_stack, missing_link_stack, info );
	if ( hasInstanceNodes ) {
		for (unsigned int i2 = 0; i2 < instanceNodes.size(); i2++) {
			instanceNodes[i2] = FixLink<NiMeshHWInstance>( objects, link_stack, missing_link_stack, info );
		};
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiInstancingMeshModifier::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiMeshModifier::GetRefs();
	if ( affectedMesh != NULL )
		refs.push_back(StaticCast<NiObject>(affectedMesh));
	for (unsigned int i1 = 0; i1 < instanceNodes.size(); i1++) {
		if ( instanceNodes[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(instanceNodes[i1]));
	};
	return refs;
}

std::list<NiObject *> NiInstancingMeshModifier::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiMeshModifier::GetPtrs();
	for (unsigned int i1 = 0; i1 < instanceNodes.size(); i1++) {
	};
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

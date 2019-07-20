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
#include "../../include/obj/NiSkinningLODController.h"
#include "../../include/gen/LODInfo.h"
#include "../../include/obj/NiMesh.h"
#include "../../include/obj/NiNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiSkinningLODController::TYPE("NiSkinningLODController", &NiTimeController::TYPE );

NiSkinningLODController::NiSkinningLODController() : currentLod((unsigned int)0), numBones((unsigned int)0), numSkins((unsigned int)0), numLodLevels((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiSkinningLODController::~NiSkinningLODController() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiSkinningLODController::GetType() const {
	return TYPE;
}

NiObject * NiSkinningLODController::Create() {
	return new NiSkinningLODController;
}

void NiSkinningLODController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiTimeController::Read( in, link_stack, info );
	NifStream( currentLod, in, info );
	NifStream( numBones, in, info );
	bones.resize(numBones);
	for (unsigned int i1 = 0; i1 < bones.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( numSkins, in, info );
	skins.resize(numSkins);
	for (unsigned int i1 = 0; i1 < skins.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( numLodLevels, in, info );
	lods.resize(numLodLevels);
	for (unsigned int i1 = 0; i1 < lods.size(); i1++) {
		NifStream( lods[i1].numBones, in, info );
		NifStream( lods[i1].numActiveSkins, in, info );
		lods[i1].skinIndices.resize(lods[i1].numActiveSkins);
		for (unsigned int i2 = 0; i2 < lods[i1].skinIndices.size(); i2++) {
			NifStream( lods[i1].skinIndices[i2], in, info );
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiSkinningLODController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiTimeController::Write( out, link_map, missing_link_stack, info );
	numLodLevels = (unsigned int)(lods.size());
	numSkins = (unsigned int)(skins.size());
	numBones = (unsigned int)(bones.size());
	NifStream( currentLod, out, info );
	NifStream( numBones, out, info );
	for (unsigned int i1 = 0; i1 < bones.size(); i1++) {
		WriteRef( StaticCast<NiObject>(bones[i1]), out, info, link_map, missing_link_stack );
	};
	NifStream( numSkins, out, info );
	for (unsigned int i1 = 0; i1 < skins.size(); i1++) {
		WriteRef( StaticCast<NiObject>(skins[i1]), out, info, link_map, missing_link_stack );
	};
	NifStream( numLodLevels, out, info );
	for (unsigned int i1 = 0; i1 < lods.size(); i1++) {
		lods[i1].numActiveSkins = (unsigned int)(lods[i1].skinIndices.size());
		NifStream( lods[i1].numBones, out, info );
		NifStream( lods[i1].numActiveSkins, out, info );
		for (unsigned int i2 = 0; i2 < lods[i1].skinIndices.size(); i2++) {
			NifStream( lods[i1].skinIndices[i2], out, info );
		};
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiSkinningLODController::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiTimeController::asString();
	numLodLevels = (unsigned int)(lods.size());
	numSkins = (unsigned int)(skins.size());
	numBones = (unsigned int)(bones.size());
	out << "  Current LOD:  " << currentLod << endl;
	out << "  Num Bones:  " << numBones << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < bones.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Bones[" << i1 << "]:  " << bones[i1] << endl;
		array_output_count++;
	};
	out << "  Num Skins:  " << numSkins << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < skins.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Skins[" << i1 << "]:  " << skins[i1] << endl;
		array_output_count++;
	};
	out << "  Num LOD Levels:  " << numLodLevels << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < lods.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		lods[i1].numActiveSkins = (unsigned int)(lods[i1].skinIndices.size());
		out << "    Num Bones:  " << lods[i1].numBones << endl;
		out << "    Num Active Skins:  " << lods[i1].numActiveSkins << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < lods[i1].skinIndices.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Skin Indices[" << i2 << "]:  " << lods[i1].skinIndices[i2] << endl;
			array_output_count++;
		};
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiSkinningLODController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiTimeController::FixLinks( objects, link_stack, missing_link_stack, info );
	for (unsigned int i1 = 0; i1 < bones.size(); i1++) {
		bones[i1] = FixLink<NiNode>( objects, link_stack, missing_link_stack, info );
	};
	for (unsigned int i1 = 0; i1 < skins.size(); i1++) {
		skins[i1] = FixLink<NiMesh>( objects, link_stack, missing_link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiSkinningLODController::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	for (unsigned int i1 = 0; i1 < bones.size(); i1++) {
		if ( bones[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(bones[i1]));
	};
	for (unsigned int i1 = 0; i1 < skins.size(); i1++) {
		if ( skins[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(skins[i1]));
	};
	return refs;
}

std::list<NiObject *> NiSkinningLODController::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiTimeController::GetPtrs();
	for (unsigned int i1 = 0; i1 < bones.size(); i1++) {
	};
	for (unsigned int i1 = 0; i1 < skins.size(); i1++) {
	};
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

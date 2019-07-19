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
#include "../../include/obj/NiRenderObject.h"
#include "../../include/gen/MaterialData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiRenderObject::TYPE("NiRenderObject", &NiAVObject::TYPE );

NiRenderObject::NiRenderObject() {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiRenderObject::~NiRenderObject() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiRenderObject::GetType() const {
	return TYPE;
}

NiObject * NiRenderObject::Create() {
	return new NiRenderObject;
}

void NiRenderObject::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiAVObject::Read( in, link_stack, info );
	if ( ( info.version >= 0x0A000100 ) && ( info.version <= 0x14010003 ) ) {
		NifStream( materialData.hasShader, in, info );
		if ( materialData.hasShader ) {
			NifStream( materialData.shaderName, in, info );
			NifStream( materialData.shaderExtraData, in, info );
		};
	};
	if ( info.version >= 0x14020005 ) {
		NifStream( materialData.numMaterials, in, info );
		materialData.materialName.resize(materialData.numMaterials);
		for (unsigned int i2 = 0; i2 < materialData.materialName.size(); i2++) {
			NifStream( materialData.materialName[i2], in, info );
		};
		materialData.materialExtraData.resize(materialData.numMaterials);
		for (unsigned int i2 = 0; i2 < materialData.materialExtraData.size(); i2++) {
			NifStream( materialData.materialExtraData[i2], in, info );
		};
		NifStream( materialData.activeMaterial, in, info );
	};
	if ( ( info.version >= 0x0A020000 ) && ( info.version <= 0x0A020000 ) && ( info.userVersion == 1 ) ) {
		NifStream( materialData.unknownByte, in, info );
	};
	if ( ( info.version >= 0x0A040001 ) && ( info.version <= 0x0A040001 ) ) {
		NifStream( materialData.unknownInteger2, in, info );
	};
	if ( info.version >= 0x14020007 ) {
		NifStream( materialData.materialNeedsUpdate, in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiRenderObject::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiAVObject::Write( out, link_map, missing_link_stack, info );
	materialData.numMaterials = (unsigned int)(materialData.materialName.size());
	if ( ( info.version >= 0x0A000100 ) && ( info.version <= 0x14010003 ) ) {
		NifStream( materialData.hasShader, out, info );
		if ( materialData.hasShader ) {
			NifStream( materialData.shaderName, out, info );
			NifStream( materialData.shaderExtraData, out, info );
		};
	};
	if ( info.version >= 0x14020005 ) {
		NifStream( materialData.numMaterials, out, info );
		for (unsigned int i2 = 0; i2 < materialData.materialName.size(); i2++) {
			NifStream( materialData.materialName[i2], out, info );
		};
		for (unsigned int i2 = 0; i2 < materialData.materialExtraData.size(); i2++) {
			NifStream( materialData.materialExtraData[i2], out, info );
		};
		NifStream( materialData.activeMaterial, out, info );
	};
	if ( ( info.version >= 0x0A020000 ) && ( info.version <= 0x0A020000 ) && ( info.userVersion == 1 ) ) {
		NifStream( materialData.unknownByte, out, info );
	};
	if ( ( info.version >= 0x0A040001 ) && ( info.version <= 0x0A040001 ) ) {
		NifStream( materialData.unknownInteger2, out, info );
	};
	if ( info.version >= 0x14020007 ) {
		NifStream( materialData.materialNeedsUpdate, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiRenderObject::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiAVObject::asString();
	materialData.numMaterials = (unsigned int)(materialData.materialName.size());
	out << "  Has Shader:  " << materialData.hasShader << endl;
	if ( materialData.hasShader ) {
		out << "    Shader Name:  " << materialData.shaderName << endl;
		out << "    Shader Extra Data:  " << materialData.shaderExtraData << endl;
	};
	out << "  Num Materials:  " << materialData.numMaterials << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < materialData.materialName.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Material Name[" << i1 << "]:  " << materialData.materialName[i1] << endl;
		array_output_count++;
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < materialData.materialExtraData.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Material Extra Data[" << i1 << "]:  " << materialData.materialExtraData[i1] << endl;
		array_output_count++;
	};
	out << "  Active Material:  " << materialData.activeMaterial << endl;
	out << "  Unknown Byte:  " << materialData.unknownByte << endl;
	out << "  Unknown Integer 2:  " << materialData.unknownInteger2 << endl;
	out << "  Material Needs Update:  " << materialData.materialNeedsUpdate << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiRenderObject::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiAVObject::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiRenderObject::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiAVObject::GetRefs();
	return refs;
}

std::list<NiObject *> NiRenderObject::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiAVObject::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

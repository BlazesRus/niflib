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
#include "../../include/obj/NiPhysXMeshDesc.h"
#include "../../include/gen/ByteArray.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPhysXMeshDesc::TYPE("NiPhysXMeshDesc", &NiObject::TYPE );

NiPhysXMeshDesc::NiPhysXMeshDesc() : isConvex(false), meshSize((unsigned short)0), meshFlags((unsigned int)0), meshPagingMode((unsigned int)0), isHardware(false), flags((byte)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiPhysXMeshDesc::~NiPhysXMeshDesc() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiPhysXMeshDesc::GetType() const {
	return TYPE;
}

NiObject * NiPhysXMeshDesc::Create() {
	return new NiPhysXMeshDesc;
}

void NiPhysXMeshDesc::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::Read( in, link_stack, info );
	if ( info.version <= 0x14030004 ) {
		NifStream( isConvex, in, info );
	};
	NifStream( meshName, in, info );
	NifStream( meshData.dataSize, in, info );
	meshData.data.resize(meshData.dataSize);
	for (unsigned int i1 = 0; i1 < meshData.data.size(); i1++) {
		NifStream( meshData.data[i1], in, info );
	};
	if ( ( info.version >= 0x14030005 ) && ( info.version <= 0x1E020002 ) ) {
		NifStream( meshSize, in, info );
		meshData.data.resize(meshSize);
		for (unsigned int i2 = 0; i2 < meshData.data.size(); i2++) {
			NifStream( (unsigned short&)meshData.data[i2], in, info );
		};
	};
	NifStream( meshFlags, in, info );
	if ( info.version >= 0x14030001 ) {
		NifStream( meshPagingMode, in, info );
	};
	if ( ( info.version >= 0x14030002 ) && ( info.version <= 0x14030004 ) ) {
		NifStream( isHardware, in, info );
	};
	if ( info.version >= 0x14030005 ) {
		NifStream( flags, in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPhysXMeshDesc::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, missing_link_stack, info );
	meshSize = (unsigned short)(meshData.data.size());
	if ( info.version <= 0x14030004 ) {
		NifStream( isConvex, out, info );
	};
	NifStream( meshName, out, info );
	meshData.dataSize = (unsigned int)(meshData.data.size());
	NifStream( meshData.dataSize, out, info );
	for (unsigned int i1 = 0; i1 < meshData.data.size(); i1++) {
		NifStream( meshData.data[i1], out, info );
	};
	if ( ( info.version >= 0x14030005 ) && ( info.version <= 0x1E020002 ) ) {
		NifStream( meshSize, out, info );
		for (unsigned int i2 = 0; i2 < meshData.data.size(); i2++) {
			NifStream( (unsigned short&)meshData.data[i2], out, info );
		};
	};
	NifStream( meshFlags, out, info );
	if ( info.version >= 0x14030001 ) {
		NifStream( meshPagingMode, out, info );
	};
	if ( ( info.version >= 0x14030002 ) && ( info.version <= 0x14030004 ) ) {
		NifStream( isHardware, out, info );
	};
	if ( info.version >= 0x14030005 ) {
		NifStream( flags, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiPhysXMeshDesc::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	meshSize = (unsigned short)(meshData.data.size());
	out << "  Is Convex:  " << isConvex << endl;
	out << "  Mesh Name:  " << meshName << endl;
	meshData.dataSize = (unsigned int)(meshData.data.size());
	out << "  Data Size:  " << meshData.dataSize << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < meshData.data.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Data[" << i1 << "]:  " << meshData.data[i1] << endl;
		array_output_count++;
	};
	out << "  Mesh Size:  " << meshSize << endl;
	out << "  Mesh Flags:  " << meshFlags << endl;
	out << "  Mesh Paging Mode:  " << meshPagingMode << endl;
	out << "  Is Hardware:  " << isHardware << endl;
	out << "  Flags:  " << flags << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPhysXMeshDesc::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPhysXMeshDesc::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

std::list<NiObject *> NiPhysXMeshDesc::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiObject::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

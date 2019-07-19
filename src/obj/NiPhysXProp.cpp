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
#include "../../include/obj/NiPhysXProp.h"
#include "../../include/obj/NiMesh.h"
#include "../../include/obj/NiObject.h"
#include "../../include/obj/NiPhysXDest.h"
#include "../../include/obj/NiPhysXPropDesc.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPhysXProp::TYPE("NiPhysXProp", &NiObjectNET::TYPE );

NiPhysXProp::NiPhysXProp() : physxToWorldScale(0.0f), numSources((unsigned int)0), numDests((int)0), numModifiedMeshes((unsigned int)0), keepMeshes(false), propDescription(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiPhysXProp::~NiPhysXProp() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiPhysXProp::GetType() const {
	return TYPE;
}

NiObject * NiPhysXProp::Create() {
	return new NiPhysXProp;
}

void NiPhysXProp::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiObjectNET::Read( in, link_stack, info );
	NifStream( physxToWorldScale, in, info );
	NifStream( numSources, in, info );
	sources.resize(numSources);
	for (unsigned int i1 = 0; i1 < sources.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( numDests, in, info );
	dests.resize(numDests);
	for (unsigned int i1 = 0; i1 < dests.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	if ( info.version >= 0x14040000 ) {
		NifStream( numModifiedMeshes, in, info );
		modifiedMeshes.resize(numModifiedMeshes);
		for (unsigned int i2 = 0; i2 < modifiedMeshes.size(); i2++) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
	};
	if ( ( info.version >= 0x1E010002 ) && ( info.version <= 0x1E020002 ) ) {
		NifStream( tempName, in, info );
	};
	NifStream( keepMeshes, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPhysXProp::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObjectNET::Write( out, link_map, missing_link_stack, info );
	numModifiedMeshes = (unsigned int)(modifiedMeshes.size());
	numDests = (int)(dests.size());
	numSources = (unsigned int)(sources.size());
	NifStream( physxToWorldScale, out, info );
	NifStream( numSources, out, info );
	for (unsigned int i1 = 0; i1 < sources.size(); i1++) {
		WriteRef( StaticCast<NiObject>(sources[i1]), out, info, link_map, missing_link_stack );
	};
	NifStream( numDests, out, info );
	for (unsigned int i1 = 0; i1 < dests.size(); i1++) {
		WriteRef( StaticCast<NiObject>(dests[i1]), out, info, link_map, missing_link_stack );
	};
	if ( info.version >= 0x14040000 ) {
		NifStream( numModifiedMeshes, out, info );
		for (unsigned int i2 = 0; i2 < modifiedMeshes.size(); i2++) {
			WriteRef( StaticCast<NiObject>(modifiedMeshes[i2]), out, info, link_map, missing_link_stack );
		};
	};
	if ( ( info.version >= 0x1E010002 ) && ( info.version <= 0x1E020002 ) ) {
		NifStream( tempName, out, info );
	};
	NifStream( keepMeshes, out, info );
	WriteRef( StaticCast<NiObject>(propDescription), out, info, link_map, missing_link_stack );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiPhysXProp::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObjectNET::asString();
	numModifiedMeshes = (unsigned int)(modifiedMeshes.size());
	numDests = (int)(dests.size());
	numSources = (unsigned int)(sources.size());
	out << "  PhysX to World Scale:  " << physxToWorldScale << endl;
	out << "  Num Sources:  " << numSources << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < sources.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Sources[" << i1 << "]:  " << sources[i1] << endl;
		array_output_count++;
	};
	out << "  Num Dests:  " << numDests << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < dests.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Dests[" << i1 << "]:  " << dests[i1] << endl;
		array_output_count++;
	};
	out << "  Num Modified Meshes:  " << numModifiedMeshes << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < modifiedMeshes.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Modified Meshes[" << i1 << "]:  " << modifiedMeshes[i1] << endl;
		array_output_count++;
	};
	out << "  Temp Name:  " << tempName << endl;
	out << "  Keep Meshes:  " << keepMeshes << endl;
	out << "  Prop Description:  " << propDescription << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPhysXProp::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObjectNET::FixLinks( objects, link_stack, missing_link_stack, info );
	for (unsigned int i1 = 0; i1 < sources.size(); i1++) {
		sources[i1] = FixLink<NiObject>( objects, link_stack, missing_link_stack, info );
	};
	for (unsigned int i1 = 0; i1 < dests.size(); i1++) {
		dests[i1] = FixLink<NiPhysXDest>( objects, link_stack, missing_link_stack, info );
	};
	if ( info.version >= 0x14040000 ) {
		for (unsigned int i2 = 0; i2 < modifiedMeshes.size(); i2++) {
			modifiedMeshes[i2] = FixLink<NiMesh>( objects, link_stack, missing_link_stack, info );
		};
	};
	propDescription = FixLink<NiPhysXPropDesc>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPhysXProp::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObjectNET::GetRefs();
	for (unsigned int i1 = 0; i1 < sources.size(); i1++) {
		if ( sources[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(sources[i1]));
	};
	for (unsigned int i1 = 0; i1 < dests.size(); i1++) {
		if ( dests[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(dests[i1]));
	};
	for (unsigned int i1 = 0; i1 < modifiedMeshes.size(); i1++) {
		if ( modifiedMeshes[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(modifiedMeshes[i1]));
	};
	if ( propDescription != NULL )
		refs.push_back(StaticCast<NiObject>(propDescription));
	return refs;
}

std::list<NiObject *> NiPhysXProp::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiObjectNET::GetPtrs();
	for (unsigned int i1 = 0; i1 < sources.size(); i1++) {
	};
	for (unsigned int i1 = 0; i1 < dests.size(); i1++) {
	};
	for (unsigned int i1 = 0; i1 < modifiedMeshes.size(); i1++) {
	};
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

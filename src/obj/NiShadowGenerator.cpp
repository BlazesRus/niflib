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
#include "../../include/obj/NiShadowGenerator.h"
#include "../../include/obj/NiDynamicEffect.h"
#include "../../include/obj/NiNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiShadowGenerator::TYPE("NiShadowGenerator", &NiObject::TYPE );

NiShadowGenerator::NiShadowGenerator() : flags((unsigned short)0), numShadowCasters((unsigned int)0), numShadowReceivers((unsigned int)0), target(NULL), depthBias(0.98f), sizeHint((unsigned short)0), nearClippingDistance(0.0f), farClippingDistance(0.0f), directionalLightFrustumWidth(0.0f) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiShadowGenerator::~NiShadowGenerator() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiShadowGenerator::GetType() const {
	return TYPE;
}

NiObject * NiShadowGenerator::Create() {
	return new NiShadowGenerator;
}

void NiShadowGenerator::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	NifStream( name, in, info );
	NifStream( flags, in, info );
	NifStream( numShadowCasters, in, info );
	shadowCasters.resize(numShadowCasters);
	for (unsigned int i1 = 0; i1 < shadowCasters.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( numShadowReceivers, in, info );
	shadowReceivers.resize(numShadowReceivers);
	for (unsigned int i1 = 0; i1 < shadowReceivers.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( depthBias, in, info );
	NifStream( sizeHint, in, info );
	if ( info.version >= 0x14030007 ) {
		NifStream( nearClippingDistance, in, info );
		NifStream( farClippingDistance, in, info );
		NifStream( directionalLightFrustumWidth, in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiShadowGenerator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, missing_link_stack, info );
	numShadowReceivers = (unsigned int)(shadowReceivers.size());
	numShadowCasters = (unsigned int)(shadowCasters.size());
	NifStream( name, out, info );
	NifStream( flags, out, info );
	NifStream( numShadowCasters, out, info );
	for (unsigned int i1 = 0; i1 < shadowCasters.size(); i1++) {
		WriteRef( StaticCast<NiObject>(shadowCasters[i1]), out, info, link_map, missing_link_stack );
	};
	NifStream( numShadowReceivers, out, info );
	for (unsigned int i1 = 0; i1 < shadowReceivers.size(); i1++) {
		WriteRef( StaticCast<NiObject>(shadowReceivers[i1]), out, info, link_map, missing_link_stack );
	};
	WriteRef( StaticCast<NiObject>(target), out, info, link_map, missing_link_stack );
	NifStream( depthBias, out, info );
	NifStream( sizeHint, out, info );
	if ( info.version >= 0x14030007 ) {
		NifStream( nearClippingDistance, out, info );
		NifStream( farClippingDistance, out, info );
		NifStream( directionalLightFrustumWidth, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiShadowGenerator::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numShadowReceivers = (unsigned int)(shadowReceivers.size());
	numShadowCasters = (unsigned int)(shadowCasters.size());
	out << "  Name:  " << name << endl;
	out << "  Flags:  " << flags << endl;
	out << "  Num Shadow Casters:  " << numShadowCasters << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < shadowCasters.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Shadow Casters[" << i1 << "]:  " << shadowCasters[i1] << endl;
		array_output_count++;
	};
	out << "  Num Shadow Receivers:  " << numShadowReceivers << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < shadowReceivers.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Shadow Receivers[" << i1 << "]:  " << shadowReceivers[i1] << endl;
		array_output_count++;
	};
	out << "  Target:  " << target << endl;
	out << "  Depth Bias:  " << depthBias << endl;
	out << "  Size Hint:  " << sizeHint << endl;
	out << "  Near Clipping Distance:  " << nearClippingDistance << endl;
	out << "  Far Clipping Distance:  " << farClippingDistance << endl;
	out << "  Directional Light Frustum Width:  " << directionalLightFrustumWidth << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiShadowGenerator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, missing_link_stack, info );
	for (unsigned int i1 = 0; i1 < shadowCasters.size(); i1++) {
		shadowCasters[i1] = FixLink<NiNode>( objects, link_stack, missing_link_stack, info );
	};
	for (unsigned int i1 = 0; i1 < shadowReceivers.size(); i1++) {
		shadowReceivers[i1] = FixLink<NiNode>( objects, link_stack, missing_link_stack, info );
	};
	target = FixLink<NiDynamicEffect>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiShadowGenerator::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	for (unsigned int i1 = 0; i1 < shadowCasters.size(); i1++) {
		if ( shadowCasters[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(shadowCasters[i1]));
	};
	for (unsigned int i1 = 0; i1 < shadowReceivers.size(); i1++) {
		if ( shadowReceivers[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(shadowReceivers[i1]));
	};
	return refs;
}

std::list<NiObject *> NiShadowGenerator::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiObject::GetPtrs();
	for (unsigned int i1 = 0; i1 < shadowCasters.size(); i1++) {
	};
	for (unsigned int i1 = 0; i1 < shadowReceivers.size(); i1++) {
	};
	if ( target != NULL )
		ptrs.push_back((NiObject *)(target));
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

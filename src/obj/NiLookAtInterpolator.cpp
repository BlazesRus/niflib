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
#include "../../include/obj/NiLookAtInterpolator.h"
#include "../../include/gen/NiQuatTransform.h"
#include "../../include/obj/NiFloatInterpolator.h"
#include "../../include/obj/NiNode.h"
#include "../../include/obj/NiPoint3Interpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiLookAtInterpolator::TYPE("NiLookAtInterpolator", &NiInterpolator::TYPE );

NiLookAtInterpolator::NiLookAtInterpolator() : flags((LookAtFlags)0), lookAt(NULL), interpolator_Translation(NULL), interpolator_Roll(NULL), interpolator_Scale(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiLookAtInterpolator::~NiLookAtInterpolator() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiLookAtInterpolator::GetType() const {
	return TYPE;
}

NiObject * NiLookAtInterpolator::Create() {
	return new NiLookAtInterpolator;
}

void NiLookAtInterpolator::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiInterpolator::Read( in, link_stack, info );
	NifStream( flags, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( lookAtName, in, info );
	if ( info.version <= 0x1404000C ) {
		NifStream( transform.translation, in, info );
		NifStream( transform.rotation, in, info );
		NifStream( transform.scale, in, info );
		if ( info.version <= 0x0A01006D ) {
			for (unsigned int i3 = 0; i3 < 3; i3++) {
				{
					bool tmp;
					NifStream( tmp, in, info );
					transform.trsValid[i3] = tmp;
				};
			};
		};
	};
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiLookAtInterpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiInterpolator::Write( out, link_map, missing_link_stack, info );
	NifStream( flags, out, info );
	WriteRef( StaticCast<NiObject>(lookAt), out, info, link_map, missing_link_stack );
	NifStream( lookAtName, out, info );
	if ( info.version <= 0x1404000C ) {
		NifStream( transform.translation, out, info );
		NifStream( transform.rotation, out, info );
		NifStream( transform.scale, out, info );
		if ( info.version <= 0x0A01006D ) {
			for (unsigned int i3 = 0; i3 < 3; i3++) {
				{
					bool tmp = transform.trsValid[i3];
					NifStream( tmp, out, info );
				};
			};
		};
	};
	WriteRef( StaticCast<NiObject>(interpolator_Translation), out, info, link_map, missing_link_stack );
	WriteRef( StaticCast<NiObject>(interpolator_Roll), out, info, link_map, missing_link_stack );
	WriteRef( StaticCast<NiObject>(interpolator_Scale), out, info, link_map, missing_link_stack );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiLookAtInterpolator::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiInterpolator::asString();
	out << "  Flags:  " << flags << endl;
	out << "  Look At:  " << lookAt << endl;
	out << "  Look At Name:  " << lookAtName << endl;
	out << "  Translation:  " << transform.translation << endl;
	out << "  Rotation:  " << transform.rotation << endl;
	out << "  Scale:  " << transform.scale << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    TRS Valid[" << i1 << "]:  " << transform.trsValid[i1] << endl;
		array_output_count++;
	};
	out << "  Interpolator: Translation:  " << interpolator_Translation << endl;
	out << "  Interpolator: Roll:  " << interpolator_Roll << endl;
	out << "  Interpolator: Scale:  " << interpolator_Scale << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiLookAtInterpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiInterpolator::FixLinks( objects, link_stack, missing_link_stack, info );
	lookAt = FixLink<NiNode>( objects, link_stack, missing_link_stack, info );
	interpolator_Translation = FixLink<NiPoint3Interpolator>( objects, link_stack, missing_link_stack, info );
	interpolator_Roll = FixLink<NiFloatInterpolator>( objects, link_stack, missing_link_stack, info );
	interpolator_Scale = FixLink<NiFloatInterpolator>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiLookAtInterpolator::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiInterpolator::GetRefs();
	if ( interpolator_Translation != NULL )
		refs.push_back(StaticCast<NiObject>(interpolator_Translation));
	if ( interpolator_Roll != NULL )
		refs.push_back(StaticCast<NiObject>(interpolator_Roll));
	if ( interpolator_Scale != NULL )
		refs.push_back(StaticCast<NiObject>(interpolator_Scale));
	return refs;
}

std::list<NiObject *> NiLookAtInterpolator::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiInterpolator::GetPtrs();
	if ( lookAt != NULL )
		ptrs.push_back((NiObject *)(lookAt));
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

Ref<NiNode> NiLookAtInterpolator::GetLookAt() const {
	return lookAt;
}

void NiLookAtInterpolator::SetLookAt( Ref<NiNode > value ) {
	lookAt = value;
}

Vector3 NiLookAtInterpolator::GetTranslation() const {
	return translation;
}

void NiLookAtInterpolator::SetTranslation( Vector3 value ) {
	translation = value;
}

Quaternion NiLookAtInterpolator::GetRotation() const {
	return rotation;
}

void NiLookAtInterpolator::SetRotation( Quaternion value ) {
	rotation = value;
}

float NiLookAtInterpolator::GetScale() const {
	return scale;
}

void NiLookAtInterpolator::SetScale( float value ) {
	scale = value;
}

//--END CUSTOM CODE--//

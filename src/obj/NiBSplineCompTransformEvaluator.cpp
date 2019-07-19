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
#include "../../include/obj/NiBSplineCompTransformEvaluator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBSplineCompTransformEvaluator::TYPE("NiBSplineCompTransformEvaluator", &NiBSplineTransformEvaluator::TYPE );

NiBSplineCompTransformEvaluator::NiBSplineCompTransformEvaluator() : translationOffset(3.402823466e+38f), translationHalfRange(3.402823466e+38f), rotationOffset(3.402823466e+38f), rotationHalfRange(3.402823466e+38f), scaleOffset(3.402823466e+38f), scaleHalfRange(3.402823466e+38f) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiBSplineCompTransformEvaluator::~NiBSplineCompTransformEvaluator() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiBSplineCompTransformEvaluator::GetType() const {
	return TYPE;
}

NiObject * NiBSplineCompTransformEvaluator::Create() {
	return new NiBSplineCompTransformEvaluator;
}

void NiBSplineCompTransformEvaluator::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiBSplineTransformEvaluator::Read( in, link_stack, info );
	NifStream( translationOffset, in, info );
	NifStream( translationHalfRange, in, info );
	NifStream( rotationOffset, in, info );
	NifStream( rotationHalfRange, in, info );
	NifStream( scaleOffset, in, info );
	NifStream( scaleHalfRange, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiBSplineCompTransformEvaluator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiBSplineTransformEvaluator::Write( out, link_map, missing_link_stack, info );
	NifStream( translationOffset, out, info );
	NifStream( translationHalfRange, out, info );
	NifStream( rotationOffset, out, info );
	NifStream( rotationHalfRange, out, info );
	NifStream( scaleOffset, out, info );
	NifStream( scaleHalfRange, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiBSplineCompTransformEvaluator::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	out << NiBSplineTransformEvaluator::asString();
	out << "  Translation Offset:  " << translationOffset << endl;
	out << "  Translation Half Range:  " << translationHalfRange << endl;
	out << "  Rotation Offset:  " << rotationOffset << endl;
	out << "  Rotation Half Range:  " << rotationHalfRange << endl;
	out << "  Scale Offset:  " << scaleOffset << endl;
	out << "  Scale Half Range:  " << scaleHalfRange << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiBSplineCompTransformEvaluator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiBSplineTransformEvaluator::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiBSplineCompTransformEvaluator::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiBSplineTransformEvaluator::GetRefs();
	return refs;
}

std::list<NiObject *> NiBSplineCompTransformEvaluator::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiBSplineTransformEvaluator::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

//--BEGIN FILE HEAD CUSTOM CODE--//
#include "../../include/obj/NiBSplineBasisData.h"
#include "../../include/obj/NiBSplineData.h"
static const int SizeofValue = 1;
//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/ObjectRegistry.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/NiBSplineCompFloatInterpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBSplineCompFloatInterpolator::TYPE("NiBSplineCompFloatInterpolator", &NiBSplineFloatInterpolator::TYPE );

NiBSplineCompFloatInterpolator::NiBSplineCompFloatInterpolator() : floatOffset(3.402823466e+38f), floatHalfRange(3.402823466e+38f) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiBSplineCompFloatInterpolator::~NiBSplineCompFloatInterpolator() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiBSplineCompFloatInterpolator::GetType() const {
	return TYPE;
}

NiObject * NiBSplineCompFloatInterpolator::Create() {
	return new NiBSplineCompFloatInterpolator;
}

void NiBSplineCompFloatInterpolator::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiBSplineFloatInterpolator::Read( in, link_stack, info );
	NifStream( floatOffset, in, info );
	NifStream( floatHalfRange, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiBSplineCompFloatInterpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiBSplineFloatInterpolator::Write( out, link_map, missing_link_stack, info );
	NifStream( floatOffset, out, info );
	NifStream( floatHalfRange, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiBSplineCompFloatInterpolator::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	out << NiBSplineFloatInterpolator::asString();
	out << "  Float Offset:  " << floatOffset << endl;
	out << "  Float Half Range:  " << floatHalfRange << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiBSplineCompFloatInterpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiBSplineFloatInterpolator::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiBSplineCompFloatInterpolator::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiBSplineFloatInterpolator::GetRefs();
	return refs;
}

std::list<NiObject *> NiBSplineCompFloatInterpolator::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiBSplineFloatInterpolator::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

int NiBSplineCompFloatInterpolator::GetNumControlPoints() const
{
	if (basisData)
	{
		return basisData->GetNumControlPoints();
	}
	return 0;
}

float Niflib::NiBSplineCompFloatInterpolator::GetOffset() const
{
	return floatOffset;
}

float Niflib::NiBSplineCompFloatInterpolator::GetHalfRange() const
{
	return floatHalfRange;
}

void Niflib::NiBSplineCompFloatInterpolator::SetHalfRange(float value)
{
	floatHalfRange = value;
}

void Niflib::NiBSplineCompFloatInterpolator::SetOffset(float value)
{
	floatOffset = value;
}

//--END CUSTOM CODE--//

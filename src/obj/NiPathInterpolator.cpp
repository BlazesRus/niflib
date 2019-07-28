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
#include "../../include/obj/NiPathInterpolator.h"
#include "../../include/obj/NiFloatData.h"
#include "../../include/obj/NiPosData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPathInterpolator::TYPE("NiPathInterpolator", &NiKeyBasedInterpolator::TYPE );

NiPathInterpolator::NiPathInterpolator() : flags((PathFlags)3), bankDir((int)1), maxBankAngle(0.0f), smoothing(0.0f), followAxis((short)0), pathData(NULL), percentData(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiPathInterpolator::~NiPathInterpolator() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiPathInterpolator::GetType() const {
	return TYPE;
}

NiObject * NiPathInterpolator::Create() {
	return new NiPathInterpolator;
}

void NiPathInterpolator::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiKeyBasedInterpolator::Read( in, link_stack, info );
	NifStream( flags, in, info );
	NifStream( bankDir, in, info );
	NifStream( maxBankAngle, in, info );
	NifStream( smoothing, in, info );
	NifStream( followAxis, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiPathInterpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiKeyBasedInterpolator::Write( out, link_map, missing_link_stack, info );
	NifStream( flags, out, info );
	NifStream( bankDir, out, info );
	NifStream( maxBankAngle, out, info );
	NifStream( smoothing, out, info );
	NifStream( followAxis, out, info );
	WriteRef( StaticCast<NiObject>(pathData), out, info, link_map, missing_link_stack );
	WriteRef( StaticCast<NiObject>(percentData), out, info, link_map, missing_link_stack );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiPathInterpolator::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	out << NiKeyBasedInterpolator::asString();
	out << "  Flags:  " << flags << endl;
	out << "  Bank Dir:  " << bankDir << endl;
	out << "  Max Bank Angle:  " << maxBankAngle << endl;
	out << "  Smoothing:  " << smoothing << endl;
	out << "  Follow Axis:  " << followAxis << endl;
	out << "  Path Data:  " << pathData << endl;
	out << "  Percent Data:  " << percentData << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiPathInterpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiKeyBasedInterpolator::FixLinks( objects, link_stack, missing_link_stack, info );
	pathData = FixLink<NiPosData>( objects, link_stack, missing_link_stack, info );
	percentData = FixLink<NiFloatData>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPathInterpolator::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiKeyBasedInterpolator::GetRefs();
	if ( pathData != NULL )
		refs.push_back(StaticCast<NiObject>(pathData));
	if ( percentData != NULL )
		refs.push_back(StaticCast<NiObject>(percentData));
	return refs;
}

std::list<NiObject *> NiPathInterpolator::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiKeyBasedInterpolator::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

PathFlags NiPathInterpolator::GetPathFlags() const
{
	return flags;
}

void NiPathInterpolator::SetPathFlags(PathFlags value)
{
	flags = value;
}

float NiPathInterpolator::GetBankDir() const
{
	return bankDir;
}

void NiPathInterpolator::SetBankDir(float value)
{
	bankDir = value;
}

float NiPathInterpolator::GetMaxBankAngle() const
{
	return maxBankAngle;
}

void NiPathInterpolator::SetMaxBankAngle(float value)
{
	maxBankAngle = value;
}

float NiPathInterpolator::GetSmoothing() const
{
	return smoothing;
}

void NiPathInterpolator::SetSmoothing(float value)
{
	smoothing = value;
}

float NiPathInterpolator::GetFollowAxis() const
{
	return followAxis;
}

void NiPathInterpolator::SetFollowAxis(float value)
{
	followAxis = value;
}

Ref<NiPosData> NiPathInterpolator::GetPathData() const
{
	return pathData;
}

void NiPathInterpolator::SetPathData(const Ref<NiPosData>& value)
{
	pathData = value;
}

Ref<NiFloatData> NiPathInterpolator::GetPercentData() const
{
	return percentData;
}

void NiPathInterpolator::SetPercentData(const Ref<NiFloatData>& value)
{
	percentData = value;
}

//--END CUSTOM CODE--//

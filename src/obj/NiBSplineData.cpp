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
#include "../../include/obj/NiBSplineData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBSplineData::TYPE("NiBSplineData", &NiObject::TYPE );

NiBSplineData::NiBSplineData() : numFloatControlPoints((unsigned int)0), numCompactControlPoints((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiBSplineData::~NiBSplineData() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiBSplineData::GetType() const {
	return TYPE;
}

NiObject * NiBSplineData::Create() {
	return new NiBSplineData;
}

void NiBSplineData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::Read( in, link_stack, info );
	NifStream( numFloatControlPoints, in, info );
	floatControlPoints.resize(numFloatControlPoints);
	for (unsigned int i1 = 0; i1 < floatControlPoints.size(); i1++) {
		NifStream( floatControlPoints[i1], in, info );
	};
	NifStream( numCompactControlPoints, in, info );
	compactControlPoints.resize(numCompactControlPoints);
	for (unsigned int i1 = 0; i1 < compactControlPoints.size(); i1++) {
		NifStream( compactControlPoints[i1], in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiBSplineData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, missing_link_stack, info );
	numCompactControlPoints = (unsigned int)(compactControlPoints.size());
	numFloatControlPoints = (unsigned int)(floatControlPoints.size());
	NifStream( numFloatControlPoints, out, info );
	for (unsigned int i1 = 0; i1 < floatControlPoints.size(); i1++) {
		NifStream( floatControlPoints[i1], out, info );
	};
	NifStream( numCompactControlPoints, out, info );
	for (unsigned int i1 = 0; i1 < compactControlPoints.size(); i1++) {
		NifStream( compactControlPoints[i1], out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiBSplineData::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numCompactControlPoints = (unsigned int)(compactControlPoints.size());
	numFloatControlPoints = (unsigned int)(floatControlPoints.size());
	out << "  Num Float Control Points:  " << numFloatControlPoints << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < floatControlPoints.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Float Control Points[" << i1 << "]:  " << floatControlPoints[i1] << endl;
		array_output_count++;
	};
	out << "  Num Compact Control Points:  " << numCompactControlPoints << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < compactControlPoints.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Compact Control Points[" << i1 << "]:  " << compactControlPoints[i1] << endl;
		array_output_count++;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiBSplineData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiBSplineData::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

std::list<NiObject *> NiBSplineData::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiObject::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

vector<float> NiBSplineData::GetFloatControlPoints() const 
{
	return floatControlPoints;
}

void NiBSplineData::SetFloatControlPoints( vector<float> value ) 
{
	this->floatControlPoints.clear();
	this->numFloatControlPoints = value.size();

	for(unsigned int i = 0; i < value.size(); i++) {
		this->floatControlPoints.push_back(value[i]);
	}
}

void NiBSplineData::AppendFloatControlPoints( vector<float> value )
{
	this->numFloatControlPoints += value.size();

	for(unsigned int i = 0; i < value.size(); i++) {
		this->floatControlPoints.push_back(value[i]);
	}
}

unsigned int NiBSplineData::GetNumFloatControlPoints()
{
	return this->numFloatControlPoints;
}

vector<float> NiBSplineData::GetFloatControlPointRange(int offset, int count) const
{
	vector<float> value;
	if (offset < 0 || count < 0 || ((offset + count) > int(floatControlPoints.size())))
		throw runtime_error("Invalid offset or count.");
	vector<float>::const_iterator srcbeg = floatControlPoints.begin(), srcend = floatControlPoints.begin(); 
	std::advance(srcbeg, offset);
	std::advance(srcend, offset + count);
	return vector<float>(srcbeg, srcend);
}

vector<short > NiBSplineData::GetCompactControlPoints() const 
{
	return compactControlPoints;
}

void NiBSplineData::SetCompactControlPoints( vector<short> value )
{
	this->compactControlPoints.clear();
	this->numCompactControlPoints = value.size();

	for(unsigned int i = 0; i < value.size(); i++) {
		this->compactControlPoints.push_back(value[i]);
	}
}

void NiBSplineData::AppendNumCompactControlPoints( vector<unsigned int> value )
{
	this->numCompactControlPoints += value.size();

	for(unsigned int i = 0; i < value.size(); i++) {
		this->numCompactControlPoints.push_back(value[i]);
	}
}

unsigned int NiBSplineData::GetNumCompactControlPoints()
{
	return this->numCompactControlPoints;
}

vector<short > NiBSplineData::GetCompactControlPointRange(int offset, int count) const
{
   if (offset < 0 || count < 0 || ((offset + count) > compactControlPoints.size()))
      throw runtime_error("Invalid offset or count.");
   vector<short>::const_iterator srcbeg = compactControlPoints.begin(), srcend = compactControlPoints.begin(); 
   std::advance(srcbeg, offset);
   std::advance(srcend, offset + count);
   return vector<short>(srcbeg, srcend);
}

//--END CUSTOM CODE--//

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

static const int SizeofQuat = 4;
static const int SizeofTrans = 3;
static const int SizeofScale = 1;
//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/ObjectRegistry.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/NiBSplineTransformInterpolator.h"
#include "../../include/gen/NiQuatTransform.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBSplineTransformInterpolator::TYPE("NiBSplineTransformInterpolator", &NiBSplineInterpolator::TYPE );

NiBSplineTransformInterpolator::NiBSplineTransformInterpolator() : translationHandle((unsigned int)0xFFFF), rotationHandle((unsigned int)0xFFFF), scaleHandle((unsigned int)0xFFFF) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiBSplineTransformInterpolator::~NiBSplineTransformInterpolator() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiBSplineTransformInterpolator::GetType() const {
	return TYPE;
}

NiObject * NiBSplineTransformInterpolator::Create() {
	return new NiBSplineTransformInterpolator;
}

void NiBSplineTransformInterpolator::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiBSplineInterpolator::Read( in, link_stack, info );
	NifStream( transform.translation, in, info );
	NifStream( transform.rotation, in, info );
	NifStream( transform.scale, in, info );
	if ( info.version <= 0x0A01006D ) {
		for (unsigned int i2 = 0; i2 < 3; i2++) {
			{
				bool tmp;
				NifStream( tmp, in, info );
				transform.trsValid[i2] = tmp;
			};
		};
	};
	NifStream( translationHandle, in, info );
	NifStream( rotationHandle, in, info );
	NifStream( scaleHandle, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiBSplineTransformInterpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiBSplineInterpolator::Write( out, link_map, missing_link_stack, info );
	NifStream( transform.translation, out, info );
	NifStream( transform.rotation, out, info );
	NifStream( transform.scale, out, info );
	if ( info.version <= 0x0A01006D ) {
		for (unsigned int i2 = 0; i2 < 3; i2++) {
			{
				bool tmp = transform.trsValid[i2];
				NifStream( tmp, out, info );
			};
		};
	};
	NifStream( translationHandle, out, info );
	NifStream( rotationHandle, out, info );
	NifStream( scaleHandle, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiBSplineTransformInterpolator::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiBSplineInterpolator::asString();
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
	out << "  Translation Handle:  " << translationHandle << endl;
	out << "  Rotation Handle:  " << rotationHandle << endl;
	out << "  Scale Handle:  " << scaleHandle << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiBSplineTransformInterpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiBSplineInterpolator::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiBSplineTransformInterpolator::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiBSplineInterpolator::GetRefs();
	return refs;
}

std::list<NiObject *> NiBSplineTransformInterpolator::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiBSplineInterpolator::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//
Vector3 NiBSplineTransformInterpolator::GetTranslation() const {
	return translation;
}

void NiBSplineTransformInterpolator::SetTranslation( Vector3 value ) {
	translation = value;
}

int NiBSplineTransformInterpolator::GetTranslationOffset() {
	return translationOffset;
}

void NiBSplineTransformInterpolator::SetTranslationOffset( int value ) {
	translationOffset = value;
}

Quaternion NiBSplineTransformInterpolator::GetRotation() const {
	return rotation;
}

void NiBSplineTransformInterpolator::SetRotation( Quaternion value ) {
	rotation = value;
}

int NiBSplineTransformInterpolator::GetRotationOffset() {
	return rotationOffset;
}

void NiBSplineTransformInterpolator::SetRotationOffset( int value ) {
	rotationOffset = value;
}

float NiBSplineTransformInterpolator::GetScale() const {
	return scale;
}

void NiBSplineTransformInterpolator::SetScale( float value ) {
	scale = value;
}

int NiBSplineTransformInterpolator::GetScaleOffset() {
	return scaleOffset;
}

void Niflib::NiBSplineTransformInterpolator::SetScaleOffset( int value ) {
	scaleOffset = value;
}

vector< Quaternion > NiBSplineTransformInterpolator::GetQuatRotateControlData() const
{
	vector< Quaternion > value;
	if ((rotationOffset != USHRT_MAX) && splineData && basisData) { // has rotation data
		int nctrl = basisData->GetNumControlPoints();
		int npts = nctrl * SizeofQuat;
		vector<float> points = splineData->GetFloatControlPointRange(rotationOffset, npts);
		value.reserve(nctrl);
		for (int i=0; i<npts; ) {
			Quaternion key;
			key.w = float(points[i++]);
			key.x = float(points[i++]);
			key.y = float(points[i++]);
			key.z = float(points[i++]);
			value.push_back(key);
		}
	}
	return value;
}

vector< Vector3 > NiBSplineTransformInterpolator::GetTranslateControlData() const
{
	vector< Vector3 > value;
	if ((translationOffset != USHRT_MAX) && splineData && basisData) { // has translation data
		int nctrl = basisData->GetNumControlPoints();
		int npts = nctrl * SizeofTrans;
		vector<float> points = splineData->GetFloatControlPointRange(translationOffset, npts);
		value.reserve(nctrl);
		for (int i=0; i<npts; ) {
			Vector3 key;
			key.x = float(points[i++]);
			key.y = float(points[i++]);
			key.z = float(points[i++]);
			value.push_back(key);
		}
	}
	return value;
}

vector< float > NiBSplineTransformInterpolator::GetScaleControlData() const
{
	vector< float > value;
	if ((scaleOffset != USHRT_MAX) && splineData && basisData) { // has translation data
		int nctrl = basisData->GetNumControlPoints();
		int npts = nctrl * SizeofScale;
		vector<float> points = splineData->GetFloatControlPointRange(scaleOffset, npts);
		value.reserve(nctrl);
		for (int i=0; i<npts; ) {
			float data = float(points[i++]);
			value.push_back(data);
		}
	}
	return value;
}

vector< Key<Quaternion> > NiBSplineTransformInterpolator::SampleQuatRotateKeys(int npoints, int degree) const
{
	vector< Key<Quaternion> > value;
	if ((rotationOffset != USHRT_MAX) && splineData && basisData) { // has rotation data
		int nctrl = basisData->GetNumControlPoints();
		int npts = nctrl * SizeofQuat;
		vector<float> points = splineData->GetFloatControlPointRange(rotationOffset, npts);
		vector<float> control(npts);
		vector<float> output(npoints*SizeofQuat);
		for (int i=0, j=0; i<nctrl; ++i) {
			for (int k=0; k<SizeofQuat; ++k)
				control[i*SizeofQuat + k] = float(points[j++]);
		}
		if (degree>=nctrl)
			degree = nctrl - 1;
		// fit data
		bspline(nctrl-1, degree+1, SizeofQuat, &control[0], &output[0], npoints);

		// copy to key
		float time = GetStartTime();
		float incr = (GetStopTime() - GetStartTime()) / float(npoints) ;
		value.reserve(npoints);
		for (int i=0, j=0; i<npoints; i++) {
			Key<Quaternion> key;
			key.time = time;
			key.backward_tangent.Set(1.0f,0.0f,0.0f,0.0f);
			key.forward_tangent.Set(1.0f,0.0f,0.0f,0.0f); 
			key.data.w = output[j++];
			key.data.x = output[j++];
			key.data.y = output[j++];
			key.data.z = output[j++];
			value.push_back(key);
			time += incr;
		}
	}
	return value;
}

vector< Key<Vector3> > NiBSplineTransformInterpolator::SampleTranslateKeys(int npoints, int degree) const
{
	vector< Key<Vector3> > value;
	if ((translationOffset != USHRT_MAX) && splineData && basisData) { // has rotation data
		int nctrl = basisData->GetNumControlPoints();
		int npts = nctrl * SizeofTrans;
		vector<float> points = splineData->GetFloatControlPointRange(translationOffset, npts);
		vector<float> control(npts);
		vector<float> output(npoints*SizeofTrans);
		for (int i=0, j=0; i<nctrl; ++i) {
			for (int k=0; k<SizeofTrans; ++k)
				control[i*SizeofTrans + k] = float(points[j++]);
		}
		// fit data
		bspline(nctrl-1, degree+1, SizeofTrans, &control[0], &output[0], npoints);

		// copy to key
		float time = GetStartTime();
		float incr = (GetStopTime() - GetStartTime()) / float(npoints) ;
		value.reserve(npoints);
		for (int i=0, j=0; i<npoints; i++) {
			Key<Vector3> key;
			key.time = time;
			key.backward_tangent.Set(0.0f,0.0f,0.0f);
			key.forward_tangent.Set(0.0f,0.0f,0.0f); 
			key.data.x = output[j++];
			key.data.y = output[j++];
			key.data.z = output[j++];
			value.push_back(key);
			time += incr;
		}
	}
	return value;
}

vector< Key<float> > NiBSplineTransformInterpolator::SampleScaleKeys(int npoints, int degree) const
{
	vector< Key<float> > value;
	if ((scaleOffset != USHRT_MAX) && splineData && basisData) // has rotation data
	{
		int nctrl = basisData->GetNumControlPoints();
		int npts = nctrl * SizeofScale;
		vector<float> points = splineData->GetFloatControlPointRange(scaleOffset, npts);
		vector<float> control(npts);
		vector<float> output(npoints*SizeofScale);
		for (int i=0, j=0; i<nctrl; ++i) {
			control[i] = float(points[j++]) / float (32767);
		}
		// fit data
		bspline(nctrl-1, degree+1, SizeofScale, &control[0], &output[0], npoints);

		// copy to key
		float time = GetStartTime();
		float incr = (GetStopTime() - GetStartTime()) / float(npoints) ;
		value.reserve(npoints);
		for (int i=0, j=0; i<npoints; i++) {
			Key<float> key;
			key.time = time;
			key.backward_tangent = 0.0f;
			key.forward_tangent = 0.0f; 
			key.data = output[j++];
			value.push_back(key);
			time += incr;
		}
	}
	return value;
}

int NiBSplineTransformInterpolator::GetNumControlPoints() const
{
	if (basisData)
	{
		return basisData->GetNumControlPoints();
	}
	return 0;
}

//--END CUSTOM CODE--//

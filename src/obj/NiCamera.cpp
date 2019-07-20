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
#include "../../include/obj/NiCamera.h"
#include "../../include/obj/NiAVObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiCamera::TYPE("NiCamera", &NiAVObject::TYPE );

NiCamera::NiCamera() : cameraFlags((unsigned short)0), frustumLeft(0.0f), frustumRight(0.0f), frustumTop(0.0f), frustumBottom(0.0f), frustumNear(0.0f), frustumFar(0.0f), useOrthographicProjection(false), viewportLeft(0.0f), viewportRight(0.0f), viewportTop(0.0f), viewportBottom(0.0f), lodAdjust(0.0f), scene(NULL), numScreenPolygons((unsigned int)0), numScreenTextures((unsigned int)0), unknownInt3((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiCamera::~NiCamera() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiCamera::GetType() const {
	return TYPE;
}

NiObject * NiCamera::Create() {
	return new NiCamera;
}

void NiCamera::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiAVObject::Read( in, link_stack, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( cameraFlags, in, info );
	};
	NifStream( frustumLeft, in, info );
	NifStream( frustumRight, in, info );
	NifStream( frustumTop, in, info );
	NifStream( frustumBottom, in, info );
	NifStream( frustumNear, in, info );
	NifStream( frustumFar, in, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( useOrthographicProjection, in, info );
	};
	NifStream( viewportLeft, in, info );
	NifStream( viewportRight, in, info );
	NifStream( viewportTop, in, info );
	NifStream( viewportBottom, in, info );
	NifStream( lodAdjust, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( numScreenPolygons, in, info );
	if ( info.version >= 0x04020100 ) {
		NifStream( numScreenTextures, in, info );
	};
	if ( info.version <= 0x03010000 ) {
		NifStream( unknownInt3, in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiCamera::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiAVObject::Write( out, link_map, missing_link_stack, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( cameraFlags, out, info );
	};
	NifStream( frustumLeft, out, info );
	NifStream( frustumRight, out, info );
	NifStream( frustumTop, out, info );
	NifStream( frustumBottom, out, info );
	NifStream( frustumNear, out, info );
	NifStream( frustumFar, out, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( useOrthographicProjection, out, info );
	};
	NifStream( viewportLeft, out, info );
	NifStream( viewportRight, out, info );
	NifStream( viewportTop, out, info );
	NifStream( viewportBottom, out, info );
	NifStream( lodAdjust, out, info );
	WriteRef( StaticCast<NiObject>(scene), out, info, link_map, missing_link_stack );
	NifStream( numScreenPolygons, out, info );
	if ( info.version >= 0x04020100 ) {
		NifStream( numScreenTextures, out, info );
	};
	if ( info.version <= 0x03010000 ) {
		NifStream( unknownInt3, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiCamera::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	out << NiAVObject::asString();
	out << "  Camera Flags:  " << cameraFlags << endl;
	out << "  Frustum Left:  " << frustumLeft << endl;
	out << "  Frustum Right:  " << frustumRight << endl;
	out << "  Frustum Top:  " << frustumTop << endl;
	out << "  Frustum Bottom:  " << frustumBottom << endl;
	out << "  Frustum Near:  " << frustumNear << endl;
	out << "  Frustum Far:  " << frustumFar << endl;
	out << "  Use Orthographic Projection:  " << useOrthographicProjection << endl;
	out << "  Viewport Left:  " << viewportLeft << endl;
	out << "  Viewport Right:  " << viewportRight << endl;
	out << "  Viewport Top:  " << viewportTop << endl;
	out << "  Viewport Bottom:  " << viewportBottom << endl;
	out << "  LOD Adjust:  " << lodAdjust << endl;
	out << "  Scene:  " << scene << endl;
	out << "  Num Screen Polygons:  " << numScreenPolygons << endl;
	out << "  Num Screen Textures:  " << numScreenTextures << endl;
	out << "  Unknown Int 3:  " << unknownInt3 << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiCamera::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiAVObject::FixLinks( objects, link_stack, missing_link_stack, info );
	scene = FixLink<NiAVObject>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiCamera::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiAVObject::GetRefs();
	if ( scene != NULL )
		refs.push_back(StaticCast<NiObject>(scene));
	return refs;
}

std::list<NiObject *> NiCamera::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiAVObject::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

float NiCamera::GetFrustumLeft() const {
	return frustumLeft;
}

void NiCamera::SetFrustumLeft( float value ) {
	frustumLeft = value;
}

float NiCamera::GetFrustumRight() const {
	return frustumRight;
}

void NiCamera::SetFrustumRight( float value ) {
	frustumRight = value;
}

float NiCamera::GetFrustumTop() const {
	return frustumTop;
}

void NiCamera::SetFrustumTop( float value ) {
	frustumTop = value;
}

float NiCamera::GetFrustumBottom() const {
	return frustumBottom;
}

void NiCamera::SetFrustumBottom( float value ) {
	frustumBottom = value;
}

float NiCamera::GetFrustumNear() const {
	return frustumNear;
}

void NiCamera::SetFrustumNear( float value ) {
	frustumNear = value;
}

float NiCamera::GetFrustumFar() const {
	return frustumFar;
}

void NiCamera::SetFrustumFar( float value ) {
	frustumFar = value;
}

bool NiCamera::GetUseOrthographicProjection() const {
	return useOrthographicProjection;
}

void NiCamera::SetUseOrthographicProjection( bool value ) {
	useOrthographicProjection = value;
}

float NiCamera::GetViewportLeft() const {
	return viewportLeft;
}

void NiCamera::SetViewportLeft( float value ) {
	viewportLeft = value;
}

float NiCamera::GetViewportRight() const {
	return viewportRight;
}

void NiCamera::SetViewportRight( float value ) {
	viewportRight = value;
}

float NiCamera::GetViewportTop() const {
	return viewportTop;
}

void NiCamera::SetViewportTop( float value ) {
	viewportTop = value;
}

float NiCamera::GetViewportBottom() const {
	return viewportBottom;
}

void NiCamera::SetViewportBottom( float value ) {
	viewportBottom = value;
}

float NiCamera::GetLodAdjust() const {
	return lodAdjust;
}

void NiCamera::SetLodAdjust( float value ) {
	lodAdjust = value;
}

//--END CUSTOM CODE--//

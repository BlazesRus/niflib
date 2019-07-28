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
#include "../../include/obj/NiTextureEffect.h"
#include "../../include/gen/NiPlane.h"
#include "../../include/obj/NiImage.h"
#include "../../include/obj/NiSourceTexture.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTextureEffect::TYPE("NiTextureEffect", &NiDynamicEffect::TYPE );

NiTextureEffect::NiTextureEffect() : textureFiltering((TexFilterMode)FILTER_TRILERP), maxAnisotropy((unsigned short)0), textureClamping((TexClampMode)WRAP_S_WRAP_T), textureType((TextureType)TEX_ENVIRONMENT_MAP), coordinateGenerationType((CoordGenType)CG_SPHERE_MAP), image(NULL), sourceTexture(NULL), enablePlane((byte)0), ps2L((short)0), ps2K((short)-75), unknownShort((unsigned short)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiTextureEffect::~NiTextureEffect() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiTextureEffect::GetType() const {
	return TYPE;
}

NiObject * NiTextureEffect::Create() {
	return new NiTextureEffect;
}

void NiTextureEffect::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiDynamicEffect::Read( in, link_stack, info );
	NifStream( modelProjectionMatrix, in, info );
	NifStream( modelProjectionTransform, in, info );
	NifStream( textureFiltering, in, info );
	if ( info.version >= 0x14050004 ) {
		NifStream( maxAnisotropy, in, info );
	};
	NifStream( textureClamping, in, info );
	NifStream( textureType, in, info );
	NifStream( coordinateGenerationType, in, info );
	if ( info.version <= 0x03010000 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	if ( info.version >= 0x04000000 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( enablePlane, in, info );
	NifStream( plane.normal, in, info );
	NifStream( plane.constant, in, info );
	if ( info.version <= 0x0A020000 ) {
		NifStream( ps2L, in, info );
		NifStream( ps2K, in, info );
	};
	if ( info.version <= 0x0401000C ) {
		NifStream( unknownShort, in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiTextureEffect::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiDynamicEffect::Write( out, link_map, missing_link_stack, info );
	NifStream( modelProjectionMatrix, out, info );
	NifStream( modelProjectionTransform, out, info );
	NifStream( textureFiltering, out, info );
	if ( info.version >= 0x14050004 ) {
		NifStream( maxAnisotropy, out, info );
	};
	NifStream( textureClamping, out, info );
	NifStream( textureType, out, info );
	NifStream( coordinateGenerationType, out, info );
	if ( info.version <= 0x03010000 ) {
		WriteRef( StaticCast<NiObject>(image), out, info, link_map, missing_link_stack );
	};
	if ( info.version >= 0x04000000 ) {
		WriteRef( StaticCast<NiObject>(sourceTexture), out, info, link_map, missing_link_stack );
	};
	NifStream( enablePlane, out, info );
	NifStream( plane.normal, out, info );
	NifStream( plane.constant, out, info );
	if ( info.version <= 0x0A020000 ) {
		NifStream( ps2L, out, info );
		NifStream( ps2K, out, info );
	};
	if ( info.version <= 0x0401000C ) {
		NifStream( unknownShort, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiTextureEffect::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	out << NiDynamicEffect::asString();
	out << "  Model Projection Matrix:  " << modelProjectionMatrix << endl;
	out << "  Model Projection Transform:  " << modelProjectionTransform << endl;
	out << "  Texture Filtering:  " << textureFiltering << endl;
	out << "  Max Anisotropy:  " << maxAnisotropy << endl;
	out << "  Texture Clamping:  " << textureClamping << endl;
	out << "  Texture Type:  " << textureType << endl;
	out << "  Coordinate Generation Type:  " << coordinateGenerationType << endl;
	out << "  Image:  " << image << endl;
	out << "  Source Texture:  " << sourceTexture << endl;
	out << "  Enable Plane:  " << enablePlane << endl;
	out << "  Normal:  " << plane.normal << endl;
	out << "  Constant:  " << plane.constant << endl;
	out << "  PS2 L:  " << ps2L << endl;
	out << "  PS2 K:  " << ps2K << endl;
	out << "  Unknown Short:  " << unknownShort << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiTextureEffect::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiDynamicEffect::FixLinks( objects, link_stack, missing_link_stack, info );
	if ( info.version <= 0x03010000 ) {
		image = FixLink<NiImage>( objects, link_stack, missing_link_stack, info );
	};
	if ( info.version >= 0x04000000 ) {
		sourceTexture = FixLink<NiSourceTexture>( objects, link_stack, missing_link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiTextureEffect::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiDynamicEffect::GetRefs();
	if ( image != NULL )
		refs.push_back(StaticCast<NiObject>(image));
	if ( sourceTexture != NULL )
		refs.push_back(StaticCast<NiObject>(sourceTexture));
	return refs;
}

std::list<NiObject *> NiTextureEffect::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiDynamicEffect::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

Matrix33 NiTextureEffect::GetModelProjectionMatrix() const {
	return modelProjectionMatrix;
}

void NiTextureEffect::SetModelProjectionMatrix( Matrix33 value ) {
	modelProjectionMatrix = value;
}

Vector3 NiTextureEffect::GetModelProjectionTransform() const {
	return modelProjectionTransform;
}

void NiTextureEffect::SetModelProjectionTransform( Vector3 value ) {
	modelProjectionTransform = value;
}

TexFilterMode NiTextureEffect::GetTextureFiltering() const {
	return textureFiltering;
}

void NiTextureEffect::SetTextureFiltering( TexFilterMode value ) {
	textureFiltering = value;
}

TexClampMode NiTextureEffect::GetTextureClamping() const {
	return textureClamping;
}

void NiTextureEffect::SetTextureClamping( TexClampMode value ) {
	textureClamping = value;
}

TextureType NiTextureEffect::GetTextureType() const {
	return textureType;
}

void NiTextureEffect::SetTextureType( TextureType value ) {
	textureType = value;
}

CoordGenType NiTextureEffect::GetCoordinateGenerationType() const {
	return coordinateGenerationType;
}

void NiTextureEffect::SetCoordinateGenerationType( CoordGenType value ) {
	coordinateGenerationType = value;
}

Ref<NiSourceTexture > NiTextureEffect::GetSourceTexture() const {
	return sourceTexture;
}

void NiTextureEffect::SetSourceTexture( Ref<NiSourceTexture > value ) {
	sourceTexture = value;
}

unsigned short NiTextureEffect::GetPs2L() const {
	return ps2L;
}

void NiTextureEffect::SetPs2L( unsigned short value ) {
	ps2L = value;
}

unsigned short NiTextureEffect::GetPs2K() const {
	return ps2K;
}

void NiTextureEffect::SetPs2K( unsigned short value ) {
	ps2K = value;
}

unsigned short Niflib::NiTextureEffect::GetMaxAnisotropy() const
{
	return maxAnisotropy;
}

void Niflib::NiTextureEffect::SetMaxAnisotropy(unsigned short value)
{
	maxAnisotropy = value;
}

TexClampMode Niflib::NiTextureEffect::GetTextureClampMode() const
{
	return textureClamping;
}

void Niflib::NiTextureEffect::SetTextureClampMode(TexClampMode value)
{
	textureClamping = value;
}

Ref<NiImage> Niflib::NiTextureEffect::GetImageIndex() const
{
	return image;
}

void Niflib::NiTextureEffect::SetImageIndex(Ref<NiImage> value)
{
	image = value;
}

byte Niflib::NiTextureEffect::GetHasPlane() const
{
	return enablePlane;
}

NiPlane Niflib::NiTextureEffect::GetPlane() const
{
	return plane;
}

void Niflib::NiTextureEffect::SetPlane(NiPlane value)
{
	plane = value;
	enablePlane = 1;
}

//--END CUSTOM CODE--//

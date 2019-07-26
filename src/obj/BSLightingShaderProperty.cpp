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
#include "../../include/obj/BSLightingShaderProperty.h"
#include "../../include/obj/BSShaderTextureSet.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSLightingShaderProperty::TYPE("BSLightingShaderProperty", &BSShaderProperty::TYPE );

BSLightingShaderProperty::BSLightingShaderProperty() : shaderFlags1_sk((SkyrimShaderPropertyFlags1)2185233153), shaderFlags2_sk((SkyrimShaderPropertyFlags2)32801), shaderFlags1_fo4((Fallout4ShaderPropertyFlags1)2151678465), shaderFlags2_fo4((Fallout4ShaderPropertyFlags2)1), uvScale(1.0, 1.0), textureSet(NULL), emissiveColor(0.0, 0.0, 0.0), emissiveMultiple(0.0f), textureClampMode((TexClampMode)3), alpha(1.0f), refractionStrength(0.0f), glossiness(80.0f), smoothness(1.0f), specularStrength(1.0f), lightingEffect1(0.3f), lightingEffect2(2.0f), subsurfaceRolloff(0.3f), rimlightPower(3.402823466e+38f), backlightPower(0.0f), grayscaleToPaletteScale(0.0f), fresnelPower(5.0f), wetnessSpecScale(-1.0f), wetnessSpecPower(-1.0f), wetnessMinVar(-1.0f), wetnessEnvMapScale(-1.0f), wetnessFresnelPower(-1.0f), wetnessMetalness(-1.0f), environmentMapScale(1.0f), unknownEnvMapShort((unsigned short)0), unknownSkinTintInt((unsigned int)0), maxPasses(0.0f), scale(0.0f), parallaxInnerLayerThickness(0.0f), parallaxRefractionScale(0.0f), parallaxEnvmapStrength(0.0f), eyeCubemapScale(0.0f) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

BSLightingShaderProperty::~BSLightingShaderProperty() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & BSLightingShaderProperty::GetType() const {
	return TYPE;
}

NiObject * BSLightingShaderProperty::Create() {
	return new BSLightingShaderProperty;
}

void BSLightingShaderProperty::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	BSShaderProperty::Read( in, link_stack, info );
	if ( (info.userVersion2 != 130) ) {
		NifStream( shaderFlags1_sk, in, info );
		NifStream( shaderFlags2_sk, in, info );
	};
	if ( (info.userVersion2 == 130) ) {
		NifStream( shaderFlags1_fo4, in, info );
		NifStream( shaderFlags2_fo4, in, info );
	};
	NifStream( uvOffset, in, info );
	NifStream( uvScale, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( emissiveColor, in, info );
	NifStream( emissiveMultiple, in, info );
	if ( (info.userVersion2 == 130) ) {
		NifStream( wetMaterial, in, info );
	};
	NifStream( textureClampMode, in, info );
	NifStream( alpha, in, info );
	NifStream( refractionStrength, in, info );
	if ( (info.userVersion2 < 130) ) {
		NifStream( glossiness, in, info );
	};
	if ( (info.userVersion2 == 130) ) {
		NifStream( smoothness, in, info );
	};
	NifStream( specularColor, in, info );
	NifStream( specularStrength, in, info );
	if ( (info.userVersion2 < 130) ) {
		NifStream( lightingEffect1, in, info );
		NifStream( lightingEffect2, in, info );
	};
	if ( (info.userVersion2 == 130) ) {
		NifStream( subsurfaceRolloff, in, info );
		NifStream( rimlightPower, in, info );
		if ( (rimlightPower == 0x7F7FFFFF) ) {
			NifStream( backlightPower, in, info );
		};
		NifStream( grayscaleToPaletteScale, in, info );
		NifStream( fresnelPower, in, info );
		NifStream( wetnessSpecScale, in, info );
		NifStream( wetnessSpecPower, in, info );
		NifStream( wetnessMinVar, in, info );
		NifStream( wetnessEnvMapScale, in, info );
		NifStream( wetnessFresnelPower, in, info );
		NifStream( wetnessMetalness, in, info );
	};
	if ( (skyrimShaderType == 1) ) {
		NifStream( environmentMapScale, in, info );
	};
	if ( (info.userVersion2 == 130) ) {
		if ( (skyrimShaderType == 1) ) {
			NifStream( unknownEnvMapShort, in, info );
		};
	};
	if ( (skyrimShaderType == 5) ) {
		NifStream( skinTintColor, in, info );
	};
	if ( (info.userVersion2 == 130) ) {
		if ( (skyrimShaderType == 5) ) {
			NifStream( unknownSkinTintInt, in, info );
		};
	};
	if ( (skyrimShaderType == 6) ) {
		NifStream( hairTintColor, in, info );
	};
	if ( (skyrimShaderType == 7) ) {
		NifStream( maxPasses, in, info );
		NifStream( scale, in, info );
	};
	if ( (skyrimShaderType == 11) ) {
		NifStream( parallaxInnerLayerThickness, in, info );
		NifStream( parallaxRefractionScale, in, info );
		NifStream( parallaxInnerLayerTextureScale, in, info );
		NifStream( parallaxEnvmapStrength, in, info );
	};
	if ( (skyrimShaderType == 14) ) {
		NifStream( sparkleParameters, in, info );
	};
	if ( (skyrimShaderType == 16) ) {
		NifStream( eyeCubemapScale, in, info );
		NifStream( leftEyeReflectionCenter, in, info );
		NifStream( rightEyeReflectionCenter, in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSLightingShaderProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	BSShaderProperty::Write( out, link_map, missing_link_stack, info );
	if ( (info.userVersion2 != 130) ) {
		NifStream( shaderFlags1_sk, out, info );
		NifStream( shaderFlags2_sk, out, info );
	};
	if ( (info.userVersion2 == 130) ) {
		NifStream( shaderFlags1_fo4, out, info );
		NifStream( shaderFlags2_fo4, out, info );
	};
	NifStream( uvOffset, out, info );
	NifStream( uvScale, out, info );
	WriteRef( StaticCast<NiObject>(textureSet), out, info, link_map, missing_link_stack );
	NifStream( emissiveColor, out, info );
	NifStream( emissiveMultiple, out, info );
	if ( (info.userVersion2 == 130) ) {
		NifStream( wetMaterial, out, info );
	};
	NifStream( textureClampMode, out, info );
	NifStream( alpha, out, info );
	NifStream( refractionStrength, out, info );
	if ( (info.userVersion2 < 130) ) {
		NifStream( glossiness, out, info );
	};
	if ( (info.userVersion2 == 130) ) {
		NifStream( smoothness, out, info );
	};
	NifStream( specularColor, out, info );
	NifStream( specularStrength, out, info );
	if ( (info.userVersion2 < 130) ) {
		NifStream( lightingEffect1, out, info );
		NifStream( lightingEffect2, out, info );
	};
	if ( (info.userVersion2 == 130) ) {
		NifStream( subsurfaceRolloff, out, info );
		NifStream( rimlightPower, out, info );
		if ( (rimlightPower == 0x7F7FFFFF) ) {
			NifStream( backlightPower, out, info );
		};
		NifStream( grayscaleToPaletteScale, out, info );
		NifStream( fresnelPower, out, info );
		NifStream( wetnessSpecScale, out, info );
		NifStream( wetnessSpecPower, out, info );
		NifStream( wetnessMinVar, out, info );
		NifStream( wetnessEnvMapScale, out, info );
		NifStream( wetnessFresnelPower, out, info );
		NifStream( wetnessMetalness, out, info );
	};
	if ( (skyrimShaderType == 1) ) {
		NifStream( environmentMapScale, out, info );
	};
	if ( (info.userVersion2 == 130) ) {
		if ( (skyrimShaderType == 1) ) {
			NifStream( unknownEnvMapShort, out, info );
		};
	};
	if ( (skyrimShaderType == 5) ) {
		NifStream( skinTintColor, out, info );
	};
	if ( (info.userVersion2 == 130) ) {
		if ( (skyrimShaderType == 5) ) {
			NifStream( unknownSkinTintInt, out, info );
		};
	};
	if ( (skyrimShaderType == 6) ) {
		NifStream( hairTintColor, out, info );
	};
	if ( (skyrimShaderType == 7) ) {
		NifStream( maxPasses, out, info );
		NifStream( scale, out, info );
	};
	if ( (skyrimShaderType == 11) ) {
		NifStream( parallaxInnerLayerThickness, out, info );
		NifStream( parallaxRefractionScale, out, info );
		NifStream( parallaxInnerLayerTextureScale, out, info );
		NifStream( parallaxEnvmapStrength, out, info );
	};
	if ( (skyrimShaderType == 14) ) {
		NifStream( sparkleParameters, out, info );
	};
	if ( (skyrimShaderType == 16) ) {
		NifStream( eyeCubemapScale, out, info );
		NifStream( leftEyeReflectionCenter, out, info );
		NifStream( rightEyeReflectionCenter, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string BSLightingShaderProperty::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << BSShaderProperty::asString();
	out << "  Shader Flags 1:  " << shaderFlags1_sk << endl;
	out << "  Shader Flags 2:  " << shaderFlags2_sk << endl;
	out << "  Shader Flags 1:  " << shaderFlags1_fo4 << endl;
	out << "  Shader Flags 2:  " << shaderFlags2_fo4 << endl;
	out << "  UV Offset:  " << uvOffset << endl;
	out << "  UV Scale:  " << uvScale << endl;
	out << "  Texture Set:  " << textureSet << endl;
	out << "  Emissive Color:  " << emissiveColor << endl;
	out << "  Emissive Multiple:  " << emissiveMultiple << endl;
	out << "  Wet Material:  " << wetMaterial << endl;
	out << "  Texture Clamp Mode:  " << textureClampMode << endl;
	out << "  Alpha:  " << alpha << endl;
	out << "  Refraction Strength:  " << refractionStrength << endl;
	out << "  Glossiness:  " << glossiness << endl;
	out << "  Smoothness:  " << smoothness << endl;
	out << "  Specular Color:  " << specularColor << endl;
	out << "  Specular Strength:  " << specularStrength << endl;
	out << "  Lighting Effect 1:  " << lightingEffect1 << endl;
	out << "  Lighting Effect 2:  " << lightingEffect2 << endl;
	out << "  Subsurface Rolloff:  " << subsurfaceRolloff << endl;
	out << "  Rimlight Power:  " << rimlightPower << endl;
	if ( (rimlightPower == 0x7F7FFFFF) ) {
		out << "    Backlight Power:  " << backlightPower << endl;
	};
	out << "  Grayscale to Palette Scale:  " << grayscaleToPaletteScale << endl;
	out << "  Fresnel Power:  " << fresnelPower << endl;
	out << "  Wetness Spec Scale:  " << wetnessSpecScale << endl;
	out << "  Wetness Spec Power:  " << wetnessSpecPower << endl;
	out << "  Wetness Min Var:  " << wetnessMinVar << endl;
	out << "  Wetness Env Map Scale:  " << wetnessEnvMapScale << endl;
	out << "  Wetness Fresnel Power:  " << wetnessFresnelPower << endl;
	out << "  Wetness Metalness:  " << wetnessMetalness << endl;
	if ( (skyrimShaderType == 1) ) {
		out << "    Environment Map Scale:  " << environmentMapScale << endl;
		out << "    Unknown Env Map Short:  " << unknownEnvMapShort << endl;
	};
	if ( (skyrimShaderType == 5) ) {
		out << "    Skin Tint Color:  " << skinTintColor << endl;
		out << "    Unknown Skin Tint Int:  " << unknownSkinTintInt << endl;
	};
	if ( (skyrimShaderType == 6) ) {
		out << "    Hair Tint Color:  " << hairTintColor << endl;
	};
	if ( (skyrimShaderType == 7) ) {
		out << "    Max Passes:  " << maxPasses << endl;
		out << "    Scale:  " << scale << endl;
	};
	if ( (skyrimShaderType == 11) ) {
		out << "    Parallax Inner Layer Thickness:  " << parallaxInnerLayerThickness << endl;
		out << "    Parallax Refraction Scale:  " << parallaxRefractionScale << endl;
		out << "    Parallax Inner Layer Texture Scale:  " << parallaxInnerLayerTextureScale << endl;
		out << "    Parallax Envmap Strength:  " << parallaxEnvmapStrength << endl;
	};
	if ( (skyrimShaderType == 14) ) {
		out << "    Sparkle Parameters:  " << sparkleParameters << endl;
	};
	if ( (skyrimShaderType == 16) ) {
		out << "    Eye Cubemap Scale:  " << eyeCubemapScale << endl;
		out << "    Left Eye Reflection Center:  " << leftEyeReflectionCenter << endl;
		out << "    Right Eye Reflection Center:  " << rightEyeReflectionCenter << endl;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSLightingShaderProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	BSShaderProperty::FixLinks( objects, link_stack, missing_link_stack, info );
	textureSet = FixLink<BSShaderTextureSet>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> BSLightingShaderProperty::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = BSShaderProperty::GetRefs();
	if ( textureSet != NULL )
		refs.push_back(StaticCast<NiObject>(textureSet));
	return refs;
}

std::list<NiObject *> BSLightingShaderProperty::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = BSShaderProperty::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

SkyrimShaderPropertyFlags1 BSLightingShaderProperty::GetSkyrimShaderFlags1() const {
	return shaderFlags1_sk;
}

void BSLightingShaderProperty::SetSkyrimShaderFlags1( SkyrimShaderPropertyFlags1 value ) {
	shaderFlags1_sk = value;
}

SkyrimShaderPropertyFlags2 BSLightingShaderProperty::GetSkyrimShaderFlags2() const {
	return shaderFlags2_sk;
}

void BSLightingShaderProperty::SetSkyrimShaderFlags2( SkyrimShaderPropertyFlags2 value ) {
	shaderFlags2_sk = value;
}

TexCoord BSLightingShaderProperty::GetUVOffset() const {
	return uvOffset;
}

void BSLightingShaderProperty::SetUVOffset( const TexCoord & value ) {
	uvOffset = value;
}

TexCoord BSLightingShaderProperty::GetUVScale() const {
	return uvScale;
}

void BSLightingShaderProperty::SetUVScale( const TexCoord & value ) {
	uvScale = value;
}

Ref<BSShaderTextureSet > BSLightingShaderProperty::GetTextureSet() const {
	return textureSet;
}

void BSLightingShaderProperty::SetTextureSet( Ref<BSShaderTextureSet > value ) {
	textureSet = value;
}

Color3 BSLightingShaderProperty::GetEmissiveColor() const {
	return emissiveColor;
}

void BSLightingShaderProperty::SetEmissiveColor( const Color3 & value ) {
	emissiveColor = value;
}

float BSLightingShaderProperty::GetEmissiveMultiple() const {
	return emissiveMultiple;
}

void BSLightingShaderProperty::SetEmissiveMultiple( float value ) {
	emissiveMultiple = value;
}

TexClampMode BSLightingShaderProperty::GetTextureClampMode() const {
	return textureClampMode;
}

void BSLightingShaderProperty::SetTextureClampMode( TexClampMode value ) {
	textureClampMode = value;
}

float BSLightingShaderProperty::GetAlpha() const {
	return alpha;
}

void BSLightingShaderProperty::SetAlpha( float value ) {
	alpha = value;
}


float BSLightingShaderProperty::GetGlossiness() const {
	return glossiness;
}

void BSLightingShaderProperty::SetGlossiness( float value ) {
	glossiness = value;
}

Color3 BSLightingShaderProperty::GetSpecularColor() const {
	return specularColor;
}

void BSLightingShaderProperty::SetSpecularColor( const Color3 & value ) {
	specularColor = value;
}

float BSLightingShaderProperty::GetSpecularStrength() const {
	return specularStrength;
}

void BSLightingShaderProperty::SetSpecularStrength( float value ) {
	specularStrength = value;
}

float BSLightingShaderProperty::GetLightingEffect1() const {
	return lightingEffect1;
}

void BSLightingShaderProperty::SetLightingEffect1( float value ) {
	lightingEffect1 = value;
}

float BSLightingShaderProperty::GetLightingEffect2() const {
	return lightingEffect2;
}

void BSLightingShaderProperty::SetLightingEffect2( float value ) {
	lightingEffect2 = value;
}

float Niflib::BSLightingShaderProperty::GetWetnessEnvMapScale() const
{
	return wetnessEnvMapScale;
}

void Niflib::BSLightingShaderProperty::SetWetnessEnvMapScale(float value)
{
	wetnessEnvMapScale = value;
}

float Niflib::BSLightingShaderProperty::GetWetnessFresnelPower() const
{
	return wetnessFresnelPower;
}

void Niflib::BSLightingShaderProperty::SetWetnessFresnelPower(float value)
{
	wetnessFresnelPower = value;
}

float Niflib::BSLightingShaderProperty::GetWetnessMetalness() const
{
	return wetnessMetalness;
}

void Niflib::BSLightingShaderProperty::SetWetnessMetalness(float value)
{
	wetnessMetalness = value;
}

float BSLightingShaderProperty::GetEnvironmentMapScale() const {
	return environmentMapScale;
}

void BSLightingShaderProperty::SetEnvironmentMapScale( float value ) {
	environmentMapScale = value;
}

Color3 BSLightingShaderProperty::GetSkinTintColor() const {
   return skinTintColor;
}

void BSLightingShaderProperty::SetSkinTintColor( const Color3 & value ) {
   skinTintColor = value;
}

Color3 BSLightingShaderProperty::GetHairTintColor() const {
   return hairTintColor;
}

void BSLightingShaderProperty::SetHairTintColor( const Color3 & value ) {
   hairTintColor = value;
}

float BSLightingShaderProperty::GetMaxPasses() const {
   return maxPasses;
}

void BSLightingShaderProperty::SetMaxPasses( float value ) {
   maxPasses = value;
}

float BSLightingShaderProperty::GetScale() const {
   return scale;
}

void BSLightingShaderProperty::SetScale( float value ) {
   scale = value;
}

float BSLightingShaderProperty::GetParallaxInnerLayerThickness() const {
   return parallaxInnerLayerThickness;
}

void BSLightingShaderProperty::SetParallaxInnerLayerThickness( float value ) {
   parallaxInnerLayerThickness = value;
}

float BSLightingShaderProperty::GetParallaxRefractionScale() const {
   return parallaxRefractionScale;
}

void BSLightingShaderProperty::SetParallaxRefractionScale( float value ) {
   parallaxRefractionScale = value;
}

TexCoord BSLightingShaderProperty::GetParallaxInnerLayerTextureScale() const {
   return parallaxInnerLayerTextureScale;
}

void BSLightingShaderProperty::SetParallaxInnerLayerTextureScale( const TexCoord & value ) {
   parallaxInnerLayerTextureScale = value;
}

float BSLightingShaderProperty::GetParallaxEnvmapStrength() const {
   return parallaxEnvmapStrength;
}

void BSLightingShaderProperty::SetParallaxEnvmapStrength( float value ) {
   parallaxEnvmapStrength = value;
}

Vector4 BSLightingShaderProperty::GetSparkleParameters() const {
	return sparkleParameters;
}

void BSLightingShaderProperty::SetSparkleParameters( const Vector4 & value ) {
	sparkleParameters = value;
}

float BSLightingShaderProperty::GetEyeCubemapScale() const {
	return eyeCubemapScale;
}

void BSLightingShaderProperty::SetEyeCubemapScale( float value ) {
	eyeCubemapScale = value;
}

Vector3 BSLightingShaderProperty::GetLeftEyeReflectionCenter() const {
	return leftEyeReflectionCenter;
}

void BSLightingShaderProperty::SetLeftEyeReflectionCenter( const Vector3 & value ) {
	leftEyeReflectionCenter = value;
}

Vector3 BSLightingShaderProperty::GetRightEyeReflectionCenter() const {
	return rightEyeReflectionCenter;
}

void BSLightingShaderProperty::SetRightEyeReflectionCenter( const Vector3 & value ) {
	rightEyeReflectionCenter = value;
}

IndexString Niflib::BSLightingShaderProperty::GetWetMaterial() const
{
	return wetMaterial;
}

void Niflib::BSLightingShaderProperty::SetWetMaterial(IndexString value)
{
	wetMaterial = value;
}

float Niflib::BSLightingShaderProperty::GetRefractionStrength() const
{
	return refractionStrength;
}

void Niflib::BSLightingShaderProperty::SetRefractionStrength(float value)
{
	refractionStrength = value;
}

float Niflib::BSLightingShaderProperty::GetSmoothness() const
{
	return smoothness;
}

void Niflib::BSLightingShaderProperty::SetSmoothness(float value)
{
	smoothness = value;
}

float Niflib::BSLightingShaderProperty::GetSubsurfaceRolloff() const
{
	return subsurfaceRolloff;
}

void Niflib::BSLightingShaderProperty::SetSubsurfaceRolloff(float value)
{
	subsurfaceRolloff = value;
}

float Niflib::BSLightingShaderProperty::GetRimlightPower() const
{
	return rimlightPower;
}

void Niflib::BSLightingShaderProperty::SetRimlightPower(float value)
{
	rimlightPower = value;
}

float Niflib::BSLightingShaderProperty::GetBacklightPower() const
{
	return backlightPower;
}

void Niflib::BSLightingShaderProperty::SetBacklightPower(float value)
{
	backlightPower = value;
}

float Niflib::BSLightingShaderProperty::GetGrayscaleToPaletteScale() const
{
	return grayscaleToPaletteScale;
}

void Niflib::BSLightingShaderProperty::SetGrayscaleToPaletteScale(float value)
{
	grayscaleToPaletteScale = value;
}

float Niflib::BSLightingShaderProperty::GetFresnelPower() const
{
	return fresnelPower;
}

void Niflib::BSLightingShaderProperty::SetFresnelPower(float value)
{
	fresnelPower = value;
}

float Niflib::BSLightingShaderProperty::GetWetnessSpecScale() const
{
	return wetnessSpecScale;
}

void Niflib::BSLightingShaderProperty::SetWetnessSpecScale(float value)
{
	wetnessSpecScale = value;
}

float Niflib::BSLightingShaderProperty::GetWetnessSpecPower() const
{
	return wetnessSpecPower;
}

void Niflib::BSLightingShaderProperty::SetWetnessSpecPower(float value)
{
	wetnessSpecPower = value;
}

float Niflib::BSLightingShaderProperty::GetWetnessMinVar() const
{
	return wetnessMinVar;
}

void Niflib::BSLightingShaderProperty::SetWetnessMinVar(float value)
{
	wetnessMinVar = value;
}

//--END CUSTOM CODE--//

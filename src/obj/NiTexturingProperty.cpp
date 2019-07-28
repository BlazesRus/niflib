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
#include "../../include/obj/NiTexturingProperty.h"
#include "../../include/gen/ShaderTexDesc.h"
#include "../../include/gen/TexDesc.h"
#include "../../include/obj/NiImage.h"
#include "../../include/obj/NiSourceTexture.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTexturingProperty::TYPE("NiTexturingProperty", &NiProperty::TYPE );

NiTexturingProperty::NiTexturingProperty() : flags((unsigned short)0), applyMode((ApplyMode)APPLY_MODULATE), textureCount((unsigned int)7), hasBaseTexture(false), hasDarkTexture(false), hasDetailTexture(false), hasGlossTexture(false), hasGlowTexture(false), hasBumpMapTexture(false), bumpMapLumaScale(0.0f), bumpMapLumaOffset(0.0f), hasNormalTexture(false), hasParallaxTexture(false), parallaxOffset(0.0f), hasDecal0Texture(false), hasDecal1Texture(false), hasDecal2Texture(false), hasDecal3Texture(false), numShaderTextures((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiTexturingProperty::~NiTexturingProperty() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiTexturingProperty::GetType() const {
	return TYPE;
}

NiObject * NiTexturingProperty::Create() {
	return new NiTexturingProperty;
}

void NiTexturingProperty::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiProperty::Read( in, link_stack, info );
	if ( info.version <= 0x0A000102 ) {
		NifStream( flags, in, info );
	};
	if ( info.version >= 0x14010002 ) {
		NifStream( (unsigned short&)flags, in, info );
	};
	if ( ( info.version >= 0x0303000D ) && ( info.version <= 0x14010001 ) ) {
		NifStream( applyMode, in, info );
	};
	NifStream( textureCount, in, info );
	NifStream( hasBaseTexture, in, info );
	if ( hasBaseTexture ) {
		if ( info.version <= 0x03010000 ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
		if ( info.version >= 0x0303000D ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( baseTexture.clampMode, in, info );
			NifStream( baseTexture.filterMode, in, info );
		};
		if ( info.version >= 0x14010003 ) {
			NifStream( baseTexture.flags, in, info );
		};
		if ( info.version >= 0x14050004 ) {
			NifStream( baseTexture.maxAnisotropy, in, info );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( baseTexture.uvSet, in, info );
		};
		if ( info.version <= 0x0A040001 ) {
			NifStream( baseTexture.ps2L, in, info );
			NifStream( baseTexture.ps2K, in, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( baseTexture.unknown1, in, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( baseTexture.hasTextureTransform, in, info );
			if ( baseTexture.hasTextureTransform ) {
				NifStream( baseTexture.translation, in, info );
				NifStream( baseTexture.scale, in, info );
				NifStream( baseTexture.rotation, in, info );
				NifStream( baseTexture.transformMethod, in, info );
				NifStream( baseTexture.center, in, info );
			};
		};
	};
	NifStream( hasDarkTexture, in, info );
	if ( hasDarkTexture ) {
		if ( info.version <= 0x03010000 ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
		if ( info.version >= 0x0303000D ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( darkTexture.clampMode, in, info );
			NifStream( darkTexture.filterMode, in, info );
		};
		if ( info.version >= 0x14010003 ) {
			NifStream( darkTexture.flags, in, info );
		};
		if ( info.version >= 0x14050004 ) {
			NifStream( darkTexture.maxAnisotropy, in, info );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( darkTexture.uvSet, in, info );
		};
		if ( info.version <= 0x0A040001 ) {
			NifStream( darkTexture.ps2L, in, info );
			NifStream( darkTexture.ps2K, in, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( darkTexture.unknown1, in, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( darkTexture.hasTextureTransform, in, info );
			if ( darkTexture.hasTextureTransform ) {
				NifStream( darkTexture.translation, in, info );
				NifStream( darkTexture.scale, in, info );
				NifStream( darkTexture.rotation, in, info );
				NifStream( darkTexture.transformMethod, in, info );
				NifStream( darkTexture.center, in, info );
			};
		};
	};
	NifStream( hasDetailTexture, in, info );
	if ( hasDetailTexture ) {
		if ( info.version <= 0x03010000 ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
		if ( info.version >= 0x0303000D ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( detailTexture.clampMode, in, info );
			NifStream( detailTexture.filterMode, in, info );
		};
		if ( info.version >= 0x14010003 ) {
			NifStream( detailTexture.flags, in, info );
		};
		if ( info.version >= 0x14050004 ) {
			NifStream( detailTexture.maxAnisotropy, in, info );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( detailTexture.uvSet, in, info );
		};
		if ( info.version <= 0x0A040001 ) {
			NifStream( detailTexture.ps2L, in, info );
			NifStream( detailTexture.ps2K, in, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( detailTexture.unknown1, in, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( detailTexture.hasTextureTransform, in, info );
			if ( detailTexture.hasTextureTransform ) {
				NifStream( detailTexture.translation, in, info );
				NifStream( detailTexture.scale, in, info );
				NifStream( detailTexture.rotation, in, info );
				NifStream( detailTexture.transformMethod, in, info );
				NifStream( detailTexture.center, in, info );
			};
		};
	};
	NifStream( hasGlossTexture, in, info );
	if ( hasGlossTexture ) {
		if ( info.version <= 0x03010000 ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
		if ( info.version >= 0x0303000D ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( glossTexture.clampMode, in, info );
			NifStream( glossTexture.filterMode, in, info );
		};
		if ( info.version >= 0x14010003 ) {
			NifStream( glossTexture.flags, in, info );
		};
		if ( info.version >= 0x14050004 ) {
			NifStream( glossTexture.maxAnisotropy, in, info );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( glossTexture.uvSet, in, info );
		};
		if ( info.version <= 0x0A040001 ) {
			NifStream( glossTexture.ps2L, in, info );
			NifStream( glossTexture.ps2K, in, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( glossTexture.unknown1, in, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( glossTexture.hasTextureTransform, in, info );
			if ( glossTexture.hasTextureTransform ) {
				NifStream( glossTexture.translation, in, info );
				NifStream( glossTexture.scale, in, info );
				NifStream( glossTexture.rotation, in, info );
				NifStream( glossTexture.transformMethod, in, info );
				NifStream( glossTexture.center, in, info );
			};
		};
	};
	NifStream( hasGlowTexture, in, info );
	if ( hasGlowTexture ) {
		if ( info.version <= 0x03010000 ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
		if ( info.version >= 0x0303000D ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( glowTexture.clampMode, in, info );
			NifStream( glowTexture.filterMode, in, info );
		};
		if ( info.version >= 0x14010003 ) {
			NifStream( glowTexture.flags, in, info );
		};
		if ( info.version >= 0x14050004 ) {
			NifStream( glowTexture.maxAnisotropy, in, info );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( glowTexture.uvSet, in, info );
		};
		if ( info.version <= 0x0A040001 ) {
			NifStream( glowTexture.ps2L, in, info );
			NifStream( glowTexture.ps2K, in, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( glowTexture.unknown1, in, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( glowTexture.hasTextureTransform, in, info );
			if ( glowTexture.hasTextureTransform ) {
				NifStream( glowTexture.translation, in, info );
				NifStream( glowTexture.scale, in, info );
				NifStream( glowTexture.rotation, in, info );
				NifStream( glowTexture.transformMethod, in, info );
				NifStream( glowTexture.center, in, info );
			};
		};
	};
	if ( info.version >= 0x0303000D ) {
		if ( (textureCount > 5) ) {
			NifStream( hasBumpMapTexture, in, info );
		};
	};
	if ( hasBumpMapTexture ) {
		if ( info.version <= 0x03010000 ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
		if ( info.version >= 0x0303000D ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( bumpMapTexture.clampMode, in, info );
			NifStream( bumpMapTexture.filterMode, in, info );
		};
		if ( info.version >= 0x14010003 ) {
			NifStream( bumpMapTexture.flags, in, info );
		};
		if ( info.version >= 0x14050004 ) {
			NifStream( bumpMapTexture.maxAnisotropy, in, info );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( bumpMapTexture.uvSet, in, info );
		};
		if ( info.version <= 0x0A040001 ) {
			NifStream( bumpMapTexture.ps2L, in, info );
			NifStream( bumpMapTexture.ps2K, in, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( bumpMapTexture.unknown1, in, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( bumpMapTexture.hasTextureTransform, in, info );
			if ( bumpMapTexture.hasTextureTransform ) {
				NifStream( bumpMapTexture.translation, in, info );
				NifStream( bumpMapTexture.scale, in, info );
				NifStream( bumpMapTexture.rotation, in, info );
				NifStream( bumpMapTexture.transformMethod, in, info );
				NifStream( bumpMapTexture.center, in, info );
			};
		};
		NifStream( bumpMapLumaScale, in, info );
		NifStream( bumpMapLumaOffset, in, info );
		NifStream( bumpMapMatrix, in, info );
	};
	if ( info.version >= 0x14020005 ) {
		if ( (textureCount > 6) ) {
			NifStream( hasNormalTexture, in, info );
		};
	};
	if ( hasNormalTexture ) {
		if ( info.version <= 0x03010000 ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
		if ( info.version >= 0x0303000D ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( normalTexture.clampMode, in, info );
			NifStream( normalTexture.filterMode, in, info );
		};
		if ( info.version >= 0x14010003 ) {
			NifStream( normalTexture.flags, in, info );
		};
		if ( info.version >= 0x14050004 ) {
			NifStream( normalTexture.maxAnisotropy, in, info );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( normalTexture.uvSet, in, info );
		};
		if ( info.version <= 0x0A040001 ) {
			NifStream( normalTexture.ps2L, in, info );
			NifStream( normalTexture.ps2K, in, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( normalTexture.unknown1, in, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( normalTexture.hasTextureTransform, in, info );
			if ( normalTexture.hasTextureTransform ) {
				NifStream( normalTexture.translation, in, info );
				NifStream( normalTexture.scale, in, info );
				NifStream( normalTexture.rotation, in, info );
				NifStream( normalTexture.transformMethod, in, info );
				NifStream( normalTexture.center, in, info );
			};
		};
	};
	if ( info.version >= 0x14020005 ) {
		if ( (textureCount > 7) ) {
			NifStream( hasParallaxTexture, in, info );
		};
	};
	if ( hasParallaxTexture ) {
		if ( info.version <= 0x03010000 ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
		if ( info.version >= 0x0303000D ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( parallaxTexture.clampMode, in, info );
			NifStream( parallaxTexture.filterMode, in, info );
		};
		if ( info.version >= 0x14010003 ) {
			NifStream( parallaxTexture.flags, in, info );
		};
		if ( info.version >= 0x14050004 ) {
			NifStream( parallaxTexture.maxAnisotropy, in, info );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( parallaxTexture.uvSet, in, info );
		};
		if ( info.version <= 0x0A040001 ) {
			NifStream( parallaxTexture.ps2L, in, info );
			NifStream( parallaxTexture.ps2K, in, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( parallaxTexture.unknown1, in, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( parallaxTexture.hasTextureTransform, in, info );
			if ( parallaxTexture.hasTextureTransform ) {
				NifStream( parallaxTexture.translation, in, info );
				NifStream( parallaxTexture.scale, in, info );
				NifStream( parallaxTexture.rotation, in, info );
				NifStream( parallaxTexture.transformMethod, in, info );
				NifStream( parallaxTexture.center, in, info );
			};
		};
		NifStream( parallaxOffset, in, info );
	};
	if ( info.version <= 0x14020004 ) {
		if ( (textureCount > 6) ) {
			NifStream( hasDecal0Texture, in, info );
		};
	};
	if ( info.version >= 0x14020005 ) {
		if ( (textureCount > 8) ) {
			NifStream( (bool&)hasDecal0Texture, in, info );
		};
	};
	if ( hasDecal0Texture ) {
		if ( info.version <= 0x03010000 ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
		if ( info.version >= 0x0303000D ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( decal0Texture.clampMode, in, info );
			NifStream( decal0Texture.filterMode, in, info );
		};
		if ( info.version >= 0x14010003 ) {
			NifStream( decal0Texture.flags, in, info );
		};
		if ( info.version >= 0x14050004 ) {
			NifStream( decal0Texture.maxAnisotropy, in, info );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( decal0Texture.uvSet, in, info );
		};
		if ( info.version <= 0x0A040001 ) {
			NifStream( decal0Texture.ps2L, in, info );
			NifStream( decal0Texture.ps2K, in, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( decal0Texture.unknown1, in, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( decal0Texture.hasTextureTransform, in, info );
			if ( decal0Texture.hasTextureTransform ) {
				NifStream( decal0Texture.translation, in, info );
				NifStream( decal0Texture.scale, in, info );
				NifStream( decal0Texture.rotation, in, info );
				NifStream( decal0Texture.transformMethod, in, info );
				NifStream( decal0Texture.center, in, info );
			};
		};
	};
	if ( info.version <= 0x14020004 ) {
		if ( (textureCount > 7) ) {
			NifStream( hasDecal1Texture, in, info );
		};
	};
	if ( info.version >= 0x14020005 ) {
		if ( (textureCount > 9) ) {
			NifStream( (bool&)hasDecal1Texture, in, info );
		};
	};
	if ( hasDecal1Texture ) {
		if ( info.version <= 0x03010000 ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
		if ( info.version >= 0x0303000D ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( decal1Texture.clampMode, in, info );
			NifStream( decal1Texture.filterMode, in, info );
		};
		if ( info.version >= 0x14010003 ) {
			NifStream( decal1Texture.flags, in, info );
		};
		if ( info.version >= 0x14050004 ) {
			NifStream( decal1Texture.maxAnisotropy, in, info );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( decal1Texture.uvSet, in, info );
		};
		if ( info.version <= 0x0A040001 ) {
			NifStream( decal1Texture.ps2L, in, info );
			NifStream( decal1Texture.ps2K, in, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( decal1Texture.unknown1, in, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( decal1Texture.hasTextureTransform, in, info );
			if ( decal1Texture.hasTextureTransform ) {
				NifStream( decal1Texture.translation, in, info );
				NifStream( decal1Texture.scale, in, info );
				NifStream( decal1Texture.rotation, in, info );
				NifStream( decal1Texture.transformMethod, in, info );
				NifStream( decal1Texture.center, in, info );
			};
		};
	};
	if ( info.version <= 0x14020004 ) {
		if ( (textureCount > 8) ) {
			NifStream( hasDecal2Texture, in, info );
		};
	};
	if ( info.version >= 0x14020005 ) {
		if ( (textureCount > 10) ) {
			NifStream( (bool&)hasDecal2Texture, in, info );
		};
	};
	if ( hasDecal2Texture ) {
		if ( info.version <= 0x03010000 ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
		if ( info.version >= 0x0303000D ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( decal2Texture.clampMode, in, info );
			NifStream( decal2Texture.filterMode, in, info );
		};
		if ( info.version >= 0x14010003 ) {
			NifStream( decal2Texture.flags, in, info );
		};
		if ( info.version >= 0x14050004 ) {
			NifStream( decal2Texture.maxAnisotropy, in, info );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( decal2Texture.uvSet, in, info );
		};
		if ( info.version <= 0x0A040001 ) {
			NifStream( decal2Texture.ps2L, in, info );
			NifStream( decal2Texture.ps2K, in, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( decal2Texture.unknown1, in, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( decal2Texture.hasTextureTransform, in, info );
			if ( decal2Texture.hasTextureTransform ) {
				NifStream( decal2Texture.translation, in, info );
				NifStream( decal2Texture.scale, in, info );
				NifStream( decal2Texture.rotation, in, info );
				NifStream( decal2Texture.transformMethod, in, info );
				NifStream( decal2Texture.center, in, info );
			};
		};
	};
	if ( info.version <= 0x14020004 ) {
		if ( (textureCount > 9) ) {
			NifStream( hasDecal3Texture, in, info );
		};
	};
	if ( info.version >= 0x14020005 ) {
		if ( (textureCount > 11) ) {
			NifStream( (bool&)hasDecal3Texture, in, info );
		};
	};
	if ( hasDecal3Texture ) {
		if ( info.version <= 0x03010000 ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
		if ( info.version >= 0x0303000D ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( decal3Texture.clampMode, in, info );
			NifStream( decal3Texture.filterMode, in, info );
		};
		if ( info.version >= 0x14010003 ) {
			NifStream( decal3Texture.flags, in, info );
		};
		if ( info.version >= 0x14050004 ) {
			NifStream( decal3Texture.maxAnisotropy, in, info );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( decal3Texture.uvSet, in, info );
		};
		if ( info.version <= 0x0A040001 ) {
			NifStream( decal3Texture.ps2L, in, info );
			NifStream( decal3Texture.ps2K, in, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( decal3Texture.unknown1, in, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( decal3Texture.hasTextureTransform, in, info );
			if ( decal3Texture.hasTextureTransform ) {
				NifStream( decal3Texture.translation, in, info );
				NifStream( decal3Texture.scale, in, info );
				NifStream( decal3Texture.rotation, in, info );
				NifStream( decal3Texture.transformMethod, in, info );
				NifStream( decal3Texture.center, in, info );
			};
		};
	};
	if ( info.version >= 0x0A000100 ) {
		NifStream( numShaderTextures, in, info );
		shaderTextures.resize(numShaderTextures);
		for (unsigned int i2 = 0; i2 < shaderTextures.size(); i2++) {
			NifStream( shaderTextures[i2].hasMap, in, info );
			if ( shaderTextures[i2].hasMap ) {
				if ( info.version <= 0x03010000 ) {
					NifStream( block_num, in, info );
					link_stack.push_back( block_num );
				};
				if ( info.version >= 0x0303000D ) {
					NifStream( block_num, in, info );
					link_stack.push_back( block_num );
				};
				if ( info.version <= 0x14000005 ) {
					NifStream( shaderTextures[i2].map.clampMode, in, info );
					NifStream( shaderTextures[i2].map.filterMode, in, info );
				};
				if ( info.version >= 0x14010003 ) {
					NifStream( shaderTextures[i2].map.flags, in, info );
				};
				if ( info.version >= 0x14050004 ) {
					NifStream( shaderTextures[i2].map.maxAnisotropy, in, info );
				};
				if ( info.version <= 0x14000005 ) {
					NifStream( shaderTextures[i2].map.uvSet, in, info );
				};
				if ( info.version <= 0x0A040001 ) {
					NifStream( shaderTextures[i2].map.ps2L, in, info );
					NifStream( shaderTextures[i2].map.ps2K, in, info );
				};
				if ( info.version <= 0x0401000C ) {
					NifStream( shaderTextures[i2].map.unknown1, in, info );
				};
				if ( info.version >= 0x0A010000 ) {
					NifStream( shaderTextures[i2].map.hasTextureTransform, in, info );
					if ( shaderTextures[i2].map.hasTextureTransform ) {
						NifStream( shaderTextures[i2].map.translation, in, info );
						NifStream( shaderTextures[i2].map.scale, in, info );
						NifStream( shaderTextures[i2].map.rotation, in, info );
						NifStream( shaderTextures[i2].map.transformMethod, in, info );
						NifStream( shaderTextures[i2].map.center, in, info );
					};
				};
				NifStream( shaderTextures[i2].mapId, in, info );
			};
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiTexturingProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiProperty::Write( out, link_map, missing_link_stack, info );
	numShaderTextures = (unsigned int)(shaderTextures.size());
	if ( info.version <= 0x0A000102 ) {
		NifStream( flags, out, info );
	};
	if ( info.version >= 0x14010002 ) {
		NifStream( (unsigned short&)flags, out, info );
	};
	if ( ( info.version >= 0x0303000D ) && ( info.version <= 0x14010001 ) ) {
		NifStream( applyMode, out, info );
	};
	NifStream( textureCount, out, info );
	NifStream( hasBaseTexture, out, info );
	if ( hasBaseTexture ) {
		if ( info.version <= 0x03010000 ) {
			WriteRef( StaticCast<NiObject>(baseTexture.image), out, info, link_map, missing_link_stack );
		};
		if ( info.version >= 0x0303000D ) {
			WriteRef( StaticCast<NiObject>(baseTexture.source), out, info, link_map, missing_link_stack );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( baseTexture.clampMode, out, info );
			NifStream( baseTexture.filterMode, out, info );
		};
		if ( info.version >= 0x14010003 ) {
			NifStream( baseTexture.flags, out, info );
		};
		if ( info.version >= 0x14050004 ) {
			NifStream( baseTexture.maxAnisotropy, out, info );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( baseTexture.uvSet, out, info );
		};
		if ( info.version <= 0x0A040001 ) {
			NifStream( baseTexture.ps2L, out, info );
			NifStream( baseTexture.ps2K, out, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( baseTexture.unknown1, out, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( baseTexture.hasTextureTransform, out, info );
			if ( baseTexture.hasTextureTransform ) {
				NifStream( baseTexture.translation, out, info );
				NifStream( baseTexture.scale, out, info );
				NifStream( baseTexture.rotation, out, info );
				NifStream( baseTexture.transformMethod, out, info );
				NifStream( baseTexture.center, out, info );
			};
		};
	};
	NifStream( hasDarkTexture, out, info );
	if ( hasDarkTexture ) {
		if ( info.version <= 0x03010000 ) {
			WriteRef( StaticCast<NiObject>(darkTexture.image), out, info, link_map, missing_link_stack );
		};
		if ( info.version >= 0x0303000D ) {
			WriteRef( StaticCast<NiObject>(darkTexture.source), out, info, link_map, missing_link_stack );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( darkTexture.clampMode, out, info );
			NifStream( darkTexture.filterMode, out, info );
		};
		if ( info.version >= 0x14010003 ) {
			NifStream( darkTexture.flags, out, info );
		};
		if ( info.version >= 0x14050004 ) {
			NifStream( darkTexture.maxAnisotropy, out, info );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( darkTexture.uvSet, out, info );
		};
		if ( info.version <= 0x0A040001 ) {
			NifStream( darkTexture.ps2L, out, info );
			NifStream( darkTexture.ps2K, out, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( darkTexture.unknown1, out, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( darkTexture.hasTextureTransform, out, info );
			if ( darkTexture.hasTextureTransform ) {
				NifStream( darkTexture.translation, out, info );
				NifStream( darkTexture.scale, out, info );
				NifStream( darkTexture.rotation, out, info );
				NifStream( darkTexture.transformMethod, out, info );
				NifStream( darkTexture.center, out, info );
			};
		};
	};
	NifStream( hasDetailTexture, out, info );
	if ( hasDetailTexture ) {
		if ( info.version <= 0x03010000 ) {
			WriteRef( StaticCast<NiObject>(detailTexture.image), out, info, link_map, missing_link_stack );
		};
		if ( info.version >= 0x0303000D ) {
			WriteRef( StaticCast<NiObject>(detailTexture.source), out, info, link_map, missing_link_stack );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( detailTexture.clampMode, out, info );
			NifStream( detailTexture.filterMode, out, info );
		};
		if ( info.version >= 0x14010003 ) {
			NifStream( detailTexture.flags, out, info );
		};
		if ( info.version >= 0x14050004 ) {
			NifStream( detailTexture.maxAnisotropy, out, info );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( detailTexture.uvSet, out, info );
		};
		if ( info.version <= 0x0A040001 ) {
			NifStream( detailTexture.ps2L, out, info );
			NifStream( detailTexture.ps2K, out, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( detailTexture.unknown1, out, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( detailTexture.hasTextureTransform, out, info );
			if ( detailTexture.hasTextureTransform ) {
				NifStream( detailTexture.translation, out, info );
				NifStream( detailTexture.scale, out, info );
				NifStream( detailTexture.rotation, out, info );
				NifStream( detailTexture.transformMethod, out, info );
				NifStream( detailTexture.center, out, info );
			};
		};
	};
	NifStream( hasGlossTexture, out, info );
	if ( hasGlossTexture ) {
		if ( info.version <= 0x03010000 ) {
			WriteRef( StaticCast<NiObject>(glossTexture.image), out, info, link_map, missing_link_stack );
		};
		if ( info.version >= 0x0303000D ) {
			WriteRef( StaticCast<NiObject>(glossTexture.source), out, info, link_map, missing_link_stack );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( glossTexture.clampMode, out, info );
			NifStream( glossTexture.filterMode, out, info );
		};
		if ( info.version >= 0x14010003 ) {
			NifStream( glossTexture.flags, out, info );
		};
		if ( info.version >= 0x14050004 ) {
			NifStream( glossTexture.maxAnisotropy, out, info );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( glossTexture.uvSet, out, info );
		};
		if ( info.version <= 0x0A040001 ) {
			NifStream( glossTexture.ps2L, out, info );
			NifStream( glossTexture.ps2K, out, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( glossTexture.unknown1, out, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( glossTexture.hasTextureTransform, out, info );
			if ( glossTexture.hasTextureTransform ) {
				NifStream( glossTexture.translation, out, info );
				NifStream( glossTexture.scale, out, info );
				NifStream( glossTexture.rotation, out, info );
				NifStream( glossTexture.transformMethod, out, info );
				NifStream( glossTexture.center, out, info );
			};
		};
	};
	NifStream( hasGlowTexture, out, info );
	if ( hasGlowTexture ) {
		if ( info.version <= 0x03010000 ) {
			WriteRef( StaticCast<NiObject>(glowTexture.image), out, info, link_map, missing_link_stack );
		};
		if ( info.version >= 0x0303000D ) {
			WriteRef( StaticCast<NiObject>(glowTexture.source), out, info, link_map, missing_link_stack );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( glowTexture.clampMode, out, info );
			NifStream( glowTexture.filterMode, out, info );
		};
		if ( info.version >= 0x14010003 ) {
			NifStream( glowTexture.flags, out, info );
		};
		if ( info.version >= 0x14050004 ) {
			NifStream( glowTexture.maxAnisotropy, out, info );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( glowTexture.uvSet, out, info );
		};
		if ( info.version <= 0x0A040001 ) {
			NifStream( glowTexture.ps2L, out, info );
			NifStream( glowTexture.ps2K, out, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( glowTexture.unknown1, out, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( glowTexture.hasTextureTransform, out, info );
			if ( glowTexture.hasTextureTransform ) {
				NifStream( glowTexture.translation, out, info );
				NifStream( glowTexture.scale, out, info );
				NifStream( glowTexture.rotation, out, info );
				NifStream( glowTexture.transformMethod, out, info );
				NifStream( glowTexture.center, out, info );
			};
		};
	};
	if ( info.version >= 0x0303000D ) {
		if ( (textureCount > 5) ) {
			NifStream( hasBumpMapTexture, out, info );
		};
	};
	if ( hasBumpMapTexture ) {
		if ( info.version <= 0x03010000 ) {
			WriteRef( StaticCast<NiObject>(bumpMapTexture.image), out, info, link_map, missing_link_stack );
		};
		if ( info.version >= 0x0303000D ) {
			WriteRef( StaticCast<NiObject>(bumpMapTexture.source), out, info, link_map, missing_link_stack );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( bumpMapTexture.clampMode, out, info );
			NifStream( bumpMapTexture.filterMode, out, info );
		};
		if ( info.version >= 0x14010003 ) {
			NifStream( bumpMapTexture.flags, out, info );
		};
		if ( info.version >= 0x14050004 ) {
			NifStream( bumpMapTexture.maxAnisotropy, out, info );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( bumpMapTexture.uvSet, out, info );
		};
		if ( info.version <= 0x0A040001 ) {
			NifStream( bumpMapTexture.ps2L, out, info );
			NifStream( bumpMapTexture.ps2K, out, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( bumpMapTexture.unknown1, out, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( bumpMapTexture.hasTextureTransform, out, info );
			if ( bumpMapTexture.hasTextureTransform ) {
				NifStream( bumpMapTexture.translation, out, info );
				NifStream( bumpMapTexture.scale, out, info );
				NifStream( bumpMapTexture.rotation, out, info );
				NifStream( bumpMapTexture.transformMethod, out, info );
				NifStream( bumpMapTexture.center, out, info );
			};
		};
		NifStream( bumpMapLumaScale, out, info );
		NifStream( bumpMapLumaOffset, out, info );
		NifStream( bumpMapMatrix, out, info );
	};
	if ( info.version >= 0x14020005 ) {
		if ( (textureCount > 6) ) {
			NifStream( hasNormalTexture, out, info );
		};
	};
	if ( hasNormalTexture ) {
		if ( info.version <= 0x03010000 ) {
			WriteRef( StaticCast<NiObject>(normalTexture.image), out, info, link_map, missing_link_stack );
		};
		if ( info.version >= 0x0303000D ) {
			WriteRef( StaticCast<NiObject>(normalTexture.source), out, info, link_map, missing_link_stack );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( normalTexture.clampMode, out, info );
			NifStream( normalTexture.filterMode, out, info );
		};
		if ( info.version >= 0x14010003 ) {
			NifStream( normalTexture.flags, out, info );
		};
		if ( info.version >= 0x14050004 ) {
			NifStream( normalTexture.maxAnisotropy, out, info );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( normalTexture.uvSet, out, info );
		};
		if ( info.version <= 0x0A040001 ) {
			NifStream( normalTexture.ps2L, out, info );
			NifStream( normalTexture.ps2K, out, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( normalTexture.unknown1, out, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( normalTexture.hasTextureTransform, out, info );
			if ( normalTexture.hasTextureTransform ) {
				NifStream( normalTexture.translation, out, info );
				NifStream( normalTexture.scale, out, info );
				NifStream( normalTexture.rotation, out, info );
				NifStream( normalTexture.transformMethod, out, info );
				NifStream( normalTexture.center, out, info );
			};
		};
	};
	if ( info.version >= 0x14020005 ) {
		if ( (textureCount > 7) ) {
			NifStream( hasParallaxTexture, out, info );
		};
	};
	if ( hasParallaxTexture ) {
		if ( info.version <= 0x03010000 ) {
			WriteRef( StaticCast<NiObject>(parallaxTexture.image), out, info, link_map, missing_link_stack );
		};
		if ( info.version >= 0x0303000D ) {
			WriteRef( StaticCast<NiObject>(parallaxTexture.source), out, info, link_map, missing_link_stack );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( parallaxTexture.clampMode, out, info );
			NifStream( parallaxTexture.filterMode, out, info );
		};
		if ( info.version >= 0x14010003 ) {
			NifStream( parallaxTexture.flags, out, info );
		};
		if ( info.version >= 0x14050004 ) {
			NifStream( parallaxTexture.maxAnisotropy, out, info );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( parallaxTexture.uvSet, out, info );
		};
		if ( info.version <= 0x0A040001 ) {
			NifStream( parallaxTexture.ps2L, out, info );
			NifStream( parallaxTexture.ps2K, out, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( parallaxTexture.unknown1, out, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( parallaxTexture.hasTextureTransform, out, info );
			if ( parallaxTexture.hasTextureTransform ) {
				NifStream( parallaxTexture.translation, out, info );
				NifStream( parallaxTexture.scale, out, info );
				NifStream( parallaxTexture.rotation, out, info );
				NifStream( parallaxTexture.transformMethod, out, info );
				NifStream( parallaxTexture.center, out, info );
			};
		};
		NifStream( parallaxOffset, out, info );
	};
	if ( info.version <= 0x14020004 ) {
		if ( (textureCount > 6) ) {
			NifStream( hasDecal0Texture, out, info );
		};
	};
	if ( info.version >= 0x14020005 ) {
		if ( (textureCount > 8) ) {
			NifStream( (bool&)hasDecal0Texture, out, info );
		};
	};
	if ( hasDecal0Texture ) {
		if ( info.version <= 0x03010000 ) {
			WriteRef( StaticCast<NiObject>(decal0Texture.image), out, info, link_map, missing_link_stack );
		};
		if ( info.version >= 0x0303000D ) {
			WriteRef( StaticCast<NiObject>(decal0Texture.source), out, info, link_map, missing_link_stack );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( decal0Texture.clampMode, out, info );
			NifStream( decal0Texture.filterMode, out, info );
		};
		if ( info.version >= 0x14010003 ) {
			NifStream( decal0Texture.flags, out, info );
		};
		if ( info.version >= 0x14050004 ) {
			NifStream( decal0Texture.maxAnisotropy, out, info );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( decal0Texture.uvSet, out, info );
		};
		if ( info.version <= 0x0A040001 ) {
			NifStream( decal0Texture.ps2L, out, info );
			NifStream( decal0Texture.ps2K, out, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( decal0Texture.unknown1, out, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( decal0Texture.hasTextureTransform, out, info );
			if ( decal0Texture.hasTextureTransform ) {
				NifStream( decal0Texture.translation, out, info );
				NifStream( decal0Texture.scale, out, info );
				NifStream( decal0Texture.rotation, out, info );
				NifStream( decal0Texture.transformMethod, out, info );
				NifStream( decal0Texture.center, out, info );
			};
		};
	};
	if ( info.version <= 0x14020004 ) {
		if ( (textureCount > 7) ) {
			NifStream( hasDecal1Texture, out, info );
		};
	};
	if ( info.version >= 0x14020005 ) {
		if ( (textureCount > 9) ) {
			NifStream( (bool&)hasDecal1Texture, out, info );
		};
	};
	if ( hasDecal1Texture ) {
		if ( info.version <= 0x03010000 ) {
			WriteRef( StaticCast<NiObject>(decal1Texture.image), out, info, link_map, missing_link_stack );
		};
		if ( info.version >= 0x0303000D ) {
			WriteRef( StaticCast<NiObject>(decal1Texture.source), out, info, link_map, missing_link_stack );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( decal1Texture.clampMode, out, info );
			NifStream( decal1Texture.filterMode, out, info );
		};
		if ( info.version >= 0x14010003 ) {
			NifStream( decal1Texture.flags, out, info );
		};
		if ( info.version >= 0x14050004 ) {
			NifStream( decal1Texture.maxAnisotropy, out, info );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( decal1Texture.uvSet, out, info );
		};
		if ( info.version <= 0x0A040001 ) {
			NifStream( decal1Texture.ps2L, out, info );
			NifStream( decal1Texture.ps2K, out, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( decal1Texture.unknown1, out, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( decal1Texture.hasTextureTransform, out, info );
			if ( decal1Texture.hasTextureTransform ) {
				NifStream( decal1Texture.translation, out, info );
				NifStream( decal1Texture.scale, out, info );
				NifStream( decal1Texture.rotation, out, info );
				NifStream( decal1Texture.transformMethod, out, info );
				NifStream( decal1Texture.center, out, info );
			};
		};
	};
	if ( info.version <= 0x14020004 ) {
		if ( (textureCount > 8) ) {
			NifStream( hasDecal2Texture, out, info );
		};
	};
	if ( info.version >= 0x14020005 ) {
		if ( (textureCount > 10) ) {
			NifStream( (bool&)hasDecal2Texture, out, info );
		};
	};
	if ( hasDecal2Texture ) {
		if ( info.version <= 0x03010000 ) {
			WriteRef( StaticCast<NiObject>(decal2Texture.image), out, info, link_map, missing_link_stack );
		};
		if ( info.version >= 0x0303000D ) {
			WriteRef( StaticCast<NiObject>(decal2Texture.source), out, info, link_map, missing_link_stack );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( decal2Texture.clampMode, out, info );
			NifStream( decal2Texture.filterMode, out, info );
		};
		if ( info.version >= 0x14010003 ) {
			NifStream( decal2Texture.flags, out, info );
		};
		if ( info.version >= 0x14050004 ) {
			NifStream( decal2Texture.maxAnisotropy, out, info );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( decal2Texture.uvSet, out, info );
		};
		if ( info.version <= 0x0A040001 ) {
			NifStream( decal2Texture.ps2L, out, info );
			NifStream( decal2Texture.ps2K, out, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( decal2Texture.unknown1, out, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( decal2Texture.hasTextureTransform, out, info );
			if ( decal2Texture.hasTextureTransform ) {
				NifStream( decal2Texture.translation, out, info );
				NifStream( decal2Texture.scale, out, info );
				NifStream( decal2Texture.rotation, out, info );
				NifStream( decal2Texture.transformMethod, out, info );
				NifStream( decal2Texture.center, out, info );
			};
		};
	};
	if ( info.version <= 0x14020004 ) {
		if ( (textureCount > 9) ) {
			NifStream( hasDecal3Texture, out, info );
		};
	};
	if ( info.version >= 0x14020005 ) {
		if ( (textureCount > 11) ) {
			NifStream( (bool&)hasDecal3Texture, out, info );
		};
	};
	if ( hasDecal3Texture ) {
		if ( info.version <= 0x03010000 ) {
			WriteRef( StaticCast<NiObject>(decal3Texture.image), out, info, link_map, missing_link_stack );
		};
		if ( info.version >= 0x0303000D ) {
			WriteRef( StaticCast<NiObject>(decal3Texture.source), out, info, link_map, missing_link_stack );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( decal3Texture.clampMode, out, info );
			NifStream( decal3Texture.filterMode, out, info );
		};
		if ( info.version >= 0x14010003 ) {
			NifStream( decal3Texture.flags, out, info );
		};
		if ( info.version >= 0x14050004 ) {
			NifStream( decal3Texture.maxAnisotropy, out, info );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( decal3Texture.uvSet, out, info );
		};
		if ( info.version <= 0x0A040001 ) {
			NifStream( decal3Texture.ps2L, out, info );
			NifStream( decal3Texture.ps2K, out, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( decal3Texture.unknown1, out, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( decal3Texture.hasTextureTransform, out, info );
			if ( decal3Texture.hasTextureTransform ) {
				NifStream( decal3Texture.translation, out, info );
				NifStream( decal3Texture.scale, out, info );
				NifStream( decal3Texture.rotation, out, info );
				NifStream( decal3Texture.transformMethod, out, info );
				NifStream( decal3Texture.center, out, info );
			};
		};
	};
	if ( info.version >= 0x0A000100 ) {
		NifStream( numShaderTextures, out, info );
		for (unsigned int i2 = 0; i2 < shaderTextures.size(); i2++) {
			NifStream( shaderTextures[i2].hasMap, out, info );
			if ( shaderTextures[i2].hasMap ) {
				if ( info.version <= 0x03010000 ) {
					WriteRef( StaticCast<NiObject>(shaderTextures[i2].map.image), out, info, link_map, missing_link_stack );
				};
				if ( info.version >= 0x0303000D ) {
					WriteRef( StaticCast<NiObject>(shaderTextures[i2].map.source), out, info, link_map, missing_link_stack );
				};
				if ( info.version <= 0x14000005 ) {
					NifStream( shaderTextures[i2].map.clampMode, out, info );
					NifStream( shaderTextures[i2].map.filterMode, out, info );
				};
				if ( info.version >= 0x14010003 ) {
					NifStream( shaderTextures[i2].map.flags, out, info );
				};
				if ( info.version >= 0x14050004 ) {
					NifStream( shaderTextures[i2].map.maxAnisotropy, out, info );
				};
				if ( info.version <= 0x14000005 ) {
					NifStream( shaderTextures[i2].map.uvSet, out, info );
				};
				if ( info.version <= 0x0A040001 ) {
					NifStream( shaderTextures[i2].map.ps2L, out, info );
					NifStream( shaderTextures[i2].map.ps2K, out, info );
				};
				if ( info.version <= 0x0401000C ) {
					NifStream( shaderTextures[i2].map.unknown1, out, info );
				};
				if ( info.version >= 0x0A010000 ) {
					NifStream( shaderTextures[i2].map.hasTextureTransform, out, info );
					if ( shaderTextures[i2].map.hasTextureTransform ) {
						NifStream( shaderTextures[i2].map.translation, out, info );
						NifStream( shaderTextures[i2].map.scale, out, info );
						NifStream( shaderTextures[i2].map.rotation, out, info );
						NifStream( shaderTextures[i2].map.transformMethod, out, info );
						NifStream( shaderTextures[i2].map.center, out, info );
					};
				};
				NifStream( shaderTextures[i2].mapId, out, info );
			};
		};
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiTexturingProperty::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiProperty::asString();
	numShaderTextures = (unsigned int)(shaderTextures.size());
	out << "  Flags:  " << flags << endl;
	out << "  Apply Mode:  " << applyMode << endl;
	out << "  Texture Count:  " << textureCount << endl;
	out << "  Has Base Texture:  " << hasBaseTexture << endl;
	if ( hasBaseTexture ) {
		out << "    Image:  " << baseTexture.image << endl;
		out << "    Source:  " << baseTexture.source << endl;
		out << "    Clamp Mode:  " << baseTexture.clampMode << endl;
		out << "    Filter Mode:  " << baseTexture.filterMode << endl;
		out << "    Flags:  " << baseTexture.flags << endl;
		out << "    Max Anisotropy:  " << baseTexture.maxAnisotropy << endl;
		out << "    UV Set:  " << baseTexture.uvSet << endl;
		out << "    PS2 L:  " << baseTexture.ps2L << endl;
		out << "    PS2 K:  " << baseTexture.ps2K << endl;
		out << "    Unknown1:  " << baseTexture.unknown1 << endl;
		out << "    Has Texture Transform:  " << baseTexture.hasTextureTransform << endl;
		if ( baseTexture.hasTextureTransform ) {
			out << "      Translation:  " << baseTexture.translation << endl;
			out << "      Scale:  " << baseTexture.scale << endl;
			out << "      Rotation:  " << baseTexture.rotation << endl;
			out << "      Transform Method:  " << baseTexture.transformMethod << endl;
			out << "      Center:  " << baseTexture.center << endl;
		};
	};
	out << "  Has Dark Texture:  " << hasDarkTexture << endl;
	if ( hasDarkTexture ) {
		out << "    Image:  " << darkTexture.image << endl;
		out << "    Source:  " << darkTexture.source << endl;
		out << "    Clamp Mode:  " << darkTexture.clampMode << endl;
		out << "    Filter Mode:  " << darkTexture.filterMode << endl;
		out << "    Flags:  " << darkTexture.flags << endl;
		out << "    Max Anisotropy:  " << darkTexture.maxAnisotropy << endl;
		out << "    UV Set:  " << darkTexture.uvSet << endl;
		out << "    PS2 L:  " << darkTexture.ps2L << endl;
		out << "    PS2 K:  " << darkTexture.ps2K << endl;
		out << "    Unknown1:  " << darkTexture.unknown1 << endl;
		out << "    Has Texture Transform:  " << darkTexture.hasTextureTransform << endl;
		if ( darkTexture.hasTextureTransform ) {
			out << "      Translation:  " << darkTexture.translation << endl;
			out << "      Scale:  " << darkTexture.scale << endl;
			out << "      Rotation:  " << darkTexture.rotation << endl;
			out << "      Transform Method:  " << darkTexture.transformMethod << endl;
			out << "      Center:  " << darkTexture.center << endl;
		};
	};
	out << "  Has Detail Texture:  " << hasDetailTexture << endl;
	if ( hasDetailTexture ) {
		out << "    Image:  " << detailTexture.image << endl;
		out << "    Source:  " << detailTexture.source << endl;
		out << "    Clamp Mode:  " << detailTexture.clampMode << endl;
		out << "    Filter Mode:  " << detailTexture.filterMode << endl;
		out << "    Flags:  " << detailTexture.flags << endl;
		out << "    Max Anisotropy:  " << detailTexture.maxAnisotropy << endl;
		out << "    UV Set:  " << detailTexture.uvSet << endl;
		out << "    PS2 L:  " << detailTexture.ps2L << endl;
		out << "    PS2 K:  " << detailTexture.ps2K << endl;
		out << "    Unknown1:  " << detailTexture.unknown1 << endl;
		out << "    Has Texture Transform:  " << detailTexture.hasTextureTransform << endl;
		if ( detailTexture.hasTextureTransform ) {
			out << "      Translation:  " << detailTexture.translation << endl;
			out << "      Scale:  " << detailTexture.scale << endl;
			out << "      Rotation:  " << detailTexture.rotation << endl;
			out << "      Transform Method:  " << detailTexture.transformMethod << endl;
			out << "      Center:  " << detailTexture.center << endl;
		};
	};
	out << "  Has Gloss Texture:  " << hasGlossTexture << endl;
	if ( hasGlossTexture ) {
		out << "    Image:  " << glossTexture.image << endl;
		out << "    Source:  " << glossTexture.source << endl;
		out << "    Clamp Mode:  " << glossTexture.clampMode << endl;
		out << "    Filter Mode:  " << glossTexture.filterMode << endl;
		out << "    Flags:  " << glossTexture.flags << endl;
		out << "    Max Anisotropy:  " << glossTexture.maxAnisotropy << endl;
		out << "    UV Set:  " << glossTexture.uvSet << endl;
		out << "    PS2 L:  " << glossTexture.ps2L << endl;
		out << "    PS2 K:  " << glossTexture.ps2K << endl;
		out << "    Unknown1:  " << glossTexture.unknown1 << endl;
		out << "    Has Texture Transform:  " << glossTexture.hasTextureTransform << endl;
		if ( glossTexture.hasTextureTransform ) {
			out << "      Translation:  " << glossTexture.translation << endl;
			out << "      Scale:  " << glossTexture.scale << endl;
			out << "      Rotation:  " << glossTexture.rotation << endl;
			out << "      Transform Method:  " << glossTexture.transformMethod << endl;
			out << "      Center:  " << glossTexture.center << endl;
		};
	};
	out << "  Has Glow Texture:  " << hasGlowTexture << endl;
	if ( hasGlowTexture ) {
		out << "    Image:  " << glowTexture.image << endl;
		out << "    Source:  " << glowTexture.source << endl;
		out << "    Clamp Mode:  " << glowTexture.clampMode << endl;
		out << "    Filter Mode:  " << glowTexture.filterMode << endl;
		out << "    Flags:  " << glowTexture.flags << endl;
		out << "    Max Anisotropy:  " << glowTexture.maxAnisotropy << endl;
		out << "    UV Set:  " << glowTexture.uvSet << endl;
		out << "    PS2 L:  " << glowTexture.ps2L << endl;
		out << "    PS2 K:  " << glowTexture.ps2K << endl;
		out << "    Unknown1:  " << glowTexture.unknown1 << endl;
		out << "    Has Texture Transform:  " << glowTexture.hasTextureTransform << endl;
		if ( glowTexture.hasTextureTransform ) {
			out << "      Translation:  " << glowTexture.translation << endl;
			out << "      Scale:  " << glowTexture.scale << endl;
			out << "      Rotation:  " << glowTexture.rotation << endl;
			out << "      Transform Method:  " << glowTexture.transformMethod << endl;
			out << "      Center:  " << glowTexture.center << endl;
		};
	};
	if ( (textureCount > 5) ) {
		out << "    Has Bump Map Texture:  " << hasBumpMapTexture << endl;
	};
	if ( hasBumpMapTexture ) {
		out << "    Image:  " << bumpMapTexture.image << endl;
		out << "    Source:  " << bumpMapTexture.source << endl;
		out << "    Clamp Mode:  " << bumpMapTexture.clampMode << endl;
		out << "    Filter Mode:  " << bumpMapTexture.filterMode << endl;
		out << "    Flags:  " << bumpMapTexture.flags << endl;
		out << "    Max Anisotropy:  " << bumpMapTexture.maxAnisotropy << endl;
		out << "    UV Set:  " << bumpMapTexture.uvSet << endl;
		out << "    PS2 L:  " << bumpMapTexture.ps2L << endl;
		out << "    PS2 K:  " << bumpMapTexture.ps2K << endl;
		out << "    Unknown1:  " << bumpMapTexture.unknown1 << endl;
		out << "    Has Texture Transform:  " << bumpMapTexture.hasTextureTransform << endl;
		if ( bumpMapTexture.hasTextureTransform ) {
			out << "      Translation:  " << bumpMapTexture.translation << endl;
			out << "      Scale:  " << bumpMapTexture.scale << endl;
			out << "      Rotation:  " << bumpMapTexture.rotation << endl;
			out << "      Transform Method:  " << bumpMapTexture.transformMethod << endl;
			out << "      Center:  " << bumpMapTexture.center << endl;
		};
		out << "    Bump Map Luma Scale:  " << bumpMapLumaScale << endl;
		out << "    Bump Map Luma Offset:  " << bumpMapLumaOffset << endl;
		out << "    Bump Map Matrix:  " << bumpMapMatrix << endl;
	};
	if ( (textureCount > 6) ) {
		out << "    Has Normal Texture:  " << hasNormalTexture << endl;
	};
	if ( hasNormalTexture ) {
		out << "    Image:  " << normalTexture.image << endl;
		out << "    Source:  " << normalTexture.source << endl;
		out << "    Clamp Mode:  " << normalTexture.clampMode << endl;
		out << "    Filter Mode:  " << normalTexture.filterMode << endl;
		out << "    Flags:  " << normalTexture.flags << endl;
		out << "    Max Anisotropy:  " << normalTexture.maxAnisotropy << endl;
		out << "    UV Set:  " << normalTexture.uvSet << endl;
		out << "    PS2 L:  " << normalTexture.ps2L << endl;
		out << "    PS2 K:  " << normalTexture.ps2K << endl;
		out << "    Unknown1:  " << normalTexture.unknown1 << endl;
		out << "    Has Texture Transform:  " << normalTexture.hasTextureTransform << endl;
		if ( normalTexture.hasTextureTransform ) {
			out << "      Translation:  " << normalTexture.translation << endl;
			out << "      Scale:  " << normalTexture.scale << endl;
			out << "      Rotation:  " << normalTexture.rotation << endl;
			out << "      Transform Method:  " << normalTexture.transformMethod << endl;
			out << "      Center:  " << normalTexture.center << endl;
		};
	};
	if ( (textureCount > 7) ) {
		out << "    Has Parallax Texture:  " << hasParallaxTexture << endl;
	};
	if ( hasParallaxTexture ) {
		out << "    Image:  " << parallaxTexture.image << endl;
		out << "    Source:  " << parallaxTexture.source << endl;
		out << "    Clamp Mode:  " << parallaxTexture.clampMode << endl;
		out << "    Filter Mode:  " << parallaxTexture.filterMode << endl;
		out << "    Flags:  " << parallaxTexture.flags << endl;
		out << "    Max Anisotropy:  " << parallaxTexture.maxAnisotropy << endl;
		out << "    UV Set:  " << parallaxTexture.uvSet << endl;
		out << "    PS2 L:  " << parallaxTexture.ps2L << endl;
		out << "    PS2 K:  " << parallaxTexture.ps2K << endl;
		out << "    Unknown1:  " << parallaxTexture.unknown1 << endl;
		out << "    Has Texture Transform:  " << parallaxTexture.hasTextureTransform << endl;
		if ( parallaxTexture.hasTextureTransform ) {
			out << "      Translation:  " << parallaxTexture.translation << endl;
			out << "      Scale:  " << parallaxTexture.scale << endl;
			out << "      Rotation:  " << parallaxTexture.rotation << endl;
			out << "      Transform Method:  " << parallaxTexture.transformMethod << endl;
			out << "      Center:  " << parallaxTexture.center << endl;
		};
		out << "    Parallax Offset:  " << parallaxOffset << endl;
	};
	if ( (textureCount > 6) ) {
		out << "    Has Decal 0 Texture:  " << hasDecal0Texture << endl;
	};
	if ( hasDecal0Texture ) {
		out << "    Image:  " << decal0Texture.image << endl;
		out << "    Source:  " << decal0Texture.source << endl;
		out << "    Clamp Mode:  " << decal0Texture.clampMode << endl;
		out << "    Filter Mode:  " << decal0Texture.filterMode << endl;
		out << "    Flags:  " << decal0Texture.flags << endl;
		out << "    Max Anisotropy:  " << decal0Texture.maxAnisotropy << endl;
		out << "    UV Set:  " << decal0Texture.uvSet << endl;
		out << "    PS2 L:  " << decal0Texture.ps2L << endl;
		out << "    PS2 K:  " << decal0Texture.ps2K << endl;
		out << "    Unknown1:  " << decal0Texture.unknown1 << endl;
		out << "    Has Texture Transform:  " << decal0Texture.hasTextureTransform << endl;
		if ( decal0Texture.hasTextureTransform ) {
			out << "      Translation:  " << decal0Texture.translation << endl;
			out << "      Scale:  " << decal0Texture.scale << endl;
			out << "      Rotation:  " << decal0Texture.rotation << endl;
			out << "      Transform Method:  " << decal0Texture.transformMethod << endl;
			out << "      Center:  " << decal0Texture.center << endl;
		};
	};
	if ( (textureCount > 7) ) {
		out << "    Has Decal 1 Texture:  " << hasDecal1Texture << endl;
	};
	if ( hasDecal1Texture ) {
		out << "    Image:  " << decal1Texture.image << endl;
		out << "    Source:  " << decal1Texture.source << endl;
		out << "    Clamp Mode:  " << decal1Texture.clampMode << endl;
		out << "    Filter Mode:  " << decal1Texture.filterMode << endl;
		out << "    Flags:  " << decal1Texture.flags << endl;
		out << "    Max Anisotropy:  " << decal1Texture.maxAnisotropy << endl;
		out << "    UV Set:  " << decal1Texture.uvSet << endl;
		out << "    PS2 L:  " << decal1Texture.ps2L << endl;
		out << "    PS2 K:  " << decal1Texture.ps2K << endl;
		out << "    Unknown1:  " << decal1Texture.unknown1 << endl;
		out << "    Has Texture Transform:  " << decal1Texture.hasTextureTransform << endl;
		if ( decal1Texture.hasTextureTransform ) {
			out << "      Translation:  " << decal1Texture.translation << endl;
			out << "      Scale:  " << decal1Texture.scale << endl;
			out << "      Rotation:  " << decal1Texture.rotation << endl;
			out << "      Transform Method:  " << decal1Texture.transformMethod << endl;
			out << "      Center:  " << decal1Texture.center << endl;
		};
	};
	if ( (textureCount > 8) ) {
		out << "    Has Decal 2 Texture:  " << hasDecal2Texture << endl;
	};
	if ( hasDecal2Texture ) {
		out << "    Image:  " << decal2Texture.image << endl;
		out << "    Source:  " << decal2Texture.source << endl;
		out << "    Clamp Mode:  " << decal2Texture.clampMode << endl;
		out << "    Filter Mode:  " << decal2Texture.filterMode << endl;
		out << "    Flags:  " << decal2Texture.flags << endl;
		out << "    Max Anisotropy:  " << decal2Texture.maxAnisotropy << endl;
		out << "    UV Set:  " << decal2Texture.uvSet << endl;
		out << "    PS2 L:  " << decal2Texture.ps2L << endl;
		out << "    PS2 K:  " << decal2Texture.ps2K << endl;
		out << "    Unknown1:  " << decal2Texture.unknown1 << endl;
		out << "    Has Texture Transform:  " << decal2Texture.hasTextureTransform << endl;
		if ( decal2Texture.hasTextureTransform ) {
			out << "      Translation:  " << decal2Texture.translation << endl;
			out << "      Scale:  " << decal2Texture.scale << endl;
			out << "      Rotation:  " << decal2Texture.rotation << endl;
			out << "      Transform Method:  " << decal2Texture.transformMethod << endl;
			out << "      Center:  " << decal2Texture.center << endl;
		};
	};
	if ( (textureCount > 9) ) {
		out << "    Has Decal 3 Texture:  " << hasDecal3Texture << endl;
	};
	if ( hasDecal3Texture ) {
		out << "    Image:  " << decal3Texture.image << endl;
		out << "    Source:  " << decal3Texture.source << endl;
		out << "    Clamp Mode:  " << decal3Texture.clampMode << endl;
		out << "    Filter Mode:  " << decal3Texture.filterMode << endl;
		out << "    Flags:  " << decal3Texture.flags << endl;
		out << "    Max Anisotropy:  " << decal3Texture.maxAnisotropy << endl;
		out << "    UV Set:  " << decal3Texture.uvSet << endl;
		out << "    PS2 L:  " << decal3Texture.ps2L << endl;
		out << "    PS2 K:  " << decal3Texture.ps2K << endl;
		out << "    Unknown1:  " << decal3Texture.unknown1 << endl;
		out << "    Has Texture Transform:  " << decal3Texture.hasTextureTransform << endl;
		if ( decal3Texture.hasTextureTransform ) {
			out << "      Translation:  " << decal3Texture.translation << endl;
			out << "      Scale:  " << decal3Texture.scale << endl;
			out << "      Rotation:  " << decal3Texture.rotation << endl;
			out << "      Transform Method:  " << decal3Texture.transformMethod << endl;
			out << "      Center:  " << decal3Texture.center << endl;
		};
	};
	out << "  Num Shader Textures:  " << numShaderTextures << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < shaderTextures.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Has Map:  " << shaderTextures[i1].hasMap << endl;
		if ( shaderTextures[i1].hasMap ) {
			out << "      Image:  " << shaderTextures[i1].map.image << endl;
			out << "      Source:  " << shaderTextures[i1].map.source << endl;
			out << "      Clamp Mode:  " << shaderTextures[i1].map.clampMode << endl;
			out << "      Filter Mode:  " << shaderTextures[i1].map.filterMode << endl;
			out << "      Flags:  " << shaderTextures[i1].map.flags << endl;
			out << "      Max Anisotropy:  " << shaderTextures[i1].map.maxAnisotropy << endl;
			out << "      UV Set:  " << shaderTextures[i1].map.uvSet << endl;
			out << "      PS2 L:  " << shaderTextures[i1].map.ps2L << endl;
			out << "      PS2 K:  " << shaderTextures[i1].map.ps2K << endl;
			out << "      Unknown1:  " << shaderTextures[i1].map.unknown1 << endl;
			out << "      Has Texture Transform:  " << shaderTextures[i1].map.hasTextureTransform << endl;
			if ( shaderTextures[i1].map.hasTextureTransform ) {
				out << "        Translation:  " << shaderTextures[i1].map.translation << endl;
				out << "        Scale:  " << shaderTextures[i1].map.scale << endl;
				out << "        Rotation:  " << shaderTextures[i1].map.rotation << endl;
				out << "        Transform Method:  " << shaderTextures[i1].map.transformMethod << endl;
				out << "        Center:  " << shaderTextures[i1].map.center << endl;
			};
			out << "      Map ID:  " << shaderTextures[i1].mapId << endl;
		};
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiTexturingProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiProperty::FixLinks( objects, link_stack, missing_link_stack, info );
	if ( hasBaseTexture ) {
		if ( info.version <= 0x03010000 ) {
			baseTexture.image = FixLink<NiImage>( objects, link_stack, missing_link_stack, info );
		};
		if ( info.version >= 0x0303000D ) {
			baseTexture.source = FixLink<NiSourceTexture>( objects, link_stack, missing_link_stack, info );
		};
	};
	if ( hasDarkTexture ) {
		if ( info.version <= 0x03010000 ) {
			darkTexture.image = FixLink<NiImage>( objects, link_stack, missing_link_stack, info );
		};
		if ( info.version >= 0x0303000D ) {
			darkTexture.source = FixLink<NiSourceTexture>( objects, link_stack, missing_link_stack, info );
		};
	};
	if ( hasDetailTexture ) {
		if ( info.version <= 0x03010000 ) {
			detailTexture.image = FixLink<NiImage>( objects, link_stack, missing_link_stack, info );
		};
		if ( info.version >= 0x0303000D ) {
			detailTexture.source = FixLink<NiSourceTexture>( objects, link_stack, missing_link_stack, info );
		};
	};
	if ( hasGlossTexture ) {
		if ( info.version <= 0x03010000 ) {
			glossTexture.image = FixLink<NiImage>( objects, link_stack, missing_link_stack, info );
		};
		if ( info.version >= 0x0303000D ) {
			glossTexture.source = FixLink<NiSourceTexture>( objects, link_stack, missing_link_stack, info );
		};
	};
	if ( hasGlowTexture ) {
		if ( info.version <= 0x03010000 ) {
			glowTexture.image = FixLink<NiImage>( objects, link_stack, missing_link_stack, info );
		};
		if ( info.version >= 0x0303000D ) {
			glowTexture.source = FixLink<NiSourceTexture>( objects, link_stack, missing_link_stack, info );
		};
	};
	if ( hasBumpMapTexture ) {
		if ( info.version <= 0x03010000 ) {
			bumpMapTexture.image = FixLink<NiImage>( objects, link_stack, missing_link_stack, info );
		};
		if ( info.version >= 0x0303000D ) {
			bumpMapTexture.source = FixLink<NiSourceTexture>( objects, link_stack, missing_link_stack, info );
		};
	};
	if ( hasNormalTexture ) {
		if ( info.version <= 0x03010000 ) {
			normalTexture.image = FixLink<NiImage>( objects, link_stack, missing_link_stack, info );
		};
		if ( info.version >= 0x0303000D ) {
			normalTexture.source = FixLink<NiSourceTexture>( objects, link_stack, missing_link_stack, info );
		};
	};
	if ( hasParallaxTexture ) {
		if ( info.version <= 0x03010000 ) {
			parallaxTexture.image = FixLink<NiImage>( objects, link_stack, missing_link_stack, info );
		};
		if ( info.version >= 0x0303000D ) {
			parallaxTexture.source = FixLink<NiSourceTexture>( objects, link_stack, missing_link_stack, info );
		};
	};
	if ( hasDecal0Texture ) {
		if ( info.version <= 0x03010000 ) {
			decal0Texture.image = FixLink<NiImage>( objects, link_stack, missing_link_stack, info );
		};
		if ( info.version >= 0x0303000D ) {
			decal0Texture.source = FixLink<NiSourceTexture>( objects, link_stack, missing_link_stack, info );
		};
	};
	if ( hasDecal1Texture ) {
		if ( info.version <= 0x03010000 ) {
			decal1Texture.image = FixLink<NiImage>( objects, link_stack, missing_link_stack, info );
		};
		if ( info.version >= 0x0303000D ) {
			decal1Texture.source = FixLink<NiSourceTexture>( objects, link_stack, missing_link_stack, info );
		};
	};
	if ( hasDecal2Texture ) {
		if ( info.version <= 0x03010000 ) {
			decal2Texture.image = FixLink<NiImage>( objects, link_stack, missing_link_stack, info );
		};
		if ( info.version >= 0x0303000D ) {
			decal2Texture.source = FixLink<NiSourceTexture>( objects, link_stack, missing_link_stack, info );
		};
	};
	if ( hasDecal3Texture ) {
		if ( info.version <= 0x03010000 ) {
			decal3Texture.image = FixLink<NiImage>( objects, link_stack, missing_link_stack, info );
		};
		if ( info.version >= 0x0303000D ) {
			decal3Texture.source = FixLink<NiSourceTexture>( objects, link_stack, missing_link_stack, info );
		};
	};
	if ( info.version >= 0x0A000100 ) {
		for (unsigned int i2 = 0; i2 < shaderTextures.size(); i2++) {
			if ( shaderTextures[i2].hasMap ) {
				if ( info.version <= 0x03010000 ) {
					shaderTextures[i2].map.image = FixLink<NiImage>( objects, link_stack, missing_link_stack, info );
				};
				if ( info.version >= 0x0303000D ) {
					shaderTextures[i2].map.source = FixLink<NiSourceTexture>( objects, link_stack, missing_link_stack, info );
				};
			};
		};
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiTexturingProperty::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	if ( baseTexture.image != NULL )
		refs.push_back(StaticCast<NiObject>(baseTexture.image));
	if ( baseTexture.source != NULL )
		refs.push_back(StaticCast<NiObject>(baseTexture.source));
	if ( darkTexture.image != NULL )
		refs.push_back(StaticCast<NiObject>(darkTexture.image));
	if ( darkTexture.source != NULL )
		refs.push_back(StaticCast<NiObject>(darkTexture.source));
	if ( detailTexture.image != NULL )
		refs.push_back(StaticCast<NiObject>(detailTexture.image));
	if ( detailTexture.source != NULL )
		refs.push_back(StaticCast<NiObject>(detailTexture.source));
	if ( glossTexture.image != NULL )
		refs.push_back(StaticCast<NiObject>(glossTexture.image));
	if ( glossTexture.source != NULL )
		refs.push_back(StaticCast<NiObject>(glossTexture.source));
	if ( glowTexture.image != NULL )
		refs.push_back(StaticCast<NiObject>(glowTexture.image));
	if ( glowTexture.source != NULL )
		refs.push_back(StaticCast<NiObject>(glowTexture.source));
	if ( bumpMapTexture.image != NULL )
		refs.push_back(StaticCast<NiObject>(bumpMapTexture.image));
	if ( bumpMapTexture.source != NULL )
		refs.push_back(StaticCast<NiObject>(bumpMapTexture.source));
	if ( normalTexture.image != NULL )
		refs.push_back(StaticCast<NiObject>(normalTexture.image));
	if ( normalTexture.source != NULL )
		refs.push_back(StaticCast<NiObject>(normalTexture.source));
	if ( parallaxTexture.image != NULL )
		refs.push_back(StaticCast<NiObject>(parallaxTexture.image));
	if ( parallaxTexture.source != NULL )
		refs.push_back(StaticCast<NiObject>(parallaxTexture.source));
	if ( decal0Texture.image != NULL )
		refs.push_back(StaticCast<NiObject>(decal0Texture.image));
	if ( decal0Texture.source != NULL )
		refs.push_back(StaticCast<NiObject>(decal0Texture.source));
	if ( decal1Texture.image != NULL )
		refs.push_back(StaticCast<NiObject>(decal1Texture.image));
	if ( decal1Texture.source != NULL )
		refs.push_back(StaticCast<NiObject>(decal1Texture.source));
	if ( decal2Texture.image != NULL )
		refs.push_back(StaticCast<NiObject>(decal2Texture.image));
	if ( decal2Texture.source != NULL )
		refs.push_back(StaticCast<NiObject>(decal2Texture.source));
	if ( decal3Texture.image != NULL )
		refs.push_back(StaticCast<NiObject>(decal3Texture.image));
	if ( decal3Texture.source != NULL )
		refs.push_back(StaticCast<NiObject>(decal3Texture.source));
	for (unsigned int i1 = 0; i1 < shaderTextures.size(); i1++) {
		if ( shaderTextures[i1].map.image != NULL )
			refs.push_back(StaticCast<NiObject>(shaderTextures[i1].map.image));
		if ( shaderTextures[i1].map.source != NULL )
			refs.push_back(StaticCast<NiObject>(shaderTextures[i1].map.source));
	};
	return refs;
}

std::list<NiObject *> NiTexturingProperty::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiProperty::GetPtrs();
	for (unsigned int i1 = 0; i1 < shaderTextures.size(); i1++) {
	};
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

ApplyMode NiTexturingProperty::GetApplyMode() const {
	return applyMode;
}

void NiTexturingProperty::SetApplyMode( ApplyMode new_val ) {
	applyMode = new_val;
}

int NiTexturingProperty::GetTextureCount() const {
	//TODO:  Create a built in type for this array of textures so it can be a real array again?
	//int count = 0;
	//if ( hasBaseTexture ) { count++; }
	//if ( hasBumpMapTexture ) { count++; }
	//if ( hasDarkTexture ) { count++; }
	//if ( hasDecal0Texture ) { count++; }
	//if ( hasDecal1Texture ) { count++; }
	//if ( hasDetailTexture ) { count++; }
	//if ( hasGlossTexture ) { count++; }
	//if ( hasGlowTexture ) { count++; }
 //  if ( hasNormalTexture ) { count++; }
 //  if ( hasUnknown2Texture ) { count++; }
 //  if ( hasDecal2Texture ) { count++; }
 //  if ( hasDecal3Texture ) { count++; }
	//return count;
   return textureCount;
}

int NiTexturingProperty::GetShaderTextureCount() const {
	return int(shaderTextures.size());
}

TexDesc & NiTexturingProperty::GetTexture( int n ) {
	//TODO:  Create a built in type for this array of textures so it can be a real array again?
	//Copy the values to the right texture
	switch (n) {
		case BASE_MAP:
			return baseTexture;
		case DARK_MAP:
			return darkTexture;
		case DETAIL_MAP:
			return detailTexture;
		case GLOSS_MAP:
			return glossTexture;
		case GLOW_MAP:
			return glowTexture;
		case BUMP_MAP:
			return bumpMapTexture;
      case NORMAL_MAP:
         return normalTexture;
      case PARALLAX_MAP:
         return parallaxTexture;
		case DECAL_0_MAP:
			return decal0Texture;
		case DECAL_1_MAP:
			return decal1Texture;
      case DECAL_2_MAP:
         return decal2Texture;
      case DECAL_3_MAP:
         return decal3Texture;
	};

	//If we get here, an invalid texture was requested.
	throw runtime_error("Invalid texture requested.");
}

TexDesc NiTexturingProperty::GetShaderTexture( int n ) const {
	return shaderTextures[n].map;
}

float NiTexturingProperty::GetLumaOffset() const {
	return bumpMapLumaOffset;
}

void NiTexturingProperty::SetLumaOffset( float new_val ) {
	bumpMapLumaOffset = new_val;
}

float NiTexturingProperty::GetLumaScale() const {
	return bumpMapLumaScale;
}

void NiTexturingProperty::SetLumaScale( float new_val ) {
	bumpMapLumaScale = new_val;
}

Matrix22 NiTexturingProperty::GetBumpMapMatrix() const {
	return bumpMapMatrix;
}

void NiTexturingProperty::SetBumpMapMatrix( Matrix22 & new_val ) {
	bumpMapMatrix = new_val;
}

float NiTexturingProperty::GetParallaxOffset() const {
	return parallaxOffset;
}

void NiTexturingProperty::SetParallaxOffset(float value)
{
	parallaxOffset = value;
}

void NiTexturingProperty::SetTextureCount( int new_count ) {

	//if ( new_count < int(textureCount) ) {
	//	for ( int i = int(textureCount); i > new_count; --i ) {
	//		ClearTexture(i);
	//	}
	//}
   textureCount = new_count;
}

void NiTexturingProperty::SetShaderTextureCount( int new_count ) {
	//Resize array
	shaderTextures.resize( new_count );
}

void NiTexturingProperty::SetTexture( int n, TexDesc & new_val ) {
	//Make sure index is not out of range
	
	if ( n < 0 || n > int(textureCount) ) {
		throw runtime_error("SetTexture - Index out of range.  Call SetTextureCount to resize.");
	}

	//TODO:  Create a built in type for this array of textures so it can be a real array again?
	//Copy the values to the right texture
	switch (n) {
		case BASE_MAP:
			hasBaseTexture = true;
			baseTexture = new_val;
			break;
		case DARK_MAP:
			hasDarkTexture = true;
			darkTexture = new_val;
			break;
		case DETAIL_MAP:
			hasDetailTexture = true;
			detailTexture = new_val;
			break;
		case GLOSS_MAP:
			hasGlossTexture = true;
			glossTexture = new_val;
			break;
		case GLOW_MAP:
			hasGlowTexture = true;
			glowTexture = new_val;
			break;
		case BUMP_MAP:
			hasBumpMapTexture = true;
			bumpMapTexture = new_val;
			break;
      case NORMAL_MAP:
         hasNormalTexture = true;
         normalTexture = new_val;
         break;
      case PARALLAX_MAP:
         hasParallaxTexture = true;
         parallaxTexture = new_val;
         break;
		case DECAL_0_MAP:
			hasDecal0Texture = true;
			decal0Texture = new_val;
			break;
		case DECAL_1_MAP:
			hasDecal1Texture = true;
			decal1Texture = new_val;
			break;
      case DECAL_2_MAP:
         hasDecal2Texture = true;
         decal2Texture = new_val;
         break;
      case DECAL_3_MAP:
         hasDecal3Texture = true;
         decal3Texture = new_val;
         break;
	};
}

void NiTexturingProperty::SetShaderTexture( int n, TexDesc & new_val, unsigned int id ) {
	//Make sure index is not out of range
	if ( n < 0 || n > int(shaderTextures.size()) ) {
		throw runtime_error("SetShaderTexture - Index out of range.  Call SetShaderTextureCount to resize.");
	}

	//Copy the values
	shaderTextures[n].hasMap = true;
	shaderTextures[n].map = new_val;
	shaderTextures[n].mapId = id; // TODO!
}

bool NiTexturingProperty::HasTexture( int n ) const {
   switch (n) {
      case BASE_MAP:
         return hasBaseTexture;
      case DARK_MAP:
         return hasDarkTexture;
      case DETAIL_MAP:
         return hasDetailTexture;
      case GLOSS_MAP:
         return hasGlossTexture;
      case GLOW_MAP:
         return hasGlowTexture;
      case BUMP_MAP:
         return hasBumpMapTexture;
      case NORMAL_MAP:
         return hasNormalTexture;
      case PARALLAX_MAP:
         return hasParallaxTexture;
      case DECAL_0_MAP:
         return hasDecal0Texture;
      case DECAL_1_MAP:
         return hasDecal1Texture;
      case DECAL_2_MAP:
         return hasDecal2Texture;
      case DECAL_3_MAP:
         return hasDecal3Texture;
      default:
         return false;
         //throw runtime_error("You have specified an invalid texture type.");
   };
}

void NiTexturingProperty::ClearTexture( int n ) {
	switch (n) {
		case BASE_MAP:
			hasBaseTexture = false;
			baseTexture.source = NULL;
			break;
		case DARK_MAP:
			hasDarkTexture = false;
			darkTexture.source = NULL;
			break;
		case DETAIL_MAP:
			hasDetailTexture = false;
			detailTexture.source = NULL;
			break;
		case GLOSS_MAP:
			hasGlossTexture = false;
			glossTexture.source = NULL;
			break;
		case GLOW_MAP:
			hasGlowTexture = false;
			glowTexture.source = NULL;
			break;
		case BUMP_MAP:
			hasBumpMapTexture = false;
			bumpMapTexture.source = NULL;
			break;
      case NORMAL_MAP:
         hasNormalTexture = false;
         normalTexture.source = NULL;
         break;
      case PARALLAX_MAP:
         hasParallaxTexture = false;
         parallaxTexture.source = NULL;
         break;
		case DECAL_0_MAP:
			hasDecal0Texture = false;
			decal0Texture.source = NULL;
			break;
		case DECAL_1_MAP:
			hasDecal1Texture = false;
			decal1Texture.source = NULL;
			break;
      case DECAL_2_MAP:
         hasDecal2Texture = false;
         decal2Texture.source = NULL;
         break;
      case DECAL_3_MAP:
         hasDecal3Texture = false;
         decal3Texture.source = NULL;
         break;
	};
}

//--END CUSTOM CODE--//

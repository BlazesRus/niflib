/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#include <string>
#include <iostream>
#include "../../include/NIF_IO.h"
#include "../../include/gen/enums.h"
#include "../../include/gen/enums_intl.h"

using namespace std;

namespace Niflib {


//--ForceType--//

void NifStream( ForceType & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = ForceType(temp);
}

void NifStream( ForceType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, ForceType const & val ) {
	switch ( val ) {
		case FORCE_PLANAR: return out << "FORCE_PLANAR";
		case FORCE_SPHERICAL: return out << "FORCE_SPHERICAL";
		case FORCE_UNKNOWN: return out << "FORCE_UNKNOWN";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--EffectShaderControlledColor--//

void NifStream( EffectShaderControlledColor & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = EffectShaderControlledColor(temp);
}

void NifStream( EffectShaderControlledColor const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, EffectShaderControlledColor const & val ) {
	switch ( val ) {
		case ECSC_EMISSIVE_COLOR: return out << "ECSC_Emissive Color";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--AlignMethod--//

void NifStream( AlignMethod & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = AlignMethod(temp);
}

void NifStream( AlignMethod const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, AlignMethod const & val ) {
	switch ( val ) {
		case ALIGN_INVALID: return out << "ALIGN_INVALID";
		case ALIGN_PER_PARTICLE: return out << "ALIGN_PER_PARTICLE";
		case ALIGN_LOCAL_FIXED: return out << "ALIGN_LOCAL_FIXED";
		case ALIGN_LOCAL_POSITION: return out << "ALIGN_LOCAL_POSITION";
		case ALIGN_LOCAL_VELOCITY: return out << "ALIGN_LOCAL_VELOCITY";
		case ALIGN_CAMERA: return out << "ALIGN_CAMERA";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--CollisionMode--//

void NifStream( CollisionMode & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = CollisionMode(temp);
}

void NifStream( CollisionMode const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, CollisionMode const & val ) {
	switch ( val ) {
		case CM_USE_OBB: return out << "CM_USE_OBB";
		case CM_USE_TRI: return out << "CM_USE_TRI";
		case CM_USE_ABV: return out << "CM_USE_ABV";
		case CM_NOTEST: return out << "CM_NOTEST";
		case CM_USE_NIBOUND: return out << "CM_USE_NIBOUND";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--PSForceType--//

void NifStream( PSForceType & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = PSForceType(temp);
}

void NifStream( PSForceType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, PSForceType const & val ) {
	switch ( val ) {
		case FORCE_BOMB: return out << "FORCE_BOMB";
		case FORCE_DRAG: return out << "FORCE_DRAG";
		case FORCE_AIR_FIELD: return out << "FORCE_AIR_FIELD";
		case FORCE_DRAG_FIELD: return out << "FORCE_DRAG_FIELD";
		case FORCE_GRAVITY_FIELD: return out << "FORCE_GRAVITY_FIELD";
		case FORCE_RADIAL_FIELD: return out << "FORCE_RADIAL_FIELD";
		case FORCE_TURBULENCE_FIELD: return out << "FORCE_TURBULENCE_FIELD";
		case FORCE_VORTEX_FIELD: return out << "FORCE_VORTEX_FIELD";
		case FORCE_GRAVITY: return out << "FORCE_GRAVITY";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--ConsistencyType--//

void NifStream( ConsistencyType & val, istream& in, const NifInfo & info ) {
	unsigned short temp;
	NifStream( temp, in, info );
	val = ConsistencyType(temp);
}

void NifStream( ConsistencyType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned short)(val), out, info );
}

ostream & operator<<( ostream & out, ConsistencyType const & val ) {
	switch ( val ) {
		case CT_MUTABLE: return out << "CT_MUTABLE";
		case CT_STATIC: return out << "CT_STATIC";
		case CT_VOLATILE: return out << "CT_VOLATILE";
		default: return out << "Invalid Value! - " << (unsigned short)(val);
	}
}

//--PlatformID--//

void NifStream( PlatformID & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = PlatformID(temp);
}

void NifStream( PlatformID const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, PlatformID const & val ) {
	switch ( val ) {
		case PLATFORM_ANY: return out << "PLATFORM_ANY";
		case PLATFORM_XENON: return out << "PLATFORM_XENON";
		case PLATFORM_PS3: return out << "PLATFORM_PS3";
		case PLATFORM_DX9: return out << "PLATFORM_DX9";
		case PLATFORM_WII: return out << "PLATFORM_WII";
		case PLATFORM_D3D10: return out << "PLATFORM_D3D10";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--BSDismemberBodyPartType--//

void NifStream( BSDismemberBodyPartType & val, istream& in, const NifInfo & info ) {
	unsigned short temp;
	NifStream( temp, in, info );
	val = BSDismemberBodyPartType(temp);
}

void NifStream( BSDismemberBodyPartType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned short)(val), out, info );
}

ostream & operator<<( ostream & out, BSDismemberBodyPartType const & val ) {
	switch ( val ) {
		case BP_TORSO: return out << "BP_TORSO";
		case BP_HEAD: return out << "BP_HEAD";
		case BP_HEAD2: return out << "BP_HEAD2";
		case BP_LEFTARM: return out << "BP_LEFTARM";
		case BP_LEFTARM2: return out << "BP_LEFTARM2";
		case BP_RIGHTARM: return out << "BP_RIGHTARM";
		case BP_RIGHTARM2: return out << "BP_RIGHTARM2";
		case BP_LEFTLEG: return out << "BP_LEFTLEG";
		case BP_LEFTLEG2: return out << "BP_LEFTLEG2";
		case BP_LEFTLEG3: return out << "BP_LEFTLEG3";
		case BP_RIGHTLEG: return out << "BP_RIGHTLEG";
		case BP_RIGHTLEG2: return out << "BP_RIGHTLEG2";
		case BP_RIGHTLEG3: return out << "BP_RIGHTLEG3";
		case BP_BRAIN: return out << "BP_BRAIN";
		case SBP_30_HEAD: return out << "SBP_30_HEAD";
		case SBP_31_HAIR: return out << "SBP_31_HAIR";
		case SBP_32_BODY: return out << "SBP_32_BODY";
		case SBP_33_HANDS: return out << "SBP_33_HANDS";
		case SBP_34_FOREARMS: return out << "SBP_34_FOREARMS";
		case SBP_35_AMULET: return out << "SBP_35_AMULET";
		case SBP_36_RING: return out << "SBP_36_RING";
		case SBP_37_FEET: return out << "SBP_37_FEET";
		case SBP_38_CALVES: return out << "SBP_38_CALVES";
		case SBP_39_SHIELD: return out << "SBP_39_SHIELD";
		case SBP_40_TAIL: return out << "SBP_40_TAIL";
		case SBP_41_LONGHAIR: return out << "SBP_41_LONGHAIR";
		case SBP_42_CIRCLET: return out << "SBP_42_CIRCLET";
		case SBP_43_EARS: return out << "SBP_43_EARS";
		case SBP_44_DRAGON_BLOODHEAD_OR_MOD_MOUTH: return out << "SBP_44_DRAGON_BLOODHEAD_OR_MOD_MOUTH";
		case SBP_45_DRAGON_BLOODWINGL_OR_MOD_NECK: return out << "SBP_45_DRAGON_BLOODWINGL_OR_MOD_NECK";
		case SBP_46_DRAGON_BLOODWINGR_OR_MOD_CHEST_PRIMARY: return out << "SBP_46_DRAGON_BLOODWINGR_OR_MOD_CHEST_PRIMARY";
		case SBP_47_DRAGON_BLOODTAIL_OR_MOD_BACK: return out << "SBP_47_DRAGON_BLOODTAIL_OR_MOD_BACK";
		case SBP_48_MOD_MISC1: return out << "SBP_48_MOD_MISC1";
		case SBP_49_MOD_PELVIS_PRIMARY: return out << "SBP_49_MOD_PELVIS_PRIMARY";
		case SBP_50_DECAPITATEDHEAD: return out << "SBP_50_DECAPITATEDHEAD";
		case SBP_51_DECAPITATE: return out << "SBP_51_DECAPITATE";
		case SBP_52_MOD_PELVIS_SECONDARY: return out << "SBP_52_MOD_PELVIS_SECONDARY";
		case SBP_53_MOD_LEG_RIGHT: return out << "SBP_53_MOD_LEG_RIGHT";
		case SBP_54_MOD_LEG_LEFT: return out << "SBP_54_MOD_LEG_LEFT";
		case SBP_55_MOD_FACE_JEWELRY: return out << "SBP_55_MOD_FACE_JEWELRY";
		case SBP_56_MOD_CHEST_SECONDARY: return out << "SBP_56_MOD_CHEST_SECONDARY";
		case SBP_57_MOD_SHOULDER: return out << "SBP_57_MOD_SHOULDER";
		case SBP_58_MOD_ARM_LEFT: return out << "SBP_58_MOD_ARM_LEFT";
		case SBP_59_MOD_ARM_RIGHT: return out << "SBP_59_MOD_ARM_RIGHT";
		case SBP_60_MOD_MISC2: return out << "SBP_60_MOD_MISC2";
		case SBP_61_FX01: return out << "SBP_61_FX01";
		case BP_SECTIONCAP_HEAD: return out << "BP_SECTIONCAP_HEAD";
		case BP_SECTIONCAP_HEAD2: return out << "BP_SECTIONCAP_HEAD2";
		case BP_SECTIONCAP_LEFTARM: return out << "BP_SECTIONCAP_LEFTARM";
		case BP_SECTIONCAP_LEFTARM2: return out << "BP_SECTIONCAP_LEFTARM2";
		case BP_SECTIONCAP_RIGHTARM: return out << "BP_SECTIONCAP_RIGHTARM";
		case BP_SECTIONCAP_RIGHTARM2: return out << "BP_SECTIONCAP_RIGHTARM2";
		case BP_SECTIONCAP_LEFTLEG: return out << "BP_SECTIONCAP_LEFTLEG";
		case BP_SECTIONCAP_LEFTLEG2: return out << "BP_SECTIONCAP_LEFTLEG2";
		case BP_SECTIONCAP_LEFTLEG3: return out << "BP_SECTIONCAP_LEFTLEG3";
		case BP_SECTIONCAP_RIGHTLEG: return out << "BP_SECTIONCAP_RIGHTLEG";
		case BP_SECTIONCAP_RIGHTLEG2: return out << "BP_SECTIONCAP_RIGHTLEG2";
		case BP_SECTIONCAP_RIGHTLEG3: return out << "BP_SECTIONCAP_RIGHTLEG3";
		case BP_SECTIONCAP_BRAIN: return out << "BP_SECTIONCAP_BRAIN";
		case SBP_130_HEAD: return out << "SBP_130_HEAD";
		case SBP_131_HAIR: return out << "SBP_131_HAIR";
		case SBP_141_LONGHAIR: return out << "SBP_141_LONGHAIR";
		case SBP_142_CIRCLET: return out << "SBP_142_CIRCLET";
		case SBP_143_EARS: return out << "SBP_143_EARS";
		case SBP_150_DECAPITATEDHEAD: return out << "SBP_150_DECAPITATEDHEAD";
		case BP_TORSOCAP_HEAD: return out << "BP_TORSOCAP_HEAD";
		case BP_TORSOCAP_HEAD2: return out << "BP_TORSOCAP_HEAD2";
		case BP_TORSOCAP_LEFTARM: return out << "BP_TORSOCAP_LEFTARM";
		case BP_TORSOCAP_LEFTARM2: return out << "BP_TORSOCAP_LEFTARM2";
		case BP_TORSOCAP_RIGHTARM: return out << "BP_TORSOCAP_RIGHTARM";
		case BP_TORSOCAP_RIGHTARM2: return out << "BP_TORSOCAP_RIGHTARM2";
		case BP_TORSOCAP_LEFTLEG: return out << "BP_TORSOCAP_LEFTLEG";
		case BP_TORSOCAP_LEFTLEG2: return out << "BP_TORSOCAP_LEFTLEG2";
		case BP_TORSOCAP_LEFTLEG3: return out << "BP_TORSOCAP_LEFTLEG3";
		case BP_TORSOCAP_RIGHTLEG: return out << "BP_TORSOCAP_RIGHTLEG";
		case BP_TORSOCAP_RIGHTLEG2: return out << "BP_TORSOCAP_RIGHTLEG2";
		case BP_TORSOCAP_RIGHTLEG3: return out << "BP_TORSOCAP_RIGHTLEG3";
		case BP_TORSOCAP_BRAIN: return out << "BP_TORSOCAP_BRAIN";
		case SBP_230_HEAD: return out << "SBP_230_HEAD";
		case BP_TORSOSECTION_HEAD: return out << "BP_TORSOSECTION_HEAD";
		case BP_TORSOSECTION_HEAD2: return out << "BP_TORSOSECTION_HEAD2";
		case BP_TORSOSECTION_LEFTARM: return out << "BP_TORSOSECTION_LEFTARM";
		case BP_TORSOSECTION_LEFTARM2: return out << "BP_TORSOSECTION_LEFTARM2";
		case BP_TORSOSECTION_RIGHTARM: return out << "BP_TORSOSECTION_RIGHTARM";
		case BP_TORSOSECTION_RIGHTARM2: return out << "BP_TORSOSECTION_RIGHTARM2";
		case BP_TORSOSECTION_LEFTLEG: return out << "BP_TORSOSECTION_LEFTLEG";
		case BP_TORSOSECTION_LEFTLEG2: return out << "BP_TORSOSECTION_LEFTLEG2";
		case BP_TORSOSECTION_LEFTLEG3: return out << "BP_TORSOSECTION_LEFTLEG3";
		case BP_TORSOSECTION_RIGHTLEG: return out << "BP_TORSOSECTION_RIGHTLEG";
		case BP_TORSOSECTION_RIGHTLEG2: return out << "BP_TORSOSECTION_RIGHTLEG2";
		case BP_TORSOSECTION_RIGHTLEG3: return out << "BP_TORSOSECTION_RIGHTLEG3";
		case BP_TORSOSECTION_BRAIN: return out << "BP_TORSOSECTION_BRAIN";
		default: return out << "Invalid Value! - " << (unsigned short)(val);
	}
}

//--Fallout3Layer--//

void NifStream( Fallout3Layer & val, istream& in, const NifInfo & info ) {
	byte temp;
	NifStream( temp, in, info );
	val = Fallout3Layer(temp);
}

void NifStream( Fallout3Layer const & val, ostream& out, const NifInfo & info ) {
	NifStream( (byte)(val), out, info );
}

ostream & operator<<( ostream & out, Fallout3Layer const & val ) {
	switch ( val ) {
		case FOL_UNIDENTIFIED: return out << "FOL_UNIDENTIFIED";
		case FOL_STATIC: return out << "FOL_STATIC";
		case FOL_ANIM_STATIC: return out << "FOL_ANIM_STATIC";
		case FOL_TRANSPARENT: return out << "FOL_TRANSPARENT";
		case FOL_CLUTTER: return out << "FOL_CLUTTER";
		case FOL_WEAPON: return out << "FOL_WEAPON";
		case FOL_PROJECTILE: return out << "FOL_PROJECTILE";
		case FOL_SPELL: return out << "FOL_SPELL";
		case FOL_BIPED: return out << "FOL_BIPED";
		case FOL_TREES: return out << "FOL_TREES";
		case FOL_PROPS: return out << "FOL_PROPS";
		case FOL_WATER: return out << "FOL_WATER";
		case FOL_TRIGGER: return out << "FOL_TRIGGER";
		case FOL_TERRAIN: return out << "FOL_TERRAIN";
		case FOL_TRAP: return out << "FOL_TRAP";
		case FOL_NONCOLLIDABLE: return out << "FOL_NONCOLLIDABLE";
		case FOL_CLOUD_TRAP: return out << "FOL_CLOUD_TRAP";
		case FOL_GROUND: return out << "FOL_GROUND";
		case FOL_PORTAL: return out << "FOL_PORTAL";
		case FOL_DEBRIS_SMALL: return out << "FOL_DEBRIS_SMALL";
		case FOL_DEBRIS_LARGE: return out << "FOL_DEBRIS_LARGE";
		case FOL_ACOUSTIC_SPACE: return out << "FOL_ACOUSTIC_SPACE";
		case FOL_ACTORZONE: return out << "FOL_ACTORZONE";
		case FOL_PROJECTILEZONE: return out << "FOL_PROJECTILEZONE";
		case FOL_GASTRAP: return out << "FOL_GASTRAP";
		case FOL_SHELLCASING: return out << "FOL_SHELLCASING";
		case FOL_TRANSPARENT_SMALL: return out << "FOL_TRANSPARENT_SMALL";
		case FOL_INVISIBLE_WALL: return out << "FOL_INVISIBLE_WALL";
		case FOL_TRANSPARENT_SMALL_ANIM: return out << "FOL_TRANSPARENT_SMALL_ANIM";
		case FOL_DEADBIP: return out << "FOL_DEADBIP";
		case FOL_CHARCONTROLLER: return out << "FOL_CHARCONTROLLER";
		case FOL_AVOIDBOX: return out << "FOL_AVOIDBOX";
		case FOL_COLLISIONBOX: return out << "FOL_COLLISIONBOX";
		case FOL_CAMERASPHERE: return out << "FOL_CAMERASPHERE";
		case FOL_DOORDETECTION: return out << "FOL_DOORDETECTION";
		case FOL_CAMERAPICK: return out << "FOL_CAMERAPICK";
		case FOL_ITEMPICK: return out << "FOL_ITEMPICK";
		case FOL_LINEOFSIGHT: return out << "FOL_LINEOFSIGHT";
		case FOL_PATHPICK: return out << "FOL_PATHPICK";
		case FOL_CUSTOMPICK1: return out << "FOL_CUSTOMPICK1";
		case FOL_CUSTOMPICK2: return out << "FOL_CUSTOMPICK2";
		case FOL_SPELLEXPLOSION: return out << "FOL_SPELLEXPLOSION";
		case FOL_DROPPINGPICK: return out << "FOL_DROPPINGPICK";
		case FOL_NULL: return out << "FOL_NULL";
		default: return out << "Invalid Value! - " << (byte)(val);
	}
}

//--InterpBlendFlags--//

void NifStream( InterpBlendFlags & val, istream& in, const NifInfo & info ) {
	byte temp;
	NifStream( temp, in, info );
	val = InterpBlendFlags(temp);
}

void NifStream( InterpBlendFlags const & val, ostream& out, const NifInfo & info ) {
	NifStream( (byte)(val), out, info );
}

ostream & operator<<( ostream & out, InterpBlendFlags const & val ) {
	switch ( val ) {
		case MANAGER_CONTROLLED: return out << "MANAGER_CONTROLLED";
		default: return out << "Invalid Value! - " << (byte)(val);
	}
}

//--EndianType--//

void NifStream( EndianType & val, istream& in, const NifInfo & info ) {
	byte temp;
	NifStream( temp, in, info );
	val = EndianType(temp);
}

void NifStream( EndianType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (byte)(val), out, info );
}

ostream & operator<<( ostream & out, EndianType const & val ) {
	switch ( val ) {
		case ENDIAN_BIG: return out << "ENDIAN_BIG";
		case ENDIAN_LITTLE: return out << "ENDIAN_LITTLE";
		default: return out << "Invalid Value! - " << (byte)(val);
	}
}

//--VelocityType--//

void NifStream( VelocityType & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = VelocityType(temp);
}

void NifStream( VelocityType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, VelocityType const & val ) {
	switch ( val ) {
		case VELOCITY_USE_NORMALS: return out << "VELOCITY_USE_NORMALS";
		case VELOCITY_USE_RANDOM: return out << "VELOCITY_USE_RANDOM";
		case VELOCITY_USE_DIRECTION: return out << "VELOCITY_USE_DIRECTION";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--AnimationType--//

void NifStream( AnimationType & val, istream& in, const NifInfo & info ) {
	unsigned short temp;
	NifStream( temp, in, info );
	val = AnimationType(temp);
}

void NifStream( AnimationType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned short)(val), out, info );
}

ostream & operator<<( ostream & out, AnimationType const & val ) {
	switch ( val ) {
		case SIT: return out << "Sit";
		case SLEEP: return out << "Sleep";
		case LEAN: return out << "Lean";
		default: return out << "Invalid Value! - " << (unsigned short)(val);
	}
}

//--AnimNoteType--//

void NifStream( AnimNoteType & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = AnimNoteType(temp);
}

void NifStream( AnimNoteType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, AnimNoteType const & val ) {
	switch ( val ) {
		case ANT_INVALID: return out << "ANT_INVALID";
		case ANT_GRABIK: return out << "ANT_GRABIK";
		case ANT_LOOKIK: return out << "ANT_LOOKIK";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--ImageType--//

void NifStream( ImageType & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = ImageType(temp);
}

void NifStream( ImageType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, ImageType const & val ) {
	switch ( val ) {
		case RGB: return out << "RGB";
		case RGBA: return out << "RGBA";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--NxD6JointMotion--//

void NifStream( NxD6JointMotion & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = NxD6JointMotion(temp);
}

void NifStream( NxD6JointMotion const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, NxD6JointMotion const & val ) {
	switch ( val ) {
		case NX_D6JOINT_MOTION_LOCKED: return out << "NX_D6JOINT_MOTION_LOCKED";
		case NX_D6JOINT_MOTION_LIMITED: return out << "NX_D6JOINT_MOTION_LIMITED";
		case NX_D6JOINT_MOTION_FREE: return out << "NX_D6JOINT_MOTION_FREE";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--StencilCompareMode--//

void NifStream( StencilCompareMode & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = StencilCompareMode(temp);
}

void NifStream( StencilCompareMode const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, StencilCompareMode const & val ) {
	switch ( val ) {
		case TEST_NEVER: return out << "TEST_NEVER";
		case TEST_LESS: return out << "TEST_LESS";
		case TEST_EQUAL: return out << "TEST_EQUAL";
		case TEST_LESS_EQUAL: return out << "TEST_LESS_EQUAL";
		case TEST_GREATER: return out << "TEST_GREATER";
		case TEST_NOT_EQUAL: return out << "TEST_NOT_EQUAL";
		case TEST_GREATER_EQUAL: return out << "TEST_GREATER_EQUAL";
		case TEST_ALWAYS: return out << "TEST_ALWAYS";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--EffectShaderControlledVariable--//

void NifStream( EffectShaderControlledVariable & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = EffectShaderControlledVariable(temp);
}

void NifStream( EffectShaderControlledVariable const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, EffectShaderControlledVariable const & val ) {
	switch ( val ) {
		case ESCV_EMISSIVEMULTIPLE: return out << "ESCV_EmissiveMultiple";
		case ESCV_FALLOFF_START_ANGLE: return out << "ESCV_Falloff Start Angle";
		case ESCV_FALLOFF_STOP_ANGLE: return out << "ESCV_Falloff Stop Angle";
		case ESCV_FALLOFF_START_OPACITY: return out << "ESCV_Falloff Start Opacity";
		case ESCV_FALLOFF_STOP_OPACITY: return out << "ESCV_Falloff Stop Opacity";
		case ESCV_ALPHA_TRANSPARENCY: return out << "ESCV_Alpha Transparency";
		case ESCV_U_OFFSET: return out << "ESCV_U Offset";
		case ESCV_U_SCALE: return out << "ESCV_U Scale";
		case ESCV_V_OFFSET: return out << "ESCV_V Offset";
		case ESCV_V_SCALE: return out << "ESCV_V Scale";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--TexFilterMode--//

void NifStream( TexFilterMode & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = TexFilterMode(temp);
}

void NifStream( TexFilterMode const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, TexFilterMode const & val ) {
	switch ( val ) {
		case FILTER_NEAREST: return out << "FILTER_NEAREST";
		case FILTER_BILERP: return out << "FILTER_BILERP";
		case FILTER_TRILERP: return out << "FILTER_TRILERP";
		case FILTER_NEAREST_MIPNEAREST: return out << "FILTER_NEAREST_MIPNEAREST";
		case FILTER_NEAREST_MIPLERP: return out << "FILTER_NEAREST_MIPLERP";
		case FILTER_BILERP_MIPNEAREST: return out << "FILTER_BILERP_MIPNEAREST";
		case FILTER_ANISOTROPIC: return out << "FILTER_ANISOTROPIC";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--SymmetryType--//

void NifStream( SymmetryType & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = SymmetryType(temp);
}

void NifStream( SymmetryType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, SymmetryType const & val ) {
	switch ( val ) {
		case SPHERICAL_SYMMETRY: return out << "SPHERICAL_SYMMETRY";
		case CYLINDRICAL_SYMMETRY: return out << "CYLINDRICAL_SYMMETRY";
		case PLANAR_SYMMETRY: return out << "PLANAR_SYMMETRY";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--LightMode--//

void NifStream( LightMode & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = LightMode(temp);
}

void NifStream( LightMode const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, LightMode const & val ) {
	switch ( val ) {
		case LIGHT_MODE_EMISSIVE: return out << "LIGHT_MODE_EMISSIVE";
		case LIGHT_MODE_EMI_AMB_DIF: return out << "LIGHT_MODE_EMI_AMB_DIF";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--MipMapFormat--//

void NifStream( MipMapFormat & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = MipMapFormat(temp);
}

void NifStream( MipMapFormat const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, MipMapFormat const & val ) {
	switch ( val ) {
		case MIP_FMT_NO: return out << "MIP_FMT_NO";
		case MIP_FMT_YES: return out << "MIP_FMT_YES";
		case MIP_FMT_DEFAULT: return out << "MIP_FMT_DEFAULT";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--ColliderType--//

void NifStream( ColliderType & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = ColliderType(temp);
}

void NifStream( ColliderType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, ColliderType const & val ) {
	switch ( val ) {
		case COLLIDER_PLANAR: return out << "COLLIDER_PLANAR";
		case COLLIDER_SPHERICAL: return out << "COLLIDER_SPHERICAL";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--StencilAction--//

void NifStream( StencilAction & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = StencilAction(temp);
}

void NifStream( StencilAction const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, StencilAction const & val ) {
	switch ( val ) {
		case ACTION_KEEP: return out << "ACTION_KEEP";
		case ACTION_ZERO: return out << "ACTION_ZERO";
		case ACTION_REPLACE: return out << "ACTION_REPLACE";
		case ACTION_INCREMENT: return out << "ACTION_INCREMENT";
		case ACTION_DECREMENT: return out << "ACTION_DECREMENT";
		case ACTION_INVERT: return out << "ACTION_INVERT";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--SyncPoint--//

void NifStream( SyncPoint & val, istream& in, const NifInfo & info ) {
	unsigned short temp;
	NifStream( temp, in, info );
	val = SyncPoint(temp);
}

void NifStream( SyncPoint const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned short)(val), out, info );
}

ostream & operator<<( ostream & out, SyncPoint const & val ) {
	switch ( val ) {
		case SYNC_ANY: return out << "SYNC_ANY";
		case SYNC_UPDATE: return out << "SYNC_UPDATE";
		case SYNC_POST_UPDATE: return out << "SYNC_POST_UPDATE";
		case SYNC_VISIBLE: return out << "SYNC_VISIBLE";
		case SYNC_RENDER: return out << "SYNC_RENDER";
		case SYNC_PHYSICS_SIMULATE: return out << "SYNC_PHYSICS_SIMULATE";
		case SYNC_PHYSICS_COMPLETED: return out << "SYNC_PHYSICS_COMPLETED";
		case SYNC_REFLECTIONS: return out << "SYNC_REFLECTIONS";
		default: return out << "Invalid Value! - " << (unsigned short)(val);
	}
}

//--TexType--//

void NifStream( TexType & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = TexType(temp);
}

void NifStream( TexType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, TexType const & val ) {
	switch ( val ) {
		case BASE_MAP: return out << "BASE_MAP";
		case DARK_MAP: return out << "DARK_MAP";
		case DETAIL_MAP: return out << "DETAIL_MAP";
		case GLOSS_MAP: return out << "GLOSS_MAP";
		case GLOW_MAP: return out << "GLOW_MAP";
		case BUMP_MAP: return out << "BUMP_MAP";
		case NORMAL_MAP: return out << "NORMAL_MAP";
		case PARALLAX_MAP: return out << "PARALLAX_MAP";
		case DECAL_0_MAP: return out << "DECAL_0_MAP";
		case DECAL_1_MAP: return out << "DECAL_1_MAP";
		case DECAL_2_MAP: return out << "DECAL_2_MAP";
		case DECAL_3_MAP: return out << "DECAL_3_MAP";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--NxCombineMode--//

void NifStream( NxCombineMode & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = NxCombineMode(temp);
}

void NifStream( NxCombineMode const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, NxCombineMode const & val ) {
	switch ( val ) {
		case NX_CM_AVERAGE: return out << "NX_CM_AVERAGE";
		case NX_CM_MIN: return out << "NX_CM_MIN";
		case NX_CM_MULTIPLY: return out << "NX_CM_MULTIPLY";
		case NX_CM_MAX: return out << "NX_CM_MAX";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--CloningBehavior--//

void NifStream( CloningBehavior & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = CloningBehavior(temp);
}

void NifStream( CloningBehavior const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, CloningBehavior const & val ) {
	switch ( val ) {
		case CLONING_SHARE: return out << "CLONING_SHARE";
		case CLONING_COPY: return out << "CLONING_COPY";
		case CLONING_BLANK_COPY: return out << "CLONING_BLANK_COPY";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--BSCPCullingType--//

void NifStream( BSCPCullingType & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = BSCPCullingType(temp);
}

void NifStream( BSCPCullingType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, BSCPCullingType const & val ) {
	switch ( val ) {
		case BSCP_CULL_NORMAL: return out << "BSCP_CULL_NORMAL";
		case BSCP_CULL_ALLPASS: return out << "BSCP_CULL_ALLPASS";
		case BSCP_CULL_ALLFAIL: return out << "BSCP_CULL_ALLFAIL";
		case BSCP_CULL_IGNOREMULTIBOUNDS: return out << "BSCP_CULL_IGNOREMULTIBOUNDS";
		case BSCP_CULL_FORCEMULTIBOUNDSNOUPDATE: return out << "BSCP_CULL_FORCEMULTIBOUNDSNOUPDATE";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--hkResponseType--//

void NifStream( hkResponseType & val, istream& in, const NifInfo & info ) {
	byte temp;
	NifStream( temp, in, info );
	val = hkResponseType(temp);
}

void NifStream( hkResponseType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (byte)(val), out, info );
}

ostream & operator<<( ostream & out, hkResponseType const & val ) {
	switch ( val ) {
		case RESPONSE_INVALID: return out << "RESPONSE_INVALID";
		case RESPONSE_SIMPLE_CONTACT: return out << "RESPONSE_SIMPLE_CONTACT";
		case RESPONSE_REPORTING: return out << "RESPONSE_REPORTING";
		case RESPONSE_NONE: return out << "RESPONSE_NONE";
		default: return out << "Invalid Value! - " << (byte)(val);
	}
}

//--hkSolverDeactivation--//

void NifStream( hkSolverDeactivation & val, istream& in, const NifInfo & info ) {
	byte temp;
	NifStream( temp, in, info );
	val = hkSolverDeactivation(temp);
}

void NifStream( hkSolverDeactivation const & val, ostream& out, const NifInfo & info ) {
	NifStream( (byte)(val), out, info );
}

ostream & operator<<( ostream & out, hkSolverDeactivation const & val ) {
	switch ( val ) {
		case SOLVER_DEACTIVATION_INVALID: return out << "SOLVER_DEACTIVATION_INVALID";
		case SOLVER_DEACTIVATION_OFF: return out << "SOLVER_DEACTIVATION_OFF";
		case SOLVER_DEACTIVATION_LOW: return out << "SOLVER_DEACTIVATION_LOW";
		case SOLVER_DEACTIVATION_MEDIUM: return out << "SOLVER_DEACTIVATION_MEDIUM";
		case SOLVER_DEACTIVATION_HIGH: return out << "SOLVER_DEACTIVATION_HIGH";
		case SOLVER_DEACTIVATION_MAX: return out << "SOLVER_DEACTIVATION_MAX";
		default: return out << "Invalid Value! - " << (byte)(val);
	}
}

//--RendererID--//

void NifStream( RendererID & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = RendererID(temp);
}

void NifStream( RendererID const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, RendererID const & val ) {
	switch ( val ) {
		case RENDERER_XBOX360: return out << "RENDERER_XBOX360";
		case RENDERER_PS3: return out << "RENDERER_PS3";
		case RENDERER_DX9: return out << "RENDERER_DX9";
		case RENDERER_D3D10: return out << "RENDERER_D3D10";
		case RENDERER_WII: return out << "RENDERER_WII";
		case RENDERER_GENERIC: return out << "RENDERER_GENERIC";
		case RENDERER_D3D11: return out << "RENDERER_D3D11";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--TransformMember--//

void NifStream( TransformMember & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = TransformMember(temp);
}

void NifStream( TransformMember const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, TransformMember const & val ) {
	switch ( val ) {
		case TT_TRANSLATE_U: return out << "TT_TRANSLATE_U";
		case TT_TRANSLATE_V: return out << "TT_TRANSLATE_V";
		case TT_ROTATE: return out << "TT_ROTATE";
		case TT_SCALE_U: return out << "TT_SCALE_U";
		case TT_SCALE_V: return out << "TT_SCALE_V";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--NxD6JointDriveType--//

void NifStream( NxD6JointDriveType & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = NxD6JointDriveType(temp);
}

void NifStream( NxD6JointDriveType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, NxD6JointDriveType const & val ) {
	switch ( val ) {
		case NX_D6JOINT_DRIVE_POSITION: return out << "NX_D6JOINT_DRIVE_POSITION";
		case NX_D6JOINT_DRIVE_VELOCITY: return out << "NX_D6JOINT_DRIVE_VELOCITY";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--LightingShaderControlledVariable--//

void NifStream( LightingShaderControlledVariable & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = LightingShaderControlledVariable(temp);
}

void NifStream( LightingShaderControlledVariable const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, LightingShaderControlledVariable const & val ) {
	switch ( val ) {
		case LSCV_REFRACTION_STRENGTH: return out << "LSCV_Refraction Strength";
		case LSCV_ENVIRONMENT_MAP_SCALE: return out << "LSCV_Environment Map Scale";
		case LSCV_GLOSSINESS: return out << "LSCV_Glossiness";
		case LSCV_SPECULAR_STRENGTH: return out << "LSCV_Specular Strength";
		case LSCV_EMISSIVE_MULTIPLE: return out << "LSCV_Emissive Multiple";
		case LSCV_ALPHA: return out << "LSCV_Alpha";
		case LSCV_U_OFFSET: return out << "LSCV_U Offset";
		case LSCV_U_SCALE: return out << "LSCV_U Scale";
		case LSCV_V_OFFSET: return out << "LSCV_V Offset";
		case LSCV_V_SCALE: return out << "LSCV_V Scale";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--MoppDataBuildType--//

void NifStream( MoppDataBuildType & val, istream& in, const NifInfo & info ) {
	byte temp;
	NifStream( temp, in, info );
	val = MoppDataBuildType(temp);
}

void NifStream( MoppDataBuildType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (byte)(val), out, info );
}

ostream & operator<<( ostream & out, MoppDataBuildType const & val ) {
	switch ( val ) {
		case BUILT_WITH_CHUNK_SUBDIVISION: return out << "BUILT_WITH_CHUNK_SUBDIVISION";
		case BUILT_WITHOUT_CHUNK_SUBDIVISION: return out << "BUILT_WITHOUT_CHUNK_SUBDIVISION";
		case BUILD_NOT_SET: return out << "BUILD_NOT_SET";
		default: return out << "Invalid Value! - " << (byte)(val);
	}
}

//--LightingShaderControlledColor--//

void NifStream( LightingShaderControlledColor & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = LightingShaderControlledColor(temp);
}

void NifStream( LightingShaderControlledColor const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, LightingShaderControlledColor const & val ) {
	switch ( val ) {
		case LSCC_SPECULAR_COLOR: return out << "LSCC_Specular Color";
		case LSCC_EMISSIVE_COLOR: return out << "LSCC_Emissive Color";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--OblivionLayer--//

void NifStream( OblivionLayer & val, istream& in, const NifInfo & info ) {
	byte temp;
	NifStream( temp, in, info );
	val = OblivionLayer(temp);
}

void NifStream( OblivionLayer const & val, ostream& out, const NifInfo & info ) {
	NifStream( (byte)(val), out, info );
}

ostream & operator<<( ostream & out, OblivionLayer const & val ) {
	switch ( val ) {
		case OL_UNIDENTIFIED: return out << "OL_UNIDENTIFIED";
		case OL_STATIC: return out << "OL_STATIC";
		case OL_ANIM_STATIC: return out << "OL_ANIM_STATIC";
		case OL_TRANSPARENT: return out << "OL_TRANSPARENT";
		case OL_CLUTTER: return out << "OL_CLUTTER";
		case OL_WEAPON: return out << "OL_WEAPON";
		case OL_PROJECTILE: return out << "OL_PROJECTILE";
		case OL_SPELL: return out << "OL_SPELL";
		case OL_BIPED: return out << "OL_BIPED";
		case OL_TREES: return out << "OL_TREES";
		case OL_PROPS: return out << "OL_PROPS";
		case OL_WATER: return out << "OL_WATER";
		case OL_TRIGGER: return out << "OL_TRIGGER";
		case OL_TERRAIN: return out << "OL_TERRAIN";
		case OL_TRAP: return out << "OL_TRAP";
		case OL_NONCOLLIDABLE: return out << "OL_NONCOLLIDABLE";
		case OL_CLOUD_TRAP: return out << "OL_CLOUD_TRAP";
		case OL_GROUND: return out << "OL_GROUND";
		case OL_PORTAL: return out << "OL_PORTAL";
		case OL_STAIRS: return out << "OL_STAIRS";
		case OL_CHAR_CONTROLLER: return out << "OL_CHAR_CONTROLLER";
		case OL_AVOID_BOX: return out << "OL_AVOID_BOX";
		case OL_UNKNOWN1: return out << "OL_UNKNOWN1";
		case OL_UNKNOWN2: return out << "OL_UNKNOWN2";
		case OL_CAMERA_PICK: return out << "OL_CAMERA_PICK";
		case OL_ITEM_PICK: return out << "OL_ITEM_PICK";
		case OL_LINE_OF_SIGHT: return out << "OL_LINE_OF_SIGHT";
		case OL_PATH_PICK: return out << "OL_PATH_PICK";
		case OL_CUSTOM_PICK_1: return out << "OL_CUSTOM_PICK_1";
		case OL_CUSTOM_PICK_2: return out << "OL_CUSTOM_PICK_2";
		case OL_SPELL_EXPLOSION: return out << "OL_SPELL_EXPLOSION";
		case OL_DROPPING_PICK: return out << "OL_DROPPING_PICK";
		case OL_OTHER: return out << "OL_OTHER";
		case OL_HEAD: return out << "OL_HEAD";
		case OL_BODY: return out << "OL_BODY";
		case OL_SPINE1: return out << "OL_SPINE1";
		case OL_SPINE2: return out << "OL_SPINE2";
		case OL_L_UPPER_ARM: return out << "OL_L_UPPER_ARM";
		case OL_L_FOREARM: return out << "OL_L_FOREARM";
		case OL_L_HAND: return out << "OL_L_HAND";
		case OL_L_THIGH: return out << "OL_L_THIGH";
		case OL_L_CALF: return out << "OL_L_CALF";
		case OL_L_FOOT: return out << "OL_L_FOOT";
		case OL_R_UPPER_ARM: return out << "OL_R_UPPER_ARM";
		case OL_R_FOREARM: return out << "OL_R_FOREARM";
		case OL_R_HAND: return out << "OL_R_HAND";
		case OL_R_THIGH: return out << "OL_R_THIGH";
		case OL_R_CALF: return out << "OL_R_CALF";
		case OL_R_FOOT: return out << "OL_R_FOOT";
		case OL_TAIL: return out << "OL_TAIL";
		case OL_SIDE_WEAPON: return out << "OL_SIDE_WEAPON";
		case OL_SHIELD: return out << "OL_SHIELD";
		case OL_QUIVER: return out << "OL_QUIVER";
		case OL_BACK_WEAPON: return out << "OL_BACK_WEAPON";
		case OL_BACK_WEAPON2: return out << "OL_BACK_WEAPON2";
		case OL_PONYTAIL: return out << "OL_PONYTAIL";
		case OL_WING: return out << "OL_WING";
		case OL_NULL: return out << "OL_NULL";
		default: return out << "Invalid Value! - " << (byte)(val);
	}
}

//--TextureType--//

void NifStream( TextureType & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = TextureType(temp);
}

void NifStream( TextureType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, TextureType const & val ) {
	switch ( val ) {
		case TEX_PROJECTED_LIGHT: return out << "TEX_PROJECTED_LIGHT";
		case TEX_PROJECTED_SHADOW: return out << "TEX_PROJECTED_SHADOW";
		case TEX_ENVIRONMENT_MAP: return out << "TEX_ENVIRONMENT_MAP";
		case TEX_FOG_MAP: return out << "TEX_FOG_MAP";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--NxJointProjectionMode--//

void NifStream( NxJointProjectionMode & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = NxJointProjectionMode(temp);
}

void NifStream( NxJointProjectionMode const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, NxJointProjectionMode const & val ) {
	switch ( val ) {
		case NX_JPM_NONE: return out << "NX_JPM_NONE";
		case NX_JPM_POINT_MINDIST: return out << "NX_JPM_POINT_MINDIST";
		case NX_JPM_LINEAR_MINDIST: return out << "NX_JPM_LINEAR_MINDIST";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--BoundVolumeType--//

void NifStream( BoundVolumeType & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = BoundVolumeType(temp);
}

void NifStream( BoundVolumeType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, BoundVolumeType const & val ) {
	switch ( val ) {
		case BASE_BV: return out << "BASE_BV";
		case SPHERE_BV: return out << "SPHERE_BV";
		case BOX_BV: return out << "BOX_BV";
		case CAPSULE_BV: return out << "CAPSULE_BV";
		case UNION_BV: return out << "UNION_BV";
		case HALFSPACE_BV: return out << "HALFSPACE_BV";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--NxShapeType--//

void NifStream( NxShapeType & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = NxShapeType(temp);
}

void NifStream( NxShapeType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, NxShapeType const & val ) {
	switch ( val ) {
		case NX_SHAPE_PLANE: return out << "NX_SHAPE_PLANE";
		case NX_SHAPE_SPHERE: return out << "NX_SHAPE_SPHERE";
		case NX_SHAPE_BOX: return out << "NX_SHAPE_BOX";
		case NX_SHAPE_CAPSULE: return out << "NX_SHAPE_CAPSULE";
		case NX_SHAPE_WHEEL: return out << "NX_SHAPE_WHEEL";
		case NX_SHAPE_CONVEX: return out << "NX_SHAPE_CONVEX";
		case NX_SHAPE_MESH: return out << "NX_SHAPE_MESH";
		case NX_SHAPE_HEIGHTFIELD: return out << "NX_SHAPE_HEIGHTFIELD";
		case NX_SHAPE_RAW_MESH: return out << "NX_SHAPE_RAW_MESH";
		case NX_SHAPE_COMPOUND: return out << "NX_SHAPE_COMPOUND";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--MeshPrimitiveType--//

void NifStream( MeshPrimitiveType & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = MeshPrimitiveType(temp);
}

void NifStream( MeshPrimitiveType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, MeshPrimitiveType const & val ) {
	switch ( val ) {
		case MESH_PRIMITIVE_TRIANGLES: return out << "MESH_PRIMITIVE_TRIANGLES";
		case MESH_PRIMITIVE_TRISTRIPS: return out << "MESH_PRIMITIVE_TRISTRIPS";
		case MESH_PRIMITIVE_LINES: return out << "MESH_PRIMITIVE_LINES";
		case MESH_PRIMITIVE_LINESTRIPS: return out << "MESH_PRIMITIVE_LINESTRIPS";
		case MESH_PRIMITIVE_QUADS: return out << "MESH_PRIMITIVE_QUADS";
		case MESH_PRIMITIVE_POINTS: return out << "MESH_PRIMITIVE_POINTS";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--AlphaFormat--//

void NifStream( AlphaFormat & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = AlphaFormat(temp);
}

void NifStream( AlphaFormat const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, AlphaFormat const & val ) {
	switch ( val ) {
		case ALPHA_NONE: return out << "ALPHA_NONE";
		case ALPHA_BINARY: return out << "ALPHA_BINARY";
		case ALPHA_SMOOTH: return out << "ALPHA_SMOOTH";
		case ALPHA_DEFAULT: return out << "ALPHA_DEFAULT";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--hkQualityType--//

void NifStream( hkQualityType & val, istream& in, const NifInfo & info ) {
	byte temp;
	NifStream( temp, in, info );
	val = hkQualityType(temp);
}

void NifStream( hkQualityType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (byte)(val), out, info );
}

ostream & operator<<( ostream & out, hkQualityType const & val ) {
	switch ( val ) {
		case MO_QUAL_INVALID: return out << "MO_QUAL_INVALID";
		case MO_QUAL_FIXED: return out << "MO_QUAL_FIXED";
		case MO_QUAL_KEYFRAMED: return out << "MO_QUAL_KEYFRAMED";
		case MO_QUAL_DEBRIS: return out << "MO_QUAL_DEBRIS";
		case MO_QUAL_MOVING: return out << "MO_QUAL_MOVING";
		case MO_QUAL_CRITICAL: return out << "MO_QUAL_CRITICAL";
		case MO_QUAL_BULLET: return out << "MO_QUAL_BULLET";
		case MO_QUAL_USER: return out << "MO_QUAL_USER";
		case MO_QUAL_CHARACTER: return out << "MO_QUAL_CHARACTER";
		case MO_QUAL_KEYFRAMED_REPORT: return out << "MO_QUAL_KEYFRAMED_REPORT";
		default: return out << "Invalid Value! - " << (byte)(val);
	}
}

//--PSLoopBehavior--//

void NifStream( PSLoopBehavior & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = PSLoopBehavior(temp);
}

void NifStream( PSLoopBehavior const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, PSLoopBehavior const & val ) {
	switch ( val ) {
		case PS_LOOP_CLAMP_BIRTH: return out << "PS_LOOP_CLAMP_BIRTH";
		case PS_LOOP_CLAMP_DEATH: return out << "PS_LOOP_CLAMP_DEATH";
		case PS_LOOP_AGESCALE: return out << "PS_LOOP_AGESCALE";
		case PS_LOOP_LOOP: return out << "PS_LOOP_LOOP";
		case PS_LOOP_REFLECT: return out << "PS_LOOP_REFLECT";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--KeyType--//

void NifStream( KeyType & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = KeyType(temp);
}

void NifStream( KeyType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, KeyType const & val ) {
	switch ( val ) {
		case LINEAR_KEY: return out << "LINEAR_KEY";
		case QUADRATIC_KEY: return out << "QUADRATIC_KEY";
		case TBC_KEY: return out << "TBC_KEY";
		case XYZ_ROTATION_KEY: return out << "XYZ_ROTATION_KEY";
		case CONST_KEY: return out << "CONST_KEY";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--VertMode--//

void NifStream( VertMode & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = VertMode(temp);
}

void NifStream( VertMode const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, VertMode const & val ) {
	switch ( val ) {
		case VERT_MODE_SRC_IGNORE: return out << "VERT_MODE_SRC_IGNORE";
		case VERT_MODE_SRC_EMISSIVE: return out << "VERT_MODE_SRC_EMISSIVE";
		case VERT_MODE_SRC_AMB_DIF: return out << "VERT_MODE_SRC_AMB_DIF";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--SortingMode--//

void NifStream( SortingMode & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = SortingMode(temp);
}

void NifStream( SortingMode const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, SortingMode const & val ) {
	switch ( val ) {
		case SORTING_INHERIT: return out << "SORTING_INHERIT";
		case SORTING_OFF: return out << "SORTING_OFF";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--OblivionHavokMaterial--//

void NifStream( OblivionHavokMaterial & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = OblivionHavokMaterial(temp);
}

void NifStream( OblivionHavokMaterial const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, OblivionHavokMaterial const & val ) {
	switch ( val ) {
		case OB_HAV_MAT_STONE: return out << "OB_HAV_MAT_STONE";
		case OB_HAV_MAT_CLOTH: return out << "OB_HAV_MAT_CLOTH";
		case OB_HAV_MAT_DIRT: return out << "OB_HAV_MAT_DIRT";
		case OB_HAV_MAT_GLASS: return out << "OB_HAV_MAT_GLASS";
		case OB_HAV_MAT_GRASS: return out << "OB_HAV_MAT_GRASS";
		case OB_HAV_MAT_METAL: return out << "OB_HAV_MAT_METAL";
		case OB_HAV_MAT_ORGANIC: return out << "OB_HAV_MAT_ORGANIC";
		case OB_HAV_MAT_SKIN: return out << "OB_HAV_MAT_SKIN";
		case OB_HAV_MAT_WATER: return out << "OB_HAV_MAT_WATER";
		case OB_HAV_MAT_WOOD: return out << "OB_HAV_MAT_WOOD";
		case OB_HAV_MAT_HEAVY_STONE: return out << "OB_HAV_MAT_HEAVY_STONE";
		case OB_HAV_MAT_HEAVY_METAL: return out << "OB_HAV_MAT_HEAVY_METAL";
		case OB_HAV_MAT_HEAVY_WOOD: return out << "OB_HAV_MAT_HEAVY_WOOD";
		case OB_HAV_MAT_CHAIN: return out << "OB_HAV_MAT_CHAIN";
		case OB_HAV_MAT_SNOW: return out << "OB_HAV_MAT_SNOW";
		case OB_HAV_MAT_STONE_STAIRS: return out << "OB_HAV_MAT_STONE_STAIRS";
		case OB_HAV_MAT_CLOTH_STAIRS: return out << "OB_HAV_MAT_CLOTH_STAIRS";
		case OB_HAV_MAT_DIRT_STAIRS: return out << "OB_HAV_MAT_DIRT_STAIRS";
		case OB_HAV_MAT_GLASS_STAIRS: return out << "OB_HAV_MAT_GLASS_STAIRS";
		case OB_HAV_MAT_GRASS_STAIRS: return out << "OB_HAV_MAT_GRASS_STAIRS";
		case OB_HAV_MAT_METAL_STAIRS: return out << "OB_HAV_MAT_METAL_STAIRS";
		case OB_HAV_MAT_ORGANIC_STAIRS: return out << "OB_HAV_MAT_ORGANIC_STAIRS";
		case OB_HAV_MAT_SKIN_STAIRS: return out << "OB_HAV_MAT_SKIN_STAIRS";
		case OB_HAV_MAT_WATER_STAIRS: return out << "OB_HAV_MAT_WATER_STAIRS";
		case OB_HAV_MAT_WOOD_STAIRS: return out << "OB_HAV_MAT_WOOD_STAIRS";
		case OB_HAV_MAT_HEAVY_STONE_STAIRS: return out << "OB_HAV_MAT_HEAVY_STONE_STAIRS";
		case OB_HAV_MAT_HEAVY_METAL_STAIRS: return out << "OB_HAV_MAT_HEAVY_METAL_STAIRS";
		case OB_HAV_MAT_HEAVY_WOOD_STAIRS: return out << "OB_HAV_MAT_HEAVY_WOOD_STAIRS";
		case OB_HAV_MAT_CHAIN_STAIRS: return out << "OB_HAV_MAT_CHAIN_STAIRS";
		case OB_HAV_MAT_SNOW_STAIRS: return out << "OB_HAV_MAT_SNOW_STAIRS";
		case OB_HAV_MAT_ELEVATOR: return out << "OB_HAV_MAT_ELEVATOR";
		case OB_HAV_MAT_RUBBER: return out << "OB_HAV_MAT_RUBBER";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--MotorType--//

void NifStream( MotorType & val, istream& in, const NifInfo & info ) {
	byte temp;
	NifStream( temp, in, info );
	val = MotorType(temp);
}

void NifStream( MotorType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (byte)(val), out, info );
}

ostream & operator<<( ostream & out, MotorType const & val ) {
	switch ( val ) {
		case MOTOR_NONE: return out << "MOTOR_NONE";
		case MOTOR_POSITION: return out << "MOTOR_POSITION";
		case MOTOR_VELOCITY: return out << "MOTOR_VELOCITY";
		case MOTOR_SPRING: return out << "MOTOR_SPRING";
		default: return out << "Invalid Value! - " << (byte)(val);
	}
}

//--PixelComponent--//

void NifStream( PixelComponent & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = PixelComponent(temp);
}

void NifStream( PixelComponent const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, PixelComponent const & val ) {
	switch ( val ) {
		case PX_COMP_RED: return out << "PX_COMP_RED";
		case PX_COMP_GREEN: return out << "PX_COMP_GREEN";
		case PX_COMP_BLUE: return out << "PX_COMP_BLUE";
		case PX_COMP_ALPHA: return out << "PX_COMP_ALPHA";
		case PX_COMP_COMPRESSED: return out << "PX_COMP_COMPRESSED";
		case PX_COMP_OFFSET_U: return out << "PX_COMP_OFFSET_U";
		case PX_COMP_OFFSET_V: return out << "PX_COMP_OFFSET_V";
		case PX_COMP_OFFSET_W: return out << "PX_COMP_OFFSET_W";
		case PX_COMP_OFFSET_Q: return out << "PX_COMP_OFFSET_Q";
		case PX_COMP_LUMA: return out << "PX_COMP_LUMA";
		case PX_COMP_HEIGHT: return out << "PX_COMP_HEIGHT";
		case PX_COMP_VECTOR_X: return out << "PX_COMP_VECTOR_X";
		case PX_COMP_VECTOR_Y: return out << "PX_COMP_VECTOR_Y";
		case PX_COMP_VECTOR_Z: return out << "PX_COMP_VECTOR_Z";
		case PX_COMP_PADDING: return out << "PX_COMP_PADDING";
		case PX_COMP_INTENSITY: return out << "PX_COMP_INTENSITY";
		case PX_COMP_INDEX: return out << "PX_COMP_INDEX";
		case PX_COMP_DEPTH: return out << "PX_COMP_DEPTH";
		case PX_COMP_STENCIL: return out << "PX_COMP_STENCIL";
		case PX_COMP_EMPTY: return out << "PX_COMP_EMPTY";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--ApplyMode--//

void NifStream( ApplyMode & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = ApplyMode(temp);
}

void NifStream( ApplyMode const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, ApplyMode const & val ) {
	switch ( val ) {
		case APPLY_REPLACE: return out << "APPLY_REPLACE";
		case APPLY_DECAL: return out << "APPLY_DECAL";
		case APPLY_MODULATE: return out << "APPLY_MODULATE";
		case APPLY_HILIGHT: return out << "APPLY_HILIGHT";
		case APPLY_HILIGHT2: return out << "APPLY_HILIGHT2";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--EmitFrom--//

void NifStream( EmitFrom & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = EmitFrom(temp);
}

void NifStream( EmitFrom const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, EmitFrom const & val ) {
	switch ( val ) {
		case EMIT_FROM_VERTICES: return out << "EMIT_FROM_VERTICES";
		case EMIT_FROM_FACE_CENTER: return out << "EMIT_FROM_FACE_CENTER";
		case EMIT_FROM_EDGE_CENTER: return out << "EMIT_FROM_EDGE_CENTER";
		case EMIT_FROM_FACE_SURFACE: return out << "EMIT_FROM_FACE_SURFACE";
		case EMIT_FROM_EDGE_SURFACE: return out << "EMIT_FROM_EDGE_SURFACE";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--BillboardMode--//

void NifStream( BillboardMode & val, istream& in, const NifInfo & info ) {
	unsigned short temp;
	NifStream( temp, in, info );
	val = BillboardMode(temp);
}

void NifStream( BillboardMode const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned short)(val), out, info );
}

ostream & operator<<( ostream & out, BillboardMode const & val ) {
	switch ( val ) {
		case ALWAYS_FACE_CAMERA: return out << "ALWAYS_FACE_CAMERA";
		case ROTATE_ABOUT_UP: return out << "ROTATE_ABOUT_UP";
		case RIGID_FACE_CAMERA: return out << "RIGID_FACE_CAMERA";
		case ALWAYS_FACE_CENTER: return out << "ALWAYS_FACE_CENTER";
		case RIGID_FACE_CENTER: return out << "RIGID_FACE_CENTER";
		case BSROTATE_ABOUT_UP: return out << "BSROTATE_ABOUT_UP";
		case ROTATE_ABOUT_UP2: return out << "ROTATE_ABOUT_UP2";
		default: return out << "Invalid Value! - " << (unsigned short)(val);
	}
}

//--ZCompareMode--//

void NifStream( ZCompareMode & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = ZCompareMode(temp);
}

void NifStream( ZCompareMode const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, ZCompareMode const & val ) {
	switch ( val ) {
		case ZCOMP_ALWAYS: return out << "ZCOMP_ALWAYS";
		case ZCOMP_LESS: return out << "ZCOMP_LESS";
		case ZCOMP_EQUAL: return out << "ZCOMP_EQUAL";
		case ZCOMP_LESS_EQUAL: return out << "ZCOMP_LESS_EQUAL";
		case ZCOMP_GREATER: return out << "ZCOMP_GREATER";
		case ZCOMP_NOT_EQUAL: return out << "ZCOMP_NOT_EQUAL";
		case ZCOMP_GREATER_EQUAL: return out << "ZCOMP_GREATER_EQUAL";
		case ZCOMP_NEVER: return out << "ZCOMP_NEVER";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--CoordGenType--//

void NifStream( CoordGenType & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = CoordGenType(temp);
}

void NifStream( CoordGenType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, CoordGenType const & val ) {
	switch ( val ) {
		case CG_WORLD_PARALLEL: return out << "CG_WORLD_PARALLEL";
		case CG_WORLD_PERSPECTIVE: return out << "CG_WORLD_PERSPECTIVE";
		case CG_SPHERE_MAP: return out << "CG_SPHERE_MAP";
		case CG_SPECULAR_CUBE_MAP: return out << "CG_SPECULAR_CUBE_MAP";
		case CG_DIFFUSE_CUBE_MAP: return out << "CG_DIFFUSE_CUBE_MAP";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--SkyrimHavokMaterial--//

void NifStream( SkyrimHavokMaterial & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = SkyrimHavokMaterial(temp);
}

void NifStream( SkyrimHavokMaterial const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, SkyrimHavokMaterial const & val ) {
	switch ( val ) {
		case SKY_HAV_MAT_BROKEN_STONE: return out << "SKY_HAV_MAT_BROKEN_STONE";
		case SKY_HAV_MAT_LIGHT_WOOD: return out << "SKY_HAV_MAT_LIGHT_WOOD";
		case SKY_HAV_MAT_SNOW: return out << "SKY_HAV_MAT_SNOW";
		case SKY_HAV_MAT_GRAVEL: return out << "SKY_HAV_MAT_GRAVEL";
		case SKY_HAV_MAT_MATERIAL_CHAIN_METAL: return out << "SKY_HAV_MAT_MATERIAL_CHAIN_METAL";
		case SKY_HAV_MAT_BOTTLE: return out << "SKY_HAV_MAT_BOTTLE";
		case SKY_HAV_MAT_WOOD: return out << "SKY_HAV_MAT_WOOD";
		case SKY_HAV_MAT_SKIN: return out << "SKY_HAV_MAT_SKIN";
		case SKY_HAV_MAT_UNKNOWN_617099282: return out << "SKY_HAV_MAT_UNKNOWN_617099282";
		case SKY_HAV_MAT_BARREL: return out << "SKY_HAV_MAT_BARREL";
		case SKY_HAV_MAT_MATERIAL_CERAMIC_MEDIUM: return out << "SKY_HAV_MAT_MATERIAL_CERAMIC_MEDIUM";
		case SKY_HAV_MAT_MATERIAL_BASKET: return out << "SKY_HAV_MAT_MATERIAL_BASKET";
		case SKY_HAV_MAT_ICE: return out << "SKY_HAV_MAT_ICE";
		case SKY_HAV_MAT_STAIRS_STONE: return out << "SKY_HAV_MAT_STAIRS_STONE";
		case SKY_HAV_MAT_WATER: return out << "SKY_HAV_MAT_WATER";
		case SKY_HAV_MAT_UNKNOWN_1028101969: return out << "SKY_HAV_MAT_UNKNOWN_1028101969";
		case SKY_HAV_MAT_MATERIAL_BLADE_1HAND: return out << "SKY_HAV_MAT_MATERIAL_BLADE_1HAND";
		case SKY_HAV_MAT_MATERIAL_BOOK: return out << "SKY_HAV_MAT_MATERIAL_BOOK";
		case SKY_HAV_MAT_MATERIAL_CARPET: return out << "SKY_HAV_MAT_MATERIAL_CARPET";
		case SKY_HAV_MAT_SOLID_METAL: return out << "SKY_HAV_MAT_SOLID_METAL";
		case SKY_HAV_MAT_MATERIAL_AXE_1HAND: return out << "SKY_HAV_MAT_MATERIAL_AXE_1HAND";
		case SKY_HAV_MAT_UNKNOWN_1440721808: return out << "SKY_HAV_MAT_UNKNOWN_1440721808";
		case SKY_HAV_MAT_STAIRS_WOOD: return out << "SKY_HAV_MAT_STAIRS_WOOD";
		case SKY_HAV_MAT_MUD: return out << "SKY_HAV_MAT_MUD";
		case SKY_HAV_MAT_MATERIAL_BOULDER_SMALL: return out << "SKY_HAV_MAT_MATERIAL_BOULDER_SMALL";
		case SKY_HAV_MAT_STAIRS_SNOW: return out << "SKY_HAV_MAT_STAIRS_SNOW";
		case SKY_HAV_MAT_HEAVY_STONE: return out << "SKY_HAV_MAT_HEAVY_STONE";
		case SKY_HAV_MAT_UNKNOWN_1574477864: return out << "SKY_HAV_MAT_UNKNOWN_1574477864";
		case SKY_HAV_MAT_UNKNOWN_1591009235: return out << "SKY_HAV_MAT_UNKNOWN_1591009235";
		case SKY_HAV_MAT_MATERIAL_BOWS_STAVES: return out << "SKY_HAV_MAT_MATERIAL_BOWS_STAVES";
		case SKY_HAV_MAT_MATERIAL_WOOD_AS_STAIRS: return out << "SKY_HAV_MAT_MATERIAL_WOOD_AS_STAIRS";
		case SKY_HAV_MAT_GRASS: return out << "SKY_HAV_MAT_GRASS";
		case SKY_HAV_MAT_MATERIAL_BOULDER_LARGE: return out << "SKY_HAV_MAT_MATERIAL_BOULDER_LARGE";
		case SKY_HAV_MAT_MATERIAL_STONE_AS_STAIRS: return out << "SKY_HAV_MAT_MATERIAL_STONE_AS_STAIRS";
		case SKY_HAV_MAT_MATERIAL_BLADE_2HAND: return out << "SKY_HAV_MAT_MATERIAL_BLADE_2HAND";
		case SKY_HAV_MAT_MATERIAL_BOTTLE_SMALL: return out << "SKY_HAV_MAT_MATERIAL_BOTTLE_SMALL";
		case SKY_HAV_MAT_SAND: return out << "SKY_HAV_MAT_SAND";
		case SKY_HAV_MAT_HEAVY_METAL: return out << "SKY_HAV_MAT_HEAVY_METAL";
		case SKY_HAV_MAT_UNKNOWN_2290050264: return out << "SKY_HAV_MAT_UNKNOWN_2290050264";
		case SKY_HAV_MAT_DRAGON: return out << "SKY_HAV_MAT_DRAGON";
		case SKY_HAV_MAT_MATERIAL_BLADE_1HAND_SMALL: return out << "SKY_HAV_MAT_MATERIAL_BLADE_1HAND_SMALL";
		case SKY_HAV_MAT_MATERIAL_SKIN_SMALL: return out << "SKY_HAV_MAT_MATERIAL_SKIN_SMALL";
		case SKY_HAV_MAT_STAIRS_BROKEN_STONE: return out << "SKY_HAV_MAT_STAIRS_BROKEN_STONE";
		case SKY_HAV_MAT_MATERIAL_SKIN_LARGE: return out << "SKY_HAV_MAT_MATERIAL_SKIN_LARGE";
		case SKY_HAV_MAT_ORGANIC: return out << "SKY_HAV_MAT_ORGANIC";
		case SKY_HAV_MAT_MATERIAL_BONE: return out << "SKY_HAV_MAT_MATERIAL_BONE";
		case SKY_HAV_MAT_HEAVY_WOOD: return out << "SKY_HAV_MAT_HEAVY_WOOD";
		case SKY_HAV_MAT_MATERIAL_CHAIN: return out << "SKY_HAV_MAT_MATERIAL_CHAIN";
		case SKY_HAV_MAT_DIRT: return out << "SKY_HAV_MAT_DIRT";
		case SKY_HAV_MAT_MATERIAL_ARMOR_LIGHT: return out << "SKY_HAV_MAT_MATERIAL_ARMOR_LIGHT";
		case SKY_HAV_MAT_MATERIAL_SHIELD_LIGHT: return out << "SKY_HAV_MAT_MATERIAL_SHIELD_LIGHT";
		case SKY_HAV_MAT_MATERIAL_COIN: return out << "SKY_HAV_MAT_MATERIAL_COIN";
		case SKY_HAV_MAT_MATERIAL_SHIELD_HEAVY: return out << "SKY_HAV_MAT_MATERIAL_SHIELD_HEAVY";
		case SKY_HAV_MAT_MATERIAL_ARMOR_HEAVY: return out << "SKY_HAV_MAT_MATERIAL_ARMOR_HEAVY";
		case SKY_HAV_MAT_MATERIAL_ARROW: return out << "SKY_HAV_MAT_MATERIAL_ARROW";
		case SKY_HAV_MAT_GLASS: return out << "SKY_HAV_MAT_GLASS";
		case SKY_HAV_MAT_STONE: return out << "SKY_HAV_MAT_STONE";
		case SKY_HAV_MAT_CLOTH: return out << "SKY_HAV_MAT_CLOTH";
		case SKY_HAV_MAT_MATERIAL_BLUNT_2HAND: return out << "SKY_HAV_MAT_MATERIAL_BLUNT_2HAND";
		case SKY_HAV_MAT_UNKNOWN_4239621792: return out << "SKY_HAV_MAT_UNKNOWN_4239621792";
		case SKY_HAV_MAT_MATERIAL_BOULDER_MEDIUM: return out << "SKY_HAV_MAT_MATERIAL_BOULDER_MEDIUM";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--NxJointType--//

void NifStream( NxJointType & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = NxJointType(temp);
}

void NifStream( NxJointType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, NxJointType const & val ) {
	switch ( val ) {
		case NX_JOINT_PRISMATIC: return out << "NX_JOINT_PRISMATIC";
		case NX_JOINT_REVOLUTE: return out << "NX_JOINT_REVOLUTE";
		case NX_JOINT_CYLINDRICAL: return out << "NX_JOINT_CYLINDRICAL";
		case NX_JOINT_SPHERICAL: return out << "NX_JOINT_SPHERICAL";
		case NX_JOINT_POINT_ON_LINE: return out << "NX_JOINT_POINT_ON_LINE";
		case NX_JOINT_POINT_IN_PLANE: return out << "NX_JOINT_POINT_IN_PLANE";
		case NX_JOINT_DISTANCE: return out << "NX_JOINT_DISTANCE";
		case NX_JOINT_PULLEY: return out << "NX_JOINT_PULLEY";
		case NX_JOINT_FIXED: return out << "NX_JOINT_FIXED";
		case NX_JOINT_D6: return out << "NX_JOINT_D6";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--hkDeactivatorType--//

void NifStream( hkDeactivatorType & val, istream& in, const NifInfo & info ) {
	byte temp;
	NifStream( temp, in, info );
	val = hkDeactivatorType(temp);
}

void NifStream( hkDeactivatorType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (byte)(val), out, info );
}

ostream & operator<<( ostream & out, hkDeactivatorType const & val ) {
	switch ( val ) {
		case DEACTIVATOR_INVALID: return out << "DEACTIVATOR_INVALID";
		case DEACTIVATOR_NEVER: return out << "DEACTIVATOR_NEVER";
		case DEACTIVATOR_SPATIAL: return out << "DEACTIVATOR_SPATIAL";
		default: return out << "Invalid Value! - " << (byte)(val);
	}
}

//--hkMotionType--//

void NifStream( hkMotionType & val, istream& in, const NifInfo & info ) {
	byte temp;
	NifStream( temp, in, info );
	val = hkMotionType(temp);
}

void NifStream( hkMotionType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (byte)(val), out, info );
}

ostream & operator<<( ostream & out, hkMotionType const & val ) {
	switch ( val ) {
		case MO_SYS_INVALID: return out << "MO_SYS_INVALID";
		case MO_SYS_DYNAMIC: return out << "MO_SYS_DYNAMIC";
		case MO_SYS_SPHERE_INERTIA: return out << "MO_SYS_SPHERE_INERTIA";
		case MO_SYS_SPHERE_STABILIZED: return out << "MO_SYS_SPHERE_STABILIZED";
		case MO_SYS_BOX_INERTIA: return out << "MO_SYS_BOX_INERTIA";
		case MO_SYS_BOX_STABILIZED: return out << "MO_SYS_BOX_STABILIZED";
		case MO_SYS_KEYFRAMED: return out << "MO_SYS_KEYFRAMED";
		case MO_SYS_FIXED: return out << "MO_SYS_FIXED";
		case MO_SYS_THIN_BOX: return out << "MO_SYS_THIN_BOX";
		case MO_SYS_CHARACTER: return out << "MO_SYS_CHARACTER";
		default: return out << "Invalid Value! - " << (byte)(val);
	}
}

//--PixelLayout--//

void NifStream( PixelLayout & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = PixelLayout(temp);
}

void NifStream( PixelLayout const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, PixelLayout const & val ) {
	switch ( val ) {
		case PX_LAY_PALETTIZED_8: return out << "PX_LAY_PALETTIZED_8";
		case PX_LAY_HIGH_COLOR_16: return out << "PX_LAY_HIGH_COLOR_16";
		case PX_LAY_TRUE_COLOR_32: return out << "PX_LAY_TRUE_COLOR_32";
		case PX_LAY_COMPRESSED: return out << "PX_LAY_COMPRESSED";
		case PX_LAY_BUMPMAP: return out << "PX_LAY_BUMPMAP";
		case PX_LAY_PALETTIZED_4: return out << "PX_LAY_PALETTIZED_4";
		case PX_LAY_DEFAULT: return out << "PX_LAY_DEFAULT";
		case PX_LAY_SINGLE_COLOR_8: return out << "PX_LAY_SINGLE_COLOR_8";
		case PX_LAY_SINGLE_COLOR_16: return out << "PX_LAY_SINGLE_COLOR_16";
		case PX_LAY_SINGLE_COLOR_32: return out << "PX_LAY_SINGLE_COLOR_32";
		case PX_LAY_DOUBLE_COLOR_32: return out << "PX_LAY_DOUBLE_COLOR_32";
		case PX_LAY_DOUBLE_COLOR_64: return out << "PX_LAY_DOUBLE_COLOR_64";
		case PX_LAY_FLOAT_COLOR_32: return out << "PX_LAY_FLOAT_COLOR_32";
		case PX_LAY_FLOAT_COLOR_64: return out << "PX_LAY_FLOAT_COLOR_64";
		case PX_LAY_FLOAT_COLOR_128: return out << "PX_LAY_FLOAT_COLOR_128";
		case PX_LAY_SINGLE_COLOR_4: return out << "PX_LAY_SINGLE_COLOR_4";
		case PX_LAY_DEPTH_24_X8: return out << "PX_LAY_DEPTH_24_X8";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--hkConstraintType--//

void NifStream( hkConstraintType & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = hkConstraintType(temp);
}

void NifStream( hkConstraintType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, hkConstraintType const & val ) {
	switch ( val ) {
		case BALLANDSOCKET: return out << "BallAndSocket";
		case HINGE: return out << "Hinge";
		case LIMITED_HINGE: return out << "Limited Hinge";
		case PRISMATIC: return out << "Prismatic";
		case RAGDOLL: return out << "Ragdoll";
		case STIFFSPRING: return out << "StiffSpring";
		case MALLEABLE: return out << "Malleable";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--LightColor--//

void NifStream( LightColor & val, istream& in, const NifInfo & info ) {
	unsigned short temp;
	NifStream( temp, in, info );
	val = LightColor(temp);
}

void NifStream( LightColor const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned short)(val), out, info );
}

ostream & operator<<( ostream & out, LightColor const & val ) {
	switch ( val ) {
		case LC_DIFFUSE: return out << "LC_DIFFUSE";
		case LC_AMBIENT: return out << "LC_AMBIENT";
		default: return out << "Invalid Value! - " << (unsigned short)(val);
	}
}

//--TexClampMode--//

void NifStream( TexClampMode & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = TexClampMode(temp);
}

void NifStream( TexClampMode const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, TexClampMode const & val ) {
	switch ( val ) {
		case CLAMP_S_CLAMP_T: return out << "CLAMP_S_CLAMP_T";
		case CLAMP_S_WRAP_T: return out << "CLAMP_S_WRAP_T";
		case WRAP_S_CLAMP_T: return out << "WRAP_S_CLAMP_T";
		case WRAP_S_WRAP_T: return out << "WRAP_S_WRAP_T";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--ComponentFormat--//

void NifStream( ComponentFormat & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = ComponentFormat(temp);
}

void NifStream( ComponentFormat const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, ComponentFormat const & val ) {
	switch ( val ) {
		case F_UNKNOWN: return out << "F_UNKNOWN";
		case F_INT8_1: return out << "F_INT8_1";
		case F_INT8_2: return out << "F_INT8_2";
		case F_INT8_3: return out << "F_INT8_3";
		case F_INT8_4: return out << "F_INT8_4";
		case F_UINT8_1: return out << "F_UINT8_1";
		case F_UINT8_2: return out << "F_UINT8_2";
		case F_UINT8_3: return out << "F_UINT8_3";
		case F_UINT8_4: return out << "F_UINT8_4";
		case F_NORMINT8_1: return out << "F_NORMINT8_1";
		case F_NORMINT8_2: return out << "F_NORMINT8_2";
		case F_NORMINT8_3: return out << "F_NORMINT8_3";
		case F_NORMINT8_4: return out << "F_NORMINT8_4";
		case F_NORMUINT8_1: return out << "F_NORMUINT8_1";
		case F_NORMUINT8_2: return out << "F_NORMUINT8_2";
		case F_NORMUINT8_3: return out << "F_NORMUINT8_3";
		case F_NORMUINT8_4: return out << "F_NORMUINT8_4";
		case F_INT16_1: return out << "F_INT16_1";
		case F_INT16_2: return out << "F_INT16_2";
		case F_INT16_3: return out << "F_INT16_3";
		case F_INT16_4: return out << "F_INT16_4";
		case F_UINT16_1: return out << "F_UINT16_1";
		case F_UINT16_2: return out << "F_UINT16_2";
		case F_UINT16_3: return out << "F_UINT16_3";
		case F_UINT16_4: return out << "F_UINT16_4";
		case F_NORMINT16_1: return out << "F_NORMINT16_1";
		case F_NORMINT16_2: return out << "F_NORMINT16_2";
		case F_NORMINT16_3: return out << "F_NORMINT16_3";
		case F_NORMINT16_4: return out << "F_NORMINT16_4";
		case F_NORMUINT16_1: return out << "F_NORMUINT16_1";
		case F_NORMUINT16_2: return out << "F_NORMUINT16_2";
		case F_NORMUINT16_3: return out << "F_NORMUINT16_3";
		case F_NORMUINT16_4: return out << "F_NORMUINT16_4";
		case F_INT32_1: return out << "F_INT32_1";
		case F_INT32_2: return out << "F_INT32_2";
		case F_INT32_3: return out << "F_INT32_3";
		case F_INT32_4: return out << "F_INT32_4";
		case F_UINT32_1: return out << "F_UINT32_1";
		case F_UINT32_2: return out << "F_UINT32_2";
		case F_UINT32_3: return out << "F_UINT32_3";
		case F_UINT32_4: return out << "F_UINT32_4";
		case F_NORMINT32_1: return out << "F_NORMINT32_1";
		case F_NORMINT32_2: return out << "F_NORMINT32_2";
		case F_NORMINT32_3: return out << "F_NORMINT32_3";
		case F_NORMINT32_4: return out << "F_NORMINT32_4";
		case F_NORMUINT32_1: return out << "F_NORMUINT32_1";
		case F_NORMUINT32_2: return out << "F_NORMUINT32_2";
		case F_NORMUINT32_3: return out << "F_NORMUINT32_3";
		case F_NORMUINT32_4: return out << "F_NORMUINT32_4";
		case F_FLOAT16_1: return out << "F_FLOAT16_1";
		case F_FLOAT16_2: return out << "F_FLOAT16_2";
		case F_FLOAT16_3: return out << "F_FLOAT16_3";
		case F_FLOAT16_4: return out << "F_FLOAT16_4";
		case F_FLOAT32_1: return out << "F_FLOAT32_1";
		case F_FLOAT32_2: return out << "F_FLOAT32_2";
		case F_FLOAT32_3: return out << "F_FLOAT32_3";
		case F_FLOAT32_4: return out << "F_FLOAT32_4";
		case F_UINT_10_10_10_L1: return out << "F_UINT_10_10_10_L1";
		case F_NORMINT_10_10_10_L1: return out << "F_NORMINT_10_10_10_L1";
		case F_NORMINT_11_11_10: return out << "F_NORMINT_11_11_10";
		case F_NORMUINT8_4_BGRA: return out << "F_NORMUINT8_4_BGRA";
		case F_NORMINT_10_10_10_2: return out << "F_NORMINT_10_10_10_2";
		case F_UINT_10_10_10_2: return out << "F_UINT_10_10_10_2";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--PropagationMode--//

void NifStream( PropagationMode & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = PropagationMode(temp);
}

void NifStream( PropagationMode const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, PropagationMode const & val ) {
	switch ( val ) {
		case PROPAGATE_ON_SUCCESS: return out << "PROPAGATE_ON_SUCCESS";
		case PROPAGATE_ON_FAILURE: return out << "PROPAGATE_ON_FAILURE";
		case PROPAGATE_ALWAYS: return out << "PROPAGATE_ALWAYS";
		case PROPAGATE_NEVER: return out << "PROPAGATE_NEVER";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--Fallout3HavokMaterial--//

void NifStream( Fallout3HavokMaterial & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = Fallout3HavokMaterial(temp);
}

void NifStream( Fallout3HavokMaterial const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, Fallout3HavokMaterial const & val ) {
	switch ( val ) {
		case FO_HAV_MAT_STONE: return out << "FO_HAV_MAT_STONE";
		case FO_HAV_MAT_CLOTH: return out << "FO_HAV_MAT_CLOTH";
		case FO_HAV_MAT_DIRT: return out << "FO_HAV_MAT_DIRT";
		case FO_HAV_MAT_GLASS: return out << "FO_HAV_MAT_GLASS";
		case FO_HAV_MAT_GRASS: return out << "FO_HAV_MAT_GRASS";
		case FO_HAV_MAT_METAL: return out << "FO_HAV_MAT_METAL";
		case FO_HAV_MAT_ORGANIC: return out << "FO_HAV_MAT_ORGANIC";
		case FO_HAV_MAT_SKIN: return out << "FO_HAV_MAT_SKIN";
		case FO_HAV_MAT_WATER: return out << "FO_HAV_MAT_WATER";
		case FO_HAV_MAT_WOOD: return out << "FO_HAV_MAT_WOOD";
		case FO_HAV_MAT_HEAVY_STONE: return out << "FO_HAV_MAT_HEAVY_STONE";
		case FO_HAV_MAT_HEAVY_METAL: return out << "FO_HAV_MAT_HEAVY_METAL";
		case FO_HAV_MAT_HEAVY_WOOD: return out << "FO_HAV_MAT_HEAVY_WOOD";
		case FO_HAV_MAT_CHAIN: return out << "FO_HAV_MAT_CHAIN";
		case FO_HAV_MAT_BOTTLECAP: return out << "FO_HAV_MAT_BOTTLECAP";
		case FO_HAV_MAT_ELEVATOR: return out << "FO_HAV_MAT_ELEVATOR";
		case FO_HAV_MAT_HOLLOW_METAL: return out << "FO_HAV_MAT_HOLLOW_METAL";
		case FO_HAV_MAT_SHEET_METAL: return out << "FO_HAV_MAT_SHEET_METAL";
		case FO_HAV_MAT_SAND: return out << "FO_HAV_MAT_SAND";
		case FO_HAV_MAT_BROKEN_CONCRETE: return out << "FO_HAV_MAT_BROKEN_CONCRETE";
		case FO_HAV_MAT_VEHICLE_BODY: return out << "FO_HAV_MAT_VEHICLE_BODY";
		case FO_HAV_MAT_VEHICLE_PART_SOLID: return out << "FO_HAV_MAT_VEHICLE_PART_SOLID";
		case FO_HAV_MAT_VEHICLE_PART_HOLLOW: return out << "FO_HAV_MAT_VEHICLE_PART_HOLLOW";
		case FO_HAV_MAT_BARREL: return out << "FO_HAV_MAT_BARREL";
		case FO_HAV_MAT_BOTTLE: return out << "FO_HAV_MAT_BOTTLE";
		case FO_HAV_MAT_SODA_CAN: return out << "FO_HAV_MAT_SODA_CAN";
		case FO_HAV_MAT_PISTOL: return out << "FO_HAV_MAT_PISTOL";
		case FO_HAV_MAT_RIFLE: return out << "FO_HAV_MAT_RIFLE";
		case FO_HAV_MAT_SHOPPING_CART: return out << "FO_HAV_MAT_SHOPPING_CART";
		case FO_HAV_MAT_LUNCHBOX: return out << "FO_HAV_MAT_LUNCHBOX";
		case FO_HAV_MAT_BABY_RATTLE: return out << "FO_HAV_MAT_BABY_RATTLE";
		case FO_HAV_MAT_RUBBER_BALL: return out << "FO_HAV_MAT_RUBBER_BALL";
		case FO_HAV_MAT_STONE_PLATFORM: return out << "FO_HAV_MAT_STONE_PLATFORM";
		case FO_HAV_MAT_CLOTH_PLATFORM: return out << "FO_HAV_MAT_CLOTH_PLATFORM";
		case FO_HAV_MAT_DIRT_PLATFORM: return out << "FO_HAV_MAT_DIRT_PLATFORM";
		case FO_HAV_MAT_GLASS_PLATFORM: return out << "FO_HAV_MAT_GLASS_PLATFORM";
		case FO_HAV_MAT_GRASS_PLATFORM: return out << "FO_HAV_MAT_GRASS_PLATFORM";
		case FO_HAV_MAT_METAL_PLATFORM: return out << "FO_HAV_MAT_METAL_PLATFORM";
		case FO_HAV_MAT_ORGANIC_PLATFORM: return out << "FO_HAV_MAT_ORGANIC_PLATFORM";
		case FO_HAV_MAT_SKIN_PLATFORM: return out << "FO_HAV_MAT_SKIN_PLATFORM";
		case FO_HAV_MAT_WATER_PLATFORM: return out << "FO_HAV_MAT_WATER_PLATFORM";
		case FO_HAV_MAT_WOOD_PLATFORM: return out << "FO_HAV_MAT_WOOD_PLATFORM";
		case FO_HAV_MAT_HEAVY_STONE_PLATFORM: return out << "FO_HAV_MAT_HEAVY_STONE_PLATFORM";
		case FO_HAV_MAT_HEAVY_METAL_PLATFORM: return out << "FO_HAV_MAT_HEAVY_METAL_PLATFORM";
		case FO_HAV_MAT_HEAVY_WOOD_PLATFORM: return out << "FO_HAV_MAT_HEAVY_WOOD_PLATFORM";
		case FO_HAV_MAT_CHAIN_PLATFORM: return out << "FO_HAV_MAT_CHAIN_PLATFORM";
		case FO_HAV_MAT_BOTTLECAP_PLATFORM: return out << "FO_HAV_MAT_BOTTLECAP_PLATFORM";
		case FO_HAV_MAT_ELEVATOR_PLATFORM: return out << "FO_HAV_MAT_ELEVATOR_PLATFORM";
		case FO_HAV_MAT_HOLLOW_METAL_PLATFORM: return out << "FO_HAV_MAT_HOLLOW_METAL_PLATFORM";
		case FO_HAV_MAT_SHEET_METAL_PLATFORM: return out << "FO_HAV_MAT_SHEET_METAL_PLATFORM";
		case FO_HAV_MAT_SAND_PLATFORM: return out << "FO_HAV_MAT_SAND_PLATFORM";
		case FO_HAV_MAT_BROKEN_CONCRETE_PLATFORM: return out << "FO_HAV_MAT_BROKEN_CONCRETE_PLATFORM";
		case FO_HAV_MAT_VEHICLE_BODY_PLATFORM: return out << "FO_HAV_MAT_VEHICLE_BODY_PLATFORM";
		case FO_HAV_MAT_VEHICLE_PART_SOLID_PLATFORM: return out << "FO_HAV_MAT_VEHICLE_PART_SOLID_PLATFORM";
		case FO_HAV_MAT_VEHICLE_PART_HOLLOW_PLATFORM: return out << "FO_HAV_MAT_VEHICLE_PART_HOLLOW_PLATFORM";
		case FO_HAV_MAT_BARREL_PLATFORM: return out << "FO_HAV_MAT_BARREL_PLATFORM";
		case FO_HAV_MAT_BOTTLE_PLATFORM: return out << "FO_HAV_MAT_BOTTLE_PLATFORM";
		case FO_HAV_MAT_SODA_CAN_PLATFORM: return out << "FO_HAV_MAT_SODA_CAN_PLATFORM";
		case FO_HAV_MAT_PISTOL_PLATFORM: return out << "FO_HAV_MAT_PISTOL_PLATFORM";
		case FO_HAV_MAT_RIFLE_PLATFORM: return out << "FO_HAV_MAT_RIFLE_PLATFORM";
		case FO_HAV_MAT_SHOPPING_CART_PLATFORM: return out << "FO_HAV_MAT_SHOPPING_CART_PLATFORM";
		case FO_HAV_MAT_LUNCHBOX_PLATFORM: return out << "FO_HAV_MAT_LUNCHBOX_PLATFORM";
		case FO_HAV_MAT_BABY_RATTLE_PLATFORM: return out << "FO_HAV_MAT_BABY_RATTLE_PLATFORM";
		case FO_HAV_MAT_RUBBER_BALL_PLATFORM: return out << "FO_HAV_MAT_RUBBER_BALL_PLATFORM";
		case FO_HAV_MAT_STONE_STAIRS: return out << "FO_HAV_MAT_STONE_STAIRS";
		case FO_HAV_MAT_CLOTH_STAIRS: return out << "FO_HAV_MAT_CLOTH_STAIRS";
		case FO_HAV_MAT_DIRT_STAIRS: return out << "FO_HAV_MAT_DIRT_STAIRS";
		case FO_HAV_MAT_GLASS_STAIRS: return out << "FO_HAV_MAT_GLASS_STAIRS";
		case FO_HAV_MAT_GRASS_STAIRS: return out << "FO_HAV_MAT_GRASS_STAIRS";
		case FO_HAV_MAT_METAL_STAIRS: return out << "FO_HAV_MAT_METAL_STAIRS";
		case FO_HAV_MAT_ORGANIC_STAIRS: return out << "FO_HAV_MAT_ORGANIC_STAIRS";
		case FO_HAV_MAT_SKIN_STAIRS: return out << "FO_HAV_MAT_SKIN_STAIRS";
		case FO_HAV_MAT_WATER_STAIRS: return out << "FO_HAV_MAT_WATER_STAIRS";
		case FO_HAV_MAT_WOOD_STAIRS: return out << "FO_HAV_MAT_WOOD_STAIRS";
		case FO_HAV_MAT_HEAVY_STONE_STAIRS: return out << "FO_HAV_MAT_HEAVY_STONE_STAIRS";
		case FO_HAV_MAT_HEAVY_METAL_STAIRS: return out << "FO_HAV_MAT_HEAVY_METAL_STAIRS";
		case FO_HAV_MAT_HEAVY_WOOD_STAIRS: return out << "FO_HAV_MAT_HEAVY_WOOD_STAIRS";
		case FO_HAV_MAT_CHAIN_STAIRS: return out << "FO_HAV_MAT_CHAIN_STAIRS";
		case FO_HAV_MAT_BOTTLECAP_STAIRS: return out << "FO_HAV_MAT_BOTTLECAP_STAIRS";
		case FO_HAV_MAT_ELEVATOR_STAIRS: return out << "FO_HAV_MAT_ELEVATOR_STAIRS";
		case FO_HAV_MAT_HOLLOW_METAL_STAIRS: return out << "FO_HAV_MAT_HOLLOW_METAL_STAIRS";
		case FO_HAV_MAT_SHEET_METAL_STAIRS: return out << "FO_HAV_MAT_SHEET_METAL_STAIRS";
		case FO_HAV_MAT_SAND_STAIRS: return out << "FO_HAV_MAT_SAND_STAIRS";
		case FO_HAV_MAT_BROKEN_CONCRETE_STAIRS: return out << "FO_HAV_MAT_BROKEN_CONCRETE_STAIRS";
		case FO_HAV_MAT_VEHICLE_BODY_STAIRS: return out << "FO_HAV_MAT_VEHICLE_BODY_STAIRS";
		case FO_HAV_MAT_VEHICLE_PART_SOLID_STAIRS: return out << "FO_HAV_MAT_VEHICLE_PART_SOLID_STAIRS";
		case FO_HAV_MAT_VEHICLE_PART_HOLLOW_STAIRS: return out << "FO_HAV_MAT_VEHICLE_PART_HOLLOW_STAIRS";
		case FO_HAV_MAT_BARREL_STAIRS: return out << "FO_HAV_MAT_BARREL_STAIRS";
		case FO_HAV_MAT_BOTTLE_STAIRS: return out << "FO_HAV_MAT_BOTTLE_STAIRS";
		case FO_HAV_MAT_SODA_CAN_STAIRS: return out << "FO_HAV_MAT_SODA_CAN_STAIRS";
		case FO_HAV_MAT_PISTOL_STAIRS: return out << "FO_HAV_MAT_PISTOL_STAIRS";
		case FO_HAV_MAT_RIFLE_STAIRS: return out << "FO_HAV_MAT_RIFLE_STAIRS";
		case FO_HAV_MAT_SHOPPING_CART_STAIRS: return out << "FO_HAV_MAT_SHOPPING_CART_STAIRS";
		case FO_HAV_MAT_LUNCHBOX_STAIRS: return out << "FO_HAV_MAT_LUNCHBOX_STAIRS";
		case FO_HAV_MAT_BABY_RATTLE_STAIRS: return out << "FO_HAV_MAT_BABY_RATTLE_STAIRS";
		case FO_HAV_MAT_RUBBER_BALL_STAIRS: return out << "FO_HAV_MAT_RUBBER_BALL_STAIRS";
		case FO_HAV_MAT_STONE_STAIRS_PLATFORM: return out << "FO_HAV_MAT_STONE_STAIRS_PLATFORM";
		case FO_HAV_MAT_CLOTH_STAIRS_PLATFORM: return out << "FO_HAV_MAT_CLOTH_STAIRS_PLATFORM";
		case FO_HAV_MAT_DIRT_STAIRS_PLATFORM: return out << "FO_HAV_MAT_DIRT_STAIRS_PLATFORM";
		case FO_HAV_MAT_GLASS_STAIRS_PLATFORM: return out << "FO_HAV_MAT_GLASS_STAIRS_PLATFORM";
		case FO_HAV_MAT_GRASS_STAIRS_PLATFORM: return out << "FO_HAV_MAT_GRASS_STAIRS_PLATFORM";
		case FO_HAV_MAT_METAL_STAIRS_PLATFORM: return out << "FO_HAV_MAT_METAL_STAIRS_PLATFORM";
		case FO_HAV_MAT_ORGANIC_STAIRS_PLATFORM: return out << "FO_HAV_MAT_ORGANIC_STAIRS_PLATFORM";
		case FO_HAV_MAT_SKIN_STAIRS_PLATFORM: return out << "FO_HAV_MAT_SKIN_STAIRS_PLATFORM";
		case FO_HAV_MAT_WATER_STAIRS_PLATFORM: return out << "FO_HAV_MAT_WATER_STAIRS_PLATFORM";
		case FO_HAV_MAT_WOOD_STAIRS_PLATFORM: return out << "FO_HAV_MAT_WOOD_STAIRS_PLATFORM";
		case FO_HAV_MAT_HEAVY_STONE_STAIRS_PLATFORM: return out << "FO_HAV_MAT_HEAVY_STONE_STAIRS_PLATFORM";
		case FO_HAV_MAT_HEAVY_METAL_STAIRS_PLATFORM: return out << "FO_HAV_MAT_HEAVY_METAL_STAIRS_PLATFORM";
		case FO_HAV_MAT_HEAVY_WOOD_STAIRS_PLATFORM: return out << "FO_HAV_MAT_HEAVY_WOOD_STAIRS_PLATFORM";
		case FO_HAV_MAT_CHAIN_STAIRS_PLATFORM: return out << "FO_HAV_MAT_CHAIN_STAIRS_PLATFORM";
		case FO_HAV_MAT_BOTTLECAP_STAIRS_PLATFORM: return out << "FO_HAV_MAT_BOTTLECAP_STAIRS_PLATFORM";
		case FO_HAV_MAT_ELEVATOR_STAIRS_PLATFORM: return out << "FO_HAV_MAT_ELEVATOR_STAIRS_PLATFORM";
		case FO_HAV_MAT_HOLLOW_METAL_STAIRS_PLATFORM: return out << "FO_HAV_MAT_HOLLOW_METAL_STAIRS_PLATFORM";
		case FO_HAV_MAT_SHEET_METAL_STAIRS_PLATFORM: return out << "FO_HAV_MAT_SHEET_METAL_STAIRS_PLATFORM";
		case FO_HAV_MAT_SAND_STAIRS_PLATFORM: return out << "FO_HAV_MAT_SAND_STAIRS_PLATFORM";
		case FO_HAV_MAT_BROKEN_CONCRETE_STAIRS_PLATFORM: return out << "FO_HAV_MAT_BROKEN_CONCRETE_STAIRS_PLATFORM";
		case FO_HAV_MAT_VEHICLE_BODY_STAIRS_PLATFORM: return out << "FO_HAV_MAT_VEHICLE_BODY_STAIRS_PLATFORM";
		case FO_HAV_MAT_VEHICLE_PART_SOLID_STAIRS_PLATFORM: return out << "FO_HAV_MAT_VEHICLE_PART_SOLID_STAIRS_PLATFORM";
		case FO_HAV_MAT_VEHICLE_PART_HOLLOW_STAIRS_PLATFORM: return out << "FO_HAV_MAT_VEHICLE_PART_HOLLOW_STAIRS_PLATFORM";
		case FO_HAV_MAT_BARREL_STAIRS_PLATFORM: return out << "FO_HAV_MAT_BARREL_STAIRS_PLATFORM";
		case FO_HAV_MAT_BOTTLE_STAIRS_PLATFORM: return out << "FO_HAV_MAT_BOTTLE_STAIRS_PLATFORM";
		case FO_HAV_MAT_SODA_CAN_STAIRS_PLATFORM: return out << "FO_HAV_MAT_SODA_CAN_STAIRS_PLATFORM";
		case FO_HAV_MAT_PISTOL_STAIRS_PLATFORM: return out << "FO_HAV_MAT_PISTOL_STAIRS_PLATFORM";
		case FO_HAV_MAT_RIFLE_STAIRS_PLATFORM: return out << "FO_HAV_MAT_RIFLE_STAIRS_PLATFORM";
		case FO_HAV_MAT_SHOPPING_CART_STAIRS_PLATFORM: return out << "FO_HAV_MAT_SHOPPING_CART_STAIRS_PLATFORM";
		case FO_HAV_MAT_LUNCHBOX_STAIRS_PLATFORM: return out << "FO_HAV_MAT_LUNCHBOX_STAIRS_PLATFORM";
		case FO_HAV_MAT_BABY_RATTLE_STAIRS_PLATFORM: return out << "FO_HAV_MAT_BABY_RATTLE_STAIRS_PLATFORM";
		case FO_HAV_MAT_RUBBER_BALL_STAIRS_PLATFORM: return out << "FO_HAV_MAT_RUBBER_BALL_STAIRS_PLATFORM";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--DataStreamUsage--//

void NifStream( DataStreamUsage & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = DataStreamUsage(temp);
}

void NifStream( DataStreamUsage const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, DataStreamUsage const & val ) {
	switch ( val ) {
		case USAGE_VERTEX_INDEX: return out << "USAGE_VERTEX_INDEX";
		case USAGE_VERTEX: return out << "USAGE_VERTEX";
		case USAGE_SHADER_CONSTANT: return out << "USAGE_SHADER_CONSTANT";
		case USAGE_USER: return out << "USAGE_USER";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--BSShaderType--//

void NifStream( BSShaderType & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = BSShaderType(temp);
}

void NifStream( BSShaderType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, BSShaderType const & val ) {
	switch ( val ) {
		case SHADER_TALL_GRASS: return out << "SHADER_TALL_GRASS";
		case SHADER_DEFAULT: return out << "SHADER_DEFAULT";
		case SHADER_SKY: return out << "SHADER_SKY";
		case SHADER_SKIN: return out << "SHADER_SKIN";
		case SHADER_WATER: return out << "SHADER_WATER";
		case SHADER_LIGHTING30: return out << "SHADER_LIGHTING30";
		case SHADER_TILE: return out << "SHADER_TILE";
		case SHADER_NOLIGHTING: return out << "SHADER_NOLIGHTING";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--BroadPhaseType--//

void NifStream( BroadPhaseType & val, istream& in, const NifInfo & info ) {
	byte temp;
	NifStream( temp, in, info );
	val = BroadPhaseType(temp);
}

void NifStream( BroadPhaseType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (byte)(val), out, info );
}

ostream & operator<<( ostream & out, BroadPhaseType const & val ) {
	switch ( val ) {
		case BROAD_PHASE_INVALID: return out << "BROAD_PHASE_INVALID";
		case BROAD_PHASE_ENTITY: return out << "BROAD_PHASE_ENTITY";
		case BROAD_PHASE_PHANTOM: return out << "BROAD_PHASE_PHANTOM";
		case BROAD_PHASE_BORDER: return out << "BROAD_PHASE_BORDER";
		default: return out << "Invalid Value! - " << (byte)(val);
	}
}

//--TransformMethod--//

void NifStream( TransformMethod & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = TransformMethod(temp);
}

void NifStream( TransformMethod const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, TransformMethod const & val ) {
	switch ( val ) {
		case TM_MAYA_DEPRECATED: return out << "TM_Maya Deprecated";
		case TM_MAX: return out << "TM_Max";
		case TM_MAYA: return out << "TM_Maya";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--PixelFormat--//

void NifStream( PixelFormat & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = PixelFormat(temp);
}

void NifStream( PixelFormat const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, PixelFormat const & val ) {
	switch ( val ) {
		case PX_FMT_RGB: return out << "PX_FMT_RGB";
		case PX_FMT_RGBA: return out << "PX_FMT_RGBA";
		case PX_FMT_PAL: return out << "PX_FMT_PAL";
		case PX_FMT_PALA: return out << "PX_FMT_PALA";
		case PX_FMT_DXT1: return out << "PX_FMT_DXT1";
		case PX_FMT_DXT3: return out << "PX_FMT_DXT3";
		case PX_FMT_DXT5: return out << "PX_FMT_DXT5";
		case PX_FMT_RGB24NONINT: return out << "PX_FMT_RGB24NONINT";
		case PX_FMT_BUMP: return out << "PX_FMT_BUMP";
		case PX_FMT_BUMPLUMA: return out << "PX_FMT_BUMPLUMA";
		case PX_FMT_RENDERSPEC: return out << "PX_FMT_RENDERSPEC";
		case PX_FMT_1CH: return out << "PX_FMT_1CH";
		case PX_FMT_2CH: return out << "PX_FMT_2CH";
		case PX_FMT_3CH: return out << "PX_FMT_3CH";
		case PX_FMT_4CH: return out << "PX_FMT_4CH";
		case PX_FMT_DEPTH_STENCIL: return out << "PX_FMT_DEPTH_STENCIL";
		case PX_FMT_UNKNOWN: return out << "PX_FMT_UNKNOWN";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--CycleType--//

void NifStream( CycleType & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = CycleType(temp);
}

void NifStream( CycleType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, CycleType const & val ) {
	switch ( val ) {
		case CYCLE_LOOP: return out << "CYCLE_LOOP";
		case CYCLE_REVERSE: return out << "CYCLE_REVERSE";
		case CYCLE_CLAMP: return out << "CYCLE_CLAMP";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--FieldType--//

void NifStream( FieldType & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = FieldType(temp);
}

void NifStream( FieldType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, FieldType const & val ) {
	switch ( val ) {
		case FIELD_WIND: return out << "FIELD_WIND";
		case FIELD_POINT: return out << "FIELD_POINT";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--MaterialColor--//

void NifStream( MaterialColor & val, istream& in, const NifInfo & info ) {
	unsigned short temp;
	NifStream( temp, in, info );
	val = MaterialColor(temp);
}

void NifStream( MaterialColor const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned short)(val), out, info );
}

ostream & operator<<( ostream & out, MaterialColor const & val ) {
	switch ( val ) {
		case TC_AMBIENT: return out << "TC_AMBIENT";
		case TC_DIFFUSE: return out << "TC_DIFFUSE";
		case TC_SPECULAR: return out << "TC_SPECULAR";
		case TC_SELF_ILLUM: return out << "TC_SELF_ILLUM";
		default: return out << "Invalid Value! - " << (unsigned short)(val);
	}
}

//--StencilDrawMode--//

void NifStream( StencilDrawMode & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = StencilDrawMode(temp);
}

void NifStream( StencilDrawMode const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, StencilDrawMode const & val ) {
	switch ( val ) {
		case DRAW_CCW_OR_BOTH: return out << "DRAW_CCW_OR_BOTH";
		case DRAW_CCW: return out << "DRAW_CCW";
		case DRAW_CW: return out << "DRAW_CW";
		case DRAW_BOTH: return out << "DRAW_BOTH";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--BSLightingShaderPropertyShaderType--//

void NifStream( BSLightingShaderPropertyShaderType & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = BSLightingShaderPropertyShaderType(temp);
}

void NifStream( BSLightingShaderPropertyShaderType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, BSLightingShaderPropertyShaderType const & val ) {
	switch ( val ) {
		case ST_DEFAULT: return out << "ST_Default";
		case ST_ENVIRONMENT_MAP: return out << "ST_Environment Map";
		case ST_GLOW_SHADER: return out << "ST_Glow Shader";
		case ST_PARALLAX: return out << "ST_Parallax";
		case ST_FACE_TINT: return out << "ST_Face Tint";
		case ST_SKIN_TINT: return out << "ST_Skin Tint";
		case ST_HAIR_TINT: return out << "ST_Hair Tint";
		case ST_PARALLAX_OCC: return out << "ST_Parallax Occ";
		case ST_MULTITEXTURE_LANDSCAPE: return out << "ST_Multitexture Landscape";
		case ST_LOD_LANDSCAPE: return out << "ST_LOD Landscape";
		case ST_SNOW: return out << "ST_Snow";
		case ST_MULTILAYER_PARALLAX: return out << "ST_MultiLayer Parallax";
		case ST_TREE_ANIM: return out << "ST_Tree Anim";
		case ST_LOD_OBJECTS: return out << "ST_LOD Objects";
		case ST_SPARKLE_SNOW: return out << "ST_Sparkle Snow";
		case ST_LOD_OBJECTS_HD: return out << "ST_LOD Objects HD";
		case ST_EYE_ENVMAP: return out << "ST_Eye Envmap";
		case ST_CLOUD: return out << "ST_Cloud";
		case ST_LOD_LANDSCAPE_NOISE: return out << "ST_LOD Landscape Noise";
		case ST_MULTITEXTURE_LANDSCAPE_LOD_BLEND: return out << "ST_Multitexture Landscape LOD Blend";
		case ST_FO4_DISMEMBERMENT: return out << "ST_FO4 Dismemberment";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--DecayType--//

void NifStream( DecayType & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = DecayType(temp);
}

void NifStream( DecayType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, DecayType const & val ) {
	switch ( val ) {
		case DECAY_NONE: return out << "DECAY_NONE";
		case DECAY_LINEAR: return out << "DECAY_LINEAR";
		case DECAY_EXPONENTIAL: return out << "DECAY_EXPONENTIAL";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--PixelRepresentation--//

void NifStream( PixelRepresentation & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = PixelRepresentation(temp);
}

void NifStream( PixelRepresentation const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, PixelRepresentation const & val ) {
	switch ( val ) {
		case PX_REP_NORM_INT: return out << "PX_REP_NORM_INT";
		case PX_REP_HALF: return out << "PX_REP_HALF";
		case PX_REP_FLOAT: return out << "PX_REP_FLOAT";
		case PX_REP_INDEX: return out << "PX_REP_INDEX";
		case PX_REP_COMPRESSED: return out << "PX_REP_COMPRESSED";
		case PX_REP_UNKNOWN: return out << "PX_REP_UNKNOWN";
		case PX_REP_INT: return out << "PX_REP_INT";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--SkyObjectType--//

void NifStream( SkyObjectType & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = SkyObjectType(temp);
}

void NifStream( SkyObjectType const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, SkyObjectType const & val ) {
	switch ( val ) {
		case BSSM_SKY_TEXTURE: return out << "BSSM_SKY_TEXTURE";
		case BSSM_SKY_SUNGLARE: return out << "BSSM_SKY_SUNGLARE";
		case BSSM_SKY: return out << "BSSM_SKY";
		case BSSM_SKY_CLOUDS: return out << "BSSM_SKY_CLOUDS";
		case BSSM_SKY_STARS: return out << "BSSM_SKY_STARS";
		case BSSM_SKY_MOON_STARS_MASK: return out << "BSSM_SKY_MOON_STARS_MASK";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--PixelTiling--//

void NifStream( PixelTiling & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = PixelTiling(temp);
}

void NifStream( PixelTiling const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, PixelTiling const & val ) {
	switch ( val ) {
		case PX_TILE_NONE: return out << "PX_TILE_NONE";
		case PX_TILE_XENON: return out << "PX_TILE_XENON";
		case PX_TILE_WII: return out << "PX_TILE_WII";
		case PX_TILE_NV_SWIZZLED: return out << "PX_TILE_NV_SWIZZLED";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--SkyrimLayer--//

void NifStream( SkyrimLayer & val, istream& in, const NifInfo & info ) {
	byte temp;
	NifStream( temp, in, info );
	val = SkyrimLayer(temp);
}

void NifStream( SkyrimLayer const & val, ostream& out, const NifInfo & info ) {
	NifStream( (byte)(val), out, info );
}

ostream & operator<<( ostream & out, SkyrimLayer const & val ) {
	switch ( val ) {
		case SKYL_UNIDENTIFIED: return out << "SKYL_UNIDENTIFIED";
		case SKYL_STATIC: return out << "SKYL_STATIC";
		case SKYL_ANIMSTATIC: return out << "SKYL_ANIMSTATIC";
		case SKYL_TRANSPARENT: return out << "SKYL_TRANSPARENT";
		case SKYL_CLUTTER: return out << "SKYL_CLUTTER";
		case SKYL_WEAPON: return out << "SKYL_WEAPON";
		case SKYL_PROJECTILE: return out << "SKYL_PROJECTILE";
		case SKYL_SPELL: return out << "SKYL_SPELL";
		case SKYL_BIPED: return out << "SKYL_BIPED";
		case SKYL_TREES: return out << "SKYL_TREES";
		case SKYL_PROPS: return out << "SKYL_PROPS";
		case SKYL_WATER: return out << "SKYL_WATER";
		case SKYL_TRIGGER: return out << "SKYL_TRIGGER";
		case SKYL_TERRAIN: return out << "SKYL_TERRAIN";
		case SKYL_TRAP: return out << "SKYL_TRAP";
		case SKYL_NONCOLLIDABLE: return out << "SKYL_NONCOLLIDABLE";
		case SKYL_CLOUD_TRAP: return out << "SKYL_CLOUD_TRAP";
		case SKYL_GROUND: return out << "SKYL_GROUND";
		case SKYL_PORTAL: return out << "SKYL_PORTAL";
		case SKYL_DEBRIS_SMALL: return out << "SKYL_DEBRIS_SMALL";
		case SKYL_DEBRIS_LARGE: return out << "SKYL_DEBRIS_LARGE";
		case SKYL_ACOUSTIC_SPACE: return out << "SKYL_ACOUSTIC_SPACE";
		case SKYL_ACTORZONE: return out << "SKYL_ACTORZONE";
		case SKYL_PROJECTILEZONE: return out << "SKYL_PROJECTILEZONE";
		case SKYL_GASTRAP: return out << "SKYL_GASTRAP";
		case SKYL_SHELLCASING: return out << "SKYL_SHELLCASING";
		case SKYL_TRANSPARENT_SMALL: return out << "SKYL_TRANSPARENT_SMALL";
		case SKYL_INVISIBLE_WALL: return out << "SKYL_INVISIBLE_WALL";
		case SKYL_TRANSPARENT_SMALL_ANIM: return out << "SKYL_TRANSPARENT_SMALL_ANIM";
		case SKYL_WARD: return out << "SKYL_WARD";
		case SKYL_CHARCONTROLLER: return out << "SKYL_CHARCONTROLLER";
		case SKYL_STAIRHELPER: return out << "SKYL_STAIRHELPER";
		case SKYL_DEADBIP: return out << "SKYL_DEADBIP";
		case SKYL_BIPED_NO_CC: return out << "SKYL_BIPED_NO_CC";
		case SKYL_AVOIDBOX: return out << "SKYL_AVOIDBOX";
		case SKYL_COLLISIONBOX: return out << "SKYL_COLLISIONBOX";
		case SKYL_CAMERASHPERE: return out << "SKYL_CAMERASHPERE";
		case SKYL_DOORDETECTION: return out << "SKYL_DOORDETECTION";
		case SKYL_CONEPROJECTILE: return out << "SKYL_CONEPROJECTILE";
		case SKYL_CAMERAPICK: return out << "SKYL_CAMERAPICK";
		case SKYL_ITEMPICK: return out << "SKYL_ITEMPICK";
		case SKYL_LINEOFSIGHT: return out << "SKYL_LINEOFSIGHT";
		case SKYL_PATHPICK: return out << "SKYL_PATHPICK";
		case SKYL_CUSTOMPICK1: return out << "SKYL_CUSTOMPICK1";
		case SKYL_CUSTOMPICK2: return out << "SKYL_CUSTOMPICK2";
		case SKYL_SPELLEXPLOSION: return out << "SKYL_SPELLEXPLOSION";
		case SKYL_DROPPINGPICK: return out << "SKYL_DROPPINGPICK";
		case SKYL_NULL: return out << "SKYL_NULL";
		default: return out << "Invalid Value! - " << (byte)(val);
	}
}

//--SkyrimWaterShaderFlags--//

void NifStream( SkyrimWaterShaderFlags & val, istream& in, const NifInfo & info ) {
	byte temp;
	NifStream( temp, in, info );
	val = SkyrimWaterShaderFlags(temp);
}

void NifStream( SkyrimWaterShaderFlags const & val, ostream& out, const NifInfo & info ) {
	NifStream( (byte)(val), out, info );
}

ostream & operator<<( ostream & out, SkyrimWaterShaderFlags const & val ) {
	switch ( val ) {
		case SWSF1_UNKNOWN0: return out << "SWSF1_UNKNOWN0";
		case SWSF1_BYPASS_REFRACTION_MAP: return out << "SWSF1_Bypass_Refraction_Map";
		case SWSF1_WATER_TOGGLE: return out << "SWSF1_Water_Toggle";
		case SWSF1_UNKNOWN3: return out << "SWSF1_UNKNOWN3";
		case SWSF1_UNKNOWN4: return out << "SWSF1_UNKNOWN4";
		case SWSF1_UNKNOWN5: return out << "SWSF1_UNKNOWN5";
		case SWSF1_HIGHLIGHT_LAYER_TOGGLE: return out << "SWSF1_Highlight_Layer_Toggle";
		case SWSF1_ENABLED: return out << "SWSF1_Enabled";
		default: return out << "Invalid Value! - " << (byte)(val);
	}
}

//--PathFlags--//

void NifStream( PathFlags & val, istream& in, const NifInfo & info ) {
	unsigned short temp;
	NifStream( temp, in, info );
	val = PathFlags(temp);
}

void NifStream( PathFlags const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned short)(val), out, info );
}

ostream & operator<<( ostream & out, PathFlags const & val ) {
	switch ( val ) {
		case NIPI_CVDATANEEDSUPDATE: return out << "NIPI_CVDataNeedsUpdate";
		case NIPI_CURVETYPEOPEN: return out << "NIPI_CurveTypeOpen";
		case NIPI_ALLOWFLIP: return out << "NIPI_AllowFlip";
		case NIPI_BANK: return out << "NIPI_Bank";
		case NIPI_CONSTANTVELOCITY: return out << "NIPI_ConstantVelocity";
		case NIPI_FOLLOW: return out << "NIPI_Follow";
		case NIPI_FLIP: return out << "NIPI_Flip";
		default: return out << "Invalid Value! - " << (unsigned short)(val);
	}
}

//--SkyrimShaderPropertyFlags1--//

void NifStream( SkyrimShaderPropertyFlags1 & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = SkyrimShaderPropertyFlags1(temp);
}

void NifStream( SkyrimShaderPropertyFlags1 const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, SkyrimShaderPropertyFlags1 const & val ) {
	switch ( val ) {
		case SLSF1_SPECULAR: return out << "SLSF1_Specular";
		case SLSF1_SKINNED: return out << "SLSF1_Skinned";
		case SLSF1_TEMP_REFRACTION: return out << "SLSF1_Temp_Refraction";
		case SLSF1_VERTEX_ALPHA: return out << "SLSF1_Vertex_Alpha";
		case SLSF1_GREYSCALE_TO_PALETTECOLOR: return out << "SLSF1_Greyscale_To_PaletteColor";
		case SLSF1_GREYSCALE_TO_PALETTEALPHA: return out << "SLSF1_Greyscale_To_PaletteAlpha";
		case SLSF1_USE_FALLOFF: return out << "SLSF1_Use_Falloff";
		case SLSF1_ENVIRONMENT_MAPPING: return out << "SLSF1_Environment_Mapping";
		case SLSF1_RECIEVE_SHADOWS: return out << "SLSF1_Recieve_Shadows";
		case SLSF1_CAST_SHADOWS: return out << "SLSF1_Cast_Shadows";
		case SLSF1_FACEGEN_DETAIL_MAP: return out << "SLSF1_Facegen_Detail_Map";
		case SLSF1_PARALLAX: return out << "SLSF1_Parallax";
		case SLSF1_MODEL_SPACE_NORMALS: return out << "SLSF1_Model_Space_Normals";
		case SLSF1_NON_PROJECTIVE_SHADOWS: return out << "SLSF1_Non_Projective_Shadows";
		case SLSF1_LANDSCAPE: return out << "SLSF1_Landscape";
		case SLSF1_REFRACTION: return out << "SLSF1_Refraction";
		case SLSF1_FIRE_REFRACTION: return out << "SLSF1_Fire_Refraction";
		case SLSF1_EYE_ENVIRONMENT_MAPPING: return out << "SLSF1_Eye_Environment_Mapping";
		case SLSF1_HAIR_SOFT_LIGHTING: return out << "SLSF1_Hair_Soft_Lighting";
		case SLSF1_SCREENDOOR_ALPHA_FADE: return out << "SLSF1_Screendoor_Alpha_Fade";
		case SLSF1_LOCALMAP_HIDE_SECRET: return out << "SLSF1_Localmap_Hide_Secret";
		case SLSF1_FACEGEN_RGB_TINT: return out << "SLSF1_FaceGen_RGB_Tint";
		case SLSF1_OWN_EMIT: return out << "SLSF1_Own_Emit";
		case SLSF1_PROJECTED_UV: return out << "SLSF1_Projected_UV";
		case SLSF1_MULTIPLE_TEXTURES: return out << "SLSF1_Multiple_Textures";
		case SLSF1_REMAPPABLE_TEXTURES: return out << "SLSF1_Remappable_Textures";
		case SLSF1_DECAL: return out << "SLSF1_Decal";
		case SLSF1_DYNAMIC_DECAL: return out << "SLSF1_Dynamic_Decal";
		case SLSF1_PARALLAX_OCCLUSION: return out << "SLSF1_Parallax_Occlusion";
		case SLSF1_EXTERNAL_EMITTANCE: return out << "SLSF1_External_Emittance";
		case SLSF1_SOFT_EFFECT: return out << "SLSF1_Soft_Effect";
		case SLSF1_ZBUFFER_TEST: return out << "SLSF1_ZBuffer_Test";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--bhkCOFlags--//

void NifStream( bhkCOFlags & val, istream& in, const NifInfo & info ) {
	unsigned short temp;
	NifStream( temp, in, info );
	val = bhkCOFlags(temp);
}

void NifStream( bhkCOFlags const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned short)(val), out, info );
}

ostream & operator<<( ostream & out, bhkCOFlags const & val ) {
	switch ( val ) {
		case BHKCO_ACTIVE: return out << "BHKCO_ACTIVE";
		case BHKCO_NOTIFY: return out << "BHKCO_NOTIFY";
		case BHKCO_SET_LOCAL: return out << "BHKCO_SET_LOCAL";
		case BHKCO_DBG_DISPLAY: return out << "BHKCO_DBG_DISPLAY";
		case BHKCO_USE_VEL: return out << "BHKCO_USE_VEL";
		case BHKCO_RESET: return out << "BHKCO_RESET";
		case BHKCO_SYNC_ON_UPDATE: return out << "BHKCO_SYNC_ON_UPDATE";
		case BHKCO_ANIM_TARGETED: return out << "BHKCO_ANIM_TARGETED";
		case BHKCO_DISMEMBERED_LIMB: return out << "BHKCO_DISMEMBERED_LIMB";
		default: return out << "Invalid Value! - " << (unsigned short)(val);
	}
}

//--BSValueNodeFlags--//

void NifStream( BSValueNodeFlags & val, istream& in, const NifInfo & info ) {
	byte temp;
	NifStream( temp, in, info );
	val = BSValueNodeFlags(temp);
}

void NifStream( BSValueNodeFlags const & val, ostream& out, const NifInfo & info ) {
	NifStream( (byte)(val), out, info );
}

ostream & operator<<( ostream & out, BSValueNodeFlags const & val ) {
	switch ( val ) {
		case BILLBOARDWORLDZ: return out << "BillboardWorldZ";
		case USEPLAYERADJUST: return out << "UsePlayerAdjust";
		default: return out << "Invalid Value! - " << (byte)(val);
	}
}

//--VectorFlags--//

void NifStream( VectorFlags & val, istream& in, const NifInfo & info ) {
	unsigned short temp;
	NifStream( temp, in, info );
	val = VectorFlags(temp);
}

void NifStream( VectorFlags const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned short)(val), out, info );
}

ostream & operator<<( ostream & out, VectorFlags const & val ) {
	switch ( val ) {
		case VF_UV_1: return out << "VF_UV_1";
		case VF_UV_2: return out << "VF_UV_2";
		case VF_UV_4: return out << "VF_UV_4";
		case VF_UV_8: return out << "VF_UV_8";
		case VF_UV_16: return out << "VF_UV_16";
		case VF_UV_32: return out << "VF_UV_32";
		case VF_UNK64: return out << "VF_Unk64";
		case VF_UNK128: return out << "VF_Unk128";
		case VF_UNK256: return out << "VF_Unk256";
		case VF_UNK512: return out << "VF_Unk512";
		case VF_UNK1024: return out << "VF_Unk1024";
		case VF_UNK2048: return out << "VF_Unk2048";
		case VF_HAS_TANGENTS: return out << "VF_Has_Tangents";
		case VF_UNK8192: return out << "VF_Unk8192";
		case VF_UNK16384: return out << "VF_Unk16384";
		case VF_UNK32768: return out << "VF_Unk32768";
		default: return out << "Invalid Value! - " << (unsigned short)(val);
	}
}

//--BSShaderFlags--//

void NifStream( BSShaderFlags & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = BSShaderFlags(temp);
}

void NifStream( BSShaderFlags const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, BSShaderFlags const & val ) {
	switch ( val ) {
		case F3SF1_SPECULAR: return out << "F3SF1_Specular";
		case F3SF1_SKINNED: return out << "F3SF1_Skinned";
		case F3SF1_LOWDETAIL: return out << "F3SF1_LowDetail";
		case F3SF1_VERTEX_ALPHA: return out << "F3SF1_Vertex_Alpha";
		case F3SF1_UNKNOWN_1: return out << "F3SF1_Unknown_1";
		case F3SF1_SINGLE_PASS: return out << "F3SF1_Single_Pass";
		case F3SF1_EMPTY: return out << "F3SF1_Empty";
		case F3SF1_ENVIRONMENT_MAPPING: return out << "F3SF1_Environment_Mapping";
		case F3SF1_ALPHA_TEXTURE: return out << "F3SF1_Alpha_Texture";
		case F3SF1_UNKNOWN_2: return out << "F3SF1_Unknown_2";
		case F3SF1_FACEGEN: return out << "F3SF1_FaceGen";
		case F3SF1_PARALLAX_SHADER_INDEX_15: return out << "F3SF1_Parallax_Shader_Index_15";
		case F3SF1_UNKNOWN_3: return out << "F3SF1_Unknown_3";
		case F3SF1_NON_PROJECTIVE_SHADOWS: return out << "F3SF1_Non_Projective_Shadows";
		case F3SF1_UNKNOWN_4: return out << "F3SF1_Unknown_4";
		case F3SF1_REFRACTION: return out << "F3SF1_Refraction";
		case F3SF1_FIRE_REFRACTION: return out << "F3SF1_Fire_Refraction";
		case F3SF1_EYE_ENVIRONMENT_MAPPING: return out << "F3SF1_Eye_Environment_Mapping";
		case F3SF1_HAIR: return out << "F3SF1_Hair";
		case F3SF1_DYNAMIC_ALPHA: return out << "F3SF1_Dynamic_Alpha";
		case F3SF1_LOCALMAP_HIDE_SECRET: return out << "F3SF1_Localmap_Hide_Secret";
		case F3SF1_WINDOW_ENVIRONMENT_MAPPING: return out << "F3SF1_Window_Environment_Mapping";
		case F3SF1_TREE_BILLBOARD: return out << "F3SF1_Tree_Billboard";
		case F3SF1_SHADOW_FRUSTUM: return out << "F3SF1_Shadow_Frustum";
		case F3SF1_MULTIPLE_TEXTURES: return out << "F3SF1_Multiple_Textures";
		case F3SF1_REMAPPABLE_TEXTURES: return out << "F3SF1_Remappable_Textures";
		case F3SF1_DECAL_SINGLE_PASS: return out << "F3SF1_Decal_Single_Pass";
		case F3SF1_DYNAMIC_DECAL_SINGLE_PASS: return out << "F3SF1_Dynamic_Decal_Single_Pass";
		case F3SF1_PARALLAX_OCCULSION: return out << "F3SF1_Parallax_Occulsion";
		case F3SF1_EXTERNAL_EMITTANCE: return out << "F3SF1_External_Emittance";
		case F3SF1_SHADOW_MAP: return out << "F3SF1_Shadow_Map";
		case F3SF1_ZBUFFER_TEST: return out << "F3SF1_ZBuffer_Test";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--FurnitureEntryPoints--//

void NifStream( FurnitureEntryPoints & val, istream& in, const NifInfo & info ) {
	unsigned short temp;
	NifStream( temp, in, info );
	val = FurnitureEntryPoints(temp);
}

void NifStream( FurnitureEntryPoints const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned short)(val), out, info );
}

ostream & operator<<( ostream & out, FurnitureEntryPoints const & val ) {
	switch ( val ) {
		case FRONT: return out << "Front";
		case BEHIND: return out << "Behind";
		case RIGHT: return out << "Right";
		case LEFT: return out << "Left";
		case UP: return out << "Up";
		default: return out << "Invalid Value! - " << (unsigned short)(val);
	}
}

//--AccumFlags--//

void NifStream( AccumFlags & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = AccumFlags(temp);
}

void NifStream( AccumFlags const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, AccumFlags const & val ) {
	switch ( val ) {
		case ACCUM_X_TRANS: return out << "ACCUM_X_TRANS";
		case ACCUM_Y_TRANS: return out << "ACCUM_Y_TRANS";
		case ACCUM_Z_TRANS: return out << "ACCUM_Z_TRANS";
		case ACCUM_X_ROT: return out << "ACCUM_X_ROT";
		case ACCUM_Y_ROT: return out << "ACCUM_Y_ROT";
		case ACCUM_Z_ROT: return out << "ACCUM_Z_ROT";
		case ACCUM_X_FRONT: return out << "ACCUM_X_FRONT";
		case ACCUM_Y_FRONT: return out << "ACCUM_Y_FRONT";
		case ACCUM_Z_FRONT: return out << "ACCUM_Z_FRONT";
		case ACCUM_NEG_FRONT: return out << "ACCUM_NEG_FRONT";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--DataStreamAccess--//

void NifStream( DataStreamAccess & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = DataStreamAccess(temp);
}

void NifStream( DataStreamAccess const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, DataStreamAccess const & val ) {
	switch ( val ) {
		case CPU_READ: return out << "CPU Read";
		case CPU_WRITE_STATIC: return out << "CPU Write Static";
		case CPU_WRITE_MUTABLE: return out << "CPU Write Mutable";
		case CPU_WRITE_VOLATILE: return out << "CPU Write Volatile";
		case GPU_READ: return out << "GPU Read";
		case GPU_WRITE: return out << "GPU Write";
		case CPU_WRITE_STATIC_INITITIALIZED: return out << "CPU Write Static Inititialized";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--BSPartFlag--//

void NifStream( BSPartFlag & val, istream& in, const NifInfo & info ) {
	unsigned short temp;
	NifStream( temp, in, info );
	val = BSPartFlag(temp);
}

void NifStream( BSPartFlag const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned short)(val), out, info );
}

ostream & operator<<( ostream & out, BSPartFlag const & val ) {
	switch ( val ) {
		case PF_EDITOR_VISIBLE: return out << "PF_EDITOR_VISIBLE";
		case PF_START_NET_BONESET: return out << "PF_START_NET_BONESET";
		default: return out << "Invalid Value! - " << (unsigned short)(val);
	}
}

//--LookAtFlags--//

void NifStream( LookAtFlags & val, istream& in, const NifInfo & info ) {
	unsigned short temp;
	NifStream( temp, in, info );
	val = LookAtFlags(temp);
}

void NifStream( LookAtFlags const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned short)(val), out, info );
}

ostream & operator<<( ostream & out, LookAtFlags const & val ) {
	switch ( val ) {
		case LOOK_FLIP: return out << "LOOK_FLIP";
		case LOOK_Y_AXIS: return out << "LOOK_Y_AXIS";
		case LOOK_Z_AXIS: return out << "LOOK_Z_AXIS";
		default: return out << "Invalid Value! - " << (unsigned short)(val);
	}
}

//--BSVectorFlags--//

void NifStream( BSVectorFlags & val, istream& in, const NifInfo & info ) {
	unsigned short temp;
	NifStream( temp, in, info );
	val = BSVectorFlags(temp);
}

void NifStream( BSVectorFlags const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned short)(val), out, info );
}

ostream & operator<<( ostream & out, BSVectorFlags const & val ) {
	switch ( val ) {
		case BSVF_HAS_UV: return out << "BSVF_Has_UV";
		case BSVF_UNK2: return out << "BSVF_Unk2";
		case BSVF_UNK4: return out << "BSVF_Unk4";
		case BSVF_UNK8: return out << "BSVF_Unk8";
		case BSVF_UNK16: return out << "BSVF_Unk16";
		case BSVF_UNK32: return out << "BSVF_Unk32";
		case BSVF_UNK64: return out << "BSVF_Unk64";
		case BSVF_UNK128: return out << "BSVF_Unk128";
		case BSVF_UNK256: return out << "BSVF_Unk256";
		case BSVF_UNK512: return out << "BSVF_Unk512";
		case BSVF_UNK1024: return out << "BSVF_Unk1024";
		case BSVF_UNK2048: return out << "BSVF_Unk2048";
		case BSVF_HAS_TANGENTS: return out << "BSVF_Has_Tangents";
		case BSVF_UNK8192: return out << "BSVF_Unk8192";
		case BSVF_UNK16384: return out << "BSVF_Unk16384";
		case BSVF_UNK32768: return out << "BSVF_Unk32768";
		default: return out << "Invalid Value! - " << (unsigned short)(val);
	}
}

//--Fallout4ShaderPropertyFlags1--//

void NifStream( Fallout4ShaderPropertyFlags1 & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = Fallout4ShaderPropertyFlags1(temp);
}

void NifStream( Fallout4ShaderPropertyFlags1 const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, Fallout4ShaderPropertyFlags1 const & val ) {
	switch ( val ) {
		case F4SF1_SPECULAR: return out << "F4SF1_Specular";
		case F4SF1_SKINNED: return out << "F4SF1_Skinned";
		case F4SF1_TEMP_REFRACTION: return out << "F4SF1_Temp_Refraction";
		case F4SF1_VERTEX_ALPHA: return out << "F4SF1_Vertex_Alpha";
		case F4SF1_GREYSCALETOPALETTE_COLOR: return out << "F4SF1_GreyscaleToPalette_Color";
		case F4SF1_GREYSCALETOPALETTE_ALPHA: return out << "F4SF1_GreyscaleToPalette_Alpha";
		case F4SF1_USE_FALLOFF: return out << "F4SF1_Use_Falloff";
		case F4SF1_ENVIRONMENT_MAPPING: return out << "F4SF1_Environment_Mapping";
		case F4SF1_RGB_FALLOFF: return out << "F4SF1_RGB_Falloff";
		case F4SF1_CAST_SHADOWS: return out << "F4SF1_Cast_Shadows";
		case F4SF1_FACE: return out << "F4SF1_Face";
		case F4SF1_UI_MASK_RECTS: return out << "F4SF1_UI_Mask_Rects";
		case F4SF1_MODEL_SPACE_NORMALS: return out << "F4SF1_Model_Space_Normals";
		case F4SF1_NON_PROJECTIVE_SHADOWS: return out << "F4SF1_Non_Projective_Shadows";
		case F4SF1_LANDSCAPE: return out << "F4SF1_Landscape";
		case F4SF1_REFRACTION: return out << "F4SF1_Refraction";
		case F4SF1_FIRE_REFRACTION: return out << "F4SF1_Fire_Refraction";
		case F4SF1_EYE_ENVIRONMENT_MAPPING: return out << "F4SF1_Eye_Environment_Mapping";
		case F4SF1_HAIR: return out << "F4SF1_Hair";
		case F4SF1_SCREENDOOR_ALPHA_FADE: return out << "F4SF1_Screendoor_Alpha_Fade";
		case F4SF1_LOCALMAP_HIDE_SECRET: return out << "F4SF1_Localmap_Hide_Secret";
		case F4SF1_SKIN_TINT: return out << "F4SF1_Skin_Tint";
		case F4SF1_OWN_EMIT: return out << "F4SF1_Own_Emit";
		case F4SF1_PROJECTED_UV: return out << "F4SF1_Projected_UV";
		case F4SF1_MULTIPLE_TEXTURES: return out << "F4SF1_Multiple_Textures";
		case F4SF1_TESSELLATE: return out << "F4SF1_Tessellate";
		case F4SF1_DECAL: return out << "F4SF1_Decal";
		case F4SF1_DYNAMIC_DECAL: return out << "F4SF1_Dynamic_Decal";
		case F4SF1_CHARACTER_LIGHTING: return out << "F4SF1_Character_Lighting";
		case F4SF1_EXTERNAL_EMITTANCE: return out << "F4SF1_External_Emittance";
		case F4SF1_SOFT_EFFECT: return out << "F4SF1_Soft_Effect";
		case F4SF1_ZBUFFER_TEST: return out << "F4SF1_ZBuffer_Test";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--Fallout4ShaderPropertyFlags2--//

void NifStream( Fallout4ShaderPropertyFlags2 & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = Fallout4ShaderPropertyFlags2(temp);
}

void NifStream( Fallout4ShaderPropertyFlags2 const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, Fallout4ShaderPropertyFlags2 const & val ) {
	switch ( val ) {
		case F4SF2_ZBUFFER_WRITE: return out << "F4SF2_ZBuffer_Write";
		case F4SF2_LOD_LANDSCAPE: return out << "F4SF2_LOD_Landscape";
		case F4SF2_LOD_OBJECTS: return out << "F4SF2_LOD_Objects";
		case F4SF2_NO_FADE: return out << "F4SF2_No_Fade";
		case F4SF2_DOUBLE_SIDED: return out << "F4SF2_Double_Sided";
		case F4SF2_VERTEX_COLORS: return out << "F4SF2_Vertex_Colors";
		case F4SF2_GLOW_MAP: return out << "F4SF2_Glow_Map";
		case F4SF2_TRANSFORM_CHANGED: return out << "F4SF2_Transform_Changed";
		case F4SF2_DISMEMBERMENT_MEATCUFF: return out << "F4SF2_Dismemberment_Meatcuff";
		case F4SF2_TINT: return out << "F4SF2_Tint";
		case F4SF2_GRASS_VERTEX_LIGHTING: return out << "F4SF2_Grass_Vertex_Lighting";
		case F4SF2_GRASS_UNIFORM_SCALE: return out << "F4SF2_Grass_Uniform_Scale";
		case F4SF2_GRASS_FIT_SLOPE: return out << "F4SF2_Grass_Fit_Slope";
		case F4SF2_GRASS_BILLBOARD: return out << "F4SF2_Grass_Billboard";
		case F4SF2_NO_LOD_LAND_BLEND: return out << "F4SF2_No_LOD_Land_Blend";
		case F4SF2_DISMEMBERMENT: return out << "F4SF2_Dismemberment";
		case F4SF2_WIREFRAME: return out << "F4SF2_Wireframe";
		case F4SF2_WEAPON_BLOOD: return out << "F4SF2_Weapon_Blood";
		case F4SF2_HIDE_ON_LOCAL_MAP: return out << "F4SF2_Hide_On_Local_Map";
		case F4SF2_PREMULT_ALPHA: return out << "F4SF2_Premult_Alpha";
		case F4SF2_VATS_TARGET: return out << "F4SF2_VATS_Target";
		case F4SF2_ANISOTROPIC_LIGHTING: return out << "F4SF2_Anisotropic_Lighting";
		case F4SF2_SKEW_SPECULAR_ALPHA: return out << "F4SF2_Skew_Specular_Alpha";
		case F4SF2_MENU_SCREEN: return out << "F4SF2_Menu_Screen";
		case F4SF2_MULTI_LAYER_PARALLAX: return out << "F4SF2_Multi_Layer_Parallax";
		case F4SF2_ALPHA_TEST: return out << "F4SF2_Alpha_Test";
		case F4SF2_GRADIENT_REMAP: return out << "F4SF2_Gradient_Remap";
		case F4SF2_VATS_TARGET_DRAW_ALL: return out << "F4SF2_VATS_Target_Draw_All";
		case F4SF2_PIPBOY_SCREEN: return out << "F4SF2_Pipboy_Screen";
		case F4SF2_TREE_ANIM: return out << "F4SF2_Tree_Anim";
		case F4SF2_EFFECT_LIGHTING: return out << "F4SF2_Effect_Lighting";
		case F4SF2_REFRACTION_WRITES_DEPTH: return out << "F4SF2_Refraction_Writes_Depth";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--NxMaterialFlag--//

void NifStream( NxMaterialFlag & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = NxMaterialFlag(temp);
}

void NifStream( NxMaterialFlag const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, NxMaterialFlag const & val ) {
	switch ( val ) {
		case NX_MF_ANISOTROPIC: return out << "NX_MF_ANISOTROPIC";
		case NX_MF_DUMMY1: return out << "NX_MF_DUMMY1";
		case NX_MF_DUMMY2: return out << "NX_MF_DUMMY2";
		case NX_MF_DUMMY3: return out << "NX_MF_DUMMY3";
		case NX_MF_DISABLE_FRICTION: return out << "NX_MF_DISABLE_FRICTION";
		case NX_MF_DISABLE_STRONG_FRICTION: return out << "NX_MF_DISABLE_STRONG_FRICTION";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--VertexFlags--//

void NifStream( VertexFlags & val, istream& in, const NifInfo & info ) {
	unsigned short temp;
	NifStream( temp, in, info );
	val = VertexFlags(temp);
}

void NifStream( VertexFlags const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned short)(val), out, info );
}

ostream & operator<<( ostream & out, VertexFlags const & val ) {
	switch ( val ) {
		case VF_VERTEX: return out << "VF_Vertex";
		case VF_UVS: return out << "VF_UVs";
		case VF_UVS_2: return out << "VF_UVs_2";
		case VF_NORMALS: return out << "VF_Normals";
		case VF_TANGENTS: return out << "VF_Tangents";
		case VF_VERTEX_COLORS: return out << "VF_Vertex_Colors";
		case VF_SKINNED: return out << "VF_Skinned";
		case VF_LAND_DATA: return out << "VF_Land_Data";
		case VF_EYE_DATA: return out << "VF_Eye_Data";
		case VF_INSTANCE: return out << "VF_Instance";
		case VF_FULL_PRECISION: return out << "VF_Full_Precision";
		default: return out << "Invalid Value! - " << (unsigned short)(val);
	}
}

//--NiSwitchFlags--//

void NifStream( NiSwitchFlags & val, istream& in, const NifInfo & info ) {
	unsigned short temp;
	NifStream( temp, in, info );
	val = NiSwitchFlags(temp);
}

void NifStream( NiSwitchFlags const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned short)(val), out, info );
}

ostream & operator<<( ostream & out, NiSwitchFlags const & val ) {
	switch ( val ) {
		case UPDATEONLYACTIVECHILD: return out << "UpdateOnlyActiveChild";
		case UPDATECONTROLLERS: return out << "UpdateControllers";
		default: return out << "Invalid Value! - " << (unsigned short)(val);
	}
}

//--BSShaderFlags2--//

void NifStream( BSShaderFlags2 & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = BSShaderFlags2(temp);
}

void NifStream( BSShaderFlags2 const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, BSShaderFlags2 const & val ) {
	switch ( val ) {
		case F3SF2_ZBUFFER_WRITE: return out << "F3SF2_ZBuffer_Write";
		case F3SF2_LOD_LANDSCAPE: return out << "F3SF2_LOD_Landscape";
		case F3SF2_LOD_BUILDING: return out << "F3SF2_LOD_Building";
		case F3SF2_NO_FADE: return out << "F3SF2_No_Fade";
		case F3SF2_REFRACTION_TINT: return out << "F3SF2_Refraction_Tint";
		case F3SF2_VERTEX_COLORS: return out << "F3SF2_Vertex_Colors";
		case F3SF2_UNKNOWN1: return out << "F3SF2_Unknown1";
		case F3SF2_1ST_LIGHT_IS_POINT_LIGHT: return out << "F3SF2_1st_Light_is_Point_Light";
		case F3SF2_2ND_LIGHT: return out << "F3SF2_2nd_Light";
		case F3SF2_3RD_LIGHT: return out << "F3SF2_3rd_Light";
		case F3SF2_VERTEX_LIGHTING: return out << "F3SF2_Vertex_Lighting";
		case F3SF2_UNIFORM_SCALE: return out << "F3SF2_Uniform_Scale";
		case F3SF2_FIT_SLOPE: return out << "F3SF2_Fit_Slope";
		case F3SF2_BILLBOARD_AND_ENVMAP_LIGHT_FADE: return out << "F3SF2_Billboard_and_Envmap_Light_Fade";
		case F3SF2_NO_LOD_LAND_BLEND: return out << "F3SF2_No_LOD_Land_Blend";
		case F3SF2_ENVMAP_LIGHT_FADE: return out << "F3SF2_Envmap_Light_Fade";
		case F3SF2_WIREFRAME: return out << "F3SF2_Wireframe";
		case F3SF2_VATS_SELECTION: return out << "F3SF2_VATS_Selection";
		case F3SF2_SHOW_IN_LOCAL_MAP: return out << "F3SF2_Show_in_Local_Map";
		case F3SF2_PREMULT_ALPHA: return out << "F3SF2_Premult_Alpha";
		case F3SF2_SKIP_NORMAL_MAPS: return out << "F3SF2_Skip_Normal_Maps";
		case F3SF2_ALPHA_DECAL: return out << "F3SF2_Alpha_Decal";
		case F3SF2_NO_TRANSPARECNY_MULTISAMPLING: return out << "F3SF2_No_Transparecny_Multisampling";
		case F3SF2_UNKNOWN2: return out << "F3SF2_Unknown2";
		case F3SF2_UNKNOWN3: return out << "F3SF2_Unknown3";
		case F3SF2_UNKNOWN4: return out << "F3SF2_Unknown4";
		case F3SF2_UNKNOWN5: return out << "F3SF2_Unknown5";
		case F3SF2_UNKNOWN6: return out << "F3SF2_Unknown6";
		case F3SF2_UNKNOWN7: return out << "F3SF2_Unknown7";
		case F3SF2_UNKNOWN8: return out << "F3SF2_Unknown8";
		case F3SF2_UNKNOWN9: return out << "F3SF2_Unknown9";
		case F3SF2_UNKNOWN10: return out << "F3SF2_Unknown10";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

//--SkyrimShaderPropertyFlags2--//

void NifStream( SkyrimShaderPropertyFlags2 & val, istream& in, const NifInfo & info ) {
	unsigned int temp;
	NifStream( temp, in, info );
	val = SkyrimShaderPropertyFlags2(temp);
}

void NifStream( SkyrimShaderPropertyFlags2 const & val, ostream& out, const NifInfo & info ) {
	NifStream( (unsigned int)(val), out, info );
}

ostream & operator<<( ostream & out, SkyrimShaderPropertyFlags2 const & val ) {
	switch ( val ) {
		case SLSF2_ZBUFFER_WRITE: return out << "SLSF2_ZBuffer_Write";
		case SLSF2_LOD_LANDSCAPE: return out << "SLSF2_LOD_Landscape";
		case SLSF2_LOD_OBJECTS: return out << "SLSF2_LOD_Objects";
		case SLSF2_NO_FADE: return out << "SLSF2_No_Fade";
		case SLSF2_DOUBLE_SIDED: return out << "SLSF2_Double_Sided";
		case SLSF2_VERTEX_COLORS: return out << "SLSF2_Vertex_Colors";
		case SLSF2_GLOW_MAP: return out << "SLSF2_Glow_Map";
		case SLSF2_ASSUME_SHADOWMASK: return out << "SLSF2_Assume_Shadowmask";
		case SLSF2_PACKED_TANGENT: return out << "SLSF2_Packed_Tangent";
		case SLSF2_MULTI_INDEX_SNOW: return out << "SLSF2_Multi_Index_Snow";
		case SLSF2_VERTEX_LIGHTING: return out << "SLSF2_Vertex_Lighting";
		case SLSF2_UNIFORM_SCALE: return out << "SLSF2_Uniform_Scale";
		case SLSF2_FIT_SLOPE: return out << "SLSF2_Fit_Slope";
		case SLSF2_BILLBOARD: return out << "SLSF2_Billboard";
		case SLSF2_NO_LOD_LAND_BLEND: return out << "SLSF2_No_LOD_Land_Blend";
		case SLSF2_ENVMAP_LIGHT_FADE: return out << "SLSF2_EnvMap_Light_Fade";
		case SLSF2_WIREFRAME: return out << "SLSF2_Wireframe";
		case SLSF2_WEAPON_BLOOD: return out << "SLSF2_Weapon_Blood";
		case SLSF2_HIDE_ON_LOCAL_MAP: return out << "SLSF2_Hide_On_Local_Map";
		case SLSF2_PREMULT_ALPHA: return out << "SLSF2_Premult_Alpha";
		case SLSF2_CLOUD_LOD: return out << "SLSF2_Cloud_LOD";
		case SLSF2_ANISOTROPIC_LIGHTING: return out << "SLSF2_Anisotropic_Lighting";
		case SLSF2_NO_TRANSPARENCY_MULTISAMPLING: return out << "SLSF2_No_Transparency_Multisampling";
		case SLSF2_UNUSED01: return out << "SLSF2_Unused01";
		case SLSF2_MULTI_LAYER_PARALLAX: return out << "SLSF2_Multi_Layer_Parallax";
		case SLSF2_SOFT_LIGHTING: return out << "SLSF2_Soft_Lighting";
		case SLSF2_RIM_LIGHTING: return out << "SLSF2_Rim_Lighting";
		case SLSF2_BACK_LIGHTING: return out << "SLSF2_Back_Lighting";
		case SLSF2_UNUSED02: return out << "SLSF2_Unused02";
		case SLSF2_TREE_ANIM: return out << "SLSF2_Tree_Anim";
		case SLSF2_EFFECT_LIGHTING: return out << "SLSF2_Effect_Lighting";
		case SLSF2_HD_LOD_OBJECTS: return out << "SLSF2_HD_LOD_Objects";
		default: return out << "Invalid Value! - " << (unsigned int)(val);
	}
}

}

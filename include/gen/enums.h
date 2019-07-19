/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _NIF_ENUMS_H_
#define _NIF_ENUMS_H_

#include <iostream>
using namespace std;

namespace Niflib {

/*! Describes the type of gravitational force. */
enum ForceType {
	FORCE_PLANAR = 0, /*!< FORCE_PLANAR */
	FORCE_SPHERICAL = 1, /*!< FORCE_SPHERICAL */
	FORCE_UNKNOWN = 2, /*!< FORCE_UNKNOWN */
};

ostream & operator<<( ostream & out, ForceType const & val );

/*!
 * An unsigned 32-bit integer, describing which color in BSEffectShaderProperty to
 * animate.
 */
enum EffectShaderControlledColor {
	ECSC_EMISSIVE_COLOR = 0, /*!< Emissive Color. */
};

ostream & operator<<( ostream & out, EffectShaderControlledColor const & val );

/*!
 * Describes the various methods that may be used to specify the orientation of the
 * particles.
 */
enum AlignMethod {
	ALIGN_INVALID = 0, /*!< ALIGN_INVALID */
	ALIGN_PER_PARTICLE = 1, /*!< ALIGN_PER_PARTICLE */
	ALIGN_LOCAL_FIXED = 2, /*!< ALIGN_LOCAL_FIXED */
	ALIGN_LOCAL_POSITION = 5, /*!< ALIGN_LOCAL_POSITION */
	ALIGN_LOCAL_VELOCITY = 9, /*!< ALIGN_LOCAL_VELOCITY */
	ALIGN_CAMERA = 16, /*!< ALIGN_CAMERA */
};

ostream & operator<<( ostream & out, AlignMethod const & val );

/*!
 * The collision mode controls the type of collision operation that is to take
 * place for NiCollisionData.
 */
enum CollisionMode {
	CM_USE_OBB = 0, /*!< Use Bounding Box */
	CM_USE_TRI = 1, /*!< Use Triangles */
	CM_USE_ABV = 2, /*!< Use Alternate Bounding Volumes */
	CM_NOTEST = 3, /*!< Indicates that no collision test should be made. */
	CM_USE_NIBOUND = 4, /*!< Use NiBound */
};

ostream & operator<<( ostream & out, CollisionMode const & val );

/*!
 * This is used by the Floodgate kernel to determine which NiPSForceHelpers
 * functions to call.
 */
enum PSForceType {
	FORCE_BOMB = 0, /*!< FORCE_BOMB */
	FORCE_DRAG = 1, /*!< FORCE_DRAG */
	FORCE_AIR_FIELD = 2, /*!< FORCE_AIR_FIELD */
	FORCE_DRAG_FIELD = 3, /*!< FORCE_DRAG_FIELD */
	FORCE_GRAVITY_FIELD = 4, /*!< FORCE_GRAVITY_FIELD */
	FORCE_RADIAL_FIELD = 5, /*!< FORCE_RADIAL_FIELD */
	FORCE_TURBULENCE_FIELD = 6, /*!< FORCE_TURBULENCE_FIELD */
	FORCE_VORTEX_FIELD = 7, /*!< FORCE_VORTEX_FIELD */
	FORCE_GRAVITY = 8, /*!< FORCE_GRAVITY */
};

ostream & operator<<( ostream & out, PSForceType const & val );

/*!
 * Used by NiGeometryData to control the volatility of the mesh.
 *         Consistency Type is masked to only the upper 4 bits (0xF000). Dirty mask
 * is the lower 12 (0x0FFF) but only used at runtime.
 */
enum ConsistencyType {
	CT_MUTABLE = 0x0000, /*!< Mutable Mesh */
	CT_STATIC = 0x4000, /*!< Static Mesh */
	CT_VOLATILE = 0x8000, /*!< Volatile Mesh */
};

ostream & operator<<( ostream & out, ConsistencyType const & val );

/*! Target platform for NiPersistentSrcTextureRendererData (later than 30.1). */
enum PlatformID {
	PLATFORM_ANY = 0, /*!< PLATFORM_ANY */
	PLATFORM_XENON = 1, /*!< PLATFORM_XENON */
	PLATFORM_PS3 = 2, /*!< PLATFORM_PS3 */
	PLATFORM_DX9 = 3, /*!< PLATFORM_DX9 */
	PLATFORM_WII = 4, /*!< PLATFORM_WII */
	PLATFORM_D3D10 = 5, /*!< PLATFORM_D3D10 */
};

ostream & operator<<( ostream & out, PlatformID const & val );

/*!
 * Biped bodypart data used for visibility control of triangles.  Options are
 * Fallout 3, except where marked for Skyrim (uses SBP prefix)
 *         Skyrim BP names are listed only for vanilla names, different creatures
 * have different defnitions for naming.
 */
enum BSDismemberBodyPartType {
	BP_TORSO = 0, /*!< Torso */
	BP_HEAD = 1, /*!< Head */
	BP_HEAD2 = 2, /*!< Head 2 */
	BP_LEFTARM = 3, /*!< Left Arm */
	BP_LEFTARM2 = 4, /*!< Left Arm 2 */
	BP_RIGHTARM = 5, /*!< Right Arm */
	BP_RIGHTARM2 = 6, /*!< Right Arm 2 */
	BP_LEFTLEG = 7, /*!< Left Leg */
	BP_LEFTLEG2 = 8, /*!< Left Leg 2 */
	BP_LEFTLEG3 = 9, /*!< Left Leg 3 */
	BP_RIGHTLEG = 10, /*!< Right Leg */
	BP_RIGHTLEG2 = 11, /*!< Right Leg 2 */
	BP_RIGHTLEG3 = 12, /*!< Right Leg 3 */
	BP_BRAIN = 13, /*!< Brain */
	SBP_30_HEAD = 30, /*!< Skyrim, Head(Human), Body(Atronachs,Beasts), Mask(Dragonpriest) */
	SBP_31_HAIR = 31, /*!< Skyrim, Hair(human), Far(Dragon), Mask2(Dragonpriest),SkinnedFX(Spriggan) */
	SBP_32_BODY = 32, /*!< Skyrim, Main body, extras(Spriggan) */
	SBP_33_HANDS = 33, /*!< Skyrim, Hands L/R, BodyToo(Dragonpriest), Legs(Draugr), Arms(Giant) */
	SBP_34_FOREARMS = 34, /*!< Skyrim, Forearms L/R, Beard(Draugr) */
	SBP_35_AMULET = 35, /*!< Skyrim, Amulet */
	SBP_36_RING = 36, /*!< Skyrim, Ring */
	SBP_37_FEET = 37, /*!< Skyrim, Feet L/R */
	SBP_38_CALVES = 38, /*!< Skyrim, Calves L/R */
	SBP_39_SHIELD = 39, /*!< Skyrim, Shield */
	SBP_40_TAIL = 40, /*!< Skyrim, Tail(Argonian/Khajiit), Skeleton01(Dragon), FX01(AtronachStorm),FXMist (Dragonpriest), Spit(Chaurus,Spider),SmokeFins(IceWraith) */
	SBP_41_LONGHAIR = 41, /*!< Skyrim, Long Hair(Human), Skeleton02(Dragon),FXParticles(Dragonpriest) */
	SBP_42_CIRCLET = 42, /*!< Skyrim, Circlet(Human, MouthFireEffect(Dragon) */
	SBP_43_EARS = 43, /*!< Skyrim, Ears */
	SBP_44_DRAGON_BLOODHEAD_OR_MOD_MOUTH = 44, /*!< Skyrim, Bloodied dragon head, or NPC face/mouth */
	SBP_45_DRAGON_BLOODWINGL_OR_MOD_NECK = 45, /*!< Skyrim, Left Bloodied dragon wing, Saddle(Horse), or NPC cape, scarf, shawl, neck-tie, etc. */
	SBP_46_DRAGON_BLOODWINGR_OR_MOD_CHEST_PRIMARY = 46, /*!< Skyrim, Right Bloodied dragon wing, or NPC chest primary or outergarment */
	SBP_47_DRAGON_BLOODTAIL_OR_MOD_BACK = 47, /*!< Skyrim, Bloodied dragon tail, or NPC backpack/wings/... */
	SBP_48_MOD_MISC1 = 48, /*!< Anything that does not fit in the list */
	SBP_49_MOD_PELVIS_PRIMARY = 49, /*!< Pelvis primary or outergarment */
	SBP_50_DECAPITATEDHEAD = 50, /*!< Skyrim, Decapitated Head */
	SBP_51_DECAPITATE = 51, /*!< Skyrim, Decapitate, neck gore */
	SBP_52_MOD_PELVIS_SECONDARY = 52, /*!< Pelvis secondary or undergarment */
	SBP_53_MOD_LEG_RIGHT = 53, /*!< Leg primary or outergarment or right leg */
	SBP_54_MOD_LEG_LEFT = 54, /*!< Leg secondary or undergarment or left leg */
	SBP_55_MOD_FACE_JEWELRY = 55, /*!< Face alternate or jewelry */
	SBP_56_MOD_CHEST_SECONDARY = 56, /*!< Chest secondary or undergarment */
	SBP_57_MOD_SHOULDER = 57, /*!< Shoulder */
	SBP_58_MOD_ARM_LEFT = 58, /*!< Arm secondary or undergarment or left arm */
	SBP_59_MOD_ARM_RIGHT = 59, /*!< Arm primary or outergarment or right arm */
	SBP_60_MOD_MISC2 = 60, /*!< Anything that does not fit in the list */
	SBP_61_FX01 = 61, /*!< Skyrim, FX01(Humanoid) */
	BP_SECTIONCAP_HEAD = 101, /*!< Section Cap | Head */
	BP_SECTIONCAP_HEAD2 = 102, /*!< Section Cap | Head 2 */
	BP_SECTIONCAP_LEFTARM = 103, /*!< Section Cap | Left Arm */
	BP_SECTIONCAP_LEFTARM2 = 104, /*!< Section Cap | Left Arm 2 */
	BP_SECTIONCAP_RIGHTARM = 105, /*!< Section Cap | Right Arm */
	BP_SECTIONCAP_RIGHTARM2 = 106, /*!< Section Cap | Right Arm 2 */
	BP_SECTIONCAP_LEFTLEG = 107, /*!< Section Cap | Left Leg */
	BP_SECTIONCAP_LEFTLEG2 = 108, /*!< Section Cap | Left Leg 2 */
	BP_SECTIONCAP_LEFTLEG3 = 109, /*!< Section Cap | Left Leg 3 */
	BP_SECTIONCAP_RIGHTLEG = 110, /*!< Section Cap | Right Leg */
	BP_SECTIONCAP_RIGHTLEG2 = 111, /*!< Section Cap | Right Leg 2 */
	BP_SECTIONCAP_RIGHTLEG3 = 112, /*!< Section Cap | Right Leg 3 */
	BP_SECTIONCAP_BRAIN = 113, /*!< Section Cap | Brain */
	SBP_130_HEAD = 130, /*!< Skyrim, Head slot, use on full-face helmets */
	SBP_131_HAIR = 131, /*!< Skyrim, Hair slot 1, use on hoods */
	SBP_141_LONGHAIR = 141, /*!< Skyrim, Hair slot 2, use for longer hair */
	SBP_142_CIRCLET = 142, /*!< Skyrim, Circlet slot 1, use for circlets */
	SBP_143_EARS = 143, /*!< Skyrim, Ear slot */
	SBP_150_DECAPITATEDHEAD = 150, /*!< Skyrim, neck gore on head side */
	BP_TORSOCAP_HEAD = 201, /*!< Torso Cap | Head */
	BP_TORSOCAP_HEAD2 = 202, /*!< Torso Cap | Head 2 */
	BP_TORSOCAP_LEFTARM = 203, /*!< Torso Cap | Left Arm */
	BP_TORSOCAP_LEFTARM2 = 204, /*!< Torso Cap | Left Arm 2 */
	BP_TORSOCAP_RIGHTARM = 205, /*!< Torso Cap | Right Arm */
	BP_TORSOCAP_RIGHTARM2 = 206, /*!< Torso Cap | Right Arm 2 */
	BP_TORSOCAP_LEFTLEG = 207, /*!< Torso Cap | Left Leg */
	BP_TORSOCAP_LEFTLEG2 = 208, /*!< Torso Cap | Left Leg 2 */
	BP_TORSOCAP_LEFTLEG3 = 209, /*!< Torso Cap | Left Leg 3 */
	BP_TORSOCAP_RIGHTLEG = 210, /*!< Torso Cap | Right Leg */
	BP_TORSOCAP_RIGHTLEG2 = 211, /*!< Torso Cap | Right Leg 2 */
	BP_TORSOCAP_RIGHTLEG3 = 212, /*!< Torso Cap | Right Leg 3 */
	BP_TORSOCAP_BRAIN = 213, /*!< Torso Cap | Brain */
	SBP_230_HEAD = 230, /*!< Skyrim, Head slot, use for neck on character head */
	BP_TORSOSECTION_HEAD = 1000, /*!< Torso Section | Head */
	BP_TORSOSECTION_HEAD2 = 2000, /*!< Torso Section | Head 2 */
	BP_TORSOSECTION_LEFTARM = 3000, /*!< Torso Section | Left Arm */
	BP_TORSOSECTION_LEFTARM2 = 4000, /*!< Torso Section | Left Arm 2 */
	BP_TORSOSECTION_RIGHTARM = 5000, /*!< Torso Section | Right Arm */
	BP_TORSOSECTION_RIGHTARM2 = 6000, /*!< Torso Section | Right Arm 2 */
	BP_TORSOSECTION_LEFTLEG = 7000, /*!< Torso Section | Left Leg */
	BP_TORSOSECTION_LEFTLEG2 = 8000, /*!< Torso Section | Left Leg 2 */
	BP_TORSOSECTION_LEFTLEG3 = 9000, /*!< Torso Section | Left Leg 3 */
	BP_TORSOSECTION_RIGHTLEG = 10000, /*!< Torso Section | Right Leg */
	BP_TORSOSECTION_RIGHTLEG2 = 11000, /*!< Torso Section | Right Leg 2 */
	BP_TORSOSECTION_RIGHTLEG3 = 12000, /*!< Torso Section | Right Leg 3 */
	BP_TORSOSECTION_BRAIN = 13000, /*!< Torso Section | Brain */
};

ostream & operator<<( ostream & out, BSDismemberBodyPartType const & val );

/*!
 * Bethesda Havok. Describes the collision layer a body belongs to in Fallout 3 and
 * Fallout NV.
 */
enum Fallout3Layer {
	FOL_UNIDENTIFIED = 0, /*!< Unidentified (white) */
	FOL_STATIC = 1, /*!< Static (red) */
	FOL_ANIM_STATIC = 2, /*!< AnimStatic (magenta) */
	FOL_TRANSPARENT = 3, /*!< Transparent (light pink) */
	FOL_CLUTTER = 4, /*!< Clutter (light blue) */
	FOL_WEAPON = 5, /*!< Weapon (orange) */
	FOL_PROJECTILE = 6, /*!< Projectile (light orange) */
	FOL_SPELL = 7, /*!< Spell (cyan) */
	FOL_BIPED = 8, /*!< Biped (green) Seems to apply to all creatures/NPCs */
	FOL_TREES = 9, /*!< Trees (light brown) */
	FOL_PROPS = 10, /*!< Props (magenta) */
	FOL_WATER = 11, /*!< Water (cyan) */
	FOL_TRIGGER = 12, /*!< Trigger (light grey) */
	FOL_TERRAIN = 13, /*!< Terrain (light yellow) */
	FOL_TRAP = 14, /*!< Trap (light grey) */
	FOL_NONCOLLIDABLE = 15, /*!< NonCollidable (white) */
	FOL_CLOUD_TRAP = 16, /*!< CloudTrap (greenish grey) */
	FOL_GROUND = 17, /*!< Ground (none) */
	FOL_PORTAL = 18, /*!< Portal (green) */
	FOL_DEBRIS_SMALL = 19, /*!< DebrisSmall (white) */
	FOL_DEBRIS_LARGE = 20, /*!< DebrisLarge (white) */
	FOL_ACOUSTIC_SPACE = 21, /*!< AcousticSpace (white) */
	FOL_ACTORZONE = 22, /*!< Actorzone (white) */
	FOL_PROJECTILEZONE = 23, /*!< Projectilezone (white) */
	FOL_GASTRAP = 24, /*!< GasTrap (yellowish green) */
	FOL_SHELLCASING = 25, /*!< ShellCasing (white) */
	FOL_TRANSPARENT_SMALL = 26, /*!< TransparentSmall (white) */
	FOL_INVISIBLE_WALL = 27, /*!< InvisibleWall (white) */
	FOL_TRANSPARENT_SMALL_ANIM = 28, /*!< TransparentSmallAnim (white) */
	FOL_DEADBIP = 29, /*!< Dead Biped (green) */
	FOL_CHARCONTROLLER = 30, /*!< CharController (yellow) */
	FOL_AVOIDBOX = 31, /*!< Avoidbox (orange) */
	FOL_COLLISIONBOX = 32, /*!< Collisionbox (white) */
	FOL_CAMERASPHERE = 33, /*!< Camerasphere (white) */
	FOL_DOORDETECTION = 34, /*!< Doordetection (white) */
	FOL_CAMERAPICK = 35, /*!< Camerapick (white) */
	FOL_ITEMPICK = 36, /*!< Itempick (white) */
	FOL_LINEOFSIGHT = 37, /*!< LineOfSight (white) */
	FOL_PATHPICK = 38, /*!< Pathpick (white) */
	FOL_CUSTOMPICK1 = 39, /*!< Custompick1 (white) */
	FOL_CUSTOMPICK2 = 40, /*!< Custompick2 (white) */
	FOL_SPELLEXPLOSION = 41, /*!< SpellExplosion (white) */
	FOL_DROPPINGPICK = 42, /*!< Droppingpick (white) */
	FOL_NULL = 43, /*!< Null (white) */
};

ostream & operator<<( ostream & out, Fallout3Layer const & val );

enum InterpBlendFlags {
	MANAGER_CONTROLLED = 1, /*!< MANAGER_CONTROLLED */
};

ostream & operator<<( ostream & out, InterpBlendFlags const & val );

enum EndianType {
	ENDIAN_BIG = 0, /*!< The numbers are stored in big endian format, such as those used by PowerPC Mac processors. */
	ENDIAN_LITTLE = 1, /*!< The numbers are stored in little endian format, such as those used by Intel and AMD x86 processors. */
};

ostream & operator<<( ostream & out, EndianType const & val );

/*!
 * Controls the way the a particle mesh emitter determines the starting speed and
 * direction of the particles that are emitted.
 */
enum VelocityType {
	VELOCITY_USE_NORMALS = 0, /*!< Uses the normals of the meshes to determine staring velocity. */
	VELOCITY_USE_RANDOM = 1, /*!< Starts particles with a random velocity. */
	VELOCITY_USE_DIRECTION = 2, /*!< Uses the emission axis to determine initial particle direction? */
};

ostream & operator<<( ostream & out, VelocityType const & val );

/*!
 * Bethesda Animation. Animation type used on this position. This specifies the
 * function of this position.
 */
enum AnimationType {
	SIT = 1, /*!< Actor use sit animation. */
	SLEEP = 2, /*!< Actor use sleep animation. */
	LEAN = 4, /*!< Used for lean animations? */
};

ostream & operator<<( ostream & out, AnimationType const & val );

/*! Anim note types. */
enum AnimNoteType {
	ANT_INVALID = 0, /*!< ANT_INVALID */
	ANT_GRABIK = 1, /*!< ANT_GRABIK */
	ANT_LOOKIK = 2, /*!< ANT_LOOKIK */
};

ostream & operator<<( ostream & out, AnimNoteType const & val );

/*! Determines how the raw image data is stored in NiRawImageData. */
enum ImageType {
	RGB = 1, /*!< Colors store red, blue, and green components. */
	RGBA = 2, /*!< Colors store red, blue, green, and alpha components. */
};

ostream & operator<<( ostream & out, ImageType const & val );

enum NxD6JointMotion {
	NX_D6JOINT_MOTION_LOCKED = 0, /*!< NX_D6JOINT_MOTION_LOCKED */
	NX_D6JOINT_MOTION_LIMITED = 1, /*!< NX_D6JOINT_MOTION_LIMITED */
	NX_D6JOINT_MOTION_FREE = 2, /*!< NX_D6JOINT_MOTION_FREE */
};

ostream & operator<<( ostream & out, NxD6JointMotion const & val );

/*! Describes stencil buffer test modes for NiStencilProperty. */
enum StencilCompareMode {
	TEST_NEVER = 0, /*!< Always false. Ref value is ignored. */
	TEST_LESS = 1, /*!< VRef ‹ VBuf */
	TEST_EQUAL = 2, /*!< VRef = VBuf */
	TEST_LESS_EQUAL = 3, /*!< VRef ≤ VBuf */
	TEST_GREATER = 4, /*!< VRef › VBuf */
	TEST_NOT_EQUAL = 5, /*!< VRef ≠ VBuf */
	TEST_GREATER_EQUAL = 6, /*!< VRef ≥ VBuf */
	TEST_ALWAYS = 7, /*!< Always true. Buffer is ignored. */
};

ostream & operator<<( ostream & out, StencilCompareMode const & val );

/*!
 * An unsigned 32-bit integer, describing which float variable in
 * BSEffectShaderProperty to animate.
 */
enum EffectShaderControlledVariable {
	ESCV_EMISSIVEMULTIPLE = 0, /*!< EmissiveMultiple. */
	ESCV_FALLOFF_START_ANGLE = 1, /*!< Falloff Start Angle (degrees). */
	ESCV_FALLOFF_STOP_ANGLE = 2, /*!< Falloff Stop Angle (degrees). */
	ESCV_FALLOFF_START_OPACITY = 3, /*!< Falloff Start Opacity. */
	ESCV_FALLOFF_STOP_OPACITY = 4, /*!< Falloff Stop Opacity. */
	ESCV_ALPHA_TRANSPARENCY = 5, /*!< Alpha Transparency (Emissive alpha?). */
	ESCV_U_OFFSET = 6, /*!< U Offset. */
	ESCV_U_SCALE = 7, /*!< U Scale. */
	ESCV_V_OFFSET = 8, /*!< V Offset. */
	ESCV_V_SCALE = 9, /*!< V Scale. */
};

ostream & operator<<( ostream & out, EffectShaderControlledVariable const & val );

/*!
 * Describes the availiable texture filter modes, i.e. the way the pixels in a
 * texture are displayed on screen.
 */
enum TexFilterMode {
	FILTER_NEAREST = 0, /*!< Nearest neighbor. Uses nearest texel with no mipmapping. */
	FILTER_BILERP = 1, /*!< Bilinear. Linear interpolation with no mipmapping. */
	FILTER_TRILERP = 2, /*!< Trilinear. Linear intepolation between 8 texels (4 nearest texels between 2 nearest mip levels). */
	FILTER_NEAREST_MIPNEAREST = 3, /*!< Nearest texel on nearest mip level. */
	FILTER_NEAREST_MIPLERP = 4, /*!< Linear interpolates nearest texel between two nearest mip levels. */
	FILTER_BILERP_MIPNEAREST = 5, /*!< Linear interpolates on nearest mip level. */
	FILTER_ANISOTROPIC = 6, /*!< Anisotropic filtering. One or many trilinear samples depending on anisotropy. */
};

ostream & operator<<( ostream & out, TexFilterMode const & val );

/*! Describes the symmetry type of bomb forces. */
enum SymmetryType {
	SPHERICAL_SYMMETRY = 0, /*!< Spherical Symmetry. */
	CYLINDRICAL_SYMMETRY = 1, /*!< Cylindrical Symmetry. */
	PLANAR_SYMMETRY = 2, /*!< Planar Symmetry. */
};

ostream & operator<<( ostream & out, SymmetryType const & val );

/*!
 * Describes which lighting equation components influence the final vertex color
 * for NiVertexColorProperty.
 */
enum LightMode {
	LIGHT_MODE_EMISSIVE = 0, /*!< Emissive. */
	LIGHT_MODE_EMI_AMB_DIF = 1, /*!< Emissive + Ambient + Diffuse. (Default) */
};

ostream & operator<<( ostream & out, LightMode const & val );

/*! Describes how mipmaps are handled in an NiTexture. */
enum MipMapFormat {
	MIP_FMT_NO = 0, /*!< Texture does not use mip maps. */
	MIP_FMT_YES = 1, /*!< Texture uses mip maps. */
	MIP_FMT_DEFAULT = 2, /*!< Use default setting. */
};

ostream & operator<<( ostream & out, MipMapFormat const & val );

/*!
 * This is used by the Floodgate kernel to determine which NiPSColliderHelpers
 * functions to call.
 */
enum ColliderType {
	COLLIDER_PLANAR = 0, /*!< COLLIDER_PLANAR */
	COLLIDER_SPHERICAL = 1, /*!< COLLIDER_SPHERICAL */
};

ostream & operator<<( ostream & out, ColliderType const & val );

/*!
 * Describes the actions which can occur as a result of tests for
 * NiStencilProperty.
 */
enum StencilAction {
	ACTION_KEEP = 0, /*!< Keep the current value in the stencil buffer. */
	ACTION_ZERO = 1, /*!< Write zero to the stencil buffer. */
	ACTION_REPLACE = 2, /*!< Write the reference value to the stencil buffer. */
	ACTION_INCREMENT = 3, /*!< Increment the value in the stencil buffer. */
	ACTION_DECREMENT = 4, /*!< Decrement the value in the stencil buffer. */
	ACTION_INVERT = 5, /*!< Bitwise invert the value in the stencil buffer. */
};

ostream & operator<<( ostream & out, StencilAction const & val );

/*! A sync point corresponds to a particular stage in per-frame processing. */
enum SyncPoint {
	SYNC_ANY = 0x8000, /*!< Synchronize for any sync points that the modifier supports. */
	SYNC_UPDATE = 0x8010, /*!< Synchronize when an object is updated. */
	SYNC_POST_UPDATE = 0x8020, /*!< Synchronize when an entire scene graph has been updated. */
	SYNC_VISIBLE = 0x8030, /*!< Synchronize when an object is determined to be potentially visible. */
	SYNC_RENDER = 0x8040, /*!< Synchronize when an object is rendered. */
	SYNC_PHYSICS_SIMULATE = 0x8050, /*!< Synchronize when a physics simulation step is about to begin. */
	SYNC_PHYSICS_COMPLETED = 0x8060, /*!< Synchronize when a physics simulation step has produced results. */
	SYNC_REFLECTIONS = 0x8070, /*!< Synchronize after all data necessary to calculate reflections is ready. */
};

ostream & operator<<( ostream & out, SyncPoint const & val );

/*! The type of texture. */
enum TexType {
	BASE_MAP = 0, /*!< The basic texture used by most meshes. */
	DARK_MAP = 1, /*!< Used to darken the model with false lighting. */
	DETAIL_MAP = 2, /*!< Combined with base map for added detail.  Usually tiled over the mesh many times for close-up view. */
	GLOSS_MAP = 3, /*!< Allows the specularity (glossyness) of an object to differ across its surface. */
	GLOW_MAP = 4, /*!< Creates a glowing effect.  Basically an incandescence map. */
	BUMP_MAP = 5, /*!< Used to make the object appear to have more detail than it really does. */
	NORMAL_MAP = 6, /*!< Used to make the object appear to have more detail than it really does. */
	PARALLAX_MAP = 7, /*!< Parallax map. */
	DECAL_0_MAP = 8, /*!< For placing images on the object like stickers. */
	DECAL_1_MAP = 9, /*!< For placing images on the object like stickers. */
	DECAL_2_MAP = 10, /*!< For placing images on the object like stickers. */
	DECAL_3_MAP = 11, /*!< For placing images on the object like stickers. */
};

ostream & operator<<( ostream & out, TexType const & val );

enum NxCombineMode {
	NX_CM_AVERAGE = 0, /*!< NX_CM_AVERAGE */
	NX_CM_MIN = 1, /*!< NX_CM_MIN */
	NX_CM_MULTIPLY = 2, /*!< NX_CM_MULTIPLY */
	NX_CM_MAX = 3, /*!< NX_CM_MAX */
};

ostream & operator<<( ostream & out, NxCombineMode const & val );

/*! Sets how objects are to be cloned. */
enum CloningBehavior {
	CLONING_SHARE = 0, /*!< Share this object pointer with the newly cloned scene. */
	CLONING_COPY = 1, /*!< Create an exact duplicate of this object for use with the newly cloned scene. */
	CLONING_BLANK_COPY = 2, /*!< Create a copy of this object for use with the newly cloned stream, leaving some of the data to be written later. */
};

ostream & operator<<( ostream & out, CloningBehavior const & val );

/*! Culling modes for multi bound nodes. */
enum BSCPCullingType {
	BSCP_CULL_NORMAL = 0, /*!< Normal */
	BSCP_CULL_ALLPASS = 1, /*!< All Pass */
	BSCP_CULL_ALLFAIL = 2, /*!< All Fail */
	BSCP_CULL_IGNOREMULTIBOUNDS = 3, /*!< Ignore Multi Bounds */
	BSCP_CULL_FORCEMULTIBOUNDSNOUPDATE = 4, /*!< Force Multi Bounds No Update */
};

ostream & operator<<( ostream & out, BSCPCullingType const & val );

/*! Bethesda Havok. */
enum hkResponseType {
	RESPONSE_INVALID = 0, /*!< Invalid Response */
	RESPONSE_SIMPLE_CONTACT = 1, /*!< Do normal collision resolution */
	RESPONSE_REPORTING = 2, /*!< No collision resolution is performed but listeners are called */
	RESPONSE_NONE = 3, /*!< Do nothing, ignore all the results. */
};

ostream & operator<<( ostream & out, hkResponseType const & val );

/*!
 * Bethesda Havok, based on hkpRigidBodyCinfo::SolverDeactivation.
 *         A list of possible solver deactivation settings. This value defines how
 * aggressively the solver deactivates objects.
 *         Note: Solver deactivation does not save CPU, but reduces creeping of
 * movable objects in a pile quite dramatically.
 */
enum hkSolverDeactivation {
	SOLVER_DEACTIVATION_INVALID = 0, /*!< Invalid */
	SOLVER_DEACTIVATION_OFF = 1, /*!< No solver deactivation. */
	SOLVER_DEACTIVATION_LOW = 2, /*!< Very conservative deactivation, typically no visible artifacts. */
	SOLVER_DEACTIVATION_MEDIUM = 3, /*!< Normal deactivation, no serious visible artifacts in most cases. */
	SOLVER_DEACTIVATION_HIGH = 4, /*!< Fast deactivation, visible artifacts. */
	SOLVER_DEACTIVATION_MAX = 5, /*!< Very fast deactivation, visible artifacts. */
};

ostream & operator<<( ostream & out, hkSolverDeactivation const & val );

/*! Target renderer for NiPersistentSrcTextureRendererData (until 30.1). */
enum RendererID {
	RENDERER_XBOX360 = 0, /*!< RENDERER_XBOX360 */
	RENDERER_PS3 = 1, /*!< RENDERER_PS3 */
	RENDERER_DX9 = 2, /*!< RENDERER_DX9 */
	RENDERER_D3D10 = 3, /*!< RENDERER_D3D10 */
	RENDERER_WII = 4, /*!< RENDERER_WII */
	RENDERER_GENERIC = 5, /*!< RENDERER_GENERIC */
	RENDERER_D3D11 = 6, /*!< RENDERER_D3D11 */
};

ostream & operator<<( ostream & out, RendererID const & val );

/*!
 * Describes which aspect of the NiTextureTransform the
 * NiTextureTransformController will modify.
 */
enum TransformMember {
	TT_TRANSLATE_U = 0, /*!< Control the translation of the U coordinates. */
	TT_TRANSLATE_V = 1, /*!< Control the translation of the V coordinates. */
	TT_ROTATE = 2, /*!< Control the rotation of the coordinates. */
	TT_SCALE_U = 3, /*!< Control the scale of the U coordinates. */
	TT_SCALE_V = 4, /*!< Control the scale of the V coordinates. */
};

ostream & operator<<( ostream & out, TransformMember const & val );

enum NxD6JointDriveType {
	NX_D6JOINT_DRIVE_POSITION = 1, /*!< NX_D6JOINT_DRIVE_POSITION */
	NX_D6JOINT_DRIVE_VELOCITY = 2, /*!< NX_D6JOINT_DRIVE_VELOCITY */
};

ostream & operator<<( ostream & out, NxD6JointDriveType const & val );

/*!
 * An unsigned 32-bit integer, describing which float variable in
 * BSLightingShaderProperty to animate.
 */
enum LightingShaderControlledVariable {
	LSCV_REFRACTION_STRENGTH = 0, /*!< The amount of distortion. */
	LSCV_ENVIRONMENT_MAP_SCALE = 8, /*!< Environment Map Scale. */
	LSCV_GLOSSINESS = 9, /*!< Glossiness. */
	LSCV_SPECULAR_STRENGTH = 10, /*!< Specular Strength. */
	LSCV_EMISSIVE_MULTIPLE = 11, /*!< Emissive Multiple. */
	LSCV_ALPHA = 12, /*!< Alpha. */
	LSCV_U_OFFSET = 20, /*!< U Offset. */
	LSCV_U_SCALE = 21, /*!< U Scale. */
	LSCV_V_OFFSET = 22, /*!< V Offset. */
	LSCV_V_SCALE = 23, /*!< V Scale. */
};

ostream & operator<<( ostream & out, LightingShaderControlledVariable const & val );

/*!
 * Bethesda Havok.
 *         A byte describing if MOPP Data is organized into chunks (PS3) or not
 * (PC)
 */
enum MoppDataBuildType {
	BUILT_WITH_CHUNK_SUBDIVISION = 0, /*!< Organized in chunks for PS3. */
	BUILT_WITHOUT_CHUNK_SUBDIVISION = 1, /*!< Not organized in chunks for PC. (Default) */
	BUILD_NOT_SET = 2, /*!< Build type not set yet. */
};

ostream & operator<<( ostream & out, MoppDataBuildType const & val );

/*!
 * An unsigned 32-bit integer, describing which color in BSLightingShaderProperty
 * to animate.
 */
enum LightingShaderControlledColor {
	LSCC_SPECULAR_COLOR = 0, /*!< Specular Color. */
	LSCC_EMISSIVE_COLOR = 1, /*!< Emissive Color. */
};

ostream & operator<<( ostream & out, LightingShaderControlledColor const & val );

/*! Bethesda Havok. Describes the collision layer a body belongs to in Oblivion. */
enum OblivionLayer {
	OL_UNIDENTIFIED = 0, /*!< Unidentified (white) */
	OL_STATIC = 1, /*!< Static (red) */
	OL_ANIM_STATIC = 2, /*!< AnimStatic (magenta) */
	OL_TRANSPARENT = 3, /*!< Transparent (light pink) */
	OL_CLUTTER = 4, /*!< Clutter (light blue) */
	OL_WEAPON = 5, /*!< Weapon (orange) */
	OL_PROJECTILE = 6, /*!< Projectile (light orange) */
	OL_SPELL = 7, /*!< Spell (cyan) */
	OL_BIPED = 8, /*!< Biped (green) Seems to apply to all creatures/NPCs */
	OL_TREES = 9, /*!< Trees (light brown) */
	OL_PROPS = 10, /*!< Props (magenta) */
	OL_WATER = 11, /*!< Water (cyan) */
	OL_TRIGGER = 12, /*!< Trigger (light grey) */
	OL_TERRAIN = 13, /*!< Terrain (light yellow) */
	OL_TRAP = 14, /*!< Trap (light grey) */
	OL_NONCOLLIDABLE = 15, /*!< NonCollidable (white) */
	OL_CLOUD_TRAP = 16, /*!< CloudTrap (greenish grey) */
	OL_GROUND = 17, /*!< Ground (none) */
	OL_PORTAL = 18, /*!< Portal (green) */
	OL_STAIRS = 19, /*!< Stairs (white) */
	OL_CHAR_CONTROLLER = 20, /*!< CharController (yellow) */
	OL_AVOID_BOX = 21, /*!< AvoidBox (dark yellow) */
	OL_UNKNOWN1 = 22, /*!< ? (white) */
	OL_UNKNOWN2 = 23, /*!< ? (white) */
	OL_CAMERA_PICK = 24, /*!< CameraPick (white) */
	OL_ITEM_PICK = 25, /*!< ItemPick (white) */
	OL_LINE_OF_SIGHT = 26, /*!< LineOfSight (white) */
	OL_PATH_PICK = 27, /*!< PathPick (white) */
	OL_CUSTOM_PICK_1 = 28, /*!< CustomPick1 (white) */
	OL_CUSTOM_PICK_2 = 29, /*!< CustomPick2 (white) */
	OL_SPELL_EXPLOSION = 30, /*!< SpellExplosion (white) */
	OL_DROPPING_PICK = 31, /*!< DroppingPick (white) */
	OL_OTHER = 32, /*!< Other (white) */
	OL_HEAD = 33, /*!< Head */
	OL_BODY = 34, /*!< Body */
	OL_SPINE1 = 35, /*!< Spine1 */
	OL_SPINE2 = 36, /*!< Spine2 */
	OL_L_UPPER_ARM = 37, /*!< LUpperArm */
	OL_L_FOREARM = 38, /*!< LForeArm */
	OL_L_HAND = 39, /*!< LHand */
	OL_L_THIGH = 40, /*!< LThigh */
	OL_L_CALF = 41, /*!< LCalf */
	OL_L_FOOT = 42, /*!< LFoot */
	OL_R_UPPER_ARM = 43, /*!< RUpperArm */
	OL_R_FOREARM = 44, /*!< RForeArm */
	OL_R_HAND = 45, /*!< RHand */
	OL_R_THIGH = 46, /*!< RThigh */
	OL_R_CALF = 47, /*!< RCalf */
	OL_R_FOOT = 48, /*!< RFoot */
	OL_TAIL = 49, /*!< Tail */
	OL_SIDE_WEAPON = 50, /*!< SideWeapon */
	OL_SHIELD = 51, /*!< Shield */
	OL_QUIVER = 52, /*!< Quiver */
	OL_BACK_WEAPON = 53, /*!< BackWeapon */
	OL_BACK_WEAPON2 = 54, /*!< BackWeapon (?) */
	OL_PONYTAIL = 55, /*!< PonyTail */
	OL_WING = 56, /*!< Wing */
	OL_NULL = 57, /*!< Null */
};

ostream & operator<<( ostream & out, OblivionLayer const & val );

/*! The type of information that is stored in a texture used by an NiTextureEffect. */
enum TextureType {
	TEX_PROJECTED_LIGHT = 0, /*!< Apply a projected light texture. Each light effect is summed before multiplying by the base texture. */
	TEX_PROJECTED_SHADOW = 1, /*!< Apply a projected shadow texture. Each shadow effect is multiplied by the base texture. */
	TEX_ENVIRONMENT_MAP = 2, /*!< Apply an environment map texture. Added to the base texture and light/shadow/decal maps. */
	TEX_FOG_MAP = 3, /*!< Apply a fog map texture. Alpha channel is used to blend the color channel with the base texture. */
};

ostream & operator<<( ostream & out, TextureType const & val );

enum NxJointProjectionMode {
	NX_JPM_NONE = 0, /*!< NX_JPM_NONE */
	NX_JPM_POINT_MINDIST = 1, /*!< NX_JPM_POINT_MINDIST */
	NX_JPM_LINEAR_MINDIST = 2, /*!< NX_JPM_LINEAR_MINDIST */
};

ostream & operator<<( ostream & out, NxJointProjectionMode const & val );

enum BoundVolumeType {
	BASE_BV = 0xffffffff, /*!< Default */
	SPHERE_BV = 0, /*!< Sphere */
	BOX_BV = 1, /*!< Box */
	CAPSULE_BV = 2, /*!< Capsule */
	UNION_BV = 4, /*!< Union */
	HALFSPACE_BV = 5, /*!< Half Space */
};

ostream & operator<<( ostream & out, BoundVolumeType const & val );

enum NxShapeType {
	NX_SHAPE_PLANE = 0, /*!< NX_SHAPE_PLANE */
	NX_SHAPE_SPHERE = 1, /*!< NX_SHAPE_SPHERE */
	NX_SHAPE_BOX = 2, /*!< NX_SHAPE_BOX */
	NX_SHAPE_CAPSULE = 3, /*!< NX_SHAPE_CAPSULE */
	NX_SHAPE_WHEEL = 4, /*!< NX_SHAPE_WHEEL */
	NX_SHAPE_CONVEX = 5, /*!< NX_SHAPE_CONVEX */
	NX_SHAPE_MESH = 6, /*!< NX_SHAPE_MESH */
	NX_SHAPE_HEIGHTFIELD = 7, /*!< NX_SHAPE_HEIGHTFIELD */
	NX_SHAPE_RAW_MESH = 8, /*!< NX_SHAPE_RAW_MESH */
	NX_SHAPE_COMPOUND = 9, /*!< NX_SHAPE_COMPOUND */
};

ostream & operator<<( ostream & out, NxShapeType const & val );

/*! Describes the type of primitives stored in a mesh object. */
enum MeshPrimitiveType {
	MESH_PRIMITIVE_TRIANGLES = 0, /*!< Triangle primitive type. */
	MESH_PRIMITIVE_TRISTRIPS = 1, /*!< Triangle strip primitive type. */
	MESH_PRIMITIVE_LINES = 2, /*!< Lines primitive type. */
	MESH_PRIMITIVE_LINESTRIPS = 3, /*!< Line strip primitive type. */
	MESH_PRIMITIVE_QUADS = 4, /*!< Quadrilateral primitive type. */
	MESH_PRIMITIVE_POINTS = 5, /*!< Point primitive type. */
};

ostream & operator<<( ostream & out, MeshPrimitiveType const & val );

/*! Describes how transparency is handled in an NiTexture. */
enum AlphaFormat {
	ALPHA_NONE = 0, /*!< No alpha. */
	ALPHA_BINARY = 1, /*!< 1-bit alpha. */
	ALPHA_SMOOTH = 2, /*!< Interpolated 4- or 8-bit alpha. */
	ALPHA_DEFAULT = 3, /*!< Use default setting. */
};

ostream & operator<<( ostream & out, AlphaFormat const & val );

/*!
 * Bethesda Havok, based on hkpCollidableQualityType. Describes the priority and
 * quality of collisions for a body,
 *             e.g. you may expect critical game play objects to have solid high-
 * priority collisions so that they never sink into ground,
 *             or may allow penetrations for visual debris objects.
 *         Notes:
 *             - Fixed and keyframed objects cannot interact with each other.
 *             - Debris can interpenetrate but still responds to Bullet hits.
 *             - Critical objects are forced to not interpenetrate.
 *             - Moving objects can interpenetrate slightly with other Moving or
 * Debris objects but nothing else.
 */
enum hkQualityType {
	MO_QUAL_INVALID = 0, /*!< Automatically assigned to MO_QUAL_FIXED, MO_QUAL_KEYFRAMED or MO_QUAL_DEBRIS */
	MO_QUAL_FIXED = 1, /*!< Static body. */
	MO_QUAL_KEYFRAMED = 2, /*!< Animated body with infinite mass. */
	MO_QUAL_DEBRIS = 3, /*!< Low importance bodies adding visual detail. */
	MO_QUAL_MOVING = 4, /*!< Moving bodies which should not penetrate or leave the world, but can. */
	MO_QUAL_CRITICAL = 5, /*!< Gameplay critical bodies which cannot penetrate or leave the world under any circumstance. */
	MO_QUAL_BULLET = 6, /*!< Fast-moving bodies, such as projectiles. */
	MO_QUAL_USER = 7, /*!< For user. */
	MO_QUAL_CHARACTER = 8, /*!< For use with rigid body character controllers. */
	MO_QUAL_KEYFRAMED_REPORT = 9, /*!< Moving bodies with infinite mass which should report contact points and TOI collisions against all other bodies. */
};

ostream & operator<<( ostream & out, hkQualityType const & val );

enum PSLoopBehavior {
	PS_LOOP_CLAMP_BIRTH = 0, /*!< Key times map such that the first key occurs at the birth of the particle, and times later than the last key get the last key value. */
	PS_LOOP_CLAMP_DEATH = 1, /*!< Key times map such that the last key occurs at the death of the particle, and times before the initial key time get the value of the initial key. */
	PS_LOOP_AGESCALE = 2, /*!< Scale the animation to fit the particle lifetime, so that the first key is age zero, and the last key comes at the particle death. */
	PS_LOOP_LOOP = 3, /*!< The time is converted to one within the time range represented by the keys, as if the key sequence loops forever in the past and future. */
	PS_LOOP_REFLECT = 4, /*!< The time is reflection looped, as if the keys played forward then backward the forward then backward etc for all time. */
};

ostream & operator<<( ostream & out, PSLoopBehavior const & val );

/*!
 * The type of animation interpolation (blending) that will be used on the
 * associated key frames.
 */
enum KeyType {
	LINEAR_KEY = 1, /*!< Use linear interpolation. */
	QUADRATIC_KEY = 2, /*!< Use quadratic interpolation.  Forward and back tangents will be stored. */
	TBC_KEY = 3, /*!< Use Tension Bias Continuity interpolation.  Tension, bias, and continuity will be stored. */
	XYZ_ROTATION_KEY = 4, /*!< For use only with rotation data.  Separate X, Y, and Z keys will be stored instead of using quaternions. */
	CONST_KEY = 5, /*!< Step function. Used for visibility keys in NiBoolData. */
};

ostream & operator<<( ostream & out, KeyType const & val );

/*! Describes how to apply vertex colors for NiVertexColorProperty. */
enum VertMode {
	VERT_MODE_SRC_IGNORE = 0, /*!< Emissive, ambient, and diffuse colors are all specified by the NiMaterialProperty. */
	VERT_MODE_SRC_EMISSIVE = 1, /*!< Emissive colors are specified by the source vertex colors. Ambient+Diffuse are specified by the NiMaterialProperty. */
	VERT_MODE_SRC_AMB_DIF = 2, /*!< Ambient+Diffuse colors are specified by the source vertex colors. Emissive is specified by the NiMaterialProperty. (Default) */
};

ostream & operator<<( ostream & out, VertMode const & val );

/*!
 * Describes the way that NiSortAdjustNode modifies the sorting behavior for the
 * subtree below it.
 */
enum SortingMode {
	SORTING_INHERIT = 0, /*!< Inherit. Acts identical to NiNode. */
	SORTING_OFF = 1, /*!< Disables sort on all geometry under this node. */
};

ostream & operator<<( ostream & out, SortingMode const & val );

/*! Bethesda Havok. Material descriptor for a Havok shape in Oblivion. */
enum OblivionHavokMaterial {
	OB_HAV_MAT_STONE = 0, /*!< Stone */
	OB_HAV_MAT_CLOTH = 1, /*!< Cloth */
	OB_HAV_MAT_DIRT = 2, /*!< Dirt */
	OB_HAV_MAT_GLASS = 3, /*!< Glass */
	OB_HAV_MAT_GRASS = 4, /*!< Grass */
	OB_HAV_MAT_METAL = 5, /*!< Metal */
	OB_HAV_MAT_ORGANIC = 6, /*!< Organic */
	OB_HAV_MAT_SKIN = 7, /*!< Skin */
	OB_HAV_MAT_WATER = 8, /*!< Water */
	OB_HAV_MAT_WOOD = 9, /*!< Wood */
	OB_HAV_MAT_HEAVY_STONE = 10, /*!< Heavy Stone */
	OB_HAV_MAT_HEAVY_METAL = 11, /*!< Heavy Metal */
	OB_HAV_MAT_HEAVY_WOOD = 12, /*!< Heavy Wood */
	OB_HAV_MAT_CHAIN = 13, /*!< Chain */
	OB_HAV_MAT_SNOW = 14, /*!< Snow */
	OB_HAV_MAT_STONE_STAIRS = 15, /*!< Stone Stairs */
	OB_HAV_MAT_CLOTH_STAIRS = 16, /*!< Cloth Stairs */
	OB_HAV_MAT_DIRT_STAIRS = 17, /*!< Dirt Stairs */
	OB_HAV_MAT_GLASS_STAIRS = 18, /*!< Glass Stairs */
	OB_HAV_MAT_GRASS_STAIRS = 19, /*!< Grass Stairs */
	OB_HAV_MAT_METAL_STAIRS = 20, /*!< Metal Stairs */
	OB_HAV_MAT_ORGANIC_STAIRS = 21, /*!< Organic Stairs */
	OB_HAV_MAT_SKIN_STAIRS = 22, /*!< Skin Stairs */
	OB_HAV_MAT_WATER_STAIRS = 23, /*!< Water Stairs */
	OB_HAV_MAT_WOOD_STAIRS = 24, /*!< Wood Stairs */
	OB_HAV_MAT_HEAVY_STONE_STAIRS = 25, /*!< Heavy Stone Stairs */
	OB_HAV_MAT_HEAVY_METAL_STAIRS = 26, /*!< Heavy Metal Stairs */
	OB_HAV_MAT_HEAVY_WOOD_STAIRS = 27, /*!< Heavy Wood Stairs */
	OB_HAV_MAT_CHAIN_STAIRS = 28, /*!< Chain Stairs */
	OB_HAV_MAT_SNOW_STAIRS = 29, /*!< Snow Stairs */
	OB_HAV_MAT_ELEVATOR = 30, /*!< Elevator */
	OB_HAV_MAT_RUBBER = 31, /*!< Rubber */
};

ostream & operator<<( ostream & out, OblivionHavokMaterial const & val );

enum MotorType {
	MOTOR_NONE = 0, /*!< MOTOR_NONE */
	MOTOR_POSITION = 1, /*!< MOTOR_POSITION */
	MOTOR_VELOCITY = 2, /*!< MOTOR_VELOCITY */
	MOTOR_SPRING = 3, /*!< MOTOR_SPRING */
};

ostream & operator<<( ostream & out, MotorType const & val );

/*! Describes the pixel format used by the NiPixelData object to store a texture. */
enum PixelComponent {
	PX_COMP_RED = 0, /*!< PX_COMP_RED */
	PX_COMP_GREEN = 1, /*!< PX_COMP_GREEN */
	PX_COMP_BLUE = 2, /*!< PX_COMP_BLUE */
	PX_COMP_ALPHA = 3, /*!< PX_COMP_ALPHA */
	PX_COMP_COMPRESSED = 4, /*!< PX_COMP_COMPRESSED */
	PX_COMP_OFFSET_U = 5, /*!< PX_COMP_OFFSET_U */
	PX_COMP_OFFSET_V = 6, /*!< PX_COMP_OFFSET_V */
	PX_COMP_OFFSET_W = 7, /*!< PX_COMP_OFFSET_W */
	PX_COMP_OFFSET_Q = 8, /*!< PX_COMP_OFFSET_Q */
	PX_COMP_LUMA = 9, /*!< PX_COMP_LUMA */
	PX_COMP_HEIGHT = 10, /*!< PX_COMP_HEIGHT */
	PX_COMP_VECTOR_X = 11, /*!< PX_COMP_VECTOR_X */
	PX_COMP_VECTOR_Y = 12, /*!< PX_COMP_VECTOR_Y */
	PX_COMP_VECTOR_Z = 13, /*!< PX_COMP_VECTOR_Z */
	PX_COMP_PADDING = 14, /*!< PX_COMP_PADDING */
	PX_COMP_INTENSITY = 15, /*!< PX_COMP_INTENSITY */
	PX_COMP_INDEX = 16, /*!< PX_COMP_INDEX */
	PX_COMP_DEPTH = 17, /*!< PX_COMP_DEPTH */
	PX_COMP_STENCIL = 18, /*!< PX_COMP_STENCIL */
	PX_COMP_EMPTY = 19, /*!< PX_COMP_EMPTY */
};

ostream & operator<<( ostream & out, PixelComponent const & val );

/*! Describes how the vertex colors are blended with the filtered texture color. */
enum ApplyMode {
	APPLY_REPLACE = 0, /*!< Replaces existing color */
	APPLY_DECAL = 1, /*!< For placing images on the object like stickers. */
	APPLY_MODULATE = 2, /*!< Modulates existing color. (Default) */
	APPLY_HILIGHT = 3, /*!< PS2 Only.  Function Unknown. */
	APPLY_HILIGHT2 = 4, /*!< Parallax Flag in some Oblivion meshes. */
};

ostream & operator<<( ostream & out, ApplyMode const & val );

/*! Controls which parts of the mesh that the particles are emitted from. */
enum EmitFrom {
	EMIT_FROM_VERTICES = 0, /*!< Emit particles from the vertices of the mesh. */
	EMIT_FROM_FACE_CENTER = 1, /*!< Emit particles from the center of the faces of the mesh. */
	EMIT_FROM_EDGE_CENTER = 2, /*!< Emit particles from the center of the edges of the mesh. */
	EMIT_FROM_FACE_SURFACE = 3, /*!< Perhaps randomly emit particles from anywhere on the faces of the mesh? */
	EMIT_FROM_EDGE_SURFACE = 4, /*!< Perhaps randomly emit particles from anywhere on the edges of the mesh? */
};

ostream & operator<<( ostream & out, EmitFrom const & val );

/*!
 * Determines the way the billboard will react to the camera.
 *         Billboard mode is stored in lowest 3 bits although Oblivion vanilla nifs
 * uses values higher than 7.
 */
enum BillboardMode {
	ALWAYS_FACE_CAMERA = 0, /*!< Align billboard and camera forward vector. Minimized rotation. */
	ROTATE_ABOUT_UP = 1, /*!< Align billboard and camera forward vector while allowing rotation around the up axis. */
	RIGID_FACE_CAMERA = 2, /*!< Align billboard and camera forward vector. Non-minimized rotation. */
	ALWAYS_FACE_CENTER = 3, /*!< Billboard forward vector always faces camera ceneter. Minimized rotation. */
	RIGID_FACE_CENTER = 4, /*!< Billboard forward vector always faces camera ceneter. Non-minimized rotation. */
	BSROTATE_ABOUT_UP = 5, /*!< The billboard will only rotate around its local Z axis (it always stays in its local X-Y plane). */
	ROTATE_ABOUT_UP2 = 9, /*!< The billboard will only rotate around the up axis (same as ROTATE_ABOUT_UP?). */
};

ostream & operator<<( ostream & out, BillboardMode const & val );

/*!
 * Describes Z-buffer test modes for NiZBufferProperty.
 *         "Less than" = closer to camera, "Greater than" = further from camera.
 */
enum ZCompareMode {
	ZCOMP_ALWAYS = 0, /*!< Always true. Buffer is ignored. */
	ZCOMP_LESS = 1, /*!< VRef ‹ VBuf */
	ZCOMP_EQUAL = 2, /*!< VRef = VBuf */
	ZCOMP_LESS_EQUAL = 3, /*!< VRef ≤ VBuf */
	ZCOMP_GREATER = 4, /*!< VRef › VBuf */
	ZCOMP_NOT_EQUAL = 5, /*!< VRef ≠ VBuf */
	ZCOMP_GREATER_EQUAL = 6, /*!< VRef ≥ VBuf */
	ZCOMP_NEVER = 7, /*!< Always false. Ref value is ignored. */
};

ostream & operator<<( ostream & out, ZCompareMode const & val );

/*! Determines the way that UV texture coordinates are generated. */
enum CoordGenType {
	CG_WORLD_PARALLEL = 0, /*!< Use planar mapping. */
	CG_WORLD_PERSPECTIVE = 1, /*!< Use perspective mapping. */
	CG_SPHERE_MAP = 2, /*!< Use spherical mapping. */
	CG_SPECULAR_CUBE_MAP = 3, /*!< Use specular cube mapping. For NiSourceCubeMap only. */
	CG_DIFFUSE_CUBE_MAP = 4, /*!< Use diffuse cube mapping. For NiSourceCubeMap only. */
};

ostream & operator<<( ostream & out, CoordGenType const & val );

/*! Bethesda Havok. Material descriptor for a Havok shape in Skyrim. */
enum SkyrimHavokMaterial {
	SKY_HAV_MAT_BROKEN_STONE = 131151687, /*!< Broken Stone */
	SKY_HAV_MAT_LIGHT_WOOD = 365420259, /*!< Light Wood */
	SKY_HAV_MAT_SNOW = 398949039, /*!< Snow */
	SKY_HAV_MAT_GRAVEL = 428587608, /*!< Gravel */
	SKY_HAV_MAT_MATERIAL_CHAIN_METAL = 438912228, /*!< Material Chain Metal */
	SKY_HAV_MAT_BOTTLE = 493553910, /*!< Bottle */
	SKY_HAV_MAT_WOOD = 500811281, /*!< Wood */
	SKY_HAV_MAT_SKIN = 591247106, /*!< Skin */
	SKY_HAV_MAT_UNKNOWN_617099282 = 617099282, /*!< Unknown in Creation Kit v1.9.32.0. Found in Dawnguard DLC in meshes\dlc01\clutter\dlc01deerskin.nif. */
	SKY_HAV_MAT_BARREL = 732141076, /*!< Barrel */
	SKY_HAV_MAT_MATERIAL_CERAMIC_MEDIUM = 781661019, /*!< Material Ceramic Medium */
	SKY_HAV_MAT_MATERIAL_BASKET = 790784366, /*!< Material Basket */
	SKY_HAV_MAT_ICE = 873356572, /*!< Ice */
	SKY_HAV_MAT_STAIRS_STONE = 899511101, /*!< Stairs Stone */
	SKY_HAV_MAT_WATER = 1024582599, /*!< Water */
	SKY_HAV_MAT_UNKNOWN_1028101969 = 1028101969, /*!< Unknown in Creation Kit v1.6.89.0. Found in actors\draugr\character assets\skeletons.nif. */
	SKY_HAV_MAT_MATERIAL_BLADE_1HAND = 1060167844, /*!< Material Blade 1 Hand */
	SKY_HAV_MAT_MATERIAL_BOOK = 1264672850, /*!< Material Book */
	SKY_HAV_MAT_MATERIAL_CARPET = 1286705471, /*!< Material Carpet */
	SKY_HAV_MAT_SOLID_METAL = 1288358971, /*!< Solid Metal */
	SKY_HAV_MAT_MATERIAL_AXE_1HAND = 1305674443, /*!< Material Axe 1Hand */
	SKY_HAV_MAT_UNKNOWN_1440721808 = 1440721808, /*!< Unknown in Creation Kit v1.6.89.0. Found in armor\draugr\draugrbootsfemale_go.nif or armor\amuletsandrings\amuletgnd.nif. */
	SKY_HAV_MAT_STAIRS_WOOD = 1461712277, /*!< Stairs Wood */
	SKY_HAV_MAT_MUD = 1486385281, /*!< Mud */
	SKY_HAV_MAT_MATERIAL_BOULDER_SMALL = 1550912982, /*!< Material Boulder Small */
	SKY_HAV_MAT_STAIRS_SNOW = 1560365355, /*!< Stairs Snow */
	SKY_HAV_MAT_HEAVY_STONE = 1570821952, /*!< Heavy Stone */
	SKY_HAV_MAT_UNKNOWN_1574477864 = 1574477864, /*!< Unknown in Creation Kit v1.6.89.0. Found in actors\dragon\character assets\skeleton.nif. */
	SKY_HAV_MAT_UNKNOWN_1591009235 = 1591009235, /*!< Unknown in Creation Kit v1.6.89.0. Found in trap objects or clutter\displaycases\displaycaselgangled01.nif or actors\deer\character assets\skeleton.nif. */
	SKY_HAV_MAT_MATERIAL_BOWS_STAVES = 1607128641, /*!< Material Bows Staves */
	SKY_HAV_MAT_MATERIAL_WOOD_AS_STAIRS = 1803571212, /*!< Material Wood As Stairs */
	SKY_HAV_MAT_GRASS = 1848600814, /*!< Grass */
	SKY_HAV_MAT_MATERIAL_BOULDER_LARGE = 1885326971, /*!< Material Boulder Large */
	SKY_HAV_MAT_MATERIAL_STONE_AS_STAIRS = 1886078335, /*!< Material Stone As Stairs */
	SKY_HAV_MAT_MATERIAL_BLADE_2HAND = 2022742644, /*!< Material Blade 2Hand */
	SKY_HAV_MAT_MATERIAL_BOTTLE_SMALL = 2025794648, /*!< Material Bottle Small */
	SKY_HAV_MAT_SAND = 2168343821, /*!< Sand */
	SKY_HAV_MAT_HEAVY_METAL = 2229413539, /*!< Heavy Metal */
	SKY_HAV_MAT_UNKNOWN_2290050264 = 2290050264, /*!< Unknown in Creation Kit v1.9.32.0. Found in Dawnguard DLC in meshes\dlc01\clutter\dlc01sabrecatpelt.nif. */
	SKY_HAV_MAT_DRAGON = 2518321175, /*!< Dragon */
	SKY_HAV_MAT_MATERIAL_BLADE_1HAND_SMALL = 2617944780, /*!< Material Blade 1Hand Small */
	SKY_HAV_MAT_MATERIAL_SKIN_SMALL = 2632367422, /*!< Material Skin Small */
	SKY_HAV_MAT_STAIRS_BROKEN_STONE = 2892392795, /*!< Stairs Broken Stone */
	SKY_HAV_MAT_MATERIAL_SKIN_LARGE = 2965929619, /*!< Material Skin Large */
	SKY_HAV_MAT_ORGANIC = 2974920155, /*!< Organic */
	SKY_HAV_MAT_MATERIAL_BONE = 3049421844, /*!< Material Bone */
	SKY_HAV_MAT_HEAVY_WOOD = 3070783559, /*!< Heavy Wood */
	SKY_HAV_MAT_MATERIAL_CHAIN = 3074114406, /*!< Material Chain */
	SKY_HAV_MAT_DIRT = 3106094762, /*!< Dirt */
	SKY_HAV_MAT_MATERIAL_ARMOR_LIGHT = 3424720541, /*!< Material Armor Light */
	SKY_HAV_MAT_MATERIAL_SHIELD_LIGHT = 3448167928, /*!< Material Shield Light */
	SKY_HAV_MAT_MATERIAL_COIN = 3589100606, /*!< Material Coin */
	SKY_HAV_MAT_MATERIAL_SHIELD_HEAVY = 3702389584, /*!< Material Shield Heavy */
	SKY_HAV_MAT_MATERIAL_ARMOR_HEAVY = 3708432437, /*!< Material Armor Heavy */
	SKY_HAV_MAT_MATERIAL_ARROW = 3725505938, /*!< Material Arrow */
	SKY_HAV_MAT_GLASS = 3739830338, /*!< Glass */
	SKY_HAV_MAT_STONE = 3741512247, /*!< Stone */
	SKY_HAV_MAT_CLOTH = 3839073443, /*!< Cloth */
	SKY_HAV_MAT_MATERIAL_BLUNT_2HAND = 3969592277, /*!< Material Blunt 2Hand */
	SKY_HAV_MAT_UNKNOWN_4239621792 = 4239621792, /*!< Unknown in Creation Kit v1.9.32.0. Found in Dawnguard DLC in meshes\dlc01\prototype\dlc1protoswingingbridge.nif. */
	SKY_HAV_MAT_MATERIAL_BOULDER_MEDIUM = 4283869410, /*!< Material Boulder Medium */
};

ostream & operator<<( ostream & out, SkyrimHavokMaterial const & val );

enum NxJointType {
	NX_JOINT_PRISMATIC = 0, /*!< NX_JOINT_PRISMATIC */
	NX_JOINT_REVOLUTE = 1, /*!< NX_JOINT_REVOLUTE */
	NX_JOINT_CYLINDRICAL = 2, /*!< NX_JOINT_CYLINDRICAL */
	NX_JOINT_SPHERICAL = 3, /*!< NX_JOINT_SPHERICAL */
	NX_JOINT_POINT_ON_LINE = 4, /*!< NX_JOINT_POINT_ON_LINE */
	NX_JOINT_POINT_IN_PLANE = 5, /*!< NX_JOINT_POINT_IN_PLANE */
	NX_JOINT_DISTANCE = 6, /*!< NX_JOINT_DISTANCE */
	NX_JOINT_PULLEY = 7, /*!< NX_JOINT_PULLEY */
	NX_JOINT_FIXED = 8, /*!< NX_JOINT_FIXED */
	NX_JOINT_D6 = 9, /*!< NX_JOINT_D6 */
};

ostream & operator<<( ostream & out, NxJointType const & val );

/*!
 * Bethesda Havok, based on hkpRigidBodyDeactivator::DeactivatorType.
 *         Deactivator Type determines which mechanism Havok will use to classify
 * the body as deactivated.
 */
enum hkDeactivatorType {
	DEACTIVATOR_INVALID = 0, /*!< Invalid */
	DEACTIVATOR_NEVER = 1, /*!< This will force the rigid body to never deactivate. */
	DEACTIVATOR_SPATIAL = 2, /*!< Tells Havok to use a spatial deactivation scheme. This makes use of high and low frequencies of positional motion to determine when deactivation should occur. */
};

ostream & operator<<( ostream & out, hkDeactivatorType const & val );

/*!
 * Bethesda Havok, based on hkpMotion::MotionType. Motion type of a rigid body
 * determines what happens when it is simulated.
 */
enum hkMotionType {
	MO_SYS_INVALID = 0, /*!< Invalid */
	MO_SYS_DYNAMIC = 1, /*!< A fully-simulated, movable rigid body. At construction time the engine checks the input inertia and selects MO_SYS_SPHERE_INERTIA or MO_SYS_BOX_INERTIA as appropriate. */
	MO_SYS_SPHERE_INERTIA = 2, /*!< Simulation is performed using a sphere inertia tensor. */
	MO_SYS_SPHERE_STABILIZED = 3, /*!< This is the same as MO_SYS_SPHERE_INERTIA, except that simulation of the rigid body is "softened". */
	MO_SYS_BOX_INERTIA = 4, /*!< Simulation is performed using a box inertia tensor. */
	MO_SYS_BOX_STABILIZED = 5, /*!< This is the same as MO_SYS_BOX_INERTIA, except that simulation of the rigid body is "softened". */
	MO_SYS_KEYFRAMED = 6, /*!< Simulation is not performed as a normal rigid body. The keyframed rigid body has an infinite mass when viewed by the rest of the system. (used for creatures) */
	MO_SYS_FIXED = 7, /*!< This motion type is used for the static elements of a game scene, e.g. the landscape. Faster than MO_SYS_KEYFRAMED at velocity 0. (used for weapons) */
	MO_SYS_THIN_BOX = 8, /*!< A box inertia motion which is optimized for thin boxes and has less stability problems */
	MO_SYS_CHARACTER = 9, /*!< A specialized motion used for character controllers */
};

ostream & operator<<( ostream & out, hkMotionType const & val );

/*! Describes the color depth in an NiTexture. */
enum PixelLayout {
	PX_LAY_PALETTIZED_8 = 0, /*!< Texture is in 8-bit palettized format. */
	PX_LAY_HIGH_COLOR_16 = 1, /*!< Texture is in 16-bit high color format. */
	PX_LAY_TRUE_COLOR_32 = 2, /*!< Texture is in 32-bit true color format. */
	PX_LAY_COMPRESSED = 3, /*!< Texture is compressed. */
	PX_LAY_BUMPMAP = 4, /*!< Texture is a grayscale bump map. */
	PX_LAY_PALETTIZED_4 = 5, /*!< Texture is in 4-bit palettized format. */
	PX_LAY_DEFAULT = 6, /*!< Use default setting. */
	PX_LAY_SINGLE_COLOR_8 = 7, /*!< PX_LAY_SINGLE_COLOR_8 */
	PX_LAY_SINGLE_COLOR_16 = 8, /*!< PX_LAY_SINGLE_COLOR_16 */
	PX_LAY_SINGLE_COLOR_32 = 9, /*!< PX_LAY_SINGLE_COLOR_32 */
	PX_LAY_DOUBLE_COLOR_32 = 10, /*!< PX_LAY_DOUBLE_COLOR_32 */
	PX_LAY_DOUBLE_COLOR_64 = 11, /*!< PX_LAY_DOUBLE_COLOR_64 */
	PX_LAY_FLOAT_COLOR_32 = 12, /*!< PX_LAY_FLOAT_COLOR_32 */
	PX_LAY_FLOAT_COLOR_64 = 13, /*!< PX_LAY_FLOAT_COLOR_64 */
	PX_LAY_FLOAT_COLOR_128 = 14, /*!< PX_LAY_FLOAT_COLOR_128 */
	PX_LAY_SINGLE_COLOR_4 = 15, /*!< PX_LAY_SINGLE_COLOR_4 */
	PX_LAY_DEPTH_24_X8 = 16, /*!< PX_LAY_DEPTH_24_X8 */
};

ostream & operator<<( ostream & out, PixelLayout const & val );

/*! Bethesda Havok. Describes the type of bhkConstraint. */
enum hkConstraintType {
	BALLANDSOCKET = 0, /*!< A ball and socket constraint. */
	HINGE = 1, /*!< A hinge constraint. */
	LIMITED_HINGE = 2, /*!< A limited hinge constraint. */
	PRISMATIC = 6, /*!< A prismatic constraint. */
	RAGDOLL = 7, /*!< A ragdoll constraint. */
	STIFFSPRING = 8, /*!< A stiff spring constraint. */
	MALLEABLE = 13, /*!< A malleable constraint. */
};

ostream & operator<<( ostream & out, hkConstraintType const & val );

/*!
 * Used by NiLightColorControllers to select which type of color in the controlled
 * object that will be animated.
 */
enum LightColor {
	LC_DIFFUSE = 0, /*!< Control the diffuse color. */
	LC_AMBIENT = 1, /*!< Control the ambient color. */
};

ostream & operator<<( ostream & out, LightColor const & val );

/*!
 * Describes the availiable texture clamp modes, i.e. the behavior of UV mapping
 * outside the [0,1] range.
 */
enum TexClampMode {
	CLAMP_S_CLAMP_T = 0, /*!< Clamp in both directions. */
	CLAMP_S_WRAP_T = 1, /*!< Clamp in the S(U) direction but wrap in the T(V) direction. */
	WRAP_S_CLAMP_T = 2, /*!< Wrap in the S(U) direction but clamp in the T(V) direction. */
	WRAP_S_WRAP_T = 3, /*!< Wrap in both directions. */
};

ostream & operator<<( ostream & out, TexClampMode const & val );

/*! The data format of components. */
enum ComponentFormat {
	F_UNKNOWN = 0x00000000, /*!< Unknown, or don't care, format. */
	F_INT8_1 = 0x00010101, /*!< F_INT8_1 */
	F_INT8_2 = 0x00020102, /*!< F_INT8_2 */
	F_INT8_3 = 0x00030103, /*!< F_INT8_3 */
	F_INT8_4 = 0x00040104, /*!< F_INT8_4 */
	F_UINT8_1 = 0x00010105, /*!< F_UINT8_1 */
	F_UINT8_2 = 0x00020106, /*!< F_UINT8_2 */
	F_UINT8_3 = 0x00030107, /*!< F_UINT8_3 */
	F_UINT8_4 = 0x00040108, /*!< F_UINT8_4 */
	F_NORMINT8_1 = 0x00010109, /*!< F_NORMINT8_1 */
	F_NORMINT8_2 = 0x0002010A, /*!< F_NORMINT8_2 */
	F_NORMINT8_3 = 0x0003010B, /*!< F_NORMINT8_3 */
	F_NORMINT8_4 = 0x0004010C, /*!< F_NORMINT8_4 */
	F_NORMUINT8_1 = 0x0001010D, /*!< F_NORMUINT8_1 */
	F_NORMUINT8_2 = 0x0002010E, /*!< F_NORMUINT8_2 */
	F_NORMUINT8_3 = 0x0003010F, /*!< F_NORMUINT8_3 */
	F_NORMUINT8_4 = 0x00040110, /*!< F_NORMUINT8_4 */
	F_INT16_1 = 0x00010211, /*!< F_INT16_1 */
	F_INT16_2 = 0x00020212, /*!< F_INT16_2 */
	F_INT16_3 = 0x00030213, /*!< F_INT16_3 */
	F_INT16_4 = 0x00040214, /*!< F_INT16_4 */
	F_UINT16_1 = 0x00010215, /*!< F_UINT16_1 */
	F_UINT16_2 = 0x00020216, /*!< F_UINT16_2 */
	F_UINT16_3 = 0x00030217, /*!< F_UINT16_3 */
	F_UINT16_4 = 0x00040218, /*!< F_UINT16_4 */
	F_NORMINT16_1 = 0x00010219, /*!< F_NORMINT16_1 */
	F_NORMINT16_2 = 0x0002021A, /*!< F_NORMINT16_2 */
	F_NORMINT16_3 = 0x0003021B, /*!< F_NORMINT16_3 */
	F_NORMINT16_4 = 0x0004021C, /*!< F_NORMINT16_4 */
	F_NORMUINT16_1 = 0x0001021D, /*!< F_NORMUINT16_1 */
	F_NORMUINT16_2 = 0x0002021E, /*!< F_NORMUINT16_2 */
	F_NORMUINT16_3 = 0x0003021F, /*!< F_NORMUINT16_3 */
	F_NORMUINT16_4 = 0x00040220, /*!< F_NORMUINT16_4 */
	F_INT32_1 = 0x00010421, /*!< F_INT32_1 */
	F_INT32_2 = 0x00020422, /*!< F_INT32_2 */
	F_INT32_3 = 0x00030423, /*!< F_INT32_3 */
	F_INT32_4 = 0x00040424, /*!< F_INT32_4 */
	F_UINT32_1 = 0x00010425, /*!< F_UINT32_1 */
	F_UINT32_2 = 0x00020426, /*!< F_UINT32_2 */
	F_UINT32_3 = 0x00030427, /*!< F_UINT32_3 */
	F_UINT32_4 = 0x00040428, /*!< F_UINT32_4 */
	F_NORMINT32_1 = 0x00010429, /*!< F_NORMINT32_1 */
	F_NORMINT32_2 = 0x0002042A, /*!< F_NORMINT32_2 */
	F_NORMINT32_3 = 0x0003042B, /*!< F_NORMINT32_3 */
	F_NORMINT32_4 = 0x0004042C, /*!< F_NORMINT32_4 */
	F_NORMUINT32_1 = 0x0001042D, /*!< F_NORMUINT32_1 */
	F_NORMUINT32_2 = 0x0002042E, /*!< F_NORMUINT32_2 */
	F_NORMUINT32_3 = 0x0003042F, /*!< F_NORMUINT32_3 */
	F_NORMUINT32_4 = 0x00040430, /*!< F_NORMUINT32_4 */
	F_FLOAT16_1 = 0x00010231, /*!< F_FLOAT16_1 */
	F_FLOAT16_2 = 0x00020232, /*!< F_FLOAT16_2 */
	F_FLOAT16_3 = 0x00030233, /*!< F_FLOAT16_3 */
	F_FLOAT16_4 = 0x00040234, /*!< F_FLOAT16_4 */
	F_FLOAT32_1 = 0x00010435, /*!< F_FLOAT32_1 */
	F_FLOAT32_2 = 0x00020436, /*!< F_FLOAT32_2 */
	F_FLOAT32_3 = 0x00030437, /*!< F_FLOAT32_3 */
	F_FLOAT32_4 = 0x00040438, /*!< F_FLOAT32_4 */
	F_UINT_10_10_10_L1 = 0x00010439, /*!< F_UINT_10_10_10_L1 */
	F_NORMINT_10_10_10_L1 = 0x0001043A, /*!< F_NORMINT_10_10_10_L1 */
	F_NORMINT_11_11_10 = 0x0001043B, /*!< F_NORMINT_11_11_10 */
	F_NORMUINT8_4_BGRA = 0x0004013C, /*!< F_NORMUINT8_4_BGRA */
	F_NORMINT_10_10_10_2 = 0x0001043D, /*!< F_NORMINT_10_10_10_2 */
	F_UINT_10_10_10_2 = 0x0001043E, /*!< F_UINT_10_10_10_2 */
};

ostream & operator<<( ostream & out, ComponentFormat const & val );

/*!
 * The propagation mode controls scene graph traversal during collision detection
 * operations for NiCollisionData.
 */
enum PropagationMode {
	PROPAGATE_ON_SUCCESS = 0, /*!< Propagation only occurs as a result of a successful collision. */
	PROPAGATE_ON_FAILURE = 1, /*!< (Deprecated) Propagation only occurs as a result of a failed collision. */
	PROPAGATE_ALWAYS = 2, /*!< Propagation always occurs regardless of collision result. */
	PROPAGATE_NEVER = 3, /*!< Propagation never occurs regardless of collision result. */
};

ostream & operator<<( ostream & out, PropagationMode const & val );

/*!
 * Bethesda Havok. Material descriptor for a Havok shape in Fallout 3 and Fallout
 * NV.
 */
enum Fallout3HavokMaterial {
	FO_HAV_MAT_STONE = 0, /*!< Stone */
	FO_HAV_MAT_CLOTH = 1, /*!< Cloth */
	FO_HAV_MAT_DIRT = 2, /*!< Dirt */
	FO_HAV_MAT_GLASS = 3, /*!< Glass */
	FO_HAV_MAT_GRASS = 4, /*!< Grass */
	FO_HAV_MAT_METAL = 5, /*!< Metal */
	FO_HAV_MAT_ORGANIC = 6, /*!< Organic */
	FO_HAV_MAT_SKIN = 7, /*!< Skin */
	FO_HAV_MAT_WATER = 8, /*!< Water */
	FO_HAV_MAT_WOOD = 9, /*!< Wood */
	FO_HAV_MAT_HEAVY_STONE = 10, /*!< Heavy Stone */
	FO_HAV_MAT_HEAVY_METAL = 11, /*!< Heavy Metal */
	FO_HAV_MAT_HEAVY_WOOD = 12, /*!< Heavy Wood */
	FO_HAV_MAT_CHAIN = 13, /*!< Chain */
	FO_HAV_MAT_BOTTLECAP = 14, /*!< Bottlecap */
	FO_HAV_MAT_ELEVATOR = 15, /*!< Elevator */
	FO_HAV_MAT_HOLLOW_METAL = 16, /*!< Hollow Metal */
	FO_HAV_MAT_SHEET_METAL = 17, /*!< Sheet Metal */
	FO_HAV_MAT_SAND = 18, /*!< Sand */
	FO_HAV_MAT_BROKEN_CONCRETE = 19, /*!< Broken Concrete */
	FO_HAV_MAT_VEHICLE_BODY = 20, /*!< Vehicle Body */
	FO_HAV_MAT_VEHICLE_PART_SOLID = 21, /*!< Vehicle Part Solid */
	FO_HAV_MAT_VEHICLE_PART_HOLLOW = 22, /*!< Vehicle Part Hollow */
	FO_HAV_MAT_BARREL = 23, /*!< Barrel */
	FO_HAV_MAT_BOTTLE = 24, /*!< Bottle */
	FO_HAV_MAT_SODA_CAN = 25, /*!< Soda Can */
	FO_HAV_MAT_PISTOL = 26, /*!< Pistol */
	FO_HAV_MAT_RIFLE = 27, /*!< Rifle */
	FO_HAV_MAT_SHOPPING_CART = 28, /*!< Shopping Cart */
	FO_HAV_MAT_LUNCHBOX = 29, /*!< Lunchbox */
	FO_HAV_MAT_BABY_RATTLE = 30, /*!< Baby Rattle */
	FO_HAV_MAT_RUBBER_BALL = 31, /*!< Rubber Ball */
	FO_HAV_MAT_STONE_PLATFORM = 32, /*!< Stone */
	FO_HAV_MAT_CLOTH_PLATFORM = 33, /*!< Cloth */
	FO_HAV_MAT_DIRT_PLATFORM = 34, /*!< Dirt */
	FO_HAV_MAT_GLASS_PLATFORM = 35, /*!< Glass */
	FO_HAV_MAT_GRASS_PLATFORM = 36, /*!< Grass */
	FO_HAV_MAT_METAL_PLATFORM = 37, /*!< Metal */
	FO_HAV_MAT_ORGANIC_PLATFORM = 38, /*!< Organic */
	FO_HAV_MAT_SKIN_PLATFORM = 39, /*!< Skin */
	FO_HAV_MAT_WATER_PLATFORM = 40, /*!< Water */
	FO_HAV_MAT_WOOD_PLATFORM = 41, /*!< Wood */
	FO_HAV_MAT_HEAVY_STONE_PLATFORM = 42, /*!< Heavy Stone */
	FO_HAV_MAT_HEAVY_METAL_PLATFORM = 43, /*!< Heavy Metal */
	FO_HAV_MAT_HEAVY_WOOD_PLATFORM = 44, /*!< Heavy Wood */
	FO_HAV_MAT_CHAIN_PLATFORM = 45, /*!< Chain */
	FO_HAV_MAT_BOTTLECAP_PLATFORM = 46, /*!< Bottlecap */
	FO_HAV_MAT_ELEVATOR_PLATFORM = 47, /*!< Elevator */
	FO_HAV_MAT_HOLLOW_METAL_PLATFORM = 48, /*!< Hollow Metal */
	FO_HAV_MAT_SHEET_METAL_PLATFORM = 49, /*!< Sheet Metal */
	FO_HAV_MAT_SAND_PLATFORM = 50, /*!< Sand */
	FO_HAV_MAT_BROKEN_CONCRETE_PLATFORM = 51, /*!< Broken Concrete */
	FO_HAV_MAT_VEHICLE_BODY_PLATFORM = 52, /*!< Vehicle Body */
	FO_HAV_MAT_VEHICLE_PART_SOLID_PLATFORM = 53, /*!< Vehicle Part Solid */
	FO_HAV_MAT_VEHICLE_PART_HOLLOW_PLATFORM = 54, /*!< Vehicle Part Hollow */
	FO_HAV_MAT_BARREL_PLATFORM = 55, /*!< Barrel */
	FO_HAV_MAT_BOTTLE_PLATFORM = 56, /*!< Bottle */
	FO_HAV_MAT_SODA_CAN_PLATFORM = 57, /*!< Soda Can */
	FO_HAV_MAT_PISTOL_PLATFORM = 58, /*!< Pistol */
	FO_HAV_MAT_RIFLE_PLATFORM = 59, /*!< Rifle */
	FO_HAV_MAT_SHOPPING_CART_PLATFORM = 60, /*!< Shopping Cart */
	FO_HAV_MAT_LUNCHBOX_PLATFORM = 61, /*!< Lunchbox */
	FO_HAV_MAT_BABY_RATTLE_PLATFORM = 62, /*!< Baby Rattle */
	FO_HAV_MAT_RUBBER_BALL_PLATFORM = 63, /*!< Rubber Ball */
	FO_HAV_MAT_STONE_STAIRS = 64, /*!< Stone */
	FO_HAV_MAT_CLOTH_STAIRS = 65, /*!< Cloth */
	FO_HAV_MAT_DIRT_STAIRS = 66, /*!< Dirt */
	FO_HAV_MAT_GLASS_STAIRS = 67, /*!< Glass */
	FO_HAV_MAT_GRASS_STAIRS = 68, /*!< Grass */
	FO_HAV_MAT_METAL_STAIRS = 69, /*!< Metal */
	FO_HAV_MAT_ORGANIC_STAIRS = 70, /*!< Organic */
	FO_HAV_MAT_SKIN_STAIRS = 71, /*!< Skin */
	FO_HAV_MAT_WATER_STAIRS = 72, /*!< Water */
	FO_HAV_MAT_WOOD_STAIRS = 73, /*!< Wood */
	FO_HAV_MAT_HEAVY_STONE_STAIRS = 74, /*!< Heavy Stone */
	FO_HAV_MAT_HEAVY_METAL_STAIRS = 75, /*!< Heavy Metal */
	FO_HAV_MAT_HEAVY_WOOD_STAIRS = 76, /*!< Heavy Wood */
	FO_HAV_MAT_CHAIN_STAIRS = 77, /*!< Chain */
	FO_HAV_MAT_BOTTLECAP_STAIRS = 78, /*!< Bottlecap */
	FO_HAV_MAT_ELEVATOR_STAIRS = 79, /*!< Elevator */
	FO_HAV_MAT_HOLLOW_METAL_STAIRS = 80, /*!< Hollow Metal */
	FO_HAV_MAT_SHEET_METAL_STAIRS = 81, /*!< Sheet Metal */
	FO_HAV_MAT_SAND_STAIRS = 82, /*!< Sand */
	FO_HAV_MAT_BROKEN_CONCRETE_STAIRS = 83, /*!< Broken Concrete */
	FO_HAV_MAT_VEHICLE_BODY_STAIRS = 84, /*!< Vehicle Body */
	FO_HAV_MAT_VEHICLE_PART_SOLID_STAIRS = 85, /*!< Vehicle Part Solid */
	FO_HAV_MAT_VEHICLE_PART_HOLLOW_STAIRS = 86, /*!< Vehicle Part Hollow */
	FO_HAV_MAT_BARREL_STAIRS = 87, /*!< Barrel */
	FO_HAV_MAT_BOTTLE_STAIRS = 88, /*!< Bottle */
	FO_HAV_MAT_SODA_CAN_STAIRS = 89, /*!< Soda Can */
	FO_HAV_MAT_PISTOL_STAIRS = 90, /*!< Pistol */
	FO_HAV_MAT_RIFLE_STAIRS = 91, /*!< Rifle */
	FO_HAV_MAT_SHOPPING_CART_STAIRS = 92, /*!< Shopping Cart */
	FO_HAV_MAT_LUNCHBOX_STAIRS = 93, /*!< Lunchbox */
	FO_HAV_MAT_BABY_RATTLE_STAIRS = 94, /*!< Baby Rattle */
	FO_HAV_MAT_RUBBER_BALL_STAIRS = 95, /*!< Rubber Ball */
	FO_HAV_MAT_STONE_STAIRS_PLATFORM = 96, /*!< Stone */
	FO_HAV_MAT_CLOTH_STAIRS_PLATFORM = 97, /*!< Cloth */
	FO_HAV_MAT_DIRT_STAIRS_PLATFORM = 98, /*!< Dirt */
	FO_HAV_MAT_GLASS_STAIRS_PLATFORM = 99, /*!< Glass */
	FO_HAV_MAT_GRASS_STAIRS_PLATFORM = 100, /*!< Grass */
	FO_HAV_MAT_METAL_STAIRS_PLATFORM = 101, /*!< Metal */
	FO_HAV_MAT_ORGANIC_STAIRS_PLATFORM = 102, /*!< Organic */
	FO_HAV_MAT_SKIN_STAIRS_PLATFORM = 103, /*!< Skin */
	FO_HAV_MAT_WATER_STAIRS_PLATFORM = 104, /*!< Water */
	FO_HAV_MAT_WOOD_STAIRS_PLATFORM = 105, /*!< Wood */
	FO_HAV_MAT_HEAVY_STONE_STAIRS_PLATFORM = 106, /*!< Heavy Stone */
	FO_HAV_MAT_HEAVY_METAL_STAIRS_PLATFORM = 107, /*!< Heavy Metal */
	FO_HAV_MAT_HEAVY_WOOD_STAIRS_PLATFORM = 108, /*!< Heavy Wood */
	FO_HAV_MAT_CHAIN_STAIRS_PLATFORM = 109, /*!< Chain */
	FO_HAV_MAT_BOTTLECAP_STAIRS_PLATFORM = 110, /*!< Bottlecap */
	FO_HAV_MAT_ELEVATOR_STAIRS_PLATFORM = 111, /*!< Elevator */
	FO_HAV_MAT_HOLLOW_METAL_STAIRS_PLATFORM = 112, /*!< Hollow Metal */
	FO_HAV_MAT_SHEET_METAL_STAIRS_PLATFORM = 113, /*!< Sheet Metal */
	FO_HAV_MAT_SAND_STAIRS_PLATFORM = 114, /*!< Sand */
	FO_HAV_MAT_BROKEN_CONCRETE_STAIRS_PLATFORM = 115, /*!< Broken Concrete */
	FO_HAV_MAT_VEHICLE_BODY_STAIRS_PLATFORM = 116, /*!< Vehicle Body */
	FO_HAV_MAT_VEHICLE_PART_SOLID_STAIRS_PLATFORM = 117, /*!< Vehicle Part Solid */
	FO_HAV_MAT_VEHICLE_PART_HOLLOW_STAIRS_PLATFORM = 118, /*!< Vehicle Part Hollow */
	FO_HAV_MAT_BARREL_STAIRS_PLATFORM = 119, /*!< Barrel */
	FO_HAV_MAT_BOTTLE_STAIRS_PLATFORM = 120, /*!< Bottle */
	FO_HAV_MAT_SODA_CAN_STAIRS_PLATFORM = 121, /*!< Soda Can */
	FO_HAV_MAT_PISTOL_STAIRS_PLATFORM = 122, /*!< Pistol */
	FO_HAV_MAT_RIFLE_STAIRS_PLATFORM = 123, /*!< Rifle */
	FO_HAV_MAT_SHOPPING_CART_STAIRS_PLATFORM = 124, /*!< Shopping Cart */
	FO_HAV_MAT_LUNCHBOX_STAIRS_PLATFORM = 125, /*!< Lunchbox */
	FO_HAV_MAT_BABY_RATTLE_STAIRS_PLATFORM = 126, /*!< Baby Rattle */
	FO_HAV_MAT_RUBBER_BALL_STAIRS_PLATFORM = 127, /*!< Rubber Ball */
};

ostream & operator<<( ostream & out, Fallout3HavokMaterial const & val );

/*! Determines how a data stream is used? */
enum DataStreamUsage {
	USAGE_VERTEX_INDEX = 0, /*!< USAGE_VERTEX_INDEX */
	USAGE_VERTEX = 1, /*!< USAGE_VERTEX */
	USAGE_SHADER_CONSTANT = 2, /*!< USAGE_SHADER_CONSTANT */
	USAGE_USER = 3, /*!< USAGE_USER */
};

ostream & operator<<( ostream & out, DataStreamUsage const & val );

/*!
 * The type of animation interpolation (blending) that will be used on the
 * associated key frames.
 */
enum BSShaderType {
	SHADER_TALL_GRASS = 0, /*!< Tall Grass Shader */
	SHADER_DEFAULT = 1, /*!< Standard Lighting Shader */
	SHADER_SKY = 10, /*!< Sky Shader */
	SHADER_SKIN = 14, /*!< Skin Shader */
	SHADER_WATER = 17, /*!< Water Shader */
	SHADER_LIGHTING30 = 29, /*!< Lighting 3.0 Shader */
	SHADER_TILE = 32, /*!< Tiled Shader */
	SHADER_NOLIGHTING = 33, /*!< No Lighting Shader */
};

ostream & operator<<( ostream & out, BSShaderType const & val );

enum BroadPhaseType {
	BROAD_PHASE_INVALID = 0, /*!< BROAD_PHASE_INVALID */
	BROAD_PHASE_ENTITY = 1, /*!< BROAD_PHASE_ENTITY */
	BROAD_PHASE_PHANTOM = 2, /*!< BROAD_PHASE_PHANTOM */
	BROAD_PHASE_BORDER = 3, /*!< BROAD_PHASE_BORDER */
};

ostream & operator<<( ostream & out, BroadPhaseType const & val );

/*!
 * Describes the order of scaling and rotation matrices. Translate, Scale,
 * Rotation, Center are from TexDesc.
 *         Back = inverse of Center. FromMaya = inverse of the V axis with a
 * positive translation along V of 1 unit.
 */
enum TransformMethod {
	TM_MAYA_DEPRECATED = 0, /*!< Center * Rotation * Back * Translate * Scale */
	TM_MAX = 1, /*!< Center * Scale * Rotation * Translate * Back */
	TM_MAYA = 2, /*!< Center * Rotation * Back * FromMaya * Translate * Scale */
};

ostream & operator<<( ostream & out, TransformMethod const & val );

/*! Describes the pixel format used by the NiPixelData object to store a texture. */
enum PixelFormat {
	PX_FMT_RGB = 0, /*!< 24-bit RGB. 8 bits per red, blue, and green component. */
	PX_FMT_RGBA = 1, /*!< 32-bit RGB with alpha. 8 bits per red, blue, green, and alpha component. */
	PX_FMT_PAL = 2, /*!< 8-bit palette index. */
	PX_FMT_PALA = 3, /*!< 8-bit palette index with alpha. */
	PX_FMT_DXT1 = 4, /*!< DXT1 compressed texture. */
	PX_FMT_DXT3 = 5, /*!< DXT3 compressed texture. */
	PX_FMT_DXT5 = 6, /*!< DXT5 compressed texture. */
	PX_FMT_RGB24NONINT = 7, /*!< (Deprecated) 24-bit noninterleaved texture, an old PS2 format. */
	PX_FMT_BUMP = 8, /*!< Uncompressed dU/dV gradient bump map. */
	PX_FMT_BUMPLUMA = 9, /*!< Uncompressed dU/dV gradient bump map with luma channel representing shininess. */
	PX_FMT_RENDERSPEC = 10, /*!< Generic descriptor for any renderer-specific format not described by other formats. */
	PX_FMT_1CH = 11, /*!< Generic descriptor for formats with 1 component. */
	PX_FMT_2CH = 12, /*!< Generic descriptor for formats with 2 components. */
	PX_FMT_3CH = 13, /*!< Generic descriptor for formats with 3 components. */
	PX_FMT_4CH = 14, /*!< Generic descriptor for formats with 4 components. */
	PX_FMT_DEPTH_STENCIL = 15, /*!< Indicates the NiPixelFormat is meant to be used on a depth/stencil surface. */
	PX_FMT_UNKNOWN = 16, /*!< PX_FMT_UNKNOWN */
};

ostream & operator<<( ostream & out, PixelFormat const & val );

/*! The animation cyle behavior. */
enum CycleType {
	CYCLE_LOOP = 0, /*!< Loop */
	CYCLE_REVERSE = 1, /*!< Reverse */
	CYCLE_CLAMP = 2, /*!< Clamp */
};

ostream & operator<<( ostream & out, CycleType const & val );

/*! The force field type. */
enum FieldType {
	FIELD_WIND = 0, /*!< Wind (fixed direction) */
	FIELD_POINT = 1, /*!< Point (fixed origin) */
};

ostream & operator<<( ostream & out, FieldType const & val );

/*!
 * Used by NiMaterialColorControllers to select which type of color in the
 * controlled object that will be animated.
 */
enum MaterialColor {
	TC_AMBIENT = 0, /*!< Control the ambient color. */
	TC_DIFFUSE = 1, /*!< Control the diffuse color. */
	TC_SPECULAR = 2, /*!< Control the specular color. */
	TC_SELF_ILLUM = 3, /*!< Control the self illumination color. */
};

ostream & operator<<( ostream & out, MaterialColor const & val );

/*! Describes the face culling options for NiStencilProperty. */
enum StencilDrawMode {
	DRAW_CCW_OR_BOTH = 0, /*!< Application default, chooses between DRAW_CCW or DRAW_BOTH. */
	DRAW_CCW = 1, /*!< Draw only the triangles whose vertices are ordered CCW with respect to the viewer. (Standard behavior) */
	DRAW_CW = 2, /*!< Draw only the triangles whose vertices are ordered CW with respect to the viewer. (Effectively flips faces) */
	DRAW_BOTH = 3, /*!< Draw all triangles, regardless of orientation. (Effectively force double-sided) */
};

ostream & operator<<( ostream & out, StencilDrawMode const & val );

/*! Values for configuring the shader type in a BSLightingShaderProperty */
enum BSLightingShaderPropertyShaderType {
	ST_DEFAULT = 0, /*!< ST_Default */
	ST_ENVIRONMENT_MAP = 1, /*!< Enables EnvMap Mask(TS6), EnvMap Scale */
	ST_GLOW_SHADER = 2, /*!< Enables Glow(TS3) */
	ST_PARALLAX = 3, /*!< Enables Height(TS4) */
	ST_FACE_TINT = 4, /*!< Enables Detail(TS4), Tint(TS7) */
	ST_SKIN_TINT = 5, /*!< Enables Skin Tint Color */
	ST_HAIR_TINT = 6, /*!< Enables Hair Tint Color */
	ST_PARALLAX_OCC = 7, /*!< Enables Height(TS4), Max Passes, Scale. Unimplemented. */
	ST_MULTITEXTURE_LANDSCAPE = 8, /*!< ST_Multitexture Landscape */
	ST_LOD_LANDSCAPE = 9, /*!< ST_LOD Landscape */
	ST_SNOW = 10, /*!< ST_Snow */
	ST_MULTILAYER_PARALLAX = 11, /*!< Enables EnvMap Mask(TS6), Layer(TS7), Parallax Layer Thickness, Parallax Refraction Scale, Parallax Inner Layer U Scale, Parallax Inner Layer V Scale, EnvMap Scale */
	ST_TREE_ANIM = 12, /*!< ST_Tree Anim */
	ST_LOD_OBJECTS = 13, /*!< ST_LOD Objects */
	ST_SPARKLE_SNOW = 14, /*!< Enables SparkleParams */
	ST_LOD_OBJECTS_HD = 15, /*!< ST_LOD Objects HD */
	ST_EYE_ENVMAP = 16, /*!< Enables EnvMap Mask(TS6), Eye EnvMap Scale */
	ST_CLOUD = 17, /*!< ST_Cloud */
	ST_LOD_LANDSCAPE_NOISE = 18, /*!< ST_LOD Landscape Noise */
	ST_MULTITEXTURE_LANDSCAPE_LOD_BLEND = 19, /*!< ST_Multitexture Landscape LOD Blend */
	ST_FO4_DISMEMBERMENT = 20, /*!< ST_FO4 Dismemberment */
};

ostream & operator<<( ostream & out, BSLightingShaderPropertyShaderType const & val );

/*! Describes the decay function of bomb forces. */
enum DecayType {
	DECAY_NONE = 0, /*!< No decay. */
	DECAY_LINEAR = 1, /*!< Linear decay. */
	DECAY_EXPONENTIAL = 2, /*!< Exponential decay. */
};

ostream & operator<<( ostream & out, DecayType const & val );

/*! Describes how each pixel should be accessed on NiPixelFormat. */
enum PixelRepresentation {
	PX_REP_NORM_INT = 0, /*!< PX_REP_NORM_INT */
	PX_REP_HALF = 1, /*!< PX_REP_HALF */
	PX_REP_FLOAT = 2, /*!< PX_REP_FLOAT */
	PX_REP_INDEX = 3, /*!< PX_REP_INDEX */
	PX_REP_COMPRESSED = 4, /*!< PX_REP_COMPRESSED */
	PX_REP_UNKNOWN = 5, /*!< PX_REP_UNKNOWN */
	PX_REP_INT = 6, /*!< PX_REP_INT */
};

ostream & operator<<( ostream & out, PixelRepresentation const & val );

/*!
 * Sets what sky function this object fulfills in BSSkyShaderProperty or
 * SkyShaderProperty.
 */
enum SkyObjectType {
	BSSM_SKY_TEXTURE = 0, /*!< BSSM_Sky_Texture */
	BSSM_SKY_SUNGLARE = 1, /*!< BSSM_Sky_Sunglare */
	BSSM_SKY = 2, /*!< BSSM_Sky */
	BSSM_SKY_CLOUDS = 3, /*!< BSSM_Sky_Clouds */
	BSSM_SKY_STARS = 5, /*!< BSSM_Sky_Stars */
	BSSM_SKY_MOON_STARS_MASK = 7, /*!< BSSM_Sky_Moon_Stars_Mask */
};

ostream & operator<<( ostream & out, SkyObjectType const & val );

/*!
 * Describes whether pixels have been tiled from their standard row-major format to
 * a format optimized for a particular platform.
 */
enum PixelTiling {
	PX_TILE_NONE = 0, /*!< PX_TILE_NONE */
	PX_TILE_XENON = 1, /*!< PX_TILE_XENON */
	PX_TILE_WII = 2, /*!< PX_TILE_WII */
	PX_TILE_NV_SWIZZLED = 3, /*!< PX_TILE_NV_SWIZZLED */
};

ostream & operator<<( ostream & out, PixelTiling const & val );

/*! Bethesda Havok. Describes the collision layer a body belongs to in Skyrim. */
enum SkyrimLayer {
	SKYL_UNIDENTIFIED = 0, /*!< Unidentified */
	SKYL_STATIC = 1, /*!< Static */
	SKYL_ANIMSTATIC = 2, /*!< Anim Static */
	SKYL_TRANSPARENT = 3, /*!< Transparent */
	SKYL_CLUTTER = 4, /*!< Clutter. Object with this layer will float on water surface. */
	SKYL_WEAPON = 5, /*!< Weapon */
	SKYL_PROJECTILE = 6, /*!< Projectile */
	SKYL_SPELL = 7, /*!< Spell */
	SKYL_BIPED = 8, /*!< Biped. Seems to apply to all creatures/NPCs */
	SKYL_TREES = 9, /*!< Trees */
	SKYL_PROPS = 10, /*!< Props */
	SKYL_WATER = 11, /*!< Water */
	SKYL_TRIGGER = 12, /*!< Trigger */
	SKYL_TERRAIN = 13, /*!< Terrain */
	SKYL_TRAP = 14, /*!< Trap */
	SKYL_NONCOLLIDABLE = 15, /*!< NonCollidable */
	SKYL_CLOUD_TRAP = 16, /*!< CloudTrap */
	SKYL_GROUND = 17, /*!< Ground. It seems that produces no sound when collide. */
	SKYL_PORTAL = 18, /*!< Portal */
	SKYL_DEBRIS_SMALL = 19, /*!< Debris Small */
	SKYL_DEBRIS_LARGE = 20, /*!< Debris Large */
	SKYL_ACOUSTIC_SPACE = 21, /*!< Acoustic Space */
	SKYL_ACTORZONE = 22, /*!< Actor Zone */
	SKYL_PROJECTILEZONE = 23, /*!< Projectile Zone */
	SKYL_GASTRAP = 24, /*!< Gas Trap */
	SKYL_SHELLCASING = 25, /*!< Shell Casing */
	SKYL_TRANSPARENT_SMALL = 26, /*!< Transparent Small */
	SKYL_INVISIBLE_WALL = 27, /*!< Invisible Wall */
	SKYL_TRANSPARENT_SMALL_ANIM = 28, /*!< Transparent Small Anim */
	SKYL_WARD = 29, /*!< Ward */
	SKYL_CHARCONTROLLER = 30, /*!< Char Controller */
	SKYL_STAIRHELPER = 31, /*!< Stair Helper */
	SKYL_DEADBIP = 32, /*!< Dead Bip */
	SKYL_BIPED_NO_CC = 33, /*!< Biped No CC */
	SKYL_AVOIDBOX = 34, /*!< Avoid Box */
	SKYL_COLLISIONBOX = 35, /*!< Collision Box */
	SKYL_CAMERASHPERE = 36, /*!< Camera Sphere */
	SKYL_DOORDETECTION = 37, /*!< Door Detection */
	SKYL_CONEPROJECTILE = 38, /*!< Cone Projectile */
	SKYL_CAMERAPICK = 39, /*!< Camera Pick */
	SKYL_ITEMPICK = 40, /*!< Item Pick */
	SKYL_LINEOFSIGHT = 41, /*!< Line of Sight */
	SKYL_PATHPICK = 42, /*!< Path Pick */
	SKYL_CUSTOMPICK1 = 43, /*!< Custom Pick 1 */
	SKYL_CUSTOMPICK2 = 44, /*!< Custom Pick 2 */
	SKYL_SPELLEXPLOSION = 45, /*!< Spell Explosion */
	SKYL_DROPPINGPICK = 46, /*!< Dropping Pick */
	SKYL_NULL = 47, /*!< Null */
};

ostream & operator<<( ostream & out, SkyrimLayer const & val );

/*! Skyrim water shader property flags */
enum SkyrimWaterShaderFlags {
	SWSF1_UNKNOWN0 = 1, /*!< Unknown */
	SWSF1_BYPASS_REFRACTION_MAP = 2, /*!< Bypasses refraction map when set to 1 */
	SWSF1_WATER_TOGGLE = 4, /*!< Main water Layer on/off */
	SWSF1_UNKNOWN3 = 8, /*!< Unknown */
	SWSF1_UNKNOWN4 = 16, /*!< Unknown */
	SWSF1_UNKNOWN5 = 32, /*!< Unknown */
	SWSF1_HIGHLIGHT_LAYER_TOGGLE = 64, /*!< Reflection layer 2 on/off. (is this scene reflection?) */
	SWSF1_ENABLED = 128, /*!< Water layer on/off */
};

ostream & operator<<( ostream & out, SkyrimWaterShaderFlags const & val );

enum PathFlags {
	NIPI_CVDATANEEDSUPDATE = 1, /*!< NIPI_CVDataNeedsUpdate */
	NIPI_CURVETYPEOPEN = 2, /*!< NIPI_CurveTypeOpen */
	NIPI_ALLOWFLIP = 4, /*!< NIPI_AllowFlip */
	NIPI_BANK = 8, /*!< NIPI_Bank */
	NIPI_CONSTANTVELOCITY = 16, /*!< NIPI_ConstantVelocity */
	NIPI_FOLLOW = 32, /*!< NIPI_Follow */
	NIPI_FLIP = 64, /*!< NIPI_Flip */
};

ostream & operator<<( ostream & out, PathFlags const & val );

/*! Skyrim Shader Property Flags 1 */
enum SkyrimShaderPropertyFlags1 {
	SLSF1_SPECULAR = 1, /*!< Enables Specularity */
	SLSF1_SKINNED = 2, /*!< Required For Skinned Meshes. */
	SLSF1_TEMP_REFRACTION = 4, /*!< SLSF1_Temp_Refraction */
	SLSF1_VERTEX_ALPHA = 8, /*!< Enables using alpha component of vertex colors. */
	SLSF1_GREYSCALE_TO_PALETTECOLOR = 16, /*!< in EffectShaderProperty */
	SLSF1_GREYSCALE_TO_PALETTEALPHA = 32, /*!< in EffectShaderProperty */
	SLSF1_USE_FALLOFF = 64, /*!< Use Falloff value in EffectShaderProperty */
	SLSF1_ENVIRONMENT_MAPPING = 128, /*!< Environment mapping (uses Envmap Scale). */
	SLSF1_RECIEVE_SHADOWS = 256, /*!< Object can recieve shadows. */
	SLSF1_CAST_SHADOWS = 512, /*!< Can cast shadows */
	SLSF1_FACEGEN_DETAIL_MAP = 1024, /*!< Use a face detail map in the 4th texture slot. */
	SLSF1_PARALLAX = 2048, /*!< Unused? */
	SLSF1_MODEL_SPACE_NORMALS = 4096, /*!< Use Model space normals and an external Specular Map. */
	SLSF1_NON_PROJECTIVE_SHADOWS = 8192, /*!< SLSF1_Non_Projective_Shadows */
	SLSF1_LANDSCAPE = 16384, /*!< SLSF1_Landscape */
	SLSF1_REFRACTION = 32768, /*!< Use normal map for refraction effect. */
	SLSF1_FIRE_REFRACTION = 65536, /*!< SLSF1_Fire_Refraction */
	SLSF1_EYE_ENVIRONMENT_MAPPING = 131072, /*!< Eye Environment Mapping (Must use the Eye shader and the model must be skinned) */
	SLSF1_HAIR_SOFT_LIGHTING = 262144, /*!< Keeps from going too bright under lights (hair shader only) */
	SLSF1_SCREENDOOR_ALPHA_FADE = 524288, /*!< SLSF1_Screendoor_Alpha_Fade */
	SLSF1_LOCALMAP_HIDE_SECRET = 1048576, /*!< Object and anything it is positioned above will not render on local map view. */
	SLSF1_FACEGEN_RGB_TINT = 2097152, /*!< Use tintmask for Face. */
	SLSF1_OWN_EMIT = 4194304, /*!< Provides its own emittance color. (will not absorb light/ambient color?) */
	SLSF1_PROJECTED_UV = 8388608, /*!< Used for decalling? */
	SLSF1_MULTIPLE_TEXTURES = 16777216, /*!< SLSF1_Multiple_Textures */
	SLSF1_REMAPPABLE_TEXTURES = 33554432, /*!< SLSF1_Remappable_Textures */
	SLSF1_DECAL = 67108864, /*!< SLSF1_Decal */
	SLSF1_DYNAMIC_DECAL = 134217728, /*!< SLSF1_Dynamic_Decal */
	SLSF1_PARALLAX_OCCLUSION = 268435456, /*!< SLSF1_Parallax_Occlusion */
	SLSF1_EXTERNAL_EMITTANCE = 536870912, /*!< SLSF1_External_Emittance */
	SLSF1_SOFT_EFFECT = 1073741824, /*!< SLSF1_Soft_Effect */
	SLSF1_ZBUFFER_TEST = 2147483648, /*!< ZBuffer Test (1=on) */
};

ostream & operator<<( ostream & out, SkyrimShaderPropertyFlags1 const & val );

/*!
 * bhkNiCollisionObject flags. The flags 0x2, 0x100, and 0x200 are not seen in any
 * NIF nor get/set by the engine.
 */
enum bhkCOFlags {
	BHKCO_ACTIVE = 1, /*!< BHKCO_ACTIVE */
	BHKCO_NOTIFY = 4, /*!< BHKCO_NOTIFY */
	BHKCO_SET_LOCAL = 8, /*!< BHKCO_SET_LOCAL */
	BHKCO_DBG_DISPLAY = 16, /*!< BHKCO_DBG_DISPLAY */
	BHKCO_USE_VEL = 32, /*!< BHKCO_USE_VEL */
	BHKCO_RESET = 64, /*!< BHKCO_RESET */
	BHKCO_SYNC_ON_UPDATE = 128, /*!< BHKCO_SYNC_ON_UPDATE */
	BHKCO_ANIM_TARGETED = 1024, /*!< BHKCO_ANIM_TARGETED */
	BHKCO_DISMEMBERED_LIMB = 2048, /*!< BHKCO_DISMEMBERED_LIMB */
};

ostream & operator<<( ostream & out, bhkCOFlags const & val );

/*! Flags for BSValueNode. */
enum BSValueNodeFlags {
	BILLBOARDWORLDZ = 1, /*!< BillboardWorldZ */
	USEPLAYERADJUST = 2, /*!< UsePlayerAdjust */
};

ostream & operator<<( ostream & out, BSValueNodeFlags const & val );

enum VectorFlags {
	VF_UV_1 = 1, /*!< VF_UV_1 */
	VF_UV_2 = 2, /*!< VF_UV_2 */
	VF_UV_4 = 4, /*!< VF_UV_4 */
	VF_UV_8 = 8, /*!< VF_UV_8 */
	VF_UV_16 = 16, /*!< VF_UV_16 */
	VF_UV_32 = 32, /*!< VF_UV_32 */
	VF_UNK64 = 64, /*!< VF_Unk64 */
	VF_UNK128 = 128, /*!< VF_Unk128 */
	VF_UNK256 = 256, /*!< VF_Unk256 */
	VF_UNK512 = 512, /*!< VF_Unk512 */
	VF_UNK1024 = 1024, /*!< VF_Unk1024 */
	VF_UNK2048 = 2048, /*!< VF_Unk2048 */
	VF_HAS_TANGENTS = 4096, /*!< VF_Has_Tangents */
	VF_UNK8192 = 8192, /*!< VF_Unk8192 */
	VF_UNK16384 = 16384, /*!< VF_Unk16384 */
	VF_UNK32768 = 32768, /*!< VF_Unk32768 */
};

ostream & operator<<( ostream & out, VectorFlags const & val );

/*! Shader Property Flags */
enum BSShaderFlags {
	F3SF1_SPECULAR = 1, /*!< Enables Specularity */
	F3SF1_SKINNED = 2, /*!< Required For Skinned Meshes */
	F3SF1_LOWDETAIL = 4, /*!< Lowddetail (seems to use standard diff/norm/spec shader) */
	F3SF1_VERTEX_ALPHA = 8, /*!< Vertex Alpha */
	F3SF1_UNKNOWN_1 = 16, /*!< Unknown */
	F3SF1_SINGLE_PASS = 32, /*!< Single Pass */
	F3SF1_EMPTY = 64, /*!< Unknown */
	F3SF1_ENVIRONMENT_MAPPING = 128, /*!< Environment mapping (uses Envmap Scale) */
	F3SF1_ALPHA_TEXTURE = 256, /*!< Alpha Texture Requires NiAlphaProperty to Enable */
	F3SF1_UNKNOWN_2 = 512, /*!< Unknown */
	F3SF1_FACEGEN = 1024, /*!< FaceGen */
	F3SF1_PARALLAX_SHADER_INDEX_15 = 2048, /*!< Parallax */
	F3SF1_UNKNOWN_3 = 4096, /*!< Unknown/Crash */
	F3SF1_NON_PROJECTIVE_SHADOWS = 8192, /*!< Non-Projective Shadows */
	F3SF1_UNKNOWN_4 = 16384, /*!< Unknown/Crash */
	F3SF1_REFRACTION = 32768, /*!< Refraction (switches on refraction power) */
	F3SF1_FIRE_REFRACTION = 65536, /*!< Fire Refraction (switches on refraction power/period) */
	F3SF1_EYE_ENVIRONMENT_MAPPING = 131072, /*!< Eye Environment Mapping (does not use envmap light fade or envmap scale) */
	F3SF1_HAIR = 262144, /*!< Hair */
	F3SF1_DYNAMIC_ALPHA = 524288, /*!< Dynamic Alpha */
	F3SF1_LOCALMAP_HIDE_SECRET = 1048576, /*!< Localmap Hide Secret */
	F3SF1_WINDOW_ENVIRONMENT_MAPPING = 2097152, /*!< Window Environment Mapping */
	F3SF1_TREE_BILLBOARD = 4194304, /*!< Tree Billboard */
	F3SF1_SHADOW_FRUSTUM = 8388608, /*!< Shadow Frustum */
	F3SF1_MULTIPLE_TEXTURES = 16777216, /*!< Multiple Textures (base diff/norm become null) */
	F3SF1_REMAPPABLE_TEXTURES = 33554432, /*!< usually seen w/texture animation */
	F3SF1_DECAL_SINGLE_PASS = 67108864, /*!< Decal */
	F3SF1_DYNAMIC_DECAL_SINGLE_PASS = 134217728, /*!< Dynamic Decal */
	F3SF1_PARALLAX_OCCULSION = 268435456, /*!< Parallax Occlusion */
	F3SF1_EXTERNAL_EMITTANCE = 536870912, /*!< External Emittance */
	F3SF1_SHADOW_MAP = 1073741824, /*!< Shadow Map */
	F3SF1_ZBUFFER_TEST = 2147483648, /*!< ZBuffer Test (1=on) */
};

ostream & operator<<( ostream & out, BSShaderFlags const & val );

/*!
 * Bethesda Animation. Furniture entry points. It specifies the direction(s) from
 * where the actor is able to enter (and leave) the position.
 */
enum FurnitureEntryPoints {
	FRONT = 1, /*!< front entry point */
	BEHIND = 2, /*!< behind entry point */
	RIGHT = 4, /*!< right entry point */
	LEFT = 8, /*!< left entry point */
	UP = 16, /*!< up entry point - unknown function. Used on some beds in Skyrim, probably for blocking of sleeping position. */
};

ostream & operator<<( ostream & out, FurnitureEntryPoints const & val );

/*! Describes the options for the accum root on NiControllerSequence. */
enum AccumFlags {
	ACCUM_X_TRANS = 1, /*!< X Translation will be accumulated. */
	ACCUM_Y_TRANS = 2, /*!< Y Translation will be accumulated. */
	ACCUM_Z_TRANS = 4, /*!< Z Translation will be accumulated. */
	ACCUM_X_ROT = 8, /*!< X Rotation will be accumulated. */
	ACCUM_Y_ROT = 16, /*!< Y Rotation will be accumulated. */
	ACCUM_Z_ROT = 32, /*!< Z Rotation will be accumulated. */
	ACCUM_X_FRONT = 64, /*!< +X is front facing. (Default) */
	ACCUM_Y_FRONT = 128, /*!< +Y is front facing. */
	ACCUM_Z_FRONT = 256, /*!< +Z is front facing. */
	ACCUM_NEG_FRONT = 512, /*!< -X is front facing. */
};

ostream & operator<<( ostream & out, AccumFlags const & val );

/*! Determines how the data stream is accessed? */
enum DataStreamAccess {
	CPU_READ = 1, /*!< CPU Read */
	CPU_WRITE_STATIC = 2, /*!< CPU Write Static */
	CPU_WRITE_MUTABLE = 4, /*!< CPU Write Mutable */
	CPU_WRITE_VOLATILE = 8, /*!< CPU Write Volatile */
	GPU_READ = 16, /*!< GPU Read */
	GPU_WRITE = 32, /*!< GPU Write */
	CPU_WRITE_STATIC_INITITIALIZED = 64, /*!< CPU Write Static Inititialized */
};

ostream & operator<<( ostream & out, DataStreamAccess const & val );

/*! Editor flags for the Body Partitions. */
enum BSPartFlag {
	PF_EDITOR_VISIBLE = 1, /*!< Visible in Editor */
	PF_START_NET_BONESET = 256, /*!< Start a new shared boneset.  It is expected this BoneSet and the following sets in the Skin Partition will have the same bones. */
};

ostream & operator<<( ostream & out, BSPartFlag const & val );

enum LookAtFlags {
	LOOK_FLIP = 1, /*!< Flip */
	LOOK_Y_AXIS = 2, /*!< Y-Axis */
	LOOK_Z_AXIS = 4, /*!< Z-Axis */
};

ostream & operator<<( ostream & out, LookAtFlags const & val );

enum BSVectorFlags {
	BSVF_HAS_UV = 1, /*!< BSVF_Has_UV */
	BSVF_UNK2 = 2, /*!< BSVF_Unk2 */
	BSVF_UNK4 = 4, /*!< BSVF_Unk4 */
	BSVF_UNK8 = 8, /*!< BSVF_Unk8 */
	BSVF_UNK16 = 16, /*!< BSVF_Unk16 */
	BSVF_UNK32 = 32, /*!< BSVF_Unk32 */
	BSVF_UNK64 = 64, /*!< BSVF_Unk64 */
	BSVF_UNK128 = 128, /*!< BSVF_Unk128 */
	BSVF_UNK256 = 256, /*!< BSVF_Unk256 */
	BSVF_UNK512 = 512, /*!< BSVF_Unk512 */
	BSVF_UNK1024 = 1024, /*!< BSVF_Unk1024 */
	BSVF_UNK2048 = 2048, /*!< BSVF_Unk2048 */
	BSVF_HAS_TANGENTS = 4096, /*!< BSVF_Has_Tangents */
	BSVF_UNK8192 = 8192, /*!< BSVF_Unk8192 */
	BSVF_UNK16384 = 16384, /*!< BSVF_Unk16384 */
	BSVF_UNK32768 = 32768, /*!< BSVF_Unk32768 */
};

ostream & operator<<( ostream & out, BSVectorFlags const & val );

/*! Fallout 4 Shader Property Flags 1 */
enum Fallout4ShaderPropertyFlags1 {
	F4SF1_SPECULAR = 1, /*!< F4SF1_Specular */
	F4SF1_SKINNED = 2, /*!< F4SF1_Skinned */
	F4SF1_TEMP_REFRACTION = 4, /*!< F4SF1_Temp_Refraction */
	F4SF1_VERTEX_ALPHA = 8, /*!< F4SF1_Vertex_Alpha */
	F4SF1_GREYSCALETOPALETTE_COLOR = 16, /*!< F4SF1_GreyscaleToPalette_Color */
	F4SF1_GREYSCALETOPALETTE_ALPHA = 32, /*!< F4SF1_GreyscaleToPalette_Alpha */
	F4SF1_USE_FALLOFF = 64, /*!< F4SF1_Use_Falloff */
	F4SF1_ENVIRONMENT_MAPPING = 128, /*!< F4SF1_Environment_Mapping */
	F4SF1_RGB_FALLOFF = 256, /*!< F4SF1_RGB_Falloff */
	F4SF1_CAST_SHADOWS = 512, /*!< F4SF1_Cast_Shadows */
	F4SF1_FACE = 1024, /*!< F4SF1_Face */
	F4SF1_UI_MASK_RECTS = 2048, /*!< F4SF1_UI_Mask_Rects */
	F4SF1_MODEL_SPACE_NORMALS = 4096, /*!< F4SF1_Model_Space_Normals */
	F4SF1_NON_PROJECTIVE_SHADOWS = 8192, /*!< F4SF1_Non_Projective_Shadows */
	F4SF1_LANDSCAPE = 16384, /*!< F4SF1_Landscape */
	F4SF1_REFRACTION = 32768, /*!< F4SF1_Refraction */
	F4SF1_FIRE_REFRACTION = 65536, /*!< F4SF1_Fire_Refraction */
	F4SF1_EYE_ENVIRONMENT_MAPPING = 131072, /*!< F4SF1_Eye_Environment_Mapping */
	F4SF1_HAIR = 262144, /*!< F4SF1_Hair */
	F4SF1_SCREENDOOR_ALPHA_FADE = 524288, /*!< F4SF1_Screendoor_Alpha_Fade */
	F4SF1_LOCALMAP_HIDE_SECRET = 1048576, /*!< F4SF1_Localmap_Hide_Secret */
	F4SF1_SKIN_TINT = 2097152, /*!< F4SF1_Skin_Tint */
	F4SF1_OWN_EMIT = 4194304, /*!< F4SF1_Own_Emit */
	F4SF1_PROJECTED_UV = 8388608, /*!< F4SF1_Projected_UV */
	F4SF1_MULTIPLE_TEXTURES = 16777216, /*!< F4SF1_Multiple_Textures */
	F4SF1_TESSELLATE = 33554432, /*!< F4SF1_Tessellate */
	F4SF1_DECAL = 67108864, /*!< F4SF1_Decal */
	F4SF1_DYNAMIC_DECAL = 134217728, /*!< F4SF1_Dynamic_Decal */
	F4SF1_CHARACTER_LIGHTING = 268435456, /*!< F4SF1_Character_Lighting */
	F4SF1_EXTERNAL_EMITTANCE = 536870912, /*!< F4SF1_External_Emittance */
	F4SF1_SOFT_EFFECT = 1073741824, /*!< F4SF1_Soft_Effect */
	F4SF1_ZBUFFER_TEST = 2147483648, /*!< F4SF1_ZBuffer_Test */
};

ostream & operator<<( ostream & out, Fallout4ShaderPropertyFlags1 const & val );

/*! Fallout 4 Shader Property Flags 2 */
enum Fallout4ShaderPropertyFlags2 {
	F4SF2_ZBUFFER_WRITE = 1, /*!< F4SF2_ZBuffer_Write */
	F4SF2_LOD_LANDSCAPE = 2, /*!< F4SF2_LOD_Landscape */
	F4SF2_LOD_OBJECTS = 4, /*!< F4SF2_LOD_Objects */
	F4SF2_NO_FADE = 8, /*!< F4SF2_No_Fade */
	F4SF2_DOUBLE_SIDED = 16, /*!< F4SF2_Double_Sided */
	F4SF2_VERTEX_COLORS = 32, /*!< F4SF2_Vertex_Colors */
	F4SF2_GLOW_MAP = 64, /*!< F4SF2_Glow_Map */
	F4SF2_TRANSFORM_CHANGED = 128, /*!< F4SF2_Transform_Changed */
	F4SF2_DISMEMBERMENT_MEATCUFF = 256, /*!< F4SF2_Dismemberment_Meatcuff */
	F4SF2_TINT = 512, /*!< F4SF2_Tint */
	F4SF2_GRASS_VERTEX_LIGHTING = 1024, /*!< F4SF2_Grass_Vertex_Lighting */
	F4SF2_GRASS_UNIFORM_SCALE = 2048, /*!< F4SF2_Grass_Uniform_Scale */
	F4SF2_GRASS_FIT_SLOPE = 4096, /*!< F4SF2_Grass_Fit_Slope */
	F4SF2_GRASS_BILLBOARD = 8192, /*!< F4SF2_Grass_Billboard */
	F4SF2_NO_LOD_LAND_BLEND = 16384, /*!< F4SF2_No_LOD_Land_Blend */
	F4SF2_DISMEMBERMENT = 32768, /*!< F4SF2_Dismemberment */
	F4SF2_WIREFRAME = 65536, /*!< F4SF2_Wireframe */
	F4SF2_WEAPON_BLOOD = 131072, /*!< F4SF2_Weapon_Blood */
	F4SF2_HIDE_ON_LOCAL_MAP = 262144, /*!< F4SF2_Hide_On_Local_Map */
	F4SF2_PREMULT_ALPHA = 524288, /*!< F4SF2_Premult_Alpha */
	F4SF2_VATS_TARGET = 1048576, /*!< F4SF2_VATS_Target */
	F4SF2_ANISOTROPIC_LIGHTING = 2097152, /*!< F4SF2_Anisotropic_Lighting */
	F4SF2_SKEW_SPECULAR_ALPHA = 4194304, /*!< F4SF2_Skew_Specular_Alpha */
	F4SF2_MENU_SCREEN = 8388608, /*!< F4SF2_Menu_Screen */
	F4SF2_MULTI_LAYER_PARALLAX = 16777216, /*!< F4SF2_Multi_Layer_Parallax */
	F4SF2_ALPHA_TEST = 33554432, /*!< F4SF2_Alpha_Test */
	F4SF2_GRADIENT_REMAP = 67108864, /*!< F4SF2_Gradient_Remap */
	F4SF2_VATS_TARGET_DRAW_ALL = 134217728, /*!< F4SF2_VATS_Target_Draw_All */
	F4SF2_PIPBOY_SCREEN = 268435456, /*!< F4SF2_Pipboy_Screen */
	F4SF2_TREE_ANIM = 536870912, /*!< F4SF2_Tree_Anim */
	F4SF2_EFFECT_LIGHTING = 1073741824, /*!< F4SF2_Effect_Lighting */
	F4SF2_REFRACTION_WRITES_DEPTH = 2147483648, /*!< F4SF2_Refraction_Writes_Depth */
};

ostream & operator<<( ostream & out, Fallout4ShaderPropertyFlags2 const & val );

enum NxMaterialFlag {
	NX_MF_ANISOTROPIC = 2, /*!< NX_MF_ANISOTROPIC */
	NX_MF_DUMMY1 = 4, /*!< NX_MF_DUMMY1 */
	NX_MF_DUMMY2 = 8, /*!< NX_MF_DUMMY2 */
	NX_MF_DUMMY3 = 16, /*!< NX_MF_DUMMY3 */
	NX_MF_DISABLE_FRICTION = 32, /*!< NX_MF_DISABLE_FRICTION */
	NX_MF_DISABLE_STRONG_FRICTION = 64, /*!< NX_MF_DISABLE_STRONG_FRICTION */
};

ostream & operator<<( ostream & out, NxMaterialFlag const & val );

enum VertexFlags {
	VF_VERTEX = 16, /*!< VF_Vertex */
	VF_UVS = 32, /*!< VF_UVs */
	VF_UVS_2 = 64, /*!< VF_UVs_2 */
	VF_NORMALS = 128, /*!< VF_Normals */
	VF_TANGENTS = 256, /*!< VF_Tangents */
	VF_VERTEX_COLORS = 512, /*!< VF_Vertex_Colors */
	VF_SKINNED = 1024, /*!< VF_Skinned */
	VF_LAND_DATA = 2048, /*!< VF_Land_Data */
	VF_EYE_DATA = 4096, /*!< VF_Eye_Data */
	VF_INSTANCE = 8192, /*!< VF_Instance */
	VF_FULL_PRECISION = 16384, /*!< VF_Full_Precision */
};

ostream & operator<<( ostream & out, VertexFlags const & val );

/*! Flags for NiSwitchNode. */
enum NiSwitchFlags {
	UPDATEONLYACTIVECHILD = 1, /*!< Update Only Active Child */
	UPDATECONTROLLERS = 2, /*!< Update Controllers */
};

ostream & operator<<( ostream & out, NiSwitchFlags const & val );

/*! Shader Property Flags 2 */
enum BSShaderFlags2 {
	F3SF2_ZBUFFER_WRITE = 1, /*!< ZBuffer Write */
	F3SF2_LOD_LANDSCAPE = 2, /*!< LOD Landscape */
	F3SF2_LOD_BUILDING = 4, /*!< LOD Building */
	F3SF2_NO_FADE = 8, /*!< No Fade */
	F3SF2_REFRACTION_TINT = 16, /*!< Refraction Tint */
	F3SF2_VERTEX_COLORS = 32, /*!< Has Vertex Colors */
	F3SF2_UNKNOWN1 = 64, /*!< Unknown */
	F3SF2_1ST_LIGHT_IS_POINT_LIGHT = 128, /*!< 1st Light is Point Light */
	F3SF2_2ND_LIGHT = 256, /*!< 2nd Light */
	F3SF2_3RD_LIGHT = 512, /*!< 3rd Light */
	F3SF2_VERTEX_LIGHTING = 1024, /*!< Vertex Lighting */
	F3SF2_UNIFORM_SCALE = 2048, /*!< Uniform Scale */
	F3SF2_FIT_SLOPE = 4096, /*!< Fit Slope */
	F3SF2_BILLBOARD_AND_ENVMAP_LIGHT_FADE = 8192, /*!< Billboard and Envmap Light Fade */
	F3SF2_NO_LOD_LAND_BLEND = 16384, /*!< No LOD Land Blend */
	F3SF2_ENVMAP_LIGHT_FADE = 32768, /*!< Envmap Light Fade */
	F3SF2_WIREFRAME = 65536, /*!< Wireframe */
	F3SF2_VATS_SELECTION = 131072, /*!< VATS Selection */
	F3SF2_SHOW_IN_LOCAL_MAP = 262144, /*!< Show in Local Map */
	F3SF2_PREMULT_ALPHA = 524288, /*!< Premult Alpha */
	F3SF2_SKIP_NORMAL_MAPS = 1048576, /*!< Skip Normal Maps */
	F3SF2_ALPHA_DECAL = 2097152, /*!< Alpha Decal */
	F3SF2_NO_TRANSPARECNY_MULTISAMPLING = 4194304, /*!< No Transparency MultiSampling */
	F3SF2_UNKNOWN2 = 8388608, /*!< Unknown */
	F3SF2_UNKNOWN3 = 16777216, /*!< Unknown */
	F3SF2_UNKNOWN4 = 33554432, /*!< Unknown */
	F3SF2_UNKNOWN5 = 67108864, /*!< Unknown */
	F3SF2_UNKNOWN6 = 134217728, /*!< Unknown */
	F3SF2_UNKNOWN7 = 268435456, /*!< Unknown */
	F3SF2_UNKNOWN8 = 536870912, /*!< Unknown */
	F3SF2_UNKNOWN9 = 1073741824, /*!< Unknown */
	F3SF2_UNKNOWN10 = 2147483648, /*!< Unknown */
};

ostream & operator<<( ostream & out, BSShaderFlags2 const & val );

/*! Skyrim Shader Property Flags 2 */
enum SkyrimShaderPropertyFlags2 {
	SLSF2_ZBUFFER_WRITE = 1, /*!< Enables writing to the Z-Buffer */
	SLSF2_LOD_LANDSCAPE = 2, /*!< SLSF2_LOD_Landscape */
	SLSF2_LOD_OBJECTS = 4, /*!< SLSF2_LOD_Objects */
	SLSF2_NO_FADE = 8, /*!< SLSF2_No_Fade */
	SLSF2_DOUBLE_SIDED = 16, /*!< Double-sided rendering. */
	SLSF2_VERTEX_COLORS = 32, /*!< Has Vertex Colors. */
	SLSF2_GLOW_MAP = 64, /*!< Use Glow Map in the third texture slot. */
	SLSF2_ASSUME_SHADOWMASK = 128, /*!< SLSF2_Assume_Shadowmask */
	SLSF2_PACKED_TANGENT = 256, /*!< SLSF2_Packed_Tangent */
	SLSF2_MULTI_INDEX_SNOW = 512, /*!< SLSF2_Multi_Index_Snow */
	SLSF2_VERTEX_LIGHTING = 1024, /*!< SLSF2_Vertex_Lighting */
	SLSF2_UNIFORM_SCALE = 2048, /*!< SLSF2_Uniform_Scale */
	SLSF2_FIT_SLOPE = 4096, /*!< SLSF2_Fit_Slope */
	SLSF2_BILLBOARD = 8192, /*!< SLSF2_Billboard */
	SLSF2_NO_LOD_LAND_BLEND = 16384, /*!< SLSF2_No_LOD_Land_Blend */
	SLSF2_ENVMAP_LIGHT_FADE = 32768, /*!< SLSF2_EnvMap_Light_Fade */
	SLSF2_WIREFRAME = 65536, /*!< Wireframe (Seems to only work on particles) */
	SLSF2_WEAPON_BLOOD = 131072, /*!< Used for blood decals on weapons. */
	SLSF2_HIDE_ON_LOCAL_MAP = 262144, /*!< Similar to hide secret, but only for self? */
	SLSF2_PREMULT_ALPHA = 524288, /*!< Has Premultiplied Alpha */
	SLSF2_CLOUD_LOD = 1048576, /*!< SLSF2_Cloud_LOD */
	SLSF2_ANISOTROPIC_LIGHTING = 2097152, /*!< Hair only? */
	SLSF2_NO_TRANSPARENCY_MULTISAMPLING = 4194304, /*!< SLSF2_No_Transparency_Multisampling */
	SLSF2_UNUSED01 = 8388608, /*!< Unused? */
	SLSF2_MULTI_LAYER_PARALLAX = 16777216, /*!< Use Multilayer (inner-layer) Map */
	SLSF2_SOFT_LIGHTING = 33554432, /*!< Use Soft Lighting Map */
	SLSF2_RIM_LIGHTING = 67108864, /*!< Use Rim Lighting Map */
	SLSF2_BACK_LIGHTING = 134217728, /*!< Use Back Lighting Map */
	SLSF2_UNUSED02 = 268435456, /*!< Unused? */
	SLSF2_TREE_ANIM = 536870912, /*!< Enables Vertex Animation, Flutter Animation */
	SLSF2_EFFECT_LIGHTING = 1073741824, /*!< SLSF2_Effect_Lighting */
	SLSF2_HD_LOD_OBJECTS = 2147483648, /*!< SLSF2_HD_LOD_Objects */
};

ostream & operator<<( ostream & out, SkyrimShaderPropertyFlags2 const & val );

}
#endif

/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

//--BEGIN FILE HEAD CUSTOM CODE--//
#include "../../include/obj/bhkShape.h"
//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/ObjectRegistry.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/bhkRigidBody.h"
#include "../../include/gen/HavokFilter.h"
#include "../../include/gen/hkQuaternion.h"
#include "../../include/obj/bhkSerializable.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkRigidBody::TYPE("bhkRigidBody", &bhkEntity::TYPE );

bhkRigidBody::bhkRigidBody() : collisionResponse((hkResponseType)RESPONSE_SIMPLE_CONTACT), unusedByte1((byte)0), processContactCallbackDelay((unsigned short)0xffff), unknownInt1((unsigned int)0), unknownInt2((unsigned int)0), collisionResponse2((hkResponseType)RESPONSE_SIMPLE_CONTACT), unusedByte2((byte)0), processContactCallbackDelay2((unsigned short)0xffff), mass(1.0f), linearDamping(0.1f), angularDamping(0.05f), timeFactor(1.0f), gravityFactor(1.0f), friction(0.5f), rollingFrictionMultiplier(0.0f), restitution(0.4f), maxLinearVelocity(104.4f), maxAngularVelocity(31.57f), penetrationDepth(0.15f), motionSystem((hkMotionType)MO_SYS_DYNAMIC), deactivatorType((hkDeactivatorType)DEACTIVATOR_NEVER), enableDeactivation(1), solverDeactivation((hkSolverDeactivation)SOLVER_DEACTIVATION_OFF), qualityType((hkQualityType)MO_QUAL_FIXED), numConstraints((unsigned int)0), bodyFlags((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

bhkRigidBody::~bhkRigidBody() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & bhkRigidBody::GetType() const {
	return TYPE;
}

NiObject * bhkRigidBody::Create() {
	return new bhkRigidBody;
}

void bhkRigidBody::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	bhkEntity::Read( in, link_stack, info );
	NifStream( collisionResponse, in, info );
	NifStream( unusedByte1, in, info );
	NifStream( processContactCallbackDelay, in, info );
	NifStream( unknownInt1, in, info );
	if ( ( info.version >= 0x14000004 ) && ( info.version <= 0x14000005 ) ) {
		NifStream( havokFilterCopy.layer_ob, in, info );
	};
	if ( ((info.version == 0x14020007) && (info.userVersion2 <= 34)) ) {
		NifStream( havokFilterCopy.layer_fo, in, info );
	};
	if ( ((info.version == 0x14020007) && (info.userVersion2 > 34)) ) {
		NifStream( havokFilterCopy.layer_sk, in, info );
	};
	NifStream( havokFilterCopy.flagsAndPartNumber, in, info );
	NifStream( havokFilterCopy.group, in, info );
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		NifStream( unused2[i1], in, info );
	};
	if ( (info.userVersion2 > 34) ) {
		NifStream( unknownInt2, in, info );
	};
	NifStream( collisionResponse2, in, info );
	NifStream( unusedByte2, in, info );
	NifStream( processContactCallbackDelay2, in, info );
	if ( (info.userVersion2 <= 34) ) {
		NifStream( (unsigned int&)unknownInt2, in, info );
	};
	NifStream( translation, in, info );
	NifStream( rotation.x, in, info );
	NifStream( rotation.y, in, info );
	NifStream( rotation.z, in, info );
	NifStream( rotation.w, in, info );
	NifStream( linearVelocity, in, info );
	NifStream( angularVelocity, in, info );
	NifStream( inertiaTensor, in, info );
	NifStream( center, in, info );
	NifStream( mass, in, info );
	NifStream( linearDamping, in, info );
	NifStream( angularDamping, in, info );
	if ( (info.userVersion2 > 34) ) {
		NifStream( timeFactor, in, info );
		NifStream( gravityFactor, in, info );
	};
	NifStream( friction, in, info );
	if ( (info.userVersion2 > 34) ) {
		NifStream( rollingFrictionMultiplier, in, info );
	};
	NifStream( restitution, in, info );
	NifStream( maxLinearVelocity, in, info );
	NifStream( maxAngularVelocity, in, info );
	NifStream( penetrationDepth, in, info );
	NifStream( motionSystem, in, info );
	if ( (info.userVersion2 <= 34) ) {
		NifStream( deactivatorType, in, info );
	};
	if ( (info.userVersion2 > 34) ) {
		NifStream( enableDeactivation, in, info );
	};
	NifStream( solverDeactivation, in, info );
	NifStream( qualityType, in, info );
	for (unsigned int i1 = 0; i1 < 12; i1++) {
		NifStream( unknownBytes1[i1], in, info );
	};
	if ( (info.userVersion2 > 34) ) {
		for (unsigned int i2 = 0; i2 < 4; i2++) {
			NifStream( unknownBytes2[i2], in, info );
		};
	};
	NifStream( numConstraints, in, info );
	constraints.resize(numConstraints);
	for (unsigned int i1 = 0; i1 < constraints.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	if ( (info.userVersion2 < 76) ) {
		NifStream( bodyFlags, in, info );
	};
	if ( (info.userVersion2 >= 76) ) {
		NifStream( (unsigned short&)bodyFlags, in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkRigidBody::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkEntity::Write( out, link_map, missing_link_stack, info );
	numConstraints = (unsigned int)(constraints.size());
	NifStream( collisionResponse, out, info );
	NifStream( unusedByte1, out, info );
	NifStream( processContactCallbackDelay, out, info );
	NifStream( unknownInt1, out, info );
	if ( ( info.version >= 0x14000004 ) && ( info.version <= 0x14000005 ) ) {
		NifStream( havokFilterCopy.layer_ob, out, info );
	};
	if ( ((info.version == 0x14020007) && (info.userVersion2 <= 34)) ) {
		NifStream( havokFilterCopy.layer_fo, out, info );
	};
	if ( ((info.version == 0x14020007) && (info.userVersion2 > 34)) ) {
		NifStream( havokFilterCopy.layer_sk, out, info );
	};
	NifStream( havokFilterCopy.flagsAndPartNumber, out, info );
	NifStream( havokFilterCopy.group, out, info );
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		NifStream( unused2[i1], out, info );
	};
	if ( (info.userVersion2 > 34) ) {
		NifStream( unknownInt2, out, info );
	};
	NifStream( collisionResponse2, out, info );
	NifStream( unusedByte2, out, info );
	NifStream( processContactCallbackDelay2, out, info );
	if ( (info.userVersion2 <= 34) ) {
		NifStream( (unsigned int&)unknownInt2, out, info );
	};
	NifStream( translation, out, info );
	NifStream( rotation.x, out, info );
	NifStream( rotation.y, out, info );
	NifStream( rotation.z, out, info );
	NifStream( rotation.w, out, info );
	NifStream( linearVelocity, out, info );
	NifStream( angularVelocity, out, info );
	NifStream( inertiaTensor, out, info );
	NifStream( center, out, info );
	NifStream( mass, out, info );
	NifStream( linearDamping, out, info );
	NifStream( angularDamping, out, info );
	if ( (info.userVersion2 > 34) ) {
		NifStream( timeFactor, out, info );
		NifStream( gravityFactor, out, info );
	};
	NifStream( friction, out, info );
	if ( (info.userVersion2 > 34) ) {
		NifStream( rollingFrictionMultiplier, out, info );
	};
	NifStream( restitution, out, info );
	NifStream( maxLinearVelocity, out, info );
	NifStream( maxAngularVelocity, out, info );
	NifStream( penetrationDepth, out, info );
	NifStream( motionSystem, out, info );
	if ( (info.userVersion2 <= 34) ) {
		NifStream( deactivatorType, out, info );
	};
	if ( (info.userVersion2 > 34) ) {
		NifStream( enableDeactivation, out, info );
	};
	NifStream( solverDeactivation, out, info );
	NifStream( qualityType, out, info );
	for (unsigned int i1 = 0; i1 < 12; i1++) {
		NifStream( unknownBytes1[i1], out, info );
	};
	if ( (info.userVersion2 > 34) ) {
		for (unsigned int i2 = 0; i2 < 4; i2++) {
			NifStream( unknownBytes2[i2], out, info );
		};
	};
	NifStream( numConstraints, out, info );
	for (unsigned int i1 = 0; i1 < constraints.size(); i1++) {
		WriteRef( StaticCast<NiObject>(constraints[i1]), out, info, link_map, missing_link_stack );
	};
	if ( (info.userVersion2 < 76) ) {
		NifStream( bodyFlags, out, info );
	};
	if ( (info.userVersion2 >= 76) ) {
		NifStream( (unsigned short&)bodyFlags, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string bhkRigidBody::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkEntity::asString();
	numConstraints = (unsigned int)(constraints.size());
	out << "  Collision Response:  " << collisionResponse << endl;
	out << "  Unused Byte 1:  " << unusedByte1 << endl;
	out << "  Process Contact Callback Delay:  " << processContactCallbackDelay << endl;
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	out << "  Layer:  " << havokFilterCopy.layer_ob << endl;
	out << "  Layer:  " << havokFilterCopy.layer_fo << endl;
	out << "  Layer:  " << havokFilterCopy.layer_sk << endl;
	out << "  Flags and Part Number:  " << havokFilterCopy.flagsAndPartNumber << endl;
	out << "  Group:  " << havokFilterCopy.group << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unused 2[" << i1 << "]:  " << unused2[i1] << endl;
		array_output_count++;
	};
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	out << "  Collision Response 2:  " << collisionResponse2 << endl;
	out << "  Unused Byte 2:  " << unusedByte2 << endl;
	out << "  Process Contact Callback Delay 2:  " << processContactCallbackDelay2 << endl;
	out << "  Translation:  " << translation << endl;
	out << "  x:  " << rotation.x << endl;
	out << "  y:  " << rotation.y << endl;
	out << "  z:  " << rotation.z << endl;
	out << "  w:  " << rotation.w << endl;
	out << "  Linear Velocity:  " << linearVelocity << endl;
	out << "  Angular Velocity:  " << angularVelocity << endl;
	out << "  Inertia Tensor:  " << inertiaTensor << endl;
	out << "  Center:  " << center << endl;
	out << "  Mass:  " << mass << endl;
	out << "  Linear Damping:  " << linearDamping << endl;
	out << "  Angular Damping:  " << angularDamping << endl;
	out << "  Time Factor:  " << timeFactor << endl;
	out << "  Gravity Factor:  " << gravityFactor << endl;
	out << "  Friction:  " << friction << endl;
	out << "  Rolling Friction Multiplier:  " << rollingFrictionMultiplier << endl;
	out << "  Restitution:  " << restitution << endl;
	out << "  Max Linear Velocity:  " << maxLinearVelocity << endl;
	out << "  Max Angular Velocity:  " << maxAngularVelocity << endl;
	out << "  Penetration Depth:  " << penetrationDepth << endl;
	out << "  Motion System:  " << motionSystem << endl;
	out << "  Deactivator Type:  " << deactivatorType << endl;
	out << "  Enable Deactivation:  " << enableDeactivation << endl;
	out << "  Solver Deactivation:  " << solverDeactivation << endl;
	out << "  Quality Type:  " << qualityType << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 12; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Bytes 1[" << i1 << "]:  " << unknownBytes1[i1] << endl;
		array_output_count++;
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Bytes 2[" << i1 << "]:  " << unknownBytes2[i1] << endl;
		array_output_count++;
	};
	out << "  Num Constraints:  " << numConstraints << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < constraints.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Constraints[" << i1 << "]:  " << constraints[i1] << endl;
		array_output_count++;
	};
	out << "  Body Flags:  " << bodyFlags << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkRigidBody::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkEntity::FixLinks( objects, link_stack, missing_link_stack, info );
	for (unsigned int i1 = 0; i1 < constraints.size(); i1++) {
		constraints[i1] = FixLink<bhkSerializable>( objects, link_stack, missing_link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> bhkRigidBody::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkEntity::GetRefs();
	for (unsigned int i1 = 0; i1 < constraints.size(); i1++) {
		if ( constraints[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(constraints[i1]));
	};
	return refs;
}

std::list<NiObject *> bhkRigidBody::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = bhkEntity::GetPtrs();
	for (unsigned int i1 = 0; i1 < constraints.size(); i1++) {
	};
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

OblivionLayer bhkRigidBody::GetLayerCopy() const {
	return layerCopy;
}

void bhkRigidBody::SetLayerCopy( OblivionLayer value ) {
	layerCopy = value;
}

SkyrimLayer bhkRigidBody::GetSkyrimLayerCopy() const {
	return skyrimLayerCopy;
}

void bhkRigidBody::SetSkyrimLayerCopy( SkyrimLayer value ) {
	skyrimLayerCopy = value;
}

Vector4 bhkRigidBody::GetTranslation() const {
	return translation;
}

void bhkRigidBody::SetTranslation( const Vector4 & value ) {
	translation = value;
}

QuaternionXYZW bhkRigidBody::GetRotation() const {
	return rotation;
}

void bhkRigidBody::SetRotation( const QuaternionXYZW & value ) {
	rotation = value;
}

Vector4 bhkRigidBody::GetLinearVelocity() const {
	return linearVelocity;
}

void bhkRigidBody::SetLinearVelocity( const Vector4 & value ) {
	linearVelocity = value;
}

Vector4 bhkRigidBody::GetAngularVelocity() const {
	return angularVelocity;
}

void bhkRigidBody::SetAngularVelocity( const Vector4 & value ) {
	angularVelocity = value;
}

InertiaMatrix  bhkRigidBody::GetInertia() const {
	return inertia;
}

void bhkRigidBody::SetInertia( const InertiaMatrix&  value ) {
	inertia = value;
}

Vector4 bhkRigidBody::GetCenter() const {
	return center;
}

void bhkRigidBody::SetCenter( const Vector4 & value ) {
	center = value;
}

float bhkRigidBody::GetMass() const {
	return mass;
}

void bhkRigidBody::SetMass( float value ) {
	mass = value;
}

float bhkRigidBody::GetLinearDamping() const {
	return linearDamping;
}

void bhkRigidBody::SetLinearDamping( float value ) {
	linearDamping = value;
}

float bhkRigidBody::GetAngularDamping() const {
	return angularDamping;
}

void bhkRigidBody::SetAngularDamping( float value ) {
	angularDamping = value;
}

float bhkRigidBody::GetFriction() const {
	return friction;
}

void bhkRigidBody::SetFriction( float value ) {
	friction = value;
}

float bhkRigidBody::GetRestitution() const {
	return restitution;
}

void bhkRigidBody::SetRestitution( float value ) {
	restitution = value;
}

float bhkRigidBody::GetMaxLinearVelocity() const {
	return maxLinearVelocity;
}

void bhkRigidBody::SetMaxLinearVelocity( float value ) {
	maxLinearVelocity = value;
}

float bhkRigidBody::GetMaxAngularVelocity() const {
	return maxAngularVelocity;
}

void bhkRigidBody::SetMaxAngularVelocity( float value ) {
	maxAngularVelocity = value;
}

float bhkRigidBody::GetPenetrationDepth() const {
	return penetrationDepth;
}

void bhkRigidBody::SetPenetrationDepth( float value ) {
	penetrationDepth = value;
}

MotionSystem bhkRigidBody::GetMotionSystem() const {
	return motionSystem;
}

void bhkRigidBody::SetMotionSystem( MotionSystem value ) {
	motionSystem = value;
}

MotionQuality bhkRigidBody::GetQualityType() const {
	return qualityType;
}

void bhkRigidBody::SetQualityType( MotionQuality value ) {
	qualityType = value;
}

DeactivatorType bhkRigidBody::GetDeactivatorType() const {
	return deactivatorType;
}

void bhkRigidBody::SetDeactivatorType( const DeactivatorType & value ) {
	deactivatorType = value;
}

SolverDeactivation bhkRigidBody::GetSolverDeactivation() const {
	return solverDeactivation;
}

void bhkRigidBody::SetSolverDeactivation( const SolverDeactivation & value ) {
	solverDeactivation = value;
}

void bhkRigidBody::AddConstraint( bhkSerializable * obj ) {
   constraints.push_back( obj );
}

void bhkRigidBody::RemoveConstraint( bhkSerializable * obj ) {
   //Search Effect list for the one to remove
   for ( vector< bhkSerializableRef >::iterator it = constraints.begin(); it != constraints.end(); ) {
      if ( *it == obj ) {
         it = constraints.erase( it );
      } else {
         ++it;
      }
   }
}

void bhkRigidBody::ClearConstraints() {
   constraints.clear();
}

vector< Ref<bhkSerializable> > bhkRigidBody::GetConstraints() const {
   return constraints;
}


// Apply scale factor <scale> on data.
void bhkRigidBody::ApplyScale(float scale)
{
    // apply scale on transform
    translation *= scale;

    // apply scale on center of gravity
    center *= scale;

    // apply scale on inertia tensor
    inertia *= pow(scale, 2.0f);

    //# apply scale on all blocks down the hierarchy
    //ApplyScale(scale)
}

void bhkRigidBody::UpdateMassProperties(float density, bool solid, float mass)
{
    // Look at all the objects under this rigid body and update the mass
    //  center of gravity, and inertia tensor accordingly. If the C{mass} parameter
    //  is given then the C{density} argument is ignored.

	if (mass != 0.0f)
        density = 1.0f;

	if (shape != NULL)
	{
		float volume;
		Vector3 com;
		shape->CalcMassProperties(density, solid, this->mass, volume, com, inertia);
		center = com;
		if (mass != 0.0f)
		{
			float mass_correction = (this->mass != 0.0f) ? mass / this->mass : 1.0f;
			this->mass = mass;
			inertia *= mass_correction;
		}
	}
}

NifArray<7,unsigned short> bhkRigidBody::GetUnknown7Shorts() const {
	return unknown7Shorts;
}

void bhkRigidBody::SetUnknown7Shorts(const NifArray<7,unsigned short> & in ) {
	unknown7Shorts = in;
}

//--END CUSTOM CODE--//

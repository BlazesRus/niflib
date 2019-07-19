/* Copyright (c) 2019, NIF File Format Library and Tools
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
#include "../../include/obj/NiPhysXD6JointDesc.h"
#include "../../include/gen/NxJointDriveDesc.h"
#include "../../include/gen/NxJointLimitSoftDesc.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPhysXD6JointDesc::TYPE("NiPhysXD6JointDesc", &NiPhysXJointDesc::TYPE );

NiPhysXD6JointDesc::NiPhysXD6JointDesc() : xMotion((NxD6JointMotion)0), yMotion((NxD6JointMotion)0), zMotion((NxD6JointMotion)0), swing1Motion((NxD6JointMotion)0), swing2Motion((NxD6JointMotion)0), twistMotion((NxD6JointMotion)0), projectionMode((NxJointProjectionMode)0), projectionDistance(0.0f), projectionAngle(0.0f), gearRatio(0.0f), flags((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiPhysXD6JointDesc::~NiPhysXD6JointDesc() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiPhysXD6JointDesc::GetType() const {
	return TYPE;
}

NiObject * NiPhysXD6JointDesc::Create() {
	return new NiPhysXD6JointDesc;
}

void NiPhysXD6JointDesc::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPhysXJointDesc::Read( in, link_stack, info );
	NifStream( xMotion, in, info );
	NifStream( yMotion, in, info );
	NifStream( zMotion, in, info );
	NifStream( swing1Motion, in, info );
	NifStream( swing2Motion, in, info );
	NifStream( twistMotion, in, info );
	NifStream( linearLimit.value, in, info );
	NifStream( linearLimit.restitution, in, info );
	NifStream( linearLimit.spring, in, info );
	NifStream( linearLimit.damping, in, info );
	NifStream( swing1Limit.value, in, info );
	NifStream( swing1Limit.restitution, in, info );
	NifStream( swing1Limit.spring, in, info );
	NifStream( swing1Limit.damping, in, info );
	NifStream( swing2Limit.value, in, info );
	NifStream( swing2Limit.restitution, in, info );
	NifStream( swing2Limit.spring, in, info );
	NifStream( swing2Limit.damping, in, info );
	NifStream( twistLowLimit.value, in, info );
	NifStream( twistLowLimit.restitution, in, info );
	NifStream( twistLowLimit.spring, in, info );
	NifStream( twistLowLimit.damping, in, info );
	NifStream( twistHighLimit.value, in, info );
	NifStream( twistHighLimit.restitution, in, info );
	NifStream( twistHighLimit.spring, in, info );
	NifStream( twistHighLimit.damping, in, info );
	NifStream( xDrive.driveType, in, info );
	NifStream( xDrive.restitution, in, info );
	NifStream( xDrive.spring, in, info );
	NifStream( xDrive.damping, in, info );
	NifStream( yDrive.driveType, in, info );
	NifStream( yDrive.restitution, in, info );
	NifStream( yDrive.spring, in, info );
	NifStream( yDrive.damping, in, info );
	NifStream( zDrive.driveType, in, info );
	NifStream( zDrive.restitution, in, info );
	NifStream( zDrive.spring, in, info );
	NifStream( zDrive.damping, in, info );
	NifStream( swingDrive.driveType, in, info );
	NifStream( swingDrive.restitution, in, info );
	NifStream( swingDrive.spring, in, info );
	NifStream( swingDrive.damping, in, info );
	NifStream( twistDrive.driveType, in, info );
	NifStream( twistDrive.restitution, in, info );
	NifStream( twistDrive.spring, in, info );
	NifStream( twistDrive.damping, in, info );
	NifStream( slerpDrive.driveType, in, info );
	NifStream( slerpDrive.restitution, in, info );
	NifStream( slerpDrive.spring, in, info );
	NifStream( slerpDrive.damping, in, info );
	NifStream( drivePosition, in, info );
	NifStream( driveOrientation, in, info );
	NifStream( driveLinearVelocity, in, info );
	NifStream( driveAngularVelocity, in, info );
	NifStream( projectionMode, in, info );
	NifStream( projectionDistance, in, info );
	NifStream( projectionAngle, in, info );
	NifStream( gearRatio, in, info );
	NifStream( flags, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPhysXD6JointDesc::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPhysXJointDesc::Write( out, link_map, missing_link_stack, info );
	NifStream( xMotion, out, info );
	NifStream( yMotion, out, info );
	NifStream( zMotion, out, info );
	NifStream( swing1Motion, out, info );
	NifStream( swing2Motion, out, info );
	NifStream( twistMotion, out, info );
	NifStream( linearLimit.value, out, info );
	NifStream( linearLimit.restitution, out, info );
	NifStream( linearLimit.spring, out, info );
	NifStream( linearLimit.damping, out, info );
	NifStream( swing1Limit.value, out, info );
	NifStream( swing1Limit.restitution, out, info );
	NifStream( swing1Limit.spring, out, info );
	NifStream( swing1Limit.damping, out, info );
	NifStream( swing2Limit.value, out, info );
	NifStream( swing2Limit.restitution, out, info );
	NifStream( swing2Limit.spring, out, info );
	NifStream( swing2Limit.damping, out, info );
	NifStream( twistLowLimit.value, out, info );
	NifStream( twistLowLimit.restitution, out, info );
	NifStream( twistLowLimit.spring, out, info );
	NifStream( twistLowLimit.damping, out, info );
	NifStream( twistHighLimit.value, out, info );
	NifStream( twistHighLimit.restitution, out, info );
	NifStream( twistHighLimit.spring, out, info );
	NifStream( twistHighLimit.damping, out, info );
	NifStream( xDrive.driveType, out, info );
	NifStream( xDrive.restitution, out, info );
	NifStream( xDrive.spring, out, info );
	NifStream( xDrive.damping, out, info );
	NifStream( yDrive.driveType, out, info );
	NifStream( yDrive.restitution, out, info );
	NifStream( yDrive.spring, out, info );
	NifStream( yDrive.damping, out, info );
	NifStream( zDrive.driveType, out, info );
	NifStream( zDrive.restitution, out, info );
	NifStream( zDrive.spring, out, info );
	NifStream( zDrive.damping, out, info );
	NifStream( swingDrive.driveType, out, info );
	NifStream( swingDrive.restitution, out, info );
	NifStream( swingDrive.spring, out, info );
	NifStream( swingDrive.damping, out, info );
	NifStream( twistDrive.driveType, out, info );
	NifStream( twistDrive.restitution, out, info );
	NifStream( twistDrive.spring, out, info );
	NifStream( twistDrive.damping, out, info );
	NifStream( slerpDrive.driveType, out, info );
	NifStream( slerpDrive.restitution, out, info );
	NifStream( slerpDrive.spring, out, info );
	NifStream( slerpDrive.damping, out, info );
	NifStream( drivePosition, out, info );
	NifStream( driveOrientation, out, info );
	NifStream( driveLinearVelocity, out, info );
	NifStream( driveAngularVelocity, out, info );
	NifStream( projectionMode, out, info );
	NifStream( projectionDistance, out, info );
	NifStream( projectionAngle, out, info );
	NifStream( gearRatio, out, info );
	NifStream( flags, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiPhysXD6JointDesc::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	out << NiPhysXJointDesc::asString();
	out << "  X Motion:  " << xMotion << endl;
	out << "  Y Motion:  " << yMotion << endl;
	out << "  Z Motion:  " << zMotion << endl;
	out << "  Swing 1 Motion:  " << swing1Motion << endl;
	out << "  Swing 2 Motion:  " << swing2Motion << endl;
	out << "  Twist Motion:  " << twistMotion << endl;
	out << "  Value:  " << linearLimit.value << endl;
	out << "  Restitution:  " << linearLimit.restitution << endl;
	out << "  Spring:  " << linearLimit.spring << endl;
	out << "  Damping:  " << linearLimit.damping << endl;
	out << "  Value:  " << swing1Limit.value << endl;
	out << "  Restitution:  " << swing1Limit.restitution << endl;
	out << "  Spring:  " << swing1Limit.spring << endl;
	out << "  Damping:  " << swing1Limit.damping << endl;
	out << "  Value:  " << swing2Limit.value << endl;
	out << "  Restitution:  " << swing2Limit.restitution << endl;
	out << "  Spring:  " << swing2Limit.spring << endl;
	out << "  Damping:  " << swing2Limit.damping << endl;
	out << "  Value:  " << twistLowLimit.value << endl;
	out << "  Restitution:  " << twistLowLimit.restitution << endl;
	out << "  Spring:  " << twistLowLimit.spring << endl;
	out << "  Damping:  " << twistLowLimit.damping << endl;
	out << "  Value:  " << twistHighLimit.value << endl;
	out << "  Restitution:  " << twistHighLimit.restitution << endl;
	out << "  Spring:  " << twistHighLimit.spring << endl;
	out << "  Damping:  " << twistHighLimit.damping << endl;
	out << "  Drive Type:  " << xDrive.driveType << endl;
	out << "  Restitution:  " << xDrive.restitution << endl;
	out << "  Spring:  " << xDrive.spring << endl;
	out << "  Damping:  " << xDrive.damping << endl;
	out << "  Drive Type:  " << yDrive.driveType << endl;
	out << "  Restitution:  " << yDrive.restitution << endl;
	out << "  Spring:  " << yDrive.spring << endl;
	out << "  Damping:  " << yDrive.damping << endl;
	out << "  Drive Type:  " << zDrive.driveType << endl;
	out << "  Restitution:  " << zDrive.restitution << endl;
	out << "  Spring:  " << zDrive.spring << endl;
	out << "  Damping:  " << zDrive.damping << endl;
	out << "  Drive Type:  " << swingDrive.driveType << endl;
	out << "  Restitution:  " << swingDrive.restitution << endl;
	out << "  Spring:  " << swingDrive.spring << endl;
	out << "  Damping:  " << swingDrive.damping << endl;
	out << "  Drive Type:  " << twistDrive.driveType << endl;
	out << "  Restitution:  " << twistDrive.restitution << endl;
	out << "  Spring:  " << twistDrive.spring << endl;
	out << "  Damping:  " << twistDrive.damping << endl;
	out << "  Drive Type:  " << slerpDrive.driveType << endl;
	out << "  Restitution:  " << slerpDrive.restitution << endl;
	out << "  Spring:  " << slerpDrive.spring << endl;
	out << "  Damping:  " << slerpDrive.damping << endl;
	out << "  Drive Position:  " << drivePosition << endl;
	out << "  Drive Orientation:  " << driveOrientation << endl;
	out << "  Drive Linear Velocity:  " << driveLinearVelocity << endl;
	out << "  Drive Angular Velocity:  " << driveAngularVelocity << endl;
	out << "  Projection Mode:  " << projectionMode << endl;
	out << "  Projection Distance:  " << projectionDistance << endl;
	out << "  Projection Angle:  " << projectionAngle << endl;
	out << "  Gear Ratio:  " << gearRatio << endl;
	out << "  Flags:  " << flags << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPhysXD6JointDesc::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPhysXJointDesc::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPhysXD6JointDesc::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPhysXJointDesc::GetRefs();
	return refs;
}

std::list<NiObject *> NiPhysXD6JointDesc::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiPhysXJointDesc::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

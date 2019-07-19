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
#include "../../include/obj/bhkRagdollConstraint.h"
#include "../../include/gen/MotorDescriptor.h"
#include "../../include/gen/RagdollDescriptor.h"
#include "../../include/gen/bhkPositionConstraintMotor.h"
#include "../../include/gen/bhkSpringDamperConstraintMotor.h"
#include "../../include/gen/bhkVelocityConstraintMotor.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkRagdollConstraint::TYPE("bhkRagdollConstraint", &bhkConstraint::TYPE );

bhkRagdollConstraint::bhkRagdollConstraint() {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

bhkRagdollConstraint::~bhkRagdollConstraint() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & bhkRagdollConstraint::GetType() const {
	return TYPE;
}

NiObject * bhkRagdollConstraint::Create() {
	return new bhkRagdollConstraint;
}

void bhkRagdollConstraint::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConstraint::Read( in, link_stack, info );
	if ( (info.userVersion2 <= 16) ) {
		NifStream( ragdoll.pivotA, in, info );
		NifStream( ragdoll.planeA, in, info );
		NifStream( ragdoll.twistA, in, info );
		NifStream( ragdoll.pivotB, in, info );
		NifStream( ragdoll.planeB, in, info );
		NifStream( ragdoll.twistB, in, info );
	};
	if ( (info.userVersion2 > 16) ) {
		NifStream( (Vector4&)ragdoll.twistA, in, info );
		NifStream( (Vector4&)ragdoll.planeA, in, info );
		NifStream( ragdoll.motorA, in, info );
		NifStream( (Vector4&)ragdoll.pivotA, in, info );
		NifStream( (Vector4&)ragdoll.twistB, in, info );
		NifStream( (Vector4&)ragdoll.planeB, in, info );
		NifStream( ragdoll.motorB, in, info );
		NifStream( (Vector4&)ragdoll.pivotB, in, info );
	};
	NifStream( ragdoll.coneMaxAngle, in, info );
	NifStream( ragdoll.planeMinAngle, in, info );
	NifStream( ragdoll.planeMaxAngle, in, info );
	NifStream( ragdoll.twistMinAngle, in, info );
	NifStream( ragdoll.twistMaxAngle, in, info );
	NifStream( ragdoll.maxFriction, in, info );
	if ( ( info.version >= 0x14020007 ) && ( (info.userVersion2 > 16) ) ) {
		NifStream( ragdoll.motor.type, in, info );
		if ( (ragdoll.motor.type == 1) ) {
			NifStream( ragdoll.motor.positionMotor.minForce, in, info );
			NifStream( ragdoll.motor.positionMotor.maxForce, in, info );
			NifStream( ragdoll.motor.positionMotor.tau, in, info );
			NifStream( ragdoll.motor.positionMotor.damping, in, info );
			NifStream( ragdoll.motor.positionMotor.proportionalRecoveryVelocity, in, info );
			NifStream( ragdoll.motor.positionMotor.constantRecoveryVelocity, in, info );
			NifStream( ragdoll.motor.positionMotor.motorEnabled, in, info );
		};
		if ( (ragdoll.motor.type == 2) ) {
			NifStream( ragdoll.motor.velocityMotor.minForce, in, info );
			NifStream( ragdoll.motor.velocityMotor.maxForce, in, info );
			NifStream( ragdoll.motor.velocityMotor.tau, in, info );
			NifStream( ragdoll.motor.velocityMotor.targetVelocity, in, info );
			NifStream( ragdoll.motor.velocityMotor.useVelocityTarget, in, info );
			NifStream( ragdoll.motor.velocityMotor.motorEnabled, in, info );
		};
		if ( (ragdoll.motor.type == 3) ) {
			NifStream( ragdoll.motor.springDamperMotor.minForce, in, info );
			NifStream( ragdoll.motor.springDamperMotor.maxForce, in, info );
			NifStream( ragdoll.motor.springDamperMotor.springConstant, in, info );
			NifStream( ragdoll.motor.springDamperMotor.springDamping, in, info );
			NifStream( ragdoll.motor.springDamperMotor.motorEnabled, in, info );
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkRagdollConstraint::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConstraint::Write( out, link_map, missing_link_stack, info );
	if ( (info.userVersion2 <= 16) ) {
		NifStream( ragdoll.pivotA, out, info );
		NifStream( ragdoll.planeA, out, info );
		NifStream( ragdoll.twistA, out, info );
		NifStream( ragdoll.pivotB, out, info );
		NifStream( ragdoll.planeB, out, info );
		NifStream( ragdoll.twistB, out, info );
	};
	if ( (info.userVersion2 > 16) ) {
		NifStream( (Vector4&)ragdoll.twistA, out, info );
		NifStream( (Vector4&)ragdoll.planeA, out, info );
		NifStream( ragdoll.motorA, out, info );
		NifStream( (Vector4&)ragdoll.pivotA, out, info );
		NifStream( (Vector4&)ragdoll.twistB, out, info );
		NifStream( (Vector4&)ragdoll.planeB, out, info );
		NifStream( ragdoll.motorB, out, info );
		NifStream( (Vector4&)ragdoll.pivotB, out, info );
	};
	NifStream( ragdoll.coneMaxAngle, out, info );
	NifStream( ragdoll.planeMinAngle, out, info );
	NifStream( ragdoll.planeMaxAngle, out, info );
	NifStream( ragdoll.twistMinAngle, out, info );
	NifStream( ragdoll.twistMaxAngle, out, info );
	NifStream( ragdoll.maxFriction, out, info );
	if ( ( info.version >= 0x14020007 ) && ( (info.userVersion2 > 16) ) ) {
		NifStream( ragdoll.motor.type, out, info );
		if ( (ragdoll.motor.type == 1) ) {
			NifStream( ragdoll.motor.positionMotor.minForce, out, info );
			NifStream( ragdoll.motor.positionMotor.maxForce, out, info );
			NifStream( ragdoll.motor.positionMotor.tau, out, info );
			NifStream( ragdoll.motor.positionMotor.damping, out, info );
			NifStream( ragdoll.motor.positionMotor.proportionalRecoveryVelocity, out, info );
			NifStream( ragdoll.motor.positionMotor.constantRecoveryVelocity, out, info );
			NifStream( ragdoll.motor.positionMotor.motorEnabled, out, info );
		};
		if ( (ragdoll.motor.type == 2) ) {
			NifStream( ragdoll.motor.velocityMotor.minForce, out, info );
			NifStream( ragdoll.motor.velocityMotor.maxForce, out, info );
			NifStream( ragdoll.motor.velocityMotor.tau, out, info );
			NifStream( ragdoll.motor.velocityMotor.targetVelocity, out, info );
			NifStream( ragdoll.motor.velocityMotor.useVelocityTarget, out, info );
			NifStream( ragdoll.motor.velocityMotor.motorEnabled, out, info );
		};
		if ( (ragdoll.motor.type == 3) ) {
			NifStream( ragdoll.motor.springDamperMotor.minForce, out, info );
			NifStream( ragdoll.motor.springDamperMotor.maxForce, out, info );
			NifStream( ragdoll.motor.springDamperMotor.springConstant, out, info );
			NifStream( ragdoll.motor.springDamperMotor.springDamping, out, info );
			NifStream( ragdoll.motor.springDamperMotor.motorEnabled, out, info );
		};
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string bhkRagdollConstraint::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	out << bhkConstraint::asString();
	out << "  Pivot A:  " << ragdoll.pivotA << endl;
	out << "  Plane A:  " << ragdoll.planeA << endl;
	out << "  Twist A:  " << ragdoll.twistA << endl;
	out << "  Pivot B:  " << ragdoll.pivotB << endl;
	out << "  Plane B:  " << ragdoll.planeB << endl;
	out << "  Twist B:  " << ragdoll.twistB << endl;
	out << "  Motor A:  " << ragdoll.motorA << endl;
	out << "  Motor B:  " << ragdoll.motorB << endl;
	out << "  Cone Max Angle:  " << ragdoll.coneMaxAngle << endl;
	out << "  Plane Min Angle:  " << ragdoll.planeMinAngle << endl;
	out << "  Plane Max Angle:  " << ragdoll.planeMaxAngle << endl;
	out << "  Twist Min Angle:  " << ragdoll.twistMinAngle << endl;
	out << "  Twist Max Angle:  " << ragdoll.twistMaxAngle << endl;
	out << "  Max Friction:  " << ragdoll.maxFriction << endl;
	out << "  Type:  " << ragdoll.motor.type << endl;
	if ( (ragdoll.motor.type == 1) ) {
		out << "    Min Force:  " << ragdoll.motor.positionMotor.minForce << endl;
		out << "    Max Force:  " << ragdoll.motor.positionMotor.maxForce << endl;
		out << "    Tau:  " << ragdoll.motor.positionMotor.tau << endl;
		out << "    Damping:  " << ragdoll.motor.positionMotor.damping << endl;
		out << "    Proportional Recovery Velocity:  " << ragdoll.motor.positionMotor.proportionalRecoveryVelocity << endl;
		out << "    Constant Recovery Velocity:  " << ragdoll.motor.positionMotor.constantRecoveryVelocity << endl;
		out << "    Motor Enabled:  " << ragdoll.motor.positionMotor.motorEnabled << endl;
	};
	if ( (ragdoll.motor.type == 2) ) {
		out << "    Min Force:  " << ragdoll.motor.velocityMotor.minForce << endl;
		out << "    Max Force:  " << ragdoll.motor.velocityMotor.maxForce << endl;
		out << "    Tau:  " << ragdoll.motor.velocityMotor.tau << endl;
		out << "    Target Velocity:  " << ragdoll.motor.velocityMotor.targetVelocity << endl;
		out << "    Use Velocity Target:  " << ragdoll.motor.velocityMotor.useVelocityTarget << endl;
		out << "    Motor Enabled:  " << ragdoll.motor.velocityMotor.motorEnabled << endl;
	};
	if ( (ragdoll.motor.type == 3) ) {
		out << "    Min Force:  " << ragdoll.motor.springDamperMotor.minForce << endl;
		out << "    Max Force:  " << ragdoll.motor.springDamperMotor.maxForce << endl;
		out << "    Spring Constant:  " << ragdoll.motor.springDamperMotor.springConstant << endl;
		out << "    Spring Damping:  " << ragdoll.motor.springDamperMotor.springDamping << endl;
		out << "    Motor Enabled:  " << ragdoll.motor.springDamperMotor.motorEnabled << endl;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkRagdollConstraint::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConstraint::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> bhkRagdollConstraint::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkConstraint::GetRefs();
	return refs;
}

std::list<NiObject *> bhkRagdollConstraint::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = bhkConstraint::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//

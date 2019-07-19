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
#include "../../include/obj/bhkMalleableConstraint.h"
#include "../../include/gen/BallAndSocketDescriptor.h"
#include "../../include/gen/HingeDescriptor.h"
#include "../../include/gen/LimitedHingeDescriptor.h"
#include "../../include/gen/MalleableDescriptor.h"
#include "../../include/gen/MotorDescriptor.h"
#include "../../include/gen/PrismaticDescriptor.h"
#include "../../include/gen/RagdollDescriptor.h"
#include "../../include/gen/StiffSpringDescriptor.h"
#include "../../include/gen/bhkPositionConstraintMotor.h"
#include "../../include/gen/bhkSpringDamperConstraintMotor.h"
#include "../../include/gen/bhkVelocityConstraintMotor.h"
#include "../../include/obj/bhkEntity.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkMalleableConstraint::TYPE("bhkMalleableConstraint", &bhkConstraint::TYPE );

bhkMalleableConstraint::bhkMalleableConstraint() {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

bhkMalleableConstraint::~bhkMalleableConstraint() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & bhkMalleableConstraint::GetType() const {
	return TYPE;
}

NiObject * bhkMalleableConstraint::Create() {
	return new bhkMalleableConstraint;
}

void bhkMalleableConstraint::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	bhkConstraint::Read( in, link_stack, info );
	NifStream( malleable.type, in, info );
	NifStream( malleable.numEntities, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( malleable.priority, in, info );
	if ( (malleable.type == 0) ) {
		NifStream( malleable.ballAndSocket.pivotA, in, info );
		NifStream( malleable.ballAndSocket.pivotB, in, info );
	};
	if ( (malleable.type == 1) ) {
		if ( info.version <= 0x14000005 ) {
			NifStream( malleable.hinge.pivotA, in, info );
			NifStream( malleable.hinge.perp2AxleInA1, in, info );
			NifStream( malleable.hinge.perp2AxleInA2, in, info );
			NifStream( malleable.hinge.pivotB, in, info );
			NifStream( malleable.hinge.axleB, in, info );
		};
		if ( info.version >= 0x14020007 ) {
			NifStream( malleable.hinge.axleA, in, info );
			NifStream( (Vector4&)malleable.hinge.perp2AxleInA1, in, info );
			NifStream( (Vector4&)malleable.hinge.perp2AxleInA2, in, info );
			NifStream( (Vector4&)malleable.hinge.pivotA, in, info );
			NifStream( (Vector4&)malleable.hinge.axleB, in, info );
			NifStream( malleable.hinge.perp2AxleInB1, in, info );
			NifStream( malleable.hinge.perp2AxleInB2, in, info );
			NifStream( (Vector4&)malleable.hinge.pivotB, in, info );
		};
	};
	if ( (malleable.type == 2) ) {
		if ( (info.userVersion2 <= 16) ) {
			NifStream( malleable.limitedHinge.pivotA, in, info );
			NifStream( malleable.limitedHinge.axleA, in, info );
			NifStream( malleable.limitedHinge.perp2AxleInA1, in, info );
			NifStream( malleable.limitedHinge.perp2AxleInA2, in, info );
			NifStream( malleable.limitedHinge.pivotB, in, info );
			NifStream( malleable.limitedHinge.axleB, in, info );
			NifStream( malleable.limitedHinge.perp2AxleInB2, in, info );
		};
		if ( (info.userVersion2 > 16) ) {
			NifStream( (Vector4&)malleable.limitedHinge.axleA, in, info );
			NifStream( (Vector4&)malleable.limitedHinge.perp2AxleInA1, in, info );
			NifStream( (Vector4&)malleable.limitedHinge.perp2AxleInA2, in, info );
			NifStream( (Vector4&)malleable.limitedHinge.pivotA, in, info );
			NifStream( (Vector4&)malleable.limitedHinge.axleB, in, info );
			NifStream( malleable.limitedHinge.perp2AxleInB1, in, info );
			NifStream( (Vector4&)malleable.limitedHinge.perp2AxleInB2, in, info );
			NifStream( (Vector4&)malleable.limitedHinge.pivotB, in, info );
		};
		NifStream( malleable.limitedHinge.minAngle, in, info );
		NifStream( malleable.limitedHinge.maxAngle, in, info );
		NifStream( malleable.limitedHinge.maxFriction, in, info );
		if ( ( info.version >= 0x14020007 ) && ( (info.userVersion2 > 16) ) ) {
			NifStream( malleable.limitedHinge.motor.type, in, info );
			if ( (malleable.limitedHinge.motor.type == 1) ) {
				NifStream( malleable.limitedHinge.motor.positionMotor.minForce, in, info );
				NifStream( malleable.limitedHinge.motor.positionMotor.maxForce, in, info );
				NifStream( malleable.limitedHinge.motor.positionMotor.tau, in, info );
				NifStream( malleable.limitedHinge.motor.positionMotor.damping, in, info );
				NifStream( malleable.limitedHinge.motor.positionMotor.proportionalRecoveryVelocity, in, info );
				NifStream( malleable.limitedHinge.motor.positionMotor.constantRecoveryVelocity, in, info );
				NifStream( malleable.limitedHinge.motor.positionMotor.motorEnabled, in, info );
			};
			if ( (malleable.limitedHinge.motor.type == 2) ) {
				NifStream( malleable.limitedHinge.motor.velocityMotor.minForce, in, info );
				NifStream( malleable.limitedHinge.motor.velocityMotor.maxForce, in, info );
				NifStream( malleable.limitedHinge.motor.velocityMotor.tau, in, info );
				NifStream( malleable.limitedHinge.motor.velocityMotor.targetVelocity, in, info );
				NifStream( malleable.limitedHinge.motor.velocityMotor.useVelocityTarget, in, info );
				NifStream( malleable.limitedHinge.motor.velocityMotor.motorEnabled, in, info );
			};
			if ( (malleable.limitedHinge.motor.type == 3) ) {
				NifStream( malleable.limitedHinge.motor.springDamperMotor.minForce, in, info );
				NifStream( malleable.limitedHinge.motor.springDamperMotor.maxForce, in, info );
				NifStream( malleable.limitedHinge.motor.springDamperMotor.springConstant, in, info );
				NifStream( malleable.limitedHinge.motor.springDamperMotor.springDamping, in, info );
				NifStream( malleable.limitedHinge.motor.springDamperMotor.motorEnabled, in, info );
			};
		};
	};
	if ( (malleable.type == 6) ) {
		if ( info.version <= 0x14000005 ) {
			NifStream( malleable.prismatic.pivotA, in, info );
			NifStream( malleable.prismatic.rotationA, in, info );
			NifStream( malleable.prismatic.planeA, in, info );
			NifStream( malleable.prismatic.slidingA, in, info );
			NifStream( malleable.prismatic.pivotB, in, info );
			NifStream( malleable.prismatic.rotationB, in, info );
			NifStream( malleable.prismatic.planeB, in, info );
			NifStream( malleable.prismatic.slidingB, in, info );
		};
		if ( info.version >= 0x14020007 ) {
			NifStream( (Vector4&)malleable.prismatic.slidingA, in, info );
			NifStream( (Vector4&)malleable.prismatic.rotationA, in, info );
			NifStream( (Vector4&)malleable.prismatic.planeA, in, info );
			NifStream( (Vector4&)malleable.prismatic.pivotA, in, info );
			NifStream( (Vector4&)malleable.prismatic.slidingB, in, info );
			NifStream( (Vector4&)malleable.prismatic.rotationB, in, info );
			NifStream( (Vector4&)malleable.prismatic.planeB, in, info );
			NifStream( (Vector4&)malleable.prismatic.pivotB, in, info );
		};
		NifStream( malleable.prismatic.minDistance, in, info );
		NifStream( malleable.prismatic.maxDistance, in, info );
		NifStream( malleable.prismatic.friction, in, info );
		if ( ( info.version >= 0x14020007 ) && ( (info.userVersion2 > 16) ) ) {
			NifStream( malleable.prismatic.motor.type, in, info );
			if ( (malleable.prismatic.motor.type == 1) ) {
				NifStream( malleable.prismatic.motor.positionMotor.minForce, in, info );
				NifStream( malleable.prismatic.motor.positionMotor.maxForce, in, info );
				NifStream( malleable.prismatic.motor.positionMotor.tau, in, info );
				NifStream( malleable.prismatic.motor.positionMotor.damping, in, info );
				NifStream( malleable.prismatic.motor.positionMotor.proportionalRecoveryVelocity, in, info );
				NifStream( malleable.prismatic.motor.positionMotor.constantRecoveryVelocity, in, info );
				NifStream( malleable.prismatic.motor.positionMotor.motorEnabled, in, info );
			};
			if ( (malleable.prismatic.motor.type == 2) ) {
				NifStream( malleable.prismatic.motor.velocityMotor.minForce, in, info );
				NifStream( malleable.prismatic.motor.velocityMotor.maxForce, in, info );
				NifStream( malleable.prismatic.motor.velocityMotor.tau, in, info );
				NifStream( malleable.prismatic.motor.velocityMotor.targetVelocity, in, info );
				NifStream( malleable.prismatic.motor.velocityMotor.useVelocityTarget, in, info );
				NifStream( malleable.prismatic.motor.velocityMotor.motorEnabled, in, info );
			};
			if ( (malleable.prismatic.motor.type == 3) ) {
				NifStream( malleable.prismatic.motor.springDamperMotor.minForce, in, info );
				NifStream( malleable.prismatic.motor.springDamperMotor.maxForce, in, info );
				NifStream( malleable.prismatic.motor.springDamperMotor.springConstant, in, info );
				NifStream( malleable.prismatic.motor.springDamperMotor.springDamping, in, info );
				NifStream( malleable.prismatic.motor.springDamperMotor.motorEnabled, in, info );
			};
		};
	};
	if ( (malleable.type == 7) ) {
		if ( (info.userVersion2 <= 16) ) {
			NifStream( malleable.ragdoll.pivotA, in, info );
			NifStream( malleable.ragdoll.planeA, in, info );
			NifStream( malleable.ragdoll.twistA, in, info );
			NifStream( malleable.ragdoll.pivotB, in, info );
			NifStream( malleable.ragdoll.planeB, in, info );
			NifStream( malleable.ragdoll.twistB, in, info );
		};
		if ( (info.userVersion2 > 16) ) {
			NifStream( (Vector4&)malleable.ragdoll.twistA, in, info );
			NifStream( (Vector4&)malleable.ragdoll.planeA, in, info );
			NifStream( malleable.ragdoll.motorA, in, info );
			NifStream( (Vector4&)malleable.ragdoll.pivotA, in, info );
			NifStream( (Vector4&)malleable.ragdoll.twistB, in, info );
			NifStream( (Vector4&)malleable.ragdoll.planeB, in, info );
			NifStream( malleable.ragdoll.motorB, in, info );
			NifStream( (Vector4&)malleable.ragdoll.pivotB, in, info );
		};
		NifStream( malleable.ragdoll.coneMaxAngle, in, info );
		NifStream( malleable.ragdoll.planeMinAngle, in, info );
		NifStream( malleable.ragdoll.planeMaxAngle, in, info );
		NifStream( malleable.ragdoll.twistMinAngle, in, info );
		NifStream( malleable.ragdoll.twistMaxAngle, in, info );
		NifStream( malleable.ragdoll.maxFriction, in, info );
		if ( ( info.version >= 0x14020007 ) && ( (info.userVersion2 > 16) ) ) {
			NifStream( malleable.ragdoll.motor.type, in, info );
			if ( (malleable.ragdoll.motor.type == 1) ) {
				NifStream( malleable.ragdoll.motor.positionMotor.minForce, in, info );
				NifStream( malleable.ragdoll.motor.positionMotor.maxForce, in, info );
				NifStream( malleable.ragdoll.motor.positionMotor.tau, in, info );
				NifStream( malleable.ragdoll.motor.positionMotor.damping, in, info );
				NifStream( malleable.ragdoll.motor.positionMotor.proportionalRecoveryVelocity, in, info );
				NifStream( malleable.ragdoll.motor.positionMotor.constantRecoveryVelocity, in, info );
				NifStream( malleable.ragdoll.motor.positionMotor.motorEnabled, in, info );
			};
			if ( (malleable.ragdoll.motor.type == 2) ) {
				NifStream( malleable.ragdoll.motor.velocityMotor.minForce, in, info );
				NifStream( malleable.ragdoll.motor.velocityMotor.maxForce, in, info );
				NifStream( malleable.ragdoll.motor.velocityMotor.tau, in, info );
				NifStream( malleable.ragdoll.motor.velocityMotor.targetVelocity, in, info );
				NifStream( malleable.ragdoll.motor.velocityMotor.useVelocityTarget, in, info );
				NifStream( malleable.ragdoll.motor.velocityMotor.motorEnabled, in, info );
			};
			if ( (malleable.ragdoll.motor.type == 3) ) {
				NifStream( malleable.ragdoll.motor.springDamperMotor.minForce, in, info );
				NifStream( malleable.ragdoll.motor.springDamperMotor.maxForce, in, info );
				NifStream( malleable.ragdoll.motor.springDamperMotor.springConstant, in, info );
				NifStream( malleable.ragdoll.motor.springDamperMotor.springDamping, in, info );
				NifStream( malleable.ragdoll.motor.springDamperMotor.motorEnabled, in, info );
			};
		};
	};
	if ( (malleable.type == 8) ) {
		NifStream( malleable.stiffSpring.pivotA, in, info );
		NifStream( malleable.stiffSpring.pivotB, in, info );
		NifStream( malleable.stiffSpring.length, in, info );
	};
	if ( info.version <= 0x14000005 ) {
		NifStream( malleable.tau, in, info );
		NifStream( malleable.damping, in, info );
	};
	if ( info.version >= 0x14020007 ) {
		NifStream( malleable.strength, in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkMalleableConstraint::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConstraint::Write( out, link_map, missing_link_stack, info );
	NifStream( malleable.type, out, info );
	NifStream( malleable.numEntities, out, info );
	WriteRef( StaticCast<NiObject>(malleable.entityA), out, info, link_map, missing_link_stack );
	WriteRef( StaticCast<NiObject>(malleable.entityB), out, info, link_map, missing_link_stack );
	NifStream( malleable.priority, out, info );
	if ( (malleable.type == 0) ) {
		NifStream( malleable.ballAndSocket.pivotA, out, info );
		NifStream( malleable.ballAndSocket.pivotB, out, info );
	};
	if ( (malleable.type == 1) ) {
		if ( info.version <= 0x14000005 ) {
			NifStream( malleable.hinge.pivotA, out, info );
			NifStream( malleable.hinge.perp2AxleInA1, out, info );
			NifStream( malleable.hinge.perp2AxleInA2, out, info );
			NifStream( malleable.hinge.pivotB, out, info );
			NifStream( malleable.hinge.axleB, out, info );
		};
		if ( info.version >= 0x14020007 ) {
			NifStream( malleable.hinge.axleA, out, info );
			NifStream( (Vector4&)malleable.hinge.perp2AxleInA1, out, info );
			NifStream( (Vector4&)malleable.hinge.perp2AxleInA2, out, info );
			NifStream( (Vector4&)malleable.hinge.pivotA, out, info );
			NifStream( (Vector4&)malleable.hinge.axleB, out, info );
			NifStream( malleable.hinge.perp2AxleInB1, out, info );
			NifStream( malleable.hinge.perp2AxleInB2, out, info );
			NifStream( (Vector4&)malleable.hinge.pivotB, out, info );
		};
	};
	if ( (malleable.type == 2) ) {
		if ( (info.userVersion2 <= 16) ) {
			NifStream( malleable.limitedHinge.pivotA, out, info );
			NifStream( malleable.limitedHinge.axleA, out, info );
			NifStream( malleable.limitedHinge.perp2AxleInA1, out, info );
			NifStream( malleable.limitedHinge.perp2AxleInA2, out, info );
			NifStream( malleable.limitedHinge.pivotB, out, info );
			NifStream( malleable.limitedHinge.axleB, out, info );
			NifStream( malleable.limitedHinge.perp2AxleInB2, out, info );
		};
		if ( (info.userVersion2 > 16) ) {
			NifStream( (Vector4&)malleable.limitedHinge.axleA, out, info );
			NifStream( (Vector4&)malleable.limitedHinge.perp2AxleInA1, out, info );
			NifStream( (Vector4&)malleable.limitedHinge.perp2AxleInA2, out, info );
			NifStream( (Vector4&)malleable.limitedHinge.pivotA, out, info );
			NifStream( (Vector4&)malleable.limitedHinge.axleB, out, info );
			NifStream( malleable.limitedHinge.perp2AxleInB1, out, info );
			NifStream( (Vector4&)malleable.limitedHinge.perp2AxleInB2, out, info );
			NifStream( (Vector4&)malleable.limitedHinge.pivotB, out, info );
		};
		NifStream( malleable.limitedHinge.minAngle, out, info );
		NifStream( malleable.limitedHinge.maxAngle, out, info );
		NifStream( malleable.limitedHinge.maxFriction, out, info );
		if ( ( info.version >= 0x14020007 ) && ( (info.userVersion2 > 16) ) ) {
			NifStream( malleable.limitedHinge.motor.type, out, info );
			if ( (malleable.limitedHinge.motor.type == 1) ) {
				NifStream( malleable.limitedHinge.motor.positionMotor.minForce, out, info );
				NifStream( malleable.limitedHinge.motor.positionMotor.maxForce, out, info );
				NifStream( malleable.limitedHinge.motor.positionMotor.tau, out, info );
				NifStream( malleable.limitedHinge.motor.positionMotor.damping, out, info );
				NifStream( malleable.limitedHinge.motor.positionMotor.proportionalRecoveryVelocity, out, info );
				NifStream( malleable.limitedHinge.motor.positionMotor.constantRecoveryVelocity, out, info );
				NifStream( malleable.limitedHinge.motor.positionMotor.motorEnabled, out, info );
			};
			if ( (malleable.limitedHinge.motor.type == 2) ) {
				NifStream( malleable.limitedHinge.motor.velocityMotor.minForce, out, info );
				NifStream( malleable.limitedHinge.motor.velocityMotor.maxForce, out, info );
				NifStream( malleable.limitedHinge.motor.velocityMotor.tau, out, info );
				NifStream( malleable.limitedHinge.motor.velocityMotor.targetVelocity, out, info );
				NifStream( malleable.limitedHinge.motor.velocityMotor.useVelocityTarget, out, info );
				NifStream( malleable.limitedHinge.motor.velocityMotor.motorEnabled, out, info );
			};
			if ( (malleable.limitedHinge.motor.type == 3) ) {
				NifStream( malleable.limitedHinge.motor.springDamperMotor.minForce, out, info );
				NifStream( malleable.limitedHinge.motor.springDamperMotor.maxForce, out, info );
				NifStream( malleable.limitedHinge.motor.springDamperMotor.springConstant, out, info );
				NifStream( malleable.limitedHinge.motor.springDamperMotor.springDamping, out, info );
				NifStream( malleable.limitedHinge.motor.springDamperMotor.motorEnabled, out, info );
			};
		};
	};
	if ( (malleable.type == 6) ) {
		if ( info.version <= 0x14000005 ) {
			NifStream( malleable.prismatic.pivotA, out, info );
			NifStream( malleable.prismatic.rotationA, out, info );
			NifStream( malleable.prismatic.planeA, out, info );
			NifStream( malleable.prismatic.slidingA, out, info );
			NifStream( malleable.prismatic.pivotB, out, info );
			NifStream( malleable.prismatic.rotationB, out, info );
			NifStream( malleable.prismatic.planeB, out, info );
			NifStream( malleable.prismatic.slidingB, out, info );
		};
		if ( info.version >= 0x14020007 ) {
			NifStream( (Vector4&)malleable.prismatic.slidingA, out, info );
			NifStream( (Vector4&)malleable.prismatic.rotationA, out, info );
			NifStream( (Vector4&)malleable.prismatic.planeA, out, info );
			NifStream( (Vector4&)malleable.prismatic.pivotA, out, info );
			NifStream( (Vector4&)malleable.prismatic.slidingB, out, info );
			NifStream( (Vector4&)malleable.prismatic.rotationB, out, info );
			NifStream( (Vector4&)malleable.prismatic.planeB, out, info );
			NifStream( (Vector4&)malleable.prismatic.pivotB, out, info );
		};
		NifStream( malleable.prismatic.minDistance, out, info );
		NifStream( malleable.prismatic.maxDistance, out, info );
		NifStream( malleable.prismatic.friction, out, info );
		if ( ( info.version >= 0x14020007 ) && ( (info.userVersion2 > 16) ) ) {
			NifStream( malleable.prismatic.motor.type, out, info );
			if ( (malleable.prismatic.motor.type == 1) ) {
				NifStream( malleable.prismatic.motor.positionMotor.minForce, out, info );
				NifStream( malleable.prismatic.motor.positionMotor.maxForce, out, info );
				NifStream( malleable.prismatic.motor.positionMotor.tau, out, info );
				NifStream( malleable.prismatic.motor.positionMotor.damping, out, info );
				NifStream( malleable.prismatic.motor.positionMotor.proportionalRecoveryVelocity, out, info );
				NifStream( malleable.prismatic.motor.positionMotor.constantRecoveryVelocity, out, info );
				NifStream( malleable.prismatic.motor.positionMotor.motorEnabled, out, info );
			};
			if ( (malleable.prismatic.motor.type == 2) ) {
				NifStream( malleable.prismatic.motor.velocityMotor.minForce, out, info );
				NifStream( malleable.prismatic.motor.velocityMotor.maxForce, out, info );
				NifStream( malleable.prismatic.motor.velocityMotor.tau, out, info );
				NifStream( malleable.prismatic.motor.velocityMotor.targetVelocity, out, info );
				NifStream( malleable.prismatic.motor.velocityMotor.useVelocityTarget, out, info );
				NifStream( malleable.prismatic.motor.velocityMotor.motorEnabled, out, info );
			};
			if ( (malleable.prismatic.motor.type == 3) ) {
				NifStream( malleable.prismatic.motor.springDamperMotor.minForce, out, info );
				NifStream( malleable.prismatic.motor.springDamperMotor.maxForce, out, info );
				NifStream( malleable.prismatic.motor.springDamperMotor.springConstant, out, info );
				NifStream( malleable.prismatic.motor.springDamperMotor.springDamping, out, info );
				NifStream( malleable.prismatic.motor.springDamperMotor.motorEnabled, out, info );
			};
		};
	};
	if ( (malleable.type == 7) ) {
		if ( (info.userVersion2 <= 16) ) {
			NifStream( malleable.ragdoll.pivotA, out, info );
			NifStream( malleable.ragdoll.planeA, out, info );
			NifStream( malleable.ragdoll.twistA, out, info );
			NifStream( malleable.ragdoll.pivotB, out, info );
			NifStream( malleable.ragdoll.planeB, out, info );
			NifStream( malleable.ragdoll.twistB, out, info );
		};
		if ( (info.userVersion2 > 16) ) {
			NifStream( (Vector4&)malleable.ragdoll.twistA, out, info );
			NifStream( (Vector4&)malleable.ragdoll.planeA, out, info );
			NifStream( malleable.ragdoll.motorA, out, info );
			NifStream( (Vector4&)malleable.ragdoll.pivotA, out, info );
			NifStream( (Vector4&)malleable.ragdoll.twistB, out, info );
			NifStream( (Vector4&)malleable.ragdoll.planeB, out, info );
			NifStream( malleable.ragdoll.motorB, out, info );
			NifStream( (Vector4&)malleable.ragdoll.pivotB, out, info );
		};
		NifStream( malleable.ragdoll.coneMaxAngle, out, info );
		NifStream( malleable.ragdoll.planeMinAngle, out, info );
		NifStream( malleable.ragdoll.planeMaxAngle, out, info );
		NifStream( malleable.ragdoll.twistMinAngle, out, info );
		NifStream( malleable.ragdoll.twistMaxAngle, out, info );
		NifStream( malleable.ragdoll.maxFriction, out, info );
		if ( ( info.version >= 0x14020007 ) && ( (info.userVersion2 > 16) ) ) {
			NifStream( malleable.ragdoll.motor.type, out, info );
			if ( (malleable.ragdoll.motor.type == 1) ) {
				NifStream( malleable.ragdoll.motor.positionMotor.minForce, out, info );
				NifStream( malleable.ragdoll.motor.positionMotor.maxForce, out, info );
				NifStream( malleable.ragdoll.motor.positionMotor.tau, out, info );
				NifStream( malleable.ragdoll.motor.positionMotor.damping, out, info );
				NifStream( malleable.ragdoll.motor.positionMotor.proportionalRecoveryVelocity, out, info );
				NifStream( malleable.ragdoll.motor.positionMotor.constantRecoveryVelocity, out, info );
				NifStream( malleable.ragdoll.motor.positionMotor.motorEnabled, out, info );
			};
			if ( (malleable.ragdoll.motor.type == 2) ) {
				NifStream( malleable.ragdoll.motor.velocityMotor.minForce, out, info );
				NifStream( malleable.ragdoll.motor.velocityMotor.maxForce, out, info );
				NifStream( malleable.ragdoll.motor.velocityMotor.tau, out, info );
				NifStream( malleable.ragdoll.motor.velocityMotor.targetVelocity, out, info );
				NifStream( malleable.ragdoll.motor.velocityMotor.useVelocityTarget, out, info );
				NifStream( malleable.ragdoll.motor.velocityMotor.motorEnabled, out, info );
			};
			if ( (malleable.ragdoll.motor.type == 3) ) {
				NifStream( malleable.ragdoll.motor.springDamperMotor.minForce, out, info );
				NifStream( malleable.ragdoll.motor.springDamperMotor.maxForce, out, info );
				NifStream( malleable.ragdoll.motor.springDamperMotor.springConstant, out, info );
				NifStream( malleable.ragdoll.motor.springDamperMotor.springDamping, out, info );
				NifStream( malleable.ragdoll.motor.springDamperMotor.motorEnabled, out, info );
			};
		};
	};
	if ( (malleable.type == 8) ) {
		NifStream( malleable.stiffSpring.pivotA, out, info );
		NifStream( malleable.stiffSpring.pivotB, out, info );
		NifStream( malleable.stiffSpring.length, out, info );
	};
	if ( info.version <= 0x14000005 ) {
		NifStream( malleable.tau, out, info );
		NifStream( malleable.damping, out, info );
	};
	if ( info.version >= 0x14020007 ) {
		NifStream( malleable.strength, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string bhkMalleableConstraint::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	out << bhkConstraint::asString();
	out << "  Type:  " << malleable.type << endl;
	out << "  Num Entities:  " << malleable.numEntities << endl;
	out << "  Entity A:  " << malleable.entityA << endl;
	out << "  Entity B:  " << malleable.entityB << endl;
	out << "  Priority:  " << malleable.priority << endl;
	if ( (malleable.type == 0) ) {
		out << "    Pivot A:  " << malleable.ballAndSocket.pivotA << endl;
		out << "    Pivot B:  " << malleable.ballAndSocket.pivotB << endl;
	};
	if ( (malleable.type == 1) ) {
		out << "    Pivot A:  " << malleable.hinge.pivotA << endl;
		out << "    Perp2 Axle In A1:  " << malleable.hinge.perp2AxleInA1 << endl;
		out << "    Perp2 Axle In A2:  " << malleable.hinge.perp2AxleInA2 << endl;
		out << "    Pivot B:  " << malleable.hinge.pivotB << endl;
		out << "    Axle B:  " << malleable.hinge.axleB << endl;
		out << "    Axle A:  " << malleable.hinge.axleA << endl;
		out << "    Perp2 Axle In B1:  " << malleable.hinge.perp2AxleInB1 << endl;
		out << "    Perp2 Axle In B2:  " << malleable.hinge.perp2AxleInB2 << endl;
	};
	if ( (malleable.type == 2) ) {
		out << "    Pivot A:  " << malleable.limitedHinge.pivotA << endl;
		out << "    Axle A:  " << malleable.limitedHinge.axleA << endl;
		out << "    Perp2 Axle In A1:  " << malleable.limitedHinge.perp2AxleInA1 << endl;
		out << "    Perp2 Axle In A2:  " << malleable.limitedHinge.perp2AxleInA2 << endl;
		out << "    Pivot B:  " << malleable.limitedHinge.pivotB << endl;
		out << "    Axle B:  " << malleable.limitedHinge.axleB << endl;
		out << "    Perp2 Axle In B2:  " << malleable.limitedHinge.perp2AxleInB2 << endl;
		out << "    Perp2 Axle In B1:  " << malleable.limitedHinge.perp2AxleInB1 << endl;
		out << "    Min Angle:  " << malleable.limitedHinge.minAngle << endl;
		out << "    Max Angle:  " << malleable.limitedHinge.maxAngle << endl;
		out << "    Max Friction:  " << malleable.limitedHinge.maxFriction << endl;
		out << "    Type:  " << malleable.limitedHinge.motor.type << endl;
		if ( (malleable.limitedHinge.motor.type == 1) ) {
			out << "      Min Force:  " << malleable.limitedHinge.motor.positionMotor.minForce << endl;
			out << "      Max Force:  " << malleable.limitedHinge.motor.positionMotor.maxForce << endl;
			out << "      Tau:  " << malleable.limitedHinge.motor.positionMotor.tau << endl;
			out << "      Damping:  " << malleable.limitedHinge.motor.positionMotor.damping << endl;
			out << "      Proportional Recovery Velocity:  " << malleable.limitedHinge.motor.positionMotor.proportionalRecoveryVelocity << endl;
			out << "      Constant Recovery Velocity:  " << malleable.limitedHinge.motor.positionMotor.constantRecoveryVelocity << endl;
			out << "      Motor Enabled:  " << malleable.limitedHinge.motor.positionMotor.motorEnabled << endl;
		};
		if ( (malleable.limitedHinge.motor.type == 2) ) {
			out << "      Min Force:  " << malleable.limitedHinge.motor.velocityMotor.minForce << endl;
			out << "      Max Force:  " << malleable.limitedHinge.motor.velocityMotor.maxForce << endl;
			out << "      Tau:  " << malleable.limitedHinge.motor.velocityMotor.tau << endl;
			out << "      Target Velocity:  " << malleable.limitedHinge.motor.velocityMotor.targetVelocity << endl;
			out << "      Use Velocity Target:  " << malleable.limitedHinge.motor.velocityMotor.useVelocityTarget << endl;
			out << "      Motor Enabled:  " << malleable.limitedHinge.motor.velocityMotor.motorEnabled << endl;
		};
		if ( (malleable.limitedHinge.motor.type == 3) ) {
			out << "      Min Force:  " << malleable.limitedHinge.motor.springDamperMotor.minForce << endl;
			out << "      Max Force:  " << malleable.limitedHinge.motor.springDamperMotor.maxForce << endl;
			out << "      Spring Constant:  " << malleable.limitedHinge.motor.springDamperMotor.springConstant << endl;
			out << "      Spring Damping:  " << malleable.limitedHinge.motor.springDamperMotor.springDamping << endl;
			out << "      Motor Enabled:  " << malleable.limitedHinge.motor.springDamperMotor.motorEnabled << endl;
		};
	};
	if ( (malleable.type == 6) ) {
		out << "    Pivot A:  " << malleable.prismatic.pivotA << endl;
		out << "    Rotation A:  " << malleable.prismatic.rotationA << endl;
		out << "    Plane A:  " << malleable.prismatic.planeA << endl;
		out << "    Sliding A:  " << malleable.prismatic.slidingA << endl;
		out << "    Pivot B:  " << malleable.prismatic.pivotB << endl;
		out << "    Rotation B:  " << malleable.prismatic.rotationB << endl;
		out << "    Plane B:  " << malleable.prismatic.planeB << endl;
		out << "    Sliding B:  " << malleable.prismatic.slidingB << endl;
		out << "    Min Distance:  " << malleable.prismatic.minDistance << endl;
		out << "    Max Distance:  " << malleable.prismatic.maxDistance << endl;
		out << "    Friction:  " << malleable.prismatic.friction << endl;
		out << "    Type:  " << malleable.prismatic.motor.type << endl;
		if ( (malleable.prismatic.motor.type == 1) ) {
			out << "      Min Force:  " << malleable.prismatic.motor.positionMotor.minForce << endl;
			out << "      Max Force:  " << malleable.prismatic.motor.positionMotor.maxForce << endl;
			out << "      Tau:  " << malleable.prismatic.motor.positionMotor.tau << endl;
			out << "      Damping:  " << malleable.prismatic.motor.positionMotor.damping << endl;
			out << "      Proportional Recovery Velocity:  " << malleable.prismatic.motor.positionMotor.proportionalRecoveryVelocity << endl;
			out << "      Constant Recovery Velocity:  " << malleable.prismatic.motor.positionMotor.constantRecoveryVelocity << endl;
			out << "      Motor Enabled:  " << malleable.prismatic.motor.positionMotor.motorEnabled << endl;
		};
		if ( (malleable.prismatic.motor.type == 2) ) {
			out << "      Min Force:  " << malleable.prismatic.motor.velocityMotor.minForce << endl;
			out << "      Max Force:  " << malleable.prismatic.motor.velocityMotor.maxForce << endl;
			out << "      Tau:  " << malleable.prismatic.motor.velocityMotor.tau << endl;
			out << "      Target Velocity:  " << malleable.prismatic.motor.velocityMotor.targetVelocity << endl;
			out << "      Use Velocity Target:  " << malleable.prismatic.motor.velocityMotor.useVelocityTarget << endl;
			out << "      Motor Enabled:  " << malleable.prismatic.motor.velocityMotor.motorEnabled << endl;
		};
		if ( (malleable.prismatic.motor.type == 3) ) {
			out << "      Min Force:  " << malleable.prismatic.motor.springDamperMotor.minForce << endl;
			out << "      Max Force:  " << malleable.prismatic.motor.springDamperMotor.maxForce << endl;
			out << "      Spring Constant:  " << malleable.prismatic.motor.springDamperMotor.springConstant << endl;
			out << "      Spring Damping:  " << malleable.prismatic.motor.springDamperMotor.springDamping << endl;
			out << "      Motor Enabled:  " << malleable.prismatic.motor.springDamperMotor.motorEnabled << endl;
		};
	};
	if ( (malleable.type == 7) ) {
		out << "    Pivot A:  " << malleable.ragdoll.pivotA << endl;
		out << "    Plane A:  " << malleable.ragdoll.planeA << endl;
		out << "    Twist A:  " << malleable.ragdoll.twistA << endl;
		out << "    Pivot B:  " << malleable.ragdoll.pivotB << endl;
		out << "    Plane B:  " << malleable.ragdoll.planeB << endl;
		out << "    Twist B:  " << malleable.ragdoll.twistB << endl;
		out << "    Motor A:  " << malleable.ragdoll.motorA << endl;
		out << "    Motor B:  " << malleable.ragdoll.motorB << endl;
		out << "    Cone Max Angle:  " << malleable.ragdoll.coneMaxAngle << endl;
		out << "    Plane Min Angle:  " << malleable.ragdoll.planeMinAngle << endl;
		out << "    Plane Max Angle:  " << malleable.ragdoll.planeMaxAngle << endl;
		out << "    Twist Min Angle:  " << malleable.ragdoll.twistMinAngle << endl;
		out << "    Twist Max Angle:  " << malleable.ragdoll.twistMaxAngle << endl;
		out << "    Max Friction:  " << malleable.ragdoll.maxFriction << endl;
		out << "    Type:  " << malleable.ragdoll.motor.type << endl;
		if ( (malleable.ragdoll.motor.type == 1) ) {
			out << "      Min Force:  " << malleable.ragdoll.motor.positionMotor.minForce << endl;
			out << "      Max Force:  " << malleable.ragdoll.motor.positionMotor.maxForce << endl;
			out << "      Tau:  " << malleable.ragdoll.motor.positionMotor.tau << endl;
			out << "      Damping:  " << malleable.ragdoll.motor.positionMotor.damping << endl;
			out << "      Proportional Recovery Velocity:  " << malleable.ragdoll.motor.positionMotor.proportionalRecoveryVelocity << endl;
			out << "      Constant Recovery Velocity:  " << malleable.ragdoll.motor.positionMotor.constantRecoveryVelocity << endl;
			out << "      Motor Enabled:  " << malleable.ragdoll.motor.positionMotor.motorEnabled << endl;
		};
		if ( (malleable.ragdoll.motor.type == 2) ) {
			out << "      Min Force:  " << malleable.ragdoll.motor.velocityMotor.minForce << endl;
			out << "      Max Force:  " << malleable.ragdoll.motor.velocityMotor.maxForce << endl;
			out << "      Tau:  " << malleable.ragdoll.motor.velocityMotor.tau << endl;
			out << "      Target Velocity:  " << malleable.ragdoll.motor.velocityMotor.targetVelocity << endl;
			out << "      Use Velocity Target:  " << malleable.ragdoll.motor.velocityMotor.useVelocityTarget << endl;
			out << "      Motor Enabled:  " << malleable.ragdoll.motor.velocityMotor.motorEnabled << endl;
		};
		if ( (malleable.ragdoll.motor.type == 3) ) {
			out << "      Min Force:  " << malleable.ragdoll.motor.springDamperMotor.minForce << endl;
			out << "      Max Force:  " << malleable.ragdoll.motor.springDamperMotor.maxForce << endl;
			out << "      Spring Constant:  " << malleable.ragdoll.motor.springDamperMotor.springConstant << endl;
			out << "      Spring Damping:  " << malleable.ragdoll.motor.springDamperMotor.springDamping << endl;
			out << "      Motor Enabled:  " << malleable.ragdoll.motor.springDamperMotor.motorEnabled << endl;
		};
	};
	if ( (malleable.type == 8) ) {
		out << "    Pivot A:  " << malleable.stiffSpring.pivotA << endl;
		out << "    Pivot B:  " << malleable.stiffSpring.pivotB << endl;
		out << "    Length:  " << malleable.stiffSpring.length << endl;
	};
	out << "  Tau:  " << malleable.tau << endl;
	out << "  Damping:  " << malleable.damping << endl;
	out << "  Strength:  " << malleable.strength << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkMalleableConstraint::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConstraint::FixLinks( objects, link_stack, missing_link_stack, info );
	malleable.entityA = FixLink<bhkEntity>( objects, link_stack, missing_link_stack, info );
	malleable.entityB = FixLink<bhkEntity>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> bhkMalleableConstraint::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkConstraint::GetRefs();
	return refs;
}

std::list<NiObject *> bhkMalleableConstraint::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = bhkConstraint::GetPtrs();
	if ( malleable.entityA != NULL )
		ptrs.push_back((NiObject *)(malleable.entityA));
	if ( malleable.entityB != NULL )
		ptrs.push_back((NiObject *)(malleable.entityB));
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//

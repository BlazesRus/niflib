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
#include "../../include/obj/bhkBreakableConstraint.h"
#include "../../include/gen/BallAndSocketDescriptor.h"
#include "../../include/gen/ConstraintData.h"
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
const Type bhkBreakableConstraint::TYPE("bhkBreakableConstraint", &bhkConstraint::TYPE );

bhkBreakableConstraint::bhkBreakableConstraint() : threshold(0.0f), removeWhenBroken(0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

bhkBreakableConstraint::~bhkBreakableConstraint() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & bhkBreakableConstraint::GetType() const {
	return TYPE;
}

NiObject * bhkBreakableConstraint::Create() {
	return new bhkBreakableConstraint;
}

void bhkBreakableConstraint::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	bhkConstraint::Read( in, link_stack, info );
	NifStream( constraintData.type, in, info );
	NifStream( constraintData.numEntities2, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( constraintData.priority, in, info );
	if ( (constraintData.type == 0) ) {
		NifStream( constraintData.ballAndSocket.pivotA, in, info );
		NifStream( constraintData.ballAndSocket.pivotB, in, info );
	};
	if ( (constraintData.type == 1) ) {
		if ( info.version <= 0x14000005 ) {
			NifStream( constraintData.hinge.pivotA, in, info );
			NifStream( constraintData.hinge.perp2AxleInA1, in, info );
			NifStream( constraintData.hinge.perp2AxleInA2, in, info );
			NifStream( constraintData.hinge.pivotB, in, info );
			NifStream( constraintData.hinge.axleB, in, info );
		};
		if ( info.version >= 0x14020007 ) {
			NifStream( constraintData.hinge.axleA, in, info );
			NifStream( (Vector4&)constraintData.hinge.perp2AxleInA1, in, info );
			NifStream( (Vector4&)constraintData.hinge.perp2AxleInA2, in, info );
			NifStream( (Vector4&)constraintData.hinge.pivotA, in, info );
			NifStream( (Vector4&)constraintData.hinge.axleB, in, info );
			NifStream( constraintData.hinge.perp2AxleInB1, in, info );
			NifStream( constraintData.hinge.perp2AxleInB2, in, info );
			NifStream( (Vector4&)constraintData.hinge.pivotB, in, info );
		};
	};
	if ( (constraintData.type == 2) ) {
		if ( (info.userVersion2 <= 16) ) {
			NifStream( constraintData.limitedHinge.pivotA, in, info );
			NifStream( constraintData.limitedHinge.axleA, in, info );
			NifStream( constraintData.limitedHinge.perp2AxleInA1, in, info );
			NifStream( constraintData.limitedHinge.perp2AxleInA2, in, info );
			NifStream( constraintData.limitedHinge.pivotB, in, info );
			NifStream( constraintData.limitedHinge.axleB, in, info );
			NifStream( constraintData.limitedHinge.perp2AxleInB2, in, info );
		};
		if ( (info.userVersion2 > 16) ) {
			NifStream( (Vector4&)constraintData.limitedHinge.axleA, in, info );
			NifStream( (Vector4&)constraintData.limitedHinge.perp2AxleInA1, in, info );
			NifStream( (Vector4&)constraintData.limitedHinge.perp2AxleInA2, in, info );
			NifStream( (Vector4&)constraintData.limitedHinge.pivotA, in, info );
			NifStream( (Vector4&)constraintData.limitedHinge.axleB, in, info );
			NifStream( constraintData.limitedHinge.perp2AxleInB1, in, info );
			NifStream( (Vector4&)constraintData.limitedHinge.perp2AxleInB2, in, info );
			NifStream( (Vector4&)constraintData.limitedHinge.pivotB, in, info );
		};
		NifStream( constraintData.limitedHinge.minAngle, in, info );
		NifStream( constraintData.limitedHinge.maxAngle, in, info );
		NifStream( constraintData.limitedHinge.maxFriction, in, info );
		if ( ( info.version >= 0x14020007 ) && ( (info.userVersion2 > 16) ) ) {
			NifStream( constraintData.limitedHinge.motor.type, in, info );
			if ( (constraintData.limitedHinge.motor.type == 1) ) {
				NifStream( constraintData.limitedHinge.motor.positionMotor.minForce, in, info );
				NifStream( constraintData.limitedHinge.motor.positionMotor.maxForce, in, info );
				NifStream( constraintData.limitedHinge.motor.positionMotor.tau, in, info );
				NifStream( constraintData.limitedHinge.motor.positionMotor.damping, in, info );
				NifStream( constraintData.limitedHinge.motor.positionMotor.proportionalRecoveryVelocity, in, info );
				NifStream( constraintData.limitedHinge.motor.positionMotor.constantRecoveryVelocity, in, info );
				NifStream( constraintData.limitedHinge.motor.positionMotor.motorEnabled, in, info );
			};
			if ( (constraintData.limitedHinge.motor.type == 2) ) {
				NifStream( constraintData.limitedHinge.motor.velocityMotor.minForce, in, info );
				NifStream( constraintData.limitedHinge.motor.velocityMotor.maxForce, in, info );
				NifStream( constraintData.limitedHinge.motor.velocityMotor.tau, in, info );
				NifStream( constraintData.limitedHinge.motor.velocityMotor.targetVelocity, in, info );
				NifStream( constraintData.limitedHinge.motor.velocityMotor.useVelocityTarget, in, info );
				NifStream( constraintData.limitedHinge.motor.velocityMotor.motorEnabled, in, info );
			};
			if ( (constraintData.limitedHinge.motor.type == 3) ) {
				NifStream( constraintData.limitedHinge.motor.springDamperMotor.minForce, in, info );
				NifStream( constraintData.limitedHinge.motor.springDamperMotor.maxForce, in, info );
				NifStream( constraintData.limitedHinge.motor.springDamperMotor.springConstant, in, info );
				NifStream( constraintData.limitedHinge.motor.springDamperMotor.springDamping, in, info );
				NifStream( constraintData.limitedHinge.motor.springDamperMotor.motorEnabled, in, info );
			};
		};
	};
	if ( (constraintData.type == 6) ) {
		if ( info.version <= 0x14000005 ) {
			NifStream( constraintData.prismatic.pivotA, in, info );
			NifStream( constraintData.prismatic.rotationA, in, info );
			NifStream( constraintData.prismatic.planeA, in, info );
			NifStream( constraintData.prismatic.slidingA, in, info );
			NifStream( constraintData.prismatic.pivotB, in, info );
			NifStream( constraintData.prismatic.rotationB, in, info );
			NifStream( constraintData.prismatic.planeB, in, info );
			NifStream( constraintData.prismatic.slidingB, in, info );
		};
		if ( info.version >= 0x14020007 ) {
			NifStream( (Vector4&)constraintData.prismatic.slidingA, in, info );
			NifStream( (Vector4&)constraintData.prismatic.rotationA, in, info );
			NifStream( (Vector4&)constraintData.prismatic.planeA, in, info );
			NifStream( (Vector4&)constraintData.prismatic.pivotA, in, info );
			NifStream( (Vector4&)constraintData.prismatic.slidingB, in, info );
			NifStream( (Vector4&)constraintData.prismatic.rotationB, in, info );
			NifStream( (Vector4&)constraintData.prismatic.planeB, in, info );
			NifStream( (Vector4&)constraintData.prismatic.pivotB, in, info );
		};
		NifStream( constraintData.prismatic.minDistance, in, info );
		NifStream( constraintData.prismatic.maxDistance, in, info );
		NifStream( constraintData.prismatic.friction, in, info );
		if ( ( info.version >= 0x14020007 ) && ( (info.userVersion2 > 16) ) ) {
			NifStream( constraintData.prismatic.motor.type, in, info );
			if ( (constraintData.prismatic.motor.type == 1) ) {
				NifStream( constraintData.prismatic.motor.positionMotor.minForce, in, info );
				NifStream( constraintData.prismatic.motor.positionMotor.maxForce, in, info );
				NifStream( constraintData.prismatic.motor.positionMotor.tau, in, info );
				NifStream( constraintData.prismatic.motor.positionMotor.damping, in, info );
				NifStream( constraintData.prismatic.motor.positionMotor.proportionalRecoveryVelocity, in, info );
				NifStream( constraintData.prismatic.motor.positionMotor.constantRecoveryVelocity, in, info );
				NifStream( constraintData.prismatic.motor.positionMotor.motorEnabled, in, info );
			};
			if ( (constraintData.prismatic.motor.type == 2) ) {
				NifStream( constraintData.prismatic.motor.velocityMotor.minForce, in, info );
				NifStream( constraintData.prismatic.motor.velocityMotor.maxForce, in, info );
				NifStream( constraintData.prismatic.motor.velocityMotor.tau, in, info );
				NifStream( constraintData.prismatic.motor.velocityMotor.targetVelocity, in, info );
				NifStream( constraintData.prismatic.motor.velocityMotor.useVelocityTarget, in, info );
				NifStream( constraintData.prismatic.motor.velocityMotor.motorEnabled, in, info );
			};
			if ( (constraintData.prismatic.motor.type == 3) ) {
				NifStream( constraintData.prismatic.motor.springDamperMotor.minForce, in, info );
				NifStream( constraintData.prismatic.motor.springDamperMotor.maxForce, in, info );
				NifStream( constraintData.prismatic.motor.springDamperMotor.springConstant, in, info );
				NifStream( constraintData.prismatic.motor.springDamperMotor.springDamping, in, info );
				NifStream( constraintData.prismatic.motor.springDamperMotor.motorEnabled, in, info );
			};
		};
	};
	if ( (constraintData.type == 7) ) {
		if ( (info.userVersion2 <= 16) ) {
			NifStream( constraintData.ragdoll.pivotA, in, info );
			NifStream( constraintData.ragdoll.planeA, in, info );
			NifStream( constraintData.ragdoll.twistA, in, info );
			NifStream( constraintData.ragdoll.pivotB, in, info );
			NifStream( constraintData.ragdoll.planeB, in, info );
			NifStream( constraintData.ragdoll.twistB, in, info );
		};
		if ( (info.userVersion2 > 16) ) {
			NifStream( (Vector4&)constraintData.ragdoll.twistA, in, info );
			NifStream( (Vector4&)constraintData.ragdoll.planeA, in, info );
			NifStream( constraintData.ragdoll.motorA, in, info );
			NifStream( (Vector4&)constraintData.ragdoll.pivotA, in, info );
			NifStream( (Vector4&)constraintData.ragdoll.twistB, in, info );
			NifStream( (Vector4&)constraintData.ragdoll.planeB, in, info );
			NifStream( constraintData.ragdoll.motorB, in, info );
			NifStream( (Vector4&)constraintData.ragdoll.pivotB, in, info );
		};
		NifStream( constraintData.ragdoll.coneMaxAngle, in, info );
		NifStream( constraintData.ragdoll.planeMinAngle, in, info );
		NifStream( constraintData.ragdoll.planeMaxAngle, in, info );
		NifStream( constraintData.ragdoll.twistMinAngle, in, info );
		NifStream( constraintData.ragdoll.twistMaxAngle, in, info );
		NifStream( constraintData.ragdoll.maxFriction, in, info );
		if ( ( info.version >= 0x14020007 ) && ( (info.userVersion2 > 16) ) ) {
			NifStream( constraintData.ragdoll.motor.type, in, info );
			if ( (constraintData.ragdoll.motor.type == 1) ) {
				NifStream( constraintData.ragdoll.motor.positionMotor.minForce, in, info );
				NifStream( constraintData.ragdoll.motor.positionMotor.maxForce, in, info );
				NifStream( constraintData.ragdoll.motor.positionMotor.tau, in, info );
				NifStream( constraintData.ragdoll.motor.positionMotor.damping, in, info );
				NifStream( constraintData.ragdoll.motor.positionMotor.proportionalRecoveryVelocity, in, info );
				NifStream( constraintData.ragdoll.motor.positionMotor.constantRecoveryVelocity, in, info );
				NifStream( constraintData.ragdoll.motor.positionMotor.motorEnabled, in, info );
			};
			if ( (constraintData.ragdoll.motor.type == 2) ) {
				NifStream( constraintData.ragdoll.motor.velocityMotor.minForce, in, info );
				NifStream( constraintData.ragdoll.motor.velocityMotor.maxForce, in, info );
				NifStream( constraintData.ragdoll.motor.velocityMotor.tau, in, info );
				NifStream( constraintData.ragdoll.motor.velocityMotor.targetVelocity, in, info );
				NifStream( constraintData.ragdoll.motor.velocityMotor.useVelocityTarget, in, info );
				NifStream( constraintData.ragdoll.motor.velocityMotor.motorEnabled, in, info );
			};
			if ( (constraintData.ragdoll.motor.type == 3) ) {
				NifStream( constraintData.ragdoll.motor.springDamperMotor.minForce, in, info );
				NifStream( constraintData.ragdoll.motor.springDamperMotor.maxForce, in, info );
				NifStream( constraintData.ragdoll.motor.springDamperMotor.springConstant, in, info );
				NifStream( constraintData.ragdoll.motor.springDamperMotor.springDamping, in, info );
				NifStream( constraintData.ragdoll.motor.springDamperMotor.motorEnabled, in, info );
			};
		};
	};
	if ( (constraintData.type == 8) ) {
		NifStream( constraintData.stiffSpring.pivotA, in, info );
		NifStream( constraintData.stiffSpring.pivotB, in, info );
		NifStream( constraintData.stiffSpring.length, in, info );
	};
	if ( (constraintData.type == 13) ) {
		NifStream( constraintData.malleable.type, in, info );
		NifStream( constraintData.malleable.numEntities, in, info );
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
		NifStream( constraintData.malleable.priority, in, info );
		if ( (constraintData.malleable.type == 0) ) {
			NifStream( constraintData.malleable.ballAndSocket.pivotA, in, info );
			NifStream( constraintData.malleable.ballAndSocket.pivotB, in, info );
		};
		if ( (constraintData.malleable.type == 1) ) {
			if ( info.version <= 0x14000005 ) {
				NifStream( constraintData.malleable.hinge.pivotA, in, info );
				NifStream( constraintData.malleable.hinge.perp2AxleInA1, in, info );
				NifStream( constraintData.malleable.hinge.perp2AxleInA2, in, info );
				NifStream( constraintData.malleable.hinge.pivotB, in, info );
				NifStream( constraintData.malleable.hinge.axleB, in, info );
			};
			if ( info.version >= 0x14020007 ) {
				NifStream( constraintData.malleable.hinge.axleA, in, info );
				NifStream( (Vector4&)constraintData.malleable.hinge.perp2AxleInA1, in, info );
				NifStream( (Vector4&)constraintData.malleable.hinge.perp2AxleInA2, in, info );
				NifStream( (Vector4&)constraintData.malleable.hinge.pivotA, in, info );
				NifStream( (Vector4&)constraintData.malleable.hinge.axleB, in, info );
				NifStream( constraintData.malleable.hinge.perp2AxleInB1, in, info );
				NifStream( constraintData.malleable.hinge.perp2AxleInB2, in, info );
				NifStream( (Vector4&)constraintData.malleable.hinge.pivotB, in, info );
			};
		};
		if ( (constraintData.malleable.type == 2) ) {
			if ( (info.userVersion2 <= 16) ) {
				NifStream( constraintData.malleable.limitedHinge.pivotA, in, info );
				NifStream( constraintData.malleable.limitedHinge.axleA, in, info );
				NifStream( constraintData.malleable.limitedHinge.perp2AxleInA1, in, info );
				NifStream( constraintData.malleable.limitedHinge.perp2AxleInA2, in, info );
				NifStream( constraintData.malleable.limitedHinge.pivotB, in, info );
				NifStream( constraintData.malleable.limitedHinge.axleB, in, info );
				NifStream( constraintData.malleable.limitedHinge.perp2AxleInB2, in, info );
			};
			if ( (info.userVersion2 > 16) ) {
				NifStream( (Vector4&)constraintData.malleable.limitedHinge.axleA, in, info );
				NifStream( (Vector4&)constraintData.malleable.limitedHinge.perp2AxleInA1, in, info );
				NifStream( (Vector4&)constraintData.malleable.limitedHinge.perp2AxleInA2, in, info );
				NifStream( (Vector4&)constraintData.malleable.limitedHinge.pivotA, in, info );
				NifStream( (Vector4&)constraintData.malleable.limitedHinge.axleB, in, info );
				NifStream( constraintData.malleable.limitedHinge.perp2AxleInB1, in, info );
				NifStream( (Vector4&)constraintData.malleable.limitedHinge.perp2AxleInB2, in, info );
				NifStream( (Vector4&)constraintData.malleable.limitedHinge.pivotB, in, info );
			};
			NifStream( constraintData.malleable.limitedHinge.minAngle, in, info );
			NifStream( constraintData.malleable.limitedHinge.maxAngle, in, info );
			NifStream( constraintData.malleable.limitedHinge.maxFriction, in, info );
			if ( ( info.version >= 0x14020007 ) && ( (info.userVersion2 > 16) ) ) {
				NifStream( constraintData.malleable.limitedHinge.motor.type, in, info );
				if ( (constraintData.malleable.limitedHinge.motor.type == 1) ) {
					NifStream( constraintData.malleable.limitedHinge.motor.positionMotor.minForce, in, info );
					NifStream( constraintData.malleable.limitedHinge.motor.positionMotor.maxForce, in, info );
					NifStream( constraintData.malleable.limitedHinge.motor.positionMotor.tau, in, info );
					NifStream( constraintData.malleable.limitedHinge.motor.positionMotor.damping, in, info );
					NifStream( constraintData.malleable.limitedHinge.motor.positionMotor.proportionalRecoveryVelocity, in, info );
					NifStream( constraintData.malleable.limitedHinge.motor.positionMotor.constantRecoveryVelocity, in, info );
					NifStream( constraintData.malleable.limitedHinge.motor.positionMotor.motorEnabled, in, info );
				};
				if ( (constraintData.malleable.limitedHinge.motor.type == 2) ) {
					NifStream( constraintData.malleable.limitedHinge.motor.velocityMotor.minForce, in, info );
					NifStream( constraintData.malleable.limitedHinge.motor.velocityMotor.maxForce, in, info );
					NifStream( constraintData.malleable.limitedHinge.motor.velocityMotor.tau, in, info );
					NifStream( constraintData.malleable.limitedHinge.motor.velocityMotor.targetVelocity, in, info );
					NifStream( constraintData.malleable.limitedHinge.motor.velocityMotor.useVelocityTarget, in, info );
					NifStream( constraintData.malleable.limitedHinge.motor.velocityMotor.motorEnabled, in, info );
				};
				if ( (constraintData.malleable.limitedHinge.motor.type == 3) ) {
					NifStream( constraintData.malleable.limitedHinge.motor.springDamperMotor.minForce, in, info );
					NifStream( constraintData.malleable.limitedHinge.motor.springDamperMotor.maxForce, in, info );
					NifStream( constraintData.malleable.limitedHinge.motor.springDamperMotor.springConstant, in, info );
					NifStream( constraintData.malleable.limitedHinge.motor.springDamperMotor.springDamping, in, info );
					NifStream( constraintData.malleable.limitedHinge.motor.springDamperMotor.motorEnabled, in, info );
				};
			};
		};
		if ( (constraintData.malleable.type == 6) ) {
			if ( info.version <= 0x14000005 ) {
				NifStream( constraintData.malleable.prismatic.pivotA, in, info );
				NifStream( constraintData.malleable.prismatic.rotationA, in, info );
				NifStream( constraintData.malleable.prismatic.planeA, in, info );
				NifStream( constraintData.malleable.prismatic.slidingA, in, info );
				NifStream( constraintData.malleable.prismatic.pivotB, in, info );
				NifStream( constraintData.malleable.prismatic.rotationB, in, info );
				NifStream( constraintData.malleable.prismatic.planeB, in, info );
				NifStream( constraintData.malleable.prismatic.slidingB, in, info );
			};
			if ( info.version >= 0x14020007 ) {
				NifStream( (Vector4&)constraintData.malleable.prismatic.slidingA, in, info );
				NifStream( (Vector4&)constraintData.malleable.prismatic.rotationA, in, info );
				NifStream( (Vector4&)constraintData.malleable.prismatic.planeA, in, info );
				NifStream( (Vector4&)constraintData.malleable.prismatic.pivotA, in, info );
				NifStream( (Vector4&)constraintData.malleable.prismatic.slidingB, in, info );
				NifStream( (Vector4&)constraintData.malleable.prismatic.rotationB, in, info );
				NifStream( (Vector4&)constraintData.malleable.prismatic.planeB, in, info );
				NifStream( (Vector4&)constraintData.malleable.prismatic.pivotB, in, info );
			};
			NifStream( constraintData.malleable.prismatic.minDistance, in, info );
			NifStream( constraintData.malleable.prismatic.maxDistance, in, info );
			NifStream( constraintData.malleable.prismatic.friction, in, info );
			if ( ( info.version >= 0x14020007 ) && ( (info.userVersion2 > 16) ) ) {
				NifStream( constraintData.malleable.prismatic.motor.type, in, info );
				if ( (constraintData.malleable.prismatic.motor.type == 1) ) {
					NifStream( constraintData.malleable.prismatic.motor.positionMotor.minForce, in, info );
					NifStream( constraintData.malleable.prismatic.motor.positionMotor.maxForce, in, info );
					NifStream( constraintData.malleable.prismatic.motor.positionMotor.tau, in, info );
					NifStream( constraintData.malleable.prismatic.motor.positionMotor.damping, in, info );
					NifStream( constraintData.malleable.prismatic.motor.positionMotor.proportionalRecoveryVelocity, in, info );
					NifStream( constraintData.malleable.prismatic.motor.positionMotor.constantRecoveryVelocity, in, info );
					NifStream( constraintData.malleable.prismatic.motor.positionMotor.motorEnabled, in, info );
				};
				if ( (constraintData.malleable.prismatic.motor.type == 2) ) {
					NifStream( constraintData.malleable.prismatic.motor.velocityMotor.minForce, in, info );
					NifStream( constraintData.malleable.prismatic.motor.velocityMotor.maxForce, in, info );
					NifStream( constraintData.malleable.prismatic.motor.velocityMotor.tau, in, info );
					NifStream( constraintData.malleable.prismatic.motor.velocityMotor.targetVelocity, in, info );
					NifStream( constraintData.malleable.prismatic.motor.velocityMotor.useVelocityTarget, in, info );
					NifStream( constraintData.malleable.prismatic.motor.velocityMotor.motorEnabled, in, info );
				};
				if ( (constraintData.malleable.prismatic.motor.type == 3) ) {
					NifStream( constraintData.malleable.prismatic.motor.springDamperMotor.minForce, in, info );
					NifStream( constraintData.malleable.prismatic.motor.springDamperMotor.maxForce, in, info );
					NifStream( constraintData.malleable.prismatic.motor.springDamperMotor.springConstant, in, info );
					NifStream( constraintData.malleable.prismatic.motor.springDamperMotor.springDamping, in, info );
					NifStream( constraintData.malleable.prismatic.motor.springDamperMotor.motorEnabled, in, info );
				};
			};
		};
		if ( (constraintData.malleable.type == 7) ) {
			if ( (info.userVersion2 <= 16) ) {
				NifStream( constraintData.malleable.ragdoll.pivotA, in, info );
				NifStream( constraintData.malleable.ragdoll.planeA, in, info );
				NifStream( constraintData.malleable.ragdoll.twistA, in, info );
				NifStream( constraintData.malleable.ragdoll.pivotB, in, info );
				NifStream( constraintData.malleable.ragdoll.planeB, in, info );
				NifStream( constraintData.malleable.ragdoll.twistB, in, info );
			};
			if ( (info.userVersion2 > 16) ) {
				NifStream( (Vector4&)constraintData.malleable.ragdoll.twistA, in, info );
				NifStream( (Vector4&)constraintData.malleable.ragdoll.planeA, in, info );
				NifStream( constraintData.malleable.ragdoll.motorA, in, info );
				NifStream( (Vector4&)constraintData.malleable.ragdoll.pivotA, in, info );
				NifStream( (Vector4&)constraintData.malleable.ragdoll.twistB, in, info );
				NifStream( (Vector4&)constraintData.malleable.ragdoll.planeB, in, info );
				NifStream( constraintData.malleable.ragdoll.motorB, in, info );
				NifStream( (Vector4&)constraintData.malleable.ragdoll.pivotB, in, info );
			};
			NifStream( constraintData.malleable.ragdoll.coneMaxAngle, in, info );
			NifStream( constraintData.malleable.ragdoll.planeMinAngle, in, info );
			NifStream( constraintData.malleable.ragdoll.planeMaxAngle, in, info );
			NifStream( constraintData.malleable.ragdoll.twistMinAngle, in, info );
			NifStream( constraintData.malleable.ragdoll.twistMaxAngle, in, info );
			NifStream( constraintData.malleable.ragdoll.maxFriction, in, info );
			if ( ( info.version >= 0x14020007 ) && ( (info.userVersion2 > 16) ) ) {
				NifStream( constraintData.malleable.ragdoll.motor.type, in, info );
				if ( (constraintData.malleable.ragdoll.motor.type == 1) ) {
					NifStream( constraintData.malleable.ragdoll.motor.positionMotor.minForce, in, info );
					NifStream( constraintData.malleable.ragdoll.motor.positionMotor.maxForce, in, info );
					NifStream( constraintData.malleable.ragdoll.motor.positionMotor.tau, in, info );
					NifStream( constraintData.malleable.ragdoll.motor.positionMotor.damping, in, info );
					NifStream( constraintData.malleable.ragdoll.motor.positionMotor.proportionalRecoveryVelocity, in, info );
					NifStream( constraintData.malleable.ragdoll.motor.positionMotor.constantRecoveryVelocity, in, info );
					NifStream( constraintData.malleable.ragdoll.motor.positionMotor.motorEnabled, in, info );
				};
				if ( (constraintData.malleable.ragdoll.motor.type == 2) ) {
					NifStream( constraintData.malleable.ragdoll.motor.velocityMotor.minForce, in, info );
					NifStream( constraintData.malleable.ragdoll.motor.velocityMotor.maxForce, in, info );
					NifStream( constraintData.malleable.ragdoll.motor.velocityMotor.tau, in, info );
					NifStream( constraintData.malleable.ragdoll.motor.velocityMotor.targetVelocity, in, info );
					NifStream( constraintData.malleable.ragdoll.motor.velocityMotor.useVelocityTarget, in, info );
					NifStream( constraintData.malleable.ragdoll.motor.velocityMotor.motorEnabled, in, info );
				};
				if ( (constraintData.malleable.ragdoll.motor.type == 3) ) {
					NifStream( constraintData.malleable.ragdoll.motor.springDamperMotor.minForce, in, info );
					NifStream( constraintData.malleable.ragdoll.motor.springDamperMotor.maxForce, in, info );
					NifStream( constraintData.malleable.ragdoll.motor.springDamperMotor.springConstant, in, info );
					NifStream( constraintData.malleable.ragdoll.motor.springDamperMotor.springDamping, in, info );
					NifStream( constraintData.malleable.ragdoll.motor.springDamperMotor.motorEnabled, in, info );
				};
			};
		};
		if ( (constraintData.malleable.type == 8) ) {
			NifStream( constraintData.malleable.stiffSpring.pivotA, in, info );
			NifStream( constraintData.malleable.stiffSpring.pivotB, in, info );
			NifStream( constraintData.malleable.stiffSpring.length, in, info );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( constraintData.malleable.tau, in, info );
			NifStream( constraintData.malleable.damping, in, info );
		};
		if ( info.version >= 0x14020007 ) {
			NifStream( constraintData.malleable.strength, in, info );
		};
	};
	NifStream( threshold, in, info );
	NifStream( removeWhenBroken, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void bhkBreakableConstraint::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	bhkConstraint::Write( out, link_map, missing_link_stack, info );
	NifStream( constraintData.type, out, info );
	NifStream( constraintData.numEntities2, out, info );
	WriteRef( StaticCast<NiObject>(constraintData.entityA), out, info, link_map, missing_link_stack );
	WriteRef( StaticCast<NiObject>(constraintData.entityB), out, info, link_map, missing_link_stack );
	NifStream( constraintData.priority, out, info );
	if ( (constraintData.type == 0) ) {
		NifStream( constraintData.ballAndSocket.pivotA, out, info );
		NifStream( constraintData.ballAndSocket.pivotB, out, info );
	};
	if ( (constraintData.type == 1) ) {
		if ( info.version <= 0x14000005 ) {
			NifStream( constraintData.hinge.pivotA, out, info );
			NifStream( constraintData.hinge.perp2AxleInA1, out, info );
			NifStream( constraintData.hinge.perp2AxleInA2, out, info );
			NifStream( constraintData.hinge.pivotB, out, info );
			NifStream( constraintData.hinge.axleB, out, info );
		};
		if ( info.version >= 0x14020007 ) {
			NifStream( constraintData.hinge.axleA, out, info );
			NifStream( (Vector4&)constraintData.hinge.perp2AxleInA1, out, info );
			NifStream( (Vector4&)constraintData.hinge.perp2AxleInA2, out, info );
			NifStream( (Vector4&)constraintData.hinge.pivotA, out, info );
			NifStream( (Vector4&)constraintData.hinge.axleB, out, info );
			NifStream( constraintData.hinge.perp2AxleInB1, out, info );
			NifStream( constraintData.hinge.perp2AxleInB2, out, info );
			NifStream( (Vector4&)constraintData.hinge.pivotB, out, info );
		};
	};
	if ( (constraintData.type == 2) ) {
		if ( (info.userVersion2 <= 16) ) {
			NifStream( constraintData.limitedHinge.pivotA, out, info );
			NifStream( constraintData.limitedHinge.axleA, out, info );
			NifStream( constraintData.limitedHinge.perp2AxleInA1, out, info );
			NifStream( constraintData.limitedHinge.perp2AxleInA2, out, info );
			NifStream( constraintData.limitedHinge.pivotB, out, info );
			NifStream( constraintData.limitedHinge.axleB, out, info );
			NifStream( constraintData.limitedHinge.perp2AxleInB2, out, info );
		};
		if ( (info.userVersion2 > 16) ) {
			NifStream( (Vector4&)constraintData.limitedHinge.axleA, out, info );
			NifStream( (Vector4&)constraintData.limitedHinge.perp2AxleInA1, out, info );
			NifStream( (Vector4&)constraintData.limitedHinge.perp2AxleInA2, out, info );
			NifStream( (Vector4&)constraintData.limitedHinge.pivotA, out, info );
			NifStream( (Vector4&)constraintData.limitedHinge.axleB, out, info );
			NifStream( constraintData.limitedHinge.perp2AxleInB1, out, info );
			NifStream( (Vector4&)constraintData.limitedHinge.perp2AxleInB2, out, info );
			NifStream( (Vector4&)constraintData.limitedHinge.pivotB, out, info );
		};
		NifStream( constraintData.limitedHinge.minAngle, out, info );
		NifStream( constraintData.limitedHinge.maxAngle, out, info );
		NifStream( constraintData.limitedHinge.maxFriction, out, info );
		if ( ( info.version >= 0x14020007 ) && ( (info.userVersion2 > 16) ) ) {
			NifStream( constraintData.limitedHinge.motor.type, out, info );
			if ( (constraintData.limitedHinge.motor.type == 1) ) {
				NifStream( constraintData.limitedHinge.motor.positionMotor.minForce, out, info );
				NifStream( constraintData.limitedHinge.motor.positionMotor.maxForce, out, info );
				NifStream( constraintData.limitedHinge.motor.positionMotor.tau, out, info );
				NifStream( constraintData.limitedHinge.motor.positionMotor.damping, out, info );
				NifStream( constraintData.limitedHinge.motor.positionMotor.proportionalRecoveryVelocity, out, info );
				NifStream( constraintData.limitedHinge.motor.positionMotor.constantRecoveryVelocity, out, info );
				NifStream( constraintData.limitedHinge.motor.positionMotor.motorEnabled, out, info );
			};
			if ( (constraintData.limitedHinge.motor.type == 2) ) {
				NifStream( constraintData.limitedHinge.motor.velocityMotor.minForce, out, info );
				NifStream( constraintData.limitedHinge.motor.velocityMotor.maxForce, out, info );
				NifStream( constraintData.limitedHinge.motor.velocityMotor.tau, out, info );
				NifStream( constraintData.limitedHinge.motor.velocityMotor.targetVelocity, out, info );
				NifStream( constraintData.limitedHinge.motor.velocityMotor.useVelocityTarget, out, info );
				NifStream( constraintData.limitedHinge.motor.velocityMotor.motorEnabled, out, info );
			};
			if ( (constraintData.limitedHinge.motor.type == 3) ) {
				NifStream( constraintData.limitedHinge.motor.springDamperMotor.minForce, out, info );
				NifStream( constraintData.limitedHinge.motor.springDamperMotor.maxForce, out, info );
				NifStream( constraintData.limitedHinge.motor.springDamperMotor.springConstant, out, info );
				NifStream( constraintData.limitedHinge.motor.springDamperMotor.springDamping, out, info );
				NifStream( constraintData.limitedHinge.motor.springDamperMotor.motorEnabled, out, info );
			};
		};
	};
	if ( (constraintData.type == 6) ) {
		if ( info.version <= 0x14000005 ) {
			NifStream( constraintData.prismatic.pivotA, out, info );
			NifStream( constraintData.prismatic.rotationA, out, info );
			NifStream( constraintData.prismatic.planeA, out, info );
			NifStream( constraintData.prismatic.slidingA, out, info );
			NifStream( constraintData.prismatic.pivotB, out, info );
			NifStream( constraintData.prismatic.rotationB, out, info );
			NifStream( constraintData.prismatic.planeB, out, info );
			NifStream( constraintData.prismatic.slidingB, out, info );
		};
		if ( info.version >= 0x14020007 ) {
			NifStream( (Vector4&)constraintData.prismatic.slidingA, out, info );
			NifStream( (Vector4&)constraintData.prismatic.rotationA, out, info );
			NifStream( (Vector4&)constraintData.prismatic.planeA, out, info );
			NifStream( (Vector4&)constraintData.prismatic.pivotA, out, info );
			NifStream( (Vector4&)constraintData.prismatic.slidingB, out, info );
			NifStream( (Vector4&)constraintData.prismatic.rotationB, out, info );
			NifStream( (Vector4&)constraintData.prismatic.planeB, out, info );
			NifStream( (Vector4&)constraintData.prismatic.pivotB, out, info );
		};
		NifStream( constraintData.prismatic.minDistance, out, info );
		NifStream( constraintData.prismatic.maxDistance, out, info );
		NifStream( constraintData.prismatic.friction, out, info );
		if ( ( info.version >= 0x14020007 ) && ( (info.userVersion2 > 16) ) ) {
			NifStream( constraintData.prismatic.motor.type, out, info );
			if ( (constraintData.prismatic.motor.type == 1) ) {
				NifStream( constraintData.prismatic.motor.positionMotor.minForce, out, info );
				NifStream( constraintData.prismatic.motor.positionMotor.maxForce, out, info );
				NifStream( constraintData.prismatic.motor.positionMotor.tau, out, info );
				NifStream( constraintData.prismatic.motor.positionMotor.damping, out, info );
				NifStream( constraintData.prismatic.motor.positionMotor.proportionalRecoveryVelocity, out, info );
				NifStream( constraintData.prismatic.motor.positionMotor.constantRecoveryVelocity, out, info );
				NifStream( constraintData.prismatic.motor.positionMotor.motorEnabled, out, info );
			};
			if ( (constraintData.prismatic.motor.type == 2) ) {
				NifStream( constraintData.prismatic.motor.velocityMotor.minForce, out, info );
				NifStream( constraintData.prismatic.motor.velocityMotor.maxForce, out, info );
				NifStream( constraintData.prismatic.motor.velocityMotor.tau, out, info );
				NifStream( constraintData.prismatic.motor.velocityMotor.targetVelocity, out, info );
				NifStream( constraintData.prismatic.motor.velocityMotor.useVelocityTarget, out, info );
				NifStream( constraintData.prismatic.motor.velocityMotor.motorEnabled, out, info );
			};
			if ( (constraintData.prismatic.motor.type == 3) ) {
				NifStream( constraintData.prismatic.motor.springDamperMotor.minForce, out, info );
				NifStream( constraintData.prismatic.motor.springDamperMotor.maxForce, out, info );
				NifStream( constraintData.prismatic.motor.springDamperMotor.springConstant, out, info );
				NifStream( constraintData.prismatic.motor.springDamperMotor.springDamping, out, info );
				NifStream( constraintData.prismatic.motor.springDamperMotor.motorEnabled, out, info );
			};
		};
	};
	if ( (constraintData.type == 7) ) {
		if ( (info.userVersion2 <= 16) ) {
			NifStream( constraintData.ragdoll.pivotA, out, info );
			NifStream( constraintData.ragdoll.planeA, out, info );
			NifStream( constraintData.ragdoll.twistA, out, info );
			NifStream( constraintData.ragdoll.pivotB, out, info );
			NifStream( constraintData.ragdoll.planeB, out, info );
			NifStream( constraintData.ragdoll.twistB, out, info );
		};
		if ( (info.userVersion2 > 16) ) {
			NifStream( (Vector4&)constraintData.ragdoll.twistA, out, info );
			NifStream( (Vector4&)constraintData.ragdoll.planeA, out, info );
			NifStream( constraintData.ragdoll.motorA, out, info );
			NifStream( (Vector4&)constraintData.ragdoll.pivotA, out, info );
			NifStream( (Vector4&)constraintData.ragdoll.twistB, out, info );
			NifStream( (Vector4&)constraintData.ragdoll.planeB, out, info );
			NifStream( constraintData.ragdoll.motorB, out, info );
			NifStream( (Vector4&)constraintData.ragdoll.pivotB, out, info );
		};
		NifStream( constraintData.ragdoll.coneMaxAngle, out, info );
		NifStream( constraintData.ragdoll.planeMinAngle, out, info );
		NifStream( constraintData.ragdoll.planeMaxAngle, out, info );
		NifStream( constraintData.ragdoll.twistMinAngle, out, info );
		NifStream( constraintData.ragdoll.twistMaxAngle, out, info );
		NifStream( constraintData.ragdoll.maxFriction, out, info );
		if ( ( info.version >= 0x14020007 ) && ( (info.userVersion2 > 16) ) ) {
			NifStream( constraintData.ragdoll.motor.type, out, info );
			if ( (constraintData.ragdoll.motor.type == 1) ) {
				NifStream( constraintData.ragdoll.motor.positionMotor.minForce, out, info );
				NifStream( constraintData.ragdoll.motor.positionMotor.maxForce, out, info );
				NifStream( constraintData.ragdoll.motor.positionMotor.tau, out, info );
				NifStream( constraintData.ragdoll.motor.positionMotor.damping, out, info );
				NifStream( constraintData.ragdoll.motor.positionMotor.proportionalRecoveryVelocity, out, info );
				NifStream( constraintData.ragdoll.motor.positionMotor.constantRecoveryVelocity, out, info );
				NifStream( constraintData.ragdoll.motor.positionMotor.motorEnabled, out, info );
			};
			if ( (constraintData.ragdoll.motor.type == 2) ) {
				NifStream( constraintData.ragdoll.motor.velocityMotor.minForce, out, info );
				NifStream( constraintData.ragdoll.motor.velocityMotor.maxForce, out, info );
				NifStream( constraintData.ragdoll.motor.velocityMotor.tau, out, info );
				NifStream( constraintData.ragdoll.motor.velocityMotor.targetVelocity, out, info );
				NifStream( constraintData.ragdoll.motor.velocityMotor.useVelocityTarget, out, info );
				NifStream( constraintData.ragdoll.motor.velocityMotor.motorEnabled, out, info );
			};
			if ( (constraintData.ragdoll.motor.type == 3) ) {
				NifStream( constraintData.ragdoll.motor.springDamperMotor.minForce, out, info );
				NifStream( constraintData.ragdoll.motor.springDamperMotor.maxForce, out, info );
				NifStream( constraintData.ragdoll.motor.springDamperMotor.springConstant, out, info );
				NifStream( constraintData.ragdoll.motor.springDamperMotor.springDamping, out, info );
				NifStream( constraintData.ragdoll.motor.springDamperMotor.motorEnabled, out, info );
			};
		};
	};
	if ( (constraintData.type == 8) ) {
		NifStream( constraintData.stiffSpring.pivotA, out, info );
		NifStream( constraintData.stiffSpring.pivotB, out, info );
		NifStream( constraintData.stiffSpring.length, out, info );
	};
	if ( (constraintData.type == 13) ) {
		NifStream( constraintData.malleable.type, out, info );
		NifStream( constraintData.malleable.numEntities, out, info );
		WriteRef( StaticCast<NiObject>(constraintData.malleable.entityA), out, info, link_map, missing_link_stack );
		WriteRef( StaticCast<NiObject>(constraintData.malleable.entityB), out, info, link_map, missing_link_stack );
		NifStream( constraintData.malleable.priority, out, info );
		if ( (constraintData.malleable.type == 0) ) {
			NifStream( constraintData.malleable.ballAndSocket.pivotA, out, info );
			NifStream( constraintData.malleable.ballAndSocket.pivotB, out, info );
		};
		if ( (constraintData.malleable.type == 1) ) {
			if ( info.version <= 0x14000005 ) {
				NifStream( constraintData.malleable.hinge.pivotA, out, info );
				NifStream( constraintData.malleable.hinge.perp2AxleInA1, out, info );
				NifStream( constraintData.malleable.hinge.perp2AxleInA2, out, info );
				NifStream( constraintData.malleable.hinge.pivotB, out, info );
				NifStream( constraintData.malleable.hinge.axleB, out, info );
			};
			if ( info.version >= 0x14020007 ) {
				NifStream( constraintData.malleable.hinge.axleA, out, info );
				NifStream( (Vector4&)constraintData.malleable.hinge.perp2AxleInA1, out, info );
				NifStream( (Vector4&)constraintData.malleable.hinge.perp2AxleInA2, out, info );
				NifStream( (Vector4&)constraintData.malleable.hinge.pivotA, out, info );
				NifStream( (Vector4&)constraintData.malleable.hinge.axleB, out, info );
				NifStream( constraintData.malleable.hinge.perp2AxleInB1, out, info );
				NifStream( constraintData.malleable.hinge.perp2AxleInB2, out, info );
				NifStream( (Vector4&)constraintData.malleable.hinge.pivotB, out, info );
			};
		};
		if ( (constraintData.malleable.type == 2) ) {
			if ( (info.userVersion2 <= 16) ) {
				NifStream( constraintData.malleable.limitedHinge.pivotA, out, info );
				NifStream( constraintData.malleable.limitedHinge.axleA, out, info );
				NifStream( constraintData.malleable.limitedHinge.perp2AxleInA1, out, info );
				NifStream( constraintData.malleable.limitedHinge.perp2AxleInA2, out, info );
				NifStream( constraintData.malleable.limitedHinge.pivotB, out, info );
				NifStream( constraintData.malleable.limitedHinge.axleB, out, info );
				NifStream( constraintData.malleable.limitedHinge.perp2AxleInB2, out, info );
			};
			if ( (info.userVersion2 > 16) ) {
				NifStream( (Vector4&)constraintData.malleable.limitedHinge.axleA, out, info );
				NifStream( (Vector4&)constraintData.malleable.limitedHinge.perp2AxleInA1, out, info );
				NifStream( (Vector4&)constraintData.malleable.limitedHinge.perp2AxleInA2, out, info );
				NifStream( (Vector4&)constraintData.malleable.limitedHinge.pivotA, out, info );
				NifStream( (Vector4&)constraintData.malleable.limitedHinge.axleB, out, info );
				NifStream( constraintData.malleable.limitedHinge.perp2AxleInB1, out, info );
				NifStream( (Vector4&)constraintData.malleable.limitedHinge.perp2AxleInB2, out, info );
				NifStream( (Vector4&)constraintData.malleable.limitedHinge.pivotB, out, info );
			};
			NifStream( constraintData.malleable.limitedHinge.minAngle, out, info );
			NifStream( constraintData.malleable.limitedHinge.maxAngle, out, info );
			NifStream( constraintData.malleable.limitedHinge.maxFriction, out, info );
			if ( ( info.version >= 0x14020007 ) && ( (info.userVersion2 > 16) ) ) {
				NifStream( constraintData.malleable.limitedHinge.motor.type, out, info );
				if ( (constraintData.malleable.limitedHinge.motor.type == 1) ) {
					NifStream( constraintData.malleable.limitedHinge.motor.positionMotor.minForce, out, info );
					NifStream( constraintData.malleable.limitedHinge.motor.positionMotor.maxForce, out, info );
					NifStream( constraintData.malleable.limitedHinge.motor.positionMotor.tau, out, info );
					NifStream( constraintData.malleable.limitedHinge.motor.positionMotor.damping, out, info );
					NifStream( constraintData.malleable.limitedHinge.motor.positionMotor.proportionalRecoveryVelocity, out, info );
					NifStream( constraintData.malleable.limitedHinge.motor.positionMotor.constantRecoveryVelocity, out, info );
					NifStream( constraintData.malleable.limitedHinge.motor.positionMotor.motorEnabled, out, info );
				};
				if ( (constraintData.malleable.limitedHinge.motor.type == 2) ) {
					NifStream( constraintData.malleable.limitedHinge.motor.velocityMotor.minForce, out, info );
					NifStream( constraintData.malleable.limitedHinge.motor.velocityMotor.maxForce, out, info );
					NifStream( constraintData.malleable.limitedHinge.motor.velocityMotor.tau, out, info );
					NifStream( constraintData.malleable.limitedHinge.motor.velocityMotor.targetVelocity, out, info );
					NifStream( constraintData.malleable.limitedHinge.motor.velocityMotor.useVelocityTarget, out, info );
					NifStream( constraintData.malleable.limitedHinge.motor.velocityMotor.motorEnabled, out, info );
				};
				if ( (constraintData.malleable.limitedHinge.motor.type == 3) ) {
					NifStream( constraintData.malleable.limitedHinge.motor.springDamperMotor.minForce, out, info );
					NifStream( constraintData.malleable.limitedHinge.motor.springDamperMotor.maxForce, out, info );
					NifStream( constraintData.malleable.limitedHinge.motor.springDamperMotor.springConstant, out, info );
					NifStream( constraintData.malleable.limitedHinge.motor.springDamperMotor.springDamping, out, info );
					NifStream( constraintData.malleable.limitedHinge.motor.springDamperMotor.motorEnabled, out, info );
				};
			};
		};
		if ( (constraintData.malleable.type == 6) ) {
			if ( info.version <= 0x14000005 ) {
				NifStream( constraintData.malleable.prismatic.pivotA, out, info );
				NifStream( constraintData.malleable.prismatic.rotationA, out, info );
				NifStream( constraintData.malleable.prismatic.planeA, out, info );
				NifStream( constraintData.malleable.prismatic.slidingA, out, info );
				NifStream( constraintData.malleable.prismatic.pivotB, out, info );
				NifStream( constraintData.malleable.prismatic.rotationB, out, info );
				NifStream( constraintData.malleable.prismatic.planeB, out, info );
				NifStream( constraintData.malleable.prismatic.slidingB, out, info );
			};
			if ( info.version >= 0x14020007 ) {
				NifStream( (Vector4&)constraintData.malleable.prismatic.slidingA, out, info );
				NifStream( (Vector4&)constraintData.malleable.prismatic.rotationA, out, info );
				NifStream( (Vector4&)constraintData.malleable.prismatic.planeA, out, info );
				NifStream( (Vector4&)constraintData.malleable.prismatic.pivotA, out, info );
				NifStream( (Vector4&)constraintData.malleable.prismatic.slidingB, out, info );
				NifStream( (Vector4&)constraintData.malleable.prismatic.rotationB, out, info );
				NifStream( (Vector4&)constraintData.malleable.prismatic.planeB, out, info );
				NifStream( (Vector4&)constraintData.malleable.prismatic.pivotB, out, info );
			};
			NifStream( constraintData.malleable.prismatic.minDistance, out, info );
			NifStream( constraintData.malleable.prismatic.maxDistance, out, info );
			NifStream( constraintData.malleable.prismatic.friction, out, info );
			if ( ( info.version >= 0x14020007 ) && ( (info.userVersion2 > 16) ) ) {
				NifStream( constraintData.malleable.prismatic.motor.type, out, info );
				if ( (constraintData.malleable.prismatic.motor.type == 1) ) {
					NifStream( constraintData.malleable.prismatic.motor.positionMotor.minForce, out, info );
					NifStream( constraintData.malleable.prismatic.motor.positionMotor.maxForce, out, info );
					NifStream( constraintData.malleable.prismatic.motor.positionMotor.tau, out, info );
					NifStream( constraintData.malleable.prismatic.motor.positionMotor.damping, out, info );
					NifStream( constraintData.malleable.prismatic.motor.positionMotor.proportionalRecoveryVelocity, out, info );
					NifStream( constraintData.malleable.prismatic.motor.positionMotor.constantRecoveryVelocity, out, info );
					NifStream( constraintData.malleable.prismatic.motor.positionMotor.motorEnabled, out, info );
				};
				if ( (constraintData.malleable.prismatic.motor.type == 2) ) {
					NifStream( constraintData.malleable.prismatic.motor.velocityMotor.minForce, out, info );
					NifStream( constraintData.malleable.prismatic.motor.velocityMotor.maxForce, out, info );
					NifStream( constraintData.malleable.prismatic.motor.velocityMotor.tau, out, info );
					NifStream( constraintData.malleable.prismatic.motor.velocityMotor.targetVelocity, out, info );
					NifStream( constraintData.malleable.prismatic.motor.velocityMotor.useVelocityTarget, out, info );
					NifStream( constraintData.malleable.prismatic.motor.velocityMotor.motorEnabled, out, info );
				};
				if ( (constraintData.malleable.prismatic.motor.type == 3) ) {
					NifStream( constraintData.malleable.prismatic.motor.springDamperMotor.minForce, out, info );
					NifStream( constraintData.malleable.prismatic.motor.springDamperMotor.maxForce, out, info );
					NifStream( constraintData.malleable.prismatic.motor.springDamperMotor.springConstant, out, info );
					NifStream( constraintData.malleable.prismatic.motor.springDamperMotor.springDamping, out, info );
					NifStream( constraintData.malleable.prismatic.motor.springDamperMotor.motorEnabled, out, info );
				};
			};
		};
		if ( (constraintData.malleable.type == 7) ) {
			if ( (info.userVersion2 <= 16) ) {
				NifStream( constraintData.malleable.ragdoll.pivotA, out, info );
				NifStream( constraintData.malleable.ragdoll.planeA, out, info );
				NifStream( constraintData.malleable.ragdoll.twistA, out, info );
				NifStream( constraintData.malleable.ragdoll.pivotB, out, info );
				NifStream( constraintData.malleable.ragdoll.planeB, out, info );
				NifStream( constraintData.malleable.ragdoll.twistB, out, info );
			};
			if ( (info.userVersion2 > 16) ) {
				NifStream( (Vector4&)constraintData.malleable.ragdoll.twistA, out, info );
				NifStream( (Vector4&)constraintData.malleable.ragdoll.planeA, out, info );
				NifStream( constraintData.malleable.ragdoll.motorA, out, info );
				NifStream( (Vector4&)constraintData.malleable.ragdoll.pivotA, out, info );
				NifStream( (Vector4&)constraintData.malleable.ragdoll.twistB, out, info );
				NifStream( (Vector4&)constraintData.malleable.ragdoll.planeB, out, info );
				NifStream( constraintData.malleable.ragdoll.motorB, out, info );
				NifStream( (Vector4&)constraintData.malleable.ragdoll.pivotB, out, info );
			};
			NifStream( constraintData.malleable.ragdoll.coneMaxAngle, out, info );
			NifStream( constraintData.malleable.ragdoll.planeMinAngle, out, info );
			NifStream( constraintData.malleable.ragdoll.planeMaxAngle, out, info );
			NifStream( constraintData.malleable.ragdoll.twistMinAngle, out, info );
			NifStream( constraintData.malleable.ragdoll.twistMaxAngle, out, info );
			NifStream( constraintData.malleable.ragdoll.maxFriction, out, info );
			if ( ( info.version >= 0x14020007 ) && ( (info.userVersion2 > 16) ) ) {
				NifStream( constraintData.malleable.ragdoll.motor.type, out, info );
				if ( (constraintData.malleable.ragdoll.motor.type == 1) ) {
					NifStream( constraintData.malleable.ragdoll.motor.positionMotor.minForce, out, info );
					NifStream( constraintData.malleable.ragdoll.motor.positionMotor.maxForce, out, info );
					NifStream( constraintData.malleable.ragdoll.motor.positionMotor.tau, out, info );
					NifStream( constraintData.malleable.ragdoll.motor.positionMotor.damping, out, info );
					NifStream( constraintData.malleable.ragdoll.motor.positionMotor.proportionalRecoveryVelocity, out, info );
					NifStream( constraintData.malleable.ragdoll.motor.positionMotor.constantRecoveryVelocity, out, info );
					NifStream( constraintData.malleable.ragdoll.motor.positionMotor.motorEnabled, out, info );
				};
				if ( (constraintData.malleable.ragdoll.motor.type == 2) ) {
					NifStream( constraintData.malleable.ragdoll.motor.velocityMotor.minForce, out, info );
					NifStream( constraintData.malleable.ragdoll.motor.velocityMotor.maxForce, out, info );
					NifStream( constraintData.malleable.ragdoll.motor.velocityMotor.tau, out, info );
					NifStream( constraintData.malleable.ragdoll.motor.velocityMotor.targetVelocity, out, info );
					NifStream( constraintData.malleable.ragdoll.motor.velocityMotor.useVelocityTarget, out, info );
					NifStream( constraintData.malleable.ragdoll.motor.velocityMotor.motorEnabled, out, info );
				};
				if ( (constraintData.malleable.ragdoll.motor.type == 3) ) {
					NifStream( constraintData.malleable.ragdoll.motor.springDamperMotor.minForce, out, info );
					NifStream( constraintData.malleable.ragdoll.motor.springDamperMotor.maxForce, out, info );
					NifStream( constraintData.malleable.ragdoll.motor.springDamperMotor.springConstant, out, info );
					NifStream( constraintData.malleable.ragdoll.motor.springDamperMotor.springDamping, out, info );
					NifStream( constraintData.malleable.ragdoll.motor.springDamperMotor.motorEnabled, out, info );
				};
			};
		};
		if ( (constraintData.malleable.type == 8) ) {
			NifStream( constraintData.malleable.stiffSpring.pivotA, out, info );
			NifStream( constraintData.malleable.stiffSpring.pivotB, out, info );
			NifStream( constraintData.malleable.stiffSpring.length, out, info );
		};
		if ( info.version <= 0x14000005 ) {
			NifStream( constraintData.malleable.tau, out, info );
			NifStream( constraintData.malleable.damping, out, info );
		};
		if ( info.version >= 0x14020007 ) {
			NifStream( constraintData.malleable.strength, out, info );
		};
	};
	NifStream( threshold, out, info );
	NifStream( removeWhenBroken, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string bhkBreakableConstraint::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	out << bhkConstraint::asString();
	out << "  Type:  " << constraintData.type << endl;
	out << "  Num Entities 2:  " << constraintData.numEntities2 << endl;
	out << "  Entity A:  " << constraintData.entityA << endl;
	out << "  Entity B:  " << constraintData.entityB << endl;
	out << "  Priority:  " << constraintData.priority << endl;
	if ( (constraintData.type == 0) ) {
		out << "    Pivot A:  " << constraintData.ballAndSocket.pivotA << endl;
		out << "    Pivot B:  " << constraintData.ballAndSocket.pivotB << endl;
	};
	if ( (constraintData.type == 1) ) {
		out << "    Pivot A:  " << constraintData.hinge.pivotA << endl;
		out << "    Perp2 Axle In A1:  " << constraintData.hinge.perp2AxleInA1 << endl;
		out << "    Perp2 Axle In A2:  " << constraintData.hinge.perp2AxleInA2 << endl;
		out << "    Pivot B:  " << constraintData.hinge.pivotB << endl;
		out << "    Axle B:  " << constraintData.hinge.axleB << endl;
		out << "    Axle A:  " << constraintData.hinge.axleA << endl;
		out << "    Perp2 Axle In B1:  " << constraintData.hinge.perp2AxleInB1 << endl;
		out << "    Perp2 Axle In B2:  " << constraintData.hinge.perp2AxleInB2 << endl;
	};
	if ( (constraintData.type == 2) ) {
		out << "    Pivot A:  " << constraintData.limitedHinge.pivotA << endl;
		out << "    Axle A:  " << constraintData.limitedHinge.axleA << endl;
		out << "    Perp2 Axle In A1:  " << constraintData.limitedHinge.perp2AxleInA1 << endl;
		out << "    Perp2 Axle In A2:  " << constraintData.limitedHinge.perp2AxleInA2 << endl;
		out << "    Pivot B:  " << constraintData.limitedHinge.pivotB << endl;
		out << "    Axle B:  " << constraintData.limitedHinge.axleB << endl;
		out << "    Perp2 Axle In B2:  " << constraintData.limitedHinge.perp2AxleInB2 << endl;
		out << "    Perp2 Axle In B1:  " << constraintData.limitedHinge.perp2AxleInB1 << endl;
		out << "    Min Angle:  " << constraintData.limitedHinge.minAngle << endl;
		out << "    Max Angle:  " << constraintData.limitedHinge.maxAngle << endl;
		out << "    Max Friction:  " << constraintData.limitedHinge.maxFriction << endl;
		out << "    Type:  " << constraintData.limitedHinge.motor.type << endl;
		if ( (constraintData.limitedHinge.motor.type == 1) ) {
			out << "      Min Force:  " << constraintData.limitedHinge.motor.positionMotor.minForce << endl;
			out << "      Max Force:  " << constraintData.limitedHinge.motor.positionMotor.maxForce << endl;
			out << "      Tau:  " << constraintData.limitedHinge.motor.positionMotor.tau << endl;
			out << "      Damping:  " << constraintData.limitedHinge.motor.positionMotor.damping << endl;
			out << "      Proportional Recovery Velocity:  " << constraintData.limitedHinge.motor.positionMotor.proportionalRecoveryVelocity << endl;
			out << "      Constant Recovery Velocity:  " << constraintData.limitedHinge.motor.positionMotor.constantRecoveryVelocity << endl;
			out << "      Motor Enabled:  " << constraintData.limitedHinge.motor.positionMotor.motorEnabled << endl;
		};
		if ( (constraintData.limitedHinge.motor.type == 2) ) {
			out << "      Min Force:  " << constraintData.limitedHinge.motor.velocityMotor.minForce << endl;
			out << "      Max Force:  " << constraintData.limitedHinge.motor.velocityMotor.maxForce << endl;
			out << "      Tau:  " << constraintData.limitedHinge.motor.velocityMotor.tau << endl;
			out << "      Target Velocity:  " << constraintData.limitedHinge.motor.velocityMotor.targetVelocity << endl;
			out << "      Use Velocity Target:  " << constraintData.limitedHinge.motor.velocityMotor.useVelocityTarget << endl;
			out << "      Motor Enabled:  " << constraintData.limitedHinge.motor.velocityMotor.motorEnabled << endl;
		};
		if ( (constraintData.limitedHinge.motor.type == 3) ) {
			out << "      Min Force:  " << constraintData.limitedHinge.motor.springDamperMotor.minForce << endl;
			out << "      Max Force:  " << constraintData.limitedHinge.motor.springDamperMotor.maxForce << endl;
			out << "      Spring Constant:  " << constraintData.limitedHinge.motor.springDamperMotor.springConstant << endl;
			out << "      Spring Damping:  " << constraintData.limitedHinge.motor.springDamperMotor.springDamping << endl;
			out << "      Motor Enabled:  " << constraintData.limitedHinge.motor.springDamperMotor.motorEnabled << endl;
		};
	};
	if ( (constraintData.type == 6) ) {
		out << "    Pivot A:  " << constraintData.prismatic.pivotA << endl;
		out << "    Rotation A:  " << constraintData.prismatic.rotationA << endl;
		out << "    Plane A:  " << constraintData.prismatic.planeA << endl;
		out << "    Sliding A:  " << constraintData.prismatic.slidingA << endl;
		out << "    Pivot B:  " << constraintData.prismatic.pivotB << endl;
		out << "    Rotation B:  " << constraintData.prismatic.rotationB << endl;
		out << "    Plane B:  " << constraintData.prismatic.planeB << endl;
		out << "    Sliding B:  " << constraintData.prismatic.slidingB << endl;
		out << "    Min Distance:  " << constraintData.prismatic.minDistance << endl;
		out << "    Max Distance:  " << constraintData.prismatic.maxDistance << endl;
		out << "    Friction:  " << constraintData.prismatic.friction << endl;
		out << "    Type:  " << constraintData.prismatic.motor.type << endl;
		if ( (constraintData.prismatic.motor.type == 1) ) {
			out << "      Min Force:  " << constraintData.prismatic.motor.positionMotor.minForce << endl;
			out << "      Max Force:  " << constraintData.prismatic.motor.positionMotor.maxForce << endl;
			out << "      Tau:  " << constraintData.prismatic.motor.positionMotor.tau << endl;
			out << "      Damping:  " << constraintData.prismatic.motor.positionMotor.damping << endl;
			out << "      Proportional Recovery Velocity:  " << constraintData.prismatic.motor.positionMotor.proportionalRecoveryVelocity << endl;
			out << "      Constant Recovery Velocity:  " << constraintData.prismatic.motor.positionMotor.constantRecoveryVelocity << endl;
			out << "      Motor Enabled:  " << constraintData.prismatic.motor.positionMotor.motorEnabled << endl;
		};
		if ( (constraintData.prismatic.motor.type == 2) ) {
			out << "      Min Force:  " << constraintData.prismatic.motor.velocityMotor.minForce << endl;
			out << "      Max Force:  " << constraintData.prismatic.motor.velocityMotor.maxForce << endl;
			out << "      Tau:  " << constraintData.prismatic.motor.velocityMotor.tau << endl;
			out << "      Target Velocity:  " << constraintData.prismatic.motor.velocityMotor.targetVelocity << endl;
			out << "      Use Velocity Target:  " << constraintData.prismatic.motor.velocityMotor.useVelocityTarget << endl;
			out << "      Motor Enabled:  " << constraintData.prismatic.motor.velocityMotor.motorEnabled << endl;
		};
		if ( (constraintData.prismatic.motor.type == 3) ) {
			out << "      Min Force:  " << constraintData.prismatic.motor.springDamperMotor.minForce << endl;
			out << "      Max Force:  " << constraintData.prismatic.motor.springDamperMotor.maxForce << endl;
			out << "      Spring Constant:  " << constraintData.prismatic.motor.springDamperMotor.springConstant << endl;
			out << "      Spring Damping:  " << constraintData.prismatic.motor.springDamperMotor.springDamping << endl;
			out << "      Motor Enabled:  " << constraintData.prismatic.motor.springDamperMotor.motorEnabled << endl;
		};
	};
	if ( (constraintData.type == 7) ) {
		out << "    Pivot A:  " << constraintData.ragdoll.pivotA << endl;
		out << "    Plane A:  " << constraintData.ragdoll.planeA << endl;
		out << "    Twist A:  " << constraintData.ragdoll.twistA << endl;
		out << "    Pivot B:  " << constraintData.ragdoll.pivotB << endl;
		out << "    Plane B:  " << constraintData.ragdoll.planeB << endl;
		out << "    Twist B:  " << constraintData.ragdoll.twistB << endl;
		out << "    Motor A:  " << constraintData.ragdoll.motorA << endl;
		out << "    Motor B:  " << constraintData.ragdoll.motorB << endl;
		out << "    Cone Max Angle:  " << constraintData.ragdoll.coneMaxAngle << endl;
		out << "    Plane Min Angle:  " << constraintData.ragdoll.planeMinAngle << endl;
		out << "    Plane Max Angle:  " << constraintData.ragdoll.planeMaxAngle << endl;
		out << "    Twist Min Angle:  " << constraintData.ragdoll.twistMinAngle << endl;
		out << "    Twist Max Angle:  " << constraintData.ragdoll.twistMaxAngle << endl;
		out << "    Max Friction:  " << constraintData.ragdoll.maxFriction << endl;
		out << "    Type:  " << constraintData.ragdoll.motor.type << endl;
		if ( (constraintData.ragdoll.motor.type == 1) ) {
			out << "      Min Force:  " << constraintData.ragdoll.motor.positionMotor.minForce << endl;
			out << "      Max Force:  " << constraintData.ragdoll.motor.positionMotor.maxForce << endl;
			out << "      Tau:  " << constraintData.ragdoll.motor.positionMotor.tau << endl;
			out << "      Damping:  " << constraintData.ragdoll.motor.positionMotor.damping << endl;
			out << "      Proportional Recovery Velocity:  " << constraintData.ragdoll.motor.positionMotor.proportionalRecoveryVelocity << endl;
			out << "      Constant Recovery Velocity:  " << constraintData.ragdoll.motor.positionMotor.constantRecoveryVelocity << endl;
			out << "      Motor Enabled:  " << constraintData.ragdoll.motor.positionMotor.motorEnabled << endl;
		};
		if ( (constraintData.ragdoll.motor.type == 2) ) {
			out << "      Min Force:  " << constraintData.ragdoll.motor.velocityMotor.minForce << endl;
			out << "      Max Force:  " << constraintData.ragdoll.motor.velocityMotor.maxForce << endl;
			out << "      Tau:  " << constraintData.ragdoll.motor.velocityMotor.tau << endl;
			out << "      Target Velocity:  " << constraintData.ragdoll.motor.velocityMotor.targetVelocity << endl;
			out << "      Use Velocity Target:  " << constraintData.ragdoll.motor.velocityMotor.useVelocityTarget << endl;
			out << "      Motor Enabled:  " << constraintData.ragdoll.motor.velocityMotor.motorEnabled << endl;
		};
		if ( (constraintData.ragdoll.motor.type == 3) ) {
			out << "      Min Force:  " << constraintData.ragdoll.motor.springDamperMotor.minForce << endl;
			out << "      Max Force:  " << constraintData.ragdoll.motor.springDamperMotor.maxForce << endl;
			out << "      Spring Constant:  " << constraintData.ragdoll.motor.springDamperMotor.springConstant << endl;
			out << "      Spring Damping:  " << constraintData.ragdoll.motor.springDamperMotor.springDamping << endl;
			out << "      Motor Enabled:  " << constraintData.ragdoll.motor.springDamperMotor.motorEnabled << endl;
		};
	};
	if ( (constraintData.type == 8) ) {
		out << "    Pivot A:  " << constraintData.stiffSpring.pivotA << endl;
		out << "    Pivot B:  " << constraintData.stiffSpring.pivotB << endl;
		out << "    Length:  " << constraintData.stiffSpring.length << endl;
	};
	if ( (constraintData.type == 13) ) {
		out << "    Type:  " << constraintData.malleable.type << endl;
		out << "    Num Entities:  " << constraintData.malleable.numEntities << endl;
		out << "    Entity A:  " << constraintData.malleable.entityA << endl;
		out << "    Entity B:  " << constraintData.malleable.entityB << endl;
		out << "    Priority:  " << constraintData.malleable.priority << endl;
		if ( (constraintData.malleable.type == 0) ) {
			out << "      Pivot A:  " << constraintData.malleable.ballAndSocket.pivotA << endl;
			out << "      Pivot B:  " << constraintData.malleable.ballAndSocket.pivotB << endl;
		};
		if ( (constraintData.malleable.type == 1) ) {
			out << "      Pivot A:  " << constraintData.malleable.hinge.pivotA << endl;
			out << "      Perp2 Axle In A1:  " << constraintData.malleable.hinge.perp2AxleInA1 << endl;
			out << "      Perp2 Axle In A2:  " << constraintData.malleable.hinge.perp2AxleInA2 << endl;
			out << "      Pivot B:  " << constraintData.malleable.hinge.pivotB << endl;
			out << "      Axle B:  " << constraintData.malleable.hinge.axleB << endl;
			out << "      Axle A:  " << constraintData.malleable.hinge.axleA << endl;
			out << "      Perp2 Axle In B1:  " << constraintData.malleable.hinge.perp2AxleInB1 << endl;
			out << "      Perp2 Axle In B2:  " << constraintData.malleable.hinge.perp2AxleInB2 << endl;
		};
		if ( (constraintData.malleable.type == 2) ) {
			out << "      Pivot A:  " << constraintData.malleable.limitedHinge.pivotA << endl;
			out << "      Axle A:  " << constraintData.malleable.limitedHinge.axleA << endl;
			out << "      Perp2 Axle In A1:  " << constraintData.malleable.limitedHinge.perp2AxleInA1 << endl;
			out << "      Perp2 Axle In A2:  " << constraintData.malleable.limitedHinge.perp2AxleInA2 << endl;
			out << "      Pivot B:  " << constraintData.malleable.limitedHinge.pivotB << endl;
			out << "      Axle B:  " << constraintData.malleable.limitedHinge.axleB << endl;
			out << "      Perp2 Axle In B2:  " << constraintData.malleable.limitedHinge.perp2AxleInB2 << endl;
			out << "      Perp2 Axle In B1:  " << constraintData.malleable.limitedHinge.perp2AxleInB1 << endl;
			out << "      Min Angle:  " << constraintData.malleable.limitedHinge.minAngle << endl;
			out << "      Max Angle:  " << constraintData.malleable.limitedHinge.maxAngle << endl;
			out << "      Max Friction:  " << constraintData.malleable.limitedHinge.maxFriction << endl;
			out << "      Type:  " << constraintData.malleable.limitedHinge.motor.type << endl;
			if ( (constraintData.malleable.limitedHinge.motor.type == 1) ) {
				out << "        Min Force:  " << constraintData.malleable.limitedHinge.motor.positionMotor.minForce << endl;
				out << "        Max Force:  " << constraintData.malleable.limitedHinge.motor.positionMotor.maxForce << endl;
				out << "        Tau:  " << constraintData.malleable.limitedHinge.motor.positionMotor.tau << endl;
				out << "        Damping:  " << constraintData.malleable.limitedHinge.motor.positionMotor.damping << endl;
				out << "        Proportional Recovery Velocity:  " << constraintData.malleable.limitedHinge.motor.positionMotor.proportionalRecoveryVelocity << endl;
				out << "        Constant Recovery Velocity:  " << constraintData.malleable.limitedHinge.motor.positionMotor.constantRecoveryVelocity << endl;
				out << "        Motor Enabled:  " << constraintData.malleable.limitedHinge.motor.positionMotor.motorEnabled << endl;
			};
			if ( (constraintData.malleable.limitedHinge.motor.type == 2) ) {
				out << "        Min Force:  " << constraintData.malleable.limitedHinge.motor.velocityMotor.minForce << endl;
				out << "        Max Force:  " << constraintData.malleable.limitedHinge.motor.velocityMotor.maxForce << endl;
				out << "        Tau:  " << constraintData.malleable.limitedHinge.motor.velocityMotor.tau << endl;
				out << "        Target Velocity:  " << constraintData.malleable.limitedHinge.motor.velocityMotor.targetVelocity << endl;
				out << "        Use Velocity Target:  " << constraintData.malleable.limitedHinge.motor.velocityMotor.useVelocityTarget << endl;
				out << "        Motor Enabled:  " << constraintData.malleable.limitedHinge.motor.velocityMotor.motorEnabled << endl;
			};
			if ( (constraintData.malleable.limitedHinge.motor.type == 3) ) {
				out << "        Min Force:  " << constraintData.malleable.limitedHinge.motor.springDamperMotor.minForce << endl;
				out << "        Max Force:  " << constraintData.malleable.limitedHinge.motor.springDamperMotor.maxForce << endl;
				out << "        Spring Constant:  " << constraintData.malleable.limitedHinge.motor.springDamperMotor.springConstant << endl;
				out << "        Spring Damping:  " << constraintData.malleable.limitedHinge.motor.springDamperMotor.springDamping << endl;
				out << "        Motor Enabled:  " << constraintData.malleable.limitedHinge.motor.springDamperMotor.motorEnabled << endl;
			};
		};
		if ( (constraintData.malleable.type == 6) ) {
			out << "      Pivot A:  " << constraintData.malleable.prismatic.pivotA << endl;
			out << "      Rotation A:  " << constraintData.malleable.prismatic.rotationA << endl;
			out << "      Plane A:  " << constraintData.malleable.prismatic.planeA << endl;
			out << "      Sliding A:  " << constraintData.malleable.prismatic.slidingA << endl;
			out << "      Pivot B:  " << constraintData.malleable.prismatic.pivotB << endl;
			out << "      Rotation B:  " << constraintData.malleable.prismatic.rotationB << endl;
			out << "      Plane B:  " << constraintData.malleable.prismatic.planeB << endl;
			out << "      Sliding B:  " << constraintData.malleable.prismatic.slidingB << endl;
			out << "      Min Distance:  " << constraintData.malleable.prismatic.minDistance << endl;
			out << "      Max Distance:  " << constraintData.malleable.prismatic.maxDistance << endl;
			out << "      Friction:  " << constraintData.malleable.prismatic.friction << endl;
			out << "      Type:  " << constraintData.malleable.prismatic.motor.type << endl;
			if ( (constraintData.malleable.prismatic.motor.type == 1) ) {
				out << "        Min Force:  " << constraintData.malleable.prismatic.motor.positionMotor.minForce << endl;
				out << "        Max Force:  " << constraintData.malleable.prismatic.motor.positionMotor.maxForce << endl;
				out << "        Tau:  " << constraintData.malleable.prismatic.motor.positionMotor.tau << endl;
				out << "        Damping:  " << constraintData.malleable.prismatic.motor.positionMotor.damping << endl;
				out << "        Proportional Recovery Velocity:  " << constraintData.malleable.prismatic.motor.positionMotor.proportionalRecoveryVelocity << endl;
				out << "        Constant Recovery Velocity:  " << constraintData.malleable.prismatic.motor.positionMotor.constantRecoveryVelocity << endl;
				out << "        Motor Enabled:  " << constraintData.malleable.prismatic.motor.positionMotor.motorEnabled << endl;
			};
			if ( (constraintData.malleable.prismatic.motor.type == 2) ) {
				out << "        Min Force:  " << constraintData.malleable.prismatic.motor.velocityMotor.minForce << endl;
				out << "        Max Force:  " << constraintData.malleable.prismatic.motor.velocityMotor.maxForce << endl;
				out << "        Tau:  " << constraintData.malleable.prismatic.motor.velocityMotor.tau << endl;
				out << "        Target Velocity:  " << constraintData.malleable.prismatic.motor.velocityMotor.targetVelocity << endl;
				out << "        Use Velocity Target:  " << constraintData.malleable.prismatic.motor.velocityMotor.useVelocityTarget << endl;
				out << "        Motor Enabled:  " << constraintData.malleable.prismatic.motor.velocityMotor.motorEnabled << endl;
			};
			if ( (constraintData.malleable.prismatic.motor.type == 3) ) {
				out << "        Min Force:  " << constraintData.malleable.prismatic.motor.springDamperMotor.minForce << endl;
				out << "        Max Force:  " << constraintData.malleable.prismatic.motor.springDamperMotor.maxForce << endl;
				out << "        Spring Constant:  " << constraintData.malleable.prismatic.motor.springDamperMotor.springConstant << endl;
				out << "        Spring Damping:  " << constraintData.malleable.prismatic.motor.springDamperMotor.springDamping << endl;
				out << "        Motor Enabled:  " << constraintData.malleable.prismatic.motor.springDamperMotor.motorEnabled << endl;
			};
		};
		if ( (constraintData.malleable.type == 7) ) {
			out << "      Pivot A:  " << constraintData.malleable.ragdoll.pivotA << endl;
			out << "      Plane A:  " << constraintData.malleable.ragdoll.planeA << endl;
			out << "      Twist A:  " << constraintData.malleable.ragdoll.twistA << endl;
			out << "      Pivot B:  " << constraintData.malleable.ragdoll.pivotB << endl;
			out << "      Plane B:  " << constraintData.malleable.ragdoll.planeB << endl;
			out << "      Twist B:  " << constraintData.malleable.ragdoll.twistB << endl;
			out << "      Motor A:  " << constraintData.malleable.ragdoll.motorA << endl;
			out << "      Motor B:  " << constraintData.malleable.ragdoll.motorB << endl;
			out << "      Cone Max Angle:  " << constraintData.malleable.ragdoll.coneMaxAngle << endl;
			out << "      Plane Min Angle:  " << constraintData.malleable.ragdoll.planeMinAngle << endl;
			out << "      Plane Max Angle:  " << constraintData.malleable.ragdoll.planeMaxAngle << endl;
			out << "      Twist Min Angle:  " << constraintData.malleable.ragdoll.twistMinAngle << endl;
			out << "      Twist Max Angle:  " << constraintData.malleable.ragdoll.twistMaxAngle << endl;
			out << "      Max Friction:  " << constraintData.malleable.ragdoll.maxFriction << endl;
			out << "      Type:  " << constraintData.malleable.ragdoll.motor.type << endl;
			if ( (constraintData.malleable.ragdoll.motor.type == 1) ) {
				out << "        Min Force:  " << constraintData.malleable.ragdoll.motor.positionMotor.minForce << endl;
				out << "        Max Force:  " << constraintData.malleable.ragdoll.motor.positionMotor.maxForce << endl;
				out << "        Tau:  " << constraintData.malleable.ragdoll.motor.positionMotor.tau << endl;
				out << "        Damping:  " << constraintData.malleable.ragdoll.motor.positionMotor.damping << endl;
				out << "        Proportional Recovery Velocity:  " << constraintData.malleable.ragdoll.motor.positionMotor.proportionalRecoveryVelocity << endl;
				out << "        Constant Recovery Velocity:  " << constraintData.malleable.ragdoll.motor.positionMotor.constantRecoveryVelocity << endl;
				out << "        Motor Enabled:  " << constraintData.malleable.ragdoll.motor.positionMotor.motorEnabled << endl;
			};
			if ( (constraintData.malleable.ragdoll.motor.type == 2) ) {
				out << "        Min Force:  " << constraintData.malleable.ragdoll.motor.velocityMotor.minForce << endl;
				out << "        Max Force:  " << constraintData.malleable.ragdoll.motor.velocityMotor.maxForce << endl;
				out << "        Tau:  " << constraintData.malleable.ragdoll.motor.velocityMotor.tau << endl;
				out << "        Target Velocity:  " << constraintData.malleable.ragdoll.motor.velocityMotor.targetVelocity << endl;
				out << "        Use Velocity Target:  " << constraintData.malleable.ragdoll.motor.velocityMotor.useVelocityTarget << endl;
				out << "        Motor Enabled:  " << constraintData.malleable.ragdoll.motor.velocityMotor.motorEnabled << endl;
			};
			if ( (constraintData.malleable.ragdoll.motor.type == 3) ) {
				out << "        Min Force:  " << constraintData.malleable.ragdoll.motor.springDamperMotor.minForce << endl;
				out << "        Max Force:  " << constraintData.malleable.ragdoll.motor.springDamperMotor.maxForce << endl;
				out << "        Spring Constant:  " << constraintData.malleable.ragdoll.motor.springDamperMotor.springConstant << endl;
				out << "        Spring Damping:  " << constraintData.malleable.ragdoll.motor.springDamperMotor.springDamping << endl;
				out << "        Motor Enabled:  " << constraintData.malleable.ragdoll.motor.springDamperMotor.motorEnabled << endl;
			};
		};
		if ( (constraintData.malleable.type == 8) ) {
			out << "      Pivot A:  " << constraintData.malleable.stiffSpring.pivotA << endl;
			out << "      Pivot B:  " << constraintData.malleable.stiffSpring.pivotB << endl;
			out << "      Length:  " << constraintData.malleable.stiffSpring.length << endl;
		};
		out << "    Tau:  " << constraintData.malleable.tau << endl;
		out << "    Damping:  " << constraintData.malleable.damping << endl;
		out << "    Strength:  " << constraintData.malleable.strength << endl;
	};
	out << "  Threshold:  " << threshold << endl;
	out << "  Remove When Broken:  " << removeWhenBroken << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void bhkBreakableConstraint::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	bhkConstraint::FixLinks( objects, link_stack, missing_link_stack, info );
	constraintData.entityA = FixLink<bhkEntity>( objects, link_stack, missing_link_stack, info );
	constraintData.entityB = FixLink<bhkEntity>( objects, link_stack, missing_link_stack, info );
	if ( (constraintData.type == 13) ) {
		constraintData.malleable.entityA = FixLink<bhkEntity>( objects, link_stack, missing_link_stack, info );
		constraintData.malleable.entityB = FixLink<bhkEntity>( objects, link_stack, missing_link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> bhkBreakableConstraint::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkConstraint::GetRefs();
	return refs;
}

std::list<NiObject *> bhkBreakableConstraint::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = bhkConstraint::GetPtrs();
	if ( constraintData.entityA != NULL )
		ptrs.push_back((NiObject *)(constraintData.entityA));
	if ( constraintData.entityB != NULL )
		ptrs.push_back((NiObject *)(constraintData.entityB));
	if ( constraintData.malleable.entityA != NULL )
		ptrs.push_back((NiObject *)(constraintData.malleable.entityA));
	if ( constraintData.malleable.entityB != NULL )
		ptrs.push_back((NiObject *)(constraintData.malleable.entityB));
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//

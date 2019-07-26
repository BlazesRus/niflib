/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

//--BEGIN FILE HEAD CUSTOM CODE--//
#include "../../include/obj/NiNode.h"
//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/ObjectRegistry.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/NiAVObject.h"
#include "../../include/gen/BoundingVolume.h"
#include "../../include/gen/BoxBV.h"
#include "../../include/gen/CapsuleBV.h"
#include "../../include/gen/HalfSpaceBV.h"
#include "../../include/gen/NiBound.h"
#include "../../include/gen/NiPlane.h"
#include "../../include/obj/NiCollisionObject.h"
#include "../../include/obj/NiProperty.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiAVObject::TYPE("NiAVObject", &NiObjectNET::TYPE );

NiAVObject::NiAVObject() : flags((unsigned int)14), scale(1.0f), numProperties((unsigned int)0), unknown2((byte)0), hasBoundingVolume(false), collisionObject(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	parent = NULL;


	parent = NULL;

	//--END CUSTOM CODE--//
}

NiAVObject::~NiAVObject() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//Clear Properties
	ClearProperties();

	//Clear Collision Object Link
	if ( collisionObject != NULL ) {
		collisionObject->SetTarget(NULL);
	}

	//--END CUSTOM CODE--//
}

const Type & NiAVObject::GetType() const {
	return TYPE;
}

NiObject * NiAVObject::Create() {
	return new NiAVObject;
}

void NiAVObject::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiObjectNET::Read( in, link_stack, info );
	if ( (info.userVersion2 > 26) ) {
		NifStream( flags, in, info );
	};
	if ( ( info.version >= 0x03000000 ) && ( (info.userVersion2 <= 26) ) ) {
		NifStream( (unsigned short&)flags, in, info );
	};
	NifStream( translation, in, info );
	NifStream( rotation, in, info );
	NifStream( scale, in, info );
	if ( info.version <= 0x04020200 ) {
		NifStream( velocity, in, info );
	};
	if ( (info.userVersion2 <= 34) ) {
		NifStream( numProperties, in, info );
		properties.resize(numProperties);
		for (unsigned int i2 = 0; i2 < properties.size(); i2++) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
	};
	if ( info.version <= 0x02030000 ) {
		for (unsigned int i2 = 0; i2 < 4; i2++) {
			NifStream( unknown1[i2], in, info );
		};
		NifStream( unknown2, in, info );
	};
	if ( ( info.version >= 0x03000000 ) && ( info.version <= 0x04020200 ) ) {
		NifStream( hasBoundingVolume, in, info );
		if ( hasBoundingVolume ) {
			NifStream( boundingVolume.collisionType, in, info );
			if ( (boundingVolume.collisionType == 0) ) {
				NifStream( boundingVolume.sphere.center, in, info );
				NifStream( boundingVolume.sphere.radius, in, info );
			};
			if ( (boundingVolume.collisionType == 1) ) {
				NifStream( boundingVolume.box.center, in, info );
				for (unsigned int i4 = 0; i4 < 3; i4++) {
					NifStream( boundingVolume.box.axis[i4], in, info );
				};
				NifStream( boundingVolume.box.extent, in, info );
			};
			if ( (boundingVolume.collisionType == 2) ) {
				NifStream( boundingVolume.capsule.center, in, info );
				NifStream( boundingVolume.capsule.origin, in, info );
				NifStream( boundingVolume.capsule.extent, in, info );
				NifStream( boundingVolume.capsule.radius, in, info );
			};
			if ( (boundingVolume.collisionType == 5) ) {
				NifStream( boundingVolume.halfSpace.plane.normal, in, info );
				NifStream( boundingVolume.halfSpace.plane.constant, in, info );
				NifStream( boundingVolume.halfSpace.center, in, info );
			};
		};
	};
	if ( info.version >= 0x0A000100 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiAVObject::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObjectNET::Write( out, link_map, missing_link_stack, info );
	numProperties = (unsigned int)(properties.size());
	if ( (info.userVersion2 > 26) ) {
		NifStream( flags, out, info );
	};
	if ( ( info.version >= 0x03000000 ) && ( (info.userVersion2 <= 26) ) ) {
		NifStream( (unsigned short&)flags, out, info );
	};
	NifStream( translation, out, info );
	NifStream( rotation, out, info );
	NifStream( scale, out, info );
	if ( info.version <= 0x04020200 ) {
		NifStream( velocity, out, info );
	};
	if ( (info.userVersion2 <= 34) ) {
		NifStream( numProperties, out, info );
		for (unsigned int i2 = 0; i2 < properties.size(); i2++) {
			WriteRef( StaticCast<NiObject>(properties[i2]), out, info, link_map, missing_link_stack );
		};
	};
	if ( info.version <= 0x02030000 ) {
		for (unsigned int i2 = 0; i2 < 4; i2++) {
			NifStream( unknown1[i2], out, info );
		};
		NifStream( unknown2, out, info );
	};
	if ( ( info.version >= 0x03000000 ) && ( info.version <= 0x04020200 ) ) {
		NifStream( hasBoundingVolume, out, info );
		if ( hasBoundingVolume ) {
			NifStream( boundingVolume.collisionType, out, info );
			if ( (boundingVolume.collisionType == 0) ) {
				NifStream( boundingVolume.sphere.center, out, info );
				NifStream( boundingVolume.sphere.radius, out, info );
			};
			if ( (boundingVolume.collisionType == 1) ) {
				NifStream( boundingVolume.box.center, out, info );
				for (unsigned int i4 = 0; i4 < 3; i4++) {
					NifStream( boundingVolume.box.axis[i4], out, info );
				};
				NifStream( boundingVolume.box.extent, out, info );
			};
			if ( (boundingVolume.collisionType == 2) ) {
				NifStream( boundingVolume.capsule.center, out, info );
				NifStream( boundingVolume.capsule.origin, out, info );
				NifStream( boundingVolume.capsule.extent, out, info );
				NifStream( boundingVolume.capsule.radius, out, info );
			};
			if ( (boundingVolume.collisionType == 5) ) {
				NifStream( boundingVolume.halfSpace.plane.normal, out, info );
				NifStream( boundingVolume.halfSpace.plane.constant, out, info );
				NifStream( boundingVolume.halfSpace.center, out, info );
			};
		};
	};
	if ( info.version >= 0x0A000100 ) {
		WriteRef( StaticCast<NiObject>(collisionObject), out, info, link_map, missing_link_stack );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiAVObject::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObjectNET::asString();
	numProperties = (unsigned int)(properties.size());
	out << "  Flags:  " << flags << endl;
	out << "  Translation:  " << translation << endl;
	out << "  Rotation:  " << rotation << endl;
	out << "  Scale:  " << scale << endl;
	out << "  Velocity:  " << velocity << endl;
	out << "  Num Properties:  " << numProperties << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < properties.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Properties[" << i1 << "]:  " << properties[i1] << endl;
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
		out << "    Unknown 1[" << i1 << "]:  " << unknown1[i1] << endl;
		array_output_count++;
	};
	out << "  Unknown 2:  " << unknown2 << endl;
	out << "  Has Bounding Volume:  " << hasBoundingVolume << endl;
	if ( hasBoundingVolume ) {
		out << "    Collision Type:  " << boundingVolume.collisionType << endl;
		if ( (boundingVolume.collisionType == 0) ) {
			out << "      Center:  " << boundingVolume.sphere.center << endl;
			out << "      Radius:  " << boundingVolume.sphere.radius << endl;
		};
		if ( (boundingVolume.collisionType == 1) ) {
			out << "      Center:  " << boundingVolume.box.center << endl;
			array_output_count = 0;
			for (unsigned int i3 = 0; i3 < 3; i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
					break;
				};
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					break;
				};
				out << "        Axis[" << i3 << "]:  " << boundingVolume.box.axis[i3] << endl;
				array_output_count++;
			};
			out << "      Extent:  " << boundingVolume.box.extent << endl;
		};
		if ( (boundingVolume.collisionType == 2) ) {
			out << "      Center:  " << boundingVolume.capsule.center << endl;
			out << "      Origin:  " << boundingVolume.capsule.origin << endl;
			out << "      Extent:  " << boundingVolume.capsule.extent << endl;
			out << "      Radius:  " << boundingVolume.capsule.radius << endl;
		};
		if ( (boundingVolume.collisionType == 5) ) {
			out << "      Normal:  " << boundingVolume.halfSpace.plane.normal << endl;
			out << "      Constant:  " << boundingVolume.halfSpace.plane.constant << endl;
			out << "      Center:  " << boundingVolume.halfSpace.center << endl;
		};
	};
	out << "  Collision Object:  " << collisionObject << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiAVObject::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObjectNET::FixLinks( objects, link_stack, missing_link_stack, info );
	if ( (info.userVersion2 <= 34) ) {
		for (unsigned int i2 = 0; i2 < properties.size(); i2++) {
			properties[i2] = FixLink<NiProperty>( objects, link_stack, missing_link_stack, info );
		};
	};
	if ( info.version >= 0x0A000100 ) {
		collisionObject = FixLink<NiCollisionObject>( objects, link_stack, missing_link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiAVObject::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObjectNET::GetRefs();
	for (unsigned int i1 = 0; i1 < properties.size(); i1++) {
		if ( properties[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(properties[i1]));
	};
	if ( collisionObject != NULL )
		refs.push_back(StaticCast<NiObject>(collisionObject));
	return refs;
}

std::list<NiObject *> NiAVObject::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiObjectNET::GetPtrs();
	for (unsigned int i1 = 0; i1 < properties.size(); i1++) {
	};
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

Matrix44 NiAVObject::GetLocalTransform() const {
	return Matrix44( translation, rotation, scale );
}

Matrix44 NiAVObject::GetWorldTransform() const {
	//Get Parent Transform if there is one
	NiNodeRef par = GetParent();

	if ( par != NULL ) {
		//Multipy local matrix and parent world matrix for result
		return GetLocalTransform() * par->GetWorldTransform();
	}
	else {
		//No parent transform, simply return local transform
		return GetLocalTransform();
	}
}

void NiAVObject::SetParent( NiNode * new_parent ) {
	parent = new_parent;
}

Ref<NiNode> NiAVObject::GetParent() const {
	return parent;
}

void NiAVObject::AddProperty( NiProperty * obj ) {
	properties.push_back( obj );
}

void NiAVObject::RemoveProperty( NiProperty * obj ) {
	//Search property list for the one to remove
	for ( vector< NiPropertyRef >::iterator it = properties.begin(); it != properties.end(); ) {
		if ( *it == obj ) {
			it = properties.erase( it );
		} else {
			++it;
		}
	}
}

void NiAVObject::ClearProperties() {
	properties.clear();
}

vector< Ref<NiProperty> > NiAVObject::GetProperties() const {
	return properties;
}

Ref<NiProperty> NiAVObject::GetPropertyByType( const Type & compare_to ) {
	for ( unsigned int i = 0; i < properties.size(); ++i ) {
		if ( properties[i] == NULL ) {
			continue;
		}
		if ( properties[i]->IsSameType( compare_to ) ) {
			return properties[i];
		}
	}
	//No matching properties found, return NULL
	return NULL;
}

unsigned short NiAVObject::GetFlags() const {
	return flags;
}

void NiAVObject::SetFlags( unsigned short n ) {
	flags = n;
}

Matrix33 NiAVObject::GetLocalRotation() const {
	return rotation;
}

void NiAVObject::SetLocalRotation( const Matrix33 & n ) {
	rotation = n;
}

Vector3 NiAVObject::GetLocalTranslation() const {
	return translation;
}

void NiAVObject::SetLocalTranslation( const Vector3 & n ) {
	translation = n;
}

float NiAVObject::GetLocalScale() const {
	return scale;
}

void NiAVObject::SetLocalScale( float n ) {
	scale = n;
}

Vector3 NiAVObject::GetVelocity() const {
	return velocity;
}

void NiAVObject::SetVelocity( const Vector3 & n ) {
	velocity = n;
}

NiAVObject::CollisionType NiAVObject::GetCollisionMode() const {
	//Mask off the 2 significant bits
	unsigned short temp = flags & 0x6;

	//Shift the result one right
	return NiAVObject::CollisionType(temp >> 1);
}

void NiAVObject::SetCollisionMode( CollisionType value ) {
	unsigned short temp = (unsigned short)value;

	//Shift one left
	temp = temp << 1;

	//Zero out the values in the flags for the 2 significant bits
	flags = flags & 0xFFF9;

	//Now combine values
	flags = flags | temp;
}

Ref<NiCollisionObject > NiAVObject::GetCollisionObject() const {
  return collisionObject;
}

void NiAVObject::SetCollisionObject( NiCollisionObject * value ) {
	if ( value != NULL ) {
		if ( value->GetTarget() != NULL ) {
			throw runtime_error( "You have attempted to add a collision object to a NiAVObject which is already attached to another NiAVObject." );
		}
		value->SetTarget( this );
	}

	if ( collisionObject !=NULL ) {
		//Remove unlink previous collision object from this node
		collisionObject->SetTarget(NULL);
	}

	collisionObject = value;
}

void NiAVObject::SetLocalTransform( const Matrix44 & n ) {
	n.Decompose( translation, rotation, scale );
}

bool NiAVObject::GetVisibility() const {
	return !( flags & 1 );
}

void NiAVObject::SetVisibility( bool n ) {
	//Only do anything if the value is different from what it already is
	if ( GetVisibility() != n ) {
		//Flip the bit
		flags ^= 1;
	}
}

bool NiAVObject::HasBoundingVolume() const {
	return hasBoundingVolume;
}

void NiAVObject::ClearBoundingVolume() {
	hasBoundingVolume = false;
}

BoundingVolume NiAVObject::GetBoundingVolume() const {
	if ( hasBoundingVolume == true ) {
		return boundingVolume;
	} else {
		throw runtime_error("This NIAVObject has no Bounding Volume.");
	}
}

void NiAVObject::SetBoundingVolume( const BoundingVolume & n ) {
	boundingVolume = n;
	hasBoundingVolume = true;
}

//--END CUSTOM CODE--//

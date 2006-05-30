/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "bhkShape.h"

//Definition of TYPE constant
const Type bhkShape::TYPE("bhkShape", &BHK_SHAPE_PARENT::TYPE );

bhkShape::bhkShape() BHK_SHAPE_CONSTRUCT {}

bhkShape::~bhkShape() {}

void bhkShape::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  BHK_SHAPE_READ
}

void bhkShape::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  BHK_SHAPE_WRITE
}

string bhkShape::asString( bool verbose ) const {
  BHK_SHAPE_STRING
}

void bhkShape::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  BHK_SHAPE_FIXLINKS
}

const Type & bhkShape::GetType() const {
  return TYPE;
};

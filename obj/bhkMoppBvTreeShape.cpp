/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "bhkMoppBvTreeShape.h"
#include "bhkShape.h"

//Definition of TYPE constant
const Type bhkMoppBvTreeShape::TYPE("bhkMoppBvTreeShape", &BHK_MOPP_BV_TREE_SHAPE_PARENT::TYPE );

bhkMoppBvTreeShape::bhkMoppBvTreeShape() BHK_MOPP_BV_TREE_SHAPE_CONSTRUCT {}

bhkMoppBvTreeShape::~bhkMoppBvTreeShape() {}

void bhkMoppBvTreeShape::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  BHK_MOPP_BV_TREE_SHAPE_READ
}

void bhkMoppBvTreeShape::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  BHK_MOPP_BV_TREE_SHAPE_WRITE
}

string bhkMoppBvTreeShape::asString( bool verbose ) const {
  BHK_MOPP_BV_TREE_SHAPE_STRING
}

void bhkMoppBvTreeShape::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  BHK_MOPP_BV_TREE_SHAPE_FIXLINKS
}

const Type & bhkMoppBvTreeShape::GetType() const {
  return TYPE;
};

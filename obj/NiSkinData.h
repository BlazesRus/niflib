/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISKINDATA_H_
#define _NISKINDATA_H_

#include "xml_extract.h"
#include NI_SKIN_DATA_INCLUDE

/*
 * NiSkinData
 */

class NiSkinData;
typedef Ref<NiSkinData> NiSkinDataRef;

class NiSkinData : public NI_SKIN_DATA_PARENT {
public:
  NiSkinData();
  ~NiSkinData();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  NI_SKIN_DATA_MEMBERS
};

#endif
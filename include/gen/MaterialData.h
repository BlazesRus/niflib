/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _MATERIALDATA_H_
#define _MATERIALDATA_H_

#include "../NIF_IO.h"

namespace Niflib {


struct MaterialData {
	/*! Default Constructor */
	NIFLIB_API MaterialData();
	/*! Default Destructor */
	NIFLIB_API ~MaterialData();
	/*! Copy Constructor */
	NIFLIB_API MaterialData( const MaterialData & src );
	/*! Copy Operator */
	NIFLIB_API MaterialData & operator=( const MaterialData & src );
	/*! Shader. */
	bool hasShader;
	/*! The shader name. */
	IndexString shaderName;
	/*!
	 * Extra data associated with the shader. A value of -1 means the shader is the
	 * default implementation.
	 */
	int shaderExtraData;
	mutable unsigned int numMaterials;
	/*! The name of the material. */
	vector<IndexString > materialName;
	/*!
	 * Extra data associated with the material. A value of -1 means the material is the
	 * default implementation.
	 */
	vector<int > materialExtraData;
	/*! The index of the currently active material. */
	int activeMaterial;
	/*! Cyanide extension (only in version 10.2.0.0?). */
	byte unknownByte;
	/*! Unknown. */
	int unknownInteger2;
	/*!
	 * Whether the materials for this object always needs to be updated before
	 * rendering with them.
	 */
	bool materialNeedsUpdate;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif

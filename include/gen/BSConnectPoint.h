/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BSCONNECTPOINT_H_
#define _BSCONNECTPOINT_H_

#include "../NIF_IO.h"

namespace Niflib {


struct BSConnectPoint {
	/*! Default Constructor */
	NIFLIB_API BSConnectPoint();
	/*! Default Destructor */
	NIFLIB_API ~BSConnectPoint();
	/*! Copy Constructor */
	NIFLIB_API BSConnectPoint( const BSConnectPoint & src );
	/*! Copy Operator */
	NIFLIB_API BSConnectPoint & operator=( const BSConnectPoint & src );
	string parent;
	string name;
	Quaternion rotation;
	Vector3 translation;
	float scale;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif

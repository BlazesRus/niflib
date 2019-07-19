/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _HAVOKFILTER_H_
#define _HAVOKFILTER_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * Bethesda Havok. Collision filter info representing Layer, Flags, Part Number,
 * and Group all combined into one uint.
 */
struct HavokFilter {
	/*! Default Constructor */
	NIFLIB_API HavokFilter();
	/*! Default Destructor */
	NIFLIB_API ~HavokFilter();
	/*! Copy Constructor */
	NIFLIB_API HavokFilter( const HavokFilter & src );
	/*! Copy Operator */
	NIFLIB_API HavokFilter & operator=( const HavokFilter & src );
	/*! The layer the collision belongs to. */
	OblivionLayer layer_ob;
	/*! The layer the collision belongs to. */
	Fallout3Layer layer_fo;
	/*! The layer the collision belongs to. */
	SkyrimLayer layer_sk;
	/*!
	 * FLAGS are stored in highest 3 bits:
	 *                 Bit 7: sets the LINK property and controls whether this body is
	 * physically linked to others.
	 *                 Bit 6: turns collision off (not used for Layer BIPED).
	 *                 Bit 5: sets the SCALED property.
	 * 
	 *                 PART NUMBER is stored in bits 0-4. Used only when Layer is set
	 * to BIPED.
	 * 
	 *                 Part Numbers for Oblivion, Fallout 3, Skyrim:
	 *                 0 - OTHER
	 *                 1 - HEAD
	 *                 2 - BODY
	 *                 3 - SPINE1
	 *                 4 - SPINE2
	 *                 5 - LUPPERARM
	 *                 6 - LFOREARM
	 *                 7 - LHAND
	 *                 8 - LTHIGH
	 *                 9 - LCALF
	 *                 10 - LFOOT
	 *                 11 - RUPPERARM
	 *                 12 - RFOREARM
	 *                 13 - RHAND
	 *                 14 - RTHIGH
	 *                 15 - RCALF
	 *                 16 - RFOOT
	 *                 17 - TAIL
	 *                 18 - SHIELD
	 *                 19 - QUIVER
	 *                 20 - WEAPON
	 *                 21 - PONYTAIL
	 *                 22 - WING
	 *                 23 - PACK
	 *                 24 - CHAIN
	 *                 25 - ADDONHEAD
	 *                 26 - ADDONCHEST
	 *                 27 - ADDONARM
	 *                 28 - ADDONLEG
	 *                 29-31 - NULL
	 */
	byte flagsAndPartNumber;
	unsigned short group;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif

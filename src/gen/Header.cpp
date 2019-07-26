/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/Header.h"
#include "../../include/gen/ByteArray.h"
#include "../../include/gen/ExportInfo.h"
using namespace Niflib;

//Constructor
Header::Header() : version((unsigned int)0x04000002), endianType((EndianType)ENDIAN_LITTLE), userVersion((unsigned int)0), numBlocks((unsigned int)0), userVersion2((unsigned int)0), numBlockTypes((unsigned short)0), numStrings((unsigned int)0), maxStringLength((unsigned int)0), numGroups((unsigned int)0) {};

//Copy Constructor
Header::Header( const Header & src ) {
	*this = src;
};

//Copy Operator
Header & Header::operator=( const Header & src ) {
	this->headerString = src.headerString;
	this->copyright = src.copyright;
	this->version = src.version;
	this->endianType = src.endianType;
	this->userVersion = src.userVersion;
	this->numBlocks = src.numBlocks;
	this->userVersion2 = src.userVersion2;
	this->exportInfo = src.exportInfo;
	this->maxFilepath = src.maxFilepath;
	this->metadata = src.metadata;
	this->numBlockTypes = src.numBlockTypes;
	this->blockTypes = src.blockTypes;
	this->blockTypeIndex = src.blockTypeIndex;
	this->blockSize = src.blockSize;
	this->numStrings = src.numStrings;
	this->maxStringLength = src.maxStringLength;
	this->strings = src.strings;
	this->numGroups = src.numGroups;
	this->groups = src.groups;
	return *this;
};

//Destructor
Header::~Header() {};
NifInfo Header::Read( istream& in ) {
	//Declare NifInfo structure
	NifInfo info;

	NifStream( headerString, in, info );
	if ( info.version <= 0x03010000 ) {
		for (unsigned int i2 = 0; i2 < 3; i2++) {
			NifStream( copyright[i2], in, info );
		};
	};
	if ( info.version >= 0x03010001 ) {
		NifStream( version, in, info );
	};
	if ( info.version >= 0x14000003 ) {
		NifStream( endianType, in, info );
	};
	if ( info.version >= 0x0A000108 ) {
		NifStream( userVersion, in, info );
	};
	if ( info.version >= 0x03010001 ) {
		NifStream( numBlocks, in, info );
	};
	if ( (((version == 0x14020007) || ((version == 0x14000005) || ((version >= 0x0A000102) && ((version <= 0x14000004) && (userVersion <= 11))))) && (userVersion >= 3)) ) {
		NifStream( userVersion2, in, info );
		NifStream( exportInfo.author, in, info );
		NifStream( exportInfo.processScript, in, info );
		NifStream( exportInfo.exportScript, in, info );
	};
	if ( (userVersion2 == 130) ) {
		NifStream( maxFilepath, in, info );
	};
	if ( info.version >= 0x1E000000 ) {
		NifStream( metadata.dataSize, in, info );
		metadata.data.resize(metadata.dataSize);
		for (unsigned int i2 = 0; i2 < metadata.data.size(); i2++) {
			NifStream( metadata.data[i2], in, info );
		};
	};
	if ( info.version >= 0x05000001 ) {
		NifStream( numBlockTypes, in, info );
		blockTypes.resize(numBlockTypes);
		for (unsigned int i2 = 0; i2 < blockTypes.size(); i2++) {
			NifStream( blockTypes[i2], in, info );
		};
		blockTypeIndex.resize(numBlocks);
		for (unsigned int i2 = 0; i2 < blockTypeIndex.size(); i2++) {
			NifStream( blockTypeIndex[i2], in, info );
		};
	};
	if ( info.version >= 0x14020005 ) {
		blockSize.resize(numBlocks);
		for (unsigned int i2 = 0; i2 < blockSize.size(); i2++) {
			NifStream( blockSize[i2], in, info );
		};
	};
	if ( info.version >= 0x14010001 ) {
		NifStream( numStrings, in, info );
		NifStream( maxStringLength, in, info );
		strings.resize(numStrings);
		for (unsigned int i2 = 0; i2 < strings.size(); i2++) {
			NifStream( strings[i2], in, info );
		};
	};
	if ( info.version >= 0x05000006 ) {
		NifStream( numGroups, in, info );
		groups.resize(numGroups);
		for (unsigned int i2 = 0; i2 < groups.size(); i2++) {
			NifStream( groups[i2], in, info );
		};
	};

	//Copy info.version to local version var.
	version = info.version;

	//Fill out and return NifInfo structure.
	info.userVersion = userVersion;
	info.userVersion2 = userVersion2;
	info.endian = EndianType(endianType);
	info.author = exportInfo.author;
	info.exportScript = exportInfo.exportScript;
	info.processScript = exportInfo.processScript;

	return info;

}

void Header::Write( ostream& out, const NifInfo & info ) const {
	numGroups = (unsigned int)(groups.size());
	numStrings = (unsigned int)(strings.size());
	numBlockTypes = (unsigned short)(blockTypes.size());
	numBlocks = (unsigned int)(blockTypeIndex.size());
	NifStream( headerString, out, info );
	if ( info.version <= 0x03010000 ) {
		for (unsigned int i2 = 0; i2 < 3; i2++) {
			NifStream( copyright[i2], out, info );
		};
	};
	if ( info.version >= 0x03010001 ) {
		NifStream( version, out, info );
	};
	if ( info.version >= 0x14000003 ) {
		NifStream( endianType, out, info );
	};
	if ( info.version >= 0x0A000108 ) {
		NifStream( userVersion, out, info );
	};
	if ( info.version >= 0x03010001 ) {
		NifStream( numBlocks, out, info );
	};
	if ( (((version == 0x14020007) || ((version == 0x14000005) || ((version >= 0x0A000102) && ((version <= 0x14000004) && (userVersion <= 11))))) && (userVersion >= 3)) ) {
		NifStream( userVersion2, out, info );
		NifStream( exportInfo.author, out, info );
		NifStream( exportInfo.processScript, out, info );
		NifStream( exportInfo.exportScript, out, info );
	};
	if ( (userVersion2 == 130) ) {
		NifStream( maxFilepath, out, info );
	};
	if ( info.version >= 0x1E000000 ) {
		metadata.dataSize = (unsigned int)(metadata.data.size());
		NifStream( metadata.dataSize, out, info );
		for (unsigned int i2 = 0; i2 < metadata.data.size(); i2++) {
			NifStream( metadata.data[i2], out, info );
		};
	};
	if ( info.version >= 0x05000001 ) {
		NifStream( numBlockTypes, out, info );
		for (unsigned int i2 = 0; i2 < blockTypes.size(); i2++) {
			NifStream( blockTypes[i2], out, info );
		};
		for (unsigned int i2 = 0; i2 < blockTypeIndex.size(); i2++) {
			NifStream( blockTypeIndex[i2], out, info );
		};
	};
	if ( info.version >= 0x14020005 ) {
		for (unsigned int i2 = 0; i2 < blockSize.size(); i2++) {
			NifStream( blockSize[i2], out, info );
		};
	};
	if ( info.version >= 0x14010001 ) {
		NifStream( numStrings, out, info );
		NifStream( maxStringLength, out, info );
		for (unsigned int i2 = 0; i2 < strings.size(); i2++) {
			NifStream( strings[i2], out, info );
		};
	};
	if ( info.version >= 0x05000006 ) {
		NifStream( numGroups, out, info );
		for (unsigned int i2 = 0; i2 < groups.size(); i2++) {
			NifStream( groups[i2], out, info );
		};
	};
}

string Header::asString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	numGroups = (unsigned int)(groups.size());
	numStrings = (unsigned int)(strings.size());
	numBlockTypes = (unsigned short)(blockTypes.size());
	numBlocks = (unsigned int)(blockTypeIndex.size());
	out << "  Header String:  " << headerString << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Copyright[" << i1 << "]:  " << copyright[i1] << endl;
		array_output_count++;
	};
	out << "  Version:  " << version << endl;
	out << "  Endian Type:  " << endianType << endl;
	out << "  User Version:  " << userVersion << endl;
	out << "  Num Blocks:  " << numBlocks << endl;
	if ( (((version == 0x14020007) || ((version == 0x14000005) || ((version >= 0x0A000102) && ((version <= 0x14000004) && (userVersion <= 11))))) && (userVersion >= 3)) ) {
		out << "    User Version 2:  " << userVersion2 << endl;
		out << "    Author:  " << exportInfo.author << endl;
		out << "    Process Script:  " << exportInfo.processScript << endl;
		out << "    Export Script:  " << exportInfo.exportScript << endl;
	};
	if ( (userVersion2 == 130) ) {
		out << "    Max Filepath:  " << maxFilepath << endl;
	};
	metadata.dataSize = (unsigned int)(metadata.data.size());
	out << "  Data Size:  " << metadata.dataSize << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < metadata.data.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Data[" << i1 << "]:  " << metadata.data[i1] << endl;
		array_output_count++;
	};
	out << "  Num Block Types:  " << numBlockTypes << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < blockTypes.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Block Types[" << i1 << "]:  " << blockTypes[i1] << endl;
		array_output_count++;
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < blockTypeIndex.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Block Type Index[" << i1 << "]:  " << blockTypeIndex[i1] << endl;
		array_output_count++;
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < blockSize.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Block Size[" << i1 << "]:  " << blockSize[i1] << endl;
		array_output_count++;
	};
	out << "  Num Strings:  " << numStrings << endl;
	out << "  Max String Length:  " << maxStringLength << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < strings.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Strings[" << i1 << "]:  " << strings[i1] << endl;
		array_output_count++;
	};
	out << "  Num Groups:  " << numGroups << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < groups.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Groups[" << i1 << "]:  " << groups[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

//--BEGIN MISC CUSTOM CODE--//

HeaderString Header::getHeaderString() {
	return headerString;
}

unsigned int Header::getVersion() {
	return version;
}

EndianType Header::getEndianType() {
	return endianType;
}

unsigned int Header::getUserVersion() {
	return userVersion;
}

unsigned int Header::getUserVersion2() {
	return userVersion2;
}

vector<string> Header::getBlockTypes() {
	return blockTypes;
}


vector<unsigned short> Niflib::Header::getBlockTypeIndex() {
	return blockTypeIndex;
}

//--END CUSTOM CODE--//

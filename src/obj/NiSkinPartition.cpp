/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

//--BEGIN FILE HEAD CUSTOM CODE--//
#include "../../include/obj/NiSkinPartition.h"
#include "../../include/gen/SkinPartition.h"
#include "../../include/obj/NiSkinInstance.h"
#include "../../include/obj/NiSkinData.h"
#include "../../include/obj/NiTriBasedGeom.h"
#include "../../include/obj/NiTriBasedGeomData.h"
#include "../../include/obj/NiTriStripsData.h"
#include "../../include/gen/SkinWeight.h"
#include "../../NvTriStrip/NvTriStrip.h"

using namespace NvTriStrip;
using namespace Niflib;

#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

typedef std::vector<float> WeightList;
typedef std::vector<unsigned short> BoneList;
typedef std::vector<unsigned short> Strip;
typedef std::vector<Strip> Strips;
typedef std::vector<Triangle> Triangles;

typedef std::pair<int,float> BoneWeight;
typedef std::vector<BoneWeight> BoneWeightList;
typedef SkinPartition Partition;
typedef vector<SkinPartition> PartitionList;

//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/ObjectRegistry.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/NiSkinPartition.h"
#include "../../include/gen/BSVertexDesc.h"
#include "../../include/gen/SkinPartition.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiSkinPartition::TYPE("NiSkinPartition", &NiObject::TYPE );

NiSkinPartition::NiSkinPartition() : numSkinPartitionBlocks((unsigned int)0), dataSize((unsigned int)0), vertexSize((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiSkinPartition::~NiSkinPartition() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiSkinPartition::GetType() const {
	return TYPE;
}

NiObject * NiSkinPartition::Create() {
	return new NiSkinPartition;
}

void NiSkinPartition::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::Read( in, link_stack, info );
	NifStream( numSkinPartitionBlocks, in, info );
	if ( (!((info.version == 0x14020007) && (info.userVersion2 == 100))) ) {
		skinPartitionBlocks.resize(numSkinPartitionBlocks);
		for (unsigned int i2 = 0; i2 < skinPartitionBlocks.size(); i2++) {
			NifStream( skinPartitionBlocks[i2].numVertices, in, info );
			NifStream( skinPartitionBlocks[i2].numTriangles, in, info );
			NifStream( skinPartitionBlocks[i2].numBones, in, info );
			NifStream( skinPartitionBlocks[i2].numStrips, in, info );
			NifStream( skinPartitionBlocks[i2].numWeightsPerVertex, in, info );
			skinPartitionBlocks[i2].bones.resize(skinPartitionBlocks[i2].numBones);
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i2].bones.size(); i3++) {
				NifStream( skinPartitionBlocks[i2].bones[i3], in, info );
			};
			if ( info.version >= 0x0A010000 ) {
				NifStream( skinPartitionBlocks[i2].hasVertexMap, in, info );
			};
			if ( info.version <= 0x0A000102 ) {
				skinPartitionBlocks[i2].vertexMap.resize(skinPartitionBlocks[i2].numVertices);
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i2].vertexMap.size(); i4++) {
					NifStream( skinPartitionBlocks[i2].vertexMap[i4], in, info );
				};
			};
			if ( info.version >= 0x0A010000 ) {
				if ( skinPartitionBlocks[i2].hasVertexMap ) {
					skinPartitionBlocks[i2].vertexMap.resize(skinPartitionBlocks[i2].numVertices);
					for (unsigned int i5 = 0; i5 < skinPartitionBlocks[i2].vertexMap.size(); i5++) {
						NifStream( (unsigned short&)skinPartitionBlocks[i2].vertexMap[i5], in, info );
					};
				};
				NifStream( skinPartitionBlocks[i2].hasVertexWeights, in, info );
			};
			if ( info.version <= 0x0A000102 ) {
				skinPartitionBlocks[i2].vertexWeights.resize(skinPartitionBlocks[i2].numVertices);
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i2].vertexWeights.size(); i4++) {
					skinPartitionBlocks[i2].vertexWeights[i4].resize(skinPartitionBlocks[i2].numWeightsPerVertex);
					for (unsigned int i5 = 0; i5 < skinPartitionBlocks[i2].vertexWeights[i4].size(); i5++) {
						NifStream( skinPartitionBlocks[i2].vertexWeights[i4][i5], in, info );
					};
				};
			};
			if ( info.version >= 0x0A010000 ) {
				if ( skinPartitionBlocks[i2].hasVertexWeights ) {
					skinPartitionBlocks[i2].vertexWeights.resize(skinPartitionBlocks[i2].numVertices);
					for (unsigned int i5 = 0; i5 < skinPartitionBlocks[i2].vertexWeights.size(); i5++) {
						skinPartitionBlocks[i2].vertexWeights[i5].resize(skinPartitionBlocks[i2].numWeightsPerVertex);
						for (unsigned int i6 = 0; i6 < skinPartitionBlocks[i2].vertexWeights[i5].size(); i6++) {
							NifStream( (float&)skinPartitionBlocks[i2].vertexWeights[i5][i6], in, info );
						};
					};
				};
			};
			skinPartitionBlocks[i2].stripLengths.resize(skinPartitionBlocks[i2].numStrips);
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i2].stripLengths.size(); i3++) {
				NifStream( skinPartitionBlocks[i2].stripLengths[i3], in, info );
			};
			if ( info.version >= 0x0A010000 ) {
				NifStream( skinPartitionBlocks[i2].hasFaces, in, info );
			};
			if ( info.version <= 0x0A000102 ) {
				if ( (skinPartitionBlocks[i2].numStrips != 0) ) {
					skinPartitionBlocks[i2].strips.resize(skinPartitionBlocks[i2].numStrips);
					for (unsigned int i5 = 0; i5 < skinPartitionBlocks[i2].strips.size(); i5++) {
						skinPartitionBlocks[i2].strips[i5].resize(skinPartitionBlocks[i2].stripLengths[i5]);
						for (unsigned int i6 = 0; i6 < skinPartitionBlocks[i2].stripLengths[i5]; i6++) {
							NifStream( skinPartitionBlocks[i2].strips[i5][i6], in, info );
						};
					};
				};
			};
			if ( info.version >= 0x0A010000 ) {
				if ( (skinPartitionBlocks[i2].hasFaces && (skinPartitionBlocks[i2].numStrips != 0)) ) {
					skinPartitionBlocks[i2].strips.resize(skinPartitionBlocks[i2].numStrips);
					for (unsigned int i5 = 0; i5 < skinPartitionBlocks[i2].strips.size(); i5++) {
						skinPartitionBlocks[i2].strips[i5].resize(skinPartitionBlocks[i2].stripLengths[i5]);
						for (unsigned int i6 = 0; i6 < skinPartitionBlocks[i2].stripLengths[i5]; i6++) {
							NifStream( (unsigned short&)skinPartitionBlocks[i2].strips[i5][i6], in, info );
						};
					};
				};
			};
			if ( info.version <= 0x0A000102 ) {
				if ( (skinPartitionBlocks[i2].numStrips == 0) ) {
					skinPartitionBlocks[i2].triangles.resize(skinPartitionBlocks[i2].numTriangles);
					for (unsigned int i5 = 0; i5 < skinPartitionBlocks[i2].triangles.size(); i5++) {
						NifStream( skinPartitionBlocks[i2].triangles[i5], in, info );
					};
				};
			};
			if ( info.version >= 0x0A010000 ) {
				if ( (skinPartitionBlocks[i2].hasFaces && (skinPartitionBlocks[i2].numStrips == 0)) ) {
					skinPartitionBlocks[i2].triangles.resize(skinPartitionBlocks[i2].numTriangles);
					for (unsigned int i5 = 0; i5 < skinPartitionBlocks[i2].triangles.size(); i5++) {
						NifStream( (Triangle&)skinPartitionBlocks[i2].triangles[i5], in, info );
					};
				};
			};
			NifStream( skinPartitionBlocks[i2].hasBoneIndices, in, info );
			if ( skinPartitionBlocks[i2].hasBoneIndices ) {
				skinPartitionBlocks[i2].boneIndices.resize(skinPartitionBlocks[i2].numVertices);
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i2].boneIndices.size(); i4++) {
					skinPartitionBlocks[i2].boneIndices[i4].resize(skinPartitionBlocks[i2].numWeightsPerVertex);
					for (unsigned int i5 = 0; i5 < skinPartitionBlocks[i2].boneIndices[i4].size(); i5++) {
						NifStream( skinPartitionBlocks[i2].boneIndices[i4][i5], in, info );
					};
				};
			};
			if ( (info.userVersion2 > 34) ) {
				NifStream( skinPartitionBlocks[i2].unknownShort, in, info );
			};
			if ( info.userVersion2 == 100 ) {
				NifStream( skinPartitionBlocks[i2].vertexDesc.vf1, in, info );
				NifStream( skinPartitionBlocks[i2].vertexDesc.vf2, in, info );
				NifStream( skinPartitionBlocks[i2].vertexDesc.vf3, in, info );
				NifStream( skinPartitionBlocks[i2].vertexDesc.vf4, in, info );
				NifStream( skinPartitionBlocks[i2].vertexDesc.vf5, in, info );
				NifStream( skinPartitionBlocks[i2].vertexDesc.vertexAttributes, in, info );
				NifStream( skinPartitionBlocks[i2].vertexDesc.vf8, in, info );
				skinPartitionBlocks[i2].trianglesCopy.resize(skinPartitionBlocks[i2].numTriangles);
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i2].trianglesCopy.size(); i4++) {
					NifStream( skinPartitionBlocks[i2].trianglesCopy[i4], in, info );
				};
			};
		};
	};
	if ( info.userVersion2 == 100 ) {
		NifStream( dataSize, in, info );
		NifStream( vertexSize, in, info );
		NifStream( vertexDesc.vf1, in, info );
		NifStream( vertexDesc.vf2, in, info );
		NifStream( vertexDesc.vf3, in, info );
		NifStream( vertexDesc.vf4, in, info );
		NifStream( vertexDesc.vf5, in, info );
		NifStream( vertexDesc.vertexAttributes, in, info );
		NifStream( vertexDesc.vf8, in, info );
		if ( (dataSize > 0) ) {
			vertexData.resize((dataSize / vertexSize));
			for (unsigned int i3 = 0; i3 < vertexData.size(); i3++) {
				NifStream( vertexData[i3], in, info, vertexDesc.vertexAttributes );
			};
		};
		partition.resize(numSkinPartitionBlocks);
		for (unsigned int i2 = 0; i2 < partition.size(); i2++) {
			NifStream( partition[i2].numVertices, in, info );
			NifStream( partition[i2].numTriangles, in, info );
			NifStream( partition[i2].numBones, in, info );
			NifStream( partition[i2].numStrips, in, info );
			NifStream( partition[i2].numWeightsPerVertex, in, info );
			partition[i2].bones.resize(partition[i2].numBones);
			for (unsigned int i3 = 0; i3 < partition[i2].bones.size(); i3++) {
				NifStream( partition[i2].bones[i3], in, info );
			};
			if ( info.version >= 0x0A010000 ) {
				NifStream( partition[i2].hasVertexMap, in, info );
			};
			if ( info.version <= 0x0A000102 ) {
				partition[i2].vertexMap.resize(partition[i2].numVertices);
				for (unsigned int i4 = 0; i4 < partition[i2].vertexMap.size(); i4++) {
					NifStream( partition[i2].vertexMap[i4], in, info );
				};
			};
			if ( info.version >= 0x0A010000 ) {
				if ( partition[i2].hasVertexMap ) {
					partition[i2].vertexMap.resize(partition[i2].numVertices);
					for (unsigned int i5 = 0; i5 < partition[i2].vertexMap.size(); i5++) {
						NifStream( (unsigned short&)partition[i2].vertexMap[i5], in, info );
					};
				};
				NifStream( partition[i2].hasVertexWeights, in, info );
			};
			if ( info.version <= 0x0A000102 ) {
				partition[i2].vertexWeights.resize(partition[i2].numVertices);
				for (unsigned int i4 = 0; i4 < partition[i2].vertexWeights.size(); i4++) {
					partition[i2].vertexWeights[i4].resize(partition[i2].numWeightsPerVertex);
					for (unsigned int i5 = 0; i5 < partition[i2].vertexWeights[i4].size(); i5++) {
						NifStream( partition[i2].vertexWeights[i4][i5], in, info );
					};
				};
			};
			if ( info.version >= 0x0A010000 ) {
				if ( partition[i2].hasVertexWeights ) {
					partition[i2].vertexWeights.resize(partition[i2].numVertices);
					for (unsigned int i5 = 0; i5 < partition[i2].vertexWeights.size(); i5++) {
						partition[i2].vertexWeights[i5].resize(partition[i2].numWeightsPerVertex);
						for (unsigned int i6 = 0; i6 < partition[i2].vertexWeights[i5].size(); i6++) {
							NifStream( (float&)partition[i2].vertexWeights[i5][i6], in, info );
						};
					};
				};
			};
			partition[i2].stripLengths.resize(partition[i2].numStrips);
			for (unsigned int i3 = 0; i3 < partition[i2].stripLengths.size(); i3++) {
				NifStream( partition[i2].stripLengths[i3], in, info );
			};
			if ( info.version >= 0x0A010000 ) {
				NifStream( partition[i2].hasFaces, in, info );
			};
			if ( info.version <= 0x0A000102 ) {
				if ( (partition[i2].numStrips != 0) ) {
					partition[i2].strips.resize(partition[i2].numStrips);
					for (unsigned int i5 = 0; i5 < partition[i2].strips.size(); i5++) {
						partition[i2].strips[i5].resize(partition[i2].stripLengths[i5]);
						for (unsigned int i6 = 0; i6 < partition[i2].stripLengths[i5]; i6++) {
							NifStream( partition[i2].strips[i5][i6], in, info );
						};
					};
				};
			};
			if ( info.version >= 0x0A010000 ) {
				if ( (partition[i2].hasFaces && (partition[i2].numStrips != 0)) ) {
					partition[i2].strips.resize(partition[i2].numStrips);
					for (unsigned int i5 = 0; i5 < partition[i2].strips.size(); i5++) {
						partition[i2].strips[i5].resize(partition[i2].stripLengths[i5]);
						for (unsigned int i6 = 0; i6 < partition[i2].stripLengths[i5]; i6++) {
							NifStream( (unsigned short&)partition[i2].strips[i5][i6], in, info );
						};
					};
				};
			};
			if ( info.version <= 0x0A000102 ) {
				if ( (partition[i2].numStrips == 0) ) {
					partition[i2].triangles.resize(partition[i2].numTriangles);
					for (unsigned int i5 = 0; i5 < partition[i2].triangles.size(); i5++) {
						NifStream( partition[i2].triangles[i5], in, info );
					};
				};
			};
			if ( info.version >= 0x0A010000 ) {
				if ( (partition[i2].hasFaces && (partition[i2].numStrips == 0)) ) {
					partition[i2].triangles.resize(partition[i2].numTriangles);
					for (unsigned int i5 = 0; i5 < partition[i2].triangles.size(); i5++) {
						NifStream( (Triangle&)partition[i2].triangles[i5], in, info );
					};
				};
			};
			NifStream( partition[i2].hasBoneIndices, in, info );
			if ( partition[i2].hasBoneIndices ) {
				partition[i2].boneIndices.resize(partition[i2].numVertices);
				for (unsigned int i4 = 0; i4 < partition[i2].boneIndices.size(); i4++) {
					partition[i2].boneIndices[i4].resize(partition[i2].numWeightsPerVertex);
					for (unsigned int i5 = 0; i5 < partition[i2].boneIndices[i4].size(); i5++) {
						NifStream( partition[i2].boneIndices[i4][i5], in, info );
					};
				};
			};
			if ( (info.userVersion2 > 34) ) {
				NifStream( partition[i2].unknownShort, in, info );
			};
			if ( info.userVersion2 == 100 ) {
				NifStream( partition[i2].vertexDesc.vf1, in, info );
				NifStream( partition[i2].vertexDesc.vf2, in, info );
				NifStream( partition[i2].vertexDesc.vf3, in, info );
				NifStream( partition[i2].vertexDesc.vf4, in, info );
				NifStream( partition[i2].vertexDesc.vf5, in, info );
				NifStream( partition[i2].vertexDesc.vertexAttributes, in, info );
				NifStream( partition[i2].vertexDesc.vf8, in, info );
				partition[i2].trianglesCopy.resize(partition[i2].numTriangles);
				for (unsigned int i4 = 0; i4 < partition[i2].trianglesCopy.size(); i4++) {
					NifStream( partition[i2].trianglesCopy[i4], in, info );
				};
			};
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiSkinPartition::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, missing_link_stack, info );
	numSkinPartitionBlocks = (unsigned int)(skinPartitionBlocks.size());
	NifStream( numSkinPartitionBlocks, out, info );
	if ( (!((info.version == 0x14020007) && (info.userVersion2 == 100))) ) {
		for (unsigned int i2 = 0; i2 < skinPartitionBlocks.size(); i2++) {
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i2].strips.size(); i3++)
				skinPartitionBlocks[i2].stripLengths[i3] = (unsigned short)(skinPartitionBlocks[i2].strips[i3].size());
			skinPartitionBlocks[i2].numWeightsPerVertex = (unsigned short)((skinPartitionBlocks[i2].vertexWeights.size() > 0) ? skinPartitionBlocks[i2].vertexWeights[0].size() : 0);
			skinPartitionBlocks[i2].numStrips = (unsigned short)(skinPartitionBlocks[i2].stripLengths.size());
			skinPartitionBlocks[i2].numBones = (unsigned short)(skinPartitionBlocks[i2].bones.size());
			skinPartitionBlocks[i2].numTriangles = skinPartitionBlocks[i2].numTrianglesCalc(info);
			skinPartitionBlocks[i2].numVertices = (unsigned short)(skinPartitionBlocks[i2].vertexMap.size());
			NifStream( skinPartitionBlocks[i2].numVertices, out, info );
			NifStream( skinPartitionBlocks[i2].numTriangles, out, info );
			NifStream( skinPartitionBlocks[i2].numBones, out, info );
			NifStream( skinPartitionBlocks[i2].numStrips, out, info );
			NifStream( skinPartitionBlocks[i2].numWeightsPerVertex, out, info );
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i2].bones.size(); i3++) {
				NifStream( skinPartitionBlocks[i2].bones[i3], out, info );
			};
			if ( info.version >= 0x0A010000 ) {
				NifStream( skinPartitionBlocks[i2].hasVertexMap, out, info );
			};
			if ( info.version <= 0x0A000102 ) {
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i2].vertexMap.size(); i4++) {
					NifStream( skinPartitionBlocks[i2].vertexMap[i4], out, info );
				};
			};
			if ( info.version >= 0x0A010000 ) {
				if ( skinPartitionBlocks[i2].hasVertexMap ) {
					for (unsigned int i5 = 0; i5 < skinPartitionBlocks[i2].vertexMap.size(); i5++) {
						NifStream( (unsigned short&)skinPartitionBlocks[i2].vertexMap[i5], out, info );
					};
				};
				NifStream( skinPartitionBlocks[i2].hasVertexWeights, out, info );
			};
			if ( info.version <= 0x0A000102 ) {
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i2].vertexWeights.size(); i4++) {
					for (unsigned int i5 = 0; i5 < skinPartitionBlocks[i2].vertexWeights[i4].size(); i5++) {
						NifStream( skinPartitionBlocks[i2].vertexWeights[i4][i5], out, info );
					};
				};
			};
			if ( info.version >= 0x0A010000 ) {
				if ( skinPartitionBlocks[i2].hasVertexWeights ) {
					for (unsigned int i5 = 0; i5 < skinPartitionBlocks[i2].vertexWeights.size(); i5++) {
						for (unsigned int i6 = 0; i6 < skinPartitionBlocks[i2].vertexWeights[i5].size(); i6++) {
							NifStream( (float&)skinPartitionBlocks[i2].vertexWeights[i5][i6], out, info );
						};
					};
				};
			};
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i2].stripLengths.size(); i3++) {
				NifStream( skinPartitionBlocks[i2].stripLengths[i3], out, info );
			};
			if ( info.version >= 0x0A010000 ) {
				NifStream( skinPartitionBlocks[i2].hasFaces, out, info );
			};
			if ( info.version <= 0x0A000102 ) {
				if ( (skinPartitionBlocks[i2].numStrips != 0) ) {
					for (unsigned int i5 = 0; i5 < skinPartitionBlocks[i2].strips.size(); i5++) {
						for (unsigned int i6 = 0; i6 < skinPartitionBlocks[i2].stripLengths[i5]; i6++) {
							NifStream( skinPartitionBlocks[i2].strips[i5][i6], out, info );
						};
					};
				};
			};
			if ( info.version >= 0x0A010000 ) {
				if ( (skinPartitionBlocks[i2].hasFaces && (skinPartitionBlocks[i2].numStrips != 0)) ) {
					for (unsigned int i5 = 0; i5 < skinPartitionBlocks[i2].strips.size(); i5++) {
						for (unsigned int i6 = 0; i6 < skinPartitionBlocks[i2].stripLengths[i5]; i6++) {
							NifStream( (unsigned short&)skinPartitionBlocks[i2].strips[i5][i6], out, info );
						};
					};
				};
			};
			if ( info.version <= 0x0A000102 ) {
				if ( (skinPartitionBlocks[i2].numStrips == 0) ) {
					for (unsigned int i5 = 0; i5 < skinPartitionBlocks[i2].triangles.size(); i5++) {
						NifStream( skinPartitionBlocks[i2].triangles[i5], out, info );
					};
				};
			};
			if ( info.version >= 0x0A010000 ) {
				if ( (skinPartitionBlocks[i2].hasFaces && (skinPartitionBlocks[i2].numStrips == 0)) ) {
					for (unsigned int i5 = 0; i5 < skinPartitionBlocks[i2].triangles.size(); i5++) {
						NifStream( (Triangle&)skinPartitionBlocks[i2].triangles[i5], out, info );
					};
				};
			};
			NifStream( skinPartitionBlocks[i2].hasBoneIndices, out, info );
			if ( skinPartitionBlocks[i2].hasBoneIndices ) {
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i2].boneIndices.size(); i4++) {
					for (unsigned int i5 = 0; i5 < skinPartitionBlocks[i2].boneIndices[i4].size(); i5++) {
						NifStream( skinPartitionBlocks[i2].boneIndices[i4][i5], out, info );
					};
				};
			};
			if ( (info.userVersion2 > 34) ) {
				NifStream( skinPartitionBlocks[i2].unknownShort, out, info );
			};
			if ( info.userVersion2 == 100 ) {
				NifStream( skinPartitionBlocks[i2].vertexDesc.vf1, out, info );
				NifStream( skinPartitionBlocks[i2].vertexDesc.vf2, out, info );
				NifStream( skinPartitionBlocks[i2].vertexDesc.vf3, out, info );
				NifStream( skinPartitionBlocks[i2].vertexDesc.vf4, out, info );
				NifStream( skinPartitionBlocks[i2].vertexDesc.vf5, out, info );
				NifStream( skinPartitionBlocks[i2].vertexDesc.vertexAttributes, out, info );
				NifStream( skinPartitionBlocks[i2].vertexDesc.vf8, out, info );
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i2].trianglesCopy.size(); i4++) {
					NifStream( skinPartitionBlocks[i2].trianglesCopy[i4], out, info );
				};
			};
		};
	};
	if ( info.userVersion2 == 100 ) {
		NifStream( dataSize, out, info );
		NifStream( vertexSize, out, info );
		NifStream( vertexDesc.vf1, out, info );
		NifStream( vertexDesc.vf2, out, info );
		NifStream( vertexDesc.vf3, out, info );
		NifStream( vertexDesc.vf4, out, info );
		NifStream( vertexDesc.vf5, out, info );
		NifStream( vertexDesc.vertexAttributes, out, info );
		NifStream( vertexDesc.vf8, out, info );
		if ( (dataSize > 0) ) {
			for (unsigned int i3 = 0; i3 < vertexData.size(); i3++) {
				NifStream( vertexData[i3], out, info, vertexDesc.vertexAttributes );
			};
		};
		for (unsigned int i2 = 0; i2 < partition.size(); i2++) {
			for (unsigned int i3 = 0; i3 < partition[i2].strips.size(); i3++)
				partition[i2].stripLengths[i3] = (unsigned short)(partition[i2].strips[i3].size());
			partition[i2].numWeightsPerVertex = (unsigned short)((partition[i2].vertexWeights.size() > 0) ? partition[i2].vertexWeights[0].size() : 0);
			partition[i2].numStrips = (unsigned short)(partition[i2].stripLengths.size());
			partition[i2].numBones = (unsigned short)(partition[i2].bones.size());
			partition[i2].numTriangles = partition[i2].numTrianglesCalc(info);
			partition[i2].numVertices = (unsigned short)(partition[i2].vertexMap.size());
			NifStream( partition[i2].numVertices, out, info );
			NifStream( partition[i2].numTriangles, out, info );
			NifStream( partition[i2].numBones, out, info );
			NifStream( partition[i2].numStrips, out, info );
			NifStream( partition[i2].numWeightsPerVertex, out, info );
			for (unsigned int i3 = 0; i3 < partition[i2].bones.size(); i3++) {
				NifStream( partition[i2].bones[i3], out, info );
			};
			if ( info.version >= 0x0A010000 ) {
				NifStream( partition[i2].hasVertexMap, out, info );
			};
			if ( info.version <= 0x0A000102 ) {
				for (unsigned int i4 = 0; i4 < partition[i2].vertexMap.size(); i4++) {
					NifStream( partition[i2].vertexMap[i4], out, info );
				};
			};
			if ( info.version >= 0x0A010000 ) {
				if ( partition[i2].hasVertexMap ) {
					for (unsigned int i5 = 0; i5 < partition[i2].vertexMap.size(); i5++) {
						NifStream( (unsigned short&)partition[i2].vertexMap[i5], out, info );
					};
				};
				NifStream( partition[i2].hasVertexWeights, out, info );
			};
			if ( info.version <= 0x0A000102 ) {
				for (unsigned int i4 = 0; i4 < partition[i2].vertexWeights.size(); i4++) {
					for (unsigned int i5 = 0; i5 < partition[i2].vertexWeights[i4].size(); i5++) {
						NifStream( partition[i2].vertexWeights[i4][i5], out, info );
					};
				};
			};
			if ( info.version >= 0x0A010000 ) {
				if ( partition[i2].hasVertexWeights ) {
					for (unsigned int i5 = 0; i5 < partition[i2].vertexWeights.size(); i5++) {
						for (unsigned int i6 = 0; i6 < partition[i2].vertexWeights[i5].size(); i6++) {
							NifStream( (float&)partition[i2].vertexWeights[i5][i6], out, info );
						};
					};
				};
			};
			for (unsigned int i3 = 0; i3 < partition[i2].stripLengths.size(); i3++) {
				NifStream( partition[i2].stripLengths[i3], out, info );
			};
			if ( info.version >= 0x0A010000 ) {
				NifStream( partition[i2].hasFaces, out, info );
			};
			if ( info.version <= 0x0A000102 ) {
				if ( (partition[i2].numStrips != 0) ) {
					for (unsigned int i5 = 0; i5 < partition[i2].strips.size(); i5++) {
						for (unsigned int i6 = 0; i6 < partition[i2].stripLengths[i5]; i6++) {
							NifStream( partition[i2].strips[i5][i6], out, info );
						};
					};
				};
			};
			if ( info.version >= 0x0A010000 ) {
				if ( (partition[i2].hasFaces && (partition[i2].numStrips != 0)) ) {
					for (unsigned int i5 = 0; i5 < partition[i2].strips.size(); i5++) {
						for (unsigned int i6 = 0; i6 < partition[i2].stripLengths[i5]; i6++) {
							NifStream( (unsigned short&)partition[i2].strips[i5][i6], out, info );
						};
					};
				};
			};
			if ( info.version <= 0x0A000102 ) {
				if ( (partition[i2].numStrips == 0) ) {
					for (unsigned int i5 = 0; i5 < partition[i2].triangles.size(); i5++) {
						NifStream( partition[i2].triangles[i5], out, info );
					};
				};
			};
			if ( info.version >= 0x0A010000 ) {
				if ( (partition[i2].hasFaces && (partition[i2].numStrips == 0)) ) {
					for (unsigned int i5 = 0; i5 < partition[i2].triangles.size(); i5++) {
						NifStream( (Triangle&)partition[i2].triangles[i5], out, info );
					};
				};
			};
			NifStream( partition[i2].hasBoneIndices, out, info );
			if ( partition[i2].hasBoneIndices ) {
				for (unsigned int i4 = 0; i4 < partition[i2].boneIndices.size(); i4++) {
					for (unsigned int i5 = 0; i5 < partition[i2].boneIndices[i4].size(); i5++) {
						NifStream( partition[i2].boneIndices[i4][i5], out, info );
					};
				};
			};
			if ( (info.userVersion2 > 34) ) {
				NifStream( partition[i2].unknownShort, out, info );
			};
			if ( info.userVersion2 == 100 ) {
				NifStream( partition[i2].vertexDesc.vf1, out, info );
				NifStream( partition[i2].vertexDesc.vf2, out, info );
				NifStream( partition[i2].vertexDesc.vf3, out, info );
				NifStream( partition[i2].vertexDesc.vf4, out, info );
				NifStream( partition[i2].vertexDesc.vf5, out, info );
				NifStream( partition[i2].vertexDesc.vertexAttributes, out, info );
				NifStream( partition[i2].vertexDesc.vf8, out, info );
				for (unsigned int i4 = 0; i4 < partition[i2].trianglesCopy.size(); i4++) {
					NifStream( partition[i2].trianglesCopy[i4], out, info );
				};
			};
		};
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiSkinPartition::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numSkinPartitionBlocks = (unsigned int)(skinPartitionBlocks.size());
	out << "  Num Skin Partition Blocks:  " << numSkinPartitionBlocks << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < skinPartitionBlocks.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (unsigned int i2 = 0; i2 < skinPartitionBlocks[i1].strips.size(); i2++)
			skinPartitionBlocks[i1].stripLengths[i2] = (unsigned short)(skinPartitionBlocks[i1].strips[i2].size());
		skinPartitionBlocks[i1].numWeightsPerVertex = (unsigned short)((skinPartitionBlocks[i1].vertexWeights.size() > 0) ? skinPartitionBlocks[i1].vertexWeights[0].size() : 0);
		skinPartitionBlocks[i1].numStrips = (unsigned short)(skinPartitionBlocks[i1].stripLengths.size());
		skinPartitionBlocks[i1].numBones = (unsigned short)(skinPartitionBlocks[i1].bones.size());
		skinPartitionBlocks[i1].numVertices = (unsigned short)(skinPartitionBlocks[i1].vertexMap.size());
		out << "    Num Vertices:  " << skinPartitionBlocks[i1].numVertices << endl;
		out << "    Num Triangles:  " << skinPartitionBlocks[i1].numTriangles << endl;
		out << "    Num Bones:  " << skinPartitionBlocks[i1].numBones << endl;
		out << "    Num Strips:  " << skinPartitionBlocks[i1].numStrips << endl;
		out << "    Num Weights Per Vertex:  " << skinPartitionBlocks[i1].numWeightsPerVertex << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < skinPartitionBlocks[i1].bones.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Bones[" << i2 << "]:  " << skinPartitionBlocks[i1].bones[i2] << endl;
			array_output_count++;
		};
		out << "    Has Vertex Map:  " << skinPartitionBlocks[i1].hasVertexMap << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < skinPartitionBlocks[i1].vertexMap.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Vertex Map[" << i2 << "]:  " << skinPartitionBlocks[i1].vertexMap[i2] << endl;
			array_output_count++;
		};
		out << "    Has Vertex Weights:  " << skinPartitionBlocks[i1].hasVertexWeights << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < skinPartitionBlocks[i1].vertexWeights.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].vertexWeights[i2].size(); i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					break;
				};
				out << "        Vertex Weights[" << i3 << "]:  " << skinPartitionBlocks[i1].vertexWeights[i2][i3] << endl;
				array_output_count++;
			};
		};
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < skinPartitionBlocks[i1].stripLengths.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Strip Lengths[" << i2 << "]:  " << skinPartitionBlocks[i1].stripLengths[i2] << endl;
			array_output_count++;
		};
		out << "    Has Faces:  " << skinPartitionBlocks[i1].hasFaces << endl;
		if ( (skinPartitionBlocks[i1].numStrips != 0) ) {
			array_output_count = 0;
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].strips.size(); i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
					break;
				};
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i1].stripLengths[i3]; i4++) {
					if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
						break;
					};
					out << "          Strips[" << i4 << "]:  " << skinPartitionBlocks[i1].strips[i3][i4] << endl;
					array_output_count++;
				};
			};
		};
		if ( (skinPartitionBlocks[i1].numStrips == 0) ) {
			array_output_count = 0;
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].triangles.size(); i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
					break;
				};
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					break;
				};
				out << "        Triangles[" << i3 << "]:  " << skinPartitionBlocks[i1].triangles[i3] << endl;
				array_output_count++;
			};
		};
		out << "    Has Bone Indices:  " << skinPartitionBlocks[i1].hasBoneIndices << endl;
		if ( skinPartitionBlocks[i1].hasBoneIndices ) {
			array_output_count = 0;
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].boneIndices.size(); i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
					break;
				};
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i1].boneIndices[i3].size(); i4++) {
					if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
						break;
					};
					out << "          Bone Indices[" << i4 << "]:  " << skinPartitionBlocks[i1].boneIndices[i3][i4] << endl;
					array_output_count++;
				};
			};
		};
		out << "    Unknown Short:  " << skinPartitionBlocks[i1].unknownShort << endl;
		out << "    VF1:  " << skinPartitionBlocks[i1].vertexDesc.vf1 << endl;
		out << "    VF2:  " << skinPartitionBlocks[i1].vertexDesc.vf2 << endl;
		out << "    VF3:  " << skinPartitionBlocks[i1].vertexDesc.vf3 << endl;
		out << "    VF4:  " << skinPartitionBlocks[i1].vertexDesc.vf4 << endl;
		out << "    VF5:  " << skinPartitionBlocks[i1].vertexDesc.vf5 << endl;
		out << "    Vertex Attributes:  " << skinPartitionBlocks[i1].vertexDesc.vertexAttributes << endl;
		out << "    VF8:  " << skinPartitionBlocks[i1].vertexDesc.vf8 << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < skinPartitionBlocks[i1].trianglesCopy.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Triangles Copy[" << i2 << "]:  " << skinPartitionBlocks[i1].trianglesCopy[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Data Size:  " << dataSize << endl;
	out << "  Vertex Size:  " << vertexSize << endl;
	out << "  VF1:  " << vertexDesc.vf1 << endl;
	out << "  VF2:  " << vertexDesc.vf2 << endl;
	out << "  VF3:  " << vertexDesc.vf3 << endl;
	out << "  VF4:  " << vertexDesc.vf4 << endl;
	out << "  VF5:  " << vertexDesc.vf5 << endl;
	out << "  Vertex Attributes:  " << vertexDesc.vertexAttributes << endl;
	out << "  VF8:  " << vertexDesc.vf8 << endl;
	if ( (dataSize > 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < vertexData.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Vertex Data[" << i2 << "]:  " << vertexData[i2] << endl;
			array_output_count++;
		};
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < partition.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (unsigned int i2 = 0; i2 < partition[i1].strips.size(); i2++)
			partition[i1].stripLengths[i2] = (unsigned short)(partition[i1].strips[i2].size());
		partition[i1].numWeightsPerVertex = (unsigned short)((partition[i1].vertexWeights.size() > 0) ? partition[i1].vertexWeights[0].size() : 0);
		partition[i1].numStrips = (unsigned short)(partition[i1].stripLengths.size());
		partition[i1].numBones = (unsigned short)(partition[i1].bones.size());
		partition[i1].numVertices = (unsigned short)(partition[i1].vertexMap.size());
		out << "    Num Vertices:  " << partition[i1].numVertices << endl;
		out << "    Num Triangles:  " << partition[i1].numTriangles << endl;
		out << "    Num Bones:  " << partition[i1].numBones << endl;
		out << "    Num Strips:  " << partition[i1].numStrips << endl;
		out << "    Num Weights Per Vertex:  " << partition[i1].numWeightsPerVertex << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < partition[i1].bones.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Bones[" << i2 << "]:  " << partition[i1].bones[i2] << endl;
			array_output_count++;
		};
		out << "    Has Vertex Map:  " << partition[i1].hasVertexMap << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < partition[i1].vertexMap.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Vertex Map[" << i2 << "]:  " << partition[i1].vertexMap[i2] << endl;
			array_output_count++;
		};
		out << "    Has Vertex Weights:  " << partition[i1].hasVertexWeights << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < partition[i1].vertexWeights.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			for (unsigned int i3 = 0; i3 < partition[i1].vertexWeights[i2].size(); i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					break;
				};
				out << "        Vertex Weights[" << i3 << "]:  " << partition[i1].vertexWeights[i2][i3] << endl;
				array_output_count++;
			};
		};
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < partition[i1].stripLengths.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Strip Lengths[" << i2 << "]:  " << partition[i1].stripLengths[i2] << endl;
			array_output_count++;
		};
		out << "    Has Faces:  " << partition[i1].hasFaces << endl;
		if ( (partition[i1].numStrips != 0) ) {
			array_output_count = 0;
			for (unsigned int i3 = 0; i3 < partition[i1].strips.size(); i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
					break;
				};
				for (unsigned int i4 = 0; i4 < partition[i1].stripLengths[i3]; i4++) {
					if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
						break;
					};
					out << "          Strips[" << i4 << "]:  " << partition[i1].strips[i3][i4] << endl;
					array_output_count++;
				};
			};
		};
		if ( (partition[i1].numStrips == 0) ) {
			array_output_count = 0;
			for (unsigned int i3 = 0; i3 < partition[i1].triangles.size(); i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
					break;
				};
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					break;
				};
				out << "        Triangles[" << i3 << "]:  " << partition[i1].triangles[i3] << endl;
				array_output_count++;
			};
		};
		out << "    Has Bone Indices:  " << partition[i1].hasBoneIndices << endl;
		if ( partition[i1].hasBoneIndices ) {
			array_output_count = 0;
			for (unsigned int i3 = 0; i3 < partition[i1].boneIndices.size(); i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
					break;
				};
				for (unsigned int i4 = 0; i4 < partition[i1].boneIndices[i3].size(); i4++) {
					if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
						break;
					};
					out << "          Bone Indices[" << i4 << "]:  " << partition[i1].boneIndices[i3][i4] << endl;
					array_output_count++;
				};
			};
		};
		out << "    Unknown Short:  " << partition[i1].unknownShort << endl;
		out << "    VF1:  " << partition[i1].vertexDesc.vf1 << endl;
		out << "    VF2:  " << partition[i1].vertexDesc.vf2 << endl;
		out << "    VF3:  " << partition[i1].vertexDesc.vf3 << endl;
		out << "    VF4:  " << partition[i1].vertexDesc.vf4 << endl;
		out << "    VF5:  " << partition[i1].vertexDesc.vf5 << endl;
		out << "    Vertex Attributes:  " << partition[i1].vertexDesc.vertexAttributes << endl;
		out << "    VF8:  " << partition[i1].vertexDesc.vf8 << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < partition[i1].trianglesCopy.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Triangles Copy[" << i2 << "]:  " << partition[i1].trianglesCopy[i2] << endl;
			array_output_count++;
		};
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiSkinPartition::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiSkinPartition::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

std::list<NiObject *> NiSkinPartition::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiObject::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

int NiSkinPartition::GetNumPartitions() const {
   return (int)skinPartitionBlocks.size();
}

void NiSkinPartition::SetNumPartitions( int value ) {
   SkinPartition part;
   part.numVertices = 0;
   part.numTriangles = 0;
   part.numBones = 0;
   part.numStrips = 0;
   part.numWeightsPerVertex = 0;
   part.hasVertexMap = false;
   part.hasVertexWeights = false;
   part.hasFaces = false;
   part.hasBoneIndices = false;
   skinPartitionBlocks.assign(value, part);
   numSkinPartitionBlocks = value;
}

unsigned short NiSkinPartition::GetWeightsPerVertex( int partition ) const {
   return skinPartitionBlocks.at(partition).numWeightsPerVertex;
}

void NiSkinPartition::SetWeightsPerVertex( int partition, unsigned short value ) {
   skinPartitionBlocks.at(partition).numWeightsPerVertex = value;
}

unsigned short NiSkinPartition::GetNumVertices( int partition ) const {
   return skinPartitionBlocks.at(partition).numVertices;
}

void NiSkinPartition::SetNumVertices( int partition, unsigned short value ) {
   skinPartitionBlocks.at(partition).numVertices = value;
}

vector<unsigned short> NiSkinPartition::GetBoneMap( int partition ) const {
   return skinPartitionBlocks.at(partition).bones;
}

void NiSkinPartition::SetBoneMap( int partition, const vector<unsigned short>& boneMap ) {
   skinPartitionBlocks.at(partition).bones = boneMap;
   skinPartitionBlocks.at(partition).numBones = (unsigned short)boneMap.size();
}

vector<unsigned short> NiSkinPartition::GetVertexMap( int partition ) const {
   return skinPartitionBlocks.at(partition).vertexMap;
}

void NiSkinPartition::SetVertexMap( int partition, const vector<unsigned short>& vertexMap ) {
   SkinPartition& part = skinPartitionBlocks.at(partition);
   if (vertexMap.empty()) {
      part.vertexMap.clear();
      part.numVertices = 0;
      part.hasVertexMap = false;
   } else {
      part.vertexMap = vertexMap;
      part.numVertices = (unsigned short)(vertexMap.size());
      part.hasVertexMap = true;
   }
}

bool NiSkinPartition::HasVertexWeights( int partition ) const {
   return skinPartitionBlocks.at(partition).hasVertexWeights;
}

void NiSkinPartition::EnableVertexWeights( int partition, bool enable) {
   SkinPartition& part = skinPartitionBlocks.at(partition);
   if (enable) {
      // Allocate appropriately sized vectors. Clearing existing data.
      vector<float> weights(part.numWeightsPerVertex);
      part.vertexWeights.assign(part.numVertices, weights);
   } else {
      part.vertexWeights.clear();
   }
   part.hasVertexWeights = enable;
}

vector<float> NiSkinPartition::GetVertexWeights( int partition, int vertex ) const {
   return skinPartitionBlocks.at(partition).vertexWeights[vertex];
}

void NiSkinPartition::SetVertexWeights( int partition, int vertex, const vector<float> & n ) {
   skinPartitionBlocks.at(partition).vertexWeights[vertex] = n;
}

bool NiSkinPartition::HasVertexBoneIndices( int partition ) const {
   return ( skinPartitionBlocks.at(partition).hasBoneIndices != 0 );
}

void NiSkinPartition::EnableVertexBoneIndices( int partition, bool enable) {
   SkinPartition& part = skinPartitionBlocks.at(partition);
   if (enable) {
      // Allocate appropriately sized vectors. Clearing existing data.
      vector<byte> bones(part.numWeightsPerVertex);
      part.boneIndices.assign(part.numVertices, bones);
   } else {
      part.boneIndices.clear();
   }
   part.hasBoneIndices = enable;
}

vector<unsigned short> NiSkinPartition::GetVertexBoneIndices( int partition, int vertex ) const {
   const vector<byte>& bones = skinPartitionBlocks.at(partition).boneIndices[vertex];
   vector<unsigned short> value;
   size_t n = bones.size();
   value.resize(bones.size());
   for (size_t i=0; i<n; ++i)
      value[i] = (unsigned short)(bones[i]);
   return value;
}

void NiSkinPartition::SetVertexBoneIndices( int partition, int vertex, const vector<unsigned short>& boneList ) {
   vector<byte>& bones = skinPartitionBlocks.at(partition).boneIndices[vertex];
   size_t n = boneList.size();
   bones.resize(n);
   for (size_t i=0; i<n; ++i)
      bones[i] = byte(boneList[i]);
}

unsigned short NiSkinPartition::GetStripCount( int partition ) const {
   return (unsigned short)skinPartitionBlocks.at(partition).strips.size();
}

void NiSkinPartition::SetStripCount( int partition, int n ) {
   SkinPartition& part = skinPartitionBlocks.at(partition);
   part.strips.resize(n);
   part.stripLengths.resize(n);
   part.hasFaces = (n!=0);
   part.numStrips = n;
}

vector<unsigned short> NiSkinPartition::GetStrip( int partition, int index ) const {
   return skinPartitionBlocks.at(partition).strips[index];
}

void NiSkinPartition::SetStrip( int partition, int index, const vector<unsigned short> & in ) {
   SkinPartition& part = skinPartitionBlocks.at(partition);
   part.strips[index] = in;
   part.stripLengths[index] = (unsigned short)(in.size());
   part.numTriangles = part.numTrianglesCalc();
   part.triangles.clear();
}

vector<Triangle> NiSkinPartition::GetTriangles( int partition ) const {
   const SkinPartition&part = skinPartitionBlocks.at(partition);
   if ( part.numStrips == 0 && !part.triangles.empty())
      return part.triangles;

   // Use Strips

   //Create a vector to hold the triangles
   vector<Triangle> triangles;
   int n = 0; // Current triangle

   //Cycle through all strips
   vector< vector<unsigned short> >::const_iterator it;
   Triangle t;
   for (it = part.strips.begin(); it != part.strips.end(); ++it ) {
      //The first three values in the strip are the first triangle
      t.Set( (*it)[0], (*it)[1], (*it)[2] );

      //Only add triangles to the list if none of the vertices match
      if ( t[0] != t[1] && t[0] != t[2] && t[1] != t[2] ) {
         triangles.push_back(t);
      }

      //Move to the next triangle
      ++n;

      //The remaining triangles use the previous two indices as their first two indices.
      for( unsigned int i = 3; i < it->size(); ++i ) {
         //Odd numbered triangles need to be reversed to keep the vertices in counter-clockwise order
         if ( i % 2 == 0 ) {
            t.Set( (*it)[i - 2], (*it)[i - 1], (*it)[i] );
         } else {
            t.Set( (*it)[i], (*it)[i - 1], (*it)[i - 2] );
         }

         //Only add triangles to the list if none of the vertices match
         if ( t[0] != t[1] && t[0] != t[2] && t[1] != t[2] ) {
            triangles.push_back(t);
         }

         //Move to the next triangle
         ++n;
      }
   }

   return triangles;
}

void NiSkinPartition::SetTriangles( int partition, const vector<Triangle> & in ) {
   if ( in.size() > 65535 || in.size() < 0 ) {
      throw runtime_error("Invalid Triangle Count: must be between 0 and 65535.");
   }
   SkinPartition& part = skinPartitionBlocks.at(partition); // at throws, [] does not
   part.triangles = in;
   part.hasFaces = (in.size() > 0) ? true : (part.strips.size() != 0);
   part.numTriangles = (unsigned short)(in.size());
}

NiSkinPartition::NiSkinPartition(Ref<NiTriBasedGeom> shape) {
   NiSkinInstanceRef skinInst = shape->GetSkinInstance();
   if ( skinInst == NULL ) {
      throw runtime_error( "You must bind a skin before setting generating skin partitions.  No NiSkinInstance found." );
   }
   NiSkinDataRef skinData = skinInst->GetSkinData();
   if ( skinData == NULL ) {
      throw runtime_error( "You must bind a skin before setting generating skin partitions.  No NiSkinData found." );
   }
   NiTriBasedGeomDataRef geomData = DynamicCast<NiTriBasedGeomData>( shape->GetData() );
   if ( geomData == NULL ) {
      throw runtime_error( "Attempted to generate a skin partition on a mesh with no geometry data." );
   }

   int nWeightsPerVertex = 4;
   vector<WeightList> vertexWeights;
   BoneList boneMap;
   vector<unsigned short> vertexMap;
   Strips strips;
   vector<BoneList> boneIndexList;
   Triangles triangles;

   int totalBones = skinInst->GetBoneCount();
   boneMap.resize(totalBones);

   int nv = geomData->GetVertexCount();
   vertexMap.resize(nv);
   vertexWeights.resize(nv);
   boneIndexList.resize(nv);

   for (int i=0; i<totalBones; ++i) {
      boneMap[i] = i;

      vector<SkinWeight> skinWeights = skinData->GetBoneWeights(i);
      for (vector<SkinWeight>::const_iterator skinWeight = skinWeights.begin(); skinWeight != skinWeights.end(); ++skinWeight) {
         WeightList& vertexWeight = vertexWeights[skinWeight->index];
         BoneList& boneIndex = boneIndexList[skinWeight->index];

         vertexWeight.push_back(skinWeight->weight);
         boneIndex.push_back(i);

         // Adjust upper limit on number of weights per vertex if necessary.
         int nWeights = int(vertexWeight.size());
         if (nWeights > nWeightsPerVertex)
            nWeightsPerVertex = nWeights;
      }
   }
   if (nWeightsPerVertex == 0) {
      throw runtime_error( "Attempted to generate a skin partition on a mesh with no weights specified." );
   }
   for (int i=0; i<nv; ++i) {
      vertexMap[i] = i;

      WeightList& vertexWeight = vertexWeights[i];
      BoneList& boneIndex = boneIndexList[i];
      vertexWeight.reserve(nWeightsPerVertex);
      boneIndex.reserve(nWeightsPerVertex);
      for (size_t j = nWeightsPerVertex - vertexWeight.size(); j>0; --j) {
         vertexWeight.push_back(0.0f);
         boneIndex.push_back(0);
      }
   }

   SetNumPartitions(1);
   SetWeightsPerVertex(0, nWeightsPerVertex);
   SetBoneMap(0, boneMap);
   SetNumVertices(0, (unsigned short)(vertexMap.size()) );
   SetVertexMap(0, vertexMap);
   EnableVertexWeights(0, true);
   EnableVertexBoneIndices(0, true);
   for (int i=0; i<nv; ++i) {
      SetVertexWeights(0, i, vertexWeights[i]);
      SetVertexBoneIndices(0, i, boneIndexList[i]);
   }

   // Special case for pre-stripped data
   if (NiTriStripsDataRef stripData = DynamicCast<NiTriStripsData>(geomData)) {
      unsigned short nstrips = stripData->GetStripCount();
      SetStripCount(0, nstrips);
      for (int i=0; i<int(nstrips); ++i) {
         SetStrip(0, i, stripData->GetStrip(i));
      }
   } else {

      Triangles triangles = geomData->GetTriangles();
      SetTriangles(0, triangles);

      unsigned short *data = new unsigned short[triangles.size() * 3 * 2];
      for (size_t i=0; i< triangles.size(); i++) {
         data[i * 3 + 0] = triangles[i][0];
         data[i * 3 + 1] = triangles[i][1];
         data[i * 3 + 2] = triangles[i][2];
      }
      PrimitiveGroup * groups = 0;
      unsigned short numGroups = 0;

      // GF 3+
      SetCacheSize(CACHESIZE_GEFORCE3);
      // don't generate hundreds of strips
      SetStitchStrips(true);
      GenerateStrips(data, int(triangles.size()*3), &groups, &numGroups);

      delete [] data;

      if (groups) {
         SetStripCount(0, numGroups);
         for (int g=0; g<numGroups; g++) {
            if (groups[g].type == PT_STRIP) {
               vector<unsigned short> strip(groups[g].numIndices);
               for ( unsigned int s = 0; s<groups[g].numIndices; s++ )
                  strip[s] = groups[g].indices[s];
               SetStrip(0, g, strip);
            }
         }
         delete [] groups;
      }
   }
  
}


////////////////////////////////////////////////

static void mergeBones( BoneList &a, BoneList& b ) {
   for (size_t i=0; i<b.size(); ++i) {
      int c = b[i];
      BoneList::iterator it = find(a.begin(), a.end(), c);
      if ( a.end() == it ) {
         a.push_back( c );
      }
   }
}

static bool containsBones( BoneList& a, BoneList& b ) {
   for (size_t i=0; i<b.size(); ++i) {
      int c = b[i];
      BoneList::iterator it = find(a.begin(), a.end(), c);
      if ( a.end() == it ) {
         return false;
      }
   }
   return true;
}
template <typename I, typename V>
size_t indexOf(I begin, I end, const V& val) {
   return std::distance(begin, std::find(begin, end, val));
}


namespace std
{
   template<>
   struct less<Triangle> : public binary_function<Triangle, Triangle, bool>
   {
      bool operator()(const Triangle& s1, const Triangle& s2) const{
         int d = 0;
         if (d == 0) d = (s1[0] - s2[0]);
         if (d == 0) d = (s1[1] - s2[1]);
         if (d == 0) d = (s1[2] - s2[2]);
         return d < 0; 
      }
   };
   template<>
   struct less<BoneWeight> : public binary_function<BoneWeight, BoneWeight, bool>
   {
      bool operator()(const BoneWeight& lhs, const BoneWeight& rhs) {
         if ( lhs.second == rhs.second ) {
            return lhs.first < rhs.first;
         } else if (lhs.second == 0.0) {
            return false;
         } else {
            return rhs.second < lhs.second;
         }
      }
   };
}

inline void rotate(Triangle &t)
{
   if (t[1] < t[0] && t[1] < t[2]) {
      t.Set( t[1], t[2], t[0] );
   } else if (t[2] < t[0]) {
      t.Set( t[2], t[0], t[1] );
   }
}

NiSkinPartition::NiSkinPartition(Ref<NiTriBasedGeom> shape, int maxBonesPerPartition, int maxBonesPerVertex, bool bStrippify, int* faceMap ) {
   NiSkinInstanceRef skinInst = shape->GetSkinInstance();
   if ( skinInst == NULL ) {
      throw runtime_error( "You must bind a skin before setting generating skin partitions.  No NiSkinInstance found." );
   }
   NiSkinDataRef skinData = skinInst->GetSkinData();
   if ( skinData == NULL ) {
      throw runtime_error( "You must bind a skin before setting generating skin partitions.  No NiSkinData found." );
   }
   NiTriBasedGeomDataRef geomData = DynamicCast<NiTriBasedGeomData>(shape->GetData() );
   if ( geomData == NULL ) {
      throw runtime_error( "Attempted to generate a skin partition on a mesh with no geometry data." );
   }

      // read in the weights from NiSkinData
   vector<Vector3> verts = geomData->GetVertices();
   vector< BoneWeightList > weights;
   if (verts.empty()){
      throw runtime_error( "Attempted to generate a skin partition on a mesh with no vertices." );
   }

   Triangles triangles = geomData->GetTriangles();
   if (triangles.empty()) {
      throw runtime_error( "Attempted to generate a skin partition on a mesh with no triangles." );
   }

   int numVerts = int(verts.size());
   weights.resize( numVerts );
   int numBones = skinData->GetBoneCount();
   for ( int bone = 0; bone < numBones; bone++ )
   {
      vector<SkinWeight> vertexWeights = skinData->GetBoneWeights(bone);
      for (int r = 0; r < int(vertexWeights.size()); ++r ){
         int vertex = vertexWeights[r].index;
         float weight = vertexWeights[r].weight;
         if ( vertex >= int(weights.size()) )
            throw runtime_error( "bad NiSkinData - vertex count does not match" );
         weights[vertex].insert( weights[vertex].end(), BoneWeight(bone, weight) );
      }
   }

   // count min and max bones per vertex
   int minBones, maxBones;
   minBones = maxBones = int(weights[0].size());
   for(vector< BoneWeightList >::iterator itr = weights.begin(); itr != weights.end(); ++itr ){
      int n = int((*itr).size());
      minBones = min(n, minBones);
      maxBones = max(n, maxBones);
   }

   if ( minBones <= 0 )
      throw runtime_error( "bad NiSkinData - some vertices have no weights at all" );

   // reduce vertex influences if necessary
   if ( maxBones > maxBonesPerVertex )
   {
      int c = 0;
      for ( vector< BoneWeightList >::iterator it = weights.begin(); it != weights.end(); ++it )
      {
         BoneWeightList & lst = *it;
         int n = int(lst.size());
         if ( n > maxBonesPerVertex )
         {
            c++;

            BoneWeightList::iterator itr = lst.begin();
            std::advance(itr, n);
            while ( itr != lst.end() )
               itr = lst.erase( itr );
         }

         float totalWeight = 0;
         for (BoneWeightList::iterator bw = lst.begin(); bw != lst.end(); ++bw) {
            totalWeight += (*bw).second;
         }
         for (BoneWeightList::iterator bw = lst.begin(); bw != lst.end(); ++bw) {
            (*bw).second /= totalWeight;
         }
      }
      //qWarning() << "reduced" << c << "vertices to" << maxBonesPerVertex << "bone influences (maximum number of bones per vertex was" << maxBones << ")";
   }

   maxBones = maxBonesPerVertex;

   // reduces bone weights so that the triangles fit into the partitions

   typedef multimap<int,int> matchmap;
   typedef pair<matchmap::iterator, matchmap::iterator> matchrange;
   matchmap match;
   bool doMatch = true;

   BoneList tribones;
   int cnt = 0;
   for (Triangles::iterator itr = triangles.begin(); itr != triangles.end(); ++itr) {
      Triangle& tri = (*itr);
      do
      {
         tribones.clear();
         for ( int c = 0; c < 3; c++ ) {
            BoneWeightList& bwl = weights[tri[c]];
            for (BoneWeightList::iterator bw = bwl.begin(); bw != bwl.end(); ++bw) {
               if ( tribones.end() == find(tribones.begin(), tribones.end(), (*bw).first ) )
                  tribones.insert(tribones.end(), (*bw).first );
            }
         }

         if ( int(tribones.size()) > maxBonesPerPartition )
         {
            // sum up the weights for each bone
            // bones with weight == 1 can't be removed

            map<int, float> sum;
            vector<int> nono;

            for ( int t = 0; t < 3; t++ ) {
               BoneWeightList& bwl = weights[tri[t]];
               if ( bwl.size() == 1 )
                  nono.insert(nono.end(), bwl.front().first );

               for (BoneWeightList::iterator bw = bwl.begin(); bw != bwl.end(); ++bw) {
                  sum[ (*bw).first ] += (*bw).second;
               }                 
            }

            // select the bone to remove

            float minWeight = 5.0;
            int minBone = -1;

            for (map<int, float>::iterator sitr = sum.begin(); sitr != sum.end(); ++sitr) {
               int b = (*sitr).first;
               if ( (find(nono.begin(), nono.end(), b) == nono.end()) && sum[b] < minWeight) {
                  minWeight = sum[b];
                  minBone = b;
               }
            }

            if ( minBone < 0 )	// this shouldn't never happen
               throw runtime_error( "internal error 0x01" );

            // do a vertex match detect
            if ( doMatch ) {
               for ( int a = 0; a < int(verts.size()); a++ ) {
                  match.insert(matchmap::value_type(a, a));
                  for ( int b = a + 1; b < int(verts.size()); b++ ) {
                     if ( verts[a] == verts[b] && weights[a] == weights[b] ) {
                        match.insert(matchmap::value_type(a, b));
                        match.insert(matchmap::value_type(b, a));
                     }
                  }
               }
            }

            // now remove that bone from all vertices of this triangle and from all matching vertices too
            for ( int t = 0; t < 3; t++ ) {
               bool rem = false;

               matchrange range = match.equal_range(tri[t]);
               for (matchmap::iterator itr = range.first; itr != range.second; ++itr) {
                  int v = (*itr).second;

                  BoneWeightList & bws = weights[ v ];
                  BoneWeightList::iterator it = bws.begin();
                  while ( it != bws.end() ) {
                     BoneWeight & bw = *it;
                     if ( bw.first == minBone ) {
                        it = bws.erase(it);
                        rem = true;
                     } else {
                        ++it;
                     }
                  }

                  float totalWeight = 0;

                  for (BoneWeightList::iterator bw = bws.begin(); bw != bws.end(); ++bw) {
                     totalWeight += (*bw).second;
                  }

                  if ( totalWeight == 0 )
                     throw runtime_error( "internal error 0x02" );

                  // normalize
                  for (BoneWeightList::iterator bw = bws.begin(); bw != bws.end(); ++bw) {
                     (*bw).second /= totalWeight;
                  }
               }
               if ( rem )
                  cnt++;
            }
         }
      } while ( int(tribones.size()) > maxBonesPerPartition );
   }
   //if ( cnt > 0 )
   //   qWarning() << "removed" << cnt << "bone influences";

   PartitionList& parts = skinPartitionBlocks;

   bool merge = true;
   // Use Explicit face mapping
   if (faceMap) {
      Triangles::iterator it = triangles.begin();
      for (int idx = 0, n = triangles.size(); idx<n; ++idx ){
         int partIdx = faceMap[idx];
         if (partIdx < 0)
            partIdx = 0;

         Triangle & tri = *it;

         // Ensure enough partitions
         while ( partIdx >= int(parts.size()) )
            parts.push_back( SkinPartition() );

         SkinPartition& part = parts[partIdx];
         BoneList tribones;
         for ( int c = 0; c < 3; c++ ) {
            BoneWeightList& bws = weights[tri[c]];
            for (BoneWeightList::iterator bw = bws.begin(); bw != bws.end(); ++bw) {
               if ( tribones.end() == find(tribones.begin(), tribones.end(), (*bw).first ) )
                  tribones.push_back( (*bw).first );
            }
         }
         mergeBones( part.bones, tribones );
         part.triangles.push_back( tri );
         it = triangles.erase(it); // delete triangle so it is not use later
      }
      merge = false; // when explicit mapping enabled, no merging is allowed
   }

   // split the triangles into partitions
   while ( ! triangles.empty() ) {

      SkinPartition part;
      Triangles::iterator it = triangles.begin();
      while ( it != triangles.end() ) {
         Triangle & tri = *it;

         BoneList tribones;
         for ( int c = 0; c < 3; c++ ) {
            BoneWeightList& bws = weights[tri[c]];
            for (BoneWeightList::iterator bw = bws.begin(); bw != bws.end(); ++bw) {
               if ( tribones.end() == find(tribones.begin(), tribones.end(), (*bw).first ) )
                  tribones.push_back( (*bw).first );
            }
         }

         if ( part.bones.empty() || containsBones( part.bones, tribones ) ) {
            mergeBones( part.bones, tribones );
            part.triangles.push_back( tri );
            it = triangles.erase(it);
         } else {
            ++it;
         }
      }

      parts.push_back( part );
   }

   //qWarning() << parts.size() << "small partitions";

   // merge partitions

   while (merge)
   {
      merge = false;
      // Working backwards through this list minimizes numbers of swaps
      //for ( int p2 = int(parts.size()-1); p2 >= 0  && ! merge; --p2 )
      //{
      //   Partition& part2 = parts[p2];
      //   for ( int p1 = int(p2-1); p1 >= 0 && ! merge; --p1 )
      //   {
      //      Partition& part1 = parts[p1];
      for ( int p1 = 0; p1 < int(parts.size()) && ! merge; p1++ )
      {
         Partition& part1 = parts[p1];
         for ( int p2 = p1+1; p2 < int(parts.size()) && ! merge; p2++ )
         {
            Partition& part2 = parts[p2];
            BoneList mergedBones = part1.bones;
            mergeBones( mergedBones, part2.bones );
            if ( int(mergedBones.size()) <= maxBonesPerPartition )
            {
               PartitionList::iterator p2i = parts.begin() + p2;
               part1.bones = mergedBones;
               part1.triangles.insert(part1.triangles.end(), (*p2i).triangles.begin(), (*p2i).triangles.end());
               parts.erase(p2i);
               merge = true;
            }
         }
      }
   }

   //qWarning() << parts.size() << "partitions";

   // start writing NiSkinPartition

   for ( int p = 0; p < int(parts.size()); p++ )
   {
      Partition& part = parts[p];
      BoneList& bones = part.bones;
      sort( bones.begin(), bones.end() );

      Triangles& triangles = part.triangles;

      vector<unsigned short>& vertices = part.vertexMap;

      // Create the vertex map

      int idx = 0;
      vector<int> vidx(numVerts, -1);
      for( Triangles::iterator tri = triangles.begin(); tri !=  triangles.end(); ++tri) {
         for ( int t = 0; t < 3; t++ ) {
            int v = (*tri)[t];
            if ( vidx[v] < 0)
               vidx[v] = idx++;
         }
      }
      vertices.assign(idx, -1);
      for (int i = 0; i < numVerts; ++i) {
         int v = vidx[i];
         if (v >= 0) {
            vertices[v] = i;
         }
      }

      for( Triangles::iterator tri = triangles.begin(); tri !=  triangles.end(); ++tri) {
         for ( int t = 0; t < 3; t++ ) {
            if ( vertices.end() == find(vertices.begin(), vertices.end(), (*tri)[t] ) )
               vertices.push_back( (*tri)[t] );
         }
      }

      part.numVertices = int(vertices.size());
      part.hasVertexMap = true;

      // map the vertices

      for ( int tri = 0; tri < int(triangles.size()); tri++ ) {
         for ( int t = 0; t < 3; t++ ) {
            triangles[tri][t] = (int)indexOf(vertices.begin(), vertices.end(), triangles[tri][t]);
         }
      }

      SetWeightsPerVertex(p, maxBones);
      EnableVertexWeights(p, true);
      EnableVertexBoneIndices(p, true);

      // strippify the triangles
      if (bStrippify)
      {
         NiTriStripsDataRef data = new NiTriStripsData(triangles, true);
         int nstrips = data->GetStripCount();
         SetStripCount( p, nstrips );
         for ( int i=0; i<nstrips; ++i ) {
            SetStrip(p, i, data->GetStrip(i));
         }
      }
      else
      {
         SetTriangles(p, triangles);
      }

      //// Special case for pre-stripped data
      //unsigned short *data = new unsigned short[triangles.size() * 3 * 2];
      //for (size_t i=0; i< triangles.size(); i++) {
      //   data[i * 3 + 0] = triangles[i][0];
      //   data[i * 3 + 1] = triangles[i][1];
      //   data[i * 3 + 2] = triangles[i][2];
      //}
      //PrimitiveGroup * groups = 0;
      //unsigned short numGroups = 0;

      //// GF 3+
      //SetCacheSize(CACHESIZE_GEFORCE3);
      //// don't generate hundreds of strips
      //SetStitchStrips(true);
      //GenerateStrips(data, triangles.size()*3, &groups, &numGroups);
      //delete [] data;
      //if (groups) {
      //   SetStripCount(p, numGroups);
      //   for (int g=0; g<numGroups; g++) {
      //      if (groups[g].type == PT_STRIP) {
      //         vector<Niflib::unsigned short> strip(groups[g].numIndices);
      //         for (size_t s=0; s<groups[g].numIndices; s++)
      //            strip[s] = groups[g].indices[s];
      //         SetStrip(p, g, strip);
      //      }
      //   }
      //   delete [] groups;
      //}

      // fill in vertex weights and bones
      for (size_t v = 0; v < vertices.size(); ++v) {
         BoneWeightList& bwl = weights[vertices[v]];
         sort(bwl.begin(), bwl.end(), std::less<BoneWeight>());
         for ( int b = 0; b < maxBones; b++ ) {
            part.boneIndices[v][b] = (int(bwl.size()) > b) ? (int)indexOf(bones.begin(), bones.end(), bwl[b].first) : 0 ;
            part.vertexWeights[v][b] = (int(bwl.size()) > b ? bwl[b].second : 0.0f);
         }
      }
   }
}

//--END CUSTOM CODE--//

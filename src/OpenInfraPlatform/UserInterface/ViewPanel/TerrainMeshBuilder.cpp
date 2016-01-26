/*! \verbatim
 *  \copyright		Copyright (c) 2015 Julian Amann. All rights reserved.
 *	\author			Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *	\brief			This file is part of the BlueFramework.
 *	\endverbatim
 */

#include "TerrainMeshBuilder.h"

#include "../../Benchmark.h"

namespace OpenInfraPlatform
{
	class VertexAndIndexBufferCreator
	{
	public:
		int createVertexAndGetIndex(
			const buw::vector3f& position,
			const buw::vector3f& normal,
			const buw::vector2f& uv)
		{
			// todo: do not add duplicates
			vertexbuffer.push_back(
				buw::VertexPosition3Normal3Texture2::create(
				position, normal, uv)
				);
		//	static int indexCount = 0;

			return static_cast<int>(vertexbuffer.size() - 1);
		}

		std::vector<buw::VertexPosition3Normal3Texture2> vertexbuffer;
	};

	buw::ReferenceCounted<BlueFramework::Engine::SimpleMesh>
		ConvertToSimpleMesh( 
		const buw::Surface* s ) 
	{
		VertexAndIndexBufferCreator vbc;

		buw::ReferenceCounted<BlueFramework::Engine::SimpleMesh> sm = 
			std::make_shared<BlueFramework::Engine::SimpleMesh>();

		std::vector< std::uint32_t > indices;

		// foreach face
		for (int faceIndex = 0; faceIndex < s->getTriangleCount(); faceIndex++)
		{
			int pointId[3];

			buw::vector3f positions[3];

			for(int i = 0; i < 3; i++)
			{
				pointId[i] = s->getTriangeFaces()[faceIndex][i];
				positions[i][0] = static_cast<float>(s->getPoints()[pointId[i]][0]);
				positions[i][1] = static_cast<float>(s->getPoints()[pointId[i]][1]);
				positions[i][2] = static_cast<float>(s->getPoints()[pointId[i]][2]);
			}

			// compute normal for flat shading
			buw::vector3f normal = (positions[0] - positions[1]) ^ (positions[0] - positions[2]);

			for(int i = 0; i < 3; i++)
			{
				indices.push_back(
					vbc.createVertexAndGetIndex( positions[i], normal, buw::vector2f(0,0) )
				);
			}
		}

		sm->vertices = vbc.vertexbuffer;
		sm->indices = indices;

		return sm;
	}
}


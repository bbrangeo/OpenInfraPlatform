#include "GeometryInputData.h"

#include <limits>

using namespace OpenInfraPlatform::IfcGeometryConverter;

/**********************************************************************************************/

void ItemData::createMeshSetsFromClosedPolyhedrons()
{
	for( unsigned int i=0; i<closed_polyhedrons.size(); ++i )
	{
		std::shared_ptr<carve::input::PolyhedronData>& poly_data = closed_polyhedrons[i];
		if( poly_data->getVertexCount() < 3 )
		{
			continue;
		}

		std::shared_ptr<carve::mesh::MeshSet<3>> meshset(
												poly_data->createMesh(carve::input::opts()) );
		
		meshsets.push_back( meshset );

	}

	closed_polyhedrons.clear();
}
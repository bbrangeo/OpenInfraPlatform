#include "ConverterBuw.h"

#include "EMTIfc2x3EntityTypes.h"
#include "EMTIfcBridgeEntityTypes.h"

//VertexMapTriangles OpenInfraPlatform::IfcGeometryConverter::ConverterBuwUtil::vertexMapTriangles_;
//VertexMapLines OpenInfraPlatform::IfcGeometryConverter::ConverterBuwUtil::vertexMapLines_;

std::mutex OpenInfraPlatform::IfcGeometryConverter::ConverterBuwUtil::s_geometryMutex;

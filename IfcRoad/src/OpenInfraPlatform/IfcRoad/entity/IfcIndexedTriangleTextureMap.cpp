/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/IfcRoadEntityEnums.h"
#include "include/IfcIndexedTriangleTextureMap.h"
#include "include/IfcSurfaceTexture.h"
#include "include/IfcTessellatedFaceSet.h"
#include "include/IfcTextureVertexList.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcIndexedTriangleTextureMap 
		IfcIndexedTriangleTextureMap::IfcIndexedTriangleTextureMap() { m_entity_enum = IFCINDEXEDTRIANGLETEXTUREMAP; }
		IfcIndexedTriangleTextureMap::IfcIndexedTriangleTextureMap( int id ) { m_id = id; m_entity_enum = IFCINDEXEDTRIANGLETEXTUREMAP; }
		IfcIndexedTriangleTextureMap::~IfcIndexedTriangleTextureMap() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcIndexedTriangleTextureMap::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcIndexedTriangleTextureMap> other = dynamic_pointer_cast<IfcIndexedTriangleTextureMap>(other_entity);
			if( !other) { return; }
			m_Maps = other->m_Maps;
			m_MappedTo = other->m_MappedTo;
			m_TexCoords = other->m_TexCoords;
			m_TexCoordIndex = other->m_TexCoordIndex;
		}
		void IfcIndexedTriangleTextureMap::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCINDEXEDTRIANGLETEXTUREMAP" << "(";
			writeEntityList( stream, m_Maps );
			stream << ",";
			if( m_MappedTo ) { stream << "#" << m_MappedTo->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_TexCoords ) { stream << "#" << m_TexCoords->getId(); } else { stream << "$"; }
			stream << ",";
			writeIntList2D( stream, m_TexCoordIndex );
			stream << ");";
		}
		void IfcIndexedTriangleTextureMap::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcIndexedTriangleTextureMap::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcIndexedTriangleTextureMap, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcIndexedTriangleTextureMap, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_Maps, map );
			readEntityReference( args[1], m_MappedTo, map );
			readEntityReference( args[2], m_TexCoords, map );
			readIntList2D(  args[3], m_TexCoordIndex );
		}
		void IfcIndexedTriangleTextureMap::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcIndexedTextureMap::setInverseCounterparts( ptr_self_entity );
		}
		void IfcIndexedTriangleTextureMap::unlinkSelf()
		{
			IfcIndexedTextureMap::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

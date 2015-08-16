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
#include "include/IfcIndexedTextureMap.h"
#include "include/IfcSurfaceTexture.h"
#include "include/IfcTessellatedFaceSet.h"
#include "include/IfcTextureVertexList.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcIndexedTextureMap 
		IfcIndexedTextureMap::IfcIndexedTextureMap() { m_entity_enum = IFCINDEXEDTEXTUREMAP; }
		IfcIndexedTextureMap::IfcIndexedTextureMap( int id ) { m_id = id; m_entity_enum = IFCINDEXEDTEXTUREMAP; }
		IfcIndexedTextureMap::~IfcIndexedTextureMap() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcIndexedTextureMap::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcIndexedTextureMap> other = dynamic_pointer_cast<IfcIndexedTextureMap>(other_entity);
			if( !other) { return; }
			m_Maps = other->m_Maps;
			m_MappedTo = other->m_MappedTo;
			m_TexCoords = other->m_TexCoords;
		}
		void IfcIndexedTextureMap::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCINDEXEDTEXTUREMAP" << "(";
			writeEntityList( stream, m_Maps );
			stream << ",";
			if( m_MappedTo ) { stream << "#" << m_MappedTo->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_TexCoords ) { stream << "#" << m_TexCoords->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcIndexedTextureMap::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcIndexedTextureMap::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcIndexedTextureMap, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcIndexedTextureMap, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_Maps, map );
			readEntityReference( args[1], m_MappedTo, map );
			readEntityReference( args[2], m_TexCoords, map );
		}
		void IfcIndexedTextureMap::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcTextureCoordinate::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcIndexedTextureMap> ptr_self = dynamic_pointer_cast<IfcIndexedTextureMap>( ptr_self_entity );
			if( !ptr_self ) { throw IfcRoadException( "IfcIndexedTextureMap::setInverseCounterparts: type mismatch" ); }
			if( m_MappedTo )
			{
				m_MappedTo->m_HasTextures_inverse.push_back( ptr_self );
			}
		}
		void IfcIndexedTextureMap::unlinkSelf()
		{
			IfcTextureCoordinate::unlinkSelf();
			if( m_MappedTo )
			{
				std::vector<weak_ptr<IfcIndexedTextureMap> >& HasTextures_inverse = m_MappedTo->m_HasTextures_inverse;
				std::vector<weak_ptr<IfcIndexedTextureMap> >::iterator it_HasTextures_inverse;
				for( it_HasTextures_inverse = HasTextures_inverse.begin(); it_HasTextures_inverse != HasTextures_inverse.end(); ++it_HasTextures_inverse)
				{
					shared_ptr<IfcIndexedTextureMap> self_candidate( *it_HasTextures_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						HasTextures_inverse.erase( it_HasTextures_inverse );
						break;
					}
				}
			}
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/IfcAlignmentP6EntityEnums.h"
#include "include/IfcFace.h"
#include "include/IfcSurfaceTexture.h"
#include "include/IfcTextureMap.h"
#include "include/IfcTextureVertex.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcTextureMap 
		IfcTextureMap::IfcTextureMap() { m_entity_enum = IFCTEXTUREMAP; }
		IfcTextureMap::IfcTextureMap( int id ) { m_id = id; m_entity_enum = IFCTEXTUREMAP; }
		IfcTextureMap::~IfcTextureMap() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTextureMap::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcTextureMap> other = dynamic_pointer_cast<IfcTextureMap>(other_entity);
			if( !other) { return; }
			m_Maps = other->m_Maps;
			m_Vertices = other->m_Vertices;
			m_MappedTo = other->m_MappedTo;
		}
		void IfcTextureMap::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTEXTUREMAP" << "(";
			writeEntityList( stream, m_Maps );
			stream << ",";
			writeEntityList( stream, m_Vertices );
			stream << ",";
			if( m_MappedTo ) { stream << "#" << m_MappedTo->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcTextureMap::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTextureMap::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTextureMap, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcTextureMap, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_Maps, map );
			readEntityReferenceList( args[1], m_Vertices, map );
			readEntityReference( args[2], m_MappedTo, map );
		}
		void IfcTextureMap::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcTextureCoordinate::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcTextureMap> ptr_self = dynamic_pointer_cast<IfcTextureMap>( ptr_self_entity );
			if( !ptr_self ) { throw IfcAlignmentP6Exception( "IfcTextureMap::setInverseCounterparts: type mismatch" ); }
			if( m_MappedTo )
			{
				m_MappedTo->m_HasTextureMaps_inverse.push_back( ptr_self );
			}
		}
		void IfcTextureMap::unlinkSelf()
		{
			IfcTextureCoordinate::unlinkSelf();
			if( m_MappedTo )
			{
				std::vector<weak_ptr<IfcTextureMap> >& HasTextureMaps_inverse = m_MappedTo->m_HasTextureMaps_inverse;
				std::vector<weak_ptr<IfcTextureMap> >::iterator it_HasTextureMaps_inverse;
				for( it_HasTextureMaps_inverse = HasTextureMaps_inverse.begin(); it_HasTextureMaps_inverse != HasTextureMaps_inverse.end(); ++it_HasTextureMaps_inverse)
				{
					shared_ptr<IfcTextureMap> self_candidate( *it_HasTextureMaps_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						HasTextureMaps_inverse.erase( it_HasTextureMaps_inverse );
						break;
					}
				}
			}
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

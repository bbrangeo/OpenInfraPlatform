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
#include "include/IfcAxis2Placement.h"
#include "include/IfcMappedItem.h"
#include "include/IfcRepresentation.h"
#include "include/IfcRepresentationMap.h"
#include "include/IfcShapeAspect.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcRepresentationMap 
		IfcRepresentationMap::IfcRepresentationMap() { m_entity_enum = IFCREPRESENTATIONMAP; }
		IfcRepresentationMap::IfcRepresentationMap( int id ) { m_id = id; m_entity_enum = IFCREPRESENTATIONMAP; }
		IfcRepresentationMap::~IfcRepresentationMap() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRepresentationMap::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcRepresentationMap> other = dynamic_pointer_cast<IfcRepresentationMap>(other_entity);
			if( !other) { return; }
			m_MappingOrigin = other->m_MappingOrigin;
			m_MappedRepresentation = other->m_MappedRepresentation;
		}
		void IfcRepresentationMap::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCREPRESENTATIONMAP" << "(";
			if( m_MappingOrigin ) { m_MappingOrigin->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_MappedRepresentation ) { stream << "#" << m_MappedRepresentation->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcRepresentationMap::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRepresentationMap::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRepresentationMap, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcRepresentationMap, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_MappingOrigin = IfcAxis2Placement::readStepData( args[0], map );
			readEntityReference( args[1], m_MappedRepresentation, map );
		}
		void IfcRepresentationMap::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			shared_ptr<IfcRepresentationMap> ptr_self = dynamic_pointer_cast<IfcRepresentationMap>( ptr_self_entity );
			if( !ptr_self ) { throw IfcRoadException( "IfcRepresentationMap::setInverseCounterparts: type mismatch" ); }
			if( m_MappedRepresentation )
			{
				m_MappedRepresentation->m_RepresentationMap_inverse.push_back( ptr_self );
			}
		}
		void IfcRepresentationMap::unlinkSelf()
		{
			if( m_MappedRepresentation )
			{
				std::vector<weak_ptr<IfcRepresentationMap> >& RepresentationMap_inverse = m_MappedRepresentation->m_RepresentationMap_inverse;
				std::vector<weak_ptr<IfcRepresentationMap> >::iterator it_RepresentationMap_inverse;
				for( it_RepresentationMap_inverse = RepresentationMap_inverse.begin(); it_RepresentationMap_inverse != RepresentationMap_inverse.end(); ++it_RepresentationMap_inverse)
				{
					shared_ptr<IfcRepresentationMap> self_candidate( *it_RepresentationMap_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						RepresentationMap_inverse.erase( it_RepresentationMap_inverse );
						break;
					}
				}
			}
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

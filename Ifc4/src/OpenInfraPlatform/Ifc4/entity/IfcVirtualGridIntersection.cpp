/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "OpenInfraPlatform/Ifc4/writer/WriterUtil.h"
#include "OpenInfraPlatform/Ifc4/Ifc4EntityEnums.h"
#include "include/IfcGridAxis.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcVirtualGridIntersection.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcVirtualGridIntersection 
		IfcVirtualGridIntersection::IfcVirtualGridIntersection() { m_entity_enum = IFCVIRTUALGRIDINTERSECTION; }
		IfcVirtualGridIntersection::IfcVirtualGridIntersection( int id ) { m_id = id; m_entity_enum = IFCVIRTUALGRIDINTERSECTION; }
		IfcVirtualGridIntersection::~IfcVirtualGridIntersection() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcVirtualGridIntersection::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcVirtualGridIntersection> other = dynamic_pointer_cast<IfcVirtualGridIntersection>(other_entity);
			if( !other) { return; }
			m_IntersectingAxes = other->m_IntersectingAxes;
			m_OffsetDistances = other->m_OffsetDistances;
		}
		void IfcVirtualGridIntersection::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCVIRTUALGRIDINTERSECTION" << "(";
			writeEntityList( stream, m_IntersectingAxes );
			stream << ",";
			writeTypeOfRealList( stream, m_OffsetDistances );
			stream << ");";
		}
		void IfcVirtualGridIntersection::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcVirtualGridIntersection::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcVirtualGridIntersection, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcVirtualGridIntersection, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_IntersectingAxes, map );
			readTypeOfRealList( args[1], m_OffsetDistances );
		}
		void IfcVirtualGridIntersection::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			shared_ptr<IfcVirtualGridIntersection> ptr_self = dynamic_pointer_cast<IfcVirtualGridIntersection>( ptr_self_entity );
			if( !ptr_self ) { throw Ifc4Exception( "IfcVirtualGridIntersection::setInverseCounterparts: type mismatch" ); }
			for( int i=0; i<m_IntersectingAxes.size(); ++i )
			{
				if( m_IntersectingAxes[i] )
				{
					m_IntersectingAxes[i]->m_HasIntersections_inverse.push_back( ptr_self );
				}
			}
		}
		void IfcVirtualGridIntersection::unlinkSelf()
		{
			for( int i=0; i<m_IntersectingAxes.size(); ++i )
			{
				if( m_IntersectingAxes[i] )
				{
					std::vector<weak_ptr<IfcVirtualGridIntersection> >& HasIntersections_inverse = m_IntersectingAxes[i]->m_HasIntersections_inverse;
					std::vector<weak_ptr<IfcVirtualGridIntersection> >::iterator it_HasIntersections_inverse;
					for( it_HasIntersections_inverse = HasIntersections_inverse.begin(); it_HasIntersections_inverse != HasIntersections_inverse.end(); ++it_HasIntersections_inverse)
					{
						shared_ptr<IfcVirtualGridIntersection> self_candidate( *it_HasIntersections_inverse );
						if( self_candidate->getId() == this->getId() )
						{
							HasIntersections_inverse.erase( it_HasIntersections_inverse );
							break;
						}
					}
				}
			}
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

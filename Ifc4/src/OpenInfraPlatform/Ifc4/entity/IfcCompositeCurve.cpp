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
#include "include/IfcCompositeCurve.h"
#include "include/IfcCompositeCurveSegment.h"
#include "include/IfcLogical.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcCompositeCurve 
		IfcCompositeCurve::IfcCompositeCurve() { m_entity_enum = IFCCOMPOSITECURVE; }
		IfcCompositeCurve::IfcCompositeCurve( int id ) { m_id = id; m_entity_enum = IFCCOMPOSITECURVE; }
		IfcCompositeCurve::~IfcCompositeCurve() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCompositeCurve::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcCompositeCurve> other = dynamic_pointer_cast<IfcCompositeCurve>(other_entity);
			if( !other) { return; }
			m_Segments = other->m_Segments;
			m_SelfIntersect = other->m_SelfIntersect;
		}
		void IfcCompositeCurve::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCOMPOSITECURVE" << "(";
			writeEntityList( stream, m_Segments );
			stream << ",";
			if( m_SelfIntersect ) { m_SelfIntersect->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcCompositeCurve::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCompositeCurve::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCompositeCurve, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcCompositeCurve, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_Segments, map );
			m_SelfIntersect = IfcLogical::readStepData( args[1] );
		}
		void IfcCompositeCurve::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcBoundedCurve::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcCompositeCurve> ptr_self = dynamic_pointer_cast<IfcCompositeCurve>( ptr_self_entity );
			if( !ptr_self ) { throw Ifc4Exception( "IfcCompositeCurve::setInverseCounterparts: type mismatch" ); }
			for( int i=0; i<m_Segments.size(); ++i )
			{
				if( m_Segments[i] )
				{
					m_Segments[i]->m_UsingCurves_inverse.push_back( ptr_self );
				}
			}
		}
		void IfcCompositeCurve::unlinkSelf()
		{
			IfcBoundedCurve::unlinkSelf();
			for( int i=0; i<m_Segments.size(); ++i )
			{
				if( m_Segments[i] )
				{
					std::vector<weak_ptr<IfcCompositeCurve> >& UsingCurves_inverse = m_Segments[i]->m_UsingCurves_inverse;
					std::vector<weak_ptr<IfcCompositeCurve> >::iterator it_UsingCurves_inverse;
					for( it_UsingCurves_inverse = UsingCurves_inverse.begin(); it_UsingCurves_inverse != UsingCurves_inverse.end(); ++it_UsingCurves_inverse)
					{
						shared_ptr<IfcCompositeCurve> self_candidate( *it_UsingCurves_inverse );
						if( self_candidate->getId() == this->getId() )
						{
							UsingCurves_inverse.erase( it_UsingCurves_inverse );
							break;
						}
					}
				}
			}
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

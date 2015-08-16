/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcBridgeException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcBridgeEntityEnums.h"
#include "include/IfcCompositeCurve.h"
#include "include/IfcCompositeCurveSegment.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcCompositeCurve 
		IfcCompositeCurve::IfcCompositeCurve() { m_entity_enum = IFCCOMPOSITECURVE; }
		IfcCompositeCurve::IfcCompositeCurve( int id ) { m_id = id; m_entity_enum = IFCCOMPOSITECURVE; }
		IfcCompositeCurve::~IfcCompositeCurve() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCompositeCurve::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
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
			if( m_SelfIntersect == false ) { stream << ".F."; }
			else if( m_SelfIntersect == true ) { stream << ".T."; }
			stream << ");";
		}
		void IfcCompositeCurve::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCompositeCurve::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCompositeCurve, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcCompositeCurve, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_Segments, map );
			if( _stricmp( args[1].c_str(), ".F." ) == 0 ) { m_SelfIntersect = false; }
			else if( _stricmp( args[1].c_str(), ".T." ) == 0 ) { m_SelfIntersect = true; }
		}
		void IfcCompositeCurve::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcBoundedCurve::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcCompositeCurve> ptr_self = dynamic_pointer_cast<IfcCompositeCurve>( ptr_self_entity );
			if( !ptr_self ) { throw IfcBridgeException( "IfcCompositeCurve::setInverseCounterparts: type mismatch" ); }
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
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

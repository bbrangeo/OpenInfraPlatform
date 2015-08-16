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
#include "include/IfcDirection.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcLocalPlacement.h"
#include "include/IfcProduct.h"
#include "include/IfcReferenceCurvePlacement.h"
#include "include/IfcReferenceCurvePlacementSystem.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcReferenceCurvePlacement 
		IfcReferenceCurvePlacement::IfcReferenceCurvePlacement() { m_entity_enum = IFCREFERENCECURVEPLACEMENT; }
		IfcReferenceCurvePlacement::IfcReferenceCurvePlacement( int id ) { m_id = id; m_entity_enum = IFCREFERENCECURVEPLACEMENT; }
		IfcReferenceCurvePlacement::~IfcReferenceCurvePlacement() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcReferenceCurvePlacement::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcReferenceCurvePlacement> other = dynamic_pointer_cast<IfcReferenceCurvePlacement>(other_entity);
			if( !other) { return; }
			m_CurvilinearAbscissa = other->m_CurvilinearAbscissa;
			m_Axis = other->m_Axis;
			m_RefDirection = other->m_RefDirection;
			m_RelativeTo = other->m_RelativeTo;
		}
		void IfcReferenceCurvePlacement::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCREFERENCECURVEPLACEMENT" << "(";
			if( m_CurvilinearAbscissa ) { m_CurvilinearAbscissa->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Axis ) { stream << "#" << m_Axis->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_RefDirection ) { stream << "#" << m_RefDirection->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_RelativeTo ) { stream << "#" << m_RelativeTo->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcReferenceCurvePlacement::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcReferenceCurvePlacement::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcReferenceCurvePlacement, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcReferenceCurvePlacement, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_CurvilinearAbscissa = IfcLengthMeasure::readStepData( args[0] );
			readEntityReference( args[1], m_Axis, map );
			readEntityReference( args[2], m_RefDirection, map );
			readEntityReference( args[3], m_RelativeTo, map );
		}
		void IfcReferenceCurvePlacement::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcReferencePlacement::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcReferenceCurvePlacement> ptr_self = dynamic_pointer_cast<IfcReferenceCurvePlacement>( ptr_self_entity );
			if( !ptr_self ) { throw IfcBridgeException( "IfcReferenceCurvePlacement::setInverseCounterparts: type mismatch" ); }
			if( m_RelativeTo )
			{
				m_RelativeTo->m_Includes_inverse.push_back( ptr_self );
			}
		}
		void IfcReferenceCurvePlacement::unlinkSelf()
		{
			IfcReferencePlacement::unlinkSelf();
			if( m_RelativeTo )
			{
				std::vector<weak_ptr<IfcReferenceCurvePlacement> >& Includes_inverse = m_RelativeTo->m_Includes_inverse;
				std::vector<weak_ptr<IfcReferenceCurvePlacement> >::iterator it_Includes_inverse;
				for( it_Includes_inverse = Includes_inverse.begin(); it_Includes_inverse != Includes_inverse.end(); ++it_Includes_inverse)
				{
					shared_ptr<IfcReferenceCurvePlacement> self_candidate( *it_Includes_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						Includes_inverse.erase( it_Includes_inverse );
						break;
					}
				}
			}
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

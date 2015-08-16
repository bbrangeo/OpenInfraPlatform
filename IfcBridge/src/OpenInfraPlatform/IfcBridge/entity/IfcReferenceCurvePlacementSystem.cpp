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
#include "include/IfcLocalPlacement.h"
#include "include/IfcProduct.h"
#include "include/IfcReferenceCurve.h"
#include "include/IfcReferenceCurvePlacement.h"
#include "include/IfcReferenceCurvePlacementSystem.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcReferenceCurvePlacementSystem 
		IfcReferenceCurvePlacementSystem::IfcReferenceCurvePlacementSystem() { m_entity_enum = IFCREFERENCECURVEPLACEMENTSYSTEM; }
		IfcReferenceCurvePlacementSystem::IfcReferenceCurvePlacementSystem( int id ) { m_id = id; m_entity_enum = IFCREFERENCECURVEPLACEMENTSYSTEM; }
		IfcReferenceCurvePlacementSystem::~IfcReferenceCurvePlacementSystem() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcReferenceCurvePlacementSystem::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcReferenceCurvePlacementSystem> other = dynamic_pointer_cast<IfcReferenceCurvePlacementSystem>(other_entity);
			if( !other) { return; }
			m_Label = other->m_Label;
			m_BasedOn = other->m_BasedOn;
		}
		void IfcReferenceCurvePlacementSystem::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCREFERENCECURVEPLACEMENTSYSTEM" << "(";
			stream << encodeStepString( m_Label );
			stream << ",";
			if( m_BasedOn ) { stream << "#" << m_BasedOn->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcReferenceCurvePlacementSystem::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcReferenceCurvePlacementSystem::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcReferenceCurvePlacementSystem, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcReferenceCurvePlacementSystem, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Label = args[0];
			readEntityReference( args[1], m_BasedOn, map );
		}
		void IfcReferenceCurvePlacementSystem::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcReferencePlacement::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcReferenceCurvePlacementSystem> ptr_self = dynamic_pointer_cast<IfcReferenceCurvePlacementSystem>( ptr_self_entity );
			if( !ptr_self ) { throw IfcBridgeException( "IfcReferenceCurvePlacementSystem::setInverseCounterparts: type mismatch" ); }
			if( m_BasedOn )
			{
				m_BasedOn->m_HasPlacements_inverse.push_back( ptr_self );
			}
		}
		void IfcReferenceCurvePlacementSystem::unlinkSelf()
		{
			IfcReferencePlacement::unlinkSelf();
			if( m_BasedOn )
			{
				std::vector<weak_ptr<IfcReferenceCurvePlacementSystem> >& HasPlacements_inverse = m_BasedOn->m_HasPlacements_inverse;
				std::vector<weak_ptr<IfcReferenceCurvePlacementSystem> >::iterator it_HasPlacements_inverse;
				for( it_HasPlacements_inverse = HasPlacements_inverse.begin(); it_HasPlacements_inverse != HasPlacements_inverse.end(); ++it_HasPlacements_inverse)
				{
					shared_ptr<IfcReferenceCurvePlacementSystem> self_candidate( *it_HasPlacements_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						HasPlacements_inverse.erase( it_HasPlacements_inverse );
						break;
					}
				}
			}
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

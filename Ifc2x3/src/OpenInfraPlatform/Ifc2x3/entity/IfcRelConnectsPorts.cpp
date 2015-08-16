/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/Ifc2x3Exception.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "Ifc2x3EntityEnums.h"
#include "include/IfcElement.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcPort.h"
#include "include/IfcRelConnectsPorts.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcRelConnectsPorts 
		IfcRelConnectsPorts::IfcRelConnectsPorts() { m_entity_enum = IFCRELCONNECTSPORTS; }
		IfcRelConnectsPorts::IfcRelConnectsPorts( int id ) { m_id = id; m_entity_enum = IFCRELCONNECTSPORTS; }
		IfcRelConnectsPorts::~IfcRelConnectsPorts() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRelConnectsPorts::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcRelConnectsPorts> other = dynamic_pointer_cast<IfcRelConnectsPorts>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_RelatingPort = other->m_RelatingPort;
			m_RelatedPort = other->m_RelatedPort;
			m_RealizingElement = other->m_RealizingElement;
		}
		void IfcRelConnectsPorts::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRELCONNECTSPORTS" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RelatingPort ) { stream << "#" << m_RelatingPort->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_RelatedPort ) { stream << "#" << m_RelatedPort->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_RealizingElement ) { stream << "#" << m_RealizingElement->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcRelConnectsPorts::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRelConnectsPorts::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<7 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRelConnectsPorts, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>7 ){ std::cout << "Wrong parameter count for entity IfcRelConnectsPorts, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			readEntityReference( args[4], m_RelatingPort, map );
			readEntityReference( args[5], m_RelatedPort, map );
			readEntityReference( args[6], m_RealizingElement, map );
		}
		void IfcRelConnectsPorts::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcRelConnects::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcRelConnectsPorts> ptr_self = dynamic_pointer_cast<IfcRelConnectsPorts>( ptr_self_entity );
			if( !ptr_self ) { throw Ifc2x3Exception( "IfcRelConnectsPorts::setInverseCounterparts: type mismatch" ); }
			if( m_RelatedPort )
			{
				m_RelatedPort->m_ConnectedFrom_inverse.push_back( ptr_self );
			}
			if( m_RelatingPort )
			{
				m_RelatingPort->m_ConnectedTo_inverse.push_back( ptr_self );
			}
		}
		void IfcRelConnectsPorts::unlinkSelf()
		{
			IfcRelConnects::unlinkSelf();
			if( m_RelatedPort )
			{
				std::vector<weak_ptr<IfcRelConnectsPorts> >& ConnectedFrom_inverse = m_RelatedPort->m_ConnectedFrom_inverse;
				std::vector<weak_ptr<IfcRelConnectsPorts> >::iterator it_ConnectedFrom_inverse;
				for( it_ConnectedFrom_inverse = ConnectedFrom_inverse.begin(); it_ConnectedFrom_inverse != ConnectedFrom_inverse.end(); ++it_ConnectedFrom_inverse)
				{
					shared_ptr<IfcRelConnectsPorts> self_candidate( *it_ConnectedFrom_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						ConnectedFrom_inverse.erase( it_ConnectedFrom_inverse );
						break;
					}
				}
			}
			if( m_RelatingPort )
			{
				std::vector<weak_ptr<IfcRelConnectsPorts> >& ConnectedTo_inverse = m_RelatingPort->m_ConnectedTo_inverse;
				std::vector<weak_ptr<IfcRelConnectsPorts> >::iterator it_ConnectedTo_inverse;
				for( it_ConnectedTo_inverse = ConnectedTo_inverse.begin(); it_ConnectedTo_inverse != ConnectedTo_inverse.end(); ++it_ConnectedTo_inverse)
				{
					shared_ptr<IfcRelConnectsPorts> self_candidate( *it_ConnectedTo_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						ConnectedTo_inverse.erase( it_ConnectedTo_inverse );
						break;
					}
				}
			}
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

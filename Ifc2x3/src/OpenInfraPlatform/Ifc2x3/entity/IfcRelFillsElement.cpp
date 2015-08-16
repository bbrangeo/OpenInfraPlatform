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
#include "include/IfcOpeningElement.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcRelFillsElement.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcRelFillsElement 
		IfcRelFillsElement::IfcRelFillsElement() { m_entity_enum = IFCRELFILLSELEMENT; }
		IfcRelFillsElement::IfcRelFillsElement( int id ) { m_id = id; m_entity_enum = IFCRELFILLSELEMENT; }
		IfcRelFillsElement::~IfcRelFillsElement() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRelFillsElement::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcRelFillsElement> other = dynamic_pointer_cast<IfcRelFillsElement>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_RelatingOpeningElement = other->m_RelatingOpeningElement;
			m_RelatedBuildingElement = other->m_RelatedBuildingElement;
		}
		void IfcRelFillsElement::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRELFILLSELEMENT" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RelatingOpeningElement ) { stream << "#" << m_RelatingOpeningElement->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_RelatedBuildingElement ) { stream << "#" << m_RelatedBuildingElement->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcRelFillsElement::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRelFillsElement::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRelFillsElement, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcRelFillsElement, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			readEntityReference( args[4], m_RelatingOpeningElement, map );
			readEntityReference( args[5], m_RelatedBuildingElement, map );
		}
		void IfcRelFillsElement::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcRelConnects::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcRelFillsElement> ptr_self = dynamic_pointer_cast<IfcRelFillsElement>( ptr_self_entity );
			if( !ptr_self ) { throw Ifc2x3Exception( "IfcRelFillsElement::setInverseCounterparts: type mismatch" ); }
			if( m_RelatedBuildingElement )
			{
				m_RelatedBuildingElement->m_FillsVoids_inverse.push_back( ptr_self );
			}
			if( m_RelatingOpeningElement )
			{
				m_RelatingOpeningElement->m_HasFillings_inverse.push_back( ptr_self );
			}
		}
		void IfcRelFillsElement::unlinkSelf()
		{
			IfcRelConnects::unlinkSelf();
			if( m_RelatedBuildingElement )
			{
				std::vector<weak_ptr<IfcRelFillsElement> >& FillsVoids_inverse = m_RelatedBuildingElement->m_FillsVoids_inverse;
				std::vector<weak_ptr<IfcRelFillsElement> >::iterator it_FillsVoids_inverse;
				for( it_FillsVoids_inverse = FillsVoids_inverse.begin(); it_FillsVoids_inverse != FillsVoids_inverse.end(); ++it_FillsVoids_inverse)
				{
					shared_ptr<IfcRelFillsElement> self_candidate( *it_FillsVoids_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						FillsVoids_inverse.erase( it_FillsVoids_inverse );
						break;
					}
				}
			}
			if( m_RelatingOpeningElement )
			{
				std::vector<weak_ptr<IfcRelFillsElement> >& HasFillings_inverse = m_RelatingOpeningElement->m_HasFillings_inverse;
				std::vector<weak_ptr<IfcRelFillsElement> >::iterator it_HasFillings_inverse;
				for( it_HasFillings_inverse = HasFillings_inverse.begin(); it_HasFillings_inverse != HasFillings_inverse.end(); ++it_HasFillings_inverse)
				{
					shared_ptr<IfcRelFillsElement> self_candidate( *it_HasFillings_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						HasFillings_inverse.erase( it_HasFillings_inverse );
						break;
					}
				}
			}
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

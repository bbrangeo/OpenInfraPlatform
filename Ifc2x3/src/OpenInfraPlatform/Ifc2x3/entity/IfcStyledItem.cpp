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
#include "include/IfcLabel.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcPresentationStyleAssignment.h"
#include "include/IfcRepresentationItem.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcStyledItem 
		IfcStyledItem::IfcStyledItem() { m_entity_enum = IFCSTYLEDITEM; }
		IfcStyledItem::IfcStyledItem( int id ) { m_id = id; m_entity_enum = IFCSTYLEDITEM; }
		IfcStyledItem::~IfcStyledItem() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcStyledItem::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcStyledItem> other = dynamic_pointer_cast<IfcStyledItem>(other_entity);
			if( !other) { return; }
			m_Item = other->m_Item;
			m_Styles = other->m_Styles;
			m_Name = other->m_Name;
		}
		void IfcStyledItem::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSTYLEDITEM" << "(";
			if( m_Item ) { stream << "#" << m_Item->getId(); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_Styles );
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcStyledItem::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcStyledItem::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcStyledItem, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcStyledItem, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Item, map );
			readEntityReferenceList( args[1], m_Styles, map );
			m_Name = IfcLabel::readStepData( args[2] );
		}
		void IfcStyledItem::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcRepresentationItem::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcStyledItem> ptr_self = dynamic_pointer_cast<IfcStyledItem>( ptr_self_entity );
			if( !ptr_self ) { throw Ifc2x3Exception( "IfcStyledItem::setInverseCounterparts: type mismatch" ); }
			if( m_Item )
			{
				m_Item->m_StyledByItem_inverse.push_back( ptr_self );
			}
		}
		void IfcStyledItem::unlinkSelf()
		{
			IfcRepresentationItem::unlinkSelf();
			if( m_Item )
			{
				std::vector<weak_ptr<IfcStyledItem> >& StyledByItem_inverse = m_Item->m_StyledByItem_inverse;
				std::vector<weak_ptr<IfcStyledItem> >::iterator it_StyledByItem_inverse;
				for( it_StyledByItem_inverse = StyledByItem_inverse.begin(); it_StyledByItem_inverse != StyledByItem_inverse.end(); ++it_StyledByItem_inverse)
				{
					shared_ptr<IfcStyledItem> self_candidate( *it_StyledByItem_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						StyledByItem_inverse.erase( it_StyledByItem_inverse );
						break;
					}
				}
			}
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

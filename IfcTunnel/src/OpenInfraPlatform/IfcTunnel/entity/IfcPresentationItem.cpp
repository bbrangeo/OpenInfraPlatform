/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcTunnelException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcTunnelEntityEnums.h"
#include "include/IfcPresentationItem.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcPresentationItem 
		IfcPresentationItem::IfcPresentationItem() { m_entity_enum = IFCPRESENTATIONITEM; }
		IfcPresentationItem::IfcPresentationItem( int id ) { m_id = id; m_entity_enum = IFCPRESENTATIONITEM; }
		IfcPresentationItem::~IfcPresentationItem() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPresentationItem::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcPresentationItem> other = dynamic_pointer_cast<IfcPresentationItem>(other_entity);
			if( !other) { return; }
		}
		void IfcPresentationItem::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPRESENTATIONITEM" << "(";
			stream << ");";
		}
		void IfcPresentationItem::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPresentationItem::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
		}
		void IfcPresentationItem::setInverseCounterparts( shared_ptr<IfcTunnelEntity> )
		{
		}
		void IfcPresentationItem::unlinkSelf()
		{
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

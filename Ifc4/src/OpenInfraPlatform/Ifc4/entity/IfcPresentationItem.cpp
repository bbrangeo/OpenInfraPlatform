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
#include "include/IfcPresentationItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcPresentationItem 
		IfcPresentationItem::IfcPresentationItem() { m_entity_enum = IFCPRESENTATIONITEM; }
		IfcPresentationItem::IfcPresentationItem( int id ) { m_id = id; m_entity_enum = IFCPRESENTATIONITEM; }
		IfcPresentationItem::~IfcPresentationItem() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPresentationItem::setEntity( shared_ptr<Ifc4Entity> other_entity )
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
		void IfcPresentationItem::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
		}
		void IfcPresentationItem::setInverseCounterparts( shared_ptr<Ifc4Entity> )
		{
		}
		void IfcPresentationItem::unlinkSelf()
		{
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

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
#include "include/IfcLocalPlacement.h"
#include "include/IfcObjectPlacement.h"
#include "include/IfcProduct.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcObjectPlacement 
		IfcObjectPlacement::IfcObjectPlacement() { m_entity_enum = IFCOBJECTPLACEMENT; }
		IfcObjectPlacement::IfcObjectPlacement( int id ) { m_id = id; m_entity_enum = IFCOBJECTPLACEMENT; }
		IfcObjectPlacement::~IfcObjectPlacement() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcObjectPlacement::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcObjectPlacement> other = dynamic_pointer_cast<IfcObjectPlacement>(other_entity);
			if( !other) { return; }
		}
		void IfcObjectPlacement::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCOBJECTPLACEMENT" << "(";
			stream << ");";
		}
		void IfcObjectPlacement::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcObjectPlacement::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
		}
		void IfcObjectPlacement::setInverseCounterparts( shared_ptr<Ifc4Entity> )
		{
		}
		void IfcObjectPlacement::unlinkSelf()
		{
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

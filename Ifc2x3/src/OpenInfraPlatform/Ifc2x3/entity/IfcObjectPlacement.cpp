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
#include "include/IfcLocalPlacement.h"
#include "include/IfcObjectPlacement.h"
#include "include/IfcProduct.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcObjectPlacement 
		IfcObjectPlacement::IfcObjectPlacement() { m_entity_enum = IFCOBJECTPLACEMENT; }
		IfcObjectPlacement::IfcObjectPlacement( int id ) { m_id = id; m_entity_enum = IFCOBJECTPLACEMENT; }
		IfcObjectPlacement::~IfcObjectPlacement() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcObjectPlacement::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
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
		void IfcObjectPlacement::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
		}
		void IfcObjectPlacement::setInverseCounterparts( shared_ptr<Ifc2x3Entity> )
		{
		}
		void IfcObjectPlacement::unlinkSelf()
		{
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

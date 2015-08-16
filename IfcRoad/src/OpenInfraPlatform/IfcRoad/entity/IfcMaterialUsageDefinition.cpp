/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/IfcRoadEntityEnums.h"
#include "include/IfcMaterialUsageDefinition.h"
#include "include/IfcRelAssociatesMaterial.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcMaterialUsageDefinition 
		IfcMaterialUsageDefinition::IfcMaterialUsageDefinition() { m_entity_enum = IFCMATERIALUSAGEDEFINITION; }
		IfcMaterialUsageDefinition::IfcMaterialUsageDefinition( int id ) { m_id = id; m_entity_enum = IFCMATERIALUSAGEDEFINITION; }
		IfcMaterialUsageDefinition::~IfcMaterialUsageDefinition() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcMaterialUsageDefinition::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcMaterialUsageDefinition> other = dynamic_pointer_cast<IfcMaterialUsageDefinition>(other_entity);
			if( !other) { return; }
		}
		void IfcMaterialUsageDefinition::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCMATERIALUSAGEDEFINITION" << "(";
			stream << ");";
		}
		void IfcMaterialUsageDefinition::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcMaterialUsageDefinition::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
		}
		void IfcMaterialUsageDefinition::setInverseCounterparts( shared_ptr<IfcRoadEntity> )
		{
		}
		void IfcMaterialUsageDefinition::unlinkSelf()
		{
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

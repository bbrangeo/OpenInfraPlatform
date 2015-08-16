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
#include "include/IfcMaterialUsageDefinition.h"
#include "include/IfcRelAssociatesMaterial.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcMaterialUsageDefinition 
		IfcMaterialUsageDefinition::IfcMaterialUsageDefinition() { m_entity_enum = IFCMATERIALUSAGEDEFINITION; }
		IfcMaterialUsageDefinition::IfcMaterialUsageDefinition( int id ) { m_id = id; m_entity_enum = IFCMATERIALUSAGEDEFINITION; }
		IfcMaterialUsageDefinition::~IfcMaterialUsageDefinition() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcMaterialUsageDefinition::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
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
		void IfcMaterialUsageDefinition::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
		}
		void IfcMaterialUsageDefinition::setInverseCounterparts( shared_ptr<IfcTunnelEntity> )
		{
		}
		void IfcMaterialUsageDefinition::unlinkSelf()
		{
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

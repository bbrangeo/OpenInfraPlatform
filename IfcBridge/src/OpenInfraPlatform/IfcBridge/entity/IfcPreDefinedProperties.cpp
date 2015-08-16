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
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcPreDefinedProperties.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcPreDefinedProperties 
		IfcPreDefinedProperties::IfcPreDefinedProperties() { m_entity_enum = IFCPREDEFINEDPROPERTIES; }
		IfcPreDefinedProperties::IfcPreDefinedProperties( int id ) { m_id = id; m_entity_enum = IFCPREDEFINEDPROPERTIES; }
		IfcPreDefinedProperties::~IfcPreDefinedProperties() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPreDefinedProperties::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcPreDefinedProperties> other = dynamic_pointer_cast<IfcPreDefinedProperties>(other_entity);
			if( !other) { return; }
		}
		void IfcPreDefinedProperties::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPREDEFINEDPROPERTIES" << "(";
			stream << ");";
		}
		void IfcPreDefinedProperties::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPreDefinedProperties::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
		}
		void IfcPreDefinedProperties::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcPropertyAbstraction::setInverseCounterparts( ptr_self_entity );
		}
		void IfcPreDefinedProperties::unlinkSelf()
		{
			IfcPropertyAbstraction::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

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
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcPreDefinedProperties.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcPreDefinedProperties 
		IfcPreDefinedProperties::IfcPreDefinedProperties() { m_entity_enum = IFCPREDEFINEDPROPERTIES; }
		IfcPreDefinedProperties::IfcPreDefinedProperties( int id ) { m_id = id; m_entity_enum = IFCPREDEFINEDPROPERTIES; }
		IfcPreDefinedProperties::~IfcPreDefinedProperties() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPreDefinedProperties::setEntity( shared_ptr<Ifc4Entity> other_entity )
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
		void IfcPreDefinedProperties::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
		}
		void IfcPreDefinedProperties::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcPropertyAbstraction::setInverseCounterparts( ptr_self_entity );
		}
		void IfcPreDefinedProperties::unlinkSelf()
		{
			IfcPropertyAbstraction::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

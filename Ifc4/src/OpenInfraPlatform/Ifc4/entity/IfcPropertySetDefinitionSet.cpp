/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "OpenInfraPlatform/Ifc4/writer/WriterUtil.h"
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "include/IfcPropertySetDefinitionSelect.h"
#include "include/IfcPropertySetDefinition.h"
#include "include/IfcPropertySetDefinitionSet.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcPropertySetDefinitionSet 
		IfcPropertySetDefinitionSet::IfcPropertySetDefinitionSet() {}
		IfcPropertySetDefinitionSet::~IfcPropertySetDefinitionSet() {}
		void IfcPropertySetDefinitionSet::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCPROPERTYSETDEFINITIONSET("; }
			writeEntityList( stream, m_vec );
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcPropertySetDefinitionSet> IfcPropertySetDefinitionSet::readStepData( std::string& arg, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcPropertySetDefinitionSet>(); }
			shared_ptr<IfcPropertySetDefinitionSet> type_object( new IfcPropertySetDefinitionSet() );
			readEntityReferenceList(  arg, type_object->m_vec, map );
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

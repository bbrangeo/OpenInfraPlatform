/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "../model/shared_ptr.h"
#include "../model/IfcTunnelException.h"
#include "include/IfcPropertySetDefinitionSelect.h"
#include "include/IfcPropertySetDefinition.h"
#include "include/IfcPropertySetDefinitionSet.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
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
		shared_ptr<IfcPropertySetDefinitionSet> IfcPropertySetDefinitionSet::readStepData( std::string& arg, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcPropertySetDefinitionSet>(); }
			shared_ptr<IfcPropertySetDefinitionSet> type_object( new IfcPropertySetDefinitionSet() );
			readEntityReferenceList(  arg, type_object->m_vec, map );
			return type_object;
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

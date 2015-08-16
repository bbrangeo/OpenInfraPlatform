/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "../../model/shared_ptr.h"
#include "../../model/IfcTunnelObject.h"
#include "IfcPropertySetDefinitionSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{class IfcPropertySetDefinition;

		// TYPE IfcPropertySetDefinitionSet = SET [1:?] OF IfcPropertySetDefinition;
		class IfcPropertySetDefinitionSet : public IfcPropertySetDefinitionSelect, public IfcTunnelType
		{
		public:
			IfcPropertySetDefinitionSet();
			~IfcPropertySetDefinitionSet();
			virtual const char* classname() const { return "IfcPropertySetDefinitionSet"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcPropertySetDefinitionSet> readStepData( std::string& arg, const std::map<int,shared_ptr<IfcTunnelEntity> >& map );
			std::vector<shared_ptr<IfcPropertySetDefinition> > m_vec;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform


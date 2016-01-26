/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Object.h"
#include "IfcPropertySetDefinitionSelect.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{class IfcPropertySetDefinition;

		// TYPE IfcPropertySetDefinitionSet = SET [1:?] OF IfcPropertySetDefinition;
		class IfcPropertySetDefinitionSet : public IfcPropertySetDefinitionSelect, public Ifc4Type
		{
		public:
			IfcPropertySetDefinitionSet();
			~IfcPropertySetDefinitionSet();
			virtual const char* classname() const { return "IfcPropertySetDefinitionSet"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcPropertySetDefinitionSet> readStepData( std::string& arg, const std::map<int,shared_ptr<Ifc4Entity> >& map );
			std::vector<shared_ptr<IfcPropertySetDefinition> > m_vec;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform


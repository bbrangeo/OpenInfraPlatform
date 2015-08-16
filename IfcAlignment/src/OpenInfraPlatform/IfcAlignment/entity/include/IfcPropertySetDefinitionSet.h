/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Object.h"
#include "IfcPropertySetDefinitionSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{class IfcPropertySetDefinition;

		// TYPE IfcPropertySetDefinitionSet = SET [1:?] OF IfcPropertySetDefinition;
		class IfcPropertySetDefinitionSet : public IfcPropertySetDefinitionSelect, public IfcAlignmentP6Type
		{
		public:
			IfcPropertySetDefinitionSet();
			~IfcPropertySetDefinitionSet();
			virtual const char* classname() const { return "IfcPropertySetDefinitionSet"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcPropertySetDefinitionSet> readStepData( std::string& arg, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			std::vector<shared_ptr<IfcPropertySetDefinition> > m_vec;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform


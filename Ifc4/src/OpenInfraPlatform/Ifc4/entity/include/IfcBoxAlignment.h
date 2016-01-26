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
#include "IfcLabel.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcBoxAlignment = IfcLabel;
		class IfcBoxAlignment : public IfcLabel
		{
		public:
			IfcBoxAlignment();
			~IfcBoxAlignment();
			virtual const char* classname() const { return "IfcBoxAlignment"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcBoxAlignment> readStepData( std::string& arg );
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform


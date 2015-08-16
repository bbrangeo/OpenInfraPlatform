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
#include "IfcLabel.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
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
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform


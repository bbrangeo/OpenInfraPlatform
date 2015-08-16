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
#include "IfcLabel.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
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
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform


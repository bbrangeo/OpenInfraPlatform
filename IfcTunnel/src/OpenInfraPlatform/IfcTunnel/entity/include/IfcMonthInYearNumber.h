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

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcMonthInYearNumber = INTEGER;
		class IfcMonthInYearNumber : public IfcTunnelType
		{
		public:
			IfcMonthInYearNumber();
			IfcMonthInYearNumber( int value );
			~IfcMonthInYearNumber();
			virtual const char* classname() const { return "IfcMonthInYearNumber"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcMonthInYearNumber> readStepData( std::string& arg );
			int m_value;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform


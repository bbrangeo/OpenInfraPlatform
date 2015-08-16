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
		// TYPE IfcTubeBundleTypeEnum = ENUMERATION OF	(FINNED	,USERDEFINED	,NOTDEFINED);
		class IfcTubeBundleTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcTubeBundleTypeEnumEnum
			{
				ENUM_FINNED,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcTubeBundleTypeEnum();
			IfcTubeBundleTypeEnum( IfcTubeBundleTypeEnumEnum e ) { m_enum = e; }
			~IfcTubeBundleTypeEnum();
			virtual const char* classname() const { return "IfcTubeBundleTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcTubeBundleTypeEnum> readStepData( std::string& arg );
			IfcTubeBundleTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform


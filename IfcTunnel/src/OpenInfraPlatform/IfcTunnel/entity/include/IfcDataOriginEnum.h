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
		// TYPE IfcDataOriginEnum = ENUMERATION OF	(MEASURED	,PREDICTED	,SIMULATED	,USERDEFINED	,NOTDEFINED);
		class IfcDataOriginEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcDataOriginEnumEnum
			{
				ENUM_MEASURED,
				ENUM_PREDICTED,
				ENUM_SIMULATED,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcDataOriginEnum();
			IfcDataOriginEnum( IfcDataOriginEnumEnum e ) { m_enum = e; }
			~IfcDataOriginEnum();
			virtual const char* classname() const { return "IfcDataOriginEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcDataOriginEnum> readStepData( std::string& arg );
			IfcDataOriginEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform


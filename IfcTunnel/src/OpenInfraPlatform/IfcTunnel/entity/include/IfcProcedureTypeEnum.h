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
		// TYPE IfcProcedureTypeEnum = ENUMERATION OF	(ADVICE_CAUTION	,ADVICE_NOTE	,ADVICE_WARNING	,CALIBRATION	,DIAGNOSTIC	,SHUTDOWN	,STARTUP	,USERDEFINED	,NOTDEFINED);
		class IfcProcedureTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcProcedureTypeEnumEnum
			{
				ENUM_ADVICE_CAUTION,
				ENUM_ADVICE_NOTE,
				ENUM_ADVICE_WARNING,
				ENUM_CALIBRATION,
				ENUM_DIAGNOSTIC,
				ENUM_SHUTDOWN,
				ENUM_STARTUP,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcProcedureTypeEnum();
			IfcProcedureTypeEnum( IfcProcedureTypeEnumEnum e ) { m_enum = e; }
			~IfcProcedureTypeEnum();
			virtual const char* classname() const { return "IfcProcedureTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcProcedureTypeEnum> readStepData( std::string& arg );
			IfcProcedureTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform


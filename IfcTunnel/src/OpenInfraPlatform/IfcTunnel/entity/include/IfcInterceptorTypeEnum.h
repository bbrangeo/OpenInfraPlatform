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
		// TYPE IfcInterceptorTypeEnum = ENUMERATION OF	(CYCLONIC	,GREASE	,OIL	,PETROL	,USERDEFINED	,NOTDEFINED);
		class IfcInterceptorTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcInterceptorTypeEnumEnum
			{
				ENUM_CYCLONIC,
				ENUM_GREASE,
				ENUM_OIL,
				ENUM_PETROL,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcInterceptorTypeEnum();
			IfcInterceptorTypeEnum( IfcInterceptorTypeEnumEnum e ) { m_enum = e; }
			~IfcInterceptorTypeEnum();
			virtual const char* classname() const { return "IfcInterceptorTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcInterceptorTypeEnum> readStepData( std::string& arg );
			IfcInterceptorTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform


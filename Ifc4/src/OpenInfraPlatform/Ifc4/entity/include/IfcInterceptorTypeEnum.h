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

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcInterceptorTypeEnum = ENUMERATION OF	(CYCLONIC	,GREASE	,OIL	,PETROL	,USERDEFINED	,NOTDEFINED);
		class IfcInterceptorTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
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
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform


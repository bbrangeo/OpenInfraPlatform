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
		// TYPE IfcTubeBundleTypeEnum = ENUMERATION OF	(FINNED	,USERDEFINED	,NOTDEFINED);
		class IfcTubeBundleTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
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
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform


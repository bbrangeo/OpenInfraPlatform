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

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcTubeBundleTypeEnum = ENUMERATION OF	(FINNED	,USERDEFINED	,NOTDEFINED);
		class IfcTubeBundleTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
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
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform


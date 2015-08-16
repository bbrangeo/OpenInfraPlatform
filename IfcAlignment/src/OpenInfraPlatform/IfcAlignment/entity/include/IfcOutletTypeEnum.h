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
		// TYPE IfcOutletTypeEnum = ENUMERATION OF	(AUDIOVISUALOUTLET	,COMMUNICATIONSOUTLET	,POWEROUTLET	,DATAOUTLET	,TELEPHONEOUTLET	,USERDEFINED	,NOTDEFINED);
		class IfcOutletTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcOutletTypeEnumEnum
			{
				ENUM_AUDIOVISUALOUTLET,
				ENUM_COMMUNICATIONSOUTLET,
				ENUM_POWEROUTLET,
				ENUM_DATAOUTLET,
				ENUM_TELEPHONEOUTLET,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcOutletTypeEnum();
			IfcOutletTypeEnum( IfcOutletTypeEnumEnum e ) { m_enum = e; }
			~IfcOutletTypeEnum();
			virtual const char* classname() const { return "IfcOutletTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcOutletTypeEnum> readStepData( std::string& arg );
			IfcOutletTypeEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform


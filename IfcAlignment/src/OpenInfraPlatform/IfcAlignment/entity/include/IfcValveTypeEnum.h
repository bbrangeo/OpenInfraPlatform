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
		// TYPE IfcValveTypeEnum = ENUMERATION OF	(AIRRELEASE	,ANTIVACUUM	,CHANGEOVER	,CHECK	,COMMISSIONING	,DIVERTING	,DRAWOFFCOCK	,DOUBLECHECK	,DOUBLEREGULATING	,FAUCET	,FLUSHING	,GASCOCK	,GASTAP	,ISOLATING	,MIXING	,PRESSUREREDUCING	,PRESSURERELIEF	,REGULATING	,SAFETYCUTOFF	,STEAMTRAP	,STOPCOCK	,USERDEFINED	,NOTDEFINED);
		class IfcValveTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcValveTypeEnumEnum
			{
				ENUM_AIRRELEASE,
				ENUM_ANTIVACUUM,
				ENUM_CHANGEOVER,
				ENUM_CHECK,
				ENUM_COMMISSIONING,
				ENUM_DIVERTING,
				ENUM_DRAWOFFCOCK,
				ENUM_DOUBLECHECK,
				ENUM_DOUBLEREGULATING,
				ENUM_FAUCET,
				ENUM_FLUSHING,
				ENUM_GASCOCK,
				ENUM_GASTAP,
				ENUM_ISOLATING,
				ENUM_MIXING,
				ENUM_PRESSUREREDUCING,
				ENUM_PRESSURERELIEF,
				ENUM_REGULATING,
				ENUM_SAFETYCUTOFF,
				ENUM_STEAMTRAP,
				ENUM_STOPCOCK,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcValveTypeEnum();
			IfcValveTypeEnum( IfcValveTypeEnumEnum e ) { m_enum = e; }
			~IfcValveTypeEnum();
			virtual const char* classname() const { return "IfcValveTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcValveTypeEnum> readStepData( std::string& arg );
			IfcValveTypeEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform


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
		// TYPE IfcRoofTypeEnum = ENUMERATION OF	(FLAT_ROOF	,SHED_ROOF	,GABLE_ROOF	,HIP_ROOF	,HIPPED_GABLE_ROOF	,GAMBREL_ROOF	,MANSARD_ROOF	,BARREL_ROOF	,RAINBOW_ROOF	,BUTTERFLY_ROOF	,PAVILION_ROOF	,DOME_ROOF	,FREEFORM	,USERDEFINED	,NOTDEFINED);
		class IfcRoofTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcRoofTypeEnumEnum
			{
				ENUM_FLAT_ROOF,
				ENUM_SHED_ROOF,
				ENUM_GABLE_ROOF,
				ENUM_HIP_ROOF,
				ENUM_HIPPED_GABLE_ROOF,
				ENUM_GAMBREL_ROOF,
				ENUM_MANSARD_ROOF,
				ENUM_BARREL_ROOF,
				ENUM_RAINBOW_ROOF,
				ENUM_BUTTERFLY_ROOF,
				ENUM_PAVILION_ROOF,
				ENUM_DOME_ROOF,
				ENUM_FREEFORM,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcRoofTypeEnum();
			IfcRoofTypeEnum( IfcRoofTypeEnumEnum e ) { m_enum = e; }
			~IfcRoofTypeEnum();
			virtual const char* classname() const { return "IfcRoofTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcRoofTypeEnum> readStepData( std::string& arg );
			IfcRoofTypeEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform


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
		// TYPE IfcWallTypeEnum = ENUMERATION OF	(MOVABLE	,PARAPET	,PARTITIONING	,PLUMBINGWALL	,SHEAR	,SOLIDWALL	,STANDARD	,POLYGONAL	,ELEMENTEDWALL	,USERDEFINED	,NOTDEFINED);
		class IfcWallTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcWallTypeEnumEnum
			{
				ENUM_MOVABLE,
				ENUM_PARAPET,
				ENUM_PARTITIONING,
				ENUM_PLUMBINGWALL,
				ENUM_SHEAR,
				ENUM_SOLIDWALL,
				ENUM_STANDARD,
				ENUM_POLYGONAL,
				ENUM_ELEMENTEDWALL,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcWallTypeEnum();
			IfcWallTypeEnum( IfcWallTypeEnumEnum e ) { m_enum = e; }
			~IfcWallTypeEnum();
			virtual const char* classname() const { return "IfcWallTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcWallTypeEnum> readStepData( std::string& arg );
			IfcWallTypeEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform


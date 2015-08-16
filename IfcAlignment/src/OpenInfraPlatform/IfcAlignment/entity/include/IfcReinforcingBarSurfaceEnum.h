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
		// TYPE IfcReinforcingBarSurfaceEnum = ENUMERATION OF	(PLAIN	,TEXTURED);
		class IfcReinforcingBarSurfaceEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcReinforcingBarSurfaceEnumEnum
			{
				ENUM_PLAIN,
				ENUM_TEXTURED
			};

			IfcReinforcingBarSurfaceEnum();
			IfcReinforcingBarSurfaceEnum( IfcReinforcingBarSurfaceEnumEnum e ) { m_enum = e; }
			~IfcReinforcingBarSurfaceEnum();
			virtual const char* classname() const { return "IfcReinforcingBarSurfaceEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcReinforcingBarSurfaceEnum> readStepData( std::string& arg );
			IfcReinforcingBarSurfaceEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform


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
		// TYPE IfcTextPath = ENUMERATION OF	(LEFT	,RIGHT	,UP	,DOWN);
		class IfcTextPath : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcTextPathEnum
			{
				ENUM_LEFT,
				ENUM_RIGHT,
				ENUM_UP,
				ENUM_DOWN
			};

			IfcTextPath();
			IfcTextPath( IfcTextPathEnum e ) { m_enum = e; }
			~IfcTextPath();
			virtual const char* classname() const { return "IfcTextPath"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcTextPath> readStepData( std::string& arg );
			IfcTextPathEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform


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
		// TYPE IfcTextPath = ENUMERATION OF	(LEFT	,RIGHT	,UP	,DOWN);
		class IfcTextPath : public Ifc4AbstractEnum, public Ifc4Type
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
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform


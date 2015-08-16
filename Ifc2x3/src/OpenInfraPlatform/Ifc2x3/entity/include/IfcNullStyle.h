/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "../../model/shared_ptr.h"
#include "../../model/Ifc2x3Object.h"
#include "IfcPresentationStyleSelect.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcNullStyle = ENUMERATION OF	(NULL);
		class IfcNullStyle : public IfcPresentationStyleSelect, public Ifc2x3Type
		{
		public:
			enum IfcNullStyleEnum
			{
				ENUM_ENUM_NULL
			};

			IfcNullStyle();
			IfcNullStyle( IfcNullStyleEnum e ) { m_enum = e; }
			~IfcNullStyle();
			virtual const char* classname() const { return "IfcNullStyle"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcNullStyle> readStepData( std::string& arg );
			IfcNullStyleEnum m_enum;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform


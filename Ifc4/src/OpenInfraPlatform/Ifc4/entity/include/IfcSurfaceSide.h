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
		// TYPE IfcSurfaceSide = ENUMERATION OF	(POSITIVE	,NEGATIVE	,BOTH);
		class IfcSurfaceSide : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcSurfaceSideEnum
			{
				ENUM_POSITIVE,
				ENUM_NEGATIVE,
				ENUM_BOTH
			};

			IfcSurfaceSide();
			IfcSurfaceSide( IfcSurfaceSideEnum e ) { m_enum = e; }
			~IfcSurfaceSide();
			virtual const char* classname() const { return "IfcSurfaceSide"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcSurfaceSide> readStepData( std::string& arg );
			IfcSurfaceSideEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform


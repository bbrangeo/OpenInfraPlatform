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
		// TYPE IfcSurfaceSide = ENUMERATION OF	(POSITIVE	,NEGATIVE	,BOTH);
		class IfcSurfaceSide : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
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
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform


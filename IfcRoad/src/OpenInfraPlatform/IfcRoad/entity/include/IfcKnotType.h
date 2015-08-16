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
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadObject.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcKnotType = ENUMERATION OF	(UNIFORM_KNOTS	,QUASI_UNIFORM_KNOTS	,PIECEWISE_BEZIER_KNOTS	,UNSPECIFIED);
		class IfcKnotType : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcKnotTypeEnum
			{
				ENUM_UNIFORM_KNOTS,
				ENUM_QUASI_UNIFORM_KNOTS,
				ENUM_PIECEWISE_BEZIER_KNOTS,
				ENUM_UNSPECIFIED
			};

			IfcKnotType();
			IfcKnotType( IfcKnotTypeEnum e ) { m_enum = e; }
			~IfcKnotType();
			virtual const char* classname() const { return "IfcKnotType"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcKnotType> readStepData( std::string& arg );
			IfcKnotTypeEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform


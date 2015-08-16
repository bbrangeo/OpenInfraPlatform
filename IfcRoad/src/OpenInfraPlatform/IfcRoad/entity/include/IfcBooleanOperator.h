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
		// TYPE IfcBooleanOperator = ENUMERATION OF	(UNION	,INTERSECTION	,DIFFERENCE);
		class IfcBooleanOperator : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcBooleanOperatorEnum
			{
				ENUM_UNION,
				ENUM_INTERSECTION,
				ENUM_DIFFERENCE
			};

			IfcBooleanOperator();
			IfcBooleanOperator( IfcBooleanOperatorEnum e ) { m_enum = e; }
			~IfcBooleanOperator();
			virtual const char* classname() const { return "IfcBooleanOperator"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcBooleanOperator> readStepData( std::string& arg );
			IfcBooleanOperatorEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform


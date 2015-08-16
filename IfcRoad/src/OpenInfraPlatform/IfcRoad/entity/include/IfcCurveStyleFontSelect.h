/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadObject.h"
#include "IfcCurveFontOrScaledCurveFontSelect.h"

// TYPE IfcCurveStyleFontSelect = SELECT	(IfcCurveStyleFont	,IfcPreDefinedCurveFont);
namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		class IfcCurveStyleFontSelect : public IfcCurveFontOrScaledCurveFontSelect
		{
		public:
			IfcCurveStyleFontSelect();
			~IfcCurveStyleFontSelect();
			virtual const char* classname() const { return "IfcCurveStyleFontSelect"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const = 0; // abstract class
			static shared_ptr<IfcCurveStyleFontSelect> readStepData( std::string& arg, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform


/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Object.h"

// TYPE IfcAppliedValueSelect = SELECT	(IfcMeasureWithUnit	,IfcReference	,IfcValue);
namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcAppliedValueSelect : public IfcAlignmentP6AbstractSelect
		{
		public:
			IfcAppliedValueSelect();
			~IfcAppliedValueSelect();
			virtual const char* classname() const { return "IfcAppliedValueSelect"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const = 0; // abstract class
			static shared_ptr<IfcAppliedValueSelect> readStepData( std::string& arg, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform


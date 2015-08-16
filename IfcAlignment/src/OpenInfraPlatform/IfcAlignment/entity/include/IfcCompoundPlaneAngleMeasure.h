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
#include "IfcDerivedMeasureValue.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcCompoundPlaneAngleMeasure = LIST [3:4] OF INTEGER;
		class IfcCompoundPlaneAngleMeasure : public IfcDerivedMeasureValue, public IfcAlignmentP6Type
		{
		public:
			IfcCompoundPlaneAngleMeasure();
			~IfcCompoundPlaneAngleMeasure();
			virtual const char* classname() const { return "IfcCompoundPlaneAngleMeasure"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcCompoundPlaneAngleMeasure> readStepData( std::string& arg );
			std::vector<int> m_vec;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform


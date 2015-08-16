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
#include "IfcDerivedMeasureValue.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcCompoundPlaneAngleMeasure = LIST [3:4] OF INTEGER;
		class IfcCompoundPlaneAngleMeasure : public IfcDerivedMeasureValue, public Ifc2x3Type
		{
		public:
			IfcCompoundPlaneAngleMeasure();
			~IfcCompoundPlaneAngleMeasure();
			virtual const char* classname() const { return "IfcCompoundPlaneAngleMeasure"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcCompoundPlaneAngleMeasure> readStepData( std::string& arg );
			std::vector<int> m_vec;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform


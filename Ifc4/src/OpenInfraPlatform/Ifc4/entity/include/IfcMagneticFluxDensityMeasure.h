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
#include "IfcDerivedMeasureValue.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcMagneticFluxDensityMeasure = REAL;
		class IfcMagneticFluxDensityMeasure : public IfcDerivedMeasureValue, public Ifc4Type
		{
		public:
			IfcMagneticFluxDensityMeasure();
			IfcMagneticFluxDensityMeasure( double value );
			~IfcMagneticFluxDensityMeasure();
			virtual const char* classname() const { return "IfcMagneticFluxDensityMeasure"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcMagneticFluxDensityMeasure> readStepData( std::string& arg );
			double m_value;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform


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
#include "IfcModulusOfTranslationalSubgradeReactionSelect.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcModulusOfLinearSubgradeReactionMeasure = REAL;
		class IfcModulusOfLinearSubgradeReactionMeasure : public IfcDerivedMeasureValue, public IfcModulusOfTranslationalSubgradeReactionSelect, public Ifc4Type
		{
		public:
			IfcModulusOfLinearSubgradeReactionMeasure();
			IfcModulusOfLinearSubgradeReactionMeasure( double value );
			~IfcModulusOfLinearSubgradeReactionMeasure();
			virtual const char* classname() const { return "IfcModulusOfLinearSubgradeReactionMeasure"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcModulusOfLinearSubgradeReactionMeasure> readStepData( std::string& arg );
			double m_value;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform


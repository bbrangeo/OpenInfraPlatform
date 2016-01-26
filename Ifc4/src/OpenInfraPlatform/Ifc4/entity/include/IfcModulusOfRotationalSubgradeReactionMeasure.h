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
#include "IfcModulusOfRotationalSubgradeReactionSelect.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcModulusOfRotationalSubgradeReactionMeasure = REAL;
		class IfcModulusOfRotationalSubgradeReactionMeasure : public IfcDerivedMeasureValue, public IfcModulusOfRotationalSubgradeReactionSelect, public Ifc4Type
		{
		public:
			IfcModulusOfRotationalSubgradeReactionMeasure();
			IfcModulusOfRotationalSubgradeReactionMeasure( double value );
			~IfcModulusOfRotationalSubgradeReactionMeasure();
			virtual const char* classname() const { return "IfcModulusOfRotationalSubgradeReactionMeasure"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcModulusOfRotationalSubgradeReactionMeasure> readStepData( std::string& arg );
			double m_value;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform


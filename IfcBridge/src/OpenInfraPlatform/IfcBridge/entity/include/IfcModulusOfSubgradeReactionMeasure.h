/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
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
#include "../../model/IfcBridgeObject.h"
#include "IfcDerivedMeasureValue.h"
#include "IfcModulusOfSubgradeReactionSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcModulusOfSubgradeReactionMeasure = REAL;
		class IfcModulusOfSubgradeReactionMeasure : public IfcDerivedMeasureValue, public IfcModulusOfSubgradeReactionSelect, public IfcBridgeType
		{
		public:
			IfcModulusOfSubgradeReactionMeasure();
			IfcModulusOfSubgradeReactionMeasure( double value );
			~IfcModulusOfSubgradeReactionMeasure();
			virtual const char* classname() const { return "IfcModulusOfSubgradeReactionMeasure"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcModulusOfSubgradeReactionMeasure> readStepData( std::string& arg );
			double m_value;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform


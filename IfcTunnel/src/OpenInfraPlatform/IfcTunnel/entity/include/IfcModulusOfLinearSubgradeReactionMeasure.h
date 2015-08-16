/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
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
#include "../../model/IfcTunnelObject.h"
#include "IfcDerivedMeasureValue.h"
#include "IfcModulusOfTranslationalSubgradeReactionSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcModulusOfLinearSubgradeReactionMeasure = REAL;
		class IfcModulusOfLinearSubgradeReactionMeasure : public IfcDerivedMeasureValue, public IfcModulusOfTranslationalSubgradeReactionSelect, public IfcTunnelType
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
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform


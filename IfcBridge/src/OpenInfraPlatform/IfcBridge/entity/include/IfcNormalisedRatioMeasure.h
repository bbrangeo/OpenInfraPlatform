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
#include "IfcRatioMeasure.h"
#include "IfcColourOrFactor.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcNormalisedRatioMeasure = IfcRatioMeasure;
		class IfcNormalisedRatioMeasure : public IfcRatioMeasure, public IfcColourOrFactor
		{
		public:
			IfcNormalisedRatioMeasure();
			~IfcNormalisedRatioMeasure();
			virtual const char* classname() const { return "IfcNormalisedRatioMeasure"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcNormalisedRatioMeasure> readStepData( std::string& arg );
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform


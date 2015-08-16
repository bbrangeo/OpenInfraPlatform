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

// TYPE IfcBooleanOperand = SELECT	(IfcBooleanResult	,IfcCsgPrimitive3D	,IfcHalfSpaceSolid	,IfcSolidModel);
namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcBooleanOperand : public IfcAlignmentP6AbstractSelect
		{
		public:
			IfcBooleanOperand();
			~IfcBooleanOperand();
			virtual const char* classname() const { return "IfcBooleanOperand"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const = 0; // abstract class
			static shared_ptr<IfcBooleanOperand> readStepData( std::string& arg, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform


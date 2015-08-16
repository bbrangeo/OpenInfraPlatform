/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include "../../model/shared_ptr.h"
#include "../../model/IfcTunnelObject.h"

// TYPE IfcRotationalStiffnessSelect = SELECT	(IfcBoolean	,IfcRotationalStiffnessMeasure);
namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		class IfcRotationalStiffnessSelect : public IfcTunnelAbstractSelect
		{
		public:
			IfcRotationalStiffnessSelect();
			~IfcRotationalStiffnessSelect();
			virtual const char* classname() const { return "IfcRotationalStiffnessSelect"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const = 0; // abstract class
			static shared_ptr<IfcRotationalStiffnessSelect> readStepData( std::string& arg, const std::map<int,shared_ptr<IfcTunnelEntity> >& map );
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform


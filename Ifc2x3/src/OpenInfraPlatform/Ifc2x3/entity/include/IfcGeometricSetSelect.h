/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include "../../model/shared_ptr.h"
#include "../../model/Ifc2x3Object.h"

// TYPE IfcGeometricSetSelect = SELECT	(IfcPoint	,IfcCurve	,IfcSurface);
namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		class IfcGeometricSetSelect : public Ifc2x3AbstractSelect
		{
		public:
			IfcGeometricSetSelect();
			~IfcGeometricSetSelect();
			virtual const char* classname() const { return "IfcGeometricSetSelect"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const = 0; // abstract class
			static shared_ptr<IfcGeometricSetSelect> readStepData( std::string& arg, const std::map<int,shared_ptr<Ifc2x3Entity> >& map );
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform


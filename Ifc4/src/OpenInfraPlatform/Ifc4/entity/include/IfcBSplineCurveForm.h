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

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcBSplineCurveForm = ENUMERATION OF	(POLYLINE_FORM	,CIRCULAR_ARC	,ELLIPTIC_ARC	,PARABOLIC_ARC	,HYPERBOLIC_ARC	,UNSPECIFIED);
		class IfcBSplineCurveForm : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcBSplineCurveFormEnum
			{
				ENUM_POLYLINE_FORM,
				ENUM_CIRCULAR_ARC,
				ENUM_ELLIPTIC_ARC,
				ENUM_PARABOLIC_ARC,
				ENUM_HYPERBOLIC_ARC,
				ENUM_UNSPECIFIED
			};

			IfcBSplineCurveForm();
			IfcBSplineCurveForm( IfcBSplineCurveFormEnum e ) { m_enum = e; }
			~IfcBSplineCurveForm();
			virtual const char* classname() const { return "IfcBSplineCurveForm"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcBSplineCurveForm> readStepData( std::string& arg );
			IfcBSplineCurveFormEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform


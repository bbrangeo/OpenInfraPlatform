/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
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
#include "../../model/Ifc2x3Object.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcBSplineCurveForm = ENUMERATION OF	(POLYLINE_FORM	,CIRCULAR_ARC	,ELLIPTIC_ARC	,PARABOLIC_ARC	,HYPERBOLIC_ARC	,UNSPECIFIED);
		class IfcBSplineCurveForm : public Ifc2x3AbstractEnum, public Ifc2x3Type
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
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform


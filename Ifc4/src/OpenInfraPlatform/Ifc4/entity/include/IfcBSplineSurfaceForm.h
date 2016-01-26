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
		// TYPE IfcBSplineSurfaceForm = ENUMERATION OF	(PLANE_SURF	,CYLINDRICAL_SURF	,CONICAL_SURF	,SPHERICAL_SURF	,TOROIDAL_SURF	,SURF_OF_REVOLUTION	,RULED_SURF	,GENERALISED_CONE	,QUADRIC_SURF	,SURF_OF_LINEAR_EXTRUSION	,UNSPECIFIED);
		class IfcBSplineSurfaceForm : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcBSplineSurfaceFormEnum
			{
				ENUM_PLANE_SURF,
				ENUM_CYLINDRICAL_SURF,
				ENUM_CONICAL_SURF,
				ENUM_SPHERICAL_SURF,
				ENUM_TOROIDAL_SURF,
				ENUM_SURF_OF_REVOLUTION,
				ENUM_RULED_SURF,
				ENUM_GENERALISED_CONE,
				ENUM_QUADRIC_SURF,
				ENUM_SURF_OF_LINEAR_EXTRUSION,
				ENUM_UNSPECIFIED
			};

			IfcBSplineSurfaceForm();
			IfcBSplineSurfaceForm( IfcBSplineSurfaceFormEnum e ) { m_enum = e; }
			~IfcBSplineSurfaceForm();
			virtual const char* classname() const { return "IfcBSplineSurfaceForm"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcBSplineSurfaceForm> readStepData( std::string& arg );
			IfcBSplineSurfaceFormEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform


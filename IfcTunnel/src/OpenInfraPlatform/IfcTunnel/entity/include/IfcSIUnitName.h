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

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcSIUnitName = ENUMERATION OF	(AMPERE	,BECQUEREL	,CANDELA	,COULOMB	,CUBIC_METRE	,DEGREE_CELSIUS	,FARAD	,GRAM	,GRAY	,HENRY	,HERTZ	,JOULE	,KELVIN	,LUMEN	,LUX	,METRE	,MOLE	,NEWTON	,OHM	,PASCAL	,RADIAN	,SECOND	,SIEMENS	,SIEVERT	,SQUARE_METRE	,STERADIAN	,TESLA	,VOLT	,WATT	,WEBER);
		class IfcSIUnitName : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcSIUnitNameEnum
			{
				ENUM_AMPERE,
				ENUM_BECQUEREL,
				ENUM_CANDELA,
				ENUM_COULOMB,
				ENUM_CUBIC_METRE,
				ENUM_DEGREE_CELSIUS,
				ENUM_FARAD,
				ENUM_GRAM,
				ENUM_GRAY,
				ENUM_HENRY,
				ENUM_HERTZ,
				ENUM_JOULE,
				ENUM_KELVIN,
				ENUM_LUMEN,
				ENUM_LUX,
				ENUM_METRE,
				ENUM_MOLE,
				ENUM_NEWTON,
				ENUM_OHM,
				ENUM_PASCAL,
				ENUM_RADIAN,
				ENUM_SECOND,
				ENUM_SIEMENS,
				ENUM_SIEVERT,
				ENUM_SQUARE_METRE,
				ENUM_STERADIAN,
				ENUM_TESLA,
				ENUM_VOLT,
				ENUM_WATT,
				ENUM_WEBER
			};

			IfcSIUnitName();
			IfcSIUnitName( IfcSIUnitNameEnum e ) { m_enum = e; }
			~IfcSIUnitName();
			virtual const char* classname() const { return "IfcSIUnitName"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcSIUnitName> readStepData( std::string& arg );
			IfcSIUnitNameEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform


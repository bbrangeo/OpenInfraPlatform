/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "../model/shared_ptr.h"
#include "../model/Ifc2x3Exception.h"
#include "include/IfcThermalLoadTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcThermalLoadTypeEnum 
		IfcThermalLoadTypeEnum::IfcThermalLoadTypeEnum() {}
		IfcThermalLoadTypeEnum::~IfcThermalLoadTypeEnum() {}
		void IfcThermalLoadTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCTHERMALLOADTYPEENUM("; }
			if( m_enum == ENUM_SENSIBLE )
			{
				stream << ".SENSIBLE.";
			}
			else if( m_enum == ENUM_LATENT )
			{
				stream << ".LATENT.";
			}
			else if( m_enum == ENUM_RADIANT )
			{
				stream << ".RADIANT.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcThermalLoadTypeEnum> IfcThermalLoadTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcThermalLoadTypeEnum>(); }
			shared_ptr<IfcThermalLoadTypeEnum> type_object( new IfcThermalLoadTypeEnum() );
			if( _stricmp( arg.c_str(), ".SENSIBLE." ) == 0 )
			{
				type_object->m_enum = IfcThermalLoadTypeEnum::ENUM_SENSIBLE;
			}
			else if( _stricmp( arg.c_str(), ".LATENT." ) == 0 )
			{
				type_object->m_enum = IfcThermalLoadTypeEnum::ENUM_LATENT;
			}
			else if( _stricmp( arg.c_str(), ".RADIANT." ) == 0 )
			{
				type_object->m_enum = IfcThermalLoadTypeEnum::ENUM_RADIANT;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcThermalLoadTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

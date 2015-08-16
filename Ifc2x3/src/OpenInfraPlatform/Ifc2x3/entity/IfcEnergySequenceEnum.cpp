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
#include "include/IfcEnergySequenceEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcEnergySequenceEnum 
		IfcEnergySequenceEnum::IfcEnergySequenceEnum() {}
		IfcEnergySequenceEnum::~IfcEnergySequenceEnum() {}
		void IfcEnergySequenceEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCENERGYSEQUENCEENUM("; }
			if( m_enum == ENUM_PRIMARY )
			{
				stream << ".PRIMARY.";
			}
			else if( m_enum == ENUM_SECONDARY )
			{
				stream << ".SECONDARY.";
			}
			else if( m_enum == ENUM_TERTIARY )
			{
				stream << ".TERTIARY.";
			}
			else if( m_enum == ENUM_AUXILIARY )
			{
				stream << ".AUXILIARY.";
			}
			else if( m_enum == ENUM_USERDEFINED )
			{
				stream << ".USERDEFINED.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcEnergySequenceEnum> IfcEnergySequenceEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcEnergySequenceEnum>(); }
			shared_ptr<IfcEnergySequenceEnum> type_object( new IfcEnergySequenceEnum() );
			if( _stricmp( arg.c_str(), ".PRIMARY." ) == 0 )
			{
				type_object->m_enum = IfcEnergySequenceEnum::ENUM_PRIMARY;
			}
			else if( _stricmp( arg.c_str(), ".SECONDARY." ) == 0 )
			{
				type_object->m_enum = IfcEnergySequenceEnum::ENUM_SECONDARY;
			}
			else if( _stricmp( arg.c_str(), ".TERTIARY." ) == 0 )
			{
				type_object->m_enum = IfcEnergySequenceEnum::ENUM_TERTIARY;
			}
			else if( _stricmp( arg.c_str(), ".AUXILIARY." ) == 0 )
			{
				type_object->m_enum = IfcEnergySequenceEnum::ENUM_AUXILIARY;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcEnergySequenceEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcEnergySequenceEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

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
#include "include/IfcElectricCurrentEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcElectricCurrentEnum 
		IfcElectricCurrentEnum::IfcElectricCurrentEnum() {}
		IfcElectricCurrentEnum::~IfcElectricCurrentEnum() {}
		void IfcElectricCurrentEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCELECTRICCURRENTENUM("; }
			if( m_enum == ENUM_ALTERNATING )
			{
				stream << ".ALTERNATING.";
			}
			else if( m_enum == ENUM_DIRECT )
			{
				stream << ".DIRECT.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcElectricCurrentEnum> IfcElectricCurrentEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcElectricCurrentEnum>(); }
			shared_ptr<IfcElectricCurrentEnum> type_object( new IfcElectricCurrentEnum() );
			if( _stricmp( arg.c_str(), ".ALTERNATING." ) == 0 )
			{
				type_object->m_enum = IfcElectricCurrentEnum::ENUM_ALTERNATING;
			}
			else if( _stricmp( arg.c_str(), ".DIRECT." ) == 0 )
			{
				type_object->m_enum = IfcElectricCurrentEnum::ENUM_DIRECT;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcElectricCurrentEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

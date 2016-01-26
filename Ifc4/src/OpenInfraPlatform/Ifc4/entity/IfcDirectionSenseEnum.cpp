/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "OpenInfraPlatform/Ifc4/writer/WriterUtil.h"
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "include/IfcDirectionSenseEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcDirectionSenseEnum 
		IfcDirectionSenseEnum::IfcDirectionSenseEnum() {}
		IfcDirectionSenseEnum::~IfcDirectionSenseEnum() {}
		void IfcDirectionSenseEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCDIRECTIONSENSEENUM("; }
			if( m_enum == ENUM_POSITIVE )
			{
				stream << ".POSITIVE.";
			}
			else if( m_enum == ENUM_NEGATIVE )
			{
				stream << ".NEGATIVE.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcDirectionSenseEnum> IfcDirectionSenseEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcDirectionSenseEnum>(); }
			shared_ptr<IfcDirectionSenseEnum> type_object( new IfcDirectionSenseEnum() );
			if( _stricmp( arg.c_str(), ".POSITIVE." ) == 0 )
			{
				type_object->m_enum = IfcDirectionSenseEnum::ENUM_POSITIVE;
			}
			else if( _stricmp( arg.c_str(), ".NEGATIVE." ) == 0 )
			{
				type_object->m_enum = IfcDirectionSenseEnum::ENUM_NEGATIVE;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

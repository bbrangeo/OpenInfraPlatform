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
#include "include/IfcDimensionExtentUsage.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcDimensionExtentUsage 
		IfcDimensionExtentUsage::IfcDimensionExtentUsage() {}
		IfcDimensionExtentUsage::~IfcDimensionExtentUsage() {}
		void IfcDimensionExtentUsage::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCDIMENSIONEXTENTUSAGE("; }
			if( m_enum == ENUM_ORIGIN )
			{
				stream << ".ORIGIN.";
			}
			else if( m_enum == ENUM_TARGET )
			{
				stream << ".TARGET.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcDimensionExtentUsage> IfcDimensionExtentUsage::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcDimensionExtentUsage>(); }
			shared_ptr<IfcDimensionExtentUsage> type_object( new IfcDimensionExtentUsage() );
			if( _stricmp( arg.c_str(), ".ORIGIN." ) == 0 )
			{
				type_object->m_enum = IfcDimensionExtentUsage::ENUM_ORIGIN;
			}
			else if( _stricmp( arg.c_str(), ".TARGET." ) == 0 )
			{
				type_object->m_enum = IfcDimensionExtentUsage::ENUM_TARGET;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

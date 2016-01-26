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
#include "include/IfcTimeSeriesDataTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcTimeSeriesDataTypeEnum 
		IfcTimeSeriesDataTypeEnum::IfcTimeSeriesDataTypeEnum() {}
		IfcTimeSeriesDataTypeEnum::~IfcTimeSeriesDataTypeEnum() {}
		void IfcTimeSeriesDataTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCTIMESERIESDATATYPEENUM("; }
			if( m_enum == ENUM_CONTINUOUS )
			{
				stream << ".CONTINUOUS.";
			}
			else if( m_enum == ENUM_DISCRETE )
			{
				stream << ".DISCRETE.";
			}
			else if( m_enum == ENUM_DISCRETEBINARY )
			{
				stream << ".DISCRETEBINARY.";
			}
			else if( m_enum == ENUM_PIECEWISEBINARY )
			{
				stream << ".PIECEWISEBINARY.";
			}
			else if( m_enum == ENUM_PIECEWISECONSTANT )
			{
				stream << ".PIECEWISECONSTANT.";
			}
			else if( m_enum == ENUM_PIECEWISECONTINUOUS )
			{
				stream << ".PIECEWISECONTINUOUS.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcTimeSeriesDataTypeEnum> IfcTimeSeriesDataTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcTimeSeriesDataTypeEnum>(); }
			shared_ptr<IfcTimeSeriesDataTypeEnum> type_object( new IfcTimeSeriesDataTypeEnum() );
			if( _stricmp( arg.c_str(), ".CONTINUOUS." ) == 0 )
			{
				type_object->m_enum = IfcTimeSeriesDataTypeEnum::ENUM_CONTINUOUS;
			}
			else if( _stricmp( arg.c_str(), ".DISCRETE." ) == 0 )
			{
				type_object->m_enum = IfcTimeSeriesDataTypeEnum::ENUM_DISCRETE;
			}
			else if( _stricmp( arg.c_str(), ".DISCRETEBINARY." ) == 0 )
			{
				type_object->m_enum = IfcTimeSeriesDataTypeEnum::ENUM_DISCRETEBINARY;
			}
			else if( _stricmp( arg.c_str(), ".PIECEWISEBINARY." ) == 0 )
			{
				type_object->m_enum = IfcTimeSeriesDataTypeEnum::ENUM_PIECEWISEBINARY;
			}
			else if( _stricmp( arg.c_str(), ".PIECEWISECONSTANT." ) == 0 )
			{
				type_object->m_enum = IfcTimeSeriesDataTypeEnum::ENUM_PIECEWISECONSTANT;
			}
			else if( _stricmp( arg.c_str(), ".PIECEWISECONTINUOUS." ) == 0 )
			{
				type_object->m_enum = IfcTimeSeriesDataTypeEnum::ENUM_PIECEWISECONTINUOUS;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcTimeSeriesDataTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

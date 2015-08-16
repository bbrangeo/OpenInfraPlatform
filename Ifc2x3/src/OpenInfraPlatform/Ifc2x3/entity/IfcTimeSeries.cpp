/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/Ifc2x3Exception.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "Ifc2x3EntityEnums.h"
#include "include/IfcDataOriginEnum.h"
#include "include/IfcDateTimeSelect.h"
#include "include/IfcLabel.h"
#include "include/IfcText.h"
#include "include/IfcTimeSeries.h"
#include "include/IfcTimeSeriesDataTypeEnum.h"
#include "include/IfcTimeSeriesReferenceRelationship.h"
#include "include/IfcUnit.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcTimeSeries 
		IfcTimeSeries::IfcTimeSeries() { m_entity_enum = IFCTIMESERIES; }
		IfcTimeSeries::IfcTimeSeries( int id ) { m_id = id; m_entity_enum = IFCTIMESERIES; }
		IfcTimeSeries::~IfcTimeSeries() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTimeSeries::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcTimeSeries> other = dynamic_pointer_cast<IfcTimeSeries>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_StartTime = other->m_StartTime;
			m_EndTime = other->m_EndTime;
			m_TimeSeriesDataType = other->m_TimeSeriesDataType;
			m_DataOrigin = other->m_DataOrigin;
			m_UserDefinedDataOrigin = other->m_UserDefinedDataOrigin;
			m_Unit = other->m_Unit;
		}
		void IfcTimeSeries::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTIMESERIES" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_StartTime ) { m_StartTime->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_EndTime ) { m_EndTime->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_TimeSeriesDataType ) { m_TimeSeriesDataType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_DataOrigin ) { m_DataOrigin->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_UserDefinedDataOrigin ) { m_UserDefinedDataOrigin->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Unit ) { m_Unit->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcTimeSeries::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTimeSeries::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<8 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTimeSeries, expecting 8, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>8 ){ std::cout << "Wrong parameter count for entity IfcTimeSeries, expecting 8, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			m_StartTime = IfcDateTimeSelect::readStepData( args[2], map );
			m_EndTime = IfcDateTimeSelect::readStepData( args[3], map );
			m_TimeSeriesDataType = IfcTimeSeriesDataTypeEnum::readStepData( args[4] );
			m_DataOrigin = IfcDataOriginEnum::readStepData( args[5] );
			m_UserDefinedDataOrigin = IfcLabel::readStepData( args[6] );
			m_Unit = IfcUnit::readStepData( args[7], map );
		}
		void IfcTimeSeries::setInverseCounterparts( shared_ptr<Ifc2x3Entity> )
		{
		}
		void IfcTimeSeries::unlinkSelf()
		{
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

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
#include "include/IfcIrregularTimeSeries.h"
#include "include/IfcIrregularTimeSeriesValue.h"
#include "include/IfcLabel.h"
#include "include/IfcText.h"
#include "include/IfcTimeSeriesDataTypeEnum.h"
#include "include/IfcTimeSeriesReferenceRelationship.h"
#include "include/IfcUnit.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcIrregularTimeSeries 
		IfcIrregularTimeSeries::IfcIrregularTimeSeries() { m_entity_enum = IFCIRREGULARTIMESERIES; }
		IfcIrregularTimeSeries::IfcIrregularTimeSeries( int id ) { m_id = id; m_entity_enum = IFCIRREGULARTIMESERIES; }
		IfcIrregularTimeSeries::~IfcIrregularTimeSeries() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcIrregularTimeSeries::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcIrregularTimeSeries> other = dynamic_pointer_cast<IfcIrregularTimeSeries>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_StartTime = other->m_StartTime;
			m_EndTime = other->m_EndTime;
			m_TimeSeriesDataType = other->m_TimeSeriesDataType;
			m_DataOrigin = other->m_DataOrigin;
			m_UserDefinedDataOrigin = other->m_UserDefinedDataOrigin;
			m_Unit = other->m_Unit;
			m_Values = other->m_Values;
		}
		void IfcIrregularTimeSeries::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCIRREGULARTIMESERIES" << "(";
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
			stream << ",";
			writeEntityList( stream, m_Values );
			stream << ");";
		}
		void IfcIrregularTimeSeries::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcIrregularTimeSeries::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<9 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcIrregularTimeSeries, expecting 9, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>9 ){ std::cout << "Wrong parameter count for entity IfcIrregularTimeSeries, expecting 9, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			m_StartTime = IfcDateTimeSelect::readStepData( args[2], map );
			m_EndTime = IfcDateTimeSelect::readStepData( args[3], map );
			m_TimeSeriesDataType = IfcTimeSeriesDataTypeEnum::readStepData( args[4] );
			m_DataOrigin = IfcDataOriginEnum::readStepData( args[5] );
			m_UserDefinedDataOrigin = IfcLabel::readStepData( args[6] );
			m_Unit = IfcUnit::readStepData( args[7], map );
			readEntityReferenceList( args[8], m_Values, map );
		}
		void IfcIrregularTimeSeries::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcTimeSeries::setInverseCounterparts( ptr_self_entity );
		}
		void IfcIrregularTimeSeries::unlinkSelf()
		{
			IfcTimeSeries::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

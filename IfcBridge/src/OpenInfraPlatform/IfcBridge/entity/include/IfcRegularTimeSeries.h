/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
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
#include "../../model/IfcBridgeObject.h"
#include "IfcTimeSeries.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		class IfcTimeMeasure;
		class IfcTimeSeriesValue;
		//ENTITY
		class IfcRegularTimeSeries : public IfcTimeSeries
		{
		public:
			IfcRegularTimeSeries();
			IfcRegularTimeSeries( int id );
			~IfcRegularTimeSeries();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcBridgeEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcRegularTimeSeries"; }


			// IfcTimeSeries -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>							m_Name;
			//  shared_ptr<IfcText>							m_Description;				//optional
			//  shared_ptr<IfcDateTime>						m_StartTime;
			//  shared_ptr<IfcDateTime>						m_EndTime;
			//  shared_ptr<IfcTimeSeriesDataTypeEnum>		m_TimeSeriesDataType;
			//  shared_ptr<IfcDataOriginEnum>				m_DataOrigin;
			//  shared_ptr<IfcLabel>							m_UserDefinedDataOrigin;	//optional
			//  shared_ptr<IfcUnit>							m_Unit;						//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcExternalReferenceRelationship> >	m_HasExternalReference_inverse;

			// IfcRegularTimeSeries -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcTimeMeasure>					m_TimeStep;
			std::vector<shared_ptr<IfcTimeSeriesValue> >	m_Values;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform


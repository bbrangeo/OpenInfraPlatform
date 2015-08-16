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
#include "IfcMetricValueSelect.h"
#include "IfcObjectReferenceSelect.h"
#include "IfcResourceObjectSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		class IfcLabel;
		class IfcText;
		class IfcDateTime;
		class IfcTimeSeriesDataTypeEnum;
		class IfcDataOriginEnum;
		class IfcUnit;
		class IfcExternalReferenceRelationship;
		//ENTITY
		class IfcTimeSeries : public IfcMetricValueSelect, public IfcObjectReferenceSelect, public IfcResourceObjectSelect, public IfcTunnelEntity
		{
		public:
			IfcTimeSeries();
			IfcTimeSeries( int id );
			~IfcTimeSeries();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcTunnelEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcTimeSeries"; }


			// IfcTimeSeries -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcLabel>										m_Name;
			shared_ptr<IfcText>										m_Description;				//optional
			shared_ptr<IfcDateTime>									m_StartTime;
			shared_ptr<IfcDateTime>									m_EndTime;
			shared_ptr<IfcTimeSeriesDataTypeEnum>					m_TimeSeriesDataType;
			shared_ptr<IfcDataOriginEnum>							m_DataOrigin;
			shared_ptr<IfcLabel>										m_UserDefinedDataOrigin;	//optional
			shared_ptr<IfcUnit>										m_Unit;						//optional
			// inverse attributes:
			std::vector<weak_ptr<IfcExternalReferenceRelationship> >	m_HasExternalReference_inverse;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform


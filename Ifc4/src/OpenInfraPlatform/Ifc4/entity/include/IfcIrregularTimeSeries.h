/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Object.h"
#include "IfcTimeSeries.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		class IfcIrregularTimeSeriesValue;
		//ENTITY
		class IfcIrregularTimeSeries : public IfcTimeSeries
		{
		public:
			IfcIrregularTimeSeries();
			IfcIrregularTimeSeries( int id );
			~IfcIrregularTimeSeries();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc4Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcIrregularTimeSeries"; }


			// IfcTimeSeries -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>										m_Name;
			//  shared_ptr<IfcText>										m_Description;				//optional
			//  shared_ptr<IfcDateTime>									m_StartTime;
			//  shared_ptr<IfcDateTime>									m_EndTime;
			//  shared_ptr<IfcTimeSeriesDataTypeEnum>					m_TimeSeriesDataType;
			//  shared_ptr<IfcDataOriginEnum>							m_DataOrigin;
			//  shared_ptr<IfcLabel>										m_UserDefinedDataOrigin;	//optional
			//  shared_ptr<IfcUnit>										m_Unit;						//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcExternalReferenceRelationship> >	m_HasExternalReference_inverse;

			// IfcIrregularTimeSeries -----------------------------------------------------------
			// attributes:
			std::vector<shared_ptr<IfcIrregularTimeSeriesValue> >	m_Values;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform


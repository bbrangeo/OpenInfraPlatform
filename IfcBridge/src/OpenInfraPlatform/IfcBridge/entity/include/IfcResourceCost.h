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

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		class IfcLabel;
		class IfcDataOriginEnum;
		class IfcDateTime;
		class IfcMonetaryMeasure;
		//ENTITY
		class IfcResourceCost : public IfcBridgeEntity
		{
		public:
			IfcResourceCost();
			IfcResourceCost( int id );
			~IfcResourceCost();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcBridgeEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcResourceCost"; }


			// IfcResourceCost -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcLabel>							m_Name;						//optional
			shared_ptr<IfcDataOriginEnum>				m_DataOrigin;				//optional
			shared_ptr<IfcLabel>							m_UserDefinedDataOrigin;	//optional
			shared_ptr<IfcDateTime>						m_StatusDate;				//optional
			shared_ptr<IfcMonetaryMeasure>				m_ScheduleCost;				//optional
			shared_ptr<IfcMonetaryMeasure>				m_ActualCost;				//optional
			shared_ptr<IfcMonetaryMeasure>				m_RemainingCost;			//optional
			shared_ptr<IfcMonetaryMeasure>				m_PlannedValue;				//optional
			shared_ptr<IfcMonetaryMeasure>				m_EarnedValue;				//optional
			shared_ptr<IfcMonetaryMeasure>				m_ActualValue;				//optional
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform


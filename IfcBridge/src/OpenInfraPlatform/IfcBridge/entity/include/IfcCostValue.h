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
#include "IfcMetricValueSelect.h"
#include "IfcAppliedValue.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		class IfcLabel;
		class IfcText;
		//ENTITY
		class IfcCostValue : public IfcMetricValueSelect, public IfcAppliedValue
		{
		public:
			IfcCostValue();
			IfcCostValue( int id );
			~IfcCostValue();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcBridgeEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcCostValue"; }


			// IfcAppliedValue -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>							m_Name;						//optional
			//  shared_ptr<IfcText>							m_Description;				//optional
			//  shared_ptr<IfcAppliedValueSelect>			m_AppliedValue;				//optional
			//  shared_ptr<IfcMeasureWithUnit>				m_UnitBasis;				//optional
			//  shared_ptr<IfcDate>							m_ApplicableDate;			//optional
			//  shared_ptr<IfcDate>							m_FixedUntilDate;			//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcExternalReferenceRelationship> >	m_HasExternalReference_inverse;
			//  std::vector<weak_ptr<IfcAppliedValueRelationship> >	m_ValueOfComponents_inverse;
			//  std::vector<weak_ptr<IfcAppliedValueRelationship> >	m_IsComponentIn_inverse;

			// IfcCostValue -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcLabel>							m_CostType;
			shared_ptr<IfcText>							m_Condition;				//optional
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform


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
		class IfcAppliedValueSelect;
		class IfcMeasureWithUnit;
		class IfcDate;
		class IfcArithmeticOperatorEnum;
		class IfcAppliedValue;
		class IfcExternalReferenceRelationship;
		//ENTITY
		class IfcAppliedValue : public IfcMetricValueSelect, public IfcObjectReferenceSelect, public IfcResourceObjectSelect, public IfcTunnelEntity
		{
		public:
			IfcAppliedValue();
			IfcAppliedValue( int id );
			~IfcAppliedValue();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcTunnelEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcAppliedValue"; }


			// IfcAppliedValue -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcLabel>										m_Name;						//optional
			shared_ptr<IfcText>										m_Description;				//optional
			shared_ptr<IfcAppliedValueSelect>						m_AppliedValue;				//optional
			shared_ptr<IfcMeasureWithUnit>							m_UnitBasis;				//optional
			shared_ptr<IfcDate>										m_ApplicableDate;			//optional
			shared_ptr<IfcDate>										m_FixedUntilDate;			//optional
			shared_ptr<IfcLabel>										m_Category;					//optional
			shared_ptr<IfcLabel>										m_Condition;				//optional
			shared_ptr<IfcArithmeticOperatorEnum>					m_ArithmeticOperator;		//optional
			std::vector<shared_ptr<IfcAppliedValue> >				m_Components;				//optional
			// inverse attributes:
			std::vector<weak_ptr<IfcExternalReferenceRelationship> >	m_HasExternalReference_inverse;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform


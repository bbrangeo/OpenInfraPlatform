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
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadObject.h"
#include "IfcAppliedValue.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		//ENTITY
		class IfcCostValue : public IfcAppliedValue
		{
		public:
			IfcCostValue();
			IfcCostValue( int id );
			~IfcCostValue();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcRoadEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
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
			//  shared_ptr<IfcLabel>							m_Category;					//optional
			//  shared_ptr<IfcLabel>							m_Condition;				//optional
			//  shared_ptr<IfcArithmeticOperatorEnum>		m_ArithmeticOperator;		//optional
			//  std::vector<shared_ptr<IfcAppliedValue> >	m_Components;				//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcExternalReferenceRelationship> >	m_HasExternalReference_inverse;

			// IfcCostValue -----------------------------------------------------------
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform


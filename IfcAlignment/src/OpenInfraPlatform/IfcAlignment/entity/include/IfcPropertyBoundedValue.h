/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Object.h"
#include "IfcSimpleProperty.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcValue;
		class IfcUnit;
		//ENTITY
		class IfcPropertyBoundedValue : public IfcSimpleProperty
		{
		public:
			IfcPropertyBoundedValue();
			IfcPropertyBoundedValue( int id );
			~IfcPropertyBoundedValue();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcPropertyBoundedValue"; }


			// IfcPropertyAbstraction -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcExternalReferenceRelationship> >	m_HasExternalReferences_inverse;

			// IfcProperty -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcIdentifier>					m_Name;
			//  shared_ptr<IfcText>							m_Description;				//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcPropertySet> >		m_PartOfPset_inverse;
			//  std::vector<weak_ptr<IfcResourceApprovalRelationship> >	m_HasApprovals_inverse;
			//  std::vector<weak_ptr<IfcResourceConstraintRelationship> >	m_HasConstraints_inverse;
			//  std::vector<weak_ptr<IfcPropertyDependencyRelationship> >	m_PropertyForDependance_inverse;
			//  std::vector<weak_ptr<IfcPropertyDependencyRelationship> >	m_PropertyDependsOn_inverse;
			//  std::vector<weak_ptr<IfcComplexProperty> >	m_PartOfComplex_inverse;

			// IfcSimpleProperty -----------------------------------------------------------

			// IfcPropertyBoundedValue -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcValue>							m_UpperBoundValue;			//optional
			shared_ptr<IfcValue>							m_LowerBoundValue;			//optional
			shared_ptr<IfcUnit>							m_Unit;						//optional
			shared_ptr<IfcValue>							m_SetPointValue;			//optional
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform


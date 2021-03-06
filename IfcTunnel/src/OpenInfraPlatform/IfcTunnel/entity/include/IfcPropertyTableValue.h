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
#include "IfcSimpleProperty.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		class IfcValue;
		class IfcText;
		class IfcUnit;
		class IfcCurveInterpolationEnum;
		//ENTITY
		class IfcPropertyTableValue : public IfcSimpleProperty
		{
		public:
			IfcPropertyTableValue();
			IfcPropertyTableValue( int id );
			~IfcPropertyTableValue();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcTunnelEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcPropertyTableValue"; }


			// IfcPropertyAbstraction -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcExternalReferenceRelationship> >	m_HasExternalReferences_inverse;

			// IfcProperty -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcIdentifier>					m_Name;
			//  shared_ptr<IfcText>							m_Description;				//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcPropertySet> >		m_PartOfPset_inverse;
			//  std::vector<weak_ptr<IfcPropertyDependencyRelationship> >	m_PropertyForDependance_inverse;
			//  std::vector<weak_ptr<IfcPropertyDependencyRelationship> >	m_PropertyDependsOn_inverse;
			//  std::vector<weak_ptr<IfcComplexProperty> >	m_PartOfComplex_inverse;

			// IfcSimpleProperty -----------------------------------------------------------

			// IfcPropertyTableValue -----------------------------------------------------------
			// attributes:
			std::vector<shared_ptr<IfcValue> >			m_DefiningValues;			//optional
			std::vector<shared_ptr<IfcValue> >			m_DefinedValues;			//optional
			shared_ptr<IfcText>							m_Expression;				//optional
			shared_ptr<IfcUnit>							m_DefiningUnit;				//optional
			shared_ptr<IfcUnit>							m_DefinedUnit;				//optional
			shared_ptr<IfcCurveInterpolationEnum>		m_CurveInterpolation;		//optional
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform


/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcTunnelException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcTunnelEntityEnums.h"
#include "include/IfcComplexProperty.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcIdentifier.h"
#include "include/IfcPropertyBoundedValue.h"
#include "include/IfcPropertyDependencyRelationship.h"
#include "include/IfcPropertySet.h"
#include "include/IfcText.h"
#include "include/IfcUnit.h"
#include "include/IfcValue.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcPropertyBoundedValue 
		IfcPropertyBoundedValue::IfcPropertyBoundedValue() { m_entity_enum = IFCPROPERTYBOUNDEDVALUE; }
		IfcPropertyBoundedValue::IfcPropertyBoundedValue( int id ) { m_id = id; m_entity_enum = IFCPROPERTYBOUNDEDVALUE; }
		IfcPropertyBoundedValue::~IfcPropertyBoundedValue() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPropertyBoundedValue::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcPropertyBoundedValue> other = dynamic_pointer_cast<IfcPropertyBoundedValue>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_UpperBoundValue = other->m_UpperBoundValue;
			m_LowerBoundValue = other->m_LowerBoundValue;
			m_Unit = other->m_Unit;
			m_SetPointValue = other->m_SetPointValue;
		}
		void IfcPropertyBoundedValue::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPROPERTYBOUNDEDVALUE" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_UpperBoundValue ) { m_UpperBoundValue->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_LowerBoundValue ) { m_LowerBoundValue->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_Unit ) { m_Unit->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_SetPointValue ) { m_SetPointValue->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcPropertyBoundedValue::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPropertyBoundedValue::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPropertyBoundedValue, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcPropertyBoundedValue, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcIdentifier::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			m_UpperBoundValue = IfcValue::readStepData( args[2], map );
			m_LowerBoundValue = IfcValue::readStepData( args[3], map );
			m_Unit = IfcUnit::readStepData( args[4], map );
			m_SetPointValue = IfcValue::readStepData( args[5], map );
		}
		void IfcPropertyBoundedValue::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcSimpleProperty::setInverseCounterparts( ptr_self_entity );
		}
		void IfcPropertyBoundedValue::unlinkSelf()
		{
			IfcSimpleProperty::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

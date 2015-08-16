/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcBridgeException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcBridgeEntityEnums.h"
#include "include/IfcComplexProperty.h"
#include "include/IfcCurveInterpolationEnum.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcIdentifier.h"
#include "include/IfcPropertyDependencyRelationship.h"
#include "include/IfcPropertySet.h"
#include "include/IfcPropertyTableValue.h"
#include "include/IfcText.h"
#include "include/IfcUnit.h"
#include "include/IfcValue.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcPropertyTableValue 
		IfcPropertyTableValue::IfcPropertyTableValue() { m_entity_enum = IFCPROPERTYTABLEVALUE; }
		IfcPropertyTableValue::IfcPropertyTableValue( int id ) { m_id = id; m_entity_enum = IFCPROPERTYTABLEVALUE; }
		IfcPropertyTableValue::~IfcPropertyTableValue() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPropertyTableValue::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcPropertyTableValue> other = dynamic_pointer_cast<IfcPropertyTableValue>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_DefiningValues = other->m_DefiningValues;
			m_DefinedValues = other->m_DefinedValues;
			m_Expression = other->m_Expression;
			m_DefiningUnit = other->m_DefiningUnit;
			m_DefinedUnit = other->m_DefinedUnit;
			m_CurveInterpolation = other->m_CurveInterpolation;
		}
		void IfcPropertyTableValue::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPROPERTYTABLEVALUE" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeTypeList( stream, m_DefiningValues, true );
			stream << ",";
			writeTypeList( stream, m_DefinedValues, true );
			stream << ",";
			if( m_Expression ) { m_Expression->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_DefiningUnit ) { m_DefiningUnit->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_DefinedUnit ) { m_DefinedUnit->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_CurveInterpolation ) { m_CurveInterpolation->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcPropertyTableValue::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPropertyTableValue::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<8 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPropertyTableValue, expecting 8, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>8 ){ std::cout << "Wrong parameter count for entity IfcPropertyTableValue, expecting 8, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcIdentifier::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			readSelectList( args[2], m_DefiningValues, map );
			readSelectList( args[3], m_DefinedValues, map );
			m_Expression = IfcText::readStepData( args[4] );
			m_DefiningUnit = IfcUnit::readStepData( args[5], map );
			m_DefinedUnit = IfcUnit::readStepData( args[6], map );
			m_CurveInterpolation = IfcCurveInterpolationEnum::readStepData( args[7] );
		}
		void IfcPropertyTableValue::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcSimpleProperty::setInverseCounterparts( ptr_self_entity );
		}
		void IfcPropertyTableValue::unlinkSelf()
		{
			IfcSimpleProperty::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

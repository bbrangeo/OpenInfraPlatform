/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/IfcAlignmentP6EntityEnums.h"
#include "include/IfcComplexProperty.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcIdentifier.h"
#include "include/IfcPropertyDependencyRelationship.h"
#include "include/IfcPropertyEnumeratedValue.h"
#include "include/IfcPropertyEnumeration.h"
#include "include/IfcPropertySet.h"
#include "include/IfcResourceApprovalRelationship.h"
#include "include/IfcResourceConstraintRelationship.h"
#include "include/IfcText.h"
#include "include/IfcValue.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcPropertyEnumeratedValue 
		IfcPropertyEnumeratedValue::IfcPropertyEnumeratedValue() { m_entity_enum = IFCPROPERTYENUMERATEDVALUE; }
		IfcPropertyEnumeratedValue::IfcPropertyEnumeratedValue( int id ) { m_id = id; m_entity_enum = IFCPROPERTYENUMERATEDVALUE; }
		IfcPropertyEnumeratedValue::~IfcPropertyEnumeratedValue() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPropertyEnumeratedValue::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcPropertyEnumeratedValue> other = dynamic_pointer_cast<IfcPropertyEnumeratedValue>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_EnumerationValues = other->m_EnumerationValues;
			m_EnumerationReference = other->m_EnumerationReference;
		}
		void IfcPropertyEnumeratedValue::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPROPERTYENUMERATEDVALUE" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeTypeList( stream, m_EnumerationValues, true );
			stream << ",";
			if( m_EnumerationReference ) { stream << "#" << m_EnumerationReference->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcPropertyEnumeratedValue::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPropertyEnumeratedValue::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPropertyEnumeratedValue, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcPropertyEnumeratedValue, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcIdentifier::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			readSelectList( args[2], m_EnumerationValues, map );
			readEntityReference( args[3], m_EnumerationReference, map );
		}
		void IfcPropertyEnumeratedValue::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcSimpleProperty::setInverseCounterparts( ptr_self_entity );
		}
		void IfcPropertyEnumeratedValue::unlinkSelf()
		{
			IfcSimpleProperty::unlinkSelf();
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

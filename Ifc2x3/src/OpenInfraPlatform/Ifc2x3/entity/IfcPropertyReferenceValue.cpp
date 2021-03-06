/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/Ifc2x3Exception.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "Ifc2x3EntityEnums.h"
#include "include/IfcComplexProperty.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcObjectReferenceSelect.h"
#include "include/IfcPropertyDependencyRelationship.h"
#include "include/IfcPropertyReferenceValue.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcPropertyReferenceValue 
		IfcPropertyReferenceValue::IfcPropertyReferenceValue() { m_entity_enum = IFCPROPERTYREFERENCEVALUE; }
		IfcPropertyReferenceValue::IfcPropertyReferenceValue( int id ) { m_id = id; m_entity_enum = IFCPROPERTYREFERENCEVALUE; }
		IfcPropertyReferenceValue::~IfcPropertyReferenceValue() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPropertyReferenceValue::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcPropertyReferenceValue> other = dynamic_pointer_cast<IfcPropertyReferenceValue>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_UsageName = other->m_UsageName;
			m_PropertyReference = other->m_PropertyReference;
		}
		void IfcPropertyReferenceValue::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPROPERTYREFERENCEVALUE" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_UsageName ) { m_UsageName->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_PropertyReference ) { m_PropertyReference->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcPropertyReferenceValue::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPropertyReferenceValue::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPropertyReferenceValue, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcPropertyReferenceValue, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcIdentifier::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			m_UsageName = IfcLabel::readStepData( args[2] );
			m_PropertyReference = IfcObjectReferenceSelect::readStepData( args[3], map );
		}
		void IfcPropertyReferenceValue::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcSimpleProperty::setInverseCounterparts( ptr_self_entity );
		}
		void IfcPropertyReferenceValue::unlinkSelf()
		{
			IfcSimpleProperty::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

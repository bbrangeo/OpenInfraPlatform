/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "OpenInfraPlatform/Ifc4/writer/WriterUtil.h"
#include "OpenInfraPlatform/Ifc4/Ifc4EntityEnums.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcPropertyEnumeration.h"
#include "include/IfcUnit.h"
#include "include/IfcValue.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcPropertyEnumeration 
		IfcPropertyEnumeration::IfcPropertyEnumeration() { m_entity_enum = IFCPROPERTYENUMERATION; }
		IfcPropertyEnumeration::IfcPropertyEnumeration( int id ) { m_id = id; m_entity_enum = IFCPROPERTYENUMERATION; }
		IfcPropertyEnumeration::~IfcPropertyEnumeration() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPropertyEnumeration::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcPropertyEnumeration> other = dynamic_pointer_cast<IfcPropertyEnumeration>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_EnumerationValues = other->m_EnumerationValues;
			m_Unit = other->m_Unit;
		}
		void IfcPropertyEnumeration::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPROPERTYENUMERATION" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeTypeList( stream, m_EnumerationValues, true );
			stream << ",";
			if( m_Unit ) { m_Unit->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcPropertyEnumeration::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPropertyEnumeration::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPropertyEnumeration, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcPropertyEnumeration, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			readSelectList( args[1], m_EnumerationValues, map );
			m_Unit = IfcUnit::readStepData( args[2], map );
		}
		void IfcPropertyEnumeration::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcPropertyAbstraction::setInverseCounterparts( ptr_self_entity );
		}
		void IfcPropertyEnumeration::unlinkSelf()
		{
			IfcPropertyAbstraction::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

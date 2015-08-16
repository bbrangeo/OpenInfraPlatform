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
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcReference.h"
#include "include/IfcTableColumn.h"
#include "include/IfcText.h"
#include "include/IfcUnit.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcTableColumn 
		IfcTableColumn::IfcTableColumn() { m_entity_enum = IFCTABLECOLUMN; }
		IfcTableColumn::IfcTableColumn( int id ) { m_id = id; m_entity_enum = IFCTABLECOLUMN; }
		IfcTableColumn::~IfcTableColumn() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTableColumn::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcTableColumn> other = dynamic_pointer_cast<IfcTableColumn>(other_entity);
			if( !other) { return; }
			m_Identifier = other->m_Identifier;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_Unit = other->m_Unit;
			m_ReferencePath = other->m_ReferencePath;
		}
		void IfcTableColumn::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTABLECOLUMN" << "(";
			if( m_Identifier ) { m_Identifier->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Unit ) { m_Unit->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_ReferencePath ) { stream << "#" << m_ReferencePath->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcTableColumn::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTableColumn::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTableColumn, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcTableColumn, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Identifier = IfcIdentifier::readStepData( args[0] );
			m_Name = IfcLabel::readStepData( args[1] );
			m_Description = IfcText::readStepData( args[2] );
			m_Unit = IfcUnit::readStepData( args[3], map );
			readEntityReference( args[4], m_ReferencePath, map );
		}
		void IfcTableColumn::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> )
		{
		}
		void IfcTableColumn::unlinkSelf()
		{
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

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
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcTableColumn.h"
#include "include/IfcText.h"
#include "include/IfcUnit.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcTableColumn 
		IfcTableColumn::IfcTableColumn() { m_entity_enum = IFCTABLECOLUMN; }
		IfcTableColumn::IfcTableColumn( int id ) { m_id = id; m_entity_enum = IFCTABLECOLUMN; }
		IfcTableColumn::~IfcTableColumn() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTableColumn::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcTableColumn> other = dynamic_pointer_cast<IfcTableColumn>(other_entity);
			if( !other) { return; }
			m_Identifier = other->m_Identifier;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_Unit = other->m_Unit;
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
			stream << ");";
		}
		void IfcTableColumn::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTableColumn::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTableColumn, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcTableColumn, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Identifier = IfcIdentifier::readStepData( args[0] );
			m_Name = IfcLabel::readStepData( args[1] );
			m_Description = IfcText::readStepData( args[2] );
			m_Unit = IfcUnit::readStepData( args[3], map );
		}
		void IfcTableColumn::setInverseCounterparts( shared_ptr<IfcBridgeEntity> )
		{
		}
		void IfcTableColumn::unlinkSelf()
		{
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

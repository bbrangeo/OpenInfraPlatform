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
#include "include/IfcCalendarDate.h"
#include "include/IfcClassification.h"
#include "include/IfcClassificationItem.h"
#include "include/IfcLabel.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcClassification 
		IfcClassification::IfcClassification() { m_entity_enum = IFCCLASSIFICATION; }
		IfcClassification::IfcClassification( int id ) { m_id = id; m_entity_enum = IFCCLASSIFICATION; }
		IfcClassification::~IfcClassification() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcClassification::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcClassification> other = dynamic_pointer_cast<IfcClassification>(other_entity);
			if( !other) { return; }
			m_Source = other->m_Source;
			m_Edition = other->m_Edition;
			m_EditionDate = other->m_EditionDate;
			m_Name = other->m_Name;
		}
		void IfcClassification::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCLASSIFICATION" << "(";
			if( m_Source ) { m_Source->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Edition ) { m_Edition->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_EditionDate ) { stream << "#" << m_EditionDate->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcClassification::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcClassification::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcClassification, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcClassification, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Source = IfcLabel::readStepData( args[0] );
			m_Edition = IfcLabel::readStepData( args[1] );
			readEntityReference( args[2], m_EditionDate, map );
			m_Name = IfcLabel::readStepData( args[3] );
		}
		void IfcClassification::setInverseCounterparts( shared_ptr<Ifc2x3Entity> )
		{
		}
		void IfcClassification::unlinkSelf()
		{
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

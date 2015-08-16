/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/IfcRoadEntityEnums.h"
#include "include/IfcApplication.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcOrganization.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcApplication 
		IfcApplication::IfcApplication() { m_entity_enum = IFCAPPLICATION; }
		IfcApplication::IfcApplication( int id ) { m_id = id; m_entity_enum = IFCAPPLICATION; }
		IfcApplication::~IfcApplication() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcApplication::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcApplication> other = dynamic_pointer_cast<IfcApplication>(other_entity);
			if( !other) { return; }
			m_ApplicationDeveloper = other->m_ApplicationDeveloper;
			m_Version = other->m_Version;
			m_ApplicationFullName = other->m_ApplicationFullName;
			m_ApplicationIdentifier = other->m_ApplicationIdentifier;
		}
		void IfcApplication::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCAPPLICATION" << "(";
			if( m_ApplicationDeveloper ) { stream << "#" << m_ApplicationDeveloper->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Version ) { m_Version->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ApplicationFullName ) { m_ApplicationFullName->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ApplicationIdentifier ) { m_ApplicationIdentifier->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcApplication::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcApplication::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcApplication, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcApplication, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_ApplicationDeveloper, map );
			m_Version = IfcLabel::readStepData( args[1] );
			m_ApplicationFullName = IfcLabel::readStepData( args[2] );
			m_ApplicationIdentifier = IfcIdentifier::readStepData( args[3] );
		}
		void IfcApplication::setInverseCounterparts( shared_ptr<IfcRoadEntity> )
		{
		}
		void IfcApplication::unlinkSelf()
		{
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

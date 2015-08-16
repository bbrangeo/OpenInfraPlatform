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
#include "include/IfcActorSelect.h"
#include "include/IfcDateTime.h"
#include "include/IfcLabel.h"
#include "include/IfcLibraryInformation.h"
#include "include/IfcLibraryReference.h"
#include "include/IfcRelAssociatesLibrary.h"
#include "include/IfcText.h"
#include "include/IfcURIReference.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcLibraryInformation 
		IfcLibraryInformation::IfcLibraryInformation() { m_entity_enum = IFCLIBRARYINFORMATION; }
		IfcLibraryInformation::IfcLibraryInformation( int id ) { m_id = id; m_entity_enum = IFCLIBRARYINFORMATION; }
		IfcLibraryInformation::~IfcLibraryInformation() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcLibraryInformation::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcLibraryInformation> other = dynamic_pointer_cast<IfcLibraryInformation>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Version = other->m_Version;
			m_Publisher = other->m_Publisher;
			m_VersionDate = other->m_VersionDate;
			m_Location = other->m_Location;
			m_Description = other->m_Description;
		}
		void IfcLibraryInformation::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCLIBRARYINFORMATION" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Version ) { m_Version->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Publisher ) { m_Publisher->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_VersionDate ) { m_VersionDate->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Location ) { m_Location->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcLibraryInformation::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcLibraryInformation::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcLibraryInformation, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcLibraryInformation, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_Version = IfcLabel::readStepData( args[1] );
			m_Publisher = IfcActorSelect::readStepData( args[2], map );
			m_VersionDate = IfcDateTime::readStepData( args[3] );
			m_Location = IfcURIReference::readStepData( args[4] );
			m_Description = IfcText::readStepData( args[5] );
		}
		void IfcLibraryInformation::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcExternalInformation::setInverseCounterparts( ptr_self_entity );
		}
		void IfcLibraryInformation::unlinkSelf()
		{
			IfcExternalInformation::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

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
#include "include/IfcDefinitionSelect.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcLibraryInformation.h"
#include "include/IfcLibraryReference.h"
#include "include/IfcLibrarySelect.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcRelAssociatesLibrary.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcRelAssociatesLibrary 
		IfcRelAssociatesLibrary::IfcRelAssociatesLibrary() { m_entity_enum = IFCRELASSOCIATESLIBRARY; }
		IfcRelAssociatesLibrary::IfcRelAssociatesLibrary( int id ) { m_id = id; m_entity_enum = IFCRELASSOCIATESLIBRARY; }
		IfcRelAssociatesLibrary::~IfcRelAssociatesLibrary() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRelAssociatesLibrary::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcRelAssociatesLibrary> other = dynamic_pointer_cast<IfcRelAssociatesLibrary>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_RelatedObjects = other->m_RelatedObjects;
			m_RelatingLibrary = other->m_RelatingLibrary;
		}
		void IfcRelAssociatesLibrary::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRELASSOCIATESLIBRARY" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeTypeList( stream, m_RelatedObjects, true );
			stream << ",";
			if( m_RelatingLibrary ) { m_RelatingLibrary->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcRelAssociatesLibrary::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRelAssociatesLibrary::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRelAssociatesLibrary, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcRelAssociatesLibrary, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			readSelectList( args[4], m_RelatedObjects, map );
			m_RelatingLibrary = IfcLibrarySelect::readStepData( args[5], map );
		}
		void IfcRelAssociatesLibrary::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcRelAssociates::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcRelAssociatesLibrary> ptr_self = dynamic_pointer_cast<IfcRelAssociatesLibrary>( ptr_self_entity );
			if( !ptr_self ) { throw Ifc4Exception( "IfcRelAssociatesLibrary::setInverseCounterparts: type mismatch" ); }
			shared_ptr<IfcLibraryInformation>  RelatingLibrary_IfcLibraryInformation = dynamic_pointer_cast<IfcLibraryInformation>( m_RelatingLibrary );
			if( RelatingLibrary_IfcLibraryInformation )
			{
				RelatingLibrary_IfcLibraryInformation->m_LibraryInfoForObjects_inverse.push_back( ptr_self );
			}
			shared_ptr<IfcLibraryReference>  RelatingLibrary_IfcLibraryReference = dynamic_pointer_cast<IfcLibraryReference>( m_RelatingLibrary );
			if( RelatingLibrary_IfcLibraryReference )
			{
				RelatingLibrary_IfcLibraryReference->m_LibraryRefForObjects_inverse.push_back( ptr_self );
			}
		}
		void IfcRelAssociatesLibrary::unlinkSelf()
		{
			IfcRelAssociates::unlinkSelf();
			shared_ptr<IfcLibraryInformation>  RelatingLibrary_IfcLibraryInformation = dynamic_pointer_cast<IfcLibraryInformation>( m_RelatingLibrary );
			if( RelatingLibrary_IfcLibraryInformation )
			{
				std::vector<weak_ptr<IfcRelAssociatesLibrary> >& LibraryInfoForObjects_inverse = RelatingLibrary_IfcLibraryInformation->m_LibraryInfoForObjects_inverse;
				std::vector<weak_ptr<IfcRelAssociatesLibrary> >::iterator it_LibraryInfoForObjects_inverse;
				for( it_LibraryInfoForObjects_inverse = LibraryInfoForObjects_inverse.begin(); it_LibraryInfoForObjects_inverse != LibraryInfoForObjects_inverse.end(); ++it_LibraryInfoForObjects_inverse)
				{
					shared_ptr<IfcRelAssociatesLibrary> self_candidate( *it_LibraryInfoForObjects_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						LibraryInfoForObjects_inverse.erase( it_LibraryInfoForObjects_inverse );
						break;
					}
				}
			}
			shared_ptr<IfcLibraryReference>  RelatingLibrary_IfcLibraryReference = dynamic_pointer_cast<IfcLibraryReference>( m_RelatingLibrary );
			if( RelatingLibrary_IfcLibraryReference )
			{
				std::vector<weak_ptr<IfcRelAssociatesLibrary> >& LibraryRefForObjects_inverse = RelatingLibrary_IfcLibraryReference->m_LibraryRefForObjects_inverse;
				std::vector<weak_ptr<IfcRelAssociatesLibrary> >::iterator it_LibraryRefForObjects_inverse;
				for( it_LibraryRefForObjects_inverse = LibraryRefForObjects_inverse.begin(); it_LibraryRefForObjects_inverse != LibraryRefForObjects_inverse.end(); ++it_LibraryRefForObjects_inverse)
				{
					shared_ptr<IfcRelAssociatesLibrary> self_candidate( *it_LibraryRefForObjects_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						LibraryRefForObjects_inverse.erase( it_LibraryRefForObjects_inverse );
						break;
					}
				}
			}
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

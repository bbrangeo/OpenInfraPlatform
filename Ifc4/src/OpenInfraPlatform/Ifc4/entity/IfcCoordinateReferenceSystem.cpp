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
#include "include/IfcCoordinateOperation.h"
#include "include/IfcCoordinateReferenceSystem.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcCoordinateReferenceSystem 
		IfcCoordinateReferenceSystem::IfcCoordinateReferenceSystem() { m_entity_enum = IFCCOORDINATEREFERENCESYSTEM; }
		IfcCoordinateReferenceSystem::IfcCoordinateReferenceSystem( int id ) { m_id = id; m_entity_enum = IFCCOORDINATEREFERENCESYSTEM; }
		IfcCoordinateReferenceSystem::~IfcCoordinateReferenceSystem() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCoordinateReferenceSystem::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcCoordinateReferenceSystem> other = dynamic_pointer_cast<IfcCoordinateReferenceSystem>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_GeodeticDatum = other->m_GeodeticDatum;
			m_VerticalDatum = other->m_VerticalDatum;
		}
		void IfcCoordinateReferenceSystem::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCOORDINATEREFERENCESYSTEM" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_GeodeticDatum ) { m_GeodeticDatum->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_VerticalDatum ) { m_VerticalDatum->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcCoordinateReferenceSystem::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCoordinateReferenceSystem::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCoordinateReferenceSystem, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcCoordinateReferenceSystem, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			m_GeodeticDatum = IfcIdentifier::readStepData( args[2] );
			m_VerticalDatum = IfcIdentifier::readStepData( args[3] );
		}
		void IfcCoordinateReferenceSystem::setInverseCounterparts( shared_ptr<Ifc4Entity> )
		{
		}
		void IfcCoordinateReferenceSystem::unlinkSelf()
		{
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

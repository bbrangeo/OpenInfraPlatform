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
#include "include/IfcLabel.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcStructuralLoadConfiguration.h"
#include "include/IfcStructuralLoadOrResult.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcStructuralLoadConfiguration 
		IfcStructuralLoadConfiguration::IfcStructuralLoadConfiguration() { m_entity_enum = IFCSTRUCTURALLOADCONFIGURATION; }
		IfcStructuralLoadConfiguration::IfcStructuralLoadConfiguration( int id ) { m_id = id; m_entity_enum = IFCSTRUCTURALLOADCONFIGURATION; }
		IfcStructuralLoadConfiguration::~IfcStructuralLoadConfiguration() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcStructuralLoadConfiguration::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcStructuralLoadConfiguration> other = dynamic_pointer_cast<IfcStructuralLoadConfiguration>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Values = other->m_Values;
			m_Locations = other->m_Locations;
		}
		void IfcStructuralLoadConfiguration::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSTRUCTURALLOADCONFIGURATION" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_Values );
			stream << ",";
			writeTypeOfRealList2D( stream, m_Locations );
			stream << ");";
		}
		void IfcStructuralLoadConfiguration::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcStructuralLoadConfiguration::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcStructuralLoadConfiguration, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcStructuralLoadConfiguration, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			readEntityReferenceList( args[1], m_Values, map );
			readTypeOfRealList2D( args[2], m_Locations );
		}
		void IfcStructuralLoadConfiguration::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcStructuralLoad::setInverseCounterparts( ptr_self_entity );
		}
		void IfcStructuralLoadConfiguration::unlinkSelf()
		{
			IfcStructuralLoad::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

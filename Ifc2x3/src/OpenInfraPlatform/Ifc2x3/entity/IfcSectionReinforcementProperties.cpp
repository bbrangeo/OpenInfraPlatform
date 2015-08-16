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
#include "include/IfcLengthMeasure.h"
#include "include/IfcReinforcementBarProperties.h"
#include "include/IfcReinforcingBarRoleEnum.h"
#include "include/IfcSectionProperties.h"
#include "include/IfcSectionReinforcementProperties.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcSectionReinforcementProperties 
		IfcSectionReinforcementProperties::IfcSectionReinforcementProperties() { m_entity_enum = IFCSECTIONREINFORCEMENTPROPERTIES; }
		IfcSectionReinforcementProperties::IfcSectionReinforcementProperties( int id ) { m_id = id; m_entity_enum = IFCSECTIONREINFORCEMENTPROPERTIES; }
		IfcSectionReinforcementProperties::~IfcSectionReinforcementProperties() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcSectionReinforcementProperties::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcSectionReinforcementProperties> other = dynamic_pointer_cast<IfcSectionReinforcementProperties>(other_entity);
			if( !other) { return; }
			m_LongitudinalStartPosition = other->m_LongitudinalStartPosition;
			m_LongitudinalEndPosition = other->m_LongitudinalEndPosition;
			m_TransversePosition = other->m_TransversePosition;
			m_ReinforcementRole = other->m_ReinforcementRole;
			m_SectionDefinition = other->m_SectionDefinition;
			m_CrossSectionReinforcementDefinitions = other->m_CrossSectionReinforcementDefinitions;
		}
		void IfcSectionReinforcementProperties::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSECTIONREINFORCEMENTPROPERTIES" << "(";
			if( m_LongitudinalStartPosition ) { m_LongitudinalStartPosition->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_LongitudinalEndPosition ) { m_LongitudinalEndPosition->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_TransversePosition ) { m_TransversePosition->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ReinforcementRole ) { m_ReinforcementRole->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_SectionDefinition ) { stream << "#" << m_SectionDefinition->getId(); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_CrossSectionReinforcementDefinitions );
			stream << ");";
		}
		void IfcSectionReinforcementProperties::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcSectionReinforcementProperties::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcSectionReinforcementProperties, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcSectionReinforcementProperties, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_LongitudinalStartPosition = IfcLengthMeasure::readStepData( args[0] );
			m_LongitudinalEndPosition = IfcLengthMeasure::readStepData( args[1] );
			m_TransversePosition = IfcLengthMeasure::readStepData( args[2] );
			m_ReinforcementRole = IfcReinforcingBarRoleEnum::readStepData( args[3] );
			readEntityReference( args[4], m_SectionDefinition, map );
			readEntityReferenceList( args[5], m_CrossSectionReinforcementDefinitions, map );
		}
		void IfcSectionReinforcementProperties::setInverseCounterparts( shared_ptr<Ifc2x3Entity> )
		{
		}
		void IfcSectionReinforcementProperties::unlinkSelf()
		{
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

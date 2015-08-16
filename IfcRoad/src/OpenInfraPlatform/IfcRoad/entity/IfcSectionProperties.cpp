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
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcProfileDef.h"
#include "include/IfcSectionProperties.h"
#include "include/IfcSectionTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcSectionProperties 
		IfcSectionProperties::IfcSectionProperties() { m_entity_enum = IFCSECTIONPROPERTIES; }
		IfcSectionProperties::IfcSectionProperties( int id ) { m_id = id; m_entity_enum = IFCSECTIONPROPERTIES; }
		IfcSectionProperties::~IfcSectionProperties() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcSectionProperties::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcSectionProperties> other = dynamic_pointer_cast<IfcSectionProperties>(other_entity);
			if( !other) { return; }
			m_SectionType = other->m_SectionType;
			m_StartProfile = other->m_StartProfile;
			m_EndProfile = other->m_EndProfile;
		}
		void IfcSectionProperties::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSECTIONPROPERTIES" << "(";
			if( m_SectionType ) { m_SectionType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_StartProfile ) { stream << "#" << m_StartProfile->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_EndProfile ) { stream << "#" << m_EndProfile->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcSectionProperties::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcSectionProperties::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcSectionProperties, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcSectionProperties, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_SectionType = IfcSectionTypeEnum::readStepData( args[0] );
			readEntityReference( args[1], m_StartProfile, map );
			readEntityReference( args[2], m_EndProfile, map );
		}
		void IfcSectionProperties::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcPreDefinedProperties::setInverseCounterparts( ptr_self_entity );
		}
		void IfcSectionProperties::unlinkSelf()
		{
			IfcPreDefinedProperties::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

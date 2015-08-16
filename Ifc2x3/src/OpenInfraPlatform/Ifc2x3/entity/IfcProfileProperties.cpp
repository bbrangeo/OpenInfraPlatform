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
#include "include/IfcLabel.h"
#include "include/IfcProfileDef.h"
#include "include/IfcProfileProperties.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcProfileProperties 
		IfcProfileProperties::IfcProfileProperties() { m_entity_enum = IFCPROFILEPROPERTIES; }
		IfcProfileProperties::IfcProfileProperties( int id ) { m_id = id; m_entity_enum = IFCPROFILEPROPERTIES; }
		IfcProfileProperties::~IfcProfileProperties() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcProfileProperties::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcProfileProperties> other = dynamic_pointer_cast<IfcProfileProperties>(other_entity);
			if( !other) { return; }
			m_ProfileName = other->m_ProfileName;
			m_ProfileDefinition = other->m_ProfileDefinition;
		}
		void IfcProfileProperties::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPROFILEPROPERTIES" << "(";
			if( m_ProfileName ) { m_ProfileName->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ProfileDefinition ) { stream << "#" << m_ProfileDefinition->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcProfileProperties::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcProfileProperties::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcProfileProperties, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcProfileProperties, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_ProfileName = IfcLabel::readStepData( args[0] );
			readEntityReference( args[1], m_ProfileDefinition, map );
		}
		void IfcProfileProperties::setInverseCounterparts( shared_ptr<Ifc2x3Entity> )
		{
		}
		void IfcProfileProperties::unlinkSelf()
		{
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

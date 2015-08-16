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
#include "include/IfcExtendedMaterialProperties.h"
#include "include/IfcLabel.h"
#include "include/IfcMaterial.h"
#include "include/IfcProperty.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcExtendedMaterialProperties 
		IfcExtendedMaterialProperties::IfcExtendedMaterialProperties() { m_entity_enum = IFCEXTENDEDMATERIALPROPERTIES; }
		IfcExtendedMaterialProperties::IfcExtendedMaterialProperties( int id ) { m_id = id; m_entity_enum = IFCEXTENDEDMATERIALPROPERTIES; }
		IfcExtendedMaterialProperties::~IfcExtendedMaterialProperties() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcExtendedMaterialProperties::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcExtendedMaterialProperties> other = dynamic_pointer_cast<IfcExtendedMaterialProperties>(other_entity);
			if( !other) { return; }
			m_Material = other->m_Material;
			m_ExtendedProperties = other->m_ExtendedProperties;
			m_Description = other->m_Description;
			m_Name = other->m_Name;
		}
		void IfcExtendedMaterialProperties::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCEXTENDEDMATERIALPROPERTIES" << "(";
			if( m_Material ) { stream << "#" << m_Material->getId(); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_ExtendedProperties );
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcExtendedMaterialProperties::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcExtendedMaterialProperties::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcExtendedMaterialProperties, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcExtendedMaterialProperties, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Material, map );
			readEntityReferenceList( args[1], m_ExtendedProperties, map );
			m_Description = IfcText::readStepData( args[2] );
			m_Name = IfcLabel::readStepData( args[3] );
		}
		void IfcExtendedMaterialProperties::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcMaterialProperties::setInverseCounterparts( ptr_self_entity );
		}
		void IfcExtendedMaterialProperties::unlinkSelf()
		{
			IfcMaterialProperties::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

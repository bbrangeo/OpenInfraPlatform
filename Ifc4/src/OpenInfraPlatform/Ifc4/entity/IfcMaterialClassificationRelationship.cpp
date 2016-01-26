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
#include "include/IfcClassificationSelect.h"
#include "include/IfcMaterial.h"
#include "include/IfcMaterialClassificationRelationship.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcMaterialClassificationRelationship 
		IfcMaterialClassificationRelationship::IfcMaterialClassificationRelationship() { m_entity_enum = IFCMATERIALCLASSIFICATIONRELATIONSHIP; }
		IfcMaterialClassificationRelationship::IfcMaterialClassificationRelationship( int id ) { m_id = id; m_entity_enum = IFCMATERIALCLASSIFICATIONRELATIONSHIP; }
		IfcMaterialClassificationRelationship::~IfcMaterialClassificationRelationship() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcMaterialClassificationRelationship::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcMaterialClassificationRelationship> other = dynamic_pointer_cast<IfcMaterialClassificationRelationship>(other_entity);
			if( !other) { return; }
			m_MaterialClassifications = other->m_MaterialClassifications;
			m_ClassifiedMaterial = other->m_ClassifiedMaterial;
		}
		void IfcMaterialClassificationRelationship::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCMATERIALCLASSIFICATIONRELATIONSHIP" << "(";
			writeTypeList( stream, m_MaterialClassifications, true );
			stream << ",";
			if( m_ClassifiedMaterial ) { stream << "#" << m_ClassifiedMaterial->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcMaterialClassificationRelationship::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcMaterialClassificationRelationship::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcMaterialClassificationRelationship, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcMaterialClassificationRelationship, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readSelectList( args[0], m_MaterialClassifications, map );
			readEntityReference( args[1], m_ClassifiedMaterial, map );
		}
		void IfcMaterialClassificationRelationship::setInverseCounterparts( shared_ptr<Ifc4Entity> )
		{
		}
		void IfcMaterialClassificationRelationship::unlinkSelf()
		{
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

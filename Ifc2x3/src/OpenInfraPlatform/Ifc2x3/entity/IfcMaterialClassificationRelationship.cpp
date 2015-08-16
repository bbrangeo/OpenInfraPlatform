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
#include "include/IfcClassificationNotationSelect.h"
#include "include/IfcMaterial.h"
#include "include/IfcMaterialClassificationRelationship.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcMaterialClassificationRelationship 
		IfcMaterialClassificationRelationship::IfcMaterialClassificationRelationship() { m_entity_enum = IFCMATERIALCLASSIFICATIONRELATIONSHIP; }
		IfcMaterialClassificationRelationship::IfcMaterialClassificationRelationship( int id ) { m_id = id; m_entity_enum = IFCMATERIALCLASSIFICATIONRELATIONSHIP; }
		IfcMaterialClassificationRelationship::~IfcMaterialClassificationRelationship() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcMaterialClassificationRelationship::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
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
		void IfcMaterialClassificationRelationship::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcMaterialClassificationRelationship, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcMaterialClassificationRelationship, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readSelectList( args[0], m_MaterialClassifications, map );
			readEntityReference( args[1], m_ClassifiedMaterial, map );
		}
		void IfcMaterialClassificationRelationship::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			shared_ptr<IfcMaterialClassificationRelationship> ptr_self = dynamic_pointer_cast<IfcMaterialClassificationRelationship>( ptr_self_entity );
			if( !ptr_self ) { throw Ifc2x3Exception( "IfcMaterialClassificationRelationship::setInverseCounterparts: type mismatch" ); }
			if( m_ClassifiedMaterial )
			{
				m_ClassifiedMaterial->m_ClassifiedAs_inverse.push_back( ptr_self );
			}
		}
		void IfcMaterialClassificationRelationship::unlinkSelf()
		{
			if( m_ClassifiedMaterial )
			{
				std::vector<weak_ptr<IfcMaterialClassificationRelationship> >& ClassifiedAs_inverse = m_ClassifiedMaterial->m_ClassifiedAs_inverse;
				std::vector<weak_ptr<IfcMaterialClassificationRelationship> >::iterator it_ClassifiedAs_inverse;
				for( it_ClassifiedAs_inverse = ClassifiedAs_inverse.begin(); it_ClassifiedAs_inverse != ClassifiedAs_inverse.end(); ++it_ClassifiedAs_inverse)
				{
					shared_ptr<IfcMaterialClassificationRelationship> self_candidate( *it_ClassifiedAs_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						ClassifiedAs_inverse.erase( it_ClassifiedAs_inverse );
						break;
					}
				}
			}
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

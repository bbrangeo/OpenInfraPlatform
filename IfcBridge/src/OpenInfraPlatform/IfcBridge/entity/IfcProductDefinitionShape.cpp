/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcBridgeException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcBridgeEntityEnums.h"
#include "include/IfcLabel.h"
#include "include/IfcProduct.h"
#include "include/IfcProductDefinitionShape.h"
#include "include/IfcRepresentation.h"
#include "include/IfcShapeAspect.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcProductDefinitionShape 
		IfcProductDefinitionShape::IfcProductDefinitionShape() { m_entity_enum = IFCPRODUCTDEFINITIONSHAPE; }
		IfcProductDefinitionShape::IfcProductDefinitionShape( int id ) { m_id = id; m_entity_enum = IFCPRODUCTDEFINITIONSHAPE; }
		IfcProductDefinitionShape::~IfcProductDefinitionShape() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcProductDefinitionShape::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcProductDefinitionShape> other = dynamic_pointer_cast<IfcProductDefinitionShape>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_Representations = other->m_Representations;
		}
		void IfcProductDefinitionShape::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPRODUCTDEFINITIONSHAPE" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_Representations );
			stream << ");";
		}
		void IfcProductDefinitionShape::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcProductDefinitionShape::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcProductDefinitionShape, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcProductDefinitionShape, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			readEntityReferenceList( args[2], m_Representations, map );
		}
		void IfcProductDefinitionShape::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcProductRepresentation::setInverseCounterparts( ptr_self_entity );
		}
		void IfcProductDefinitionShape::unlinkSelf()
		{
			IfcProductRepresentation::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

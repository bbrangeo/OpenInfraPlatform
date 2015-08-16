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
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcProductRepresentation.h"
#include "include/IfcRepresentationContext.h"
#include "include/IfcRepresentationItem.h"
#include "include/IfcRepresentationMap.h"
#include "include/IfcShapeAspect.h"
#include "include/IfcShapeRepresentation.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcShapeRepresentation 
		IfcShapeRepresentation::IfcShapeRepresentation() { m_entity_enum = IFCSHAPEREPRESENTATION; }
		IfcShapeRepresentation::IfcShapeRepresentation( int id ) { m_id = id; m_entity_enum = IFCSHAPEREPRESENTATION; }
		IfcShapeRepresentation::~IfcShapeRepresentation() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcShapeRepresentation::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcShapeRepresentation> other = dynamic_pointer_cast<IfcShapeRepresentation>(other_entity);
			if( !other) { return; }
			m_ContextOfItems = other->m_ContextOfItems;
			m_RepresentationIdentifier = other->m_RepresentationIdentifier;
			m_RepresentationType = other->m_RepresentationType;
			m_Items = other->m_Items;
		}
		void IfcShapeRepresentation::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSHAPEREPRESENTATION" << "(";
			if( m_ContextOfItems ) { stream << "#" << m_ContextOfItems->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_RepresentationIdentifier ) { m_RepresentationIdentifier->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RepresentationType ) { m_RepresentationType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_Items );
			stream << ");";
		}
		void IfcShapeRepresentation::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcShapeRepresentation::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcShapeRepresentation, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcShapeRepresentation, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_ContextOfItems, map );
			m_RepresentationIdentifier = IfcLabel::readStepData( args[1] );
			m_RepresentationType = IfcLabel::readStepData( args[2] );
			readEntityReferenceList( args[3], m_Items, map );
		}
		void IfcShapeRepresentation::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcShapeModel::setInverseCounterparts( ptr_self_entity );
		}
		void IfcShapeRepresentation::unlinkSelf()
		{
			IfcShapeModel::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

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
#include "include/IfcFace.h"
#include "include/IfcFaceBound.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcTextureMap.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcFace 
		IfcFace::IfcFace() { m_entity_enum = IFCFACE; }
		IfcFace::IfcFace( int id ) { m_id = id; m_entity_enum = IFCFACE; }
		IfcFace::~IfcFace() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcFace::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcFace> other = dynamic_pointer_cast<IfcFace>(other_entity);
			if( !other) { return; }
			m_Bounds = other->m_Bounds;
		}
		void IfcFace::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCFACE" << "(";
			writeEntityList( stream, m_Bounds );
			stream << ");";
		}
		void IfcFace::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcFace::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcFace, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcFace, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_Bounds, map );
		}
		void IfcFace::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcTopologicalRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcFace::unlinkSelf()
		{
			IfcTopologicalRepresentationItem::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

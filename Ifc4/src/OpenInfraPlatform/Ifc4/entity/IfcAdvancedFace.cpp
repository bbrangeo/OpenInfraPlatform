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
#include "include/IfcAdvancedFace.h"
#include "include/IfcBoolean.h"
#include "include/IfcFaceBound.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcSurface.h"
#include "include/IfcTextureMap.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcAdvancedFace 
		IfcAdvancedFace::IfcAdvancedFace() { m_entity_enum = IFCADVANCEDFACE; }
		IfcAdvancedFace::IfcAdvancedFace( int id ) { m_id = id; m_entity_enum = IFCADVANCEDFACE; }
		IfcAdvancedFace::~IfcAdvancedFace() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcAdvancedFace::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcAdvancedFace> other = dynamic_pointer_cast<IfcAdvancedFace>(other_entity);
			if( !other) { return; }
			m_Bounds = other->m_Bounds;
			m_FaceSurface = other->m_FaceSurface;
			m_SameSense = other->m_SameSense;
		}
		void IfcAdvancedFace::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCADVANCEDFACE" << "(";
			writeEntityList( stream, m_Bounds );
			stream << ",";
			if( m_FaceSurface ) { stream << "#" << m_FaceSurface->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_SameSense ) { m_SameSense->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcAdvancedFace::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcAdvancedFace::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcAdvancedFace, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcAdvancedFace, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_Bounds, map );
			readEntityReference( args[1], m_FaceSurface, map );
			m_SameSense = IfcBoolean::readStepData( args[2] );
		}
		void IfcAdvancedFace::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcFaceSurface::setInverseCounterparts( ptr_self_entity );
		}
		void IfcAdvancedFace::unlinkSelf()
		{
			IfcFaceSurface::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

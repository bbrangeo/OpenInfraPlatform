/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcTunnelException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcTunnelEntityEnums.h"
#include "include/IfcAdvancedFace.h"
#include "include/IfcFaceBound.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcSurface.h"
#include "include/IfcTextureMap.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcAdvancedFace 
		IfcAdvancedFace::IfcAdvancedFace() { m_entity_enum = IFCADVANCEDFACE; }
		IfcAdvancedFace::IfcAdvancedFace( int id ) { m_id = id; m_entity_enum = IFCADVANCEDFACE; }
		IfcAdvancedFace::~IfcAdvancedFace() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcAdvancedFace::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
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
			if( m_SameSense == false ) { stream << ".F."; }
			else if( m_SameSense == true ) { stream << ".T."; }
			stream << ");";
		}
		void IfcAdvancedFace::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcAdvancedFace::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcAdvancedFace, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcAdvancedFace, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_Bounds, map );
			readEntityReference( args[1], m_FaceSurface, map );
			if( _stricmp( args[2].c_str(), ".F." ) == 0 ) { m_SameSense = false; }
			else if( _stricmp( args[2].c_str(), ".T." ) == 0 ) { m_SameSense = true; }
		}
		void IfcAdvancedFace::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcFaceSurface::setInverseCounterparts( ptr_self_entity );
		}
		void IfcAdvancedFace::unlinkSelf()
		{
			IfcFaceSurface::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

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
#include "include/IfcFaceBound.h"
#include "include/IfcFaceSurface.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcSurface.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcFaceSurface 
		IfcFaceSurface::IfcFaceSurface() { m_entity_enum = IFCFACESURFACE; }
		IfcFaceSurface::IfcFaceSurface( int id ) { m_id = id; m_entity_enum = IFCFACESURFACE; }
		IfcFaceSurface::~IfcFaceSurface() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcFaceSurface::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcFaceSurface> other = dynamic_pointer_cast<IfcFaceSurface>(other_entity);
			if( !other) { return; }
			m_Bounds = other->m_Bounds;
			m_FaceSurface = other->m_FaceSurface;
			m_SameSense = other->m_SameSense;
		}
		void IfcFaceSurface::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCFACESURFACE" << "(";
			writeEntityList( stream, m_Bounds );
			stream << ",";
			if( m_FaceSurface ) { stream << "#" << m_FaceSurface->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_SameSense == false ) { stream << ".F."; }
			else if( m_SameSense == true ) { stream << ".T."; }
			stream << ");";
		}
		void IfcFaceSurface::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcFaceSurface::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcFaceSurface, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcFaceSurface, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_Bounds, map );
			readEntityReference( args[1], m_FaceSurface, map );
			if( _stricmp( args[2].c_str(), ".F." ) == 0 ) { m_SameSense = false; }
			else if( _stricmp( args[2].c_str(), ".T." ) == 0 ) { m_SameSense = true; }
		}
		void IfcFaceSurface::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcFace::setInverseCounterparts( ptr_self_entity );
		}
		void IfcFaceSurface::unlinkSelf()
		{
			IfcFace::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

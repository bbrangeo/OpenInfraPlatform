/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/IfcAlignmentP6EntityEnums.h"
#include "include/IfcBoolean.h"
#include "include/IfcFaceBound.h"
#include "include/IfcFaceSurface.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcSurface.h"
#include "include/IfcTextureMap.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcFaceSurface 
		IfcFaceSurface::IfcFaceSurface() { m_entity_enum = IFCFACESURFACE; }
		IfcFaceSurface::IfcFaceSurface( int id ) { m_id = id; m_entity_enum = IFCFACESURFACE; }
		IfcFaceSurface::~IfcFaceSurface() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcFaceSurface::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
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
			if( m_SameSense ) { m_SameSense->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcFaceSurface::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcFaceSurface::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcFaceSurface, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcFaceSurface, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_Bounds, map );
			readEntityReference( args[1], m_FaceSurface, map );
			m_SameSense = IfcBoolean::readStepData( args[2] );
		}
		void IfcFaceSurface::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcFace::setInverseCounterparts( ptr_self_entity );
		}
		void IfcFaceSurface::unlinkSelf()
		{
			IfcFace::unlinkSelf();
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

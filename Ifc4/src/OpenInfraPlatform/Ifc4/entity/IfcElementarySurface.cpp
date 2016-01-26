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
#include "include/IfcAxis2Placement3D.h"
#include "include/IfcElementarySurface.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcElementarySurface 
		IfcElementarySurface::IfcElementarySurface() { m_entity_enum = IFCELEMENTARYSURFACE; }
		IfcElementarySurface::IfcElementarySurface( int id ) { m_id = id; m_entity_enum = IFCELEMENTARYSURFACE; }
		IfcElementarySurface::~IfcElementarySurface() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcElementarySurface::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcElementarySurface> other = dynamic_pointer_cast<IfcElementarySurface>(other_entity);
			if( !other) { return; }
			m_Position = other->m_Position;
		}
		void IfcElementarySurface::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCELEMENTARYSURFACE" << "(";
			if( m_Position ) { stream << "#" << m_Position->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcElementarySurface::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcElementarySurface::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcElementarySurface, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcElementarySurface, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Position, map );
		}
		void IfcElementarySurface::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcSurface::setInverseCounterparts( ptr_self_entity );
		}
		void IfcElementarySurface::unlinkSelf()
		{
			IfcSurface::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

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
#include "include/IfcCylindricalSurface.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcCylindricalSurface 
		IfcCylindricalSurface::IfcCylindricalSurface() { m_entity_enum = IFCCYLINDRICALSURFACE; }
		IfcCylindricalSurface::IfcCylindricalSurface( int id ) { m_id = id; m_entity_enum = IFCCYLINDRICALSURFACE; }
		IfcCylindricalSurface::~IfcCylindricalSurface() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCylindricalSurface::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcCylindricalSurface> other = dynamic_pointer_cast<IfcCylindricalSurface>(other_entity);
			if( !other) { return; }
			m_Position = other->m_Position;
			m_Radius = other->m_Radius;
		}
		void IfcCylindricalSurface::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCYLINDRICALSURFACE" << "(";
			if( m_Position ) { stream << "#" << m_Position->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Radius ) { m_Radius->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcCylindricalSurface::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCylindricalSurface::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCylindricalSurface, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcCylindricalSurface, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Position, map );
			m_Radius = IfcPositiveLengthMeasure::readStepData( args[1] );
		}
		void IfcCylindricalSurface::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcElementarySurface::setInverseCounterparts( ptr_self_entity );
		}
		void IfcCylindricalSurface::unlinkSelf()
		{
			IfcElementarySurface::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

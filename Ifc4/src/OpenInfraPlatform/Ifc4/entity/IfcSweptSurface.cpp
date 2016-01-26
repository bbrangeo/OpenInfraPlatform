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
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcProfileDef.h"
#include "include/IfcStyledItem.h"
#include "include/IfcSweptSurface.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcSweptSurface 
		IfcSweptSurface::IfcSweptSurface() { m_entity_enum = IFCSWEPTSURFACE; }
		IfcSweptSurface::IfcSweptSurface( int id ) { m_id = id; m_entity_enum = IFCSWEPTSURFACE; }
		IfcSweptSurface::~IfcSweptSurface() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcSweptSurface::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcSweptSurface> other = dynamic_pointer_cast<IfcSweptSurface>(other_entity);
			if( !other) { return; }
			m_SweptCurve = other->m_SweptCurve;
			m_Position = other->m_Position;
		}
		void IfcSweptSurface::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSWEPTSURFACE" << "(";
			if( m_SweptCurve ) { stream << "#" << m_SweptCurve->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Position ) { stream << "#" << m_Position->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcSweptSurface::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcSweptSurface::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcSweptSurface, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcSweptSurface, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_SweptCurve, map );
			readEntityReference( args[1], m_Position, map );
		}
		void IfcSweptSurface::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcSurface::setInverseCounterparts( ptr_self_entity );
		}
		void IfcSweptSurface::unlinkSelf()
		{
			IfcSurface::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

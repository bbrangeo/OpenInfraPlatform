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
#include "include/IfcCurve.h"
#include "include/IfcPcurve.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcSurface.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcPcurve 
		IfcPcurve::IfcPcurve() { m_entity_enum = IFCPCURVE; }
		IfcPcurve::IfcPcurve( int id ) { m_id = id; m_entity_enum = IFCPCURVE; }
		IfcPcurve::~IfcPcurve() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPcurve::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcPcurve> other = dynamic_pointer_cast<IfcPcurve>(other_entity);
			if( !other) { return; }
			m_BasisSurface = other->m_BasisSurface;
			m_ReferenceCurve = other->m_ReferenceCurve;
		}
		void IfcPcurve::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPCURVE" << "(";
			if( m_BasisSurface ) { stream << "#" << m_BasisSurface->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_ReferenceCurve ) { stream << "#" << m_ReferenceCurve->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcPcurve::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPcurve::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPcurve, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcPcurve, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_BasisSurface, map );
			readEntityReference( args[1], m_ReferenceCurve, map );
		}
		void IfcPcurve::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcCurve::setInverseCounterparts( ptr_self_entity );
		}
		void IfcPcurve::unlinkSelf()
		{
			IfcCurve::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

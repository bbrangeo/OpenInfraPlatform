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
#include "include/IfcCurve.h"
#include "include/IfcPcurve.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcSurface.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcPcurve 
		IfcPcurve::IfcPcurve() { m_entity_enum = IFCPCURVE; }
		IfcPcurve::IfcPcurve( int id ) { m_id = id; m_entity_enum = IFCPCURVE; }
		IfcPcurve::~IfcPcurve() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPcurve::setEntity( shared_ptr<IfcRoadEntity> other_entity )
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
		void IfcPcurve::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPcurve, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcPcurve, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_BasisSurface, map );
			readEntityReference( args[1], m_ReferenceCurve, map );
		}
		void IfcPcurve::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcCurve::setInverseCounterparts( ptr_self_entity );
		}
		void IfcPcurve::unlinkSelf()
		{
			IfcCurve::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

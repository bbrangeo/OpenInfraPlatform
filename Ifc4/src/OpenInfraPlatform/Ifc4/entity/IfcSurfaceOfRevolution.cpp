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
#include "include/IfcAxis1Placement.h"
#include "include/IfcAxis2Placement3D.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcProfileDef.h"
#include "include/IfcStyledItem.h"
#include "include/IfcSurfaceOfRevolution.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcSurfaceOfRevolution 
		IfcSurfaceOfRevolution::IfcSurfaceOfRevolution() { m_entity_enum = IFCSURFACEOFREVOLUTION; }
		IfcSurfaceOfRevolution::IfcSurfaceOfRevolution( int id ) { m_id = id; m_entity_enum = IFCSURFACEOFREVOLUTION; }
		IfcSurfaceOfRevolution::~IfcSurfaceOfRevolution() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcSurfaceOfRevolution::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcSurfaceOfRevolution> other = dynamic_pointer_cast<IfcSurfaceOfRevolution>(other_entity);
			if( !other) { return; }
			m_SweptCurve = other->m_SweptCurve;
			m_Position = other->m_Position;
			m_AxisPosition = other->m_AxisPosition;
		}
		void IfcSurfaceOfRevolution::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSURFACEOFREVOLUTION" << "(";
			if( m_SweptCurve ) { stream << "#" << m_SweptCurve->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Position ) { stream << "#" << m_Position->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_AxisPosition ) { stream << "#" << m_AxisPosition->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcSurfaceOfRevolution::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcSurfaceOfRevolution::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcSurfaceOfRevolution, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcSurfaceOfRevolution, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_SweptCurve, map );
			readEntityReference( args[1], m_Position, map );
			readEntityReference( args[2], m_AxisPosition, map );
		}
		void IfcSurfaceOfRevolution::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcSweptSurface::setInverseCounterparts( ptr_self_entity );
		}
		void IfcSurfaceOfRevolution::unlinkSelf()
		{
			IfcSweptSurface::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

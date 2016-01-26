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
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcRightCircularCylinder.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcRightCircularCylinder 
		IfcRightCircularCylinder::IfcRightCircularCylinder() { m_entity_enum = IFCRIGHTCIRCULARCYLINDER; }
		IfcRightCircularCylinder::IfcRightCircularCylinder( int id ) { m_id = id; m_entity_enum = IFCRIGHTCIRCULARCYLINDER; }
		IfcRightCircularCylinder::~IfcRightCircularCylinder() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRightCircularCylinder::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcRightCircularCylinder> other = dynamic_pointer_cast<IfcRightCircularCylinder>(other_entity);
			if( !other) { return; }
			m_Position = other->m_Position;
			m_Height = other->m_Height;
			m_Radius = other->m_Radius;
		}
		void IfcRightCircularCylinder::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRIGHTCIRCULARCYLINDER" << "(";
			if( m_Position ) { stream << "#" << m_Position->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Height ) { m_Height->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Radius ) { m_Radius->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcRightCircularCylinder::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRightCircularCylinder::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRightCircularCylinder, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcRightCircularCylinder, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Position, map );
			m_Height = IfcPositiveLengthMeasure::readStepData( args[1] );
			m_Radius = IfcPositiveLengthMeasure::readStepData( args[2] );
		}
		void IfcRightCircularCylinder::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcCsgPrimitive3D::setInverseCounterparts( ptr_self_entity );
		}
		void IfcRightCircularCylinder::unlinkSelf()
		{
			IfcCsgPrimitive3D::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

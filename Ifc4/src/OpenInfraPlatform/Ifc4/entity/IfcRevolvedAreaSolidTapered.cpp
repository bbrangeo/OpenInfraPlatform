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
#include "include/IfcPlaneAngleMeasure.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcProfileDef.h"
#include "include/IfcRevolvedAreaSolidTapered.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcRevolvedAreaSolidTapered 
		IfcRevolvedAreaSolidTapered::IfcRevolvedAreaSolidTapered() { m_entity_enum = IFCREVOLVEDAREASOLIDTAPERED; }
		IfcRevolvedAreaSolidTapered::IfcRevolvedAreaSolidTapered( int id ) { m_id = id; m_entity_enum = IFCREVOLVEDAREASOLIDTAPERED; }
		IfcRevolvedAreaSolidTapered::~IfcRevolvedAreaSolidTapered() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRevolvedAreaSolidTapered::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcRevolvedAreaSolidTapered> other = dynamic_pointer_cast<IfcRevolvedAreaSolidTapered>(other_entity);
			if( !other) { return; }
			m_SweptArea = other->m_SweptArea;
			m_Position = other->m_Position;
			m_Axis = other->m_Axis;
			m_Angle = other->m_Angle;
			m_EndSweptArea = other->m_EndSweptArea;
		}
		void IfcRevolvedAreaSolidTapered::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCREVOLVEDAREASOLIDTAPERED" << "(";
			if( m_SweptArea ) { stream << "#" << m_SweptArea->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Position ) { stream << "#" << m_Position->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Axis ) { stream << "#" << m_Axis->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Angle ) { m_Angle->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_EndSweptArea ) { stream << "#" << m_EndSweptArea->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcRevolvedAreaSolidTapered::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRevolvedAreaSolidTapered::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRevolvedAreaSolidTapered, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcRevolvedAreaSolidTapered, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_SweptArea, map );
			readEntityReference( args[1], m_Position, map );
			readEntityReference( args[2], m_Axis, map );
			m_Angle = IfcPlaneAngleMeasure::readStepData( args[3] );
			readEntityReference( args[4], m_EndSweptArea, map );
		}
		void IfcRevolvedAreaSolidTapered::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcRevolvedAreaSolid::setInverseCounterparts( ptr_self_entity );
		}
		void IfcRevolvedAreaSolidTapered::unlinkSelf()
		{
			IfcRevolvedAreaSolid::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

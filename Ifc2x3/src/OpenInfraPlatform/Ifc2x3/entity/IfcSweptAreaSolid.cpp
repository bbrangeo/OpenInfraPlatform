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
#include "include/IfcAxis2Placement3D.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcProfileDef.h"
#include "include/IfcStyledItem.h"
#include "include/IfcSweptAreaSolid.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcSweptAreaSolid 
		IfcSweptAreaSolid::IfcSweptAreaSolid() { m_entity_enum = IFCSWEPTAREASOLID; }
		IfcSweptAreaSolid::IfcSweptAreaSolid( int id ) { m_id = id; m_entity_enum = IFCSWEPTAREASOLID; }
		IfcSweptAreaSolid::~IfcSweptAreaSolid() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcSweptAreaSolid::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcSweptAreaSolid> other = dynamic_pointer_cast<IfcSweptAreaSolid>(other_entity);
			if( !other) { return; }
			m_SweptArea = other->m_SweptArea;
			m_Position = other->m_Position;
		}
		void IfcSweptAreaSolid::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSWEPTAREASOLID" << "(";
			if( m_SweptArea ) { stream << "#" << m_SweptArea->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Position ) { stream << "#" << m_Position->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcSweptAreaSolid::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcSweptAreaSolid::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcSweptAreaSolid, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcSweptAreaSolid, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_SweptArea, map );
			readEntityReference( args[1], m_Position, map );
		}
		void IfcSweptAreaSolid::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcSolidModel::setInverseCounterparts( ptr_self_entity );
		}
		void IfcSweptAreaSolid::unlinkSelf()
		{
			IfcSolidModel::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

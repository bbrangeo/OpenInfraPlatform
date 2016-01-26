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
#include "include/IfcSweptAreaSolid.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcSweptAreaSolid 
		IfcSweptAreaSolid::IfcSweptAreaSolid() { m_entity_enum = IFCSWEPTAREASOLID; }
		IfcSweptAreaSolid::IfcSweptAreaSolid( int id ) { m_id = id; m_entity_enum = IFCSWEPTAREASOLID; }
		IfcSweptAreaSolid::~IfcSweptAreaSolid() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcSweptAreaSolid::setEntity( shared_ptr<Ifc4Entity> other_entity )
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
		void IfcSweptAreaSolid::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcSweptAreaSolid, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcSweptAreaSolid, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_SweptArea, map );
			readEntityReference( args[1], m_Position, map );
		}
		void IfcSweptAreaSolid::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcSolidModel::setInverseCounterparts( ptr_self_entity );
		}
		void IfcSweptAreaSolid::unlinkSelf()
		{
			IfcSolidModel::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

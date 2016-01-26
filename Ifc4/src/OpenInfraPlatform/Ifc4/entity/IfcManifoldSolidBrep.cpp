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
#include "include/IfcClosedShell.h"
#include "include/IfcManifoldSolidBrep.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcManifoldSolidBrep 
		IfcManifoldSolidBrep::IfcManifoldSolidBrep() { m_entity_enum = IFCMANIFOLDSOLIDBREP; }
		IfcManifoldSolidBrep::IfcManifoldSolidBrep( int id ) { m_id = id; m_entity_enum = IFCMANIFOLDSOLIDBREP; }
		IfcManifoldSolidBrep::~IfcManifoldSolidBrep() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcManifoldSolidBrep::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcManifoldSolidBrep> other = dynamic_pointer_cast<IfcManifoldSolidBrep>(other_entity);
			if( !other) { return; }
			m_Outer = other->m_Outer;
		}
		void IfcManifoldSolidBrep::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCMANIFOLDSOLIDBREP" << "(";
			if( m_Outer ) { stream << "#" << m_Outer->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcManifoldSolidBrep::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcManifoldSolidBrep::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcManifoldSolidBrep, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcManifoldSolidBrep, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Outer, map );
		}
		void IfcManifoldSolidBrep::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcSolidModel::setInverseCounterparts( ptr_self_entity );
		}
		void IfcManifoldSolidBrep::unlinkSelf()
		{
			IfcSolidModel::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

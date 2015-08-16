/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/IfcAlignmentP6EntityEnums.h"
#include "include/IfcCsgSelect.h"
#include "include/IfcCsgSolid.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcCsgSolid 
		IfcCsgSolid::IfcCsgSolid() { m_entity_enum = IFCCSGSOLID; }
		IfcCsgSolid::IfcCsgSolid( int id ) { m_id = id; m_entity_enum = IFCCSGSOLID; }
		IfcCsgSolid::~IfcCsgSolid() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCsgSolid::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcCsgSolid> other = dynamic_pointer_cast<IfcCsgSolid>(other_entity);
			if( !other) { return; }
			m_TreeRootExpression = other->m_TreeRootExpression;
		}
		void IfcCsgSolid::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCSGSOLID" << "(";
			if( m_TreeRootExpression ) { m_TreeRootExpression->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcCsgSolid::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCsgSolid::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCsgSolid, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcCsgSolid, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_TreeRootExpression = IfcCsgSelect::readStepData( args[0], map );
		}
		void IfcCsgSolid::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcSolidModel::setInverseCounterparts( ptr_self_entity );
		}
		void IfcCsgSolid::unlinkSelf()
		{
			IfcSolidModel::unlinkSelf();
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

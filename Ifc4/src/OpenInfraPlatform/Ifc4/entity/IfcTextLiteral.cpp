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
#include "include/IfcAxis2Placement.h"
#include "include/IfcPresentableText.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcTextLiteral.h"
#include "include/IfcTextPath.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcTextLiteral 
		IfcTextLiteral::IfcTextLiteral() { m_entity_enum = IFCTEXTLITERAL; }
		IfcTextLiteral::IfcTextLiteral( int id ) { m_id = id; m_entity_enum = IFCTEXTLITERAL; }
		IfcTextLiteral::~IfcTextLiteral() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTextLiteral::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcTextLiteral> other = dynamic_pointer_cast<IfcTextLiteral>(other_entity);
			if( !other) { return; }
			m_Literal = other->m_Literal;
			m_Placement = other->m_Placement;
			m_Path = other->m_Path;
		}
		void IfcTextLiteral::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTEXTLITERAL" << "(";
			if( m_Literal ) { m_Literal->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Placement ) { m_Placement->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_Path ) { m_Path->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcTextLiteral::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTextLiteral::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTextLiteral, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcTextLiteral, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Literal = IfcPresentableText::readStepData( args[0] );
			m_Placement = IfcAxis2Placement::readStepData( args[1], map );
			m_Path = IfcTextPath::readStepData( args[2] );
		}
		void IfcTextLiteral::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcTextLiteral::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

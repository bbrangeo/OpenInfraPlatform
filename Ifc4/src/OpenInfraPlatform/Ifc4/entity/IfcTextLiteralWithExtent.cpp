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
#include "include/IfcBoxAlignment.h"
#include "include/IfcPlanarExtent.h"
#include "include/IfcPresentableText.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcTextLiteralWithExtent.h"
#include "include/IfcTextPath.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcTextLiteralWithExtent 
		IfcTextLiteralWithExtent::IfcTextLiteralWithExtent() { m_entity_enum = IFCTEXTLITERALWITHEXTENT; }
		IfcTextLiteralWithExtent::IfcTextLiteralWithExtent( int id ) { m_id = id; m_entity_enum = IFCTEXTLITERALWITHEXTENT; }
		IfcTextLiteralWithExtent::~IfcTextLiteralWithExtent() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTextLiteralWithExtent::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcTextLiteralWithExtent> other = dynamic_pointer_cast<IfcTextLiteralWithExtent>(other_entity);
			if( !other) { return; }
			m_Literal = other->m_Literal;
			m_Placement = other->m_Placement;
			m_Path = other->m_Path;
			m_Extent = other->m_Extent;
			m_BoxAlignment = other->m_BoxAlignment;
		}
		void IfcTextLiteralWithExtent::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTEXTLITERALWITHEXTENT" << "(";
			if( m_Literal ) { m_Literal->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Placement ) { m_Placement->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_Path ) { m_Path->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Extent ) { stream << "#" << m_Extent->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_BoxAlignment ) { m_BoxAlignment->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcTextLiteralWithExtent::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTextLiteralWithExtent::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTextLiteralWithExtent, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcTextLiteralWithExtent, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Literal = IfcPresentableText::readStepData( args[0] );
			m_Placement = IfcAxis2Placement::readStepData( args[1], map );
			m_Path = IfcTextPath::readStepData( args[2] );
			readEntityReference( args[3], m_Extent, map );
			m_BoxAlignment = IfcBoxAlignment::readStepData( args[4] );
		}
		void IfcTextLiteralWithExtent::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcTextLiteral::setInverseCounterparts( ptr_self_entity );
		}
		void IfcTextLiteralWithExtent::unlinkSelf()
		{
			IfcTextLiteral::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

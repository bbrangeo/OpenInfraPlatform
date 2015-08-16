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
#include "include/IfcCartesianPoint.h"
#include "include/IfcLine.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcVector.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcLine 
		IfcLine::IfcLine() { m_entity_enum = IFCLINE; }
		IfcLine::IfcLine( int id ) { m_id = id; m_entity_enum = IFCLINE; }
		IfcLine::~IfcLine() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcLine::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcLine> other = dynamic_pointer_cast<IfcLine>(other_entity);
			if( !other) { return; }
			m_Pnt = other->m_Pnt;
			m_Dir = other->m_Dir;
		}
		void IfcLine::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCLINE" << "(";
			if( m_Pnt ) { stream << "#" << m_Pnt->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Dir ) { stream << "#" << m_Dir->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcLine::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcLine::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcLine, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcLine, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Pnt, map );
			readEntityReference( args[1], m_Dir, map );
		}
		void IfcLine::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcCurve::setInverseCounterparts( ptr_self_entity );
		}
		void IfcLine::unlinkSelf()
		{
			IfcCurve::unlinkSelf();
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

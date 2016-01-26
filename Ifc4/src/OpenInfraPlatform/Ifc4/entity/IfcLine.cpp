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
#include "include/IfcCartesianPoint.h"
#include "include/IfcLine.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcVector.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcLine 
		IfcLine::IfcLine() { m_entity_enum = IFCLINE; }
		IfcLine::IfcLine( int id ) { m_id = id; m_entity_enum = IFCLINE; }
		IfcLine::~IfcLine() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcLine::setEntity( shared_ptr<Ifc4Entity> other_entity )
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
		void IfcLine::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcLine, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcLine, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Pnt, map );
			readEntityReference( args[1], m_Dir, map );
		}
		void IfcLine::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcCurve::setInverseCounterparts( ptr_self_entity );
		}
		void IfcLine::unlinkSelf()
		{
			IfcCurve::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

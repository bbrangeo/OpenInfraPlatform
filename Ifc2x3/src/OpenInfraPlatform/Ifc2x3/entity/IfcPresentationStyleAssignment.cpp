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
#include "include/IfcPresentationStyleAssignment.h"
#include "include/IfcPresentationStyleSelect.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcPresentationStyleAssignment 
		IfcPresentationStyleAssignment::IfcPresentationStyleAssignment() { m_entity_enum = IFCPRESENTATIONSTYLEASSIGNMENT; }
		IfcPresentationStyleAssignment::IfcPresentationStyleAssignment( int id ) { m_id = id; m_entity_enum = IFCPRESENTATIONSTYLEASSIGNMENT; }
		IfcPresentationStyleAssignment::~IfcPresentationStyleAssignment() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPresentationStyleAssignment::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcPresentationStyleAssignment> other = dynamic_pointer_cast<IfcPresentationStyleAssignment>(other_entity);
			if( !other) { return; }
			m_Styles = other->m_Styles;
		}
		void IfcPresentationStyleAssignment::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPRESENTATIONSTYLEASSIGNMENT" << "(";
			writeTypeList( stream, m_Styles, true );
			stream << ");";
		}
		void IfcPresentationStyleAssignment::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPresentationStyleAssignment::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPresentationStyleAssignment, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcPresentationStyleAssignment, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readSelectList( args[0], m_Styles, map );
		}
		void IfcPresentationStyleAssignment::setInverseCounterparts( shared_ptr<Ifc2x3Entity> )
		{
		}
		void IfcPresentationStyleAssignment::unlinkSelf()
		{
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

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
#include "include/IfcLabel.h"
#include "include/IfcStructuralLoadStatic.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcStructuralLoadStatic 
		IfcStructuralLoadStatic::IfcStructuralLoadStatic() { m_entity_enum = IFCSTRUCTURALLOADSTATIC; }
		IfcStructuralLoadStatic::IfcStructuralLoadStatic( int id ) { m_id = id; m_entity_enum = IFCSTRUCTURALLOADSTATIC; }
		IfcStructuralLoadStatic::~IfcStructuralLoadStatic() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcStructuralLoadStatic::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcStructuralLoadStatic> other = dynamic_pointer_cast<IfcStructuralLoadStatic>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
		}
		void IfcStructuralLoadStatic::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSTRUCTURALLOADSTATIC" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcStructuralLoadStatic::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcStructuralLoadStatic::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcStructuralLoadStatic, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcStructuralLoadStatic, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
		}
		void IfcStructuralLoadStatic::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcStructuralLoadOrResult::setInverseCounterparts( ptr_self_entity );
		}
		void IfcStructuralLoadStatic::unlinkSelf()
		{
			IfcStructuralLoadOrResult::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

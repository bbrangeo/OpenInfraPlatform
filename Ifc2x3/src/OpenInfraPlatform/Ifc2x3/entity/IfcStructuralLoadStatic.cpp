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
#include "include/IfcLabel.h"
#include "include/IfcStructuralLoadStatic.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcStructuralLoadStatic 
		IfcStructuralLoadStatic::IfcStructuralLoadStatic() { m_entity_enum = IFCSTRUCTURALLOADSTATIC; }
		IfcStructuralLoadStatic::IfcStructuralLoadStatic( int id ) { m_id = id; m_entity_enum = IFCSTRUCTURALLOADSTATIC; }
		IfcStructuralLoadStatic::~IfcStructuralLoadStatic() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcStructuralLoadStatic::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
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
		void IfcStructuralLoadStatic::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcStructuralLoadStatic, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcStructuralLoadStatic, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
		}
		void IfcStructuralLoadStatic::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcStructuralLoad::setInverseCounterparts( ptr_self_entity );
		}
		void IfcStructuralLoadStatic::unlinkSelf()
		{
			IfcStructuralLoad::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

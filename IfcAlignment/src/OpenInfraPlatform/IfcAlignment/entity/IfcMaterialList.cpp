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
#include "include/IfcMaterial.h"
#include "include/IfcMaterialList.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcMaterialList 
		IfcMaterialList::IfcMaterialList() { m_entity_enum = IFCMATERIALLIST; }
		IfcMaterialList::IfcMaterialList( int id ) { m_id = id; m_entity_enum = IFCMATERIALLIST; }
		IfcMaterialList::~IfcMaterialList() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcMaterialList::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcMaterialList> other = dynamic_pointer_cast<IfcMaterialList>(other_entity);
			if( !other) { return; }
			m_Materials = other->m_Materials;
		}
		void IfcMaterialList::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCMATERIALLIST" << "(";
			writeEntityList( stream, m_Materials );
			stream << ");";
		}
		void IfcMaterialList::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcMaterialList::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcMaterialList, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcMaterialList, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_Materials, map );
		}
		void IfcMaterialList::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> )
		{
		}
		void IfcMaterialList::unlinkSelf()
		{
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

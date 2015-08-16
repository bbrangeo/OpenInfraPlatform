/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcBridgeException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcBridgeEntityEnums.h"
#include "include/IfcMaterial.h"
#include "include/IfcMaterialList.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcMaterialList 
		IfcMaterialList::IfcMaterialList() { m_entity_enum = IFCMATERIALLIST; }
		IfcMaterialList::IfcMaterialList( int id ) { m_id = id; m_entity_enum = IFCMATERIALLIST; }
		IfcMaterialList::~IfcMaterialList() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcMaterialList::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
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
		void IfcMaterialList::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcMaterialList, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcMaterialList, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_Materials, map );
		}
		void IfcMaterialList::setInverseCounterparts( shared_ptr<IfcBridgeEntity> )
		{
		}
		void IfcMaterialList::unlinkSelf()
		{
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

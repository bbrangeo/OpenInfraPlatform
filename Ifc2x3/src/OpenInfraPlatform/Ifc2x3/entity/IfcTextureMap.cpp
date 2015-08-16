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
#include "include/IfcAnnotationSurface.h"
#include "include/IfcTextureMap.h"
#include "include/IfcVertexBasedTextureMap.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcTextureMap 
		IfcTextureMap::IfcTextureMap() { m_entity_enum = IFCTEXTUREMAP; }
		IfcTextureMap::IfcTextureMap( int id ) { m_id = id; m_entity_enum = IFCTEXTUREMAP; }
		IfcTextureMap::~IfcTextureMap() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTextureMap::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcTextureMap> other = dynamic_pointer_cast<IfcTextureMap>(other_entity);
			if( !other) { return; }
			m_TextureMaps = other->m_TextureMaps;
		}
		void IfcTextureMap::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTEXTUREMAP" << "(";
			writeEntityList( stream, m_TextureMaps );
			stream << ");";
		}
		void IfcTextureMap::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTextureMap::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTextureMap, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcTextureMap, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_TextureMaps, map );
		}
		void IfcTextureMap::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcTextureCoordinate::setInverseCounterparts( ptr_self_entity );
		}
		void IfcTextureMap::unlinkSelf()
		{
			IfcTextureCoordinate::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

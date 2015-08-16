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
#include "include/IfcCartesianPoint.h"
#include "include/IfcTextureVertex.h"
#include "include/IfcVertexBasedTextureMap.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcVertexBasedTextureMap 
		IfcVertexBasedTextureMap::IfcVertexBasedTextureMap() { m_entity_enum = IFCVERTEXBASEDTEXTUREMAP; }
		IfcVertexBasedTextureMap::IfcVertexBasedTextureMap( int id ) { m_id = id; m_entity_enum = IFCVERTEXBASEDTEXTUREMAP; }
		IfcVertexBasedTextureMap::~IfcVertexBasedTextureMap() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcVertexBasedTextureMap::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcVertexBasedTextureMap> other = dynamic_pointer_cast<IfcVertexBasedTextureMap>(other_entity);
			if( !other) { return; }
			m_TextureVertices = other->m_TextureVertices;
			m_TexturePoints = other->m_TexturePoints;
		}
		void IfcVertexBasedTextureMap::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCVERTEXBASEDTEXTUREMAP" << "(";
			writeEntityList( stream, m_TextureVertices );
			stream << ",";
			writeEntityList( stream, m_TexturePoints );
			stream << ");";
		}
		void IfcVertexBasedTextureMap::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcVertexBasedTextureMap::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcVertexBasedTextureMap, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcVertexBasedTextureMap, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_TextureVertices, map );
			readEntityReferenceList( args[1], m_TexturePoints, map );
		}
		void IfcVertexBasedTextureMap::setInverseCounterparts( shared_ptr<Ifc2x3Entity> )
		{
		}
		void IfcVertexBasedTextureMap::unlinkSelf()
		{
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

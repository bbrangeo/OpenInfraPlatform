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
#include "include/IfcBlobTexture.h"
#include "include/IfcCartesianTransformationOperator2D.h"
#include "include/IfcIdentifier.h"
#include "include/IfcSurfaceTextureEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcBlobTexture 
		IfcBlobTexture::IfcBlobTexture() { m_entity_enum = IFCBLOBTEXTURE; }
		IfcBlobTexture::IfcBlobTexture( int id ) { m_id = id; m_entity_enum = IFCBLOBTEXTURE; }
		IfcBlobTexture::~IfcBlobTexture() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcBlobTexture::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcBlobTexture> other = dynamic_pointer_cast<IfcBlobTexture>(other_entity);
			if( !other) { return; }
			m_RepeatS = other->m_RepeatS;
			m_RepeatT = other->m_RepeatT;
			m_TextureType = other->m_TextureType;
			m_TextureTransform = other->m_TextureTransform;
			m_RasterFormat = other->m_RasterFormat;
			m_RasterCode = other->m_RasterCode;
		}
		void IfcBlobTexture::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCBLOBTEXTURE" << "(";
			if( m_RepeatS == false ) { stream << ".F."; }
			else if( m_RepeatS == true ) { stream << ".T."; }
			stream << ",";
			if( m_RepeatT == false ) { stream << ".F."; }
			else if( m_RepeatT == true ) { stream << ".T."; }
			stream << ",";
			if( m_TextureType ) { m_TextureType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_TextureTransform ) { stream << "#" << m_TextureTransform->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_RasterFormat ) { m_RasterFormat->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RasterCode == false ) { stream << ".F."; }
			else if( m_RasterCode == true ) { stream << ".T."; }
			stream << ");";
		}
		void IfcBlobTexture::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcBlobTexture::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcBlobTexture, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcBlobTexture, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			if( _stricmp( args[0].c_str(), ".F." ) == 0 ) { m_RepeatS = false; }
			else if( _stricmp( args[0].c_str(), ".T." ) == 0 ) { m_RepeatS = true; }
			if( _stricmp( args[1].c_str(), ".F." ) == 0 ) { m_RepeatT = false; }
			else if( _stricmp( args[1].c_str(), ".T." ) == 0 ) { m_RepeatT = true; }
			m_TextureType = IfcSurfaceTextureEnum::readStepData( args[2] );
			readEntityReference( args[3], m_TextureTransform, map );
			m_RasterFormat = IfcIdentifier::readStepData( args[4] );
			if( _stricmp( args[5].c_str(), ".F." ) == 0 ) { m_RasterCode = false; }
			else if( _stricmp( args[5].c_str(), ".T." ) == 0 ) { m_RasterCode = true; }
		}
		void IfcBlobTexture::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcSurfaceTexture::setInverseCounterparts( ptr_self_entity );
		}
		void IfcBlobTexture::unlinkSelf()
		{
			IfcSurfaceTexture::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

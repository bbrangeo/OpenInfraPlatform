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
#include "include/IfcBinary.h"
#include "include/IfcBlobTexture.h"
#include "include/IfcBoolean.h"
#include "include/IfcCartesianTransformationOperator2D.h"
#include "include/IfcIdentifier.h"
#include "include/IfcSurfaceStyleWithTextures.h"
#include "include/IfcTextureCoordinate.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcBlobTexture 
		IfcBlobTexture::IfcBlobTexture() { m_entity_enum = IFCBLOBTEXTURE; }
		IfcBlobTexture::IfcBlobTexture( int id ) { m_id = id; m_entity_enum = IFCBLOBTEXTURE; }
		IfcBlobTexture::~IfcBlobTexture() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcBlobTexture::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcBlobTexture> other = dynamic_pointer_cast<IfcBlobTexture>(other_entity);
			if( !other) { return; }
			m_RepeatS = other->m_RepeatS;
			m_RepeatT = other->m_RepeatT;
			m_Mode = other->m_Mode;
			m_TextureTransform = other->m_TextureTransform;
			m_Parameter = other->m_Parameter;
			m_RasterFormat = other->m_RasterFormat;
			m_RasterCode = other->m_RasterCode;
		}
		void IfcBlobTexture::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCBLOBTEXTURE" << "(";
			if( m_RepeatS ) { m_RepeatS->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RepeatT ) { m_RepeatT->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Mode ) { m_Mode->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_TextureTransform ) { stream << "#" << m_TextureTransform->getId(); } else { stream << "$"; }
			stream << ",";
			writeTypeList( stream, m_Parameter );
			stream << ",";
			if( m_RasterFormat ) { m_RasterFormat->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RasterCode ) { m_RasterCode->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcBlobTexture::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcBlobTexture::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<7 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcBlobTexture, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>7 ){ std::cout << "Wrong parameter count for entity IfcBlobTexture, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_RepeatS = IfcBoolean::readStepData( args[0] );
			m_RepeatT = IfcBoolean::readStepData( args[1] );
			m_Mode = IfcIdentifier::readStepData( args[2] );
			readEntityReference( args[3], m_TextureTransform, map );
			readTypeList( args[4], m_Parameter );
			m_RasterFormat = IfcIdentifier::readStepData( args[5] );
			m_RasterCode = IfcBinary::readStepData( args[6] );
		}
		void IfcBlobTexture::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcSurfaceTexture::setInverseCounterparts( ptr_self_entity );
		}
		void IfcBlobTexture::unlinkSelf()
		{
			IfcSurfaceTexture::unlinkSelf();
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/IfcRoadEntityEnums.h"
#include "include/IfcBinary.h"
#include "include/IfcBoolean.h"
#include "include/IfcCartesianTransformationOperator2D.h"
#include "include/IfcIdentifier.h"
#include "include/IfcPixelTexture.h"
#include "include/IfcSurfaceStyleWithTextures.h"
#include "include/IfcTextureCoordinate.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcPixelTexture 
		IfcPixelTexture::IfcPixelTexture() { m_entity_enum = IFCPIXELTEXTURE; }
		IfcPixelTexture::IfcPixelTexture( int id ) { m_id = id; m_entity_enum = IFCPIXELTEXTURE; }
		IfcPixelTexture::~IfcPixelTexture() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPixelTexture::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcPixelTexture> other = dynamic_pointer_cast<IfcPixelTexture>(other_entity);
			if( !other) { return; }
			m_RepeatS = other->m_RepeatS;
			m_RepeatT = other->m_RepeatT;
			m_Mode = other->m_Mode;
			m_TextureTransform = other->m_TextureTransform;
			m_Parameter = other->m_Parameter;
			m_Width = other->m_Width;
			m_Height = other->m_Height;
			m_ColourComponents = other->m_ColourComponents;
			m_Pixel = other->m_Pixel;
		}
		void IfcPixelTexture::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPIXELTEXTURE" << "(";
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
			if( m_Width == m_Width ){ stream << m_Width; }
			else { stream << "$"; }
			stream << ",";
			if( m_Height == m_Height ){ stream << m_Height; }
			else { stream << "$"; }
			stream << ",";
			if( m_ColourComponents == m_ColourComponents ){ stream << m_ColourComponents; }
			else { stream << "$"; }
			stream << ",";
			writeTypeList( stream, m_Pixel );
			stream << ");";
		}
		void IfcPixelTexture::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPixelTexture::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<9 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPixelTexture, expecting 9, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>9 ){ std::cout << "Wrong parameter count for entity IfcPixelTexture, expecting 9, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_RepeatS = IfcBoolean::readStepData( args[0] );
			m_RepeatT = IfcBoolean::readStepData( args[1] );
			m_Mode = IfcIdentifier::readStepData( args[2] );
			readEntityReference( args[3], m_TextureTransform, map );
			readTypeList( args[4], m_Parameter );
			readIntValue( args[5], m_Width );
			readIntValue( args[6], m_Height );
			readIntValue( args[7], m_ColourComponents );
			readTypeList( args[8], m_Pixel );
		}
		void IfcPixelTexture::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcSurfaceTexture::setInverseCounterparts( ptr_self_entity );
		}
		void IfcPixelTexture::unlinkSelf()
		{
			IfcSurfaceTexture::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

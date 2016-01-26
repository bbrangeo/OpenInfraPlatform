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
#include "include/IfcBoolean.h"
#include "include/IfcCartesianTransformationOperator2D.h"
#include "include/IfcIdentifier.h"
#include "include/IfcImageTexture.h"
#include "include/IfcSurfaceStyleWithTextures.h"
#include "include/IfcTextureCoordinate.h"
#include "include/IfcURIReference.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcImageTexture 
		IfcImageTexture::IfcImageTexture() { m_entity_enum = IFCIMAGETEXTURE; }
		IfcImageTexture::IfcImageTexture( int id ) { m_id = id; m_entity_enum = IFCIMAGETEXTURE; }
		IfcImageTexture::~IfcImageTexture() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcImageTexture::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcImageTexture> other = dynamic_pointer_cast<IfcImageTexture>(other_entity);
			if( !other) { return; }
			m_RepeatS = other->m_RepeatS;
			m_RepeatT = other->m_RepeatT;
			m_Mode = other->m_Mode;
			m_TextureTransform = other->m_TextureTransform;
			m_Parameter = other->m_Parameter;
			m_URLReference = other->m_URLReference;
		}
		void IfcImageTexture::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCIMAGETEXTURE" << "(";
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
			if( m_URLReference ) { m_URLReference->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcImageTexture::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcImageTexture::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcImageTexture, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcImageTexture, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_RepeatS = IfcBoolean::readStepData( args[0] );
			m_RepeatT = IfcBoolean::readStepData( args[1] );
			m_Mode = IfcIdentifier::readStepData( args[2] );
			readEntityReference( args[3], m_TextureTransform, map );
			readTypeList( args[4], m_Parameter );
			m_URLReference = IfcURIReference::readStepData( args[5] );
		}
		void IfcImageTexture::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcSurfaceTexture::setInverseCounterparts( ptr_self_entity );
		}
		void IfcImageTexture::unlinkSelf()
		{
			IfcSurfaceTexture::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

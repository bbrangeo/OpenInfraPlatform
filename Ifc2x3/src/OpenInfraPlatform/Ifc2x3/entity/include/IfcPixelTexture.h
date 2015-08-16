/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "../../model/shared_ptr.h"
#include "../../model/Ifc2x3Object.h"
#include "IfcSurfaceTexture.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		class IfcInteger;
		//ENTITY
		class IfcPixelTexture : public IfcSurfaceTexture
		{
		public:
			IfcPixelTexture();
			IfcPixelTexture( int id );
			~IfcPixelTexture();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc2x3Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcPixelTexture"; }


			// IfcSurfaceTexture -----------------------------------------------------------
			// attributes:
			//  bool											m_RepeatS;
			//  bool											m_RepeatT;
			//  shared_ptr<IfcSurfaceTextureEnum>			m_TextureType;
			//  shared_ptr<IfcCartesianTransformationOperator2D>	m_TextureTransform;			//optional

			// IfcPixelTexture -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcInteger>						m_Width;
			shared_ptr<IfcInteger>						m_Height;
			shared_ptr<IfcInteger>						m_ColourComponents;
			std::vector<const char* >					m_Pixel;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform


/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Object.h"
#include "IfcSurfaceTexture.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		class IfcBinary;
		//ENTITY
		class IfcPixelTexture : public IfcSurfaceTexture
		{
		public:
			IfcPixelTexture();
			IfcPixelTexture( int id );
			~IfcPixelTexture();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc4Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcPixelTexture"; }


			// IfcPresentationItem -----------------------------------------------------------

			// IfcSurfaceTexture -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcBoolean>						m_RepeatS;
			//  shared_ptr<IfcBoolean>						m_RepeatT;
			//  shared_ptr<IfcIdentifier>					m_Mode;						//optional
			//  shared_ptr<IfcCartesianTransformationOperator2D>	m_TextureTransform;			//optional
			//  std::vector<shared_ptr<IfcIdentifier> >		m_Parameter;				//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcTextureCoordinate> >	m_IsMappedBy_inverse;
			//  std::vector<weak_ptr<IfcSurfaceStyleWithTextures> >	m_UsedInStyles_inverse;

			// IfcPixelTexture -----------------------------------------------------------
			// attributes:
			int											m_Width;
			int											m_Height;
			int											m_ColourComponents;
			std::vector<shared_ptr<IfcBinary> >			m_Pixel;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform


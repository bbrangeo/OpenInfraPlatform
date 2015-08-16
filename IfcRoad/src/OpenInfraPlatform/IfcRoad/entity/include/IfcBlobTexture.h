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
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadObject.h"
#include "IfcSurfaceTexture.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		class IfcIdentifier;
		class IfcBinary;
		//ENTITY
		class IfcBlobTexture : public IfcSurfaceTexture
		{
		public:
			IfcBlobTexture();
			IfcBlobTexture( int id );
			~IfcBlobTexture();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcRoadEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcBlobTexture"; }


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

			// IfcBlobTexture -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcIdentifier>					m_RasterFormat;
			shared_ptr<IfcBinary>						m_RasterCode;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform


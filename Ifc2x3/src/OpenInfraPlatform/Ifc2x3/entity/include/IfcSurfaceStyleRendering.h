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
#include "IfcSurfaceStyleShading.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		class IfcNormalisedRatioMeasure;
		class IfcColourOrFactor;
		class IfcSpecularHighlightSelect;
		class IfcReflectanceMethodEnum;
		//ENTITY
		class IfcSurfaceStyleRendering : public IfcSurfaceStyleShading
		{
		public:
			IfcSurfaceStyleRendering();
			IfcSurfaceStyleRendering( int id );
			~IfcSurfaceStyleRendering();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc2x3Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcSurfaceStyleRendering"; }


			// IfcSurfaceStyleShading -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcColourRgb>						m_SurfaceColour;

			// IfcSurfaceStyleRendering -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcNormalisedRatioMeasure>		m_Transparency;				//optional
			shared_ptr<IfcColourOrFactor>				m_DiffuseColour;			//optional
			shared_ptr<IfcColourOrFactor>				m_TransmissionColour;		//optional
			shared_ptr<IfcColourOrFactor>				m_DiffuseTransmissionColour;	//optional
			shared_ptr<IfcColourOrFactor>				m_ReflectionColour;			//optional
			shared_ptr<IfcColourOrFactor>				m_SpecularColour;			//optional
			shared_ptr<IfcSpecularHighlightSelect>		m_SpecularHighlight;		//optional
			shared_ptr<IfcReflectanceMethodEnum>			m_ReflectanceMethod;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform


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
#include "IfcSurfaceStyleShading.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
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
			virtual void setEntity( shared_ptr<Ifc4Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcSurfaceStyleRendering"; }


			// IfcPresentationItem -----------------------------------------------------------

			// IfcSurfaceStyleShading -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcColourRgb>						m_SurfaceColour;
			//  shared_ptr<IfcNormalisedRatioMeasure>		m_Transparency;				//optional

			// IfcSurfaceStyleRendering -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcColourOrFactor>				m_DiffuseColour;			//optional
			shared_ptr<IfcColourOrFactor>				m_TransmissionColour;		//optional
			shared_ptr<IfcColourOrFactor>				m_DiffuseTransmissionColour;	//optional
			shared_ptr<IfcColourOrFactor>				m_ReflectionColour;			//optional
			shared_ptr<IfcColourOrFactor>				m_SpecularColour;			//optional
			shared_ptr<IfcSpecularHighlightSelect>		m_SpecularHighlight;		//optional
			shared_ptr<IfcReflectanceMethodEnum>			m_ReflectanceMethod;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform


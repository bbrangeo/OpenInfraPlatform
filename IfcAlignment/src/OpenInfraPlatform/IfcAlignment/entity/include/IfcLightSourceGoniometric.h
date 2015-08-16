/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Object.h"
#include "IfcLightSource.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcAxis2Placement3D;
		class IfcColourRgb;
		class IfcThermodynamicTemperatureMeasure;
		class IfcLuminousFluxMeasure;
		class IfcLightEmissionSourceEnum;
		class IfcLightDistributionDataSourceSelect;
		//ENTITY
		class IfcLightSourceGoniometric : public IfcLightSource
		{
		public:
			IfcLightSourceGoniometric();
			IfcLightSourceGoniometric( int id );
			~IfcLightSourceGoniometric();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcLightSourceGoniometric"; }


			// IfcRepresentationItem -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcPresentationLayerAssignment> >	m_LayerAssignment_inverse;
			//  std::vector<weak_ptr<IfcStyledItem> >			m_StyledByItem_inverse;

			// IfcGeometricRepresentationItem -----------------------------------------------------------

			// IfcLightSource -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>								m_Name;						//optional
			//  shared_ptr<IfcColourRgb>							m_LightColour;
			//  shared_ptr<IfcNormalisedRatioMeasure>			m_AmbientIntensity;			//optional
			//  shared_ptr<IfcNormalisedRatioMeasure>			m_Intensity;				//optional

			// IfcLightSourceGoniometric -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcAxis2Placement3D>					m_Position;
			shared_ptr<IfcColourRgb>							m_ColourAppearance;			//optional
			shared_ptr<IfcThermodynamicTemperatureMeasure>	m_ColourTemperature;
			shared_ptr<IfcLuminousFluxMeasure>				m_LuminousFlux;
			shared_ptr<IfcLightEmissionSourceEnum>			m_LightEmissionSource;
			shared_ptr<IfcLightDistributionDataSourceSelect>	m_LightDistributionDataSource;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform


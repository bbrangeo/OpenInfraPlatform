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
#include "IfcLightSource.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		class IfcCartesianPoint;
		class IfcPositiveLengthMeasure;
		//ENTITY
		class IfcLightSourcePositional : public IfcLightSource
		{
		public:
			IfcLightSourcePositional();
			IfcLightSourcePositional( int id );
			~IfcLightSourcePositional();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc4Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcLightSourcePositional"; }


			// IfcRepresentationItem -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcPresentationLayerAssignment> >	m_LayerAssignment_inverse;
			//  std::vector<weak_ptr<IfcStyledItem> >		m_StyledByItem_inverse;

			// IfcGeometricRepresentationItem -----------------------------------------------------------

			// IfcLightSource -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>							m_Name;						//optional
			//  shared_ptr<IfcColourRgb>						m_LightColour;
			//  shared_ptr<IfcNormalisedRatioMeasure>		m_AmbientIntensity;			//optional
			//  shared_ptr<IfcNormalisedRatioMeasure>		m_Intensity;				//optional

			// IfcLightSourcePositional -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcCartesianPoint>				m_Position;
			shared_ptr<IfcPositiveLengthMeasure>			m_Radius;
			double										m_ConstantAttenuation;
			double										m_DistanceAttenuation;
			double										m_QuadricAttenuation;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform


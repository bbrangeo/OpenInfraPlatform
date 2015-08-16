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
#include "IfcLightSourcePositional.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		class IfcDirection;
		class IfcReal;
		class IfcPositivePlaneAngleMeasure;
		//ENTITY
		class IfcLightSourceSpot : public IfcLightSourcePositional
		{
		public:
			IfcLightSourceSpot();
			IfcLightSourceSpot( int id );
			~IfcLightSourceSpot();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc2x3Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcLightSourceSpot"; }


			// IfcRepresentationItem -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcPresentationLayerAssignment> >	m_LayerAssignments_inverse;
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
			//  shared_ptr<IfcCartesianPoint>				m_Position;
			//  shared_ptr<IfcPositiveLengthMeasure>			m_Radius;
			//  shared_ptr<IfcReal>							m_ConstantAttenuation;
			//  shared_ptr<IfcReal>							m_DistanceAttenuation;
			//  shared_ptr<IfcReal>							m_QuadricAttenuation;

			// IfcLightSourceSpot -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcDirection>						m_Orientation;
			shared_ptr<IfcReal>							m_ConcentrationExponent;	//optional
			shared_ptr<IfcPositivePlaneAngleMeasure>		m_SpreadAngle;
			shared_ptr<IfcPositivePlaneAngleMeasure>		m_BeamWidthAngle;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

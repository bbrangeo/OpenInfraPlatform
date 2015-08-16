/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
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
#include "../../model/IfcTunnelObject.h"
#include "IfcParameterizedProfileDef.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		class IfcPositiveLengthMeasure;
		class IfcNonNegativeLengthMeasure;
		class IfcPlaneAngleMeasure;
		//ENTITY
		class IfcAsymmetricIShapeProfileDef : public IfcParameterizedProfileDef
		{
		public:
			IfcAsymmetricIShapeProfileDef();
			IfcAsymmetricIShapeProfileDef( int id );
			~IfcAsymmetricIShapeProfileDef();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcTunnelEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcAsymmetricIShapeProfileDef"; }


			// IfcProfileDef -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcProfileTypeEnum>				m_ProfileType;
			//  shared_ptr<IfcLabel>							m_ProfileName;				//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcExternalReferenceRelationship> >	m_HasExternalReference_inverse;
			//  std::vector<weak_ptr<IfcProfileProperties> >	m_HasProperties_inverse;

			// IfcParameterizedProfileDef -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcAxis2Placement2D>				m_Position;					//optional

			// IfcAsymmetricIShapeProfileDef -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcPositiveLengthMeasure>			m_BottomFlangeWidth;
			shared_ptr<IfcPositiveLengthMeasure>			m_OverallDepth;
			shared_ptr<IfcPositiveLengthMeasure>			m_WebThickness;
			shared_ptr<IfcPositiveLengthMeasure>			m_BottomFlangeThickness;
			shared_ptr<IfcNonNegativeLengthMeasure>		m_BottomFlangeFilletRadius;	//optional
			shared_ptr<IfcPositiveLengthMeasure>			m_TopFlangeWidth;
			shared_ptr<IfcPositiveLengthMeasure>			m_TopFlangeThickness;		//optional
			shared_ptr<IfcNonNegativeLengthMeasure>		m_TopFlangeFilletRadius;	//optional
			shared_ptr<IfcNonNegativeLengthMeasure>		m_BottomFlangeEdgeRadius;	//optional
			shared_ptr<IfcPlaneAngleMeasure>				m_BottomFlangeSlope;		//optional
			shared_ptr<IfcNonNegativeLengthMeasure>		m_TopFlangeEdgeRadius;		//optional
			shared_ptr<IfcPlaneAngleMeasure>				m_TopFlangeSlope;			//optional
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform


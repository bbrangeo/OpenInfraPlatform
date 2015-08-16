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
#include "IfcParameterizedProfileDef.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		class IfcPositiveLengthMeasure;
		//ENTITY
		class IfcCraneRailAShapeProfileDef : public IfcParameterizedProfileDef
		{
		public:
			IfcCraneRailAShapeProfileDef();
			IfcCraneRailAShapeProfileDef( int id );
			~IfcCraneRailAShapeProfileDef();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc2x3Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcCraneRailAShapeProfileDef"; }


			// IfcProfileDef -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcProfileTypeEnum>				m_ProfileType;
			//  shared_ptr<IfcLabel>							m_ProfileName;				//optional

			// IfcParameterizedProfileDef -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcAxis2Placement2D>				m_Position;

			// IfcCraneRailAShapeProfileDef -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcPositiveLengthMeasure>			m_OverallHeight;
			shared_ptr<IfcPositiveLengthMeasure>			m_BaseWidth2;
			shared_ptr<IfcPositiveLengthMeasure>			m_Radius;					//optional
			shared_ptr<IfcPositiveLengthMeasure>			m_HeadWidth;
			shared_ptr<IfcPositiveLengthMeasure>			m_HeadDepth2;
			shared_ptr<IfcPositiveLengthMeasure>			m_HeadDepth3;
			shared_ptr<IfcPositiveLengthMeasure>			m_WebThickness;
			shared_ptr<IfcPositiveLengthMeasure>			m_BaseWidth4;
			shared_ptr<IfcPositiveLengthMeasure>			m_BaseDepth1;
			shared_ptr<IfcPositiveLengthMeasure>			m_BaseDepth2;
			shared_ptr<IfcPositiveLengthMeasure>			m_BaseDepth3;
			shared_ptr<IfcPositiveLengthMeasure>			m_CentreOfGravityInY;		//optional
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform


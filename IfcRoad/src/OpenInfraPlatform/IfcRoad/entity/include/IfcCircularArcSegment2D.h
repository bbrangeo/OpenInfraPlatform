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
#include "IfcCurveSegment2D.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		class IfcPositiveLengthMeasure;
		class IfcBoolean;
		//ENTITY
		class IfcCircularArcSegment2D : public IfcCurveSegment2D
		{
		public:
			IfcCircularArcSegment2D();
			IfcCircularArcSegment2D( int id );
			~IfcCircularArcSegment2D();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcRoadEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcCircularArcSegment2D"; }


			// IfcRepresentationItem -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcPresentationLayerAssignment> >	m_LayerAssignment_inverse;
			//  std::vector<weak_ptr<IfcStyledItem> >		m_StyledByItem_inverse;

			// IfcGeometricRepresentationItem -----------------------------------------------------------

			// IfcCurve -----------------------------------------------------------

			// IfcBoundedCurve -----------------------------------------------------------

			// IfcCurveSegment2D -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcCartesianPoint>				m_StartPoint;
			//  shared_ptr<IfcPlaneAngleMeasure>				m_StartDirection;
			//  shared_ptr<IfcPositiveLengthMeasure>			m_SegmentLength;

			// IfcCircularArcSegment2D -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcPositiveLengthMeasure>			m_Radius;
			shared_ptr<IfcBoolean>						m_IsCcw;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform


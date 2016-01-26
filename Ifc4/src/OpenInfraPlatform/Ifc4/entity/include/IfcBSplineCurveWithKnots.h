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
#include "IfcBSplineCurve.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		class IfcParameterValue;
		class IfcKnotType;
		//ENTITY
		class IfcBSplineCurveWithKnots : public IfcBSplineCurve
		{
		public:
			IfcBSplineCurveWithKnots();
			IfcBSplineCurveWithKnots( int id );
			~IfcBSplineCurveWithKnots();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc4Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcBSplineCurveWithKnots"; }


			// IfcRepresentationItem -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcPresentationLayerAssignment> >	m_LayerAssignment_inverse;
			//  std::vector<weak_ptr<IfcStyledItem> >		m_StyledByItem_inverse;

			// IfcGeometricRepresentationItem -----------------------------------------------------------

			// IfcCurve -----------------------------------------------------------

			// IfcBoundedCurve -----------------------------------------------------------

			// IfcBSplineCurve -----------------------------------------------------------
			// attributes:
			//  int											m_Degree;
			//  std::vector<shared_ptr<IfcCartesianPoint> >	m_ControlPointsList;
			//  shared_ptr<IfcBSplineCurveForm>				m_CurveForm;
			//  shared_ptr<IfcLogical>						m_ClosedCurve;
			//  shared_ptr<IfcLogical>						m_SelfIntersect;

			// IfcBSplineCurveWithKnots -----------------------------------------------------------
			// attributes:
			std::vector<int >							m_KnotMultiplicities;
			std::vector<shared_ptr<IfcParameterValue> >	m_Knots;
			shared_ptr<IfcKnotType>						m_KnotSpec;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform


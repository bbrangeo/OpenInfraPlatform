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
#include "IfcFillStyleSelect.h"
#include "IfcGeometricRepresentationItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		class IfcCurveStyle;
		class IfcHatchLineDistanceSelect;
		class IfcCartesianPoint;
		class IfcPlaneAngleMeasure;
		//ENTITY
		class IfcFillAreaStyleHatching : public IfcFillStyleSelect, public IfcGeometricRepresentationItem
		{
		public:
			IfcFillAreaStyleHatching();
			IfcFillAreaStyleHatching( int id );
			~IfcFillAreaStyleHatching();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc2x3Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcFillAreaStyleHatching"; }


			// IfcRepresentationItem -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcPresentationLayerAssignment> >	m_LayerAssignments_inverse;
			//  std::vector<weak_ptr<IfcStyledItem> >		m_StyledByItem_inverse;

			// IfcGeometricRepresentationItem -----------------------------------------------------------

			// IfcFillAreaStyleHatching -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcCurveStyle>					m_HatchLineAppearance;
			shared_ptr<IfcHatchLineDistanceSelect>		m_StartOfNextHatchLine;
			shared_ptr<IfcCartesianPoint>				m_PointOfReferenceHatchLine;	//optional
			shared_ptr<IfcCartesianPoint>				m_PatternStart;				//optional
			shared_ptr<IfcPlaneAngleMeasure>				m_HatchLineAngle;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform


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
#include "IfcBoundedSurface.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		class IfcCartesianPoint;
		class IfcBSplineSurfaceForm;
		class IfcLogical;
		//ENTITY
		class IfcBSplineSurface : public IfcBoundedSurface
		{
		public:
			IfcBSplineSurface();
			IfcBSplineSurface( int id );
			~IfcBSplineSurface();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcRoadEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcBSplineSurface"; }


			// IfcRepresentationItem -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcPresentationLayerAssignment> >	m_LayerAssignment_inverse;
			//  std::vector<weak_ptr<IfcStyledItem> >		m_StyledByItem_inverse;

			// IfcGeometricRepresentationItem -----------------------------------------------------------

			// IfcSurface -----------------------------------------------------------

			// IfcBoundedSurface -----------------------------------------------------------

			// IfcBSplineSurface -----------------------------------------------------------
			// attributes:
			int											m_UDegree;
			int											m_VDegree;
			std::vector<std::vector<shared_ptr<IfcCartesianPoint> > >	m_ControlPointsList;
			shared_ptr<IfcBSplineSurfaceForm>			m_SurfaceForm;
			shared_ptr<IfcLogical>						m_UClosed;
			shared_ptr<IfcLogical>						m_VClosed;
			shared_ptr<IfcLogical>						m_SelfIntersect;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform


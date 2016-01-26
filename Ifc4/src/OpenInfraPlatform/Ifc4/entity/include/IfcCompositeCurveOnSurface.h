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
#include "IfcCurveOnSurface.h"
#include "IfcCompositeCurve.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		//ENTITY
		class IfcCompositeCurveOnSurface : public IfcCurveOnSurface, public IfcCompositeCurve
		{
		public:
			IfcCompositeCurveOnSurface();
			IfcCompositeCurveOnSurface( int id );
			~IfcCompositeCurveOnSurface();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc4Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcCompositeCurveOnSurface"; }


			// IfcRepresentationItem -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcPresentationLayerAssignment> >	m_LayerAssignment_inverse;
			//  std::vector<weak_ptr<IfcStyledItem> >		m_StyledByItem_inverse;

			// IfcGeometricRepresentationItem -----------------------------------------------------------

			// IfcCurve -----------------------------------------------------------

			// IfcBoundedCurve -----------------------------------------------------------

			// IfcCompositeCurve -----------------------------------------------------------
			// attributes:
			//  std::vector<shared_ptr<IfcCompositeCurveSegment> >	m_Segments;
			//  shared_ptr<IfcLogical>						m_SelfIntersect;

			// IfcCompositeCurveOnSurface -----------------------------------------------------------
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform


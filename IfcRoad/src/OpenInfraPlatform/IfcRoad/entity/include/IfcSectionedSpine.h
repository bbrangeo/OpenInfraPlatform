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
#include "IfcGeometricRepresentationItem.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		class IfcCompositeCurve;
		class IfcProfileDef;
		class IfcAxis2Placement3D;
		//ENTITY
		class IfcSectionedSpine : public IfcGeometricRepresentationItem
		{
		public:
			IfcSectionedSpine();
			IfcSectionedSpine( int id );
			~IfcSectionedSpine();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcRoadEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcSectionedSpine"; }


			// IfcRepresentationItem -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcPresentationLayerAssignment> >	m_LayerAssignment_inverse;
			//  std::vector<weak_ptr<IfcStyledItem> >			m_StyledByItem_inverse;

			// IfcGeometricRepresentationItem -----------------------------------------------------------

			// IfcSectionedSpine -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcCompositeCurve>					m_SpineCurve;
			std::vector<shared_ptr<IfcProfileDef> >			m_CrossSections;
			std::vector<shared_ptr<IfcAxis2Placement3D> >	m_CrossSectionPositions;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform


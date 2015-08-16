/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
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
#include "../../model/IfcBridgeObject.h"
#include "IfcReferencePlacement.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		class IfcLengthMeasure;
		class IfcDirection;
		class IfcReferenceCurvePlacementSystem;
		//ENTITY
		class IfcReferenceCurvePlacement : public IfcReferencePlacement
		{
		public:
			IfcReferenceCurvePlacement();
			IfcReferenceCurvePlacement( int id );
			~IfcReferenceCurvePlacement();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcBridgeEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcReferenceCurvePlacement"; }


			// IfcObjectPlacement -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcProduct> >			m_PlacesObject_inverse;
			//  std::vector<weak_ptr<IfcLocalPlacement> >	m_ReferencedByPlacements_inverse;

			// IfcReferencePlacement -----------------------------------------------------------

			// IfcReferenceCurvePlacement -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcLengthMeasure>					m_CurvilinearAbscissa;
			shared_ptr<IfcDirection>						m_Axis;
			shared_ptr<IfcDirection>						m_RefDirection;
			shared_ptr<IfcReferenceCurvePlacementSystem>	m_RelativeTo;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform


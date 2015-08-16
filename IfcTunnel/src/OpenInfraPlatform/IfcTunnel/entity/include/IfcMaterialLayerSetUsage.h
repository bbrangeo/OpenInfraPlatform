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
#include "IfcMaterialUsageDefinition.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		class IfcMaterialLayerSet;
		class IfcLayerSetDirectionEnum;
		class IfcDirectionSenseEnum;
		class IfcLengthMeasure;
		class IfcPositiveLengthMeasure;
		//ENTITY
		class IfcMaterialLayerSetUsage : public IfcMaterialUsageDefinition
		{
		public:
			IfcMaterialLayerSetUsage();
			IfcMaterialLayerSetUsage( int id );
			~IfcMaterialLayerSetUsage();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcTunnelEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcMaterialLayerSetUsage"; }


			// IfcMaterialUsageDefinition -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelAssociatesMaterial> >	m_AssociatedTo_inverse;

			// IfcMaterialLayerSetUsage -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcMaterialLayerSet>				m_ForLayerSet;
			shared_ptr<IfcLayerSetDirectionEnum>			m_LayerSetDirection;
			shared_ptr<IfcDirectionSenseEnum>			m_DirectionSense;
			shared_ptr<IfcLengthMeasure>					m_OffsetFromReferenceLine;
			shared_ptr<IfcPositiveLengthMeasure>			m_ReferenceExtent;			//optional
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform


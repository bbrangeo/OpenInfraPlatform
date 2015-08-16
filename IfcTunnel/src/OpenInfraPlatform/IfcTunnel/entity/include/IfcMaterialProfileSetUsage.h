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
		class IfcMaterialProfileSet;
		class IfcCardinalPointReference;
		class IfcPositiveLengthMeasure;
		//ENTITY
		class IfcMaterialProfileSetUsage : public IfcMaterialUsageDefinition
		{
		public:
			IfcMaterialProfileSetUsage();
			IfcMaterialProfileSetUsage( int id );
			~IfcMaterialProfileSetUsage();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcTunnelEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcMaterialProfileSetUsage"; }


			// IfcMaterialUsageDefinition -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelAssociatesMaterial> >	m_AssociatedTo_inverse;

			// IfcMaterialProfileSetUsage -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcMaterialProfileSet>			m_ForProfileSet;
			shared_ptr<IfcCardinalPointReference>		m_CardinalPoint;			//optional
			shared_ptr<IfcPositiveLengthMeasure>			m_ReferenceExtent;			//optional
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform


/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "OpenInfraPlatform/Ifc4/writer/WriterUtil.h"
#include "OpenInfraPlatform/Ifc4/Ifc4EntityEnums.h"
#include "include/IfcLightDistributionCurveEnum.h"
#include "include/IfcLightDistributionData.h"
#include "include/IfcLightIntensityDistribution.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcLightIntensityDistribution 
		IfcLightIntensityDistribution::IfcLightIntensityDistribution() { m_entity_enum = IFCLIGHTINTENSITYDISTRIBUTION; }
		IfcLightIntensityDistribution::IfcLightIntensityDistribution( int id ) { m_id = id; m_entity_enum = IFCLIGHTINTENSITYDISTRIBUTION; }
		IfcLightIntensityDistribution::~IfcLightIntensityDistribution() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcLightIntensityDistribution::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcLightIntensityDistribution> other = dynamic_pointer_cast<IfcLightIntensityDistribution>(other_entity);
			if( !other) { return; }
			m_LightDistributionCurve = other->m_LightDistributionCurve;
			m_DistributionData = other->m_DistributionData;
		}
		void IfcLightIntensityDistribution::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCLIGHTINTENSITYDISTRIBUTION" << "(";
			if( m_LightDistributionCurve ) { m_LightDistributionCurve->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_DistributionData );
			stream << ");";
		}
		void IfcLightIntensityDistribution::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcLightIntensityDistribution::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcLightIntensityDistribution, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcLightIntensityDistribution, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_LightDistributionCurve = IfcLightDistributionCurveEnum::readStepData( args[0] );
			readEntityReferenceList( args[1], m_DistributionData, map );
		}
		void IfcLightIntensityDistribution::setInverseCounterparts( shared_ptr<Ifc4Entity> )
		{
		}
		void IfcLightIntensityDistribution::unlinkSelf()
		{
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

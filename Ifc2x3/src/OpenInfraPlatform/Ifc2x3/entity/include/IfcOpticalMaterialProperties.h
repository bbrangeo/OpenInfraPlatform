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
#include "IfcMaterialProperties.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		class IfcPositiveRatioMeasure;
		//ENTITY
		class IfcOpticalMaterialProperties : public IfcMaterialProperties
		{
		public:
			IfcOpticalMaterialProperties();
			IfcOpticalMaterialProperties( int id );
			~IfcOpticalMaterialProperties();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc2x3Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcOpticalMaterialProperties"; }


			// IfcMaterialProperties -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcMaterial>						m_Material;

			// IfcOpticalMaterialProperties -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcPositiveRatioMeasure>			m_VisibleTransmittance;		//optional
			shared_ptr<IfcPositiveRatioMeasure>			m_SolarTransmittance;		//optional
			shared_ptr<IfcPositiveRatioMeasure>			m_ThermalIrTransmittance;	//optional
			shared_ptr<IfcPositiveRatioMeasure>			m_ThermalIrEmissivityBack;	//optional
			shared_ptr<IfcPositiveRatioMeasure>			m_ThermalIrEmissivityFront;	//optional
			shared_ptr<IfcPositiveRatioMeasure>			m_VisibleReflectanceBack;	//optional
			shared_ptr<IfcPositiveRatioMeasure>			m_VisibleReflectanceFront;	//optional
			shared_ptr<IfcPositiveRatioMeasure>			m_SolarReflectanceFront;	//optional
			shared_ptr<IfcPositiveRatioMeasure>			m_SolarReflectanceBack;		//optional
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform


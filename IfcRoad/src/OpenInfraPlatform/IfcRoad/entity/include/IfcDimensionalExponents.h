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

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		//ENTITY
		class IfcDimensionalExponents : public IfcRoadEntity
		{
		public:
			IfcDimensionalExponents();
			IfcDimensionalExponents( int id );
			~IfcDimensionalExponents();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcRoadEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcDimensionalExponents"; }


			// IfcDimensionalExponents -----------------------------------------------------------
			// attributes:
			int											m_LengthExponent;
			int											m_MassExponent;
			int											m_TimeExponent;
			int											m_ElectricCurrentExponent;
			int											m_ThermodynamicTemperatureExponent;
			int											m_AmountOfSubstanceExponent;
			int											m_LuminousIntensityExponent;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform


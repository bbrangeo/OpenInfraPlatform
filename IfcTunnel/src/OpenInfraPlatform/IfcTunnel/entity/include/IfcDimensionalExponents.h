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

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		//ENTITY
		class IfcDimensionalExponents : public IfcTunnelEntity
		{
		public:
			IfcDimensionalExponents();
			IfcDimensionalExponents( int id );
			~IfcDimensionalExponents();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcTunnelEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self );
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
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform


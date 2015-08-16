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
#include "IfcResourceLevelRelationship.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		class IfcMonetaryUnit;
		class IfcPositiveRatioMeasure;
		class IfcDateTime;
		class IfcLibraryInformation;
		//ENTITY
		class IfcCurrencyRelationship : public IfcResourceLevelRelationship
		{
		public:
			IfcCurrencyRelationship();
			IfcCurrencyRelationship( int id );
			~IfcCurrencyRelationship();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcTunnelEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcCurrencyRelationship"; }


			// IfcResourceLevelRelationship -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>							m_Name;						//optional
			//  shared_ptr<IfcText>							m_Description;				//optional

			// IfcCurrencyRelationship -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcMonetaryUnit>					m_RelatingMonetaryUnit;
			shared_ptr<IfcMonetaryUnit>					m_RelatedMonetaryUnit;
			shared_ptr<IfcPositiveRatioMeasure>			m_ExchangeRate;
			shared_ptr<IfcDateTime>						m_RateDateTime;				//optional
			shared_ptr<IfcLibraryInformation>			m_RateSource;				//optional
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform


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
#include "IfcColourOrFactor.h"
#include "IfcColourSpecification.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		class IfcNormalisedRatioMeasure;
		//ENTITY
		class IfcColourRgb : public IfcColourOrFactor, public IfcColourSpecification
		{
		public:
			IfcColourRgb();
			IfcColourRgb( int id );
			~IfcColourRgb();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcTunnelEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcColourRgb"; }


			// IfcPresentationItem -----------------------------------------------------------

			// IfcColourSpecification -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>							m_Name;						//optional

			// IfcColourRgb -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcNormalisedRatioMeasure>		m_Red;
			shared_ptr<IfcNormalisedRatioMeasure>		m_Green;
			shared_ptr<IfcNormalisedRatioMeasure>		m_Blue;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform


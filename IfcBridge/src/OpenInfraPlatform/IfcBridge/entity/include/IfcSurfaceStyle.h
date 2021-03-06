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
#include "IfcPresentationStyleSelect.h"
#include "IfcPresentationStyle.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		class IfcSurfaceSide;
		class IfcSurfaceStyleElementSelect;
		//ENTITY
		class IfcSurfaceStyle : public IfcPresentationStyleSelect, public IfcPresentationStyle
		{
		public:
			IfcSurfaceStyle();
			IfcSurfaceStyle( int id );
			~IfcSurfaceStyle();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcBridgeEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcSurfaceStyle"; }


			// IfcPresentationStyle -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>										m_Name;						//optional

			// IfcSurfaceStyle -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcSurfaceSide>								m_Side;
			std::vector<shared_ptr<IfcSurfaceStyleElementSelect> >	m_Styles;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform


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
#include "IfcSurfaceStyleElementSelect.h"
#include "IfcPresentationItem.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		class IfcColourRgb;
		//ENTITY
		class IfcSurfaceStyleShading : public IfcSurfaceStyleElementSelect, public IfcPresentationItem
		{
		public:
			IfcSurfaceStyleShading();
			IfcSurfaceStyleShading( int id );
			~IfcSurfaceStyleShading();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcBridgeEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcSurfaceStyleShading"; }


			// IfcPresentationItem -----------------------------------------------------------

			// IfcSurfaceStyleShading -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcColourRgb>						m_SurfaceColour;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform


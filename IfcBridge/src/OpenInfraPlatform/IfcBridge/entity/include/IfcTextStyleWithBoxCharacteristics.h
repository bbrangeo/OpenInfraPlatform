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
#include "IfcTextStyleSelect.h"
#include "IfcPresentationItem.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		class IfcPositiveLengthMeasure;
		class IfcPlaneAngleMeasure;
		class IfcSizeSelect;
		//ENTITY
		class IfcTextStyleWithBoxCharacteristics : public IfcTextStyleSelect, public IfcPresentationItem
		{
		public:
			IfcTextStyleWithBoxCharacteristics();
			IfcTextStyleWithBoxCharacteristics( int id );
			~IfcTextStyleWithBoxCharacteristics();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcBridgeEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcTextStyleWithBoxCharacteristics"; }


			// IfcPresentationItem -----------------------------------------------------------

			// IfcTextStyleWithBoxCharacteristics -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcPositiveLengthMeasure>			m_BoxHeight;				//optional
			shared_ptr<IfcPositiveLengthMeasure>			m_BoxWidth;					//optional
			shared_ptr<IfcPlaneAngleMeasure>				m_BoxSlantAngle;			//optional
			shared_ptr<IfcPlaneAngleMeasure>				m_BoxRotateAngle;			//optional
			shared_ptr<IfcSizeSelect>					m_CharacterSpacing;			//optional
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform


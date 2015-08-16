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
#include "IfcTextStyleSelect.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		class IfcPositiveLengthMeasure;
		class IfcPlaneAngleMeasure;
		class IfcSizeSelect;
		//ENTITY
		class IfcTextStyleWithBoxCharacteristics : public IfcTextStyleSelect, public Ifc2x3Entity
		{
		public:
			IfcTextStyleWithBoxCharacteristics();
			IfcTextStyleWithBoxCharacteristics( int id );
			~IfcTextStyleWithBoxCharacteristics();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc2x3Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcTextStyleWithBoxCharacteristics"; }


			// IfcTextStyleWithBoxCharacteristics -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcPositiveLengthMeasure>			m_BoxHeight;				//optional
			shared_ptr<IfcPositiveLengthMeasure>			m_BoxWidth;					//optional
			shared_ptr<IfcPlaneAngleMeasure>				m_BoxSlantAngle;			//optional
			shared_ptr<IfcPlaneAngleMeasure>				m_BoxRotateAngle;			//optional
			shared_ptr<IfcSizeSelect>					m_CharacterSpacing;			//optional
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform


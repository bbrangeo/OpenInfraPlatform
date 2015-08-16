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
#include "IfcStructuralLoadOrResult.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		class IfcLengthMeasure;
		class IfcRatioMeasure;
		//ENTITY
		class IfcSurfaceReinforcementArea : public IfcStructuralLoadOrResult
		{
		public:
			IfcSurfaceReinforcementArea();
			IfcSurfaceReinforcementArea( int id );
			~IfcSurfaceReinforcementArea();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcBridgeEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcSurfaceReinforcementArea"; }


			// IfcStructuralLoad -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>							m_Name;						//optional

			// IfcStructuralLoadOrResult -----------------------------------------------------------

			// IfcSurfaceReinforcementArea -----------------------------------------------------------
			// attributes:
			std::vector<shared_ptr<IfcLengthMeasure> >	m_SurfaceReinforcement1;	//optional
			std::vector<shared_ptr<IfcLengthMeasure> >	m_SurfaceReinforcement2;	//optional
			shared_ptr<IfcRatioMeasure>					m_ShearReinforcement;		//optional
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform


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
#include "IfcBoundaryCondition.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		class IfcModulusOfSubgradeReactionSelect;
		//ENTITY
		class IfcBoundaryFaceCondition : public IfcBoundaryCondition
		{
		public:
			IfcBoundaryFaceCondition();
			IfcBoundaryFaceCondition( int id );
			~IfcBoundaryFaceCondition();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcTunnelEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcBoundaryFaceCondition"; }


			// IfcBoundaryCondition -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>								m_Name;						//optional

			// IfcBoundaryFaceCondition -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcModulusOfSubgradeReactionSelect>	m_TranslationalStiffnessByAreaX;	//optional
			shared_ptr<IfcModulusOfSubgradeReactionSelect>	m_TranslationalStiffnessByAreaY;	//optional
			shared_ptr<IfcModulusOfSubgradeReactionSelect>	m_TranslationalStiffnessByAreaZ;	//optional
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform


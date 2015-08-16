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
#include "IfcRelAssociates.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		class IfcProfileProperties;
		class IfcShapeAspect;
		class IfcOrientationSelect;
		//ENTITY
		class IfcRelAssociatesProfileProperties : public IfcRelAssociates
		{
		public:
			IfcRelAssociatesProfileProperties();
			IfcRelAssociatesProfileProperties( int id );
			~IfcRelAssociatesProfileProperties();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc2x3Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcRelAssociatesProfileProperties"; }


			// IfcRoot -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcGloballyUniqueId>				m_GlobalId;
			//  shared_ptr<IfcOwnerHistory>					m_OwnerHistory;
			//  shared_ptr<IfcLabel>							m_Name;						//optional
			//  shared_ptr<IfcText>							m_Description;				//optional

			// IfcRelationship -----------------------------------------------------------

			// IfcRelAssociates -----------------------------------------------------------
			// attributes:
			//  std::vector<shared_ptr<IfcRoot> >			m_RelatedObjects;

			// IfcRelAssociatesProfileProperties -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcProfileProperties>				m_RelatingProfileProperties;
			shared_ptr<IfcShapeAspect>					m_ProfileSectionLocation;	//optional
			shared_ptr<IfcOrientationSelect>				m_ProfileOrientation;		//optional
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform


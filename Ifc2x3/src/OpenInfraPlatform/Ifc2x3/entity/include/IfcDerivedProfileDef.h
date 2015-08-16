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
#include "IfcProfileDef.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		class IfcProfileDef;
		class IfcCartesianTransformationOperator2D;
		class IfcLabel;
		//ENTITY
		class IfcDerivedProfileDef : public IfcProfileDef
		{
		public:
			IfcDerivedProfileDef();
			IfcDerivedProfileDef( int id );
			~IfcDerivedProfileDef();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc2x3Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcDerivedProfileDef"; }


			// IfcProfileDef -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcProfileTypeEnum>					m_ProfileType;
			//  shared_ptr<IfcLabel>								m_ProfileName;				//optional

			// IfcDerivedProfileDef -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcProfileDef>						m_ParentProfile;
			shared_ptr<IfcCartesianTransformationOperator2D>	m_Operator;
			shared_ptr<IfcLabel>								m_Label;					//optional
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform


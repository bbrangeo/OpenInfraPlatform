/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Object.h"
#include "IfcRectangleProfileDef.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcPositiveLengthMeasure;
		class IfcNonNegativeLengthMeasure;
		//ENTITY
		class IfcRectangleHollowProfileDef : public IfcRectangleProfileDef
		{
		public:
			IfcRectangleHollowProfileDef();
			IfcRectangleHollowProfileDef( int id );
			~IfcRectangleHollowProfileDef();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcRectangleHollowProfileDef"; }


			// IfcProfileDef -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcProfileTypeEnum>				m_ProfileType;
			//  shared_ptr<IfcLabel>							m_ProfileName;				//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcExternalReferenceRelationship> >	m_HasExternalReference_inverse;
			//  std::vector<weak_ptr<IfcProfileProperties> >	m_HasProperties_inverse;

			// IfcParameterizedProfileDef -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcAxis2Placement2D>				m_Position;					//optional

			// IfcRectangleProfileDef -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcPositiveLengthMeasure>			m_XDim;
			//  shared_ptr<IfcPositiveLengthMeasure>			m_YDim;

			// IfcRectangleHollowProfileDef -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcPositiveLengthMeasure>			m_WallThickness;
			shared_ptr<IfcNonNegativeLengthMeasure>		m_InnerFilletRadius;		//optional
			shared_ptr<IfcNonNegativeLengthMeasure>		m_OuterFilletRadius;		//optional
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform


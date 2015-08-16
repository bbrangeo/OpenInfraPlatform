/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadObject.h"
#include "IfcAlignment2DSegment.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		class IfcCurveSegment2D;
		class IfcAlignment2DHorizontal;
		//ENTITY
		class IfcAlignment2DHorizontalSegment : public IfcAlignment2DSegment
		{
		public:
			IfcAlignment2DHorizontalSegment();
			IfcAlignment2DHorizontalSegment( int id );
			~IfcAlignment2DHorizontalSegment();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcRoadEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcAlignment2DHorizontalSegment"; }


			// IfcAlignment2DSegment -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcBoolean>							m_TangentialContinuity;		//optional
			//  shared_ptr<IfcLabel>								m_StartTag;					//optional
			//  shared_ptr<IfcLabel>								m_EndTag;					//optional

			// IfcAlignment2DHorizontalSegment -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcCurveSegment2D>					m_CurveGeometry;
			// inverse attributes:
			std::vector<weak_ptr<IfcAlignment2DHorizontal> >	m_ToHorizontal_inverse;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform


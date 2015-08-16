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
#include "IfcAlignment2DVerticalSegment.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		//ENTITY
		class IfcAlignment2DVerSegLine : public IfcAlignment2DVerticalSegment
		{
		public:
			IfcAlignment2DVerSegLine();
			IfcAlignment2DVerSegLine( int id );
			~IfcAlignment2DVerSegLine();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcRoadEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcAlignment2DVerSegLine"; }


			// IfcAlignment2DSegment -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcBoolean>						m_TangentialContinuity;		//optional
			//  shared_ptr<IfcLabel>							m_StartTag;					//optional
			//  shared_ptr<IfcLabel>							m_EndTag;					//optional

			// IfcAlignment2DVerticalSegment -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLengthMeasure>					m_StartDistAlong;
			//  shared_ptr<IfcPositiveLengthMeasure>			m_HorizontalLength;
			//  shared_ptr<IfcLengthMeasure>					m_StartHeight;
			//  shared_ptr<IfcRatioMeasure>					m_StartGradient;
			// inverse attributes:
			//  std::vector<weak_ptr<IfcAlignment2DVertical> >	m_ToVertical_inverse;

			// IfcAlignment2DVerSegLine -----------------------------------------------------------
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform


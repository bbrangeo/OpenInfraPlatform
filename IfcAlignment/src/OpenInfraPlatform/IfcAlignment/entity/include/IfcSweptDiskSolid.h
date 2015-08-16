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
#include "IfcSolidModel.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcCurve;
		class IfcPositiveLengthMeasure;
		class IfcParameterValue;
		//ENTITY
		class IfcSweptDiskSolid : public IfcSolidModel
		{
		public:
			IfcSweptDiskSolid();
			IfcSweptDiskSolid( int id );
			~IfcSweptDiskSolid();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcSweptDiskSolid"; }


			// IfcRepresentationItem -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcPresentationLayerAssignment> >	m_LayerAssignment_inverse;
			//  std::vector<weak_ptr<IfcStyledItem> >		m_StyledByItem_inverse;

			// IfcGeometricRepresentationItem -----------------------------------------------------------

			// IfcSolidModel -----------------------------------------------------------

			// IfcSweptDiskSolid -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcCurve>							m_Directrix;
			shared_ptr<IfcPositiveLengthMeasure>			m_Radius;
			shared_ptr<IfcPositiveLengthMeasure>			m_InnerRadius;				//optional
			shared_ptr<IfcParameterValue>				m_StartParam;				//optional
			shared_ptr<IfcParameterValue>				m_EndParam;					//optional
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

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
#include "IfcCartesianTransformationOperator2D.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcReal;
		//ENTITY
		class IfcCartesianTransformationOperator2DnonUniform : public IfcCartesianTransformationOperator2D
		{
		public:
			IfcCartesianTransformationOperator2DnonUniform();
			IfcCartesianTransformationOperator2DnonUniform( int id );
			~IfcCartesianTransformationOperator2DnonUniform();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcCartesianTransformationOperator2DnonUniform"; }


			// IfcRepresentationItem -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcPresentationLayerAssignment> >	m_LayerAssignment_inverse;
			//  std::vector<weak_ptr<IfcStyledItem> >		m_StyledByItem_inverse;

			// IfcGeometricRepresentationItem -----------------------------------------------------------

			// IfcCartesianTransformationOperator -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcDirection>						m_Axis1;					//optional
			//  shared_ptr<IfcDirection>						m_Axis2;					//optional
			//  shared_ptr<IfcCartesianPoint>				m_LocalOrigin;
			//  shared_ptr<IfcReal>							m_Scale;					//optional

			// IfcCartesianTransformationOperator2D -----------------------------------------------------------

			// IfcCartesianTransformationOperator2DnonUniform -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcReal>							m_Scale2;					//optional
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform


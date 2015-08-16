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
#include "IfcCartesianTransformationOperator3D.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		class IfcReal;
		//ENTITY
		class IfcCartesianTransformationOperator3DnonUniform : public IfcCartesianTransformationOperator3D
		{
		public:
			IfcCartesianTransformationOperator3DnonUniform();
			IfcCartesianTransformationOperator3DnonUniform( int id );
			~IfcCartesianTransformationOperator3DnonUniform();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcRoadEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcCartesianTransformationOperator3DnonUniform"; }


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

			// IfcCartesianTransformationOperator3D -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcDirection>						m_Axis3;					//optional

			// IfcCartesianTransformationOperator3DnonUniform -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcReal>							m_Scale2;					//optional
			shared_ptr<IfcReal>							m_Scale3;					//optional
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform


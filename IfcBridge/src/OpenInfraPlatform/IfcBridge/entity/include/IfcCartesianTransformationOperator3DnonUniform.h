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
#include "IfcCartesianTransformationOperator3D.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		//ENTITY
		class IfcCartesianTransformationOperator3DnonUniform : public IfcCartesianTransformationOperator3D
		{
		public:
			IfcCartesianTransformationOperator3DnonUniform();
			IfcCartesianTransformationOperator3DnonUniform( int id );
			~IfcCartesianTransformationOperator3DnonUniform();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcBridgeEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self );
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
			//  double										m_Scale;					//optional

			// IfcCartesianTransformationOperator3D -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcDirection>						m_Axis3;					//optional

			// IfcCartesianTransformationOperator3DnonUniform -----------------------------------------------------------
			// attributes:
			double										m_Scale2;					//optional
			double										m_Scale3;					//optional
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform


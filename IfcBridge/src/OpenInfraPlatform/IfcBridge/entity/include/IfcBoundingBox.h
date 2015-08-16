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
#include "IfcGeometricRepresentationItem.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		class IfcCartesianPoint;
		class IfcPositiveLengthMeasure;
		//ENTITY
		class IfcBoundingBox : public IfcGeometricRepresentationItem
		{
		public:
			IfcBoundingBox();
			IfcBoundingBox( int id );
			~IfcBoundingBox();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcBridgeEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcBoundingBox"; }


			// IfcRepresentationItem -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcPresentationLayerAssignment> >	m_LayerAssignment_inverse;
			//  std::vector<weak_ptr<IfcStyledItem> >		m_StyledByItem_inverse;

			// IfcGeometricRepresentationItem -----------------------------------------------------------

			// IfcBoundingBox -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcCartesianPoint>				m_Corner;
			shared_ptr<IfcPositiveLengthMeasure>			m_XDim;
			shared_ptr<IfcPositiveLengthMeasure>			m_YDim;
			shared_ptr<IfcPositiveLengthMeasure>			m_ZDim;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform


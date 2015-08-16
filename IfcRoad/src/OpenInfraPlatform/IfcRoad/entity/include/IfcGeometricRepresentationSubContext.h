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
#include "IfcGeometricRepresentationContext.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		class IfcGeometricRepresentationContext;
		class IfcPositiveRatioMeasure;
		class IfcGeometricProjectionEnum;
		class IfcLabel;
		//ENTITY
		class IfcGeometricRepresentationSubContext : public IfcGeometricRepresentationContext
		{
		public:
			IfcGeometricRepresentationSubContext();
			IfcGeometricRepresentationSubContext( int id );
			~IfcGeometricRepresentationSubContext();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcRoadEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcGeometricRepresentationSubContext"; }


			// IfcRepresentationContext -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>								m_ContextIdentifier;		//optional
			//  shared_ptr<IfcLabel>								m_ContextType;				//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRepresentation> >		m_RepresentationsInContext_inverse;

			// IfcGeometricRepresentationContext -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcDimensionCount>					m_CoordinateSpaceDimension;
			//  shared_ptr<IfcReal>								m_Precision;				//optional
			//  shared_ptr<IfcAxis2Placement>					m_WorldCoordinateSystem;
			//  shared_ptr<IfcDirection>							m_TrueNorth;				//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcCoordinateOperation> >	m_HasCoordinateOperation_inverse;
			//  std::vector<weak_ptr<IfcGeometricRepresentationSubContext> >	m_HasSubContexts_inverse;

			// IfcGeometricRepresentationSubContext -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcGeometricRepresentationContext>	m_ParentContext;
			shared_ptr<IfcPositiveRatioMeasure>				m_TargetScale;				//optional
			shared_ptr<IfcGeometricProjectionEnum>			m_TargetView;
			shared_ptr<IfcLabel>								m_UserDefinedTargetView;	//optional
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform


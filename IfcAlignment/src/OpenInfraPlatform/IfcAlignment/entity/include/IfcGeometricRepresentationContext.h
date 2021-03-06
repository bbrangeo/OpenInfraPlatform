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
#include "IfcCoordinateReferenceSystemSelect.h"
#include "IfcRepresentationContext.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcDimensionCount;
		class IfcReal;
		class IfcAxis2Placement;
		class IfcDirection;
		class IfcCoordinateOperation;
		class IfcGeometricRepresentationSubContext;
		//ENTITY
		class IfcGeometricRepresentationContext : public IfcCoordinateReferenceSystemSelect, public IfcRepresentationContext
		{
		public:
			IfcGeometricRepresentationContext();
			IfcGeometricRepresentationContext( int id );
			~IfcGeometricRepresentationContext();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcGeometricRepresentationContext"; }


			// IfcRepresentationContext -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>											m_ContextIdentifier;		//optional
			//  shared_ptr<IfcLabel>											m_ContextType;				//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRepresentation> >					m_RepresentationsInContext_inverse;

			// IfcGeometricRepresentationContext -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcDimensionCount>								m_CoordinateSpaceDimension;
			shared_ptr<IfcReal>											m_Precision;				//optional
			shared_ptr<IfcAxis2Placement>								m_WorldCoordinateSystem;
			shared_ptr<IfcDirection>										m_TrueNorth;				//optional
			// inverse attributes:
			std::vector<weak_ptr<IfcCoordinateOperation> >				m_HasCoordinateOperation_inverse;
			std::vector<weak_ptr<IfcGeometricRepresentationSubContext> >	m_HasSubContexts_inverse;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform


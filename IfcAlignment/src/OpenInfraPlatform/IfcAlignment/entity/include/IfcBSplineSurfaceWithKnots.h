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
#include "IfcBSplineSurface.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcParameterValue;
		class IfcKnotType;
		//ENTITY
		class IfcBSplineSurfaceWithKnots : public IfcBSplineSurface
		{
		public:
			IfcBSplineSurfaceWithKnots();
			IfcBSplineSurfaceWithKnots( int id );
			~IfcBSplineSurfaceWithKnots();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcBSplineSurfaceWithKnots"; }


			// IfcRepresentationItem -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcPresentationLayerAssignment> >	m_LayerAssignment_inverse;
			//  std::vector<weak_ptr<IfcStyledItem> >		m_StyledByItem_inverse;

			// IfcGeometricRepresentationItem -----------------------------------------------------------

			// IfcSurface -----------------------------------------------------------

			// IfcBoundedSurface -----------------------------------------------------------

			// IfcBSplineSurface -----------------------------------------------------------
			// attributes:
			//  int											m_UDegree;
			//  int											m_VDegree;
			//  std::vector<std::vector<shared_ptr<IfcCartesianPoint> > >	m_ControlPointsList;
			//  shared_ptr<IfcBSplineSurfaceForm>			m_SurfaceForm;
			//  shared_ptr<IfcLogical>						m_UClosed;
			//  shared_ptr<IfcLogical>						m_VClosed;
			//  shared_ptr<IfcLogical>						m_SelfIntersect;

			// IfcBSplineSurfaceWithKnots -----------------------------------------------------------
			// attributes:
			std::vector<int >							m_UMultiplicities;
			std::vector<int >							m_VMultiplicities;
			std::vector<shared_ptr<IfcParameterValue> >	m_UKnots;
			std::vector<shared_ptr<IfcParameterValue> >	m_VKnots;
			shared_ptr<IfcKnotType>						m_KnotSpec;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform


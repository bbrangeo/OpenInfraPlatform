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
#include "IfcTopologicalRepresentationItem.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcLoop;
		class IfcBoolean;
		//ENTITY
		class IfcFaceBound : public IfcTopologicalRepresentationItem
		{
		public:
			IfcFaceBound();
			IfcFaceBound( int id );
			~IfcFaceBound();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcFaceBound"; }


			// IfcRepresentationItem -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcPresentationLayerAssignment> >	m_LayerAssignment_inverse;
			//  std::vector<weak_ptr<IfcStyledItem> >		m_StyledByItem_inverse;

			// IfcTopologicalRepresentationItem -----------------------------------------------------------

			// IfcFaceBound -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcLoop>							m_Bound;
			shared_ptr<IfcBoolean>						m_Orientation;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform


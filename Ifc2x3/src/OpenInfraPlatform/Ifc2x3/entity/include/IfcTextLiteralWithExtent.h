/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
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
#include "../../model/Ifc2x3Object.h"
#include "IfcTextLiteral.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		class IfcPlanarExtent;
		class IfcBoxAlignment;
		//ENTITY
		class IfcTextLiteralWithExtent : public IfcTextLiteral
		{
		public:
			IfcTextLiteralWithExtent();
			IfcTextLiteralWithExtent( int id );
			~IfcTextLiteralWithExtent();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc2x3Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcTextLiteralWithExtent"; }


			// IfcRepresentationItem -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcPresentationLayerAssignment> >	m_LayerAssignments_inverse;
			//  std::vector<weak_ptr<IfcStyledItem> >		m_StyledByItem_inverse;

			// IfcGeometricRepresentationItem -----------------------------------------------------------

			// IfcTextLiteral -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcPresentableText>				m_Literal;
			//  shared_ptr<IfcAxis2Placement>				m_Placement;
			//  shared_ptr<IfcTextPath>						m_Path;

			// IfcTextLiteralWithExtent -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcPlanarExtent>					m_Extent;
			shared_ptr<IfcBoxAlignment>					m_BoxAlignment;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform


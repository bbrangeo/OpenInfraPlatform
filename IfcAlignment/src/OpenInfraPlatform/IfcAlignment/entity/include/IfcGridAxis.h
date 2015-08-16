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

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcLabel;
		class IfcCurve;
		class IfcBoolean;
		class IfcGrid;
		class IfcVirtualGridIntersection;
		//ENTITY
		class IfcGridAxis : public IfcAlignmentP6Entity
		{
		public:
			IfcGridAxis();
			IfcGridAxis( int id );
			~IfcGridAxis();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcGridAxis"; }


			// IfcGridAxis -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcLabel>									m_AxisTag;					//optional
			shared_ptr<IfcCurve>									m_AxisCurve;
			shared_ptr<IfcBoolean>								m_SameSense;
			// inverse attributes:
			std::vector<weak_ptr<IfcGrid> >						m_PartOfW_inverse;
			std::vector<weak_ptr<IfcGrid> >						m_PartOfV_inverse;
			std::vector<weak_ptr<IfcGrid> >						m_PartOfU_inverse;
			std::vector<weak_ptr<IfcVirtualGridIntersection> >	m_HasIntersections_inverse;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform


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
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Object.h"
#include "IfcGridPlacementDirectionSelect.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		class IfcGridAxis;
		class IfcLengthMeasure;
		//ENTITY
		class IfcVirtualGridIntersection : public IfcGridPlacementDirectionSelect, public Ifc4Entity
		{
		public:
			IfcVirtualGridIntersection();
			IfcVirtualGridIntersection( int id );
			~IfcVirtualGridIntersection();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc4Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcVirtualGridIntersection"; }


			// IfcVirtualGridIntersection -----------------------------------------------------------
			// attributes:
			std::vector<shared_ptr<IfcGridAxis> >		m_IntersectingAxes;
			std::vector<shared_ptr<IfcLengthMeasure> >	m_OffsetDistances;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform


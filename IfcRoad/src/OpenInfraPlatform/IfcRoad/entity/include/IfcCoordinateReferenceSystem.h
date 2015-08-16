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
#include "IfcCoordinateReferenceSystemSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		class IfcLabel;
		class IfcText;
		class IfcIdentifier;
		class IfcCoordinateOperation;
		//ENTITY
		class IfcCoordinateReferenceSystem : public IfcCoordinateReferenceSystemSelect, public IfcRoadEntity
		{
		public:
			IfcCoordinateReferenceSystem();
			IfcCoordinateReferenceSystem( int id );
			~IfcCoordinateReferenceSystem();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcRoadEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcCoordinateReferenceSystem"; }


			// IfcCoordinateReferenceSystem -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcLabel>								m_Name;
			shared_ptr<IfcText>								m_Description;				//optional
			shared_ptr<IfcIdentifier>						m_GeodeticDatum;			//optional
			shared_ptr<IfcIdentifier>						m_VerticalDatum;			//optional
			// inverse attributes:
			std::vector<weak_ptr<IfcCoordinateOperation> >	m_HasCoordinateOperation_inverse;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform


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
#include "IfcProductRepresentationSelect.h"
#include "IfcProductRepresentation.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		class IfcProduct;
		class IfcShapeAspect;
		//ENTITY
		class IfcProductDefinitionShape : public IfcProductRepresentationSelect, public IfcProductRepresentation
		{
		public:
			IfcProductDefinitionShape();
			IfcProductDefinitionShape( int id );
			~IfcProductDefinitionShape();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcRoadEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcProductDefinitionShape"; }


			// IfcProductRepresentation -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>							m_Name;						//optional
			//  shared_ptr<IfcText>							m_Description;				//optional
			//  std::vector<shared_ptr<IfcRepresentation> >	m_Representations;

			// IfcProductDefinitionShape -----------------------------------------------------------
			// inverse attributes:
			std::vector<weak_ptr<IfcProduct> >			m_ShapeOfProduct_inverse;
			std::vector<weak_ptr<IfcShapeAspect> >		m_HasShapeAspects_inverse;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform


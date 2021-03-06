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
#include "IfcMaterialDefinition.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		class IfcMaterial;
		class IfcNonNegativeLengthMeasure;
		class IfcLogical;
		class IfcLabel;
		class IfcText;
		class IfcNormalisedRatioMeasure;
		class IfcMaterialLayerSet;
		//ENTITY
		class IfcMaterialLayer : public IfcMaterialDefinition
		{
		public:
			IfcMaterialLayer();
			IfcMaterialLayer( int id );
			~IfcMaterialLayer();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcRoadEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcMaterialLayer"; }


			// IfcMaterialDefinition -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelAssociatesMaterial> >	m_AssociatedTo_inverse;
			//  std::vector<weak_ptr<IfcExternalReferenceRelationship> >	m_HasExternalReferences_inverse;
			//  std::vector<weak_ptr<IfcMaterialProperties> >	m_HasProperties_inverse;

			// IfcMaterialLayer -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcMaterial>						m_Material;					//optional
			shared_ptr<IfcNonNegativeLengthMeasure>		m_LayerThickness;
			shared_ptr<IfcLogical>						m_IsVentilated;				//optional
			shared_ptr<IfcLabel>							m_Name;						//optional
			shared_ptr<IfcText>							m_Description;				//optional
			shared_ptr<IfcLabel>							m_Category;					//optional
			shared_ptr<IfcNormalisedRatioMeasure>		m_Priority;					//optional
			// inverse attributes:
			weak_ptr<IfcMaterialLayerSet>				m_ToMaterialLayerSet_inverse;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform


/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
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
#include "../../model/IfcTunnelObject.h"
#include "IfcMaterialLayer.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		class IfcLayerSetDirectionEnum;
		class IfcLengthMeasure;
		//ENTITY
		class IfcMaterialLayerWithOffsets : public IfcMaterialLayer
		{
		public:
			IfcMaterialLayerWithOffsets();
			IfcMaterialLayerWithOffsets( int id );
			~IfcMaterialLayerWithOffsets();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcTunnelEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcMaterialLayerWithOffsets"; }


			// IfcMaterialDefinition -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelAssociatesMaterial> >	m_AssociatedTo_inverse;
			//  std::vector<weak_ptr<IfcExternalReferenceRelationship> >	m_HasExternalReferences_inverse;
			//  std::vector<weak_ptr<IfcMaterialProperties> >	m_HasProperties_inverse;

			// IfcMaterialLayer -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcMaterial>						m_Material;					//optional
			//  shared_ptr<IfcNonNegativeLengthMeasure>		m_LayerThickness;
			//  shared_ptr<IfcLogical>						m_IsVentilated;				//optional
			//  shared_ptr<IfcLabel>							m_Name;						//optional
			//  shared_ptr<IfcText>							m_Description;				//optional
			//  shared_ptr<IfcLabel>							m_Category;					//optional
			//  shared_ptr<IfcNormalisedRatioMeasure>		m_Priority;					//optional
			// inverse attributes:
			//  weak_ptr<IfcMaterialLayerSet>				m_ToMaterialLayerSet_inverse;

			// IfcMaterialLayerWithOffsets -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcLayerSetDirectionEnum>			m_OffsetDirection;
			std::vector<shared_ptr<IfcLengthMeasure> >	m_OffsetValues;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform


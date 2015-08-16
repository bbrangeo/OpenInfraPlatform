/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcTunnelException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcTunnelEntityEnums.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcLogical.h"
#include "include/IfcMaterial.h"
#include "include/IfcMaterialLayer.h"
#include "include/IfcMaterialLayerSet.h"
#include "include/IfcMaterialProperties.h"
#include "include/IfcNonNegativeLengthMeasure.h"
#include "include/IfcNormalisedRatioMeasure.h"
#include "include/IfcRelAssociatesMaterial.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcMaterialLayer 
		IfcMaterialLayer::IfcMaterialLayer() { m_entity_enum = IFCMATERIALLAYER; }
		IfcMaterialLayer::IfcMaterialLayer( int id ) { m_id = id; m_entity_enum = IFCMATERIALLAYER; }
		IfcMaterialLayer::~IfcMaterialLayer() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcMaterialLayer::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcMaterialLayer> other = dynamic_pointer_cast<IfcMaterialLayer>(other_entity);
			if( !other) { return; }
			m_Material = other->m_Material;
			m_LayerThickness = other->m_LayerThickness;
			m_IsVentilated = other->m_IsVentilated;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_Category = other->m_Category;
			m_Priority = other->m_Priority;
		}
		void IfcMaterialLayer::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCMATERIALLAYER" << "(";
			if( m_Material ) { stream << "#" << m_Material->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_LayerThickness ) { m_LayerThickness->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_IsVentilated ) { m_IsVentilated->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Category ) { m_Category->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Priority ) { m_Priority->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcMaterialLayer::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcMaterialLayer::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<7 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcMaterialLayer, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>7 ){ std::cout << "Wrong parameter count for entity IfcMaterialLayer, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Material, map );
			m_LayerThickness = IfcNonNegativeLengthMeasure::readStepData( args[1] );
			m_IsVentilated = IfcLogical::readStepData( args[2] );
			m_Name = IfcLabel::readStepData( args[3] );
			m_Description = IfcText::readStepData( args[4] );
			m_Category = IfcLabel::readStepData( args[5] );
			m_Priority = IfcNormalisedRatioMeasure::readStepData( args[6] );
		}
		void IfcMaterialLayer::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcMaterialDefinition::setInverseCounterparts( ptr_self_entity );
		}
		void IfcMaterialLayer::unlinkSelf()
		{
			IfcMaterialDefinition::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

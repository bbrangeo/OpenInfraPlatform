/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/Ifc2x3Exception.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "Ifc2x3EntityEnums.h"
#include "include/IfcLogical.h"
#include "include/IfcMaterial.h"
#include "include/IfcMaterialLayer.h"
#include "include/IfcMaterialLayerSet.h"
#include "include/IfcPositiveLengthMeasure.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcMaterialLayer 
		IfcMaterialLayer::IfcMaterialLayer() { m_entity_enum = IFCMATERIALLAYER; }
		IfcMaterialLayer::IfcMaterialLayer( int id ) { m_id = id; m_entity_enum = IFCMATERIALLAYER; }
		IfcMaterialLayer::~IfcMaterialLayer() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcMaterialLayer::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcMaterialLayer> other = dynamic_pointer_cast<IfcMaterialLayer>(other_entity);
			if( !other) { return; }
			m_Material = other->m_Material;
			m_LayerThickness = other->m_LayerThickness;
			m_IsVentilated = other->m_IsVentilated;
		}
		void IfcMaterialLayer::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCMATERIALLAYER" << "(";
			if( m_Material ) { stream << "#" << m_Material->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_LayerThickness ) { m_LayerThickness->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_IsVentilated ) { m_IsVentilated->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcMaterialLayer::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcMaterialLayer::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcMaterialLayer, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcMaterialLayer, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Material, map );
			m_LayerThickness = IfcPositiveLengthMeasure::readStepData( args[1] );
			m_IsVentilated = IfcLogical::readStepData( args[2] );
		}
		void IfcMaterialLayer::setInverseCounterparts( shared_ptr<Ifc2x3Entity> )
		{
		}
		void IfcMaterialLayer::unlinkSelf()
		{
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

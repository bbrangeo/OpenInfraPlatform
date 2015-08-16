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
#include "include/IfcGeneralMaterialProperties.h"
#include "include/IfcMassDensityMeasure.h"
#include "include/IfcMaterial.h"
#include "include/IfcMolecularWeightMeasure.h"
#include "include/IfcNormalisedRatioMeasure.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcGeneralMaterialProperties 
		IfcGeneralMaterialProperties::IfcGeneralMaterialProperties() { m_entity_enum = IFCGENERALMATERIALPROPERTIES; }
		IfcGeneralMaterialProperties::IfcGeneralMaterialProperties( int id ) { m_id = id; m_entity_enum = IFCGENERALMATERIALPROPERTIES; }
		IfcGeneralMaterialProperties::~IfcGeneralMaterialProperties() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcGeneralMaterialProperties::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcGeneralMaterialProperties> other = dynamic_pointer_cast<IfcGeneralMaterialProperties>(other_entity);
			if( !other) { return; }
			m_Material = other->m_Material;
			m_MolecularWeight = other->m_MolecularWeight;
			m_Porosity = other->m_Porosity;
			m_MassDensity = other->m_MassDensity;
		}
		void IfcGeneralMaterialProperties::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCGENERALMATERIALPROPERTIES" << "(";
			if( m_Material ) { stream << "#" << m_Material->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_MolecularWeight ) { m_MolecularWeight->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Porosity ) { m_Porosity->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_MassDensity ) { m_MassDensity->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcGeneralMaterialProperties::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcGeneralMaterialProperties::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcGeneralMaterialProperties, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcGeneralMaterialProperties, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Material, map );
			m_MolecularWeight = IfcMolecularWeightMeasure::readStepData( args[1] );
			m_Porosity = IfcNormalisedRatioMeasure::readStepData( args[2] );
			m_MassDensity = IfcMassDensityMeasure::readStepData( args[3] );
		}
		void IfcGeneralMaterialProperties::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcMaterialProperties::setInverseCounterparts( ptr_self_entity );
		}
		void IfcGeneralMaterialProperties::unlinkSelf()
		{
			IfcMaterialProperties::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

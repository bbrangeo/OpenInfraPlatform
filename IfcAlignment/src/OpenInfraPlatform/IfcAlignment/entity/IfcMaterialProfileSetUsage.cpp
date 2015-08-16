/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/IfcAlignmentP6EntityEnums.h"
#include "include/IfcCardinalPointReference.h"
#include "include/IfcMaterialProfileSet.h"
#include "include/IfcMaterialProfileSetUsage.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcRelAssociatesMaterial.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcMaterialProfileSetUsage 
		IfcMaterialProfileSetUsage::IfcMaterialProfileSetUsage() { m_entity_enum = IFCMATERIALPROFILESETUSAGE; }
		IfcMaterialProfileSetUsage::IfcMaterialProfileSetUsage( int id ) { m_id = id; m_entity_enum = IFCMATERIALPROFILESETUSAGE; }
		IfcMaterialProfileSetUsage::~IfcMaterialProfileSetUsage() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcMaterialProfileSetUsage::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcMaterialProfileSetUsage> other = dynamic_pointer_cast<IfcMaterialProfileSetUsage>(other_entity);
			if( !other) { return; }
			m_ForProfileSet = other->m_ForProfileSet;
			m_CardinalPoint = other->m_CardinalPoint;
			m_ReferenceExtent = other->m_ReferenceExtent;
		}
		void IfcMaterialProfileSetUsage::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCMATERIALPROFILESETUSAGE" << "(";
			if( m_ForProfileSet ) { stream << "#" << m_ForProfileSet->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_CardinalPoint ) { m_CardinalPoint->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ReferenceExtent ) { m_ReferenceExtent->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcMaterialProfileSetUsage::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcMaterialProfileSetUsage::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcMaterialProfileSetUsage, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcMaterialProfileSetUsage, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_ForProfileSet, map );
			m_CardinalPoint = IfcCardinalPointReference::readStepData( args[1] );
			m_ReferenceExtent = IfcPositiveLengthMeasure::readStepData( args[2] );
		}
		void IfcMaterialProfileSetUsage::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcMaterialUsageDefinition::setInverseCounterparts( ptr_self_entity );
		}
		void IfcMaterialProfileSetUsage::unlinkSelf()
		{
			IfcMaterialUsageDefinition::unlinkSelf();
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

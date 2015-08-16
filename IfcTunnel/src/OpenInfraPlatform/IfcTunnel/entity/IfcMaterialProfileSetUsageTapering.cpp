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
#include "include/IfcCardinalPointReference.h"
#include "include/IfcMaterialProfileSet.h"
#include "include/IfcMaterialProfileSetUsageTapering.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcRelAssociatesMaterial.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcMaterialProfileSetUsageTapering 
		IfcMaterialProfileSetUsageTapering::IfcMaterialProfileSetUsageTapering() { m_entity_enum = IFCMATERIALPROFILESETUSAGETAPERING; }
		IfcMaterialProfileSetUsageTapering::IfcMaterialProfileSetUsageTapering( int id ) { m_id = id; m_entity_enum = IFCMATERIALPROFILESETUSAGETAPERING; }
		IfcMaterialProfileSetUsageTapering::~IfcMaterialProfileSetUsageTapering() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcMaterialProfileSetUsageTapering::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcMaterialProfileSetUsageTapering> other = dynamic_pointer_cast<IfcMaterialProfileSetUsageTapering>(other_entity);
			if( !other) { return; }
			m_ForProfileSet = other->m_ForProfileSet;
			m_CardinalPoint = other->m_CardinalPoint;
			m_ReferenceExtent = other->m_ReferenceExtent;
			m_ForProfileEndSet = other->m_ForProfileEndSet;
			m_CardinalEndPoint = other->m_CardinalEndPoint;
		}
		void IfcMaterialProfileSetUsageTapering::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCMATERIALPROFILESETUSAGETAPERING" << "(";
			if( m_ForProfileSet ) { stream << "#" << m_ForProfileSet->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_CardinalPoint ) { m_CardinalPoint->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ReferenceExtent ) { m_ReferenceExtent->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ForProfileEndSet ) { stream << "#" << m_ForProfileEndSet->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_CardinalEndPoint ) { m_CardinalEndPoint->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcMaterialProfileSetUsageTapering::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcMaterialProfileSetUsageTapering::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcMaterialProfileSetUsageTapering, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcMaterialProfileSetUsageTapering, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_ForProfileSet, map );
			m_CardinalPoint = IfcCardinalPointReference::readStepData( args[1] );
			m_ReferenceExtent = IfcPositiveLengthMeasure::readStepData( args[2] );
			readEntityReference( args[3], m_ForProfileEndSet, map );
			m_CardinalEndPoint = IfcCardinalPointReference::readStepData( args[4] );
		}
		void IfcMaterialProfileSetUsageTapering::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcMaterialProfileSetUsage::setInverseCounterparts( ptr_self_entity );
		}
		void IfcMaterialProfileSetUsageTapering::unlinkSelf()
		{
			IfcMaterialProfileSetUsage::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

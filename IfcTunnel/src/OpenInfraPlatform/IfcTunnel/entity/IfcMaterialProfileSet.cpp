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
#include "include/IfcCompositeProfileDef.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcMaterialProfile.h"
#include "include/IfcMaterialProfileSet.h"
#include "include/IfcMaterialProperties.h"
#include "include/IfcRelAssociatesMaterial.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcMaterialProfileSet 
		IfcMaterialProfileSet::IfcMaterialProfileSet() { m_entity_enum = IFCMATERIALPROFILESET; }
		IfcMaterialProfileSet::IfcMaterialProfileSet( int id ) { m_id = id; m_entity_enum = IFCMATERIALPROFILESET; }
		IfcMaterialProfileSet::~IfcMaterialProfileSet() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcMaterialProfileSet::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcMaterialProfileSet> other = dynamic_pointer_cast<IfcMaterialProfileSet>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_MaterialProfiles = other->m_MaterialProfiles;
			m_CompositeProfile = other->m_CompositeProfile;
		}
		void IfcMaterialProfileSet::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCMATERIALPROFILESET" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_MaterialProfiles );
			stream << ",";
			if( m_CompositeProfile ) { stream << "#" << m_CompositeProfile->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcMaterialProfileSet::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcMaterialProfileSet::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcMaterialProfileSet, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcMaterialProfileSet, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			readEntityReferenceList( args[2], m_MaterialProfiles, map );
			readEntityReference( args[3], m_CompositeProfile, map );
		}
		void IfcMaterialProfileSet::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcMaterialDefinition::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcMaterialProfileSet> ptr_self = dynamic_pointer_cast<IfcMaterialProfileSet>( ptr_self_entity );
			if( !ptr_self ) { throw IfcTunnelException( "IfcMaterialProfileSet::setInverseCounterparts: type mismatch" ); }
			for( int i=0; i<m_MaterialProfiles.size(); ++i )
			{
				if( m_MaterialProfiles[i] )
				{
					m_MaterialProfiles[i]->m_ToMaterialProfileSet_inverse = ptr_self;
				}
			}
		}
		void IfcMaterialProfileSet::unlinkSelf()
		{
			IfcMaterialDefinition::unlinkSelf();
			for( int i=0; i<m_MaterialProfiles.size(); ++i )
			{
				if( m_MaterialProfiles[i] )
				{
					shared_ptr<IfcMaterialProfileSet> self_candidate( m_MaterialProfiles[i]->m_ToMaterialProfileSet_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						weak_ptr<IfcMaterialProfileSet>& self_candidate_weak = m_MaterialProfiles[i]->m_ToMaterialProfileSet_inverse;
						self_candidate_weak.reset();
					}
				}
			}
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

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
#include "include/IfcAnalysisModelTypeEnum.h"
#include "include/IfcAxis2Placement3D.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcRelAssigns.h"
#include "include/IfcRelAssignsToGroup.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelDecomposes.h"
#include "include/IfcRelDefines.h"
#include "include/IfcRelServicesBuildings.h"
#include "include/IfcStructuralAnalysisModel.h"
#include "include/IfcStructuralLoadGroup.h"
#include "include/IfcStructuralResultGroup.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcStructuralAnalysisModel 
		IfcStructuralAnalysisModel::IfcStructuralAnalysisModel() { m_entity_enum = IFCSTRUCTURALANALYSISMODEL; }
		IfcStructuralAnalysisModel::IfcStructuralAnalysisModel( int id ) { m_id = id; m_entity_enum = IFCSTRUCTURALANALYSISMODEL; }
		IfcStructuralAnalysisModel::~IfcStructuralAnalysisModel() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcStructuralAnalysisModel::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcStructuralAnalysisModel> other = dynamic_pointer_cast<IfcStructuralAnalysisModel>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ObjectType = other->m_ObjectType;
			m_PredefinedType = other->m_PredefinedType;
			m_OrientationOf2DPlane = other->m_OrientationOf2DPlane;
			m_LoadedBy = other->m_LoadedBy;
			m_HasResults = other->m_HasResults;
		}
		void IfcStructuralAnalysisModel::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSTRUCTURALANALYSISMODEL" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ObjectType ) { m_ObjectType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_PredefinedType ) { m_PredefinedType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OrientationOf2DPlane ) { stream << "#" << m_OrientationOf2DPlane->getId(); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_LoadedBy );
			stream << ",";
			writeEntityList( stream, m_HasResults );
			stream << ");";
		}
		void IfcStructuralAnalysisModel::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcStructuralAnalysisModel::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<9 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcStructuralAnalysisModel, expecting 9, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>9 ){ std::cout << "Wrong parameter count for entity IfcStructuralAnalysisModel, expecting 9, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_ObjectType = IfcLabel::readStepData( args[4] );
			m_PredefinedType = IfcAnalysisModelTypeEnum::readStepData( args[5] );
			readEntityReference( args[6], m_OrientationOf2DPlane, map );
			readEntityReferenceList( args[7], m_LoadedBy, map );
			readEntityReferenceList( args[8], m_HasResults, map );
		}
		void IfcStructuralAnalysisModel::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcSystem::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcStructuralAnalysisModel> ptr_self = dynamic_pointer_cast<IfcStructuralAnalysisModel>( ptr_self_entity );
			if( !ptr_self ) { throw Ifc2x3Exception( "IfcStructuralAnalysisModel::setInverseCounterparts: type mismatch" ); }
			for( int i=0; i<m_HasResults.size(); ++i )
			{
				if( m_HasResults[i] )
				{
					m_HasResults[i]->m_ResultGroupFor_inverse.push_back( ptr_self );
				}
			}
			for( int i=0; i<m_LoadedBy.size(); ++i )
			{
				if( m_LoadedBy[i] )
				{
					m_LoadedBy[i]->m_LoadGroupFor_inverse.push_back( ptr_self );
				}
			}
		}
		void IfcStructuralAnalysisModel::unlinkSelf()
		{
			IfcSystem::unlinkSelf();
			for( int i=0; i<m_HasResults.size(); ++i )
			{
				if( m_HasResults[i] )
				{
					std::vector<weak_ptr<IfcStructuralAnalysisModel> >& ResultGroupFor_inverse = m_HasResults[i]->m_ResultGroupFor_inverse;
					std::vector<weak_ptr<IfcStructuralAnalysisModel> >::iterator it_ResultGroupFor_inverse;
					for( it_ResultGroupFor_inverse = ResultGroupFor_inverse.begin(); it_ResultGroupFor_inverse != ResultGroupFor_inverse.end(); ++it_ResultGroupFor_inverse)
					{
						shared_ptr<IfcStructuralAnalysisModel> self_candidate( *it_ResultGroupFor_inverse );
						if( self_candidate->getId() == this->getId() )
						{
							ResultGroupFor_inverse.erase( it_ResultGroupFor_inverse );
							break;
						}
					}
				}
			}
			for( int i=0; i<m_LoadedBy.size(); ++i )
			{
				if( m_LoadedBy[i] )
				{
					std::vector<weak_ptr<IfcStructuralAnalysisModel> >& LoadGroupFor_inverse = m_LoadedBy[i]->m_LoadGroupFor_inverse;
					std::vector<weak_ptr<IfcStructuralAnalysisModel> >::iterator it_LoadGroupFor_inverse;
					for( it_LoadGroupFor_inverse = LoadGroupFor_inverse.begin(); it_LoadGroupFor_inverse != LoadGroupFor_inverse.end(); ++it_LoadGroupFor_inverse)
					{
						shared_ptr<IfcStructuralAnalysisModel> self_candidate( *it_LoadGroupFor_inverse );
						if( self_candidate->getId() == this->getId() )
						{
							LoadGroupFor_inverse.erase( it_LoadGroupFor_inverse );
							break;
						}
					}
				}
			}
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

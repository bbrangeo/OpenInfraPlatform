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
#include "include/IfcLabel.h"
#include "include/IfcMaterialLayer.h"
#include "include/IfcMaterialLayerSet.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcMaterialLayerSet 
		IfcMaterialLayerSet::IfcMaterialLayerSet() { m_entity_enum = IFCMATERIALLAYERSET; }
		IfcMaterialLayerSet::IfcMaterialLayerSet( int id ) { m_id = id; m_entity_enum = IFCMATERIALLAYERSET; }
		IfcMaterialLayerSet::~IfcMaterialLayerSet() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcMaterialLayerSet::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcMaterialLayerSet> other = dynamic_pointer_cast<IfcMaterialLayerSet>(other_entity);
			if( !other) { return; }
			m_MaterialLayers = other->m_MaterialLayers;
			m_LayerSetName = other->m_LayerSetName;
		}
		void IfcMaterialLayerSet::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCMATERIALLAYERSET" << "(";
			writeEntityList( stream, m_MaterialLayers );
			stream << ",";
			if( m_LayerSetName ) { m_LayerSetName->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcMaterialLayerSet::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcMaterialLayerSet::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcMaterialLayerSet, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcMaterialLayerSet, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_MaterialLayers, map );
			m_LayerSetName = IfcLabel::readStepData( args[1] );
		}
		void IfcMaterialLayerSet::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			shared_ptr<IfcMaterialLayerSet> ptr_self = dynamic_pointer_cast<IfcMaterialLayerSet>( ptr_self_entity );
			if( !ptr_self ) { throw Ifc2x3Exception( "IfcMaterialLayerSet::setInverseCounterparts: type mismatch" ); }
			for( int i=0; i<m_MaterialLayers.size(); ++i )
			{
				if( m_MaterialLayers[i] )
				{
					m_MaterialLayers[i]->m_ToMaterialLayerSet_inverse = ptr_self;
				}
			}
		}
		void IfcMaterialLayerSet::unlinkSelf()
		{
			for( int i=0; i<m_MaterialLayers.size(); ++i )
			{
				if( m_MaterialLayers[i] )
				{
					shared_ptr<IfcMaterialLayerSet> self_candidate( m_MaterialLayers[i]->m_ToMaterialLayerSet_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						weak_ptr<IfcMaterialLayerSet>& self_candidate_weak = m_MaterialLayers[i]->m_ToMaterialLayerSet_inverse;
						self_candidate_weak.reset();
					}
				}
			}
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

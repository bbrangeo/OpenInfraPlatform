/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcBridgeException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcBridgeEntityEnums.h"
#include "include/IfcArbitraryProfileDefWithVoids.h"
#include "include/IfcCurve.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcProfileProperties.h"
#include "include/IfcProfileTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcArbitraryProfileDefWithVoids 
		IfcArbitraryProfileDefWithVoids::IfcArbitraryProfileDefWithVoids() { m_entity_enum = IFCARBITRARYPROFILEDEFWITHVOIDS; }
		IfcArbitraryProfileDefWithVoids::IfcArbitraryProfileDefWithVoids( int id ) { m_id = id; m_entity_enum = IFCARBITRARYPROFILEDEFWITHVOIDS; }
		IfcArbitraryProfileDefWithVoids::~IfcArbitraryProfileDefWithVoids() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcArbitraryProfileDefWithVoids::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcArbitraryProfileDefWithVoids> other = dynamic_pointer_cast<IfcArbitraryProfileDefWithVoids>(other_entity);
			if( !other) { return; }
			m_ProfileType = other->m_ProfileType;
			m_ProfileName = other->m_ProfileName;
			m_OuterCurve = other->m_OuterCurve;
			m_InnerCurves = other->m_InnerCurves;
		}
		void IfcArbitraryProfileDefWithVoids::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCARBITRARYPROFILEDEFWITHVOIDS" << "(";
			if( m_ProfileType ) { m_ProfileType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ProfileName ) { m_ProfileName->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OuterCurve ) { stream << "#" << m_OuterCurve->getId(); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_InnerCurves );
			stream << ");";
		}
		void IfcArbitraryProfileDefWithVoids::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcArbitraryProfileDefWithVoids::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcArbitraryProfileDefWithVoids, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcArbitraryProfileDefWithVoids, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_ProfileType = IfcProfileTypeEnum::readStepData( args[0] );
			m_ProfileName = IfcLabel::readStepData( args[1] );
			readEntityReference( args[2], m_OuterCurve, map );
			readEntityReferenceList( args[3], m_InnerCurves, map );
		}
		void IfcArbitraryProfileDefWithVoids::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcArbitraryClosedProfileDef::setInverseCounterparts( ptr_self_entity );
		}
		void IfcArbitraryProfileDefWithVoids::unlinkSelf()
		{
			IfcArbitraryClosedProfileDef::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

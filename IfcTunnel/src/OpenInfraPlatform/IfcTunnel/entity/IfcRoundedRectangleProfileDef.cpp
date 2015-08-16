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
#include "include/IfcAxis2Placement2D.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcProfileProperties.h"
#include "include/IfcProfileTypeEnum.h"
#include "include/IfcRoundedRectangleProfileDef.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcRoundedRectangleProfileDef 
		IfcRoundedRectangleProfileDef::IfcRoundedRectangleProfileDef() { m_entity_enum = IFCROUNDEDRECTANGLEPROFILEDEF; }
		IfcRoundedRectangleProfileDef::IfcRoundedRectangleProfileDef( int id ) { m_id = id; m_entity_enum = IFCROUNDEDRECTANGLEPROFILEDEF; }
		IfcRoundedRectangleProfileDef::~IfcRoundedRectangleProfileDef() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRoundedRectangleProfileDef::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcRoundedRectangleProfileDef> other = dynamic_pointer_cast<IfcRoundedRectangleProfileDef>(other_entity);
			if( !other) { return; }
			m_ProfileType = other->m_ProfileType;
			m_ProfileName = other->m_ProfileName;
			m_Position = other->m_Position;
			m_XDim = other->m_XDim;
			m_YDim = other->m_YDim;
			m_RoundingRadius = other->m_RoundingRadius;
		}
		void IfcRoundedRectangleProfileDef::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCROUNDEDRECTANGLEPROFILEDEF" << "(";
			if( m_ProfileType ) { m_ProfileType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ProfileName ) { m_ProfileName->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Position ) { stream << "#" << m_Position->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_XDim ) { m_XDim->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_YDim ) { m_YDim->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RoundingRadius ) { m_RoundingRadius->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcRoundedRectangleProfileDef::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRoundedRectangleProfileDef::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRoundedRectangleProfileDef, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcRoundedRectangleProfileDef, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_ProfileType = IfcProfileTypeEnum::readStepData( args[0] );
			m_ProfileName = IfcLabel::readStepData( args[1] );
			readEntityReference( args[2], m_Position, map );
			m_XDim = IfcPositiveLengthMeasure::readStepData( args[3] );
			m_YDim = IfcPositiveLengthMeasure::readStepData( args[4] );
			m_RoundingRadius = IfcPositiveLengthMeasure::readStepData( args[5] );
		}
		void IfcRoundedRectangleProfileDef::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcRectangleProfileDef::setInverseCounterparts( ptr_self_entity );
		}
		void IfcRoundedRectangleProfileDef::unlinkSelf()
		{
			IfcRectangleProfileDef::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

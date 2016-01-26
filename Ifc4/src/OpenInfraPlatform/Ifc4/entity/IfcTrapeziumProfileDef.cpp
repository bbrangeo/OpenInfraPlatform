/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "OpenInfraPlatform/Ifc4/writer/WriterUtil.h"
#include "OpenInfraPlatform/Ifc4/Ifc4EntityEnums.h"
#include "include/IfcAxis2Placement2D.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcProfileProperties.h"
#include "include/IfcProfileTypeEnum.h"
#include "include/IfcTrapeziumProfileDef.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcTrapeziumProfileDef 
		IfcTrapeziumProfileDef::IfcTrapeziumProfileDef() { m_entity_enum = IFCTRAPEZIUMPROFILEDEF; }
		IfcTrapeziumProfileDef::IfcTrapeziumProfileDef( int id ) { m_id = id; m_entity_enum = IFCTRAPEZIUMPROFILEDEF; }
		IfcTrapeziumProfileDef::~IfcTrapeziumProfileDef() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTrapeziumProfileDef::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcTrapeziumProfileDef> other = dynamic_pointer_cast<IfcTrapeziumProfileDef>(other_entity);
			if( !other) { return; }
			m_ProfileType = other->m_ProfileType;
			m_ProfileName = other->m_ProfileName;
			m_Position = other->m_Position;
			m_BottomXDim = other->m_BottomXDim;
			m_TopXDim = other->m_TopXDim;
			m_YDim = other->m_YDim;
			m_TopXOffset = other->m_TopXOffset;
		}
		void IfcTrapeziumProfileDef::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTRAPEZIUMPROFILEDEF" << "(";
			if( m_ProfileType ) { m_ProfileType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ProfileName ) { m_ProfileName->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Position ) { stream << "#" << m_Position->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_BottomXDim ) { m_BottomXDim->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_TopXDim ) { m_TopXDim->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_YDim ) { m_YDim->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_TopXOffset ) { m_TopXOffset->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcTrapeziumProfileDef::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTrapeziumProfileDef::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<7 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTrapeziumProfileDef, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>7 ){ std::cout << "Wrong parameter count for entity IfcTrapeziumProfileDef, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_ProfileType = IfcProfileTypeEnum::readStepData( args[0] );
			m_ProfileName = IfcLabel::readStepData( args[1] );
			readEntityReference( args[2], m_Position, map );
			m_BottomXDim = IfcPositiveLengthMeasure::readStepData( args[3] );
			m_TopXDim = IfcPositiveLengthMeasure::readStepData( args[4] );
			m_YDim = IfcPositiveLengthMeasure::readStepData( args[5] );
			m_TopXOffset = IfcLengthMeasure::readStepData( args[6] );
		}
		void IfcTrapeziumProfileDef::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcParameterizedProfileDef::setInverseCounterparts( ptr_self_entity );
		}
		void IfcTrapeziumProfileDef::unlinkSelf()
		{
			IfcParameterizedProfileDef::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

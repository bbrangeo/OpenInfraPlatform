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
#include "include/IfcArbitraryProfileDefWithVoids.h"
#include "include/IfcCurve.h"
#include "include/IfcLabel.h"
#include "include/IfcProfileTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcArbitraryProfileDefWithVoids 
		IfcArbitraryProfileDefWithVoids::IfcArbitraryProfileDefWithVoids() { m_entity_enum = IFCARBITRARYPROFILEDEFWITHVOIDS; }
		IfcArbitraryProfileDefWithVoids::IfcArbitraryProfileDefWithVoids( int id ) { m_id = id; m_entity_enum = IFCARBITRARYPROFILEDEFWITHVOIDS; }
		IfcArbitraryProfileDefWithVoids::~IfcArbitraryProfileDefWithVoids() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcArbitraryProfileDefWithVoids::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
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
		void IfcArbitraryProfileDefWithVoids::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcArbitraryProfileDefWithVoids, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcArbitraryProfileDefWithVoids, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_ProfileType = IfcProfileTypeEnum::readStepData( args[0] );
			m_ProfileName = IfcLabel::readStepData( args[1] );
			readEntityReference( args[2], m_OuterCurve, map );
			readEntityReferenceList( args[3], m_InnerCurves, map );
		}
		void IfcArbitraryProfileDefWithVoids::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcArbitraryClosedProfileDef::setInverseCounterparts( ptr_self_entity );
		}
		void IfcArbitraryProfileDefWithVoids::unlinkSelf()
		{
			IfcArbitraryClosedProfileDef::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

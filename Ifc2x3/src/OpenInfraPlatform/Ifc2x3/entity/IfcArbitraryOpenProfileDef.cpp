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
#include "include/IfcArbitraryOpenProfileDef.h"
#include "include/IfcBoundedCurve.h"
#include "include/IfcLabel.h"
#include "include/IfcProfileTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcArbitraryOpenProfileDef 
		IfcArbitraryOpenProfileDef::IfcArbitraryOpenProfileDef() { m_entity_enum = IFCARBITRARYOPENPROFILEDEF; }
		IfcArbitraryOpenProfileDef::IfcArbitraryOpenProfileDef( int id ) { m_id = id; m_entity_enum = IFCARBITRARYOPENPROFILEDEF; }
		IfcArbitraryOpenProfileDef::~IfcArbitraryOpenProfileDef() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcArbitraryOpenProfileDef::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcArbitraryOpenProfileDef> other = dynamic_pointer_cast<IfcArbitraryOpenProfileDef>(other_entity);
			if( !other) { return; }
			m_ProfileType = other->m_ProfileType;
			m_ProfileName = other->m_ProfileName;
			m_Curve = other->m_Curve;
		}
		void IfcArbitraryOpenProfileDef::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCARBITRARYOPENPROFILEDEF" << "(";
			if( m_ProfileType ) { m_ProfileType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ProfileName ) { m_ProfileName->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Curve ) { stream << "#" << m_Curve->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcArbitraryOpenProfileDef::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcArbitraryOpenProfileDef::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcArbitraryOpenProfileDef, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcArbitraryOpenProfileDef, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_ProfileType = IfcProfileTypeEnum::readStepData( args[0] );
			m_ProfileName = IfcLabel::readStepData( args[1] );
			readEntityReference( args[2], m_Curve, map );
		}
		void IfcArbitraryOpenProfileDef::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcProfileDef::setInverseCounterparts( ptr_self_entity );
		}
		void IfcArbitraryOpenProfileDef::unlinkSelf()
		{
			IfcProfileDef::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

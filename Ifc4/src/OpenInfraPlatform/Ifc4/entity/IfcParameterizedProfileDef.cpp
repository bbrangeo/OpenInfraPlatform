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
#include "include/IfcParameterizedProfileDef.h"
#include "include/IfcProfileProperties.h"
#include "include/IfcProfileTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcParameterizedProfileDef 
		IfcParameterizedProfileDef::IfcParameterizedProfileDef() { m_entity_enum = IFCPARAMETERIZEDPROFILEDEF; }
		IfcParameterizedProfileDef::IfcParameterizedProfileDef( int id ) { m_id = id; m_entity_enum = IFCPARAMETERIZEDPROFILEDEF; }
		IfcParameterizedProfileDef::~IfcParameterizedProfileDef() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcParameterizedProfileDef::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcParameterizedProfileDef> other = dynamic_pointer_cast<IfcParameterizedProfileDef>(other_entity);
			if( !other) { return; }
			m_ProfileType = other->m_ProfileType;
			m_ProfileName = other->m_ProfileName;
			m_Position = other->m_Position;
		}
		void IfcParameterizedProfileDef::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPARAMETERIZEDPROFILEDEF" << "(";
			if( m_ProfileType ) { m_ProfileType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ProfileName ) { m_ProfileName->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Position ) { stream << "#" << m_Position->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcParameterizedProfileDef::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcParameterizedProfileDef::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcParameterizedProfileDef, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcParameterizedProfileDef, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_ProfileType = IfcProfileTypeEnum::readStepData( args[0] );
			m_ProfileName = IfcLabel::readStepData( args[1] );
			readEntityReference( args[2], m_Position, map );
		}
		void IfcParameterizedProfileDef::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcProfileDef::setInverseCounterparts( ptr_self_entity );
		}
		void IfcParameterizedProfileDef::unlinkSelf()
		{
			IfcProfileDef::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

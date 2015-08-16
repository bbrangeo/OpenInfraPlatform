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
#include "include/IfcDerivedUnit.h"
#include "include/IfcDerivedUnitElement.h"
#include "include/IfcDerivedUnitEnum.h"
#include "include/IfcLabel.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcDerivedUnit 
		IfcDerivedUnit::IfcDerivedUnit() { m_entity_enum = IFCDERIVEDUNIT; }
		IfcDerivedUnit::IfcDerivedUnit( int id ) { m_id = id; m_entity_enum = IFCDERIVEDUNIT; }
		IfcDerivedUnit::~IfcDerivedUnit() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcDerivedUnit::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcDerivedUnit> other = dynamic_pointer_cast<IfcDerivedUnit>(other_entity);
			if( !other) { return; }
			m_Elements = other->m_Elements;
			m_UnitType = other->m_UnitType;
			m_UserDefinedType = other->m_UserDefinedType;
		}
		void IfcDerivedUnit::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCDERIVEDUNIT" << "(";
			writeEntityList( stream, m_Elements );
			stream << ",";
			if( m_UnitType ) { m_UnitType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_UserDefinedType ) { m_UserDefinedType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcDerivedUnit::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcDerivedUnit::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcDerivedUnit, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcDerivedUnit, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_Elements, map );
			m_UnitType = IfcDerivedUnitEnum::readStepData( args[1] );
			m_UserDefinedType = IfcLabel::readStepData( args[2] );
		}
		void IfcDerivedUnit::setInverseCounterparts( shared_ptr<IfcBridgeEntity> )
		{
		}
		void IfcDerivedUnit::unlinkSelf()
		{
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/IfcRoadEntityEnums.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcNamedUnit.h"
#include "include/IfcPhysicalComplexQuantity.h"
#include "include/IfcPhysicalSimpleQuantity.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcPhysicalSimpleQuantity 
		IfcPhysicalSimpleQuantity::IfcPhysicalSimpleQuantity() { m_entity_enum = IFCPHYSICALSIMPLEQUANTITY; }
		IfcPhysicalSimpleQuantity::IfcPhysicalSimpleQuantity( int id ) { m_id = id; m_entity_enum = IFCPHYSICALSIMPLEQUANTITY; }
		IfcPhysicalSimpleQuantity::~IfcPhysicalSimpleQuantity() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPhysicalSimpleQuantity::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcPhysicalSimpleQuantity> other = dynamic_pointer_cast<IfcPhysicalSimpleQuantity>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_Unit = other->m_Unit;
		}
		void IfcPhysicalSimpleQuantity::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPHYSICALSIMPLEQUANTITY" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Unit ) { stream << "#" << m_Unit->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcPhysicalSimpleQuantity::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPhysicalSimpleQuantity::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPhysicalSimpleQuantity, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcPhysicalSimpleQuantity, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			readEntityReference( args[2], m_Unit, map );
		}
		void IfcPhysicalSimpleQuantity::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcPhysicalQuantity::setInverseCounterparts( ptr_self_entity );
		}
		void IfcPhysicalSimpleQuantity::unlinkSelf()
		{
			IfcPhysicalQuantity::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

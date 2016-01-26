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
#include "include/IfcCountMeasure.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcNamedUnit.h"
#include "include/IfcPhysicalComplexQuantity.h"
#include "include/IfcQuantityCount.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcQuantityCount 
		IfcQuantityCount::IfcQuantityCount() { m_entity_enum = IFCQUANTITYCOUNT; }
		IfcQuantityCount::IfcQuantityCount( int id ) { m_id = id; m_entity_enum = IFCQUANTITYCOUNT; }
		IfcQuantityCount::~IfcQuantityCount() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcQuantityCount::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcQuantityCount> other = dynamic_pointer_cast<IfcQuantityCount>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_Unit = other->m_Unit;
			m_CountValue = other->m_CountValue;
			m_Formula = other->m_Formula;
		}
		void IfcQuantityCount::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCQUANTITYCOUNT" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Unit ) { stream << "#" << m_Unit->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_CountValue ) { m_CountValue->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Formula ) { m_Formula->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcQuantityCount::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcQuantityCount::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcQuantityCount, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcQuantityCount, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			readEntityReference( args[2], m_Unit, map );
			m_CountValue = IfcCountMeasure::readStepData( args[3] );
			m_Formula = IfcLabel::readStepData( args[4] );
		}
		void IfcQuantityCount::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcPhysicalSimpleQuantity::setInverseCounterparts( ptr_self_entity );
		}
		void IfcQuantityCount::unlinkSelf()
		{
			IfcPhysicalSimpleQuantity::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

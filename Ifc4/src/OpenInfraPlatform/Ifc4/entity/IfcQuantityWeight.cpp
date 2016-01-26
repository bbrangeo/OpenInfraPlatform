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
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcMassMeasure.h"
#include "include/IfcNamedUnit.h"
#include "include/IfcPhysicalComplexQuantity.h"
#include "include/IfcQuantityWeight.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcQuantityWeight 
		IfcQuantityWeight::IfcQuantityWeight() { m_entity_enum = IFCQUANTITYWEIGHT; }
		IfcQuantityWeight::IfcQuantityWeight( int id ) { m_id = id; m_entity_enum = IFCQUANTITYWEIGHT; }
		IfcQuantityWeight::~IfcQuantityWeight() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcQuantityWeight::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcQuantityWeight> other = dynamic_pointer_cast<IfcQuantityWeight>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_Unit = other->m_Unit;
			m_WeightValue = other->m_WeightValue;
			m_Formula = other->m_Formula;
		}
		void IfcQuantityWeight::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCQUANTITYWEIGHT" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Unit ) { stream << "#" << m_Unit->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_WeightValue ) { m_WeightValue->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Formula ) { m_Formula->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcQuantityWeight::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcQuantityWeight::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcQuantityWeight, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcQuantityWeight, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			readEntityReference( args[2], m_Unit, map );
			m_WeightValue = IfcMassMeasure::readStepData( args[3] );
			m_Formula = IfcLabel::readStepData( args[4] );
		}
		void IfcQuantityWeight::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcPhysicalSimpleQuantity::setInverseCounterparts( ptr_self_entity );
		}
		void IfcQuantityWeight::unlinkSelf()
		{
			IfcPhysicalSimpleQuantity::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

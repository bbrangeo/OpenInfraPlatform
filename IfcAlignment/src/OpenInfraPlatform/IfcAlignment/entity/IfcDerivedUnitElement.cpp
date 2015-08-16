/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/IfcAlignmentP6EntityEnums.h"
#include "include/IfcDerivedUnitElement.h"
#include "include/IfcNamedUnit.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcDerivedUnitElement 
		IfcDerivedUnitElement::IfcDerivedUnitElement() { m_entity_enum = IFCDERIVEDUNITELEMENT; }
		IfcDerivedUnitElement::IfcDerivedUnitElement( int id ) { m_id = id; m_entity_enum = IFCDERIVEDUNITELEMENT; }
		IfcDerivedUnitElement::~IfcDerivedUnitElement() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcDerivedUnitElement::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcDerivedUnitElement> other = dynamic_pointer_cast<IfcDerivedUnitElement>(other_entity);
			if( !other) { return; }
			m_Unit = other->m_Unit;
			m_Exponent = other->m_Exponent;
		}
		void IfcDerivedUnitElement::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCDERIVEDUNITELEMENT" << "(";
			if( m_Unit ) { stream << "#" << m_Unit->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Exponent == m_Exponent ){ stream << m_Exponent; }
			else { stream << "$"; }
			stream << ");";
		}
		void IfcDerivedUnitElement::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcDerivedUnitElement::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcDerivedUnitElement, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcDerivedUnitElement, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Unit, map );
			readIntValue( args[1], m_Exponent );
		}
		void IfcDerivedUnitElement::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> )
		{
		}
		void IfcDerivedUnitElement::unlinkSelf()
		{
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

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
#include "include/IfcDerivedUnitElement.h"
#include "include/IfcNamedUnit.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcDerivedUnitElement 
		IfcDerivedUnitElement::IfcDerivedUnitElement() { m_entity_enum = IFCDERIVEDUNITELEMENT; }
		IfcDerivedUnitElement::IfcDerivedUnitElement( int id ) { m_id = id; m_entity_enum = IFCDERIVEDUNITELEMENT; }
		IfcDerivedUnitElement::~IfcDerivedUnitElement() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcDerivedUnitElement::setEntity( shared_ptr<IfcRoadEntity> other_entity )
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
		void IfcDerivedUnitElement::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcDerivedUnitElement, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcDerivedUnitElement, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Unit, map );
			readIntValue( args[1], m_Exponent );
		}
		void IfcDerivedUnitElement::setInverseCounterparts( shared_ptr<IfcRoadEntity> )
		{
		}
		void IfcDerivedUnitElement::unlinkSelf()
		{
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

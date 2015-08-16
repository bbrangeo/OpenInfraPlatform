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
#include "include/IfcCurrencyRelationship.h"
#include "include/IfcDateAndTime.h"
#include "include/IfcLibraryInformation.h"
#include "include/IfcMonetaryUnit.h"
#include "include/IfcPositiveRatioMeasure.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcCurrencyRelationship 
		IfcCurrencyRelationship::IfcCurrencyRelationship() { m_entity_enum = IFCCURRENCYRELATIONSHIP; }
		IfcCurrencyRelationship::IfcCurrencyRelationship( int id ) { m_id = id; m_entity_enum = IFCCURRENCYRELATIONSHIP; }
		IfcCurrencyRelationship::~IfcCurrencyRelationship() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCurrencyRelationship::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcCurrencyRelationship> other = dynamic_pointer_cast<IfcCurrencyRelationship>(other_entity);
			if( !other) { return; }
			m_RelatingMonetaryUnit = other->m_RelatingMonetaryUnit;
			m_RelatedMonetaryUnit = other->m_RelatedMonetaryUnit;
			m_ExchangeRate = other->m_ExchangeRate;
			m_RateDateTime = other->m_RateDateTime;
			m_RateSource = other->m_RateSource;
		}
		void IfcCurrencyRelationship::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCURRENCYRELATIONSHIP" << "(";
			if( m_RelatingMonetaryUnit ) { stream << "#" << m_RelatingMonetaryUnit->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_RelatedMonetaryUnit ) { stream << "#" << m_RelatedMonetaryUnit->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_ExchangeRate ) { m_ExchangeRate->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RateDateTime ) { stream << "#" << m_RateDateTime->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_RateSource ) { stream << "#" << m_RateSource->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcCurrencyRelationship::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCurrencyRelationship::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCurrencyRelationship, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcCurrencyRelationship, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_RelatingMonetaryUnit, map );
			readEntityReference( args[1], m_RelatedMonetaryUnit, map );
			m_ExchangeRate = IfcPositiveRatioMeasure::readStepData( args[2] );
			readEntityReference( args[3], m_RateDateTime, map );
			readEntityReference( args[4], m_RateSource, map );
		}
		void IfcCurrencyRelationship::setInverseCounterparts( shared_ptr<Ifc2x3Entity> )
		{
		}
		void IfcCurrencyRelationship::unlinkSelf()
		{
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

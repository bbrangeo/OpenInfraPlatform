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
#include "include/IfcNormalisedRatioMeasure.h"
#include "include/IfcRelaxation.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcRelaxation 
		IfcRelaxation::IfcRelaxation() { m_entity_enum = IFCRELAXATION; }
		IfcRelaxation::IfcRelaxation( int id ) { m_id = id; m_entity_enum = IFCRELAXATION; }
		IfcRelaxation::~IfcRelaxation() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRelaxation::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcRelaxation> other = dynamic_pointer_cast<IfcRelaxation>(other_entity);
			if( !other) { return; }
			m_RelaxationValue = other->m_RelaxationValue;
			m_InitialStress = other->m_InitialStress;
		}
		void IfcRelaxation::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRELAXATION" << "(";
			if( m_RelaxationValue ) { m_RelaxationValue->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_InitialStress ) { m_InitialStress->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcRelaxation::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRelaxation::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRelaxation, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcRelaxation, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_RelaxationValue = IfcNormalisedRatioMeasure::readStepData( args[0] );
			m_InitialStress = IfcNormalisedRatioMeasure::readStepData( args[1] );
		}
		void IfcRelaxation::setInverseCounterparts( shared_ptr<Ifc2x3Entity> )
		{
		}
		void IfcRelaxation::unlinkSelf()
		{
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

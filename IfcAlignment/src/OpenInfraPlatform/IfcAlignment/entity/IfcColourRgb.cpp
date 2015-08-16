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
#include "include/IfcColourRgb.h"
#include "include/IfcLabel.h"
#include "include/IfcNormalisedRatioMeasure.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcColourRgb 
		IfcColourRgb::IfcColourRgb() { m_entity_enum = IFCCOLOURRGB; }
		IfcColourRgb::IfcColourRgb( int id ) { m_id = id; m_entity_enum = IFCCOLOURRGB; }
		IfcColourRgb::~IfcColourRgb() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcColourRgb::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcColourRgb> other = dynamic_pointer_cast<IfcColourRgb>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Red = other->m_Red;
			m_Green = other->m_Green;
			m_Blue = other->m_Blue;
		}
		void IfcColourRgb::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCOLOURRGB" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Red ) { m_Red->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Green ) { m_Green->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Blue ) { m_Blue->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcColourRgb::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcColourRgb::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcColourRgb, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcColourRgb, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_Red = IfcNormalisedRatioMeasure::readStepData( args[1] );
			m_Green = IfcNormalisedRatioMeasure::readStepData( args[2] );
			m_Blue = IfcNormalisedRatioMeasure::readStepData( args[3] );
		}
		void IfcColourRgb::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcColourSpecification::setInverseCounterparts( ptr_self_entity );
		}
		void IfcColourRgb::unlinkSelf()
		{
			IfcColourSpecification::unlinkSelf();
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

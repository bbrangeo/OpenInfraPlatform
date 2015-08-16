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
#include "include/IfcColourRgb.h"
#include "include/IfcLabel.h"
#include "include/IfcNormalisedRatioMeasure.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcColourRgb 
		IfcColourRgb::IfcColourRgb() { m_entity_enum = IFCCOLOURRGB; }
		IfcColourRgb::IfcColourRgb( int id ) { m_id = id; m_entity_enum = IFCCOLOURRGB; }
		IfcColourRgb::~IfcColourRgb() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcColourRgb::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
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
		void IfcColourRgb::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcColourRgb, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcColourRgb, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_Red = IfcNormalisedRatioMeasure::readStepData( args[1] );
			m_Green = IfcNormalisedRatioMeasure::readStepData( args[2] );
			m_Blue = IfcNormalisedRatioMeasure::readStepData( args[3] );
		}
		void IfcColourRgb::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcColourSpecification::setInverseCounterparts( ptr_self_entity );
		}
		void IfcColourRgb::unlinkSelf()
		{
			IfcColourSpecification::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

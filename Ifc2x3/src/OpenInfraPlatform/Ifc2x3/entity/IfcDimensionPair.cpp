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
#include "include/IfcDimensionPair.h"
#include "include/IfcDraughtingCallout.h"
#include "include/IfcLabel.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcDimensionPair 
		IfcDimensionPair::IfcDimensionPair() { m_entity_enum = IFCDIMENSIONPAIR; }
		IfcDimensionPair::IfcDimensionPair( int id ) { m_id = id; m_entity_enum = IFCDIMENSIONPAIR; }
		IfcDimensionPair::~IfcDimensionPair() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcDimensionPair::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcDimensionPair> other = dynamic_pointer_cast<IfcDimensionPair>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_RelatingDraughtingCallout = other->m_RelatingDraughtingCallout;
			m_RelatedDraughtingCallout = other->m_RelatedDraughtingCallout;
		}
		void IfcDimensionPair::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCDIMENSIONPAIR" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RelatingDraughtingCallout ) { stream << "#" << m_RelatingDraughtingCallout->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_RelatedDraughtingCallout ) { stream << "#" << m_RelatedDraughtingCallout->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcDimensionPair::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcDimensionPair::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcDimensionPair, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcDimensionPair, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			readEntityReference( args[2], m_RelatingDraughtingCallout, map );
			readEntityReference( args[3], m_RelatedDraughtingCallout, map );
		}
		void IfcDimensionPair::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcDraughtingCalloutRelationship::setInverseCounterparts( ptr_self_entity );
		}
		void IfcDimensionPair::unlinkSelf()
		{
			IfcDraughtingCalloutRelationship::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

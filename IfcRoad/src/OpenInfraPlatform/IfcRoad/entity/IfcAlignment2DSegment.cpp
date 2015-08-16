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
#include "include/IfcAlignment2DSegment.h"
#include "include/IfcBoolean.h"
#include "include/IfcLabel.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcAlignment2DSegment 
		IfcAlignment2DSegment::IfcAlignment2DSegment() { m_entity_enum = IFCALIGNMENT2DSEGMENT; }
		IfcAlignment2DSegment::IfcAlignment2DSegment( int id ) { m_id = id; m_entity_enum = IFCALIGNMENT2DSEGMENT; }
		IfcAlignment2DSegment::~IfcAlignment2DSegment() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcAlignment2DSegment::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcAlignment2DSegment> other = dynamic_pointer_cast<IfcAlignment2DSegment>(other_entity);
			if( !other) { return; }
			m_TangentialContinuity = other->m_TangentialContinuity;
			m_StartTag = other->m_StartTag;
			m_EndTag = other->m_EndTag;
		}
		void IfcAlignment2DSegment::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCALIGNMENT2DSEGMENT" << "(";
			if( m_TangentialContinuity ) { m_TangentialContinuity->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_StartTag ) { m_StartTag->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_EndTag ) { m_EndTag->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcAlignment2DSegment::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcAlignment2DSegment::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcAlignment2DSegment, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcAlignment2DSegment, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_TangentialContinuity = IfcBoolean::readStepData( args[0] );
			m_StartTag = IfcLabel::readStepData( args[1] );
			m_EndTag = IfcLabel::readStepData( args[2] );
		}
		void IfcAlignment2DSegment::setInverseCounterparts( shared_ptr<IfcRoadEntity> )
		{
		}
		void IfcAlignment2DSegment::unlinkSelf()
		{
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

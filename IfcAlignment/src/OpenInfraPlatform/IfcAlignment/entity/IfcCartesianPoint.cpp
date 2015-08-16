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
#include "include/IfcCartesianPoint.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcCartesianPoint 
		IfcCartesianPoint::IfcCartesianPoint() { m_entity_enum = IFCCARTESIANPOINT; }
		IfcCartesianPoint::IfcCartesianPoint( int id ) { m_id = id; m_entity_enum = IFCCARTESIANPOINT; }
		IfcCartesianPoint::~IfcCartesianPoint() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCartesianPoint::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcCartesianPoint> other = dynamic_pointer_cast<IfcCartesianPoint>(other_entity);
			if( !other) { return; }
			m_Coordinates = other->m_Coordinates;
		}
		void IfcCartesianPoint::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCARTESIANPOINT" << "(";
			writeTypeOfRealList( stream, m_Coordinates );
			stream << ");";
		}
		void IfcCartesianPoint::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCartesianPoint::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCartesianPoint, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcCartesianPoint, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readTypeOfRealList( args[0], m_Coordinates );
		}
		void IfcCartesianPoint::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcPoint::setInverseCounterparts( ptr_self_entity );
		}
		void IfcCartesianPoint::unlinkSelf()
		{
			IfcPoint::unlinkSelf();
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

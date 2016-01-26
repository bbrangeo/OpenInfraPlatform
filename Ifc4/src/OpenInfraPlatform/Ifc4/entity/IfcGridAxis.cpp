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
#include "include/IfcBoolean.h"
#include "include/IfcCurve.h"
#include "include/IfcGrid.h"
#include "include/IfcGridAxis.h"
#include "include/IfcLabel.h"
#include "include/IfcVirtualGridIntersection.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcGridAxis 
		IfcGridAxis::IfcGridAxis() { m_entity_enum = IFCGRIDAXIS; }
		IfcGridAxis::IfcGridAxis( int id ) { m_id = id; m_entity_enum = IFCGRIDAXIS; }
		IfcGridAxis::~IfcGridAxis() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcGridAxis::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcGridAxis> other = dynamic_pointer_cast<IfcGridAxis>(other_entity);
			if( !other) { return; }
			m_AxisTag = other->m_AxisTag;
			m_AxisCurve = other->m_AxisCurve;
			m_SameSense = other->m_SameSense;
		}
		void IfcGridAxis::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCGRIDAXIS" << "(";
			if( m_AxisTag ) { m_AxisTag->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_AxisCurve ) { stream << "#" << m_AxisCurve->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_SameSense ) { m_SameSense->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcGridAxis::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcGridAxis::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcGridAxis, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcGridAxis, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_AxisTag = IfcLabel::readStepData( args[0] );
			readEntityReference( args[1], m_AxisCurve, map );
			m_SameSense = IfcBoolean::readStepData( args[2] );
		}
		void IfcGridAxis::setInverseCounterparts( shared_ptr<Ifc4Entity> )
		{
		}
		void IfcGridAxis::unlinkSelf()
		{
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

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
#include "include/IfcBoolean.h"
#include "include/IfcCurve.h"
#include "include/IfcGrid.h"
#include "include/IfcGridAxis.h"
#include "include/IfcLabel.h"
#include "include/IfcVirtualGridIntersection.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcGridAxis 
		IfcGridAxis::IfcGridAxis() { m_entity_enum = IFCGRIDAXIS; }
		IfcGridAxis::IfcGridAxis( int id ) { m_id = id; m_entity_enum = IFCGRIDAXIS; }
		IfcGridAxis::~IfcGridAxis() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcGridAxis::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
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
		void IfcGridAxis::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcGridAxis, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcGridAxis, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_AxisTag = IfcLabel::readStepData( args[0] );
			readEntityReference( args[1], m_AxisCurve, map );
			m_SameSense = IfcBoolean::readStepData( args[2] );
		}
		void IfcGridAxis::setInverseCounterparts( shared_ptr<IfcBridgeEntity> )
		{
		}
		void IfcGridAxis::unlinkSelf()
		{
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

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
#include "include/IfcAnnotationFillArea.h"
#include "include/IfcCurve.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcAnnotationFillArea 
		IfcAnnotationFillArea::IfcAnnotationFillArea() { m_entity_enum = IFCANNOTATIONFILLAREA; }
		IfcAnnotationFillArea::IfcAnnotationFillArea( int id ) { m_id = id; m_entity_enum = IFCANNOTATIONFILLAREA; }
		IfcAnnotationFillArea::~IfcAnnotationFillArea() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcAnnotationFillArea::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcAnnotationFillArea> other = dynamic_pointer_cast<IfcAnnotationFillArea>(other_entity);
			if( !other) { return; }
			m_OuterBoundary = other->m_OuterBoundary;
			m_InnerBoundaries = other->m_InnerBoundaries;
		}
		void IfcAnnotationFillArea::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCANNOTATIONFILLAREA" << "(";
			if( m_OuterBoundary ) { stream << "#" << m_OuterBoundary->getId(); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_InnerBoundaries );
			stream << ");";
		}
		void IfcAnnotationFillArea::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcAnnotationFillArea::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcAnnotationFillArea, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcAnnotationFillArea, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_OuterBoundary, map );
			readEntityReferenceList( args[1], m_InnerBoundaries, map );
		}
		void IfcAnnotationFillArea::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcAnnotationFillArea::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

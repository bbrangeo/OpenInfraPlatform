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
#include "include/IfcLengthMeasure.h"
#include "include/IfcPlanarExtent.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcPlanarExtent 
		IfcPlanarExtent::IfcPlanarExtent() { m_entity_enum = IFCPLANAREXTENT; }
		IfcPlanarExtent::IfcPlanarExtent( int id ) { m_id = id; m_entity_enum = IFCPLANAREXTENT; }
		IfcPlanarExtent::~IfcPlanarExtent() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPlanarExtent::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcPlanarExtent> other = dynamic_pointer_cast<IfcPlanarExtent>(other_entity);
			if( !other) { return; }
			m_SizeInX = other->m_SizeInX;
			m_SizeInY = other->m_SizeInY;
		}
		void IfcPlanarExtent::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPLANAREXTENT" << "(";
			if( m_SizeInX ) { m_SizeInX->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_SizeInY ) { m_SizeInY->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcPlanarExtent::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPlanarExtent::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPlanarExtent, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcPlanarExtent, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_SizeInX = IfcLengthMeasure::readStepData( args[0] );
			m_SizeInY = IfcLengthMeasure::readStepData( args[1] );
		}
		void IfcPlanarExtent::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcPlanarExtent::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

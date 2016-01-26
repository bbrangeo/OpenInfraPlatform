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
#include "include/IfcAxis2Placement.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcPlanarBox.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcPlanarBox 
		IfcPlanarBox::IfcPlanarBox() { m_entity_enum = IFCPLANARBOX; }
		IfcPlanarBox::IfcPlanarBox( int id ) { m_id = id; m_entity_enum = IFCPLANARBOX; }
		IfcPlanarBox::~IfcPlanarBox() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPlanarBox::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcPlanarBox> other = dynamic_pointer_cast<IfcPlanarBox>(other_entity);
			if( !other) { return; }
			m_SizeInX = other->m_SizeInX;
			m_SizeInY = other->m_SizeInY;
			m_Placement = other->m_Placement;
		}
		void IfcPlanarBox::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPLANARBOX" << "(";
			if( m_SizeInX ) { m_SizeInX->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_SizeInY ) { m_SizeInY->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Placement ) { m_Placement->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcPlanarBox::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPlanarBox::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPlanarBox, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcPlanarBox, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_SizeInX = IfcLengthMeasure::readStepData( args[0] );
			m_SizeInY = IfcLengthMeasure::readStepData( args[1] );
			m_Placement = IfcAxis2Placement::readStepData( args[2], map );
		}
		void IfcPlanarBox::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcPlanarExtent::setInverseCounterparts( ptr_self_entity );
		}
		void IfcPlanarBox::unlinkSelf()
		{
			IfcPlanarExtent::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

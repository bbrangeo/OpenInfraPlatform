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
#include "include/IfcAxis2Placement.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcPlanarBox.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcPlanarBox 
		IfcPlanarBox::IfcPlanarBox() { m_entity_enum = IFCPLANARBOX; }
		IfcPlanarBox::IfcPlanarBox( int id ) { m_id = id; m_entity_enum = IFCPLANARBOX; }
		IfcPlanarBox::~IfcPlanarBox() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPlanarBox::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
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
		void IfcPlanarBox::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPlanarBox, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcPlanarBox, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_SizeInX = IfcLengthMeasure::readStepData( args[0] );
			m_SizeInY = IfcLengthMeasure::readStepData( args[1] );
			m_Placement = IfcAxis2Placement::readStepData( args[2], map );
		}
		void IfcPlanarBox::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcPlanarExtent::setInverseCounterparts( ptr_self_entity );
		}
		void IfcPlanarBox::unlinkSelf()
		{
			IfcPlanarExtent::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

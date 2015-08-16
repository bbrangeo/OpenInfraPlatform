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
#include "include/IfcConnectionVolumeGeometry.h"
#include "include/IfcSolidOrShell.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcConnectionVolumeGeometry 
		IfcConnectionVolumeGeometry::IfcConnectionVolumeGeometry() { m_entity_enum = IFCCONNECTIONVOLUMEGEOMETRY; }
		IfcConnectionVolumeGeometry::IfcConnectionVolumeGeometry( int id ) { m_id = id; m_entity_enum = IFCCONNECTIONVOLUMEGEOMETRY; }
		IfcConnectionVolumeGeometry::~IfcConnectionVolumeGeometry() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcConnectionVolumeGeometry::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcConnectionVolumeGeometry> other = dynamic_pointer_cast<IfcConnectionVolumeGeometry>(other_entity);
			if( !other) { return; }
			m_VolumeOnRelatingElement = other->m_VolumeOnRelatingElement;
			m_VolumeOnRelatedElement = other->m_VolumeOnRelatedElement;
		}
		void IfcConnectionVolumeGeometry::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCONNECTIONVOLUMEGEOMETRY" << "(";
			if( m_VolumeOnRelatingElement ) { m_VolumeOnRelatingElement->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_VolumeOnRelatedElement ) { m_VolumeOnRelatedElement->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcConnectionVolumeGeometry::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcConnectionVolumeGeometry::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcConnectionVolumeGeometry, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcConnectionVolumeGeometry, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_VolumeOnRelatingElement = IfcSolidOrShell::readStepData( args[0], map );
			m_VolumeOnRelatedElement = IfcSolidOrShell::readStepData( args[1], map );
		}
		void IfcConnectionVolumeGeometry::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcConnectionGeometry::setInverseCounterparts( ptr_self_entity );
		}
		void IfcConnectionVolumeGeometry::unlinkSelf()
		{
			IfcConnectionGeometry::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

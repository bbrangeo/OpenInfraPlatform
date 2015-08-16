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
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcExternallyDefinedSurfaceStyle.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcURIReference.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcExternallyDefinedSurfaceStyle 
		IfcExternallyDefinedSurfaceStyle::IfcExternallyDefinedSurfaceStyle() { m_entity_enum = IFCEXTERNALLYDEFINEDSURFACESTYLE; }
		IfcExternallyDefinedSurfaceStyle::IfcExternallyDefinedSurfaceStyle( int id ) { m_id = id; m_entity_enum = IFCEXTERNALLYDEFINEDSURFACESTYLE; }
		IfcExternallyDefinedSurfaceStyle::~IfcExternallyDefinedSurfaceStyle() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcExternallyDefinedSurfaceStyle::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcExternallyDefinedSurfaceStyle> other = dynamic_pointer_cast<IfcExternallyDefinedSurfaceStyle>(other_entity);
			if( !other) { return; }
			m_Location = other->m_Location;
			m_Identification = other->m_Identification;
			m_Name = other->m_Name;
		}
		void IfcExternallyDefinedSurfaceStyle::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCEXTERNALLYDEFINEDSURFACESTYLE" << "(";
			if( m_Location ) { m_Location->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Identification ) { m_Identification->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcExternallyDefinedSurfaceStyle::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcExternallyDefinedSurfaceStyle::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcExternallyDefinedSurfaceStyle, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcExternallyDefinedSurfaceStyle, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Location = IfcURIReference::readStepData( args[0] );
			m_Identification = IfcIdentifier::readStepData( args[1] );
			m_Name = IfcLabel::readStepData( args[2] );
		}
		void IfcExternallyDefinedSurfaceStyle::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcExternalReference::setInverseCounterparts( ptr_self_entity );
		}
		void IfcExternallyDefinedSurfaceStyle::unlinkSelf()
		{
			IfcExternalReference::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

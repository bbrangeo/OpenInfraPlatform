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
#include "include/IfcOneDirectionRepeatFactor.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcVector.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcOneDirectionRepeatFactor 
		IfcOneDirectionRepeatFactor::IfcOneDirectionRepeatFactor() { m_entity_enum = IFCONEDIRECTIONREPEATFACTOR; }
		IfcOneDirectionRepeatFactor::IfcOneDirectionRepeatFactor( int id ) { m_id = id; m_entity_enum = IFCONEDIRECTIONREPEATFACTOR; }
		IfcOneDirectionRepeatFactor::~IfcOneDirectionRepeatFactor() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcOneDirectionRepeatFactor::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcOneDirectionRepeatFactor> other = dynamic_pointer_cast<IfcOneDirectionRepeatFactor>(other_entity);
			if( !other) { return; }
			m_RepeatFactor = other->m_RepeatFactor;
		}
		void IfcOneDirectionRepeatFactor::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCONEDIRECTIONREPEATFACTOR" << "(";
			if( m_RepeatFactor ) { stream << "#" << m_RepeatFactor->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcOneDirectionRepeatFactor::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcOneDirectionRepeatFactor::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcOneDirectionRepeatFactor, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcOneDirectionRepeatFactor, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_RepeatFactor, map );
		}
		void IfcOneDirectionRepeatFactor::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcOneDirectionRepeatFactor::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

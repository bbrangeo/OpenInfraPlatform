/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/Ifc2x3Exception.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "Ifc2x3EntityEnums.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcTwoDirectionRepeatFactor.h"
#include "include/IfcVector.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcTwoDirectionRepeatFactor 
		IfcTwoDirectionRepeatFactor::IfcTwoDirectionRepeatFactor() { m_entity_enum = IFCTWODIRECTIONREPEATFACTOR; }
		IfcTwoDirectionRepeatFactor::IfcTwoDirectionRepeatFactor( int id ) { m_id = id; m_entity_enum = IFCTWODIRECTIONREPEATFACTOR; }
		IfcTwoDirectionRepeatFactor::~IfcTwoDirectionRepeatFactor() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTwoDirectionRepeatFactor::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcTwoDirectionRepeatFactor> other = dynamic_pointer_cast<IfcTwoDirectionRepeatFactor>(other_entity);
			if( !other) { return; }
			m_RepeatFactor = other->m_RepeatFactor;
			m_SecondRepeatFactor = other->m_SecondRepeatFactor;
		}
		void IfcTwoDirectionRepeatFactor::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTWODIRECTIONREPEATFACTOR" << "(";
			if( m_RepeatFactor ) { stream << "#" << m_RepeatFactor->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_SecondRepeatFactor ) { stream << "#" << m_SecondRepeatFactor->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcTwoDirectionRepeatFactor::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTwoDirectionRepeatFactor::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTwoDirectionRepeatFactor, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcTwoDirectionRepeatFactor, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_RepeatFactor, map );
			readEntityReference( args[1], m_SecondRepeatFactor, map );
		}
		void IfcTwoDirectionRepeatFactor::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcOneDirectionRepeatFactor::setInverseCounterparts( ptr_self_entity );
		}
		void IfcTwoDirectionRepeatFactor::unlinkSelf()
		{
			IfcOneDirectionRepeatFactor::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

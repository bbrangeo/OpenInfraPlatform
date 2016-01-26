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
#include "include/IfcDraughtingPreDefinedColour.h"
#include "include/IfcLabel.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcDraughtingPreDefinedColour 
		IfcDraughtingPreDefinedColour::IfcDraughtingPreDefinedColour() { m_entity_enum = IFCDRAUGHTINGPREDEFINEDCOLOUR; }
		IfcDraughtingPreDefinedColour::IfcDraughtingPreDefinedColour( int id ) { m_id = id; m_entity_enum = IFCDRAUGHTINGPREDEFINEDCOLOUR; }
		IfcDraughtingPreDefinedColour::~IfcDraughtingPreDefinedColour() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcDraughtingPreDefinedColour::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcDraughtingPreDefinedColour> other = dynamic_pointer_cast<IfcDraughtingPreDefinedColour>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
		}
		void IfcDraughtingPreDefinedColour::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCDRAUGHTINGPREDEFINEDCOLOUR" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcDraughtingPreDefinedColour::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcDraughtingPreDefinedColour::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcDraughtingPreDefinedColour, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcDraughtingPreDefinedColour, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
		}
		void IfcDraughtingPreDefinedColour::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcPreDefinedColour::setInverseCounterparts( ptr_self_entity );
		}
		void IfcDraughtingPreDefinedColour::unlinkSelf()
		{
			IfcPreDefinedColour::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

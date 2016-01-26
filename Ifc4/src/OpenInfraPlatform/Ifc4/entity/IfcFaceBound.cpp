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
#include "include/IfcBoolean.h"
#include "include/IfcFaceBound.h"
#include "include/IfcLoop.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcFaceBound 
		IfcFaceBound::IfcFaceBound() { m_entity_enum = IFCFACEBOUND; }
		IfcFaceBound::IfcFaceBound( int id ) { m_id = id; m_entity_enum = IFCFACEBOUND; }
		IfcFaceBound::~IfcFaceBound() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcFaceBound::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcFaceBound> other = dynamic_pointer_cast<IfcFaceBound>(other_entity);
			if( !other) { return; }
			m_Bound = other->m_Bound;
			m_Orientation = other->m_Orientation;
		}
		void IfcFaceBound::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCFACEBOUND" << "(";
			if( m_Bound ) { stream << "#" << m_Bound->getId(); } else { stream << "$"; }
			stream << ",";
			if (m_Orientation == false) { stream << ".F."; }
			else if (m_Orientation == true) { stream << ".T."; }
			stream << ");";
		}
		void IfcFaceBound::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcFaceBound::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcFaceBound, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcFaceBound, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Bound, map );
			if (_stricmp(args[1].c_str(), ".F.") == 0) { m_Orientation = false; }
			else if (_stricmp(args[1].c_str(), ".T.") == 0) { m_Orientation = true; }
		}
		void IfcFaceBound::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcTopologicalRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcFaceBound::unlinkSelf()
		{
			IfcTopologicalRepresentationItem::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

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
#include "include/IfcLabel.h"
#include "include/IfcPreDefinedPointMarkerSymbol.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcPreDefinedPointMarkerSymbol 
		IfcPreDefinedPointMarkerSymbol::IfcPreDefinedPointMarkerSymbol() { m_entity_enum = IFCPREDEFINEDPOINTMARKERSYMBOL; }
		IfcPreDefinedPointMarkerSymbol::IfcPreDefinedPointMarkerSymbol( int id ) { m_id = id; m_entity_enum = IFCPREDEFINEDPOINTMARKERSYMBOL; }
		IfcPreDefinedPointMarkerSymbol::~IfcPreDefinedPointMarkerSymbol() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPreDefinedPointMarkerSymbol::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcPreDefinedPointMarkerSymbol> other = dynamic_pointer_cast<IfcPreDefinedPointMarkerSymbol>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
		}
		void IfcPreDefinedPointMarkerSymbol::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPREDEFINEDPOINTMARKERSYMBOL" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcPreDefinedPointMarkerSymbol::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPreDefinedPointMarkerSymbol::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPreDefinedPointMarkerSymbol, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcPreDefinedPointMarkerSymbol, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
		}
		void IfcPreDefinedPointMarkerSymbol::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcPreDefinedSymbol::setInverseCounterparts( ptr_self_entity );
		}
		void IfcPreDefinedPointMarkerSymbol::unlinkSelf()
		{
			IfcPreDefinedSymbol::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

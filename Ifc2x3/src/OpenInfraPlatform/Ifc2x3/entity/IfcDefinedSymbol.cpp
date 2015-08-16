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
#include "include/IfcCartesianTransformationOperator2D.h"
#include "include/IfcDefinedSymbol.h"
#include "include/IfcDefinedSymbolSelect.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcDefinedSymbol 
		IfcDefinedSymbol::IfcDefinedSymbol() { m_entity_enum = IFCDEFINEDSYMBOL; }
		IfcDefinedSymbol::IfcDefinedSymbol( int id ) { m_id = id; m_entity_enum = IFCDEFINEDSYMBOL; }
		IfcDefinedSymbol::~IfcDefinedSymbol() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcDefinedSymbol::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcDefinedSymbol> other = dynamic_pointer_cast<IfcDefinedSymbol>(other_entity);
			if( !other) { return; }
			m_Definition = other->m_Definition;
			m_Target = other->m_Target;
		}
		void IfcDefinedSymbol::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCDEFINEDSYMBOL" << "(";
			if( m_Definition ) { m_Definition->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_Target ) { stream << "#" << m_Target->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcDefinedSymbol::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcDefinedSymbol::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcDefinedSymbol, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcDefinedSymbol, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Definition = IfcDefinedSymbolSelect::readStepData( args[0], map );
			readEntityReference( args[1], m_Target, map );
		}
		void IfcDefinedSymbol::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcDefinedSymbol::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

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
#include "include/IfcAnnotationSymbolOccurrence.h"
#include "include/IfcFillAreaStyleTileSymbolWithStyle.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcFillAreaStyleTileSymbolWithStyle 
		IfcFillAreaStyleTileSymbolWithStyle::IfcFillAreaStyleTileSymbolWithStyle() { m_entity_enum = IFCFILLAREASTYLETILESYMBOLWITHSTYLE; }
		IfcFillAreaStyleTileSymbolWithStyle::IfcFillAreaStyleTileSymbolWithStyle( int id ) { m_id = id; m_entity_enum = IFCFILLAREASTYLETILESYMBOLWITHSTYLE; }
		IfcFillAreaStyleTileSymbolWithStyle::~IfcFillAreaStyleTileSymbolWithStyle() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcFillAreaStyleTileSymbolWithStyle::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcFillAreaStyleTileSymbolWithStyle> other = dynamic_pointer_cast<IfcFillAreaStyleTileSymbolWithStyle>(other_entity);
			if( !other) { return; }
			m_Symbol = other->m_Symbol;
		}
		void IfcFillAreaStyleTileSymbolWithStyle::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCFILLAREASTYLETILESYMBOLWITHSTYLE" << "(";
			if( m_Symbol ) { stream << "#" << m_Symbol->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcFillAreaStyleTileSymbolWithStyle::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcFillAreaStyleTileSymbolWithStyle::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcFillAreaStyleTileSymbolWithStyle, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcFillAreaStyleTileSymbolWithStyle, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Symbol, map );
		}
		void IfcFillAreaStyleTileSymbolWithStyle::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcFillAreaStyleTileSymbolWithStyle::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

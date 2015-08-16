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
#include "include/IfcFillAreaStyleTileSymbolWithStyle.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcFillAreaStyleTileSymbolWithStyle 
		IfcFillAreaStyleTileSymbolWithStyle::IfcFillAreaStyleTileSymbolWithStyle() { m_entity_enum = IFCFILLAREASTYLETILESYMBOLWITHSTYLE; }
		IfcFillAreaStyleTileSymbolWithStyle::IfcFillAreaStyleTileSymbolWithStyle( int id ) { m_id = id; m_entity_enum = IFCFILLAREASTYLETILESYMBOLWITHSTYLE; }
		IfcFillAreaStyleTileSymbolWithStyle::~IfcFillAreaStyleTileSymbolWithStyle() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcFillAreaStyleTileSymbolWithStyle::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
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
		void IfcFillAreaStyleTileSymbolWithStyle::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcFillAreaStyleTileSymbolWithStyle, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcFillAreaStyleTileSymbolWithStyle, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Symbol, map );
		}
		void IfcFillAreaStyleTileSymbolWithStyle::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcFillAreaStyleTileSymbolWithStyle::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

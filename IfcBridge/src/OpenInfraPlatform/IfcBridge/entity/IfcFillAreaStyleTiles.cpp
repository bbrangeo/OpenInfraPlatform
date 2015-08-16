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
#include "include/IfcFillAreaStyleTileShapeSelect.h"
#include "include/IfcFillAreaStyleTiles.h"
#include "include/IfcOneDirectionRepeatFactor.h"
#include "include/IfcPositiveRatioMeasure.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcFillAreaStyleTiles 
		IfcFillAreaStyleTiles::IfcFillAreaStyleTiles() { m_entity_enum = IFCFILLAREASTYLETILES; }
		IfcFillAreaStyleTiles::IfcFillAreaStyleTiles( int id ) { m_id = id; m_entity_enum = IFCFILLAREASTYLETILES; }
		IfcFillAreaStyleTiles::~IfcFillAreaStyleTiles() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcFillAreaStyleTiles::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcFillAreaStyleTiles> other = dynamic_pointer_cast<IfcFillAreaStyleTiles>(other_entity);
			if( !other) { return; }
			m_TilingPattern = other->m_TilingPattern;
			m_Tiles = other->m_Tiles;
			m_TilingScale = other->m_TilingScale;
		}
		void IfcFillAreaStyleTiles::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCFILLAREASTYLETILES" << "(";
			if( m_TilingPattern ) { stream << "#" << m_TilingPattern->getId(); } else { stream << "$"; }
			stream << ",";
			writeTypeList( stream, m_Tiles, true );
			stream << ",";
			if( m_TilingScale ) { m_TilingScale->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcFillAreaStyleTiles::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcFillAreaStyleTiles::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcFillAreaStyleTiles, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcFillAreaStyleTiles, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_TilingPattern, map );
			readSelectList( args[1], m_Tiles, map );
			m_TilingScale = IfcPositiveRatioMeasure::readStepData( args[2] );
		}
		void IfcFillAreaStyleTiles::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcFillAreaStyleTiles::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

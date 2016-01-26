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
#include "include/IfcCartesianPointList3D.h"
#include "include/IfcIndexedColourMap.h"
#include "include/IfcIndexedTextureMap.h"
#include "include/IfcParameterValue.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcTessellatedFaceSet.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcTessellatedFaceSet 
		IfcTessellatedFaceSet::IfcTessellatedFaceSet() { m_entity_enum = IFCTESSELLATEDFACESET; }
		IfcTessellatedFaceSet::IfcTessellatedFaceSet( int id ) { m_id = id; m_entity_enum = IFCTESSELLATEDFACESET; }
		IfcTessellatedFaceSet::~IfcTessellatedFaceSet() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTessellatedFaceSet::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcTessellatedFaceSet> other = dynamic_pointer_cast<IfcTessellatedFaceSet>(other_entity);
			if( !other) { return; }
			m_Coordinates = other->m_Coordinates;
			m_Normals = other->m_Normals;
			m_Closed = other->m_Closed;
		}
		void IfcTessellatedFaceSet::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTESSELLATEDFACESET" << "(";
			if( m_Coordinates ) { stream << "#" << m_Coordinates->getId(); } else { stream << "$"; }
			stream << ",";
			writeTypeOfRealList2D( stream, m_Normals );
			stream << ",";
			if( m_Closed ) { m_Closed->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcTessellatedFaceSet::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTessellatedFaceSet::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTessellatedFaceSet, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcTessellatedFaceSet, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Coordinates, map );
			readTypeOfRealList2D( args[1], m_Normals );
			m_Closed = IfcBoolean::readStepData( args[2] );
		}
		void IfcTessellatedFaceSet::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcTessellatedItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcTessellatedFaceSet::unlinkSelf()
		{
			IfcTessellatedItem::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

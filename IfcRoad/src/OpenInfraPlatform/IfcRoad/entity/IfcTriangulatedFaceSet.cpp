/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/IfcRoadEntityEnums.h"
#include "include/IfcBoolean.h"
#include "include/IfcCartesianPointList3D.h"
#include "include/IfcIndexedColourMap.h"
#include "include/IfcIndexedTextureMap.h"
#include "include/IfcParameterValue.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcTriangulatedFaceSet.h"

#include "OpenInfraPlatform/IfcRoad/reader/IfcStepCTELexer.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcTriangulatedFaceSet 
		IfcTriangulatedFaceSet::IfcTriangulatedFaceSet() { m_entity_enum = IFCTRIANGULATEDFACESET; }
		IfcTriangulatedFaceSet::IfcTriangulatedFaceSet( int id ) { m_id = id; m_entity_enum = IFCTRIANGULATEDFACESET; }
		IfcTriangulatedFaceSet::~IfcTriangulatedFaceSet() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTriangulatedFaceSet::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcTriangulatedFaceSet> other = dynamic_pointer_cast<IfcTriangulatedFaceSet>(other_entity);
			if( !other) { return; }
			m_Coordinates = other->m_Coordinates;
			m_Normals = other->m_Normals;
			m_Closed = other->m_Closed;
			m_CoordIndex = other->m_CoordIndex;
			m_NormalIndex = other->m_NormalIndex;
		}
		void IfcTriangulatedFaceSet::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTRIANGULATEDFACESET" << "(";
			if( m_Coordinates ) { stream << "#" << m_Coordinates->getId(); } else { stream << "$"; }
			stream << ",";
			writeTypeOfRealList2D( stream, m_Normals );
			stream << ",";
			if( m_Closed ) { m_Closed->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeIntList2D( stream, m_CoordIndex );
			stream << ",";
			writeIntList2D( stream, m_NormalIndex );
			stream << ");";
		}
		void IfcTriangulatedFaceSet::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTriangulatedFaceSet::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTriangulatedFaceSet, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcTriangulatedFaceSet, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Coordinates, map );
			readTypeOfRealList2D( args[1], m_Normals );
			m_Closed = IfcBoolean::readStepData( args[2] );
			IfcStepCTE::readListOfListOfIntegers(args[3], m_CoordIndex);
			IfcStepCTE::readListOfListOfIntegers(args[4], m_NormalIndex);
			//readIntList2D(  args[3], m_CoordIndex );
			//readIntList2D(  args[4], m_NormalIndex );
		}
		void IfcTriangulatedFaceSet::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcTessellatedFaceSet::setInverseCounterparts( ptr_self_entity );
		}
		void IfcTriangulatedFaceSet::unlinkSelf()
		{
			IfcTessellatedFaceSet::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/IfcRoadEntityEnums.h"
#include "include/IfcGeometricCurveSet.h"
#include "include/IfcGeometricSetSelect.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcGeometricCurveSet 
		IfcGeometricCurveSet::IfcGeometricCurveSet() { m_entity_enum = IFCGEOMETRICCURVESET; }
		IfcGeometricCurveSet::IfcGeometricCurveSet( int id ) { m_id = id; m_entity_enum = IFCGEOMETRICCURVESET; }
		IfcGeometricCurveSet::~IfcGeometricCurveSet() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcGeometricCurveSet::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcGeometricCurveSet> other = dynamic_pointer_cast<IfcGeometricCurveSet>(other_entity);
			if( !other) { return; }
			m_Elements = other->m_Elements;
		}
		void IfcGeometricCurveSet::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCGEOMETRICCURVESET" << "(";
			writeTypeList( stream, m_Elements, true );
			stream << ");";
		}
		void IfcGeometricCurveSet::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcGeometricCurveSet::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcGeometricCurveSet, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcGeometricCurveSet, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readSelectList( args[0], m_Elements, map );
		}
		void IfcGeometricCurveSet::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcGeometricSet::setInverseCounterparts( ptr_self_entity );
		}
		void IfcGeometricCurveSet::unlinkSelf()
		{
			IfcGeometricSet::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

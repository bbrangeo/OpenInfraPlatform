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
#include "include/IfcGeometricSet.h"
#include "include/IfcGeometricSetSelect.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcGeometricSet 
		IfcGeometricSet::IfcGeometricSet() { m_entity_enum = IFCGEOMETRICSET; }
		IfcGeometricSet::IfcGeometricSet( int id ) { m_id = id; m_entity_enum = IFCGEOMETRICSET; }
		IfcGeometricSet::~IfcGeometricSet() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcGeometricSet::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcGeometricSet> other = dynamic_pointer_cast<IfcGeometricSet>(other_entity);
			if( !other) { return; }
			m_Elements = other->m_Elements;
		}
		void IfcGeometricSet::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCGEOMETRICSET" << "(";
			writeTypeList( stream, m_Elements, true );
			stream << ");";
		}
		void IfcGeometricSet::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcGeometricSet::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcGeometricSet, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcGeometricSet, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readSelectList( args[0], m_Elements, map );
		}
		void IfcGeometricSet::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcGeometricSet::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

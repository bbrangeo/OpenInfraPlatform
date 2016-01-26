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
#include "include/IfcSurfaceStyleRefraction.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcSurfaceStyleRefraction 
		IfcSurfaceStyleRefraction::IfcSurfaceStyleRefraction() { m_entity_enum = IFCSURFACESTYLEREFRACTION; }
		IfcSurfaceStyleRefraction::IfcSurfaceStyleRefraction( int id ) { m_id = id; m_entity_enum = IFCSURFACESTYLEREFRACTION; }
		IfcSurfaceStyleRefraction::~IfcSurfaceStyleRefraction() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcSurfaceStyleRefraction::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcSurfaceStyleRefraction> other = dynamic_pointer_cast<IfcSurfaceStyleRefraction>(other_entity);
			if( !other) { return; }
			m_RefractionIndex = other->m_RefractionIndex;
			m_DispersionFactor = other->m_DispersionFactor;
		}
		void IfcSurfaceStyleRefraction::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSURFACESTYLEREFRACTION" << "(";
			if( m_RefractionIndex == m_RefractionIndex ){ stream << m_RefractionIndex; }
			else { stream << "$"; }
			stream << ",";
			if( m_DispersionFactor == m_DispersionFactor ){ stream << m_DispersionFactor; }
			else { stream << "$"; }
			stream << ");";
		}
		void IfcSurfaceStyleRefraction::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcSurfaceStyleRefraction::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcSurfaceStyleRefraction, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcSurfaceStyleRefraction, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readRealValue( args[0], m_RefractionIndex );
			readRealValue( args[1], m_DispersionFactor );
		}
		void IfcSurfaceStyleRefraction::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcPresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcSurfaceStyleRefraction::unlinkSelf()
		{
			IfcPresentationItem::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
